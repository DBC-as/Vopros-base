<?php

/**
 * @file
 * Definition of vopros_service_direction_views_handler_filter_in_operator.
 */

/**
 * Filter by forward direction.
 *
 * @ingroup views_filter_handlers
 */
class vopros_service_direction_views_handler_filter_in_operator extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Direction');
      $this->value_options = array(
        'incoming' => t('Incoming'),
        'outgoing' => t('Outgoing'),
      );
    }
  }
}
