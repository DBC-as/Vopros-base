<?php

class vopros_base_taxonomy_tid_filter_handler extends views_handler_filter_numeric {
  function value_form(&$form, &$form_state) {
    $field = field_info_field($this->definition['field_name']);
    if (!empty($field['settings']['allowed_values'])) {
      $options = array();
      foreach ($field['settings']['allowed_values'] as $value) {
        if (isset($value['vocabulary'])) {
          $vocab = taxonomy_vocabulary_machine_name_load($value['vocabulary']);
          $terms = taxonomy_term_load_multiple(array(), array('vid' => $vocab->vid));
          foreach ($terms as $tid => $term) {
            $options[$tid] = $term->name;
          }
        }
      }
      if (!empty($options)) {
        $options = array('' => t('All')) + $options;
      }
      $form['value']['#tree'] = TRUE;
      $form['value']['value'] = array(
        '#type' => 'select',
        '#title' => empty($form_state['exposed']) ? t('Value') : '',
        '#options' => $options,
        '#default_value' => $this->value['value'],
        '#multiple' => FALSE, //$this->options['expose']['multiple'],
      );
    }
    if (!isset($form['value'])) {
      parent::value_form($form, $form_state);
    }
  }
}
