<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function vopros_qna_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vopros_answers_edit';
  $context->description = 'Context for editing an answer.';
  $context->tag = 'vopros_qna';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'vopros_answer' => 'vopros_answer',
      ),
      'options' => array(
        'node_form' => '2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-vopros' => array(
          'module' => 'menu',
          'delta' => 'menu-vopros',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
      'layout' => 'sidebar',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for editing an answer.');
  t('vopros_qna');

  $export['vopros_answers_edit'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vopros_questions_edit';
  $context->description = 'Context for editing a question.';
  $context->tag = 'vopros_qna';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'vopros_question' => 'vopros_question',
      ),
      'options' => array(
        'node_form' => '2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-vopros' => array(
          'module' => 'menu',
          'delta' => 'menu-vopros',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
      'layout' => 'sidebar',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for editing a question.');
  t('vopros_qna');

  $export['vopros_questions_edit'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vopros_questions_list';
  $context->description = 'Context for viewing the questions list.';
  $context->tag = 'vopros_qna';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'vopros_questions:page_1' => 'vopros_questions:page_1',
        'vopros_questions:page_2' => 'vopros_questions:page_2',
        'vopros_questions:page_3' => 'vopros_questions:page_3',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-vopros' => array(
          'module' => 'menu',
          'delta' => 'menu-vopros',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
      'layout' => 'sidebar',
    ),
    'breadcrumb' => 'questions',
    'menu' => 'questions',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for viewing the questions list.');
  t('vopros_qna');

  $export['vopros_questions_list'] = $context;
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
        'menu-menu-vopros' => array(
          'module' => 'menu',
          'delta' => 'menu-vopros',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
      'layout' => 'sidebar',
    ),
    'breadcrumb' => 'questions',
    'menu' => 'questions',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for displaying answers, etc., when a question is viewed.');
  t('vopros_qna');

  $export['vopros_questions_view'] = $context;
  return $export;
}
