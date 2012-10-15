<?php

/**
 * Entity controller class for vopros question.
 */
class VoprosFeedbackEntityController extends EntityAPIController {
  /**
   * Creates a new instance of a vopros_log entity.
   */
  public function create(array $values = array()) {
    $values = $values + array(
      'email_id' => 0,
      'question_id' => 0,
      'feedback_content' => '',
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
    // Notify users about the rating.
      vopros_feedback_notify($entity);
  }

  /**
   * Implements EntityAPIControllerInterface.
   *
   * @param $content
   *   Optionally. Allows pre-populating the built content to ease overridding
   *   this method.
   */
  function buildContent($feedback, $view_mode = 'full', $langcode = NULL, $content = array()) {
    // Add extra fields
    $content['feedback_content'] = array(
      '#theme' => 'vopros_feedback_content',
      '#feedback' => $feedback,
      '#view_mode' => $view_mode,
    );
    // Let entity API handle the boring stuff.
    return parent::buildContent($feedback, $view_mode, $langcode, $content);
  }
}
