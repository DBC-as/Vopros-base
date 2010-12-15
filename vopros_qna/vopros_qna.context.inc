<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function vopros_qna_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vopros_questions_view';
  $context->description = 'Context for displaying answers, etc., when a question is viewed.';
  $context->tag = 'vopros_qna';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'vopros_question' => 'vopros_question',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-vopros_answers-block_1' => array(
          'module' => 'views',
          'delta' => 'vopros_answers-block_1',
          'region' => 'content',
          'weight' => 0,
        ),
      ),
      'layout' => 'sidebar',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for displaying answers, etc., when a question is viewed.');
  t('vopros_qna');

  $export['vopros_questions_view'] = $context;
  return $export;
}
