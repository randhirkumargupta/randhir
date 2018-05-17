<?php

/**
 * Inc file contains the functions author story api
 */

/**
 * main function for generate author_story_list api
 * @pram int $author_id, $story_type, $cpageno
 *
 * @return array
 */
function author_story_list($author_id = 0, $story_type = 0, $cpageno = 0) {
    // variable decalartion
    $data = '';
    $output_array = array();
    $data_array = array();
    $updated_datetime = "";

    // list array building
    // latest story
    if ($story_type == '0') {
        $data = author_latest_storylist($author_id, $cpageno);
    }
    // popular story
    elseif ($story_type == '1') {
        $data = author_popular_storylist($author_id, $cpageno);
    }



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

    $data_array['author_id'] = "$author_id";
    $data_array['news_count'] = "$datacount";
    $data_array['news_display_count'] = "10";
    $data_array['news_pagination_cap'] = "10";


    $data_array['news'] = isset($data['data']) ? $data['data'] : array();
    $output_array['data'] = $data_array;

    return $output_array;
}

/**
 * function for generate author_latest_storylist array
 * @pram int $author_id, $cpageno
 *
 * @return array
 */
function author_latest_storylist($author_id, $cpageno) {
    global $base_url;
    $range_max = 10;
    $range_min = 0;
    $changed_datetime = "";

    if (!$cpageno == 0) {
        $range_min = $cpageno * $range_max;
    }


    $data = array();
    $type = array("story");

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_common_by_line_reporter_id', 'bl', 'bl.entity_id = n.nid');
    $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id = n.nid');
    $query->leftJoin('taxonomy_term_data', 'td', 'td.tid = pc.field_primary_category_value');
    $query->leftJoin('field_data_field_story_kicker_text', 'sk', 'sk.entity_id = n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
    $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
    $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
    $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
    $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
    $query->leftJoin('field_data_field_story_rating', 'sr', 'sr.entity_id = n.nid');
    $query->leftJoin('field_data_field_story_source_type', 'st', 'st.entity_id = n.nid');

    $query->fields('n', array('nid', 'title', 'type', 'created', 'changed'));
    $query->fields('td', array('tid', 'name'));
    $query->fields('sk', array('field_story_kicker_text_value'));
    $query->fields('si', array('field_story_small_image_fid'));
    $query->fields('li', array('field_story_large_image_fid'));
    $query->fields('eli', array('field_story_extra_large_image_fid'));
    $query->fields('st', array('field_story_source_type_value'));

    $query->fields('si_file', array('uri'));
    $query->fields('li_file', array('uri'));
    $query->fields('eli_file', array('uri'));
    $query->fields('sr', array('field_story_rating_value'));

    $query->condition('n.type', $type, 'IN');
    $query->condition('n.status', 1);
    //    $query->condition('n.nid','837198');
    $query->condition('bl.field_common_by_line_reporter_id_value', '%' . db_like($author_id) . '%', 'LIKE');
    $query->orderBy('n.nid', 'DESC');
    $query->range($range_min, $range_max);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $news = array();
    $news2 = array();
    foreach ($result as $k => $res) {

        $comment_cont = 0; //getCommentsCount($res['nid']);
        $changed = $res['changed'];
        $n_view_count = 0; //getNodeViewCount($res['nid']);
        $nid = $res['nid'];

        $n_share_count = 0; //getNodeShareCount($res['nid']);
        $file_small_img_url = file_create_url($res['uri']);
        $file_large_img_url = file_create_url($res['li_file_uri']);
        $type = $res['type'];
        $node_title = $res['title'];
        $short_desc = isset($res['field_story_kicker_text_value']) ? $res['field_story_kicker_text_value'] : '';

        if ($res['field_story_source_type_value'] != 'migrated') {
            $file_small_img_url = '';
            if ($res['uri'] != '') {
                $file_small_img_url = image_style_url('170x127', $res['uri']);
            }
            if ($res['li_file_uri'] != '') {
                $file_large_img_url = completeFilePath($res['field_story_large_image_fid']);
            }
            if ($res['eli_file_uri'] != '') {
                $file_extra_large_img_url = image_style_url('photo_slider_753x543', $res['eli_file_uri']);
            }
        } else {
            $file_small_img_url = completeFilePath($res['field_story_small_image_fid']);
            $file_large_img_url = completeFilePath($res['field_story_large_image_fid']);
            $file_extra_large_img_url = completeFilePath($res['field_story_extra_large_image_fid']);
        }

        $term_id = $res['tid'];
        $term_name = $res['name'];

        if ($changed) {
            $changed_datetime = date("Y-m-d H:i:s", $changed);
        }


        $news['n_id'] = "$nid";
        $news['n_type'] = "$type";
        $news['n_is_sponsored'] = "";
        $news['n_share_link'] = get_node_firebase_weburl($res['nid']);
        $news['n_title'] = "$node_title";
        $news['n_short_desc'] = "$short_desc";
        $news['n_pcategory_id'] = "$term_id";
        $news['n_pcategory_name'] = "$term_name";

        $news['n_rating'] = isset($res['field_story_rating_value']) ? $res['field_story_rating_value'] : '';
        $news['n_comment_count'] = "$comment_cont";
        $news['n_share_count'] = "$n_share_count";
        $news['n_view_count'] = "$n_view_count";
        $news['n_small_image'] = "$file_small_img_url";
        $news['n_large_image'] = "$file_large_img_url";
        $news['n_extralarge_image'] = "$file_extra_large_img_url";
        $news['n_updated_datetime'] = "$changed_datetime";
        $news2[] = $news;
    }

    $data['data'] = $news2;
    $data['lcount'] = count($news2);
    return $data;
}

function author_popular_storylist($author_id, $cpageno) {
    global $base_url;
    $range_max = 10;
    $range_min = 0;
    $changed_datetime = "";

    if (!$cpageno == 0) {
        $range_min = $cpageno * $range_max;
    }


    $data = array();
    $type = array("story");

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_common_by_line_reporter_id', 'bl', 'bl.entity_id = n.nid');
    $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id = n.nid');
    $query->leftJoin('taxonomy_term_data', 'td', 'td.tid = pc.field_primary_category_value');
    $query->leftJoin('field_data_field_story_kicker_text', 'sk', 'sk.entity_id = n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
    $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
    $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
    $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
    $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
    $query->leftJoin('field_data_field_story_rating', 'sr', 'sr.entity_id = n.nid');
    $query->leftJoin('field_data_field_story_source_type', 'st', 'st.entity_id = n.nid');

    $query->fields('n', array('nid', 'title', 'type', 'created', 'changed'));
    $query->fields('td', array('tid', 'name'));
    $query->fields('sk', array('field_story_kicker_text_value'));
    $query->fields('si', array('field_story_small_image_fid'));
    $query->fields('li', array('field_story_large_image_fid'));
    $query->fields('eli', array('field_story_extra_large_image_fid'));
    $query->fields('st', array('field_story_source_type_value'));

    $query->fields('si_file', array('uri'));
    $query->fields('li_file', array('uri'));
    $query->fields('eli_file', array('uri'));
    $query->fields('sr', array('field_story_rating_value'));

    $query->condition('n.type', $type, 'IN');
    $query->condition('n.status', 1);
    //    $query->condition('n.nid','837198');
    $query->condition('bl.field_common_by_line_reporter_id_value', '%' . db_like($author_id) . '%', 'LIKE');
    $query->orderBy('n.nid', 'DESC');
    $query->range($range_min, $range_max);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $news = array();
    $news2 = array();
    foreach ($result as $k => $res) {

        $comment_cont = 0; //getCommentsCount($res['nid']);
        $changed = $res['changed'];
        $n_view_count = 0; //getNodeViewCount($res['nid']);
        $nid = $res['nid'];

        $n_share_count = 0; //getNodeShareCount($res['nid']);
        $file_small_img_url = file_create_url($res['uri']);
        $file_large_img_url = file_create_url($res['li_file_uri']);
        $type = $res['type'];
        $node_title = $res['title'];
        $short_desc = isset($res['field_story_kicker_text_value']) ? $res['field_story_kicker_text_value'] : '';

        if ($res['field_story_source_type_value'] != 'migrated') {
            $file_small_img_url = '';
            if ($res['uri'] != '') {
                $file_small_img_url = image_style_url('170x127', $res['uri']);
            }
            if ($res['li_file_uri'] != '') {
                $file_large_img_url = completeFilePath($res['field_story_large_image_fid']);
            }
            if ($res['eli_file_uri'] != '') {
                $file_extra_large_img_url = image_style_url('photo_slider_753x543', $res['eli_file_uri']);
            }
        } else {
            $file_small_img_url = completeFilePath($res['field_story_small_image_fid']);
            $file_large_img_url = completeFilePath($res['field_story_large_image_fid']);
            $file_extra_large_img_url = completeFilePath($res['field_story_extra_large_image_fid']);
        }

        $term_id = $res['tid'];
        $term_name = $res['name'];

        if ($changed) {
            $changed_datetime = date("Y-m-d H:i:s", $changed);
        }


        $news['n_id'] = "$nid";
        $news['n_type'] = "$type";
        $news['n_is_sponsored'] = "";
        $news['n_share_link'] = get_node_firebase_weburl($res['nid']);
        $news['n_title'] = "$node_title";
        $news['n_short_desc'] = "$short_desc";
        $news['n_pcategory_id'] = "$term_id";
        $news['n_pcategory_name'] = "$term_name";

        $news['n_rating'] = isset($res['field_story_rating_value']) ? $res['field_story_rating_value'] : '';
        $news['n_comment_count'] = "$comment_cont";
        $news['n_share_count'] = "$n_share_count";
        $news['n_view_count'] = "$n_view_count";
        $news['n_small_image'] = "$file_small_img_url";
        $news['n_large_image'] = "$file_large_img_url";
        $news['n_extralarge_image'] = "$file_extra_large_img_url";
        $news['n_updated_datetime'] = "$changed_datetime";
        $news2[] = $news;
    }

    $data['data'] = $news2;
    $data['lcount'] = count($news2);
    return $data;
}

/*
 * function for get popular story based on max page visit and most shared stories
 *  i.e which has maximum loyality points
 * @pram int $author_id,$cpageno
 * @return array
 */
/* function author_popular_storylist($author_id, $cpageno) {
  global $base_url;
  $changed_datetime = "";
  $range_max = 10;
  $range_min = 0;
  if (!$cpageno == 0) {
  $range_min = $cpageno * $range_max;
  }


  $type = array("story");
  $data = array();

  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_common_by_line_reporter_id', 'bl', 'bl.entity_id = n.nid');
  $query->fields('n', array('nid'));
  $query->condition('n.type', $type, 'IN');
  $query->condition('n.status', 1);
  $query->condition('bl.field_common_by_line_reporter_id_value', '%' . db_like($author_id) . '%', 'LIKE');
  $query->range($range_min, $range_max);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  $popular_res = array();
  foreach ($result as $k => $res) {
  $popular_res[$res['nid']] = analytics_node_data($res['nid'], 'total');
  }
  //Sort Desc by total analytics count
  arsort($popular_res);

  $news = array();
  $news2 = array();
  foreach ($popular_res as $pop_res_k => $pop_res_v) {

  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_common_by_line_reporter_id', 'bl', 'bl.entity_id = n.nid');
  $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id = n.nid');
  $query->leftJoin('taxonomy_term_data', 'td', 'td.tid = pc.field_primary_category_value');
  $query->leftJoin('field_data_field_story_kicker_text', 'sk', 'sk.entity_id = n.nid');
  $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
  $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
  $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
  $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
  $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
  $query->leftJoin('field_data_field_story_rating', 'sr', 'sr.entity_id = n.nid');

  $query->fields('n', array('nid', 'title', 'type', 'created', 'changed'));
  $query->fields('td', array('tid', 'name'));
  $query->fields('sk', array('field_story_kicker_text_value'));
  $query->fields('si', array('field_story_small_image_fid'));
  $query->fields('li', array('field_story_large_image_fid'));
  $query->fields('eli', array('field_story_extra_large_image_fid'));

  $query->fields('si_file', array('uri'));
  $query->fields('li_file', array('uri'));
  $query->fields('sr', array('field_story_rating_value'));
  $query->condition('n.nid', $pop_res_k);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  foreach ($result as $k => $res) {

  $analy_data = analytics_node_data($res['nid']);
  $comment_cont = isset($analy_data['data_count_node_comment']) ? $analy_data['data_count_node_comment'] : '';
  $n_view_count = isset($analy_data['node_view_count']) ? $analy_data['node_view_count'] : '';
  $n_share_count = isset($analy_data['data_count_node_share']) ? $analy_data['data_count_node_share'] : '';

  $changed = $res['changed'];
  $file_small_img_url = completeFilePath($res['field_story_small_image_fid']);
  $file_large_img_url = completeFilePath($res['field_story_large_image_fid']);
  $file_extra_large_img_url = completeFilePath($res['field_story_extra_large_image_fid']);

  $node_id = $res['nid'];
  $node_type = $res['type'];
  $node_title = $res['title'];
  $node_short_desc = isset($res['field_story_kicker_text_value']) ? $res['field_story_kicker_text_value'] : '';
  $term_id = $res['tid'];
  $term_name = $res['name'];

  if ($changed) {
  $changed_datetime = date("Y-m-d H:i:s", $changed);
  }


  $news['n_id'] = "$node_id";
  $news['n_type'] = "$node_type";
  $news['n_is_sponsored'] = "";
  $news['n_share_link'] = get_node_firebase_weburl($res['nid']);
  $news['n_title'] = "$node_title";
  $news['n_short_desc'] = "$node_short_desc";
  $news['n_pcategory_id'] = "$term_id";
  $news['n_pcategory_name'] = "$term_name";

  $news['n_rating'] = isset($res['field_story_rating_value']) ? $res['field_story_rating_value'] : '';
  $news['n_comment_count'] = "$comment_cont";
  $news['n_share_count'] = "$n_share_count";
  $news['n_view_count'] = "$n_view_count";
  $news['n_small_image'] = "$file_small_img_url";
  $news['n_large_image'] = "$file_large_img_url";
  $news['p_extralarge_image'] = "$file_extra_large_img_url";
  $news['n_updated_datetime'] = "$changed_datetime";
  $news2[] = $news;
  }
  }

  $data['data'] = $news2;
  $data['lcount'] = count($result);
  return $data;
  } */

/**
 * function for generate author_detail_data array
 * @pram int $author_id
 *
 * @return array
 */
function author_detail_data($author_id) {

    $output_array = array();
    $data_array = array();
    $updated_datetime = "";

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_story_extra_large_image', 'ai', 'ai.entity_id = n.nid');
    $query->leftJoin('field_data_field_celebrity_pro_occupation', 'occ', 'occ.entity_id = n.nid');
    $query->leftJoin('field_data_field_reporter_twitter_handle', 'tw', 'tw.entity_id = n.nid');
    $query->leftJoin('field_data_body', 'db', 'db.entity_id = n.nid');
    $query->fields('n', array('nid', 'title'));
    $query->fields('ai', array('field_story_extra_large_image_fid'));
    $query->fields('occ', array('field_celebrity_pro_occupation_tid'));
    $query->fields('tw', array('field_reporter_twitter_handle_value'));
    $query->fields('db', array('body_value'));
    $query->condition('n.status', 1);
    $query->condition('n.nid', $author_id);
    // Author term id
    $query->condition('occ.field_celebrity_pro_occupation_tid', AUTHOR_TID);
    $query->condition('n.type', 'reporter');
    $result = $query->execute()->fetchAssoc();

    $num_of_results = count($result);

    if ($num_of_results > 1) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";

        $data_array['id'] = isset($result['nid']) ? $result['nid'] : '';
        $data_array['title'] = isset($result['title']) ? $result['title'] : '';
        $data_array['profile_image'] = completeFilePath($result['field_story_extra_large_image_fid']);
        $data_array['follower_count'] = '';
        $data_array['twitter_handler'] = isset($result['field_reporter_twitter_handle_value']) ? $result['field_reporter_twitter_handle_value'] : '';
        $data_array['location'] = '';
        $json_body_value = preg_replace("!\r?\n!", "", $result['body_value']);
        $data_array['desc'] = isset($result['body_value']) ? strip_tags($json_body_value) : '';
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
        $data_array = array();
    }


    $output_array['data'] = $data_array;
    return $output_array;
}

/**
 * function for generate anchor_detail_data array
 * @pram int $anchor_id
 *
 * @return array
 */
function anchor_detail_data($anchor_id) {

    $output_array = array();
    $data_array = array();
    $updated_datetime = "";

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_story_extra_large_image', 'ai', 'ai.entity_id = n.nid');
    $query->leftJoin('field_data_field_celebrity_pro_occupation', 'occ', 'occ.entity_id = n.nid');
    $query->leftJoin('field_data_field_reporter_twitter_handle', 'tw', 'tw.entity_id = n.nid');
    $query->leftJoin('field_data_body', 'db', 'db.entity_id = n.nid');
    $query->fields('n', array('nid', 'title'));
    $query->fields('ai', array('field_story_extra_large_image_fid'));
    $query->fields('occ', array('field_celebrity_pro_occupation_tid'));
    $query->fields('tw', array('field_reporter_twitter_handle_value'));
    $query->fields('db', array('body_value'));
    $query->condition('n.status', 1);
    $query->condition('n.nid', $anchor_id);
    // Anchor term id
    $query->condition('occ.field_celebrity_pro_occupation_tid', ANCHOR_TID);
    $query->condition('n.type', 'reporter');
    $result = $query->execute()->fetchAssoc();

    $num_of_results = count($result);

    if ($num_of_results > 1) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";

        $data_array['id'] = isset($result['nid']) ? $result['nid'] : '';
        $data_array['title'] = isset($result['title']) ? $result['title'] : '';
        $data_array['profile_image'] = completeFilePath($result['field_story_extra_large_image_fid']);
        $data_array['follower_count'] = '';
        $data_array['twitter_handler'] = isset($result['field_reporter_twitter_handle_value']) ? $result['field_reporter_twitter_handle_value'] : '';
        $data_array['location'] = '';
        $json_body_value = preg_replace("!\r?\n!", "", $result['body_value']);
        $data_array['desc'] = isset($result['body_value']) ? strip_tags($json_body_value) : "";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
        $data_array = array();
    }

    $output_array['data'] = $data_array;
    return $output_array;
}

/**
 * Return Newswrap list
 *
 * @return array
 */
function news_wrap_list() {
    // variable decalartion
    $output_array = array();
    $data_array = array();
    $updated_datetime = "";

    // list array building
    $data = news_wrap_datalist();
    $current_date = date('Y-m-d H:i:s', time());

    if ($data['lcount'] > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }

    $data_array['updated_datetime'] = "$current_date";
    $data_array['news'] = $data['data'];
    $output_array['data'] = $data_array;

    return $output_array;
}

/**
 * Return all the recent stories having highlights
 *
 * @return array
 */
function news_wrap_datalist() {
    global $base_url;
    $data = array();
    $data_topstories = topstoriesList();

    $data = $data_topstories['data'];
    $lcont = 0;
    foreach ($data as $k => $res) {
        if (count($res['n_highlight']) > 0) {
            $nid = $res['n_id'];
            $type = getStoryType($nid);
            $firebase_url = get_node_firebase_weburl($nid);
            $n_title = strip_tags($res['n_title']);
            $n_large_image = $res['n_large_image'];
            $n_updated_datetime = $res['n_updated_datetime'];
            $category_id = $res['n_pcategory_id'];
            $category_title = $res['n_pcategory_name'];
            $highlight = $res['n_highlight'];
            $news['n_id'] = $nid;
            $news['n_title'] = $n_title;
            $news['n_large_image'] = "$n_large_image";
            $news['n_updated_datetime'] = "$n_updated_datetime";
            $news['category_id'] = $category_id;
            $news['category_title'] = $category_title;
            $news['highlight'] = $highlight;
            $news['n_type'] = $type;
            $news['n_share_link'] = $firebase_url;
            // for emoji
            $n_emoji_left = array();
            $n_emoji_right = array();
            $emoji_left = $res['field_emoji_value'];
            $emoji_right = $res['field_emoji_2_value'];
            if ($emoji_left) {
                $n_emoji_left = itg_rapid_get_emoji($emoji_left);
            }
            if ($emoji_right) {
                $n_emoji_right = itg_rapid_get_emoji($emoji_right);
            }
            $news['n_emoji_left'] = $n_emoji_left;
            $news['n_emoji_right'] = $n_emoji_right; 
            $news2[] = $news;
            $lcont++;
        }
    }
    $data['data'] = $news2;
    $data['lcount'] = $lcont;
    return $data;
}

/**
 * function for generate anchor_programm_data_list array
 * @pram int $anchor_id, $type ,$cpageno
 *
 * @return array
 */
function anchor_programm_data_list($anchor_id, $type, $cpageno) {
    // variable decalartion
    $output_array = array();
    $data = '';
    $data_array = array();
    $updated_datetime = "";

    // list array building
    // latest Programm
    if ($type == '0') {
        $data = anchor_latest_programm_list($anchor_id, $cpageno);
    }
    // popular Programm
    elseif ($type == '1') {
        $data = anchor_popular_programm_list($anchor_id, $cpageno);
    }



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

    $data_array['program_count'] = "$datacount";
    $data_array['program_display_count'] = "10";
    $data_array['program_pagination_cap'] = "10";

    $data_array['program'] = isset($data['data']) ? $data['data'] : array();
    $output_array['data'] = $data_array;

    return $output_array;
}

/**
 * function for generate anchor_latest_programm_list array
 * @pram int $anchor_id,$cpageno
 *
 * @return array
 */
function anchor_latest_programm_list($anchor_id, $cpageno) {

    $range_max = 10;
    $changed_datetime = "";
    $range_min = 0;
    if (!$cpageno == 0) {
        $range_min = $cpageno * $range_max;
    }


    $data = array();

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_video_anchor', 'av', 'av.entity_id = n.nid');
    $query->leftJoin('field_data_field_video_upload', 'vu', 'vu.entity_id = n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id = n.nid');
    $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
    $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
    $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
    $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
    $query->leftJoin('field_data_field_video_upload', 'veo', 'veo.entity_id = n.nid');
    $query->leftJoin('field_data_field_video_duration', 've_du', 've_du.entity_id = n.nid');
    $query->leftJoin('field_data_field_story_reporter', 'fsr', 'fsr.entity_id=n.nid');
    $query->leftJoin('field_data_field_primary_category', 'fpc', 'fpc.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_source_type', 'st', 'st.entity_id = n.nid');

    $query->fields('n', array('nid', 'title', 'type', 'created', 'changed'));
    $query->fields('av', array('field_video_anchor_target_id'));
    $query->fields('si', array('field_story_small_image_fid'));
    $query->fields('li', array('field_story_large_image_fid'));
    $query->fields('eli', array('field_story_extra_large_image_fid'));
    $query->fields('veo', array('field_video_upload_value'));
    $query->fields('ve_du', array('field_video_duration_value'));
    $query->fields('fsr', array('field_story_reporter_target_id'));
    $query->fields('fpc', array('field_primary_category_value'));
    $query->fields('st', array('field_story_source_type_value'));

    $interval = 180;
    $d1 = date('Y-m-d', strtotime("-" . $interval . " days"));
    $d2 = date(strtotime($d1));
    $query->condition('n.created', $d2, '>=');
    $query->condition('n.status', 1);
    $query->condition('n.type', 'videogallery')->orderBy('n.nid', 'DESC')->groupBy('n.nid');
    $query->condition('av.field_video_anchor_target_id', $anchor_id);
    $query->range($range_min, $range_max);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $prog = array();
    $prog2 = array();
    foreach ($result as $k => $res) {

        $comment_cont = 0; //getCommentsCount($res['nid']);
        $changed = $res['changed'];
        $n_view_count = 0; //getNodeViewCount($res['nid']);
        $n_share_count = 0; //getNodeShareCount($res['nid']);
        $file_small_img_url = file_create_url($res['uri']);
        $file_large_img_url = file_create_url($res['li_file_uri']);

        $file_small_img_url = completeFilePath($res['field_story_small_image_fid']);
        $file_large_img_url = completeFilePath($res['field_story_large_image_fid']);
        $file_extra_large_img_url = completeFilePath($res['field_story_extra_large_image_fid']);

        // get byline and credit
        $field_story_reporter_target_id = $res['field_story_reporter_target_id'];
        $reporter_node = itg_common_get_node_title($field_story_reporter_target_id);

        if ($changed) {
            $changed_datetime = date("Y-m-d H:i:s", $changed);
        }


        $field_video_upload = $res['field_video_upload_value'];
        $file_id = file_usage($field_video_upload);
        //to get the video of all the other formats
        $load_collection = field_collection_item_load($field_video_upload);
        $daily_motion_fid = $load_collection->field_videogallery_video_upload['und'][0]['fid'];

        //display all the video sounce check and format
        $source_type = $res['field_story_source_type_value'];
        $videotag = video_detail_formats($res['nid'], $source_type);
        $filesize = $videotag['dailymotion']['filsize'];


        //$load_collection = field_collection_item_load($res['field_video_upload_value']);
        $show_add = $load_collection->field_include_ads['und'][0]['value'];
        if ($show_add == 'yes') {
            $show_add = '1';
        } else {
            $show_add = '0';
        }
        $video_desc = $load_collection->field_videogallery_description['und'][0]['value'];
        $primary_cat = $res['field_primary_category_value'];
        $prim_cat = taxonomy_term_load($primary_cat);

        $prog['p_id'] = $res['nid'];
        $prog['p_title'] = $res['title'];
        $prog['p_credit'] = "$reporter_node";
        $prog['p_byline'] = "$reporter_node";
        $prog['p_short_desc'] = "$video_desc";
        $prog['p_small_image'] = $file_small_img_url;
        $prog['p_large_image'] = $file_large_img_url;
        $prog['p_extralarge_image'] = "$file_extra_large_img_url";

        if (!empty($videotag['dailymotion'])) {
            $videoids = get_video_in_fieldcollection_by_nid($res['nid']);
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
            $prog['p_is_default_player'] = "0";
            $prog['p_url'] = $bitrate_url; //$videotag['dailymotion']['video_id'];
            $prog['p_download_url'] = $file_url_1; //$videotag['dailymotion']['bitate_url']['download_url'];
        } elseif (!empty($videotag['migrated'])) {
            $prog['p_is_default_player'] = "0";
            $prog['p_url'] = $videotag['migrated']['video_path_mp4'];
            $prog['p_download_url'] = $videotag['migrated']['video_path_mp4'];
        }

        $prog['p_view_count'] = "$n_view_count";
        $prog['p_comment_count'] = "$comment_cont";
        $prog['p_share_count'] = "$n_share_count";
        $prog['p_share_url'] = get_node_firebase_weburl($res['nid']);
        $prog['p_updated_datetime'] = "$changed_datetime";
        $dur = explode(':', $res['field_video_duration_value']);
        $duration_sec = $dur[0] * 60 + $dur[1];

        $prog['p_duration'] = "$duration_sec";

        $prog['p_show_ad'] = isset($show_add) ? $show_add : '0';
        $prog['p_subcategory_id'] = isset($prim_cat->tid) ? $prim_cat->tid : '';
        $prog['p_subcategory_title'] = isset($prim_cat->name) ? $prim_cat->name : '';
        $prog['p_program_size'] = isset($filesize) ? "$filesize" : '';
        $prog['p_anchor_id'] = "$anchor_id";

        $prog2[] = $prog;
    }

    $data['data'] = $prog2;
    $data['lcount'] = count($result);
    return $data;
}

function anchor_popular_programm_list($anchor_id, $cpageno) {

    $range_max = 10;
    $changed_datetime = "";
    $range_min = 0;
    if (!$cpageno == 0) {
        $range_min = $cpageno * $range_max;
    }


    $data = array();

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_video_anchor', 'av', 'av.entity_id = n.nid');
    $query->leftJoin('field_data_field_video_upload', 'vu', 'vu.entity_id = n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id = n.nid');
    $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
    $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
    $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
    $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
    $query->leftJoin('field_data_field_video_upload', 'veo', 'veo.entity_id = n.nid');
    $query->leftJoin('field_data_field_video_duration', 've_du', 've_du.entity_id = n.nid');
    $query->leftJoin('field_data_field_story_reporter', 'fsr', 'fsr.entity_id=n.nid');
    $query->leftJoin('field_data_field_primary_category', 'fpc', 'fpc.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_source_type', 'st', 'st.entity_id = n.nid');

    $query->fields('n', array('nid', 'title', 'type', 'created', 'changed'));
    $query->fields('av', array('field_video_anchor_target_id'));
    $query->fields('si', array('field_story_small_image_fid'));
    $query->fields('li', array('field_story_large_image_fid'));
    $query->fields('eli', array('field_story_extra_large_image_fid'));
    $query->fields('veo', array('field_video_upload_value'));
    $query->fields('ve_du', array('field_video_duration_value'));
    $query->fields('fsr', array('field_story_reporter_target_id'));
    $query->fields('fpc', array('field_primary_category_value'));
    $query->fields('st', array('field_story_source_type_value'));

    $interval = 60;
    $d1 = date('Y-m-d', strtotime("-" . $interval . " days"));
    $d2 = date(strtotime($d1));
    $query->condition('n.created', $d2, '>=');
    $query->condition('n.status', 1);
    $query->condition('n.type', 'videogallery')->orderBy('n.nid', 'DESC')->groupBy('n.nid');
    $query->condition('av.field_video_anchor_target_id', $anchor_id);
    $query->range($range_min, $range_max);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $prog = array();
    $prog2 = array();
    foreach ($result as $k => $res) {

        $comment_cont = 0; //getCommentsCount($res['nid']);
        $changed = $res['changed'];
        $n_view_count = 0; //getNodeViewCount($res['nid']);
        $n_share_count = 0; //getNodeShareCount($res['nid']);
        $file_small_img_url = file_create_url($res['uri']);
        $file_large_img_url = file_create_url($res['li_file_uri']);

        $file_small_img_url = completeFilePath($res['field_story_small_image_fid']);
        $file_large_img_url = completeFilePath($res['field_story_large_image_fid']);
        $file_extra_large_img_url = completeFilePath($res['field_story_extra_large_image_fid']);

        // get byline and credit
        $field_story_reporter_target_id = $res['field_story_reporter_target_id'];
        $reporter_node = itg_common_get_node_title($field_story_reporter_target_id);

        if ($changed) {
            $changed_datetime = date("Y-m-d H:i:s", $changed);
        }


        $field_video_upload = $res['field_video_upload_value'];
        $file_id = file_usage($field_video_upload);
        //to get the video of all the other formats
        $load_collection = field_collection_item_load($field_video_upload);
        $daily_motion_fid = $load_collection->field_videogallery_video_upload['und'][0]['fid'];

        //display all the video sounce check and format
        $source_type = $res['field_story_source_type_value'];
        $videotag = video_detail_formats($res['nid'], $source_type);
        $filesize = $videotag['dailymotion']['filsize'];


        //$load_collection = field_collection_item_load($res['field_video_upload_value']);
        $show_add = $load_collection->field_include_ads['und'][0]['value'];
        if ($show_add == 'yes') {
            $show_add = '1';
        } else {
            $show_add = '0';
        }
        $video_desc = $load_collection->field_videogallery_description['und'][0]['value'];
        $primary_cat = $res['field_primary_category_value'];
        $prim_cat = taxonomy_term_load($primary_cat);

        $prog['p_id'] = $res['nid'];
        $prog['p_title'] = $res['title'];
        $prog['p_credit'] = "$reporter_node";
        $prog['p_byline'] = "$reporter_node";
        $prog['p_short_desc'] = "$video_desc";
        $prog['p_small_image'] = $file_small_img_url;
        $prog['p_large_image'] = $file_large_img_url;
        $prog['p_extralarge_image'] = "$file_extra_large_img_url";

        if (!empty($videotag['dailymotion'])) {
            $videoids = get_video_in_fieldcollection_by_nid($res['nid']);
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
            $prog['p_is_default_player'] = "0";
            $prog['p_url'] = $bitrate_url; //$videotag['dailymotion']['video_id'];
            $prog['p_download_url'] = $file_url_1; //$videotag['dailymotion']['bitate_url']['download_url'];
        } elseif (!empty($videotag['migrated'])) {
            $prog['p_is_default_player'] = "0";
            $prog['p_url'] = $videotag['migrated']['video_path_mp4'];
            $prog['p_download_url'] = $videotag['migrated']['video_path_mp4'];
        }

        $prog['p_view_count'] = "$n_view_count";
        $prog['p_comment_count'] = "$comment_cont";
        $prog['p_share_count'] = "$n_share_count";
        $prog['p_share_url'] = get_node_firebase_weburl($res['nid']);
        $prog['p_updated_datetime'] = "$changed_datetime";
        $dur = explode(':', $res['field_video_duration_value']);
        $duration_sec = $dur[0] * 60 + $dur[1];

        $prog['p_duration'] = "$duration_sec";

        $prog['p_show_ad'] = isset($show_add) ? $show_add : '0';
        $prog['p_subcategory_id'] = isset($prim_cat->tid) ? $prim_cat->tid : '';
        $prog['p_subcategory_title'] = isset($prim_cat->name) ? $prim_cat->name : '';
        $prog['p_program_size'] = isset($filesize) ? "$filesize" : '';
        $prog['p_anchor_id'] = "$anchor_id";

        $prog2[] = $prog;
    }

    $data['data'] = $prog2;
    $data['lcount'] = count($result);
    return $data;
}

/**
 * function for generate anchor_popular_programm_list array
 * @pram int $anchor_id,$cpageno
 *
 * @return array
 */
/* function anchor_popular_programm_list($anchor_id, $cpageno) {
  $range_max = 10;
  $range_min = 0;
  $changed_datetime = "";
  if (!$cpageno == 0) {
  $range_min = $cpageno * $range_max;
  }


  $data = array();
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_video_anchor', 'av', 'av.entity_id = n.nid');
  $query->fields('n', array('nid'));
  $query->condition('n.status', 1);
  $query->condition('n.type', 'videogallery');
  $query->condition('av.field_video_anchor_target_id', '%' . db_like($anchor_id) . '%', 'LIKE');
  $query->range($range_min, $range_max);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  $popular_res = array();
  foreach ($result as $k => $res) {
  $popular_res[$res['nid']] = analytics_node_data($res['nid'], 'total');
  }
  //Sort Desc by total analytics count
  arsort($popular_res);
  $prog = array();
  $prog2 = array();

  foreach ($popular_res as $pop_res_k => $pop_res_v) {
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id = n.nid');
  $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
  $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
  $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
  $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
  $query->leftJoin('field_data_field_video_duration', 've_du', 've_du.entity_id = n.nid');
  $query->leftJoin('field_data_field_story_reporter', 'fsr', 'fsr.entity_id=n.nid');
  $query->leftJoin('field_data_field_primary_category', 'fpc', 'fpc.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_source_type', 'st', 'st.entity_id = n.nid');

  $query->fields('n', array('nid', 'title', 'type', 'created', 'changed'));
  $query->fields('st', array('field_story_source_type_value'));
  $query->fields('si', array('field_story_small_image_fid'));
  $query->fields('li', array('field_story_large_image_fid'));
  $query->fields('eli', array('field_story_extra_large_image_fid'));
  $query->fields('ve_du', array('field_video_duration_value'));
  $query->fields('fsr', array('field_story_reporter_target_id'));
  $query->fields('fpc', array('field_primary_category_value'));


  $query->condition('n.nid', $pop_res_k);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  foreach ($result as $k => $res) {
  $comment_cont = getCommentsCount($res['nid']);
  $changed = $res['changed'];
  $n_view_count = getNodeViewCount($res['nid']);
  $n_share_count = getNodeShareCount($res['nid']);
  $file_small_img_url = file_create_url($res['uri']);
  $file_large_img_url = file_create_url($res['li_file_uri']);

  $file_small_img_url = completeFilePath($res['field_story_small_image_fid']);
  $file_large_img_url = completeFilePath($res['field_story_large_image_fid']);
  $file_extra_large_img_url = completeFilePath($res['field_story_extra_large_image_fid']);

  // get byline and credit
  $field_story_reporter_target_id = $res['field_story_reporter_target_id'];
  $reporter_node = itg_common_get_node_title($field_story_reporter_target_id);

  if ($changed) {
  $changed_datetime = date("Y-m-d H:i:s", $changed);
  }


  $field_video_upload = $res['field_video_upload_value'];
  $file_id = file_usage($field_video_upload);
  //to get the video of all the other formats
  $load_collection = field_collection_item_load($field_video_upload);
  $daily_motion_fid = $load_collection->field_videogallery_video_upload['und'][0]['fid'];

  //display all the video sounce check and format
  $source_type = $res['field_story_source_type_value'];
  $videotag = video_detail_formats($res['nid'], $source_type);
  $filesize = $videotag['dailymotion']['filsize'];

  $load_collection = field_collection_item_load($res['field_video_upload_value']);
  $show_add = $load_collection->field_include_ads['und'][0]['value'];
  if ($show_add == 'yes') {
  $show_add = '1';
  }
  else {
  $show_add = '0';
  }
  $video_desc = $load_collection->field_videogallery_description['und'][0]['value'];
  $primary_cat = $res['field_primary_category_value'];
  $prim_cat = taxonomy_term_load($primary_cat);

  $prog['p_id'] = $res['nid'];
  $prog['p_title'] = $res['title'];
  $prog['p_credit'] = "$reporter_node";
  $prog['p_byline'] = "$reporter_node";
  $prog['p_short_desc'] = "$video_desc";
  $prog['p_small_image'] = $file_small_img_url;
  $prog['p_large_image'] = $file_large_img_url;
  $prog['p_extralarge_image'] = "$file_extra_large_img_url";

  if (!empty($videotag['dailymotion'])) {
  $videoids = get_video_in_fieldcollection_by_nid($res['nid']);
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

  $prog['p_is_default_player'] = "0";
  $prog['p_url'] = $bitrate_url; //$videotag['dailymotion']['video_id'];
  $prog['p_download_url'] = $file_url_1;
  }
  elseif (!empty($videotag['migrated'])) {
  $prog['p_is_default_player'] = "0";
  $prog['p_url'] = $videotag['migrated']['video_path_mp4'];
  $prog['p_download_url'] = $videotag['migrated']['video_path_mp4'];
  }

  $prog['p_view_count'] = "$n_view_count";
  $prog['p_comment_count'] = "$comment_cont";
  $prog['p_share_count'] = "$n_share_count";
  $prog['p_share_url'] = get_node_firebase_weburl($res['nid']);
  $prog['p_updated_datetime'] = "$changed_datetime";

  $dur = explode(':', $res['field_video_duration_value']);
  $duration_sec = $dur[0] * 60 + $dur[1];
  $prog['p_duration'] = "$duration_sec";

  $prog['p_duration'] = $res['field_video_duration_value'];
  $prog['p_show_ad'] = isset($show_add) ? $show_add : '0';
  $prog['p_subcategory_id'] = isset($prim_cat->tid) ? $prim_cat->tid : '';
  $prog['p_subcategory_title'] = isset($prim_cat->name) ? $prim_cat->name : '';
  $prog['p_program_size'] = isset($filesize) ? "$filesize" : "";
  $prog['p_anchor_id'] = "$anchor_id";

  $prog2[] = $prog;
  }
  }

  $data['data'] = $prog2;
  $data['lcount'] = count($prog2);
  return $data;
  }
 */

/**
 * function for generate follow_author_data_responce array
 * @pram int $user_id, $author_id, $type
 *
 * @return array
 */
function follow_author_data_responce($user_id, $author_id, $type) {
    // variable decalartion

    $data = array();
    $output_array = array();
    $data_array = array();
    $updated_datetime = "";
    $ntype = 'author';
    $activity = 'follow_story';
    if ($type == 'follow_story') {
        $dstatus = '1';
    } elseif ($type == 'Unfollow') {
        $dstatus = '0';
    }

    $activity_date = date('d-m-Y');
    $activity_date_time = date('d-m-Y h:i:s');


    if (function_exists('mongodb')) {
        $con = mongodb();
        if ($con) {
            $people = $con->front_user_activity;
            $get_previous_info = itg_get_front_activity_info($author_id, $ntype, $user_id, $activity, '');
            if (empty($get_previous_info['nid'])) {
                if ($dtag == 'tag') {
                    $term = taxonomy_term_load($author_id);
                    $actual_title = $term->name;
                    $primary_cat_id = '';
                    $primary_cat_name = '';
                    $extra_image = NULL;
                    $path = '';
                } else {
                    $actual_data = node_load($author_id);
                    $actual_title = $actual_data->title;
                    $primary_cat_id = $actual_data->field_primary_category[LANGUAGE_NONE][0]['value'];
                    $primary_cat_name = taxonomy_term_load($actual_data->field_primary_category[LANGUAGE_NONE][0]['value']);
                    $extra_image = $actual_data->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                    $path = $actual_data->path['source'];
                }

                $qry = array("nid" => $author_id, "uid" => $user_id, "title" => $actual_title, "path" => $path, "image" => $extra_image, "primary_category_id" => $primary_cat_id, "primary_category_name" => $primary_cat_name->name, "ntype" => $ntype, "activity" => $activity, "activity_date" => $activity_date, "activity_date_time" => $activity_date_time, "status" => $dstatus, "timestamp" => time());
                $result = $people->insert($qry);
                $response = array('success' => $dstatus, 'activity' => $user_activity, 'type' => $ntype);
            } else {
                $newdata = array('$set' => array("status" => $dstatus, "activity_date" => $activity_date, "activity_date_time" => $activity_date_time, "timestamp" => time()));
                $people->update(array("nid" => $author_id, "activity" => $activity, "uid" => $user_id), $newdata);
                $response = array("success" => $dstatus, 'activity' => $activity, 'type' => $ntype);
            }
        }
    }

    if (!empty($response)) {
        $data['id'] = $author_id;
        //$response['success'];
        $data['is_saved'] = 1;
        $data['limit_crossed'] = '0';
    }

    if (!empty($response)) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
        $output_array['data'] = $data;
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
        $output_array['data'] = $data;
    }
    return $output_array;
}

/**
 * function for generate follow_anchor_data_responce array
 * @pram int $user_id, $author_id, $type
 *
 * @return array
 */
function follow_anchor_data_responce($user_id, $author_id, $type) {
    // variable decalartion
    $data = array();
    $output_array = array();
    $data_array = array();
    $updated_datetime = "";
    $ntype = 'anchor';
    $activity = "follow_anchor";
    if ($type == 'follow_story') {
        $dstatus = '1';
    } elseif ($type == 'Unfollow') {
        $dstatus = '0';
    }

    $activity_date = date('d-m-Y');
    $activity_date_time = date('d-m-Y h:i:s');


    if (function_exists('mongodb')) {
        $con = mongodb();
        if ($con) {
            $people = $con->front_user_activity;
            $get_previous_info = itg_get_front_activity_info($author_id, $ntype, $user_id, $activity, '');
            if (empty($get_previous_info['nid'])) {
                if ($dtag == 'tag') {
                    $term = taxonomy_term_load($author_id);
                    $actual_title = $term->name;
                    $primary_cat_id = '';
                    $primary_cat_name = '';
                    $extra_image = NULL;
                    $path = '';
                } else {
                    $actual_data = node_load($author_id);
                    $actual_title = $actual_data->title;
                    $primary_cat_id = $actual_data->field_primary_category[LANGUAGE_NONE][0]['value'];
                    $primary_cat_name = taxonomy_term_load($actual_data->field_primary_category[LANGUAGE_NONE][0]['value']);
                    $extra_image = $actual_data->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                    $path = $actual_data->path['source'];
                }

                $qry = array("nid" => $author_id, "uid" => $user_id, "title" => $actual_title, "path" => $path, "image" => $extra_image, "primary_category_id" => $primary_cat_id, "primary_category_name" => $primary_cat_name->name, "ntype" => $ntype, "activity" => $activity, "activity_date" => $activity_date, "activity_date_time" => $activity_date_time, "status" => $dstatus, "timestamp" => time());
                $result = $people->insert($qry);
                $response = array('success' => $dstatus, 'activity' => $user_activity, 'type' => $ntype);
            } else {
                $newdata = array('$set' => array("status" => $dstatus, "activity_date" => $activity_date, "activity_date_time" => $activity_date_time, "timestamp" => time()));
                $people->update(array("nid" => $author_id, "activity" => $activity, "uid" => $user_id), $newdata);
                $response = array("success" => $dstatus, 'activity' => $activity, 'type' => $ntype);
            }
        }
    }

    if (!empty($response)) {
        $data['id'] = $author_id;
        //$response['success'];
        $data['is_saved'] = 1;
        $data['limit_crossed'] = '0';
    }

    if (!empty($response)) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
        $output_array['data'] = $data;
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
        $output_array['data'] = $data;
    }
    return $output_array;
}
