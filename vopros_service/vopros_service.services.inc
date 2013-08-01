<?php
/**
 * @file
 * vopros_service.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function vopros_service_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'vopros_transfer';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'vopros_transfer';
  $endpoint->authentication = array(
    'vopros_service' => 'vopros_service',
  );
  $endpoint->server_settings = array();
  $endpoint->resources = array(
    'question' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
      'targeted_actions' => array(
        'send_answer' => array(
          'enabled' => '1',
        ),
        'send_message' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 0;

  $export[$endpoint->name] = $endpoint;
  return $export;
}
