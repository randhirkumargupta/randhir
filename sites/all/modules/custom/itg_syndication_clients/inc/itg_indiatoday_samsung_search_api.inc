<?php

/**
 * @file
 * The ITG Syndication clients for samsung search
 */

/**
 * Function itg_indiatoday_samsung_search_api
 * @param str $key
 * @param string $result
 */
function itg_indiatoday_samsung_search_api(){    
    $data = array();
    $video_list = array();
    $video_list = itg_indiatoday_samsung_search_api_video_list();
    $data['status_code'] = 1;
    $data['status_message'] = "Video";
    $data['data']['id'] = "2";
    $data['data']['title'] = "Video";
    $data['data']['video'] = $video_list;
    
     echo json_encode($data);
}
/**
 * 
 */

function itg_indiatoday_samsung_search_api_video_list(){
    $key = arg(2);
    $i_arg = array();
    $i_arg[0] = $key;
    $searchpage = views_get_view_result('front_end_global_search', 'default', $i_arg);     
    $video_list = array();
    $loopc = 0;
    foreach ($searchpage as $key => $value){       
        $nid = $value->entity_id;
        $node = node_load($nid);
        $title = $node->title;
        $extra_large_image = file_create_url($node->field_story_extra_large_image['und'][0]['uri']);
        $field_story_medium_image = file_create_url($node->field_story_medium_image['und'][0]['uri']);
        $img_info = getInfoData2($large_image_fid);
        $image_courtesy = $img_info['image_courtesy'];
        $image_caption = $img_info['image_caption'];
        $caption = $node->field_story_extra_large_image['und'][0]['title'];
        $body = $node->body['und'][0]['value'];
        $firebase_url = 'http://indiatoday.in/'.drupal_get_path_alias('node/'.$nid.'');
        $changed = $node->changed;
        if ($changed) {
            $changed_datetime = date("Y-m-d H:i:s", $changed);
        }
        $video_list[$loopc]['v_id'] = "$nid";
        $video_list[$loopc]['v_title'] = "$title";
        $video_list[$loopc]['v_credit'] = "$image_courtesy";
        $video_list[$loopc]['v_byline'] = "$image_caption";
        $video_list[$loopc]['v_desc'] = "$body";
        $video_list[$loopc]['v_small_image'] = "$field_story_medium_image";
        $video_list[$loopc]['v_large_image'] = "$extra_large_image";
        $video_list[$loopc]['v_download_url'] = "$firebase_url";
        $video_list[$loopc]['v_updated_datetime'] = "$changed_datetime";
        $video_list[$loopc]['v_duration'] = "";
        $video_list[$loopc]['v_show_ad'] = "0"; 
        $loopc++;
    }
    //p($video_list);
    
    return $video_list;
    
}

/**
 * function for get getInfoData
 * @pram int
 *
 * @return array
 */
function getInfoData2($fid) {
  $data = array();
  if ($fid) {
    $query = db_select('image_info', 'iminfo');
    $query->fields('iminfo', array('image_courtesy', 'image_caption', 'image_date'));
    $query->condition('iminfo.fid', $fid, '=');
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    foreach ($result as $k => $res) {
      $data['image_courtesy'] = $res['image_courtesy'];
      $data['image_caption'] = $res['image_caption'];
      $data['image_date'] = $res['image_date'];
    }
  }
  return $data;
}