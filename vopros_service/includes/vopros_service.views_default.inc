<?php
/**
 * @file
 * vopros_services.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function vopros_service_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'vopros_service_forwarded_question_list';
  $view->description = 'Used to display questions, to find the ones that can/should be answered';
  $view->tag = 'default';
  $view->base_table = 'vopros_question';
  $view->human_name = 'Forwarded question list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Question list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
  );
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
    'qanda_service_name' => 'qanda_service_name',
    'question_usage' => 'question_usage',
    'question_status' => 'question_status',
    'question_deadline_timestamp' => 'question_deadline_timestamp',
    'changed' => 'changed',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'question_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'question_title' => array(
      'sortable' => 1,
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
    'question_usage' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'question_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'question_deadline_timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Question: Views Count */
  $handler->display->display_options['footer']['views_count']['id'] = 'views_count';
  $handler->display->display_options['footer']['views_count']['table'] = 'vopros_question';
  $handler->display->display_options['footer']['views_count']['field'] = 'views_count';
  /* Relationship: Question: Feedback */
  $handler->display->display_options['relationships']['feedback_question_id']['id'] = 'feedback_question_id';
  $handler->display->display_options['relationships']['feedback_question_id']['table'] = 'vopros_question';
  $handler->display->display_options['relationships']['feedback_question_id']['field'] = 'feedback_question_id';
  /* Relationship: Vopros Service forwarded questions.: Service machine name */
  $handler->display->display_options['relationships']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['relationships']['machine_name']['table'] = 'vopros_service_question';
  $handler->display->display_options['relationships']['machine_name']['field'] = 'machine_name';
  /* Field: Question: Question ID */
  $handler->display->display_options['fields']['question_id']['id'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_id']['field'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['question_id']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['question_id']['separator'] = '';
  /* Field: Question: Question_status_reason */
  $handler->display->display_options['fields']['question_status_reason']['id'] = 'question_status_reason';
  $handler->display->display_options['fields']['question_status_reason']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_status_reason']['field'] = 'question_status_reason';
  $handler->display->display_options['fields']['question_status_reason']['exclude'] = TRUE;
  /* Field: Question: Question_title */
  $handler->display->display_options['fields']['question_title']['id'] = 'question_title';
  $handler->display->display_options['fields']['question_title']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_title']['field'] = 'question_title';
  $handler->display->display_options['fields']['question_title']['label'] = 'Title';
  $handler->display->display_options['fields']['question_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['question_title']['alter']['path'] = 'admin/vopros/questions/[question_id]';
  $handler->display->display_options['fields']['question_title']['hide_alter_empty'] = FALSE;
  /* Field: Question: Qanda_service_name */
  $handler->display->display_options['fields']['qanda_service_name']['id'] = 'qanda_service_name';
  $handler->display->display_options['fields']['qanda_service_name']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['qanda_service_name']['field'] = 'qanda_service_name';
  $handler->display->display_options['fields']['qanda_service_name']['label'] = 'Received from';
  $handler->display->display_options['fields']['qanda_service_name']['element_label_colon'] = FALSE;
  /* Field: Question: Question_usage */
  $handler->display->display_options['fields']['question_usage']['id'] = 'question_usage';
  $handler->display->display_options['fields']['question_usage']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_usage']['field'] = 'question_usage';
  $handler->display->display_options['fields']['question_usage']['label'] = 'Usage';
  $handler->display->display_options['fields']['question_usage']['alter']['max_length'] = '35';
  $handler->display->display_options['fields']['question_usage']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['question_usage']['hide_alter_empty'] = FALSE;
  /* Field: Question: Question_status */
  $handler->display->display_options['fields']['question_status']['id'] = 'question_status';
  $handler->display->display_options['fields']['question_status']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_status']['field'] = 'question_status';
  $handler->display->display_options['fields']['question_status']['label'] = 'Status';
  $handler->display->display_options['fields']['question_status']['hide_alter_empty'] = FALSE;
  /* Field: Question: Question_deadline_timestamp */
  $handler->display->display_options['fields']['question_deadline_timestamp']['id'] = 'question_deadline_timestamp';
  $handler->display->display_options['fields']['question_deadline_timestamp']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_deadline_timestamp']['field'] = 'question_deadline_timestamp';
  $handler->display->display_options['fields']['question_deadline_timestamp']['label'] = 'Deadline';
  $handler->display->display_options['fields']['question_deadline_timestamp']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['question_deadline_timestamp']['date_format'] = 'vopros_question_deadline';
  /* Field: Question: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Question: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Vopros Service: Label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'vopros_service';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['relationship'] = 'machine_name';
  $handler->display->display_options['fields']['label']['label'] = 'Service';
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
  $handler->display->display_options['filters']['question_status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['question_status']['expose']['operator'] = 'question_status_op';
  $handler->display->display_options['filters']['question_status']['expose']['identifier'] = 'question_status';
  $handler->display->display_options['filters']['question_status']['expose']['remember'] = TRUE;
  /* Filter criterion: Question: Redaktion (vopros_editorial) */
  $handler->display->display_options['filters']['vopros_editorial_tid']['id'] = 'vopros_editorial_tid';
  $handler->display->display_options['filters']['vopros_editorial_tid']['table'] = 'field_data_vopros_editorial';
  $handler->display->display_options['filters']['vopros_editorial_tid']['field'] = 'vopros_editorial_tid';
  $handler->display->display_options['filters']['vopros_editorial_tid']['group'] = 0;
  $handler->display->display_options['filters']['vopros_editorial_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['operator_id'] = 'vopros_editorial_tid_op';
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['label'] = 'with the editorial';
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['operator'] = 'vopros_editorial_tid_op';
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['identifier'] = 'vopros_editorial_tid';
  $handler->display->display_options['filters']['vopros_editorial_tid']['expose']['remember'] = TRUE;
  /* Filter criterion: Question: Qanda_service_name */
  $handler->display->display_options['filters']['qanda_service_name']['id'] = 'qanda_service_name';
  $handler->display->display_options['filters']['qanda_service_name']['table'] = 'vopros_question';
  $handler->display->display_options['filters']['qanda_service_name']['field'] = 'qanda_service_name';
  $handler->display->display_options['filters']['qanda_service_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['qanda_service_name']['expose']['operator_id'] = 'qanda_service_name_op';
  $handler->display->display_options['filters']['qanda_service_name']['expose']['label'] = 'Received from';
  $handler->display->display_options['filters']['qanda_service_name']['expose']['operator'] = 'qanda_service_name_op';
  $handler->display->display_options['filters']['qanda_service_name']['expose']['identifier'] = 'qanda_service_name';
  /* Filter criterion: Vopros Service forwarded questions.: Direction of forward */
  $handler->display->display_options['filters']['direction']['id'] = 'direction';
  $handler->display->display_options['filters']['direction']['table'] = 'vopros_service_question';
  $handler->display->display_options['filters']['direction']['field'] = 'direction';
  $handler->display->display_options['filters']['direction']['exposed'] = TRUE;
  $handler->display->display_options['filters']['direction']['expose']['operator_id'] = 'direction_op';
  $handler->display->display_options['filters']['direction']['expose']['label'] = 'Direction of forward';
  $handler->display->display_options['filters']['direction']['expose']['operator'] = 'direction_op';
  $handler->display->display_options['filters']['direction']['expose']['identifier'] = 'direction';
  $handler->display->display_options['filters']['direction']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Vopros Service forwarded questions.: Type of forward */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'vopros_service_question';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type of forward';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: List */
  $handler = $view->new_display('page', 'List', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'admin/vopros/questions/forwarded';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Forwarded';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'Questions';
  $handler->display->display_options['tab_options']['description'] = 'Display a list of active questions';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['vopros_service_forwarded_question_list'] = array(
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
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('question'),
    t('Service'),
    t('Question ID'),
    t('.'),
    t('Question_status_reason'),
    t('Title'),
    t('Received from'),
    t('Usage'),
    t('Status'),
    t('Deadline'),
    t('Updated'),
    t('Created'),
    t('with the editorial'),
    t('Direction of forward'),
    t('Type of forward'),
    t('List'),
  );
  $export['vopros_service_forwarded_question_list'] = $view;

  return $export;
}
