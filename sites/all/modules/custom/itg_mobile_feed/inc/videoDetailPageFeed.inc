<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate videoDetailPage xml feed
 *
 * @return array
 */
function videoDetailPageFeed() {
  $output = "";

  if (count(arg()) < 2) {
    $output = "Please pass video node nid in url";
  }
  else {
    $output = generateVideoDetailPageFeed(arg(1));
  }


  echo $output; die();
}

/**
 * function for generate generateVideoDetailPageFeed xml feed file
 *
 * @return array
 */
function generateVideoDetailPageFeed($nid, $file_name='', $term_feed_path='', $type) {
  //echo print_ar(arg());exit();

  //$nid = 571;
  //$nid = 461;
  $imgtag = "";


  if(!$file_name){
      $file_name = "video".$nid.".xml";
  }
  if(!$term_feed_path){
    $term_feed_path = getcwd() . "/sites/default/files/xml_it/videos";
    //$term_feed_path = "public://xml_it/videos";
    //file_prepare_directory($term_feed_path, FILE_CREATE_DIRECTORY);
  }
   elseif($type){
     if($type == "photogallery"){
          $term_feed_path = getcwd() . "/sites/default/files/xml_it/photos";
          //$term_feed_path = "public://xml_it/photos";
	 //file_prepare_directory($term_feed_path, FILE_CREATE_DIRECTORY);
     }

     elseif($type == "story"){
         $term_feed_path = getcwd() . "/sites/default/files/xml_it/stories";
          //$term_feed_path = "public://xml_it/stories";
	 //file_prepare_directory($term_feed_path, FILE_CREATE_DIRECTORY);
     }
     elseif($type == "videogallery"){
         $term_feed_path = getcwd() . "/sites/default/files/xml_it/videos";
         //$term_feed_path = "public://xml_it/videos";
	 //file_prepare_directory($term_feed_path, FILE_CREATE_DIRECTORY);
     }
  }
  //field_image_caption
  $output = "";
  if (!$nid) {
    $output = "Nid is missing";
  }
  else {
    //check into redis
   $redis_key = "itgd_video".$nid;

   $result_get = getRedis($redis_key);


   if($result_get['key_value'] !=""){
       $output = $result_get['key_value'];
      // echo "redis get - ". $output; exit();
   }
   else{
    //$output = "video detail page";

    global $base_url;
    $ttl = 300;
    $node = node_load($nid);
    //print_ar($node); exit();
    $title = $node->title;
    $tid = $node->field_primary_category['und'][0]['value'];
    $term = taxonomy_term_load($tid);
    $term_name = $term->name;
    $comment_cont = $node->comment;
    $byline_id = $node->field_story_reporter[LANGUAGE_NONE][0]['target_id'];
    $reporter_node = itg_common_get_node_title($byline_id);
    $related_node = relatedContentNodeType($nid, "videogallery");
    $city = getCityByNid($nid);
    //$weburl = $base_url . "/node/" . $nid;
    $alias = drupal_get_path_alias('node/'.$nid.'');
    $weburl = $base_url ."/". $alias;
    $create_date = date("F d, Y", $node->created);
    $create_datetime = date(DATE_ATOM, $node->created);
    $thumbimage = completeFilePath($node->field_story_medium_image['und'][0]['fid']);
    $is_fav = getNidIsFavorite($nid);
    $syndications = getNidIsSyndications($nid);
    $field_video_upload = $node->field_video_upload['und'][0]['value'];
    $file_id = file_usage($field_video_upload);

    $load_collection = field_collection_item_load($field_video_upload);
    $daily_motion_fid = $load_collection->field_videogallery_video_upload['und'][0]['fid'];

    // get video path
    $video_path_info = videoCheckExistFile($daily_motion_fid, $nid, $field_video_upload);
    $metatags_title = $node->metatags;
    $metatags_description = $node->description;

    //call function getMobileFeedXmlHeader
    $output .= getMobileFeedXmlHeader();
    $output .= "<item><videoid>" . $nid . "</videoid><idsection>" . $tid . "</idsection><section><![CDATA[" . $term_name . "]]></section><credit><![CDATA[" . $reporter_node . "]]></credit><date><![CDATA[" . $create_date . "]]></date><datetime><![CDATA[" . $create_datetime . "]]></datetime><title><![CDATA[" . $title . "]]></title><thumbimage><![CDATA[" . $thumbimage . "]]></thumbimage><mediaid></mediaid><uurl></uurl>";

    //get video tag
    $videotag = getVideoTagDetail($video_path_info,$daily_motion_fid);
    if ($videotag) {
      $output .= $videotag;
    }

    $output .= "<create_date><![CDATA[" . $create_date . "]]></create_date><create_datetime><![CDATA[" . $create_datetime . "]]></create_datetime><syndications>" . $syndications . "</syndications><is_favorite>" . $is_fav . "</is_favorite><metakeyword><![CDATA[".$metatags_title."]]></metakeyword><metadescription><![CDATA[".$metatags_description."]]></metadescription><weburl>" . $weburl . "</weburl>";

    //get body img tag
    $imgtag = getImgTagDetail($node);
    if ($imgtag) {
      $output .= $imgtag;
    }else{
       $output .= emptygetImgTagDetail();
    }
    //related node
    if (isset($related_node['nid']) && count($related_node['nid']) > 0) {
      $output .= getRelatedNodeXmlTag($related_node['nid']);
    }else{
        $output .= emptygetRelatedNodeXmlTag();
    }
    //function for get comment xml tag
    if ($comment_cont > 0) {
      $output .= getCommentXmlTag($node);
    }else{
        $output .= emptygetCommentXmlTag();
    }
    //call function getMobileFeedXmlFooter
    $output .= "</item>" . getMobileFeedXmlFooter();
    // set into redis
    $result_set = setRedis($redis_key, $output, $ttl);
    //echo "redis set - ". $result_set['set_flag']; exit();
  }
}



  if($output){
        $return_flag .= writeFeedFile($term_feed_path, $file_name, $output);
    }
    else{
        $return_flag .="Nid is missing";
    }

  return $return_flag;
//header('Content-Type: application/xml; charset=utf-8');
//echo $output; exit();
}


function all_video_format($file_id){
	//$fid = '664';
	$query = db_select('dailymotion_response_details', 'avf');
	$query->innerJoin('itg_video_bitrates_data','dma','dma.video_id = avf.video_id');
	$query->fields('dma',array('responce'));
	$query->condition('avf.fid',$file_id);
	$all_result = $query->execute()->fetchField();
	return $all_video_data = json_decode($all_result,TRUE);
}

/**
 * function for generate video xml tag
 *
 * @return array
 */
function getVideoTagDetail($video_path_info,$file_id = NULL) {
    //print_r($video_path_info);exit();
    $output = "";
    $video_path_mp4 = $video_path_info['video_path_mp4'];
    $filesize = $video_path_info['filesize'];

    $flv_url = str_replace(".mp4",".flv",$video_path_mp4);
    $videoparts_3gp = str_replace(".mp4",".3gp",$video_path_mp4);

//to get the video of all the other formats
    $video_formats = all_video_format($file_id);

    if($video_path_info['dailymtion_flag'] == "yes"){

        $output .= "<videoparts><part>".$videoparts_3gp."</part></videoparts><size_364bit>".$filesize."</size_364bit><videoparts_mp4><part>".$video_path_mp4."</part></videoparts_mp4><videoparts_m3u8><part>".$video_formats['stream_h264_hd_url']."</part></videoparts_m3u8><flvvideoparts><part>".$video_formats['stream_h264_hq_url']."</part></flvvideoparts><videoparts_3gp><part>".$video_formats['stream_h264_ld_url']."</part></videoparts_3gp>";
    }
    else{
        $flv_url = str_replace(".mp4",".flv",$video_path_mp4);
        $videoparts_3gp = str_replace(".mp4",".3gp",$video_path_mp4);
        $output .= "<videoparts><part>".$videoparts_3gp."</part></videoparts><size_364bit>".$filesize."</size_364bit><videoparts_mp4><part>".$video_path_mp4."</part></videoparts_mp4><videoparts_m3u8><part>".$videoparts_3gp."</part></videoparts_m3u8><flvvideoparts><part>".$flv_url."</part></flvvideoparts><videoparts_3gp><part>".$videoparts_3gp."</part></videoparts_3gp>";
    }
    return $output;
}

/**
 * function for generate image xml tag
 *
 * @return array
 */
function getImgTagDetail($node) {
  //print_ar($node, "getImgTag");exit();
  $field_story_small_image = $node->field_story_small_image['und'][0]['fid'];
  $field_story_medium_image = $node->field_story_medium_image['und'][0]['fid'];
  $highres = completeFilePath($field_story_small_image);
  // custom function for get img caption
  $caption = getImgCaption($field_story_small_image);
  $imgtag = "";
  $imgtag = "<bodyimages><image><lowres><![CDATA[".$highres."]]></lowres><highres><![CDATA[".$highres."]]></highres><caption>".$caption."</caption></image></bodyimages>";


  return $imgtag;
}

/**
 * function for generate Empty image xml tag
 *
 *
 */
function emptygetImgTagDetail() {

  $imgtag = "";
  $imgtag = "<bodyimages><image><lowres><![CDATA[]]></lowres><highres><![CDATA[]]></highres><caption></caption></image></bodyimages>";
  return $imgtag;
}


/**
 * Function check file id
o filename
 * @param $fid
 * @return string
 */
function file_usage($id){
  $ids = "";
  $query = db_select('file_usage', 'fu');
  $query->condition('fu.id', $id);
  $query->fields('fu', array('fid'));
  $results = $query->execute()->fetchAll();
  $ids = $results[0]->fid;
  //echo $ids; exit();
  return $ids;
}

/**
 * Function check exist video filename
 * @param $fid
 * @return string
 */
function videoCheckExistFile($fid, $nid, $field_video_upload) {
  //echo "hi".$fid; exit();
  $video_path_info = array();
  $dailymtion_flag = "no";
  $filesize = "";
  $query = db_select('file_managed', 'fm');
  $query->condition('fm.fid', $fid);
  $query->fields('fm', array('filename', 'uri', 'filemime', 'filesize', 'status'));
  $query->orderBy('fm.fid', 'DESC');
  $query->range(0, 1);
  $results = $query->execute()->fetchAll();
  //print_ar($results); exit();
  $uri = $results[0]->uri;
  $filename = $results[0]->filename;
  $filesize = $results[0]->filesize;

  // for daily motion vedio
  if(strpos($uri,'dailymotion_video_dir') !== false){
      $dailymotion_path = getDailymotionPath($fid, $filename);
      $dailymtion_flag = "yes";
  }
  else{
        //field_video_upload[und][0][field_migrated_video_url][und][0][value]
        $query = db_select('field_data_field_migrated_video_url', 'fmv');
        $query->condition('fmv.entity_id', $field_video_upload);
        $query->fields('fmv', array('field_migrated_video_url_value'));
        $results = $query->execute()->fetchAll();
        //print_ar($results); exit();
        $uri = $results[0]->field_migrated_video_url_value;
        $dailymtion_flag = "no";
        $dailymotion_path = $uri;
  }

  $video_path_info['dailymtion_flag'] = $dailymtion_flag;
  $video_path_info['video_path_mp4'] = $dailymotion_path;
  $video_path_info['filesize'] = $filesize;


  return $video_path_info;


}

/**
 * Function get dailymotion video path
 * @param $fid
 * @return string
 */

function getDailymotionPath($fid, $filename){
  //echo "hi".$fid; exit();
  $query = db_select('dailymotion_response_details', 'drd');
  $query->condition('drd.name', $filename);
  $query->fields('drd', array('title', 'channel', 'type', 'video_id', 'video_duration', 'dailymotion_thumb_url', 'name', 'upload_time'));
  $results = $query->execute()->fetchAll();
  $channel = $results[0]->channel;
  $video_id = $results[0]->video_id;
  $dailymotion_thumb_url = $results[0]->dailymotion_thumb_url;
  $name = $results[0]->name;
  $ext = pathinfo($name, PATHINFO_EXTENSION);
  $type = $results[0]->type;
  $filename_ar = explode(".",$filename);
  $final_filename = $filename_ar[0];
  $final_filename = str_replace("_","-",$final_filename);


  //$video_path = "https://www.dailymotion.com/video/".$video_id."_public-dailymotion-".$type."-".$final_filename."-".$ext."_".$channel."";
  $video_path = "https://www.dailymotion.com/video/".$video_id."";
  return $video_path;
}
