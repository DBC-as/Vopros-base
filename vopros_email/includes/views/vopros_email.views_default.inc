<?php

/**
 * Implements hook_views_default_views().
 */
function vopros_email_views_default_views() {
  $views = array();

  // Email list of type inbound.
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
  $handler->display->display_options['title'] = 'Ingoing mails not related to a question';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'email' => 'email',
    'subject' => 'subject',
    'email_content' => 'email_content',
    'email_id' => 'email_id',
    'nothing_4' => 'nothing',
    'nothing_3' => 'nothing',
    'nothing' => 'nothing',
    'nothing_2' => 'nothing',
    'nothing_1' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'email' => array(
      'sortable' => 0,
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
    'email_content' => array(
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
    'nothing_4' => array(
      'align' => '',
      'separator' => '',
    ),
    'nothing_3' => array(
      'align' => '',
      'separator' => '',
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
    ),
    'nothing_2' => array(
      'align' => '',
      'separator' => '',
    ),
    'nothing_1' => array(
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
  /* Field: Email: Subject */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'vopros_email';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['subject']['alter']['path'] = 'admin/vopros/emails/[email_id]';
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
  $handler->display->display_options['fields']['email_content']['alter']['nl2br'] = 1;
  $handler->display->display_options['fields']['email_content']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['email_content']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['email_content']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['email_content']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['email_content']['alter']['html'] = 0;
  $handler->display->display_options['fields']['email_content']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['email_content']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['email_content']['hide_empty'] = 0;
  $handler->display->display_options['fields']['email_content']['empty_zero'] = 0;
  /* Field: View link */
  $handler->display->display_options['fields']['nothing_4']['id'] = 'nothing_4';
  $handler->display->display_options['fields']['nothing_4']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_4']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_4']['ui_name'] = 'View link';
  $handler->display->display_options['fields']['nothing_4']['label'] = '';
  $handler->display->display_options['fields']['nothing_4']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nothing_4']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing_4']['alter']['path'] = 'admin/vopros/emails/[email_id]';
  $handler->display->display_options['fields']['nothing_4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_4']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nothing_4']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_4']['empty_zero'] = 0;
  /* Field: Break */
  $handler->display->display_options['fields']['nothing_3']['id'] = 'nothing_3';
  $handler->display->display_options['fields']['nothing_3']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_3']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_3']['ui_name'] = 'Break';
  $handler->display->display_options['fields']['nothing_3']['label'] = '';
  $handler->display->display_options['fields']['nothing_3']['alter']['text'] = '<br />';
  $handler->display->display_options['fields']['nothing_3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing_3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_3']['alter']['nl2br'] = 1;
  $handler->display->display_options['fields']['nothing_3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_3']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nothing_3']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_3']['empty_zero'] = 0;
  /* Field: Convert link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Convert link';
  $handler->display->display_options['fields']['nothing']['label'] = 'Action';
  $handler->display->display_options['fields']['nothing']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Convert';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'admin/vopros/emails/[email_id]/convert';
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
  /* Field: Break */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Break';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<br />';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nothing_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_2']['empty_zero'] = 0;
  /* Field: Delete link */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Delete link';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Delete';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'admin/vopros/emails/[email_id]/delete';
  $handler->display->display_options['fields']['nothing_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_1']['empty_zero'] = 0;
  /* Filter criterion: Email: Question_id */
  $handler->display->display_options['filters']['question_id']['id'] = 'question_id';
  $handler->display->display_options['filters']['question_id']['table'] = 'vopros_email';
  $handler->display->display_options['filters']['question_id']['field'] = 'question_id';
  $handler->display->display_options['filters']['question_id']['operator'] = '<';
  $handler->display->display_options['filters']['question_id']['value']['value'] = '1';

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
    t('Ingoing mails not related to a question'),
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
    t('Subject'),
    t('admin/vopros/emails/[email_id]'),
    t('Email content'),
    t('View'),
    t('<br />'),
    t('Action'),
    t('Convert'),
    t('admin/vopros/emails/[email_id]/convert'),
    t('Delete'),
    t('admin/vopros/emails/[email_id]/delete'),
    t('Page'),
  );
  
  $menu_translations = array(
    t('Display a list of inbound emails'),
    t('Emails'),
    t('Email list'),
  );

  $views[$view->name] = $view;

  return $views;
}
