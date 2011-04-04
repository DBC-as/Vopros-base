<?php

/**
 * @ file
 * Admin forms and callback functions.
 */

/**
 * Question settings form
 */
function vopros_question_settings_form($form, &$form_state) {
  return system_settings_form($form);
}

/**
 * Form to edit or create a question
 */
function vopros_question_question_form($form, &$form_state, $question) {
  // Add the field related form elements.
  $form_state['vopros_question'] = $question;
  field_attach_form('vopros_question', $question, $form, $form_state);
  
  $form['question_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#required' => TRUE,
    '#default_value' => isset($question->question_title) ? $question->question_title : '',
    '#weight' => -12,
  );

  $form['question_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Question content'),
    '#required' => TRUE,
    '#default_value' => isset($question->question_content) ? $question->question_content : '',
    '#weight' => -11,
  );

  $form['question_status'] = array(
    '#type' => 'select',
    '#title' => t('Status'),
    '#options' => _vopros_question_status(),
    '#default_value' => isset($question->question_status) ? $question->question_status : '',
    '#weight' => -10,
  );

  $form['question_usage'] = array(
    '#type' => 'select',
    '#title' => t('Usage'),
    '#options' => _vopros_question_usage(),
    '#default_value' => isset($question->question_usage) ? $question->question_usage : '',
  );

  $form['question_note'] = array(
    '#type' => 'textarea',
    '#title' => t('Note about the question'),
    '#default_value' => isset($question->question_note) ? $question->question_note : '',
  );

  $form['ask'] = array(
    '#type' => 'fieldset',
    '#title' => t('Info about person who asked the question'),
    '#collapsible' => TRUE,
  );
  

  $form['ask']['user_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => isset($question->user_name) ? $question->user_name : '',
    '#required' => TRUE,
  );

  $form['ask']['user_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#default_value' => isset($question->user_email) ? $question->user_email : '',
  );

  $form['ask']['user_postal_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Postal code'),
    '#default_value' => isset($question->user_postal_code) ? $question->user_postal_code : '',
    '#required' => TRUE,
  );

  $form['ask']['user_mobile_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile phone'),
    '#default_value' => isset($question->user_mobile_phone) ? $question->user_mobile_phone : '',
  );

  $form['ask']['user_age'] = array(
    '#type' => 'textfield',
    '#title' => t('Age'),
    '#default_value' => isset($question->user_age) ? $question->user_age : '',
  );

  $form['ask']['user_gender'] = array(
    '#type' => 'select',
    '#title' => t('Gender'),
    '#options' => array(
      'male' => t('Male'),
      'female' => t('Female'),
    ),
    '#default_value' => isset($question->user_gender) ? $question->user_gender : '',
  );

  $form['ask']['user_field_of_study'] = array(
    '#type' => 'textfield',
    '#title' => t('Field of study'),
    '#default_value' => isset($question->user_field_of_study) ? $question->user_field_of_study : '',
  );

  $form['ask']['user_library'] = array(
    '#type' => 'textfield',
    '#title' => t('Library'),
    '#default_value' => isset($question->user_library) ? $question->user_library : '',
  );

  $form['ask']['user_answer_preference'] = array(
    '#type' => 'select',
    '#title' => t('How to recieve answer'),
    '#options' => array(
      'mail' => t('Email'),
      'sms' => t('SMS'),
    ),
    '#default_value' => isset($question->user_answer_preference) ? $question->user_answer_preference : '',
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 100,
  );

  return $form;
}

/**
 * Validate handler for vopros_question_question_form().
 */
function vopros_question_question_form_validate(&$form, &$form_state) {
  
}

/**
 * Submit handler for vopros_question_question_form().
 */
function vopros_question_question_form_submit(&$form, &$form_state) {
  $question = &$form_state['vopros_question'];

  $info = entity_get_property_info('vopros_question');

  foreach ($info['properties'] as $key => $property) {
    if (isset($form_state['values'][$key])) {
      $question->{$key} = $form_state['values'][$key];
    }
  }

  // Notify field widgets.
  field_attach_submit('commerce_product', $question, $form, $form_state);

  // Save the product.
  vopros_question_save($question);
}

/**
 * Ajax form for changing the title with ajax.
 */
function vopros_question_title_form($form, &$form_state, $question) {
  $form['title'] = array(
    '#type' => 'textfield',
    '#default_value' => $question->question_title,
  );

  $form['question'] = array(
    '#type' => 'value',
    '#value' => $question,
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#ajax' => array(
      'callback' => 'vopros_question_title_form_save',
    ),
  );

  $form['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#ajax' => array(
      'callback' => 'vopros_question_title_form_cancel',
    ),
  );

  return $form;
}

/**
 * Handle the display of a question
 */
function vopros_question_page_view($question) {
  drupal_add_js(drupal_get_path('module', 'vopros_question') . '/media/vopros_question_title.js');
  drupal_add_css(drupal_get_path('module', 'vopros_question') . '/media/vopros_question_title.css');
  drupal_add_js(array('vopros_quesiton_id' => $question->question_id), 'setting');
  return '<div class="hidden title-form">' . drupal_render(drupal_get_form('vopros_question_title_form', $question)) . '</div>' . vopros_embed_view('vopros_question_admin', 'default', array($question->question_id));
}

/**
 * AJAX callback saving title
 */
function vopros_question_title_form_save(&$form, &$form_state) {
  // Save the question.
  $question = $form_state['values']['question'];
  $question->question_title = $form_state['values']['title'];
  vopros_question_save($question);
  // Send back ajax commands.
  $commands = array();
  $commands[] = ajax_command_invoke('#vopros-question-title-form', 'appendTo', array('.title-form'));
  $commands[] = ajax_command_invoke('.views-field-question-title .field-content', 'show', array());
  $commands[] = ajax_command_invoke('.views-field-question-title .field-content', 'text', array($form_state['values']['title']));
  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * AJAX callback cancel
 */
function vopros_question_title_form_cancel(&$form, &$form_state) {
  $commands = array();
  $commands[] = ajax_command_invoke('#edit-title', 'attr', array('value', $form['title']['#default_value']));
  $commands[] = ajax_command_invoke('#vopros-question-title-form', 'appendTo', array('.title-form'));
  $commands[] = ajax_command_invoke('.views-field-question-title .field-content', 'show');
  return array('#type' => 'ajax', '#commands' => $commands);
}
