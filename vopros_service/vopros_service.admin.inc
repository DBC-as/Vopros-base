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
    '#default_value' => isset($service->machine_name) ? $profile_type->machine_name : '',
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

  $form['allow_outgoing_help'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow to ask for help'),
    '#default_value' => $service->allow_outgoing_help,
  );

  $form['allow_outgoing_turn_over'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow to turn over questions'),
    '#default_value' => $service->allow_outgoing_turn_over,
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
  $service->allow_outgoing_help = $form_state['values']['allow_outgoing_help'];
  $service->allow_outgoing_turn_over = $form_state['values']['allow_outgoing_turn_over'];
  $service->save();
}

/**
 * Form API submit callback for the delete button.
 */
function vopros_service_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/vopros/services/' . $form_state['vopros_service']->service_id . '/delete';
}
