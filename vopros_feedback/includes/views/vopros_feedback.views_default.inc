<?php

/**
 * Implements hook_views_default_views().
 */
function vopros_feedback_views_default_views() {
  $views = array();

  // Feedback page, display the feedback given to a user.
  $view = new view();
  $view->name = 'vopros_feedback_user_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'vopros_feedback';
  $view->human_name = 'vopros_feedback_user_list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Your feedback';
  $handler->display->display_options['use_more_always'] = FALSE;
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
  /* Relationship: Feedback: Email_id */
  $handler->display->display_options['relationships']['email_id']['id'] = 'email_id';
  $handler->display->display_options['relationships']['email_id']['table'] = 'vopros_feedback';
  $handler->display->display_options['relationships']['email_id']['field'] = 'email_id';
  /* Relationship: Email: Question_id */
  $handler->display->display_options['relationships']['question_id']['id'] = 'question_id';
  $handler->display->display_options['relationships']['question_id']['table'] = 'vopros_email';
  $handler->display->display_options['relationships']['question_id']['field'] = 'question_id';
  $handler->display->display_options['relationships']['question_id']['relationship'] = 'email_id';
  $handler->display->display_options['relationships']['question_id']['label'] = 'spørgsmål';
  /* Relationship: Feedback: User given feedback */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'vopros_feedback';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Feedback: Feedback ID */
  $handler->display->display_options['fields']['feedback_id']['id'] = 'feedback_id';
  $handler->display->display_options['fields']['feedback_id']['table'] = 'vopros_feedback';
  $handler->display->display_options['fields']['feedback_id']['field'] = 'feedback_id';
  $handler->display->display_options['fields']['feedback_id']['label'] = '';
  $handler->display->display_options['fields']['feedback_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['feedback_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['feedback_id']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['feedback_id']['separator'] = '';
  /* Field: Email: Email ID */
  $handler->display->display_options['fields']['email_id']['id'] = 'email_id';
  $handler->display->display_options['fields']['email_id']['table'] = 'vopros_email';
  $handler->display->display_options['fields']['email_id']['field'] = 'email_id';
  $handler->display->display_options['fields']['email_id']['relationship'] = 'email_id';
  $handler->display->display_options['fields']['email_id']['label'] = '';
  $handler->display->display_options['fields']['email_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['email_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['email_id']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['email_id']['separator'] = '';
  /* Field: Email: Question_id */
  $handler->display->display_options['fields']['question_id']['id'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['table'] = 'vopros_email';
  $handler->display->display_options['fields']['question_id']['field'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['relationship'] = 'email_id';
  $handler->display->display_options['fields']['question_id']['label'] = '';
  $handler->display->display_options['fields']['question_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['question_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['question_id']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['question_id']['separator'] = '';
  /* Field: Question: Question_title */
  $handler->display->display_options['fields']['question_title']['id'] = 'question_title';
  $handler->display->display_options['fields']['question_title']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_title']['field'] = 'question_title';
  $handler->display->display_options['fields']['question_title']['relationship'] = 'question_id';
  $handler->display->display_options['fields']['question_title']['label'] = 'Question';
  $handler->display->display_options['fields']['question_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['question_title']['alter']['path'] = 'admin/vopros/questions/[question_id]';
  $handler->display->display_options['fields']['question_title']['hide_alter_empty'] = FALSE;
  /* Field: Answer link (link to email) */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Answer link (link to email)';
  $handler->display->display_options['fields']['nothing']['label'] = 'Answer';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'See answer sent to user';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'admin/vopros/emails/[email_id]';
  /* Field: feedback: Rating */
  $handler->display->display_options['fields']['vopros_feedback_rating']['id'] = 'vopros_feedback_rating';
  $handler->display->display_options['fields']['vopros_feedback_rating']['table'] = 'field_data_vopros_feedback_rating';
  $handler->display->display_options['fields']['vopros_feedback_rating']['field'] = 'vopros_feedback_rating';
  $handler->display->display_options['fields']['vopros_feedback_rating']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['vopros_feedback_rating']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['vopros_feedback_rating']['settings'] = array(
    'expose' => 0,
    'feedback_enable' => 0,
    'style' => 'average',
    'text' => 'average',
  );
  /* Field: Feedback: Feedback_content */
  $handler->display->display_options['fields']['feedback_content']['id'] = 'feedback_content';
  $handler->display->display_options['fields']['feedback_content']['table'] = 'vopros_feedback';
  $handler->display->display_options['fields']['feedback_content']['field'] = 'feedback_content';
  $handler->display->display_options['fields']['feedback_content']['label'] = 'Feedback';
  $handler->display->display_options['fields']['feedback_content']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['feedback_content']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['feedback_content']['hide_alter_empty'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Contextual filter: Feedback: User given feedback */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'vopros_feedback';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Feedback: Email_id */
  $handler->display->display_options['relationships']['email_id']['id'] = 'email_id';
  $handler->display->display_options['relationships']['email_id']['table'] = 'vopros_feedback';
  $handler->display->display_options['relationships']['email_id']['field'] = 'email_id';
  /* Relationship: Email: Question_id */
  $handler->display->display_options['relationships']['question_id']['id'] = 'question_id';
  $handler->display->display_options['relationships']['question_id']['table'] = 'vopros_email';
  $handler->display->display_options['relationships']['question_id']['field'] = 'question_id';
  $handler->display->display_options['relationships']['question_id']['relationship'] = 'email_id';
  $handler->display->display_options['relationships']['question_id']['label'] = 'spørgsmål';
  /* Relationship: Email: Answer_id */
  $handler->display->display_options['relationships']['answer_id']['id'] = 'answer_id';
  $handler->display->display_options['relationships']['answer_id']['table'] = 'vopros_email';
  $handler->display->display_options['relationships']['answer_id']['field'] = 'answer_id';
  $handler->display->display_options['relationships']['answer_id']['relationship'] = 'email_id';
  $handler->display->display_options['relationships']['answer_id']['required'] = TRUE;
  /* Relationship: Answer: Answer owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'vopros_answer';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'answer_id';
  $handler->display->display_options['relationships']['uid']['label'] = 'answer_user';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['profile']['required'] = TRUE;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'vopros_user_librarian' => 'vopros_user_librarian',
  );
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile_1']['id'] = 'profile_1';
  $handler->display->display_options['relationships']['profile_1']['table'] = 'users';
  $handler->display->display_options['relationships']['profile_1']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile_1']['relationship'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Feedback: Feedback ID */
  $handler->display->display_options['fields']['feedback_id']['id'] = 'feedback_id';
  $handler->display->display_options['fields']['feedback_id']['table'] = 'vopros_feedback';
  $handler->display->display_options['fields']['feedback_id']['field'] = 'feedback_id';
  $handler->display->display_options['fields']['feedback_id']['label'] = '';
  $handler->display->display_options['fields']['feedback_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['feedback_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['feedback_id']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['feedback_id']['separator'] = '';
  /* Field: Email: Email ID */
  $handler->display->display_options['fields']['email_id']['id'] = 'email_id';
  $handler->display->display_options['fields']['email_id']['table'] = 'vopros_email';
  $handler->display->display_options['fields']['email_id']['field'] = 'email_id';
  $handler->display->display_options['fields']['email_id']['relationship'] = 'email_id';
  $handler->display->display_options['fields']['email_id']['label'] = '';
  $handler->display->display_options['fields']['email_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['email_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['email_id']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['email_id']['separator'] = '';
  /* Field: Email: Question_id */
  $handler->display->display_options['fields']['question_id']['id'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['table'] = 'vopros_email';
  $handler->display->display_options['fields']['question_id']['field'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['relationship'] = 'email_id';
  $handler->display->display_options['fields']['question_id']['label'] = '';
  $handler->display->display_options['fields']['question_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['question_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['question_id']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['question_id']['separator'] = '';
  /* Field: Question: Question_title */
  $handler->display->display_options['fields']['question_title']['id'] = 'question_title';
  $handler->display->display_options['fields']['question_title']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_title']['field'] = 'question_title';
  $handler->display->display_options['fields']['question_title']['relationship'] = 'question_id';
  $handler->display->display_options['fields']['question_title']['label'] = 'Question';
  $handler->display->display_options['fields']['question_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['question_title']['alter']['path'] = 'admin/vopros/questions/[question_id]';
  $handler->display->display_options['fields']['question_title']['hide_alter_empty'] = FALSE;
  /* Field: Answer link (link to email) */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Answer link (link to email)';
  $handler->display->display_options['fields']['nothing']['label'] = 'Answer';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'See answer sent to user';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'admin/vopros/emails/[email_id]';
  /* Field: feedback: Rating */
  $handler->display->display_options['fields']['vopros_feedback_rating']['id'] = 'vopros_feedback_rating';
  $handler->display->display_options['fields']['vopros_feedback_rating']['table'] = 'field_data_vopros_feedback_rating';
  $handler->display->display_options['fields']['vopros_feedback_rating']['field'] = 'vopros_feedback_rating';
  $handler->display->display_options['fields']['vopros_feedback_rating']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['vopros_feedback_rating']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['vopros_feedback_rating']['settings'] = array(
    'expose' => 0,
    'feedback_enable' => 0,
    'style' => 'average',
    'text' => 'average',
  );
  /* Field: Feedback: Feedback_content */
  $handler->display->display_options['fields']['feedback_content']['id'] = 'feedback_content';
  $handler->display->display_options['fields']['feedback_content']['table'] = 'vopros_feedback';
  $handler->display->display_options['fields']['feedback_content']['field'] = 'feedback_content';
  $handler->display->display_options['fields']['feedback_content']['label'] = 'Feedback';
  $handler->display->display_options['fields']['feedback_content']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['feedback_content']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['feedback_content']['hide_alter_empty'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: feedback: Rating (vopros_feedback_rating:rating) */
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['id'] = 'vopros_feedback_rating_rating';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['table'] = 'field_data_vopros_feedback_rating';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['field'] = 'vopros_feedback_rating_rating';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['exposed'] = TRUE;
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['expose']['operator_id'] = 'vopros_feedback_rating_rating_op';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['expose']['label'] = 'User rating';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['expose']['operator'] = 'vopros_feedback_rating_rating_op';
  $handler->display->display_options['filters']['vopros_feedback_rating_rating']['expose']['identifier'] = 'vopros_feedback_rating_rating';
  /* Filter criterion: Profile: Same library as current user */
  $handler->display->display_options['filters']['vopros_user_same_agency']['id'] = 'vopros_user_same_agency';
  $handler->display->display_options['filters']['vopros_user_same_agency']['table'] = 'field_data_vopros_user_library';
  $handler->display->display_options['filters']['vopros_user_same_agency']['field'] = 'vopros_user_same_agency';
  $handler->display->display_options['filters']['vopros_user_same_agency']['relationship'] = 'profile';
  $handler->display->display_options['filters']['vopros_user_same_agency']['value'] = '1';
  $handler->display->display_options['path'] = 'admin/vopros/feedback/agency';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Agency feedback';
  $handler->display->display_options['menu']['description'] = 'Display the feedback received by users in your agency';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Feedback';
  $handler->display->display_options['tab_options']['description'] = 'Display feedback given by users.';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  $views[$view->name] = $view;

  return $views;
}
