<?php

class vopros_question_status_views_handler_filter_in_operator extends views_handler_filter_in_operator {
  // Used to convert fake options to real ones.
  function init(&$view, &$options) {
    parent::init($view, $options);
    if (isset($this->value) && is_array($this->value)) {
      foreach ($this->value as $key => $value) {
        if ($value == 'open') {
          unset($this->value[$key]);
          $this->value += array('new', 'active');
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
      if ($value == 'open') {
        unset($this->value[$key]);
        $this->value += array('new', 'active');
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
    // Notice options are not automatically synced.
    // @see _vopros_question_status().
    $mapping = _vopros_question_status();
    // Small hack, use $this->query to determine if we are on the admin
    // interface or on an exposed filter.
    if ($this->query == NULL) {
      $this->value_options = $mapping;
    }
    else {
      $options = array(
        t('Open') => array(
          'open' => t('All open'),
          'new' => $mapping['new'],
          'active' => t('Active', array(), array('context' => 'plural form')),
        ),
        'assigned' => $mapping['assigned'],
        t('Closed') => array(
          'all_closed' => t('All closed'),
          'answered' => $mapping['answered'],
          'closed' => $mapping['closed'],
        ),
      );
      $this->value_options = $options;
    }
    
  }
}
