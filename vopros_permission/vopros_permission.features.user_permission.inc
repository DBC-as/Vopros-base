<?php
/**
 * @file
 * vopros_permission.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function vopros_permission_user_default_permissions() {
  $permissions = array();

  // Exported permission: access SMSes
  $permissions['access SMSes'] = array(
    'name' => 'access SMSes',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_sms',
  );

  // Exported permission: access advances admin pages
  $permissions['access advances admin pages'] = array(
    'name' => 'access advances admin pages',
    'roles' => array(),
  );

  // Exported permission: access all views
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      0 => 'Admin',
    ),
    'module' => 'views',
  );

  // Exported permission: access answers
  $permissions['access answers'] = array(
    'name' => 'access answers',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_answer',
  );

  // Exported permission: access emails
  $permissions['access emails'] = array(
    'name' => 'access emails',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_email',
  );

  // Exported permission: access feedback
  $permissions['access feedback'] = array(
    'name' => 'access feedback',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_feedback',
  );

  // Exported permission: access logs
  $permissions['access logs'] = array(
    'name' => 'access logs',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_log',
  );

  // Exported permission: access public questions
  $permissions['access public questions'] = array(
    'name' => 'access public questions',
    'roles' => array(),
  );

  // Exported permission: access questions
  $permissions['access questions'] = array(
    'name' => 'access questions',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_question',
  );

  // Exported permission: access toolbar
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: access user profiles
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'Admin',
    ),
    'module' => 'user',
  );

  // Exported permission: administer SMSes
  $permissions['administer SMSes'] = array(
    'name' => 'administer SMSes',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_sms',
  );

  // Exported permission: administer answers
  $permissions['administer answers'] = array(
    'name' => 'administer answers',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_answer',
  );

  // Exported permission: administer emails
  $permissions['administer emails'] = array(
    'name' => 'administer emails',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_email',
  );

  // Exported permission: administer feedback
  $permissions['administer feedback'] = array(
    'name' => 'administer feedback',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_feedback',
  );

  // Exported permission: administer logs
  $permissions['administer logs'] = array(
    'name' => 'administer logs',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_log',
  );

  // Exported permission: administer permissions
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(),
  );

  // Exported permission: administer public questions
  $permissions['administer public questions'] = array(
    'name' => 'administer public questions',
    'roles' => array(),
  );

  // Exported permission: administer questions
  $permissions['administer questions'] = array(
    'name' => 'administer questions',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_question',
  );

  // Exported permission: administer ting settings
  $permissions['administer ting settings'] = array(
    'name' => 'administer ting settings',
    'roles' => array(),
  );

  // Exported permission: administer users
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      0 => 'Admin',
    ),
    'module' => 'user',
  );

  // Exported permission: administer views
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      0 => 'Admin',
    ),
    'module' => 'views',
  );

  // Exported permission: administer vopros
  $permissions['administer vopros'] = array(
    'name' => 'administer vopros',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_base',
  );

  // Exported permission: administer vopros_migrate
  $permissions['administer vopros_migrate'] = array(
    'name' => 'administer vopros_migrate',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_migrate',
  );

  // Exported permission: administer voting api
  $permissions['administer voting api'] = array(
    'name' => 'administer voting api',
    'roles' => array(
      0 => 'Admin',
    ),
    'module' => 'votingapi',
  );

  // Exported permission: cancel account
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      0 => 'Admin',
    ),
    'module' => 'user',
  );

  // Exported permission: change own username
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      0 => 'Admin',
    ),
    'module' => 'user',
  );

  // Exported permission: contact user about question
  $permissions['contact user about question'] = array(
    'name' => 'contact user about question',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_question',
  );

  // Exported permission: create SMSes
  $permissions['create SMSes'] = array(
    'name' => 'create SMSes',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_sms',
  );

  // Exported permission: create answers
  $permissions['create answers'] = array(
    'name' => 'create answers',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_answer',
  );

  // Exported permission: create emails
  $permissions['create emails'] = array(
    'name' => 'create emails',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_email',
  );

  // Exported permission: create feedback
  $permissions['create feedback'] = array(
    'name' => 'create feedback',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_feedback',
  );

  // Exported permission: create logs
  $permissions['create logs'] = array(
    'name' => 'create logs',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_log',
  );

  // Exported permission: create public questions
  $permissions['create public questions'] = array(
    'name' => 'create public questions',
    'roles' => array(),
  );

  // Exported permission: create questions
  $permissions['create questions'] = array(
    'name' => 'create questions',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_question',
  );

  // Exported permission: edit any answer
  $permissions['edit any answer'] = array(
    'name' => 'edit any answer',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_answer',
  );

  // Exported permission: edit any email
  $permissions['edit any email'] = array(
    'name' => 'edit any email',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_email',
  );

  // Exported permission: edit any feedback
  $permissions['edit any feedback'] = array(
    'name' => 'edit any feedback',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_feedback',
  );

  // Exported permission: edit any log
  $permissions['edit any log'] = array(
    'name' => 'edit any log',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_log',
  );

  // Exported permission: edit any sms
  $permissions['edit any sms'] = array(
    'name' => 'edit any sms',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_sms',
  );

  // Exported permission: edit any vopros_admin profile
  $permissions['edit any vopros_admin profile'] = array(
    'name' => 'edit any vopros_admin profile',
    'roles' => array(
      0 => 'Admin',
    ),
    'module' => 'profile2',
  );

  // Exported permission: edit own SMSes
  $permissions['edit own SMSes'] = array(
    'name' => 'edit own SMSes',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_sms',
  );

  // Exported permission: edit own answers
  $permissions['edit own answers'] = array(
    'name' => 'edit own answers',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_answer',
  );

  // Exported permission: edit own emails
  $permissions['edit own emails'] = array(
    'name' => 'edit own emails',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_email',
  );

  // Exported permission: edit own feedback
  $permissions['edit own feedback'] = array(
    'name' => 'edit own feedback',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_feedback',
  );

  // Exported permission: edit own logs
  $permissions['edit own logs'] = array(
    'name' => 'edit own logs',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_log',
  );

  // Exported permission: edit own vopros_admin profile
  $permissions['edit own vopros_admin profile'] = array(
    'name' => 'edit own vopros_admin profile',
    'roles' => array(
      0 => 'Admin',
    ),
    'module' => 'profile2',
  );

  // Exported permission: edit public questions
  $permissions['edit public questions'] = array(
    'name' => 'edit public questions',
    'roles' => array(),
  );

  // Exported permission: edit questions
  $permissions['edit questions'] = array(
    'name' => 'edit questions',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_question',
  );

  // Exported permission: select account cancellation method
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      0 => 'Admin',
    ),
    'module' => 'user',
  );

  // Exported permission: view any vopros_admin profile
  $permissions['view any vopros_admin profile'] = array(
    'name' => 'view any vopros_admin profile',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'profile2',
  );

  // Exported permission: view own SMSes
  $permissions['view own SMSes'] = array(
    'name' => 'view own SMSes',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_sms',
  );

  // Exported permission: view own answers
  $permissions['view own answers'] = array(
    'name' => 'view own answers',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_answer',
  );

  // Exported permission: view own emails
  $permissions['view own emails'] = array(
    'name' => 'view own emails',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_email',
  );

  // Exported permission: view own feedback
  $permissions['view own feedback'] = array(
    'name' => 'view own feedback',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_feedback',
  );

  // Exported permission: view own logs
  $permissions['view own logs'] = array(
    'name' => 'view own logs',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'vopros_log',
  );

  // Exported permission: view own vopros_admin profile
  $permissions['view own vopros_admin profile'] = array(
    'name' => 'view own vopros_admin profile',
    'roles' => array(
      0 => 'Admin',
      1 => 'Editor',
    ),
    'module' => 'profile2',
  );

  return $permissions;
}
