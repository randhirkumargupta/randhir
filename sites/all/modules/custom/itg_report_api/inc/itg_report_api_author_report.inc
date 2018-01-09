<?php

/**
 * Inc file contains the functions for author report - TVTN report API
 */

/**
 * main function for generate author report - TVTN array
 * @pram datetime $start_date
 *
 * @return array
 */
function author_report_tvtn($start_date) {
  global $base_url;
  $data = array();
  $prev_day = time() - (24 * 60 * 60);
  $hour = 01;
  
  $yesterday = strtotime('-1 day', $start_date);
  $month = date("M-Y", $start_date);
  $year = date("Y", $start_date);
  $site_id = 1;
  $site_name = "India Today";

  // date details
  $data['date details']['today'] = date("d-F-Y", $start_date);
  $data['date details']['yesterday'] = date("d-F-Y", $yesterday);;
  $data['date details']['month'] = $month;
  $data['date details']['year'] = $year;

  // site_snapshot  
  $today_unix = $start_date;
  $today_end = $start_date + 86399;
  $yesterday_unix = strtotime('-1 day', $today_unix);
  $yesterday_unix_end = $yesterday_unix + 86399;
  $month_prev_unix = strtotime('-1 month', $today_unix);
  $month_prev_unix_end = $month_prev_unix + 2629743;
  $year_prev_unix = strtotime('-1 year', $today_unix); 
  $year_prev_unix_end = $year_prev_unix + 31556926;
  
  $today_total = getContentCountByDate($today_unix, $today_end);
  $yesterday_total = getContentCountByDate($yesterday_unix, $yesterday_unix_end);
  $month_total = getContentCountByDate($month_prev_unix, $month_prev_unix_end);
  $year_total = getContentCountByDate($year_prev_unix, $year_prev_unix_end);

  $data['site_snapshot']['site_name'] = "$site_name";
  $data['site_snapshot']['today'] = "$today_total";
  $data['site_snapshot']['yesterday'] = "$yesterday_total";
  $data['site_snapshot']['month'] = "$month_total";
  $data['site_snapshot']['year'] = "$year_total";
  $data['site_snapshot']['site_id'] = "$site_id";

  // auhtorwise_data
  $data['auhtorwise_data']['site_name'] = "$site_name";
  $data['auhtorwise_data']['today'] = "$today_total";
  $data['auhtorwise_data']['yesterday'] = "$yesterday_total";
  $data['auhtorwise_data']['month'] = "$month_total";
  $data['auhtorwise_data']['year'] = "$year_total";
  $data['auhtorwise_data']['site_id'] = "$site_id";
  //auhtor_data
  $author_list = getAuthorList_Report();
  // start loop on author list array
  $author_loop_cont = 0;
  $auhtor_data = array();
  foreach ($author_list as $key => $value) {
    $user_id = $value['user_id'];
    $name = $value['name'];
    $mail = $value['mail'];

    $today_total_uid = getContentCountByDateAndByUid($today_unix, $user_id);
    $yesterday_total_uid = getContentCountByDateAndByUid($yesterday_unix, $user_id);
    $month_total_uid = getContentCountByDateAndByUid($month_prev_unix, $user_id);
    $year_total_uid = getContentCountByDateAndByUid($year_prev_unix, $user_id);

    $auhtor_data[$author_loop_cont]['author_id'] = "$user_id";
    $auhtor_data[$author_loop_cont]['author_email'] = "$mail";
    $auhtor_data[$author_loop_cont]['author_name'] = "$name";
    $auhtor_data[$author_loop_cont]['site_id'] = "$site_id";
    $auhtor_data[$author_loop_cont]['today'] = "$today_total_uid";
    $auhtor_data[$author_loop_cont]['yesterday'] = "$yesterday_total_uid";
    $auhtor_data[$author_loop_cont]['month'] = "$month_total_uid";
    $auhtor_data[$author_loop_cont]['year'] = "$year_total_uid";

    //auhtor_data contents
    $author_today_data = todayContentsByUid($today_unix, $user_id);

    //loop author today data
    $author_inner_loop_cont = 0;
    $contents = array();
    foreach ($author_today_data as $today_key => $today_val) {
      $title = $today_val['title'];
      $nid = $today_val['nid'];
      $title_path = drupal_get_path_alias('node/' . $nid . '');
      $contents[$author_inner_loop_cont]['author_id'] = "$user_id";
      $contents[$author_inner_loop_cont]['author_email'] = "$mail";
      $contents[$author_inner_loop_cont]['author_name'] = "$name";
      $contents[$author_inner_loop_cont]['site_id'] = "$site_id";
      $contents[$author_inner_loop_cont]['content_url'] = "$title_path";
      $contents[$author_inner_loop_cont]['page_title'] = "$title";
      $author_inner_loop_cont++;
    }
    if ($author_inner_loop_cont) {
      $auhtor_data[$author_loop_cont]['contents'] = $contents;
    }
    else {
      unset($auhtor_data[$author_loop_cont]);
    }
    $author_loop_cont++;
  }
  
  //$auhtor_data[0]['contents']['author_id'] = "1";
  $data['auhtorwise_data']['auhtor_data'] = $auhtor_data;

  return $data;
}

/**
 * main function for generate author report array
 * @pram datetime $start_date
 *
 * @return array
 */
function author_report($start_date) {
  global $base_url;
  $data = array();
  $prev_day = time() - (24 * 60 * 60);
  $hour = 01;
  
  $yesterday = strtotime('-1 day', $start_date);
  $month = date("M-Y", $start_date);
  $year = date("Y", $start_date);
  $site_id = 1;
  $site_name = "India Today";

  // date details
  $data['date details']['today'] = date("d-F-Y", $start_date);
  $data['date details']['yesterday'] = date("d-F-Y", $yesterday);;
  $data['date details']['month'] = $month;
  $data['date details']['year'] = $year;

  // site_snapshot  
  $today_unix = $start_date;
  $today_end = $start_date + 86399;
  $yesterday_unix = strtotime('-1 day', $today_unix);
  $yesterday_unix_end = $yesterday_unix + 86399;
  $month_prev_unix = strtotime('-1 month', $today_unix);
  $month_prev_unix_end = $month_prev_unix + 2629743;
  $year_prev_unix = strtotime('-1 year', $today_unix); 
  $year_prev_unix_end = $year_prev_unix + 31556926;
  
  $today_total = getContentCountByDate($today_unix, $today_end);
  $yesterday_total = getContentCountByDate($yesterday_unix, $yesterday_unix_end);
  $month_total = getContentCountByDate($month_prev_unix, $month_prev_unix_end);
  $year_total = getContentCountByDate($year_prev_unix, $year_prev_unix_end);

  $data['site_snapshot']['site_name'] = "$site_name";
  $data['site_snapshot']['today'] = "$today_total";
  $data['site_snapshot']['yesterday'] = "$yesterday_total";
  $data['site_snapshot']['month'] = "$month_total";
  $data['site_snapshot']['year'] = "$year_total";
  $data['site_snapshot']['site_id'] = "$site_id";

  // auhtorwise_data
  $data['auhtorwise_data']['site_name'] = "$site_name";
  $data['auhtorwise_data']['today'] = "$today_total";
  $data['auhtorwise_data']['yesterday'] = "$yesterday_total";
  $data['auhtorwise_data']['month'] = "$month_total";
  $data['auhtorwise_data']['year'] = "$year_total";
  $data['auhtorwise_data']['site_id'] = "$site_id";

  //auhtor_data
  $author_list = getAuthorList_Report($today_unix, $today_end);

  // start loop on author list array
  $author_loop_cont = 0;
  $auhtor_data = array();
  foreach ($author_list as $key => $value) {
    $user_id = $value['nid'];
    $name = $value['title'];
    $mail = $value['email'];
    $today_total_uid = getContentCountByDateAndByUid($today_unix,$today_end, $user_id);
    $yesterday_total_uid = getContentCountByDateAndByUid($yesterday_unix,$yesterday_unix_end, $user_id);
    $month_total_uid = getContentCountByDateAndByUid($month_prev_unix, $month_prev_unix_end, $user_id);
    $year_total_uid = getContentCountByDateAndByUid($year_prev_unix, $year_prev_unix_end, $user_id);

    $auhtor_data[$author_loop_cont]['author_id'] = "$user_id";
    $auhtor_data[$author_loop_cont]['author_email'] = "$mail";
    $auhtor_data[$author_loop_cont]['author_name'] = "$name";
    $auhtor_data[$author_loop_cont]['site_id'] = "$site_id";
    $auhtor_data[$author_loop_cont]['today'] = "$today_total_uid";
    $auhtor_data[$author_loop_cont]['yesterday'] = "$yesterday_total_uid";
    $auhtor_data[$author_loop_cont]['month'] = "$month_total_uid";
    $auhtor_data[$author_loop_cont]['year'] = "$year_total_uid";

    //auhtor_data contents
    $author_today_data = todayContentsByUid($today_unix, $user_id);

    //loop author today data
    $author_inner_loop_cont = 0;
    $contents = array();
    foreach ($author_today_data as $today_key => $today_val) {
      $title = $today_val['title'];
      $nid = $today_val['nid'];
      $title_path = $base_url . "/" . drupal_get_path_alias('node/' . $nid . '');
      $contents[$author_inner_loop_cont]['author_id'] = "$user_id";
      $contents[$author_inner_loop_cont]['author_email'] = "$mail";
      $contents[$author_inner_loop_cont]['author_name'] = "$name";
      $contents[$author_inner_loop_cont]['site_id'] = "$site_id";
      $contents[$author_inner_loop_cont]['content_url'] = "$title_path";
      $contents[$author_inner_loop_cont]['page_title'] = "$title";
      $author_inner_loop_cont++;
    }
    if ($author_inner_loop_cont) {
      $auhtor_data[$author_loop_cont]['contents'] = $contents;
    }
    else {
      unset($auhtor_data[$author_loop_cont]);
    }
    $author_loop_cont++;
  }
  
  $data['auhtorwise_data']['auhtor_data'] = $auhtor_data;

  return $data;
}

/**
 * function for get total contents by date
 * @pram datetime $start_date
 *
 * @return int $count
 */
function getContentCountByDate($start_date, $end_date) {
  $query_cont = db_select('node', 'n');
  $query_cont->fields('n', array('nid'));
  //end
  if ($start_date != "na") {    
    $query_cont->condition('n.created', $start_date, ">=");
    $query_cont->condition('n.created', $end_date, "<=");
  }
  $query_cont->condition('n.status', 1);
  $result_cont = $query_cont->execute()->fetchAll();  
  $total_records = count($result_cont);
  $query_cont = "";
  $result_cont = "";
  return $total_records;
}

/**
 * function for generate author list array
 *
 * @return array authorList
 */
function getAuthorList_Report($s_date, $e_date) {
  global $base_url;
  $list = array();
  $total_cont = 0;
  $query = db_select('itg_multi_byline_info', 'byi');
  $query->leftJoin('node', 'n', 'n.nid=byi.nid');
  $query->fields('byi', array('id', 'nid'));
  $query->condition('n.created', $s_date, '>=');
  $query->condition('n.created', $e_date, '<=');
  $query->groupBy('byi.id');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  foreach ($result as $reskey => $resvalue) {
      $id = $resvalue['id'];
      $list[$id] = getBYlineDetail($resvalue['nid']);
  }
  return $list;
}
function getAuthorList_Report_bk() {
  global $base_url;
  $list = array();
  $total_cont = 0;
  $query = db_select('users', 'u');
  $query->leftJoin('users_roles', 'ur', 'ur.uid=u.uid');
  $query->fields('u', array('uid', 'name', 'mail', 'status'));
  //$query->condition('ur.rid', 1, '<>')->condition('ur.rid', 25, '<>')->orderBy('u.name', 'DESC')->groupBy('u.uid');
  $query->orderBy('u.name', 'DESC')->groupBy('u.uid');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  foreach ($result as $reskey => $resvalue) {
    $uid = $resvalue['uid'];
    $name = $resvalue['name'];
    $mail = $resvalue['mail'];
    $status = $resvalue['status'];
    // list data
    $list[$total_cont]['user_id'] = "$uid";
    $list[$total_cont]['name'] = "$name";
    $list[$total_cont]['email'] = "$mail";
    $list[$total_cont]['status'] = "$status";

    $total_cont++;
  }
  $query = "";
  $result = "";
  return $list;
}

/**
 * function for get total contents by date & uid
 * @pram datetime $start_date
 * @pram int $uid
 *
 * @return int $count
 */

function getContentCountByDateAndByUid($start_date, $end_date, $uid) {
  $query_cont = db_select('node', 'n');
  $query->leftJoin('itg_multi_byline_info', 'byi', 'n.nid=byi.nid');
  $query_cont->fields('n', array('nid'));
  //end
  if ($start_date != "na") {    
    $query_cont->condition('n.created', $start_date, ">=");
  }
  if ($end_date != "na") {    
    $query_cont->condition('n.created', $end_date, "<=");
  }
  $query_cont->condition('byi.nid', $uid);
  $result_cont = $query_cont->execute()->fetchAll();  
  $total_records = count($result_cont);
  $query_cont = "";
  $result_cont = "";
  return $total_records;
}
function getContentCountByDateAndByUid_bk($start_date, $uid) {
  $query_cont = db_select('node', 'n');
  $query_cont->fields('n', array('nid'));
  //end
  if ($start_date != "na") {
    //$start_date_timestamp = strtotime($start_date);
    $query_cont->condition('n.created', $start_date, ">=");
  }

  $query_cont->condition('n.uid', $uid);
  $result_cont = $query_cont->execute()->fetchAll();
  //return $query->countQuery()->execute()->fetchField();
  $total_records = count($result_cont);
  $query_cont = "";
  $result_cont = "";
  return $total_records;
}

/**
 * function for today contents by uid
 * @pram datetime $start_date
 * @pram int $uid
 *
 * @return int $count
 */
function todayContentsByUid($start_date, $uid) {
  $list = array();
  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'title'));
  $query->condition('n.created', $start_date, ">=");
  $query->condition('n.uid', $uid);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $loop_cont = 0;
  foreach ($result as $reskey => $resvalue) {
    $nid = $resvalue[nid];
    $title = $resvalue[title];
    $list[$loop_cont]['nid'] = $nid;
    $list[$loop_cont]['title'] = $title;
    $loop_cont++;
  }
  $query = "";
  $result = "";
  return $list;
}

function getBYlineDetail($nid) {
    $byline_data = array();
    if($nid){
        $query_n = db_select('node', 'n');
        $query_n->leftJoin('field_data_field_reporter_email_id', 're', 'n.nid = re.entity_id');
        $query_n->fields('n', array('nid', 'title', 'status'));
        $query_n->fields('re', array('field_reporter_email_id_value'));
        $query_n->condition('n.nid', $nid, '=');
        $result_n = $query_n->execute()->fetchAll(PDO::FETCH_ASSOC);
        foreach ($result_n as $reskey_n => $resvalue_n) {
            $nid = $resvalue_n['nid'];
            $title = $resvalue_n['title'];
            $status = $resvalue_n['status'];
            $field_reporter_email_id_value = $resvalue_n['field_reporter_email_id_value'];        
            $byline_data['nid'] = $nid;
            $byline_data['title'] = $title;
            $byline_data['status'] = $status;
            $byline_data['email'] = $field_reporter_email_id_value;

        }
    }
    return $byline_data;
}

