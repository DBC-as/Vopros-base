<?php

/**
 * @file
 * Theme function and preprocess functions for the vopros_log module.
 */

function theme_vopros_log_question_feed($variables) {
  $log = $variables['log']['#log'];
  $username = theme('username', array('account' => user_load($log->uid)));
  $date = format_date($log->created, 'short');
  
  $output = '<div class="log-feed-item feed-item">';
  $output .= '<div class="log-header">';
  $output .= t('!username posted log message @date', array('@date' => $date, '!username' => $username));
  $output .= '</div>';
  $output .= '<div class="log-content">';
  $output .= str_replace("\n", '<br />', check_plain($log->log_content));
  $output .= '</div>';
  $output .= '</div>';
  return $output;
}
