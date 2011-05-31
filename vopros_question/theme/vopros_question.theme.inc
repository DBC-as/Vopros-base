<?php

/**
 * @file
 */

function template_preprocess_vopros_question(&$variables) {
  $variables['view_mode'] = $variables['elements']['#view_mode'];
  $question = $variables['question'] = $variables['elements']['#question'];

  // Flatten the question object's member fields.
  $variables = array_merge((array) $question, $variables);
  $variables['right'] = $variables['elements']['right'];
  unset($variables['elements']['right']);

  // Helpful $content variable for templates.
  foreach (element_children($variables['elements']) as $key) {
    $variables['content'][$key] = $variables['elements'][$key];
  }

  // Make the field variables available with the appropriate language.
  field_attach_preprocess('question', $question, $variables['content'], $variables);
}

/**
 * Theme function for question title
 */
function theme_vopros_question_title($variables) {
  $question = $variables['question']['#question'];
  return '<h2 class="question-title">' . check_plain($question->question_title) . '</h2>';
}

/**
 * Theme function for question content
 */
function theme_vopros_question_content($variables) {
  $question = $variables['question']['#question'];
  return '<p class="question-content">' . check_plain($question->question_content) . '</p>';
}

/**
 * Theme function for question deadline
 */
function theme_vopros_question_deadline($variables) {
  $question = $variables['question']['#question'];
  $time_diff = $_SERVER['REQUEST_TIME'] - $question->question_deadline_timestamp;
  if ($time_diff > 0) {
    $deadline = t('Deadline passed');
  }
  elseif ($time_diff < - 6 * 7 * 86400)  { // 6 weeks
    $deadline = t('No Deadline');
  }
  else {
    $deadline = t('%time to deadline', array('%time' => format_interval(-$time_diff, 2)));
  }
  $output = '<div class="question-deadline vopros-question-extra">';
  $output .= '<span class="label">' . t('Deadline:') .  '</span>';
  $output .= '<span class="value">' . $deadline .  '</span>';
  $output .= '</div>';
  return $output;
}

/**
 * Theme function for question usage
 */
function theme_vopros_question_usage($variables) {
  $question = $variables['question']['#question'];
  $mapping = _vopros_question_usage();
  $output = '<div class="question-usage vopros-question-extra">';
  $output .= '<span class="label">' . t('Usage:') .  '</span>';
  $output .= '<span class="value">' . (isset($mapping[$question->question_usage]) ? $mapping[$question->question_usage] : t('Other')) . '</span>';
  $output .= '</div>';
  return $output;
}

function theme_vopros_question_created($variables) {
  $question = $variables['question']['#question'];
  $output = '<div class="question-created vopros-question-extra">';
  $output .= '<span class="label">' . t('Created:') .  '</span>';
  $output .= '<span class="value">' . format_date($question->created, 'short') . '</span>';
  $output .= '</div>';
  return $output;
}

/**
 * Theme function for question internal note
 */
function theme_vopros_question_note($variables) {
  $question = $variables['question']['#question'];
  $output = '';
  if ($question->question_note) {
    $output = '<div class="question-note vopros-question-extra">';
    $output .= '<span class="label">' . t('Note:') .  '</span>';
    $output .= '<span class="value">' . check_plain($question->question_note) . '</span>';
    $output .= '</div>';
  }
  return $output;
}

/**
 * Theme function for question user data
 */
function theme_vopros_question_user_data($variables) {
  $user_age_mapping = _vopros_question_user_age();
  $question = $variables['question']['#question'];
  $output = '';
  if ($variables['question']['#view_mode'] !== 'teaser') {
    $output .= '<h3 class="question-user-data">' . t('User data') . '</h3>';
  }
  
  $output .= '<div class="question-user-data-data">';

  $output .= '<div class="question-user-name vopros-question-extra">';
  $output .= '<span class="label">' . t('Name:') .  '</span>';
  $output .= '<span class="value">' . check_plain($question->user_name) .  '</span>';
  $output .= '</div>';
  $output .= '<div class="question-user-age vopros-question-extra">';
  $output .= '<span class="label">' . t('Age:') .  '</span>';
  $output .= '<span class="value">' . isset($user_age_mapping[$question->user_age]) ? $user_age_mapping[$question->user_age] : $user_age_mapping['no inform'] .  '</span>';
  $output .= '</div>';
  if ($question->user_postal_code) {
    $output .= '<div class="question-user-postal-code vopros-question-extra">';
    $output .= '<span class="label">' . t('Postal code:') .  '</span>';
    $output .= '<span class="value">' . check_plain($question->user_postal_code) .  '</span>';
    $output .= '</div>';
  }
  if ($question->user_field_of_study) {
    $output .= '<div class="question-user-field-of-study vopros-question-extra">';
    $output .= '<span class="label">' . t('Field of study:') .  '</span>';
    $output .= '<span class="value">' . check_plain($question->user_field_of_study) .  '</span>';
    $output .= '</div>';
  }
  if ($question->user_library) {
    $output .= '<div class="question-user-library vopros-question-extra">';
    $output .= '<span class="label">' . t('Library:') .  '</span>';
    $output .= '<span class="value">' . check_plain($question->user_library) .  '</span>';
    $output .= '</div>';
  }

  $output .= '</div>';
  return $output;
}

/**
 * Theme function for the question log
 */
function theme_vopros_question_log($variables) {
  $question = $variables['question']['#question'];
  $show = isset($variables['question']['show']) && $variables['question']['show'];
  $output = '';
  if ($question->log || $show) {
    $output .= '<div class="question-log vopros-question-extra">';
    $output .= '<div class="label">' . t('Internal log:') .  '</div>';
    $output .= '<div class="value">' . check_markup($question->log) . '</div>';
    $output .= '</div>';
  }
  return $output;
}
