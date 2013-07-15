<?php
/**
 * @file
 * vopros_user.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function vopros_user_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'vopros_user_profile_service';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'Vopros user profile service';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Profile: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  /* Field: Profile: Library */
  $handler->display->display_options['fields']['vopros_user_library']['id'] = 'vopros_user_library';
  $handler->display->display_options['fields']['vopros_user_library']['table'] = 'field_data_vopros_user_library';
  $handler->display->display_options['fields']['vopros_user_library']['field'] = 'vopros_user_library';
  $handler->display->display_options['fields']['vopros_user_library']['label'] = 'agency';
  $handler->display->display_options['fields']['vopros_user_library']['settings'] = array(
    'skip_safe' => 0,
    'skip_empty_values' => 1,
  );
  /* Field: Profile: Last name */
  $handler->display->display_options['fields']['vopros_user_last_name']['id'] = 'vopros_user_last_name';
  $handler->display->display_options['fields']['vopros_user_last_name']['table'] = 'field_data_vopros_user_last_name';
  $handler->display->display_options['fields']['vopros_user_last_name']['field'] = 'vopros_user_last_name';
  $handler->display->display_options['fields']['vopros_user_last_name']['label'] = 'last_name';
  $handler->display->display_options['fields']['vopros_user_last_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['vopros_user_last_name']['settings'] = array(
    'skip_safe' => 1,
    'skip_empty_values' => 0,
  );
  /* Field: Profile: First name */
  $handler->display->display_options['fields']['vopros_user_first_name']['id'] = 'vopros_user_first_name';
  $handler->display->display_options['fields']['vopros_user_first_name']['table'] = 'field_data_vopros_user_first_name';
  $handler->display->display_options['fields']['vopros_user_first_name']['field'] = 'vopros_user_first_name';
  $handler->display->display_options['fields']['vopros_user_first_name']['label'] = 'first_name';
  $handler->display->display_options['fields']['vopros_user_first_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['vopros_user_first_name']['settings'] = array(
    'skip_safe' => 0,
    'skip_empty_values' => 1,
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'user_name';
  /* Field: Profile: User uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'profile';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['fields']['user']['label'] = 'uid';
  $handler->display->display_options['fields']['user']['separator'] = '';
  /* Field: Profile: Description */
  $handler->display->display_options['fields']['field_vopros_user_description']['id'] = 'field_vopros_user_description';
  $handler->display->display_options['fields']['field_vopros_user_description']['table'] = 'field_data_field_vopros_user_description';
  $handler->display->display_options['fields']['field_vopros_user_description']['field'] = 'field_vopros_user_description';
  $handler->display->display_options['fields']['field_vopros_user_description']['label'] = 'description';
  $handler->display->display_options['fields']['field_vopros_user_description']['type'] = 'text_plain';
  /* Field: Profile: Image */
  $handler->display->display_options['fields']['field_vopros_user_image']['id'] = 'field_vopros_user_image';
  $handler->display->display_options['fields']['field_vopros_user_image']['table'] = 'field_data_field_vopros_user_image';
  $handler->display->display_options['fields']['field_vopros_user_image']['field'] = 'field_vopros_user_image';
  $handler->display->display_options['fields']['field_vopros_user_image']['label'] = 'image';
  $handler->display->display_options['fields']['field_vopros_user_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_vopros_user_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Profile: Expertise */
  $handler->display->display_options['fields']['field_vopros_user_expertise']['id'] = 'field_vopros_user_expertise';
  $handler->display->display_options['fields']['field_vopros_user_expertise']['table'] = 'field_data_field_vopros_user_expertise';
  $handler->display->display_options['fields']['field_vopros_user_expertise']['field'] = 'field_vopros_user_expertise';
  $handler->display->display_options['fields']['field_vopros_user_expertise']['label'] = 'expertise';
  $handler->display->display_options['fields']['field_vopros_user_expertise']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_vopros_user_expertise']['delta_offset'] = '0';
  /* Filter criterion: Profile: User uid */
  $handler->display->display_options['filters']['user']['id'] = 'user';
  $handler->display->display_options['filters']['user']['table'] = 'profile';
  $handler->display->display_options['filters']['user']['field'] = 'user';
  $handler->display->display_options['filters']['user']['exposed'] = TRUE;
  $handler->display->display_options['filters']['user']['expose']['operator_id'] = 'user_op';
  $handler->display->display_options['filters']['user']['expose']['label'] = 'User uid';
  $handler->display->display_options['filters']['user']['expose']['operator'] = 'user_op';
  $handler->display->display_options['filters']['user']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['user']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'user';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name (raw)';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'user_name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Services */
  $handler = $view->new_display('services', 'Services', 'services_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'vopros_user_profile_service';
  $translatables['vopros_user_profile_service'] = array(
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
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('User'),
    t('Profile ID'),
    t('.'),
    t(','),
    t('agency'),
    t('last_name'),
    t('first_name'),
    t('user_name'),
    t('uid'),
    t('description'),
    t('image'),
    t('expertise'),
    t('User uid'),
    t('Name (raw)'),
    t('Services'),
  );
  $export['vopros_user_profile_service'] = $view;

  return $export;
}
