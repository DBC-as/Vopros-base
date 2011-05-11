<?php

class vopros_question_status_views_handler_filter_string extends views_handler_filter_string {
  function value_form(&$form, &$form_state) {
    parent::value_form(&$form, &$form_state);
    if (isset($form['value'])) {
      $form['value']['#type'] = 'select';
      $form['value']['#options'] = _vopros_question_status();
      $form['value']['#multiple'] = FALSE;
    }
  }
}
