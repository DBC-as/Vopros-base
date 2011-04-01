<?php

/**
 * @ file
 * Admin forms and callback functions.
 */

/**
 * Question settings form
 */
function vopros_question_settings_form($form, &$form_state) {
  return system_settings_form($form);
}