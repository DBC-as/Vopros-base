<?php

/**
 * Admin forms and page callbacks for vopros public question module.
 */

/**
 * General settings form.
 */
function vopros_public_question_settings_form($form, &$form_state) {
  $form['markup'] = array(
    '#markup' => t('No settings yet.'),
  );
  return system_settings_form($form);
}

/**
 * Form for creating and editing public questions.
 */
function vopros_public_question_form($form, &$form_state, $question = NULL, $public_question = NULL) {
  if (empty($question)) {
    $question = vopros_question_new();
  }
  if (empty($public_question)) {
    $public_question = vopros_public_question_new();
  }
  if (isset($question->question_id)) {
    $public_question->question_id = $question->question_id;
  }
  elseif ($public_question->question_id) {
    $question = vopros_question_load($public_question->question_id);
  }

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $public_question->title ? $public_question->title : $question->question_title,
  );

  $form['question_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Question content'),
    '#default_value' => $public_question->question_content ? $public_question->question_content : $question->question_content,
    '#rows' => 20,
  );

  $answer_content = '';
  $answers = vopros_answer_load_multiple(FALSE, array('question_id' => $question->question_id));
  foreach ($answers as $answer) {    
    $answer_content .= $answer->answer_content . "\n\n\n\n";
  }

  $form['answer_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Answer content'),
    '#default_value' => $public_question->answer_content ? $public_question->answer_content : trim($answer_content),
    '#rows' => 20,
  );

  $form['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => $public_question->subject ? $public_question->subject : '',
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => array('vopros_public_question_form_save_submit'),
  );

  if ($public_question->status === 'unpublished') {
    $form['publish'] = array(
      '#type' => 'submit',
      '#value' => t('Save and publish'),
      '#submit' => array('vopros_public_question_form_publish_submit'),
    );
  }

  $form_state['public_question'] = $public_question;
  $form_state['question'] = $question;

  return $form;
}

/**
 * Submit handler for vopros_public_question_form().
 * Used for saving a public question.
 */
function vopros_public_question_form_save_submit(&$form, &$form_state) {
  global $user;
  $public_question = $form_state['public_question'];
  $public_question->title = $form_state['values']['title'];
  $public_question->answer_content = $form_state['values']['answer_content'];
  $public_question->question_content = $form_state['values']['question_content'];
  $public_question->subject = $form_state['values']['subject'];
  $public_question->uid = $user->uid;
  vopros_public_question_save($public_question);
  $form_state['redirect'] = 'admin/vopros/public-questions/' . $public_question->public_question_id . '/edit';
  drupal_set_message(t("Question/answer has been saved but haven't been made public"), 'warning');
}

/**
 * Submit handler for vopros_public_question_form().
 * Used for saving a public question.
 */
function vopros_public_question_form_publish_submit(&$form, &$form_state) {
  // Save the public question.
  global $user;
  $public_question = $form_state['public_question'];

  $public_question->title = $form_state['values']['title'];
  $public_question->answer_content = $form_state['values']['answer_content'];
  $public_question->question_content = $form_state['values']['question_content'];
  $public_question->subject = $form_state['values']['subject'];
  $public_question->uid = $user->uid;
  vopros_public_question_save($public_question);

  // Create the description from the question and answer. Used by osa_addi.
  $public_question->description = $public_question->question_content . "\n\n" . $public_question->answer_content;
  $result = osa_addi_create_object($public_question, $public_question->uuid);
  if ($result['status'] == 'object_created') {
    drupal_set_message(t('Question has been published !link', array('!link' => l(t('see public question'), 'admin/vopros/public-questions/' . $public_question->public_question_id . '/edit'))));
    $public_question->status = 'published';
    $question = vopros_question_load($public_question->question_id);
    $question->question_status = 'published';
    $question->question_status_reason = '';
    vopros_question_save($question);
    vopros_public_question_save($public_question);
    $form_state['redirect'] = 'admin/vopros/questions/list';
  }
  else {
    drupal_set_message(t('Record could not be created'), 'error');
  }
  
}
