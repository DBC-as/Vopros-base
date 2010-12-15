<?php

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function vopros_qna_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-vopros
  $menus['menu-vopros'] = array(
    'menu_name' => 'menu-vopros',
    'title' => 'Spørgsmål og svar',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Spørgsmål og svar');


  return $menus;
}
