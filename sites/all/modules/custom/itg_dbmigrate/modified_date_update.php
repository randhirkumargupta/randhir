<?php

set_time_limit(0);
//ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

custom_modified_date_update();

/**
 * story content ordering
 */
function custom_modified_date_update() {
 $query = db_select('itg_node_update_updation', 'ud');
 $query = $query->fields('ud');
 $query = $query->condition('Flag', 0, '=');
 //$query = $query->range(0, 10);
 //$query = $query->orderby('ud.nid');
 $result = $query->execute()->fetchAll();
//p($result);
 foreach($result as $res) {
    $vid = '';
    $vid = current_version_id($res->nid);
    if(!empty($vid)) {
    custom_node_modified_date_udpate($res->nid, $res->timestamp);
    db_update('itg_node_update_updation')
          ->fields(array(
              'Flag' => 1,
          ))
          ->condition('nid', $res->nid, '=')
          ->execute();
   drush_print($res->nid);
   //p($res->nid);
  }
 }
}


/**
 * Implement function for node modified data update in node and revision table.
 */
function custom_node_modified_date_udpate($nid, $timestamp) {
    $vid = current_version_id($nid);
    // node table update
    db_update('node')
          ->fields(array(
              'changed' => $timestamp,
          ))
          ->condition('nid', $nid, '=')
          ->execute();
    // node revision table update
    db_update('node_revision')
          ->fields(array(
              'timestamp' => $timestamp,
          ))
          ->condition('nid', $nid, '=')
          ->condition('vid', $vid, '=')
          ->execute();
}
/**
 * Get node current vid
 */
function current_version_id($nid) {
    $query = db_select('node', 'n');
    $query->fields('n', array('vid'));
    $query->condition('nid', $nid, '=');
    $vid = $query->execute()->fetchCol();
    return $vid;
}
?>

