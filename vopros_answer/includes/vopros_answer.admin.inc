<?php

/**
 * @ file
 * Admin forms and callback functions.
 */

/**
 * Answer settings form
 */
function vopros_answer_settings_form($form, &$form_state) {
  return system_settings_form($form);
}

/**
 * The answer page used when answering questions.
 */
function vopros_answer_answer_page($question, $answer) {
  module_load_include('inc', 'vopros_question', 'includes/vopros_question.admin');
  drupal_add_js(drupal_get_path('module', 'vopros_question') . '/js/vopros_question_title.js');
  drupal_add_css(drupal_get_path('module', 'vopros_question') . '/theme/vopros_question_title.css');
  if (empty($question)) {
    $question = vopros_question_load($answer->question_id);
  }

  $build = array(
    'answer_form' => drupal_get_form('vopros_answer_form', $question, $answer),
  );
  return $build;
}

/**
 * Answer form
 */
function vopros_answer_form($form, &$form_state, $question, $answer) {
  // Add the field related form elements.
  field_attach_form('vopros_answer', $answer, $form, $form_state);

  $form['action'] = array(
    '#prefix' => '<div class="action">',
    '#suffix' => '</div>',
  );

  $form['action']['save_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save and send'),
    '#submit' => array('vopros_answer_form_save_submit_submit'),
    '#validate' => array('vopros_answer_form_submit_validate'),
  );

  $form['form'] = array(
    '#prefix' => '<div class="form">',
    '#suffix' => '</div>',
  );

  $question_build = vopros_question_page_view($question, 'teaser');
  $question_build['question_title']['#suffix'] = '<span class="back-to-question">(' . l('See question', 'admin/vopros/questions/' . $question->question_id, array('attributes' => array('target' => '_blank'))) . ')</span>';
  $question_intro = array(
    $question_build['question_title'],
    $question_build['question_content'],
  );
  $question_data = array(
    $question_build['question_deadline'],
    $question_build['question_usage'],
    $question_build['question_note'],
  );

  $question_user_data = array(
    $question_build['ask'],
  );
  

  $form['form']['question_intro'] = array(
    '#markup' => render($question_intro),
  );

  $form['question'] = array(
    '#type' => 'value',
    '#value' => $question,
  );

  $form['answer'] = array(
    '#type' => 'value',
    '#value' => $answer,
  );

  $form['form']['answer_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Answer'),
    '#default_value' => isset($answer->answer_content) ? $answer->answer_content : '',
    '#rows' => 10,
  );

  $form['form']['user_answer_preference'] = array(
    '#question' => $question,
    '#theme' => 'vopros_question_user_answer_preference',
  );

  $form['form']['question_data'] = array(
    '#type' => 'fieldset',
    '#title' => t('Question data'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['form']['question_data']['content'] = array(
    '#markup' => render($question_data),
  );

  $form['form']['question_user_data'] = array(
    '#type' => 'fieldset',
    '#title' => t('User data'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['form']['question_user_data']['content'] = array(
    '#markup' => render($question_user_data),
  );
  

  $form['form']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => array('vopros_answer_form_save_submit'),
    '#validate' => array('vopros_answer_form_submit_validate'),
  );

  $form['form']['save_release'] = array(
    '#type' => 'submit',
    '#value' => t('Save and release'),
    '#submit' => array('vopros_answer_form_save_release_submit'),
    '#validate' => array('vopros_answer_form_submit_validate'),
  );

  $form['form']['save_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save and send'),
    '#submit' => array('vopros_answer_form_save_submit_submit'),
    '#validate' => array('vopros_answer_form_submit_validate'),
  );

  $form['form']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Release'),
    '#submit' => array('vopros_answer_form_cancel_submit'),
  );

  return $form;
}

/**
 * Validata handler when saving an answer.
 */
function vopros_answer_form_submit_validate(&$form, &$form_state) {
  $answer = $form_state['values']['answer'];
  field_attach_validate('vopros_answer', $answer, $form, $form_state);
  if (!(trim($form_state['values']['answer_content']))) {
    form_set_error('answer_content', t('Answer field is required'));
  }
}

/**
 * Submit handler for saving answers
 */
function vopros_answer_form_save_submit(&$form, &$form_state) {
  $v = $form_state['values'];
  $answer = $v['answer'];
  $question = $v['question'];
  vopros_question_save($question);
  $answer->question_id = $question->question_id;
  $answer->answer_content = $v['answer_content'];
  $answer->author_name = $GLOBALS['user']->name;
  field_attach_submit('vopros_answer', $answer, $form, $form_state);
  vopros_answer_save($answer);
  drupal_set_message('Answer saved');
  $form_state['redirect'] = 'admin/vopros/answers/' . $answer->answer_id . '/edit';
}

/**
 * Submit handler for cancelling an answer.
 */
function vopros_answer_form_cancel_submit(&$form, &$form_state) {
  // Set the status to new, if the question doesn't have an answer or if it only has a single empty answer.
  // Open up the question for others.
  drupal_set_message(t('The question has been unlocked for others to answer.'), 'warning');
  $question = $form_state['values']['question'];
  $answers = vopros_answer_load_for_question($question->question_id);
  $question->question_status = 'active';
  if (count($answers) == 0) {
    $question->question_status = 'new';
  }
  if (count($answers) != 0) {
    $answer = array_shift($answers);
    if (empty($answer->answer_content)) {
      $question->question_status = 'new';
    }
  }
  $question->uid = 0;
  
  vopros_question_save($question);
  // Redirect to question overview page.
  $form_state['redirect'] = 'admin/vopros/questions/';
}

/**
 * Submit handler for save an answer and release the question.
 */
function vopros_answer_form_save_release_submit(&$form, &$form_state) {
  $v = $form_state['values'];
  $question = $v['question'];
  $question->uid = 0;
  $question->question_status = 'active';
  $question->question_status_reason = 'released';
  $answer = $v['answer'];
  vopros_question_save($question);
  $answer->question_id = $question->question_id;
  $answer->answer_content = $v['answer_content'];
  $answer->author_name = $GLOBALS['user']->name;
  field_attach_submit('vopros_answer', $answer, $form, $form_state);
  vopros_answer_save($answer);
  drupal_set_message('Answer saved and question released for others to answer.');
  $form_state['redirect'] = 'admin/vopros/questions/' . $question->question_id;
}

/**
 * Submit handler to Save and send the answer
 */
function vopros_answer_form_save_submit_submit(&$form, &$form_state) {
  $v = $form_state['values'];
  $question = $form_state['values']['question'];
  vopros_question_save($question);
  $answer = $v['answer'];
  $answer->question_id = $question->question_id;
  $answer->answer_content = $v['answer_content'];
  $answer->author_name = $GLOBALS['user']->name;
  $answer->status = 'complete';
  $form_state['answer'] = $answer;
  vopros_answer_save($answer);
  drupal_set_message('Answer saved and is ready to be submited to the user.');
  $form_state['redirect'] = 'admin/vopros/questions/' . $question->question_id;
}

/**
 * Form to display revisions for an answer.
 */
function vopros_answer_revisions_form($form, &$form_state, $answer) {
  $form['#theme'] = 'diff_node_revisions';

  $form['answer'] = array(
    '#type' => 'value',
    '#value' => $answer,
  );

  $revisions = vopros_answer_revision_list($answer);
  $revision_ids = array();

  foreach ($revisions as $revision) {
    $revision->account = user_load($revision->revision_uid);
    $operations = array();
    $revision_ids[$revision->revision_id] = '';

    if ($revision->revision_id == $answer->revision_id) {
      $form['info'][$revision->revision_id] = array(
        '#markup' => t('!date by !username', array(
          '!date' => l(format_date($revision->revision_timestamp, 'small'), "admin/vopros/answers/$answer->answer_id"),
          '!username' => theme('username', (array) $revision)))
        . (($revision->log != '') ? '<p class="revision-log">'. filter_xss($revision->log) .'</p>' : ''),
      );
    }
    else {
      $form['info'][$revision->revision_id] = array(
        '#markup' => t('!date by !username', array(
          '!date' => l(format_date($revision->revision_timestamp, 'small'), "admin/vopros/answers/$answer->answer_id/revisions/$revision->revision_id/view"),
          '!username' => theme('username', (array) $revision)))
        . (($revision->log != '') ? '<p class="revision-log">'. filter_xss($revision->log) .'</p>' : '')
      );
      $operations[] = array('#markup' => l(t('revert'), "admin/vopros/answers/$answer->answer_id/revisions/$revision->revision_id/revert"));
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
function vopros_answer_revisions_form_submit($form, &$form_state) {
  // the ids are ordered so the old revision is always on the left
  $old_revision_id = min($form_state['values']['old'], $form_state['values']['new']);
  $new_revision_id = max($form_state['values']['old'], $form_state['values']['new']);
  $form_state['redirect'] =  'admin/vopros/answers/'. $form_state['values']['answer']->answer_id .'/revisions/view/'. $old_revision_id .'/'. $new_revision_id;
}

/**
 * Show the diff for two answers.
 */
function vopros_answer_diffs_show($answer, $old_revision_id, $new_revision_id) {
  module_load_include('inc', 'diff', 'diff.pages');
  $old_answer = vopros_answer_load($answer->answer_id, $old_revision_id);
  $old_answer->account = user_load($old_answer->revision_uid);
  $new_answer = vopros_answer_load($answer->answer_id, $new_revision_id);
  $new_answer->account = user_load($new_answer->revision_uid);

  // Generate table header (date, username, logmessage).
  $old_header = t('!date by !username', array(
    '!date' => l(format_date($old_answer->revision_timestamp), "admin/vopros/answers/$answer->answer_id/revisions/$old_answer->revision_id/view"),
    '!username' => theme('username', (array) $old_answer),
  ));
  $new_header = t('!date by !username', array(
    '!date' => l(format_date($new_answer->revision_timestamp), "admin/vopros/answers/$answer->answer_id/revisions/$new_answer->revision_id/view"),
    '!username' => theme('username', (array) $new_answer),
  ));

  $old_log = $old_answer->log != '' ? '<p class="revision-log">'. filter_xss($old_answer->log) .'</p>' : '';
  $new_log = $new_answer->log != '' ? '<p class="revision-log">'. filter_xss($new_answer->log) .'</p>' : '';

  // Get the next and previous revisions.
  $revisions = vopros_answer_revision_list($answer);
  ksort($revisions);
  $prev_revision = $next_revision_id = 0;
  $get_next_revision = FALSE;
  foreach ($revisions as $revision_id => $value) {
    if ($get_next_revision == TRUE) {
      $get_next_revision = FALSE;
      $next_revision_id = $revision_id;
    }
    if ($revision_id == $new_answer->revision_id) {
      $get_next_revision = TRUE;
    }
    if ($revision_id == $old_answer->revision_id) {
      $prev_revision_id = $prev_revision;
    }
    $prev_revision = $revision_id;
  }

  if ($next_revision_id) {
    $next_link = l(t('next diff >'), 'admin/vopros/answers/'. $answer->answer_id .'/revisions/view/'. $new_answer->revision_id .'/'. $next_revision_id);
  }
  else {
    $next_link = '';
  }
  if ($prev_revision_id) {
    $prev_link = l(t('< previous diff'), 'admin/vopros/answers/'. $answer->answer_id .'/revisions/view/'. $prev_revision_id .'/'. $old_answer->revision_id);
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
  $rows = array_merge($rows, _vopros_answer_diff_rows($old_answer, $new_answer));
  $output = theme('diff_table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('diff')), 'cols' => $cols));

  if ($answer->revision_id == $new_answer->revision_id) {
    $output .= '<div class="diff-section-title">'. t('Current revision:') .'</div>';
  }
  else {
    $output .= '<div class="diff-section-title">'. t('Revision of !new_date:', array('!new_date' => format_date($new_answer->revision_timestamp))) .'</div>';
  }
  return $output;
}

/**
 * Creates an array of rows which represent a diff between $old_answer and $new_answer.
 * The rows can be used via theme('diff_table') to be displayed.
 *
 * @param $old_answer
 *   Node for comparison which will be displayed on the left side.
 * @param $new_answer
 *   Node for comparison which will be displayed on the right side.
 */
function _vopros_answer_diff_rows($old_answer, $new_answer) {
  drupal_add_css(drupal_get_path('module', 'diff') .'/diff.css', 'module', 'all', FALSE);

  $rows = array();
  $any_visible_change = FALSE;

  $answer_diffs = array();
  $info = entity_get_property_info('vopros_answer');
  $p = $info['properties'];

  $single_line = array(
    'status',
  );

  foreach ($single_line as $key) {
    $answer_diffs[$key] = array(
      '#name' => t(str_replace('_', ' ', $p[$key]['label'])),
      '#old' => array(isset($select[$key]) ? $select[$key][$old_answer->{$key}] : $old_answer->{$key}),
      '#new' => array(isset($select[$key]) ? $select[$key][$new_answer->{$key}] : $new_answer->{$key}),
      '#format' => array(
        'show_header' => FALSE,
      ),
    );
  }

  $multi_line = array(
    'answer_content',
  );

  foreach ($multi_line as $key) {
    $answer_diffs[$key] = array(
      '#name' => t(str_replace('_', ' ', $p[$key]['label'])),
      '#old' => explode("\n", $old_answer->{$key}),
      '#new' => explode("\n", $new_answer->{$key}),
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
  $answer_diffs['#sorted'] = TRUE;

  // Recurse through all child elements.
  $count = 0;
  foreach (element_children($answer_diffs) as $key) {
    // Assign a decimal placeholder weight to preserve original array order.
    if (!isset($answer_diffs[$key]['#weight'])) {
      $answer_diffs[$key]['#weight'] = $count/1000;
    }
    else {
      // If one of the child elements has a weight then we will need to sort
      // later.
      unset($answer_diffs['#sorted']);
    }
    $count++;
  }

  // One of the children has a #weight.
  if (!isset($answer_diffs['#sorted'])) {
    uasort($answer_diffs, "element_sort");
  }

  // Render diffs for each.
  foreach ($answer_diffs as $answer_diff) {
    $show_header = isset($answer_diff['#format']['show_header']) ? $answer_diff['#format']['show_header'] : FALSE;
    if ($answer_diff_rows = diff_get_rows($answer_diff['#old'], $answer_diff['#new'], $show_header)) {
      $rows[] = array(array(
        'data' => t('Changes to %name', array('%name' => $answer_diff['#name'])),
        'class' => 'diff-section-title',
        'colspan' => 4
      ));
      $rows = array_merge($rows, $answer_diff_rows);
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
 * Menu callback: Revert a answer to different revision.
 */
function vopros_answer_revision_revert($answer, $revision) {
  if ($answer->revision_id != $revision->revision_id && $answer->answer_id == $revision->answer_id) {
    drupal_write_record('vopros_answer', $revision, 'answer_id');
  }
  return drupal_goto('admin/vopros/answers/' . $answer->answer_id . '/revisions');
}
