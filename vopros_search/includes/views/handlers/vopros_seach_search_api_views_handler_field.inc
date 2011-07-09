<?php

/**
 * @file Class implementation: VoprosSeachSearchApiViewsHandlerField
 */

/**
 * Customized SearchApiViewsHandlerField for rendering fields displayed in
 * search results render with views and search_api.
 */
class VoprosSeachSearchApiViewsHandlerField extends SearchApiViewsHandlerField {

  /**
   * Render the field.
   *
   * Tries to covert $value to become the human readable and translatable string
   * for fields it limited possible values, like question_status.
   *
   * @param $values
   *   The values retrieved from the database.
   */
  public function render($values) {
    $value = $this->get_value($values);
    $mapping = array();
    // Needed to test on question_status_reason to avoid false positives for question_status.
    if (strpos($this->field, 'question_status_reason')) {
      $mapping = _vopros_question_status_reason();
    }
    elseif (strpos($this->field, 'question_status')) {
      $mapping = _vopros_question_status();
    }
    // Try to convert values for fields we know about.
    if (isset($mapping[$value])) {
      $value = $mapping[$value];
    }
    // Proceed as normal.
    if (is_array($value)) {
      return $this->renderArray($value, $values);
    }
    return $this->renderLink($value, $values);
  }
}
