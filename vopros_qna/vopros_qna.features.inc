<?php

/**
 * Implementation of hook_node_info().
 */
function vopros_qna_node_info() {
  $items = array(
    'vopros_answer' => array(
      'name' => t('Answer'),
      'module' => 'features',
      'description' => t('Answer to a Vopros question, usually posted by a staff member.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Answer'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'vopros_question' => array(
      'name' => t('Spørgsmål'),
      'module' => 'features',
      'description' => t('Et spørgsmål fra en bruger.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'has_body' => '1',
      'body_label' => t('Spørgsmål'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function vopros_qna_views_api() {
  return array(
    'api' => '2',
  );
}
