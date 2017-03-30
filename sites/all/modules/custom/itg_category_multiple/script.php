<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.
//delete_itg_widget_table();
//update_itg_widget_table();
//update_meta_description_in_photo();
print_name();


function print_name() {
  $query = db_select('migrate_map_itgstorylist', 'mmi');
  $query->fields('mmi', array('destid1', 'sourceid1'));
  $query->range(0,10);
  $result = $query->execute();
  $xml_path = 'sites/default/files/story/';
  foreach($result as $rel){ 
    $xml = simplexml_load_file($xml_path . $rel->sourceid1.'.xml', 'SimpleXMLElement');
    $cat = array();
    $tid_array = array();
    foreach($xml->categories->category as $categories) {
      $cat = explode('#', (string) $categories);
      foreach($cat as $cc){
        $tid_array[] = $cc;
      }
    }
    if(!empty($tid_array)){
      $ishwar = array_unique($tid_array);
      updating_term_for_migration($rel->destid1, $ishwar);
    }
    echo $rel->destid1.'-'.$rel->sourceid1.', ';
  }
}


/**
 * 
 * @param type $nid
 */

function updating_term_for_migration($nid, $tids) {
 $node = node_load($nid);
 unset($node->field_story_category[LANGUAGE_NONE]);
  foreach($tids as $chunk_data){
  $node->field_story_category[LANGUAGE_NONE][]['tid'] = $chunk_data;
  }
  field_attach_update('node', $node); 
}
