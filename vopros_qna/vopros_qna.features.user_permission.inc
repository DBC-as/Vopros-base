<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function vopros_qna_user_default_permissions() {
  $permissions = array();

  // Exported permission: edit field_answer_links
  $permissions['edit field_answer_links'] = array(
    'name' => 'edit field_answer_links',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'medarbejder',
      '2' => 'redaktør',
    ),
  );

  // Exported permission: edit field_answer_question_ref
  $permissions['edit field_answer_question_ref'] = array(
    'name' => 'edit field_answer_question_ref',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_answer_ting_ref
  $permissions['edit field_answer_ting_ref'] = array(
    'name' => 'edit field_answer_ting_ref',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'medarbejder',
      '2' => 'redaktør',
    ),
  );

  // Exported permission: edit field_question_already_searched
  $permissions['edit field_question_already_searched'] = array(
    'name' => 'edit field_question_already_searched',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_question_answer_usage
  $permissions['edit field_question_answer_usage'] = array(
    'name' => 'edit field_question_answer_usage',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'medarbejder',
      '4' => 'redaktør',
    ),
  );

  // Exported permission: edit field_question_category
  $permissions['edit field_question_category'] = array(
    'name' => 'edit field_question_category',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'medarbejder',
      '2' => 'redaktør',
    ),
  );

  // Exported permission: edit field_question_deadline
  $permissions['edit field_question_deadline'] = array(
    'name' => 'edit field_question_deadline',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_question_inquirer_mail
  $permissions['edit field_question_inquirer_mail'] = array(
    'name' => 'edit field_question_inquirer_mail',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_question_inquirer_name
  $permissions['edit field_question_inquirer_name'] = array(
    'name' => 'edit field_question_inquirer_name',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_question_inquirer_phone
  $permissions['edit field_question_inquirer_phone'] = array(
    'name' => 'edit field_question_inquirer_phone',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_question_inquirer_postcode
  $permissions['edit field_question_inquirer_postcode'] = array(
    'name' => 'edit field_question_inquirer_postcode',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_question_service
  $permissions['edit field_question_service'] = array(
    'name' => 'edit field_question_service',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view field_answer_links
  $permissions['view field_answer_links'] = array(
    'name' => 'view field_answer_links',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'medarbejder',
      '4' => 'redaktør',
    ),
  );

  // Exported permission: view field_answer_question_ref
  $permissions['view field_answer_question_ref'] = array(
    'name' => 'view field_answer_question_ref',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'medarbejder',
      '4' => 'redaktør',
    ),
  );

  // Exported permission: view field_answer_ting_ref
  $permissions['view field_answer_ting_ref'] = array(
    'name' => 'view field_answer_ting_ref',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'medarbejder',
      '4' => 'redaktør',
    ),
  );

  // Exported permission: view field_question_already_searched
  $permissions['view field_question_already_searched'] = array(
    'name' => 'view field_question_already_searched',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'medarbejder',
      '4' => 'redaktør',
    ),
  );

  // Exported permission: view field_question_answer_usage
  $permissions['view field_question_answer_usage'] = array(
    'name' => 'view field_question_answer_usage',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'medarbejder',
      '4' => 'redaktør',
    ),
  );

  // Exported permission: view field_question_category
  $permissions['view field_question_category'] = array(
    'name' => 'view field_question_category',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'medarbejder',
      '4' => 'redaktør',
    ),
  );

  // Exported permission: view field_question_deadline
  $permissions['view field_question_deadline'] = array(
    'name' => 'view field_question_deadline',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'medarbejder',
      '4' => 'redaktør',
    ),
  );

  // Exported permission: view field_question_inquirer_mail
  $permissions['view field_question_inquirer_mail'] = array(
    'name' => 'view field_question_inquirer_mail',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'medarbejder',
      '2' => 'redaktør',
    ),
  );

  // Exported permission: view field_question_inquirer_name
  $permissions['view field_question_inquirer_name'] = array(
    'name' => 'view field_question_inquirer_name',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'medarbejder',
      '2' => 'redaktør',
    ),
  );

  // Exported permission: view field_question_inquirer_phone
  $permissions['view field_question_inquirer_phone'] = array(
    'name' => 'view field_question_inquirer_phone',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'medarbejder',
      '2' => 'redaktør',
    ),
  );

  // Exported permission: view field_question_inquirer_postcode
  $permissions['view field_question_inquirer_postcode'] = array(
    'name' => 'view field_question_inquirer_postcode',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'medarbejder',
      '2' => 'redaktør',
    ),
  );

  // Exported permission: view field_question_service
  $permissions['view field_question_service'] = array(
    'name' => 'view field_question_service',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'medarbejder',
      '2' => 'redaktør',
    ),
  );

  return $permissions;
}
