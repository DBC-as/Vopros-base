<?php

/**
 * @ file
 * Admin forms and callback functions.
 */

/**
 * Answer settings form
 */
function vopros_email_settings_form($form, &$form_state) {
  if (!isset($form_state['new_snippets_count'])) {
    $form_state['new_snippets_count'] = 1;
  }

  $form['contact'] = array(
    '#type' => 'fieldset',
    '#title' => t('Contact user email macros'),
  );

  foreach (vopros_question_get_reasons('contact') as $key => $value) {
    $key = str_replace(' ', '_', $key);
    $form['contact']['vopros_email_macro_' . $key] = array(
      '#type' => 'textarea',
      '#title' => $value,
      '#description' => t('Macro used when contacting a user.'),
      '#default_value' => variable_get('vopros_email_macro_' . $key, ''),
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
    '#title' => t('Email macros'),
    '#description' => t('Create macros inserted when sending an email.'),
  );

  $form['macros']['vopros_email_answered_question_macro'] = array(
    '#type' => 'textarea',
    '#title' => t('Answered question'),
    '#description' => t('Macro used when answering a question.'),
    '#default_value' => variable_get('vopros_email_answered_question_macro', ''),
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
 * Answer form
 */
function vopros_email_form($form, &$form_state, $answer, $email) {
  $form['action'] = array(
    '#prefix' => '<div class="action">',
    '#suffix' => '</div>',
  );

  $form['action']['publish'] = array(
    '#type' => 'checkbox',
    '#title' => t('Publish question and answer'),
  );

  $form['action']['send'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
    '#submit' => array('vopros_email_form_submit'),
  );

  if (empty($answer) && isset($email->answer_id)) {
    $answer = vopros_question_load($email->answer_id);
  }

  $answer_wrapper = entity_metadata_wrapper('vopros_answer', $answer);

  $form['answer'] = array(
    '#type' => 'value',
    '#value' => $answer,
  );

  $form['vopros_email'] = array(
    '#type' => 'value',
    '#value' => $email,
  );

  $form['form'] = array(
    '#prefix' => '<div class="form">',
    '#suffix' => '</div>',
  );

  $form['form']['email'] = array(
    '#title' => t('To'),
    '#type' => 'textfield',
    '#default_value' => $answer_wrapper->question->user_email->value(),
    '#required' => TRUE,
  );

  $form['form']['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t('The subject for the email.'),
    '#default_value' => isset($email->subject) ? $email->subject : '',
    '#required' => TRUE,
  );

  $form['form']['content'] = array(
    '#type' => 'textarea',
    '#title' => t('Mail body'),
    '#description' => t('The main content of the email.'),
    '#default_value' => token_replace(variable_get('vopros_email_answered_question_macro', ''), array(
      'vopros_answer' => $answer,
      'vopros_question' => $answer_wrapper->question->value(),
    )),
    '#required' => TRUE,
  );

  $form['form']['send'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
    '#submit' => array('vopros_email_form_submit'),
  );

  $form['form']['edit_answer'] = array(
    '#markup' => l(t('Edit answer'), 'admin/vopros/answers/' . $answer->answer_id . '/edit'),
    '#value' => t('Edit answer'),
    '#submit' => array('vopros_email_form_submit'),
  );

  return $form;
}

/**
 * Submit handler for saving questions
 */
function vopros_email_form_submit(&$form, &$form_state) {
  // Update the email with submitted data.
  $email = $form_state['values']['vopros_email'];
  $email->subject = $form_state['values']['subject'];
  $email->content = $form_state['values']['content'];
  $email->email = $form_state['values']['email'];
  // Create the needed relations for later.
  $email->uid = $GLOBALS['user']->uid;
  $email->answer_id = $form_state['values']['answer']->answer_id;
  $email->question_id = $form_state['values']['answer']->question_id;
  
  vopros_email_save($email);
  if ($email->status != 'sent') {
    vopros_email_send($email);
    $email->status = 'sent';
    vopros_email_save($email);
  }

  $question->question_status = 'answered';
  
  $form_state['redirect'] = 'admin/vopros/questions';
  drupal_set_message(t('The email has been sent and the question is marked as answered.'));
}

/**
 * Form for answering a question.
 */
function vopros_email_question_contact_form($form, &$form_state, $question) {
  $form['send_mail'] = array(
    '#type' => 'submit',
    '#value' => t('Send mail'),
  );

  $form['question'] = array(
    '#value' => $question,
    '#type' => 'value',
  );

  $form['email'] = array(
    '#title' => t('To'),
    '#type' => 'textfield',
    '#default_value' => $question->user_email,
    '#required' => TRUE,
  );

  $form['reason'] = array(
    '#type' => 'select',
    '#title' => t('Answer type'),
    '#options' => vopros_question_get_reasons(),
    '#required' => TRUE,
    '#ajax' => array(
      'callback' => 'vopros_email_question_contact_form_macro',
    ),
  );

  $form['subject'] = array(
    '#title' => t('Subject'),
    '#type' => 'textfield',
    '#required' => TRUE,
  );

  $form['body'] = array(
    '#title' => t('Mail body'),
    '#type' => 'textarea',
    '#required' => TRUE,
  );

  return $form;
}

/**
 * AJAX callback for displaying macros.
 */
function vopros_email_question_contact_form_macro($form, &$form_state) {
  $key = str_replace(' ', '_', $form_state['values']['reason']);

  $text = variable_get('vopros_email_macro_' . $key, '');

  $processed_text = token_replace($text, array('vopros_question' => $form_state['values']['question']));
  $commands = array();
  $commands[] = ajax_command_invoke('#edit-body', 'val', array($processed_text));
  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Validate handler for vopros_email_question_contact_form().
 */
function vopros_email_question_contact_form_validate(&$form, &$form_state) {
  $mail = $form_state['values']['email'];
  if (!valid_email_address($mail)) {
    form_set_error('email', t('The email address %mail is not valid.', array('%mail' => $mail)));
  }
}

/**
 * Validate handler for vopros_email_question_contact_form().
 */
function vopros_email_question_contact_form_submit(&$form, &$form_state) {
  $v = $form_state['values'];
  $question = $v['question'];
  $email = vopros_email_new(array(
    'question_id' => $question->question_id,
    'uid' => $GLOBALS['user']->uid,
    'content' => $v['body'],
    'subject' => $v['subject'],
    'email' => $v['email'],
  ));
  vopros_email_save($email);
  if ($email->status != 'sent') {
    vopros_email_send($email);
    $email->status = 'sent';
    vopros_email_save($email);
  }
  $question->question_status = 'closed';
  $question->question_status_reason = $v['reason'];
  vopros_question_save($question);
  drupal_set_message(t('The email has been sent to the user and the question is closed until the user provides feedback'));
}
