<?php

/**
 * @ file
 * Admin forms and callback functions.
 */

/**
 * Answer settings form
 */
function vopros_email_settings_form($form, &$form_state) {
  $form['info'] = array(
    '#markup' => t('Below you can define default texts used for different situations when sending an email to the user. This could be an email containing the answer, or when the need to contact the user arises, fx to ask for more info. It is possible to use Drupal tokens to create dynamic macros containing question/answer or user data. See below under each category for a list of available tokens and their meaning.'),
    '#prefix' => '<p>',
    '#suffix' => '</p>',
  );

  $form['contact'] = array(
    '#type' => 'fieldset',
    '#title' => t('Contact user email macros'),
  );

  foreach (vopros_question_get_reasons('contact') as $key => $value) {
    $key = str_replace(' ', '_', $key);
    $form['contact'][$key] = array(
      '#type' => 'fieldset',
      '#title' => $value,
      '#description' => t('Setup macros used for sending email.'),
    );

    $form['contact'][$key]['vopros_email_subject_macro_' . $key] = array(
      '#type' => 'textfield',
      '#title' => t('Subject.'),
      '#default_value' => variable_get('vopros_email_subject_macro_' . $key, ''),
    );

    $form['contact'][$key]['vopros_email_macro_' . $key] = array(
      '#type' => 'textarea',
      '#title' => t('Mail body.'),
      '#default_value' => variable_get('vopros_email_macro_' . $key, ''),
    );
  }

  $form['contact']['tokens'] = array(
    '#markup' => theme('token_tree', array(
      'token_types' => array('vopros_question'),
      'global_types' => FALSE,
    )),
    '#weight' => 2,
  );

  $form['macros'] = array(
    '#type' => 'fieldset',
    '#title' => t('Email macros'),
    '#description' => t('Create macros inserted when sending an email.'),
  );

  $form['macros']['vopros_email_answered_question_subject_macro'] = array(
    '#type' => 'textfield',
    '#title' => t('Answered question subject'),
    '#description' => t('Macro used when answering a question.'),
    '#default_value' => variable_get('vopros_email_answered_question_subject_macro', ''),
  );

  $form['macros']['vopros_email_answered_question_macro'] = array(
    '#type' => 'textarea',
    '#title' => t('Answered question mail body'),
    '#description' => t('Macro used when answering a question.'),
    '#default_value' => variable_get('vopros_email_answered_question_macro', ''),
  );

  $form['macros']['tokens'] = array(
    '#markup' => theme('token_tree', array(
      'token_types' => array('vopros_answer', 'vopros_question', 'vopros_email'),
      'global_types' => FALSE,
    )),
    '#weight' => 2,
  );

  return system_settings_form($form);
}

/**
 * Answer form
 */
function vopros_email_form($form, &$form_state, $email, $answer = NULL) {
  if (empty($answer) && $email->answer_id) {
    $answer = vopros_answer_load($email->answer_id);
  }

  if ($answer) {
    $answer_wrapper = entity_metadata_wrapper('vopros_answer', $answer);
    $email->answer_uid = $answer->uid;
  }

  $form['action'] = array(
    '#prefix' => '<div class="action">',
    '#suffix' => '</div>',
    '#weight' => -101,
  );

  $form['action']['send'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
  );

  $form['answer'] = array(
    '#type' => 'value',
    '#value' => $answer,
  );

  $form['vopros_email'] = array(
    '#type' => 'value',
    '#value' => $email,
  );

  $form['form'] = array(
    '#prefix' => '<div class="form">',
    '#suffix' => '</div>',
    '#weight' => -100,
  );

  $form['form']['email'] = array(
    '#title' => t('To'),
    '#type' => 'textfield',
    '#default_value' => $email->email,
    '#required' => TRUE,
  );

  if (!$email->email && $answer && isset($answer_wrapper)) {
    $form['form']['email']['#default_value'] = $answer_wrapper->question->user_email->value();
  }

  $form['form']['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t('The subject for the email.'),
    '#default_value' => $email->subject,
    '#required' => TRUE,
  );

  if (!$email->subject && $answer && isset($answer_wrapper)) {
    $form['form']['subject']['#default_value'] = token_replace(variable_get('vopros_email_answered_question_subject_macro', ''), array(
      'vopros_answer' => $answer,
      'vopros_question' => $answer_wrapper->question->value(),
    ), array('sanitize' => FALSE));
  }

  $form['form']['email_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Mail body'),
    '#description' => t('The main content of the email.'),
    '#default_value' => $email->email_content,
    '#required' => TRUE,
    '#rows' => 10,
  );

  if (!$email->email_content && $answer && isset($answer_wrapper)) {
    $form['form']['email_content']['#default_value'] = token_replace(variable_get('vopros_email_answered_question_macro', ''), array(
      'vopros_answer' => $answer,
      'vopros_question' => $answer_wrapper->question->value(),
    ), array('sanitize' => FALSE));
  }

  $form['buttons'] = array(
    '#weight' => 100,
  );

  $form['buttons']['send'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
    '#attributes' => array('class' => array('primary-action')),
  );

  if ($answer) {
    $form['buttons']['edit_answer'] = array(
      '#markup' => l(t('Edit answer'), 'admin/vopros/answers/' . $answer->answer_id . '/edit'),
    );
  }

  field_attach_form('vopros_email', $email, $form, $form_state);
  return $form;
}

function vopros_email_form_validate(&$form, &$form_state) {
  $email = $form_state['values']['vopros_email'];
  field_attach_validate('vopros_email', $email, $form, $form_state);
  $form_state['values']['vopros_email'] = $email;
}

/**
 * Submit handler for saving questions
 */
function vopros_email_form_submit(&$form, &$form_state) {
  // Update the email with submitted data.
  $email = $form_state['values']['vopros_email'];
  $email->subject = $form_state['values']['subject'];
  $email->email_content = $form_state['values']['email_content'];
  $email->email = $form_state['values']['email'];
  field_attach_submit('vopros_email', $email, $form, $form_state);
  // Create the needed relations for later.
  $email->uid = $GLOBALS['user']->uid;

  if (!$email->answer_id && isset($form_state['values']['answer']->answer_id)) {
    $email->answer_id = $form_state['values']['answer']->answer_id;
    $email->question_id = $form_state['values']['answer']->question_id;
  }

  vopros_email_save($email);
  // Replace email tokens if any (only possible after the email is created).
  $email->email_content = token_replace($email->email_content, array('vopros_email' => $email), array('sanitize' => FALSE));
  vopros_email_save($email);
  if ($email->status != 'sent') {
    vopros_email_send($email);
    $email->status = 'sent';
    vopros_email_save($email);
  }

  if ($email->question_id) {
    $question = vopros_question_load($email->question_id);
    $question->question_status = 'answered';
    $question->question_status_reason = '';
    $question->save();
  }

  $form_state['redirect'] = 'admin/vopros/questions';
  drupal_set_message(t('The answer has been sent to @receiver and the question !question is marked as answered.', array('@receiver' => $email->email, '!question' => '<em>' . l($question->question_title, 'admin/vopros/questions/' . $question->question_id) . '</em>')));
}

/**
 * Form for answering a question.
 */
function vopros_email_question_contact_form($form, &$form_state, $question) {
  $form['action'] = array(
    '#prefix' => '<div class="action">',
    '#suffix' => '</div>',
  );
  $form['action']['send_mail'] = array(
    '#type' => 'submit',
    '#value' => t('Send mail'),
  );

  $form['question'] = array(
    '#value' => $question,
    '#type' => 'value',
  );

  $form['form'] = array(
    '#prefix' => '<div class="form">',
    '#suffix' => '</div>',
  );

  $form['form']['email'] = array(
    '#title' => t('To'),
    '#type' => 'textfield',
    '#default_value' => $question->user_email,
    '#required' => TRUE,
  );

  $form['form']['reason'] = array(
    '#type' => 'radios',
    '#title' => t('Answer type'),
    '#options' => vopros_question_get_reasons(),
    '#required' => TRUE,
    '#ajax' => array(
      'callback' => 'vopros_email_question_contact_form_macro',
    ),
  );

  $form['form']['subject'] = array(
    '#title' => t('Subject'),
    '#type' => 'textfield',
    '#required' => TRUE,
  );

  $form['form']['email_content'] = array(
    '#title' => t('Email content'),
    '#type' => 'textarea',
    '#required' => TRUE,
  );

  $form['form']['send_mail'] = array(
    '#type' => 'submit',
    '#value' => t('Send mail'),
    '#attributes' => array('class' => array('primary-action')),
  );

  $form['form']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/vopros/questions/' . $question->question_id),
  );

  return $form;
}

/**
 * AJAX callback for displaying macros.
 */
function vopros_email_question_contact_form_macro($form, &$form_state) {
  $key = str_replace(' ', '_', $form_state['values']['reason']);
  $content_key = 'vopros_email_macro_' . $key;
  $content = variable_get($content_key, '');
  drupal_alter('vopros_email_question_contact_form_macro', $content, $form, $content_key);
  $processed_content = token_replace($content, array('vopros_question' => $form_state['values']['question']), array('sanitize' => FALSE));

  $subject_key = 'vopros_email_subject_macro_' . $key;
  $subject = variable_get($subject_key, '');
  drupal_alter('vopros_email_question_contact_form_macro', $subject, $form, $subject_key);
  $processed_subject = token_replace($subject, array('vopros_question' => $form_state['values']['question']), array('sanitize' => FALSE));

  $commands = array();
  $commands[] = ajax_command_invoke('#edit-subject', 'val', array($processed_subject));
  $commands[] = ajax_command_invoke('#edit-email-content', 'val', array($processed_content));
  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Validate handler for vopros_email_question_contact_form().
 */
function vopros_email_question_contact_form_validate(&$form, &$form_state) {
  $mail = $form_state['values']['email'];
  if (!valid_email_address($mail)) {
    form_set_error('email', t('The email address %mail is not valid.', array('%mail' => $mail)));
  }
}

/**
 * Validate handler for vopros_email_question_contact_form().
 */
function vopros_email_question_contact_form_submit(&$form, &$form_state) {
  $v = $form_state['values'];
  $question = $v['question'];
  $email = vopros_email_new(array(
    'question_id' => $question->question_id,
    'uid' => $GLOBALS['user']->uid,
    'email_content' => $v['email_content'],
    'subject' => $v['subject'],
    'email' => $v['email'],
  ));
  vopros_email_save($email);
  if ($email->status != 'sent') {
    vopros_email_send($email);
    $email->status = 'sent';
    vopros_email_save($email);
  }
  $question->question_status = 'closed';
  $question->question_status_reason = $v['reason'];
  $question->save();
  drupal_set_message(t('The e-mail has been sent to @receiver and the question !question is marked as closed without answer (@status_reason).',
    array(
      '@receiver' => $email->email,
      '!question' => '<em>' . l($question->question_title, 'admin/vopros/questions/' . $question->question_id) . '</em>',
      '@status_reason' => $form['form']['reason']['#options'][$v['reason']],
    )
  ));
  $form_state['redirect'] = 'admin/vopros/questions';
}

/**
 * Handle the display of an email.
 */
function vopros_email_page_view($email, $view_mode = 'administrator', $langcode = NULL) {
  $build = array();

  // Populate $email->content with a render() array.
  vopros_email_build_content($email, $view_mode, $langcode);

  $build = $email->content + $build;
  unset($email->content);

  $build += array(
    '#view_mode' => $view_mode,
    '#theme' => 'vopros_email',
    '#email' => $email,
    '#language' => $langcode,
  );

  $type = 'vopros_email';
  drupal_alter(array('vopros_email_view', 'entity_view'), $build, $type);

  return $build;
}

/**
 * Confirm form for deleting emails.
 */
function vopros_email_delete_confirm_form($form, &$form_state, $email) {
  $form = array();
  $form['email'] = array(
    '#type' => 'value',
    '#value' => $email,
  );
  $question = t('Are you sure you want to delete the email?');
  $description = t('This action cannot be undone.');
  $path = "admin/vopros/emails";
  $yes = t('Delete');
  $no = t('Cancel');
  return confirm_form($form, $question, $path, "<p>$question</p><p>$description</p>", $yes, $no, 'confirm');
}

/**
 * Submit handler for vopros_email_delete_confirm_form().
 */
function vopros_email_delete_confirm_form_submit(&$form, &$form_state) {
  $email = $form_state['values']['email'];
  vopros_email_delete($email->email_id);
  $form_state['redirect'] = 'admin/vopros/emails';
}

/**
 * A form for creating a new question from an email.
 */
function vopros_email_convert_to_question_form($form, &$form_state, $email) {
  // Ensure this include file is loaded when the form is rebuilt from the cache.
  $form_state['build_info']['files']['form'] = drupal_get_path('module', 'vopros_question') . '/includes/vopros_question.admin.inc';
  module_load_include('inc', 'vopros_question', 'includes/vopros_question.admin');
  $question = vopros_question_new(array(
    'question_title' => $email->subject,
    'question_content' => $email->email_content,
    'user_email' => $email->email,
  ));

  $form = vopros_question_question_form($form, $form_state, $question);

  $form['email'] = array(
    '#type' => 'value',
    '#value' => $email,
  );

  $form['#validate'] = array('vopros_question_question_form_validate', 'vopros_email_convert_to_question_form_validate');
  $form['#submit'] = array('vopros_question_question_form_submit', 'vopros_email_convert_to_question_form_submit');

  return $form;
}

/**
 * Validate handler for vopros_email_convert_to_question_form().
 */
function vopros_email_convert_to_question_form_validate(&$form, &$form_state) {
  if ($form_state['values']['email']->question_id) {
    form_set_error('', t('Email is already attached to a question, cannot be converted to a question.'));
  }
}

/**
 * Submit handler for vopros_email_convert_to_question_form().
 */
function vopros_email_convert_to_question_form_submit(&$form, &$form_state) {
  $question = $form_state['question'];
  $question->question_status_reason = 'created from email';
  $question->save();
  $email = $form_state['values']['email'];
  $email->question_id = $question->question_id;
  vopros_email_save($email);
  $form_state['redirect'] = 'admin/vopros/questions/' . $question->question_id;
}

/**
 * Form for forwarding a mail to another user.
 */
function vopros_email_forward_form($form, &$form_state, $email) {
  $options = vopros_user_get_librarians();
  asort($options);

  $form_state['email'] = $email;

  $form['uid'] = array(
    '#type' => 'select',
    '#title' => t('User'),
    '#description' => t('Select the user you want to forward the mail to.'),
    '#required' => TRUE,
    '#options' => $options,
  );

  $form['message'] = array(
    '#type' => 'textarea',
    '#title' => t('Message'),
    '#description' => t('An extra message to append to the mail.'),
  );

  $form['forward'] = array(
    '#type' => 'submit',
    '#value' => t('forward'),
  );

  return $form;
}

/**
 * Submit handler for forwarding.
 */
function vopros_email_forward_form_submit($form, &$form_state) {
  $email = $form_state['email'];
  $account = user_load($form_state['values']['uid']);

  $form_state['redirect'] = 'admin/vopros/emails/' . $email->email_id;

  if ($account) {
    $mail = array(
      'email' => $email,
      'message' => $form_state['values']['message'],
      'user' => vopros_user_name(),
    );
    drupal_mail('vopros_email', 'forward_email', $account->mail, NULL, $mail);
    drupal_set_message(t("Email forwarded."));
  }
}

/**
 * Form for transferring an email from one question to another
 */
function vopros_email_transfer_form($form, &$form_state, $email) {
  // Don't allow transfering emails that doesn't belong to a question.
  if (!$email->question_id) {
    $form['message'] = array(
      '#markup' => t('This email cannot be transferred'),
    );
    return $form;
  }

  // Ensure this include file is loaded when the form is rebuilt from the cache.
  $form_state['build_info']['files']['form'] = drupal_get_path('module', 'vopros_question') . '/includes/vopros_question.admin.inc';
  module_load_include('inc', 'vopros_question', 'includes/vopros_question.admin');
  $question = vopros_question_new(array(
    'question_title' => $email->subject,
    'question_content' => $email->email_content,
    'user_email' => $email->email,
  ));

  $form = vopros_question_question_form($form, $form_state, $question);

  $form['email'] = array(
    '#type' => 'value',
    '#value' => $email,
  );

  $form['#validate'] = array('vopros_question_question_form_validate');
  $form['#submit'] = array('vopros_question_question_form_submit', 'vopros_email_transfer_form_submit');

  return $form;
}

/**
 * Submit handler for vopros_email_transfer_form().
 */
function vopros_email_transfer_form_submit(&$form, &$form_state) {
  $question = $form_state['question'];
  $email = $form_state['values']['email'];
  $record = array(
    'email_id' => $email->email_id,
    'uid' => $GLOBALS['user']->uid,
    'origin_question_id' => $email->question_id,
    'target_question_id' => $question->question_id,
    'transfer_time' => $question->created,
  );
  drupal_write_record('vopros_email_transfers', $record);
  $question->question_status_reason = 'created from email';
  $question->save();
  $email->question_id = $question->question_id;
  vopros_email_save($email);
}
