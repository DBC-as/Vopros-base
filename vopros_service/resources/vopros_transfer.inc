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
  // Validate basic data.
  if (empty($data['uuid']) || !uuid_is_valid($data['uuid'])) {
    services_error('Invalid UUID.', 422);
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

  // Handle message from upstream.
  if (!empty($data['message'])) {
    $question->question_content .= "\n\n-- " . t('Message from forwarding service') . "--\n\n" . check_plain($data['message']);
  }

  services_error('Not implemented.', 500);
}

/**
 * Return a message or answer to the questioner.
 */
function _vopros_service_resource_send_answer($uuid, $message, $answer = NULL) {
  services_error('Not implemented.', 500);
}

/**
 * Send a message to the helper.
 */
function _vopros_service_resource_send_message($uuid, $message) {
  services_error('Not implemented.', 500);
}
