<?php

/**
 * @file
 * Theme functions and preprocess functions for vopros_answer module.
 */

/**
 * Theme function to render a single answer's content
 */
function theme_vopros_answer_answer_content($variables) {
  $answer = $variables['answer'];
  $output = '<div class="vopros-answer">';
  if ($variables['title']) {
    $output .= '<h3>' . $variables['title'] . '</h3>';
  }
  $output .= '<p>' . $answer->answer_content . '</p>';
  $output .= '</div>';
  return $output;
}

/**
 * Theme function to render several answers content.
 */
function theme_vopros_answer_answers_pl_content($variables) {
  $answers = $variables['answers'];
  if (count($answers) == 1) {
    $answer = array_shift($answers);
    $vars = array('answer' => $answer);
    if (isset($variables['title'])) {
      $vars['title'] = $variables['title'];
    }
    else {
      $vars['title'] = t('Answer');
    }
    $output = theme('vopros_answer_answer_content', $vars);
    if ($variables['edit']) {
      $output .= l(t('Edit answer'), 'admin/vopros/answers/' . $answer->answer_id . '/edit');
    }
    return $output;
  }
  $items = array();
  foreach ($answers as $answer) {
    $output = theme('vopros_answer_answer_content', array('answer' => $answer, 'title' => ''));
    if ($variables['edit']) {
      $output .= l(t('Edit answer'), 'admin/vopros/answers/' . $answer->answer_id . '/edit');
    }
    $items[] = $output;
  }
  return '<h3>' . t('Answers') . '</h3>' . theme('item_list', $items);
}
