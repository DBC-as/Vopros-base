<?php
/**
 * @file
 * vopros_user.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function vopros_user_taxonomy_default_vocabularies() {
  return array(
    'vopros_user_expertise' => array(
      'name' => 'Expertise',
      'machine_name' => 'vopros_user_expertise',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
