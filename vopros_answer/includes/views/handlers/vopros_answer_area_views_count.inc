<?php

/**
 * Defines a line item actions area handler so the action buttons can be plugged
 * into the View itself.
 */
class vopros_answer_area_views_count extends views_handler_area {

  function option_definition() {
    $options = parent::option_definition();

    // Undefine the empty option.
    unset($options['empty']);

    return $options;
  }

  function render($empty = FALSE) {
    if (!$empty) {
      return '<p>' . t('Number of questions: @count', array('@count' => $this->view->total_rows)) . '</p>';
    }
  }
}
