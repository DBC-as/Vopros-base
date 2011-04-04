<?php

/**
 * Implements hook_views_default_views().
 */
function vopros_question_views_default_views() {
  $views = array();

  $view = new view;
  $view->name = 'vopros_question_admin';
  $view->description = 'Displays a question for admins';
  $view->tag = 'default';
  $view->base_table = 'vopros_question';
  $view->human_name = 'Question admin view';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Question: Label */
  $handler->display->display_options['fields']['question_title']['id'] = 'question_title';
  $handler->display->display_options['fields']['question_title']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_title']['field'] = 'question_title';
  $handler->display->display_options['fields']['question_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_title']['empty_zero'] = 0;
  /* Field: Question: Question_content */
  $handler->display->display_options['fields']['question_content']['id'] = 'question_content';
  $handler->display->display_options['fields']['question_content']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_content']['field'] = 'question_content';
  $handler->display->display_options['fields']['question_content']['label'] = 'Question';
  $handler->display->display_options['fields']['question_content']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['question_content']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['question_content']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['question_content']['alter']['external'] = 0;
  $handler->display->display_options['fields']['question_content']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['question_content']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_content']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_content']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_content']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_content']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_content']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_content']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_content']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_content']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_content']['empty_zero'] = 0;
  /* Field: Question: Question_note */
  $handler->display->display_options['fields']['question_note']['id'] = 'question_note';
  $handler->display->display_options['fields']['question_note']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_note']['field'] = 'question_note';
  $handler->display->display_options['fields']['question_note']['label'] = 'Note from user';
  $handler->display->display_options['fields']['question_note']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['question_note']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['question_note']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['question_note']['alter']['external'] = 0;
  $handler->display->display_options['fields']['question_note']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['question_note']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_note']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_note']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_note']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_note']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_note']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_note']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_note']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_note']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_note']['empty_zero'] = 0;
  /* Field: Question: Question_deadline */
  $handler->display->display_options['fields']['question_deadline']['id'] = 'question_deadline';
  $handler->display->display_options['fields']['question_deadline']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_deadline']['field'] = 'question_deadline';
  $handler->display->display_options['fields']['question_deadline']['label'] = 'Deadline';
  $handler->display->display_options['fields']['question_deadline']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['question_deadline']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['question_deadline']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['question_deadline']['alter']['external'] = 0;
  $handler->display->display_options['fields']['question_deadline']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['question_deadline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_deadline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_deadline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_deadline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_deadline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_deadline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_deadline']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_deadline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_deadline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_deadline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_deadline']['format_plural'] = 0;
  /* Field: Question: Question_status */
  $handler->display->display_options['fields']['question_status']['id'] = 'question_status';
  $handler->display->display_options['fields']['question_status']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_status']['field'] = 'question_status';
  $handler->display->display_options['fields']['question_status']['label'] = 'Status';
  $handler->display->display_options['fields']['question_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['question_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['question_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['question_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['question_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['question_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_status']['empty_zero'] = 0;
  /* Field: Question: Referenced_by */
  $handler->display->display_options['fields']['referenced_by']['id'] = 'referenced_by';
  $handler->display->display_options['fields']['referenced_by']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['referenced_by']['field'] = 'referenced_by';
  $handler->display->display_options['fields']['referenced_by']['label'] = 'Referenced by';
  $handler->display->display_options['fields']['referenced_by']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['referenced_by']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['referenced_by']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['referenced_by']['alter']['external'] = 0;
  $handler->display->display_options['fields']['referenced_by']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['referenced_by']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['referenced_by']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['referenced_by']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['referenced_by']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['referenced_by']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['referenced_by']['alter']['html'] = 0;
  $handler->display->display_options['fields']['referenced_by']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['referenced_by']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['referenced_by']['hide_empty'] = 0;
  $handler->display->display_options['fields']['referenced_by']['empty_zero'] = 0;
  /* Field: Question: Question_usage */
  $handler->display->display_options['fields']['question_usage']['id'] = 'question_usage';
  $handler->display->display_options['fields']['question_usage']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_usage']['field'] = 'question_usage';
  $handler->display->display_options['fields']['question_usage']['label'] = 'Usage';
  $handler->display->display_options['fields']['question_usage']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['question_usage']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['question_usage']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['question_usage']['alter']['external'] = 0;
  $handler->display->display_options['fields']['question_usage']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['question_usage']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_usage']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_usage']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_usage']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_usage']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_usage']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_usage']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_usage']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_usage']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_usage']['empty_zero'] = 0;
  /* Field: Question: User_name */
  $handler->display->display_options['fields']['user_name']['id'] = 'user_name';
  $handler->display->display_options['fields']['user_name']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['user_name']['field'] = 'user_name';
  $handler->display->display_options['fields']['user_name']['label'] = 'User\'s name';
  $handler->display->display_options['fields']['user_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['user_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['user_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['user_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['user_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['user_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['user_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['user_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['user_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['user_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['user_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['user_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['user_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['user_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['user_name']['empty_zero'] = 0;
  /* Field: Question: User_age */
  $handler->display->display_options['fields']['user_age']['id'] = 'user_age';
  $handler->display->display_options['fields']['user_age']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['user_age']['field'] = 'user_age';
  $handler->display->display_options['fields']['user_age']['label'] = 'User\'s age';
  $handler->display->display_options['fields']['user_age']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['user_age']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['user_age']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['user_age']['alter']['external'] = 0;
  $handler->display->display_options['fields']['user_age']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['user_age']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['user_age']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['user_age']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['user_age']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['user_age']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['user_age']['alter']['html'] = 0;
  $handler->display->display_options['fields']['user_age']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['user_age']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['user_age']['hide_empty'] = 0;
  $handler->display->display_options['fields']['user_age']['empty_zero'] = 0;
  $handler->display->display_options['fields']['user_age']['format_plural'] = 0;
  /* Field: Question: User_field_of_study */
  $handler->display->display_options['fields']['user_field_of_study']['id'] = 'user_field_of_study';
  $handler->display->display_options['fields']['user_field_of_study']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['user_field_of_study']['field'] = 'user_field_of_study';
  $handler->display->display_options['fields']['user_field_of_study']['label'] = 'User\'s field of study';
  $handler->display->display_options['fields']['user_field_of_study']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['user_field_of_study']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['user_field_of_study']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['user_field_of_study']['alter']['external'] = 0;
  $handler->display->display_options['fields']['user_field_of_study']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['user_field_of_study']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['user_field_of_study']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['user_field_of_study']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['user_field_of_study']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['user_field_of_study']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['user_field_of_study']['alter']['html'] = 0;
  $handler->display->display_options['fields']['user_field_of_study']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['user_field_of_study']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['user_field_of_study']['hide_empty'] = 0;
  $handler->display->display_options['fields']['user_field_of_study']['empty_zero'] = 0;
  /* Field: Question: User_postal_code */
  $handler->display->display_options['fields']['user_postal_code']['id'] = 'user_postal_code';
  $handler->display->display_options['fields']['user_postal_code']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['user_postal_code']['field'] = 'user_postal_code';
  $handler->display->display_options['fields']['user_postal_code']['label'] = 'User\'s posta code';
  $handler->display->display_options['fields']['user_postal_code']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['user_postal_code']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['user_postal_code']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['user_postal_code']['alter']['external'] = 0;
  $handler->display->display_options['fields']['user_postal_code']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['user_postal_code']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['user_postal_code']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['user_postal_code']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['user_postal_code']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['user_postal_code']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['user_postal_code']['alter']['html'] = 0;
  $handler->display->display_options['fields']['user_postal_code']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['user_postal_code']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['user_postal_code']['hide_empty'] = 0;
  $handler->display->display_options['fields']['user_postal_code']['empty_zero'] = 0;
  /* Field: Question: User_library */
  $handler->display->display_options['fields']['user_library']['id'] = 'user_library';
  $handler->display->display_options['fields']['user_library']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['user_library']['field'] = 'user_library';
  $handler->display->display_options['fields']['user_library']['label'] = 'User\'s library';
  $handler->display->display_options['fields']['user_library']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['user_library']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['user_library']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['user_library']['alter']['external'] = 0;
  $handler->display->display_options['fields']['user_library']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['user_library']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['user_library']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['user_library']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['user_library']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['user_library']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['user_library']['alter']['html'] = 0;
  $handler->display->display_options['fields']['user_library']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['user_library']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['user_library']['hide_empty'] = 0;
  $handler->display->display_options['fields']['user_library']['empty_zero'] = 0;
  /* Contextual filter: Question: Question ID */
  $handler->display->display_options['arguments']['question_id']['id'] = 'question_id';
  $handler->display->display_options['arguments']['question_id']['table'] = 'vopros_question';
  $handler->display->display_options['arguments']['question_id']['field'] = 'question_id';
  $handler->display->display_options['arguments']['question_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['question_id']['title_enable'] = 1;
  $handler->display->display_options['arguments']['question_id']['title'] = '%1';
  $handler->display->display_options['arguments']['question_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['question_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['question_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['question_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['question_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['question_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['question_id']['not'] = 0;

  /* Display: Page */
  $translatables['vopros_question_admin'] = array(
    t('Displays a question for admins'),
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Label'),
    t('Question'),
    t('Note from user'),
    t('Deadline'),
    t('.'),
    t(','),
    t('Status'),
    t('Referenced by'),
    t('Usage'),
    t('User\'s name'),
    t('User\'s age'),
    t('User\'s field of study'),
    t('User\'s posta code'),
    t('User\'s library'),
    t('All'),
    t('%1'),
    t('Page'),
  );

  $views[$view->name] = $view;

  return $views;
}
