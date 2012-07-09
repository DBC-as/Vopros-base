<?php

class vopros_question_qanda_service_name_views_handler_filter_in_operator extends views_handler_filter_in_operator {
  function get_value_options() {
    if (isset($this->value_options)) {
      return;
    }
    $this->value_options = _vopros_question_qanda_serice_options();
  }
}
