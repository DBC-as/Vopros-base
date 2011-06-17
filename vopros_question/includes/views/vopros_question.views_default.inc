<?php

/**
 * Implements hook_views_default_views().
 */
function vopros_question_views_default_views() {
  $views = array();

  // Question list view.
  // Used to display questions, to find the ones that can/should be answered.
  $view = new view;
  $view->name = 'vopros_question_list';
  $view->description = 'Used to display questions, to find the ones that can/should be answered';
  $view->tag = 'default';
  $view->base_table = 'vopros_question';
  $view->human_name = 'Question list';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Question list';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access questions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'question_id' => 'question_id',
    'question_title' => 'question_title',
    'subject_catagory' => 'subject_catagory',
    'question_usage' => 'question_usage',
    'question_status' => 'question_status',
    'question_deadline_timestamp' => 'question_deadline_timestamp',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'question_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'question_title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'subject_catagory' => array(
      'align' => '',
      'separator' => '',
    ),
    'question_usage' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'question_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'question_deadline_timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['order'] = 'desc';
  $handler->display->display_options['style_options']['empty_table'] = 1;
  /* Header: Question: Own questions */
  $handler->display->display_options['header']['own_questions']['id'] = 'own_questions';
  $handler->display->display_options['header']['own_questions']['table'] = 'vopros_question';
  $handler->display->display_options['header']['own_questions']['field'] = 'own_questions';
  /* Field: Question: Question ID */
  $handler->display->display_options['fields']['question_id']['id'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_id']['field'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['question_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_id']['separator'] = '';
  $handler->display->display_options['fields']['question_id']['format_plural'] = 0;
  /* Field: Question: Question_title */
  $handler->display->display_options['fields']['question_title']['id'] = 'question_title';
  $handler->display->display_options['fields']['question_title']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_title']['field'] = 'question_title';
  $handler->display->display_options['fields']['question_title']['label'] = 'Title';
  $handler->display->display_options['fields']['question_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['question_title']['alter']['path'] = 'admin/vopros/questions/[question_id]';
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
  /* Field: Question: Subject */
  $handler->display->display_options['fields']['subject_catagory']['id'] = 'subject_catagory';
  $handler->display->display_options['fields']['subject_catagory']['table'] = 'field_data_subject_catagory';
  $handler->display->display_options['fields']['subject_catagory']['field'] = 'subject_catagory';
  $handler->display->display_options['fields']['subject_catagory']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['external'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['subject_catagory']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['subject_catagory']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['html'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['subject_catagory']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['subject_catagory']['hide_empty'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['empty_zero'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['subject_catagory']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['subject_catagory']['field_api_classes'] = 0;
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
  /* Field: Question: Question_deadline_timestamp */
  $handler->display->display_options['fields']['question_deadline_timestamp']['id'] = 'question_deadline_timestamp';
  $handler->display->display_options['fields']['question_deadline_timestamp']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_deadline_timestamp']['field'] = 'question_deadline_timestamp';
  $handler->display->display_options['fields']['question_deadline_timestamp']['label'] = 'Deadline';
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_deadline_timestamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_deadline_timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['date_format'] = 'vopros_question_deadline';
  /* Field: Question: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Contextual filter: Question: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'vopros_question';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  /* Filter criterion: Question: Question_status */
  $handler->display->display_options['filters']['question_status']['id'] = 'question_status';
  $handler->display->display_options['filters']['question_status']['table'] = 'vopros_question';
  $handler->display->display_options['filters']['question_status']['field'] = 'question_status';
  $handler->display->display_options['filters']['question_status']['value'] = array(
    'value' => 'new',
  );
  $handler->display->display_options['filters']['question_status']['group'] = 0;
  $handler->display->display_options['filters']['question_status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['question_status']['expose']['operator_id'] = 'question_status_op';
  $handler->display->display_options['filters']['question_status']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['question_status']['expose']['label'] = 'Show all';
  $handler->display->display_options['filters']['question_status']['expose']['operator'] = 'question_status_op';
  $handler->display->display_options['filters']['question_status']['expose']['identifier'] = 'question_status';
  $handler->display->display_options['filters']['question_status']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['question_status']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['question_status']['expose']['multiple'] = FALSE;
  /* Filter criterion: Question: Question_usage */
  $handler->display->display_options['filters']['question_usage']['id'] = 'question_usage';
  $handler->display->display_options['filters']['question_usage']['table'] = 'vopros_question';
  $handler->display->display_options['filters']['question_usage']['field'] = 'question_usage';
  $handler->display->display_options['filters']['question_usage']['value'] = array(
    'value' => '',
  );
  $handler->display->display_options['filters']['question_usage']['group'] = 0;
  $handler->display->display_options['filters']['question_usage']['exposed'] = TRUE;
  $handler->display->display_options['filters']['question_usage']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['question_usage']['expose']['operator_id'] = 'question_usage_op';
  $handler->display->display_options['filters']['question_usage']['expose']['label'] = 'questions user for';
  $handler->display->display_options['filters']['question_usage']['expose']['operator'] = 'question_usage_op';
  $handler->display->display_options['filters']['question_usage']['expose']['identifier'] = 'question_usage';
  $handler->display->display_options['filters']['question_usage']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['question_usage']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['question_usage']['expose']['multiple'] = FALSE;
  /* Filter criterion: Fields: Editorial (vopros_editorial) - tid */
  $handler->display->display_options['filters']['vopros_editorial_tid']['id'] = 'vopros_editorial_tid';
  $handler->display->display_options['filters']['vopros_editorial_tid']['table'] = 'field_data_vopros_editorial';
  $handler->display->display_options['filters']['vopros_editorial_tid']['field'] = 'vopros_editorial_tid';
  $handler->display->display_options['filters']['vopros_editorial_tid']['group'] = 0;
  $handler->display->display_options['filters']['vopros_editorial_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['operator_id'] = 'vopros_editorial_tid_op';
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['label'] = 'with the editorial';
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['operator'] = 'vopros_editorial_tid_op';
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['identifier'] = 'vopros_editorial_tid';
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['multiple'] = FALSE;
  /* Filter criterion: Fields: Subject (subject_catagory) - tid */
  $handler->display->display_options['filters']['subject_catagory_tid']['id'] = 'subject_catagory_tid';
  $handler->display->display_options['filters']['subject_catagory_tid']['table'] = 'field_data_subject_catagory';
  $handler->display->display_options['filters']['subject_catagory_tid']['field'] = 'subject_catagory_tid';
  $handler->display->display_options['filters']['subject_catagory_tid']['group'] = 0;
  $handler->display->display_options['filters']['subject_catagory_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['subject_catagory_tid']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['subject_catagory_tid']['expose']['operator_id'] = 'subject_catagory_tid_op';
  $handler->display->display_options['filters']['subject_catagory_tid']['expose']['label'] = 'with the subject';
  $handler->display->display_options['filters']['subject_catagory_tid']['expose']['operator'] = 'subject_catagory_tid_op';
  $handler->display->display_options['filters']['subject_catagory_tid']['expose']['identifier'] = 'subject_catagory_tid';
  $handler->display->display_options['filters']['subject_catagory_tid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['subject_catagory_tid']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'admin/vopros/questions/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Question list';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Questions';
  $handler->display->display_options['tab_options']['description'] = 'Display a list of active questions';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['vopros_question_list'] = array(
    t('Master'),
    t('Question list'),
    t('more'),
    t('Go'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Question ID'),
    t('.'),
    t('Title'),
    t('admin/vopros/questions/[question_id]'),
    t('Subject'),
    t('Usage'),
    t('Status'),
    t('Deadline'),
    t('Created'),
    t('All'),
    t('Show all'),
    t('questions user for'),
    t('with the editorial'),
    t('with the subject'),
    t('Page'),
  );

  $views[$view->name] = $view;

  return $views;
}
