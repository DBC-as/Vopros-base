<?php

/**
 * @file
 * Vopros Service page callbacks.
 */

/**
 * Forward question form builder.
 */
function vopros_service_forward_form($form, &$form_state, $question) {
  $form_state['question'] = $question;

  $form['#attached'] = array(
    'css' => array(drupal_get_path('module', 'vopros_service') . '/css/vopros_service.admin.css'),
  );

  $form['sidebar'] = array(
    '#prefix' => '<div class="sidebar">',
    '#suffix' => '</div>',
  );

  $form['form'] = array(
    '#prefix' => '<div class="form">',
    '#suffix' => '</div>',
  );

  $form['form']['question_display'] = array(
    '#type' => 'fieldset',
    '#title' => t('Question'),
  );

  $form['form']['question_display']['question_title'] = array(
    '#theme' => 'vopros_question_title',
    '#question' => $question,
    '#view_mode' => 'full',
  );

  $form['form']['question_display']['question_text'] = array(
    '#theme' => 'vopros_question_content',
    '#question' => $question,
    '#view_mode' => 'full',
  );

  $options = array(
    'help' => t('Ask for help'),
  );
  if ($question->user_answer_preference == 'sms') {
    $options['turn_over_sms'] = t('Turn over the question');
  }
  else {
    $options['turn_over'] = t('Turn over the question');
  }
  // @todo Really, we should filter out types without any services.
  $form['form']['send_type'] = array(
    '#type' => 'radios',
    '#title' => t('Way of sending'),
    '#options' => $options,
    '#required' => TRUE,
    '#ajax' => array(
      'callback' => 'vopros_service_forward_form_ajax',
      'wrapper' => 'service-options',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  // Find service definitions.
  if ($question->user_answer_preference == 'sms') {
    $where = 'v.allow_outgoing_help = 1 OR v.allow_outgoing_turn_over_sms = 1';
  }
  else {
    $where = 'v.allow_outgoing_help = 1 OR v.allow_outgoing_turn_over = 1';
  }
  $query = db_select('vopros_service', 'v')
    ->fields('v')
    ->where($where)
    ->orderBy('label');

  $form_state['services'] = $query->execute()->fetchAllAssoc('machine_name');

  /*
   * Show the selector initially with all possible options, so core validation
   * can see them on submit.
   */
  $options = _vopros_service_forward_form_options($form_state['services'], 'allow_outgoing_help');
  if ($question->user_answer_preference == 'sms') {
    $options += _vopros_service_forward_form_options($form_state['services'], 'allow_outgoing_turn_over_sms');
  }
  else {
    $options += _vopros_service_forward_form_options($form_state['services'], 'allow_outgoing_turn_over');
  }
  $form['form']['service'] = array(
    '#type' => 'select',
    '#title' => t('Service'),
    '#options' => $options,
    '#required' => TRUE,
    '#prefix' => '<div id="service-options">',
    '#suffix' => '</div>',
  );

  $form['form']['message'] = array(
    '#type' => 'textarea',
    '#title' => t('Message to service'),
  );

  $form['form']['actions'] = array('#type' => 'actions');

  $form['form']['actions']['forward'] = array(
    '#type' => 'submit',
    '#value' => t('Forward question'),
    '#validate' => array('vopros_service_forward_form_forward_validate'),
    '#submit' => array(
      'vopros_service_forward_form_forward_submit',
      'vopros_service_forward_form_submit',
    ),
  );

  $form['sidebar']['forward'] = $form['form']['actions']['forward'];

  $form['form']['actions']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => array(
      'vopros_service_forward_form_submit',
    ),
    '#limit_validation_errors' => array(),
  );

  return $form;
}

/**
 * Create a options array of services of a specific type.
 */
function _vopros_service_forward_form_options($services, $type) {
  $options = array();
  foreach ($services as $service) {
    if (!empty($service->{$type}) && $service->{$type}) {
      $options[$service->machine_name] = $service->label;
    }
  }

  return $options;
}

/**
 * Ajax callback for vopros_service_question_service_form().
 *
 * Repopulates the service dropdown when the type changes.
 */
function vopros_service_forward_form_ajax($form, &$form_state) {
  $type = $form_state['triggering_element']['#value'];

  $form['form']['service']['#options'] = _vopros_service_forward_form_options($form_state['services'], 'allow_outgoing_' . $type);
  if (empty($form['form']['service']['#options'])) {
    return array(
      '#markup' => t('No services configured for this way of sending.'),
      '#prefix' => '<div id="service-options">',
      '#suffix' => '</div>',
    );
  }

  return $form['form']['service'];
}

/**
 * Validate handler for the forward button.
 *
 * Validates the form and attempts to forward the question.
 */
function vopros_service_forward_form_forward_validate($form, &$form_state) {
  // If the service is empty, core will set the error, but we need to bail out
  // ourselves.
  if (form_get_errors()) {
    return;
  }
  $question = $form_state['question'];
  $service_name = $form_state['values']['service'];
  $form_state['selected_service'] = $form_state['services'][$service_name];
  $message = $form_state['values']['message'];
  if (_vopros_service_forward_question($form_state['selected_service'], $form_state['values']['send_type'], $question, $message)) {
    // Note that the question was forwarded.
    db_insert('vopros_service_question')
      ->fields(array(
          'machine_name' => $form_state['selected_service']->machine_name,
          'direction' => 'outgoing',
          'type' => $form_state['values']['send_type'],
          'uuid' => $question->uuid,
      ))
    ->execute();

    // Close question if it was handed over.
    if ($form_state['selected_service']->allow_outgoing_turn_over) {
      $question->question_status = 'closed';
      $question->question_status_reason = 'handed over to external service';
      entity_save('vopros_question', $question);
      $form_state['redirect'] = 'admin/vopros/questions';
    }
  }
  else {
    // Assignment on purpose.
    if ($error = _vopros_service_error()) {
      $message = t('Could not forward question to service, it said: @message', array('@message' => $error));
    }
    else {
      $message = t('Could not forward question to service.');
    }
    form_error($form, $message);
  }
}

/**
 * Submit handler for the forward button.
 *
 * Just prints a message as the validate handler has already forwarded the
 * question and the shared submit handler handles redirection.
 */
function vopros_service_forward_form_forward_submit($form, &$form_state) {
  $question = $form_state['question'];
  if ($form_state['values']['send_type'] == 'turn_over') {
    $question->question_status = 'closed';
    $question->question_status_reason = 'handed over to external service';
    drupal_set_message(t('The question "@title" has been handed over to an external service', array('@title' => $form_state['question']->question_title)), 'notice');
    $form_state['redirect'] = 'admin/vopros/questions';
  }
}

/**
 * Common submithandler.
 *
 * Redirects back to the question, if no other validate/submit handler has set a
 * redirect.
 */
function vopros_service_forward_form_submit($form, &$form_state) {
  if (empty($form_state['redirect'])) {
    $question = $form_state['question'];
    $url = entity_uri('vopros_question', $question);
    $form_state['redirect'] = array($url['path'] , $url['options']);
  }
}
