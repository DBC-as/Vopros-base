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
      'allow_outgoing_turn_over_sms' => FALSE,
    );
    return parent::create($values);
  }
}
