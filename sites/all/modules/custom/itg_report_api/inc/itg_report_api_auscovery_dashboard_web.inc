<?php

/**
 * Inc file contains the functions for auscovery_dashboard_web report API
 */

/**
 * main function for generate auscovery_dashboard_web array
 * @pram datetime $start_date
 * @pram datetime $end_date
 *
 * @return array
 */
function auscovery_dashboard_web($start_date, $end_date) {
  global $base_url; 
  $data = array();
  $list = array();
  $loop_cont = 0;
  $item_per_page = 100;
  $range_max = $item_per_page;
  $pageno = 0;
  $range_min = 0;
  if (!$pageno == 0) {
    $range_min = $pageno * $range_max;
  }

  $type = "story";
  $query = db_select('node', 'n');  
  $query->leftJoin('field_data_field_primary_category', 'fpc', 'fpc.entity_id=n.nid');
  $query->leftJoin('itg_multi_byline_info', 'byli', 'byli.nid=n.nid');
  $query->leftJoin('field_data_field_reporter_email_id', 'repr', 'byli.byline_id=repr.entity_id');
  $query->leftJoin('field_data_field_reporter_profile_type', 'repro', 'byli.byline_id=repro.entity_id');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed', 'status'));
  $query->fields('fpc', array('field_primary_category_value'));  
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('byli', array('byline_id', 'publish_status'));
  $query->fields('repr', array('field_reporter_email_id_value'));
  $query->fields('repro', array('field_reporter_profile_type_value'));
  //end
  if ($start_date != "na") {    
    $query->condition('n.created', $start_date, ">=");
  }
  if ($end_date != "na") {    
    $query->condition('n.created', $end_date, "<=");
  }
  if ($type != "na") {
    $query->condition('n.type', $type);
  }  
  $query->condition('repr.field_reporter_email_id_value', NULL, 'IS NOT');
  $query->groupBy('n.nid');
  $query->condition('n.status', 1)->orderBy('n.created', 'DESC');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  foreach ($result as $reskey => $resvalue) {
    $nid = $resvalue['nid'];
    $title = $resvalue['title'];
    $created = $resvalue['created'];
    $type = $resvalue['type'];
    $uid = $resvalue['uid'];
    $changed = $resvalue['changed'];
    $node_satatus = $resvalue['status'];
    $field_primary_category_value = $resvalue['field_primary_category_value'];
    $body_value = $resvalue['body_value'];
    $field_itg_content_publish_date_value = $resvalue['field_itg_content_publish_date_value'];
    //$url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);  
    $url = drupal_get_path_alias('node/' . $nid);  
    $create_date = date("Y-m-d H:i:s", $created);
    $prime_cat = getNodePrimeCatByNid($nid);
    $author_id = $resvalue['byline_id'];
    $author_email = $resvalue['field_reporter_email_id_value'];    
    $author_status = $resvalue['publish_status'];
    $profile_type = $resvalue['field_reporter_profile_type_value'];
    $author_name = getAuthorNameDashboard($author_id);
    // list data
    $list[$loop_cont]['content_id'] = "$nid";
    $list[$loop_cont]['author_id'] = "$author_id";
    $list[$loop_cont]['author_email'] = "$author_email";
    $list[$loop_cont]['author_name'] = "$author_name";
    $list[$loop_cont]['profile_type'] = "$profile_type";
    $list[$loop_cont]['author_status'] = "$author_status";
    $list[$loop_cont]['title'] = "$title";
    $list[$loop_cont]['content_url'] = "$url";
    $list[$loop_cont]['primary_category'] = "$prime_cat->tid";
    $list[$loop_cont]['created'] = "$create_date";
    $list[$loop_cont]['content_status'] = "$node_satatus";
    $list[$loop_cont]['published_on'] = "$field_itg_content_publish_date_value";
    $loop_cont++;
    $list = auscovery_dashboard_web_video_list($list, $loop_cont);
  }
  $data['data'] = $list;
  return $data;
}
/**
 * auscovery_dashboard_web_video_list
 * @param type $list
 * @param type $loop_cont
 * @return type
 */
function auscovery_dashboard_web_video_list($list, $loop_cont, $start_date, $end_date){    
  $type = "videogallery";
  $query = db_select('node', 'n');  
  $query->leftJoin('field_data_field_primary_category', 'fpc', 'fpc.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_reporter', 'fsr', 'fsr.entity_id=n.nid');
  $query->leftJoin('field_data_field_reporter_email_id', 'repr', 'fsr.field_story_reporter_target_id=repr.entity_id');
  $query->leftJoin('field_data_field_reporter_profile_type', 'repro', 'fsr.field_story_reporter_target_id=repro.entity_id');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->leftJoin('field_data_field_mis_report', 'mis', 'n.nid=mis.entity_id');
  $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed', 'status'));
  $query->fields('fpc', array('field_primary_category_value'));  
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('fsr', array('field_story_reporter_target_id'));
  $query->fields('repr', array('field_reporter_email_id_value'));
  $query->fields('repro', array('field_reporter_profile_type_value'));
  $query->fields('mis', array('field_mis_report_value'));
  //end
  if ($start_date != "na") {    
    $query->condition('n.created', $start_date, ">=");
  }
  if ($end_date != "na") {    
    $query->condition('n.created', $end_date, "<=");
  }
  if ($type != "na") {
    $query->condition('n.type', $type);
  }  
  $query->condition('repr.field_reporter_email_id_value', NULL, 'IS NOT');
  $query->groupBy('n.nid');
  $query->condition('n.status', 1)->orderBy('n.created', 'DESC');  
  print strtr((string) $query, $query->arguments());  die();
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  foreach ($result as $reskey => $resvalue) {
    $nid = $resvalue['nid'];
    $title = $resvalue['title'];
    $created = $resvalue['created'];
    $type = $resvalue['type'];
    $uid = $resvalue['uid'];
    $changed = $resvalue['changed'];
    $node_satatus = $resvalue['status'];
    $field_primary_category_value = $resvalue['field_primary_category_value'];
    $body_value = $resvalue['body_value'];
    $field_itg_content_publish_date_value = $resvalue['field_itg_content_publish_date_value'];
    //$url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);  
    $url = drupal_get_path_alias('node/' . $nid);  
    $create_date = date("Y-m-d H:i:s", $created);
    $prime_cat = getNodePrimeCatByNid($nid);
    $author_id = $resvalue['field_story_reporter_target_id'];
    $author_email = $resvalue['field_reporter_email_id_value'];    
    $author_status = $resvalue['publish_status'];
    $profile_type = $resvalue['field_reporter_profile_type_value'];
    $author_name = getAuthorNameDashboard($author_id);
    $field_mis_report_value = $resvalue['field_mis_report_value'];
    $mis_report = 0;
    if($field_mis_report_value == 'mis_report'){
        $mis_report = 1;
    }
    // list data
    $list[$loop_cont]['content_id'] = "$nid";
    $list[$loop_cont]['author_id'] = "$author_id";
    $list[$loop_cont]['author_email'] = "$author_email";
    $list[$loop_cont]['author_name'] = "$author_name";
    $list[$loop_cont]['profile_type'] = "$profile_type";
    $list[$loop_cont]['author_status'] = "$author_status";
    $list[$loop_cont]['title'] = "$title";
    $list[$loop_cont]['content_url'] = "$url";
    $list[$loop_cont]['primary_category'] = "$prime_cat->tid";
    $list[$loop_cont]['created'] = "$create_date";
    $list[$loop_cont]['content_status'] = "$node_satatus";
    $list[$loop_cont]['published_on'] = "$field_itg_content_publish_date_value";
    $list[$loop_cont]['reporter_filed'] = "1";
    $list[$loop_cont]['mis_report'] = "$mis_report";
    $loop_cont++;    
  }
  return $list;
}

/**
 * main function for generate auscovery_dashboard_mob array
 * @pram datetime $start_date
 * @pram datetime $end_date
 *
 * @return array
 */
function auscovery_dashboard_mob($start_date, $end_date) {
  global $base_url;
  $data = array();
  $list = array();
  $loop_cont = 0;
  $item_per_page = 100;
  $range_max = $item_per_page;
  $pageno = 0;
  $range_min = 0;
  if (!$pageno == 0) {
    $range_min = $pageno * $range_max;
  }

  $type = "story";
  $query = db_select('node', 'n');
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->leftJoin('field_data_field_primary_category', 'fpc', 'fpc.entity_id=n.nid');
  $query->leftJoin('itg_multi_byline_info', 'byli', 'byli.nid=n.nid');
  $query->leftJoin('field_data_field_reporter_email_id', 'repr', 'byli.byline_id=repr.entity_id');
  $query->leftJoin('field_data_field_reporter_profile_type', 'repro', 'byli.byline_id=repro.entity_id');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed', 'status'));
  $query->fields('fpc', array('field_primary_category_value'));  
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('byli', array('byline_id', 'publish_status'));
  $query->fields('repr', array('field_reporter_email_id_value'));
  $query->fields('repro', array('field_reporter_profile_type_value'));
  //end
  if ($start_date != "na") {    
    $query->condition('n.created', $start_date, ">=");
  }
  if ($end_date != "na") {    
    $query->condition('n.created', $end_date, "<=");
  }
  if ($type != "na") {
    $query->condition('n.type', $type);
  }
  //$query->condition('ti.tid', '1206640', '<>');
  $query->condition('repr.field_reporter_email_id_value', NULL, 'IS NOT');  
  $query->groupBy('n.nid');
  $query->condition('n.status', 1)->orderBy('n.created', 'DESC');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  foreach ($result as $reskey => $resvalue) {
    $nid = $resvalue['nid'];
    $title = $resvalue['title'];
    $created = $resvalue['created'];
    $type = $resvalue['type'];
    $uid = $resvalue['uid'];
    $changed = $resvalue['changed'];
    $node_satatus = $resvalue['status'];
    $field_primary_category_value = $resvalue['field_primary_category_value'];
    $body_value = $resvalue['body_value'];
    $field_itg_content_publish_date_value = $resvalue['field_itg_content_publish_date_value'];
    //$url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);  
    $url = drupal_get_path_alias('node/' . $nid);  
    $create_date = date("Y-m-d H:i:s", $created);
    $prime_cat = getNodePrimeCatByNid($nid);
    $author_id = $resvalue['byline_id'];
    $author_email = $resvalue['field_reporter_email_id_value'];    
    $author_status = $resvalue['publish_status'];
    $profile_type = $resvalue['field_reporter_profile_type_value'];
    $author_name = getAuthorNameDashboard($author_id);
    // list data
    $list[$loop_cont]['content_id'] = "$nid";
    $list[$loop_cont]['author_id'] = "$author_id";
    $list[$loop_cont]['author_email'] = "$author_email";
    $list[$loop_cont]['author_name'] = "$author_name";
    $list[$loop_cont]['profile_type'] = "$profile_type";
    $list[$loop_cont]['author_status'] = "$author_status";
    $list[$loop_cont]['title'] = "$title";
    $list[$loop_cont]['content_url'] = "$url";
    $list[$loop_cont]['primary_category'] = "$prime_cat->tid";
    $list[$loop_cont]['created'] = "$create_date";
    $list[$loop_cont]['content_status'] = "$node_satatus";
    $list[$loop_cont]['published_on'] = "$field_itg_content_publish_date_value";
    $loop_cont++;
  }
  $data['data'] = $list;
  return $data;
}

/**
 * function for getUserProfile_report array
 * @pram int $uid
 *
 * @return array $user_profile;
 */
function getUserProfile_report($uid) {

  $user_profile = array();
  $query = db_select('users', 'u');
  $query->leftJoin('field_data_field_reporter_profile_type', 'upt', 'upt.entity_id=u.uid');
  $query->fields('u', array('name', 'uid', 'mail', 'status'));
  $query->fields('upt', array('field_reporter_profile_type_value'));
  $query->condition('u.uid', $uid);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  foreach ($result as $key => $value) {
    $user_profile['uid'] = $value['uid'];
    $user_profile['name'] = $value['name'];
    $user_profile['mail'] = $value['mail'];
    $user_profile['status'] = $value['status'];
    $user_profile['profile_type'] = $value['field_reporter_profile_type_value'];
  }

  return $user_profile;
}
/**
 * function for getAuthorNameDashboard 
 * @pram int $author_id
 *
 * @return string $author_name;
 */
function getAuthorNameDashboard($author_id) {
    $author_name = "";
    if ($author_id) {
        $query = db_select('node', 'n');
        $query->fields('n', array('title'));
        $query->condition('n.nid', $author_id);
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        foreach ($result as $key => $value) {
            $author_name = $value['title'];
        }
    }
    return $author_name;
}
