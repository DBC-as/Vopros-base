<?php

/**
 * @file
 * Views integration for Vopros Service forward table.
 *
 * @see http://drupal.org/project/views
 */

/**
 * Implements hook_views_data().
 */
function vopros_service_views_data() {
  $data['vopros_service_question']['table'] = array(
    'name' => 'vopros_service_question',
    'group' => 'Vopros Service forwarded questions.',
    // Relation to question table.
    'join' => array(
      'vopros_question' => array(
        'left_field' => 'uuid',
        'field' => 'uuid',
        // 'type' => 'INNER',
      ),
      'vopros_service' => array(
        'left_field' => 'machine_name',
        'field' => 'machine_name',
        // 'type' => 'INNER',
      ),
    ),
  );

  $data['vopros_service_question']['machine_name'] = array(
    'title' => t('Service machine name'),
    'help' => t('Machine name of the service this question has been forwarded from/to.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'relationship' => array(
      'base' => 'vopros_service',
      'base field' => 'machine_name',
      'field' => 'machine_name',
      'handler' => 'views_handler_relationship',
      'label' => t('Service'),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['vopros_service_question']['direction'] = array(
    'title' => t('Direction of forward'),
    'help' => t('Whether this forward is incoming or outgoing.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'vopros_service_direction_views_handler_filter_in_operator',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['vopros_service_question']['type'] = array(
    'title' => t('Type of forward'),
    'help' => t('Whether this forward is help or turn_over.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'vopros_service_type_views_handler_filter_in_operator',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  return $data;
}
