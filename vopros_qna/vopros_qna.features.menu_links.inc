<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function vopros_qna_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-vopros:node/add/vopros-question
  $menu_links['menu-vopros:node/add/vopros-question'] = array(
    'menu_name' => 'menu-vopros',
    'link_path' => 'node/add/vopros-question',
    'router_path' => 'node/add/vopros-question',
    'link_title' => 'Stil spørgsmål',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-vopros:questions
  $menu_links['menu-vopros:questions'] = array(
    'menu_name' => 'menu-vopros',
    'link_path' => 'questions',
    'router_path' => 'questions',
    'link_title' => 'Besvarede spørgsmål',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-vopros:questions/in_progress
  $menu_links['menu-vopros:questions/in_progress'] = array(
    'menu_name' => 'menu-vopros',
    'link_path' => 'questions/in_progress',
    'router_path' => 'questions/in_progress',
    'link_title' => 'Spørgsmål under behandling',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-vopros:questions/new
  $menu_links['menu-vopros:questions/new'] = array(
    'menu_name' => 'menu-vopros',
    'link_path' => 'questions/new',
    'router_path' => 'questions/new',
    'link_title' => 'Nye spørgsmål',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Besvarede spørgsmål');
  t('Nye spørgsmål');
  t('Spørgsmål under behandling');
  t('Stil spørgsmål');


  return $menu_links;
}
