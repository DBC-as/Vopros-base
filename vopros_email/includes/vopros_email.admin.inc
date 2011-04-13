<?php

/**
 * @ file
 * Admin forms and callback functions.
 */

/**
 * Answer settings form
 */
function vopros_email_settings_form($form, &$form_state) {
  return system_settings_form($form);
}

/**
 * Answer form
 */
function vopros_email_form($form, &$form_state, $answer, $email) {
  if (empty($answer) && isset($email->answer_id)) {
    $answer = vopros_question_load($email->answer_id);
  }
  $form['answer'] = array(
    '#type' => 'value',
    '#value' => $answer,
  );

  $form['email'] = array(
    '#type' => 'value',
    '#value' => $email,
  );

  $form['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t('The subject for the email.'),
    '#default_value' => isset($email->subject) ? $email->subject : '',
  );

  $form['content'] = array(
    '#type' => 'textarea',
    '#title' => t('Content'),
    '#description' => t('The main content of the email.'),
    '#default_value' => isset($email->content) ? $email->content : (isset($answer->answer_content) ? $answer->answer_content : ''),
  );

  $form['send'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
    '#submit' => array('vopros_email_form_submit'),
  );

  return $form;
}

/**
 * Submit handler for saving questions
 */
function vopros_email_form_submit(&$form, &$form_state) {
  $email = $form_state['values']['email'];
  $email->subject = $form_state['values']['subject'];
  $email->content = $form_state['values']['content'];
  $email->uid = $GLOBALS['user']->uid;
  $email->answer_id = $form_state['values']['answer']->answer_id;
  vopros_email_save($email);
  if ($email->status != 'sent') {
    vopros_email_send($email);
    $email->status = 'sent';
    vopros_email_save($email);
  }
  $form_state['redirect'] = 'admin/vopros/email/' . $email->email_id;
}
