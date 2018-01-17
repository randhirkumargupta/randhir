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
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->leftJoin('field_data_field_primary_category', 'fpc', 'fpc.entity_id=n.nid');
  $query->leftJoin('itg_multi_byline_info', 'byli', 'byli.nid=n.nid');
  $query->leftJoin('field_data_field_reporter_email_id', 'repr', 'byli.byline_id=repr.entity_id');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed', 'status'));
  $query->fields('fpc', array('field_primary_category_value'));  
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('byli', array('byline_id', 'publish_status'));
  $query->fields('repr', array('field_reporter_email_id_value'));
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
  $query->condition('ti.tid', '1206640', '<>');
  $query->condition('repr.field_reporter_email_id_value', '%aajtak.com', 'LIKE');
  $query->condition('n.status', 1)->orderBy('n.created', 'DESC')->range($range_min, $range_max);
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
    $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);    $   
    $created_datetime = date("Y-m-d H:i:s", $created);
    $prime_cat = getNodePrimeCatByNid($nid);
    $author_id = $resvalue['byline_id'];
    $author_email = $resvalue['field_reporter_email_id_value'];
    $author_name = "";
    $author_status = $resvalue['publish_status'];
    $profile_type = "";
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
    $list[$loop_cont]['created'] = "$created_datetime";
    $list[$loop_cont]['content_status'] = "$node_satatus";
    $list[$loop_cont]['published_on'] = "$field_itg_content_publish_date_value";
    $loop_cont++;
  }
  $data['data'] = $list;
  return $data;
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
  $item_per_page = 10;
  $range_max = $item_per_page;
  $pageno = 0;
  $range_min = 0;
  if (!$pageno == 0) {
    $range_min = $pageno * $range_max;
  }
  
  $type = "story";
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_primary_category', 'fpc', 'fpc.entity_id=n.nid');
  //$query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed', 'status'));
  $query->fields('fpc', array('field_primary_category_value'));
  //$query->fields('dbody', array('body_value'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  //end
  if ($start_date != "na") {
    //$start_date_timestamp = strtotime($start_date);
    $query->condition('n.created', $start_date, ">=");
  }
  if ($end_date != "na") {
    //$end_date_timestamp = strtotime($end_date);
    $query->condition('n.created', $end_date, "<=");
  }
  if ($type != "na") {
    $query->condition('n.type', $type);
  }
  $query->condition('n.status', 1)->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);
  //$query->condition('n.status', 1)->orderBy('n.created', 'DESC')->groupBy('n.nid');
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

    $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);
    $created_by = getUserProfile_report($uid);
    // $wordcount = count(explode(" ", strip_tags(trim($body_value))));
    $created_datetime = date("Y-m-d H:i:s", $created);
    $prime_cat = getNodePrimeCatByNid($nid);

    $author_id = $created_by['uid'];
    $author_email = $created_by['mail'];
    $author_name = $created_by['name'];
    $author_status = $created_by['status'];
    $profile_type = $created_by['field_reporter_profile_type_value'];

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
    $list[$loop_cont]['created'] = "$created_datetime";
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

