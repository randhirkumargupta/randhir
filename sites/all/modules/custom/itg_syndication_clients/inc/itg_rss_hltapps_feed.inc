<?php

/**
 * @file
 * The ITG Syndication clients for Hltapps
 */

/**
 * menu callback
 * Function for generate Hltapps story feed
 */
function itg_rss_hltapps_stories() {
  $sections = get_hltapps_sections('story');
  foreach ($sections as $file_name => $section_id) {
    itg_genrate_hltapps_stories_syndication($section_id, $file_name);
  }
}

/**
 * menu callback
 * Function for generate Hltapps video feed
 */
function itg_rss_hltapps_videos() {
  $sections = get_hltapps_sections('video');
  foreach ($sections as $file_name => $section) {
    itg_genrate_hltapps_videos_syndication($section['section'], $file_name, $section['limit']);
  }
}

/**
 * menu callback
 * Function for generate Hltapps programme feed
 */
function itg_rss_hltapps_programme() {
  $sections = get_hltapps_sections('programme');
  foreach ($sections as $file_name => $section) {
    itg_genrate_hltapps_programme_syndication($section['section'], $file_name, $section['limit']);
  }
}

/**
 * menu callback
 * Function for generate Hltapps photo feed
 */
function itg_rss_hltapps_photos() {
  $sections = get_hltapps_sections('photo');
  foreach ($sections as $file_name => $section) {
    itg_genrate_hltapps_photos_syndication($section['section'], $file_name, $section['limit']);
  }
}

/**
 * menu callback
 * Function for generate Hltapps mixed feed
 */
function itg_rss_hltapps_mixed_rss_feed() {
  $sections = get_hltapps_sections('mixed');
  foreach ($sections as $file_name => $section) {
    itg_genrate_hltapps_mixed_feed_syndication($section['section'], $file_name, $section['title']);
  }
}

/**
 * menu callback
 * Function for generate Hlt video feed
 */
function itg_rss_msn_hlt_videos_feed() {
  $sections = get_hltapps_sections('msn_hlt_video');
  foreach ($sections as $file_name => $section) {
    itg_genrate_msn_hlt_videos_feed_syndication($section['section'], $file_name);
  }
}

/**
 * menu callback
 * Function for generate Hltapps static feed
 */
function itg_rss_hltappsstaticfeeds() {
  itg_generate_hltapps_static_feed_homesectionslist();
  itg_generate_hltapps_static_feed_sectionslist();
  itg_generate_hltapps_static_feed_video_sectionslist();
  itg_generate_hltapps_static_feed_photo_sectionslist();
  itg_generate_hltapps_static_feed_about_us();
  itg_generate_hltapps_static_feed_livetv_text();
  itg_generate_hltapps_static_feed_playbook_ad();
  itg_generate_hltapps_static_feed_bb_ad();
  itg_generate_hltapps_static_api_livetv();
  itg_generate_hltapps_static_api();
}

/**
 * menu callback
 * Function for generate Hltapps programme static feed
 */
function itg_rss_programme_static() {
  itg_generate_hltapps_programme_static(get_hltapps_sections('programmes'));
}

/**
 * menu callback
 * Function for generate Hltapps breakingnews static feed
 */
function itg_rss_breakingnews_feed() {
  $type = array('breaking_news');
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->join('field_data_field_type', 'ft', 'ft.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');

  $query->fields('n', array('nid', 'title', 'created', 'changed'));
  $query->fields('ssi', array('field_story_small_image_fid'));
  $query->condition('ft.field_type_value', 'Breaking News', '=');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'breaking_news', '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 1);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $xml = itg_genrate_samsungtv_it_breakingnews_syndication($result);
  $xml_path = 'public://hltapps/';
  $file_path = $xml_path . 'breakingnews.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * 
 * @param int $section_id
 * @param string $file_name
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
      if ($days_ago = get_content_fetch_time($section_id)) {
        $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
        $query->condition('n.created', $days_ago, '>=');
      }
    }
    else {
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

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param string $category
 * @param int $section_id
 * @return string
 */
function genrate_hltapps_stories_xml($result = NULL, $category, $section_id) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<root>';
    $xml .= '<id>1</id>';
    $xml .= '<title><![CDATA[ ' . $category . ' ]]></title>';
    $xml .= '<itemcount>' . count($result) . '</itemcount>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $nid = $value['nid'];
      $publish_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
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

/**
 * 
 * @global string $base_url
 * @param array $value
 * @param string $category
 * @param string $xml_story_file
 * @param int $section_id
 */
function genrate_hltapps_stories_detail_xml($value, $category, $xml_story_file, $section_id) {
  global $base_url;
  $publish_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
  $updated_date = date("H:i", strtotime($value['changed']));
  $byline = get_byline_name_by_nid($value['nid']);
  $place = get_content_city($value['nid']);
  $body = remove_extra_tag_in_body($value["body_value"]);
  $body = itg_replace_token_with_data($body, $value['nid']);
  $body = itg_remove_extra_custom_tags($body);
  $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
  $large_img = get_image_info_by_fid($value['field_story_large_image_fid']);
  $courtesy = $value['field_story_courtesy_value'];
  $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
  $xml_detail = '<root>';
  $xml_detail .= '<item>';
  $xml_detail .= '<id>' . $value["nid"] . '</id>';
  $xml_detail .= '<sectionid>' . $section_id . '</sectionid>';
  $xml_detail .= '<sectionname>' . $category . '</sectionname>';
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
  $xml_detail .= '<weburl><![CDATA[ ' . $url . ' ]]></weburl>';
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
 * 
 * @param int $section_id
 * @param string $file_name
 * @param int $limit
 */
function itg_genrate_hltapps_videos_syndication($section_id = NULL, $file_name, $limit = 25) {
  if (!empty($section_id)) {
    if ($section_id != -1) {
      $section_name = get_term_name_by_tid($section_id);
    }
    else if ($file_name == "topten.xml") {
      $section_name = 'Top Ten';
    }
    else if ($file_name == "news.xml") {
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
      if ($days_ago = get_content_fetch_time($section_id)) {
        $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
        $query->condition('n.created', $days_ago, '>=');
      }
    }
    else {
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

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param string $section_name
 * @param int $section_id
 * @return string
 */
function genrate_hltapps_videos_xml($result, $section_name, $section_id) {
  global $base_url;

  $xml = '<root>';
  $xml .= '<id>' . $section_id . '</id>';
  $xml .= '<title><![CDATA[' . $section_name . ']]></title>';
  if ($section_id == 1) {
    $xml .= '<description><![CDATA[ About India & world News. ]]></description>';
  }
  $xml .= '<itemcount>' . count($result) . '</itemcount>';

  if (!empty($result)) {
    foreach ($result as $value) {
      $nid = $value['nid'];
      $video_file_name = 'video' . $nid . '.xml';
      $created_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      //$primary_cat = get_term_name_by_tid($value['field_primary_category_value']);
      $content_url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<shortdescription><![CDATA[' . $kicker_text . ']]></shortdescription>';
      //$xml .= '<sectionname>' . $primary_cat . '</sectionname>';
      $xml .= '<thumbimage><![CDATA[' . $small_img['imag_url'] . ']]></thumbimage>';
      $xml .= '<url>' . $video_file_name . '</url>';
      $xml .= '<web-url><![CDATA[' . $content_url . ']]></web-url>';
      $xml .= '<createddate>' . $created_date . '</createddate>';
      $xml .= '</item>';
      genrate_hltapps_video_detail_xml($value, $section_id, $section_name, $video_file_name);
    }
  }
  $xml .= '</root>';
  return $xml;
}

/**
 * 
 * @global string $base_url
 * @param array $value
 * @param int $section_id
 * @param string $section_name
 * @param string $video_file_name
 */
function genrate_hltapps_video_detail_xml($value, $section_id, $section_name, $video_file_name) {
  global $base_url;
  if ($section_name == 'Top Ten') {
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
  $videotag = itg_video_detail_formats($nid, $source_type);
  $content_url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);

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
  $video_xml .= '<weburl><![CDATA[' . $content_url . ']]></weburl>';
  $video_xml .= get_comment_xml_tag($value['nid']);
  $video_xml .= '</item>';
  $video_xml .= '</root>';
  $xml_path = 'public://hltapps/videos/';
  $file_path = $xml_path . $video_file_name;
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $video_xml);
  fclose($fpd);
}

/**
 * 
 * @param int $section_id
 * @param string $file_name
 * @param int $limit
 */
function itg_genrate_hltapps_photos_syndication($section_id = NULL, $file_name, $limit = 25) {
  if (!empty($section_id)) {
    $section_name = get_term_name_by_tid($section_id);
    $type = array('photogallery');
    $query = db_select('node', 'n');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->leftJoin('field_data_field_story_large_image', 'sli', 'sli.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');

    if ($days_ago = get_content_fetch_time($section_id)) {
      $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
      $query->condition('n.created', $days_ago, '>=');
    }

    $query->condition('ti.tid', $section_id, '=');
    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('sli', array('field_story_large_image_fid'));
    $query->fields('ssi', array('field_story_small_image_fid'));
    $query->condition('n.status', 1);
    $query->condition('n.type', 'photogallery', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, $limit);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_hltapps_photos_xml($result, $section_name, $section_id);
    $xml_path = 'public://hltapps/photos/';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param string $section_name
 * @param int $section_id
 * @return string
 */
function genrate_hltapps_photos_xml($result, $section_name, $section_id) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $total_count = count($result);
    $xml .= '<root>';
    $xml .= '<id>' . $section_id . '</id>';
    $xml .= '<title><![CDATA[' . $section_name . ']]></title>';
    $xml .= '<itemcount>' . $total_count . '</itemcount>';

    foreach ($result as $value) {
      $nid = $value['nid'];
      $photo_detail_file_name = 'photo' . $nid . '.xml';
      $created_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $content_url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<shortdescription><![CDATA[' . $kicker_text . ']]></shortdescription>';
      $xml .= '<thumbimage><![CDATA[' . $small_img['imag_url'] . ']]></thumbimage>';
      $xml .= '<url>' . $photo_detail_file_name . '</url>';
      $xml .= '<weburl><![CDATA[' . $content_url . ']]></weburl>';
      $xml .= '<createddate>' . $created_date . '</createddate>';
      $xml .= '</item>';

      generate_hltapps_photo_detail_xml($value, $section_id, $section_name, $photo_detail_file_name);
    }
    $xml .= '</root>';
  }
  return $xml;
}

/**
 * 
 * @global string $base_url
 * @param array $value
 * @param int $section_id
 * @param string $section_name
 * @param string $photo_detail_file_name
 */
function generate_hltapps_photo_detail_xml($value, $section_id, $section_name, $photo_detail_file_name) {
  global $base_url;
  $nid = $value['nid'];
  $gallery_img_fc = get_all_associated_photos($nid);
  $image_count = count($gallery_img_fc);
  $created_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
  $content_url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);
  $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
  $large_img = get_image_info_by_fid($value['field_story_large_image_fid']);

  $photo_xml .= '<root>';
  $photo_xml .= '<id>' . $nid . '</id>';
  $photo_xml .= '<sectionid>' . $section_id . '</sectionid>';
  $photo_xml .= '<sectionname>' . $section_name . '</sectionname>';
  $photo_xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
  $photo_xml .= '<itemscount>' . $image_count . '</itemscount>';
  $photo_xml .= '<createddate>' . $created_date . '</createddate>';
  $photo_xml .= '<longdescription><![CDATA[' . $value['field_story_kicker_text_value'] . ']]></longdescription>';
  $photo_xml .= '<images>';
  $photo_xml .= '<image>';
  $photo_xml .= '<thumbimage><![CDATA[' . $small_img["imag_url"] . ' ]]></thumbimage>';
  $photo_xml .= '<largeimage><![CDATA[' . $large_img["imag_url"] . ' ]]></largeimage>';
  $photo_xml .= '</image>';
  $photo_xml .= '</images>';
  $photo_xml .= '<weburl><![CDATA[' . $content_url . ']]></weburl>';
  $byline = get_byline_name_by_nid($nid);

  foreach ($gallery_img_fc as $photo) {
    $byline = $photo['title'];
    $large_image = '';
    if (!empty($photo['field_images_fid'])) {
      $large_image = get_image_info_by_fid($photo['field_images_fid']);
    }
    $small_image = '';
    if (!empty($photo['field_photo_small_image_fid'])) {
      $small_image = get_image_info_by_fid($photo['field_photo_small_image_fid']);
    }

    $photo_xml .= '<item>';
    $photo_xml .= '<imageid>' . $photo['field_gallery_image_value'] . '</imageid>';
    $photo_xml .= '<thumbimage>' . $small_image['imag_url'] . '</thumbimage>';
    $photo_xml .= '<largeimage>' . $large_image['imag_url'] . '</largeimage>';
    $photo_xml .= '<caption><![CDATA[' . $photo['field_image_caption_value'] . ']]></caption>';
    $photo_xml .= '<byline><![CDATA[' . $byline . ']]></byline>';
    $photo_xml .= '<alttext><![CDATA[' . $large_image['alt'] . ']]></alttext>';
    $photo_xml .= '</item>';
  }
  $photo_xml .= get_comment_xml_tag($nid);
  $photo_xml .= '</root>';
  $xml_path = 'public://hltapps/photos/';
  $file_path = $xml_path . $photo_detail_file_name;
  $fp1 = fopen($file_path, "w");
  fwrite($fp1, $photo_xml);
  fclose($fp1);
}

/**
 * 
 * @param int $section_id
 * @param string $file_name
 * @param int $limit
 */
function itg_genrate_hltapps_programme_syndication($section_id = NULL, $file_name, $limit = 25) {
  if (!empty($section_id)) {
    $section_name = get_term_name_by_tid($section_id);

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
      if ($days_ago = get_content_fetch_time($section_id)) {
        $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
        $query->condition('n.created', $days_ago, '>=');
      }
    }
    else {
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
    $xml = genrate_hltapps_programme_xml($result, $section_name, $section_id);
    $xml_path = 'public://hltapps/videos/';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param string $section_name
 * @param int $section_id
 * @return string
 */
function genrate_hltapps_programme_xml($result, $section_name, $section_id) {
  global $base_url;
  $section_desc = get_term_description_by_tid($section_id);
  $xml = '<root>';
  $xml .= '<id>' . $section_id . '</id>';
  $xml .= '<title><![CDATA[' . $section_name . ']]></title>';
  $xml .= '<description><![CDATA[' . $section_desc . ']]></description>';
  $xml .= '<itemcount>' . count($result) . '</itemcount>';

  if (!empty($result)) {
    foreach ($result as $value) {
      $nid = $value['nid'];
      $video_file_name = 'video' . $nid . '.xml';
      $created_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<shortdescription><![CDATA[' . $kicker_text . ']]></shortdescription>';
      $xml .= '<thumbimage><![CDATA[' . $small_img['imag_url'] . ']]></thumbimage>';
      $xml .= '<url>' . $video_file_name . '</url>';
      $xml .= '<createddate>' . $created_date . '</createddate>';
      $xml .= '</item>';
      genrate_hltapps_video_detail_xml($value, $section_id, $section_name, $video_file_name);
    }
  }
  $xml .= '</root>';
  return $xml;
}

/**
 * 
 * @param array $sections
 * @param string $file_name
 * @param string $feed_name
 */
function itg_genrate_hltapps_mixed_feed_syndication($sections = NULL, $file_name, $feed_name) {
  $categories_id = array();
  $type = array('story', 'videogallery', 'photogallery');
  if ($sections != -1) {
    foreach ($sections as $key => $value) {
      $categories_id[] = $value;
    }
  }
  $categories_id = array_unique($categories_id);
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_large_image', 'sli', 'sli.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');
  $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_courtesy', 'sc', 'sc.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_source_type', 'sst', 'sst.entity_id=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');

  if (count($categories_id) > 0) {
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->condition('ti.tid', $categories_id, 'IN');
    $max_day_ago = 10;
    foreach ($categories_id as $sec_id) {
      $temp = get_content_fetch_time($sec_id);
      if ($max_day_ago < $temp) {
        $max_day_ago = $temp;
      }
    }
    $days_ago = strtotime(date('Y-m-d', strtotime('-' . $max_day_ago . ' days')));
    $query->condition('n.created', $days_ago, '>=');
  }
  $query->fields('dbody', array('body_value'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('synopsis', array('field_story_kicker_text_value'));
  $query->fields('sli', array('field_story_large_image_fid'));
  $query->fields('n', array('nid', 'title', 'created', 'type'));
  $query->fields('ssi', array('field_story_small_image_fid'));
  $query->fields('pc', array('field_primary_category_value'));
  $query->fields('sc', array('field_story_courtesy_value'));
  $query->fields('sst', array('field_story_source_type_value'));

  $query->condition('n.status', 1);
  $query->condition('n.type', $type, 'IN');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 24);

  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
//    print strtr((string) $query, $query->arguments());die;
  $xml = genrate_hltapps_mixed_feed($result, $sections, $feed_name);
  $xml_path = 'public://hltapps/';
  $file_path = $xml_path . $file_name;
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * 
 * @param array $result
 * @param array $sections
 * @param string $feed_name
 * @return string
 */
function genrate_hltapps_mixed_feed($result, $sections, $feed_name) {
  if (!empty($result)) {
    $xml = '<root>';
    $xml .= '<id>10</id>';
    $xml .= '<title>' . $feed_name . '</title>';
    $xml .= '<itemcount>' . count($result) . '</itemcount>';
    foreach ($result as $value) {
      $nid = $value['nid'];

      if ($value['type'] == 'story') {
        if (is_lock_story($value['nid'])) {
          continue;
        }
        $section_id = $sections['story'];
        $category = get_term_name_by_tid($section_id);
        $detail_file_name = 'stories/story' . $nid . '.xml';
        genrate_hltapps_stories_detail_xml($value, $category, $detail_file_name, $section_id);
      }
      else if ($value['type'] == 'videogallery') {
        $section_id = $sections['video'];
        $section_name = get_term_name_by_tid($section_id);
        $detail_file_name = 'videos/video' . $nid . '.xml';
        genrate_hltapps_video_detail_xml($value, $section_id, $section_name, $detail_file_name);
      }
      else if ($value['type'] == 'photogallery') {
        $section_id = $sections['video'];
        $section_name = get_term_name_by_tid($section_id);
        $detail_file_name = 'photos/photo' . $nid . '.xml';
        generate_hltapps_photo_detail_xml($value, $section_id, $section_name, $detail_file_name);
      }

      $created_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<shortdescription><![CDATA[' . $kicker_text . ']]></shortdescription>';
      $xml .= '<thumbimage><![CDATA[' . $small_img['imag_url'] . ']]></thumbimage>';
      $xml .= '<url>' . $detail_file_name . '</url>';
      $xml .= '<createddate>' . $created_date . '</createddate>';
      $xml .= '</item>';
    }
    $xml .= '</root>';
    return $xml;
  }
}

/**
 * Function for generate livenow-listing.xml feed
 * @global string $base_url
 */
function itg_rss_hltapps_livenow_listing_feed() {
  global $base_url;
  $fixed_sections = get_hltapps_sections('programme');
  $fixed_section = array();
  $fixed_section_files = array();
  foreach ($fixed_sections as $key => $value) {
    $fixed_section[] = $value['section'];
    $fixed_section_files[$value['section']] = $key;
  }
  $programme_childs = get_childrens_from_tids(get_hltapps_sections('programmes'));
  $xml = '<root>';
  $xml .= '<sectionid>1</sectionid>';
  $xml .= '<section><![CDATA[ live now on channel ]]></section>';
  $xml .= '<sectioncount>' . count($programme_childs) . '</sectioncount>';
  foreach ($programme_childs as $key => $value) {
    if (!in_array($value['tid'], $fixed_section)) {
      $file_name = slugify($value['name']) . '.xml';
      itg_genrate_hltapps_programme_syndication($value['tid'], $file_name, 25);
    }
    else {
      $file_name = $fixed_section_files[$value['tid']];
    }
    $cat_link = FRONT_URL . "/" . drupal_get_path_alias('taxonomy/term/' . $value['tid']);
    $cat_img = get_image_info_by_fid($value['field_sponser_logo_fid']);
    $xml .= '<item>';
    $xml .= '<title><![CDATA[ ' . $value['name'] . ' ]]></title>';
    $xml .= '<url>' . $file_name . '</url>';
    $xml .= '<weburl><![CDATA[ ' . $cat_link . ' ]]></weburl>';
    $xml .= '<schedulenote><![CDATA[ ' . $value['field_user_city_value'] . ' ]]></schedulenote>';
    $xml .= '<sectionimage> ' . $cat_img['imag_url'] . ' </sectionimage>';
    $xml .= '</item>';
  }
  $xml .= '</root>';
  $xml_path = 'public://hltapps/';
  $file_path = $xml_path . 'videos/livenow-listing.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * Function term children from tid
 * @param int $tid
 * @param int $vid
 * @return array
 */
function get_childrens_from_tids($tid, $vid) {
  $query = db_select('taxonomy_term_data', 't');
  $query->join('taxonomy_term_hierarchy', 'h', 'h.tid = t.tid');
  $query->leftJoin('itg_category_manager', 'cm', 'cm.tid = t.tid');
  $query->leftJoin('field_data_field_user_city', 'fuc', 'fuc.entity_id = t.tid');
  $query->leftJoin('field_data_field_sponser_logo', 'fsl', 'fsl.entity_id = t.tid');
  $query->fields('t', array('tid', 'name'));
  $query->fields('fuc', array('field_user_city_value'));
  $query->fields('fsl', array('field_sponser_logo_fid'));
  $query->condition('h.parent', $tid);
  $query->condition('cm.status', 1, '=');
  if ($vid) {
    $query->condition('t.vid', $vid);
  }
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result;
}

/**
 * 
 * @param int $section_id
 * @param string $file_name
 * @param int $limit
 */
function itg_genrate_msn_hlt_videos_feed_syndication($section_id = NULL, $file_name, $limit = 15) {
  if (!empty($section_id)) {
    $section_name = get_term_name_by_tid($section_id);

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_story_large_image', 'sli', 'sli.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');
    $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_courtesy', 'sc', 'sc.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_source_type', 'sst', 'sst.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');

    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->condition('ti.tid', $section_id, '=');

    if ($days_ago = get_content_fetch_time($section_id)) {
      $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
      $query->condition('n.created', $days_ago, '>=');
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
    $xml = genrate_msn_hlt_videos_xml($result, $section_name, $section_id);
    $xml_path = 'public://msn/hlt/videos/';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param string $section_name
 * @param int $section_id
 * @return string
 */
function genrate_msn_hlt_videos_xml($result, $section_name, $section_id) {
  global $base_url;
  $xml = '<root>';
  $xml .= '<id>' . $section_id . '</id>';
  $xml .= '<title><![CDATA[' . $section_name . ']]></title>';
  $xml .= '<itemcount>' . count($result) . '</itemcount>';
  $file_base_path = get_feed_base_url() . '/msn/hlt/videos'; //file_create_url('public://msn/hlt/videos/');
  if (!empty($result)) {
    foreach ($result as $value) {
      $nid = $value['nid'];
      $video_file_name = 'video' . $nid . '.xml';
      $created_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $content_url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<shortdescription><![CDATA[' . $kicker_text . ']]></shortdescription>';
      $xml .= '<thumbimage><![CDATA[' . $small_img['imag_url'] . ']]></thumbimage>';
      $xml .= '<url>' . $file_base_path . '/' . $video_file_name . '</url>';
      $xml .= '<weburl><![CDATA[' . $content_url . ']]></weburl>';
      $xml .= '<createddate>' . $created_date . '</createddate>';
      $xml .= '</item>';
      genrate_msn_hlt_video_detail_xml($value, $section_id, $section_name, $video_file_name);
    }
  }
  $xml .= '</root>';
  return $xml;
}

/**
 * 
 * @global string $base_url
 * @param array $value
 * @param int $section_id
 * @param string $section_name
 * @param string $video_file_name
 */
function genrate_msn_hlt_video_detail_xml($value, $section_id, $section_name, $video_file_name) {
  global $base_url;

  $nid = $value['nid'];
  $created_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
  $byline = get_byline_name_by_nid($value['nid']);
  $place = get_content_city($value['nid']);
  $courtesy = $value['field_story_courtesy_value'];
  $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
  $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
  $large_img = get_image_info_by_fid($value['field_story_large_image_fid']);
  $source_type = $value['field_story_source_type_value'];
  $videotag = itg_video_detail_formats($nid, $source_type);
  $video_size = migrated_video_transcoding($nid);
  $content_url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);

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
    $videoids = get_video_in_fieldcollection_by_nid_mirtaed($nid);
    foreach ($videoids as $keys => $video_value) {
      $url = $video_value->field_migrated_video_url_value;
    }
    $data_video = itg_videogallery_get_video_bitrate_by_url($url, $nid);
    $bitrate_url = $data_video['bitrate_url'];
    $mp4_url = $data_video['file_url'];
    $video_xml .= "<videoparts><part>" . $bitrate_url . "</part></videoparts><size_364bit></size_364bit><flvvideoparts><part>" . $mp4_url . "</part></flvvideoparts><videoparts_3gp><part>" . $mp4_url . "</part></videoparts_3gp>";
  }
  elseif (!empty($videotag['dailymotion'])) {
    $videoids = get_video_in_fieldcollection_by_nid($nid);
    foreach ($videoids as $keys => $video_value) {
      if ($video_value->video_id != '') {
        $video_id = $video_value->video_id;
      } elseif ($video_value->solr_video_id != '') {
        $video_id = $video_value->solr_video_id;
      }
    }
    $inter_video_details = internal_video_bitrate_data($video_id);
    $video_xml .= "<videoparts><part>" . $inter_video_details['bitrate_url'] . "</part></videoparts><size_364bit>" . $videotag['dailymotion']['filsize'] . "</size_364bit><videoparts_mp4><part>" . $inter_video_details['file_url'] . "</part></videoparts_mp4><videoparts_m3u8><part>" . $inter_video_details['bitrate_url'] . "</part></videoparts_m3u8><flvvideoparts><part>" . $inter_video_details['file_url'] . "</part></flvvideoparts><videoparts_3gp><part>" . $inter_video_details['file_url'] . "</part></videoparts_3gp>";
  }
  $video_xml .= '<images>';
  $video_xml .= '<image>';
  $video_xml .= '<thumbimage><![CDATA[' . $small_img["imag_url"] . ' ]]></thumbimage>';
  $video_xml .= '<largeimage><![CDATA[' . $large_img["imag_url"] . ' ]]></largeimage>';
  $video_xml .= '</image>';
  $video_xml .= '</images>';
  $video_xml .= '<weburl><![CDATA[' . $content_url . ']]></weburl>';
  $video_xml .= get_comment_xml_tag($value['nid']);
  $video_xml .= '</item>';
  $video_xml .= '</root>';
  $xml_path = 'public://msn/hlt/videos/';
  $file_path = $xml_path . $video_file_name;
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $video_xml);
  fclose($fpd);
}

/**
 * Function is used to generate static xml feed for hltapps homesectionslist
 */
function itg_generate_hltapps_static_feed_homesectionslist() {
  $data = array();
  $xml = theme('hltapps_homesectionslist', array('data' => $data));
  $xml_path = 'public://hltapps/';
  $file_path = $xml_path . 'homesectionslist.xml';
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $xml);
  fclose($fpd);
}

/**
 * Function is used to generate static xml feed for hltapps homesectionslist
 */
function itg_generate_hltapps_static_feed_sectionslist() {
  $data = array();
  $xml = theme('hltapps_sectionslist', array('data' => $data));
  $xml_path = 'public://hltapps/';
  $file_path = $xml_path . 'sectionslist.xml';
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $xml);
  fclose($fpd);
}

/**
 * Function is used to generate static xml feed for hltapps video sectionslist
 */
function itg_generate_hltapps_static_feed_video_sectionslist() {
  $data = array();
  $xml = theme('hltapps_video_sectionslist', array('data' => $data));
  $xml_path = 'public://hltapps/videos/';
  $file_path = $xml_path . 'sectionslist.xml';
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $xml);
  fclose($fpd);
}

/**
 * Function is used to generate static xml feed for hltapps photo sectionslist
 */
function itg_generate_hltapps_static_feed_photo_sectionslist() {
  $data = array();
  $xml = theme('hltapps_photo_sectionslist', array('data' => $data));
  $xml_path = 'public://hltapps/photos/';
  $file_path = $xml_path . 'sectionslist.xml';
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $xml);
  fclose($fpd);
}

/**
 * Function is used to generate static xml feed for hltapps about us
 */
function itg_generate_hltapps_static_feed_about_us() {
  $data = array();
  $xml = theme('hltapps_static_about_us', array('data' => $data));
  $xml_path = 'public://hltapps/aboutapp/';
  $file_path = $xml_path . 'aboutus.xml';
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $xml);
  fclose($fpd);
}

/**
 * Function is used to generate static xml feed for hltapps livetv_text
 */
function itg_generate_hltapps_static_feed_livetv_text() {
  $data = array();
  $xml = theme('hltapps_static_livetv_text', array('data' => $data));
  $xml_path = 'public://hltapps/api/';
  $file_path = $xml_path . 'livetv_text.xml';
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $xml);
  fclose($fpd);
}

/**
 * Function is used to generate static xml feed for hltapps playback ad
 */
function itg_generate_hltapps_static_feed_playbook_ad() {
  $data = array();
  $xml = theme('hltapps_static_playbook_ad', array('data' => $data));
  $xml_path = 'public://hltapps/ads/';
  $file_path = $xml_path . 'playbook_ad.xml';
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $xml);
  fclose($fpd);
}

/**
 * Function is used to generate static xml feed for hltapps BB ad
 */
function itg_generate_hltapps_static_feed_bb_ad() {
  $data = array();
  $xml = theme('hltapps_static_bb_ad', array('data' => $data));
  $xml_path = 'public://hltapps/ads/';
  $file_path = $xml_path . 'bb_ad.xml';
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $xml);
  fclose($fpd);
}

/**
 * Function is used to generate static xml feed for hltapps api livetv
 */
function itg_generate_hltapps_static_api_livetv() {
  $data = array();
  $xml = theme('hltapps_static_api_livetv', array('data' => $data));
  $xml_path = 'public://hltapps/api/';
  $file_path = $xml_path . 'livetv.xml';
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $xml);
  fclose($fpd);
}

/**
 * Function is used to generate static xml feed for hltapps api
 */
function itg_generate_hltapps_static_api() {
  $data = array();
  $xml = theme('hltapps_static_api', array('data' => $data));
  $xml_path = 'public://hltapps/';
  $file_path = $xml_path . 'api.xml';
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $xml);
  fclose($fpd);
}

/**
 * Function for generate progamme feed
 * @global string $base_url
 * @param int $section_id
 */
function itg_generate_hltapps_programme_static($section_id) {
  $sections = get_parent_category_name_by_tid($section_id);
  global $base_url;
  $fixed_sections = get_hltapps_sections('programme');
  $fixed_section = array();
  $fixed_section_files = array();
  foreach ($fixed_sections as $key => $value) {
    $fixed_section[] = $value['section'];
    $fixed_section_files[$value['section']] = $key;
  }
  $programme_childs = get_childrens_from_tids($sections);
  $xml = '<root>';
  $xml .= '<id>1</id>';
  $xml .= '<section><![CDATA[ programmes ]]></section>';
  $xml .= '<sectioncount>' . count($programme_childs) . '</sectioncount>';
  foreach ($programme_childs as $key => $value) {
    if (!in_array($value['tid'], $fixed_section)) {
      $file_name = slugify($value['name']) . '.xml';
      itg_genrate_hltapps_programme_syndication($value['tid'], $file_name, 25);
    }
    else {
      $file_name = $fixed_section_files[$value['tid']];
    }
    $cat_link = FRONT_URL . "/" . drupal_get_path_alias('taxonomy/term/' . $value['tid']);
    $cat_img = get_image_info_by_fid($value['field_sponser_logo_fid']);
    $xml .= '<item>';
    $xml .= '<title><![CDATA[ ' . $value['name'] . ' ]]></title>';
    $xml .= '<url>' . $file_name . '</url>';
    $xml .= '<weburl><![CDATA[ ' . $cat_link . ' ]]></weburl>';
    $xml .= '<sectionimage> ' . $cat_img['imag_url'] . ' </sectionimage>';
    $xml .= '</item>';
  }
  $xml .= '</root>';
  $xml_path = 'public://hltapps/videos/';
  $file_path = $xml_path . 'programmes.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}
