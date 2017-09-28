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
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_short_headline', 'sheadline', 'sheadline.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_stroy_city', 'story_city', 'npd.entity_id=n.nid');
    $query->leftJoin('taxonomy_term_data', 'tdata', 'tdata.tid=story_city.field_stroy_city_tid');
    
    $query->fields('n', array('nid', 'title', 'created', 'changed'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('sheadline', array('field_story_short_headline_value'));
    $query->fields('tdata', array('name'));
    echo '<pre>';print_r($tid_list);die;
  }
}