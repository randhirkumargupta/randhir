<?php

set_time_limit(0);
//ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

byline_source_update('byline');

function byline_source_update($pre) {
  $path_xml = 'sites/default/files/migrate/xml_file/';
  $file_name = 'byline-master.xml';
  $xml_data = simplexml_load_file($path_xml . $file_name, 'SimpleXMLElement');

  foreach ($xml_data->row as $xml) {
    $content_id = _return_nid_by_xml_ids($xml->id);

    if (!empty($content_id)) {
      $content_revision_id = get_node_revision_id($content_id);
      $source_id_val = $pre.'-'.(int) $xml->id;       
        itg_data_insert_in_field($content_id, $content_revision_id, 'field_old_content_source_id', 'reporter', 'node', $source_id_val);
        echo (int) $xml->id.'-'.$content_id.'</br>';//update content id
      }
  }
}


function itg_data_insert_in_field($nid, $revision_id, $field_name, $bundle, $entity_type, $data) {

    $tb1 = 'field_data_' . $field_name;
    $field = $field_name . '_value';
    $tb2 = 'field_revision_' . $field_name;
    $la = 'und';

    //##############################################################################


      db_query("INSERT INTO {$tb1} (entity_type, bundle, deleted, entity_id, revision_id, language, delta, $field) VALUES (:entity_type, :bundle, :deleted, :entity_id, :revision_id, :language, :delta, :field_dt)", array(':entity_type' => $entity_type, ':bundle' => $bundle, ':deleted' => 0, ':entity_id' => $nid, ':revision_id' => $revision_id, ':language' => $la, ':delta' => 0, ':field_dt'=>$data));
      db_query("INSERT INTO {$tb2} (entity_type, bundle, deleted, entity_id, revision_id, language, delta, $field) VALUES (:entity_type, :bundle, :deleted, :entity_id, :revision_id, :language, :delta, :field_dt)", array(':entity_type' => $entity_type, ':bundle' => $bundle, ':deleted' => 0, ':entity_id' => $nid, ':revision_id' => $revision_id, ':language' => $la, ':delta' => 0, ':field_dt'=>$data));
     
    //######################################################################################

   // db_delete('field_data_' . $field_name)->condition('entity_id', $nid)->execute();
   // db_delete('field_revision_' . $field_name)->condition('entity_id', $nid)->execute();
}

/**
 * get new content id of itg by old content id
 * @param int $sourceid
 * @return int destination id
 */
function get_node_revision_id($nid) {
  $query = db_select('node', 'n');
  $query->fields('n', array('vid'));
  $query->condition('nid', $nid);

  return $query->execute()->fetchField();
}


?>
