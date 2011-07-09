<?php

/**
 * @file Admin forms and menu callbacks for the vopros_feedback module.
 */

/**
 * General settings form.
 */
function vopros_feedback_settings_form($form, &$form_state) {
  return system_settings_form($form);
}

/**
 * Form for creating and editing vopros_feedback entities.
 */
function vopros_feedback_form($form, &$form_state, $feedback) {
  field_attach_form('vopros_feedback', $form, $form_state, $feedback);

  $form['feedback_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Feedback'),
    '#default_value' => $feedback->feedback_content,
    
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save feedback'),
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
  field_attach_validate('vopros_feedback', $form, $form_state, $feedback);
}

/**
 * Submit handler for vopros_feedback_form().
 */
function vopros_feedback_form_submit(&$form, &$form_state) {
  $feedback = $form_state['feedback'];
  field_attach_submit('vopros_feedback', $form, $form_state, $feedback);
  $feedback->feedback_content = $form_state['values']['feedback_content'];
  $feedback->uid = $GLOBALS['user']->uid;
  vopros_feedback_save($feedback);
}

function vopros_feedback_page_view($feedback) {
  return 'Not implemented yet.';
}