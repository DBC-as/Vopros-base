<?php

/**
 * Entity controller class for vopros question.
 */
class VoprosQuestionEntityController extends VoprosAPIEntityController {
  public function validateData($question) {
    $errors = array();
    if (!isset($question->question_title) || empty($question->question_title)) {
      $errors[] = array('question_title', t('@name is required', array('@name' => t('Question title'))));
    }
    if (!isset($question->question_content) || empty($question->question_content)) {
      $errors[] = array('question_content', t('@name is required', array('@name' => t('Question content'))));
    }
    if ($question->question_deadline && !is_numeric($question->question_deadline)) {
      $errors[] = array('question_deadline', t('@name must be numeric', array('@name' => t('Question deadline'))));
    }
    if (isset($question->question_usage) && $question->question_usage && !in_array($question->question_usage, array_keys(_vopros_question_usage()))) {
      $errors[] = array('question_usage', t('Selected option: %value not valid for @field',
        array('%value' => $question->question_usage, '@field' => t('Question usage'))
      ));
    }
    if (!isset($question->user_name) || empty($question->user_name)) {
      $errors[] = array('user_name', t('@name is required', array('@name' => t('User name'))));
    }
    if (
      (!isset($question->user_email) || empty($question->user_email)) &&
      (!isset($question->user_mobile_phone) || empty($question->user_mobile_phone))
    ) {
      $errors[] = array('user', t('@name is required', array('@name' => t('User email or mobile phone'))));
    }
    if (!empty($errors)) {
      return array('status' => 'error', 'errors' => $errors);
    }
    return array('status' => 'valid');
  }
}
