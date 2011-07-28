<?php

/**
 * @file Theme implementations for the vopros_feedback module
 */

/**
 * Theme function for displaying the feedback conte
 */
function theme_vopros_feedback_content($variables) {
  $feedback = $variables['feedback'];
  $output = '<div class="feedback-content field">';
  $output .= '<div class="field-label">' . t('Feedback') . ':&nbsp;</div>';
  $output .= '<div class="content">' . str_replace("\n", '<br />', check_plain($feedback->feedback_content)) . '</div>';
  $output .= '</div>';
  return $output;
}

/**
 * Theme the result of a feedback.
 */
function theme_vopros_feedback_result($variables) {
  $feedback = $variables['feedback'];

  $build = field_attach_view('vopros_feedback', $feedback, 'full');
  $build['feedback_content'] = array(
    '#theme' => 'vopros_feedback_content',
    '#feedback' => $feedback,
  );

  return render($build);
}
