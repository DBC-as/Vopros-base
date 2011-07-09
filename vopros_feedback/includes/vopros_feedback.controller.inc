<?php

/**
 * Entity controller class for vopros question.
 */
class VoprosFeedbackEntityController extends VoprosAPIEntityController {
  /**
   * Creates a new instance of a vorpos_log entity.
   */
  public function create(array $values = array()) {
    return (object) ($values + array(
      'answer_id' => 0,
      'question_id' => 0,
      'created' => '',
      'changed' => '',
      'is_new' => TRUE,
    ));
  }
}
