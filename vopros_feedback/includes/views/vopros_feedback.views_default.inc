<?php

/**
 * Implements hook_views_default_views().
 */
function vopros_feedback_views_default_views() {
  $views = array();

  // Feedback page, display the feedback given to a user.
  $view = new view;
  $view->name = 'vopros_feedback_user_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'vopros_feedback';
  $view->human_name = 'vopros_feedback_user_list';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Your feedback';
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access feedback';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Nulstil';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorter efter';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Poster pr side';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'feedback_id' => 'feedback_id',
    'email_id' => 'email_id',
    'question_id' => 'question_id',
    'question_title' => 'question_title',
    'nothing' => 'nothing',
    'vopros_feedback_rating' => 'vopros_feedback_rating',
    'feedback_content' => 'feedback_content',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'feedback_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'email_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
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
    'nothing' => array(
      'align' => '',
      'separator' => '',
    ),
    'vopros_feedback_rating' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'feedback_content' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Feedback: Email_id */
  $handler->display->display_options['relationships']['email_id']['id'] = 'email_id';
  $handler->display->display_options['relationships']['email_id']['table'] = 'vopros_feedback';
  $handler->display->display_options['relationships']['email_id']['field'] = 'email_id';
  $handler->display->display_options['relationships']['email_id']['required'] = 0;
  /* Relationship: Email: Question_id */
  $handler->display->display_options['relationships']['question_id']['id'] = 'question_id';
  $handler->display->display_options['relationships']['question_id']['table'] = 'vopros_email';
  $handler->display->display_options['relationships']['question_id']['field'] = 'question_id';
  $handler->display->display_options['relationships']['question_id']['relationship'] = 'email_id';
  $handler->display->display_options['relationships']['question_id']['label'] = 'spørgsmål';
  $handler->display->display_options['relationships']['question_id']['required'] = 0;
  /* Felt: Feedback: Feedback ID */
  $handler->display->display_options['fields']['feedback_id']['id'] = 'feedback_id';
  $handler->display->display_options['fields']['feedback_id']['table'] = 'vopros_feedback';
  $handler->display->display_options['fields']['feedback_id']['field'] = 'feedback_id';
  $handler->display->display_options['fields']['feedback_id']['label'] = '';
  $handler->display->display_options['fields']['feedback_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['feedback_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['feedback_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['feedback_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['feedback_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['feedback_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['feedback_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['feedback_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['feedback_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['feedback_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['feedback_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['feedback_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['feedback_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['feedback_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['feedback_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['feedback_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['feedback_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['feedback_id']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['feedback_id']['separator'] = '';
  $handler->display->display_options['fields']['feedback_id']['format_plural'] = 0;
  /* Felt: Email: Email ID */
  $handler->display->display_options['fields']['email_id']['id'] = 'email_id';
  $handler->display->display_options['fields']['email_id']['table'] = 'vopros_email';
  $handler->display->display_options['fields']['email_id']['field'] = 'email_id';
  $handler->display->display_options['fields']['email_id']['relationship'] = 'email_id';
  $handler->display->display_options['fields']['email_id']['label'] = '';
  $handler->display->display_options['fields']['email_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['email_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['email_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['email_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['email_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['email_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['email_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['email_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['email_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['email_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['email_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['email_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['email_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['email_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['email_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['email_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['email_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['email_id']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['email_id']['separator'] = '';
  $handler->display->display_options['fields']['email_id']['format_plural'] = 0;
  /* Felt: Email: Question_id */
  $handler->display->display_options['fields']['question_id']['id'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['table'] = 'vopros_email';
  $handler->display->display_options['fields']['question_id']['field'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['relationship'] = 'email_id';
  $handler->display->display_options['fields']['question_id']['label'] = '';
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
  $handler->display->display_options['fields']['question_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['question_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['question_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['question_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['question_id']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['question_id']['separator'] = '';
  $handler->display->display_options['fields']['question_id']['format_plural'] = 0;
  /* Felt: Spørgsmål: Question_title */
  $handler->display->display_options['fields']['question_title']['id'] = 'question_title';
  $handler->display->display_options['fields']['question_title']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_title']['field'] = 'question_title';
  $handler->display->display_options['fields']['question_title']['relationship'] = 'question_id';
  $handler->display->display_options['fields']['question_title']['label'] = 'Question';
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
  /* Felt: Answer link (link to email) */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Answer link (link to email)';
  $handler->display->display_options['fields']['nothing']['label'] = 'Answer';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'See answer sent to user';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'admin/vopros/emails/[email_id]';
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
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Felt: feedback: Rating */
  $handler->display->display_options['fields']['vopros_feedback_rating']['id'] = 'vopros_feedback_rating';
  $handler->display->display_options['fields']['vopros_feedback_rating']['table'] = 'field_data_vopros_feedback_rating';
  $handler->display->display_options['fields']['vopros_feedback_rating']['field'] = 'vopros_feedback_rating';
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
  $handler->display->display_options['fields']['vopros_feedback_rating']['settings'] = array(
    'expose' => 0,
    'feedback_enable' => 0,
    'style' => 'average',
    'text' => 'average',
  );
  $handler->display->display_options['fields']['vopros_feedback_rating']['field_api_classes'] = 0;
  /* Felt: Feedback: Feedback_content */
  $handler->display->display_options['fields']['feedback_content']['id'] = 'feedback_content';
  $handler->display->display_options['fields']['feedback_content']['table'] = 'vopros_feedback';
  $handler->display->display_options['fields']['feedback_content']['field'] = 'feedback_content';
  $handler->display->display_options['fields']['feedback_content']['label'] = 'Feedback';
  $handler->display->display_options['fields']['feedback_content']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['feedback_content']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['feedback_content']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['feedback_content']['alter']['external'] = 0;
  $handler->display->display_options['fields']['feedback_content']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['feedback_content']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['feedback_content']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['feedback_content']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['feedback_content']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['feedback_content']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['feedback_content']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['feedback_content']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['feedback_content']['alter']['html'] = 0;
  $handler->display->display_options['fields']['feedback_content']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['feedback_content']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['feedback_content']['hide_empty'] = 0;
  $handler->display->display_options['fields']['feedback_content']['empty_zero'] = 0;
  $handler->display->display_options['fields']['feedback_content']['hide_alter_empty'] = 0;
  /* Contextual filter: Feedback: User given feedback */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'vopros_feedback';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  /* Filter criterion: feedback: Rating (vopros_feedback_rating:rating) */
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['id'] = 'vopros_feedback_rating_rating';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['table'] = 'field_data_vopros_feedback_rating';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['field'] = 'vopros_feedback_rating_rating';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['exposed'] = TRUE;
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['expose']['operator_id'] = 'vopros_feedback_rating_rating_op';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['expose']['label'] = 'User rating';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['expose']['operator'] = 'vopros_feedback_rating_rating_op';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['expose']['identifier'] = 'vopros_feedback_rating_rating';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/vopros/feedback/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'User feedback';
  $handler->display->display_options['menu']['description'] = 'Display the feedback received by users';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Feedback';
  $handler->display->display_options['tab_options']['description'] = 'Display feedback given by users.';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['vopros_feedback_user_list'] = array(
    t('Master'),
    t('Your feedback'),
    t('mere'),
    t('Anvend'),
    t('Nulstil'),
    t('Sorter efter'),
    t('Asc'),
    t('Desc'),
    t('Poster pr side'),
    t('- Alle -'),
    t('Offset'),
    t('email'),
    t('spørgsmål'),
    t('.'),
    t('Spørgsmål'),
    t('admin/vopros/questions/[question_id]'),
    t('Svar'),
    t('See answer sent to user'),
    t('admin/vopros/emails/[email_id]'),
    t('Rating'),
    t('Feedback'),
    t('Alle'),
    t('User rating'),
    t('Page'),
  );

  $custom_translatables = array(
   t('Display feedback given by users.'),
   t('Feedback'),
   t('User feedback'),
  );

  $views[$view->name] = $view;

  return $views;
}
