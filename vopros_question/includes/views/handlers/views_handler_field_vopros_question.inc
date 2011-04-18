<?php

class views_handler_field_vopros_question extends views_handler_field {
  function render($values) {
    $value = $this->get_value($values);
    $san = $this->sanitize_value($value);
    switch ($this->field) {
      case 'question_status':
        $statuses = _vopros_question_status();
        return isset($statuses[$san]) ? $statuses[$san] : $san;
        break;
      case 'question_usage':
        $statuses = _vopros_question_usage();
        return isset($statuses[$san]) ? $statuses[$san] : $san;
        break;
    }
    return $san;
  }
}