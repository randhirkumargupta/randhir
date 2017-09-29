<?php

/**
 * @file
 * The ITG Syndication clients for BSB Story
 */

/**
 * menu callback for bsb story syndication
 */
function itg_bsb_story_syndication($section_id = NULL){
  if(!empty($section_id)){
//    $tid_list[] = $section_id;
//    $term_tree = taxonomy_get_tree(CATEGORY_MANAGMENT, $section_id,  NULL, FALSE);
//    if(count($term_tree) > 0){
//      foreach ($term_tree as $key => $value) {
//          $tid_list[] = $value->tid;
//      }
//    }
    $type = array('story');
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->leftJoin('field_data_field_story_short_headline', 'sheadline', 'sheadline.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_itg_tags', 'story_tags', 'story_tags.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'smi', 'smi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');
    
    $query->condition('ti.tid', $section_id, '=');
    $query->fields('n', array('nid', 'title', 'created', 'changed'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('sheadline', array('field_story_short_headline_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('smi', array('field_story_medium_image_fid'));
    $query->fields('ssi', array('field_story_small_image_fid'));
    
    $query->condition('n.status', 1);
    $query->condition('n.type', $type, 'IN');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 30);
//    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    
    echo '<pre>';print_r(get_term_name_by_tid(222513));die;
  }
}

function get_image_info_by_fid($fid = NULL){
  $image_data = array();
  if(!empty($fid)){
    $query = db_select('image_info', 'ii');
    $query->fields('ii', array('image_caption'));
    $query->condition('ii.fid', $fid, '=');
    $image_data = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    
  }
  return $image_data;
}

function get_term_name_by_tid($tid = NULL){
  $tname = '';
  if(!empty($tid)){
    $query = db_select('taxonomy_term_data', 'ttd');
    $query->fields('ttd', array('name'));
    $query->condition('ttd.tid', $tid, '=');
    $tname = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    if(count($tname) > 0){
      $tname = $tname[0]['name'];
    }
  }
  return $tname;
}

function get_content_city($nid = NULL){
  $city = array();
  if(!empty($nid)){
    $query = db_select('field_data_field_stroy_city', 'city');
    $query->leftJoin('taxonomy_term_data', 'tdata', 'tdata.tid=city.field_stroy_city_tid');
    $query->fields('tdata', array('name'));
    $query->fields('city', array('field_stroy_city_tid'));
    $query->condition('city.entity_id', $nid, '=');
    $city = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  }
  return $city;
}

function get_content_tags($nid = NULL){
  $tags = array();
  if(!empty($nid)){
    $query = db_select('field_data_field_story_itg_tags', 'tags');
    $query->leftJoin('taxonomy_term_data', 'tdata', 'tdata.tid=tags.field_story_itg_tags_tid');
    $query->fields('tdata', array('name'));
    $query->fields('tags', array('field_story_itg_tags_tid'));
    $query->condition('tags.entity_id', $nid, '=');
    $tags = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  }
  return $tags;
}