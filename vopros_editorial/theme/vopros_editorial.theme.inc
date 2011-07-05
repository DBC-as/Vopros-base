<?php

/**
 * @file Theme implementations for the vopros_question module
 */

/**
 * Theme function for the question status changes on activity feed.
 */
function theme_vopros_editorial_field_feed($variables) {
  $revision = $variables['question']['#revision'];
  $date = format_date($revision->revision_timestamp, 'short');
  $term = taxonomy_term_load($revision->tid);
  $username = t('System');
  if ($revision->revision_uid) {
    $username = theme('username', array('account' => user_load($revision->revision_uid)));
  }

  $output = '<div class="editorial-feed-item feed-item">';
  $output .= t('Question transferred to %editorial by !username @date', array('@date' => $date, '!username' => $username, '%editorial' => $term->name));
  $output .= '</div>';
  return $output;
}
