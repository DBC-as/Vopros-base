<?php

/**
 * @file Public menu callbacks and forms.
 */

function vopros_feedback_public_feedback_page($email) {
  global $vopros_feedback_hide_regions;
  // Notify to alter this page and hide regions.
  $vopros_feedback_hide_regions = TRUE;
  // Some styles needed to hide header and footer.
  drupal_add_css(drupal_get_path('module', 'vopros_feedback') . '/theme/vopros_feedback.base.css');
  drupal_add_css(drupal_get_path('module', 'vopros_feedback') . '/theme/vopros_feedback.theme.css');
  // Hide the breadbrumb.
  drupal_set_breadcrumb('');
  $conditions = array(
    'question_id' => $email->question_id,
    'email_id' => $email->email_id,
  );
  $feedbacks = vopros_feedback_load_multiple(FALSE, $conditions);
  if (count($feedbacks)) {
    $feedback = array_shift($feedbacks);
  }
  else {
    $feedback = vopros_feedback_new($conditions);
  }

  $show_form = FALSE;
  if (!empty($_GET['show-form'])) {
    $show_form = TRUE;
  }

  return drupal_get_form('vopros_feedback_public_form', $feedback, $show_form);
}

/**
 * Form for creating and editing vopros_feedback entities.
 */
function vopros_feedback_public_form($form, &$form_state, $feedback, $show_form = FALSE) {
  if (!$feedback->created || $show_form) {
    $form['feedback_content'] = array(
      '#type' => 'textarea',
      '#title' => t('Feedback'),
      '#default_value' => $feedback->feedback_content,
    );

    $form['save'] = array(
      '#type' => 'submit',
      '#value' => t('Save feedback'),
      '#weight' => 100,
    );

    if (!$feedback->created) {
      $form['save']['#value'] = t('Give feedback');
    }
    field_attach_form('vopros_feedback', $feedback, $form, $form_state);
  }

  else {
    if ($text = variable_get('vopros_feedback_intro_text', '')) {
      $form['intro'] = array(
        '#prefix' => '<p class="intro-text">',
        '#suffix' => '</p>',
        '#markup' => check_plain(variable_get('vopros_feedback_intro_text', '')),
      );
    }

    $form[] = $feedback->view();
    $form['edit'] = array(
      '#type' => 'submit',
      '#value' => t('Edit feedback'),
      '#weight' => 100,
      '#submit' => array('vopros_feedback_public_form_get_form_submit')
    );
  }

  $form_state['feedback'] = $feedback;

  return $form;
}

/**
 * Validate handler for vopros_feedback_form().
 */
function vopros_feedback_public_form_validate(&$form, &$form_state) {
  $feedback = $form_state['feedback'];
  field_attach_validate('vopros_feedback', $feedback, $form, $form_state);
}

/**
 * Submit handler for vopros_feedback_form().
 */
function vopros_feedback_public_form_submit(&$form, &$form_state) {
  $feedback = $form_state['feedback'];
  field_attach_submit('vopros_feedback', $feedback, $form, $form_state);
  $feedback->feedback_content = $form_state['values']['feedback_content'];
  $feedback->uid = $GLOBALS['user']->uid;
  vopros_feedback_save($feedback);
  $form_state['redirect'] = 'vopros/feedback/' . $feedback->email_id . '/' . md5($feedback->email_id . variable_get('vopros_feedback_secret', ''));
  drupal_set_message(t('Your feedback has been received. Thank you.'));
}

/**
 * Submit handler for vopros_feedback_form().
 */
function vopros_feedback_public_form_get_form_submit($form, &$form_state) {
  $feedback = $form_state['feedback'];
  $form_state['redirect'] = array(
    'vopros/feedback/' . $feedback->email_id . '/' . md5($feedback->email_id . variable_get('vopros_feedback_secret', '')),
    array('query' => array('show-form' => 'true')),
  );
}
