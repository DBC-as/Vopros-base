<?php

/**
 * Defines a line item actions area handler so the action buttons can be plugged
 * into the View itself.
 */
class vopros_answer_area_own_questions extends views_handler_area {

  function option_definition() {
    $options = parent::option_definition();

    // Undefine the empty option.
    unset($options['empty']);

    return $options;
  }

  function render($empty = FALSE) {
    if ($GLOBALS['user']->uid) {
      $view = views_get_view('vopros_question_own_questions');
      $view->set_display('page');
      $view->set_arguments(array(0 => $GLOBALS['user']->uid));
      // Prepare and execute the View query.
      $view->pre_execute();
      $view->execute();
      $output = '';
      if ($view->total_rows > 0) {
        $output = '<h2>' . t('Your active questions') . '</h2>' . $view->render();
      }
      return $output;
    }
  }
}
