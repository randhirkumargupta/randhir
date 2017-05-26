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
function generateVideoDetailPageFeed($nid, $file_name='', $term_feed_path='') {
  //echo print_ar(arg());exit();

  //$nid = 571;
  //$nid = 461;
  $imgtag = "";
  
  
  if(!$file_name){
      $file_name = "video".$nid.".xml";
  }
  if(!$term_feed_path){
    $term_feed_path = getcwd() . "/sites/all/modules/custom/itg_mobile_feed/xml_it/videos"; 
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
    $related_node = relatedContentNodeType($nid);
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
    // get video path
    $video_path_info = videoCheckExistFile($file_id, $nid);  
    $metatags_title = $node->metatags;
    $metatags_description = $node->description;
    
    //call function getMobileFeedXmlHeader
    $output .= getMobileFeedXmlHeader();
    $output .= "<item><videoid>" . $nid . "</videoid>
                    <idsection>" . $tid . "</idsection>
                    <section><![CDATA[" . $term_name . "]]></section>
                    <credit><![CDATA[" . $reporter_node . "]]></credit>
                    <date><![CDATA[" . $create_date . "]]></date>
                    <datetime><![CDATA[" . $create_datetime . "]]></datetime>
                    <title><![CDATA[" . $title . "]]></title>
                    <thumbimage><![CDATA[" . $thumbimage . "]]></thumbimage>
                    <mediaid></mediaid>
                    <uurl></uurl>";

    //get video tag
    $videotag = getVideoTagDetail($video_path_info);
    if ($videotag) {
      $output .= $videotag;
    }

    $output .= "<create_date><![CDATA[" . $create_date . "]]></create_date>
                    <create_datetime><![CDATA[" . $create_datetime . "]]></create_datetime>
                    <syndications>" . $syndications . "</syndications>
                    <is_favorite>" . $is_fav . "</is_favorite>
                    <metakeyword><![CDATA[".$metatags_title."]]></metakeyword>
                    <metadescription><![CDATA[".$metatags_description."]]></metadescription>
                    <weburl>" . $weburl . "</weburl>";

    //get body img tag
    $imgtag = getImgTagDetail($node);
    if ($imgtag) {
      $output .= $imgtag;
    }
    //related node
    if (isset($related_node['nid']) && count($related_node['nid']) > 0) {
      $output .= getRelatedNodeXmlTag($related_node['nid']);
    }
    //function for get comment xml tag
    if ($comment_cont > 0) {
      $output .= getCommentXmlTag($node);
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
// header('Content-Type: application/xml; charset=utf-8');
//echo $output; exit();
}

/**
 * function for generate video xml tag
 *
 * @return array
 */
function getVideoTagDetail($video_path_info) {
    //print_ar($video_path_info);exit();
    $output = "";
    $video_path_mp4 = $video_path_info['video_path_mp4'];
    $filesize = $video_path_info['filesize'];
    if($video_path_info['dailymtion_flag'] == "yes"){
        
        $output .= "<videoparts>
                        <part></part>
                    </videoparts>
                    <size_364bit>".$filesize."</size_364bit>
                    <videoparts_mp4>
                        <part>".$video_path_mp4."</part>
                    </videoparts_mp4>
                    <videoparts_m3u8>
                        <part></part>
                    </videoparts_m3u8>
                    <flvvideoparts>
                        <part></part>
                    </flvvideoparts>
                    <videoparts_3gp>
                        <part></part>
                    </videoparts_3gp>";
    }
    else{
        $flv_url = str_replace(".mp4",".flv",$video_path_mp4);
        $videoparts_3gp = str_replace(".mp4",".3gp",$video_path_mp4);
        $output .= "<videoparts>
                        <part></part>
                    </videoparts>
                    <size_364bit>".$filesize."</size_364bit>
                    <videoparts_mp4>
                        <part>".$video_path_mp4."</part>
                    </videoparts_mp4>
                    <videoparts_m3u8>
                        <part></part>
                    </videoparts_m3u8>
                    <flvvideoparts>
                        <part>".$flv_url."</part>
                    </flvvideoparts>
                    <videoparts_3gp>
                        <part>".$videoparts_3gp."</part>
                    </videoparts_3gp>";
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
  $imgtag = "\n<bodyimages> 
                    <image>  
                        <lowres><![CDATA[".$highres."]]></lowres>
                        <highres><![CDATA[".$highres."]]></highres>
                        <caption>".$caption."</caption>  
                    </image> 
                </bodyimages>\n";


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
function videoCheckExistFile($fid, $nid) {
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
        $query->condition('fmv.revision_id', $nid);
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
  $query->condition('drd.fid', $fid);
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
  
  
  $video_path = "https://www.dailymotion.com/video/".$video_id."_public-dailymotion-".$type."-".$final_filename."-".$ext."_".$channel."";
  return $video_path;
}

