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
  $data['date details']['yesterday'] = date("d-F-Y", $yesterday);
  $data['date details']['month'] = $month;
  $data['date details']['year'] = $year;
  // site_snapshot  
  $month_s = date("M", $start_date);
  $year_s = date("Y", $start_date);
  $month_time_s = strtotime("" . $year_s . "-" . $month_s . "-01");
  $year_time_s = strtotime("" . $year_s . "-01-01");
  $today_unix = $start_date;
  $today_end = $start_date + 86399;
  $yesterday_unix = strtotime('-1 day', $today_unix);
  $yesterday_unix_end = $yesterday_unix + 86399;
  $month_prev_unix = $month_time_s;
  $month_prev_unix_end = $today_end;
  $year_prev_unix = $year_time_s;
  $year_prev_unix_end = $today_end;

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
  $data['auhtorwise_data']['site_id'] = "$site_id";    //auhtor_data
  $author_list = getAuthorList_Report($today_unix, $today_end);
  // start loop on author list array
  $author_loop_cont = 0;
  $auhtor_data = array();
  foreach ($author_list as $key => $value) {
    $user_id = $value['author_id'];
    $name = getAuthorNameDashboard($user_id);
    $mail = $value['author_email'];
    $today_total_uid = getContentCountByDateAndByUid($today_unix, $today_end, $mail);
    $yesterday_total_uid = getContentCountByDateAndByUid($yesterday_unix, $yesterday_unix_end, $mail);
    $month_total_uid = getContentCountByDateAndByUid($month_prev_unix, $month_prev_unix_end, $mail);
    $year_total_uid = getContentCountByDateAndByUid($year_prev_unix, $year_prev_unix_end, $mail);
    $auhtor_data[$author_loop_cont]['author_id'] = "$user_id";
    $auhtor_data[$author_loop_cont]['author_email'] = "$mail";
    $auhtor_data[$author_loop_cont]['author_name'] = "$name";
    $auhtor_data[$author_loop_cont]['site_id'] = "$site_id";
    $auhtor_data[$author_loop_cont]['today'] = "$today_total_uid";
    $auhtor_data[$author_loop_cont]['yesterday'] = "$yesterday_total_uid";
    $auhtor_data[$author_loop_cont]['month'] = "$month_total_uid";
    $auhtor_data[$author_loop_cont]['year'] = "$year_total_uid";
    //auhtor_data contents
    $author_today_data = todayContentsByUid($today_unix, $today_end, $mail);
    //loop author today data
    $author_inner_loop_cont = 0;
    $contents = array();
    foreach ($author_today_data as $today_key => $today_val) {
      $title = $today_val['title'];
      $nid = $today_val['nid'];
      $desc = kickerByNid($nid);
      $title_path = drupal_get_path_alias('node/' . $nid . '');
      $contents[$author_inner_loop_cont]['author_id'] = "$user_id";
      $contents[$author_inner_loop_cont]['author_email'] = "$mail";
      $contents[$author_inner_loop_cont]['author_name'] = "$name";
      $contents[$author_inner_loop_cont]['site_id'] = "$site_id";
      $contents[$author_inner_loop_cont]['content_id'] = "$nid";
      $contents[$author_inner_loop_cont]['introtext'] = "$desc";
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
  $data['date details']['yesterday'] = date("d-F-Y", $yesterday);
  $data['date details']['month'] = $month;
  $data['date details']['year'] = $year;
  // site_snapshot  
  $month_s = date("M", $start_date);
  $year_s = date("Y", $start_date);
  $month_time_s = strtotime("" . $year_s . "-" . $month_s . "-01");
  $year_time_s = strtotime("" . $year_s . "-01-01");
  $today_unix = $start_date;
  $today_end = $start_date + 86399;
  $yesterday_unix = strtotime('-1 day', $today_unix);
  $yesterday_unix_end = $yesterday_unix + 86399;
  $month_prev_unix = $month_time_s;
  $month_prev_unix_end = $today_end;
  $year_prev_unix = $year_time_s;
  $year_prev_unix_end = $today_end;

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
  p($author_list);
  foreach ($author_list as $key => $value) {
    $user_id = $value['author_id'];
    $name = getAuthorNameDashboard($user_id);
    $mail = $value['author_email'];
    $today_total_uid = getContentCountByDateAndByUid($today_unix, $today_end, $mail);
    $yesterday_total_uid = getContentCountByDateAndByUid($yesterday_unix, $yesterday_unix_end, $mail);
    $month_total_uid = getContentCountByDateAndByUid($month_prev_unix, $month_prev_unix_end, $mail);
    $year_total_uid = getContentCountByDateAndByUid($year_prev_unix, $year_prev_unix_end, $mail);
    $auhtor_data[$author_loop_cont]['author_id'] = "$user_id";
    $auhtor_data[$author_loop_cont]['author_email'] = "$mail";
    $auhtor_data[$author_loop_cont]['author_name'] = "$name";
    $auhtor_data[$author_loop_cont]['site_id'] = "$site_id";
    $auhtor_data[$author_loop_cont]['today'] = "$today_total_uid";
    $auhtor_data[$author_loop_cont]['yesterday'] = "$yesterday_total_uid";
    $auhtor_data[$author_loop_cont]['month'] = "$month_total_uid";
    $auhtor_data[$author_loop_cont]['year'] = "$year_total_uid";
    //auhtor_data contents
    $author_today_data = todayContentsByUid($today_unix, $today_end, $mail);
    //loop author today data
    $author_inner_loop_cont = 0;
    $contents = array();
    foreach ($author_today_data as $today_key => $today_val) {
      $title = $today_val['title'];
      $nid = $today_val['nid'];
      $desc = kickerByNid($nid);
      $title_path = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid . '');
      $contents[$author_inner_loop_cont]['author_id'] = "$user_id";
      $contents[$author_inner_loop_cont]['author_email'] = "$mail";
      $contents[$author_inner_loop_cont]['author_name'] = "$name";
      $contents[$author_inner_loop_cont]['site_id'] = "$site_id";
      $contents[$author_inner_loop_cont]['content_id'] = "$nid";
      $contents[$author_inner_loop_cont]['introtext'] = "$desc";
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

  $cont = 0;
  $flag = 0;
  $query = db_select('node', 'n');
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->leftJoin('itg_multi_byline_info', 'byli', 'byli.nid=n.nid');
  $query->leftJoin('field_data_field_reporter_email_id', 'repr', 'byli.byline_id=repr.entity_id');
  $query->fields('n', array('nid', 'status'));
  $query->fields('byli', array('byline_id'));
  $query->fields('repr', array('field_reporter_email_id_value'));
  //end
  if ($start_date != "na") {
    $query->condition('n.created', $start_date, ">=");
    $query->condition('n.created', $end_date, "<=");
  }
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story');
  $query->condition('ti.tid', '1206640', '<>');
  $query->condition('repr.field_reporter_email_id_value', '%aajtak.com', 'LIKE');
  $query->groupBy('n.nid');
  $result = $query->execute();
  $cont = $result->rowCount();
  return $cont;
}

/**
 * function for generate author Flag array
 * @pram int $nid, $status
 * @return int authorflag
 */
function getbylineFlag($nid, $status) {
  $flag = 0;
  if (!empty($nid) && !empty($status)) {
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_reporter_email_id', 'rem', 'n.nid = rem.entity_id');
    $query->fields('rem', array('field_reporter_email_id_value'));
    $query->condition('n.nid', $nid, '=');
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    foreach ($result as $reskey => $resvalue) {
      $email = $resvalue['field_reporter_email_id_value'];
      if (strpos($email, 'aajtak.com') !== false) {
        $flag = 1;
        break;
      }
    }
  }
  return $flag;
}

/**
 * function for generate author detail array
 * @pram $nid, $status
 * @return array authorDetail
 */
function getbylineDetail($nid, $status) {
  $data = array();
  if (!empty($nid) && !empty($status)) {
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_reporter_email_id', 'rem', 'n.nid = rem.entity_id');
    $query->fields('rem', array('field_reporter_email_id_value'));
    $query->fields('n');
    $query->condition('s.nid', $nid, '=');
    $query->condition('s.publish_status', $status, '=');
    $query->condition('n.type', 'reporter', '=');
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    foreach ($result as $reskey => $resvalue) {
      $email = $resvalue['field_reporter_email_id_value'];
      if (strpos($email, 'aajtak.com') !== false) {
        $data['author_id'] = $resvalue['nid'];
        $data['author_name'] = $resvalue['title'];
        $data['author_email'] = $email;
      }
    }
  }
  return $data;
}

/**
 * function for generate author list array
 *
 * @return array authorList
 */
function getAuthorList_Report($s_date, $e_date) {
  global $base_url;
  $list = array();
  $cont = 0;
  $flag = 0;
  $query = db_select('itg_multi_byline_info', 'byli');
  $query->leftJoin('node', 'n', 'byli.nid=n.nid');
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->leftJoin('field_data_field_reporter_email_id', 'repr', 'repr.entity_id=byli.byline_id');
  $query->fields('n', array('nid', 'status'));
  $query->fields('byli', array('byline_id'));
  $query->fields('repr', array('field_reporter_email_id_value'));
  //end
  if ($start_date != "na") {
    $query->condition('n.created', $s_date, ">=");
    $query->condition('n.created', $e_date, "<=");
  }
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story');
  $query->condition('ti.tid', '1206640', '<>');
  $query->condition('repr.field_reporter_email_id_value', '%aajtak.com', 'LIKE');
  $query->groupBy('n.nid');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  foreach ($result as $reskey => $resvalue) {
    $author_nid = $resvalue['byline_id'];
    $author_name = getAuthorNameDashboard($author_id);
    $data['author_id'] = $author_nid;
    $data['author_name'] = $author_name;
    $data['author_email'] = $resvalue['field_reporter_email_id_value'];
    $list[$author_nid] = $data;
    $cont++;
  }

  //$list = array_unique($list);  
  return $list;
}

/**
 * function for get total contents by date & uid
 * @pram datetime $start_date
 * @pram int $uid
 *
 * @return int $count
 */
function getContentCountByDateAndByUid($start_date, $end_date, $email) {
  $cont = 0;
  $flag = 0;
  $query = db_select('node', 'n');
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->leftJoin('itg_multi_byline_info', 'byli', 'byli.nid=n.nid');
  $query->leftJoin('field_data_field_reporter_email_id', 'repr', 'byli.byline_id=repr.entity_id');
  $query->fields('n', array('nid', 'status'));
  $query->fields('byli', array('byline_id'));
  $query->fields('repr', array('field_reporter_email_id_value'));
  //end
  if ($start_date != "na") {
    $query->condition('n.created', $start_date, ">=");
    $query->condition('n.created', $end_date, "<=");
  }
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story');
  $query->condition('ti.tid', '1206640', '<>');
  $query->condition('repr.field_reporter_email_id_value', $email, '=');
  $query->groupBy('n.nid');
  $result = $query->execute();
  $cont = $num_of_results = $result->rowCount();
  return $cont;
}

/**
 * function for generate author Flag by email array
 * @pram int $nid, $status
 * @return int authorflag
 */
function getbylineFlagByEmail($nid, $status, $email) {
  $flag = 0;
  if (!empty($nid) && !empty($status)) {
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_reporter_email_id', 'rem', 'n.nid = rem.entity_id');
    $query->fields('rem', array('field_reporter_email_id_value'));
    $query->condition('s.nid', $nid, '=');
    $query->condition('s.publish_status', $status, '=');
    $query->condition('n.type', 'reporter', '=');
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    foreach ($result as $reskey => $resvalue) {
      $email_g = $resvalue['field_reporter_email_id_value'];
      if ($email_g == $email) {
        $flag = 1;
        break;
      }
    }
  }
  return $flag;
}

/**
 * function for today contents by uid
 * @pram datetime $start_date
 * @pram int $uid
 *
 * @return int $count
 */
function todayContentsByUid($start_date, $end_date, $mail) {
  $list = array();
  $cont = 0;
  $flag = 0;
  $query = db_select('node', 'n');
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->leftJoin('itg_multi_byline_info', 'byli', 'byli.nid=n.nid');
  $query->leftJoin('field_data_field_reporter_email_id', 'repr', 'byli.byline_id=repr.entity_id');
  $query->fields('n', array('nid', 'status', 'title'));
  $query->fields('byli', array('byline_id'));
  $query->fields('repr', array('field_reporter_email_id_value'));
  //end
  if ($start_date != "na") {
    $query->condition('n.created', $start_date, ">=");
    $query->condition('n.created', $end_date, "<=");
  }
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story');
  $query->condition('ti.tid', '1206640', '<>');
  $query->condition('repr.field_reporter_email_id_value', $mail, '=');
  $query->groupBy('n.nid');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  foreach ($result as $reskey => $resvalue) {
    $nid = $resvalue['nid'];
    $list[$cont]['nid'] = $nid;
    $list[$cont]['title'] = $resvalue['title'];
    $cont++;
  }

  return $list;
}

/**
 * function for kickerByNid
 * @pram int $nid
 * @return string $desc
 */
function kickerByNid($nid) {
  $desc = "";
  if ($nid) {
    $query_n = db_select('field_data_field_story_kicker_text', 'kt');
    $query_n->fields('kt', array('field_story_kicker_text_value'));
    $query_n->condition('kt.entity_id', $nid, '=');
    $result_n = $query_n->execute()->fetchAll(PDO::FETCH_ASSOC);
    foreach ($result_n as $reskey_n => $resvalue_n) {
      $desc = $resvalue_n['field_story_kicker_text_value'];
    }
  }
  return $desc;
}
