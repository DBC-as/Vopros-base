<?php

/**
 * Entity controller class for vopros question.
 */
class VoprosServiceEntityController extends VoprosAPIEntityController {
  /**
   * Creates a new instance of a vopros_log entity.
   */
  public function create(array $values = array()) {
    $values = $values + array(
      'service_id' => 0,
      'machine_name' => '',
      'label' => '',
      'url' => '',
      'auth_key' => '',
      'auth_type' => 'secret_key',
      'allow_ingoing' => FALSE,
      'allow_outgoing_help' => FALSE,
      'allow_outgoing_turn_over' => FALSE,
    );
    return parent::create($values);
  }
}

/**
 * Entity controller class for vopros question.
 */
class VoprosServiceMessageEntityController extends VoprosAPIEntityController {
  /**
   * Creates a new instance of a vopros_log entity.
   */
  public function create(array $values = array()) {
    $values = $values + array(
      'message_id' => 0,
      'message_content' => '',
      'answer_id' => 0,
      'sender_service_id' => 0,
      'receiver_service_id' => 0,
    );
    return parent::create($values);
  }
}

