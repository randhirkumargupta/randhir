<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * 
 * @param array $updates
 */
function save_itg_widget_personalization_data($updates) {
  $widget_name = "personalization_widget";
  foreach ($updates as $termId => $weight) {
    db_merge('itg_widget_order')
            ->key(array('nid' => $termId, 'widget' => $widget_name))
            ->fields(array(
                'nid' => $termId,
                'widget' => $widget_name,
                'weight' => $weight,
            ))
            ->execute();
  }
  drupal_set_message("My Preferences Has Been Save");
}

/**
 * 
 * @param int $tid
 * @return array
 */
function get_personalization_saved_value($tid) {
  $query = db_select('itg_widget_order', 'iwo');
  $query->addField('iwo', 'weight');
  $query->condition('iwo.nid', $tid);
  return $query->execute()->fetch();
}

function get_personalization_front_data() {
  $new_ordered_data = array();
  // As in table itg_widget_order tid is saved in nid colom.
  // So join field_story_category_tid join is applied on nid.
  $query = db_select('itg_widget_order', 'iwo');
  $query->fields('iwo', array('weight', 'nid'))
          ->condition('iwo.widget', "personalization_widget")
          ->orderBy('iwo.weight', 'DESC')
          ->orderBy('iwo.nid', 'DESC');
  $result = $query->execute()->fetchAll();

  // Create gorup of same weight tids
  foreach ($result as $info) {
    $new_ordered_data_weighted_group[$info->weight][] = $info->nid;
  }
  foreach ($new_ordered_data_weighted_group as $weight => $tids) {
    $temp_tid_array_baised_on_node_count = array();

    if (count($tids) > 1) {
      // For each term create array baised on number of nodes inside tid.
      foreach ($tids as $term_id) {
        // count the nodes under tid
        $number_of_nodes_in_tid = count(get_node_ids_assoicated_with_tid($term_id));
        //create
        $temp_tid_array_baised_on_node_count[$number_of_nodes_in_tid][] = $term_id;
      }
      // decending order
      krsort($temp_tid_array_baised_on_node_count);

      $sorted_array = get_array_in_decending_mode($temp_tid_array_baised_on_node_count);
    }
    else {
      $new_ordered_data[] = $tids[0];
    }
  }
  return $result;
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
function get_personlization_node_data_for_front($nid) {
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $query->leftJoin('file_managed', 'fm', 'fm.fid=eli.field_story_extra_large_image_fid');
  $query->fields('n', array('title', 'nid'));
  $query->fields('fm', array('uri'));
  $query->condition('n.nid', $nid);
  $query->condition('n.type', array('story', 'videogallery', 'photogallery'), 'IN');
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
function get_node_ids_assoicated_with_tid($tid) {
  $query = db_select('taxonomy_index', 'ti');
  $query->leftJoin('node', 'n', 'n.nid=ti.nid');
  $query->addField('ti', 'nid');
  $query->condition('ti.tid', $tid);
  $query->condition('n.status', 1);
  $query->condition('n.type', array('story', 'videogallery', 'photogallery'), 'IN');
  $query->orderBy('n.created', 'DESC');
  $query->range(0, 2);
  return $query->execute()->fetchAll(PDO::FETCH_ASSOC);
}

/**
 * function is used to return array for front end.
 */
function get_personlization_front_block_data() {
  $persionalization = get_personalization_front_data();
  $front_end_data = array();
  foreach ($persionalization as $persionalization_key => $persionalization_data) {
    // tid saved in nid colom in itg_widget_order table
    $nodes_associate_with_taxonomy = get_node_ids_assoicated_with_tid($persionalization_data->nid);
    foreach ($nodes_associate_with_taxonomy as $key => $nid_array) {
      $nid = $nid_array['nid'];
      $tid = $persionalization_data->nid;
      $front_end_data[$tid]['data'][] = get_personlization_node_data_for_front($nid);
      $front_end_data[$tid]['taxonomy_term_load'] = taxonomy_term_load($tid);
    }
  }
  return $front_end_data;
}
