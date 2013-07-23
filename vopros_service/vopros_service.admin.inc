<?php

/**
 * Admin forms and callbacks for vopros_service module.
 */

/**
 * UI controller class for the admin interface.
 */
class VoprosServiceUIController extends VoprosUIController {
  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Display a list of vopros services.';
    return $items;
  }
}

/**
 * Generates the profile type editing form.
 */
function vopros_service_form($form, &$form_state, $service, $op = 'edit') {
  if ($op == 'clone') {
    $profile_type->label .= ' (cloned)';
    $profile_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $service->label,
    '#description' => t('The human-readable name of this service.'),
    '#required' => TRUE,
    '#size' => 30,
  );

  $form['machine_name'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($service->machine_name) ? $service->machine_name : '',
    '#maxlength' => 32,
    '#disabled' => empty($service->is_new),
    '#machine_name' => array(
      'exists' => 'vopros_service_machine_name_load',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this profile type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#description' => t('The base URL for vopros service.'),
    '#size' => 40,
    '#maxlength' => 255,
  );

  $form['auth_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Auth key'),
    '#description' => t('The secret key or auth token used for authentications.'),
    '#default_value' => $service->auth_key,
    '#size' => 40,
    '#maxlength' => 255,
  );

  $form['auth_type'] = array(
    '#type' => 'select',
    '#title' => t('Auth type'),
    '#description' => t('The type of authentication used for the vopros server.'),
    '#options' => vopros_service_auth_types(),
    '#default_value' => $service->auth_type,
  );

  $form['allow_ingoing'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow ingoing'),
    '#default_value' => $service->allow_ingoing,
  );

  $form['allow_outgoing_type'] = array(
    '#type' => 'radios',
    '#title' => t('Service type'),
    '#options' => array(
      'help' => t('Ask for help'),
      'turn_over' => t('Turn over questions'),
    ),
    '#default_value' => $service->allow_outgoing_turn_over ?  'turn_over' : 'help',
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save service'),
    '#weight' => 40,
  );

  if ($op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete profile type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('vopros_service_form_submit_delete'),
    );
  }

  return $form;
}

/**
 * Validate handler for vopros_service_form().
 */
function vopros_service_form_validate($form, &$form_state) {
  if (!valid_url($form_state['values']['url'], TRUE)) {
    form_error($form['url'], t('Invalid service URL.'));
  }
}

/**
 * Submit handler for vopros_service_form().
 */
function vopros_service_form_submit($form, &$form_state) {
  $service = $form_state['vopros_service'];
  $service->label = $form_state['values']['label'];
  $service->machine_name = $form_state['values']['machine_name'];
  $service->url = $form_state['values']['url'];
  $service->auth_key = $form_state['values']['auth_key'];
  $service->auth_type = $form_state['values']['auth_type'];
  $service->allow_ingoing = $form_state['values']['allow_ingoing'];
  $service->allow_outgoing_help = ($form_state['values']['allow_outgoing_type'] == 'help');
  $service->allow_outgoing_turn_over = ($form_state['values']['allow_outgoing_turn_over'] == 'turn_over');
  $service->save();
}

/**
 * Form API submit callback for the delete button.
 */
function vopros_service_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/vopros/services/' . $form_state['vopros_service']->service_id . '/delete';
}

/**
 * Form for sending a question to an external service.
 */
function vopros_service_question_service_form($form, &$form_state, $question) {
  $form_state['question'] = $question;

  $form['#attached'] = array(
    'css' => array(drupal_get_path('module', 'vopros_service') . '/css/vopros_service.admin.css'),
  );

  $form['sidebar'] = array(
    '#prefix' => '<div class="sidebar">',
    '#suffix' => '</div>',
  );
  $form['sidebar']['send'] = array(
    '#type' => 'submit',
    '#value' => t('Send to external'),
  );

  $form['form'] = array(
    '#prefix' => '<div class="form">',
    '#suffix' => '</div>',
  );

  $form['form']['question_title'] = array(
    '#prefix' => '<h2>',
    '#suffix' => '</h2>',
    '#markup' => $question->question_title,
  );

  $form['form']['question_content'] = array(
    '#markup' => $question->question_content,
  );

  $form['form']['message'] = array(
    '#type' => 'textarea',
    '#rows' => 5,
    '#title' => t('Message'),
  );

  $form['form']['send_type'] = array(
    '#type' => 'select',
    '#title' => t('Way of sending'),
    '#options' => array(
      'allow_outgoing_help' => t('Ask for help'),
      'allow_outgoing_turn_over' => t('Turn over the question'),
    ),
    '#required' => TRUE,
    '#ajax' => array(
      'callback' => 'vopros_service_question_service_form_ajax',
      'wrapper' => 'service-options',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $services = vopros_service_load_multiple();
  $form_state['services'] = $services;
  $service_options = array();

  foreach ($services as $service_id => $service) {
    if ($service->allow_outgoing_help || $service->allow_outgoing_turn_over) {
      $service_options[$service_id] = $service->label();
    }
  }

  $form['form']['service'] = array(
    '#prefix' => '<div id="service-options">',
    '#suffix' => '</div>',
    '#type' => 'select',
    '#title' => t('Service to send to'),
    '#options' => $service_options,
    '#required' => TRUE,
  );

  $form['form']['actions'] = array('#type' => 'actions');

  $form['form']['actions']['send'] = array(
    '#type' => 'submit',
    '#value' => t('Send to external'),
    '#attributes' => array('class' => array('primary-action')),
    '#submit' => array('vopros_service_question_service_form_send_submit'),
  );

  $form['form']['actions']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => array('vopros_service_question_service_form_cancel_submit'),
    '#limit_validation_errors' => array(),
  );

  return $form;
}

/**
 * Submit handler for canceling sending a question to external service.
 */
function vopros_service_question_service_form_cancel_submit($form, &$form_state) {
  $form_state['redirect'] = 'admin/vopros/questions/' . $form_state['question']->question_id;
}

/**
 * Ajax callback for vopros_service_question_service_form().
 */
function vopros_service_question_service_form_ajax($form, &$form_state) {
  $type = $form_state['triggering_element']['#value'];
  $service_options = array();

  foreach ($form_state['services'] as $service_id => $service) {
    if ($service->{$type}) {
      $service_options[$service_id] = $service->label();
    }
  }
  $form['form']['service']['#options'] = $service_options;
  return $form['form']['service'];
}

/**
 * Submit handler for vopros_service_question_service_form().
 */
function vopros_service_question_service_form_send_submit($form, &$form_state) {
  $question = $form_state['question'];
  if ($form_state['values']['send_type'] == 'allow_outgoing_turn_over') {
    $question->question_status = 'closed';
    $question->question_status_reason = 'turned over to external service';
    drupal_set_message('The question @title has been turned over to an external service', array('@title' => $question->question_title), 'notice');
    $form_state['redirect'] = 'admin/vopros/questions';
  }
}
