<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

story_field_update();

function story_field_update() {
  $path_xml = 'sites/default/files/migrate/xml_file/story_conclave/';
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path_xml)) as $filename) {
    $file_name = $filename->getFilename();
    if ($file_name == '.' || $file_name == '..') {
      continue;
    }
    $xml_data = simplexml_load_file($path_xml . $file_name, 'SimpleXMLElement');
    foreach ($xml_data->story as $xml) {
      $nid = '';
      $data_city = '';
      $published_date = '';
      $published_date_ist = '';
      $published_dates = '';
      $node_sef = '';
      $node_new_sefurl = '';
      $caption_text = '';
      $fid = '';
      $ptype = '';
      $ctype = '';
      $path = '';

      
        $nid = _return_nid_by_xml_id($xml->id);
        $check_updated = check_updated_node_stories($nid, $xml->id, $file_name);
        $chk = 0;
        if (empty($check_updated)) {
          if (!empty($nid)) {
            $node = node_load($nid);

// external url
            if (!empty($xml->external_url)) { // update for external url we have to create field in story form.
              $node->field_story_external_url[LANGUAGE_NONE][0]['value'] = (string) $xml->external_url;
            }
            
            field_attach_update('node', $node);


//image caption
            if (!empty((string) $xml->kicker_image_caption)) {
              $caption_text = (string) $xml->kicker_image_caption;
              $fid = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'];
              if (!empty($fid) && !empty($caption_text)) {
                image_caption_insert_db($caption_text, $fid);
              }
            }
            node_update_insert_status_update($node->nid, $xml->id, $file_name);
            echo $xml->id . ', ';
          }
        }

    }
    
  }
}

/**
 * node status save in db
 */
function node_update_insert_status_update($nid, $xml_id, $file_name) {
  db_insert('story_fields_update_script_check')
      ->fields(array(
        'xml_id' => $xml_id,
        'nid' => $nid,
        'xml_name' => $file_name,
        'image_update' => 5,
      ))
      ->execute();
}

/**
 * Check updated node
 */
function check_updated_node_stories($nid, $xml_id, $xml_file_name) {
    $query = db_select('story_fields_update_script_check', 'sfuus');
     $query->fields('sfuus', array('id'));
    $query->condition('nid', $nid, '=');
    $query->condition('xml_id', $xml_id, '=');
    $query->condition('image_update', 5, '='); // conclave
    $result = $query->execute()->fetchField();
  
  return $result;
}

function image_caption_insert_db($caption_text, $fid) {
  db_insert('image_info')
      ->fields(array(
        'image_caption' => $caption_text,
        'fid' => $fid,
      ))
      ->execute();
}

function _return_nid_by_xml_id($xml_id) {
  $query = db_select('migrate_map_itgstorylist', 'm_map_i');
  $query->fields('m_map_i', array('destid1'));
  $query->isNotNull('destid1');
  $query->condition('sourceid1', $xml_id, '=');
  $result = $query->execute()->fetchField();
  return $result;
}

/**
 * Primary and category blank entry
 */
function node_update_blank_category($ptype, $ctype, $xml_id, $file_name, $nid) {
  db_insert('primary_cat_blank_update')
      ->fields(array(
        'xml_id' => $xml_id,
        'xml_name' => $file_name,
        'type' => $ptype . '-' . $ctype,
        'nid' => $nid,
      ))
      ->execute();
}
?>
