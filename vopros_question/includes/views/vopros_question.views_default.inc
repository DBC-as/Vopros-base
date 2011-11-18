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
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access questions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'question_id' => 'question_id',
    'question_title' => 'question_title',
    'subject_catagory' => 'subject_catagory',
    'question_usage' => 'question_usage',
    'question_status' => 'question_status',
    'question_deadline_timestamp' => 'question_deadline_timestamp',
    'changed' => 'changed',
    'created' => 'created',
    'vopros_feedback_rating' => 'vopros_feedback_rating',
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
    'changed' => array(
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
    'vopros_feedback_rating' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['order'] = 'desc';
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Header: Question: Own questions */
  $handler->display->display_options['header']['own_questions']['id'] = 'own_questions';
  $handler->display->display_options['header']['own_questions']['table'] = 'vopros_question';
  $handler->display->display_options['header']['own_questions']['field'] = 'own_questions';
  /* Footer: Question: Views Count */
  if (module_exists('vopros_answer')) {
    $handler->display->display_options['footer']['views_count']['id'] = 'views_count';
    $handler->display->display_options['footer']['views_count']['table'] = 'vopros_question';
    $handler->display->display_options['footer']['views_count']['field'] = 'views_count';
  }
  /* Relationship: Question: Feedback */
  $handler->display->display_options['relationships']['feedback_question_id']['id'] = 'feedback_question_id';
  $handler->display->display_options['relationships']['feedback_question_id']['table'] = 'vopros_question';
  $handler->display->display_options['relationships']['feedback_question_id']['field'] = 'feedback_question_id';
  $handler->display->display_options['relationships']['feedback_question_id']['required'] = 0;
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
  $handler->display->display_options['fields']['question_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_id']['hide_alter_empty'] = 0;
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
  $handler->display->display_options['fields']['question_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_title']['hide_alter_empty'] = 0;
  /* Field: Question: Subject */
  $handler->display->display_options['fields']['subject_catagory']['id'] = 'subject_catagory';
  $handler->display->display_options['fields']['subject_catagory']['table'] = 'field_data_subject_catagory';
  $handler->display->display_options['fields']['subject_catagory']['field'] = 'subject_catagory';
  $handler->display->display_options['fields']['subject_catagory']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['external'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['subject_catagory']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['subject_catagory']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['html'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['subject_catagory']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['subject_catagory']['hide_empty'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['empty_zero'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['subject_catagory']['group_rows'] = 1;
  $handler->display->display_options['fields']['subject_catagory']['delta_offset'] = '0';
  $handler->display->display_options['fields']['subject_catagory']['delta_reversed'] = 0;
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
  $handler->display->display_options['fields']['question_usage']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['question_usage']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_usage']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_usage']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_usage']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_usage']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_usage']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_usage']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_usage']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_usage']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_usage']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_usage']['hide_alter_empty'] = 0;
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
  $handler->display->display_options['fields']['question_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['question_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_status']['hide_alter_empty'] = 0;
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
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_deadline_timestamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_deadline_timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['date_format'] = 'vopros_question_deadline';
  /* Field: Question: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Question: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: feedback: Rating */
  $handler->display->display_options['fields']['vopros_feedback_rating']['id'] = 'vopros_feedback_rating';
  $handler->display->display_options['fields']['vopros_feedback_rating']['table'] = 'field_data_vopros_feedback_rating';
  $handler->display->display_options['fields']['vopros_feedback_rating']['field'] = 'vopros_feedback_rating';
  $handler->display->display_options['fields']['vopros_feedback_rating']['relationship'] = 'feedback_question_id';
  $handler->display->display_options['fields']['vopros_feedback_rating']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['vopros_feedback_rating']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['vopros_feedback_rating']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['vopros_feedback_rating']['alter']['external'] = 0;
  $handler->display->display_options['fields']['vopros_feedback_rating']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['vopros_feedback_rating']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['vopros_feedback_rating']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['vopros_feedback_rating']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['vopros_feedback_rating']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['vopros_feedback_rating']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['vopros_feedback_rating']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['vopros_feedback_rating']['alter']['html'] = 0;
  $handler->display->display_options['fields']['vopros_feedback_rating']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['vopros_feedback_rating']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['vopros_feedback_rating']['hide_empty'] = 0;
  $handler->display->display_options['fields']['vopros_feedback_rating']['empty_zero'] = 0;
  $handler->display->display_options['fields']['vopros_feedback_rating']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['vopros_feedback_rating']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['vopros_feedback_rating']['field_api_classes'] = 0;
  /* Filter criterion: Question: Question_status */
  $handler->display->display_options['filters']['question_status']['id'] = 'question_status';
  $handler->display->display_options['filters']['question_status']['table'] = 'vopros_question';
  $handler->display->display_options['filters']['question_status']['field'] = 'question_status';
  $handler->display->display_options['filters']['question_status']['value'] = array(
    'new' => 'new',
    'active' => 'active',
    'assigned' => 'assigned',
    'answered' => 'answered',
    'closed' => 'closed',
    'published' => 'published',
  );
  $handler->display->display_options['filters']['question_status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['question_status']['expose']['operator_id'] = 'question_status_op';
  $handler->display->display_options['filters']['question_status']['expose']['label'] = 'Show all';
  $handler->display->display_options['filters']['question_status']['expose']['operator'] = 'question_status_op';
  $handler->display->display_options['filters']['question_status']['expose']['identifier'] = 'question_status';
  $handler->display->display_options['filters']['question_status']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['question_status']['expose']['reduce'] = 0;
  /* Filter criterion: Question: Question_usage */
  $handler->display->display_options['filters']['question_usage']['id'] = 'question_usage';
  $handler->display->display_options['filters']['question_usage']['table'] = 'vopros_question';
  $handler->display->display_options['filters']['question_usage']['field'] = 'question_usage';
  $handler->display->display_options['filters']['question_usage']['exposed'] = TRUE;
  $handler->display->display_options['filters']['question_usage']['expose']['operator_id'] = 'question_usage_op';
  $handler->display->display_options['filters']['question_usage']['expose']['label'] = 'questions used for';
  $handler->display->display_options['filters']['question_usage']['expose']['operator'] = 'question_usage_op';
  $handler->display->display_options['filters']['question_usage']['expose']['identifier'] = 'question_usage';
  $handler->display->display_options['filters']['question_usage']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['question_usage']['expose']['reduce'] = 0;
  /* Filter criterion: Question: Editorial (vopros_editorial) */
  $handler->display->display_options['filters']['vopros_editorial_tid']['id'] = 'vopros_editorial_tid';
  $handler->display->display_options['filters']['vopros_editorial_tid']['table'] = 'field_data_vopros_editorial';
  $handler->display->display_options['filters']['vopros_editorial_tid']['field'] = 'vopros_editorial_tid';
  $handler->display->display_options['filters']['vopros_editorial_tid']['group'] = 0;
  $handler->display->display_options['filters']['vopros_editorial_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['operator_id'] = 'vopros_editorial_tid_op';
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['label'] = 'with the editorial';
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['operator'] = 'vopros_editorial_tid_op';
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['identifier'] = 'vopros_editorial_tid';
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['multiple'] = FALSE;
  /* Filter criterion: feedback: Rating (vopros_feedback_rating:rating) */
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['id'] = 'vopros_feedback_rating_rating';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['table'] = 'field_data_vopros_feedback_rating';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['field'] = 'vopros_feedback_rating_rating';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['relationship'] = 'feedback_question_id';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['exposed'] = TRUE;
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['expose']['operator_id'] = 'vopros_feedback_rating_rating_op';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['expose']['label'] = 'with rating';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['expose']['operator'] = 'vopros_feedback_rating_rating_op';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['expose']['identifier'] = 'vopros_feedback_rating_rating';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['expose']['reduce'] = 0;
  /* Filter criterion: Question: Subject (subject_catagory) */
  $handler->display->display_options['filters']['subject_catagory_tid']['id'] = 'subject_catagory_tid';
  $handler->display->display_options['filters']['subject_catagory_tid']['table'] = 'field_data_subject_catagory';
  $handler->display->display_options['filters']['subject_catagory_tid']['field'] = 'subject_catagory_tid';
  $handler->display->display_options['filters']['subject_catagory_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['subject_catagory_tid']['expose']['operator_id'] = 'subject_catagory_tid_op';
  $handler->display->display_options['filters']['subject_catagory_tid']['expose']['label'] = 'with the subject';
  $handler->display->display_options['filters']['subject_catagory_tid']['expose']['operator'] = 'subject_catagory_tid_op';
  $handler->display->display_options['filters']['subject_catagory_tid']['expose']['identifier'] = 'subject_catagory_tid';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer questions';
  /* Relationship: Question: Question owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'vopros_question';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['question_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_id']['hide_alter_empty'] = 0;
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
  $handler->display->display_options['fields']['question_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_title']['hide_alter_empty'] = 0;
  /* Field: Question: Subject */
  $handler->display->display_options['fields']['subject_catagory']['id'] = 'subject_catagory';
  $handler->display->display_options['fields']['subject_catagory']['table'] = 'field_data_subject_catagory';
  $handler->display->display_options['fields']['subject_catagory']['field'] = 'subject_catagory';
  $handler->display->display_options['fields']['subject_catagory']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['external'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['subject_catagory']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['subject_catagory']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['alter']['html'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['subject_catagory']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['subject_catagory']['hide_empty'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['empty_zero'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['subject_catagory']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['subject_catagory']['group_rows'] = 1;
  $handler->display->display_options['fields']['subject_catagory']['delta_offset'] = '0';
  $handler->display->display_options['fields']['subject_catagory']['delta_reversed'] = 0;
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
  $handler->display->display_options['fields']['question_usage']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['question_usage']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_usage']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_usage']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_usage']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_usage']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_usage']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_usage']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_usage']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_usage']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_usage']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_usage']['hide_alter_empty'] = 0;
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
  $handler->display->display_options['fields']['question_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['question_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_status']['hide_alter_empty'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Question assignee';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
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
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_deadline_timestamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_deadline_timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['question_deadline_timestamp']['date_format'] = 'vopros_question_deadline';
  /* Field: Question: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Question: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Question: Question_status */
  $handler->display->display_options['filters']['question_status']['id'] = 'question_status';
  $handler->display->display_options['filters']['question_status']['table'] = 'vopros_question';
  $handler->display->display_options['filters']['question_status']['field'] = 'question_status';
  $handler->display->display_options['filters']['question_status']['value'] = array(
    'new' => 'new',
    'active' => 'active',
    'assigned' => 'assigned',
    'answered' => 'answered',
    'closed' => 'closed',
  );
  $handler->display->display_options['filters']['question_status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['question_status']['expose']['operator_id'] = 'question_status_op';
  $handler->display->display_options['filters']['question_status']['expose']['label'] = 'Question status';
  $handler->display->display_options['filters']['question_status']['expose']['operator'] = 'question_status_op';
  $handler->display->display_options['filters']['question_status']['expose']['identifier'] = 'question_status';
  $handler->display->display_options['filters']['question_status']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['question_status']['expose']['reduce'] = 0;
  /* Filter criterion: Question: Question_usage */
  $handler->display->display_options['filters']['question_usage']['id'] = 'question_usage';
  $handler->display->display_options['filters']['question_usage']['table'] = 'vopros_question';
  $handler->display->display_options['filters']['question_usage']['field'] = 'question_usage';
  $handler->display->display_options['filters']['question_usage']['exposed'] = TRUE;
  $handler->display->display_options['filters']['question_usage']['expose']['operator_id'] = 'question_usage_op';
  $handler->display->display_options['filters']['question_usage']['expose']['label'] = 'Question usage';
  $handler->display->display_options['filters']['question_usage']['expose']['operator'] = 'question_usage_op';
  $handler->display->display_options['filters']['question_usage']['expose']['identifier'] = 'question_usage';
  $handler->display->display_options['filters']['question_usage']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['question_usage']['expose']['reduce'] = 0;
  /* Filter criterion: Question: Editorial (vopros_editorial) */
  $handler->display->display_options['filters']['vopros_editorial_tid']['id'] = 'vopros_editorial_tid';
  $handler->display->display_options['filters']['vopros_editorial_tid']['table'] = 'field_data_vopros_editorial';
  $handler->display->display_options['filters']['vopros_editorial_tid']['field'] = 'vopros_editorial_tid';
  $handler->display->display_options['filters']['vopros_editorial_tid']['group'] = 0;
  $handler->display->display_options['filters']['vopros_editorial_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['operator_id'] = 'vopros_editorial_tid_op';
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['label'] = 'Editorial';
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['operator'] = 'vopros_editorial_tid_op';
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['identifier'] = 'vopros_editorial_tid';
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['multiple'] = FALSE;
  /* Filter criterion: Question: Subject (subject_catagory) */
  $handler->display->display_options['filters']['subject_catagory_tid']['id'] = 'subject_catagory_tid';
  $handler->display->display_options['filters']['subject_catagory_tid']['table'] = 'field_data_subject_catagory';
  $handler->display->display_options['filters']['subject_catagory_tid']['field'] = 'subject_catagory_tid';
  $handler->display->display_options['filters']['subject_catagory_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['subject_catagory_tid']['expose']['operator_id'] = 'subject_catagory_tid_op';
  $handler->display->display_options['filters']['subject_catagory_tid']['expose']['label'] = 'Subject';
  $handler->display->display_options['filters']['subject_catagory_tid']['expose']['operator'] = 'subject_catagory_tid_op';
  $handler->display->display_options['filters']['subject_catagory_tid']['expose']['identifier'] = 'subject_catagory_tid';
  $handler->display->display_options['filters']['subject_catagory_tid']['expose']['multiple'] = FALSE;
  /* Filter criterion: Question assignee */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'vopros_question';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['ui_name'] = 'Question assignee';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Question assignee';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['uid']['expose']['reduce'] = 0;
  $handler->display->display_options['path'] = 'admin/vopros/questions/admin-list';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Admin list';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['vopros_question_list'] = array(
    t('Master'),
    t('Question list'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('question'),
    t('Question ID'),
    t('.'),
    t('Title'),
    t('admin/vopros/questions/[question_id]'),
    t('Subject'),
    t('Usage'),
    t('Status'),
    t('Deadline'),
    t('Updated'),
    t('Created'),
    t('Rating'),
    t('Show all'),
    t('questions used for'),
    t('with the editorial'),
    t('with rating'),
    t('with the subject'),
    t('Page'),
    t('user'),
    t('Question assignee'),
    t('Question status'),
    t('Question usage'),
    t('Editorial'),
    t('Questions'),
    t('Admin list'),
    t('List'),
    t('Question list'),
    t('Display a list of active questions')
  );

  $custom_translatables = array(
   t('Admin list'),
   t('Feedback'),
   t('User feedback'),
   t('Display a list of active questions'),
   t('Questions'),
   t('Question list'),
  );

  $views[$view->name] = $view;

  return $views;
}
