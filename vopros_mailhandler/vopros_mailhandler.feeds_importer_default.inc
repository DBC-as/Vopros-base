<?php
/**
 * @file
 * email.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function vopros_mailhandler_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'vopros_mailhandler';
  $feeds_importer->config = array(
    'name' => 'Vopros mail importer',
    'description' => 'Imports mails from the vopros email account',
    'fetcher' => array(
      'plugin_key' => 'MailhandlerFetcher',
      'config' => array(
        'filter' => 'all',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'VoprosMailhandlerParser',
      'config' => array(
        'if_auth_fails' => 'remove',
        'default_commands' => 'status: 1',
        'available_commands' => 'status',
        'command_plugin' => array(
          0 => 'MailhandlerCommandsDefault',
          1 => 'MailhandlerCommandsFiles',
          2 => 'MailhandlerCommandsHeaders',
        ),
        'authenticate_plugin' => 'MailhandlerAuthenticateDefault',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'VoprosMailhandlerProcessor',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'subject_question',
            'target' => 'question_id',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'fromaddress',
            'target' => 'email',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'subject',
            'target' => 'subject',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'origbody',
            'target' => 'email_content',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'attachments',
            'target' => 'vopros_email_attachment',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => 0,
        'input_format' => NULL,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['vopros_mailhandler'] = $feeds_importer;

  return $export;
}
