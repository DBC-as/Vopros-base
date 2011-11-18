<?php

/**
 * Implements hook_views_default_views().
 */
function vopros_user_views_default_views() {
  // Shortcut link block.
  $views = array();
  $view = new view;
  $view->name = 'vopros_user_shortcut_links';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'Shortcut links for users';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Shortcut links';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Field: Profile: Shortcut links */
  $handler->display->display_options['fields']['vopros_user_shortcuts']['id'] = 'vopros_user_shortcuts';
  $handler->display->display_options['fields']['vopros_user_shortcuts']['table'] = 'field_data_vopros_user_shortcuts';
  $handler->display->display_options['fields']['vopros_user_shortcuts']['field'] = 'vopros_user_shortcuts';
  $handler->display->display_options['fields']['vopros_user_shortcuts']['label'] = '';
  $handler->display->display_options['fields']['vopros_user_shortcuts']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['alter']['external'] = 0;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['alter']['html'] = 0;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['hide_empty'] = 0;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['empty_zero'] = 0;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['vopros_user_shortcuts']['group_rows'] = 1;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['delta_offset'] = '0';
  $handler->display->display_options['fields']['vopros_user_shortcuts']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['vopros_user_shortcuts']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['vopros_user_shortcuts']['field_api_classes'] = 0;
  /* Contextual filter: Profile: User uid */
  $handler->display->display_options['arguments']['user']['id'] = 'user';
  $handler->display->display_options['arguments']['user']['table'] = 'profile';
  $handler->display->display_options['arguments']['user']['field'] = 'user';
  $handler->display->display_options['arguments']['user']['default_action'] = 'default';
  $handler->display->display_options['arguments']['user']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['user']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['user']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['user']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['user']['not'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['vopros_user_shortcut_links'] = array(
    t('Master'),
    t('Shortcut links'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('All'),
    t('Block'),
  );
  $views['vopros_user_shortcut_links'] = $view;

  /**
   * User list
   */
  $view = new view;
  $view->name = 'vopros_user_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Vopros user list';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Vopros user list';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer vopros';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'vopros_user_library' => 'vopros_user_library',
    'vopros_user_first_name' => 'vopros_user_first_name',
    'vopros_user_last_name' => 'vopros_user_last_name',
    'mail' => 'mail',
    'vopros_user_phone_number' => 'vopros_user_phone_number',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'vopros_user_library' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'vopros_user_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'vopros_user_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'vopros_user_phone_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = 0;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'vopros_user_librarian' => 'vopros_user_librarian',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'User name';
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
  $handler->display->display_options['fields']['vopros_user_library']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['alter']['html'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['vopros_user_library']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['vopros_user_library']['hide_empty'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['empty_zero'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['vopros_user_library']['field_api_classes'] = 0;
  /* Field: Profile: First name */
  $handler->display->display_options['fields']['vopros_user_first_name']['id'] = 'vopros_user_first_name';
  $handler->display->display_options['fields']['vopros_user_first_name']['table'] = 'field_data_vopros_user_first_name';
  $handler->display->display_options['fields']['vopros_user_first_name']['field'] = 'vopros_user_first_name';
  $handler->display->display_options['fields']['vopros_user_first_name']['relationship'] = 'profile';
  /* Field: Profile: Last name */
  $handler->display->display_options['fields']['vopros_user_last_name']['id'] = 'vopros_user_last_name';
  $handler->display->display_options['fields']['vopros_user_last_name']['table'] = 'field_data_vopros_user_last_name';
  $handler->display->display_options['fields']['vopros_user_last_name']['field'] = 'vopros_user_last_name';
  $handler->display->display_options['fields']['vopros_user_last_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['vopros_user_last_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['vopros_user_last_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['vopros_user_last_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['vopros_user_last_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['vopros_user_last_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['vopros_user_last_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['vopros_user_last_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['vopros_user_last_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['vopros_user_last_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['vopros_user_last_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['vopros_user_last_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['vopros_user_last_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['vopros_user_last_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['vopros_user_last_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['vopros_user_last_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['vopros_user_last_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['vopros_user_last_name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['vopros_user_last_name']['field_api_classes'] = 0;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['external'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['mail']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['mail']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['html'] = 0;
  $handler->display->display_options['fields']['mail']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['mail']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['mail']['hide_empty'] = 0;
  $handler->display->display_options['fields']['mail']['empty_zero'] = 0;
  $handler->display->display_options['fields']['mail']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['mail']['link_to_user'] = 0;
  /* Field: Profile: Phone number */
  $handler->display->display_options['fields']['vopros_user_phone_number']['id'] = 'vopros_user_phone_number';
  $handler->display->display_options['fields']['vopros_user_phone_number']['table'] = 'field_data_vopros_user_phone_number';
  $handler->display->display_options['fields']['vopros_user_phone_number']['field'] = 'vopros_user_phone_number';
  $handler->display->display_options['fields']['vopros_user_phone_number']['relationship'] = 'profile';
  $handler->display->display_options['fields']['vopros_user_phone_number']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['vopros_user_phone_number']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['vopros_user_phone_number']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['vopros_user_phone_number']['alter']['external'] = 0;
  $handler->display->display_options['fields']['vopros_user_phone_number']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['vopros_user_phone_number']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['vopros_user_phone_number']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['vopros_user_phone_number']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['vopros_user_phone_number']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['vopros_user_phone_number']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['vopros_user_phone_number']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['vopros_user_phone_number']['alter']['html'] = 0;
  $handler->display->display_options['fields']['vopros_user_phone_number']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['vopros_user_phone_number']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['vopros_user_phone_number']['hide_empty'] = 0;
  $handler->display->display_options['fields']['vopros_user_phone_number']['empty_zero'] = 0;
  $handler->display->display_options['fields']['vopros_user_phone_number']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['vopros_user_phone_number']['field_api_classes'] = 0;
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['operator'] = 'not in';
  $handler->display->display_options['filters']['uid']['value'] = array(
    0 => 0,
  );
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['uid']['expose']['reduce'] = 0;
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['filters']['uid_1']['table'] = 'users';
  $handler->display->display_options['filters']['uid_1']['field'] = 'uid';
  $handler->display->display_options['filters']['uid_1']['value'] = '';
  $handler->display->display_options['filters']['uid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid_1']['expose']['operator_id'] = 'uid_1_op';
  $handler->display->display_options['filters']['uid_1']['expose']['label'] = 'User name';
  $handler->display->display_options['filters']['uid_1']['expose']['operator'] = 'uid_1_op';
  $handler->display->display_options['filters']['uid_1']['expose']['identifier'] = 'uid_1';
  $handler->display->display_options['filters']['uid_1']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['uid_1']['expose']['reduce'] = 0;
  /* Filter criterion: Profile: First name (vopros_user_first_name) */
  $handler->display->display_options['filters']['vopros_user_first_name_value']['id'] = 'vopros_user_first_name_value';
  $handler->display->display_options['filters']['vopros_user_first_name_value']['table'] = 'field_data_vopros_user_first_name';
  $handler->display->display_options['filters']['vopros_user_first_name_value']['field'] = 'vopros_user_first_name_value';
  $handler->display->display_options['filters']['vopros_user_first_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['vopros_user_first_name_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['vopros_user_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['vopros_user_first_name_value']['expose']['operator_id'] = 'vopros_user_first_name_value_op';
  $handler->display->display_options['filters']['vopros_user_first_name_value']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['vopros_user_first_name_value']['expose']['operator'] = 'vopros_user_first_name_value_op';
  $handler->display->display_options['filters']['vopros_user_first_name_value']['expose']['identifier'] = 'vopros_user_first_name_value';
  $handler->display->display_options['filters']['vopros_user_first_name_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['vopros_user_first_name_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Profile: Last name (vopros_user_last_name) */
  $handler->display->display_options['filters']['vopros_user_last_name_value']['id'] = 'vopros_user_last_name_value';
  $handler->display->display_options['filters']['vopros_user_last_name_value']['table'] = 'field_data_vopros_user_last_name';
  $handler->display->display_options['filters']['vopros_user_last_name_value']['field'] = 'vopros_user_last_name_value';
  $handler->display->display_options['filters']['vopros_user_last_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['vopros_user_last_name_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['vopros_user_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['vopros_user_last_name_value']['expose']['operator_id'] = 'vopros_user_last_name_value_op';
  $handler->display->display_options['filters']['vopros_user_last_name_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['vopros_user_last_name_value']['expose']['operator'] = 'vopros_user_last_name_value_op';
  $handler->display->display_options['filters']['vopros_user_last_name_value']['expose']['identifier'] = 'vopros_user_last_name_value';
  $handler->display->display_options['filters']['vopros_user_last_name_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['vopros_user_last_name_value']['expose']['multiple'] = FALSE;
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
  $handler->display->display_options['path'] = 'admin/vopros/users';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Users';
  $handler->display->display_options['menu']['description'] = 'View the list of users.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $translatables['vopros_user_list'] = array(
    t('Master'),
    t('Vopros user list'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Profile'),
    t('User name'),
    t('Library'),
    t('First name'),
    t('Last name'),
    t('E-mail'),
    t('Phone number'),
    t('Name'),
    t('Page'),
  );

  $views['vopros_user_list'] = $view;

  return $views;
}
