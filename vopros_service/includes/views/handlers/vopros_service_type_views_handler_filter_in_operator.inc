<?php

/**
 * @file
 * Definition of vopros_service_type_views_handler_filter_in_operator.
 */

/**
 * Filter by forward type.
 *
 * @ingroup views_filter_handlers
 */
class vopros_service_type_views_handler_filter_in_operator extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Type');
      $this->value_options = array(
        'help' => t('Help'),
        'turn_over' => t('Turn over'),
      );
    }
  }
}
