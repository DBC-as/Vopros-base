<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function vopros_defaults_user_default_permissions() {
  $permissions = array();

  // Exported permission: create vopros_answer content
  $permissions['create vopros_answer content'] = array(
    'name' => 'create vopros_answer content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'medarbejder',
      '2' => 'redaktør',
    ),
  );

  // Exported permission: create vopros_question content
  $permissions['create vopros_question content'] = array(
    'name' => 'create vopros_question content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'medarbejder',
      '4' => 'redaktør',
    ),
  );

  // Exported permission: delete any vopros_answer content
  $permissions['delete any vopros_answer content'] = array(
    'name' => 'delete any vopros_answer content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'redaktør',
    ),
  );

  // Exported permission: delete any vopros_question content
  $permissions['delete any vopros_question content'] = array(
    'name' => 'delete any vopros_question content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'redaktør',
    ),
  );

  // Exported permission: delete own vopros_answer content
  $permissions['delete own vopros_answer content'] = array(
    'name' => 'delete own vopros_answer content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'medarbejder',
      '2' => 'redaktør',
    ),
  );

  // Exported permission: delete own vopros_question content
  $permissions['delete own vopros_question content'] = array(
    'name' => 'delete own vopros_question content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'redaktør',
    ),
  );

  // Exported permission: edit any vopros_answer content
  $permissions['edit any vopros_answer content'] = array(
    'name' => 'edit any vopros_answer content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'redaktør',
    ),
  );

  // Exported permission: edit any vopros_question content
  $permissions['edit any vopros_question content'] = array(
    'name' => 'edit any vopros_question content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'medarbejder',
      '2' => 'redaktør',
    ),
  );

  // Exported permission: edit own vopros_answer content
  $permissions['edit own vopros_answer content'] = array(
    'name' => 'edit own vopros_answer content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'medarbejder',
      '2' => 'redaktør',
    ),
  );

  // Exported permission: edit own vopros_question content
  $permissions['edit own vopros_question content'] = array(
    'name' => 'edit own vopros_question content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'medarbejder',
      '2' => 'redaktør',
    ),
  );

  return $permissions;
}
