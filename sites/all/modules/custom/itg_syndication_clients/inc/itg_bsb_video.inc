<?php

/**
 * @file
 * The ITG Syndication clients for BSB Story
 */
function itg_bsb_video_syndication() {
  $sections = getbsb_client_video_array();
  foreach ($sections as $section_id => $file_name) {
    itg_genrate_bsb_video_syndication($section_id, $file_name);
  }
}

/**
 * menu callback for bsb story syndication
 */
function itg_genrate_bsb_video_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    $section_name = 'Latest Videos';//get_terms_name_by_ids(array($section_id));
//    $section_name = $section_name[0]['name'];
    $type = array('videogallery');
    $query = db_select('node', 'n');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'smi', 'smi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');
    $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_courtesy', 'sc', 'sc.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_source_type', 'sst', 'sst.entity_id=n.nid');


    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('smi', array('field_story_medium_image_fid'));
    $query->fields('ssi', array('field_story_small_image_fid'));
    $query->fields('pc', array('field_primary_category_value'));
    $query->fields('sc', array('field_story_courtesy_value'));
    $query->fields('sst', array('field_story_source_type_value'));


    $query->condition('ti.tid', $section_id, '=');
    $query->condition('n.status', 1);
    $query->condition('n.type', $type, 'IN');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 25);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_bsb_video_syndication_xml($result, $section_id, $section_name);
    $xml_path = 'sites/default/files/bsb/videos/';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

function genrate_bsb_video_syndication_xml($result = NULL, $section_id, $category) {
  $xml = '';
  $xml .= '<Root>';
  $xml .= '<id>1</id>';
  $xml .= '<title>'.$category.'</title>';

  if (!empty($result)) {
    $xml .= '<start_index>0</start_index>';
    $xml .= '<end_index>' . count($result) . '</end_index>';

    foreach ($result as $value) {
      $nid = $value['nid'];
      $video_file_name = 'video' . $nid . '.xml';
      $created_date = date("Y-m-d", $value['created']);
      $created_datetime = date("Y-m-d\TH:i:sP", $value['created']);
      $medium_img = get_image_info_by_fid($value['field_story_medium_image_fid']);
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $related = related_content_node_type($nid, 'videogallery');
      $is_fav = get_nid_is_favorite($nid);
      genrate_video_detail_xml($value, $section_id, $category, $video_file_name, $small_img, $related);

      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<mediumimage><![CDATA[' . $medium_img['imag_url'] . ']]></mediumimage>';
      $xml .= '<thumbimage><![CDATA[' . $small_img['imag_url'] . ']]></thumbimage>';
      $xml .= '<url>' . $video_file_name . '</url>';
      $xml .= '<create_date>' . $created_date . '</create_date>';
      $xml .= '<create_datetime>' . $created_datetime . '</create_datetime>';
      $xml .= '<is_favorite>' . $is_fav . '</is_favorite>';
      $xml .= '<relateds>';
      $xml .= '<photos>' . $related['photos'] . '</photos>';
      $xml .= '<videos>' . $related['videos'] . '</videos>';
      $xml .= '<stories>' . $related['stories'] . '</stories>';
      $xml .= '</relateds>';
      $xml .= '</item>';
    }
  }
  $xml .= '</Root>';
  return $xml;
}

function genrate_video_detail_xml($result, $section_id, $category, $filename, $small_img, $related) {

  global $base_url;
  $nid = $result['nid'];
  $title = $result['title'];
  $primary_cat = get_term_name_by_tid($result['field_primary_category_value']);
  $credit = $result['field_story_courtesy_value'];
  $content_url = $base_url . "/" . drupal_get_path_alias('node/' . $nid);
  $created_date = date("Y-m-d", $result['created']);
  $created_datetime = date("Y-m-d\TH:i:sP", $result['created']);
  $is_fav = get_nid_is_favorite($nid);
  $syndications = get_nid_is_syndications($nid);
  $meta_tags = get_node_metatags_by_nid($nid);
  $meta_title = '';
  $meta_description = '';
  if ($meta_tags) {
    $temp = unserialize($meta_tags['data']);
    $meta_title = $temp['title']['value'];
    $meta_description = $temp['description']['value'];
  }
  $video_xml .= '<Root>';
  $video_xml .= '<videoid>' . $nid . '</videoid>';
  $video_xml .= '<idsection>' . $section_id . '</idsection>';
  $video_xml .= '<section><![CDATA[' . $primary_cat . ']]></section>';
  $video_xml .= '<credit><![CDATA[' . $credit . ']]></credit>';
  $video_xml .= '<date><![CDATA[' . $created_date . ']]></date>';
  $video_xml .= '<datetime><![CDATA[' . $created_datetime . ']]></datetime>';
  $video_xml .= '<title><![CDATA[' . $title . ']]></title>';
  $video_xml .= '<thumbimage><![CDATA[' . $small_img['imag_url'] . ']]></thumbimage>';
  $video_xml .= '<mediaid></mediaid><uurl></uurl>';
  $source_type = $result['field_story_source_type_value'];
  $videotag = video_detail_formats($nid, $source_type);
  
  if (!empty($videotag['migrated'])) { //migrated video
    $video_xml .= "<videoparts><part>" . $videotag['migrated']['videoparts_3gp'] . "</part></videoparts><size_364bit></size_364bit><videoparts_mp4><part>" . $videotag['migrated']['video_path_mp4'] . "</part></videoparts_mp4><videoparts_m3u8><part>" . $videotag['migrated']['videoparts_3gp'] . "</part></videoparts_m3u8><flvvideoparts><part>" . $videotag['migrated']['flv_url'] . "</part></flvvideoparts><videoparts_3gp><part>" . $videotag['migrated']['videoparts_3gp'] . "</part></videoparts_3gp>";
  }
  elseif (!empty($videotag['dailymotion'])) {
    $video_xml .= "<videoparts><part>" . $videotag['dailymotion']['bitate_url']['stream_h264_hq_url'] . "</part></videoparts><size_364bit>" . $videotag['dailymotion']['filsize'] . "</size_364bit><videoparts_mp4><part>" . $videotag['dailymotion']['bitate_url']['videoparts_mp4'] . "</part></videoparts_mp4><videoparts_m3u8><part>" . $videotag['dailymotion']['bitate_url']['stream_h264_url'] . "</part></videoparts_m3u8><flvvideoparts><part>" . $videotag['dailymotion']['bitate_url']['stream_h264_hq_url'] . "</part></flvvideoparts><videoparts_3gp><part>" . $videotag['dailymotion']['bitate_url']['stream_h264_ld_url'] . "</part></videoparts_3gp>";
  }
  $video_xml .= "<create_date><![CDATA[" . $created_date . "]]></create_date><create_datetime><![CDATA[" . $created_datetime . "]]></create_datetime><syndications>" . $syndications . "</syndications><is_favorite>" . $is_fav . "</is_favorite><metakeyword><![CDATA[" . $meta_title . "]]></metakeyword><metadescription><![CDATA[" . $meta_description . "]]></metadescription><weburl>" . $content_url . "</weburl>";

  //get body img tag
  $imgtag = get_img_tag_detail($result);
  if ($imgtag) {
    $video_xml .= $imgtag;
  }
  else {
    $video_xml .= empty_get_img_tag_detail();
  }

  $video_xml .= '<related>';
  $video_xml .= '<stories>';
  if (!empty($related['related_story_xml'])) {
    $video_xml .= $related['related_story_xml'];
  }
  else {
    $video_xml .= get_empty_related_story_tag();
  }

  $video_xml .= '</stories>';

  $video_xml .= '<photos>';
  if (!empty($related['related_photo_xml'])) {
    $video_xml .= $related['related_photo_xml'];
  }
  else {
    $video_xml .= get_empty_related_photo_tag();
  }

  $video_xml .= '</photos>';

  $video_xml .= '<videos>';

  if (!empty($related['related_video_xml'])) {
    $video_xml .= $related['related_video_xml'];
  }
  else {
    $video_xml .= get_empty_related_video_tag();
  }

  $video_xml .= '</videos>';
  $video_xml .= '</related>';
  $video_xml .= get_comment_xml_tag($nid);
  $video_xml .= '</Root>';
  
  $xml_path = 'sites/default/files/bsb/videos/';
  $file_path = $xml_path . $filename;
  $fp = fopen($file_path, "w");
  fwrite($fp, $video_xml);
  fclose($fp);
}

function get_empty_related_story_tag() {
  return "<story><title></title><url></url><thumbimage></thumbimage></story>";
}

function get_empty_related_video_tag() {
  return "<video><title></title><url></url><thumbimage></thumbimage></video>";
}

function get_empty_related_photo_tag() {
  return "<photo><title></title><url></url><thumbimage></thumbimage></photo>";
}

/**
 * common function for return related content node type
 *
 * @return array
 * @pram $type
 */
function related_content_node_type($node_list = "", $type) {
  global $base_url;
  $file_name = "";
  $term_feed_path = "";
  $type_ar = array('photos' => 'NO', 'videos' => 'NO', 'stories' => 'NO');
  $related_ar = array();
  $count = 0;
  $query = db_select('field_data_field_common_related_content', 'frc');
  $query->fields('frc', array('field_common_related_content_value'));
  $query->condition('frc.entity_id', $node_list);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $node_str = $result[0]['field_common_related_content_value'];

  // replace enviroment name: AWS_, UAT_ etc
  $node_str = str_replace("AWS_", "", $node_str);
  $node_str = str_replace("UAT_", "", $node_str);
  $node_str = str_replace("IT_", "", $node_str);
  $node_str = str_replace("|~|", ",", $node_str);

  $nid_list = explode(",", $node_str);
  $query_type = db_select('node', 'n');
  $query_type->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
  $query_type->fields('n', array('type', 'nid', 'title'));
  $query_type->fields('si', array('field_story_small_image_fid'));
  $query_type->condition('n.nid', $nid_list, 'IN');
  $result_type = $query_type->execute()->fetchAll(PDO::FETCH_ASSOC);

  $related_story_xml = '';
  $related_video_xml = '';
  $related_photo_xml = '';
  foreach ($result_type as $reskey => $resvalue) {
    $nid = $resvalue['nid'];
    if ($resvalue['type'] == "story") {
      $type_ar['stories'] = "YES";
      $url = $base_url . "/" . drupal_get_path_alias('node/' . $resvalue['nid']);
      $small_img = get_image_info_by_fid($resvalue['field_story_small_image_fid']);
      $related_story_xml .= '<story>';
      $related_story_xml .= '<title>' . $resvalue['title'] . '</title>';
      $related_story_xml .= '<url>' . $url . '</url>';
      $related_story_xml .= '<thumbimage>' . $small_img['imag_url'] . '</thumbimage>';
      $related_story_xml .= '</story>';
    }
    elseif ($resvalue['type'] == "videogallery") {
      $type_ar['videos'] = "YES";
      $url = $base_url . "/" . drupal_get_path_alias('node/' . $resvalue['nid']);
      $small_img = get_image_info_by_fid($resvalue['field_story_small_image_fid']);
      $related_video_xml .= '<video>';
      $related_video_xml .= '<title>' . $resvalue['title'] . '</title>';
      $related_video_xml .= '<url>' . $url . '</url>';
      $related_video_xml .= '<thumbimage>' . $small_img['imag_url'] . '</thumbimage>';
      $related_video_xml .= '</video>';
    }
    elseif ($resvalue['type'] == "photogallery") {
      $type_ar['photos'] = "YES";
      $url = $base_url . "/" . drupal_get_path_alias('node/' . $resvalue['nid']);
      $small_img = get_image_info_by_fid($resvalue['field_story_small_image_fid']);
      $related_photo_xml .= '<photo>';
      $related_photo_xml .= '<title>' . $resvalue['title'] . '</title>';
      $related_photo_xml .= '<url>' . $url . '</url>';
      $related_photo_xml .= '<thumbimage>' . $small_img['imag_url'] . '</thumbimage>';
      $related_photo_xml .= '</photo>';
    }
    $count++;
  }
  $type_ar['nid'] = $related_ar;
  $type_ar['related_story_xml'] = $related_story_xml;
  $type_ar['related_video_xml'] = $related_video_xml;
  $type_ar['related_photo_xml'] = $related_photo_xml;
  return $type_ar;
}

/*
 * All video format responce
 * @param $nid
 * @return the details video xml tags
 */

function video_detail_formats($nid, $source_type) {

  $video_detail = array();

  if ($source_type != 'migrated') {
    $video_status = 'dailymotion';
    $videoids = get_video_in_fieldcollection_by_nid($nid);

    foreach ($videoids as $keys => $video_value) {
      if ($video_value->video_id != '') {
        $video_id = $video_value->video_id;
      }
      elseif ($video_value->solr_video_id != '') {
        $video_id = $video_value->solr_video_id;
      }
      else {
        
      }
      $video_detail[$video_status]['video_id'] = $video_id;
      $file_id = $video_value->fid;
    }

    $query = db_select('file_managed', 'fm');
    $query->condition('fm.fid', $file_id);
    $query->fields('fm', array('filename', 'uri', 'filemime', 'filesize', 'status'));
    $query->orderBy('fm.fid', 'DESC');
    $query->range(0, 1);
    $results = $query->execute()->fetchAll();
    $uri = $results[0]->uri;
    $video_detail[$video_status]['filename'] = $results[0]->filename;
    $video_detail[$video_status]['filsize'] = $results[0]->filesize;

    $query = db_select('itg_video_bitrates_data', 'itgv');
    $query->fields('itgv', array('bitate_url', 'bitates_field'));
    $query->condition('itgv.video_id', $video_id);
    $result2 = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $video_format = array();
    foreach ($result2 as $res_data) {
      $video_format[$res_data['bitates_field']] = $res_data['bitate_url'];
    }
    $video_path_mp4 = "https://www.dailymotion.com/video/" . $video_id . "";
    $video_format['videoparts_mp4'] = $video_path_mp4;
    $video_detail[$video_status]['bitate_url'] = $video_format;
    $dailymotion_download = dailymotion_download_video_uri($video_id);
    $video_detail[$video_status]['bitate_url']['download_url'] = "$dailymotion_download";
  }
  elseif ($source_type == 'migrated') {
    $video_status = 'migrated';
    $videoids = get_video_in_fieldcollection_by_nid_mirtaed($nid);
    foreach ($videoids as $keys => $video_value) {
      $video_path_mp4 = $video_value->field_migrated_video_url_value;
    }
    $video_detail[$video_status]['video_path_mp4'] = $video_path_mp4;
    $flv_url = str_replace(".mp4", ".flv", $video_path_mp4);
    $videoparts_3gp = str_replace(".mp4", ".3gp", $video_path_mp4);
    $video_detail[$video_status]['flv_url'] = $flv_url;
    $video_detail[$video_status]['videoparts_3gp'] = $videoparts_3gp;    
  }
  return $video_detail;
}

/**
 * Get the dailymotion download video url
 * @param type $video_id
 * @return type
 */
function dailymotion_download_video_uri($video_id) {
  $query = db_select('field_data_field_bitrate_video_id', 'bvi');
  $query->leftJoin('field_data_field_video_url', 'v_url', 'v_url.entity_id = bvi.entity_id');
  $query->fields('v_url', array('field_video_url_value'));
  $query->condition('bvi.field_bitrate_video_id_value', $video_id);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result[0]['field_video_url_value'];
}

function get_nid_is_favorite($nid) {
  $flag = "";
  $result = db_select('field_data_field_featured', 'ffd')->fields('ffd', array('field_featured_value'))->condition('ffd.entity_id', $nid, '=')->execute()->fetchAssoc();
  if (isset($result['field_featured_value']) && ($result['field_featured_value'] == "yes" || $result['field_featured_value'] == "Yes")) {
    $flag = "true";
  }
  else {
    $flag = "false";
  }
  return $flag;
}

/**
 * function get nid is syndications
 * @pram $tid
 *
 * @return type
 */
function get_nid_is_syndications($nid) {
  // variable declation
  $flag = 0;
  $result = db_select('field_data_field_story_syndication', 'fss')->fields('fss', array('field_story_syndication_value'))->condition('fss.entity_id', $nid, '=')->execute()->fetchAssoc();

  if (isset($result['field_featured_value']) && ($result['field_featured_value'] == "yes" || $result['field_featured_value'] == "Yes")) {
    $flag = 1;
  }
  else {
    $flag = 0;
  }
  return $flag;
}



/**
 * function for generate Empty image xml tag
 *
 *
 */
function empty_get_img_tag_detail() {
  $imgtag = "<bodyimages><image><lowres><![CDATA[]]></lowres><highres><![CDATA[]]></highres><caption></caption></image></bodyimages>";
  return $imgtag;
}

/**
 * function for generate image xml tag
 *
 * @return array
 */
function get_img_tag_detail($result) {
  if (empty($result[field_story_medium_image_fid]))
    return FALSE;

  $highres = get_image_info_by_fid($result['field_story_medium_image_fid']);
  $lowres = get_image_info_by_fid($result['field_story_small_image_fid']);
  $imgtag = "<bodyimages><image><lowres><![CDATA[" . $lowres['imag_url'] . "]]></lowres><highres><![CDATA[" . $highres['imag_url'] . "]]></highres><caption>" . $highres['caption'] . "</caption></image></bodyimages>";
  return $imgtag;
}

/**
 * function for generate comment xml tag
 *
 * @return array
 */
function get_comment_xml_tag($nid) {
  $node = node_load($nid);

  if (count($node->comment) <= 0) {
    return emptyget_comment_xml_tag();
  }
  // variable declation
  $mode = "COMMENT_MODE_FLAT";
  $comments_per_page = 10;
  $commentsflag = 0;
  $comment_tag = "";
  $output = "";
  $comments_list = comment_get_thread($node, $mode, $comments_per_page);

  // writng comments tag
  foreach ($comments_list as $key => $value) {
    $cid = $value;
    $commentsflag = 1;
    $commens_obj = comment_load($cid);
    $commenttext = $commens_obj->comment_body['und'][0]['value'];
    $name = $commens_obj->name;
    $create_date = date("F d, Y", $commens_obj->created);
    $create_datetime = date("Y-m-d\TH:i:sP", $commens_obj->created);
    $email = $commens_obj->mail;
    $comment_tag .= "<comment><commenttext>" . $commenttext . "</commenttext><name>" . $name . "</name><createddate>" . $create_date . "</createddate><createddatetime>" . $create_datetime . "</createddatetime><email>" . $email . "</email></comment>";
  }

  if ($commentsflag) {
    $output .= "<comments>";
    $output .= $comment_tag;
    $output .= "</comments>";
  }
  else {
    $output .= emptyget_comment_xml_tag();
  }
  return $output;
}

/**
 * function for generate Empty comment xml tag
 *
 *
 */
function emptyget_comment_xml_tag() {
  $commenttext = "";
  $name = '';
  $create_date = '';
  $create_datetime = "";
  $email = "";
  // writng comments tag
  $comment_tag .= "<comment><commenttext>" . $commenttext . "</commenttext><name>" . $name . "</name><createddate>" . $create_date . "</createddate><createddatetime>" . $create_datetime . "</createddatetime><email>" . $email . "</email></comment>";

  $output .= "<comments>";
  $output .= $comment_tag;
  $output .= "</comments>";
  return $output;
}
