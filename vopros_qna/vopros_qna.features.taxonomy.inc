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
      'hierarchy' => '1',
      'multiple' => '0',
      'required' => '1',
      'tags' => '0',
      'module' => 'features_question_category',
      'weight' => '-10',
      'nodes' => array(
        'vopros_question' => 'vopros_question',
      ),
    ),
  );
}
