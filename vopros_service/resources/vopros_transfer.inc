<?php

/**
 * @file
 * Vopros transfer service functions.
 */

/**
 * Create a new forwarded question.
 */
function _vopros_service_resource_retrieve($type, $data) {
  $question = vopros_question_new();
  $service = vopros_service_current();

  // Validate basic data.
  if (empty($data['uuid']) || !uuid_is_valid($data['uuid'])) {
    services_error('Invalid UUID.', 422);
  }

  if (vopros_service_forward_load_by_uuid($data['uuid'])) {
    services_error('UUID already used.', 422);
  }
  $question->uuid = $data['uuid'];

  if (empty($data['question_title'])) {
    services_error('Invalid question_title.', 422);
  }
  $question->question_title = check_plain($data['question_title']);

  if (empty($data['question_content'])) {
    services_error('Invalid question_content.', 422);
  }
  $question->question_content = check_plain($data['question_content']);

  if (empty($data['question_deadline']) || !preg_match('/^-?[0-9]+$/', $data['question_deadline'])) {
    services_error('Invalid question_deadline.', 422);
  }
  $question->question_deadline = check_plain($data['question_deadline']);

  if (empty($data['question_deadline_timestamp']) || !preg_match('/^[0-9]+$/', $data['question_deadline_timestamp'])) {
    services_error('Invalid question_deadline_timestamp.', 422);
  }
  $question->question_deadline_timestamp = check_plain($data['question_deadline_timestamp']);

  if (empty($data['question_usage'])) {
    services_error('Invalid question_usage.', 422);
  }
  $question->question_usage = check_plain($data['question_usage']);

  $question->qanda_service_name = 'vopros_service_' . $service->service_id;

  // Handle message from upstream.
  if (!empty($data['message'])) {
    $question->question_content .= "\n\n-- " . t('Message from forwarding service') . "--\n\n" . check_plain($data['message']);
  }

  if ($type == 'turn_over') {
    // I believe most of these are optional.
    if (!empty($data['user_name'])) {
      $question->user_name = $data['user_name'];
    }
    if (!empty($data['user_email'])) {
      $question->user_email = $data['user_email'];
    }
    if (!empty($data['user_postal_code'])) {
      $question->user_postal_code = $data['user_postal_code'];
    }
    if (!empty($data['user_mobile_phone'])) {
      $question->user_mobile_phone = $data['user_mobile_phone'];
    }
    if (!empty($data['user_age'])) {
      $question->user_age = $data['user_age'];
    }
    if (!empty($data['user_gender'])) {
      $question->user_gender = $data['user_gender'];
    }
    if (!empty($data['user_field_of_study'])) {
      $question->user_field_of_study = $data['user_field_of_study'];
    }
    if (!empty($data['user_library'])) {
      $question->user_library = $data['user_library'];
    }
    if (!empty($data['user_answer_preference'])) {
      $question->user_answer_preference = $data['user_answer_preference'];
    }

    // @todo should send mail to user, notifying them about the transfer.
  }
  else {
    $question->user_name = t('Request for assistance from @service', array('@service' => $service->label));
    // Set answer preference so messages will be returned to the other Vopros.n
    $question->user_answer_preference = 'vopros_service';
  }

  // First save question.
  if (entity_save('vopros_question', $question) === FALSE) {
    services_error('Error while saving question.', 500);
  }
  // Then note that it is an external question.
  db_insert('vopros_service_question')
    ->fields(array(
        'machine_name' => $service->machine_name,
        'direction' => 'incoming',
        'type' => $type,
        'uuid' => $question->uuid,
      ))
    ->execute();
}

/**
 * Return a message or answer to the questioner.
 */
function _vopros_service_resource_send_answer($uuid, $from, $message, $answer = NULL) {
  $service = vopros_service_current();
  // Ensure that the question is transfered tranferred from us.
  $type = db_select('vopros_service_question', 'v')
    ->fields('v', array('type'))
    ->condition('machine_name', $service->machine_name)
    ->condition('direction', 'outgoing')
    ->condition('uuid', $uuid)
    ->execute()
    ->fetchField();

  if (empty($type)) {
    services_error('Question not forwarded.', 422);
  }
  elseif ($type != 'help') {
    services_error('Wrong type.', 422);
  }

  $question = vopros_question_load_by_uuid($uuid);
  if ($question) {
    if ($answer) {
      // We got an answer. Create a vopros_answer.
      $answer = vopros_answer_new(array(
                  'question_id' => $question->question_id,
                  'author_name' => $from,
                  'answer_content' => $answer,
                  'status' => 'active',
      ));
      vopros_answer_save($answer);
    }
    $message = entity_create('vopros_service_message', array(
        'question_id' => $question->question_id,
        'service_machine_name' => $service->machine_name,
        'message_type' => 'incoming',
        'message_content' => check_plain($message),
        'message_from' => check_plain($from),
      ));
    entity_save('vopros_service_message', $message);
    // Reactivate issue.
    $question->question_status = 'active';
    $question->question_status_reason = 'reactivated by external service';
    entity_save('vopros_question', $question);
  }
  else {
    services_error('Could not load question.', 422);
  }
}

/**
 * Send a message to the helper.
 */
function _vopros_service_resource_send_message($uuid, $from, $message) {
  $service = vopros_service_current();
  // Ensure that the question is transfered to us.
  $type = db_select('vopros_service_question', 'v')
    ->fields('v', array('type'))
    ->condition('machine_name', $service->machine_name)
    ->condition('direction', 'incoming')
    ->condition('uuid', $uuid)
    ->execute()
    ->fetchField();

  if (empty($type)) {
    services_error('Question not forwarded.', 422);
  }
  elseif ($type != 'help') {
    services_error('Wrong type.', 422);
  }

  $question = vopros_question_load_by_uuid($uuid);
  if ($question) {
    $message = entity_create('vopros_service_message', array(
        'question_id' => $question->question_id,
        'service_machine_name' => $service->machine_name,
        'message_type' => 'incoming',
        'message_content' => check_plain($message),
        'message_from' => check_plain($from),
      ));
    entity_save('vopros_service_message', $message);
    // Reactivate issue.
    $question->question_status = 'active';
    $question->question_status_reason = 'reactivated by external service';
    entity_save('vopros_question', $question);
  }
  else {
    services_error('Could not load question.', 422);
  }
}
