<?php

/**
 * Inc file contains the functions for homePgae API 
 */

/**
 * main function for generate homePageJson array
 *
 * @return array
 */


/**
 * Get Package category listing from the middleware
 * @return type
 */
function homepage_topstories() {
    $top_story_list = array();
    $top_story_data = fetchMasterConfigData('top_stories_management');
    $top_story_limit = isset($top_story_data) ? $top_story_data : '10';

    $top_story_list = homePageJsonTopstories($top_story_limit);
    return $top_story_list;
}

/**
 * Get Package category listing from the middleware
 * @return type
 */
function home_page_newslist_cat() {
    $query = db_select('itg_app_middleware', 'am');
    $query->innerJoin('itg_app_master_info_internal', 'mci', 'mci.org_id=am.ids');
    $query->fields('am', array('ids'));
    $query->condition('am.identifier', 'categories_options');
    $query->condition('am.ids', '0', '!=');
    $query->condition('mci.info_type', 'categories', '=');
    $query->condition('mci.info_key', 'order', '=');
    $query->orderBy('mci.info_value', 'ASC');
    $query->groupBy('am.ids');
    $query_results = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $cat_news_list = array();
    foreach ($query_results as $tid) {
        $cat_news_list[] = homePageCatNewslist($tid['ids']);
    }

    return $cat_news_list;
    
}

/**
 * Get Magazine node listing from the middleware
 * @return type
 */
function home_page_magazine_node_list() {
    $mag_news_list = array();

    $query = db_select('itg_app_middleware', 'am');
    $query->leftJoin('itg_app_master_info_internal', 'mii', 'mii.org_id=am.ids');
    $query->fields('am', array('ids'));
    $query->condition('am.identifier', 'magazine_options');
    $query->condition('am.ids', '0', '!=');
    $query->condition('mii.info_type', 'magazine', '=');
    $query->orderBy('mii.info_value', 'ASC');
    $result_query = $query->execute()->fetchAll(PDO::FETCH_ASSOC);


    foreach ($result_query as $result_data) {

        $mag_news_list[] = $result_data['ids'];
    }

    return $mag_news_list;
}

/**
 * Get Magazine node listing from the middleware
 * @return type
 */
function home_page_polls_node_list() {
    $polls_node_list = array();

    $query = db_select('itg_app_middleware', 'am');
    $query->fields('am', array('ids'));
    $query->condition('am.identifier', 'poll_options');
    $query->condition('am.ids', '0', '!=');
    $result_query = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    foreach ($result_query as $result_data) {
        $polls_node_list[] = $result_data['ids'];
    }
    return $polls_node_list;
}

/**
 * Get Package category listing from the middleware
 * @return type
 */
function home_page_packages_bk() {
    $query = db_select('itg_app_middleware', 'am');
    $query->leftJoin('itg_app_master_info_internal', 'mci', 'mci.org_id=am.ids');
    $query->fields('am', array('ids'));
    $query->condition('am.identifier', 'itg_package');
    $query->condition('am.ids', '0', '!=');
    $query->condition('mci.info_type', 'packages', '=');
    $query->orderBy('mci.info_value', 'ASC');
    $query_results = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $list_arr = array();
    foreach ($query_results as $tid) {
        $list_tid[] = $tid['ids'];
    }
    //$list_tid_str = implode(",",$list_tid);
    $list_arr = homePageJsonPackagelist($list_tid);
    return $list_arr;
}

function home_page_packages() {
    $query = db_select('itg_app_middleware', 'am');
    $query->leftJoin('itg_app_master_info_internal', 'mci', 'mci.org_id=am.ids');
    $query->fields('am', array('ids'));
    $query->condition('am.identifier', 'itg_package');
    $query->condition('am.ids', '0', '!=');
    $query->condition('mci.info_type', 'packages', '=');
    $query->orderBy('mci.info_value', 'ASC');
    $query_results = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $list_arr = array();
    foreach ($query_results as $tid) {

        $list_arr[] = homePageJsonPackagelist($tid['ids']);
    }

    return $list_arr;
}

/**
 * main function for generate homePageJsonPackagelist_india array
 * @param int $tid term id
 * @return array
 */
function homePageJsonPackagelist($tid) { 

    global $base_url, $order;
    $data_news = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    $tid = $tid;
    $term_m = taxonomy_term_load($tid);
    $term_name_m = $term_m->name;
    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $tid_list[] = $tid;
    $listcount = 0;
    $range_max = 3;
    $range_min = 0;
    if (!$pageno == 0) {
        $range_min = $pageno * $lcont;
    }

    $order_by = 'ASC';
    $type = array("videogallery", "photogallery", "story");
    $news_list_array = array();
    $photolist = array();
    $videolist = array();
    $loop_count = 0; {
        $listcount = 0;
        // code vid=14  start
        if ($tid > 0) {
            $term_tree = taxonomy_get_tree(CATEGORY_MANAGMENT, $tid, $max_depth = NULL, $load_entities = FALSE);
        } else {
            $term_tree = taxonomy_get_tree(CATEGORY_MANAGMENT, 0, $max_depth = NULL, $load_entities = FALSE);
        }
        $term_tree_count = count($term_tree);
        if ($term_tree_count) {
            foreach ($term_tree as $key => $value) {
                $tid_list[] = $value->tid;
            }
        }

        // code vid=14  end

        $data_news['id'] = "$tid";
        $data_news['order'] = "$order";
        $data_news['type'] = "packagelist";
        $data_news['title'] = "$term_name_m";
        $data_news['label'] = "$term_name_m";
        $data_news['show_label'] = "0";
        $data_news['n_template_id'] = "2";

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

        $query->leftJoin('field_data_field_common_related_content', 'rc', 'rc.entity_id=n.nid');
         // for breaking_news
        $query->leftJoin('field_data_field_multi_user_allows', 'fmu', 'fmu.entity_id=n.nid'); // new or old blog
        $query->leftJoin('field_data_field_common_short_description', 'fcsd', 'fcsd.entity_id=n.nid'); // blog short desc
        $query->leftJoin('field_data_field_type', 'fdt', 'fdt.entity_id=n.nid'); // live blog type
        $query->leftJoin('field_data_field_story_expires', 'fse', 'fse.entity_id=n.nid'); // live tv checkbox
        $query->leftJoin('field_data_field_constituancy', 'fdc', 'fdc.entity_id=n.nid'); // sub_title
        // for emoji
        $query->leftJoin('field_data_field_emoji_2', 'emj2', 'emj2.entity_id=n.nid'); //emoji right
        $query->leftJoin('field_data_field_emoji', 'emj', 'emj.entity_id=n.nid'); //emoji left

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
        // for breaking_news
        $query->fields('fmu', array('field_multi_user_allows_value'));
        $query->fields('fcsd', array('field_common_short_description_value'));
        $query->fields('fdt', array('field_type_value'));
        $query->fields('fse', array('field_story_expires_value'));
        $query->fields('fdc', array('field_constituancy_value'));
        // for emoji
        $query->fields('emj2', array('field_emoji_2_value'));
        $query->fields('emj', array('field_emoji_value'));


        //end

        $query->condition('ti.tid', $tid, '=');
        $interval = itg_app_time_interval($tid);        
        $d1 = date('Y-m-d', strtotime("-" . $interval . " days"));
        $d2 = date(strtotime($d1));
        $query->condition('n.created', $d2, '>=');
        $query->condition('n.status', 1)->condition('n.type', $type, 'IN')->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);

        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

        foreach ($result as $reskey => $resvalue) {

            $title = $resvalue['title'];
            $type = $resvalue['type'];
            $nid = $resvalue['nid'];
            $created = $resvalue['created'];
            $changed = $resvalue['changed'];
            $field_story_kicker_text_value = $resvalue['field_story_kicker_text_value'];
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
            // Get Publish time:
            $pub_date = get_content_publish_date($nid);
            if (!empty($pub_date)) {
                $pub_date = date('Y-m-d H:i:s', strtotime($pub_date[0]['field_itg_content_publish_date_value']));
            } else {
                $pub_date = "";
            }
            // custom function for get img caption
            $caption = getImgCaption($resvalue['field_story_medium_image_fid']);
            // custom function for get img byline
            $byline = getImgByline($resvalue['field_story_medium_image_fid']);
            $is_developing = 0;
            $conf = getStoryConfigVal($nid);
            if (in_multiarray("developing_story", $conf, "field_story_configurations_value")) {
                $is_developing = 1;
            }
            if ($type == 'story') {
                $type = getStoryType($nid);
            }
            $prime_cat = getNodePrimeCatByNid($nid);
            $data_newslist[$listcount]['n_id'] = "$nid";
            $data_newslist[$listcount]['n_type'] = "$type";
            $data_newslist[$listcount]['n_is_developing'] = "$is_developing";
            $data_newslist[$listcount]['n_is_sponsored'] = "0";
            $data_newslist[$listcount]['n_share_link'] = "$firebase_url";
            $data_newslist[$listcount]['n_title'] = "$title";
            $data_newslist[$listcount]['n_description'] = "$field_story_kicker_text_value";
            $data_newslist[$listcount]['n_pcategory_id'] = "$prime_cat->tid";
            $data_newslist[$listcount]['n_pcategory_name'] = "$prime_cat->name";
            $data_newslist[$listcount]['n_comment_count'] = "$comment_cont";
            $data_newslist[$listcount]['n_small_image'] = "$file_small_img_url";
            $data_newslist[$listcount]['n_large_image'] = "$file_large_img_url";
            $data_newslist[$listcount]['n_image_credit'] = "$byline";
            $data_newslist[$listcount]['n_updated_datetime'] = "$pub_date";
            $heighligth = array();
            $heighligth = (array) getHighlightByNid($nid);
            $data_newslist[$listcount]['n_highlight'] = $heighligth;
            // photo list array
            if ($type == "photogallery") {
                $photolist = getPhotolist($nid);
            } elseif ($type == "photostory") {
                $photo_list_array = generatePhotoStoryDetailList($nid);
                $photolist = $photo_list_array['data'];
            }
            $data_newslist[$listcount]['n_photo'] = (array) $photolist;
            // re-insalize photolist
            $photolist = array();

            // video list array

            if ($type == "videogallery") {
                $videolist = getVideolist($nid);
            }
            $data_newslist[$listcount]['n_video'] = (array) $videolist;
            // re-insalize vediolist
            $videolist = array();

            // homepage.inc
            $n_polls = getPolllist($node);
            // story.inc
            $n_rating = getRating($node);
            // homepage.inc
            $n_magazine = array();

            $data_newslist[$listcount]['n_polls'] = $n_polls;
            $data_newslist[$listcount]['n_rating'] = $n_rating;
            $data_newslist[$listcount]['n_magazine'] = $n_magazine;
            $n_widget = array();
            $data_newslist[$listcount]['n_widget'] = $n_widget;
            // for breaking_news
            $n_blog = array();
            $created = $resvalue['created'];
            $blog_type = $resvalue['field_type_value'];
            $new_blog = 0;
            if ($resvalue['field_multi_user_allows_value']) {
                $new_blog = 1;
            }
            elseif($resvalue['field_type_value'] == "Cricket Live Blog"){
               $new_blog = 2; 
            }
            $live_tv = 0;
            if ($resvalue['field_story_expires_value'] == 'Yes') {
                $live_tv = 1;
            }
            $short_desc = $resvalue['field_common_short_description_value'];
            $sub_title = $resvalue['field_constituancy_value'];
            $page_title = $node_data->title;
            $field_type_value = $resvalue['field_type_value'];
            //p($resvalue);
            
            if($type == "breaking_news"){
                $n_blog['blog_type'] = "$blog_type";
                $n_blog['id'] = "$nid";
                $n_blog['sub_title'] = "$sub_title";
                $n_blog['short_desc'] = "$short_desc";
                $n_blog['new_blog'] = "$new_blog";
                $n_blog['live_tv'] = "$live_tv";
                $n_blog = (object) $n_blog;
                $data_newslist[$listcount]['n_blog'] =  $n_blog;
            }
            else{
                $n_blog = array();    
                $n_blog['empty'] = "";
                $n_blog = (object) $n_blog;  
                $data_newslist[$listcount]['n_blog'] = $n_blog;
            }
            // for emoji
            $n_emoji_left = array();
            $n_emoji_right = array();
            $emoji_left = $resvalue['field_emoji_value'];
            $emoji_right = $resvalue['field_emoji_2_value'];
            if ($emoji_left) {
                $n_emoji_left = itg_rapid_get_emoji($emoji_left);
            }
            if ($emoji_right) {
                $n_emoji_right = itg_rapid_get_emoji($emoji_right);
            }
            $data_newslist[$listcount]['n_emoji_left'] = $n_emoji_left;
            $data_newslist[$listcount]['n_emoji_right'] = $n_emoji_right;


            $listcount++;
        }
    }

    $data_news['news'] = (array) $data_newslist;
    $order++;
    return $data_news;
}

function homePageJsonPackagelist_bk($tid) {

    global $base_url, $order;
    $data_news = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    $tid = $tid;
    //$term_m = taxonomy_term_load($tid);
    //$term_name_m = $term_m->name;
    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    //$tid_list[] = $tid;
    $listcount = 0;
    $range_max = 5;
    $range_min = 0;
    if (!$pageno == 0) {
        $range_min = $pageno * $lcont;
    }

    $order_by = 'ASC';
    $type = array("videogallery", "photogallery", "story");
    $news_list_array = array();
    $photolist = array();
    $videolist = array();
    $loop_count = 0; {
        $listcount = 0;


        $data_news['id'] = "1206552"; // india now calling
        $data_news['order'] = "$order";
        $data_news['type'] = "packagelist";
        $data_news['title'] = "packages";
        $data_news['label'] = "packages";
        $data_news['show_label'] = "0";
        $data_news['n_template_id'] = "2";

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

        $query->condition('ti.tid', $tid, 'IN');
        $interval = itg_app_time_interval($tid);        
        $d1 = date('Y-m-d', strtotime("-" . $interval . " days"));
        $d2 = date(strtotime($d1));
        $query->condition('n.created', $d2, '>=');
        $query->condition('n.status', 1)->condition('n.type', $type, 'IN')->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);

        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

        foreach ($result as $reskey => $resvalue) {

            $title = $resvalue['title'];
            $type = $resvalue['type'];
            $nid = $resvalue['nid'];
            $created = $resvalue['created'];
            $changed = $resvalue['changed'];
            $field_story_kicker_text_value = $resvalue['field_story_kicker_text_value'];
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
            // Get Publish time:
            $pub_date = get_content_publish_date($nid);
            if (!empty($pub_date)) {
                $pub_date = date('Y-m-d H:i:s', strtotime($pub_date[0]['field_itg_content_publish_date_value']));
            } else {
                $pub_date = "";
            }
            // custom function for get img caption
            $caption = getImgCaption($resvalue['field_story_medium_image_fid']);
            // custom function for get img byline
            $byline = getImgByline($resvalue['field_story_medium_image_fid']);
            $is_developing = 0;
            $conf = getStoryConfigVal($nid);
            if (in_multiarray("developing_story", $conf, "field_story_configurations_value")) {
                $is_developing = 1;
            }
            if ($type == 'story') {
                $type = getStoryType($nid);
            }
            $prime_cat = getNodePrimeCatByNid($nid);
            $data_newslist[$listcount]['n_id'] = "$nid";
            $data_newslist[$listcount]['n_type'] = "$type";
            $data_newslist[$listcount]['n_is_developing'] = "$is_developing";
            $data_newslist[$listcount]['n_is_sponsored'] = "0";
            $data_newslist[$listcount]['n_share_link'] = "$firebase_url";
            $data_newslist[$listcount]['n_title'] = "$title";
            $data_newslist[$listcount]['n_description'] = "$field_story_kicker_text_value";
            $data_newslist[$listcount]['n_pcategory_id'] = "$prime_cat->tid";
            $data_newslist[$listcount]['n_pcategory_name'] = "$prime_cat->name";
            $data_newslist[$listcount]['n_comment_count'] = "$comment_cont";
            $data_newslist[$listcount]['n_small_image'] = "$file_small_img_url";
            $data_newslist[$listcount]['n_large_image'] = "$file_large_img_url";
            $data_newslist[$listcount]['n_image_credit'] = "$byline";
            $data_newslist[$listcount]['n_updated_datetime'] = "$pub_date";
            $heighligth = array();
            $heighligth = (array) getHighlightByNid($nid);
            $data_newslist[$listcount]['n_highlight'] = $heighligth;
            // photo list array
            if ($type == "photogallery") {
                $photolist = getPhotolist($nid);
            } elseif ($type == "photostory") {
                $photo_list_array = generatePhotoStoryDetailList($nid);
                $photolist = $photo_list_array['data'];
            }
            $data_newslist[$listcount]['n_photo'] = (array) $photolist;
            // re-insalize photolist
            $photolist = array();

            // video list array

            if ($type == "videogallery") {
                $videolist = getVideolist($nid);
            }
            $data_newslist[$listcount]['n_video'] = (array) $videolist;
            // re-insalize vediolist
            $videolist = array();

            // homepage.inc
            $n_polls = getPolllist($node);
            // story.inc
            $n_rating = getRating($node);
            // homepage.inc
            $n_magazine = array();

            $data_newslist[$listcount]['n_polls'] = $n_polls;
            $data_newslist[$listcount]['n_rating'] = $n_rating;
            $data_newslist[$listcount]['n_magazine'] = $n_magazine;
            $n_widget = array();
            $data_newslist[$listcount]['n_widget'] = $n_widget;

            $listcount++;
        }
    }

    $data_news['news'] = (array) $data_newslist;
    $order++;
    return $data_news;
}



/**
 * main function for generate homePageJsonNewslist_india array
 *
 * @return array
 */
function homePageCatNewslist($tid) {
    global $base_url, $order;
    $lcont = fetchitg_app_master_info_internaldata($tid, 'lcont');
    $template = fetchitg_app_master_info_internaldata($tid, 'template');
    if ($template == "Template1") {
        $template_val = 1;
    } elseif ($template == "Template2") {
        $template_val = 2;
    } elseif ($template == "Template3") {
        $template_val = 3;
    }
    //fetch config data
    global $base_url;
    $data_news = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    $tid = $tid;
    $term_m = taxonomy_term_load($tid);
    $term_name_m = $term_m->name;
    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $tid_list[] = $tid;
    $listcount = 0;
    $range_max = $lcont;
    $range_min = 0;
    if (!$pageno == 0) {
        $range_min = $pageno * $lcont;
    }

    $order_by = 'ASC';
    $type = array("videogallery", "photogallery", "story", "breaking_news");
    $news_list_array = array();
    $photolist = array();
    $videolist = array();
    $loop_count = 0; {
        $listcount = 0;
        

        // code vid=14  end

        $data_news['id'] = "$tid";
        $data_news['order'] = "$order";
        $data_news['type'] = "newslist";
        $data_news['title'] = "$term_name_m";
        $data_news['label'] = "$term_name_m";
        $data_news['show_label'] = "0";
        $data_news['n_template_id'] = "$template_val";

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

        $query->leftJoin('field_data_field_common_related_content', 'rc', 'rc.entity_id=n.nid');
         // for breaking_news
        $query->leftJoin('field_data_field_multi_user_allows', 'fmu', 'fmu.entity_id=n.nid'); // new or old blog
        $query->leftJoin('field_data_field_common_short_description', 'fcsd', 'fcsd.entity_id=n.nid'); // blog short desc
        $query->leftJoin('field_data_field_type', 'fdt', 'fdt.entity_id=n.nid'); // live blog type
        $query->leftJoin('field_data_field_story_expires', 'fse', 'fse.entity_id=n.nid'); // live tv checkbox
        $query->leftJoin('field_data_field_constituancy', 'fdc', 'fdc.entity_id=n.nid'); // sub_title
        // for emoji
        $query->leftJoin('field_data_field_emoji_2', 'emj2', 'emj2.entity_id=n.nid'); //emoji right
        $query->leftJoin('field_data_field_emoji', 'emj', 'emj.entity_id=n.nid'); //emoji left

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
        // for breaking_news
        $query->fields('fmu', array('field_multi_user_allows_value'));
        $query->fields('fcsd', array('field_common_short_description_value'));
        $query->fields('fdt', array('field_type_value'));
        $query->fields('fse', array('field_story_expires_value'));
        $query->fields('fdc', array('field_constituancy_value'));
        // for emoji
        $query->fields('emj2', array('field_emoji_2_value'));
        $query->fields('emj', array('field_emoji_value'));
        

        //end

        $query->condition('ti.tid', $tid, '=');
        $interval = itg_app_time_interval($tid);        
        $d1 = date('Y-m-d', strtotime("-" . $interval . " days"));
        $d2 = date(strtotime($d1));
        $query->condition('n.created', $d2, '>=');
        $query->condition('n.status', 1)->condition('n.type', $type, 'IN')->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);

        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

        foreach ($result as $reskey => $resvalue) {
            // filter breaking news blog..
            if($resvalue['field_type_value'] == "Breaking News" || $resvalue['field_type_value'] == "Cricket Live Blog"){
                continue;
            }
            $title = $resvalue['title'];
            $type = $resvalue['type'];
            $nid = $resvalue['nid'];
            $created = $resvalue['created'];
            $changed = $resvalue['changed'];
            $field_story_kicker_text_value = $resvalue['field_story_kicker_text_value'];
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
            // Get Publish time:
            $pub_date = get_content_publish_date($nid);
            if (!empty($pub_date)) {
                $pub_date = date('Y-m-d H:i:s', strtotime($pub_date[0]['field_itg_content_publish_date_value']));
            } else {
                $pub_date = "";
            }
            // custom function for get img caption
            $caption = getImgCaption($resvalue['field_story_medium_image_fid']);
            // custom function for get img byline
            $byline = getImgByline($resvalue['field_story_medium_image_fid']);
            $is_developing = 0;
            $conf = getStoryConfigVal($nid);
            if (in_multiarray("developing_story", $conf, "field_story_configurations_value")) {
                $is_developing = 1;
            }
            if ($type == 'story') {
                $type = getStoryType($nid);
            }
            $prime_cat = getNodePrimeCatByNid($nid);
            $data_newslist[$listcount]['n_id'] = "$nid";
            if($type == "breaking_news"){
                $data_newslist[$listcount]['n_type'] = "story"; 
                $data_newslist[$listcount]['n_is_blog'] = "1"; 
            }
            else{
              $data_newslist[$listcount]['n_type'] = "$type"; 
              $data_newslist[$listcount]['n_is_blog'] = "0"; 
            }
            $data_newslist[$listcount]['n_is_developing'] = "$is_developing";
            $data_newslist[$listcount]['n_is_sponsored'] = "0";
            $data_newslist[$listcount]['n_share_link'] = "$firebase_url";
            $data_newslist[$listcount]['n_title'] = "$title";
            $data_newslist[$listcount]['n_description'] = "$field_story_kicker_text_value";
            $data_newslist[$listcount]['n_pcategory_id'] = "$prime_cat->tid";
            $data_newslist[$listcount]['n_pcategory_name'] = "$prime_cat->name";
            $data_newslist[$listcount]['n_comment_count'] = "$comment_cont";
            $data_newslist[$listcount]['n_small_image'] = "$file_small_img_url";
            $data_newslist[$listcount]['n_large_image'] = "$file_large_img_url";
            $data_newslist[$listcount]['n_image_credit'] = "$byline";
            $data_newslist[$listcount]['n_updated_datetime'] = "$pub_date";
            $heighligth = array();
            $heighligth = (array) getHighlightByNid($nid);
            $data_newslist[$listcount]['n_highlight'] = $heighligth;
            // photo list array
            if ($type == "photogallery") {
                $photolist = getPhotolist($nid);
            } elseif ($type == "photostory") {
                $photo_list_array = generatePhotoStoryDetailList($nid);
                $photolist = $photo_list_array['data'];
            }
            $data_newslist[$listcount]['n_photo'] = (array) $photolist;
            // re-insalize photolist
            $photolist = array();

            // video list array

            if ($type == "videogallery") {
                $videolist = getVideolist($nid);
            }
            $data_newslist[$listcount]['n_video'] = (array) $videolist;
            // re-insalize vediolist
            $videolist = array();

            // homepage.inc
            $n_polls = getPolllist($node);
            // story.inc
            $n_rating = getRating($node);
            // homepage.inc
            $n_magazine = array();

            $data_newslist[$listcount]['n_polls'] = $n_polls;
            $data_newslist[$listcount]['n_rating'] = $n_rating;
            $data_newslist[$listcount]['n_magazine'] = $n_magazine;
            $n_widget = array();
            $data_newslist[$listcount]['n_widget'] = $n_widget;
            // for breaking_news
            $n_blog = array();
            $created = $resvalue['created'];
            $blog_type = $resvalue['field_type_value'];
            $new_blog = 0;
            if ($resvalue['field_multi_user_allows_value']) {
                $new_blog = 1;
            }
            elseif($resvalue['field_type_value'] == "Cricket Live Blog"){
               $new_blog = 2; 
            }
            $live_tv = 0;
            if ($resvalue['field_story_expires_value'] == 'Yes') {
                $live_tv = 1;
            }
            $short_desc = $resvalue['field_common_short_description_value'];
            $sub_title = $resvalue['field_constituancy_value'];
            $page_title = $node_data->title;
            $field_type_value = $resvalue['field_type_value'];
            //p($resvalue);
            
            if($type == "breaking_news"){
                $n_blog['blog_type'] = "$blog_type";
                $n_blog['id'] = "$nid";
                $n_blog['sub_title'] = "$sub_title";
                $n_blog['short_desc'] = "$short_desc";
                $n_blog['new_blog'] = "$new_blog";
                $n_blog['live_tv'] = "$live_tv";
                $n_blog = (object) $n_blog;
                $data_newslist[$listcount]['n_blog'] =  $n_blog;
            }
            else{
                $n_blog = array();    
                $n_blog['empty'] = "";
                $n_blog = (object) $n_blog;  
                $data_newslist[$listcount]['n_blog'] = $n_blog;
            }
            // for emoji
            $n_emoji_left = array();
            $n_emoji_right = array();
            $emoji_left = $resvalue['field_emoji_value'];
            $emoji_right = $resvalue['field_emoji_2_value'];
            if ($emoji_left) {
                $n_emoji_left = itg_rapid_get_emoji($emoji_left);
            }
            if ($emoji_right) {
                $n_emoji_right = itg_rapid_get_emoji($emoji_right);
            }
            $data_newslist[$listcount]['n_emoji_left'] = $n_emoji_left;
            $data_newslist[$listcount]['n_emoji_right'] = $n_emoji_right;

            $listcount++;
        }
    }

    $data_news['news'] = (object) $data_newslist;
    $order++;

    return $data_news;
}

function fetchitg_app_master_info_internaldata($tid, $key) {
    $value = "";
    if ($tid) {
        $query = db_select('itg_app_master_info_internal', 'mci');
        $query->fields('mci');
        $query->condition('mci.org_id', $tid, '=');
        $query->condition('mci.info_type', 'categories', '=');
        $query->condition('mci.info_key', $key, '=');
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        $value = $result[0]['info_value'];
    }
    return $value;
}

function fetchitg_app_master_config_internal($key) {
    $value = "";
    if ($key) {
        $query = db_select('itg_app_master_config_internal', 'mci');
        $query->fields('mci');
        $query->condition('mci.config_key', $key, '=');
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        $value = $result[0]['config_val'];
    }
    return $value;
}

function fetchitg_app_master_config_internal_key($config_val = 0) {
    $value = "";
    if ($config_val) {
        $query = db_select('itg_app_master_config_internal', 'mci');
        $query->fields('mci');
        $query->condition('mci.config_val', $config_val, '=');
        $db_or = db_or();
        $db_or->condition('mci.config_key', 'homeapi_order_packages', '=');
        $db_or->condition('mci.config_key', 'homeapi_order_topstories', '=');
        $db_or->condition('mci.config_key', 'homeapi_order_categories', '=');
        $db_or->condition('mci.config_key', 'homeapi_order_magazines', '=');
        $db_or->condition('mci.config_key', 'homeapi_order_polls', '=');
        $query->condition($db_or);
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        $value = $result[0]['config_key'];
    }
    return $value;
}

function fetch_widget_config($name) {
    $data = array();
    if ($name) {
        $query = db_select('itg_app_middleware', 'iam');
        $query->fields('iam');
        $query->condition('iam.identifier', 'itg_widget', '=');
        $query->condition('iam.name', $name, '=');
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        $data = $result[0];
    }
    return $data;
}

function itg_rv_widget_data($scorecard) {
    global $base_url;
    $data_news = array();
    $data_newslist = array();
    $comman = array();
    $n_widget = array();
    $listcount = 0;


    $data_news['id'] = "0";
    $data_news['order'] = "0";
    $data_news['type'] = "webview";
    $data_news['title'] = "Widget";
    $data_news['label'] = "Widget";
    $data_news['show_label'] = "0";
    $data_news['n_template_id'] = "1";

    $data_newslist[$listcount]['n_id'] = "0";
    $data_newslist[$listcount]['n_template_id'] = "";
    $data_newslist[$listcount]['n_type'] = "widget";
    $data_newslist[$listcount]['n_is_developing'] = "0";
    $data_newslist[$listcount]['n_is_sponsored'] = "0";
    $data_newslist[$listcount]['n_share_link'] = "";
    $data_newslist[$listcount]['n_title'] = "";
    $data_newslist[$listcount]['n_description'] = "0";
    $data_newslist[$listcount]['n_pcategory_id'] = "0";
    $data_newslist[$listcount]['n_pcategory_name'] = "";
    $data_newslist[$listcount]['n_comment_count'] = "";
    $data_newslist[$listcount]['n_small_image'] = "";
    $data_newslist[$listcount]['n_large_image'] = "";
    $data_newslist[$listcount]['n_image_credit'] = "";
    $data_newslist[$listcount]['n_updated_datetime'] = "";

    $data_newslist[$listcount]['n_photo'] = $comman;
    $data_newslist[$listcount]['n_video'] = $comman;
    $data_newslist[$listcount]['n_polls'] = $comman;
    $data_newslist[$listcount]['n_rating'] = $comman;
    $data_newslist[$listcount]['n_magazine'] = $comman;

    $n_widget[0] = json_decode($scorecard['url'], TRUE);

    $data_newslist[$listcount]['n_widget'] = $n_widget;

    $data_news['news'] = (array) $data_newslist;
    return $data_news;
}

function findarmin($arr) {
    $min = $arr[0];

    foreach ($arr as $key => $val) {
        if ($min > $val) {
            $min = $val;
        }
    }
    return $min;
}
