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

/**
 * Display count of created questions devided by the time it was created
 */
function vopros_statistics_week_view($start = NULL, $end = NULL) {
  if (!$end) {
    $end = REQUEST_TIME;
  }
  if (!$start) {
    $start = REQUEST_TIME - 86400 * 7;
  }

  $result = db_query("SELECT DAYNAME(FROM_UNIXTIME(q.created)) AS day_name, COUNT(*) AS questions FROM {vopros_question} AS q
            WHERE created < :end
            AND created > :start
            GROUP BY day_name", array(':end' => $end, ':start' => $start))->fetchAllKeyed(0, 1);


  $header = array(t('Week day'), t('Total questions created'));
  $rows = array();
  // Create a unix timestamp for a random date that has the time 00:00:00.
  $weeks = array(
    'Monday' => t('Monday'),
    'Tuesday' => t('Tuesday'),
    'Wednesday' => t('Wednesday'),
    'Thursday' => t('Thursday'),
    'Friday' => t('Friday'),
    'Saturday' => t('Saturday'),
    'Sunday' => t('Sunday'),
  );

  // Create the total count
  foreach ($weeks as $week_day => $label) {
    $rows[$week_day] = array($label, isset($result[$week_day]) ? $result[$week_day] : 0);
  }

  // Get statistics for each editorial.
  if (module_exists('vopros_editorial')) {
    $vocab = taxonomy_vocabulary_machine_name_load('vopros_editorial');
    $terms = taxonomy_term_load_multiple(FALSE, array('vid' => $vocab->vid));
    foreach ($terms as $tid => $term) {
      $header[] = $term->name;
      $result = db_query("SELECT DAYNAME(FROM_UNIXTIME(q.created)) AS day_name, COUNT(*) AS questions FROM {vopros_question} AS q
                                              INNER JOIN {field_data_vopros_editorial} AS f ON f.entity_id = q.question_id
                                              WHERE q.created < :end
                                              AND q.created > :start
                                              AND f.vopros_editorial_tid = :tid
                                              GROUP BY day_name", array(':tid' => $tid, ':end' => $end, ':start' => $start))->fetchAllKeyed(0, 1);
      foreach ($weeks as $week_day => $label) {
        $rows[$week_day][] = isset($result[$week_day]) ? $result[$week_day] : 0;
      }
    }
  }

  $build = array(
    'form' => drupal_get_form('vopros_statistics_week_form', $start, $end),
    'table' => array(
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows,
    ),
  );
  return $build;
}

/**
 * Form for selecting the date range for the time statistics page.
 */
function vopros_statistics_week_form($form, &$form_state, $start, $end) {
  $form['start'] = array(
    '#type' => 'date_popup',
    '#title' => t('Start for time range'),
    '#date_format' => 'd-m-Y',
    '#date_year_range' => '-10:+1',
    '#default_value' => date('Y-m-d', $start),
    '#required' => TRUE,
  );

  $form['end'] = array(
    '#type' => 'date_popup',
    '#title' => t('End for time range'),
    '#date_format' => 'd-m-Y',
    '#date_year_range' => '-10:+1',
    '#default_value' => date('Y-m-d', $end),
    '#required' => TRUE,
  );

  $form['get'] = array(
    '#type' => 'submit',
    '#value' => t('Get statistics'),
  );

  return $form;
}

/**
 * Submit handler for vopros_statistics_time_form()
 */
function vopros_statistics_week_form_submit($form, &$form_state) {
  $start = strtotime($form_state['values']['start']);
  $end = strtotime($form_state['values']['end']);
  $form_state['redirect'] = "admin/vopros/statistics/week/$start/$end";
}

/**
 * Display count of created questions devided by the time it was created
 */
function vopros_statistics_time_view($start = NULL, $end = NULL) {
  if (!$end) {
    $end = REQUEST_TIME;
  }
  if (!$start) {
    $start = REQUEST_TIME - 86400 * 7;
  }

  $result = db_query("SELECT HOUR(FROM_UNIXTIME(q.created)) AS created_hour, COUNT(*) AS questions FROM {vopros_question} AS q
            WHERE created < :end
            AND created > :start
            GROUP BY created_hour
            ORDER BY created_hour", array(':end' => $end, ':start' => $start))->fetchAllKeyed(0, 1);


  $header = array(t('Time'), t('Questions created'));
  $rows = array();
  // Create a unix timestamp for a random date that has the time 00:00:00.
  $start_time = strtotime('2000-12-12 00:00:00');
  foreach (range(0, 23) as $time) {
    $count = isset($result[$time]) ? $result[$time] : 0;
    $rows[$time] = array(date('H:i:s', $start_time + $time*3600) . ' - ' . date('H:i:s', $start_time + $time*3600 + 3599), $count);
  }

  if (module_exists('vopros_editorial')) {
    $vocab = taxonomy_vocabulary_machine_name_load('vopros_editorial');
    $terms = taxonomy_term_load_multiple(FALSE, array('vid' => $vocab->vid));
    foreach ($terms as $tid => $term) {
      $header[] = $term->name;
      $result = db_query("SELECT HOUR(FROM_UNIXTIME(q.created)) AS created_hour, COUNT(*) AS questions FROM {vopros_question} AS q
                          INNER JOIN {field_data_vopros_editorial} AS f ON f.entity_id = q.question_id
                          WHERE created < :end
                          AND created > :start
                          AND f.vopros_editorial_tid = :tid
                          GROUP BY created_hour
                          ORDER BY created_hour", array(':end' => $end, ':start' => $start, ':tid' => $tid))->fetchAllKeyed(0, 1);
      foreach (range(0, 23) as $time) {
        $rows[$time][] = isset($result[$time]) ? $result[$time] : 0;
      }
    }
  }

  $build = array(
    'form' => drupal_get_form('vopros_statistics_time_form', $start, $end),
    'table' => array(
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows,
    ),
  );
  return $build;
}

/**
 * Form for selecting the date range for the time statistics page.
 */
function vopros_statistics_time_form($form, &$form_state, $start, $end) {
  $form['start'] = array(
    '#type' => 'date_popup',
    '#title' => t('Start for time range'),
    '#date_format' => 'd-m-Y',
    '#date_year_range' => '-10:+1',
    '#default_value' => date('Y-m-d', $start),
    '#required' => TRUE,
  );

  $form['end'] = array(
    '#type' => 'date_popup',
    '#title' => t('End for time range'),
    '#date_format' => 'd-m-Y',
    '#date_year_range' => '-10:+1',
    '#default_value' => date('Y-m-d', $end),
    '#required' => TRUE,
  );

  $form['get'] = array(
    '#type' => 'submit',
    '#value' => t('Get statistics'),
  );

  return $form;
}

/**
 * Submit handler for vopros_statistics_time_form()
 */
function vopros_statistics_time_form_submit($form, &$form_state) {
  $start = strtotime($form_state['values']['start']);
  $end = strtotime($form_state['values']['end']);
  $form_state['redirect'] = "admin/vopros/statistics/time/$start/$end";
}

/**
 * Display statistics based on Q and A service names.
 */
function vopros_statistics_qanda_service_name_view($start = NULL, $end = NULL) {
  if (!$end) {
    $end = REQUEST_TIME;
  }
  if (!$start) {
    $start = REQUEST_TIME - 86400 * 7;
  }
  $qanda_service_names = _vopros_question_qanda_serice_options();

  // Get the total questions for each Q and A service name.
  $total_count = db_query("SELECT COUNT(*), qanda_service_name FROM {vopros_question}
                           WHERE created < :end
                           AND created > :start
                           GROUP BY qanda_service_name", array(':end' => $end, ':start' => $start))->fetchAllKeyed(1, 0);

  $header = array(t('Q and A service name'), t('Total questions'));

  // If we have editorial, get it for each editorial as well.
  if (module_exists('vopros_editorial')) {
    $vocab = taxonomy_vocabulary_machine_name_load('vopros_editorial');
    $terms = taxonomy_term_load_multiple(FALSE, array('vid' => $vocab->vid));
    $editorials = array();
    foreach ($terms as $tid => $term) {
      $header[] = $term->name;
      $editorials[$tid] = db_query("SELECT COUNT(*) as questions, q.qanda_service_name FROM {field_data_vopros_editorial} AS f
                              INNER JOIN vopros_question AS q ON q.question_id = f.entity_id
                              WHERE f.vopros_editorial_tid = :tid
                              AND created < :end
                              AND created > :start
                              GROUP BY q.qanda_service_name", array(':tid' => $tid, ':end' => $end, ':start' => $start))->fetchAllKeyed(1, 0);
    }
  }
  $rows = array();
  foreach ($qanda_service_names as $key => $label) {
    $row = array(
      $label,
      isset($total_count[$key]) ? $total_count[$key] : 0,
    );
    if (!empty($terms)) {
      foreach ($terms as $tid => $term) {
        if (isset($editorials[$tid][$key])) {
          $row[] = $editorials[$tid][$key];
        }
        else {
          $row[] = 0;
        }
      }
    }
    $rows[] = $row;
  }
  $build = array(
    'form' => drupal_get_form('vopros_statistics_qanda_service_name_form', $start, $end),
    'table' => array(
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows,
    ),
  );
  return $build;
}

/**
 * Form for selecting the date range for the time statistics page.
 */
function vopros_statistics_qanda_service_name_form($form, &$form_state, $start, $end) {
  $form['start'] = array(
    '#type' => 'date_popup',
    '#title' => t('Start for time range'),
    '#date_format' => 'd-m-Y',
    '#date_year_range' => '-10:+1',
    '#default_value' => date('Y-m-d', $start),
    '#required' => TRUE,
  );

  $form['end'] = array(
    '#type' => 'date_popup',
    '#title' => t('End for time range'),
    '#date_format' => 'd-m-Y',
    '#date_year_range' => '-10:+1',
    '#default_value' => date('Y-m-d', $end),
    '#required' => TRUE,
  );

  $form['get'] = array(
    '#type' => 'submit',
    '#value' => t('Get statistics'),
  );

  return $form;
}

/**
 * Submit handler for vopros_statistics_time_form()
 */
function vopros_statistics_qanda_service_name_form_submit($form, &$form_state) {
  $start = strtotime($form_state['values']['start']);
  $end = strtotime($form_state['values']['end']);
  $form_state['redirect'] = "admin/vopros/statistics/qanda_service_name/$start/$end";
}
