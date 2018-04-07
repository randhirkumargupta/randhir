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
    $data = array();
    $data_packagelist = array();
    $data_topstories = array();
    $data_news = array();
    $data_magazine = array();

    $data_packagelist_india = homePageJsonPackagelist_india();
    $data_topstories = topstoriesList('home');
    $data_news_india = homePageJsonNewslist_india();

    $data_news_lifestyle = homePageJsonNewslist_lifestyle();

    $data_news_world = homePageJsonNewslist_world();
    $data_magazine = homePageJsonMagazine();
    $data_poll = homePageJsonPoll();
    $homePageJsonWidget_1 = array();
    $homePageJsonWidget_1 = homePageJsonWidget_1();
    $homePageJsonWidget_2 = array();
    $homePageJsonWidget_2 = homePageJsonWidget_2();
    $homePageJsonWidget_3 = array();
    $homePageJsonWidget_3 = homePageJsonWidget_3();
    $business = array();
    //$business = homePageJsonNewslist_business();
    //change on 19-feb-18
    $itg_rapid_home_movies_json = array();
    $itg_rapid_home_movies_json = itg_rapid_home_movies_json();
    $itg_rapid_home_technology_json = array();
    $itg_rapid_home_technology_json = itg_rapid_home_technology_json();
    $itg_rapid_home_sports_json = array();
    $itg_rapid_home_sports_json = itg_rapid_home_sports_json();

    $data['status_code'] = "1";
    $data['status_message'] = "customised_message";    
    $data['data'][0] = $homePageJsonWidget_2;     // scorecard   
    $data['data'][1] = $data_topstories;  
    $data['data'][2] = $homePageJsonWidget_1; // CWG       
    $data['data'][3] = $itg_rapid_home_movies_json;
    $data['data'][4] = $itg_rapid_home_technology_json;
    $data['data'][5] = $data_news_india;
    $data['data'][6] = $itg_rapid_home_sports_json;
    $data['data'][7] = $data_news_lifestyle;
    $data['data'][8] = $data_news_world;
    $data['data'][9] = $data_magazine;
    return $data;
}

/**
 * main function for generate homePageJsonPackagelist_india array
 *
 * @return array
 */
function homePageJsonPackagelist_india() {

    global $base_url;
    $data_news = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    $tid = HOME_PAGE_JSON_ELECTION;
    $term_m = taxonomy_term_load($tid);
    $term_name_m = $term_m->name;
    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $listcount = 0;
    $range_max = 3;
    $range_min = 0;
    if (!$pageno == 0) {
        $range_min = $pageno * $range_max;
    }

    $order_by = 'ASC';
    $type = array("videogallery", "photogallery", "story");
    $news_list_array = array();
    $photolist = array();
    $videolist = array();
    $loop_count = 0;
    {
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
        $tid_list = array();
        $tid_list[] = $tid;
        // code vid=14  end
        $data_news['id'] = "$tid";
        $data_news['order'] = "1";
        $data_news['type'] = "packagelist";
        $data_news['title'] = "$term_name_m";
        $data_news['label'] = "$term_name_m";
        $data_news['show_label'] = "0";
        $data_news['n_template_id'] = "1";
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
        if (count($tid_list) > 0) {
            $query->condition('ti.tid', $tid_list, 'IN');
        }
        $d1 = date('Y-m-d', strtotime("-360 days"));
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

    return $data_news;
}

/**
 * main function for generate homePageJsonPackagelist_lifestyle array
 *
 * @return array
 */
function homePageJsonPackagelist_lifestyle() {

    global $base_url;
    $data_news = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    $tid = HOME_PAGE_JSON_MOVIES_PHOTO;
    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $listcount = 0;
    $range_max = 3;
    $range_min = 0;
    if (!$pageno == 0) {
        $range_min = $pageno * $range_max;
    }

    $order_by = 'ASC';
    $type = array("photogallery");
    $news_list_array = array();
    $photolist = array();
    $videolist = array();
    $loop_count = 0;
    {
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
        $data_news['order'] = "2";
        $data_news['type'] = "packagelist";
        $data_news['title'] = "Movies Photo";
        $data_news['label'] = "Movies Photo";
        $data_news['show_label'] = "0";
        $data_news['n_template_id'] = "1";


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

        $query->fields('kt', array('field_story_kicker_text_value'));
        $query->fields('vd', array('field_video_duration_value'));
        $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));
        if (count($tid_list) > 0) {
            $query->condition('ti.tid', $tid_list, 'IN');
        }
        $d1 = date('Y-m-d', strtotime("-360 days"));
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
            $data_newslist[$listcount]['n_large_image'] = "$file_medium_img_url";
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

    return $data_news;
}

/**
 * main function for generate homePageJsonPackagelist_world array
 *
 * @return array
 */
function homePageJsonPackagelist_world() {

    global $base_url;
    $data_news = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    $tid = HOME_PAGE_JSON_MOVIES_VIDEO;
    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $listcount = 0;
    $range_max = 3;
    $range_min = 0;
    if (!$pageno == 0) {
        $range_min = $pageno * $range_max;
    }

    $order_by = 'ASC';
    $type = array("videogallery");
    $news_list_array = array();
    $photolist = array();
    $videolist = array();
    $loop_count = 0;
    {
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
        $data_news['order'] = "3";
        $data_news['type'] = "packagelist";
        $data_news['title'] = "Movies video";
        $data_news['label'] = "Movies video";
        $data_news['show_label'] = "0";
        $data_news['n_template_id'] = "1";

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

        $query->fields('kt', array('field_story_kicker_text_value'));
        $query->fields('vd', array('field_video_duration_value'));
        $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));

        //end
        if (count($tid_list) > 0) {
            $query->condition('ti.tid', $tid_list, 'IN');
        }
        $d1 = date('Y-m-d', strtotime("-360 days"));
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
            //$weburl = $base_url . "/node/" . $nid;
            $alias = drupal_get_path_alias('node/' . $nid . '');
            $weburl = $base_url . "/" . $alias;
            $field_video_duration_value = $resvalue['field_video_duration_value'];
            // file url
            $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
            $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);

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
            $data_newslist[$listcount]['n_large_image'] = "$file_medium_img_url";
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

    return $data_news;
}

/**
 * main function for generate homePageJsonTopstories array
 *
 * @return array
 */
function homePageJsonTopstories() {
    // variable declation
    $data_topstories = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    $home_list_count = 0;
    $widget_name = "top_stories_widget";
    $range_max = 10;
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


    //end
    $query->condition('iwo.widget', $widget_name)->condition('n.status', 1)->condition('n.type', 'story')->groupBy('n.nid')->orderBy('iwo.weight', $order_by)->orderBy('n.nid', 'DESC')->range($range_min, $range_max)->fields('iwo', array('nid', 'extra', 'weight'));
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $data_topstories['id'] = "0";
    $data_topstories['order'] = "2";
    $data_topstories['type'] = "topstories";
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
            $changed_datetime = "";
        }
        // Get Publish time:
        $pub_date = get_content_publish_date($nid);
        if (!empty($pub_date)) {  
          $pub_date = date('Y-m-d H:i:s', strtotime($pub_date[0]['field_itg_content_publish_date_value']));
        } else {
          $pub_date = "";
        }
        //json tag writing
        if ($type == "story") {
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
            $data_newslist[$home_list_count]['n_updated_datetime'] = "$pub_date";
            $data_newslist[$home_list_count]['n_photo'] = $n_photo;
            $data_newslist[$home_list_count]['n_video'] = $n_video;
            $data_newslist[$home_list_count]['n_polls'] = $n_polls;
            $data_newslist[$home_list_count]['n_rating'] = $n_rating;
            $data_newslist[$home_list_count]['n_magazine'] = $n_magazine;
            $n_widget = array();
            $data_newslist[$home_list_count]['n_widget'] = $n_widget;
            $home_list_count++;
        }
    }

    $data_topstories['news'] = (array) $data_newslist;
    return $data_topstories;
}

/**
 * main function for generate homePageJsonNewslist_india array
 *
 * @return array
 */
function homePageJsonNewslist_india() {
    global $base_url;
    $data_news = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    $tid = HOME_PAGE_JSON_NEWS_LIST_INDIA;
    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $tid_list[] = $tid;
    $listcount = 0;
    $range_max = 5;
    $range_min = 0;
    if (!$pageno == 0) {
        $range_min = $pageno * $range_max;
    }

    $order_by = 'ASC';
    $type = array("videogallery", "photogallery", "story");
    $news_list_array = array();
    $photolist = array();
    $videolist = array();
    $loop_count = 0;
    {
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

        $data_news['id'] = "1206578";
        $data_news['order'] = "2";
        $data_news['type'] = "newslist";
        $data_news['title'] = "India";
        $data_news['label'] = "India";
        $data_news['show_label'] = "0";
        $data_news['n_template_id'] = "1";
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

        if (count($tid_list) > 0) {
            $query->condition('ti.tid', $tid_list, 'IN');
        }
        $d1 = date('Y-m-d', strtotime("-360 days"));
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

    return $data_news;
}

/**
 * main function for generate homePageJsonNewslist_world array
 *
 * @return array
 */
function homePageJsonNewslist_world() {
    global $base_url;
    $data_news = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    $tid = HOME_PAGE_JSON_NEWS_LIST_WORLD;
    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $tid_list[] = $tid;
    $listcount = 0;
    $range_max = 5;
    $range_min = 0;
    if (!$pageno == 0) {
        $range_min = $pageno * $range_max;
    }

    $order_by = 'ASC';
    $type = array("videogallery", "photogallery", "story");
    $news_list_array = array();
    $photolist = array();
    $videolist = array();
    $loop_count = 0;
    {
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
        $data_news['order'] = "4";
        $data_news['type'] = "newslist";
        $data_news['title'] = "World";
        $data_news['label'] = "World";
        $data_news['show_label'] = "0";
        $data_news['n_template_id'] = "3";

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

        if (count($tid_list) > 0) {
            $query->condition('ti.tid', $tid_list, 'IN');
        }
        $d1 = date('Y-m-d', strtotime("-360 days"));
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

    return $data_news;
}

/**
 * main function for generate homePageJsonMagazine array
 *
 * @return array
 */
function homePageJsonMagazine() {
    $data_magazine = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    $n_magazine_data = magazineCoverstoriesPageRerourceValueList();
    $n_magazine = $n_magazine_data['data'];

    $data_magazine['id'] = "0";
    $data_magazine['order'] = "5";
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
        // Get Publish time:
        $pub_date = get_content_publish_date($nid);
        if (!empty($pub_date)) {  
          $pub_date = date('Y-m-d H:i:s', strtotime($pub_date[0]['field_itg_content_publish_date_value']));
        } else {
          $pub_date = "";
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
        $story[$loop_count]['s_updated_datetime'] = "$pub_date";
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
 *
 * @return bool
 */
function in_multiarray($elem, $array, $field) {
    $top = sizeof($array) - 1;
    $bottom = 0;
    while ($bottom <= $top) {
        if ($array[$bottom][$field] == $elem) {
            return TRUE;
        } elseif (is_array($array[$bottom][$field]))
            if (in_multiarray($elem, ($array[$bottom][$field]))) {
                return TRUE;
            }

        $bottom++;
    }
    return FALSE;
}

/**
 * function for getNodeBodyByNid
 * @pram datetime $nid
 *
 * @return string $field_data_body;
 */
function getNodeBodyByNid_Report($nid) {
    if ($nid) {
        $query = db_select('field_data_body', 'nb');
        $query->fields('nb', array('body_value'));
        $query->condition('nb.entity_id', $nid);
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        $field_data_body = $result[0]['body_value'];
        return $field_data_body;
    }
}

/**
 * function for getNode prime cat tid ByNid
 * @pram datetime $nid
 *
 * @return obj term_object;
 */
function getNodePrimeCatByNid_($nid) {
    $query = db_select('field_data_field_primary_category', 'fpc');
    $query->fields('fpc', array('field_primary_category_value'));
    $query->condition('fpc.entity_id', $nid);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $field_primary_category_value = $result[0]['field_primary_category_value'];
    return taxonomy_term_load($field_primary_category_value);
}

/**
 * main function for generate homePageJsonPoll array
 *
 * @return array
 */
function homePageJsonPoll() {
    /* static poll show at front. */


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
    $data_magazine['order'] = "7";
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
    return $data_magazine;
}

/**
 * main function for generate homePageJsonNewslist_lifestyle array
 *
 * @return array
 */
function homePageJsonNewslist_lifestyle() {
    global $base_url;
    $data_news = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    $tid = HOME_PAGE_JSON_NEWS_LIST_LIFE_STYLE;
    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $tid_list[] = $tid;
    $listcount = 0;
    $range_max = 5;
    $range_min = 0;
    if (!$pageno == 0) {
        $range_min = $pageno * $range_max;
    }

    $order_by = 'ASC';
    $type = array("videogallery", "photogallery", "story");
    $news_list_array = array();
    $photolist = array();
    $videolist = array();
    $loop_count = 0;
    {
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
        $data_news['order'] = "3";
        $data_news['type'] = "newslist";
        $data_news['title'] = "Lifestyle";
        $data_news['label'] = "Lifestyle";
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

        if (count($tid_list) > 0) {
            $query->condition('ti.tid', $tid_list, 'IN');
        }
        $d1 = date('Y-m-d', strtotime("-360 days"));
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

    return $data_news;
}
/**
 * main function for generate homePage Widget1 array
 *
 * @return array
 */
function homePageJsonWidget_1() {
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
    
    $n_widget[0]['type'] = "1";
    $n_widget[0]['type_label'] = "cwgtally";
    $n_widget[0]['tilte'] = "CWG 2018 MEDAL TALLY"; 
    $n_widget[0]['short_url'] = "https://assets-indiatoday.sportz.io/cwg/medals_tally_rhs.html";
    $n_widget[0]['extended_url'] = "https://assets-indiatoday.sportz.io/cwg/medals_tally_page.html";
    $n_widget[0]['action'] = "webview";    
    
    $data_newslist[$listcount]['n_widget'] = $n_widget;

    $data_news['news'] = (array) $data_newslist;
    return $data_news;
}
/**
 * main function for generate homePageJsonNewslist_india array
 *
 * @return array
 */
function homePageJsonNewslist_business() {
    global $base_url;
    $data_news = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    if($_SERVER['SERVER_NAME'] == "appfeeds.intoday.in"){
        $tid = 1778508;
        $label = "Union Budget 2018";
    }
    else{
        $tid = 1206574;
        $label = "Business";
    }
    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $tid_list[] = $tid;
    $listcount = 0;
    $range_max = 5;
    $range_min = 0;
    if (!$pageno == 0) {
        $range_min = $pageno * $range_max;
    }

    $order_by = 'ASC';
    $type = array("videogallery", "photogallery", "story");
    $news_list_array = array();
    $photolist = array();
    $videolist = array();
    $loop_count = 0;
    {
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
        $data_news['order'] = "2";
        $data_news['type'] = "newslist";
        $data_news['title'] = "$label";
        $data_news['label'] = "$label";
        $data_news['show_label'] = "0";
        $data_news['n_template_id'] = "1";
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

    return $data_news;
}

//changes on 19-feb-18
/**
 * main function for generate itg_rapid_home_movies array
 *
 * @return array
 */
function itg_rapid_home_movies_json() {
    global $base_url;
    $data_news = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    $tid = 1206533; // MOVIES
    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $tid_list[] = $tid;
    $listcount = 0;
    $range_max = 5;
    $range_min = 0;
    if (!$pageno == 0) {
        $range_min = $pageno * $range_max;
    }

    $order_by = 'ASC';
    $type = array("videogallery", "photogallery", "story");
    $news_list_array = array();
    $photolist = array();
    $videolist = array();
    $loop_count = 0;
    {
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
        $term = taxonomy_term_load($tid);
        $term_name = $term->name;
        $data_news['id'] = "$tid";
        $data_news['order'] = "2";
        $data_news['type'] = "newslist";
        $data_news['title'] = "$term_name";
        $data_news['label'] = "$term_name";
        $data_news['show_label'] = "0";
        $data_news['n_template_id'] = "1";
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
        $interval = itg_app_time_interval($tid);
        $d1 = date('Y-m-d', strtotime("-" . $interval . " days"));
        $d2 = date(strtotime($d1));
        $query->condition('n.created', $d2, '>=');
        $query->condition('n.status', 1)->condition('n.type', $type, 'IN')->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);

        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

        foreach ($result as $reskey => $resvalue) {
            $title = strip_tags($resvalue['title']);
            $type = $resvalue['type'];
            $nid = $resvalue['nid'];
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

    return $data_news;
}

/**
 * main function for generate itg_rapid_home_technology array
 *
 * @return array
 */
function itg_rapid_home_technology_json() {
    global $base_url;
    $data_news = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    $tid = 1206688; // technology
    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $tid_list[] = $tid;
    $listcount = 0;
    $range_max = 5;
    $range_min = 0;
    if (!$pageno == 0) {
        $range_min = $pageno * $range_max;
    }

    $order_by = 'ASC';
    $type = array("videogallery", "photogallery", "story");
    $news_list_array = array();
    $photolist = array();
    $videolist = array();
    $loop_count = 0;
    {
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
        $term = taxonomy_term_load($tid);
        $term_name = $term->name;
        $data_news['id'] = "$tid";
        $data_news['order'] = "2";
        $data_news['type'] = "newslist";
        $data_news['title'] = "$term_name";
        $data_news['label'] = "$term_name";
        $data_news['show_label'] = "0";
        $data_news['n_template_id'] = "1";
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
        $interval = itg_app_time_interval($tid);
        $d1 = date('Y-m-d', strtotime("-" . $interval . " days"));
        $d2 = date(strtotime($d1));
        $query->condition('n.created', $d2, '>=');
        $query->condition('n.status', 1)->condition('n.type', $type, 'IN')->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);

        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

        foreach ($result as $reskey => $resvalue) {
            $title = strip_tags($resvalue['title']);
            $type = $resvalue['type'];
            $nid = $resvalue['nid'];
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

    return $data_news;
}
/**
 * main function for generate itg_rapid_home_sports array
 *
 * @return array
 */
function itg_rapid_home_sports_json() {
    global $base_url;
    $data_news = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    $tid = 1206550; // sports
    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $tid_list[] = $tid;
    $listcount = 0;
    $range_max = 5;
    $range_min = 0;
    if (!$pageno == 0) {
        $range_min = $pageno * $range_max;
    }

    $order_by = 'ASC';
    $type = array("videogallery", "photogallery", "story");
    $news_list_array = array();
    $photolist = array();
    $videolist = array();
    $loop_count = 0;
    {
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
        $term = taxonomy_term_load($tid);
        $term_name = $term->name;
        $data_news['id'] = "$tid";
        $data_news['order'] = "2";
        $data_news['type'] = "newslist";
        $data_news['title'] = "$term_name";
        $data_news['label'] = "$term_name";
        $data_news['show_label'] = "0";
        $data_news['n_template_id'] = "1";
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
        $interval = itg_app_time_interval($tid);
        $d1 = date('Y-m-d', strtotime("-" . $interval . " days"));
        $d2 = date(strtotime($d1));
        $query->condition('n.created', $d2, '>=');
        $query->condition('n.status', 1)->condition('n.type', $type, 'IN')->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);

        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

        foreach ($result as $reskey => $resvalue) {
            $title = strip_tags($resvalue['title']);
            $type = $resvalue['type'];
            $nid = $resvalue['nid'];
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

    return $data_news;
}
/**
 * main function for generate homePage Widget2 array
 *
 * @return array
 */
function homePageJsonWidget_2() {
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
    
    $n_widget[0]['type'] = "2";
    $n_widget[0]['type_label'] = "scorecard";
    $n_widget[0]['tilte'] = "Scorecard"; 
    $n_widget[0]['short_url'] = "https://feeds.intoday.in/xml_it/commentary/widget_scorecardapp_home_v1.html";
    $n_widget[0]['extended_url'] = "https://feeds.intoday.in/xml_it/commentary/widget_scorecardapp_detail.html";
    $n_widget[0]['action'] = "webview"; 
    $n_widget[0]['is_india_match'] = "1";
    
    $data_newslist[$listcount]['n_widget'] = $n_widget;

    $data_news['news'] = (array) $data_newslist;
    return $data_news;
}
/**
 * main function for generate homePage Widget3 array
 *
 * @return array
 */
function homePageJsonWidget_3() {
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
    
    $n_widget[0]['type'] = "4";
    $n_widget[0]['type_label'] = "watchlive";
    $n_widget[0]['tilte'] = "India Today Conclave 2018 Live"; 
    $n_widget[0]['short_url'] = "http://feeds.intoday.in/aajtak/api/conclave.html";
    $n_widget[0]['extended_url'] = "http://conclave.intoday.in/2018/";
    $n_widget[0]['action'] = "webview";    
    
    $data_newslist[$listcount]['n_widget'] = $n_widget;

    $data_news['news'] = (array) $data_newslist;
    return $data_news;
}
