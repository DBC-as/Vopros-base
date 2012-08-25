<?php
/**
 * @file
 * vopros_answer.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function vopros_answer_default_rules_configuration() {
  $items = array();
  $items['rules_vopros_question_list_cache_reset'] = entity_import('rules_config', '{ "rules_vopros_question_list_cache_reset" : {
      "LABEL" : "Question list cache reset",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "vopros_question" ],
      "REQUIRES" : [ "cache_actions", "entity" ],
      "ON" : [
        "vopros_question_insert",
        "vopros_question_delete",
        "vopros_question_update"
      ],
      "DO" : [
        { "cache_actions_action_clear_views_cache" : { "view" : { "value" : { "vopros_question_own_questions" : "vopros_question_own_questions" } } } }
      ]
    }
  }');
  return $items;
}
