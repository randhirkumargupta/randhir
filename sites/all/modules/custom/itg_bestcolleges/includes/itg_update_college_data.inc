<?php

/**
 * @file
 * Used to this module to update college date through Batch API.
 */

/**
 * Form builder function to allow choice of which batch to run.
 */
function update_college_data_form() {
  $form['description'] = array(
    '#type' => 'markup',
    '#markup' => t('This offers two different batches. First one to execute to update college nid in all custom tables and second one to update all associated content with new college nid.'),
  );
  $form['batch'] = array(
    '#type' => 'select',
    '#title' => 'Choose batch',
    '#options' => array(
      'batch_1' => t('batch 1 - Update college nid in custom tables.'),
      'batch_2' => t('batch 2 - Update story, photo and video nid from old to college'),
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  return $form;
}

/**
 * Submit handler.
 * @param array $form
 * @param array $form_state
 */
function batch_example_simple_form_submit($form, &$form_state) {
  $function = 'batch_example_' . $form_state['values']['batch'];
  // Reset counter for debug information.
  //$_SESSION['http_request_count'] = 0;

  // Execute the function named batch_example_batch_1() or
  // batch_example_batch_2().
  $batch = $function();
  batch_set($batch);
}


/**
 * Batch 1 definition: Execute to update college nid in all custom tables.
 */
function batch_example_batch_1() {
  $nids = getCollegeIds();
  $nids_count = count($nids);
  drupal_set_message(t('Creating an array of @num operations', array('@num' => $nids_count)));

  $operations = array();
  /*for ($i = 0; $i < $num_operations; $i++) {
    $operations[] = array(
      'batch_example_op_1',
      array(
        $nid,
        t('(Operation @operation)', array('@operation' => $i)),
      ),
    );
  }*/
  foreach($nids as $nids_value) {
    //$operations[] = array('drupology_associate_audio_tiles_to_song', array($nids_value));
    $operations[] = array(
      'batch_example_op_1',
      array(
        $nids_value,
        t('(Operation @operation)', array('@operation' => $nids_value['old_id'])),
      ),
    );
  }
  $batch = array(
    'operations' => $operations,
    'finished' => 'batch_example_finished',
  );
  return $batch;
}

/**
 * Batch operation for batch 1: load a node.
 *
 * This is the function that is called on each operation in batch 1.
 */
function batch_example_op_1($nids_value, $operation_details, &$context) {
  
  //$node = node_load($nid, NULL, TRUE);
  $context['results'][] = $nids_value['old_id'] . ' : ' . check_plain($nids_value['new_id']);

  // Optional message displayed under the progressbar.
  $context['message'] = t('Loading node "@title"', array('@title' => $node->title)) . ' ' . $operation_details;

  //_batch_example_update_http_requests();
}

/**
 * Batch 2 : Prepare a batch definition that will load all nodes 20 times.
 */
function batch_example_batch_2() {
  $num_operations = 20;

  // Give helpful information about how many nodes are being operated on.
  $node_count = db_query('SELECT COUNT(DISTINCT nid) FROM {node}')->fetchField();
  drupal_set_message(
    t('There are @node_count nodes so each of the @num operations will require @count HTTP requests.',
      array(
        '@node_count' => $node_count,
        '@num' => $num_operations,
        '@count' => ceil($node_count / 5),
      )
    )
  );

  $operations = array();
  // 20 operations, each one loads all nodes.
  for ($i = 0; $i < $num_operations; $i++) {
    $operations[] = array(
      'batch_example_op_2',
      array(t('(Operation @operation)', array('@operation' => $i))),
    );
  }
  $batch = array(
    'operations' => $operations,
    'finished' => 'batch_example_finished',
    // Message displayed while processing the batch. Available placeholders are:
    // @current, @remaining, @total, @percentage, @estimate and @elapsed.
    // These placeholders are replaced with actual values in _batch_process(),
    // using strtr() instead of t(). The values are determined based on the
    // number of operations in the 'operations' array (above), NOT by the number
    // of nodes that will be processed. In this example, there are 20
    // operations, so @total will always be 20, even though there are multiple
    // nodes per operation.
    // Defaults to t('Completed @current of @total.').
    'title' => t('Processing batch 2'),
    'init_message' => t('Batch 2 is starting.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Batch 2 has encountered an error.'),
  );
  return $batch;
}

/**
 * Batch operation for batch 2 : Update all associated content with new college nid
 */
function batch_example_op_2($operation_details, &$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox'] = array();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;

    // Save node count for the termination message.
    $context['sandbox']['max'] = db_query('SELECT COUNT(DISTINCT nid) FROM {node}')->fetchField();
  }
  $limit = 5;

  // Retrieve the next group of nids.
  $result = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->orderBy('n.nid', 'ASC')
    ->where('n.nid > :nid', array(':nid' => $context['sandbox']['current_node']))
    ->extend('PagerDefault')
    ->limit($limit)
    ->execute();
  foreach ($result as $row) {
    // Here we actually perform our dummy 'processing' on the current node.
    $node = node_load($row->nid, NULL, TRUE);

    // Store some results for post-processing in the 'finished' callback.
    // The contents of 'results' will be available as $results in the
    // 'finished' function (in this example, batch_example_finished()).
    $context['results'][] = $node->nid . ' : ' . check_plain($node->title) . ' ' . $operation_details;

    // Update our progress information.
    $context['sandbox']['progress']++;
    $context['sandbox']['current_node'] = $node->nid;
    $context['message'] = check_plain($node->title);
  }

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = ($context['sandbox']['progress'] >= $context['sandbox']['max']);
  }
  _batch_example_update_http_requests();
}

/**
 * Batch 'finished' callback used by both batch 1 and batch 2.
 */
function batch_example_finished($success, $results, $operations) {
  if ($success) {
    // Here we could do something meaningful with the results.
    // We just display the number of nodes we processed...
    //drupal_set_message(t('@count results processed in @requests HTTP requests.', array('@count' => count($results), '@requests' => _batch_example_get_http_requests())));
    drupal_set_message(t('The final result was "%final"', array('%final' => end($results))));
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    drupal_set_message(
      t('An error occurred while processing @operation with arguments : @args',
        array(
          '@operation' => $error_operation[0],
          '@args' => print_r($error_operation[0], TRUE),
        )
      ),
      'error'
    );
  }
}

/**
 * Utility function - simply queries and loads the lowest nid.
 *
 * @return int|NULL
 *   A nid or NULL if there are no nodes.
 */
function batch_example_lowest_nid() {
  $select = db_select('node', 'n')
  ->fields('n', array('nid'))
  ->orderBy('n.nid', 'ASC')
  ->extend('PagerDefault')
  ->limit(1);
  $nid = $select->execute()->fetchField();
  return $nid;
}

/**
 * Utility function to increment HTTP requests in a session variable.
 */
function _batch_example_update_http_requests() {
  $_SESSION['http_request_count']++;
}

/**
 * Utility function to count the HTTP requests in a session variable.
 *
 * @return int
 *   Number of requests.
 */
function _batch_example_get_http_requests() {
  return !empty($_SESSION['http_request_count']) ? $_SESSION['http_request_count'] : 0;
}

/*
 * Get college nid and old id
 */
function getCollegeIds() {
  $itg_query = db_select('node', 'n');
  $itg_query->join('field_data_field_college_id', 'fdf', 'n.nid = fdf.entity_id');
  $itg_query->fields('fdf', array('entity_id', 'field_college_id_value'))
      ->condition('n.status', 1)
      ->orderBy('fdf.field_college_id_value', 'ASC');
  $itg_result = $itg_query->execute()->fetchAll();
  $data = array();
  foreach ($itg_result as $itg_result_val) {
    $data[] = array('old_id' => $itg_result_val->field_college_id_value, 'new_id' => $itg_result_val->entity_id);
  }
  return $data;
}
