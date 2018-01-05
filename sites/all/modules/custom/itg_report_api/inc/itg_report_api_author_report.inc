<?php

/**
 * Inc file contains the functions for story_Count_report API 
 */

/**
 * main function for generate author report - TVTN array
 * @pram datetime $start_date
 * @return array
 */
function author_report_tvtn($start_date) {
    global $base_url;
    $data = array();
    $prev_day = time() - ( 24 * 60 * 60);
    $hour = 01;
  $today = strtotime($hour . ':00:00');
  $yesterday = strtotime('-1 day', $today);
    $month = date("M-Y", $start_date);
    $year = date("Y", $start_date);
    $site_id = 1;
    $site_name = "India Today";

    // date details
    $data['date details']['today'] = $today;
    $data['date details']['yesterday'] = $yesterday;
    $data['date details']['month'] = $month;
    $data['date details']['year'] = $year;

    // site_snapshot
    $hour = 12;
    $today_unix = strtotime($hour . ':00:00');
    $yesterday_unix = strtotime('-1 day', $today_unix);
    $month_prev_unix = strtotime('-1 month', $today_unix);
    $year_prev_unix = strtotime('-1 year', $today_unix);

    $today_total = getContentCountByDate($today_unix);
    $yesterday_total = getContentCountByDate($yesterday_unix);
    $month_total = getContentCountByDate($month_prev_unix);
    $year_total = getContentCountByDate($year_prev_unix);

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
    //p($author_list);die();
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
        //p($author_today_data);die();
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
        if($author_inner_loop_cont){
            $auhtor_data[$author_loop_cont]['contents'] = $contents;
        }
        else{
            unset($auhtor_data[$author_loop_cont]);
        }
        $author_loop_cont++;
    }
     //static author data
    $auhtor_data[0]['author_id'] = "1568";
    $auhtor_data[0]['author_email'] = "anand.patel@aajtak.com";
    $auhtor_data[0]['author_name'] = "Anand Patel";
    $auhtor_data[0]['site_id'] = "1";
    $auhtor_data[0]['today'] = "1";
    $auhtor_data[0]['yesterday'] = "1";
    $auhtor_data[0]['month'] = "1";
    $auhtor_data[0]['year'] = "1";
    
    $auhtor_data[0]['contents']['author_id'] = "1568";
    $auhtor_data[0]['contents']['author_email'] = "anand.patel@aajtak.com";
    $auhtor_data[0]['contents']['author_name'] = "Anand Patel";
    $auhtor_data[0]['contents']['site_id'] = "1";
    $auhtor_data[0]['contents']['content_url'] = "";
    $auhtor_data[0]['contents']['page_title'] = "Sharad Yadav shoots letter to";
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
    $prev_day = time() - ( 24 * 60 * 60);
    $hour = 01;
  $today = strtotime($hour . ':00:00');
  $yesterday = strtotime('-1 day', $today);
    $month = date("M-Y", $start_date);
    $year = date("Y", $start_date);
    $site_id = 1;
    $site_name = "India Today";

    // date details
    $data['date details']['today'] = $today;
    $data['date details']['yesterday'] = $yesterday;
    $data['date details']['month'] = $month;
    $data['date details']['year'] = $year;

    // site_snapshot
    $hour = 12;
    $today_unix = strtotime($hour . ':00:00');
    $yesterday_unix = strtotime('-1 day', $today_unix);
    $month_prev_unix = strtotime('-1 month', $today_unix);
    $year_prev_unix = strtotime('-1 year', $today_unix);

    $today_total = getContentCountByDate($today_unix);
    $yesterday_total = getContentCountByDate($yesterday_unix);
    $month_total = getContentCountByDate($month_prev_unix);
    $year_total = getContentCountByDate($year_prev_unix);

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
    //p($author_list);die();
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
        //p($author_today_data);die();
        //loop author today data
        $author_inner_loop_cont = 0;
        $contents = array();
        foreach ($author_today_data as $today_key => $today_val) {
            $title = $today_val['title'];
            $nid = $today_val['nid'];
            $title_path = $base_url."/".drupal_get_path_alias('node/' . $nid . '');
            $contents[$author_inner_loop_cont]['author_id'] = "$user_id";
            $contents[$author_inner_loop_cont]['author_email'] = "$mail";
            $contents[$author_inner_loop_cont]['author_name'] = "$name";
            $contents[$author_inner_loop_cont]['site_id'] = "$site_id";
            $contents[$author_inner_loop_cont]['content_url'] = "$title_path";
            $contents[$author_inner_loop_cont]['page_title'] = "$title";
            $author_inner_loop_cont++;
        }
        if($author_inner_loop_cont){
            $auhtor_data[$author_loop_cont]['contents'] = $contents;
        }
        else{
            unset($auhtor_data[$author_loop_cont]);
        }
        $author_loop_cont++;
    }
    //static author data
    $auhtor_data[0]['author_id'] = "1568";
    $auhtor_data[0]['author_email'] = "anand.patel@aajtak.com";
    $auhtor_data[0]['author_name'] = "Anand Patel";
    $auhtor_data[0]['site_id'] = "1";
    $auhtor_data[0]['today'] = "1";
    $auhtor_data[0]['yesterday'] = "1";
    $auhtor_data[0]['month'] = "1";
    $auhtor_data[0]['year'] = "1";
    
    $auhtor_data[0]['contents']['author_id'] = "1568";
    $auhtor_data[0]['contents']['author_email'] = "anand.patel@aajtak.com";
    $auhtor_data[0]['contents']['author_name'] = "Anand Patel";
    $auhtor_data[0]['contents']['site_id'] = "1";
    $auhtor_data[0]['contents']['content_url'] = "";
    $auhtor_data[0]['contents']['page_title'] = "Sharad Yadav shoots letter to";
    //$auhtor_data[0]['contents']['author_id'] = "1";
    
    
    $data['auhtorwise_data']['auhtor_data'] = $auhtor_data;

    return $data;
}

/**
 * function for get total contents by date
 * @pram datetime $start_date
 * @return int $count
 */
function getContentCountByDate($start_date) {
    $query_cont = db_select('node', 'n');
    $query_cont->fields('n', array('nid'));
    //end   
    if ($start_date != "na") {
        //$start_date_timestamp = strtotime($start_date);
        $query_cont->condition('n.created', $start_date, ">=");
    }

    //$query_cont->condition('n.status', 1);
    $result_cont = $query_cont->execute()->fetchAll();
    //return $query->countQuery()->execute()->fetchField();
    $total_records = count($result_cont);
    $query_cont = "";
    $result_cont = "";
    return $total_records;
}

/**
 * function for generate author list array 
 * @return array authorList
 */
function getAuthorList_Report() {
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
 * @return int $count
 */
function getContentCountByDateAndByUid($start_date, $uid) {
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
