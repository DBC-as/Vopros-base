<?php

/**
 * Implements hook_views_default_views().
 */
function vopros_search_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'vopros_search_solr';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_vopros_answer_question';
  $view->human_name = 'Solr Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access questions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['entity_access'] = 0;
  $handler->display->display_options['query']['options']['parse_mode'] = 'direct';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Answer: Question_id */
  $handler->display->display_options['fields']['question_id']['id'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['table'] = 'search_api_index_vopros_answer_question';
  $handler->display->display_options['fields']['question_id']['field'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['label'] = '';
  $handler->display->display_options['fields']['question_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['question_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['question_id']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['question_id']['separator'] = '';
  $handler->display->display_options['fields']['question_id']['link_to_entity'] = 0;
  /* Field: Question: Question_title (indexed) */
  $handler->display->display_options['fields']['question_question_title']['id'] = 'question_question_title';
  $handler->display->display_options['fields']['question_question_title']['table'] = 'search_api_index_vopros_answer_question';
  $handler->display->display_options['fields']['question_question_title']['field'] = 'question_question_title';
  $handler->display->display_options['fields']['question_question_title']['label'] = '';
  $handler->display->display_options['fields']['question_question_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['question_question_title']['alter']['path'] = 'admin/vopros/questions/[question_id]';
  $handler->display->display_options['fields']['question_question_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['question_question_title']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['question_question_title']['element_wrapper_class'] = 'question-title';
  $handler->display->display_options['fields']['question_question_title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['question_question_title']['link_to_entity'] = 0;
  /* Field: Question: Question_content (indexed) */
  $handler->display->display_options['fields']['question_question_content']['id'] = 'question_question_content';
  $handler->display->display_options['fields']['question_question_content']['table'] = 'search_api_index_vopros_answer_question';
  $handler->display->display_options['fields']['question_question_content']['field'] = 'question_question_content';
  $handler->display->display_options['fields']['question_question_content']['label'] = '';
  $handler->display->display_options['fields']['question_question_content']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['question_question_content']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['question_question_content']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['question_question_content']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['question_question_content']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['question_question_content']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['question_question_content']['link_to_entity'] = 0;
  /* Field: Question: Created (indexed) */
  $handler->display->display_options['fields']['question_created']['id'] = 'question_created';
  $handler->display->display_options['fields']['question_created']['table'] = 'search_api_index_vopros_answer_question';
  $handler->display->display_options['fields']['question_created']['field'] = 'question_created';
  $handler->display->display_options['fields']['question_created']['label'] = 'Asked';
  $handler->display->display_options['fields']['question_created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['question_created']['date_format'] = 'short';
  $handler->display->display_options['fields']['question_created']['link_to_entity'] = 0;
  /* Field: Question: Question_status_reason (indexed) */
  $handler->display->display_options['fields']['question_question_status_reason']['id'] = 'question_question_status_reason';
  $handler->display->display_options['fields']['question_question_status_reason']['table'] = 'search_api_index_vopros_answer_question';
  $handler->display->display_options['fields']['question_question_status_reason']['field'] = 'question_question_status_reason';
  $handler->display->display_options['fields']['question_question_status_reason']['label'] = '';
  $handler->display->display_options['fields']['question_question_status_reason']['exclude'] = TRUE;
  $handler->display->display_options['fields']['question_question_status_reason']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['question_question_status_reason']['link_to_entity'] = 0;
  /* Field: Question: Question_status (indexed) */
  $handler->display->display_options['fields']['question_question_status']['id'] = 'question_question_status';
  $handler->display->display_options['fields']['question_question_status']['table'] = 'search_api_index_vopros_answer_question';
  $handler->display->display_options['fields']['question_question_status']['field'] = 'question_question_status';
  $handler->display->display_options['fields']['question_question_status']['label'] = 'Status';
  $handler->display->display_options['fields']['question_question_status']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['question_question_status']['alter']['text'] = '[question_question_status] ([question_question_status_reason])';
  $handler->display->display_options['fields']['question_question_status']['element_wrapper_type'] = 'strong';
  $handler->display->display_options['fields']['question_question_status']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['question_question_status']['link_to_entity'] = 0;
  /* Sort criterion: Question: Created (indexed) */
  $handler->display->display_options['sorts']['question_created']['id'] = 'question_created';
  $handler->display->display_options['sorts']['question_created']['table'] = 'search_api_index_vopros_answer_question';
  $handler->display->display_options['sorts']['question_created']['field'] = 'question_created';
  $handler->display->display_options['sorts']['question_created']['order'] = 'DESC';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_vopros_answer_question';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  /* Filter criterion: Question: Redaktion (indexed) */
  $handler->display->display_options['filters']['question_vopros_editorial']['id'] = 'question_vopros_editorial';
  $handler->display->display_options['filters']['question_vopros_editorial']['table'] = 'search_api_index_vopros_answer_question';
  $handler->display->display_options['filters']['question_vopros_editorial']['field'] = 'question_vopros_editorial';
  $handler->display->display_options['filters']['question_vopros_editorial']['value'] = array();
  $handler->display->display_options['filters']['question_vopros_editorial']['exposed'] = TRUE;
  $handler->display->display_options['filters']['question_vopros_editorial']['expose']['operator_id'] = 'question_vopros_editorial_op';
  $handler->display->display_options['filters']['question_vopros_editorial']['expose']['label'] = 'Editorial';
  $handler->display->display_options['filters']['question_vopros_editorial']['expose']['operator'] = 'question_vopros_editorial_op';
  $handler->display->display_options['filters']['question_vopros_editorial']['expose']['identifier'] = 'question_vopros_editorial';
  $handler->display->display_options['filters']['question_vopros_editorial']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['question_vopros_editorial']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Answer: Answer owner */
  $handler->display->display_options['filters']['user']['id'] = 'user';
  $handler->display->display_options['filters']['user']['table'] = 'search_api_index_vopros_answer_question';
  $handler->display->display_options['filters']['user']['field'] = 'user';
  $handler->display->display_options['filters']['user']['value'] = array();
  $handler->display->display_options['filters']['user']['exposed'] = TRUE;
  $handler->display->display_options['filters']['user']['expose']['operator_id'] = 'user_op';
  $handler->display->display_options['filters']['user']['expose']['label'] = 'Last edited by';
  $handler->display->display_options['filters']['user']['expose']['operator'] = 'user_op';
  $handler->display->display_options['filters']['user']['expose']['identifier'] = 'user';
  $handler->display->display_options['filters']['user']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'search';
  $translatables['vopros_search_solr'] = array(
    t('Master'),
    t('Search'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('.'),
    t('Asked'),
    t('Status'),
    t('[question_question_status] ([question_question_status_reason])'),
    t('Editorial'),
    t('Last edited by'),
    t('Page'),
  );

  $views['vopros_search_solr'] = $view;

  return $views;
}
