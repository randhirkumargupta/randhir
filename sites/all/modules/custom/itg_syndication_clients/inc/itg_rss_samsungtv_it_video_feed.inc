<?php

/**
 * Function for generate samsung video feed
 */
function itg_rss_samsungtv_it_video_feed() {
  $sections = get_samsungtv_it_sections();
  foreach ($sections as $file_name => $section) {
    itg_genrate_samsungtv_it_videos_syndication($section['section'], $file_name, $section['limit']);
  }
}

/**
 * Function for generate samsung live listing feed
 */
function itg_rss_samsungtv_it_livenow_listing_feed() {
  $sections = get_samsungtv_it_live_now_sections();
  itg_genrate_samsungtv_it_live_now_syndication($sections);
}

/**
 * Function for generatesamsung breaking news feed
 */
function itg_rss_samsungtv_it_videobreakingnews_feed() {
  $type = array('breaking_news');
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->join('field_data_field_type', 'ft', 'ft.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');

  $query->fields('n', array('nid', 'title', 'created', 'changed'));
  $query->fields('ssi', array('field_story_small_image_fid'));
  $query->condition('ft.field_type_value', 'Breaking News', '=');
  $query->condition('n.status', 1);
  $query->condition('n.type', $type, 'IN');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 1);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $xml = itg_genrate_samsungtv_it_breakingnews_syndication($result);
  $xml_path = 'public://samsungtv_it/videos/';
  $file_path = $xml_path . 'breakingnews.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * Function for generate samsung video breaking news
 * 
 */
function itg_rss_indiatoday_videobreakingnews_feed() {
  $type = array('breaking_news');
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->join('field_data_field_type', 'ft', 'ft.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');

  $query->fields('n', array('nid', 'title', 'created', 'changed'));
  $query->fields('ssi', array('field_story_small_image_fid'));
  $query->condition('ft.field_type_value', 'Breaking News', '=');
  $query->condition('n.status', 1);
  $query->condition('n.type', $type, 'IN');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 1);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $xml = itg_genrate_samsungtv_it_breakingnews_syndication($result);
  $xml_path = 'public://indiatoday/';
  $file_path = $xml_path . 'breakingnews.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * Function for generate samsung home xml feed
 */
function itg_rss_samsungtv_it_video_home_feed() {
  $xml = get_samsung_it_home_static_xml();
  $xml_path = 'public://samsungtv_it/videos/';
  $file_path = $xml_path . 'home.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * 
 * @param int $section_id
 * @param string $file_name
 * @param int $limit
 */
function itg_genrate_samsungtv_it_videos_syndication($section_id = NULL, $file_name, $limit = 25) {
  if (!empty($section_id)) {
    $section_name = get_term_name_by_tid($section_id);

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_source_type', 'sst', 'sst.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');

    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->condition('ti.tid', $section_id, '=');

    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('ssi', array('field_story_small_image_fid'));
    $query->fields('sst', array('field_story_source_type_value'));

    $query->condition('n.status', 1);
    $query->condition('n.type', 'videogallery', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, $limit);

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_samsungtv_it_videos_xml($result, $section_name, $section_id, $file_name);
    $xml_path = 'public://samsungtv_it/videos/';
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
 * @param string $file_name
 * @return string
 */
function genrate_samsungtv_it_videos_xml($result, $section_name, $section_id, $file_name) {
  global $base_url;
  $xml = '<Root>';
  $xml .= '<sectionid>' . $section_id . '</sectionid>';
  $xml .= '<sectionname>' . $section_name . '</sectionname>';
  $xml .= '<totalvideos>' . count($result) . '</totalvideos>';

  if (!empty($result)) {
    foreach ($result as $value) {
      $nid = $value['nid'];
      $video_file_name = 'video' . $nid . '.xml';
      $created_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<thumbimage><![CDATA[' . $small_img['imag_url'] . ']]></thumbimage>';
      $xml .= '<url>' . $video_file_name . '</url>';
      $xml .= '<create_date>' . $created_date . '</create_date>';
      $xml .= '</item>';
      genrate_samsungtv_it_video_detail_xml($value, $section_id, $section_name, $video_file_name, $file_name);
    }
  }
  $xml .= '</Root>';
  return $xml;
}

/**
 * 
 * @global string $base_url
 * @param array $value
 * @param int $section_id
 * @param string $section_name
 * @param string $video_file_name
 * @param string $file_name
 */
function genrate_samsungtv_it_video_detail_xml($value, $section_id, $section_name, $video_file_name, $file_name) {
  global $base_url;

  $nid = $value['nid'];
  $created_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
  $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
  $source_type = $value['field_story_source_type_value'];
  $videotag = itg_video_detail_formats($nid, $source_type);

  $video_xml = '<Root>';
  $video_xml .= '<item>';
  $video_xml .= '<videoid>' . $value['nid'] . '</videoid>';
  $video_xml .= '<sectionname><![CDATA[' . $section_name . ']]></sectionname>';
  $video_xml .= '<sectionsource><![CDATA[' . $file_name . ']]></sectionsource>';
  $video_xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
  $video_xml .= '<thumbimage><![CDATA[' . $small_img['imag_url'] . ']]></thumbimage>';

  if (!empty($videotag['migrated'])) { //migrated video
    $video_xml .= "<videoparts><part_0>" . $videotag['migrated']['video_path_mp4'] . "</part_0></videoparts>";
  }
  elseif (!empty($videotag['dailymotion'])) {
    $video_xml .= "<videoparts><part_0>" . $videotag['dailymotion']['bitate_url']['videoparts_mp4'] . "</videoparts>";
  }
  $video_xml .= '<createddate>' . $created_date . '</createddate>';
  $video_xml .= '</item>';
  $video_xml .= '</Root>';
  $xml_path = 'public://samsungtv_it/videos/';
  $file_path = $xml_path . $video_file_name;
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $video_xml);
  fclose($fpd);
}

/**
 * Funstion for get static xml 
 * @return string
 */
function get_samsung_it_home_static_xml() {
  $xml = "<Root>
          <sectionid>1</sectionid>
          <sectionname>Home</sectionname>
          <sectioncount>7</sectioncount>
          <item>
          <title>Live Now on Channel</title>
          <url>livenow-listing.xml</url>
          </item>
          <item>
          <title>India</title>
          <url>india.xml</url>
          </item>
          <item>
          <title>World</title>
          <url>world.xml</url>
          </item>
          <item>
          <title>Business</title>
          <url>business.xml</url>
          </item>
          <item>
          <title>Entertainment</title>
          <url>entertainment.xml</url>
          </item>
          <item>
          <title>Programmes</title>
          <url>programms.xml</url>
          </item>
          </Root>";
  return $xml;
}

/**
 * 
 * @param array $sections
 */
function itg_genrate_samsungtv_it_live_now_syndication($sections) {
  $query = db_select('taxonomy_term_data', 't');
  $query->leftJoin('itg_category_manager', 'cm', 'cm.tid = t.tid');
  $query->leftJoin('field_data_field_program_timing_in_days', 'ptin', 'ptin.entity_id = t.tid');
  $query->leftJoin('field_data_field_user_city', 'fuc', 'fuc.entity_id = t.tid');
  $query->leftJoin('field_data_field_sponser_logo', 'fsl', 'fsl.entity_id = t.tid');
  $query->fields('t', array('tid', 'name'));
  $query->fields('ptin', array('field_program_timing_in_days_value'));
  $query->fields('fuc', array('field_user_city_value'));
  $query->fields('fsl', array('field_sponser_logo_fid'));
  $query->condition('cm.status', 1, '=');
  $query->condition('t.tid', $sections, 'IN');

  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $xml = genrate_samsungtv_it_live_now_xml($result);
  $xml_path = 'public://samsungtv_it/videos/';
  $file_path = $xml_path . 'livenow-listing.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * 
 * @param array $result
 * @return string
 */
function genrate_samsungtv_it_live_now_xml($result) {
  $xml = '<Root>';
  $xml .= '<sectionid>1</sectionid>';
  $xml .= '<section>Live Now on Channel</section>';
  $xml .= '<sectioncount>' . count($result) . '</sectioncount>';
  foreach ($result as $key => $value) {
    $url = slugify($value['name']);
    $cat_img = get_image_info_by_fid($value['field_sponser_logo_fid']);
    $xml .= '<item>';
    $xml .= '<title><![CDATA[' . $value['name'] . ']]></title>';
    $xml .= '<scheduletime>' . $value['field_user_city_value'] . '</scheduletime>';
    $xml .= '<scheduleday>' . $value['field_program_timing_in_days_value'] . '</scheduleday>';
    $xml .= '<url><![CDATA[' . $url . '.xml]]></url>';
    $xml .= '<sectionimage><![CDATA[' . $cat_img['imag_url'] . ']]></sectionimage>';
    $xml .= '</item>';
  }
  $xml .= '</Root>';
  return $xml;
}

