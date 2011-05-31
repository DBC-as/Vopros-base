<?php

class vopros_email_handler_field_vopros_email extends views_handler_field {
  function render($values) {
    $value = $this->get_value($values);
    $san = $this->sanitize_value($value);
    switch ($this->field) {
      case 'type':
        $options = _vopros_email_type();
        return isset($options[$san]) ? $options[$san] : $san;
        break;
    }
    return $san;
  }
}