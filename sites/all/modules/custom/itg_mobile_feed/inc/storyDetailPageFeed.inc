<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate storyDetailPage xml feed
 *
 * @return string $output
 */
function storyDetailPageFeed() {
  $output = "";
  if (count(arg()) < 2) {
    $output = "Please pass story node nid in url";
  }
  else {
    $output = generateStoryDetailPageFeed(arg(1));
  }
  echo $output;
  drupal_exit();
}

/**
 * function for generate generateStoryDetailPageFeed xml feed file
 * @pram int $nid
 * @pram string $file_name, $term_feed_path, $type
 *
 * @return string $return_flag
 */
function generateStoryDetailPageFeed($nid, $file_name = "", $term_feed_path = "", $type) {
  $imgtag = "";
  if (!$file_name) {
    $file_name = "story" . $nid . ".xml";
  }
  if (!$term_feed_path) {
    $term_feed_path = "public://xml_it/stories";
  }
  elseif ($type) {
    if ($type == "photogallery") {
      $term_feed_path = "public://xml_it/photos";
    }
    elseif ($type == "story") {
      $term_feed_path = "public://xml_it/stories";
    }
    elseif ($type == "videogallery") {
      $term_feed_path = "public://xml_it/videos";
    }
  }

  //field_image_caption
  $output = "";
  if (!$nid) {
    $output = "Nid is missing";
  }
  else {
    //check into redis
    $redis_key = "itgd_story" . $nid;
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
      $output = $result_get['key_value'];
    }
    else {
      global $base_url;
      $ttl = DEFAULT_REDIS_EXPIRE_TIME;
      $node = node_load($nid);
      $title = html_entity_decode($node->title);
      $tid = $node->field_primary_category['und'][0]['value'];
      $term = taxonomy_term_load($tid);
      $term_name = $term->name;
      $comment_cont = $node->comment;
      $byline_id = $node->field_story_reporter[LANGUAGE_NONE][0]['target_id'];
      $reporter_node = itg_common_get_node_title($byline_id);
      $related_node = relatedContentNodeType($nid, "story");
      $city = getCityByNid($nid);
      $alias = drupal_get_path_alias('node/' . $nid . '');
      $weburl = $base_url . "/" . $alias;
      $create_date = date("F d, Y", $node->created);
      $create_datetime = date(DATE_ATOM, $node->created);
      $full_body = $node->body['und']['0']['value'];
      $body_android = getBodyDataForAndroid($full_body, $node);
      $output .= getMobileFeedXmlHeader();
      $output .= "<item><storyid>" . $nid . "</storyid><idsection>" . $tid . "</idsection><section><![CDATA[" . $term_name . "]]> </section><headline><![CDATA[" . $title . "]]></headline><credit><![CDATA[" . $reporter_node . "]]> </credit><date>$create_date</date><datetime>" . $create_datetime . "</datetime><city><![CDATA[" . $city . "]]></city><courtesy><![CDATA[]]></courtesy>";
      $output .= "<body><![CDATA[" . html_entity_decode($full_body) . "]]></body>";
      $output .= "<body_android><![CDATA[" . $body_android . "]]></body_android>";
      //get video tag
      $videotag = getVideoTag($node);
      if ($videotag) {
        $output .= $videotag;
      }
      else {
        $output .= emptygetVideoTag();
      }
      //get video tag
      $imgtag = getImgTag($node);
      if ($imgtag) {
        $output .= $imgtag;
      }
      else {
        $output .= emptygetImgTag();
      }
      //web url tag
      $output .= "<weburl><![CDATA[" . $weburl . "]]></weburl>";
      if (isset($related_node['nid']) && count($related_node['nid']) > 0) {
        $output .= getRelatedNodeXmlTag($related_node['nid']);
      }
      else {
        $output .= emptygetRelatedNodeXmlTag();
      }
      //function for get comment xml tag
      if ($comment_cont > 0) {
        $output .= getCommentXmlTag($node);
      }
      else {
        $output .= emptygetCommentXmlTag();
      }
      //call function getMobileFeedXmlFooter
      $output .= "</item>" . getMobileFeedXmlFooter();
      $result_set = setRedis($redis_key, $output, $ttl);
    }
  }
  if ($output) {
    $return_flag .= writeFeedFile($term_feed_path, $file_name, $output);
  }
  else {
    $return_flag .= "Nid is missing";
  }

  return $return_flag;
}

/**
 * function for generate video xml tag
 * @pram object $node
 *
 * @return string $videotag
 */
function getVideoTag($node) {
  $videotag = "";
  $src = "";
  $img_url = '';

  $html = html_entity_decode($node->body['und']['0']['value']);
  $doc = new DOMDocument();
  libxml_use_internal_errors(TRUE);
  // loads your html
  $doc->loadHTML($html);
  $xpath = new DOMXPath($doc);
  // find your image
  $nodelist = $xpath->query("//iframe");
  // gets the 1st image
  $node = $nodelist->item(0);
  $iframe_code = getStringBetween($html, '<iframe', '</iframe>');
  $video_path = getStringBetween($iframe_code, 'src="', '"');
  // Migrated video
  if (strpos($video_path, '/embed/')) {
    $encrypted_nid = end(explode("/", $video_path));
    $video_nid = decryptForEmbed($encrypted_nid);
    $node_id = embed_video_nid($video_nid);
    $node = node_load($node_id);
    $source_type = $node->field_story_source_type[LANGUAGE_NONE][0]['value'];
    if (!empty($node->field_story_medium_image['und'][0]['uri'])) {
      $img_url = file_create_url($node->field_story_medium_image['und'][0]['uri']);
    }
    $videotag = video_detail_formats($node->nid, $source_type);
    print_r($videotag);
    // Daily motion video
  }
  elseif (strpos($video_path, '/embeded-video/')) {
    $dailymotion_vid = end(explode("/", $video_path));
    //$daily_motion_video_details = itg_videogallery_get_all_video_info_by_video_id($dailymotion_vid);
    $video_detail = array();
    $video_status = 'dailymotion';
    $query = db_select('itg_video_bitrates_data', 'itgv');
    $query->fields('itgv', array('bitate_url', 'bitates_field'));
    $query->condition('itgv.video_id', $dailymotion_vid);
    $result2 = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $video_format = array();
    foreach ($result2 as $res_data) {
      $video_format[$res_data['bitates_field']] = $res_data['bitate_url'];
    }
    $video_path_mp4 = "https://www.dailymotion.com/embed/video/" . $dailymotion_vid . "";
    $video_format['videoparts_mp4'] = $video_path_mp4;
    $video_detail[$video_status]['bitate_url'] = $video_format;
    $dailymotion_download = dailymotion_download_video_uri($video_id);
    $video_detail[$video_status]['bitate_url']['download_url'] = "$dailymotion_download";
    if (!empty($video_field->field_story_medium_image['und'][0]['uri'])) {
      $img_url = file_create_url($video_field->field_story_medium_image['und'][0]['uri']);
    }
    $videotag = $video_detail;
    //print_r($videotag);
  }

  
  if (!empty($videotag['migrated'])) {
    $videotag = "<video_embed><videoparts_mp4><part>" . $videotag['migrated']['video_path_mp4'] . "</part><img_url><![CDATA[" . $img_url . "]]></img_url></videoparts_mp4><videoparts_m3u8><part>" . $videotag['migrated']['videoparts_m3u8'] . "</part><img_url><![CDATA[" . $img_url . "]]></img_url></videoparts_m3u8></video_embed>";
  }
  elseif (!empty($videotag['dailymotion'])) {
    $videotag = "<video_embed><videoparts_mp4><part>" . $videotag['dailymotion']['bitate_url']['videoparts_mp4'] . "</part><img_url><![CDATA[" . $img_url . "]]></img_url></videoparts_mp4><videoparts_m3u8><part>" . $videotag['dailymotion']['bitate_url']['stream_h264_url'] . "</part><img_url><![CDATA[" . $img_url . "]]></img_url></videoparts_m3u8></video_embed>";
  }
  else {
    $videotag = "<video_embed><videoparts_mp4><part></part><img_url><![CDATA[]]></img_url></videoparts_mp4><videoparts_m3u8><part></part><img_url><![CDATA[]]></img_url></videoparts_m3u8></video_embed>";
  }
  return $videotag;
}

/**
 * Function for getting dailymotion videoname to nid
 * @pram string $video_name
 *
 * @return string $qry
 */
function dailymotion_video_name_to_nid($video_name) {
  $qry = db_select('dailymotion_response_details', 'vd')->fields('vd', array('nid'))->condition('vd.title', $video_name)->execute()->fetchField();
  return $qry;
}

/**
 * Get Nid by migrated video name
 * @pram string $video_uri
 *
 * @return array $all_result
 */
function migrated_video_to_nid($video_uri) {

  $query = db_select('field_data_field_migrated_video_url', 'mv');
  $query->innerJoin('field_data_field_video_upload', 'vo', 'vo.field_video_upload_value = mv.entity_id');
  $query->fields('vo', array('entity_id'));
  $query->condition('mv.field_migrated_video_url_value', $video_uri);
  return $all_result = $query->execute()->fetchField();
}

/**
 * function uploaded_video_to_nid
 * @pram string $video_uri
 *
 * @return array $all_result
 */
function uploaded_video_to_nid($video_uri) {

  $query = db_select('file_managed', 'f');
  $query->innerJoin('field_data_field_videogallery_video_upload', 'vp', 'vp.field_videogallery_video_upload_fid = f.fid');
  $query->innerJoin('field_data_field_video_upload', 'vo', 'vo.field_video_upload_value = vp.entity_id');
  $query->fields('vo', array('entity_id'));
  $query->condition('f.uri', $video_uri);
  return $all_result = $query->execute()->fetchField();
}

/**
 * Get string betwee tags
 * @pram string $str, $from, $to
 *
 * @return string
 */
function getStringBetween($str, $from, $to) {

  $sub = substr($str, strpos($str, $from) + strlen($from), strlen($str));
  return substr($sub, 0, strpos($sub, $to));
}

/**
 * function for generate Empty video xml tag
 *
 * @return string $videotag
 */
function emptygetVideoTag() {
  $videotag = "";
  $videotag = "<video_embed><videoparts_mp4><part></part><img_url><![CDATA[]]></img_url></videoparts_mp4><videoparts_m3u8><part></part><img_url><![CDATA[]]></img_url></videoparts_m3u8></video_embed>";
  return $videotag;
}

/**
 * function for generate empty image xml tag
 *
 * @return string $imgtag
 */
function emptygetImgTag() {
  $imgtag = "";
  $imgtag = "<bodyimages><image><lowres><![CDATA[]]></lowres><highres><![CDATA[]]></highres><caption></caption></image></bodyimages>";
  return $imgtag;
}

/**
 * function for generate image xml tag
 * @pram object $node
 *
 * @return string $imgtag
 */
function getImgTag($node) {
  $imgtag = "";
  $src = "";
  $img_caption_val = "";
  $story_large_fid = $node->field_story_extra_large_image['und'][0]['fid'];
  $story_large_img = completeFilePath($story_large_fid);


  $html = $node->body['und']['0']['value'];
  $doc = new DOMDocument();
  libxml_use_internal_errors(TRUE);
  // loads your html
  $doc->loadHTML($html);
  $xpath = new DOMXPath($doc);
  // find your image
  $nodelist = $xpath->query("//img");
  // gets the 1st image
  $node = $nodelist->item(0);
  if ($node->attributes->length > 0) {
    //It has img
    $src = $node->attributes->getNamedItem('src')->nodeValue;
    //$img_caption_val = getStringBetween($html, '<div class="body_caption">', '</div>');
  }
  $src = "";
  if ($src) {
    $imgtag = "<bodyimages><image><lowres><![CDATA[" . $src . "]]></lowres><highres><![CDATA[" . $src . "]]></highres><caption>" . $img_caption_val . "</caption></image></bodyimages>";
  }
  else {
    $imgtag = "<bodyimages><image><lowres><![CDATA[" . $story_large_img . "]]></lowres><highres><![CDATA[" . $story_large_img . "]]></highres><caption>" . $img_caption_val . "</caption></image></bodyimages>";
  }
  return $imgtag;
}

