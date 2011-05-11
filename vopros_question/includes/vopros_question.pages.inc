<?php

/**
 * @ file
 * Public page callback functions.
 */

/**
 * Page callback to create questions.
 *
 * Used by Open Question to create questions
 */
function vopros_question_create_service() {
  $question = vopros_question_new();
  $question_wrapper = entity_metadata_wrapper('vopros_question', $question);
  $post_data = array();
  // Reformat all the post data to not use CamelCase.
  foreach ($_POST as $key => $value) {
    $post_data[strtolower(preg_replace('/(?<=\\w)(?=[A-Z])/',"_$1", $key))] = $value;
  }
  $properties = $question_wrapper->getPropertyInfo();
  // Populate the question with the needed info
  foreach ($properties as $property => $info) {
    if (isset($post_data[$property])) {
      $question->{$property} = $post_data[$property];
    }
  }
  $validation = vopros_question_validate_data($question);
  if ($validation['status'] == 'valid') {
    $question_wrapper->save();
    print t('Question created');
    exit();
  }
  drupal_add_http_header('Status', '400');
  $errors = array();
  foreach ($validation['errors'] as $value) {
    $errors[] = $value[0];
  }
  watchdog('vopros_question', 'Could not create vopros question, invalid data for: %fields', array('%fields' => implode(', ', $errors)), WATCHDOG_ERROR);
  print t('Question not created');
  exit();
}

/**
 * Page callback to create questions.
 *
 * Used by SMS service to create questions
 */
function vopros_question_create_sms() {
  $default_values = array(
    'user_answer_preference' => 'sms',
    'agency_id' => 'SMS1919',
  );

  $question = vopros_question_new($default_values);
  $message = isset($_GET['msg']) ? iconv( 'CP1252', 'UTF-8', $_GET['msg']) : '';
  $phone = isset($_GET['origin']) ? $_GET['origin'] : '';
  if ($message && $phone) {
    $words = explode(' ', $message);
    $keyword = array_shift($words);
    $question->qanda_service_name = $keyword;
    $question->question_content = implode(' ', $words);
    $question->user_mobile_phone = $phone;
    vopros_question_save($question);
  }
  $output = 
'<?xml version="1.0" encoding="iso-8859-1"?>
  <action>
    <type>terminate</type>
  </action>';
  print $output;
  exit();
}
