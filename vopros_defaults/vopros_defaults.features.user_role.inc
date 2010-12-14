<?php

/**
 * Implementation of hook_user_default_roles().
 */
function vopros_defaults_user_default_roles() {
  $roles = array();

  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
  );

  // Exported role: medarbejder
  $roles['medarbejder'] = array(
    'name' => 'medarbejder',
  );

  // Exported role: redaktør
  $roles['redaktør'] = array(
    'name' => 'redaktør',
  );

  return $roles;
}
