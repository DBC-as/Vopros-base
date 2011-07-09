<?php

/**
 * @file Public menu callbacks and forms.
 */

function vopros_feedback_public_feedback_page($email) {
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

  module_load_include('inc', 'vopros_feedback', 'includes/vopros_feedback.admin');
  return drupal_get_form('vopros_feedback_form', $feedback);
}
