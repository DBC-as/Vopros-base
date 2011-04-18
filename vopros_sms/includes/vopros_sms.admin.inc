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
  $form['#after_build'] = array('vopros_sms_form_add_js');

  if (empty($answer) && isset($sms->answer_id)) {
    $answer = vopros_question_load($sms->answer_id);
  }
  
  $form['answer'] = array(
    '#type' => 'value',
    '#value' => $answer,
  );

  $form['sms'] = array(
    '#type' => 'value',
    '#value' => $sms,
  );

  $content = isset($sms->content) ? $sms->content : '';
  if (strlen($content) <= 160) {
    $sms_count = 1;
  }
  else {
    $sms_count = strlen($content) / 153;
  }

  $form['content_wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content'),
  );

  $form['content_wrapper']['chars'] = array(
    '#markup' => '<div id="sms-counter">' . t('SMS counter:'). ' <span class="counter">' . strlen($content) . '/' . $sms_count . '</span></div>',
  );

  $form['content_wrapper']['content'] = array(
    '#type' => 'textarea',
    '#title' => t('Content'),
    '#description' => t('The main content of the sms.'),
    '#default_value' => $content,
  );

  $form['send'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
    '#submit' => array('vopros_sms_form_submit'),
  );

  return $form;
}

/**
 * After build function to add JS for the vopros_sms_form.
 */
function vopros_sms_form_add_js(&$form, &$form_state) {
  drupal_add_js(drupal_get_path('module', 'vopros_sms') . '/static/vopros_sms_form.js');
  return $form;
}

/**
 * Submit handler for saving questions
 */
function vopros_sms_form_submit(&$form, &$form_state) {
  $sms = $form_state['values']['sms'];
  $sms->content = $form_state['values']['content'];
  $sms->uid = $GLOBALS['user']->uid;
  $sms->answer_id = $form_state['values']['answer']->answer_id;
  $sms_wrapper = entity_metadata_wrapper('vopros_sms', $sms);
  vopros_sms_save($sms);
  if ($sms->status != 'sent') {
    vopros_sms_send($sms);
  }
  $form_state['redirect'] = 'admin/vopros/questions/' . $sms_wrapper->answer->question->question_id->value();
}
