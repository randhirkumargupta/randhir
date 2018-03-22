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
    $next_page_url = $base_url . "/reportapi/story_count_report?start_date=" . date('Y-m-d', $start_date) . "&end_date=" . date('Y-m-d', $end_date) . "&type=" . $type . "&status=" . $status . "&item_per_page=" . $item_per_page . "&pageno=" . $next_page_no . "";
    $data['results'] = $list;
    $data['total_records'] = "$total_records";
    $data['next_page_url'] = "$next_page_url";
    //secrtion data report
    $section_data = array();
    $section_data = getSectionCountData_report($start_date, $end_date, $type, $status);
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
    $query->condition('n.status', $status)->orderBy('n.created', 'DESC');
    $result_cont = $query->execute()->fetchAll();
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
function getSectionCountData_report($start_date, $end_date, $type, $status) {
    global $base_url;
    $section_data = array();
    $section_list_count = array();
    $vid = 14;
    $section_list = getSectionListByVID($vid);

    $loop_count = 0;
    foreach ($section_list as $key => $value) {
        $n_cont = 0;
        $n_cont = countTidNode_report($start_date, $end_date, $value['tid'], $type, $status);
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
function countTidNode_report($start_date, $end_date, $tid, $type, $status) {
    $synd = empty($_GET['synd']) ? 0 : $_GET['synd'];
    $exclude_agency = empty($_GET['exclude_agency']) ? 0 : $_GET['exclude_agency'];
    $agencies = array('ANI', 'AP', 'IANS', 'Mail Today', 'PTI', 'Reuters');
    //story count between
    $query = db_select('node', 'n');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
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
//    if ($start_date != "na") {
//        $query->condition('n.created', $start_date, ">=");
//    }
//    if ($end_date != "na") {
//        $query->condition('n.created', $end_date, "<=");
//    }
    if($start_date != "na" && $end_date != "na"){
        $start_date_timestamp = $start_date . " 00:00:00";
        $end_date_timestamp = $end_date . " 23:59:00";
        $query->condition('npd.field_itg_content_publish_date_value', array($start_date_timestamp, $end_date_timestamp), 'BETWEEN');
    }
    if ($type != "na") {
        $query->condition('n.type', $type);
    }
    
    if($_GET['type'] == 'fb'){
      $query->join('field_data_field_story_social_media_integ', 'ssmi', 'ssmi.entity_id=n.nid');
      $query->condition('ssmi.field_story_social_media_integ_value', 'facebook_instant_article', 'LIKE');
    }
    
    if ($synd) {
      $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
      $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    }
    
    if ($exclude_agency) {
      $query->join('field_data_field_story_source_type', 'fsst', 'fsst.entity_id=n.nid');
      $query->condition('fsst.field_story_source_type_value', $agencies , 'NOT IN');
      //$query->join('field_data_field_primary_category', 'fpc', 'fpc.entity_id=n.nid');
      $query->condition('fpc.field_primary_category_value', '1206640', '!='); //PTI category
    }
    if($tid != '1206640'){
      $query->condition('ti.tid', $tid, '='); 
    }
    if($type == 'story'){
      $query->condition('repr.field_reporter_email_id_value', NULL, 'IS NOT');
    }    
    $query->groupBy('n.nid');
    $query->condition('n.status', $status)->orderBy('n.created', 'DESC');
    
    //print strtr((string)$query,$query->arguments());die;
    $result = $query->execute()->fetchAll();
    $total_records_between = count($result);
    return $total_records_between;
}

/**
 * main function for generate story/photo/video datalist report
 * @pram datetime $start_date
 * @pram datetime $end_date
 * @pram string $type
 * @pram int $status
 *
 * @param boolen $synd
 * @pram int $item_per_page
 *
 * @return array
 */
function get_datalist_report($start_date, $end_date, $type, $status, $synd, $item_per_page, $pageno = 0) {

    global $base_url;
    $list = array();
    $data = array();
    $total_cont = 0;
    $range_max = $item_per_page;
    $all_tids = array();
    $synd = empty($_GET['synd']) ? 0 : $_GET['synd'];
    if($type == 'fb'){
      $type = 'story';
    }
    
    $exclude_agency = empty($_GET['exclude_agency']) ? 0 : $_GET['exclude_agency'];
    $agencies = array('ANI', 'AP', 'IANS', 'Mail Today', 'PTI', 'Reuters');
    //$photolist = array();
    if (!$pageno == 0) {
        $range_min = $pageno * $range_max;
    } else {
        $range_min = 0;
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
     if($start_date != "na" && $end_date != "na"){
        $start_date_timestamp = $start_date . " 00:00:00";
        $end_date_timestamp = $end_date . " 23:59:00";
        $query->condition('npd.field_itg_content_publish_date_value', array($start_date_timestamp, $end_date_timestamp), 'BETWEEN');
    }
    if ($type != "na") {
        $query->condition('n.type', $type);
    }
    if ($synd) {
      $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
      $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    }
    
    if ($exclude_agency) {
      $query->join('field_data_field_story_source_type', 'fsst', 'fsst.entity_id=n.nid');
      $query->condition('fsst.field_story_source_type_value', $agencies , 'NOT IN');
      //$query->join('field_data_field_primary_category', 'fpc', 'fpc.entity_id=n.nid');
      $query->condition('fpc.field_primary_category_value', '1206640', '!='); //PTI category
    }
    
    if($_GET['type'] == 'fb'){
      $query->join('field_data_field_story_social_media_integ', 'ssmi', 'ssmi.entity_id=n.nid');
      $query->condition('ssmi.field_story_social_media_integ_value', 'facebook_instant_article', 'LIKE');
    }
    
    
    if ($status != '') {
        $query->condition('n.status', $status);
    }
    $query->orderBy('npd.field_itg_content_publish_date_value', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);
    //print strtr((String)$query, $query->arguments());die;
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $loopc = 1;
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
        $last_pub_date = date("Y-m-d H:i:s", strtotime($field_itg_content_publish_date_value));
        $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);
        $created_by = getNodeCreatedBy_UserName($uid);
        $wordcount = str_word_count($body_value);
        $created_datetime = date("Y-m-d H:i:s", $created);
        $prime_cat = get_prime_cat_by_nid($nid);
        $all_tids[] = $prime_cat->tid;

        $html = html_entity_decode($body_value);
        $doc = new DOMDocument();
        libxml_use_internal_errors(TRUE);
        $doc->loadHTML($html);
        $xpath = new DOMXPath($doc);
        $nodelist = $xpath->query("//iframe");
        $node = $nodelist->item(0);
        $iframe_code = getStringBetween($html, '<iframe', '</iframe>');
        $video_path = getStringBetween($iframe_code, 'src="', '"');
        $video_embed = 'No';
        if (strpos($video_path, '/embed/')) {
            $video_embed = 'Yes';
        } elseif (strpos($video_path, '/embeded-video/')) {
            $video_embed = 'Yes';
        }
        $social_query = db_select('jos_social_media_sharing', 'sm')
                        ->fields('sm', array('is_promoted', 'promotion_remark'))
                        ->condition('sm.content_id', $nid)
                        ->condition('sm.content_type', $type)
                        ->execute()->fetchAll(PDO::FETCH_ASSOC);
        $is_promoted = $social_query[0]['is_promoted'];
        $promotion_remark = $social_query[0]['promotion_remark'];
        // list data
        $list[$loopc]['is_promoted'] = "$is_promoted";
        $list[$loopc]['promotion_remark'] = "$promotion_remark";
        $list[$loopc]['id'] = "$nid";
        $list[$loopc]['title'] = "$title";
        $list[$loopc]['url'] = "$url";
        $list[$loopc]['word_count'] = "$wordcount";
        $list[$loopc]['published_datetime'] = "$last_pub_date";
        $list[$loopc]['section_name'] = "$prime_cat->name";
        $list[$loopc]['created_datetime'] = "$created_datetime";
        $list[$loopc]['video_embed'] = "$video_embed";
        $list[$loopc]['created_by'] = "$created_by";
        $loopc++;
    }
    
    $total_records = report_totalRecordsCount($start_date, $end_date, $type, $status, $synd, $item_per_page, $pageno);
    $next_page_no = $pageno + 1;
//    if ($type == 'videogallery') {
//        $type = 'video';
//    }
//    if ($type == 'photogallery') {
//        $type = 'gallery';
//    }
//    if ($status == 0) {
//        $status = 'unpublish';
//    } elseif ($status == 1) {
//        $status = 'publish';
//    }
    $next_page_url = $base_url . "/reportapi/report_api_data_list?start_date=" . $start_date . "&end_date=" . $end_date . "&type=" . $type . "&status=" . $status . "&synd=" . $synd . "&item_per_page=" . $item_per_page . "&pageno=" . $next_page_no . "";
    if (count($result) < $item_per_page) {
        $next_page_url = '';
    }
    $data['results'] = $list;
    $data['total_records'] = "$total_records";
    $data['next_page_url'] = "$next_page_url";
    //secrtion data report
    $section_data = array();
    $section_data = report_getSectionCountData_report($start_date, $end_date, $all_tids,$type, $status);
    $data['section_data'] = $section_data;
    //p($data);
    return $data;
}

/**
 * function for get primary term
 *
 * @param $nid node id
 */
function get_prime_cat_by_nid($nid) {
    $query = db_select('field_data_field_primary_category', 'fpc');
    $query->fields('fpc', array('field_primary_category_value'));
    $query->condition('fpc.entity_id', $nid);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $field_primary_category_value = $result[0]['field_primary_category_value'];
    return taxonomy_term_load($field_primary_category_value);
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
function report_totalRecordsCount($start_date, $end_date, $type, $status, $synd, $item_per_page, $pageno) {
    $synd = empty($_GET['synd']) ? 0 : $_GET['synd'];
    $exclude_agency = empty($_GET['exclude_agency']) ? 0 : $_GET['exclude_agency'];
    $agencies = array('ANI', 'AP', 'IANS', 'Mail Today', 'PTI', 'Reuters');
    
    $query_cont = db_select('node', 'n');
    $query_cont->fields('n', array('nid'));
    $query_cont->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    //end
//    if ($start_date != "na") {
//        $start_date_timestamp = strtotime($start_date . " 01:01:00");
//        $query_cont->condition('n.created', $start_date_timestamp, ">=");
//    }
//    if ($end_date != "na") {
//        $end_date_timestamp = strtotime($end_date . " 23:59:00");
//        $query_cont->condition('n.created', $end_date_timestamp, "<=");
//    }
    if($start_date != "na" && $end_date != "na"){
        $start_date_timestamp = $start_date . " 00:00:00";
        $end_date_timestamp = $end_date . " 23:59:00";
        $query_cont->condition('npd.field_itg_content_publish_date_value', array($start_date_timestamp, $end_date_timestamp), 'BETWEEN');
    }
    if ($type != "na") {
        $query_cont->condition('n.type', $type);
    }
    if ($synd) {
      $query_cont->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
      $query_cont->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    }
    if($_GET['type'] == 'fb'){
      $query_cont->join('field_data_field_story_social_media_integ', 'ssmi', 'ssmi.entity_id=n.nid');
      $query_cont->condition('ssmi.field_story_social_media_integ_value', 'facebook_instant_article', 'LIKE');
    }
    
    if ($exclude_agency) {
      $query_cont->join('field_data_field_story_source_type', 'fsst', 'fsst.entity_id=n.nid');
      $query_cont->condition('fsst.field_story_source_type_value', $agencies , 'NOT IN');
      $query_cont->join('field_data_field_primary_category', 'fpc', 'fpc.entity_id=n.nid');
      $query_cont->condition('fpc.field_primary_category_value', '1206640', '!='); //PTI category
    }
     
    $query_cont->condition('n.status', $status)->groupBy('n.nid');
    $result_cont = $query_cont->execute()->fetchAll();
    $total_records = count($result_cont);
    return $total_records;
}

function report_getSectionCountData_report($start_date, $end_date, $all_tids,$type, $status) {
    global $base_url;
    $section_data = array();
    $section_list_count = array();
    $unique_tids = array_unique($all_tids);
    $loop_count = 0;
    foreach ($unique_tids as $value) {
        //p($value);die();
        $n_cont = 0;
        $n_cont = countTidNode_report($start_date, $end_date, $value,$type, $status);
        if ($n_cont) {
            $ntid = $value;
            $term = taxonomy_term_load($ntid);
            $section_data[$loop_count]['count'] = "$n_cont";
            $section_data[$loop_count]['section'] = "$term->name";
            $section_data[$loop_count]['section_id'] = "$ntid";
            $loop_count++;
        }
    }
    return $section_data;
}
