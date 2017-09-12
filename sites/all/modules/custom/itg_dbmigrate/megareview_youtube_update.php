<?php

set_time_limit(0);
//ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

megareview_url_update();

function megareview_url_update() {
  $path_xml = 'sites/default/files/migrate/xml_file/movie-review-xmls-19-06-2017/';
  $file_name = 'india_mega_reviews.xml';
  $xml_data = simplexml_load_file($path_xml . $file_name, 'SimpleXMLElement');
  foreach ($xml_data->row as $xml) {
    $content_id = _return_nid_by_xml_ids($xml->id);

    if (!empty($content_id)) {
        $node = node_load($content_id);
        p($node->field_mega_review_youtube_url);
        //$node->field_mega_review_youtube_url['und'][0]['value'] = (string) $xml->youtubeurl;
        //field_attach_update('node', $node);
      }
  }
}


function _return_nid_by_xml_ids($xml_id) {
  $query = db_select('migrate_map_itgmegareview', 'm_map_i');
  $query->fields('m_map_i', array('destid1'));
  $query->isNotNull('destid1');
  $query->condition('sourceid1', $xml_id, '=');
  $result = $query->execute()->fetchField();
  return $result;
}
?>
