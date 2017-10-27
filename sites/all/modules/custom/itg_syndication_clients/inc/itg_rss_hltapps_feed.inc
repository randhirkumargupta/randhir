<?php

/**
 * @file
 * The ITG Syndication clients for Hltapps
 */
function itg_rss_hltapps_stories() {
  $sections = get_hltapps_sections('story');
  foreach ($sections as $file_name => $section_id) {
    itg_genrate_hltapps_stories_syndication($section_id, $file_name);
  }
}

function itg_rss_hltapps_videos() {
  $sections = get_hltapps_sections('video');
  foreach ($sections as $file_name => $section) {
    itg_genrate_hltapps_videos_syndication($section['section'], $file_name, $section['limit']);
  }
}

/**
 * menu callback for Hltapps story syndication
 */
function itg_genrate_hltapps_stories_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    if ($section_id != -1) {
      $section_name = get_term_name_by_tid($section_id);
    }
    else {
      $section_name = 'Latest News';
    }

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_large_image', 'sli', 'sli.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_courtesy', 'sc', 'sc.entity_id=n.nid');

    if (!empty($section_id) && $section_id != -1) {
      $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
      $query->condition('ti.tid', $section_id, '=');
    }else{
      $section_id = 1;
    }

    $query->fields('n', array('nid', 'title', 'created', 'changed'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('sli', array('field_story_large_image_fid'));
    $query->fields('ssi', array('field_story_small_image_fid'));
    $query->fields('sc', array('field_story_courtesy_value'));

    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 20);

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_hltapps_stories_xml($result, $section_name, $section_id);
    $xml_path = 'public://hltapps/stories/';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

function genrate_hltapps_stories_xml($result = NULL, $category, $section_id) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<root>';
    $xml .= '<id>1</id>';
    $xml .= '<title><![CDATA[ ' . $category . ' ]]></title>';
    $xml .= '<itemcount>' . count($result) . '</itemcount>';
    foreach ($result as $key => $value) {
      $nid = $value['nid'];
      $publish_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $url = $base_url . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $xml_story_file = 'story' . $nid . '.xml';
      $xml .= '<item>';
      $xml .= '<title><![CDATA[ ' . $value["title"] . ' ]]></title>';
      $xml .= '<shortdescription><![CDATA[ ' . $kicker_text . ' ]]></shortdescription>';
      $xml .= '<thumbimage><![CDATA[ ' . $small_img["imag_url"] . ' ]]></thumbimage>';
      $xml .= '<url>' . $xml_story_file . '</url>';
      $xml .= '<weburl><![CDATA[ ' . $url . ' ]]></weburl>';
      $xml .= '<createddate> ' . $publish_date . ' </createddate>';
      $xml .= '</item>';
      genrate_hltapps_stories_detail_xml($value, $category, $xml_story_file, $section_id);
    }
    $xml .= '</root>';
  }
  return $xml;
}

function genrate_hltapps_stories_detail_xml($value, $category, $xml_story_file, $section_id) {
  $publish_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
  $updated_date = date("H:i", strtotime($value['changed']));
  $byline = get_byline_name_by_nid($value['nid']);
  $place = get_content_city($value['nid']);
  $body = remove_extra_tag_in_body($value["body_value"]);
  $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
  $large_img = get_image_info_by_fid($value['field_story_large_image_fid']);
  $courtesy = $value['field_story_courtesy_value'];
  $xml_detail = '<root>';
  $xml_detail .= '<item>';
  $xml_detail .= '<id>'.$value["nid"].'</id>';
  $xml_detail .= '<sectionid>'.$section_id.'</sectionid>';
  $xml_detail .= '<sectionname>'.$category.'</sectionname>';
  $xml_detail .= '<title><![CDATA[ ' . $value["title"] . ' ]]></title>';
  $xml_detail .= '<credit><![CDATA[ ' . $byline . ' ]]></credit>';
  $xml_detail .= '<createddate> ' . $publish_date . ' </createddate>';
  $xml_detail .= '<updateddate> ' . $updated_date . ' IST </updateddate>';
  $xml_detail .= '<city><![CDATA[' . $place . ' ]]></city>';
  $xml_detail .= '<courtesy><![CDATA[' . $courtesy . ' ]]></courtesy>';
  $xml_detail .= '<longdescription><![CDATA[' . $body . ' ]]></longdescription>';
  $xml_detail .= '<images>';
  $xml_detail .= '<image>';
  $xml_detail .= '<thumbimage><![CDATA[' . $small_img["imag_url"] . ' ]]></thumbimage>';
  $xml_detail .= '<largeimage><![CDATA[' . $large_img["imag_url"] . ' ]]></largeimage>';
  $xml_detail .= '</image>';
  $xml_detail .= '</images>';
  $xml_detail .= get_comment_xml_tag($value['nid']);
  $xml_detail .= '</item>';
  $xml_detail .= '</root>';
  $xml_path = 'public://hltapps/stories/';
  $file_path = $xml_path . $xml_story_file;
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $xml_detail);
  fclose($fpd);
}


/**
 * menu callback for Hltapps story syndication
 */
function itg_genrate_hltapps_videos_syndication($section_id = NULL, $file_name, $limit = 25) {
  if (!empty($section_id)) {
    if ($section_id != -1) {
      $section_name = get_term_name_by_tid($section_id);
    }else if ($file_name == "topten.xml"){
      $section_name = 'Top Ten';
    }
    else if ($file_name == "news.xml"){
      $section_name = 'news';
    }

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_story_large_image', 'sli', 'sli.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');
    $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_courtesy', 'sc', 'sc.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_source_type', 'sst', 'sst.entity_id=n.nid');
     $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');

    if (!empty($section_id) && $section_id != -1) {
      $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
      $query->condition('ti.tid', $section_id, '=');
    }else{
      $section_id = 1;
    }

    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('sli', array('field_story_large_image_fid'));
    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('ssi', array('field_story_small_image_fid'));
    $query->fields('pc', array('field_primary_category_value'));
    $query->fields('sc', array('field_story_courtesy_value'));
    $query->fields('sst', array('field_story_source_type_value'));
    
    $query->condition('n.status', 1);
    $query->condition('n.type', 'videogallery', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, $limit);

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_hltapps_videos_xml($result, $section_name, $section_id);
    $xml_path = 'public://hltapps/videos/';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

function genrate_hltapps_videos_xml($result, $section_name, $section_id){
  global $base_url;
  $xml = '<root>';
  $xml .= '<id>'.$section_id.'</id>';  
  $xml .= '<title>'.$section_name.'</title>';
  $xml .= '<itemcount>'.count($result).'</itemcount>';
  if (!empty($result)) {
    foreach ($result as $value) {
      $nid = $value['nid'];
      $video_file_name = 'video' . $nid . '.xml';
      $created_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $primary_cat = get_term_name_by_tid($value['field_primary_category_value']);
      $content_url = $base_url . "/" . drupal_get_path_alias('node/' . $nid);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<shortdescription><![CDATA[' . $kicker_text . ']]></shortdescription>';
      $xml .= '<sectionname>' . $primary_cat . '</sectionname>';
      $xml .= '<thumbimage><![CDATA[' . $small_img['imag_url'] . ']]></thumbimage>';
      $xml .= '<url>'.$video_file_name.'</url>';
      $xml .= '<web-url><![CDATA[' . $content_url . ']]></web-url>';
      $xml .= '<createddate>'.$created_date.'</createddate>';
      $xml .= '</item>';
      genrate_hltapps_video_detail_xml($value, $section_id, $section_name, $video_file_name);
    }
  }
  $xml .= '</root>';
  return $xml;
}

function genrate_hltapps_video_detail_xml($value, $section_id, $section_name, $video_file_name){
  if($section_name == 'Top Ten'){
    $section_name = 'Videos';
  }
  $nid = $value['nid'];
  $created_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
  $byline = get_byline_name_by_nid($value['nid']);
  $place = get_content_city($value['nid']);
  $courtesy = $value['field_story_courtesy_value'];
  $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
  $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
  $large_img = get_image_info_by_fid($value['field_story_large_image_fid']);
  $source_type = $value['field_story_source_type_value'];
  $videotag = video_detail_formats($nid, $source_type);
  $content_url = $base_url . "/" . drupal_get_path_alias('node/' . $nid);
  
  $video_xml = '<root>';
  $video_xml .= '<item>';
  $video_xml .= '<id>' . $value['nid'] . '</id>';
  $video_xml .= '<sectionid>' . $section_id . '</sectionid>';
  $video_xml .= '<sectionname>' . $section_name . '</sectionname>';
  $video_xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
  $video_xml .= '<credit><![CDATA[' . $byline . ']]></credit>';
  $video_xml .= '<createddate>' . $created_date . '</createddate>';
  $video_xml .= '<city><![CDATA[' . $place . ']]></city>';
  $video_xml .= '<courtesy><![CDATA[' . $courtesy . ']]></courtesy>';
  $video_xml .= '<longdescription><![CDATA[' . $kicker_text . ']]></longdescription>';
  $video_xml .= '<mediaid></mediaid>';
  $video_xml .= '<uurl></uurl>';
  if (!empty($videotag['migrated'])) { //migrated video
    $video_xml .= "<videoparts><part>" . $videotag['migrated']['videoparts_3gp'] . "</part></videoparts><size_364bit></size_364bit><videoparts_mp4><part>" . $videotag['migrated']['video_path_mp4'] . "</part></videoparts_mp4><videoparts_m3u8><part>" . $videotag['migrated']['videoparts_3gp'] . "</part></videoparts_m3u8><flvvideoparts><part>" . $videotag['migrated']['flv_url'] . "</part></flvvideoparts><videoparts_3gp><part>" . $videotag['migrated']['videoparts_3gp'] . "</part></videoparts_3gp>";
  }
  elseif (!empty($videotag['dailymotion'])) {
    $video_xml .= "<videoparts><part>" . $videotag['dailymotion']['bitate_url']['stream_h264_hq_url'] . "</part></videoparts><size_364bit>" . $videotag['dailymotion']['filsize'] . "</size_364bit><videoparts_mp4><part>" . $videotag['dailymotion']['bitate_url']['videoparts_mp4'] . "</part></videoparts_mp4><videoparts_m3u8><part>" . $videotag['dailymotion']['bitate_url']['stream_h264_url'] . "</part></videoparts_m3u8><flvvideoparts><part>" . $videotag['dailymotion']['bitate_url']['stream_h264_hq_url'] . "</part></flvvideoparts><videoparts_3gp><part>" . $videotag['dailymotion']['bitate_url']['stream_h264_ld_url'] . "</part></videoparts_3gp>";
  }
  $video_xml .= '<images>';
  $video_xml .= '<image>';
  $video_xml .= '<thumbimage><![CDATA[' . $small_img["imag_url"] . ' ]]></thumbimage>';
  $video_xml .= '<largeimage><![CDATA[' . $large_img["imag_url"] . ' ]]></largeimage>';
  $video_xml .= '</image>';
  $video_xml .= '</images>';
  $video_xml .= get_comment_xml_tag($value['nid']);
  $video_xml .= '<weburl><![CDATA[' . $content_url . ']]></weburl>';
  $video_xml .= '</item>';
  $video_xml .= '</root>';
  $xml_path = 'public://hltapps/videos/';
  $file_path = $xml_path . $video_file_name;
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $video_xml);
  fclose($fpd);
}