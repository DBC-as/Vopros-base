<?php

/**
 * Implementation of hook_strongarm().
 */
function vopros_qna_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_vopros_answer';
  $strongarm->value = '';

  $export['ant_pattern_vopros_answer'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_vopros_question';
  $strongarm->value = 'Spørgsmål stillet til [field_question_service-formatted] [small] ([field_question_answer_usage-formatted])';

  $export['ant_pattern_vopros_question'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_vopros_answer';
  $strongarm->value = '0';

  $export['ant_vopros_answer'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_vopros_question';
  $strongarm->value = '2';

  $export['ant_vopros_question'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_vopros_answer';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-2',
    'revision_information' => '2',
    'author' => '1',
    'options' => '3',
    'menu' => '-4',
    'path' => '5',
    'path_redirect' => '4',
  );

  $export['content_extra_weights_vopros_answer'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_vopros_question';
  $strongarm->value = array(
    'title' => '32',
    'body_field' => '36',
    'revision_information' => '42',
    'author' => '41',
    'options' => '43',
    'menu' => '35',
    'path' => '44',
    'path_redirect' => '45',
  );

  $export['content_extra_weights_vopros_question'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_vopros_answer';
  $strongarm->value = '0';

  $export['language_content_type_vopros_answer'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_vopros_question';
  $strongarm->value = '0';

  $export['language_content_type_vopros_question'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_vopros_answer';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_vopros_answer'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_vopros_question';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_vopros_question'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_vopros_question_default';
  $strongarm->value = array(
    'title' => array(
      'region' => 'main',
      'weight' => '0',
      'has_required' => FALSE,
      'title' => 'Titel',
      'hidden' => 0,
    ),
    'body_field' => array(
      'region' => 'main',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'menu' => array(
      'region' => 'right',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'Menu settings',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'revision_information' => array(
      'region' => 'right',
      'weight' => '6',
      'has_required' => FALSE,
      'title' => 'Revision information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'path' => array(
      'region' => 'right',
      'weight' => '8',
      'has_required' => FALSE,
      'title' => 'URL path settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'options' => array(
      'region' => 'right',
      'weight' => '7',
      'has_required' => FALSE,
      'title' => 'Publishing options',
      'collapsed' => 0,
      'hidden' => 0,
    ),
    'author' => array(
      'region' => 'right',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'Authoring information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'buttons' => array(
      'region' => 'main',
      'weight' => '9',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'field_question_service' => array(
      'region' => 'right',
      'weight' => '2',
      'has_required' => TRUE,
      'title' => 'Spørgetjeneste',
    ),
    'field_question_status' => array(
      'region' => 'right',
      'weight' => '0',
      'has_required' => TRUE,
      'title' => 'Status',
    ),
    'field_question_category' => array(
      'region' => 'right',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'Kategori',
      'hidden' => 0,
    ),
    'field_question_deadline' => array(
      'region' => 'right',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Tidsfrist',
      'hidden' => 0,
    ),
    'field_question_answer_usage' => array(
      'region' => 'right',
      'weight' => '3',
      'has_required' => TRUE,
      'title' => 'Svarets anvendelse',
    ),
    'field_question_already_searched' => array(
      'region' => 'main',
      'weight' => '8',
      'has_required' => FALSE,
      'title' => 'Allerede søgt',
      'hidden' => 0,
    ),
    'group_question_inquirer' => array(
      'region' => 'main',
      'weight' => '5',
      'has_required' => TRUE,
      'title' => 'Spørgerens data',
      'collapsed' => 0,
    ),
  );

  $export['nodeformscols_field_placements_vopros_question_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_vopros_answer_pattern';
  $strongarm->value = '';

  $export['pathauto_node_vopros_answer_pattern'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_vopros_question_pattern';
  $strongarm->value = 'question/[nid]-[title-raw]';

  $export['pathauto_node_vopros_question_pattern'] = $strongarm;
  return $export;
}
