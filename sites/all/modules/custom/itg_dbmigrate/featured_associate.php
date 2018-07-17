<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

featured_associate_content();

function featured_associate_content() {
  $path_xml = 'sites/default/files/migrate/xml_file/';
  $file_name = 'related_featured_master2007-01-01.xml';
  $xml_data = simplexml_load_file($path_xml . $file_name, 'SimpleXMLElement');
//p($xml_data);
  $story_nid = '';
  $content_type = '';
  $content_nid = '';
  $node = '';
  $related_content_val = '';
  foreach ($xml_data->featuredcontents->featuredcontent as $xml) {
    $story_nid = _return_nid_by_xml_id_story((int) $xml->id);
    $content_type = (string) $xml->featuredcontenttype;
    $content_nid = _return_nid_by_xml_id_photo_video((int) $xml->featuredcontentid, $content_type);
    if (!empty($story_nid)) {
      $node = node_load($story_nid);
      if ($content_type == 'photo') {
        $node->field_story_associate_lead['und'][0]['value'] = 'gallery';
      }
      elseif ($content_type == 'video') {
        $node->field_story_associate_lead['und'][0]['value'] = 'video';
      }
      if (!empty($content_nid)) {
        //$related_content_val = '|~|IT_' . $content_nid;
        //$node->field_common_related_content['und'][0]['value'] = $node->field_common_related_content['und'][0]['value'].$related_content_val;
        if ($content_type == 'photo') {
          $node->field_associate_photo_gallery['und'][0]['target_id'] = $content_nid;
        }
        elseif ($content_type == 'video') {
          $node->field_story_associate_video['und'][0]['target_id'] = $content_nid;
        }
      }

      field_attach_update('node', $node);
      echo $story_nid . ', ';
    }
  }
}

function _return_nid_by_xml_id_photo_video($xml_id, $content_type) {
  $table = '';
  if ($content_type == 'photo') {
    $table = 'migrate_map_itgphotogallery';
  }
  elseif ($content_type == 'video') {
    $table = 'migrate_map_itgvideogallery';
  }
  $query = db_select($table, 'm_map_i');
  $query->fields('m_map_i', array('destid1'));
  $query->isNotNull('destid1');
  $query->condition('sourceid1', $xml_id, '=');
  $result = $query->execute()->fetchField();
  return $result;
}

function _return_nid_by_xml_id_story($xml_id) {
  $query = db_select('migrate_map_itgstorylist', 'm_map_i');
  $query->fields('m_map_i', array('destid1'));
  $query->isNotNull('destid1');
  $query->condition('sourceid1', $xml_id, '=');
  $result = $query->execute()->fetchField();
  return $result;
}

?>
