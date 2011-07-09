<?php

/**
 * @file Theme implementations for the vopros_public_question module
 */

/**
 * Theme function for displaying status entry when the question was published.
 */
function theme_vopros_public_question_feed($variables) {
  $public_question = $variables['element']['#public_question'];
  $username = theme('username', array('account' => user_load($public_question->uid)));
  $date = format_date($public_question->created, 'short');
  $output = '<div class="published-feed-item feed-item">';
  $output .= t('Question published by !username @date', array('@date' => $date, '!username' => $username));
  $output .= '</div>';
  return $output;
}
