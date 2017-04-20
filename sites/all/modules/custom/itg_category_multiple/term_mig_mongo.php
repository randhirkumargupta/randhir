<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments();

migrate_all_terms_in_mongo();

function migrate_all_terms_in_mongo() {

print "Start....";
  $query = db_select('taxonomy_term_data', 'td');
  $query->leftJoin('taxonomy_term_hierarchy', 'th', 'th.tid = td.tid');
  $query->leftJoin('itg_category_manager', 'icm', 'icm.tid = td.tid');
  $query->leftJoin('taxonomy_vocabulary', 'tv', 'tv.vid=td.vid');
  $result = $query
      ->condition('td.vid', CATEGORY_MANAGMENT)
      ->fields('td', array('tid', 'name', 'vid'))
      ->fields('th', array('parent'))
      ->fields('tv', array('machine_name'))
      ->fields('icm', array('status'))
      ->execute();
  
  foreach($result as $data){
    if (function_exists('mongodb')) {
    $con = mongodb();
    $people = $con->taxonomy_term_data_mongo;

    // check connection
    if ($con) {
      $qry = array(
        "tid" => (int) $data->tid,
        "name" => $data->name,
        "parent" => (int) $data->parent,
        "vid" => (int) $data->vid,
        "machine_name" => $data->machine_name,
        "content_type" => get_content_type_list_for_this_term_mig($data->tid),
        "status" => (int) $data->status,
        'parent_data' => taxonomy_get_parents_all($data->tid),
      );
      $result = $people->insert($qry);
    }
   drupal_set_message('data inserted successfully for ' . $data->tid);
  }
  }
}
