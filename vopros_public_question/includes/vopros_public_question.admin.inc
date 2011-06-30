<?php

/**
 * Admin forms and page callbacks for vopros public question module.
 */

/**
 * General settings form.
 */
function vopros_public_question_settings_form($form, &$form_state) {
  $form['markup'] = array(
    '#markup' => t('No settings yet.'),
  );
  return system_settings_form($form);
}
