<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function vopros_qna_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function vopros_qna_node_info() {
  $items = array(
    'vopros_answer' => array(
      'name' => t('Svar'),
      'module' => 'features',
      'description' => t('Svar to a Vopros spørgsmål, som regel skrevet af en medarbejder.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'has_body' => '1',
      'body_label' => t('Svar'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'vopros_question' => array(
      'name' => t('Spørgsmål'),
      'module' => 'features',
      'description' => t('Et spørgsmål fra en bruger.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'has_body' => '1',
      'body_label' => t('Spørgsmål'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_rules_defaults().
 */
function vopros_qna_rules_defaults() {
  return array(
    'rules' => array(
      'vopros_qna_1' => array(
        '#type' => 'rule',
        '#set' => 'event_node_insert',
        '#label' => 'Redirect user when asking a question',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'vopros_qna',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Created content is Spørgsmål',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'vopros_question' => 'vopros_question',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
          '1' => array(
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
            '#name' => 'rules_condition_content_is_published',
            '#info' => array(
              'label' => 'Created content is published',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
            '#negate' => 1,
          ),
        ),
        '#actions' => array(
          '1' => array(
            '#type' => 'action',
            '#settings' => array(
              'message' => 'Tak for dit spørgsmål. Du vil modtage en e-mail når det bliver besvaret.',
              'error' => 0,
            ),
            '#name' => 'rules_action_drupal_message',
            '#info' => array(
              'label' => 'Confirm the question to be received.',
              'label callback' => FALSE,
              'module' => 'System',
              'eval input' => array(
                '0' => 'message',
              ),
            ),
            '#weight' => -7,
          ),
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Redirect to front page',
              'label callback' => FALSE,
              'module' => 'System',
              'eval input' => array(
                '0' => 'path',
                '1' => 'query',
                '2' => 'fragment',
              ),
            ),
            '#name' => 'rules_action_drupal_goto',
            '#settings' => array(
              'path' => '<front>',
              'query' => '',
              'fragment' => '',
              'force' => 1,
              'immediate' => 0,
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'vopros_qna_2' => array(
        '#type' => 'rule',
        '#set' => 'event_node_insert',
        '#label' => 'Send e-mail notification when question is answered',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'vopros_qna',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Created content is Svar',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'vopros_answer' => 'vopros_answer',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
          '1' => array(
            '#type' => 'condition',
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_published',
            '#info' => array(
              'label' => 'Created content is published',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => -10,
            '#info' => array(
              'label' => 'Load the referenced answer',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content containing the node reference field',
                ),
              ),
              'new variables' => array(
                'referenced_answer' => array(
                  'label' => 'referenced answer',
                  'label callback' => FALSE,
                  'type' => 'node',
                ),
              ),
              'module' => 'CCK',
            ),
            '#name' => 'nodereference_rules_action_load',
            '#settings' => array(
              'field' => 'field_answer_question_ref',
              '#argument map' => array(
                'node' => 'node',
                'referenced_node' => 'referenced_answer',
              ),
            ),
            '#type' => 'action',
          ),
          '2' => array(
            '#type' => 'action',
            '#settings' => array(
              'message' => 'Din besvarelse af [referenced_answer:title] er registreret og vi har sendt en e-mail til [referenced_answer:field_question_inquirer_name-formatted] for at lade ham/hende vide at spørgsmålet er besvaret.',
              'error' => 0,
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => 'referenced_answer',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_drupal_message',
            '#info' => array(
              'label' => 'Show a configurable message on the site',
              'module' => 'System',
              'eval input' => array(
                '0' => 'message',
              ),
            ),
            '#weight' => 5,
          ),
          '1' => array(
            '#type' => 'action',
            '#settings' => array(
              'to' => '[referenced_answer:field_question_inquirer_mail-raw]',
              'from' => '',
              'subject' => '“[referenced_answer:title]” er blevet besvaret',
              'message' => 'Hej [referenced_answer:field_question_inquirer_name-formatted],

Dit spørgsmål “[referenced_answer:title]” er blevet besvaret af [author:user]

Klik ind på [node:node-url] for at se dit svar.

--
Med venlig hilsen,
[referenced_answer:field_question_service-formatted]

Dette er en automatisk påmindelse, og kan ikke besvares.',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'subject' => array(
                    '0' => 'referenced_answer',
                  ),
                  'message' => array(
                    '0' => 'referenced_answer',
                    '1' => 'node',
                    '2' => 'author',
                  ),
                  'to' => array(
                    '0' => 'referenced_answer',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_mail',
            '#info' => array(
              'label' => 'Send an e-mail to the user who asked the question',
              'label callback' => FALSE,
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
                '3' => 'to',
              ),
            ),
            '#weight' => 10,
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}

/**
 * Implementation of hook_views_api().
 */
function vopros_qna_views_api() {
  return array(
    'api' => '2',
  );
}
