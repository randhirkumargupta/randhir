<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate videoCategoryPage array
 *
 * @return array
 */
function newscategoryPageRerourceValue($tid = 0, $pageno = 0) {
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
    $data = generateNewsCategoryList($tid, $pageno);
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

    if ($datacount > 10) {
        $datacount = 10;
    }

    $data_array['id'] = "$tid";
    $data_array['title'] = "$term_name";
    $data_array['layout_id'] = "0";
    $data_array['news_count'] = "$datacount";
    $data_array['news_display_count'] = "10";
    $data_array['news_pagination_cap'] = "7";
    $data_array['updated_datetime'] = "$data_up_time";


    $data_array['news'] = $data['data'];
    $output_array['data'] = $data_array;

    return $output_array;
}

/**
 * function for generate videoCategoryPage list
 *
 * @return array
 */
function generateNewsCategoryList($tid, $pageno) {
    // variable declaration
    global $base_url;
    $node_count = "";
    $output = "";
    $data = array();
    $tid_list = array();
    $tid_list[] = $tid;
    $listcount = 0;
    $range_max = 10;
    //$photolist = array();
    if (!$pageno == 0) {
        $range_min = $pageno * $range_max;
    } else {
        $range_min = 0;
    }
    $order_by = 'ASC';
    $type = array("videogallery", "photogallery", "story");
    //$type = "videogallery, photogallery, story";
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
        $query->leftJoin('field_data_field_primary_category', 'fpc', 'fpc.entity_id=n.nid');

        $query->fields('eli_file', array('uri'));
        $query->fields('li_file', array('uri'));
        $query->fields('mi_file', array('uri'));
        $query->fields('si_file', array('uri'));
        $query->fields('esi_file', array('uri'));

        $query->fields('eli', array('field_story_extra_large_image_fid'));
        $query->fields('mi', array('field_story_medium_image_fid'));
        $query->fields('li', array('field_story_large_image_fid'));
        $query->fields('si', array('field_story_small_image_fid'));
        $query->fields('rc', array('field_common_related_content_value'));

        $query->fields('kt', array('field_story_kicker_text_value'));
        $query->fields('vd', array('field_video_duration_value'));
        $query->fields('fpc', array('field_primary_category_value'));
        $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));


        //end

        if (count($tid_list) > 0) {
            $query->condition('ti.tid', $tid_list, 'IN');
        }
        $query->condition('n.status', 1)->condition('n.type', $type, 'IN')->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);

        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

        foreach ($result as $reskey => $resvalue) {

            // node feed tag
            $title = $resvalue['title'];
            $type = $resvalue['type'];
            $nid = $resvalue['nid'];
            //p(node_load($nid));die();
            if ($type == 'story') {
                $type = getStoryType($nid);
            }
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
            $file_ext_large_img_url = completeFilePath($resvalue['field_story_extra_large_image_fid']);



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
            $field_primary_category_value = $resvalue['field_primary_category_value'];
            $term = taxonomy_term_load($field_primary_category_value);
            $term_name = $term->name;

            $news_list_array[$listcount]['n_id'] = "$nid";
            $news_list_array[$listcount]['n_type'] = "$type";
            $news_list_array[$listcount]['n_is_sponsored'] = "0";
            $news_list_array[$listcount]['n_share_link'] = "$firebase_url";
            $news_list_array[$listcount]['n_title'] = "$title";
            $news_list_array[$listcount]['n_short_desc'] = "$field_story_kicker_text_value";
            $news_list_array[$listcount]['n_pcategory_id'] = "$field_primary_category_value";
            $news_list_array[$listcount]['n_pcategory_name'] = "$term_name";
            $news_list_array[$listcount]['n_rating'] = "";
            $news_list_array[$listcount]['n_comment_count'] = "$comment_cont";
            if ($type == "photogallery") {
                $node_data = node_load($nid);

                $img_data = $node_data->field_gallery_image['und'][0];
                $fc = field_collection_field_get_entity($img_data);

                //echo "<pre>"; print_r($fc);  echo "</pre>"; exit();
                $fid = $fc->field_api_image['und'][0]['fid'];
                $uri = $fc->field_images['und'][0]['filename'];
                $source_data = $node_data->field_story_source_type['und'][0]['value'];
                if ($source_data != "migrated") {
                    $photo_story_eliimg = image_style_url('photo_slider_753x543', $uri);
                    $photo_story_liimg = image_style_url('photo_slider_483x271', $uri);
                    $photo_story_siimg = image_style_url('photo_landing_slider_thumb_88x66', $uri);
                    $photo_story_eliimg = str_replace("http://itgdrapid.indiatodayonline.in/s3/files", "http://itgd-mum-dev-static.s3.ap-south-1.amazonaws.com/s3fs-public", $photo_story_eliimg);
                    $photo_story_liimg = str_replace("http://itgdrapid.indiatodayonline.in/s3/files", "http://itgd-mum-dev-static.s3.ap-south-1.amazonaws.com/s3fs-public", $photo_story_liimg);
                    $photo_story_siimg = str_replace("http://itgdrapid.indiatodayonline.in/s3/files", "http://itgd-mum-dev-static.s3.ap-south-1.amazonaws.com/s3fs-public", $photo_story_siimg);
                    $news_list_array[$listcount]['n_small_image'] = "$photo_story_siimg";
                    $news_list_array[$listcount]['n_large_image'] = "$photo_story_eliimg";
                    $news_list_array[$listcount]['n_extralarge_image'] = "$photo_story_eliimg";
                } else {
                    $news_list_array[$listcount]['n_small_image'] = "$file_small_img_url";
                    $news_list_array[$listcount]['n_large_image'] = "$file_large_img_url";
                    $news_list_array[$listcount]['n_extralarge_image'] = "$file_ext_large_img_url";
                }
            } else {
                $news_list_array[$listcount]['n_small_image'] = "$file_small_img_url";
                $news_list_array[$listcount]['n_large_image'] = "$file_large_img_url";
                $news_list_array[$listcount]['n_extralarge_image'] = "$file_ext_large_img_url";
            }
            $news_list_array[$listcount]['n_updated_datetime'] = "$changed_datetime";

            // photo list array

            if ($type == "photogallery") {
                $photolist = getPhotolist($nid);
            }
            if (count($photolist) == 0) {
                $photolist = (object) $photolist;
            }
            $news_list_array[$listcount]['n_photo'] = $photolist;
            // re-insalize photolist
            $photolist = array();

            // video list array
            if ($type == "videogallery") {
                $videolist = getVideolist($nid);
            }
            if (count($videolist) == 0) {
                $videolist = (object) $videolist;
            }
            $news_list_array[$listcount]['n_video'] = $videolist;
            // re-insalize vediolist
            $videolist = array();

            $listcount++;
        }
    }

    $data['lcount'] = $listcount;
    $data['data'] = $news_list_array;
    $data['updated_datetime'] = $changed_datetime;
    return $data;
}

/**
 * function for generate getPhotolist array
 *
 * @return array
 */
function getPhotolist($nid) {
    // variable decalaration
    $photolist = array();
    $photolist_loop = array();
    $node = node_load($nid);
    $galleryimg = $node->field_gallery_image['und'];
    $lcont = 0;
    foreach ($galleryimg as $key => $value) {

        /*$fc = field_collection_field_get_entity($value);
        $fid = $fc->field_api_image['und'][0]['fid'];
        $fid_file = $fid;
        $img_url = completeFilePath($fid_file);
        // custom function for get img caption
        $caption = getImgCaption($fid);
        // custom function for get img byline
        $byline = getImgByline($fid);*/
       $fc = field_collection_field_get_entity($value);        
      //echo "<pre>"; print_r($fc);  echo "</pre>"; exit();
      $fid = $fc->field_image_id['und'][0]['value'];
      if(!$fid > 0){
                $fid = $fc->field_images['und'][0]['fid'];
            }
      $uri = $fc->field_images['und'][0]['filename'];
      $file_uri = file_create_url($uri);
      //$file_uri_fi = field_data_field_story_large_image($file_uri);
      $fid_file = $fid;
      $img_url = completeFilePath($fid_file);
      // custom function for get img caption
      //$caption = getImgCaption($fid);
      $caption = $fc->field_image_caption['und'][0]['value'];
      // custom function for get img byline
      //$byline = getImgByline($fid);
      $byline = $fc->field_credit['und'][0]['value'];
      $photo_story_img = image_style_url('photo_slider_753x543', $uri);
      $photo_story_img = str_replace("http://itgdrapid.indiatodayonline.in/s3/files","http://itgd-mum-dev-static.s3.ap-south-1.amazonaws.com/s3fs-public",$photo_story_img);

        $photolist_loop[$lcont]['np_id'] = "$fid";
        $photolist_loop[$lcont]['np_image'] = "$photo_story_img";
        $photolist_loop[$lcont]['np_credit'] = "$byline";
        $photolist_loop[$lcont]['np_caption'] = "$caption";
        $lcont++;
    }
    $photolist['photos'] = $photolist_loop;
    return $photolist;
}

/**
 * function for generate getVideolist array
 *
 * @return array
 */
 function getVideolist($nid){
     // variable declaration
     $videolist = array();

     // select node belong from current nid


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
     $query->leftJoin('field_data_field_story_syndication', 'fss', 'fss.entity_id=n.nid');
     $query->leftJoin('field_data_field_story_reporter', 'fsr', 'fsr.entity_id=n.nid');
     $query->leftJoin('field_data_field_video_upload', 'fvu', 'fvu.entity_id=n.nid');
     $query->leftJoin('field_data_field_story_source_type','st','st.entity_id = n.nid');

     $query->fields('eli_file', array('uri'));
     $query->fields('li_file', array('uri'));
     $query->fields('mi_file', array('uri'));
     $query->fields('si_file', array('uri'));
     $query->fields('esi_file', array('uri'));

     $query->fields('mi', array('field_story_medium_image_fid'));
     $query->fields('li', array('field_story_large_image_fid'));
     $query->fields('si', array('field_story_small_image_fid'));
     $query->fields('rc', array('field_common_related_content_value'));
     $query->fields('st',array('field_story_source_type_value'));

     $query->fields('kt', array('field_story_kicker_text_value'));
     $query->fields('vd', array('field_video_duration_value'));
     $query->fields('n', array('nid', 'title', 'created', 'type', 'uid'));
     $query->fields('fss', array('field_story_syndication_value'));
     $query->fields('fsr', array('field_story_reporter_target_id'));
     $query->fields('fvu', array('field_video_upload_value'));
     $query->condition('n.nid', $nid);
     $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
     foreach ($result as $reskey => $resvalue) {

         // node feed tag


       $title = $resvalue['title'];
       $type = $resvalue['type'];
       $nid = $resvalue['nid'];
       $created = $resvalue['created'];
       $changed = $resvalue['changed'];
       $nv_cont = getNodeViewCount($nid);
       $field_story_kicker_text_value = $resvalue['field_story_kicker_text_value'];
       $alias = drupal_get_path_alias('node/'.$nid.'');
       $weburl = $base_url ."/". $alias;
       $field_video_duration_value = $resvalue['field_video_duration_value'];
       // file url
       $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
       $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);
       $file_large_img_url = completeFilePath($resvalue['field_story_large_image_fid']);

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

       //display all the video sounce check and format
       $source_type = $resvalue['field_story_source_type_value'];
       $videotag = video_detail_formats($resvalue['nid'], $source_type);
       $filesize = $videotag['dailymotion']['filsize'];

       // create date formating
       $firebase_url = get_node_firebase_weburl($nid);

       if($created){
         $create_datetime = date("Y-m-d H:i:s", $created);
         $create_date = date("F d, Y", $created);
       }
       else{
           $create_datetime = "";
           $create_date = "";
       }
       if($changed){
         $changed_datetime = date("Y-m-d H:i:s", $changed);
       }
       else{
           $changed_datetime = "";
       }

         $videolist['nv_id'] = "$nid";
         $videolist['nv_title'] = "$title";
         $videolist['nv_credit'] = "$reporter_node";
         $videolist['nv_byline'] = "$reporter_node";
         $videolist['nv_short_desc'] = "$field_story_kicker_text_value";
         $videolist['nv_small_image'] = "$file_small_img_url";
         $videolist['nv_large_image'] = "$file_large_img_url";

        if (!empty($videotag['dailymotion'])) {
             $videolist['nv_is_jwplayer'] = "1";
             $videolist['nv_url'] = $videotag['dailymotion']['video_id'];
             $videolist['nv_download_url'] = "";
         }elseif(!empty($videotag['migrated'])){
             $videolist['nv_is_jwplayer'] = "0";
             $videolist['nv_url'] = "";
             $videolist['nv_download_url'] = $videotag['migrated']['video_path_mp4'];
         }
         $videolist['nv_view_count'] = "$nv_cont";
         $videolist['nv_comment_count'] = "";
         $videolist['nv_share_url'] = "$firebase_url";
         $videolist['nv_updated_datetime'] = "$changed_datetime";
         $videolist['nv_duration'] = "$field_video_duration_value";
         $videolist['nv_show_ad'] = "0";

     }

     return $videolist;

 }
 
/**
 * function for generate getViewCount
 * @pram $nid
 * @return $nv_count
 */
function getNodeViewCount($nid) {

      $node_anyalytics = analytics_node_data($nid,'array');
      $nv_count = $node_anyalytics['node_view_count'];
      return $nv_count;
}

/*
 * function to count the share of a node
 * @param $nid
 * @return $share_count
 */

function getNodeShareCount($nid) {

     $node_anyalytics = analytics_node_data($nid,'array');
     $ns_count = $node_anyalytics['data_count_node_share'];
     return $ns_count;
}

/*
 * Count the node share, comment , view etc
 * @args $nid
 * $type 'total' will return the count of it
 * @return an Associated array with count all these values.
 */

function analytics_node_data($nid, $total) {

    if (function_exists('mongodb')) {
        $con = mongodb();
        $analytics_data_array = array();
        $data_count_node_view = array();
        $data_count_node_like = array();
        $data_count_node_comment = array();
        $data_count_node_share = array(
            'facebook_share' => 0,
            'twitter_share' => 0,
            'google_share' => 0,
        );
        $data_count_node_share_number = 0;
        $final_count_result = 0;
        $current_time_stamp = time();
        $timestamp_24_hour_before = strtotime('-24 hours', $current_time_stamp);
        if ($con) {
            // Query to get node views count START.
            $pagedetails_collection = $con->pagedetails;
            $condition = array('nid' => "$nid");
            $result = $pagedetails_collection->find($condition);
            foreach ($result as $document) {
                $data_count_node_view[] = $document['nid'];
            }
            $analytics_data_array['node_view_count'] = count($data_count_node_view);
            //END.
            // Query to get node like count START
            $count_collection = $con->itg_custom_flag_count;

            // Appended 0 as in mongo database 0 is going.
            $count_condition = array('nid' => "0$nid", 'timestamp' => array('$gte' => $timestamp_24_hour_before, '$lte' => $current_time_stamp));
            $count_result = $count_collection->find($count_condition);
            foreach ($count_result as $count_document) {
                $data_count_node_like = $count_document['like_count'];
            }
            $analytics_data_array['data_count_node_like'] = $data_count_node_like;
            //END
            //Query to get comment count of node START.
            $comment_count = $con->itgcms_comment;
            $comment_condition = array('page_id' => "$nid", 'timestamp' => array('$gte' => $timestamp_24_hour_before, '$lte' => $current_time_stamp));
            $comment_count_result = $comment_count->find($comment_condition);

            foreach ($comment_count_result as $comment_document) {
                $data_count_node_comment[] = $comment_document['nid'];
            }

            $analytics_data_array['data_count_node_comment'] = count($data_count_node_comment);
            // Now add vukkle comments count.
            $analytics_data_array['data_count_node_comment'] = $analytics_data_array['data_count_node_comment'] + _get_vukkle_comment_count($nid);
            // END
            //Query to get number of share START
            $front_user_activity = $con->front_user_activity;
            $front_user_activity_condition = array('nid' => "$nid", 'timestamp' => array('$gte' => $timestamp_24_hour_before, '$lte' => $current_time_stamp));
            $front_user_activity_result = $front_user_activity->find($front_user_activity_condition);

            foreach ($front_user_activity_result as $front_user_activity_document) {
                if ($front_user_activity_document['activity'] == 'twitter_share') {
                    $data_count_node_share['twitter_share'] = $data_count_node_share['twitter_share'] + 1;
                }

                if ($front_user_activity_document['activity'] == 'google_share') {
                    $data_count_node_share['google_share'] = $data_count_node_share['google_share'] + 1;
                }

                if ($front_user_activity_document['activity'] == 'facebook_share') {
                    $data_count_node_share['facebook_share'] = $data_count_node_share['facebook_share'] + 1;
                }
            }
            // Add all share data.
            $data_count_node_share_number = $data_count_node_share['twitter_share'] + $data_count_node_share['google_share'] + $data_count_node_share['facebook_share'];

            $analytics_data_array['data_count_node_share'] = $data_count_node_share_number;
            //END
        }

        if ($total == 'total') {
            // return the total count
            // Caculate sum of all data.
            foreach ($analytics_data_array as $counting) {
                if (is_int($counting)) {
                    $final_count_result = $final_count_result + $counting;
                }
            }
            return $final_count_result;
        } else {
            // return the associated Array
            return $analytics_data_array;
        }
    }
}
