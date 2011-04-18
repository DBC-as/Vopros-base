<?php

/**
 * @ file
 * Admin forms and callback functions.
 */

/**
 * Answer settings form
 */
function vopros_answer_settings_form($form, &$form_state) {
  return system_settings_form($form);
}

/**
 * Answer form
 */
function vopros_answer_form($form, &$form_state, $question, $answer) {
  if (empty($question)) {
    $question = vopros_question_load($answer->question_id);
  }
  $form['question'] = array(
    '#type' => 'value',
    '#value' => $question,
  );

  $form['answer'] = array(
    '#type' => 'value',
    '#value' => $answer,
  );

  $form['question_content'] = array(
    '#markup' => $question->question_content,
    '#prefix' => '<div class="question">',
    '#suffix' => '</div>',
  );

  $form['link'] = array(
    '#markup' => l('See question', 'admin/vopros/questions/' . $question->question_id),
    '#prefix' => '<div class="question-link">',
    '#suffix' => '</div>',
  );

  $form['answer_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Answer'),
    '#default_value' => isset($answer->answer_content) ? $answer->answer_content : '',
    
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => array('vopros_answer_form_save_submit'),
  );

  $form['save_release'] = array(
    '#type' => 'submit',
    '#value' => t('Save and release'),
    '#submit' => array('vopros_answer_form_save_release_submit'),
  );

  $form['save_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save and submit'),
    '#submit' => array('vopros_answer_form_save_submit_submit'),
  );

  $form['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => array('vopros_answer_form_cancel_submit'),
  );

  return $form;
}

/**
 * Submit handler for saving questions
 */
function vopros_answer_form_save_submit(&$form, &$form_state) {
  $v = $form_state['values'];
  $answer = $v['answer'];
  $question = $v['question'];
  $answer->question_id = $question->question_id;
  $answer->answer_content = $v['answer_content'];
  $answer->author_name = $GLOBALS['user']->name;
  vopros_answer_save($answer);
  drupal_set_message('Answer saved');
}

/**
 * Submit handler for cancelling an answer.
 */
function vopros_answer_form_cancel_submit(&$form, &$form_state) {
  // TODO: What should happen here?
  // Open up the question for others.
  $question = $form_state['values']['question'];
  $question->uid = 0;
  $question->question_status = 'in progress';
  vopros_question_save($question);
  $form_state['redirect'] = 'admin/vopros/questions/' . $question->question_id;
}

/**
 * Submit handler for save an answer and release the question.
 */
function vopros_answer_form_save_release_submit(&$form, &$form_state) {
  $question = $form_state['values']['question'];
  $question->uid = 0;
  $question->question_status = 'in progress';
  vopros_question_save($question);
  $answer->question_id = $question->question_id;
  $answer->answer_content = $v['answer_content'];
  $answer->author_name = $GLOBALS['user']->name;
  vopros_answer_save($answer);
  drupal_set_message('Answer saved and question released for others to answer');
  $form_state['redirect'] = 'admin/vopros/questions/' . $question->question_id;
}

/**
 * Submit handler to save and submit the answer
 */
function vopros_answer_form_save_submit_submit(&$form, &$form_state) {
  $v = $form_state['values'];
  $question = $form_state['values']['question'];
  $question->question_status = 'answered';
  vopros_question_save($question);
  $answer->question_id = $question->question_id;
  $answer->answer_content = $v['answer_content'];
  $answer->author_name = $GLOBALS['user']->name;
  $answer->status = 'complete';
  $form_state['answer'] = $answer;
  vopros_answer_save($answer);
  drupal_set_message('Answer saved and question marked as answered');
  $form_state['redirect'] = 'admin/vopros/questions/' . $question->question_id;
}
