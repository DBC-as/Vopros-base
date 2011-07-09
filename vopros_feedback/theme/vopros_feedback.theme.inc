<?php

/**
 * @file Theme implementations for the vopros_feedback module
 */

/**
 * Theme function for displaying the feedback conte
 */
function theme_vopros_feedback_content($variables) {
  $feedback = $variables['element']['#feedback'];
  $output = '<div class="feedback-content field">';
  $output .= '<div class="field-label">' . t('Feedback') . ':&nbsp;</div>';
  $output .= '<div class="content">' . str_replace("\n", '<br />', check_plain($feedback->feedback_content)) . '</div>';
  $output .= '</div>';
  return $output;
}
