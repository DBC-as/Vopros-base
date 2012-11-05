<?php

/**
 * Entity controller class for vopros question.
 */
class VoprosEmailEntityController extends VoprosAPIEntityController {
  /**
   * Creates a new instance of a vopros_log entity.
   */
  public function create(array $values = array()) {
    $values = $values + array(
      'answer_id' => 0,
      'question_id' => 0,
      'uid' => 0,
      'email' => '',
      'email_content' => '',
      'subject' => '',
      'type' => '',
      'created' => '',
      'changed' => '',
      'is_new' => TRUE,
    );
    return parent::create($value);
  }
}
