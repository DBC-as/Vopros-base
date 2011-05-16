<?php

class vopros_question_usage_views_handler_filter_string extends views_handler_filter_string {
  function value_form(&$form, &$form_state) {
    $form['value']['#tree'] = TRUE;
    $form['value']['value'] = array(
      '#type' => 'select',
      '#title' => empty($form_state['exposed']) ? t('Value') : '',
      '#options' => array('' => t('All')) + _vopros_question_usage(),
      '#default_value' => $this->value['value'],
      '#multiple' => FALSE,
    );
  }
}
