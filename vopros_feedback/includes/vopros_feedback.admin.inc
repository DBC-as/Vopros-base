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
  return $form;
}