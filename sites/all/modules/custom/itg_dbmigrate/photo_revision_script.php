<?php

//15369 nid for photogallery
check_photo_revision();

function check_photo_revision() {

  $query = db_query("SELECT n.nid as node_nid, n.vid as node_vid, n.status as node_status, nr.nid, nr.vid, nr.status, source.field_story_source_type_value, n.type FROM node as n LEFT JOIN node_revision as nr ON n.vid = nr.vid INNER JOIN field_data_field_story_source_type as source ON n.nid = source.entity_id Where n.type = 'photogallery' AND n.status = 1 AND nr.status = 0 AND source.field_story_source_type_value = 'migrated'  ORDER BY nr.nid desc LIMIT 0, 5");
  $count = 0;
  foreach ($query as $result) {
    update_node_revision_status($result);
    $count++;
  }
  echo ' Count ' . $count;
}

function update_node_revision_status($result) {
  db_update('node_revision') // Table name no longer needs {}
      ->fields(array(
        'status' => 1,
      ))
      ->condition('vid', $result->node_vid, '=')
      ->execute();
  echo 'VID ' . $result->node_vid . ' Node_Id ' . $result->node_nid;
}

//cast status update
//testing();
function testing() {
  $query = db_select('migrate_map_itgcast', 'mm');
  $query->fields('mm', array('destid1'));
//  $query->condition('destid1', 838760, '=');
  $result = $query->execute();
  foreach ($result as $rel) {
   $node = node_load($rel->destid1);
   $node->status = 1;
   node_save($node);
  echo $node->nid.', ';
  }
}


?>