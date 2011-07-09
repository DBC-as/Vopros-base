<?php

/**
 * Implements hook_views_default_views().
 */
function vopros_search_views_default_views() {
  $views = array();

  // Search page
  $view = new view;
  $view->name = 'vopros_search_solr';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_answer_and_question';
  $view->human_name = 'Solr Search';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Question: Question URL */
  $handler->display->display_options['fields']['question_url']['id'] = 'question_url';
  $handler->display->display_options['fields']['question_url']['table'] = 'search_api_index_answer_and_question';
  $handler->display->display_options['fields']['question_url']['field'] = 'question_url';
  $handler->display->display_options['fields']['question_url']['label'] = '';
  $handler->display->display_options['fields']['question_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['question_url']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['question_url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['question_url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['question_url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['question_url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['question_url']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['question_url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['question_url']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_url']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['question_url']['link_to_entity'] = 0;
  /* Field: Question: Question_status_reason */
  $handler->display->display_options['fields']['question_question_status_reason']['id'] = 'question_question_status_reason';
  $handler->display->display_options['fields']['question_question_status_reason']['table'] = 'search_api_index_answer_and_question';
  $handler->display->display_options['fields']['question_question_status_reason']['field'] = 'question_question_status_reason';
  $handler->display->display_options['fields']['question_question_status_reason']['label'] = '';
  $handler->display->display_options['fields']['question_question_status_reason']['exclude'] = TRUE;
  $handler->display->display_options['fields']['question_question_status_reason']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['question_question_status_reason']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['question_question_status_reason']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['question_question_status_reason']['alter']['external'] = 0;
  $handler->display->display_options['fields']['question_question_status_reason']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['question_question_status_reason']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['question_question_status_reason']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_question_status_reason']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_question_status_reason']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_question_status_reason']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_question_status_reason']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_question_status_reason']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_question_status_reason']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['question_question_status_reason']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_question_status_reason']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_question_status_reason']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_question_status_reason']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['question_question_status_reason']['link_to_entity'] = 0;
  /* Field: Question: Question_title */
  $handler->display->display_options['fields']['question_question_title']['id'] = 'question_question_title';
  $handler->display->display_options['fields']['question_question_title']['table'] = 'search_api_index_answer_and_question';
  $handler->display->display_options['fields']['question_question_title']['field'] = 'question_question_title';
  $handler->display->display_options['fields']['question_question_title']['label'] = '';
  $handler->display->display_options['fields']['question_question_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['question_question_title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['question_question_title']['alter']['path'] = '[question_url]';
  $handler->display->display_options['fields']['question_question_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['question_question_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['question_question_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['question_question_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['question_question_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_question_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_question_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_question_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_question_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_question_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_question_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['question_question_title']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['question_question_title']['element_wrapper_class'] = 'question-title';
  $handler->display->display_options['fields']['question_question_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_question_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_question_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_question_title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['question_question_title']['link_to_entity'] = 0;
  /* Field: Question: Created */
  $handler->display->display_options['fields']['question_created']['id'] = 'question_created';
  $handler->display->display_options['fields']['question_created']['table'] = 'search_api_index_answer_and_question';
  $handler->display->display_options['fields']['question_created']['field'] = 'question_created';
  $handler->display->display_options['fields']['question_created']['label'] = 'Asked';
  $handler->display->display_options['fields']['question_created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['question_created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['question_created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['question_created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['question_created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['question_created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['question_created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['question_created']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['question_created']['format'] = array(
    'type' => 'short',
    'custom' => '',
    'granularity' => '1',
  );
  /* Field: Question: Question_status */
  $handler->display->display_options['fields']['question_question_status']['id'] = 'question_question_status';
  $handler->display->display_options['fields']['question_question_status']['table'] = 'search_api_index_answer_and_question';
  $handler->display->display_options['fields']['question_question_status']['field'] = 'question_question_status';
  $handler->display->display_options['fields']['question_question_status']['label'] = 'Status';
  $handler->display->display_options['fields']['question_question_status']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['question_question_status']['alter']['text'] = '[question_question_status] ([question_question_status_reason])';
  $handler->display->display_options['fields']['question_question_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['question_question_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['question_question_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['question_question_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['question_question_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['question_question_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_question_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_question_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_question_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_question_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_question_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_question_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_question_status']['element_wrapper_type'] = 'strong';
  $handler->display->display_options['fields']['question_question_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_question_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_question_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_question_status']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['question_question_status']['link_to_entity'] = 0;
  /* Field: Question: Question_content */
  $handler->display->display_options['fields']['question_question_content']['id'] = 'question_question_content';
  $handler->display->display_options['fields']['question_question_content']['table'] = 'search_api_index_answer_and_question';
  $handler->display->display_options['fields']['question_question_content']['field'] = 'question_question_content';
  $handler->display->display_options['fields']['question_question_content']['label'] = '';
  $handler->display->display_options['fields']['question_question_content']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['question_question_content']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['question_question_content']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['question_question_content']['alter']['external'] = 0;
  $handler->display->display_options['fields']['question_question_content']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['question_question_content']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['question_question_content']['alter']['nl2br'] = 1;
  $handler->display->display_options['fields']['question_question_content']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['question_question_content']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_question_content']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_question_content']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_question_content']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['question_question_content']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_question_content']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['question_question_content']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_question_content']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_question_content']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_question_content']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['question_question_content']['link_to_entity'] = 0;
  /* Field: Answer label */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Answer label';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Answer';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Field: Answer: Answer_content */
  $handler->display->display_options['fields']['answer_content']['id'] = 'answer_content';
  $handler->display->display_options['fields']['answer_content']['table'] = 'search_api_index_answer_and_question';
  $handler->display->display_options['fields']['answer_content']['field'] = 'answer_content';
  $handler->display->display_options['fields']['answer_content']['label'] = '';
  $handler->display->display_options['fields']['answer_content']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['answer_content']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['answer_content']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['answer_content']['alter']['external'] = 0;
  $handler->display->display_options['fields']['answer_content']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['answer_content']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['answer_content']['alter']['nl2br'] = 1;
  $handler->display->display_options['fields']['answer_content']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['answer_content']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['answer_content']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['answer_content']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['answer_content']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['answer_content']['alter']['html'] = 0;
  $handler->display->display_options['fields']['answer_content']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['answer_content']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['answer_content']['hide_empty'] = 1;
  $handler->display->display_options['fields']['answer_content']['empty_zero'] = 0;
  $handler->display->display_options['fields']['answer_content']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['answer_content']['link_to_entity'] = 0;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_answer_and_question';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'search';

  $views['vopros_search_solr'] = $view;

  return $views;
}
