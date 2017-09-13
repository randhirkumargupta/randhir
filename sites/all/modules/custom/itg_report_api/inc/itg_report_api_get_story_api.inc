<?php

/**
 * Inc file contains the functions for story_Count_report API 
 */

/**
 * main function for generate getStoryAPI array
 * @pram datetime $start_date
 * @pram datetime $end_date
 * @pram string $type
 * @pram int $status
 * @pram int $item_per_page
 * @return array
 */
function getStoryAPI($start_date, $end_date, $type, $status, $item_per_page, $pageno = 0) {

    global $base_url;
    $list = array();
    $data = array();
    $total_cont = 0;
    $range_max = $item_per_page;
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
    if ($start_date != "na") {
        $start_date_timestamp = strtotime($start_date);
        $query->condition('n.created', $start_date_timestamp, ">=");
    }
    if ($end_date != "na") {
        $end_date_timestamp = strtotime($end_date);
        $query->condition('n.created', $end_date_timestamp, "<=");
    }
    if ($type != "na") {
        $query->condition('n.type', $type);
    }
    $query->condition('n.status', 1)->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);
    //$total_records = $query->countQuery()->execute()->fetchField();
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    foreach ($result as $reskey => $resvalue) {
        //p($resvalue); die();
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
        $video_embed = "no";
        // list data
        $list[$nid]['id'] = "$nid";
        $list[$nid]['title'] = "$title";
        $list[$nid]['url'] = "$url";
        $list[$nid]['word_count'] = "$wordcount";
        $list[$nid]['published_datetime'] = "$field_itg_content_publish_date_value";
        $list[$nid]['section_name'] = "$prime_cat->name";
        $list[$nid]['created_datetime'] = "$created_datetime";
        $list[$nid]['video_embed'] = "$video_embed";
        $list[$nid]['created_by'] = "$created_by";
    }
    //$start_date, $end_date, $type, $status, $item_per_page, $pageno = 0
    $total_records = totalRecordsCount_StoryAPI($start_date, $end_date, $type, $status, $item_per_page, $pageno);
    //$next_page_no = $pageno + 1;
    //$next_page_url = $base_url . "/reportapi/story_count_report?start_date=" . $start_date . "&end_date=" . $end_date . "&type=" . $type . "&status=" . $status . "&item_per_page=" . $item_per_page . "&pageno=" . $next_page_no . "";
    $data['results'] = $list;
    $data['total_records'] = "$total_records";
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
 * @return int $total_records 
 */
function totalRecordsCount_StoryAPI($start_date, $end_date, $type, $status, $item_per_page, $pageno) {
    $query_cont = db_select('node', 'n');
    $query_cont->fields('n', array('nid'));
    //end   
    if ($start_date != "na") {
        $start_date_timestamp = strtotime($start_date);
        $query_cont->condition('n.created', $start_date_timestamp, ">=");
    }
    if ($end_date != "na") {
        $end_date_timestamp = strtotime($end_date);
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
