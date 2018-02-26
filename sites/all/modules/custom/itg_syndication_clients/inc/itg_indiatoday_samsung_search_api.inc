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
        $img_info = getInfoData($large_image_fid);
        $image_courtesy = $img_info['image_courtesy'];
        $image_caption = $img_info['image_caption'];
        $caption = $node->field_story_extra_large_image['und'][0]['title'];
        $body = $node->body['und'][0]['value'];
        $firebase_url = get_node_firebase_weburl($nid);
        $changed = $node->changed;
        if ($changed) {
            $changed_datetime = date("Y-m-d H:i:s", $changed);
        }
        $video_list[$loopc]['v_id'] = "$nid";
        $video_list[$loopc]['v_title'] = "$title";
        $video_list[$loopc]['v_credit'] = "$image_courtesy";
        $video_list[$loopc]['v_byline'] = "$image_caption";
        $video_list[$loopc]['v_desc'] = "$body";
        $video_list[$loopc]['v_small_image'] = "$extra_large_image";
        $video_list[$loopc]['v_large_image'] = "$extra_large_image";
        $video_list[$loopc]['v_download_url'] = "$firebase_url";
        $video_list[$loopc]['v_updated_datetime'] = "$changed_datetime";
        $video_list[$loopc]['v_duration'] = "";
        $video_list[$loopc]['v_show_ad'] = "0"; 
        $loopc++;
    }
    
    
    return $video_list;
    
}