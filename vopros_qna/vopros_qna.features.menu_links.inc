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
    'weight' => '0',
  );
  // Exported menu link: menu-vopros:questions
  $menu_links['menu-vopros:questions'] = array(
    'menu_name' => 'menu-vopros',
    'link_path' => 'questions',
    'router_path' => 'questions',
    'link_title' => 'Se spørgsmål',
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
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Se spørgsmål');
  t('Stil spørgsmål');


  return $menu_links;
}
