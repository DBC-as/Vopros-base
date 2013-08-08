<?php

/**
 * @file
 * Definition of vopros_user_filter_user_same_agency.
 */

/**
 * Filter handler for users in the same agency.
 *
 * @ingroup views_filter_handlers
 */
class vopros_user_filter_user_same_agency extends views_handler_filter_boolean_operator {
  function construct() {
    parent::construct();
    $this->value_value = t('Is from the same library as the current user');
  }

  function query() {
    $this->ensure_my_table();

    $field = $this->table_alias . '.' . $this->real_field . ' ';
    $or = db_or();

    if (empty($this->value)) {
      $or->condition($field, '1', '<>');
    }
    else {
      $or->condition($field, '1', '=');
    }

    $this->query->add_where($this->options['group'], $or);
  }

}
