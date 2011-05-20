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

  $form['contact'] = array(
    '#type' => 'fieldset',
    '#title' => t('Contact user e-mail macros'),
  );

  foreach (vopros_question_get_reasons('contact') as $key => $value) {
    $key = str_replace(' ', '_', $key);
    $form['contact']['vopros_email_macro_' . $key] = array(
      '#type' => 'textarea',
      '#title' => $value,
      '#description' => t('Macro used when contacting a user.'),
      '#default_value' => variable_get('vopros_email_macro_' . $key, ''),
    );
  }

  $form['contact']['tokens'] = array(
    '#markup' => theme('token_tree', array(
      'token_types' => array('vopros_question'),
      'global_types' => FALSE,
    )),
  );

  $form['macros'] = array(
    '#type' => 'fieldset',
    '#title' => t('E-mail macros'),
    '#description' => t('Create macros inserted when sending an email.'),
  );

  $form['macros']['vopros_email_answered_question_macro'] = array(
    '#type' => 'textarea',
    '#title' => t('Answered question'),
    '#description' => t('Macro used when answering a question.'),
    '#default_value' => variable_get('vopros_email_answered_question_macro', ''),
  );

  $form['macros']['tokens'] = array(
    '#markup' => theme('token_tree', array(
      'token_types' => array('vopros_answer', 'vopros_question'),
      'global_types' => FALSE,
    )),
  );

  return system_settings_form($form);
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
    '#title' => t('Content'),
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
    '#default_value' => token_replace(variable_get('vopros_email_answered_question_macro', ''), array(
      'vopros_answer' => $answer,
      'vopros_question' => vopros_question_load($answer->question_id),
    )),
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

/**
 * Form for answering a question.
 */
function vopros_email_question_contact_form($form, &$form_state, $question) {
  $form['send_mail'] = array(
    '#type' => 'submit',
    '#value' => t('Send mail'),
  );

  $form['question'] = array(
    '#value' => $question,
    '#type' => 'value',
  );

  $form['mail'] = array(
    '#title' => t('To'),
    '#type' => 'textfield',
    '#default_value' => $question->user_email,
    '#required' => TRUE,
  );

  $form['reason'] = array(
    '#type' => 'select',
    '#title' => t('Answer type'),
    '#options' => vopros_question_get_reasons(),
    '#required' => TRUE,
    '#ajax' => array(
      'callback' => 'vopros_email_question_contact_form_macro',
    ),
  );

  $form['subject'] = array(
    '#title' => t('Subject'),
    '#type' => 'textfield',
    '#required' => TRUE,
  );

  $form['body'] = array(
    '#title' => t('Mail body'),
    '#type' => 'textarea',
    '#required' => TRUE,
  );

  return $form;
}

function vopros_email_question_contact_form_macro($form, &$form_state) {
  $key = str_replace(' ', '_', $form_state['values']['reason']);

  $text = variable_get('vopros_email_macro_' . $key, '');

  $processed_text = token_replace($text, array('vopros_question' => $form_state['values']['question']));
  $commands = array();
  $commands[] = ajax_command_invoke('#edit-body', 'val', array($processed_text));
  return array('#type' => 'ajax', '#commands' => $commands);
}
