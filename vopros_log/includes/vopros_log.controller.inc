<?php

/**
 * Entity controller class for vopros question.
 */
class VoprosLogEntityController extends EntityAPIController {
  /**
   * Creates a new instance of a vopros_log entity.
   */
  public function create(array $values = array()) {
    $values = $values + array(
      'answer_id' => 0,
      'question_id' => 0,
      'uid' => 0,
      'log_content' => '',
      'created' => '',
      'changed' => '',
      'is_new' => TRUE,
    );
    return parent::create($values);
  }

  /**
   * Save function for the vopros_log entity.
   *
   * Set defaults values before the entity is saved.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    if (empty($entity->created)) {
      $entity->created = REQUEST_TIME;
    }
    $entity->changed = REQUEST_TIME;
    parent::save($entity, $transaction);
  }
}
