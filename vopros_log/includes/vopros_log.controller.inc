<?php

/**
 * Entity controller class for vopros question.
 */
class VoprosLogEntityController extends EntityAPIController {
  /**
   * Creates a new instance of a vorpos_log entity.
   */
  public function create(array $values = array()) {
    return (object) ($values + array(
      'answer_id' => 0,
      'question_id' => 0,
      'uid' => 0,
      'log_content' => '',
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
