<?php

/**
 * Entity controller class for vopros question.
 */
class VoprosAnswerEntityController extends VoprosAPIEntityController {
  /**
   * Creates a new instance of a vopros_question entity.
   */
  public function create(array $values = array()) {
    return (object) ($values + array(
      'question_id' => 0,
      'uid' => 0,
      'answer_content' => '',
      'status' => 'active',
      'author_name' => '',
      'is_new' => TRUE,
      'created' => NULL,
      'changed' => NULL,
    ));
  }
}
