<?php

/**
 * @ file
 * Admin forms and callback functions.
 */

/**
 * Question settings form
 */
function vopros_question_settings_form($form, &$form_state) {
  $form['vopros_question_qanda_service_options'] = array(
    '#type' => 'textarea',
    '#title' => t('Q and A service options'),
    '#description' => t('Setup the possible Q and A service options used in question list filters. Enter options as key|name and one per new line.'),
    '#default_value' => variable_get('vopros_question_qanda_service_options', ''),
  );

  return system_settings_form($form);
}

/**
 * Form to edit or create a question
 */
function vopros_question_question_form($form, &$form_state, $question) {
  $form['action'] = array(
    '#weight' => -1000,
    '#prefix' => '<div class="action">',
    '#suffix' => '</div>',
  );

  $form['action']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  // Add the field related form elements.
  $form['question'] = array(
    '#value' => $question,
    '#type' => 'value',
  );

  $form['form'] = array(
    '#prefix' => '<div class="form">',
    '#suffix' => '</div>',
  );

  field_attach_form('vopros_question', $question, $form['form'], $form_state);
  if (empty($form['form']['vopros_editorial']['und']['#default_value']) && !empty($form['form']['vopros_editorial']['und']['#options'])) {
    $options = $form['form']['vopros_editorial']['und']['#options'];
    if (isset($options['_none'])) {
      unset($options['_none']);
    }
    $form['form']['vopros_editorial']['und']['#default_value'] = array_shift(array_keys($options));
  }

  $form['form']['question_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#required' => TRUE,
    '#default_value' => isset($question->question_title) ? $question->question_title : '',
    '#weight' => -12,
  );

  $form['form']['question_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Question content'),
    '#required' => TRUE,
    '#default_value' => isset($question->question_content) ? $question->question_content : '',
    '#weight' => -11,
  );

  $form['form']['question_status'] = array(
    '#type' => 'select',
    '#title' => t('Status'),
    '#options' => _vopros_question_status(),
    '#default_value' => isset($question->question_status) ? $question->question_status : '',
    '#weight' => -10,
  );

  $form['form']['question_deadline'] = array(
    '#type' => 'select',
    '#title' => t('Deadline'),
    '#options' => _vopros_question_deadline(),
    '#default_value' => isset($question->question_deadline) ? $question->question_deadline : -1,
  );

  $form['form']['question_usage'] = array(
    '#type' => 'select',
    '#title' => t('Usage'),
    '#options' => _vopros_question_usage(),
    '#default_value' => isset($question->question_usage) ? $question->question_usage : '',
  );

  $form['form']['question_note'] = array(
    '#type' => 'textarea',
    '#title' => t('Note about the question'),
    '#default_value' => isset($question->question_note) ? $question->question_note : '',
  );

  $form['form']['ask'] = array(
    '#type' => 'fieldset',
    '#title' => t('Info about person who asked the question'),
    '#collapsible' => TRUE,
  );
  

  $form['form']['ask']['user_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => isset($question->user_name) ? $question->user_name : '',
  );

  $form['form']['ask']['user_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#default_value' => isset($question->user_email) ? $question->user_email : '',
  );

  $form['form']['ask']['user_postal_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Postal code'),
    '#default_value' => isset($question->user_postal_code) ? $question->user_postal_code : '',
  );

  $form['form']['ask']['user_mobile_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile phone'),
    '#default_value' => isset($question->user_mobile_phone) ? $question->user_mobile_phone : '',
  );

  $form['form']['ask']['user_age'] = array(
    '#type' => 'select',
    '#title' => t('Age'),
    '#default_value' => isset($question->user_age) ? $question->user_age : '',
    '#options' => _vopros_question_user_age(),
  );

  $form['form']['ask']['user_gender'] = array(
    '#type' => 'select',
    '#title' => t('Gender'),
    '#options' => _vopros_question_user_gender(),
    '#default_value' => isset($question->user_gender) ? $question->user_gender : '',
  );

  $form['form']['ask']['user_field_of_study'] = array(
    '#type' => 'textfield',
    '#title' => t('Field of study'),
    '#default_value' => isset($question->user_field_of_study) ? $question->user_field_of_study : '',
  );

  $form['form']['ask']['user_library'] = array(
    '#type' => 'textfield',
    '#title' => t('Library'),
    '#default_value' => isset($question->user_library) ? $question->user_library : '',
  );

  $form['form']['ask']['user_answer_preference'] = array(
    '#type' => 'select',
    '#title' => t('How to recieve answer'),
    '#options' => array(
      'mail' => t('Email'),
      'sms' => t('SMS'),
    ),
    '#default_value' => isset($question->user_answer_preference) ? $question->user_answer_preference : '',
  );

  $form['form']['buttons'] = array(
    '#weight' => 100,
  );

  $form['form']['buttons']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#attributes' => array('class' => array('primary-action')),
    
  );

  return $form;
}

/**
 * Validate handler for vopros_question_question_form().
 */
function vopros_question_question_form_validate(&$form, &$form_state) {
  $question = $form_state['values']['question'];
  field_attach_validate('vopros_question', $question, $form['form'], $form_state);
}

/**
 * Submit handler for vopros_question_question_form().
 */
function vopros_question_question_form_submit(&$form, &$form_state) {
  $question = $form_state['values']['question'];

  $info = entity_get_property_info('vopros_question');

  foreach ($info['properties'] as $key => $property) {
    if (isset($form_state['values'][$key])) {
      $question->{$key} = $form_state['values'][$key];
    }
  }

  if (!isset($question->created) || empty($question->created)) {
    // Set the created time 1 second in the past to make it different from the changed.
    // This is to make sure that we don't hit the edit page on first view.
    $question->created = REQUEST_TIME - 1;
  }

  // Notify field widgets.
  field_attach_submit('vopros_question', $question, $form['form'], $form_state);

  // Save the product.
  vopros_question_save($question);
  // Add the question to the $form_state for other modules to use.
  $form_state['question'] = $question;
  $form_state['redirect'] = 'admin/vopros/questions/' . $question->question_id;
}

/**
 * Ajax form for changing the title with ajax.
 */
function vopros_question_title_form($form, &$form_state, $question) {
  $form_state['build_info']['files']['form'] = drupal_get_path('module', 'vopros_question') . '/includes/vopros_question.admin.inc';
  
  $form['title'] = array(
    '#type' => 'textfield',
    '#default_value' => $question->question_title,
  );

  $form['question'] = array(
    '#type' => 'value',
    '#value' => $question,
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#ajax' => array(
      'callback' => 'vopros_question_title_form_save',
    ),
  );

  $form['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#ajax' => array(
      'callback' => 'vopros_question_title_form_cancel',
    ),
  );

  return $form;
}

/**
 * Handle the display of a question
 */
function vopros_question_page_view($question, $view_mode = 'administrator', $langcode = NULL) {
  if ($question->created == $question->changed) {
    drupal_goto('admin/vopros/questions/' . $question->question_id . '/edit');
  }
  drupal_add_js(drupal_get_path('module', 'vopros_question') . '/js/vopros_question_title.js');
  drupal_add_css(drupal_get_path('module', 'vopros_question') . '/theme/vopros_question_title.css');
  drupal_add_css(drupal_get_path('module', 'vopros_question') . '/theme/vopros_question_page.css');
  drupal_add_js(array('vopros_question_id' => $question->question_id), 'setting');

  // View mode is needed to sort the build array.
  $build = array('right' => array());

  $build[] = array(
    '#markup' => '<div class="hidden title-form">' . drupal_render(drupal_get_form('vopros_question_title_form', $question)) . '</div>',
  );

  // Populate $vopros_question->content with a render() array.
  vopros_question_build_content($question, $view_mode, $langcode);

  $build = $question->content + $build;
  unset($question->content);

  $build += array(
    '#view_mode' => $view_mode,
    '#theme' => 'vopros_question',
    '#question' => $question,
    '#language' => $langcode,
  );

  $type = 'vopros_question';
  drupal_alter(array('vopros_question_view', 'entity_view'), $build, $type);

  return $build;
}

/**
 * AJAX callback saving title
 */
function vopros_question_title_form_save(&$form, &$form_state) {
  // Save the question.
  $question = $form_state['values']['question'];
  $question->question_title = $form_state['values']['title'];
  vopros_question_save($question, 0);
  // Send back ajax commands.
  $commands = array();
  $commands[] = ajax_command_invoke('#vopros-question-title-form', 'appendTo', array('.title-form'));
  $commands[] = ajax_command_invoke('h2.question-title', 'show', array());
  $commands[] = ajax_command_invoke('h2.question-title', 'text', array($form_state['values']['title']));
  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * AJAX callback cancel
 */
function vopros_question_title_form_cancel(&$form, &$form_state) {
  $commands = array();
  $commands[] = ajax_command_invoke('#edit-title', 'attr', array('value', $form['title']['#default_value']));
  $commands[] = ajax_command_invoke('#vopros-question-title-form', 'appendTo', array('.title-form'));
  $commands[] = ajax_command_invoke('h2.question-title', 'show');
  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Form to display revisions for an question.
 */
function vopros_question_revisions_form($form, &$form_state, $question) {
  $form['#theme'] = 'diff_node_revisions';

  $form['question'] = array(
    '#type' => 'value',
    '#value' => $question,
  );

  $revisions = vopros_question_revision_list($question);
  $revision_ids = array();

  foreach ($revisions as $revision) {
    $revision->account = user_load($revision->revision_uid);
    $operations = array();
    $revision_ids[$revision->revision_id] = '';

    if ($revision->revision_id == $question->revision_id) {
      $form['info'][$revision->revision_id] = array(
        '#markup' => t('!date by !username', array(
          '!date' => l(format_date($revision->revision_timestamp, 'small'), "admin/vopros/questions/$question->question_id"),
          '!username' => theme('username', (array) $revision)))
        . (($revision->log != '') ? '<p class="revision-log">'. filter_xss($revision->log) .'</p>' : ''),
      );
    }
    else {
      $form['info'][$revision->revision_id] = array(
        '#markup' => t('!date by !username', array(
          '!date' => l(format_date($revision->revision_timestamp, 'small'), "admin/vopros/questions/$question->question_id/revisions/$revision->revision_id/view"),
          '!username' => theme('username', (array) $revision)))
        . (($revision->log != '') ? '<p class="revision-log">'. filter_xss($revision->log) .'</p>' : '')
      );
      $operations[] = array('#markup' => l(t('revert'), "admin/vopros/questions/$question->question_id/revisions/$revision->revision_id/revert"));
      // Set a dummy, even if the user has no permission for the other
      // operations, so that we can check if the operations array is
      // empty to know if the row denotes the current revision.
      $operations[] = array();
    }
    $form['operations'][$revision->revision_id] = $operations;

  }
  $new_revision_id = key($revision_ids);
  next($revision_ids);
  $old_revision_id = key($revision_ids);
  $form['diff']['old'] = array(
    '#type' => 'radios',
    '#options' => $revision_ids,
    '#default_value' => $old_revision_id
  );
  $form['diff']['new'] = array(
    '#type' => 'radios',
    '#options' => $revision_ids,
    '#default_value' => $new_revision_id
  );
  $form['submit'] = array('#type' => 'submit', '#value' => t('Show diff'));

  return $form;
}

/**
 * Submit code for input form to select two revisions.
 */
function vopros_question_revisions_form_submit($form, &$form_state) {
  // the ids are ordered so the old revision is always on the left
  $old_revision_id = min($form_state['values']['old'], $form_state['values']['new']);
  $new_revision_id = max($form_state['values']['old'], $form_state['values']['new']);
  $form_state['redirect'] =  'admin/vopros/questions/'. $form_state['values']['question']->question_id .'/revisions/view/'. $old_revision_id .'/'. $new_revision_id;
}

/**
 * Show the diff for two questions.
 */
function vopros_question_diffs_show($question, $old_revision_id, $new_revision_id) {
  module_load_include('inc', 'diff', 'diff.pages');
  $old_question = vopros_question_load($question->question_id, $old_revision_id);
  $old_question->account = user_load($old_question->revision_uid);
  $new_question = vopros_question_load($question->question_id, $new_revision_id);
  $new_question->account = user_load($new_question->revision_uid);

  // Generate table header (date, username, logmessage).
  $old_header = t('!date by !username', array(
    '!date' => l(format_date($old_question->revision_timestamp), "admin/vopros/questions/$question->question_id/revisions/$old_question->revision_id/view"),
    '!username' => theme('username', (array) $old_question),
  ));
  $new_header = t('!date by !username', array(
    '!date' => l(format_date($new_question->revision_timestamp), "admin/vopros/questions/$question->question_id/revisions/$new_question->revision_id/view"),
    '!username' => theme('username', (array) $new_question),
  ));

  $old_log = $old_question->log != '' ? '<p class="revision-log">'. filter_xss($old_question->log) .'</p>' : '';
  $new_log = $new_question->log != '' ? '<p class="revision-log">'. filter_xss($new_question->log) .'</p>' : '';

  // Get the next and previous revisions.
  $revisions = vopros_question_revision_list($question);
  ksort($revisions);
  $prev_revision = $next_revision_id = 0;
  $get_next_revision = FALSE;
  foreach ($revisions as $revision_id => $value) {
    if ($get_next_revision == TRUE) {
      $get_next_revision = FALSE;
      $next_revision_id = $revision_id;
    }
    if ($revision_id == $new_question->revision_id) {
      $get_next_revision = TRUE;
    }
    if ($revision_id == $old_question->revision_id) {
      $prev_revision_id = $prev_revision;
    }
    $prev_revision = $revision_id;
  }

  if ($next_revision_id) {
    $next_link = l(t('next diff >'), 'admin/vopros/questions/'. $question->question_id .'/revisions/view/'. $new_question->revision_id .'/'. $next_revision_id);
  }
  else {
    $next_link = '';
  }
  if ($prev_revision_id) {
    $prev_link = l(t('< previous diff'), 'admin/vopros/questions/'. $question->question_id .'/revisions/view/'. $prev_revision_id .'/'. $old_question->revision_id);
  }
  else {
    $prev_link = '';
  }

  $cols = _diff_default_cols();
  $header = _diff_default_header($old_header, $new_header);
  $rows = array();
  if ($old_log || $new_log) {
    $rows[] = array(
      array(
        'data' => $old_log,
        'colspan' => 2
      ),
      array(
        'data' => $new_log,
        'colspan' => 2
      )
    );
  }
  $rows[] = array(
    array(
      'data' => $prev_link,
      'class' => array('diff-prevlink'),
      'colspan' => 2
    ),
    array(
      'data' => $next_link,
      'class' => array('diff-nextlink'),
      'colspan' => 2
    )
  );
  $rows = array_merge($rows, _vopros_question_diff_rows($old_question, $new_question));
  $output = theme('diff_table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('diff')), 'cols' => $cols));

  if ($question->revision_id == $new_question->revision_id) {
    $output .= '<div class="diff-section-title">'. t('Current revision:') .'</div>';
  }
  else {
    $output .= '<div class="diff-section-title">'. t('Revision of !new_date:', array('!new_date' => format_date($new_question->revision_timestamp))) .'</div>';
  }
  return $output;
}

/**
 * Creates an array of rows which represent a diff between $old_question and $new_question.
 * The rows can be used via theme('diff_table') to be displayed.
 *
 * @param $old_question
 *   Node for comparison which will be displayed on the left side.
 * @param $new_question
 *   Node for comparison which will be displayed on the right side.
 */
function _vopros_question_diff_rows($old_question, $new_question) {
  drupal_add_css(drupal_get_path('module', 'diff') .'/diff.css', 'module', 'all', FALSE);

  $rows = array();
  $any_visible_change = FALSE;

  $question_diffs = array();
  $info = entity_get_property_info('vopros_question');
  $p = $info['properties'];
  $select = array(
    'question_usage' => _vopros_question_usage(),
    'question_status' => _vopros_question_status(),
    'question_deadline' => _vopros_question_deadline(),
  );

  $single_line = array(
    'question_title',
    'question_status',
    'question_usage',
    'question_deadline',
    'user_name',
    'user_email',
    'user_postal_code',
    'user_mobile_phone',
    'user_age',
    'user_gender',
    'user_field_of_study',
    'user_library',
    'user_answer_preference',
  );

  foreach ($single_line as $key) {
    $question_diffs[$key] = array(
      '#name' => str_replace('_', ' ', $p[$key]['label']),
      '#old' => array(isset($select[$key]) ? $select[$key][$old_question->{$key}] : $old_question->{$key}),
      '#new' => array(isset($select[$key]) ? $select[$key][$new_question->{$key}] : $new_question->{$key}),
      '#format' => array(
        'show_header' => FALSE,
      ),
    );
  }

  $multi_line = array(
    'question_content',
    'question_note',
  );

  foreach ($multi_line as $key) {
    $question_diffs[$key] = array(
      '#name' => str_replace('_', ' ', $p[$key]['label']),
      '#old' => explode("\n", $new_question->{$key}),
      '#new' => explode("\n", $old_question->{$key}),
    );
  }

  // @TODO: Add diff for fields
  /*$instances = field_info_instances('node', field_extract_bundle('node', $type));
  foreach ($instances as $instance) {
    $field_name = $instance['field_name'];
    $langcode = field_language('node', $new_node, $field_name);
    if (isset($new_node->{$field_name}[$langcode])) {
      foreach (array_keys($new_node->{$field_name}[$langcode]) as $delta) {
        if (isset($new_node->{$field_name}[$langcode][$delta]['value'])) {
          $view_old = $old_node->{$field_name}[$langcode][$delta]['value'];
          $view_new = $new_node->{$field_name}[$langcode][$delta]['value'];
          $result["{$field_name}_{$delta}"] = array(
            '#name' => t($instance['label']),
            '#old' => explode("\n", $view_old),
            '#new' => explode("\n", $view_new),
          );
        }
      }
    }
  }*/

  // We start off assuming all form elements are in the correct order.
  $question_diffs['#sorted'] = TRUE;

  // Recurse through all child elements.
  $count = 0;
  foreach (element_children($question_diffs) as $key) {
    // Assign a decimal placeholder weight to preserve original array order.
    if (!isset($question_diffs[$key]['#weight'])) {
      $question_diffs[$key]['#weight'] = $count/1000;
    }
    else {
      // If one of the child elements has a weight then we will need to sort
      // later.
      unset($question_diffs['#sorted']);
    }
    $count++;
  }

  // One of the children has a #weight.
  if (!isset($question_diffs['#sorted'])) {
    uasort($question_diffs, "element_sort");
  }

  // Render diffs for each.
  foreach ($question_diffs as $question_diff) {
    $show_header = isset($question_diff['#format']['show_header']) ? $question_diff['#format']['show_header'] : FALSE;
    if ($question_diff_rows = diff_get_rows($question_diff['#old'], $question_diff['#new'], $show_header)) {
      $rows[] = array(array(
        'data' => t('Changes to %name', array('%name' => $question_diff['#name'])),
        'class' => 'diff-section-title',
        'colspan' => 4
      ));
      $rows = array_merge($rows, $question_diff_rows);
      $any_visible_change = TRUE;
    }
  }
  if (!$any_visible_change) {
    $rows[] = array(array(
      'data' => t('No visible changes'),
      'class' => 'diff-section-title',
      'colspan' => 4
    ));
    // Needed to keep safari happy
    $rows[] = array(
      array('data' => ''),
      array('data' => ''),
      array('data' => ''),
      array('data' => ''),
    );
  }
  return $rows;
}

/**
 * Menu callback: Revert a question to different revision.
 */
function vopros_question_revision_revert($question, $revision) {
  if ($question->revision_id != $revision->revision_id && $question->question_id == $revision->question_id) {
    drupal_write_record('vopros_question', $revision, 'question_id');
  }
  return drupal_goto('admin/vopros/questions/' . $question->question_id . '/revisions');
}

/**
 * Form to close a question.
 */
function vopros_question_close_question_form($form, &$form_state, $question) {
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Close question'),
  );

  $form['question'] = array(
    '#type' => 'value',
    '#value' => $question,
  );

  $form['reason'] = array(
    '#type' => 'radios',
    '#title' => t('Reason to close the question'),
    '#options' => vopros_question_get_reasons('close'),
    '#required' => TRUE,
    '#ajax' => array(
      'callback' => 'vopros_question_close_question_form_ajax',
    ),
  );

  return $form;
}

/**
 * JS effect when changing reasons.
 */
function vopros_question_close_question_form_ajax(&$form, &$form_state) {
  $commands = array();
  if ($form_state['values']['reason'] == 'answered' || $form_state['values']['reason'] == 'published') {
    $commands[] = ajax_command_invoke('.form-item-log-content', 'hide', array());
  }
  else {
    $commands[] = ajax_command_invoke('.form-item-log-content', 'show', array());
  }
  
  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Submit handler for vopros_question_close_question_form().
 */
function vopros_question_close_question_form_submit(&$form, &$form_state) {
  $v = $form_state['values'];
  $question = $v['question'];
  if ($v['reason'] == 'answered') {
    $question->question_status = 'answered';
    $question->question_status_reason = 'already answered';
    drupal_set_message(t('Question has been marked as answered'), 'warning');
  }
  elseif ($v['reason'] == 'published') {
    $question->question_status = 'published';
    $question->question_status_reason = 'already published';
    drupal_set_message(t('Question has been marked as published'), 'warning');
  }
  else {
    $question->question_status = 'closed';
    $question->question_status_reason = $v['reason'];
    drupal_set_message(t('Question has been closed and wont be answered'), 'warning');
  }
  
  vopros_question_save($question);
  $form_state['redirect'] = 'admin/vopros/questions';
  
}

/**
 * Front form that create a form with click to edit fields.
 */
function vopros_question_question_frontend_form($form, &$form_state, $question) {
  $form['action'] = array(
    '#weight' => -1000,
    '#prefix' => '<div class="action">',
    '#suffix' => '</div>',
  );
  $form += vopros_question_question_form($form, $form_state, $question);

  $form['#validate'] = array('vopros_question_question_form_validate');
  $form['#submit'] = array('vopros_question_question_form_submit');

  $form['action']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => -100,
    '#submit' => array('vopros_question_frontend_save_submit'),
  );

  $hidden = array(
    'question_status',
  );

  $click_to_edit = array(
    'question_content',
    'question_deadline',
    'question_usage',
    'question_note',
    'user_name',
    'user_email',
    'user_postal_code',
    'user_mobile_phone',
    'user_age',
    'user_gender',
    'user_field_of_study',
    'user_library',
    'user_answer_preference',
  );

  $new_hidden = array(
    'question_deadline',
    'question_usage',
    'question_note',
    'user_name',
    'user_email',
    'user_postal_code',
    'user_mobile_phone',
    'user_age',
    'user_gender',
    'user_field_of_study',
    'user_library',
    'user_answer_preference',
  );

  foreach ($form['form']['ask'] as $key => $value) {
    if (is_array($value)) {
      $form['form'][$key] = $value;
    }
  }
  unset($form['form']['ask']);

  $extra_class = '';
  if ($question->created == $question->changed) {
    $extra_class = 'hidden';
  }

  foreach ($click_to_edit as $form_field) {
    if (isset($form['form'][$form_field])) {
      $form['form'][$form_field]['#prefix'] = '<div class="hidden">';
      $form['form'][$form_field]['#suffix'] = '</div>';
      $default_value = $form['form'][$form_field]['#default_value'];
      if (isset($form['form'][$form_field]['#options']) && isset($form['form'][$form_field]['#options'][$default_value])) {
        $default_value = $form['form'][$form_field]['#options'][$default_value];
      }
      if ($default_value) {
        $class = in_array($form_field, $new_hidden) ? $extra_class : '';
        $form['form'][$form_field]['#prefix'] = '<div class="form-wrapper fake-wrapper ' . $class . '"><div class="form-item fake-wrapper"><label>' . $form['form'][$form_field]['#title'] . '</label><div class="fake-form-item">' . $default_value . '</div><div class="tooltip">' . t('Click to edit') .'</div></div></div>' . $form['form'][$form_field]['#prefix'];
      }
    }
  }

  foreach ($hidden as $form_field) {
    $form['form'][$form_field]['#type'] = 'hidden';
  }

  if ($question->created == $question->changed) {
    $form['form']['show_all'] = array(
      '#type' => 'button',
      '#value' => t('Show complete form'),
      '#weight' => 99,
      '#prefix' => '<div class="show-all">',
      '#suffix' => '</div>',
      '#ajax' => array(
        'callback' => 'vopros_question_question_frontend_form_show_all_ajax',
      ),
    );
  }

  $form['form']['buttons']['save']['#submit'] = array('vopros_question_frontend_save_submit');
  

  $form['form']['buttons']['contact'] = array(
    '#value' => t('Contact user'),
    '#type' => 'submit',
  );

  $form['form']['buttons']['close'] = array(
    '#value' => t('Close question'),
    '#type' => 'submit',
    '#submit' => array('vopros_question_handle_question_form_close_submit'),
  );

  return $form;
}

function vopros_question_question_frontend_form_show_all_ajax(&$form, &$form_state) {
  $commands = array();
  $commands[] = ajax_command_invoke('.fake-wrapper.hidden', 'show', array());
  $commands[] = ajax_command_invoke('.show-all', 'hide', array());
  return array('#type' => 'ajax', '#commands' => $commands);
}

function vopros_question_frontend_save_submit(&$form, &$form_state) {
  vopros_question_question_form_submit($form, $form_state);
  if ($form['question']['#value']->created == $form['question']['#value']->changed) {
    $form_state['redirect'] = 'admin/vopros/questions/list';
  }
  else {
    $form_state['redirect'] = 'admin/vopros/questions/' . $form_state['values']['question']->question_id;
  }
  $form_state['redirect'] = 'admin/vopros/questions/list';
  drupal_set_message(t('Question has been saved'));
  
}
