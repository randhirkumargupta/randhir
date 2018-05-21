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
 * Function for generate samsung json feed
 */
function itg_indiatoday_samsung_jsonfeed_syndication(){
  itg_generate_samsung_json_feed_newslist();
  itg_generate_samsung_json_feed_video_newslist();
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
  $query->condition('n.type', 'breaking_news', '=');
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
  $query->condition('n.type', 'breaking_news', '=');
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
    if($days_ago = get_content_fetch_time($section_id)){
      $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
      $query->condition('n.created', $days_ago, '>=');
    }
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


function itg_generate_samsung_json_feed_newslist(){
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_large_image', 'smi', 'smi.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_extra_large_image','eli','eli.entity_id = n.nid');

  $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');

  $query->fields('n', array('nid', 'title'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('synopsis', array('field_story_kicker_text_value'));
  $query->fields('smi', array('field_story_large_image_fid'));
  $query->fields('eli', array('field_story_extra_large_image_fid'));
  $days_ago = strtotime(date('Y-m-d', strtotime('-7 days')));
  $query->condition('n.created', $days_ago, '>=');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 20);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $json = array(
    'status_code' => 1,
    'status_message' => 1,
    'data' => array(
      'id' => 1,
      'title' => 'Top Stories',
    )
  );
  foreach($result as $value){
    if (is_lock_story($value['nid'])) {
      continue;
    }
    $publish_date = date("Y-m-d H:i:s", strtotime($value['field_itg_content_publish_date_value']));
    $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
    $medium_img = get_image_info_by_fid($value['field_story_large_image_fid']);
    $extra_large_img = get_image_info_by_fid($value['field_story_extra_large_image_fid']);
    $alias = drupal_get_path_alias('node/' . $value['nid'] . '');
    $weburl = FRONT_URL . "/" . $alias;
    $json['data']['news'][] = array(
      'n_id' => (int)$value['nid'],
      'n_title' => $value['title'],
      'n_short_desc' => $kicker_text,
      'n_small_image' => $medium_img["imag_url"],
      'n_updated_datetime' => $publish_date,
      'n_content_url' => $weburl,
      'v_large_image' => $extra_large_img["imag_url"],
    );
  }
  $json_output = json_encode($json);
  $json_output = utf8_encode($json_output);
  $json_output = fixBadUnicodeForJson($json_output);
  //$json_output=mb_convert_encoding($json_output,'utf-16');
  $json_path = 'public://rss-feeds/xml_data/samsung/it/videos/';
  $file_path = $json_path . 'newslist.json';
  $fp = fopen($file_path, "w");
  fwrite($fp, $json_output);
  fclose($fp);
}

function itg_generate_samsung_json_feed_video_newslist(){
  $sections = get_samsung_video_category();
  $json = array(
    'status_code' => 1,
    'status_message' => '',
    'data' => array(),
  );
  foreach($sections as $filename => $sections){
    if(is_array($sections)){
      $section_name = get_term_name_by_tid($sections[0]);
      $sections_id = $sections[0];
    }else if ($sections == 1){
      $section_name = 'Featured';
      $sections_id = 1;
    }else{
      $section_name = get_term_name_by_tid($sections);
      $sections_id = $sections;
    }
    
    $json['data']['category'][] = array(
      'id' => $sections_id,
      'title' => $section_name,
      'url' => $filename
    );
    itg_generate_samsung_json_video($filename, $sections, $section_name);
  }
  $json['data']['category'][] = array(
      'id' => 1,
      'title' => 'News',
      'url' => 'newslist.json'
    );
  $json_data = json_encode($json);
  $json_data = utf8_encode($json_data);
  $json_data = fixBadUnicodeForJson($json_data);
  //$json_data=mb_convert_encoding($json_data,'utf-16');
  $xml_path = 'public://rss-feeds/xml_data/samsung/it/videos/';
  $file_path = $xml_path . 'categorylist.json';
  $fp = fopen($file_path, "w");
  fwrite($fp, $json_data);
  fclose($fp);
}

function itg_generate_samsung_json_video($filename, $sections, $section_name){
  if(!empty($sections)){
    $type = array('videogallery');
    $query = db_select('node', 'n');
    
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_large_image', 'smi', 'smi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_source_type', 'sst', 'sst.entity_id=n.nid');
    $query->leftJoin('field_data_field_video_kicker', 'synopsis', 'synopsis.entity_id=n.nid');
    
    $section_id = 0;
    if(is_array($sections)){
      $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
      $query->condition('ti.tid', $sections, 'IN');
      $section_id = $sections[0];
    }else if ($sections != 1){
      $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
      $query->condition('ti.tid', $sections, '=');
      $section_id = $sections;
    }
    
    $query->fields('synopsis', array('field_video_kicker_value'));
    $query->fields('smi', array('field_story_large_image_fid'));
    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('ssi', array('field_story_small_image_fid'));
    $query->fields('sst', array('field_story_source_type_value'));
    
    if($days_ago = get_content_fetch_time($section_id)){
      $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
      $query->condition('n.created', $days_ago, '>=');
    }
    
    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    $query->condition('n.status', 1);
    $query->condition('n.type', 'videogallery', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 20);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    
    $jsondetail = array(
      'status_code' => 1,
      'status_message' => 'Video',
      'data' => array(
        'id' => 2,
        'title' => 'video',
      ),
    );
    foreach($result as $value){
      $nid = $value['nid'];
      $created_date = date("Y-m-d H:i:s", $value['created']);
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $large_img = get_image_info_by_fid($value['field_story_large_image_fid']);
      $source_type = $value['field_story_source_type_value'];
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_video_kicker_value']));
      
      $video_data = get_itg_video_transcoding($nid);
      $byline = get_byline_name_by_nid($nid);
      
      $duration = '';
      if (count($video_data) > 0) {
        $duration = $video_data[0]->video_duration;
      }
      $highest_bit = get_highest_bitrate_video_by_nid($nid);
      /*$bitrate_replace = '512.mp4';
      if(!empty($highest_bit)){
        $temp = array();
        $flag = 0;
        foreach($highest_bit as $value){
          $temp[] = $value['bitrate'];
          $flag++;
          if($flag == 2){
            break;
          }
        }
        $bitrate_replace = implode(',', $temp);
        $bitrate_replace = $bitrate_replace.'.mp4';
      }*/
      
      $video_url = '';
      if ($source_type == 'migrated') { //migrated video
        $videoids = get_video_in_fieldcollection_by_nid_mirtaed($nid);
        foreach ($videoids as $keys => $video_value) {
          $url = $video_value->field_migrated_video_url_value;
        }
        $data_video = itg_videogallery_get_video_bitrate_by_url($url, $nid);
        $bitrate_url = $data_video['bitrate_url'];
        $mp4_url = $data_video['file_url'];
        $video_url = $bitrate_url;
        
      }
      else {
        $videoids = get_video_in_fieldcollection_by_nid($nid);
        foreach ($videoids as $keys => $video_value) {
          if ($video_value->video_id != '') {
            $video_id = $video_value->video_id;
          } elseif ($video_value->solr_video_id != '') {
            $video_id = $video_value->solr_video_id;
          }
        }
        $inter_video_details = itg_internal_video_bitrate_data($video_id);
        $video_url = $inter_video_details['bitrate_url'];
      }
      $bitrate_rate = reverse_video_bitrate_data($video_id);
      $video_url = str_replace($bitrate_rate['matched_bitrate'],$bitrate_rate['original_bitrate'],$video_url);
      $video_url = str_replace(',156,', ',', $video_url);
      $jsondetail['data']['video'][] = array(
        'v_id' => (int)$nid,
        'v_title' => $value['title'],
        'v_credit' => FRONT_URL,
        'v_byline' => $byline,
        'v_desc' => $kicker_text,
        'v_small_image' => $small_img["imag_url"],
        'v_large_image' => $large_img["imag_url"],
        'v_download_url' => $video_url,
        'v_updated_datetime' => $created_date,
        'v_duration' => $duration,
        'v_show_ad' => 0,
      );
      
    }
    $json_data1 = json_encode($jsondetail);
    $json_data1 = utf8_encode($json_data1);
    $json_data1 = fixBadUnicodeForJson($json_data1);
    //$json_data1=mb_convert_encoding($json_data1,'utf-16');
    $xml_path1 = 'public://rss-feeds/xml_data/samsung/it/videos/';
    $file_path1 = $xml_path1 . $filename;
    $fp1 = fopen($file_path1, "w");
    fwrite($fp1, $json_data1);
    fclose($fp1);
    
    //duplicate json
    $xml_path1 = 'public://rss-feeds/xml_data/samsung/it/videos_dup/';
    $file_path1 = $xml_path1 . $filename;
    $fp1 = fopen($file_path1, "w");
    fwrite($fp1, $json_data1);
    fclose($fp1);
  }
}
function fixBadUnicodeForJson($str) {
    $str = preg_replace("/\\\\u00([0-9a-f]{2})\\\\u00([0-9a-f]{2})\\\\u00([0-9a-f]{2})\\\\u00([0-9a-f]{2})/e", 'chr(hexdec("$1")).chr(hexdec("$2")).chr(hexdec("$3")).chr(hexdec("$4"))', $str);
    $str = preg_replace("/\\\\u00([0-9a-f]{2})\\\\u00([0-9a-f]{2})\\\\u00([0-9a-f]{2})/e", 'chr(hexdec("$1")).chr(hexdec("$2")).chr(hexdec("$3"))', $str);
    $str = preg_replace("/\\\\u00([0-9a-f]{2})\\\\u00([0-9a-f]{2})/e", 'chr(hexdec("$1")).chr(hexdec("$2"))', $str);
    $str = preg_replace("/\\\\u00([0-9a-f]{2})/e", 'chr(hexdec("$1"))', $str);
    return $str;
}
