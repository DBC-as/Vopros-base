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
    'body_field' => '35',
    'revision_information' => '40',
    'author' => '39',
    'options' => '41',
    'menu' => '34',
    'path' => '42',
    'path_redirect' => '43',
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
  return $export;
}
