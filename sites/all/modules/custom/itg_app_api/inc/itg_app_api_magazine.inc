<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate magazineEditionPageRerourceValue array
 *
 * @return array
 */
function magazineEditionPageRerourceValue($issueid = 0, $pageno = 0) {
    $output_array = array();
    $data_array = array();
    $photo_list_array = array();
    $updated_datetime = "";

    $term = taxonomy_term_load($tid);
    $term_name = $term->name;
    if (!$tid) {
        $term_name = "Latest";
    }
    // list array building
    $data = magazineEditionPageRerourceValueList($issueid, $pageno);

    if ($data['issue_nid'] > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }

    //data array building
    $datacount = $data['lcount'];
    $data_up_time = $data['updated_datetime'];

    $issue_date = $data['issue_date'];
    $issue_cover_image = $data['issue_cover_image'];
    $issue_digitalmag_url = $data['issue_digitalmag_url'];

    $data_array['issue_id'] = "$issueid";
    $data_array['issue_date'] = "$issue_date";
    $data_array['issue_cover_image'] = "$issue_cover_image";
    $data_array['issue_digitalmag_url'] = "$issue_digitalmag_url";
    $data_array['story_count'] = "$datacount";
    $data_array['story_display_count'] = "10";
    $data_array['story_pagination_cap'] = "7";
    $data_array['updated_datetime'] = "$data_up_time";

    $data_array['story'] = $data['data'];
    $output_array['data'] = $data_array;

    return $output_array;
}

/**
 * function for generate magazineEditionPageRerourceValueList array
 *
 * @return array
 */
function magazineEditionPageRerourceValueList($issueid, $pageno) {
    // variable declaration
    global $base_url;
    //issue node
    $node = node_load($issueid);
    $field_issue_large_cover_image_fid = $node->field_issue_large_cover_image['und'][0]['fid'];
    $issue_cover_image = $field_issue_large_cover_image_url = completeFilePath($field_issue_large_cover_image_fid);
    $lar_img_uri = $node->field_issue_large_cover_image['und'][0]['uri'];
    $lar_img = image_style_url('magazine_top_issue_172x240', $lar_img_uri);

    $field_issue_small_cover_image_fid = $node->field_issue_small_cover_image['und'][0]['fid'];
    $issue_digitalmag_url = $field_issue_small_cover_image_url = completeFilePath($field_issue_small_cover_image_fid);

    $issue_date = $node->field_issue_title['und'][0]['value'];
    $issue_nid = $node->nid;

    $field_issue_magazine = $node->field_issue_magazine['und'][0]['target_id'];

    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $tid_list[] = $tid;
    $listcount = 0;
    $range_max = 10;
    $range_min = 0;
    if (!$pageno == 0) {
        $range_min = $pageno * $range_max;
    }

    $order_by = 'DESC';
    $story_list_array = array();
    $loop_count = 0;
    /*$current_issue = itg_rapid_get_current_issue();
    $show_web_exclusive = variable_get('show_web_exclusive'); // 1
    
    if($current_issue == $issue_date && $show_web_exclusive == 1){
        $story_list_array = itg_rapid_get_web_exclisive_story($issue_date);
        $web_ex_st_cont = count($story_list_array);
        $listcount = $web_ex_st_cont;
        if($pageno == 0){
            $range_max = 10- $web_ex_st_cont;
        }
    }*/
    
    //select cover story..
    $story_list_array = itg_rapid_get_cover_story($issue_date, $range_min, $range_max);
    $cover_st_cont = count($story_list_array);
        if ($cover_st_cont < 10) {
        // select node belong from current term id or child term id
        $listcount = $cover_st_cont;
        $range_min = 0;
        if (!$pageno == 0) {
            $range_min = $pageno * 10;
        }
        if($cover_st_cont > 0){
            $range_max = 10- $cover_st_cont;
        }
        
        
        $query = db_select('node', 'n');
        //join  for field value
        $query->leftJoin('field_data_field_story_category', 'fsc', 'fsc.entity_id=n.nid');
        $query->leftJoin('itg_widget_order', 'iwo', 'iwo.nid=n.nid');
        $query->leftJoin('field_data_field_story_short_headline', 'fssh', 'fssh.entity_id=n.nid');

        $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_extra_small_image', 'esi', 'esi.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
        $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
        $query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');
        $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
        $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
        $query->leftJoin('file_managed', 'mi_file', 'mi_file.fid=mi.field_story_medium_image_fid');
        $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
        $query->leftJoin('file_managed', 'esi_file', 'esi_file.fid=esi.field_story_extra_small_image_fid');

        $query->leftJoin('field_data_field_common_related_content', 'rc', 'rc.entity_id=n.nid');
        //field_data_field_story_select_magazine
        $query->leftJoin('field_data_field_story_select_magazine', 'fssm', 'fssm.field_story_select_magazine_target_id=n.nid');
        //field_data_field_story_issue_date
        $query->leftJoin('field_data_field_story_issue_date', 'fsid', 'fsid.entity_id=n.nid');
        //field_data_field_story_magazine_story_issue
        $query->leftJoin('field_data_field_story_magazine_story_issue', 'fsms', 'fsms.entity_id=n.nid');
        //field_data_field_itg_common_by_line_name
        $query->leftJoin('field_data_field_itg_common_by_line_name', 'fsbl', 'fsbl.entity_id=n.nid');
        //field_data_field_reporter_unique_id
        $query->leftJoin('field_data_field_reporter_unique_id', 'fsri', 'fsri.entity_id=n.nid');
        //field_data_field_primary_category
        $query->leftJoin('field_data_field_primary_category', 'fci', 'fci.entity_id=n.nid');

        $query->fields('eli_file', array('uri'));
        $query->fields('li_file', array('uri'));
        $query->fields('mi_file', array('uri'));
        $query->fields('si_file', array('uri'));
        $query->fields('esi_file', array('uri'));

        $query->fields('mi', array('field_story_medium_image_fid'));
        $query->fields('li', array('field_story_large_image_fid'));
        $query->fields('si', array('field_story_small_image_fid'));
        $query->fields('rc', array('field_common_related_content_value'));

        $query->fields('kt', array('field_story_kicker_text_value'));
        $query->fields('vd', array('field_video_duration_value'));
        $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));
        $query->fields('fsbl', array('field_itg_common_by_line_name_value'));
        $query->fields('fsri', array('field_reporter_unique_id_value'));
        $query->fields('fci', array('field_primary_category_value'));
        $query->fields('fssh', array('field_story_short_headline_value'));


        //end 
        ////$query->condition('fsc.field_story_category_tid', 1206509)->condition('n.status', 1)->condition('n.type', 'story')->condition('fsid.field_story_issue_date_value', $issue_date)->orderBy('iwo.weight', 'DESC')->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);
        //$query->condition('fsc.field_story_category_tid', 1206501, '!=')->condition('fsc.field_story_category_tid', 1206509, '!=')->condition('n.status', 1)->condition('n.type', 'story')->condition('fsid.field_story_issue_date_value', $issue_date)->orderBy('iwo.weight', 'DESC')->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);
        $query->condition('fsms.field_story_magazine_story_issue_value', 'magazine_issue_story')->condition('fsc.field_story_category_tid', 1206501, '!=')->condition('fsc.field_story_category_tid', 1206509, '!=')->condition('fsc.field_story_category_tid', 1206499, '!=')->condition('n.status', 1)->condition('n.type', 'story')->condition('fsid.field_story_issue_date_value', $issue_date)->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        foreach ($result as $reskey => $resvalue) {
            // node feed tag
            //$title = $resvalue['title'];
            $title = $resvalue['field_story_short_headline_value'];
            if(!$title){
                $title = $resvalue['title'];
            }
            $field_itg_common_by_line_name_value = $resvalue['field_itg_common_by_line_name_value'];
            $field_reporter_unique_id_value = $resvalue['field_reporter_unique_id_value'];
            $field_reporter_unique_id_value = str_replace("byline_", "", $field_reporter_unique_id_value);
            $type = $resvalue['type'];
            $nid = $resvalue['nid'];
            $field_primary_category_value = $resvalue['field_primary_category_value'];
            $term = taxonomy_term_load($field_primary_category_value);
            $term_name = $term->name;
            $created = $resvalue['created'];
            $changed = $resvalue['changed'];
            $field_story_kicker_text_value = strip_tags($resvalue['field_story_kicker_text_value']);
            $alias = drupal_get_path_alias('node/' . $nid . '');
            $weburl = $base_url . "/" . $alias;
            $field_video_duration_value = $resvalue['field_video_duration_value'];
            // file url
            $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
            $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);
            $file_large_img_url = completeFilePath($resvalue['field_story_large_image_fid']);

            //related content
            $related = relatedContentNodeType($resvalue['field_common_related_content_value']);
            $comment_cont = getCommentsCount($nid);

            // create date formating
            $firebase_url = get_node_firebase_weburl($nid);

            if ($created) {
                $create_datetime = date("Y-m-d H:i:s", $created);
                $create_date = date("Y-m-d H:i:s", $created);
            } else {
                $create_datetime = "";
                $create_date = "";
            }
            if ($changed) {
                $changed_datetime = date("Y-m-d H:i:s", $changed);
            } else {
                $changed_datetime = "";
            }
            $conf = getStoryConfigVal($nid);
            $is_lock = 0;
            if (in_array("lock_story", $conf)) {
                $is_lock = 1;
            }

            $story_list_array[$listcount]['s_id'] = "$nid";
            $story_list_array[$listcount]['s_title'] = "$title";
            $story_list_array[$listcount]['s_share_link'] = "$firebase_url";
            $story_list_array[$listcount]['s_short_desc'] = "$field_story_kicker_text_value";
            $story_list_array[$listcount]['s_comment_count'] = "$comment_cont";
            $story_list_array[$listcount]['s_small_image'] = "$file_small_img_url";
            $story_list_array[$listcount]['s_large_image'] = "$file_large_img_url";
            $story_list_array[$listcount]['s_updated_datetime'] = "$changed_datetime";
            $story_list_array[$listcount]['s_is_locked'] = "$is_lock";
            $story_list_array[$listcount]['s_author_id'] = "$field_reporter_unique_id_value";
            $story_list_array[$listcount]['s_author_title'] = "$field_itg_common_by_line_name_value";
            $story_list_array[$listcount]['s_pcategory_id'] = "$field_primary_category_value";
            $story_list_array[$listcount]['s_pcategory_title'] = "$term_name";

            $listcount++;
        }
    }
    
    //selection of suplement story
    if($listcount < 10){
        $range_min = 0;
        if (!$pageno == 0) {
            $range_min = $pageno * $range_max;
        }
        $range_max = 10- $listcount + 1;
        $supp_ar = itg_rapid_get_supplement_by_issue($issue_date);
        $story_list_array = itg_rapid_get_supp_story($supp_ar, $range_min, $range_max, $listcount, $story_list_array);
    }
    $listcount = count($story_list_array);
    $data['lcount'] = $listcount;
    $data['data'] = $story_list_array;
    $data['updated_datetime'] = $changed_datetime;

    $data['issue_date'] = $issue_date;
    $data['issue_nid'] = $issue_nid;
    $data['issue_cover_image'] = $lar_img;
    $data['issue_digitalmag_url'] = $issue_digitalmag_url;


    return $data;
}

/**
 * main function for generate magazineCoverstoriesPageRerourceValue array
 *
 * @return array
 */
function magazineCoverstoriesPageRerourceValue() {

    // variable decalartion
    $output_array = array();
    $data_array = array();
    $issue_list_array = array();
    $updated_datetime = "";
    // list array building
    $data = magazineCoverstoriesPageRerourceValueList();
    if ($data['lcount'] > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }
    //data array building
    $datacount = $data['lcount'];
    $data_up_time = $data['updated_datetime'];
    $data_array['issue'] = $data['data'];
    $output_array['data'] = $data_array;
    return $output_array;
}

/**
 * function for generate magazineCoverstoriesPageRerourceValueList xml feed
 *
 * @return array
 */
function magazineCoverstoriesPageRerourceValueList($source = "") {
    // variable declaration
    global $base_url;
    $node_count = "";
    $output = "";
    $data = array();
    $listcount = 0;
    $data_list_array = array();
    $loop_count = 0;

    // issue list query..
    if ($source == "home") {
        $magazine_nids = home_page_magazine_node_list();

        $query_issue = db_select('node', 'n');
        $query_issue->leftJoin('itg_app_master_info_internal', 'mci', 'mci.org_id=n.nid');
        $query_issue->leftJoin('field_data_field_issue_large_cover_image', 'fsli', 'fsli.entity_id=n.nid');
        $query_issue->leftJoin('field_data_field_issue_small_cover_image', 'fssi', 'fssi.entity_id=n.nid');
        $query_issue->leftJoin('field_data_field_issue_title', 'fsit', 'fsit.entity_id=n.nid');
        //$query_issue->leftJoin('field_data_field_story_issue_date', 'fsid', 'fsid.entity_id=n.nid');

        $query_issue->fields('fsli', array('field_issue_large_cover_image_fid'));
        $query_issue->fields('fssi', array('field_issue_small_cover_image_fid'));
        $query_issue->fields('fsit', array('field_issue_title_value'));
        $query_issue->fields('n', array('nid'));
        $query_issue->fields('mci', array('info_value'));

        $query_issue->condition('n.status', 1);
        $query_issue->condition('n.type', 'issue');
        $query_issue->condition('n.nid', $magazine_nids, 'IN');
        $query_issue->condition('mci.info_type', 'magazine', '=');
        //$query_issue->orderBy('mci.info_value', 'ASC');  
        $query_issue->orderBy('fsit.field_issue_title_value', 'DESC');
    } else {
        $query_issue = db_select('node', 'n');
        $query_issue->leftJoin('field_data_field_issue_large_cover_image', 'fsli', 'fsli.entity_id=n.nid');
        $query_issue->leftJoin('field_data_field_issue_small_cover_image', 'fssi', 'fssi.entity_id=n.nid');
        $query_issue->leftJoin('field_data_field_issue_title', 'fsit', 'fsit.entity_id=n.nid');
        //$query_issue->leftJoin('field_data_field_story_issue_date', 'fsid', 'fsid.entity_id=n.nid');

        $query_issue->fields('fsli', array('field_issue_large_cover_image_fid'));
        $query_issue->fields('fssi', array('field_issue_small_cover_image_fid'));
        $query_issue->fields('fsit', array('field_issue_title_value'));
        $query_issue->fields('n', array('nid'));

        $query_issue->condition('n.status', 1)->condition('n.type', 'issue')->orderBy('fsit.field_issue_title_value', 'desc')->range(0, 20);
    }
    $result_issue = $query_issue->execute()->fetchAll(PDO::FETCH_ASSOC);
    foreach ($result_issue as $reskey => $resvalue) {

        //issue node
        $issueid = $resvalue['nid'];
        $node_data = node_load($issueid);

        $lar_img_uri = $node_data->field_issue_large_cover_image['und'][0]['uri'];
        $lar_img = image_style_url('magazine_top_issue_172x240', $lar_img_uri);
        $field_issue_large_cover_image_fid = $resvalue['field_issue_large_cover_image_fid'];
        $issue_cover_image = $field_issue_large_cover_image_url = completeFilePath($field_issue_large_cover_image_fid);

        $field_issue_small_cover_image_fid = $resvalue['field_issue_small_cover_image_fid'];
        $issue_digitalmag_url = $field_issue_small_cover_image_url = completeFilePath($field_issue_small_cover_image_fid);

        $issue_date = $resvalue['field_issue_title_value'];
        $issue_nid = $resvalue['nid'];
        $story_list_data = getCoverstoriesList($issue_date);
        if (count($story_list_data) > 0) {
            $data_list_array[$loop_count]['issue_id'] = "$issueid";
            $data_list_array[$loop_count]['issue_date'] = "$issue_date";
            $data_list_array[$loop_count]['issue_cover_image'] = "$lar_img";
            $data_list_array[$loop_count]['story'] = $story_list_data;
            $loop_count++;
        }
        if ($loop_count >= 10) {
            break;
        }
    }

    $data['lcount'] = $loop_count;
    $data['data'] = $data_list_array;
    $data['updated_datetime'] = $changed_datetime;
    return $data;
}

/**
 * main function for getStoryList array
 *
 * @return array
 */
function getCoverstoriesList($issue_date) {

    $cover_story_list_array = array();
    $loop_count = 0;
    
    //select cover story..
    $cover_story_list_array = itg_rapid_get_cover_story($issue_date, 0, 2);
    $cover_st_cont = count($cover_story_list_array);
        if ($cover_st_cont < 2) {
        // select node belong from current term id or child term id
        $loop_count = $cover_st_cont;
        $range_min = 0;        
        
        if($cover_st_cont > 0){
            $range_max = 2- $cover_st_cont;
        }
    
    // select node belong from current term id or child term id
    $query = db_select('node', 'n');
    //join  for field value
    $query->leftJoin('field_data_field_story_category', 'fsc', 'fsc.entity_id=n.nid');
    $query->leftJoin('itg_widget_order', 'iwo', 'iwo.nid=n.nid');
    $query->leftJoin('field_data_field_story_short_headline', 'fssh', 'fssh.entity_id=n.nid');
    
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_small_image', 'esi', 'esi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');
    $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
    $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
    $query->leftJoin('file_managed', 'mi_file', 'mi_file.fid=mi.field_story_medium_image_fid');
    $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
    $query->leftJoin('file_managed', 'esi_file', 'esi_file.fid=esi.field_story_extra_small_image_fid');

    $query->leftJoin('field_data_field_common_related_content', 'rc', 'rc.entity_id=n.nid');
    //field_data_field_story_select_magazine
    $query->leftJoin('field_data_field_story_select_magazine', 'fssm', 'fssm.field_story_select_magazine_target_id=n.nid');
    //field_data_field_story_issue_date
    $query->leftJoin('field_data_field_story_issue_date', 'fsid', 'fsid.entity_id=n.nid');
    //field_data_field_story_magazine_story_issue
    $query->leftJoin('field_data_field_story_magazine_story_issue', 'fsms', 'fsms.entity_id=n.nid');
    //field_data_field_itg_common_by_line_name
    $query->leftJoin('field_data_field_itg_common_by_line_name', 'fsbl', 'fsbl.entity_id=n.nid');
    //field_data_field_reporter_unique_id
    $query->leftJoin('field_data_field_reporter_unique_id', 'fsri', 'fsri.entity_id=n.nid');
    //field_data_field_primary_category
    $query->leftJoin('field_data_field_primary_category', 'fci', 'fci.entity_id=n.nid');

    $query->fields('eli_file', array('uri'));
    $query->fields('li_file', array('uri'));
    $query->fields('mi_file', array('uri'));
    $query->fields('si_file', array('uri'));
    $query->fields('esi_file', array('uri'));

    $query->fields('mi', array('field_story_medium_image_fid'));
    $query->fields('li', array('field_story_large_image_fid'));
    $query->fields('si', array('field_story_small_image_fid'));
    $query->fields('rc', array('field_common_related_content_value'));

    $query->fields('kt', array('field_story_kicker_text_value'));
    $query->fields('vd', array('field_video_duration_value'));
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));

    $query->fields('fsbl', array('field_itg_common_by_line_name_value'));
    $query->fields('fsri', array('field_reporter_unique_id_value'));
    $query->fields('fci', array('field_primary_category_value'));
    $query->fields('fssh', array('field_story_short_headline_value'));

    //end
    //$query->condition('fsc.field_story_category_tid', 1206509)->condition('n.status', 1)->condition('n.type', 'story')->condition('fsid.field_story_issue_date_value', $issue_date)->orderBy('iwo.weight', 'DESC')->orderBy('n.created', 'DESC')->groupBy('n.nid')->range(0, 2);
    $query->condition('fsms.field_story_magazine_story_issue_value', 'magazine_issue_story')->condition('n.status', 1)->condition('n.type', 'story')->condition('fsid.field_story_issue_date_value', $issue_date)->orderBy('iwo.weight', 'DESC')->orderBy('n.created', 'DESC')->groupBy('n.nid')->range(0, 2);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    foreach ($result as $reskey => $resvalue) {
        $field_itg_common_by_line_name_value = $resvalue['field_itg_common_by_line_name_value'];
        $field_reporter_unique_id_value = $resvalue['field_reporter_unique_id_value'];
        $field_reporter_unique_id_value = str_replace("byline_", "", $field_reporter_unique_id_value);
        //$title = $resvalue['title'];
        $title = $resvalue['field_story_short_headline_value'];
        if(!$title){
                $title = $resvalue['title'];
            }
        $type = $resvalue['type'];
        $nid = $resvalue['nid'];
        $field_primary_category_value = $resvalue['field_primary_category_value'];
        $term = taxonomy_term_load($field_primary_category_value);
        $term_name = $term->name;
        $created = $resvalue['created'];
        $changed = $resvalue['changed'];
        $field_story_kicker_text_value = strip_tags($resvalue['field_story_kicker_text_value']);
        $alias = drupal_get_path_alias('node/' . $nid . '');
        $weburl = $base_url . "/" . $alias;
        $field_video_duration_value = $resvalue['field_video_duration_value'];
        // file url
        $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
        $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);
        $file_large_img_url = completeFilePath($resvalue['field_story_large_image_fid']);

        //related content
        $related = relatedContentNodeType($resvalue['field_common_related_content_value']);
        $comment_cont = getCommentsCount($nid);

        // create date formating
        $firebase_url = get_node_firebase_weburl($nid);

        if ($created) {
            $create_datetime = date("Y-m-d H:i:s", $created);
            $create_date = date("Y-m-d H:i:s", $created);
        } else {
            $create_datetime = "";
            $create_date = "";
        }
        if ($changed) {
            $changed_datetime = date("Y-m-d H:i:s", $changed);
        } else {
            $changed_datetime = "";
        }
        $conf = getStoryConfigVal($nid);
        $is_lock = 0;
        if (in_array("lock_story", $conf)) {
            $is_lock = 1;
        }

        $cover_story_list_array[$loop_count]['s_id'] = "$nid";
        $cover_story_list_array[$loop_count]['s_title'] = "$title";
        $cover_story_list_array[$loop_count]['s_share_link'] = "$firebase_url";
        $cover_story_list_array[$loop_count]['s_short_desc'] = "$field_story_kicker_text_value";
        $cover_story_list_array[$loop_count]['s_comment_count'] = "$comment_cont";
        $cover_story_list_array[$loop_count]['s_small_image'] = "$file_small_img_url";
        $cover_story_list_array[$loop_count]['s_large_image'] = "$file_large_img_url";
        $cover_story_list_array[$loop_count]['s_updated_datetime'] = "$changed_datetime";
        $cover_story_list_array[$loop_count]['s_is_locked'] = "$is_lock";
        $cover_story_list_array[$loop_count]['s_author_id'] = "$field_reporter_unique_id_value";
        $cover_story_list_array[$loop_count]['s_author_title'] = "$field_itg_common_by_line_name_value";
        $cover_story_list_array[$loop_count]['s_pcategory_id'] = "$field_primary_category_value";
        $cover_story_list_array[$loop_count]['s_pcategory_title'] = "$term_name";

        $loop_count++;
    }
}

    return $cover_story_list_array;
}

// 3rd

/**
 * main function for generate magazineEditionListPageRerourceValue array
 *
 * @return array
 */
function magazineEditionListPageRerourceValue($sdate = 0, $tdate = 0, $cpageno = 0) {
    // variable decalartion
    $output_array = array();
    $data_array = array();
    $photo_list_array = array();
    $updated_datetime = "";
    // list array building
    $data = magazineEditionListPageRerourceValueList($sdate, $tdate, $cpageno);

    if ($data['lcount'] > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }

    //data array building
    $datacount = $data['lcount'];
    $data_up_time = $data['updated_datetime'];

    $data_array['issue_count'] = "$datacount";
    $data_array['issue_display_count'] = "10";
    $data_array['issue_pagination_cap'] = "7";
    $data_array['issue'] = $data['data'];
    $output_array['data'] = $data_array;

    return $output_array;
}

/**
 * function for generate magazineEditionListPageRerourceValueList xml feed
 *
 * @return array
 */
function magazineEditionListPageRerourceValueList($sdate, $tdate, $pageno) {
    // variable declaration
    global $base_url;
    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $tid_list[] = $tid;
    $issue_list_array = array();
    $listcount = 0;
    $range_max = 10;
    $sdate_fi = strtotime($sdate . " 00:00:00");
    $tdate_fi = strtotime($tdate . " 23:59:00");
    $range_min = 0;
    if (!$pageno == 0) {
        $range_min = $pageno * $range_max;
    }


    $loop_count = 0; 

    // issue list query..
    $query_issue = db_select('node', 'n');
    $query_issue->leftJoin('field_data_field_issue_large_cover_image', 'fsli', 'fsli.entity_id=n.nid');
    $query_issue->leftJoin('field_data_field_issue_small_cover_image', 'fssi', 'fssi.entity_id=n.nid');
    $query_issue->leftJoin('field_data_field_issue_title', 'fsit', 'fsit.entity_id=n.nid');
    $query_issue->fields('fsli', array('field_issue_large_cover_image_fid'));
    $query_issue->fields('fssi', array('field_issue_small_cover_image_fid'));
    $query_issue->fields('fsit', array('field_issue_title_value'));
    $query_issue->fields('n', array('nid'));
    $query_issue->condition('fsit.field_issue_title_value', array($sdate, $tdate), 'BETWEEN')->condition('n.type', 'issue')->orderBy('fsit.field_issue_title_value', 'DESC')->range($range_min, $range_max);
    $result_issue = $query_issue->execute()->fetchAll(PDO::FETCH_ASSOC);
    foreach ($result_issue as $reskey => $resvalue) {

        //issue node
        $issueid = $resvalue['nid'];
        $field_issue_large_cover_image_fid = $resvalue['field_issue_large_cover_image_fid'];
        $issue_cover_image = $field_issue_large_cover_image_url = completeFilePath($field_issue_large_cover_image_fid);

        $field_issue_small_cover_image_fid = $resvalue['field_issue_small_cover_image_fid'];
        $issue_digitalmag_url = $field_issue_small_cover_image_url = completeFilePath($field_issue_small_cover_image_fid);

        $issue_date = $resvalue['field_issue_title_value'];
        $issue_nid = $resvalue['nid'];
        $i_story_count = getIssueStoryCount($issue_date);

        $issue_list_array[$loop_count]['i_id'] = "$issue_nid";
        $issue_list_array[$loop_count]['i_issue_date'] = "$issue_date";
        $issue_list_array[$loop_count]['i_story_count'] = "$i_story_count";
        $issue_list_array[$loop_count]['i_issue_cover_image'] = "$issue_cover_image";
        $loop_count++;
    }
    $data['lcount'] = $loop_count;
    $data['data'] = $issue_list_array;
    $data['updated_datetime'] = $changed_datetime;
    return $data;
}

/**
 * function for get count of story on issue
 * @pram $issue_date
 *
 * @return $count
 */
function getIssueStoryCount($issue_date) {
    // issue list query..
    $count = 0;
    $query_issue = db_select('node', 'n');

    $query_issue->leftJoin('field_data_field_story_issue_date', 'fsid', 'fsid.entity_id=n.nid');
    $query_issue->fields('n', array('nid'));

    $query_issue->condition('n.status', 1)->condition('n.type', 'story')->condition('fsid.field_story_issue_date_value', $issue_date);
    $result_issue = $query_issue->execute()->fetchAll(PDO::FETCH_ASSOC);
    $count = count($result_issue);
    return $count;
}

/**
 * function for get congiguration of story
 * @pram $nid
 *
 * @return array
 */
function getStoryConfigVal($nid) {
    $conf = array();
    if ($nid) {
        $query_issue = db_select('field_data_field_story_configurations', 'sc');
        $query_issue->fields('sc', array('field_story_configurations_value'));
        $query_issue->condition('sc.entity_id', $nid);
        $result_issue = $query_issue->execute()->fetchAll(PDO::FETCH_ASSOC);
        foreach ($result_issue as $reskey => $resvalue) {
            $conf[] = $resvalue;
        }
        return $conf;
    }
}
/**
 * itg_rapid_get_web_exclisive_story
 * @param type $issueid
 */

function itg_rapid_get_web_exclisive_story($issue_date) {
    // variable declaration
    global $base_url;
    //issue node
    

    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $tid_list[] = $tid;
    $listcount = 0;
    $range_max = 4;
    $range_min = 0;    
    $order_by = 'DESC';
    $story_list_array = array();
    $loop_count = 0;

    // select node belong from current term id or child term id

    $query = db_select('node', 'n');
    //join  for field value
    $query->leftJoin('field_data_field_story_category', 'fsc', 'fsc.entity_id=n.nid');
    $query->leftJoin('itg_widget_order', 'iwo', 'iwo.nid=n.nid');
    $query->leftJoin('field_data_field_story_short_headline', 'fssh', 'fssh.entity_id=n.nid');
    
    
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_small_image', 'esi', 'esi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');
    $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
    $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
    $query->leftJoin('file_managed', 'mi_file', 'mi_file.fid=mi.field_story_medium_image_fid');
    $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
    $query->leftJoin('file_managed', 'esi_file', 'esi_file.fid=esi.field_story_extra_small_image_fid');

    $query->leftJoin('field_data_field_common_related_content', 'rc', 'rc.entity_id=n.nid');
    //field_data_field_story_select_magazine
    $query->leftJoin('field_data_field_story_select_magazine', 'fssm', 'fssm.field_story_select_magazine_target_id=n.nid');
    //field_data_field_story_issue_date
    $query->leftJoin('field_data_field_story_issue_date', 'fsid', 'fsid.entity_id=n.nid');
    //field_data_field_story_magazine_story_issue
    $query->leftJoin('field_data_field_story_magazine_story_issue', 'fsms', 'fsms.entity_id=n.nid');
    //field_data_field_itg_common_by_line_name
    $query->leftJoin('field_data_field_itg_common_by_line_name', 'fsbl', 'fsbl.entity_id=n.nid');
    //field_data_field_reporter_unique_id
    $query->leftJoin('field_data_field_reporter_unique_id', 'fsri', 'fsri.entity_id=n.nid');
    //field_data_field_primary_category
    $query->leftJoin('field_data_field_primary_category', 'fci', 'fci.entity_id=n.nid');

    $query->fields('eli_file', array('uri'));
    $query->fields('li_file', array('uri'));
    $query->fields('mi_file', array('uri'));
    $query->fields('si_file', array('uri'));
    $query->fields('esi_file', array('uri'));

    $query->fields('mi', array('field_story_medium_image_fid'));
    $query->fields('li', array('field_story_large_image_fid'));
    $query->fields('si', array('field_story_small_image_fid'));
    $query->fields('rc', array('field_common_related_content_value'));

    $query->fields('kt', array('field_story_kicker_text_value'));
    $query->fields('vd', array('field_video_duration_value'));
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));
    $query->fields('fsbl', array('field_itg_common_by_line_name_value'));
    $query->fields('fsri', array('field_reporter_unique_id_value'));
    $query->fields('fci', array('field_primary_category_value'));
    $query->fields('fssh', array('field_story_short_headline_value'));


    //end
    $query->condition('fsc.field_story_category_tid', 1206501)->condition('n.status', 1)->condition('n.type', 'story')->condition('fsid.field_story_issue_date_value', $issue_date)->orderBy('iwo.weight', 'DESC')->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    foreach ($result as $reskey => $resvalue) {
        // node feed tag
        //$title = $resvalue['title'];
        $title = $resvalue['field_story_short_headline_value'];
        if(!$title){
                $title = $resvalue['title'];
            }
        $field_itg_common_by_line_name_value = $resvalue['field_itg_common_by_line_name_value'];
        $field_reporter_unique_id_value = $resvalue['field_reporter_unique_id_value'];
        $field_reporter_unique_id_value = str_replace("byline_", "", $field_reporter_unique_id_value);
        $type = $resvalue['type'];
        $nid = $resvalue['nid'];
        $field_primary_category_value = $resvalue['field_primary_category_value'];
        $term = taxonomy_term_load($field_primary_category_value);
        $term_name = $term->name;
        $created = $resvalue['created'];
        $changed = $resvalue['changed'];
        $field_story_kicker_text_value = strip_tags($resvalue['field_story_kicker_text_value']);
        $alias = drupal_get_path_alias('node/' . $nid . '');
        $weburl = $base_url . "/" . $alias;
        $field_video_duration_value = $resvalue['field_video_duration_value'];
        // file url
        $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
        $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);
        $file_large_img_url = completeFilePath($resvalue['field_story_large_image_fid']);

        //related content
        $related = relatedContentNodeType($resvalue['field_common_related_content_value']);
        $comment_cont = getCommentsCount($nid);

        // create date formating
        $firebase_url = get_node_firebase_weburl($nid);

        if ($created) {
            $create_datetime = date("Y-m-d H:i:s", $created);
            $create_date = date("Y-m-d H:i:s", $created);
        } else {
            $create_datetime = "";
            $create_date = "";
        }
        if ($changed) {
            $changed_datetime = date("Y-m-d H:i:s", $changed);
        } else {
            $changed_datetime = "";
        }
        $conf = getStoryConfigVal($nid);
        $is_lock = 0;
        if (in_array("lock_story", $conf)) {
            $is_lock = 1;
        }

        $story_list_array[$listcount]['s_id'] = "$nid";
        $story_list_array[$listcount]['s_title'] = "$title";
        $story_list_array[$listcount]['s_share_link'] = "$firebase_url";
        $story_list_array[$listcount]['s_short_desc'] = "$field_story_kicker_text_value";
        $story_list_array[$listcount]['s_comment_count'] = "$comment_cont";
        $story_list_array[$listcount]['s_small_image'] = "$file_small_img_url";
        $story_list_array[$listcount]['s_large_image'] = "$file_large_img_url";
        $story_list_array[$listcount]['s_updated_datetime'] = "$changed_datetime";
        $story_list_array[$listcount]['s_is_locked'] = "$is_lock";
        $story_list_array[$listcount]['s_author_id'] = "$field_reporter_unique_id_value";
        $story_list_array[$listcount]['s_author_title'] = "$field_itg_common_by_line_name_value";
        $story_list_array[$listcount]['s_pcategory_id'] = "$field_primary_category_value";
        $story_list_array[$listcount]['s_pcategory_title'] = "$term_name";

        $listcount++;
    }
    return $story_list_array;
}
/**
 * itg_rapid_get_current_issue
 * @return type
 */
function itg_rapid_get_current_issue() {
  //$current_issue = itg_msi_get_current_time_issue();
  $current_issue = itg_rapid_issue_attribute_date();
  if (!empty($current_issue)) {
    $output = $current_issue;
  }
  else {
    $year_15_days_ago = date('Y', strtotime('+15 days'));
    if ($year_15_days_ago > date('Y')) {
      $last_issue_ass_story_date = itg_rapid_issue_attribute_date();
      $current_time = date('Y-m-d', strtotime($last_issue_ass_story_date));
      $condition_type = '=';
    }
    else {
      $current_time = date('Y-m-d', time());
      $condition_type = '<';
    }
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_issue_title', 'ft', 'ft.entity_id = n.nid');
    $query->fields('ft', array('field_issue_title_value'));
    $query->condition('ft.field_issue_title_value', $current_time, $condition_type);
    $query->orderBy('ft.field_issue_title_value', 'DESC');
    $query->condition('n.type', 'issue', '=');
    $query->condition('n.status', 1, '=');
    $query->range(0, 1);
    $output = $query->execute()->fetchField();
  }
  return $output;
}
/**
 * Implements function for itg_rapid_issue_attribute_date
 * @return string
 */
function itg_rapid_issue_attribute_date() {
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_issue_title', 'ft', 'ft.entity_id = n.nid');
    $query->fields('ft', array('field_issue_title_value'));
    $query->orderBy('ft.field_issue_title_value', 'DESC');
    $query->condition('n.type', 'issue', '=');
    $query->condition('n.status', 1, '=');
    $query->range(0, 1);
    $result = strtotime($query->execute()->fetchField());
    $result = $query->execute()->fetchField();
    return $result;
}

/**
 * itg_rapid_get_cover_story
 * @param type $issue_date
 */

function itg_rapid_get_cover_story($issue_date, $range_min, $range_max) {
    // variable declaration
    global $base_url;
    //issue node
    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $tid_list[] = $tid;
    $listcount = 0;       
    $order_by = 'DESC';
    $story_list_array = array();
    $loop_count = 0;

    // select node belong from current term id or child term id

    $query = db_select('node', 'n');
    //join  for field value
    $query->leftJoin('field_data_field_story_category', 'fsc', 'fsc.entity_id=n.nid');
    $query->leftJoin('itg_widget_order', 'iwo', 'iwo.nid=n.nid');
    $query->leftJoin('field_data_field_story_short_headline', 'fssh', 'fssh.entity_id=n.nid');
    
    
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_small_image', 'esi', 'esi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');
    $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
    $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
    $query->leftJoin('file_managed', 'mi_file', 'mi_file.fid=mi.field_story_medium_image_fid');
    $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
    $query->leftJoin('file_managed', 'esi_file', 'esi_file.fid=esi.field_story_extra_small_image_fid');

    $query->leftJoin('field_data_field_common_related_content', 'rc', 'rc.entity_id=n.nid');
    //field_data_field_story_select_magazine
    $query->leftJoin('field_data_field_story_select_magazine', 'fssm', 'fssm.field_story_select_magazine_target_id=n.nid');
    //field_data_field_story_issue_date
    $query->leftJoin('field_data_field_story_issue_date', 'fsid', 'fsid.entity_id=n.nid');
    //field_data_field_story_magazine_story_issue
    $query->leftJoin('field_data_field_story_magazine_story_issue', 'fsms', 'fsms.entity_id=n.nid');
    //field_data_field_itg_common_by_line_name
    $query->leftJoin('field_data_field_itg_common_by_line_name', 'fsbl', 'fsbl.entity_id=n.nid');
    //field_data_field_reporter_unique_id
    $query->leftJoin('field_data_field_reporter_unique_id', 'fsri', 'fsri.entity_id=n.nid');
    //field_data_field_primary_category
    $query->leftJoin('field_data_field_primary_category', 'fci', 'fci.entity_id=n.nid');

    $query->fields('eli_file', array('uri'));
    $query->fields('li_file', array('uri'));
    $query->fields('mi_file', array('uri'));
    $query->fields('si_file', array('uri'));
    $query->fields('esi_file', array('uri'));

    $query->fields('mi', array('field_story_medium_image_fid'));
    $query->fields('li', array('field_story_large_image_fid'));
    $query->fields('si', array('field_story_small_image_fid'));
    $query->fields('rc', array('field_common_related_content_value'));

    $query->fields('kt', array('field_story_kicker_text_value'));
    $query->fields('vd', array('field_video_duration_value'));
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));
    $query->fields('fsbl', array('field_itg_common_by_line_name_value'));
    $query->fields('fsri', array('field_reporter_unique_id_value'));
    $query->fields('fci', array('field_primary_category_value'));
    $query->fields('fssh', array('field_story_short_headline_value'));

    //end
    //$query->condition('fsc.field_story_category_tid', 1206509)->condition('n.status', 1)->condition('n.type', 'story')->condition('fsid.field_story_issue_date_value', $issue_date)->orderBy('iwo.weight', 'DESC')->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);
    $query->condition('fsms.field_story_magazine_story_issue_value', 'magazine_issue_story')->condition('fsc.field_story_category_tid', 1206509)->condition('n.status', 1)->condition('n.type', 'story')->condition('fsid.field_story_issue_date_value', $issue_date)->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    foreach ($result as $reskey => $resvalue) {
        // node feed tag
        //$title = $resvalue['title'];
        $title = $resvalue['field_story_short_headline_value'];
        if(!$title){
                $title = $resvalue['title'];
            }
        $field_itg_common_by_line_name_value = $resvalue['field_itg_common_by_line_name_value'];
        $field_reporter_unique_id_value = $resvalue['field_reporter_unique_id_value'];
        $field_reporter_unique_id_value = str_replace("byline_", "", $field_reporter_unique_id_value);
        $type = $resvalue['type'];
        $nid = $resvalue['nid'];
        $field_primary_category_value = $resvalue['field_primary_category_value'];
        $term = taxonomy_term_load($field_primary_category_value);
        $term_name = $term->name;
        $created = $resvalue['created'];
        $changed = $resvalue['changed'];
        $field_story_kicker_text_value = strip_tags($resvalue['field_story_kicker_text_value']);
        $alias = drupal_get_path_alias('node/' . $nid . '');
        $weburl = $base_url . "/" . $alias;
        $field_video_duration_value = $resvalue['field_video_duration_value'];
        // file url
        $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
        $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);
        $file_large_img_url = completeFilePath($resvalue['field_story_large_image_fid']);

        //related content
        $related = relatedContentNodeType($resvalue['field_common_related_content_value']);
        $comment_cont = getCommentsCount($nid);

        // create date formating
        $firebase_url = get_node_firebase_weburl($nid);

        if ($created) {
            $create_datetime = date("Y-m-d H:i:s", $created);
            $create_date = date("Y-m-d H:i:s", $created);
        } else {
            $create_datetime = "";
            $create_date = "";
        }
        if ($changed) {
            $changed_datetime = date("Y-m-d H:i:s", $changed);
        } else {
            $changed_datetime = "";
        }
        $conf = getStoryConfigVal($nid);
        $is_lock = 0;
        if (in_array("lock_story", $conf)) {
            $is_lock = 1;
        }

        $story_list_array[$listcount]['s_id'] = "$nid";
        $story_list_array[$listcount]['s_title'] = "$title";
        $story_list_array[$listcount]['s_share_link'] = "$firebase_url";
        $story_list_array[$listcount]['s_short_desc'] = "$field_story_kicker_text_value";
        $story_list_array[$listcount]['s_comment_count'] = "$comment_cont";
        $story_list_array[$listcount]['s_small_image'] = "$file_small_img_url";
        $story_list_array[$listcount]['s_large_image'] = "$file_large_img_url";
        $story_list_array[$listcount]['s_updated_datetime'] = "$changed_datetime";
        $story_list_array[$listcount]['s_is_locked'] = "$is_lock";
        $story_list_array[$listcount]['s_author_id'] = "$field_reporter_unique_id_value";
        $story_list_array[$listcount]['s_author_title'] = "$field_itg_common_by_line_name_value";
        $story_list_array[$listcount]['s_pcategory_id'] = "$field_primary_category_value";
        $story_list_array[$listcount]['s_pcategory_title'] = "$term_name";

        $listcount++;
    }
    return $story_list_array;
}
/**
 * itg_rapid_get_supplement_by_issue
 * @param type $issue_date
 */
function itg_rapid_get_supplement_by_issue($issue_date){
    $supp_array = array();
    if($issue_date){
        $query = db_select('field_data_field_supp_issue', 'fis');
        $query->fields('fis', array('entity_id'));
        $query->condition('fis.field_supp_issue_value', $issue_date);
        //print strtr((string) $query, $query->arguments());die();
         $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        foreach ($result as $reskey => $resvalue) {
            $supp_array[] = $resvalue['entity_id'];
        }
    }
    return $supp_array;
}

/**
 * itg_rapid_get_supp_story
 * @global type $base_url
 * @param type $supp_ar
 * @param type $range_min
 * @param type $range_max
 * @return type
 */

function itg_rapid_get_supp_story($supp_ar, $range_min, $range_max, $listcount, $story_list_array) {
    
    // variable declaration
    global $base_url;
    //issue node
    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $tid_list[] = $tid;
    $listcount = 0;       
    $order_by = 'DESC';
    //$story_list_array = array();
    $loop_count = 0;

    // select node belong from current term id or child term id
    if(count($supp_ar) > 0){

    $query = db_select('node', 'n');
    //join  for field value   
    //$query->leftJoin('itg_widget_order', 'iwo', 'iwo.nid=n.nid');  
    $query->leftJoin('field_data_field_story_short_headline', 'fssh', 'fssh.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_small_image', 'esi', 'esi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    //$query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');
    $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
    $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
    $query->leftJoin('file_managed', 'mi_file', 'mi_file.fid=mi.field_story_medium_image_fid');
    $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
    $query->leftJoin('file_managed', 'esi_file', 'esi_file.fid=esi.field_story_extra_small_image_fid');

    //$query->leftJoin('field_data_field_common_related_content', 'rc', 'rc.entity_id=n.nid');
    //field_data_field_story_select_magazine
    //$query->leftJoin('field_data_field_story_select_magazine', 'fssm', 'fssm.field_story_select_magazine_target_id=n.nid');
    //field_data_field_story_issue_date
    $query->leftJoin('field_data_field_story_select_supplement', 'fsid', 'fsid.entity_id=n.nid');
    //field_data_field_story_magazine_story_issue
    
    //field_data_field_itg_common_by_line_name
    $query->leftJoin('field_data_field_itg_common_by_line_name', 'fsbl', 'fsbl.entity_id=n.nid');
    //field_data_field_reporter_unique_id
    $query->leftJoin('field_data_field_reporter_unique_id', 'fsri', 'fsri.entity_id=n.nid');
    //field_data_field_primary_category
    $query->leftJoin('field_data_field_primary_category', 'fci', 'fci.entity_id=n.nid');

    $query->fields('eli_file', array('uri'));
    $query->fields('li_file', array('uri'));
    $query->fields('mi_file', array('uri'));
    $query->fields('si_file', array('uri'));
    $query->fields('esi_file', array('uri'));

    $query->fields('mi', array('field_story_medium_image_fid'));
    $query->fields('li', array('field_story_large_image_fid'));
    $query->fields('si', array('field_story_small_image_fid'));
    //$query->fields('rc', array('field_common_related_content_value'));

    $query->fields('kt', array('field_story_kicker_text_value'));
    //$query->fields('vd', array('field_video_duration_value'));
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));
    $query->fields('fsbl', array('field_itg_common_by_line_name_value'));
    $query->fields('fsri', array('field_reporter_unique_id_value'));
    $query->fields('fci', array('field_primary_category_value'));
    $query->fields('fssh', array('field_story_short_headline_value'));


    //end
    $query->condition('n.status', 1)->condition('n.type', 'story')->condition('fsid.field_story_select_supplement_target_id', $supp_ar, 'IN')->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    foreach ($result as $reskey => $resvalue) {
        // node feed tag
        //$title = $resvalue['title'];
        $title = $resvalue['field_story_short_headline_value'];
        if(!$title){
                $title = $resvalue['title'];
            }
        $field_itg_common_by_line_name_value = $resvalue['field_itg_common_by_line_name_value'];
        $field_reporter_unique_id_value = $resvalue['field_reporter_unique_id_value'];
        $field_reporter_unique_id_value = str_replace("byline_", "", $field_reporter_unique_id_value);
        $type = $resvalue['type'];
        $nid = $resvalue['nid'];
        $field_primary_category_value = $resvalue['field_primary_category_value'];
        $term = taxonomy_term_load($field_primary_category_value);
        $term_name = $term->name;
        $created = $resvalue['created'];
        $changed = $resvalue['changed'];
        $field_story_kicker_text_value = strip_tags($resvalue['field_story_kicker_text_value']);
        $alias = drupal_get_path_alias('node/' . $nid . '');
        $weburl = $base_url . "/" . $alias;
        //$field_video_duration_value = $resvalue['field_video_duration_value'];
        // file url
        $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
        $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);
        $file_large_img_url = completeFilePath($resvalue['field_story_large_image_fid']);

        //related content
        //$related = relatedContentNodeType($resvalue['field_common_related_content_value']);
        $comment_cont = getCommentsCount($nid);

        // create date formating
        $firebase_url = get_node_firebase_weburl($nid);

        if ($created) {
            $create_datetime = date("Y-m-d H:i:s", $created);
            $create_date = date("Y-m-d H:i:s", $created);
        } else {
            $create_datetime = "";
            $create_date = "";
        }
        if ($changed) {
            $changed_datetime = date("Y-m-d H:i:s", $changed);
        } else {
            $changed_datetime = "";
        }
        $conf = getStoryConfigVal($nid);
        $is_lock = 0;
        if (in_array("lock_story", $conf)) {
            $is_lock = 1;
        }

        $story_list_array[$listcount]['s_id'] = "$nid";
        $story_list_array[$listcount]['s_title'] = "$title";
        $story_list_array[$listcount]['s_share_link'] = "$firebase_url";
        $story_list_array[$listcount]['s_short_desc'] = "$field_story_kicker_text_value";
        $story_list_array[$listcount]['s_comment_count'] = "$comment_cont";
        $story_list_array[$listcount]['s_small_image'] = "$file_small_img_url";
        $story_list_array[$listcount]['s_large_image'] = "$file_large_img_url";
        $story_list_array[$listcount]['s_updated_datetime'] = "$changed_datetime";
        $story_list_array[$listcount]['s_is_locked'] = "$is_lock";
        $story_list_array[$listcount]['s_author_id'] = "$field_reporter_unique_id_value";
        $story_list_array[$listcount]['s_author_title'] = "$field_itg_common_by_line_name_value";
        $story_list_array[$listcount]['s_pcategory_id'] = "$field_primary_category_value";
        $story_list_array[$listcount]['s_pcategory_title'] = "$term_name";

        $listcount++;
    }
    } 
    return $story_list_array;
}
