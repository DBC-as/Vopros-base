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
  return $views;
}
