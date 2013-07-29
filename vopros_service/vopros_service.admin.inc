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
 * UI controller class for the admin interface.
 */
class VoprosServiceMessageUIController extends VoprosUIController {
  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Display a list of vopros service message.';
    unset($items[$this->path. '/add']);
    unset($items[$this->path. '/manage/%entity_object']);
    unset($items[$this->path. '/manage/%entity_object/edit']);
    unset($items[$this->path. '/manage/%entity_object/clone']);
    unset($items[$this->path. '/manage/%entity_object/%']);
    return $items;
  }

  /**
   * Generates the row for the passed entity and may be overridden in order to
   * customize the rows.
   *
   * @param $additional_cols
   *   Additional columns to be added after the entity label column.
   */
  protected function overviewTableRow($conditions, $id, $entity, $additional_cols = array()) {
    $row = parent::overviewTableRow($conditions, $id, $entity, $additional_cols);
    array_pop($row);
    array_pop($row);
    return $row;
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
    '#default_value' => $service->url,
    '#size' => 40,
    '#maxlength' => 255,
  );

  // Auth type is not configurable at the moment, when implemented, we need to
  // refactor auth_key out of the service definition and let the authentication
  // plugin deal with settings and form.
  $form['auth_type'] = array(
    '#type' => 'value',
    '#value' => 'shared_token',
  );

  $form['auth_token'] = array(
    '#prefix' => '<div class="auth-token">',
    '#suffix' => '</div>',
  );

  $form['auth_token']['auth_key'] = array(
    '#prefix' => '<div id="auth-key">',
    '#suffix' => '</div>',
    '#type' => 'textfield',
    '#title' => t('Auth key'),
    '#description' => t("Shared token. Must be the same on both ends, and unique across all services. Use regenerate to generate a random token that's not already used."),
    '#default_value' => $service->auth_key,
    '#size' => 40,
    '#maxlength' => 255,
  );

  $form['auth_token']['regenerate'] = array(
    '#type' => 'button',
    '#value' => t('Regenerate'),
    '#ajax' => array(
      'callback' => 'vopros_service_form_ajax',
      'wrapper' => 'auth-key',
      'method' => 'replace',
      'effect' => 'fade',
    ),

  );

  $form['allow_ingoing'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow ingoing'),
    '#default_value' => $service->allow_ingoing,
  );

  $allow_outgoing_types = array();
  if ($service->allow_outgoing_help) {
    $allow_outgoing_types['help'] = 'help';
  }
  if ($service->allow_outgoing_turn_over) {
    $allow_outgoing_types['turn_over'] = 'turn_over';
  }
  $form['allow_outgoing_type'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Outgoing service type'),
    '#options' => array(
      'help' => t('Ask for help'),
      'turn_over' => t('Turn over questions'),
    ),
    '#default_value' => $allow_outgoing_types,
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
      '#value' => t('Delete service'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('vopros_service_form_submit_delete'),
    );
  }

  return $form;
}

/**
 * Ajax callback for vopros_service_form().
 *
 * Generates a new service token.
 */
function vopros_service_form_ajax($form, &$form_state) {
  // We're using drupal_get_token to get a random and very unlikely to collide,
  // token. We don't need to validate it.
  $form['auth_token']['auth_key']['#value'] = drupal_get_token(REQUEST_TIME);
  return $form['auth_token']['auth_key'];
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
  $service->allow_outgoing_help = in_array('help', $form_state['values']['allow_outgoing_type']);
  $service->allow_outgoing_turn_over = in_array('turn_over', $form_state['values']['allow_outgoing_type']);
  $service->save();

  $form_state['redirect'] = 'admin/vopros/services';
}

/**
 * Form API submit callback for the delete button.
 */
function vopros_service_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/vopros/services/' . $form_state['vopros_service']->service_id . '/delete';
}
