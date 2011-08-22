<?php

/**
 * Entity controller class for vopros question.
 */
class VoprosFeedbackEntityController extends EntityAPIController {
  /**
   * Creates a new instance of a vopros_log entity.
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
   * Save function for the vopros_log entity.
   *
   * Set defaults values before the entity is saved.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $time = REQUEST_TIME;
    if (empty($entity->created)) {
      $entity->created = $time;
    }
    // Act when creating a new feedback that has a reference to a question.
    // Remove direct relationship to question.
    if (empty($entity->feedback_id) && !empty($entity->question_id)) {
      db_update('vopros_feedback')
        ->fields(array('question_id' => 0))
        ->condition('question_id', $entity->question_id)
        ->execute();
    }
    $entity->changed = $time;
    parent::save($entity, $transaction);
  }
}
