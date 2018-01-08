<?php

/**
 * Inc file contains the functions for story_Count_report API
 */

/**
 * main function for generate story_Count_report array
 * @pram datetime $start_date
 * @pram datetime $end_date
 * @pram string $type
 * @pram int $status
 * @pram int $item_per_page
 *
 * @return array
 */
function getStoryCountReport($start_date, $end_date, $type, $status, $item_per_page, $pageno = 0) {

  global $base_url;
  $list = array();
  $data = array();
  $total_cont = 0;
  $range_max = $item_per_page;
  $range_min = 0;
  if (!$pageno == 0) {
    $range_min = $pageno * $range_max;
  }
  
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_primary_category', 'fpc', 'fpc.entity_id=n.nid');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));
  $query->fields('fpc', array('field_primary_category_value'));
  $query->fields('dbody', array('body_value'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  //end
  if ($start_date != "na") {
    $start_date_timestamp = strtotime($start_date. " 01:01:00");
    $query->condition('n.created', $start_date_timestamp, ">=");
  }
  if ($end_date != "na") {
    $end_date_timestamp = strtotime($end_date. " 23:59:00");
    $query->condition('n.created', $end_date_timestamp, "<=");
  }
  if ($type != "na") {
    $query->condition('n.type', $type);
  }
  $query->condition('n.status', 1)->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);
  //$total_records = $query->countQuery()->execute()->fetchField();
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

    $url = $base_url . "/" . drupal_get_path_alias('node/' . $nid);
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
  //$start_date, $end_date, $type, $status, $item_per_page, $pageno = 0
  $total_records = totalRecordsCount($start_date, $end_date, $type, $status, $item_per_page, $pageno);
  $next_page_no = $pageno + 1;
  $next_page_url = $base_url . "/reportapi/story_count_report?start_date=" . $start_date . "&end_date=" . $end_date . "&type=" . $type . "&status=" . $status . "&item_per_page=" . $item_per_page . "&pageno=" . $next_page_no . "";
  $data['results'] = $list;
  $data['total_records'] = "$total_records";
  $data['next_page_url'] = "$next_page_url";
  //secrtion data report
  $section_data = array();
  $section_data = getSectionCountData_report($start_date, $end_date);
  $data['section_data'] = $section_data;
  return $data;
}

/**
 * function for Created By user name
 * @pram int $uid
 *
 * @return string $published_datetime;
 */
function getNodeCreatedBy_UserName($uid) {
  $query = db_select('users', 'u');
  $query->fields('u', array('name'));
  $query->condition('u.uid', $uid);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $name = $result[0]['name'];
  return $name;
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
function totalRecordsCount($start_date, $end_date, $type, $status, $item_per_page, $pageno) {
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
  //return $query->countQuery()->execute()->fetchField();
  $total_records = count($result_cont);
  return $total_records;
}

/**
 * function for get section data
 * @pram datetime $start_date
 * @pram datetime $end_date
 *
 * @return array $section_data;
 */
function getSectionCountData_report($start_date, $end_date) {
  global $base_url;
  $section_data = array();
  $section_list_count = array();
  $vid = 14;
  $section_list = getSectionListByVID($vid);

  $loop_count = 0;
  foreach ($section_list as $key => $value) {

    $n_cont = 0;
    $n_cont = countTidNode_report($start_date, $end_date, $value['tid']);
    if ($n_cont) {
      $ntid = $value['tid'];
      $term = taxonomy_term_load($ntid);
      $section_data[$loop_count]['count'] = "$n_cont";
      $section_data[$loop_count]['section'] = "$term->name";
      $section_data[$loop_count]['section_id'] = "$ntid";
      $loop_count++;
    }
  }
  return $section_data;
}

/**
 * function for section node count
 * @pram datetime $start_date
 * @pram datetime $end_date
 * @pram int $tid
 *
 * @return int $n_count;
 */
function countTidNode_report($start_date, $end_date, $tid) {
  //story count between

  $start_date_timestamp = strtotime($start_date. " 01:01:00");
  $end_date_timestamp = strtotime($end_date. " 23:59:00");
  $n_count = 0;
  $query = db_select('node', 'n');
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->fields('n', array('nid'));
  $query->condition('n.created', $start_date_timestamp, '>=')->condition('n.created', $end_date_timestamp, '<=')->condition('ti.tid', $tid);
  //$query->condition('ti.tid', $tid);
  $result = $query->execute()->fetchAll();
  $total_records_between = count($result);
  return $total_records_between;
}

