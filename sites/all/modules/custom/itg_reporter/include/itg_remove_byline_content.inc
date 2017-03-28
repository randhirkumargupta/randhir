<?php

/**
 * Implement itg_remove_byline_content
 */
function itg_remove_byline_content() {
  $current_time = strtotime(date("Y-m-d H:i:s"));
  $cmp_time = strtotime("-24 hours", $current_time);
  $itg_query = db_select('itg_multi_byline_info', 'u');
  $itg_query->fields('u', array('id'));
  $itg_query->condition('u.nid', 0, '=');
  $itg_query->condition('u.created', $cmp_time, '<');
  $itg_result = $itg_query->execute()->fetchAll();

  foreach ($itg_result as $itg_val) {
    $num_deleted = db_delete('itg_multi_byline_info')
        ->condition('id', $itg_val->id)
        ->condition('nid', 0, '=')
        ->execute();
  }
}
