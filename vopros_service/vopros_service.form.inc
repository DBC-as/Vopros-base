<?php

/**
 * @file
 * Message handling form.
 */

/**
 * Form builder for sending a message to a service.
 */
function vopros_service_message_form($form, &$form_state, $forward) {
  form_load_include($form_state, 'vopros_service', 'inc', 'vopros_service.form');

  $form_state['forward'] = $forward;

  $form['message'] = array(
    '#title' => t('New message'),
    '#type' => 'textarea',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => ('Send message'),
  );

  return $form;
}

/**
 * Validation handler for message sending form.
 */
function vopros_service_message_form_validate($form, &$form_state) {
  $forward = $form_state['forward'];

  $form_state['question'] = vopros_question_load_by_uuid($forward->uuid);
  if (!$form_state['question']) {
    form_error($form, t('Could not load question.'));
  }

  $form_state['service'] = vopros_service_machine_name_load($forward->machine_name);
  if (!$form_state['service']) {
    form_error($form, t('Could not load service.'));
  }
}

/**
 * Submit handler for sending message form.
 */
function vopros_service_message_form_submit($form, &$form_state) {
  global $user;

  global $user;
  $name = vopros_user_name($user);

  $data = array(
    'from' => $name,
    'message' => $form_state['values']['message'],
  );

  if (_vopros_service_send_message($form_state['service'], $form_state['question'], $data)) {
    $question_message = entity_create('vopros_service_message', array(
        'question_id' => $form_state['question']->question_id,
        'service_machine_name' => $form_state['service']->machine_name,
        'message_type' => 'outgoing',
        'message_content' => check_plain($form_state['values']['message']),
        'message_from' => $name,
        'message_uid' => $user->uid,
      ));
    entity_save('vopros_service_message', $question_message);
    drupal_set_message(t('Message sent.'), 'status');
  }
  else {
    // Assignment on purpose.
    if ($error = _vopros_service_error()) {
      $message = t('Could not send message to service, it said: @message', array('@message' => $error));
    }
    else {
      $message = t('Could not send message to service.');
    }
    form_error($form, $message);
  }
}

/**
 * Form builder for sending a message back to the asking service..
 */
function vopros_service_message_back_form($form, &$form_state, $question) {
  form_load_include($form_state, 'vopros_service', 'inc', 'vopros_service.form');

  $form_state['question'] = $question;

  $form['#attached'] = array(
    'css' => array(drupal_get_path('module', 'vopros_service') . '/css/vopros_service.admin.css'),
  );

  $form['action'] = array(
    '#prefix' => '<div class="action">',
    '#suffix' => '</div>',
  );

  $form['action']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send message'),
  );

  $form['form'] = array(
    '#prefix' => '<div class="form">',
    '#suffix' => '</div>',
  );

  $form['form']['message'] = array(
    '#title' => t('Message'),
    '#type' => 'textarea',
    '#required' => TRUE,
  );

  $form['form']['submit'] = $form['action']['submit'];
  $form['form']['submit']['#attributes'] = array('class' => array('primary-action'));

  $form['form']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/vopros/questions/' . $question->question_id),
  );

  return $form;
}

/**
 * Validation handler for back message form.
 */
function vopros_service_message_back_form_validate($form, &$form_state) {
  $forwards = vopros_service_forward_load_by_uuid($form_state['question']->uuid);
  if (empty($forwards)) {
    form_error($form, t('Could not load forward.'));
  }
  else {
    $forward = NULL;
    foreach ($forwards as $f) {
      if ($f->direction == 'incoming') {
        $forward = $f;
        break;
      }
    }
    if (!$forward) {
      form_error($form, t('Could not find any incoming forwards on question.'));
    }
    else {
      $form_state['service'] = vopros_service_machine_name_load($forward->machine_name);
      if (!$form_state['service']) {
        form_error($form, t('Could not load service.'));
      }
    }
  }
}

/**
 * Submit handler for back message form.
 */
function vopros_service_message_back_form_submit($form, &$form_state) {
  global $user;
  $name = vopros_user_name($user);
  $data = array(
    'from' => $name,
    'message' => $form_state['values']['message'],
  );

  if (_vopros_service_send_answer($form_state['service'], $form_state['question'], $data)) {
    $question_message = entity_create('vopros_service_message', array(
        'question_id' => $form_state['question']->question_id,
        'service_machine_name' => $form_state['service']->machine_name,
        'message_type' => 'outgoing',
        'message_content' => check_plain($form_state['values']['message']),
        'message_from' => $name,
        'message_uid' => $user->uid,
      ));
    entity_save('vopros_service_message', $question_message);
    drupal_set_message(t('Message sent.'), 'status');
    $form_state['redirect'] = 'admin/vopros/questions';
  }
  else {
    // Assignment on purpose.
    if ($error = _vopros_service_error()) {
      $message = t('Could not send message to service, it said: @message', array('@message' => $error));
    }
    else {
      $message = t('Could not send message to service.');
    }
    form_error($form, $message);

  }
}
