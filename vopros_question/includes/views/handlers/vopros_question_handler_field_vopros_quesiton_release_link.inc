<?php
class vopros_question_handler_field_vopros_quesiton_release_link extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['agreement_id'] = 'question_id';
    $this->real_field = 'question_id';
  }

  function render($values) {
    $question_id = $this->get_value($values);
    if (empty($question_id)) {
      return '';
    }

    return l('Release', 'admin/vopros/questions/' . $question_id . '/release');
  }
}
