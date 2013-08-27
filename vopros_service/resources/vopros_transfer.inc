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
  $question->question_title = $data['question_title'];

  if (empty($data['question_content'])) {
    services_error('Invalid question_content.', 422);
  }
  $question->question_content = $data['question_content'];

  if (empty($data['question_deadline']) || !preg_match('/^-?[0-9]+$/', $data['question_deadline'])) {
    services_error('Invalid question_deadline.', 422);
  }
  $question->question_deadline = $data['question_deadline'];

  if (empty($data['question_deadline_timestamp']) || !preg_match('/^[0-9]+$/', $data['question_deadline_timestamp'])) {
    services_error('Invalid question_deadline_timestamp.', 422);
  }
  $question->question_deadline_timestamp = $data['question_deadline_timestamp'];

  if (empty($data['question_usage'])) {
    services_error('Invalid question_usage.', 422);
  }
  $question->question_usage = $data['question_usage'];

  $question->qanda_service_name = 'vopros_service_' . $service->service_id;

  // Handle message from upstream.
  if (!empty($data['message'])) {
    $question->question_content .= "\n\n-- " . t('Message from forwarding service') . "--\n\n" . $data['message'];
  }

  if ($type == 'help') {
    $question->user_name = t('Request for assistance from @service', array('@service' => $service->label));
    // Set answer preference so messages will be returned to the other Vopros.
    $question->user_answer_preference = 'vopros_service';
  }
  else {
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

    if (!empty($data['vopros_question_attachment'])) {
      // Use wrapper, to get it to deal with all the field stuff.
      $question_wrapper = entity_metadata_wrapper('vopros_question', $question);

      foreach ($data['vopros_question_attachment'] as $raw_file) {
        // Generate a name if none was supplied.
        $path = !empty($raw_file['name']) ? file_default_scheme() . '://' . $raw_file['name'] : NULL;
        $data = base64_decode($raw_file['data']);
        if ($data !== FALSE) {
          $file = file_save_data($data, $path);
          if ($file) {
            $file_data = array(
              'fid' => $file->fid,
              'display' => 1,
              'description' => '',
            );
            $question_wrapper->vopros_question_attachment[] = $file_data;
          }
        }
      }
    }
  }

  // Set the service on the object so other modules can react to service created
  // questions.
  $question->vopros_service = $service;

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

  // Finally notify user of transfer.
  if ($type != 'help') {
    _vopros_service_question_takeover_notification($service, $question);
  }
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
    $message = entity_create('vopros_service_message', array(
        'question_id' => $question->question_id,
        'service_machine_name' => $service->machine_name,
        'message_type' => 'incoming',
        'message_content' => $message,
        'message_from' => $from,
        'message_answer' => trim($answer),
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
        'message_content' => $message,
        'message_from' => $from,
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
