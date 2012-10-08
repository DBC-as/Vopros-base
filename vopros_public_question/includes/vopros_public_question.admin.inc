<?php

/**
 * Admin forms and page callbacks for vopros public question module.
 */

/**
 * General settings form.
 */
function vopros_public_question_settings_form($form, &$form_state) {
  $options = array('plain_text' => t('Plain text'));

  $results = db_select('filter_format', 'f')
    ->fields('f', array('format', 'name'))
    ->execute();

  foreach ($results as $format) {
    $options[$format->format] = $format->name;
  }

  $form['vopros_public_question_default_text_format'] = array(
    '#type' => 'select',
    '#title' => t('Default text format'),
    '#options' => $options,
    '#default_value' => variable_get('vopros_public_question_default_text_format', 'plain_text'),
    '#required' => TRUE,
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
  $public_question_wrapper = entity_metadata_wrapper('vopros_public_question', $public_question);
  $question_wrapper = entity_metadata_wrapper('vopros_question', $question);
  if (!empty($public_question->is_new)) {
    $public_question_wrapper->vopros_public_question_subject = $question_wrapper->subject_catagory->value();
  }

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $public_question->title ? $public_question->title : $question->question_title,
  );

  $form['question_content'] = array(
    '#type' => 'text_format',
    '#title' => t('Question content'),
    '#default_value' => $public_question->question_content ? $public_question->question_content : $question->question_content,
    '#format' => $public_question->question_content_format,
    '#rows' => 20,
  );

  $answer_content = '';
  $answers = vopros_answer_load_multiple(FALSE, array('question_id' => $question->question_id));
  foreach ($answers as $answer) {
    $answer_content .= $answer->answer_content . "\n\n\n\n";
  }

  $form['answer_content'] = array(
    '#type' => 'text_format',
    '#title' => t('Answer content'),
    '#default_value' => $public_question->answer_content ? $public_question->answer_content : trim($answer_content),
    '#format' => $public_question->answer_content_format,
    '#rows' => 20,
  );

  $vocab = taxonomy_vocabulary_machine_name_load('vopros_question_subject_catagory');
  $options = array();
  $terms = taxonomy_term_load_multiple(FALSE, array('vid' => $vocab->vid));
  $question_terms = $question_wrapper->subject_catagory->value();
  $question_term_name = '';
  if ($question_terms) {
    $question_term = array_shift($question_terms);
    $question_term_name = $question_term->name;
  }
  foreach ($terms as $term) {
    $options[$term->name] = $term->name;
  }

  field_attach_form('vopros_public_question', $public_question, $form, $form_state);

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
  else {
    $form['update'] = array(
      '#type' => 'submit',
      '#value' => t('Save and update'),
      '#submit' => array('vopros_public_question_form_update_submit'),
    );
  }

  $form_state['public_question'] = $public_question;
  $form_state['question'] = $question;

  return $form;
}

/**
 * Validate handler for vopros_public_question_form()/
 */
function vopros_public_question_form_validate(&$form, &$form_state) {
  $public_question = $form_state['public_question'];
  field_attach_validate('vopros_public_question', $public_question, $form, $form_state);
}

/**
 * Submit handler for vopros_public_question_form().
 * Used for saving a public question.
 */
function vopros_public_question_form_save_submit(&$form, &$form_state) {
  global $user;
  $public_question = $form_state['public_question'];
  $public_question->title = $form_state['values']['title'];
  $public_question->answer_content = $form_state['values']['answer_content']['value'];
  $public_question->answer_content_format = $form_state['values']['answer_content']['format'];
  $public_question->question_content = $form_state['values']['question_content']['value'];
  $public_question->question_content_format = $form_state['values']['question_content']['format'];
  $public_question->uid = $user->uid;
  field_attach_submit('vopros_public_question', $public_question, $form, $form_state);
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
  $public_question->answer_content = $form_state['values']['answer_content']['value'];
  $public_question->answer_content_format = $form_state['values']['answer_content']['format'];
  $public_question->question_content = $form_state['values']['question_content']['value'];
  $public_question->question_content_format = $form_state['values']['question_content']['format'];
  $public_question->uid = $user->uid;
  field_attach_submit('vopros_public_question', $public_question, $form, $form_state);
  vopros_public_question_save($public_question);

  if (vopros_public_question_publish_question($public_question)) {
    drupal_set_message(t('Question has been published !link', array('!link' => l(t('see public question'), 'admin/vopros/public-questions/' . $public_question->public_question_id . '/edit'))));
    $public_question->status = 'published';
    $public_question->question_content = $unformatted_question_content;
    vopros_public_question_save($public_question);
    $form_state['redirect'] = 'admin/vopros/questions/list';
  }
  else {
    drupal_set_message(t('Could not create question at service.'), 'error');
  }
}

/**
 * Submit handler for vopros_public_question_form().
 * Used for saving a public question and updating it on external storage.
 */
function vopros_public_question_form_update_submit(&$form, &$form_state) {
  global $user;
  $public_question = $form_state['public_question'];
  $public_question->title = $form_state['values']['title'];
  $public_question->answer_content = $form_state['values']['answer_content']['value'];
  $public_question->answer_content_format = $form_state['values']['answer_content']['format'];
  $public_question->question_content = $form_state['values']['question_content']['value'];
  $public_question->question_content_format = $form_state['values']['question_content']['format'];
  $public_question->uid = $user->uid;
  field_attach_submit('vopros_public_question', $public_question, $form, $form_state);
  vopros_public_question_save($public_question);
  $public_question_wrapper = entity_metadata_wrapper('vopros_public_question', $public_question);
  $public_question->subject = array();
  foreach ($public_question_wrapper->vopros_public_question_subject->value() as $term) {
    $public_question->subject[] = $term->name;
  }
  $result = osa_addi_create_object($public_question, $public_question->uuid, array(), 'updateObjectRequest');
  if ($result['status'] == 'object_updated') {
    drupal_set_message(t("Question/answer has been saved and made public"));
    $form_state['redirect'] = 'admin/vopros/questions/list';
  }
  elseif ($result['status'] == 'error_fetching_object_record') {
    if (vopros_public_question_publish_question($public_question)) {
      drupal_set_message(t("Question/answer was deleted ans has been recreated"));
    }
    else {
      $form_state['redirect'] = 'admin/vopros/public-questions/' . $public_question->public_question_id . '/edit';
      drupal_set_message(t('Could not update question at service.'), 'error');
    }
  }
  else {
    $form_state['redirect'] = 'admin/vopros/public-questions/' . $public_question->public_question_id . '/edit';
    drupal_set_message(t('Could not update question at service.'), 'error');
  }
}
