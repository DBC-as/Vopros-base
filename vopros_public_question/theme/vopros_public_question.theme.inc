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

/**
 * Theme function for displaying status entry when the question was published.
 */
function theme_vopros_public_question_link($variables) {
  $public_question = $variables['element']['#public_question'];
  $output = '<div class="public-question vopros-question-extra"><span class="label">' . t('Public question') . ':</span><span class="value">' . l(t('Edit public question'), 'admin/vopros/public-questions/' . $public_question->public_question_id . '/edit') . '</span>';
  $output .= '</div>';
  return $output;
}

/**
 * Theme function for displaying a link that can be used to publish the question.
 */
function theme_vopros_public_question_new_link($variables) {
  $question = $variables['element']['#question'];
  $output = '<div class="public-question vopros-question-extra"><span class="label">' . t('No public question') . ':</span><span class="value">' . l(t('Add public question now'), 'admin/vopros/public-questions/new/' . $question->question_id) . '</span>';
  $output .= '</div>';
  return $output;
}
