<?php
/**
 * function for  featuresWidgetData list 
 * @return array
 */
function featuresWidgetData() { 

  $output = "";
  $widget_name = "home_page_feature_widget";
  $range_max = 3;
  $range_min = 0;
  $order_by = 'asc';

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

  $query->fields('kt', array('field_story_kicker_text_value'));
  $query->fields('vd', array('field_video_duration_value'));
  $query->fields('n', array('nid', 'title', 'created', 'type', 'uid'));


  //end
  $query->condition('iwo.widget', $widget_name)->condition('n.status', 1)->orderBy('iwo.weight', $order_by)->orderBy('n.nid', 'DESC')->range($range_min, $range_max)->fields('iwo', array('nid', 'extra', 'weight'));
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result;
 
}
/**
 * function for  topstoriesList
 * @return array
 */
function topstoriesList() {
    // variable declation
    $data_topstories = array();
    $data_newslist = array();
    $n_photo = array();
    $n_video = array();
    $n_polls = array();
    $n_rating = array();
    $home_list_count = 0;
    $widget_name = "top_stories_widget";
    $range_max = 15;
    $range_min = 0;
    $order_by = 'asc';

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
    $result_ts = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $result_fs = featuresWidgetData();
    $result = array_merge($result_fs,$result_ts);

    $data_topstories['id'] = "0";      
    $data_topstories['title'] = "Top Stories";
    $data_topstories['label'] = "Top Stories";
    $data_topstories['show_label'] = "0";    

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

    $data_topstories['data'] = (array) $data_newslist;
    return $data_topstories;
}
