<?php

/**
 * @ file
 * Admin forms and callback functions.
 */

/**
 * Answer settings form
 */
function vopros_sms_settings_form($form, &$form_state) {
  $form['vopros_sms_push_api_url'] = array(
    '#type' => 'textfield',
    '#title' => t('SMS send API url'),
    '#description' => t('The API url to use for sending SMSes.'),
    '#default_value' => variable_get('vopros_sms_push_api_url', ''),
  );

  $form['vopros_sms_push_user_name'] = array(
    '#type' => 'textfield',
    '#title' => t('SMS send user name'),
    '#description' => t('The user name to use as authentication when sending SMSes'),
    '#default_value' => variable_get('vopros_sms_push_user_name', ''),
  );

  $form['pass'] = array(
    '#type' => 'fieldset',
    '#title' => t('SMS send password'),
    '#description' => t('The user name to use as authentication when sending SMSes.'),
    '#collapsible' => TRUE,
    '#collapsed' => (bool) variable_get('vopros_sms_push_password', ''),
  );

  $form['pass']['vopros_sms_push_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#default_value' => variable_get('vopros_sms_push_password', ''),
  );

  $form['vopros_sms_push_short_code'] = array(
    '#type' => 'textfield',
    '#title' => t('SMS send short code'),
    '#description' => t('The short code used when sending SMSes'),
    '#default_value' => variable_get('vopros_sms_push_short_code', ''),
  );

  $form['vopros_sms_push_sender'] = array(
    '#type' => 'textfield',
    '#title' => t('SMS send sender'),
    '#description' => t('Used as the sender of the SMSes, 11 alphanumeric chars allowed'),
    '#default_value' => variable_get('vopros_sms_push_sender', ''),
    '#maxlength' => 11,
    '#element_validate' => array('vopros_sms_push_sender_validate'),
  );

  $form['contact'] = array(
    '#type' => 'fieldset',
    '#title' => t('Contact user SMS macros'),
  );

  foreach (vopros_question_get_reasons('contact_sms') as $key => $value) {
    $key = str_replace(' ', '_', $key);
    $form['contact']['vopros_sms_macro_' . $key] = array(
      '#type' => 'textarea',
      '#title' => $value,
      '#description' => t('Macro used when contacting a user.'),
      '#default_value' => variable_get('vopros_sms_macro_' . $key, ''),
    );
  }

  $form['contact']['tokens'] = array(
    '#markup' => theme('token_tree', array(
      'token_types' => array('vopros_question'),
      'global_types' => FALSE,
    )),
  );

  $form['macros'] = array(
    '#type' => 'fieldset',
    '#title' => t('SMS macros'),
    '#description' => t('Create macros inserted when sending an email.'),
  );

  $form['macros']['vopros_sms_answered_question_macro'] = array(
    '#type' => 'textarea',
    '#title' => t('Answered question'),
    '#description' => t('Macro used when answering a question.'),
    '#default_value' => variable_get('vopros_sms_answered_question_macro', ''),
  );

  $form['macros']['tokens'] = array(
    '#markup' => theme('token_tree', array(
      'token_types' => array('vopros_answer', 'vopros_question'),
      'global_types' => FALSE,
    )),
  );

  return system_settings_form($form);
}

/**
 * Validate the sms_push_sender.
 */
function vopros_sms_push_sender_validate(&$form, &$form_state) {
  if (preg_match('/[^a-z0-9]/', $form_state['values']['vopros_sms_push_sender'])) {
    form_set_error('vopros_sms_push_sender', t('Only alphanumeric chars (letters and numbers) allowed'));
  }
}

/**
 * Answer form
 */
function vopros_sms_form($form, &$form_state, $answer, $sms) {
  if (empty($answer) && isset($sms->answer_id)) {
    $answer = vopros_question_load($sms->answer_id);
  }

  $answer_wrapper = entity_metadata_wrapper('vopros_answer', $answer);

  $form['action'] = array(
    '#prefix' => '<div class="action">',
    '#suffix' => '</div>',
  );

  $form['action']['save_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
    '#submit' => array('vopros_sms_form_submit'),
  );
  
  $form['#after_build'] = array('vopros_sms_form_add_js');

  
  
  $form['answer'] = array(
    '#type' => 'value',
    '#value' => $answer,
  );

  $form['sms'] = array(
    '#type' => 'value',
    '#value' => $sms,
  );

  $form['form'] = array(
    '#prefix' => '<div class="form">',
    '#suffix' => '</div>',
  );

  $form['form']['phone_number'] = array(
     '#title' => t('To'),
     '#type' => 'textfield',
     '#default_value' => $answer_wrapper->question->user_mobile_phone->value(),
     '#required' => TRUE,
   );

  $content =  token_replace(variable_get('vopros_sms_answered_question_macro', ''), array(
     'vopros_answer' => $answer,
     'vopros_question' => $answer_wrapper->question->value(),
   ));
  
  if (strlen($content) <= 160) {
    $sms_count = 1;
  }
  else {
    $sms_count = strlen($content) / 153;
  }

  $form['form']['content_wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content'),
  );

  $form['form']['content_wrapper']['chars'] = array(
    '#markup' => '<div id="sms-counter">' . t('SMS counter:'). ' <span class="counter">' . strlen($content) . '/' . $sms_count . '</span></div>',
  );

  $form['form']['content_wrapper']['content'] = array(
    '#type' => 'textarea',
    '#title' => t('Content'),
    '#description' => t('The main content of the sms.'),
    '#default_value' => $content,
    '#required' => TRUE,
  );

  $form['form']['buttons'] = array(
    '#weight' => 100
  );

  $form['form']['buttons']['send'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
    '#submit' => array('vopros_sms_form_submit'),
  );

  $form['form']['buttons']['edit_answer'] = array(
    '#markup' => l(t('Edit answer'), 'admin/vopros/answers/' . $answer->answer_id . '/edit'),
  );

  return $form;
}

/**
 * After build function to add JS for the vopros_sms_form.
 */
function vopros_sms_form_add_js(&$form, &$form_state) {
  drupal_add_js(drupal_get_path('module', 'vopros_sms') . '/js/vopros_sms_form.js');
  return $form;
}

/**
 * Submit handler for saving questions
 */
function vopros_sms_form_submit(&$form, &$form_state) {
  $sms = $form_state['values']['sms'];
  $sms->content = $form_state['values']['content'];
  $sms->phone_number = $form_state['values']['phone_number'];
  $sms->uid = $GLOBALS['user']->uid;
  $sms->answer_id = $form_state['values']['answer']->answer_id;
  $sms->question_id = $form_state['values']['answer']->question_id;
  $sms_wrapper = entity_metadata_wrapper('vopros_sms', $sms);
  vopros_sms_save($sms);
  if ($sms->status != 'sent') {
    vopros_sms_send($sms);
  }
  drupal_set_message(t('The answer has been sent to @receiver and the question is marked as answered.', array('@receiver' => $sms->phone_number)));
  $form_state['redirect'] = 'admin/vopros/questions/';
}

/**
 * Form for sending an sms to the user.
 */
function vopros_sms_question_contact_form($form, &$form_state, $question) {
  $form['#after_build'] = array('vopros_sms_form_add_js');

  $form['send_sms'] = array(
    '#type' => 'submit',
    '#value' => t('Send SMS'),
  );

  $form['question'] = array(
    '#value' => $question,
    '#type' => 'value',
  );

  $form['phone_number'] = array(
    '#title' => t('To'),
    '#type' => 'textfield',
    '#default_value' => $question->user_mobile_phone,
    '#required' => TRUE,
  );

  $form['reason'] = array(
    '#type' => 'select',
    '#title' => t('Answer type'),
    '#options' => vopros_question_get_reasons('contact_sms'),
    '#required' => TRUE,
    '#ajax' => array(
      'callback' => 'vopros_sms_question_contact_form_macro',
    ),
  );

  $form['content_wrapper']['chars'] = array(
    '#markup' => '<div id="sms-counter">' . t('SMS counter:'). ' <span class="counter">' . 0 . '/' . 1 . '</span></div>',
  );

  $form['content_wrapper']['content'] = array(
    '#title' => t('SMS body'),
    '#type' => 'textarea',
    '#required' => TRUE,
  );

  return $form;
}


/**
 * AJAX callback for displaying macros.
 */
function vopros_sms_question_contact_form_macro($form, &$form_state) {
  $key = str_replace(' ', '_', $form_state['values']['reason']);
  $key = 'vopros_sms_macro_' . $key;

  $text = variable_get($key, '');
  drupal_alter('vopros_sms_question_contact_form_macro', $text, $form, $key);

  $processed_text = token_replace($text, array('vopros_question' => $form_state['values']['question']));

  $commands = array();
  $commands[] = ajax_command_invoke('#edit-content', 'val', array($processed_text));
  return array('#type' => 'ajax', '#commands' => $commands);
}


/**
 * Submit handler for vopros_sms_question_contact_form().
 */
function vopros_sms_question_contact_form_submit(&$form, &$form_state) {
  $v = $form_state['values'];
  $question = $v['question'];
  $sms = vopros_sms_new(array(
    'question_id' => $question->question_id,
    'uid' => $GLOBALS['user']->uid,
    'content' => $v['content'],
    'phone_number' => $v['phone_number'],
  ));
  vopros_sms_save($sms);
  if ($sms->status != 'sent') {
    vopros_sms_send($sms);
    $sms->status = 'sent';
    vopros_sms_save($sms);
  }
  $question->question_status = 'closed';
  $question->question_status_reason = $v['reason'];
  vopros_question_save($question);
  drupal_set_message(t('The SMS has been sent to @receiver and the question is closed until the user provides feedback', array('@receiver' => $sms->phone_number)), 'warning');
  $form_state['redirect'] = 'admin/vopros/questions';
}