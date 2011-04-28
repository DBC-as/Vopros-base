<?php
class vopros_question_handler_field_date extends views_handler_field_date {
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['date_format']['#options']['vopros_question_deadline'] = t('Vopros deadline');

  }

  function render($values) {
    $format = $this->options['date_format'];
    if ($format !== 'vopros_question_deadline') {
      return parent::render($values);
    }
    $value = $this->get_value($values);
    $time_diff = REQUEST_TIME - $value;
    if ($time_diff > 0) {
      return t('Deadline passed');
    }
    elseif ($time_diff < - 6 * 7 * 86400)  { // 6 weeks
      return t('No Deadline');
    }
    else {
      return t('%time to deadline', array('%time' => format_interval(-$time_diff, 2)));
    }
    
    return 'test';
  }
}
