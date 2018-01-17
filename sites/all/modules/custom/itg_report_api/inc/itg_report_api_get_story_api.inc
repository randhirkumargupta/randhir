<?php

/**
 * Inc file contains the functions for getStoryAPI report API
 */

/**
 * main function for generate getStoryAPI array
 * @pram datetime $start_date
 * @pram datetime $end_date
 * @pram string $user_type
 * @pram string $user_sub_type
 * @pram string $userid
 * @pram string $content_type
 *
 * @return array
 */
function getStoryAPI($start_date, $end_date, $user_type, $user_sub_type, $userid, $content_type) {

  global $base_url;
  $list = array();
  $data = array();
  $total_cont = 0;
  $range_max = 20;
  $pageno = 0;
  $range_min = 0;
  if (!$pageno == 0) {
    $range_min = $pageno * $range_max;
  }  
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
  //filter of user type
  if ($user_sub_type == "created_by") {
    $query->condition('n.created', $start_date, '>=');
    $query->condition('n.created', $end_date, '<=');
  }
  elseif ($user_sub_type == "modified by" || $user_sub_type == "modified_by") {
    $query->condition('n.changed', $start_date, '>=');
    $query->condition('n.changed', $end_date, '<=');
  }
  // filter by content type
  if ($content_type != "na") {
    $query->condition('n.type', $content_type);
  }
  // filter by uid
  if ($userid != "na") {
    $query->condition('n.uid', $userid);
  }
  //$query->condition('ti.tid', '1206640', '<>');
  $query->condition('repr.field_reporter_email_id_value', NULL, 'IS NOT');
  $query->groupBy('n.nid');
  $query->condition('n.status', $status)->orderBy('n.created', 'DESC');

  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  foreach ($result as $reskey => $resvalue) {

    $total_cont++;
    $nid = $resvalue['nid'];
    $title = $resvalue['title'];
    $created = $resvalue['created'];
    $type = $resvalue['type'];
    $uid = $resvalue['uid'];
    $changed = $resvalue['changed'];
    $field_primary_category_value = $resvalue['field_primary_category_value'];
    $body_value = $resvalue['body_value'];
    $field_itg_content_publish_date_value = $resvalue['field_itg_content_publish_date_value'];

    $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);
    $created_by = getNodeCreatedBy_UserName($uid);
    $wordcount = count(explode(" ", strip_tags(trim($body_value))));
    $created_datetime = date("Y-m-d H:i:s", $created);
    $prime_cat = getNodePrimeCatByNid($nid);

    // list data
    $list[$nid]['id'] = "$nid";
    $list[$nid]['title'] = "$title";
    $list[$nid]['url'] = "$url";
    $list[$nid]['word_count'] = "$wordcount";
    $list[$nid]['published_datetime'] = "$field_itg_content_publish_date_value";
    $list[$nid]['section_name'] = "$prime_cat->name";
    $list[$nid]['created_datetime'] = "$created_datetime";
    $list[$nid]['video_embed'] = "$nid";
    $list[$nid]['created_by'] = "$created_by";
  }

  $data['results'] = $list;
  $data['total_records'] = "$total_cont";
  //$data['next_page_url'] = "$next_page_url";
  return $data;
}

/**
 * function for totalRecordsCount
 * @pram datetime $start_date
 * @pram datetime $end_date
 * @pram string $type
 * @pram int $status
 * @pram int $item_per_page
 *
 * @return int $total_records
 */
function totalRecordsCount_StoryAPI($start_date, $end_date, $type, $status, $item_per_page, $pageno) {
  $query_cont = db_select('node', 'n');
  $query_cont->fields('n', array('nid'));
  //end
  if ($start_date != "na") {
    $start_date_timestamp = strtotime($start_date. " 01:01:00");
    $query_cont->condition('n.created', $start_date_timestamp, ">=");
  }
  if ($end_date != "na") {
    $end_date_timestamp = strtotime($end_date. " 23:59:00");
    $query_cont->condition('n.created', $end_date_timestamp, "<=");
  }
  if ($type != "na") {
    $query_cont->condition('n.type', $type);
  }
  $query_cont->condition('n.status', 1);
  $result_cont = $query_cont->execute()->fetchAll();

  $total_records = count($result_cont);
  return $total_records;
}

