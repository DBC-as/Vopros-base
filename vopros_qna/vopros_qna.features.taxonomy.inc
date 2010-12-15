<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function vopros_qna_taxonomy_default_vocabularies() {
  return array(
    'question_category' => array(
      'name' => 'Question category',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '0',
      'required' => '0',
      'tags' => '0',
      'module' => 'features_question_category',
      'weight' => '-10',
      'type' => NULL,
      'nodes' => array(),
    ),
  );
}
