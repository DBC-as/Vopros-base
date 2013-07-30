<?php

/**
 * Entity controller class for vopros question messages.
 */
class VoprosServiceMessageEntityController extends EntityAPIController {
  /**
   * Creates a new instance of a vopros_service_message entity.
   */
  public function create(array $values = array()) {
    $values = $values + array(
      'service_messageid' => 0,
      'question_id' => 0,
      'message_type' => '',
      'message_content' => '',
      'message_from' => '',
      'message_uid' => 0,
      'created' => REQUEST_TIME,
    );
    return parent::create($values);
  }


  /**
   * Implements EntityAPIControllerInterface.
   *
   * @param $content
   *   Optionally. Allows pre-populating the built content to ease overridding
   *   this method.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $content['message_from'] = array(
      '#markup' => $entity->message_from,
    );

    $content['message_content'] = array(
      '#markup' => $entity->message_content,
    );

    return parent::buildContent($entity, $view_mode, $langcode, $content);
  }

}
