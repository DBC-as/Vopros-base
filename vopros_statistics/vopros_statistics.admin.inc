<?php

/**
 * Display statistics for a year
 */
function vopros_statistics_year_view($year = NULL) {
  if (empty($year)) {
    $year = date('Y', REQUEST_TIME);
  }

  // Generate all of the weeks.
  $dates = array();
  foreach (range(1,52) as $week_num) {
    $week_num_date = $week_num;
    if ($week_num < 10) {
      $week_num_date = '0' . (string) $week_num_date;
    }

    $dates[$week_num] = array(
      ':start' => strtotime($year . 'W' . $week_num_date . '1'),
      ':end' => strtotime($year . 'W' . $week_num_date . '7'),
    );

    if ($dates[$week_num][':end'] > REQUEST_TIME) {
      break;
    }
  }

  $header = array(t('Week number'), t('Total questions'));
  if (module_exists('vopros_editorial')) {
    $vocab = taxonomy_vocabulary_machine_name_load('vopros_editorial');
    $terms = taxonomy_term_load_multiple(FALSE, array('vid' => $vocab->vid));
    foreach ($terms as $term) {
      $header[] = $term->name;
    }
  }
  $rows = array();

  foreach ($dates as $week => $where) {
    $question_ids = db_query("SELECT question_id FROM {vopros_question} WHERE created >= :start AND created <= :end", $where)->fetchAllKeyed(0,0);
    $row = array(
      $week,
      count($question_ids),
    );
    $question_ids[] = 0;
    if (!empty($terms)) {
      $editorials = db_query("SELECT COUNT(*), vopros_editorial_tid FROM field_data_vopros_editorial
                              WHERE entity_id IN (:question_ids) GROUP BY vopros_editorial_tid", array(':question_ids' => $question_ids))->fetchAllKeyed(1, 0);
      foreach ($terms as $tid => $term) {
        $row[] = $editorials[$tid];
      }
    }

    $rows[] = $row;
  }

  return theme('table', array('header' => $header, 'rows' => $rows));
}
