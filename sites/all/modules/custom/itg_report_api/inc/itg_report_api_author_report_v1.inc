<?php

/**
 * Inc file contains the functions for author report - TVTN report API
 */

/**
 * main function for generate author report array
 * @pram datetime $start_date
 * @return array
 */
function author_report_v1($start_date, $type) {    
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

    $today_total = getContentCountByDate_v1($today_unix, $today_end, $type);
    $yesterday_total = getContentCountByDate_v1($yesterday_unix, $yesterday_unix_end, $type);
    $month_total = getContentCountByDate_v1($month_prev_unix, $month_prev_unix_end, $type);
    $year_total = getContentCountByDate_v1($year_prev_unix, $year_prev_unix_end, $type);
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
    $author_list = getAuthorList_Report_v1($today_unix, $today_end, $type);
    // start loop on author list array
    $author_loop_cont = 0;
    $auhtor_data = array();
    foreach ($author_list as $key => $value) {
        $user_id = $value['author_id'];
        $name = getAuthorNameDashboard($user_id);
        $mail = $value['author_email'];
        $today_total_uid = getContentCountByDateAndByUid($today_unix, $today_end, $mail, $type);
        $yesterday_total_uid = getContentCountByDateAndByUid($yesterday_unix, $yesterday_unix_end, $mail, $type);
        $month_total_uid = getContentCountByDateAndByUid($month_prev_unix, $month_prev_unix_end, $mail, $type);
        $year_total_uid = getContentCountByDateAndByUid($year_prev_unix, $year_prev_unix_end, $mail, $type);
        $auhtor_data[$author_loop_cont]['author_id'] = "$user_id";
        $auhtor_data[$author_loop_cont]['author_email'] = "$mail";
        $auhtor_data[$author_loop_cont]['author_name'] = "$name";
        $auhtor_data[$author_loop_cont]['site_id'] = "$site_id";
        $auhtor_data[$author_loop_cont]['today'] = "$today_total_uid";
        $auhtor_data[$author_loop_cont]['yesterday'] = "$yesterday_total_uid";
        $auhtor_data[$author_loop_cont]['month'] = "$month_total_uid";
        $auhtor_data[$author_loop_cont]['year'] = "$year_total_uid";
        //auhtor_data contents
        $author_today_data = todayContentsByUid($today_unix, $today_end, $mail, $type);
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
        } else {
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
function getContentCountByDate_v1($start_date, $end_date, $type) {    
    $cont = 0;
    $flag = 0;
    $content_type = $type;
    $query = db_select('node', 'n');
    if ($content_type == 'story') {
        $query->leftJoin('field_data_field_story_category', 'pc', 'pc.entity_id=n.nid');
        $query->leftJoin('itg_multi_byline_info', 'byli', 'byli.nid=n.nid');
        $query->leftJoin('field_data_field_reporter_email_id', 'repr', 'byli.byline_id=repr.entity_id');
    }
    if ($content_type == 'videogallery') {
        $query->leftJoin('field_data_field_story_reporter', 'fsr', 'fsr.entity_id=n.nid');
        $query->leftJoin('field_data_field_reporter_email_id', 'repr', 'fsr.field_story_reporter_target_id=repr.entity_id');
    }
    if ($_GET['author_report'] == 1) {
        $query->leftJoin('field_data_field_author_report', 'autr', 'byli.byline_id=autr.entity_id');
    }
    if ($content_type == 'videogallery') {
        $query->leftJoin('field_data_field_mis_report', 'mis', 'n.nid=mis.entity_id');
    }
    $query->fields('n', array('nid', 'status'));
    if ($content_type == 'story') {
        $query->fields('byli', array('byline_id'));
    }
    $query->fields('repr', array('field_reporter_email_id_value'));
    if ($_GET['author_report'] == 1) {
        $query->fields('autr', array('field_author_report_value'));
    }
    if ($content_type == 'videogallery') {
        $query->fields('mis', array('field_mis_report_value'));
        $query->fields('fsr', array('field_story_reporter_target_id'));
    }
    //end
    if ($start_date != "na") {
        $query->condition('n.created', $start_date, ">=");
        $query->condition('n.created', $end_date, "<=");
    }
    $query->condition('n.status', 1);
    $query->condition('n.type', $content_type);
    if ($content_type == 'story') {
        $query->condition('pc.field_story_category_tid', '1206640', '<>');
        $query->condition('pc.bundle', $content_type);
    }
    if ($content_type == 'story') {
        if ($_GET['author_report'] != 1) {
            $query->condition('repr.field_reporter_email_id_value', '%aajtak.com', 'LIKE');
        } else {
            $query->condition('autr.field_author_report_value', 'author_report', '=');
        }
    }
    if ($content_type == 'videogallery') {
        $query->condition('mis.field_mis_report_value', 'mis_report', '=');
    }
    $query->groupBy('n.nid');
    $result = $query->execute();
    $cont = $result->rowCount();
    return $cont;
}


/**
 * function for generate author list array
 *
 * @return array authorList
 */
function getAuthorList_Report_v1($s_date, $e_date, $type) {
    
    global $base_url;
    $list = array();
    $cont = 0;
    $flag = 0;
    $content_type = $type;


    $query = db_select('node', 'n');

    if ($content_type == 'story') {
        $query->leftJoin('itg_multi_byline_info', 'byli', 'byli.nid=n.nid');
        $query->leftJoin('field_data_field_story_category', 'pc', 'pc.entity_id=n.nid');
        $query->leftJoin('field_data_field_reporter_email_id', 'repr', 'repr.entity_id=byli.byline_id');
    }

    if ($_GET['author_report'] == 1) {
        $query->leftJoin('field_data_field_author_report', 'autr', 'byli.byline_id=autr.entity_id');
    }
    if ($content_type == 'videogallery') {
        $query->leftJoin('field_data_field_mis_report', 'mis', 'n.nid=mis.entity_id');
        $query->leftJoin('field_data_field_story_reporter', 'fsr', 'fsr.entity_id=n.nid');
        $query->leftJoin('field_data_field_reporter_email_id', 'repr', 'fsr.field_story_reporter_target_id=repr.entity_id');
        
    }
    $query->fields('n', array('nid', 'status'));
    if ($content_type == 'story') {
        $query->fields('byli', array('byline_id'));
    }
    $query->fields('repr', array('field_reporter_email_id_value'));
    if ($_GET['author_report'] == 1) {
        $query->fields('autr', array('field_author_report_value'));
    }
    if ($content_type == 'videogallery') {
        $query->fields('mis', array('field_mis_report_value'));
        $query->fields('fsr', array('field_story_reporter_target_id'));
    }
    //end
    if ($start_date != "na") {
        $query->condition('n.created', $s_date, ">=");
        $query->condition('n.created', $e_date, "<=");
    }

    $query->condition('n.status', 1);
    $query->condition('n.type', $content_type);
    if ($content_type == 'story') {
        $query->condition('pc.field_story_category_tid', '1206640', '<>');
        $query->condition('pc.bundle', $content_type);
    }
    if ($content_type == 'story') {
        if ($_GET['author_report'] != 1) {
            $query->condition('repr.field_reporter_email_id_value', '%aajtak.com', 'LIKE');
            $query->groupBy('n.nid');
        } else {
            $query->condition('autr.field_author_report_value', 'author_report', '=');
        }
    }
    if ($content_type == 'videogallery') {
        $query->condition('mis.field_mis_report_value', 'mis_report', '=');
    }

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    foreach ($result as $reskey => $resvalue) {
        $author_nid = $resvalue['byline_id'];
        if($content_type == 'videogallery') {
            $author_nid = $resvalue['field_story_reporter_target_id'];
        }
        $author_name = getAuthorNameDashboard($author_nid);
        $data['author_id'] = $author_nid;
        $data['author_name'] = $author_name;
        $data['author_email'] = $resvalue['field_reporter_email_id_value'];
        $list[$author_nid] = $data;
        $cont++;
    }

    //$list = array_unique($list);
    return $list;
}




