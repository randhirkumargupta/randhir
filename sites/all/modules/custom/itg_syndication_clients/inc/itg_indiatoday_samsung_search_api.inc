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
    //$searchpage = views_get_view_result('front_end_global_search', 'page_1', 'india');
    $i_arg = array();
    $i_arg[0] = 'india';
    $searchpage1 = views_get_view_result('front_end_global_search', 'page_1', $i_arg);
   
    p($searchpage1);
    $data = array();
    $video_list = array();
    $video_list = itg_indiatoday_samsung_search_api_video_list();
    $data['status_code'] = 1;
    $data['status_message'] = "Video";
    $data['data']['id'] = "2";
    $data['data']['title'] = "Video";
    $data['data']['video'] = $video_list;
    
     p(json_encode($data));
}
/**
 * 
 */

function itg_indiatoday_samsung_search_api_video_list(){
    $video_list = array();
    $video_list[0]['v_id'] = "1176124";
    $video_list[0]['v_title'] = "Xiaomi Redmi Note 5 Pro Review";
    $video_list[0]['v_credit'] = "Rahul Sethi";
    $video_list[0]['v_byline'] = "Rahul Sethi";
    $video_list[0]['v_desc'] = "<p>Redmi Note 5 Pro is selling at R</p>";
    $video_list[0]['v_small_image'] = "medium-img";
    $video_list[0]['v_large_image'] = "extr-l-img";
    $video_list[0]['v_download_url'] = "url";
    $video_list[0]['v_updated_datetime'] = "2018-02-04 15:02:27";
    $video_list[0]['v_duration'] = "11";
    $video_list[0]['v_show_ad'] = "0";
    
    $video_list[1]['v_id'] = "1176124";
    $video_list[1]['v_title'] = "Xiaomi Redmi Note 5 Pro Review";
    $video_list[1]['v_credit'] = "Rahul Sethi";
    $video_list[1]['v_byline'] = "Rahul Sethi";
    $video_list[1]['v_desc'] = "<p>Redmi Note 5 Pro is selling at R</p>";
    $video_list[1]['v_small_image'] = "medium-img";
    $video_list[1]['v_large_image'] = "extr-l-img";
    $video_list[1]['v_download_url'] = "url";
    $video_list[1]['v_updated_datetime'] = "2018-02-04 15:02:27";
    $video_list[1]['v_duration'] = "11";
    $video_list[1]['v_show_ad'] = "0";
    
    return $video_list;
    
}