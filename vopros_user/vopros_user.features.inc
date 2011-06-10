<?php
/**
 * @file
 * vopros_user.features.inc
 */

/**
 * Implementation of hook_default_profile2_type().
 */
function vopros_user_default_profile2_type() {
  $items = array();
  $items['vopros_admin'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "vopros_admin",
    "label" : "Librarian",
    "weight" : "0",
    "data" : { "registration" : 0 }
  }');
  return $items;
}
