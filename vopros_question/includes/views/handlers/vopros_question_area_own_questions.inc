<?php

/**
 * Defines a line item actions area handler so the action buttons can be plugged
 * into the View itself.
 */
class vopros_question_area_own_questions extends views_handler_area {

  function option_definition() {
    $options = parent::option_definition();

    // Undefine the empty option.
    unset($options['empty']);

    return $options;
  }

  function render($empty = FALSE) {
    if (!$empty) {
      if ($GLOBALS['user']->uid) {
        $output = vopros_base_embed_view('vopros_question_list', 'own_questions', array(0 => $GLOBALS['user']->uid));
        if ($output) {
          $output = '<h2>' . t('Your active questions') . '</h2>' . $output;
        }
        return $output;
      }
    }
  }

}