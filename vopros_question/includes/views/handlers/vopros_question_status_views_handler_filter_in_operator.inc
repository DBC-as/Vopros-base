<?php

class vopros_question_status_views_handler_filter_in_operator extends views_handler_filter_in_operator {
  // Used to convert fake options to real ones.
  function init(&$view, &$options) {
    parent::init($view, $options);
    if (isset($this->value) && is_array(this->$this->value)) {
      foreach ($this->value as $key => $value) {
        if ($value == 'active') {
          unset($this->value[$key]);
          $this->value += array('new', 'in_progress');
        }
        elseif ($value == 'all_closed') {
          unset($this->value[$key]);
          $this->value += array('closed', 'answered');
        }
      }
    }
  }
  // Used to convert fake options to real ones.
  function accept_exposed_input($input) {
    $value = parent::accept_exposed_input($input);
    foreach ($this->value as $key => $value) {
      if ($value == 'active') {
        unset($this->value[$key]);
        $this->value += array('new', 'in_progress');
      }
      elseif ($value == 'all_closed') {
        unset($this->value[$key]);
        $this->value += array('closed', 'answered');
      }
    }
    return $value;
  }

  function get_value_options() {
    if (isset($this->value_options)) {
      return;
    }
    $this->value_options = array('active' => t('Active'), 'all_closed' => t('Closed')) + _vopros_question_status();
  }
}
