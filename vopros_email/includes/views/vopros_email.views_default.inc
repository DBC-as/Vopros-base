<?php

/**
 * Implements hook_views_default_views().
 */
function vopros_email_views_default_views() {
  $views = array();

  // Email list of type inbound.
  $view = new view;
  $view = new view;
  $view->name = 'vopros_mail_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'vopros_email';
  $view->human_name = 'Mail list';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Mail list';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Email: Question_id */
  $handler->display->display_options['relationships']['question_id']['id'] = 'question_id';
  $handler->display->display_options['relationships']['question_id']['table'] = 'vopros_email';
  $handler->display->display_options['relationships']['question_id']['field'] = 'question_id';
  $handler->display->display_options['relationships']['question_id']['required'] = 0;
  /* Field: Question: Question_title */
  $handler->display->display_options['fields']['question_title']['id'] = 'question_title';
  $handler->display->display_options['fields']['question_title']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_title']['field'] = 'question_title';
  $handler->display->display_options['fields']['question_title']['relationship'] = 'question_id';
  $handler->display->display_options['fields']['question_title']['exclude'] = TRUE;
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
  /* Field: Email: Question_id */
  $handler->display->display_options['fields']['question_id']['id'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['table'] = 'vopros_email';
  $handler->display->display_options['fields']['question_id']['field'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['label'] = 'Question';
  $handler->display->display_options['fields']['question_id']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['question_id']['alter']['text'] = '[question_title]';
  $handler->display->display_options['fields']['question_id']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['question_id']['alter']['path'] = 'admin/vopros/question/[question_id]';
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
  /* Field: Email: Email */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'vopros_email';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  $handler->display->display_options['fields']['email']['label'] = 'Email address';
  $handler->display->display_options['fields']['email']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['email']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['email']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['email']['alter']['external'] = 0;
  $handler->display->display_options['fields']['email']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['email']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['email']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['email']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['email']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['email']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['email']['alter']['html'] = 0;
  $handler->display->display_options['fields']['email']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['email']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['email']['hide_empty'] = 0;
  $handler->display->display_options['fields']['email']['empty_zero'] = 0;
  /* Field: Email: Subject */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'vopros_email';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['external'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['subject']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['subject']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['html'] = 0;
  $handler->display->display_options['fields']['subject']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['subject']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['subject']['hide_empty'] = 0;
  $handler->display->display_options['fields']['subject']['empty_zero'] = 0;
  /* Field: Email: Email_content */
  $handler->display->display_options['fields']['email_content']['id'] = 'email_content';
  $handler->display->display_options['fields']['email_content']['table'] = 'vopros_email';
  $handler->display->display_options['fields']['email_content']['field'] = 'email_content';
  $handler->display->display_options['fields']['email_content']['label'] = 'Email content';
  $handler->display->display_options['fields']['email_content']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['email_content']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['email_content']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['email_content']['alter']['external'] = 0;
  $handler->display->display_options['fields']['email_content']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['email_content']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['email_content']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['email_content']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['email_content']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['email_content']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['email_content']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['email_content']['alter']['html'] = 0;
  $handler->display->display_options['fields']['email_content']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['email_content']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['email_content']['hide_empty'] = 0;
  $handler->display->display_options['fields']['email_content']['empty_zero'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/vopros/emails/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Email list';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Emails';
  $handler->display->display_options['tab_options']['description'] = 'Display a list of inbound emails';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['vopros_mail_list'] = array(
    t('Master'),
    t('Mail list'),
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
    t('Question_title'),
    t('Question'),
    t('[question_title]'),
    t('admin/vopros/question/[question_id]'),
    t('.'),
    t('Email address'),
    t('Subject'),
    t('Email content'),
    t('Page'),
  );

  $views[$view->name] = $view;


  // View to display the mail correspondence for a question.
  $view = new view;
  $view->name = 'vopros_email_question_cor';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'vopros_email';
  $view->human_name = 'Mail correspondence';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Mail correspondence';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'email' => 'email',
    'type' => 'type',
    'subject' => 'subject',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'subject' => array(
      'sortable' => 0,
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
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Field: Email: Email ID */
  $handler->display->display_options['fields']['email_id']['id'] = 'email_id';
  $handler->display->display_options['fields']['email_id']['table'] = 'vopros_email';
  $handler->display->display_options['fields']['email_id']['field'] = 'email_id';
  $handler->display->display_options['fields']['email_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['email_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['email_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['email_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['email_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['email_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['email_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['email_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['email_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['email_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['email_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['email_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['email_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['email_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['email_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['email_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['email_id']['separator'] = '';
  $handler->display->display_options['fields']['email_id']['format_plural'] = 0;
  /* Field: Email: Email */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'vopros_email';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  $handler->display->display_options['fields']['email']['label'] = 'Email address';
  $handler->display->display_options['fields']['email']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['email']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['email']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['email']['alter']['external'] = 0;
  $handler->display->display_options['fields']['email']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['email']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['email']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['email']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['email']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['email']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['email']['alter']['html'] = 0;
  $handler->display->display_options['fields']['email']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['email']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['email']['hide_empty'] = 0;
  $handler->display->display_options['fields']['email']['empty_zero'] = 0;
  /* Field: Email: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'vopros_email';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  /* Field: Email: Subject */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'vopros_email';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  /* Field: Email: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'vopros_email';
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
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Action';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View email';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'admin/vopros/emails/[email_id]';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  /* Contextual filter: Email: Question_id */
  $handler->display->display_options['arguments']['question_id']['id'] = 'question_id';
  $handler->display->display_options['arguments']['question_id']['table'] = 'vopros_email';
  $handler->display->display_options['arguments']['question_id']['field'] = 'question_id';
  $handler->display->display_options['arguments']['question_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['question_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['question_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['question_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['question_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['question_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['question_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['question_id']['not'] = 0;
  $translatables['vopros_email_question_cor'] = array(
    t('Master'),
    t('Mail correspondence'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Email ID'),
    t('.'),
    t('Email address'),
    t('Type'),
    t('Subject'),
    t('Created'),
    t('Action'),
    t('View email'),
    t('admin/vopros/emails/[email_id]'),
    t('All'),
  );

  $views[$view->name] = $view;

  return $views;
}
