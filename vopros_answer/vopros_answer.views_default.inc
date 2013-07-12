<?php
/**
 * @file
 * vopros_answer.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function vopros_answer_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'vopros_answer_overview';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'vopros_answer';
  $view->human_name = 'Answer overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Answer overview';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access questions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'question_title' => 'question_title',
    'qanda_service_name' => 'qanda_service_name',
    'name' => 'name',
    'vopros_user_library' => 'vopros_user_library',
    'revision_timestamp' => 'revision_timestamp',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'question_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'qanda_service_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'vopros_user_library' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'revision_timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Footer: Question: Views Count */
  $handler->display->display_options['footer']['views_count']['id'] = 'views_count';
  $handler->display->display_options['footer']['views_count']['table'] = 'vopros_question';
  $handler->display->display_options['footer']['views_count']['field'] = 'views_count';
  /* Relationship: Answer: Answer ID */
  $handler->display->display_options['relationships']['answer_id']['id'] = 'answer_id';
  $handler->display->display_options['relationships']['answer_id']['table'] = 'vopros_answer';
  $handler->display->display_options['relationships']['answer_id']['field'] = 'answer_id';
  $handler->display->display_options['relationships']['answer_id']['required'] = 1;
  /* Relationship: Answer: Question_id */
  $handler->display->display_options['relationships']['question_id']['id'] = 'question_id';
  $handler->display->display_options['relationships']['question_id']['table'] = 'vopros_answer';
  $handler->display->display_options['relationships']['question_id']['field'] = 'question_id';
  $handler->display->display_options['relationships']['question_id']['required'] = 1;
  /* Relationship: Answer revisions: Answer revision creator */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'vopros_answer_revision';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'answer_id';
  $handler->display->display_options['relationships']['uid']['label'] = 'Answer creator';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['profile']['required'] = 0;
  /* Field: Question: Question ID */
  $handler->display->display_options['fields']['question_id']['id'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_id']['field'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['relationship'] = 'question_id';
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
  $handler->display->display_options['fields']['question_id']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_id']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['question_id']['separator'] = '';
  $handler->display->display_options['fields']['question_id']['format_plural'] = 0;
  /* Field: Question: Question_title */
  $handler->display->display_options['fields']['question_title']['id'] = 'question_title';
  $handler->display->display_options['fields']['question_title']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_title']['field'] = 'question_title';
  $handler->display->display_options['fields']['question_title']['relationship'] = 'question_id';
  $handler->display->display_options['fields']['question_title']['label'] = 'Question';
  $handler->display->display_options['fields']['question_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['question_title']['alter']['path'] = 'admin/vopros/question/[question_id]';
  $handler->display->display_options['fields']['question_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['question_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['question_title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['question_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['question_title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['question_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_title']['hide_alter_empty'] = 1;
  /* Field: Question: Qanda_service_name */
  $handler->display->display_options['fields']['qanda_service_name']['id'] = 'qanda_service_name';
  $handler->display->display_options['fields']['qanda_service_name']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['qanda_service_name']['field'] = 'qanda_service_name';
  $handler->display->display_options['fields']['qanda_service_name']['relationship'] = 'question_id';
  $handler->display->display_options['fields']['qanda_service_name']['label'] = 'Received from';
  $handler->display->display_options['fields']['qanda_service_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['qanda_service_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['qanda_service_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['qanda_service_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['qanda_service_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['qanda_service_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['qanda_service_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['qanda_service_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['qanda_service_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['qanda_service_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['qanda_service_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['qanda_service_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['qanda_service_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['qanda_service_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['qanda_service_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['qanda_service_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['qanda_service_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['qanda_service_name']['hide_alter_empty'] = 1;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Answer creator';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Profile: Library */
  $handler->display->display_options['fields']['vopros_user_library']['id'] = 'vopros_user_library';
  $handler->display->display_options['fields']['vopros_user_library']['table'] = 'field_data_vopros_user_library';
  $handler->display->display_options['fields']['vopros_user_library']['field'] = 'vopros_user_library';
  $handler->display->display_options['fields']['vopros_user_library']['relationship'] = 'profile';
  $handler->display->display_options['fields']['vopros_user_library']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['alter']['external'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['vopros_user_library']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['vopros_user_library']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['alter']['html'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['vopros_user_library']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['vopros_user_library']['hide_empty'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['empty_zero'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['vopros_user_library']['field_api_classes'] = 0;
  /* Field: Question: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'question_id';
  $handler->display->display_options['fields']['created']['label'] = 'Question created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Filter criterion: Question: Qanda_service_name */
  $handler->display->display_options['filters']['qanda_service_name']['id'] = 'qanda_service_name';
  $handler->display->display_options['filters']['qanda_service_name']['table'] = 'vopros_question';
  $handler->display->display_options['filters']['qanda_service_name']['field'] = 'qanda_service_name';
  $handler->display->display_options['filters']['qanda_service_name']['relationship'] = 'question_id';
  $handler->display->display_options['filters']['qanda_service_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['qanda_service_name']['expose']['operator_id'] = 'qanda_service_name_op';
  $handler->display->display_options['filters']['qanda_service_name']['expose']['label'] = 'Received from';
  $handler->display->display_options['filters']['qanda_service_name']['expose']['operator'] = 'qanda_service_name_op';
  $handler->display->display_options['filters']['qanda_service_name']['expose']['identifier'] = 'qanda_service_name';
  $handler->display->display_options['filters']['qanda_service_name']['expose']['reduce'] = 0;
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Answer creator';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['uid']['expose']['reduce'] = 0;
  /* Filter criterion: Profile: Library (vopros_user_library) */
  $handler->display->display_options['filters']['vopros_user_library_value']['id'] = 'vopros_user_library_value';
  $handler->display->display_options['filters']['vopros_user_library_value']['table'] = 'field_data_vopros_user_library';
  $handler->display->display_options['filters']['vopros_user_library_value']['field'] = 'vopros_user_library_value';
  $handler->display->display_options['filters']['vopros_user_library_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['vopros_user_library_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['vopros_user_library_value']['expose']['operator_id'] = 'vopros_user_library_value_op';
  $handler->display->display_options['filters']['vopros_user_library_value']['expose']['label'] = 'Library';
  $handler->display->display_options['filters']['vopros_user_library_value']['expose']['operator'] = 'vopros_user_library_value_op';
  $handler->display->display_options['filters']['vopros_user_library_value']['expose']['identifier'] = 'vopros_user_library_value';
  $handler->display->display_options['filters']['vopros_user_library_value']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/vopros/questions/answer-overview';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Answer overview';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $export['vopros_answer_overview'] = $view;

  $view = new view();
  $view->name = 'vopros_question_own_questions';
  $view->description = '';
  $view->tag = 'vopros_question';
  $view->base_table = 'vopros_answer';
  $view->human_name = 'List of own questions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Your questions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'rules';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['id'] = '1';
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
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
  /* Relationship: Answer: Question_id */
  $handler->display->display_options['relationships']['question_id']['id'] = 'question_id';
  $handler->display->display_options['relationships']['question_id']['table'] = 'vopros_answer';
  $handler->display->display_options['relationships']['question_id']['field'] = 'question_id';
  /* Field: Question: Question ID */
  $handler->display->display_options['fields']['question_id']['id'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_id']['field'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['relationship'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['question_id']['separator'] = '';
  /* Field: Question: Question_title */
  $handler->display->display_options['fields']['question_title']['id'] = 'question_title';
  $handler->display->display_options['fields']['question_title']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_title']['field'] = 'question_title';
  $handler->display->display_options['fields']['question_title']['relationship'] = 'question_id';
  $handler->display->display_options['fields']['question_title']['label'] = 'Title';
  $handler->display->display_options['fields']['question_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['question_title']['alter']['path'] = 'admin/vopros/questions/[question_id]';
  /* Field: Question: Emner */
  $handler->display->display_options['fields']['subject_catagory']['id'] = 'subject_catagory';
  $handler->display->display_options['fields']['subject_catagory']['table'] = 'field_data_subject_catagory';
  $handler->display->display_options['fields']['subject_catagory']['field'] = 'subject_catagory';
  $handler->display->display_options['fields']['subject_catagory']['relationship'] = 'question_id';
  $handler->display->display_options['fields']['subject_catagory']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Question: Question_usage */
  $handler->display->display_options['fields']['question_usage']['id'] = 'question_usage';
  $handler->display->display_options['fields']['question_usage']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_usage']['field'] = 'question_usage';
  $handler->display->display_options['fields']['question_usage']['relationship'] = 'question_id';
  $handler->display->display_options['fields']['question_usage']['label'] = 'Usage';
  /* Field: Question: Question_status */
  $handler->display->display_options['fields']['question_status']['id'] = 'question_status';
  $handler->display->display_options['fields']['question_status']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_status']['field'] = 'question_status';
  $handler->display->display_options['fields']['question_status']['relationship'] = 'question_id';
  $handler->display->display_options['fields']['question_status']['label'] = 'Status';
  /* Field: Question: Question_deadline_timestamp */
  $handler->display->display_options['fields']['question_deadline_timestamp']['id'] = 'question_deadline_timestamp';
  $handler->display->display_options['fields']['question_deadline_timestamp']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_deadline_timestamp']['field'] = 'question_deadline_timestamp';
  $handler->display->display_options['fields']['question_deadline_timestamp']['relationship'] = 'question_id';
  $handler->display->display_options['fields']['question_deadline_timestamp']['label'] = 'Deadline';
  $handler->display->display_options['fields']['question_deadline_timestamp']['date_format'] = 'vopros_question_deadline';
  /* Field: Question: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'question_id';
  /* Field: Question: Release question link */
  $handler->display->display_options['fields']['release_link']['id'] = 'release_link';
  $handler->display->display_options['fields']['release_link']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['release_link']['field'] = 'release_link';
  $handler->display->display_options['fields']['release_link']['relationship'] = 'question_id';
  $handler->display->display_options['fields']['release_link']['label'] = 'Release question';
  /* Contextual filter: Question: Question owner */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'vopros_question';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'question_id';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Question: Question_status */
  $handler->display->display_options['filters']['question_status']['id'] = 'question_status';
  $handler->display->display_options['filters']['question_status']['table'] = 'vopros_question';
  $handler->display->display_options['filters']['question_status']['field'] = 'question_status';
  $handler->display->display_options['filters']['question_status']['relationship'] = 'question_id';
  $handler->display->display_options['filters']['question_status']['value'] = array(
    'value' => 'assigned',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'user/%/vopros/questions';
  $translatables['vopros_question_own_questions'] = array(
    t('Master'),
    t('Your questions'),
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
    t('question'),
    t('Question ID'),
    t('.'),
    t('Title'),
    t('Emner'),
    t('Usage'),
    t('Status'),
    t('Deadline'),
    t('Created'),
    t('Release question'),
    t('All'),
    t('Page'),
  );

  $export['vopros_question_own_questions'] = $view;

  return $export;
}
