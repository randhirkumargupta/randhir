<?php

/**
 * Inc file contains the functions video API 
 */

/**
 * main function for generate videoCategoryPage array
 * @pram int $tid, $pageno
 *
 * @return array
 */
function videocategoryPageRerourceValue($tid = 0, $pageno = 0) {
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
    $data = generateVideoCategoryList($tid, $pageno);
    if ($data['lcount'] > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }
    $datacount = $data['lcount'];
    $data_up_time = $data['updated_datetime'];

    //data array building
    $data_array['id'] = "$tid";
    $data_array['title'] = "$term_name";
    $data_array['layout_id'] = "0";

    $data_array['video_count'] = "$datacount";
    $data_array['video_display_count'] = "10";
    $data_array['video_pagination_cap'] = "50";
    $data_array['updated_datetime'] = "$data_up_time";
    $data_array['video'] = $data['data'];
    $output_array['data'] = $data_array;
    return $output_array;
}

/**
 * function for generate videoCategoryPage list
 * @pram int $tid, $pageno
 *
 * @return array
 */
function generateVideoCategoryList($tid, $pageno) {
    // variable declaration
    global $base_url;
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

    $order_by = 'ASC';
    $type = "videogallery";
    $photo_list_array = array();
    $loop_count = 0; {
        $listcount = 0;

        // code vid=14  start
        if ($tid > 0) {
            $term_tree = taxonomy_get_tree(CATEGORY_MANAGMENT, $tid, $max_depth = NULL, $load_entities = FALSE);
        } else {
            $term_tree = taxonomy_get_tree(CATEGORY_MANAGMENT, 1206552, $max_depth = NULL, $load_entities = FALSE);
        }
        $term_tree_count = count($term_tree);
        if ($term_tree_count) {
            foreach ($term_tree as $key => $value) {
                $tid_list[] = $value->tid;
            }
        }

        // code vid=14  end
        // select node belong from current term id or child term id
        // filter user data list
        $filter_user_data = array(2744, 1584, 1162, 1155, 1141, 1137, 970, 1156, 1190, 1522, 3, 1350, 1148, 2573);

        $query = db_select('taxonomy_index', 'ti');
        $query->leftJoin('node', 'n', 'n.nid=ti.nid');
        //join  for field value
        $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_extra_small_image', 'esi', 'esi.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
        $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
        $query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_source_type', 'st', 'st.entity_id = n.nid');
        $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
        $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
        $query->leftJoin('file_managed', 'mi_file', 'mi_file.fid=mi.field_story_medium_image_fid');
        $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
        $query->leftJoin('file_managed', 'esi_file', 'esi_file.fid=esi.field_story_extra_small_image_fid');

        $query->leftJoin('field_data_field_common_related_content', 'rc', 'rc.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_syndication', 'fss', 'fss.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_reporter', 'fsr', 'fsr.entity_id=n.nid');
        $query->leftJoin('field_data_field_video_upload', 'fvu', 'fvu.entity_id=n.nid');
        //field_data_field_primary_category
        $query->leftJoin('field_data_field_primary_category', 'fpc', 'fpc.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_expert_description', 'ffd', 'ffd.entity_id=n.nid');

        $query->fields('st', array('field_story_source_type_value'));
        $query->fields('eli_file', array('uri'));
        $query->fields('li_file', array('uri'));
        $query->fields('mi_file', array('uri'));
        $query->fields('si_file', array('uri'));
        $query->fields('esi_file', array('uri'));

        $query->fields('mi', array('field_story_medium_image_fid'));
        $query->fields('li', array('field_story_large_image_fid'));
        $query->fields('si', array('field_story_small_image_fid'));
        $query->fields('eli', array('field_story_extra_large_image_fid'));
        $query->fields('rc', array('field_common_related_content_value'));

        $query->fields('kt', array('field_story_kicker_text_value'));
        $query->fields('vd', array('field_video_duration_value'));
        $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));
        $query->fields('fss', array('field_story_syndication_value'));
        $query->fields('fsr', array('field_story_reporter_target_id'));
        $query->fields('fvu', array('field_video_upload_value'));
        $query->fields('fpc', array('field_primary_category_value'));
        $query->fields('ffd', array('field_story_expert_description_value'));

        if ($tid == 0 && count($tid_list) > 0) {
            $query->condition('ti.tid', $tid_list, 'IN');
        } else {
            $query->condition('ti.tid', $tid, '=');
        }
        $interval = itg_app_time_interval($tid);
        $d1 = date('Y-m-d', strtotime("-" . $interval . " days"));
        $d2 = date(strtotime($d1));
        $query->condition('n.created', $d2, '>=');
        $query->condition('n.uid', $filter_user_data, 'NOT IN');
        $query->condition('n.status', 1)->condition('n.type', $type)->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);

        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

        foreach ($result as $reskey => $resvalue) {
            // node feed tag
            $title = $resvalue['title'];
            $type = $resvalue['type'];
            $nid = $resvalue['nid'];
            $created = $resvalue['created'];
            $changed = $resvalue['changed'];
            $field_story_kicker_text_value = $resvalue['field_story_kicker_text_value'];
            $field_primary_category_value = $resvalue['field_primary_category_value'];
            $term = taxonomy_term_load($tid);
            $term_name = $term->name;
            $nv_cont = getNodeViewCount($nid);
            $alias = drupal_get_path_alias('node/' . $nid . '');
            $weburl = $base_url . "/" . $alias;
            $field_video_duration_value = $resvalue['field_video_duration_value'];
            // file url
            $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
            $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);
            $file_large_img_url = completeFilePath($resvalue['field_story_large_image_fid']);
            $file_extra_large_img_url = completeFilePath($resvalue['field_story_extra_large_image_fid']);

            $desc = $resvalue['field_story_expert_description_value'];
            $desc = str_replace("\n", "", $desc);
            $desc = str_replace("\r", "", $desc);
            $desc = str_replace("\t", "", $desc);

            //related content
            $related = relatedContentNodeType($resvalue['field_common_related_content_value']);

            $field_story_reporter_target_id = $resvalue['field_story_reporter_target_id'];
            $reporter_node = itg_common_get_node_title($field_story_reporter_target_id);
            //video url start
            $field_video_upload = $resvalue['field_video_upload_value'];
            $file_id = file_usage($field_video_upload);
            //to get the video of all the other formats
            $load_collection = field_collection_item_load($field_video_upload);

            $daily_motion_fid = $load_collection->field_videogallery_video_upload['und'][0]['fid'];

            // return all the video details
            $source_type = $resvalue['field_story_source_type_value'];
            $videotag = video_detail_formats($resvalue['nid'], $source_type);

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
            // Get Publish time:
            $pub_date = get_content_publish_date($nid);
            if (!empty($pub_date)) {  
              $pub_date = date('Y-m-d H:i:s', strtotime($pub_date[0]['field_itg_content_publish_date_value']));
            } else {
              $pub_date = "";
            }
            $title = strip_tags($title);
            //$desc = strip_tags($desc);
            $comment_cont = getCommentsCount($nid);
            $photo_list_array[$listcount]['v_id'] = "$nid";
            $photo_list_array[$listcount]['v_title'] = "$title";
            $photo_list_array[$listcount]['v_credit'] = "$reporter_node";
            $photo_list_array[$listcount]['v_byline'] = "$reporter_node";
            $photo_list_array[$listcount]['v_short_desc'] = "$desc";
            $photo_list_array[$listcount]['v_small_image'] = "$file_small_img_url";
            $photo_list_array[$listcount]['v_large_image'] = "$file_large_img_url";
            $photo_list_array[$listcount]['v_extralarge_image'] = "$file_extra_large_img_url";
            if (!empty($videotag['dailymotion'])) {
                $videoids = get_video_in_fieldcollection_by_nid($nid);
                foreach ($videoids as $keys => $video_value) {
                    if ($video_value->video_id != '') {
                        $video_id = $video_value->video_id;
                    } elseif ($video_value->solr_video_id != '') {
                        $video_id = $video_value->solr_video_id;
                    }
                }
                
                $inter_video_details = internal_video_bitrate_data($video_id);
                
                $bitrate_url = $inter_video_details['bitrate_url'];
                $file_url_1 = $inter_video_details['file_url'];
                $photo_list_array[$listcount]['v_is_default_player'] = "0";
                $photo_list_array[$listcount]['v_url'] = $bitrate_url;
                $photo_list_array[$listcount]['v_download_url'] = $file_url_1;
                //if ($videotag['dailymotion']['bitate_url']['download_url']) {
                    //$photo_list_array[$listcount]['v_download_url'] = $inter_video_details['bitrate_url'];
                //} else
                    //$photo_list_array[$listcount]['v_download_url'] = "" . BITARATES_BASE_PATH . "/x5o9vhw_848x480.mp4";
            }
            elseif (!empty($videotag['migrated'])) {
                $videoids = get_video_in_fieldcollection_by_nid_mirtaed($nid);
                foreach ($videoids as $keys => $video_value) {
                    $url = $video_value->field_migrated_video_url_value;
                }
                $data_video = itg_videogallery_get_video_bitrate_by_url($url, $nid);
                $bitrate_url = $data_video['bitrate_url'];
                $mp4_url = $data_video['file_url'];
                $photo_list_array[$listcount]['v_is_default_player'] = "0";
                $photo_list_array[$listcount]['v_url'] = $bitrate_url; //$mp4_url;
                //$video_path_mp4
                $photo_list_array[$listcount]['v_download_url'] = $mp4_url;
            }
            $v_duration = get_rv_video_duration_by_nid($nid);
            $term_pri = taxonomy_term_load($field_primary_category_value);
            $term_name_pri = $term_pri->name;
            $photo_list_array[$listcount]['v_view_count'] = "$nv_cont";
            $photo_list_array[$listcount]['v_comment_count'] = "$comment_cont";
            $photo_list_array[$listcount]['v_share_url'] = "$firebase_url";
            $photo_list_array[$listcount]['v_updated_datetime'] = "$pub_date";
            $photo_list_array[$listcount]['v_duration'] = "$v_duration";
            $photo_list_array[$listcount]['v_show_ad'] = "0";
            $photo_list_array[$listcount]['v_video_size'] = "300";
            $photo_list_array[$listcount]['v_subcategory_id'] = "$field_primary_category_value";
            $photo_list_array[$listcount]['v_subcategory_title'] = "$term_name_pri";

            $listcount++;
        }
    }

    $data['lcount'] = $listcount;
    $data['data'] = $photo_list_array;
    $data['updated_datetime'] = $pub_date;
    return $data;
}

/*
 * function for get video url query
 * @pram int $video_fid
 * @return string $qry
 */

function fid_videoid($video_fid) {
    if ($video_fid) {
        $qry = db_select('dailymotion_response_details', 'dr')->fields('dr', array('video_id'))->condition('dr.fid', $video_fid)->execute()->fetchField();
        return $qry;
    }
}

/**
 * main function for generate programCategoryPage array
 * @pram int $tid, $pageno
 *
 * @return array
 */
function programcategoryPageRerourceValue($tid = 0, $pageno = 0) {
    // variable decalartion
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
    $data = generateProgramCategoryList($tid, $pageno);
    if ($data['lcount'] > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }
    $datacount = $data['lcount'];
    $data_up_time = $data['updated_datetime'];
    //data array building
    $data_array['id'] = "$tid";
    $data_array['title'] = "$term_name";
    $data_array['layout_id'] = "0";
    $data_array['subcategory_id'] = "$tid";
    $data_array['subcategory_title'] = "$term_name";
    $data_array['program_count'] = "$datacount";
    $data_array['program_display_count'] = "10";
    $data_array['program_pagination_cap'] = "50";
    $data_array['updated_datetime'] = "$data_up_time";

    $data_array['program'] = $data['data'];
    $output_array['data'] = $data_array;

    return $output_array;
}

/**
 * function for  generateProgramCategoryList list
 * @pram int $tid, $pageno
 *
 * @return array
 */
function generateProgramCategoryList($tid, $pageno) {
    // variable declaration
    global $base_url;
    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $tid_list[] = $tid;
    $listcount = 0;
    $range_max = 10;
    $term = taxonomy_term_load($tid);
    $term_name = $term->name;
    $range_min = 0;
    if (!$pageno == 0) {
        $range_min = $pageno * $range_max;
    }

    // filter user data list
    /* Testing user id, i will remove after testing. */

    $filter_user_data = array(2744, 1584, 1162, 1155, 1141, 1137, 970, 1156, 1190, 1522, 3, 1350, 1148, 2573);
    $order_by = 'ASC';
    $type = "videogallery";
    $photo_list_array = array();
    $loop_count = 0; {
        $listcount = 0;

        // code vid=14  start
        if ($tid > 0) {
            $term_tree = taxonomy_get_tree(CATEGORY_MANAGMENT, $tid, $max_depth = NULL, $load_entities = FALSE);
        } else {
            $term_tree = taxonomy_get_tree(CATEGORY_MANAGMENT, 1206553, $max_depth = NULL, $load_entities = FALSE);
        }
        $term_tree_count = count($term_tree);
        if ($term_tree_count) {
            foreach ($term_tree as $key => $value) {
                $tid_list[] = $value->tid;
            }
        }

        // select node belong from current term id or child term id
        $query = db_select('taxonomy_index', 'ti');
        $query->leftJoin('node', 'n', 'n.nid=ti.nid');
        //join  for field value
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
        $query->leftJoin('field_data_field_video_upload', 'fvu', 'fvu.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_source_type', 'st', 'st.entity_id = n.nid');

        $query->leftJoin('field_data_field_common_related_content', 'rc', 'rc.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_syndication', 'fss', 'fss.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_reporter', 'fsr', 'fsr.entity_id=n.nid');
        $query->leftJoin('field_data_field_primary_category', 'fpc', 'fpc.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_expert_description', 'ffd', 'ffd.entity_id=n.nid');

        $query->fields('eli_file', array('uri'));
        $query->fields('li_file', array('uri'));
        $query->fields('mi_file', array('uri'));
        $query->fields('si_file', array('uri'));
        $query->fields('esi_file', array('uri'));

        $query->fields('mi', array('field_story_medium_image_fid'));
        $query->fields('li', array('field_story_large_image_fid'));
        $query->fields('si', array('field_story_small_image_fid'));
        $query->fields('eli', array('field_story_extra_large_image_fid'));
        $query->fields('rc', array('field_common_related_content_value'));

        $query->fields('kt', array('field_story_kicker_text_value'));
        $query->fields('vd', array('field_video_duration_value'));
        $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));
        $query->fields('fss', array('field_story_syndication_value'));
        $query->fields('fsr', array('field_story_reporter_target_id'));
        $query->fields('fvu', array('field_video_upload_value'));
        $query->fields('st', array('field_story_source_type_value'));
        $query->fields('fpc', array('field_primary_category_value'));
        $query->fields('ffd', array('field_story_expert_description_value'));
        //end

        if ($tid == 0 && count($tid_list) > 0) {
            $query->condition('ti.tid', $tid_list, 'IN');
        } else {
            $query->condition('ti.tid', $tid, '=');
        }
        $interval = itg_app_time_interval($tid);
        $d1 = date('Y-m-d', strtotime("-" . $interval . " days"));
        $d2 = date(strtotime($d1));
        $query->condition('n.created', $d2, '>=');
        $query->condition('n.uid', $filter_user_data, 'NOT IN');
        $query->condition('n.status', 1)->condition('n.type', $type)->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);

        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

        foreach ($result as $reskey => $resvalue) {
            // node feed tag
            $title = $resvalue['title'];
            $type = $resvalue['type'];
            $nid = $resvalue['nid'];
            $created = $resvalue['created'];
            $changed = $resvalue['changed'];
            $field_story_kicker_text_value = $resvalue['field_story_kicker_text_value'];
            $nv_cont = getNodeViewCount($nid);
            $alias = drupal_get_path_alias('node/' . $nid . '');
            $weburl = $base_url . "/" . $alias;
            $field_video_duration_value = $resvalue['field_video_duration_value'];
            // file url
            $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
            $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);
            $file_large_img_url = completeFilePath($resvalue['field_story_large_image_fid']);
            $file_extra_large_img_url = completeFilePath($resvalue['field_story_extra_large_image_fid']);

            //related content
            $related = relatedContentNodeType($resvalue['field_common_related_content_value']);
            $field_story_reporter_target_id = $resvalue['field_story_reporter_target_id'];
            $reporter_node = itg_common_get_node_title($field_story_reporter_target_id);
            //video url start
            $field_video_upload = $resvalue['field_video_upload_value'];
            $file_id = file_usage($field_video_upload);
            //to get the video of all the other formats
            $load_collection = field_collection_item_load($field_video_upload);
            $daily_motion_fid = $load_collection->field_videogallery_video_upload['und'][0]['fid'];
            $anchor_id = getVedioAnchor($nid);
            $desc = $resvalue['field_story_expert_description_value'];
            $desc = str_replace("\n", "", $desc);
            $desc = str_replace("\r", "", $desc);
            $desc = str_replace("\t", "", $desc);


            //display all the video sounce check and format
            $source_type = $resvalue['field_story_source_type_value'];
            $videotag = video_detail_formats($nid, $source_type);
            $filesize = $videotag['dailymotion']['filsize'];
            //video url end
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
            // Get Publish time:
            $pub_date = get_content_publish_date($nid);
            if (!empty($pub_date)) {  
              $pub_date = date('Y-m-d H:i:s', strtotime($pub_date[0]['field_itg_content_publish_date_value']));
            } else {
              $pub_date = "";
            }
            $title = strip_tags($title);
            //$desc = strip_tags($desc);
            $photo_list_array[$listcount]['p_id'] = "$nid";
            $photo_list_array[$listcount]['p_title'] = "$title";
            $photo_list_array[$listcount]['p_credit'] = "$reporter_node";
            $photo_list_array[$listcount]['p_byline'] = "$reporter_node";
            $photo_list_array[$listcount]['p_short_desc'] = "$desc";
            $photo_list_array[$listcount]['p_small_image'] = "$file_small_img_url";
            $photo_list_array[$listcount]['p_large_image'] = "$file_large_img_url";
            $photo_list_array[$listcount]['p_extralarge_image'] = "$file_extra_large_img_url";

            //if($video_path_mp4){
            if (!empty($videotag['migrated'])) {
                $videoids = get_video_in_fieldcollection_by_nid_mirtaed($nid);
                foreach ($videoids as $keys => $video_value) {
                    $url = $video_value->field_migrated_video_url_value;
                }
                $data_video = itg_videogallery_get_video_bitrate_by_url($url, $nid);
                $bitrate_url = $data_video['bitrate_url'];
                $mp4_url = $data_video['file_url'];
                $photo_list_array[$listcount]['p_is_default_player'] = "0";
                $photo_list_array[$listcount]['p_url'] = $bitrate_url; //$mp4_url;
                $photo_list_array[$listcount]['p_download_url'] = $mp4_url;
            } elseif (!empty($videotag['dailymotion'])) {
                $videoids = get_video_in_fieldcollection_by_nid($nid);
                foreach ($videoids as $keys => $video_value) {
                    if ($video_value->video_id != '') {
                        $video_id = $video_value->video_id;
                    } elseif ($video_value->solr_video_id != '') {
                        $video_id = $video_value->solr_video_id;
                    }
                }
                $inter_video_details = internal_video_bitrate_data($video_id);
                $bitrate_url = $inter_video_details['bitrate_url'];
                $file_url_1 = $inter_video_details['file_url'];
                $photo_list_array[$listcount]['p_is_default_player'] = "0";
                $photo_list_array[$listcount]['p_url'] = $bitrate_url; //$videotag['dailymotion']['video_id'];
                $photo_list_array[$listcount]['p_download_url'] = $file_url_1;
                // if ($videotag['dailymotion']['bitate_url']['download_url']) {
                    // $photo_list_array[$listcount]['p_download_url'] = $inter_video_details['bitrate_url'];
                // } else
                    // $photo_list_array[$listcount]['p_download_url'] = "" . BITARATES_BASE_PATH . "/x5o9vhw_848x480.mp4";
            }
            $field_primary_category_value = $resvalue['field_primary_category_value'];
            $term = taxonomy_term_load($field_primary_category_value);
            $term_name = $term->name;
            $trem_id = $term->tid;
            $comment_cont = getCommentsCount($nid);
            $p_duration = get_rv_video_duration_by_nid($nid);
            $photo_list_array[$listcount]['p_view_count'] = "$nv_cont";
            $photo_list_array[$listcount]['p_comment_count'] = "$comment_cont";
            $photo_list_array[$listcount]['p_share_url'] = "$firebase_url";
            $photo_list_array[$listcount]['p_updated_datetime'] = "$pub_date";
            $photo_list_array[$listcount]['p_duration'] = "$p_duration";
            $photo_list_array[$listcount]['p_show_ad'] = "0";
            $photo_list_array[$listcount]['p_subcategory_id'] = "$trem_id";
            $photo_list_array[$listcount]['p_subcategory_title'] = "$term_name";
            $photo_list_array[$listcount]['p_program_size'] = "$filesize";
            $photo_list_array[$listcount]['p_anchor_id'] = "$anchor_id";

            $listcount++;
        }
    }
    $data['lcount'] = $listcount;
    $data['data'] = $photo_list_array;
    $data['updated_datetime'] = $pub_date;

    return $data;
}

/**
 * function for  programCategoryListlPageRerourceValue
 * @pram string $token
 *
 * @return array
 */
function programCategoryListlPageRerourceValue($token) {
    $output_array = array();
    $data_array = array();
    $program_list_array = array();
    $updated_datetime = "";
    $conf_array = tidConfig();
    $program_key = "itg_programmes_order_by";
    //$Program_section_list = array(1207797,1207827,1207722,1208900,1208095,1208902,1768536,1208173,1207755,1206960,1207972,1208898,1208061);
    $Program_section_list = array(1207797,1207827,1207722,1208900,1208095,1208902,1208173,1207755,1206960,1207972,1208061);
    

    // list array building
    $data = generateProgramSectionList($Program_section_list);
    if ($data['lcount'] > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }

    $datacount = $data['lcount'];
    $data_up_time = $data['updated_datetime'];
    if ($data_up_time) {
        $changed_datetime = date("Y-m-d H:i:s", $data_up_time);
    } else {
        $changed_datetime = "";
    }
    //data array building
    $output_array['data']['updated_datetime'] = $changed_datetime;
    $output_array['data']['program'] = $data['data'];
    return $output_array;
}

/**
 * function for  generateProgramSectionList
 * @pram array $program_section_list
 *
 * @return array
 */
function generateProgramSectionList($Program_section_list) {
    $data = array();
    $output_ar = array();
    $listcount = 0;
    foreach ($Program_section_list as $key => $value) {
        $value = (int) $value;
        $term = taxonomy_term_load($value);
        $update_time = getLatestNodeTime($term->tid);
        $term_name = $term->name;
        $term_url = nodeCategoryFrontUrl($value, 'term');
        $child_term_url = nodeCategoryFrontUrl($value, 'term');
        $p_short_description = strip_tags($term->description);
        $p_short_description = str_replace("\n", "", $p_short_description);
        $p_short_description = str_replace("\r", "", $p_short_description);
        $p_short_description = str_replace("\t", "", $p_short_description);

        $p_schedule = $term->field_program_timing_in_days['und'][0]['value'];

        $term_name = drupal_strtolower(str_replace(" ", "-", $term_name));
        $term_name = drupal_strtolower(str_replace("&", "and", $term_name));
        //$cat_icon_img = sectionCategoryIconImg($value);
        $cat_icon_img = sectionPrgramIconImg($value);
        $p_short_description = $p_short_description;

        $data[$listcount]['p_id'] = "$value";
        $data[$listcount]['p_title'] = "$term->name";
        $data[$listcount]['p_image'] = "$cat_icon_img";
        $data[$listcount]['p_type'] = "programlist";
        $data[$listcount]['p_short_description'] = "$p_short_description";
        $data[$listcount]['p_schedule'] = "$p_schedule";
        $listcount++;
    }

    $output_ar['data'] = $data;
    $output_ar['lcount'] = $listcount;
    $output_ar['updated_datetime'] = $update_time;

    return $output_ar;
}

/**
 * function for  getLatestNodeTime
 * @pram int $tid
 *
 * @return array
 */
function getLatestNodeTime($tid) {
    if ($tid) {
        $query = db_select('taxonomy_index', 'txi');
        $query->fields('txi', array('created'));
        $query->condition('txi.tid', $tid);
        $query->orderBy('txi.created', 'DESC');
        $query->range(0, 1);
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        $published_statp = $result[0]['created'];
        return $published_statp;
    }
}

/**
 * function for  return anchor id
 *
 * @param type $nid
 *
 * @return $anchor_id
 */
function getVedioAnchor($nid) {
    if ($nid) {
        $query = db_select('field_data_field_video_anchor', 'fda');
        $query->fields('fda', array('field_video_anchor_target_id'));
        $query->condition('fda.entity_id', $nid);
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        $anchor_id = $result[0]['field_video_anchor_target_id'];
        return $anchor_id;
    }
}

/* Change request */

/**
 * function for generate VideoDetail
 * @pram int $nid
 *
 * @return array
 */
function generateVideoDetail($nid) {
    // variable declaration
    global $base_url;
    $field_story_source_type = array();
    $data = array();
    $listcount = 0;
    if ($nid) {
        $node = node_load($nid);
        // node feed tag
        $title = $node->title;
        $type = $node->type;
        $nid = $node->nid;
        $created = $node->created;
        $changed = $node->changed;
        $field_story_kicker_text_value = $node->field_video_kicker['und']['0']['value'];
        $field_primary_category_value = $node->field_primary_category['und']['0']['value'];

        $nv_cont = getNodeViewCount($nid);
        $alias = drupal_get_path_alias('node/' . $nid . '');
        $weburl = $base_url . "/" . $alias;
        $field_video_duration_value = $node->field_video_duration['und']['0']['value'];
        // file url
        $file_small_img_url = completeFilePath($node->field_story_small_image['und']['0']['fid']);
        $file_medium_img_url = completeFilePath($node->field_story_medium_image['und']['0']['fid']);
        $file_large_img_url = completeFilePath($node->field_story_large_image['und']['0']['fid']);
        $file_extra_large_img_url = completeFilePath($node->field_story_extra_large_image['und']['0']['fid']);

        $desc = $node->field_story_expert_description['und']['0']['value'];
        $desc = str_replace("\n", "", $desc);
        $desc = str_replace("\r", "", $desc);
        $desc = str_replace("\t", "", $desc);

        //related content
        $related = relatedContentNodeType($node->field_common_related_content['und']['0']['value']);

        $field_story_reporter_target_id = $node->field_story_reporter['und']['0']['target_id'];
        $reporter_node = itg_common_get_node_title($field_story_reporter_target_id);
        //video url start
        $field_video_upload = $node->field_video_upload['und']['0']['value'];
        $file_id = file_usage($field_video_upload);
        //to get the video of all the other formats
        $load_collection = field_collection_item_load($field_video_upload);

        $daily_motion_fid = $load_collection->field_videogallery_video_upload['und'][0]['fid'];

        // return all the video details
        $source_type = $node->field_story_source_type['und']['0']['value'];
        $videotag = video_detail_formats($nid, $source_type);

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
        $title = strip_tags($title);
        $desc = strip_tags($desc);
        $photo_list_array[$listcount]['v_id'] = "$nid";
        $photo_list_array[$listcount]['v_title'] = "$title";
        $photo_list_array[$listcount]['v_credit'] = "$reporter_node";
        $photo_list_array[$listcount]['v_byline'] = "$reporter_node";
        $photo_list_array[$listcount]['v_short_desc'] = "$desc";
        $photo_list_array[$listcount]['v_small_image'] = "$file_small_img_url";
        $photo_list_array[$listcount]['v_large_image'] = "$file_large_img_url";
        $photo_list_array[$listcount]['v_extralarge_image'] = "$file_extra_large_img_url";
        if (!empty($videotag['dailymotion'])) {
            $videoids = get_video_in_fieldcollection_by_nid($nid);
            foreach ($videoids as $keys => $video_value) {
                if ($video_value->video_id != '') {
                    $video_id = $video_value->video_id;
                } elseif ($video_value->solr_video_id != '') {
                    $video_id = $video_value->solr_video_id;
                }
            }
            $inter_video_details = internal_video_bitrate_data($video_id);
            $bitrate_url = $inter_video_details['bitrate_url'];
            $file_url_1 = $inter_video_details['file_url'];
            $photo_list_array[$listcount]['v_is_default_player'] = "0";
            $photo_list_array[$listcount]['v_url'] = $bitrate_url;
            $photo_list_array[$listcount]['v_download_url'] = $file_url_1;
            //if ($videotag['dailymotion']['bitate_url']['download_url']) {
                //$photo_list_array[$listcount]['v_download_url'] = $inter_video_details['bitrate_url'];
            //} else
                //$photo_list_array[$listcount]['v_download_url'] = "" . BITARATES_BASE_PATH . "/x5o9vhw_848x480.mp4";
        }
        elseif (!empty($videotag['migrated'])) {
            $videoids = get_video_in_fieldcollection_by_nid_mirtaed($nid);
            foreach ($videoids as $keys => $video_value) {
                $url = $video_value->field_migrated_video_url_value;
            }
            $data_video = itg_videogallery_get_video_bitrate_by_url($url, $nid);
            $bitrate_url = $data_video['bitrate_url'];
            $mp4_url = $data_video['file_url'];
            $photo_list_array[$listcount]['v_is_default_player'] = "0";
            $photo_list_array[$listcount]['v_url'] = $bitrate_url; //$mp4_url;
            //$video_path_mp4
            $photo_list_array[$listcount]['v_download_url'] = $mp4_url;
        }
        $v_duration = get_rv_video_duration_by_nid($nid);
        $comment_cont = getCommentsCount($nid);
        $term_pri = taxonomy_term_load($field_primary_category_value);
        $term_name_pri = $term_pri->name;
        $photo_list_array[$listcount]['v_view_count'] = "$nv_cont";
        $photo_list_array[$listcount]['v_comment_count'] = "$comment_cont";
        $photo_list_array[$listcount]['v_share_url'] = "$firebase_url";
        $photo_list_array[$listcount]['v_updated_datetime'] = "$changed_datetime";
        $photo_list_array[$listcount]['v_duration'] = "$v_duration";
        $photo_list_array[$listcount]['v_show_ad'] = "0";
        $photo_list_array[$listcount]['v_video_size'] = "300";
        $photo_list_array[$listcount]['v_subcategory_id'] = "$field_primary_category_value";
        $photo_list_array[$listcount]['v_subcategory_title'] = "$term_name_pri";
    }
    $data['status_code'] = "1";
    $data['status_message'] = "";
    $data['data'] = $photo_list_array;
    return $data;
}

/**
 * function for  generateProgramDetail
 * @pram int $nid
 *
 * @return array
 */
function generateProgramDetail($nid) {
    // variable declaration
    global $base_url;
    $listcount = 0;
    $photo_list_array = array();
    $data = array();
    if ($nid) {
        // node feed tag
        $node = node_load($nid);
        $title = $node->title;
        $type = $node->type;
        $nid = $node->nid;
        $created = $node->created;
        $changed = $node->changed;
        $field_story_kicker_text_value = $node->field_video_kicker['und']['0']['value'];
        $nv_cont = getNodeViewCount($nid);
        $alias = drupal_get_path_alias('node/' . $nid . '');
        $weburl = $base_url . "/" . $alias;
        $field_video_duration_value = $node->field_video_duration['und']['0']['value'];
        // file url
        $file_small_img_url = completeFilePath($node->field_story_small_image['und']['0']['fid']);
        $file_medium_img_url = completeFilePath($node->field_story_medium_image['und']['0']['fid']);
        $file_large_img_url = completeFilePath($node->field_story_large_image['und']['0']['fid']);
        $file_extra_large_img_url = completeFilePath($node->field_story_extra_large_image['und']['0']['fid']);

        //related content
        $related = relatedContentNodeType($node->field_common_related_content['und']['0']['value']);
        $field_story_reporter_target_id = $node->field_story_reporter['und']['0']['target_id'];
        $reporter_node = itg_common_get_node_title($field_story_reporter_target_id);
        //video url start
        $field_video_upload = $node->field_video_upload['und']['0']['value'];
        $file_id = file_usage($field_video_upload);
        //to get the video of all the other formats
        $load_collection = field_collection_item_load($field_video_upload);
        $daily_motion_fid = $load_collection->field_videogallery_video_upload['und'][0]['fid'];
        $anchor_id = getVedioAnchor($nid);
        $desc = $node->field_story_expert_description['und']['0']['value'];
        $desc = str_replace("\n", "", $desc);
        $desc = str_replace("\r", "", $desc);
        $desc = str_replace("\t", "", $desc);

        //display all the video sounce check and format
        $source_type = $node->field_story_source_type['und']['0']['value'];
        $videotag = video_detail_formats($nid, $source_type);
        $filesize = $videotag['dailymotion']['filsize'];
        //video url end
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
        $title = strip_tags($title);
        //$desc = strip_tags($desc);
        $photo_list_array[$listcount]['p_id'] = "$nid";
        $photo_list_array[$listcount]['p_title'] = "$title";
        $photo_list_array[$listcount]['p_credit'] = "$reporter_node";
        $photo_list_array[$listcount]['p_byline'] = "$reporter_node";
        $photo_list_array[$listcount]['p_short_desc'] = "$desc";
        $photo_list_array[$listcount]['p_small_image'] = "$file_small_img_url";
        $photo_list_array[$listcount]['p_large_image'] = "$file_large_img_url";
        $photo_list_array[$listcount]['p_extralarge_image'] = "$file_extra_large_img_url";
        //if($video_path_mp4){
        if (!empty($videotag['dailymotion'])) {
            $videoids = get_video_in_fieldcollection_by_nid($nid);
            foreach ($videoids as $keys => $video_value) {
                if ($video_value->video_id != '') {
                    $video_id = $video_value->video_id;
                } elseif ($video_value->solr_video_id != '') {
                    $video_id = $video_value->solr_video_id;
                }
            }
            $inter_video_details = internal_video_bitrate_data($video_id);
            $photo_list_array[$listcount]['p_is_default_player'] = "0";
            $photo_list_array[$listcount]['p_url'] = $inter_video_details['bitrate_url'];
            $photo_list_array[$listcount]['p_download_url'] = $inter_video_details['file_url'];
        }
        elseif (!empty($videotag['migrated'])) {
            $videoids = get_video_in_fieldcollection_by_nid_mirtaed($nid);
            foreach ($videoids as $keys => $video_value) {
                $url = $video_value->field_migrated_video_url_value;
            }
            $data_video = itg_videogallery_get_video_bitrate_by_url($url, $nid);
            $bitrate_url = $data_video['bitrate_url'];
            $mp4_url = $data_video['file_url'];
            $video_path_mp4 = $video_path_info['video_path_mp4'];
            $photo_list_array[$listcount]['p_is_default_player'] = "0";
            $photo_list_array[$listcount]['p_url'] = $bitrate_url; //$mp4_url;
            $photo_list_array[$listcount]['p_download_url'] = $mp4_url;
        }
        $field_primary_category_value = $node->field_primary_category['und']['0']['value'];
        $term = taxonomy_term_load($field_primary_category_value);
        $term_name = $term->name;
        $trem_id = $term->tid;
        $comment_cont = getCommentsCount($nid);
        $p_duration = get_rv_video_duration_by_nid($nid);
        $photo_list_array[$listcount]['p_view_count'] = "$nv_cont";
        $photo_list_array[$listcount]['p_comment_count'] = "$comment_cont";
        $photo_list_array[$listcount]['p_share_url'] = "$firebase_url";
        $photo_list_array[$listcount]['p_updated_datetime'] = "$changed_datetime";
        $photo_list_array[$listcount]['p_duration'] = "$p_duration";
        $photo_list_array[$listcount]['p_show_ad'] = "0";
        $photo_list_array[$listcount]['p_subcategory_id'] = "$trem_id";
        $photo_list_array[$listcount]['p_subcategory_title'] = "$term_name";
        $photo_list_array[$listcount]['p_program_size'] = "$filesize";
        $photo_list_array[$listcount]['p_anchor_id'] = "$anchor_id";
    }
    $data['status_code'] = "1";
    $data['status_message'] = "";
    $data['data'] = $photo_list_array;
    return $data;
}

/**
 * function for featuresWidgetData list
 *
 * @return array
 */
function featuresWidgetData() {

    $output = "";
    $widget_name = "home_page_feature_widget";
    $range_max = 3;
    $range_min = 0;
    $order_by = 'ASC';
    $type = array("videogallery", "photogallery", "story");

    $query = db_select('itg_widget_order', 'iwo');
    $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
    //join  for field value
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

    $query->fields('eli_file', array('uri'));
    $query->fields('li_file', array('uri'));
    $query->fields('mi_file', array('uri'));
    $query->fields('si_file', array('uri'));
    $query->fields('esi_file', array('uri'));

    $query->fields('mi', array('field_story_medium_image_fid'));
    $query->fields('si', array('field_story_small_image_fid'));
    $query->fields('rc', array('field_common_related_content_value'));
    $query->fields('li', array('field_story_large_image_fid'));

    $query->fields('kt', array('field_story_kicker_text_value'));
    $query->fields('vd', array('field_video_duration_value'));
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));


    //end
    $query->condition('iwo.widget', $widget_name)->condition('n.status', 1)->condition('n.type', $type, 'IN')->orderBy('iwo.weight', $order_by)->orderBy('n.nid', 'DESC')->range($range_min, $range_max)->fields('iwo', array('nid', 'extra', 'weight'));
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    return $result;
}

/**
 * function for  topstoriesList
 *
 * @return array
 */
function topstoriesList($source, $limit = 0) {
    // variable declation
    global $order;
    $data_topstories = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    $home_list_count = 0;
    $widget_name = "top_stories_widget";
    $range_max = 15;
    $result_fs = featuresWidgetData();
    if ($source == 'home') {
        $result_fs_cont_ar = $result_fs;
        $result_fs_cont = count($result_fs_cont_ar);
        $range_max = 10- $result_fs_cont;
        if($limit > 0){
            $range_max = $limit- $result_fs_cont;
        }
    }
    $range_min = 0;
    $order_by = 'ASC';

    $query = db_select('itg_widget_order', 'iwo');
    $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
    $query->leftJoin('taxonomy_index', 'ti', 'n.nid=ti.nid');
    //join  for field value
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

    $query->fields('eli_file', array('uri'));
    $query->fields('li_file', array('uri'));
    $query->fields('mi_file', array('uri'));
    $query->fields('si_file', array('uri'));
    $query->fields('esi_file', array('uri'));

    $query->fields('mi', array('field_story_medium_image_fid'));
    $query->fields('si', array('field_story_small_image_fid'));
    $query->fields('rc', array('field_common_related_content_value'));
    $query->fields('li', array('field_story_large_image_fid'));

    $query->fields('kt', array('field_story_kicker_text_value'));
    $query->fields('vd', array('field_video_duration_value'));
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));
    $query->fields('ti', array('tid'));
    $query->fields('dbody', array('body_value'));


    //end
    $query->condition('iwo.widget', $widget_name)->condition('n.status', 1)->condition('n.type', 'story')->groupBy('n.nid')->orderBy('iwo.weight', $order_by)->orderBy('n.nid', 'DESC')->range($range_min, $range_max)->fields('iwo', array('nid', 'extra', 'weight'));
    $result_ts = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    
    $result = array_merge($result_fs, $result_ts);
    //$result = array_merge($result_ts, $result_fs);

    $data_topstories['id'] = "0";
    $data_topstories['title'] = "Top Stories";
    $data_topstories['label'] = "Top Stories";
    $data_topstories['show_label'] = "0";
    if ($source == 'home') {
        $data_topstories['id'] = "0";
        $data_topstories['order'] = "$order";
        $data_topstories['type'] = "topstories";
        $data_topstories['title'] = "Top Stories";
        $data_topstories['label'] = "Top Stories";
        $data_topstories['show_label'] = "0";
        $data_topstories['n_template_id'] = "1";
    }

    // loop on top stories.
    foreach ($result as $key => $value) {
        // varibale for json tag
        $title = $value['title'];
        $type = $value['type'];
        $nid = $value['nid'];
        $created = $value['created'];
        $changed = $value['changed'];
        $tid = $value['tid'];
        $field_story_kicker_text_value = $value['field_story_kicker_text_value'];
        $body_value = $value['body_value'];

        $term = taxonomy_term_load($tid);
        $term_name = $term->name;

        // file url
        $file_small_img_url = completeFilePath($value['field_story_small_image_fid']);
        $file_medium_img_url = completeFilePath($value['field_story_medium_image_fid']);
        $file_large_img_url = completeFilePath($value['field_story_large_image_fid']);
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
            $changed_datetime = date("Y-m-d H:i:s", $created);
        }
        // Get Publish time:
        $pub_date = get_content_publish_date($nid);
        if (!empty($pub_date)) {  
          $pub_date = date('Y-m-d H:i:s', strtotime($pub_date[0]['field_itg_content_publish_date_value']));
        } else {
          $pub_date = "";
        }
        //json tag writing
        //if ($type == "story") {
        // news list

        $n_rating = getRating($node);
        $n_magazine = array();

        // custom function for get img caption
        $caption = getImgCaption($value['field_story_medium_image_fid']);
        // custom function for get img byline
        $byline = getImgByline($value['field_story_medium_image_fid']);
        $is_developing = 0;
        $conf = getStoryConfigVal($nid);
        if (in_multiarray("developing_story", $conf, "field_story_configurations_value")) {
            $is_developing = 1;
        }
        if ($type == 'story') {
            $type = getStoryType($nid);
        }
        $prime_cat = getNodePrimeCatByNid($nid);
        $data_newslist[$home_list_count]['n_id'] = "$nid";
        //$data_newslist[$home_list_count]['n_template_id'] = "";
        $data_newslist[$home_list_count]['n_type'] = "$type";
        $data_newslist[$home_list_count]['n_is_developing'] = "$is_developing";
        $data_newslist[$home_list_count]['n_is_sponsored'] = "0";
        $data_newslist[$home_list_count]['n_share_link'] = "$firebase_url";
        $data_newslist[$home_list_count]['n_title'] = "$title";
        $data_newslist[$home_list_count]['n_description'] = "$field_story_kicker_text_value";
        $data_newslist[$home_list_count]['n_pcategory_id'] = "$prime_cat->tid";
        $data_newslist[$home_list_count]['n_pcategory_name'] = "$prime_cat->name";
        $data_newslist[$home_list_count]['n_comment_count'] = "$comment_cont";
        $data_newslist[$home_list_count]['n_small_image'] = "$file_small_img_url";
        $data_newslist[$home_list_count]['n_large_image'] = "$file_large_img_url";
        $data_newslist[$home_list_count]['n_image_credit'] = "$byline";
        $data_newslist[$home_list_count]['n_updated_datetime'] = "$changed_datetime";
        
        $heighligth = array();
        $heighligth = (array) getHighlightByNid($nid);
        $data_newslist[$home_list_count]['n_highlight'] = $heighligth;

        //$data_newslist[$home_list_count]['n_photo'] = $n_photo;
        //$data_newslist[$home_list_count]['n_video'] = $n_video;
        // photo list array
        if ($type == "photogallery") {
            $photolist = getPhotolist($nid);
        } elseif ($type == "photostory") {
            $photo_list_array = generatePhotoStoryDetailList($nid);
            $photolist = $photo_list_array['data'];
        }
        $data_newslist[$home_list_count]['n_photo'] = (array) $photolist;
        // re-insalize photolist
        $photolist = array();

        // video list array
        if ($type == "videogallery") {
            $videolist = getVideolist($nid);
        }
        $data_newslist[$home_list_count]['n_video'] = (array) $videolist;
        // re-insalize vediolist
        $videolist = array();
        $data_newslist[$home_list_count]['n_polls'] = $n_polls;
        $data_newslist[$home_list_count]['n_rating'] = $n_rating;
        $data_newslist[$home_list_count]['n_magazine'] = $n_magazine;
        $n_widget = array();
        $data_newslist[$home_list_count]['n_widget'] = $n_widget;
        /* work on offline start */

        if ($type == "story"  && $source != 'home') {
            $byline_data = itg_get_multi_byline_details($nid, 1);
            $aid = $byline_data[0]['nid'];
            $a_title = $byline_data[0]['title'];
            $body_without_html = strip_tags($body_value);
            //$body_with_html_data = formateNodeBodyToken($body_value);
            //$body_with_html = $body_with_html_data['n_body'];
            $no_desc_withouthtml = $body_without_html;
            $arr_offline = array();
            $arr_offline['no_desc_withouthtml'] = "$body_without_html";
            $arr_offline['no_author']['a_title'] = "$a_title";
            $data_newslist[$home_list_count]['n_offline_data'] = $arr_offline;
        }
        /* work on offline end */
        $home_list_count++;
        //}
    }


    if ($source == 'home') {
        $data_topstories['news'] = (array) $data_newslist;
        $order++;
    } else {
        $data_topstories['data'] = (array) $data_newslist;
    }
    return $data_topstories;
}
