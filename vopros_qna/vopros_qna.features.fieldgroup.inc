<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function vopros_qna_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_question_inquirer
  $groups['vopros_question-group_question_inquirer'] = array(
    'group_type' => 'standard',
    'type_name' => 'vopros_question',
    'group_name' => 'group_question_inquirer',
    'label' => 'Spørgerens data',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_collapsible',
        'description' => 'Skriv lidt om dig selv, så vi ved hvem vi skal kontakte med et svar eller hvis vi har brug for flere oplysninger. Bliver ikke offentliggjort.',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '37',
    'fields' => array(
      '0' => 'field_question_inquirer_name',
      '1' => 'field_question_inquirer_mail',
      '2' => 'field_question_inquirer_postcode',
      '3' => 'field_question_inquirer_phone',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Spørgerens data');

  return $groups;
}
