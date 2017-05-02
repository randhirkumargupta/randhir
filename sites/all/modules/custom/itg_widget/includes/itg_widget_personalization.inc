<?php

/**
 * @file
 * File provide personalization functionality.
 *
 */

/**
 * 
 * @param array $updates
 */
function save_itg_widget_personalization_data($updates) {
  global $user;
  $widget_name = "personalization_widget";

  $nids = array_keys($updates);
  // Delete all the tids from table if they are not in $updates variable
  // unsued tid should be delete
  db_delete('itg_widget_order')
      ->condition('widget', $widget_name)
      ->condition('nid', $nids, "NOT IN")
      ->condition('extra', $user->uid)
      ->execute();
  // Update the weight of tids if exists or insert if dont exists.
  foreach ($updates as $term_id => $weight) {
    db_merge('itg_widget_order')
        ->key(array('nid' => $term_id, 'widget' => $widget_name, 'extra' => $user->uid))
        ->fields(array(
          'nid' => $term_id,
          'widget' => $widget_name,
          'weight' => $weight,
          'extra' => $user->uid,
        ))
        ->execute();
  }
  drupal_set_message(t("My Preferences Has Been Save."));
}

/**
 * 
 * @param int $tid
 * @return array
 */
function get_personalization_saved_value($tid, $uid) {
  $query = db_select('itg_widget_order', 'iwo');
  $query->addField('iwo', 'weight');
  $query->condition('iwo.nid', $tid);
  $query->condition('iwo.extra', $uid);
  return $query->execute()->fetch();
}

function get_personalization_front_data() {
  global $user;
  $weight_count_loop = FALSE;
  // As in table itg_widget_order tid is saved in nid colom.
  // So join field_story_category_tid join is applied on nid.
  $query = db_select('itg_widget_order', 'iwo');
  $query->fields('iwo', array('weight', 'nid'))
      ->condition('iwo.widget', "personalization_widget")
      ->condition('iwo.extra', $user->uid)
      // Orderby weight or taxonomyterm id.
      ->orderBy('iwo.weight', 'DESC')
      ->orderBy('iwo.nid', 'DESC')
      ->range(0, 30);
  $result = $query->execute()->fetchAllAssoc('nid');
  $new_array_of_terms = array_keys($result);
  // case handled if perferences is not saved.
  if (count($result) == 0) {
    $weight_count_loop = TRUE;
    $query = db_select('itg_widget_order', 'iwo');
    $query->leftJoin('field_data_field_set_as_featured_cate', 'fc', 'fc.entity_id=iwo.cat_id');
    $query->fields('iwo', array('cat_id'))
        ->condition('iwo.widget', "section_wise_widget")
        ->condition('fc.field_set_as_featured_cate_value', 'Yes')
        ->groupBy('iwo.cat_id')
        ->range(0, 30);
    $result = $query->execute()->fetchAllAssoc('cat_id');
  }
  if ($weight_count_loop) {
    $new_array_of_terms = array();
    // Get only tids.
    $tids_array = array_keys($result);
    foreach ($tids_array as $term_id) {
      $new_array_of_terms[$term_id] = count_node_under_tid($term_id);
    }
    krsort($new_array_of_terms);
  }
  return ($weight_count_loop) ? array_keys($new_array_of_terms) : $new_array_of_terms;
}

/**
 * Function to get total number of nodes in taxonomy.
 * @param int $tid
 * @return int
 */
function count_node_under_tid($tid) {
  $query = db_select('taxonomy_index', 'ti');
  $query->leftJoin('node', 'n', 'n.nid=ti.nid');
  $query->addField('ti', 'nid');
  $query->condition('ti.tid', $tid);
  $query->condition('n.status', 1);
  $query->condition('n.type', array('story', 'videogallery', 'photogallery'), 'IN');
  $query->orderBy('n.created', 'DESC');
  return $query->execute()->rowCount();
}

function get_array_in_decending_mode($temp_tid_array_baised_on_node_count) {
  $temp_array = array();
  foreach ($temp_tid_array_baised_on_node_count as $key => $value) {
    if (is_array($value)) {
      foreach ($value as $tid) {
        $temp_array[] = $tid;
      }
    }
    else {
      $temp_array[] = $tid;
    }
  }
  return $temp_array;
}

/**
 * function to get data according to front end.
 * 
 * @param nid $nid
 * @return array
 */
function get_personlization_node_data_for_front($nid, $is_blog_true = TRUE) {
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $query->leftJoin('file_managed', 'fm', 'fm.fid=eli.field_story_extra_large_image_fid');
  $query->fields('n', array('title', 'nid'));
  $query->fields('fm', array('uri'));
  $query->fields('eli', array('field_story_extra_large_image_alt', 'field_story_extra_large_image_title'));
  $query->condition('n.nid', $nid);
    if(!$is_blog_true) {
    $query->condition('n.type', array('story', 'videogallery', 'photogallery' , 'blog'), 'IN');
  } else {
    $query->condition('n.type', array('story', 'videogallery', 'photogallery'), 'IN');
  }
  $query->condition('n.status', 1);
  $query->orderBy('n.created', 'DESC');
  return $query->execute()->fetchAll(PDO::FETCH_ASSOC);
}

/**
 * Function is used to get only two recently careted nodes w.r.t. tid.
 * 
 * @param int $tid
 * @return array
 */
function get_node_ids_assoicated_with_tid($tid, $is_front = FALSE , $is_blog_true = TRUE) {
  $query = db_select('taxonomy_index', 'ti');
  $query->leftJoin('node', 'n', 'n.nid=ti.nid');
  $query->leftJoin('taxonomy_term_data', 'ttd', 'ttd.tid=ti.tid');
  $query->addField('ttd', 'tid');
  $query->addField('ttd', 'name');
  $query->addField('ti', 'nid');
  $query->condition('ti.tid', $tid);
  $query->condition('n.status', 1);
  if(!$is_blog_true) {
    $query->condition('n.type', array('story', 'videogallery', 'photogallery' , 'blog'), 'IN');
  } else {
    $query->condition('n.type', array('story', 'videogallery', 'photogallery'), 'IN');
  }
  $query->orderBy('n.created', 'DESC');
  if ($is_front) {
    $query->range(0, 2);
  }
  return $query->execute()->fetchAll(PDO::FETCH_ASSOC);
}

/**
 * function is used to return array for front end.
 */
function get_personlization_front_block_data($flag = TRUE) {
  global $user;
  $query_flag = TRUE;
  if ($flag && $user->uid != 0) {
    $persionalization = get_personalization_front_data();
    //p($persionalization);
  }
  else {
    if (isset($_COOKIE['recomended_for_you'])) {
      if(function_exists('itg_user_log_get_sections')) {
      $sections = itg_user_log_get_sections($_COOKIE['recomended_for_you']);
      }
      if(function_exists('itg_get_recommended_data')) {
      $persionalization = itg_get_recommended_data($sections);
      }
      //p($persionalization);
       $query_flag = FALSE;
    }
  }
  //$persionalization = get_personalization_front_data();
  //pr($persionalization);
  $front_end_data = array();
  foreach ($persionalization as $persionalization_key => $persionalization_data) {
    // tid saved in nid colom in itg_widget_order table
    $nodes_associate_with_taxonomy = get_node_ids_assoicated_with_tid($persionalization_data, TRUE, $query_flag);
    foreach ($nodes_associate_with_taxonomy as $key => $nid_array) {
      $nid = $nid_array['nid'];
      $tid = $persionalization_data;
      $temp_node_data = get_personlization_node_data_for_front($nid, $query_flag);
      // Create term details object.
      $temp_term = new stdClass();
      $temp_term->name = $nid_array['name'];
      $temp_term->tid = $nid_array['tid'];
      $texonomy_data = $temp_term;
      unset($temp_term);
      $front_end_data[] = array("node_data" => $temp_node_data[0], "taxonomy_name" => $texonomy_data);
    }
  }
  return $front_end_data;
}

//
///**
// * Function gives only name and tid.
// * @param int $tid
// * @return object
// */
//function _get_term_data_from_tid($tid) {
//  $data = array();
//  $query = db_select('taxonomy_term_data' ,'ttd')
//      ->fields('ttd' ,array('tid','name'))
//      ->condition('ttd.tid' ,$tid);
//  $data = $query->execute()->fetchObject();
//  return $data;
//}