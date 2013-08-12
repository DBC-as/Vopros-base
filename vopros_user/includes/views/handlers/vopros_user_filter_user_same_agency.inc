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
    global $user;
    $this->ensure_my_table();

    $field = $this->table_alias . '.' . $this->real_field . ' ';
    $or = db_or();

    $profile = profile2_load_by_user($user, 'vopros_user_librarian');
    if ($profile) {
      $wrapper = entity_metadata_wrapper('profile2', $profile);
      $value = $wrapper->vopros_user_library->value();
      if (empty($this->value)) {
        $or->condition($field, $value, '<>');
      }
      else {
        $or->condition($field, $value, '=');
      }
    }
    else {
      // I know...
      $or->condition($field, 'veryunlikelyvalue', '=');
    }

    $this->query->add_where($this->options['group'], $or);
  }

}
