<?php
/**
 * Implements itg_get_tag()
 * @param string $title
 */
function itg_get_tag($title) {

  if (strlen(trim($title)) > 0) {
    $vocab_id = arg(1);
    $prefill_tag = explode(',', $title);
    // Fetch last
    $last_string = trim(array_pop($prefill_tag));
    $options = array();
    $title = strtolower(trim($title));
    $query = db_select('taxonomy_term_data', 'tn');
    $query->fields('tn', array('name', 'tid'));
    $query->condition('name', '%' . $last_string . '%', 'LIKE');
    $query->condition('vid', $vocab_id, '=');
    $query->range(0, 20);

    $result = $query->execute();
    $prefix = count($prefill_tag) ? implode(', ', $prefill_tag) . ', ' : '';
    while ($record = $result->fetchAssoc()) {
      $options[$prefix . $record['name']] = $record['name'];
    }
    drupal_json_output($options);
  }
}

/**
 * Implement itg_get_twitter_list
 * @param string $name
 */
function itg_get_twitter_list($name) {
  $term_array = taxonomy_get_term_by_name('reporter');
  $term = reset($term_array); # get the first element of the array which is our term object

  $reporter_name = db_select('node', 'n');
  $reporter_name->join('field_data_field_celebrity_pro_occupation', 'rpn', 'n.nid = rpn.entity_id');
  $reporter_name->join('field_data_field_reporter_twitter_handle', 'tw', 'n.nid = tw.entity_id');
  $reporter_name->fields('tw', array('field_reporter_twitter_handle_value'));
  $reporter_name->condition('field_celebrity_pro_occupation_tid', $term->tid, '=');
  $reporter_name->condition('n.type', 'reporter', '=');
  $reporter_name->condition('tw.field_reporter_twitter_handle_value', '%' . $name . '%', 'LIKE');
  $result = $reporter_name->execute();

  while ($record = $result->fetchAssoc()) {
    $r_title = strtolower($record['field_reporter_twitter_handle_value']);
    $options[$r_title] = $r_title;
  }
  drupal_json_output($options);
}


/*
 * Implements _custom_solr_index_node().
 */
function _custom_solr_index_node() {
  $arg = arg();
  if($arg[0] == 'custom-index-solr-node' && !empty($arg[1])) {
    $node = node_load($arg[1]);
    if(!empty($node)) {
     _custom_helper_apachesolr_index_immediately($node, 'node'); 
    }
  }
}

/**
 * Administrative settings.
 *
 * @return array
 *   An array containing form items to place on the module settings page.
 */
function solr_hash_url_form() {
  $form['hash_url_config'] = array(
    '#type' => 'textarea',
    '#title' => t('Hash url config'),
    '#attributes' => array('placeholder' => t('Ex: 9m4hke|http://uat-it.indiatodayonline.in')),
    '#default_value' => variable_get('hash_url_config'),
  );
  return system_settings_form($form);
}