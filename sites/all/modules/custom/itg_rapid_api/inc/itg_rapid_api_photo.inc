<?php
/**
 * Inc file contains the functions
 */

/**
 * main function for generate photoCategoryPage array
 *
 * @return array
 */


function photocategoryPageRerourceValue($tid = 0, $pageno = 0) {
    
  
    // variable decalartion
    
    $output_array = array();
    $data_array = array();
    $photo_list_array = array();      
    $updated_datetime = "";
    
    $term = taxonomy_term_load($tid);
    $term_name = $term->name;   
    
    // list array building
    $data = generatePhotoCategoryList($tid, $pageno);
    
    if($data['lcount'] > 0){
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";  
    }
 else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";  
    }
    
    //data array building
     $datacount = $data['lcount'];
     $data_up_time = $data['updated_datetime'];
    
    $data_array['id'] = "$tid";
    $data_array['title'] = "$term_name";
    $data_array['layout_id'] = "1";
    $data_array['photo_count'] = "$datacount";
    $data_array['photo_display_count'] = "10";
    $data_array['photo_pagination_cap'] = "7";
    $data_array['updated_datetime'] = "$data_up_time";
    
    $data_array['photo'] = $data['data'];
    $output_array['data'] = $data_array;
    
    return $output_array;
}


/**
 * function for generate photoCategoryPage xml feed
 *
 * @return array
 */
function generatePhotoCategoryList($tid, $pageno) {
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
  $type = "photogallery";
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
    $query->condition('n.status', 1)->condition('n.type', $type)->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    foreach ($result as $reskey => $resvalue) {
//echo "<pre>";  print_r($resvalue);echo "</pre>"; exit();
      // node feed tag
      $listcount++;

      $title = $resvalue['title'];
      $type = $resvalue['type'];
      $nid = $resvalue['nid'];
      $created = $resvalue['created'];
      $changed = $resvalue['changed'];
      $comment_cont = getCommentsCount($nid);
      $node = node_load($nid);
      $galleryimg = $node->field_gallery_image['und'];
      $toptlapics = count($galleryimg);
      $field_gallery_image = $resvalue['field_gallery_image'];
      $field_gallery_image_cont = count($field_gallery_image);
      //$weburl = $base_url . "/node/" . $nid;
      $alias = drupal_get_path_alias('node/'.$nid.'');
      $weburl = $base_url ."/". $alias;
      // file url
      $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
      $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);

      //related content
      $related = relatedContentNodeType($resvalue['field_common_related_content_value']);

      // create date formating
      
      $create_date = date("Y-m-d H:i:s", $created);
      $changed_datetime = date("Y-m-d H:i:s", $changed);
      // photo detail for listing
       $photo_list_array[$loop_count]['p_id'] = "$nid";
       $photo_list_array[$loop_count]['p_title'] = "$title";
       $photo_list_array[$loop_count]['p_small_image'] = "$file_small_img_url";
       $photo_list_array[$loop_count]['p_large_image'] = "$file_medium_img_url";
       $photo_list_array[$loop_count]['p_count'] = "$toptlapics";
       $photo_list_array[$loop_count]['p_comment_count'] = "$comment_cont";
       $photo_list_array[$loop_count]['p_share_link'] = "Universal link";
       $photo_list_array[$loop_count]['p_updated_datetime'] = "$changed_datetime";
       $loop_count++;
    }
  }
  $data['lcount'] = $listcount;
  $data['data'] = $photo_list_array;
  $data['updated_datetime'] = $changed_datetime;
  
  
  return $data;
}

/**
 * main function for generate photoDetailPage array
 *
 * @return array
 */

function photoDetailPageRerourceValue($id){
    // variable decalartion
    
    // variable decalartion
    
    $output_array = array();
    $data_array = array();
    $photo_list_array = array();
       
    
    // list array building
    $data = generatePhotoDeatilList($id); 
    if($data['data']['photo_count'] > 0){
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";  
    }
    else{
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";  
    }
    
    $output_array['data'] = $data['data'];
    
    return $output_array;
}

/**
 * function for generate generatePhotoDeatilList JSON
 *
 * @return array
 */

function generatePhotoDeatilList($id){
    // variable declaration    
    global $base_url; 
    $data = array();
    $nid = $id;
    $photo_list_array = array();
    $data_array = array();
    $node = node_load($nid);
    // variable for feed
    $title = $node->title;
    $tid = $node->field_primary_category['und'][0]['value'];
    $term = taxonomy_term_load($tid);
    $term_name = $term->name;
    //$comment_cont = $node->comment;
    $alias = drupal_get_path_alias('node/'.$nid.'');
    $weburl = $base_url ."/". $alias;
    $galleryimg = $node->field_gallery_image['und'];
    $toptlapics = count($galleryimg);
    $changed = $node->changed;
    $changed_datetime = date("Y-m-d H:i:s", $changed);
    $comment_cont = getCommentsCount($nid);
    
    //data array building
    
    $data_array['id'] = "$nid";
    $data_array['title'] = "$title";
    $data_array['updated_datetime'] = "$changed_datetime";
    $data_array['subcategory_id'] = "$tid";
    $data_array['subcategory_title'] = "$term_name";
    $data_array['photo_count'] = "$toptlapics";
    $data_array['comment_count'] = "$comment_cont";
    $data_array['share_link'] = "Universal link";
    $galleryimg = $node->field_gallery_image['und'];
    
    // list array building
    $photo_list_array = generatePhotoDetailList($galleryimg);    
    $data_array['photo'] = $photo_list_array;
    
    
    $data['data'] = $data_array;
    return $data;
}

/**
 * function for generate photo list array
 *
 * @return array
 */

function generatePhotoDetailList($galleryimg){
    $photo_list_array = array();
    $listcont = 0;
    if (count($galleryimg) > 0) {
      // loop on gallery img
      $output = "";
      foreach ($galleryimg as $key => $value) {
        //print_ar($value, "getGalleryImgTag");exit();
        $fid = $value['value'];
        $fid_file = $value['revision_id'];
        $img_url = completeFilePath($fid_file);
        // custom function for get img caption
        $caption = getImgCaption($fid);
        // custom function for get img byline
        $byline = getImgByline($fid);
        if(!$byline){
           // $byline = "";
        }
        $photo_list_array[$listcont]['p_id'] = "$fid";
        $photo_list_array[$listcont]['p_image'] = "$img_url";
        $photo_list_array[$listcont]['p_credit'] = "$byline";
        $photo_list_array[$listcont]['p_caption'] = "$caption";
        $listcont++;
      }
  }
  return $photo_list_array;
}