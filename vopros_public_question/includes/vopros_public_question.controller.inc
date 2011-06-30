<?php

// Needed during install.
module_load_include('inc', 'vopros_base', 'includes/vopros.controller');

/**
 * Entity controller class for vopros question.
 */
class VoprosPublicQuestionEntityController extends VoprosAPIEntityController {
  /**
   * Creates a new instance of a vorpos_log entity.
   */
  public function create(array $values = array()) {
    return (object) ($values + array(
      'question_id' => 0,
      'uid' => 0,
      'title' => '',
      'description' => '',
      'status' => '',
      'subject' => '',
      'created' => '',
      'changed' => '',
      'is_new' => TRUE,
    ));
  }
}
