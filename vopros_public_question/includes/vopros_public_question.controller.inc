<?php

// Needed during install.
module_load_include('inc', 'vopros_base', 'includes/vopros.controller');

/**
 * Entity controller class for vopros question.
 */
class VoprosPublicQuestionEntityController extends VoprosAPIEntityController {
  /**
   * Creates a new instance of a vopros_log entity.
   */
  public function create(array $values = array()) {
    $values = $values + array(
      'question_id' => 0,
      'uid' => 0,
      'title' => '',
      'question_content' => '',
      'answer_content' => '',
      'question_content_format' => variable_get('vopros_public_question_default_text_format', 'plain_text'),
      'answer_content_format' => variable_get('vopros_public_question_default_text_format', 'plain_text'),
      'description' => '',
      'status' => 'unpublished',
      'subject' => '',
      'created' => '',
      'changed' => '',
      'is_new' => TRUE,
    );
    return parent::create($values);
  }
}
