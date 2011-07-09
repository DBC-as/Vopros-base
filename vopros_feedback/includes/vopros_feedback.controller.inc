<?php

/**
 * Entity controller class for vopros question.
 */
class VoprosFeedbackEntityController extends EntityAPIController {
  /**
   * Creates a new instance of a vorpos_log entity.
   */
  public function create(array $values = array()) {
    return (object) ($values + array(
      'email_id' => 0,
      'question_id' => 0,
      'feedback_content' => '',
      'created' => '',
      'changed' => '',
      'is_new' => TRUE,
    ));
  }

  /**
   * Save function for the vorpos_log entity.
   *
   * Set defaults values before the entity is saved.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $time = time();
    if (empty($entity->created)) {
      $entity->created = $time;
    }
    $entity->changed = $time;
    parent::save($entity, $transaction);
  }
}
