<?php

set_time_limit(0);
$args = drush_get_arguments(); // Get the arguments.

//Function call
tag_associate_content_type();


/**
 * Implement funciton for tag update according content type
 */
function tag_associate_content_type() {
    
    //For Story
    /*$table = 'migrate_map_itgstorylist';
    $xml_name = 'story_tags.xml';
    $type = 'story';*/
    
    //For Video
    $table = 'migrate_map_itgvideogallery';
    $xml_name = 'video_tags.xml';
    $type = 'video';
       
    
    tags_associate_update_script($table, $xml_name, $type);
}

/**
 * Content tags associate
 */
function tags_associate_update_script($table, $xml_name, $type) {
  $path = 'sites/default/files/migrate/xml_file/tags_associate/'.$xml_name;
  $xml = simplexml_load_file($path, 'SimpleXMLElement');
  foreach ($xml->content_tags as $xml_data) {
    $nid = '';
    $source_id = '';
    $source_id = (int) $xml_data->content_id;
    $data_tags = '';
    $node = '';
    if (isset($xml_data->tags->tag) && !empty($xml_data->tags->tag)) {
      foreach ($xml_data->tags->tag as $final_tags) {
        $source_tags = '';
        $orignal_tag = '';
        $source_tags = (string) $final_tags;
        $orignal_tag = get_itg_destination_id('migrate_map_itgtags', $source_tags);
        if(!empty($orignal_tag)) {
            $data_tags[]['tid'] = $orignal_tag;
        }
      }
    }
    $nid = get_itg_destination_id($table, $source_id);
    if(!empty($nid)) {
    $node = node_load($nid);
    $node->field_story_itg_tags[LANGUAGE_NONE] = $data_tags;
    field_attach_update('node', $node);
    drush_print($node->nid.'-'.$source_id.'success');
    }else{
         $query = db_insert('video_story_tag_miss_node')
        ->fields(array(
          'sourceid' => $source_id,
          'type' => $type,
        ))
        ->execute();
       drush_print($source_id.' failed');
    }
  }
}


?>
