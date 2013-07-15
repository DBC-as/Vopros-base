<?php
/**
 * @file
 * vopros_user.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function vopros_user_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'vopros_server';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'vopros-server';
  $endpoint->authentication = array();
  $endpoint->server_settings = array();
  $endpoint->resources = array(
    'vopros_user_profile_service' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['vopros_server'] = $endpoint;

  return $export;
}
