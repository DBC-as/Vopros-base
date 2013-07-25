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

  $form['question_display'] = array(
    '#type' => 'fieldset',
    '#title' => t('Question'),
  );

  $form['question_display']['question_text'] = array(
    '#theme' => 'vopros_question_content',
    '#question' => $question,
    '#view_mode' => 'full',
  );

  // Find service definitions.
  $services = array();
  $query = db_select('vopros_service', 'v')
    ->fields('v', array(
        'machine_name',
        'label',
        'allow_outgoing_help',
        'allow_outgoing_turn_over',
      ))
    ->where('v.allow_outgoing_help = 1 OR v.allow_outgoing_turn_over = 1')
    ->orderBy('label');

  foreach ($query->execute() as $service) {
    $service_type = $service->allow_outgoing_help ?
      t('Help', array(), array('context' => 'a vopros service')) :
      t('Turn over', array(), array('context' => 'a vopros service'));
    $services[$service->machine_name] = t('@service_label (@service_type)', array('@service_label' => $service->label, '@service_type' => $service_type));
  }

  $form['service'] = array(
    '#type' => 'select',
    '#title' => t('Service'),
    '#options' => $services,
    '#required' => TRUE,
  );

  $form['message'] = array(
    '#type' => 'textarea',
    '#title' => t('Message to service'),
  );

  $form['buttons']['forward'] = array(
    '#type' => 'submit',
    '#value' => t('Forward question'),
    '#validate' => array('vopros_service_forward_form_forward_validate'),
    '#submit' => array(
      'vopros_service_forward_form_forward_submit',
      'vopros_service_forward_form_submit',
    ),
  );

  $form['buttons']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => array(
      'vopros_service_forward_form_submit',
    ),
    '#limit_validation_errors' => array(),
  );

  return $form;
}

function vopros_service_forward_form_forward_validate($form, &$form_state) {
  $question = $form_state['question'];
  $service = vopros_service_machine_name_load($form_state['values']['service']);
  $message = $form_state['values']['message'];
  if (_vopros_service_forward_question($service, $question, $message)) {

  }
  else {
    form_error($form, t('Could not forward question to service.'));
  }
}

function vopros_service_forward_form_forward_submit($form, &$form_state) {
  dpm('forward_submit');
}

/**
 * Common submithandler.
 */
function vopros_service_forward_form_submit($form, &$form_state) {
  $question = $form_state['question'];
  $url = entity_uri('vopros_question', $question);
  $form_state['redirect'] = array($url['path'] , $url['options']);
}
