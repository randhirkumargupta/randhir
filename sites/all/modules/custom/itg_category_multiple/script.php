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
  foreach($result as $rel){ 
    $value[] = $rel;
  }
  print_r($value);
}


/**
 * 
 * @param type $nid
 */

function updating_term_for_migration($nid, $tids) {

  $node = new stdClass();
  $node->nid = $nid; 
  $node->type = 'article';
  
  $node->field_story_category[LANGUAGE_NONE][0]['tid'] = '';
  field_attach_update('node', $node);
  field_attach_presave('node', $node);
  // Clear the static loading cache.
  entity_get_controller('node')->resetCache(array($node->nid));
}
