<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.
//delete_itg_widget_table();
//update_itg_widget_table();
//update_meta_description_in_photo();
//print_name_story();
//print_name_photo();
//print_name_video();
//issue_mapping();
//issue_correct_mapping_supplement_story();
//itg_widget_order_all_data_move();
//itg_widget_order_delete();
//insert_merge();
// __itg_widget_data_into_helper_tbl();
// 
update_node_status_type_in_helper_tbl();

//insert_data_in_widget_helper_test();


/*
 * This function use for update node status and type in itg_widget_helper table.
 * 
 */

function update_node_status_type_in_helper_tbl() {
  $query = db_select("itg_widget_helper", "iwo")
      ->fields("iwo");
  $result = $query->execute()->fetchAll();
  foreach ($result as $widget_data) {

    $node_load_data = unserialize($widget_data->node_data);
    db_update('itg_widget_helper') // Table name no longer needs {}
        ->fields(array(
          'node_status' => $node_load_data->status,
          'node_type' => $node_load_data->type,
        ))
        ->condition('nid', $widget_data->nid, '=')
        ->execute();
    print $widget_data->nid;
  }
}

//function __itg_widget_data_into_helper_tbl() {
//  $result = _itg_widget_get_old_data_script();
//
//  foreach ($result as $key => $data) {
//        if($data && !empty($data) && $data >0) {
//                    echo $data . ", ";           
//             __itg_widget_helper_data_insert($data);
//        }
//    }
//}

function __itg_get_noids_in_helper_table() {
  $widget_tbl = db_select("itg_widget_helper", "iwo")
          ->fields("iwo", array("nid"))
          ->execute()->fetchAllAssoc("nid");
  return array_keys($widget_tbl);
}

function _itg_widget_get_old_data_script() {
  $all_ready_nids = __itg_get_noids_in_helper_table();
  try {
    $widget_tbl = db_select("itg_widget_order", "iwo")
            ->fields("iwo", array("nid"))
            ->condition('iwo.nid', array($all_ready_nids), "NOT IN")
            ->orderBy('iwo.nid', 'DESC')
            ->execute()->fetchAllAssoc("nid");

    $widget_tbl_section = db_select("itg_widget_order_section", "iws")
            ->condition('iws.nid', array($all_ready_nids), "NOT IN")
            ->orderBy('iws.nid', 'DESC')
            ->fields("iws", array("nid"))->execute()->fetchAllAssoc("nid");

    $array1 = array_keys($widget_tbl);
    $array2 = array_keys($widget_tbl_section);
    $result = array_unique(array_merge($array1, $array2));
    return $result;
  }
  catch (Exception $ex) {
    return $ex->getMessage();
  }
}

update_node_status_type_in_helper_tbl();
 //__itg_widget_data_into_helper_tbl();
 
function update_node_status_type_in_helper_tbl() {  
    $query = db_select("itg_widget_helper", "iwo")->fields("iwo"); 
    $result = $query->execute()->fetchAll();
    foreach ($result as $widget_data) {    
        $node_load_data = unserialize($widget_data->node_data);    
        db_update('itg_widget_helper') 
        ->fields(array(
          'node_status' => $node_load_data->status,
          'node_type' => $node_load_data->type,
          ))        
        ->condition('nid', $widget_data->nid, '=')
        ->execute();
        print $widget_data->nid;  
    }
} 

//insert_data_in_widget_helper_test();

function __itg_widget_data_into_helper_tbl() {
  $result = _itg_widget_get_old_data_script();

  foreach ($result as $key => $data) {
        if($data && !empty($data) && $data >0) {
                    echo $data . ", ";           
             __itg_widget_helper_data_insert($data);
        }
    }
}

function __itg_get_noids_in_helper_table() {
    $widget_tbl = db_select("itg_widget_helper", "iwo")
            ->fields("iwo", array("nid"))
            ->execute()->fetchAllAssoc("nid");
    return array_keys($widget_tbl);
}

function _itg_widget_get_old_data_script() {
    $all_ready_nids = __itg_get_noids_in_helper_table();
    try {
        $widget_tbl = db_select("itg_widget_order", "iwo")
            ->fields("iwo", array("nid"))
            ->condition('iwo.nid' , array($all_ready_nids) , "NOT IN")
            ->orderBy('iwo.nid' , 'DESC')
            ->execute()->fetchAllAssoc("nid");

        $widget_tbl_section = db_select("itg_widget_order_section", "iws")
          ->condition('iws.nid' , array($all_ready_nids) , "NOT IN")
            ->orderBy('iws.nid' , 'DESC')
            ->fields("iws", array("nid"))->execute()->fetchAllAssoc("nid");

        $array1 = array_keys($widget_tbl);
        $array2 = array_keys($widget_tbl_section);
        $result = array_unique(array_merge($array1, $array2));
        return $result;
    } catch (Exception $ex) {
        return $ex->getMessage();
    }
}

function itg_widget_order_all_data_move() {
  $query = db_select('itg_widget_order_old', 'iwo');
  $query->fields('iwo', array('cat_id'));
  $query->condition('cat_id', 0, '!=');
  $query->condition('widget', 'section_wise_widget', '=');
  $query->isNotNull('cat_id');
  $query->groupBy("cat_id");
  //$query->orderBy("weight", "DESC");
  $result = $query->execute()->fetchAll();

  foreach ($result as $rel) {
    $query_story = db_select('itg_widget_order_old', 'iwos');
    $query_story->fields('iwos');
    $query_story->condition('content_type', 'story', '=');
    $query_story->condition('cat_id', $rel->cat_id, '=');
    $query_story->condition('widget', 'section_wise_widget', '=');
    $query_story->orderBy('weight', 'DESC');
    $query_story->range(0, 100);
    $result_story = $query_story->execute();
    foreach ($result_story as $rel_story) {
      section_insert('itg_widget_order_section', $rel_story);
    }

    $query_photo = db_select('itg_widget_order_old', 'iwos');
    $query_photo->fields('iwos');
    $query_photo->condition('content_type', 'photogallery', '=');
    $query_photo->condition('cat_id', $rel->cat_id, '=');
    $query_photo->condition('widget', 'section_wise_widget', '=');
    $query_photo->orderBy('weight', 'DESC');
    $query_photo->range(0, 100);
    $result_photo = $query_photo->execute();
    foreach ($result_photo as $rel_photo) {
      section_insert('itg_widget_order_section', $rel_photo);
    }


    $query_video = db_select('itg_widget_order_old', 'iwos');
    $query_video->fields('iwos');
    $query_video->condition('content_type', 'videogallery', '=');
    $query_video->condition('cat_id', $rel->cat_id, '=');
    $query_video->condition('widget', 'section_wise_widget', '=');
    $query_video->orderBy('weight', 'DESC');
    $query_video->range(0, 100);
    $result_video = $query_video->execute();
    foreach ($result_video as $rel_video) {
      section_insert('itg_widget_order_section', $rel_video);
    }

    $query_all = db_select('itg_widget_order_old', 'iwos');
    $query_all->fields('iwos');
    $query_all->condition('content_type', 'All', '=');
    $query_all->condition('cat_id', $rel->cat_id, '=');
    $query_all->condition('widget', 'section_wise_widget', '=');
    $query_all->orderBy('weight', 'DESC');
    $query_all->range(0, 100);
    $result_all = $query_all->execute();
    foreach ($result_all as $rel_all) {
      section_insert('itg_widget_order', $rel_all);
    }

    echo $rel->cat_id . ' ,';
  }
}

function itg_widget_order_delete() {
  $query = db_delete('itg_widget_order_old');
  $query->condition('widget', 'section_wise_widget', '=');
  $result = $query->execute();
}

function insert_merge() {

  $query_story = db_select('itg_widget_order', 'iwos');
  $query_story->fields('iwos');
  $result_story = $query_story->execute();
  foreach ($result_story as $rel_story) {
    section_insert('itg_widget_order_old', $rel_story);
  }
}

function section_insert($table_name, $rel) {
  db_insert($table_name) // Table name no longer needs {}
      ->fields(array(
        'nid' => $rel->nid,
        'cat_id' => $rel->cat_id,
        'content_type' => $rel->content_type,
        'widget' => $rel->widget,
        'weight' => $rel->weight,
        'extra' => $rel->extra,
        'constituency' => $rel->constituency,
        'state' => $rel->state,
       // 'id' => $rel->id,
      ))
      ->execute();
}

function issue_correct_mapping_supplement_story() {
  $xml_path = 'sites/default/files/xml_file_chunk/yearwise-story/issue_based_story/issue_based_story_2016/';
  $foldername = 'issue_based_story_2016';
  $path = $xml_path . $foldername;
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path)) as $filename) {
    $rest = substr($filename, -4);
    if ($rest == ".xml") {
      $xml = simplexml_load_file($filename, 'SimpleXMLElement');

      if (isset($xml->select_magazine) && !empty($xml->select_magazine)) {
        $result_issue_sourceid = (int) $xml->select_magazine;
        $result_supplement = '';

        if (isset($xml->primarycategory) && !empty($xml->primarycategory) && !empty($xml->story_issue)) {
          // if parent term equal source id = 20# & destid = 1206499 then supplement value 
          $pquery = db_select('taxonomy_term_hierarchy', 'th');
          $pquery->fields('th', array('parent'));
          $pquery->condition('tid', (int) $xml->primarycategory, '=');
          $parent_tid_result = $pquery->execute()->fetchField();
          if ($parent_tid_result == 1206499) { // 20 # 1206499 id for supplement
            $query = db_select('migrate_map_itgcategory', 'category');
            $query->fields('category', array('sourceid1'));
            $query->condition('destid1', (int) $xml->primarycategory, '=');
            $result_supplement = $query->execute()->fetchField();
            $supplement_id = $result_supplement . 'A' . $result_issue_sourceid;
            $supplement_destid = get_itg_destination_id('migrate_map_itgsupplements', $supplement_id);
            if (!empty($supplement_destid)) {
              $xml_file = $filename->getFilename();
              $yes_issue[] = $xml->id;
              copy($filename, getcwd() . '/' . $xml_path . 'issue_correct_2016/' . $xml_file);
            }
            else {
              $not_issue[] = $xml->id;
              $xml_file = $filename->getFilename();
              copy($filename, getcwd() . '/' . $xml_path . 'notsupplement_found_2016/' . $xml_file);
            }
          }
          else {
            $not_ptid[] = $xml->id;
          }
        }
        else {
          $not_issue_bassed[] = $xml->id;
          $xml_file = $filename->getFilename();
          copy($filename, getcwd() . '/' . $xml_path . 'notissue_based_2016/' . $xml_file);
        }
      }
    }
  }
  echo 'issue_based->' . count($yes_issue) . ',  ';
  echo 'supplement not fount->' . count($not_issue) . ',  ';
  echo 'parent tid not->' . count($not_ptid) . ',  ';
  echo 'not issue based->' . count($not_issue_bassed) . ',  ';
}

//1testing();
//2supplement_time();
//3update_issue_revision();
function testing() {
  //issue time update
  $query = db_select('field_data_field_issue_title', 'n');
  $query->fields('n', array('field_issue_title_value', 'entity_id'));
  $query->condition('field_issue_title_value', '%' . db_like('18:30:00') . '%', 'LIKE');
  $result = $query->execute();
  foreach ($result as $rel) {
    $date = strtotime($rel->field_issue_title_value . '+5 hours 30 minutes');
    $newdate = date('Y-m-d H:i:s', $date);
    $node = node_load($rel->entity_id);
    $node->field_issue_title['und'][0]['value'] = $newdate;

    field_attach_update('node', $node);
    echo $rel->field_issue_title_value . ' --> ' . $newdate . '  nid' . $node->nid;
  }
}

function update_issue_revision() {
  $query = db_select('field_data_field_issue_title', 'n');
  $query->fields('n', array('field_issue_title_value', 'entity_id'));
  //$query->condition('field_issue_title_value', '%' . db_like('18:30:00') . '%', 'LIKE');
  $result = $query->execute();
  foreach ($result as $rel) {
    //$date = strtotime($rel->field_issue_title_value. '+5 hours 30 minutes');

    $newdate = $rel->field_issue_title_value;

    db_update('node') // Table name no longer needs {}
        ->fields(array(
          'title' => $newdate,
        ))
        ->condition('nid', $rel->entity_id, '=')
        ->execute();

    db_update('node_revision') // Table name no longer needs {}
        ->fields(array(
          'title' => $newdate,
        ))
        ->condition('nid', $rel->entity_id, '=')
        ->execute();
    echo $rel->field_issue_title_value . ' --> ' . $newdate . '  nid' . $node->nid;
  }
}

function supplement_time() {
  $query = db_select('field_data_field_issue_supplement', 'fs');
  $query->fields('fs', array('entity_id', 'field_issue_supplement_target_id'));
  $query->condition('bundle', 'issue', '=');
  $result = $query->execute();
  foreach ($result as $rel) {
    $issue_node = node_load($rel->entity_id);
    $snode = node_load($rel->field_issue_supplement_target_id);
    $snode->field_supp_issue[LANGUAGE_NONE][0]['value'] = $issue_node->field_issue_title['und'][0]['value'];
    field_attach_update('node', $snode);
    echo $snode->nid . ' - ' . $issue_node->nid . ', ';
  }
}

function issue_mapping() {
  $xml_path = 'sites/default/files/migrate/xml_file/all_issue.xml';
  $xml = simplexml_load_file($xml_path, 'SimpleXMLElement');
  $issue_nid = '';
  foreach ($xml as $xm) {
    if (isset($xm->supplements->supplement) && !empty($xm->supplements->supplement)) {
      $issue_nid = get_itg_destination_id('migrate_map_itgissue', (int) $xm->id);
      $suppliment_org_id = array();
      foreach ($xm->supplements->supplement as $final_supplement) {
        $supp_id_concat = $final_supplement . 'A' . (int) $xm->id;
        $suppliment_org_id[]['target_id'] = get_itg_destination_id('migrate_map_itgsupplements', $supp_id_concat);
      }
      $node = node_load($issue_nid);
      unset($node->field_issue_supplement[LANGUAGE_NONE]);
      $node->field_issue_supplement[LANGUAGE_NONE] = $suppliment_org_id;
      field_attach_update('node', $node);
      pr($issue_nid);
      pr($xm->id);
    }
  }
}

/**
 * shift marking for story
 */
function print_name_story() {
  $query = db_select('migrate_map_itgstorylist', 'mmi');
  $query->fields('mmi', array('destid1', 'sourceid1'));
  $query->range(0, 10);
  $result = $query->execute();
  $xml_path = 'sites/default/files/story/';
  foreach ($result as $rel) {
    $xml = simplexml_load_file($xml_path . $rel->sourceid1 . '.xml', 'SimpleXMLElement');
    $cat = array();
    $tid_array = array();
    foreach ($xml->categories->category as $categories) {
      $cat = explode('#', (string) $categories);
      foreach ($cat as $cc) {
        $tid_array[] = $cc;
      }
    }
    if (!empty($tid_array)) {
      $ishwar = array_unique($tid_array);
      updating_term_for_migration($rel->destid1, $ishwar);
    }
    echo $rel->destid1 . '-' . $rel->sourceid1 . ', ';
  }
}

/**
 * shift marking for photo
 */
function print_name_photo() {
  $xml_path = 'sites/default/files/photogallery/indiatoday-galleries.xml';
  $xml = simplexml_load_file($xml_path, 'SimpleXMLElement');
  foreach ($xml as $xm) {
    if (isset($xm->categories->category) && !empty($xm->categories->category)) {
      $cat = array();
      $tid_array = array();
      foreach ($xm->categories->category as $final_category) {
        $cat = explode('#', $final_category);
        foreach ($cat as $cc) {
          $tid_array[] = get_itg_destination_id('migrate_map_itgphoto', (string) $cc);
        }
      }
    }
    $query = db_select('migrate_map_itgphotogallery', 'mmy');
    $query->fields('mmy', array('destid1'));
    $query->condition('sourceid1', (string) $xm->id, '=');
    $result = $query->execute()->fetchField();
    if (!empty($tid_array) && !empty($result)) {
      $ishwar = array_unique($tid_array);
      updating_term_for_migration($result, $ishwar);
      echo $result . '-' . (string) $xm->id . ', ';
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
  foreach ($tids as $chunk_data) {
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
