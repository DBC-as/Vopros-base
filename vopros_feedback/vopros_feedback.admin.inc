<?php

/**
 * @file Admin forms and menu callbacks for the vopros_feedback module.
 */

/**
 * General settings form.
 */
function vopros_feedback_settings_form($form, &$form_state) {
  $form['vopros_feedback_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('MD5 Secret'),
    '#description' => t('Used for creating a validation hash used as access control.'),
    '#default_value' => variable_get('vopros_feedback_secret', ''),
  );

  $form['vopros_feedback_intro_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Intro text'),
    '#description' => t('Setup intro text on feedback page when feedback has been saved.'),
    '#default_value' => variable_get('vopros_feedback_intro_text', ''),
  );

  return system_settings_form($form);
}

/**
 * Form for creating and editing vopros_feedback entities.
 */
function vopros_feedback_form($form, &$form_state, $feedback, $question = NULL, $email = NULL) {
  field_attach_form('vopros_feedback', $feedback, $form, $form_state);

  if (!$feedback->question_id && isset($question->question_id)) {
    $feedback->question_id = $question->question_id;
  }

  if (!$feedback->email_id && isset($email->email_id)) {
    $feedback->email_id = $email->email_id;
  }

  $form['feedback_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Feedback'),
    '#default_value' => $feedback->feedback_content,
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save feedback'),
    '#weight' => 100,
  );

  if (!$feedback->created) {
    $form['save']['#value'] = t('Give feedback');
  }

  $form_state['feedback'] = $feedback;

  return $form;
}

/**
 * Validate handler for vopros_feedback_form().
 */
function vopros_feedback_form_validate(&$form, &$form_state) {
  $feedback = $form_state['feedback'];
  field_attach_validate('vopros_feedback', $feedback, $form, $form_state);
}

/**
 * Submit handler for vopros_feedback_form().
 */
function vopros_feedback_form_submit(&$form, &$form_state) {
  $feedback = $form_state['feedback'];
  field_attach_submit('vopros_feedback', $feedback, $form, $form_state);
  $feedback->feedback_content = $form_state['values']['feedback_content'];
  $feedback->uid = $GLOBALS['user']->uid;
  vopros_feedback_save($feedback);

  drupal_set_message(t('Your feedback has been received. Thank you.'));
}

/**
 * Handle the display of an feedback.
 */
function vopros_feedback_page_view($feedback, $view_mode = 'administrator', $langcode = NULL) {
  return $feedback->view($view_mode, $langcode);
}
