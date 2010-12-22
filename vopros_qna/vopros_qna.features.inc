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
