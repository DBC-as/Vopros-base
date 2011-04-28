<?php

/**
 * @ file
 * Admin forms and callback functions.
 */

/**
 * Answer settings form
 */
function vopros_email_settings_form($form, &$form_state) {
  if (!isset($form_state['new_snippets_count'])) {
    $form_state['new_snippets_count'] = 1;
  }

  $snippets = variable_get('vopros_email_snippets', array());

  $form['snippets'] = array(
    '#type' => 'fieldset',
    '#title' => t('E-mail snippets'),
    '#description' => t('Create snippets used for sending emails.'),
    'saved_snippets' => array('#tree' => TRUE),
    'new_snippets' => array('#tree' => TRUE),
  );

  foreach ($snippets as $key => $snippet) {
    $form['snippets']['saved_snippets'][$key] = array(
      '#type' => 'fieldset',
      '#title' => $snippet['name'],
      'name' => array(
        '#type' => 'textfield',
        '#title' => t('Name'),
        '#description' => t('Give your snippet a name.'),
        '#default_value' => $snippet['name'],
      ),
      'snippet' => array(
        '#type' => 'textarea',
        '#title' => t('Snippet'),
        '#description' => t('The text to be included in the email.'),
        '#default_value' => $snippet['snippet'],
      ),
      'delete' => array(
        '#type' => 'checkbox',
        '#title' => t('Delete'),
        '#default_value' => -1,
      ),
    );
  }

  foreach (range(1, $form_state['new_snippets_count']) as $value) {
    $form['snippets']['new_snippets'][] = array(
      '#type' => 'fieldset',
      '#title' => t('New text snippet'),
      'name' => array(
        '#type' => 'textfield',
        '#title' => t('Name'),
        '#description' => t('Give your snippet a name.'),
      ),
      'snippet' => array(
        '#type' => 'textarea',
        '#title' => t('Snippet'),
        '#description' => t('The text to be included in the email.'),
      ),
    );
  }

  $form['snippets']['new_snippets'][0]['#prefix'] = '<div id="new_snippets">';
  $form['snippets']['new_snippets'][count($form['snippets']['new_snippets']) - 1]['#suffix'] = '</div>';

  $form['snippets']['add'] = array(
    '#type' => 'submit',
    '#value' => t('Add another'),
    '#ajax' => array(
      'callback' => 'vopros_email_snippet_js',
      'wrapper' => 'new_snippets',
    ),
    '#submit' => array('vopros_email_snippet_submit'),
  );

  $form['save_settings'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
    '#submit' => array('vopros_email_settings_form_submit'),
  );

  return $form;
}

/**
 * Submit handler for adding new snippets to settings form.
 */
function vopros_email_snippet_submit($form, &$form_state) {
  // Add one to the snippet count.
  $form_state['new_snippets_count'] += 1;
  // Rebuild the form, to the let form function change the form.
  $form_state['rebuild'] = TRUE;
}

/**
 * AJAX callback, add new snippets to settings form.
 */
function vopros_email_snippet_js($form, $form_state) {
  // Only the new snippets are changed.
  return $form['snippets']['new_snippets'];
}

/**
 * Submit handler for vopros_email_settings_form().
 */
function vopros_email_settings_form_submit(&$form, &$form_state) {
  $snippets = variable_get('vopros_email_snippets', array());

  foreach ($form_state['values']['saved_snippets'] as $key => $snippet) {
    if ($snippet['delete'] || (empty($snippet['name']) || empty($snippet['snippet']))) {
      unset($snippets[$key]);
    }
    else {
      $snippets[$key]['name'] = $snippet['name'];
      $snippets[$key]['snippet'] = $snippet['snippet'];
    }
  }

  foreach ($form_state['values']['new_snippets'] as $snippet) {
    if ($snippet['name'] && $snippet['snippet']) {
      $snippets[] = array(
        'name' => $snippet['name'],
        'snippet' => $snippet['snippet'],
      );
    }
  }
  variable_set('vopros_email_snippets', $snippets);
}

/**
 * Answer form
 */
function vopros_email_form($form, &$form_state, $answer, $email) {
  if (empty($answer) && isset($email->answer_id)) {
    $answer = vopros_question_load($email->answer_id);
  }
  $form['answer'] = array(
    '#type' => 'value',
    '#value' => $answer,
  );

  $form['email'] = array(
    '#type' => 'value',
    '#value' => $email,
  );

  $form['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t('The subject for the email.'),
    '#default_value' => isset($email->subject) ? $email->subject : '',
    '#required' => TRUE,
  );

  $form['content_field'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content')
  );

  $snippets = variable_get('vopros_email_snippets', array());
  $options = array();

  foreach ($snippets as $key => $snippet) {
    $options[$key] = $snippet['name'];
  }

  if ($options) {
    $form['content_field']['snippet']['snippet_option'] = array(
      '#type' => 'select',
      '#title' => t('Select snippet'),
      '#options' => array('' => t('Select')) + $options,
    );

    $form['content_field']['snippet']['snippet_destination'] = array(
      '#type' => 'select',
      '#title' => t('Snippet destination'),
      '#options' => array(
        'beginning' => t('Beginning'),
        'end' => t('End'),
      ),
    );

    $form['content_field']['snippet']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Insert snippet'),
      '#ajax' => array(
        'callback' => 'vopros_email_form_insert_snippet_js',
      ),
    );
  }

  $form['content_field']['content'] = array(
    '#type' => 'textarea',
    '#title' => t('Mail body'),
    '#description' => t('The main content of the email.'),
    '#default_value' => isset($email->content) ? $email->content : (isset($answer->answer_content) ? $answer->answer_content : ''),
    '#required' => TRUE,
  );

  $form['send'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
    '#submit' => array('vopros_email_form_submit'),
  );

  return $form;
}

function vopros_email_form_insert_snippet_js($form, &$form_state) {
  $snippets = variable_get('vopros_email_snippets', array());
  $key = $form_state['values']['snippet_option'];
  $commands = array();
  if (isset($snippets[$key]) && $snippets[$key]['snippet']) {
    $snippet = $snippets[$key]['snippet'];
    if ($form_state['values']['snippet_destination'] == 'end') {
      $text = $form_state['values']['content'] . "\n" . $snippet;
    }
    else {
      $text = $snippet . "\n" . $form_state['values']['content'];
    }
    $commands[] = ajax_command_invoke('#edit-content', 'val', array($text));
  }
  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Submit handler for saving questions
 */
function vopros_email_form_submit(&$form, &$form_state) {
  $email = $form_state['values']['email'];
  $email->subject = $form_state['values']['subject'];
  $email->content = $form_state['values']['content'];
  $email->uid = $GLOBALS['user']->uid;
  $email->answer_id = $form_state['values']['answer']->answer_id;
  vopros_email_save($email);
  if ($email->status != 'sent') {
    vopros_email_send($email);
    $email->status = 'sent';
    vopros_email_save($email);
  }
  $form_state['redirect'] = 'admin/vopros/email/' . $email->email_id;
}
