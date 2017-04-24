<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.
//delete_itg_widget_table();
//update_itg_widget_table();
//update_meta_description_in_photo();
//print_name_story();
//print_name_photo();
print_name_video();
/**
 * shift marking for story
 */
function print_name_story() {
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
 * shift marking for photo
 */
function print_name_photo() {
  $xml_path = 'sites/default/files/photogallery/indiatoday-galleries.xml';
  $xml = simplexml_load_file($xml_path, 'SimpleXMLElement');
  foreach($xml as $xm){
    if (isset($xm->categories->category) && !empty($xm->categories->category)) {
        $cat = array();
        $tid_array = array();
        foreach ($xm->categories->category as $final_category) {
          $cat = explode('#', $final_category);
          foreach($cat as $cc){
            $tid_array[] = get_itg_destination_id('migrate_map_itgphoto', (string) $cc);
          }
        }
      }
      $query = db_select('migrate_map_itgphotogallery', 'mmy');
      $query->fields('mmy', array('destid1'));
      $query->condition('sourceid1', (string) $xm->id, '=');
      $result = $query->execute()->fetchField();
      if(!empty($tid_array) && !empty($result)){
      $ishwar = array_unique($tid_array);
       updating_term_for_migration($result, $ishwar);
      echo $result.'-'.(string) $xm->id.', ';
      }
      
      }
   }

/**
 * 
 * @param type $nid
 */

function updating_term_for_migration($nid, $tids) {
 $node = node_load($nid);
 unset($node->field_story_category[LANGUAGE_NONE]);
 $tids[] = 1208521; // for photo category
  foreach($tids as $chunk_data){
  $node->field_story_category[LANGUAGE_NONE][]['tid'] = $chunk_data;
  }
  field_attach_update('node', $node); 
}

/**
 * video shift marking
 */
function print_name_video() {
  $xml_path = 'sites/default/files/video/indiatoday_video_2016-06.xml';
  //$xml_path = 'sites/default/files/video/indiatoday_video_2016-07.xml';
  $xml = simplexml_load_file($xml_path, 'SimpleXMLElement');
  $str = '';

  foreach ($xml as $xm) {
    $category_array = array();
    $tid_array = array();
    foreach ($xm->categories->category as $xm_cat) {
      $category_array = explode('#', $xm_cat);
      $k = 1;
      foreach ($category_array as $individal_cat) {

        $array_count = $k;
        $source_cid = (string) $individal_cat;

        $table_name = itg_migrate_category_table($array_count);
        if ($k != 1) {
          $str = '#';
        }
        $tid_array[] = get_itg_destination_id($table_name, $source_cid);
        $k++;
      }
    }
    $query = db_select('migrate_map_itgvideogallery', 'mmy');
    $query->fields('mmy', array('destid1'));
    $query->condition('sourceid1', (string) $xm->id, '=');
    $result = $query->execute()->fetchField();
    if (!empty($tid_array) && !empty($result)) {
      $ishwar = array_unique($tid_array);
      updating_term_for_migration_video($result, $ishwar);
      echo $result . '-' . (string) $xm->id . ', ';
    }
  }
}

/**
 * 
 * @param type $nid
 */

function updating_term_for_migration_video($nid, $tids) {
  $node = node_load($nid);
  unset($node->field_story_category[LANGUAGE_NONE]);
  foreach ($tids as $chunk_data) {
    $node->field_story_category[LANGUAGE_NONE][]['tid'] = $chunk_data;
  }
  field_attach_update('node', $node);
}
