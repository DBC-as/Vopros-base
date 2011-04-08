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
  return '<div class="vopros-answer">' . $answer->answer_content . '</div>';
}

/**
 * Theme function to render several answers content.
 */
function theme_vopros_answer_answers_pl_content($variables) {
  $answers = $variables['answers'];
  if (count($answers) == 1) {
    $answer = array_shift($answers);
    $output = theme('vopros_answer_answer_content', array('answer' => $answer));
    if ($variables['edit']) {
      $output .= l('Edit answer', 'admin/vopros/answer/' . $answer->answer_id . '/edit');
    }
    return $output;
  }
  $items = array();
  foreach ($answers as $answer) {
    $output = theme('vopros_answer_answer_content', array('answer' => $answer));
    if ($variables['edit']) {
      $output .= l('Edit answer', 'admin/vopros/answer/' . $answer->answer_id . '/edit');
    }
    $items[] = $output;
  }
  return theme('item_list', $items);
}
