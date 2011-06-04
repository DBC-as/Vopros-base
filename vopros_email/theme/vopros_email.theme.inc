<?php

/**
 * @file
 */

function template_preprocess_vopros_email(&$variables) {
  $variables['view_mode'] = $variables['elements']['#view_mode'];
  $email = $variables['email'] = $variables['elements']['#email'];

  // Flatten the question object's member fields.
  $variables = array_merge((array) $email, $variables);

  // Helpful $content variable for templates.
  foreach (element_children($variables['elements']) as $key) {
    $variables['content'][$key] = $variables['elements'][$key];
  }

  // Make the field variables available with the appropriate language.
  field_attach_preprocess('email', $email, $variables['content'], $variables);
}

/**
 * Theme function for email subject.
 */
function theme_vopros_email_subject($variables) {
  $email = $variables['email']['#email'];
  $output = '<div class="email-subject vopros-email-extra">';
  $output .= '<span class="label">' . t('Subject:') .  '</span>';
  $output .= '<span class="value">' . check_plain($email->subject) .  '</span>';
  $output .= '</div>';
  return $output;
}

/**
 * Theme function for email content.
 */
function theme_vopros_email_content($variables) {
  $email = $variables['email']['#email'];
  $output = '<div class="email-content vopros-email-extra">';
  $output .= '<span class="label">' . t('Content:') .  '</span>';
  $output .= '<span class="value">' . check_plain($email->email_content) .  '</span>';
  $output .= '</div>';
  return $output;
}

/**
 * Theme function for email email.
 */
function theme_vopros_email_email($variables) {
  $email = $variables['email']['#email'];
  $output = '<div class="email-email vopros-email-extra">';
  $output .= '<span class="label">' . t('Email address:') .  '</span>';
  $output .= '<span class="value">' . check_plain($email->email) .  '</span>';
  $output .= '</div>';
  return $output;
}

/**
 * Theme function for email type.
 */
function theme_vopros_email_type($variables) {
  $email = $variables['email']['#email'];
  $options = _vopros_email_type();
  $value = $options[$email->type] ? $options[$email->type] : check_plain($email->type);
  $output = '<div class="email-type vopros-email-extra">';
  $output .= '<span class="label">' . t('Type of email:') .  '</span>';
  $output .= '<span class="value">' . $value .  '</span>';
  $output .= '</div>';
  return $output;
}

/**
 * Theme function to render an email on the question activity feed.
 */
function theme_vopros_email_question_feed($variables) {
  $email = $variables['email']['#email'];
  if ($email->uid) {
    $sender = theme('username', array('account' => user_load($email->uid)));
    $receiver = check_plain($email->email);
  }
  else {
    $sender = check_plain($email->email);
    $receiver = variable_get('site_name', 'Drupal');
  }
  $date = format_date($email->created, 'short');
  
  $output = '<div class="email-feed-item feed-item">';
  $output .= '<div class="email-header">';
  $output .= '<div class="email-from"><span class="label">' . t('From:') . '</span><span class="data">' . $sender . '</span></div>';
  $output .= '<div class="email-to"><span class="label">' . t('To:') . '</span><span class="data">' . $receiver . '</span></div>';
  $output .= '<div class="email-date"><span class="label">' . t('Sent:') . '</span><span class="data">' . $date . '</span></div>';
  $output .= '</div>';
  $output .= '<div class="email-content">';
  $output .= str_replace("\n", '<br />', check_plain($email->email_content));
  $output .= '</div>';
  $output .= '</div>';
  return $output;
}
