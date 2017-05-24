<?php
/**
 * Inc file contains the functions
 */

/**
 * main function for generate photoCategoryPage array
 *
 * @return array
 */


function videocategoryPageRerourceValue($tid = 0, $pageno = 0) {
    
  
    // variable decalartion
    
    $output_array = array();
    $data_array = array();
    $photo_list_array = array();
    $output_array['status_code'] = 200;
    $output_array['status_message'] = "customised_message";    
    $updated_datetime = "";
    
    $term = taxonomy_term_load($tid);
    $term_name = $term->name;   
    
    // list array building
    $data = generateVideoCategoryList($tid, $pageno);
    
    
    //data array building
    
    $data_array['id'] = $tid;
    $data_array['title'] = $term_name;
    $data_array['layout_id'] = "template_1";
    $data_array['subcategory_id'] = $tid;
    $data_array['subcategory_title'] = $term_name;
    $data_array['video_count'] = $data['lcount'];
    $data_array['video_display_count'] = 10;
    $data_array['video_pagination_cap'] = 7;
    $data_array['updated_datetime'] = $data['updated_datetime'];
    
    $data_array['video'] = $data['data'];
    $output_array['data'] = $data_array;
    
    return $output_array;
}


/**
 * function for generate photoCategoryPage xml feed
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
  if(!$pageno == 0){
      $range_min = $pageno * $range_max;
  }
  else{
    $range_min = 0;
  }
  $order_by = 'ASC';
  $type = "videogallery";
  $photo_list_array = array();
  $loop_count = 0;


{
    $listcount = 0;


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
    $query->leftJoin('field_data_field_story_syndication', 'fss', 'fss.entity_id=n.nid');

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
    $query->fields('fss', array('field_story_syndication_value'));


    //end
    
    if($tid > 0){
        $query->condition('ti.tid', $tid_list, 'IN');
    }
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
      //$weburl = $base_url . "/node/" . $nid;
      $alias = drupal_get_path_alias('node/'.$nid.'');
      $weburl = $base_url ."/". $alias;
      $field_video_duration_value = $resvalue['field_video_duration_value'];
      // file url
      $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
      $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);

      //related content
      $related = relatedContentNodeType($resvalue['field_common_related_content_value']);

      // create date formating
      $create_date = date("F d, Y", $created);
      $create_datetime = date(DATE_ATOM, $created);
      $changed_datetime = date(DATE_ATOM, $changed);
      
        $photo_list_array[$listcount]['v_id'] = $nid;
        $photo_list_array[$listcount]['v_title'] = $title;
        $photo_list_array[$listcount]['v_credit'] = "";
        $photo_list_array[$listcount]['v_byline'] = "";
        $photo_list_array[$listcount]['v_short_desc'] = $field_story_kicker_text_value;
        $photo_list_array[$listcount]['v_small_image'] = $file_small_img_url;
        $photo_list_array[$listcount]['v_large_image'] = $file_medium_img_url;
        $photo_list_array[$listcount]['v_is_default_player'] = 1;
        $photo_list_array[$listcount]['v_url'] = $weburl;
        $photo_list_array[$listcount]['v_download_url'] = "MP4 URL";
        $photo_list_array[$listcount]['v_view_count'] = 0;
        $photo_list_array[$listcount]['v_comment_count'] = 10;
        $photo_list_array[$listcount]['v_share_url'] = "Universal link";
        $photo_list_array[$listcount]['v_updated_datetime'] = $changed_datetime;
        $photo_list_array[$listcount]['v_duration'] = $field_video_duration_value;
        $photo_list_array[0]['v_show_ad'] = 0;
        $photo_list_array[0]['v_video_size'] = 300;
        
        $listcount++;
    }
  }
  
  
  
  $data['lcount'] = $listcount;
  $data['data'] = $photo_list_array;
  $data['updated_datetime'] = $changed_datetime;
  
  
  return $data;
}

