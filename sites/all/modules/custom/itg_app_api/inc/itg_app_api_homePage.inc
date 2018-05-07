<?php

/**
 * Inc file contains the functions for homePgae API 
 */

/**
 * main function for generate homePageJson array
 *
 * @return array
 */
function homePageJson() {
    global $order;
    $data = array();
    $data_final = array();
    $data_packagelist = array();
    $data_topstories = array();
    $data_news = array();
    $data_magazine = array();
    $order = "1";
    $data_cat_news = array();
    $data_poll = array();
    $data_topstories = array();
    $data_middleware = array();
    $total_count = 0;

    $middleware_packages_config = fetchMasterConfigData('packages_config_options');
    if ($middleware_packages_config == 1) {
        $data_middleware = home_page_packages();

        $total_count += count($data_middleware);
    }

    $middleware_topstories_config = fetchMasterConfigData('top_stories_config_options');
    if ($middleware_topstories_config == 1) { //enable
        $limit = fetchMasterConfigData('top_stories_management');
        $data_topstories = topstoriesList('home', $limit);
        $total_count += count($data_topstories);
    }

    $middleware_cat_config = fetchMasterConfigData('categories_config_options');
    if ($middleware_cat_config == 1) { //enable
        $data_cat_news = home_page_newslist_cat();
        
        $total_count += count($data_cat_news);
    }

    $middleware_magazine_config = fetchMasterConfigData('magazine_config_options');
    if ($middleware_magazine_config == 1) { //enable
        $data_magazine = homePageJsonMagazine();
        $total_count += count($data_magazine);
    } elseif ($middleware_magazine_config == 2) {
        $data_magazine = homePageJsonMagazine('direct');
        $total_count += count($data_magazine);
    }

    $middleware_polls_config = fetchMasterConfigData('polls_config_options');
    if ($middleware_polls_config == 1) { //enable
        $data_poll = homePageJsonPoll();
        $total_count += count($data_poll);
    }

    $success_status_mess = fetchMasterConfigData('homePage_display_custom_msg');
    $success_status_message = isset($success_status_mess) ? $success_status_mess : "";

    if ($total_count > 0) {
        $data['status_code'] = "1";
        $data['status_message'] = "$success_status_message";
        $data_final['status_code'] = "1";
        $data_final['status_message'] = "$success_status_message";
    } else {
        $data['status_code'] = "0";
        $data['status_message'] = "";
        $data_final['status_code'] = "0";
        $data_final['status_message'] = "";
    }

    $i = 0;
    $homeapi_order_packages = fetchitg_app_master_config_internal('homeapi_order_packages');
    $homeapi_order_topstories = fetchitg_app_master_config_internal('homeapi_order_topstories');
    $homeapi_order_categories = fetchitg_app_master_config_internal('homeapi_order_categories');
    $homeapi_order_magazines = fetchitg_app_master_config_internal('homeapi_order_magazines');
    $homeapi_order_polls = fetchitg_app_master_config_internal('homeapi_order_polls');

    if (count($data_middleware) > 0) {
        $data['data'][$homeapi_order_packages] = $data_middleware;
        $i++;
    } else {
        unset($data['data'][$homeapi_order_packages]);
    }

    if (count($data_topstories) > 0) {
        $data['data'][$homeapi_order_topstories] = $data_topstories;
        $i++;
    } else {
        unset($data['data'][$homeapi_order_topstories]);
    }
    if (count($data_cat_news) > 0) {

        $data['data'][$homeapi_order_categories] = $data_cat_news;
        $i++;
    } else {
        unset($data['data'][$homeapi_order_categories]);
    }
    if (count($data_magazine) > 0) {
        $data['data'][$homeapi_order_magazines] = $data_magazine;
        $i++;
    } else {
        unset($data['data'][$homeapi_order_magazines]);
    }
    if (count($data_poll) > 0) {
        $data['data'][$homeapi_order_polls] = $data_poll;
        $i++;
    } else {
        unset($data['data'][$homeapi_order_polls]);
    }
    /* widget calling start */
    $middleware_packages_config = fetchMasterConfigData('widget_config_options');
    if ($middleware_packages_config) {
        $query_w = db_select('itg_app_middleware', 'iam');
        $query_w->fields('iam');
        $query_w->condition('iam.identifier', 'itg_widget', '=');
        $query_w->condition('iam.status', 1, '=');
        $result_w = $query_w->execute()->fetchAll(PDO::FETCH_ASSOC);

        foreach ($result_w as $reskey => $resvalue) {
            $name = $resvalue['name'];
            $widget = fetch_widget_config($name);
            if ($widget['status'] == 1) {
                $widget_data = itg_rv_widget_data($widget);
                
                $widget_order = fetchitg_app_master_config_internal('homeapi_order_widget_' . $name . '');

                $data['data'][$widget_order] = (array) $widget_data;
            }
        }
    }
    
    $array_key = array_keys($data['data']);

    $active_chunk_c = count($data['data']);
    $data_live = array();
    for ($i = 0; $i < $active_chunk_c; $i++) {
        $min_key = min($array_key);
        if (count($data['data'][$min_key]) > 1 || isset($data['data'][$min_key][0]['id'])) {
           
            $data_live[$i] = $data['data'][$min_key];
            unset($data['data'][$min_key]);

            foreach ($array_key as $key => $value) {
                if ($value == $min_key) {
                    unset($array_key[$key]);
                }
            }
        }
    }

    $data['data'] = $data_live;

    $lc = 0;
    foreach ($data['data'] as $key => $value) {
        if (count($value[0]) > 0) {
            foreach ($value as $key2 => $value2) {
                $order_v = $lc + 1;
                $value2['order'] = "$order_v";
                $data_final['data'][$lc] = $value2;
                $lc ++;
            }
        } else {
            $order_v = $lc + 1;
            $value['order'] = "$order_v";
            $data_final['data'][$lc] = $value;
            $lc ++;
        }
    }
    if (count($data) == 2) {
        $data['data'] = array();
        $data_final['data'] = array();
    }

    return $data_final;
}

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

        $query->condition('ti.tid', $tid, '=');
        //$interval = itg_app_time_interval($tid);
        $interval = 360;
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
        //$interval = itg_app_time_interval($tid);
        $interval = 360;
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
 * main function for generate homePageJsonTopstories array
 *
 * @return array
 */
function homePageJsonTopstories($top_story_limit) {
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
    $range_max = $top_story_limit;
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

    $query->fields('kt', array('field_story_kicker_text_value'));
    $query->fields('vd', array('field_video_duration_value'));
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));
    $query->fields('ti', array('tid'));


    //end
    $query->condition('iwo.widget', $widget_name)->condition('n.status', 1)->condition('n.type', 'story')->groupBy('n.nid')->orderBy('iwo.weight', $order_by)->orderBy('n.nid', 'DESC')->range($range_min, $range_max)->fields('iwo', array('nid', 'extra', 'weight'));
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $data_topstories['id'] = "0";
    $data_topstories['order'] = "$order";
    $data_topstories['type'] = "newslist";
    $data_topstories['title'] = "Top Stories";
    $data_topstories['label'] = "Top Stories";
    $data_topstories['show_label'] = "0";
    $data_topstories['n_template_id'] = "1";

    // xml tag wring for features widget..
    foreach ($result as $key => $value) {
        // varibale for json tag
        $title = $value['title'];
        $type = $value['type'];
        $nid = $value['nid'];
        $created = $value['created'];
        $changed = $value['changed'];
        $tid = $value['tid'];
        $field_story_kicker_text_value = $value['field_story_kicker_text_value'];

        $term = taxonomy_term_load($tid);
        $term_name = $term->name;

        // file url
        $file_small_img_url = completeFilePath($value['field_story_small_image_fid']);
        $file_medium_img_url = completeFilePath($value['field_story_medium_image_fid']);
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
        //json tag writing
        if ($type == "story") {
            // news list
//      $n_photo = getPhotolist($nid);
//      $n_video = getVideolist($nid);
//      $n_polls = getPolllist($node);
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
            $data_newslist[$home_list_count]['n_large_image'] = "$file_medium_img_url";
            $data_newslist[$home_list_count]['n_image_credit'] = "$byline";
            $data_newslist[$home_list_count]['n_updated_datetime'] = "$changed_datetime";
            $data_newslist[$home_list_count]['n_photo'] = $n_photo;
            $data_newslist[$home_list_count]['n_video'] = $n_video;
            $data_newslist[$home_list_count]['n_polls'] = $n_polls;
            $data_newslist[$home_list_count]['n_rating'] = $n_rating;
            $data_newslist[$home_list_count]['n_magazine'] = $n_magazine;
            $home_list_count++;
        }
    }

    $data_topstories['news'] = (array) $data_newslist;
    $order++;
    return $data_topstories;
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

        //end

        $query->condition('ti.tid', $tid, '=');
        //$interval = itg_app_time_interval($tid);
        $interval = 360;
        $d1 = date('Y-m-d', strtotime("-" . $interval . " days"));
        $d2 = date(strtotime($d1));
        $query->condition('n.created', $d2, '>=');
        $query->condition('n.status', 1)->condition('n.type', $type, 'IN')->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);

        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

        foreach ($result as $reskey => $resvalue) {
            // filter breaking news blog..
            if($resvalue['field_type_value'] == "Breaking News"){
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
                
                $n_blog = (object) $n_blog;
                $data_newslist[$listcount]['n_blog'] = new \stdClass();
            }
            

            $listcount++;
        }
    }

    $data_news['news'] = (array) $data_newslist;
    $order++;

    return $data_news;
}

/**
 * main function for generate homePageJsonMagazine array
 *
 * @return array
 */
function homePageJsonMagazine($direct = "") {
    global $order;
    $data_magazine = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    if ($direct == 'direct') {
        $n_magazine_data = magazineCoverstoriesPageRerourceValueList();
    } else {
        $n_magazine_data = magazineCoverstoriesPageRerourceValueList('home');
    }

    $n_magazine = $n_magazine_data['data'];

    $data_magazine['id'] = "0";
    $data_magazine['order'] = "$order";
    $data_magazine['type'] = "magazine";
    $data_magazine['title'] = "From The Magazine";
    $data_magazine['label'] = "From The Magazine";
    $data_magazine['show_label'] = "0";
    // news list
    $share_url = get_node_firebase_weburl($nid);
    $is_developing = 0;
    $conf = getStoryConfigVal($nid);
    if (in_multiarray("developing_story", $conf, "field_story_configurations_value")) {
        $is_developing = 1;
    }
    $data_newslist[0]['n_id'] = "";
    $data_newslist[0]['n_type'] = "";
    $data_newslist[0]['n_is_developing'] = "$is_developing";
    $data_newslist[0]['n_is_sponsored'] = "";
    $data_newslist[0]['n_share_link'] = "";
    $data_newslist[0]['n_title'] = "";
    $data_newslist[0]['n_description'] = "";
    $data_newslist[0]['n_pcategory_id'] = "";
    $data_newslist[0]['n_pcategory_name'] = "";
    $data_newslist[0]['n_comment_count'] = "";
    $data_newslist[0]['n_small_image'] = "";
    $data_newslist[0]['n_large_image'] = "";
    $data_newslist[0]['n_image_credit'] = "";
    $data_newslist[0]['n_updated_datetime'] = "";
    $data_newslist[0]['n_photo'] = $n_photo;
    $data_newslist[0]['n_video'] = $n_video;
    $data_newslist[0]['n_polls'] = $n_polls;
    $data_newslist[0]['n_rating'] = $n_rating;
    $data_newslist[0]['n_magazine'] = $n_magazine;
    $n_widget = array();
    $data_newslist[0]['n_widget'] = $n_widget;

    $data_magazine['news'] = (array) $data_newslist;
    $order++;
    return $data_magazine;
}

/**
 * function for generate getPolllist array
 *
 * @return array
 */
function getPolllist($node) {
    $poll = array();
    return $poll;
}

/**
 * function for generate getMagazineList array
 *
 * @return array
 */
function getMagazineList() {
    $magazine = array();
    $issue = array();
    $story = array();

    $loop_count = 0;
    $range_min = 0;
    $range_max = 5;
    // issue list query..

    $query_issue = db_select('node', 'n');
    $query_issue->leftJoin('field_data_field_issue_large_cover_image', 'fsli', 'fsli.entity_id=n.nid');
    $query_issue->leftJoin('field_data_field_issue_small_cover_image', 'fssi', 'fssi.entity_id=n.nid');
    $query_issue->leftJoin('field_data_field_issue_title', 'fsit', 'fsit.entity_id=n.nid');

    $query_issue->fields('fsli', array('field_issue_large_cover_image_fid'));
    $query_issue->fields('fssi', array('field_issue_small_cover_image_fid'));
    $query_issue->fields('fsit', array('field_issue_title_value'));
    $query_issue->fields('n', array('nid'));

    $query_issue->condition('n.status', 1)->condition('n.type', 'issue')->orderBy('n.created', 'DESC')->range($range_min, $range_max);
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

        $story = getMagazineStory($issue_date);

        $issue[$loop_count]['issue_id'] = "$issue_nid";
        $issue[$loop_count]['i_issue_date'] = "$issue_date";
        $issue[$loop_count]['issue_cover_image'] = "$issue_cover_image";
        $issue[$loop_count]['story'] = $story;
        $loop_count++;
    }


    $magazine['issue'] = $issue;



    return $magazine;
}

/**
 * function for generate getMagazineStory array
 *
 * @return array
 */
function getMagazineStory($issue_date) {
    $story = array();

    // select issue stories
    $range_min = 0;
    $range_max = 5;

    $query = db_select('node', 'n');
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
    $query->fields('si', array('field_story_small_image_fid'));
    $query->fields('rc', array('field_common_related_content_value'));

    $query->fields('kt', array('field_story_kicker_text_value'));
    $query->fields('vd', array('field_video_duration_value'));
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));

    $query->fields('fsbl', array('field_itg_common_by_line_name_value'));
    $query->fields('fsri', array('field_reporter_unique_id_value'));
    $query->fields('fci', array('field_primary_category_value'));

    //end
    $query->condition('n.status', 1)->condition('n.type', 'story')->condition('fsid.field_story_issue_date_value', $issue_date)->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $loop_count = 0;

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

        //related content
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
        if (in_multiarray("lock_story", $conf, "field_story_configurations_value")) {
            $is_lock = 1;
        }

        $field_itg_common_by_line_name_value = $resvalue['field_itg_common_by_line_name_value'];
        $field_reporter_unique_id_value = $resvalue['field_reporter_unique_id_value'];
        $field_reporter_unique_id_value = str_replace("byline_", "", $field_reporter_unique_id_value);

        $field_primary_category_value = $resvalue['field_primary_category_value'];
        $term = taxonomy_term_load($field_primary_category_value);
        $term_name = $term->name;

        $story[$loop_count]['s_id'] = "$nid";
        $story[$loop_count]['s_title'] = "$title";
        $story[$loop_count]['s_share_link'] = "$firebase_url";
        $story[$loop_count]['s_short_desc'] = "$field_story_kicker_text_value";
        $story[$loop_count]['s_comment_count'] = "$comment_cont";
        $story[$loop_count]['s_small_image'] = "$file_small_img_url";
        $story[$loop_count]['s_large_image'] = "$file_medium_img_url";
        $story[$loop_count]['s_updated_datetime'] = "$changed_datetime";
        $story[$loop_count]['s_is_locked'] = "$is_lock";
        $story[$loop_count]['s_author_id'] = "$field_reporter_unique_id_value";
        $story[$loop_count]['s_author_title'] = "$field_itg_common_by_line_name_value";
        $story[$loop_count]['s_pcategory_id'] = "$field_itg_common_by_line_name_value";
        $story[$loop_count]['s_pcategory_title'] = "$term_name";
        $loop_count++;
    }



    return $story;
}

/**
 * function for serach in M-D array
 * @pram array
 * @return bool
 */
function in_multiarray($elem, $array, $field) {
    $top = sizeof($array) - 1;
    $bottom = 0;
    while ($bottom <= $top) {
        if ($array[$bottom][$field] == $elem)
            return true;
        else
        if (is_array($array[$bottom][$field]))
            if (in_multiarray($elem, ($array[$bottom][$field])))
                return true;

        $bottom++;
    }
    return false;
}

/**
 * function for getNodeBodyByNid
 * @pram datetime $nid 
 * @return string $field_data_body;
 */
function getNodeBodyByNid_Report($nid) {
    $query = db_select('field_data_body', 'nb');
    $query->fields('nb', array('body_value'));
    $query->condition('nb.entity_id', $nid);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $field_data_body = $result[0]['body_value'];
    return $field_data_body;
}

/**
 * main function for generate homePageJsonPoll array
 *
 * @return array
 */
function homePageJsonPoll() {
    global $order;
    $data_magazine = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    $n_magazine = array();

    $n_polls = array();
    $n_polls = polls_open_datalist(0, "home");

    $data_magazine['id'] = "0";
    $data_magazine['order'] = "$order";
    $data_magazine['type'] = "poll";
    $data_magazine['title'] = "poll";
    $data_magazine['label'] = "poll";
    $data_magazine['show_label'] = "0";
    // news list
    $share_url = get_node_firebase_weburl($nid);
    $is_developing = 0;
    $conf = getStoryConfigVal($nid);
    if (in_multiarray("developing_story", $conf, "field_story_configurations_value")) {
        $is_developing = 1;
    }
    $data_newslist[0]['n_id'] = "";
    $data_newslist[0]['n_type'] = "";
    $data_newslist[0]['n_is_developing'] = "$is_developing";
    $data_newslist[0]['n_is_sponsored'] = "";
    $data_newslist[0]['n_share_link'] = "";
    $data_newslist[0]['n_title'] = "";
    $data_newslist[0]['n_description'] = "";
    $data_newslist[0]['n_pcategory_id'] = "";
    $data_newslist[0]['n_pcategory_name'] = "";
    $data_newslist[0]['n_comment_count'] = "";
    $data_newslist[0]['n_small_image'] = "";
    $data_newslist[0]['n_large_image'] = "";
    $data_newslist[0]['n_image_credit'] = "";
    $data_newslist[0]['n_updated_datetime'] = "";
    $data_newslist[0]['n_photo'] = $n_photo;
    $data_newslist[0]['n_video'] = $n_video;
    $data_newslist[0]['n_polls'] = $n_polls['data'];
    $data_newslist[0]['n_rating'] = $n_rating;
    $data_newslist[0]['n_magazine'] = $n_magazine;
    $n_widget = array();
    $data_newslist[0]['n_widget'] = $n_widget;

    $data_magazine['news'] = (array) $data_newslist;
    //$data_magazine = (array) $data_magazine;


    return $data_magazine;
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
