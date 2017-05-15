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
    
    // list array building
    $data = generateNewsCategoryList($tid, $pageno);
    if($data['lcount'] > 0){
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";  
    }
 else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";  
    }
    $datacount = $data['lcount'];
    $data_up_time = $data['updated_datetime'];
    
    //data array building
    
    $data_array['id'] = "$tid";
    $data_array['title'] = "$term_name";
    $data_array['layout_id'] = "template_1";
    $data_array['news_count'] = "$datacount";
    $data_array['news_display_count'] = "$term_name";
    $data_array['news_pagination_cap'] = "$datacount";
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
  $range_max = 20;
  //$photolist = array();
  if(!$pageno == 0){
      $range_min = $pageno * $range_max;
  }
  else{
    $range_min = 0;
  }
  $order_by = 'ASC';
  $type = array("videogallery", "photogallery", "story");
  //$type = "videogallery, photogallery, story";
  $news_list_array = array();
  $photolist = array();
  $videolist = array();
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
    
    if($tid > 0){
        $query->condition('ti.tid', $tid_list, 'IN');
    }
    $query->condition('n.status', 1)->condition('n.type', $type, 'IN')->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);

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
      $comment_cont = getCommentsCount($nid);

      // create date formating
      $create_date = date("F d, Y", $created);
      $create_datetime = date("Y-m-d H:i:s", $created);
      $changed_datetime = date("Y-m-d H:i:s", $changed);
      
            $news_list_array[$listcount]['n_id'] = "$nid";
            $news_list_array[$listcount]['n_type'] = "$type";
            $news_list_array[$listcount]['n_is_sponsored'] = "0";
            $news_list_array[$listcount]['n_share_link'] = "Universal_link";
            $news_list_array[$listcount]['n_title'] = "$title";
            $news_list_array[$listcount]['n_short_desc'] = "$field_story_kicker_text_value";
            $news_list_array[$listcount]['n_primary_tag'] = "tag_name";
            $news_list_array[$listcount]['n_rating'] = "";
            $news_list_array[$listcount]['n_comment_count'] = "$comment_cont";
            $news_list_array[$listcount]['n_small_image'] = "$file_small_img_url";
            $news_list_array[$listcount]['n_large_image'] = "$file_medium_img_url";
            $news_list_array[$listcount]['n_updated_datetime'] = "$changed_datetime";
            // photo list array
            
            if($type == "photogallery"){
                $photolist = getPhotolist($nid);
            }
            $news_list_array[$listcount]['n_photo'] = $photolist;
            // re-insalize photolist
            $photolist = array();
  
            // video list array
            
            if($type == "videogallery"){
                $videolist = getVideolist($nid);
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

function getPhotolist($nid){
    // variable decalaration
    $photolist = array();
    $photolist_loop = array();
    $node = node_load($nid);
    $galleryimg = $node->field_gallery_image['und'];
    $lcont = 0;
    foreach ($galleryimg as $key => $value) {
        
        $fid = $value['value'];
        $fid_file = $value['revision_id'];
        $img_url = completeFilePath($fid_file);
        // custom function for get img caption
        $caption = getImgCaption($fid);
        // custom function for get img byline
        $byline = getImgByline($fid);
        
        $photolist_loop[$lcont]['np_id'] = "$fid";
        $photolist_loop[$lcont]['np_image'] = "$img_url";
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
    $query->condition('n.nid', $nid);
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
      $create_datetime = date("Y-m-d H:i:s", $created);
      $changed_datetime = date("Y-m-d H:i:s", $changed);
        
        $videolist['nv_id'] = "$nid";
        $videolist['nv_title'] = "$title";
        $videolist['nv_credit'] = "";
        $videolist['nv_byline'] = "";
        $videolist['nv_short_desc'] = "$field_story_kicker_text_value";
        $videolist['nv_small_image'] = "$file_small_img_url";
        $videolist['nv_large_image'] = "$file_medium_img_url";
        $videolist['nv_is_jwplayer'] = "1";
        $videolist['nv_url'] = "$weburl";
        $videolist['nv_download_url'] = "MP4 URL";
        $videolist['nv_view_count'] = "";
        $videolist['nv_comment_count'] = "";
        $videolist['nv_share_url'] = "Universal link";
        $videolist['nv_updated_datetime'] = "$changed_datetime";
        $videolist['nv_duration'] = "$field_video_duration_value";
        $videolist['nv_show_ad'] = "0";
    
    }
    
    return $videolist;
   
}



