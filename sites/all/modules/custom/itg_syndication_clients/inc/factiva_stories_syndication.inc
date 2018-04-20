<?php

/**
 * @file
 * The ITG Syndication clients for factiva Story
 */
function factiva_stories_syndication() {
  $sections = get_factiva_sections();
  foreach ($sections as $section_id => $file_name) {
    itg_genrate_factiva_story_syndication($section_id, $file_name);
  }
  // now code for factiva_v1
  $sections1 = get_factiva_sections_v1();
  foreach ($sections1 as $section_id1 => $file_name1) {
    itg_genrate_factiva_story_syndication_v1($section_id1, $file_name1);
  }
}

/**
 * Function is used to generate BSB Story XML
 * @param int $section_id
 * @param string $file_name
 */
function itg_genrate_factiva_story_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    $section_name = get_term_name_by_tid($section_id);

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_short_headline', 'sheadline', 'sheadline.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');

    if ($section_id != -1) {
      $query->condition('ti.tid', $section_id, '=');
      if ($days_ago = get_content_fetch_time($section_id)) {
        $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
        $query->condition('n.created', $days_ago, '>=');
      }
    }
    else {
      $days_ago = strtotime(date('Y-m-d', strtotime('-10 days')));
      $query->condition('n.created', $days_ago, '>=');
    }

    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');

    $query->fields('n', array('nid', 'title', 'created', 'changed'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('sheadline', array('field_story_short_headline_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));

    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 30);

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_factiva_story_syndication_xml($result, $section_name);
    $xml_path = 'public://factiva/stories/';
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
 * @return string
 */
function genrate_factiva_story_syndication_xml($result = NULL, $category) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<artical>';
    $xml .= '<magazine>India Today Online</magazine>';
    $xml .= '<frequency>Daily</frequency>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $byline = get_byline_name_by_nid($value['nid']);
      $byline = empty($byline) ? 'IndiaToday.in' : $byline;
      $publish_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_tags_from_body($body);
      $body = itg_remove_extra_custom_tags($body);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));

      $xml .= '<section>India Today Online</section>';
      $xml .= '<edition>' . $publish_date . '</edition>';
      $xml .= '<byline>' . $byline . '</byline>';
      $xml .= '<headline>' . $value['field_story_short_headline_value'] . '</headline>';
      $xml .= '<introtext>' . $kicker_text . '</introtext>';
      $xml .= '<bodytext>' . $body . '</bodytext>';
      $xml .= '<copyright>Reproduced From India Today Online. Copyright ' . date("Y") . '. LMIL. All rights reserved.</copyright>';
    }
    $xml .= '</artical>';
  }

  return $xml;
}
/**
 * Function is used to generate factiva_v2 Story Rss
 * @param int $section_id
 * @param string $file_name
 */
function itg_genrate_factiva_story_syndication_v1($section_id = NULL, $file_name) {
    if (!empty($section_id)) {
        $section_name = get_term_name_by_tid($section_id);
        $query = db_select('node', 'n');
        $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
        $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
        $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
        $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
        $query->leftJoin('field_data_field_story_medium_image', 'smi', 'smi.entity_id=n.nid');
        $query->fields('n', array('nid', 'title', 'created', 'changed'));
        $query->fields('npd', array('field_itg_content_publish_date_value'));
        $query->fields('dbody', array('body_value'));
        $query->fields('smi', array('field_story_medium_image_fid'));
        $interval = itg_app_time_interval($section_id);        
        $days_ago = strtotime(date('Y-m-d', strtotime('-'.$interval.' days')));
        $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
        $query->condition('n.created', $days_ago, '>=');
        $query->condition('ti.tid', $section_id, '=');
        $query->condition('n.status', 1);
        $query->condition('n.type', 'story', '=');
        $query->orderBy('n.created', 'DESC');
        $query->groupBy('n.nid')->range(0, 25);
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        $xml = genrate_factiva_story_syndication_xml_v1($result, $section_name, $section_id);
        $xml_path = 'public://rss-feeds/xml_data/factiva/it/stories/';
        file_prepare_directory($xml_path, FILE_CREATE_DIRECTORY);
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
 * @return string
 */
function genrate_factiva_story_syndication_xml_v1($result = NULL, $category, $sid) {
    $xml = '';
    if (!empty($result)) {
        global $base_url;
        $logo = FRONT_URL.'/sites/all/themes/itg/logo.png'; //theme_get_setting('logo');
        $cat_link = FRONT_URL . "/" . drupal_get_path_alias('taxonomy/term/' . $sid);
        $xml .= '<rss xmlns:content="http://purl.org/rss/1.0/modules/content/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" version="2.0">';
        $xml .= '<channel>';
        $xml .= '<title><![CDATA[ India Today Latest News]]></title>';
        $xml .= '<description><![CDATA[ India Today ]]></description>';
        $xml .= '<link>' . FRONT_URL . '</link>';

        $xml .= '<image>';
        $xml .= '<url>' . $logo . '</url>';
        $xml .= '<title><![CDATA[ India Today Latest News ]]></title>';
        $xml .= '<link>' . FRONT_URL . '</link>';
        $xml .= '</image>';
        foreach ($result as $key => $value) {
            if (is_lock_story($value['nid'])) {
                continue;
            }
            $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
            $pub_date = date("D, j M Y H:i:s", strtotime($value['field_itg_content_publish_date_value']));
            $body = remove_extra_tag_in_body_v1($value["body_value"]);
            $body = itg_replace_token_with_data($body, $value['nid']);
            $body = itg_remove_extra_custom_tags($body);
            $body = stripInvalidXml($body);
            $medium_img = get_image_info_by_fid($value['field_story_medium_image_fid']);
            $byline = get_byline_name_by_nid($value['nid']);
            $uniq_id = "indiatoday.in" . $value['nid'];
            $guid = itg_genrate_uniqui_guid($uniq_id);
            $medium_img["imag_url"] = empty($medium_img["imag_url"]) ? $logo : $medium_img["imag_url"];
            $xml .= '<item>';
            $xml .= '<title><![CDATA[' . stripInvalidXml($value['title']) . ']]></title>';
            $xml .= '<guid isPermaLink="false">' . $guid . '</guid>';
            $xml .= '<description><![CDATA[' . $body . ']]></description>';
            $xml .= '<pubDate>' . $pub_date . ' +0000</pubDate>';
            $xml .= '<link>' . $url . '</link>';
            $xml .= '<dc:creator><![CDATA[' . $byline . ']]></dc:creator>';
            $xml .= '<media:thumbnail url = "' . $medium_img["imag_url"] . '"></media:thumbnail>';
            $xml .= '</item>';
        }
        $xml .= '</channel>';
        $xml .= '</rss>';
    }

    return $xml;
}
/**
 * remove_extra_tag_in_body_v1
 * @param type $story_body
 * @return type
 */
function remove_extra_tag_in_body_v1($story_body) {
  // remove survey
  if (strpos($story_body, '[ITG:SURVEY:')) {
    if (preg_match('/ITG:SURVEY:([0-9]+)/', $story_body, $matches_survey)) {
      $survey_nid = $matches_survey[1];
    }
    $story_body = str_replace('[ITG:SURVEY:' . $survey_nid . ']', '', $story_body);
  }
  // remove quiz
  if (strpos($story_body, '[ITG:QUIZ:')) {
    if (preg_match('/ITG:QUIZ:([0-9]+)/', $story_body, $matches_quiz)) {
      $quiz_nid = $matches_quiz[1];
    }
    $story_body = str_replace('[ITG:QUIZ:' . $quiz_nid . ']', '', $story_body);
  }
  // remove poll
  if (strpos($story_body, '[ITG:POLL:')) {
    if (preg_match('/ITG:POLL:([0-9]+)/', $story_body, $matches_poll)) {
      $poll_nid = $matches_poll[1];
    }
    $story_body = str_replace('[ITG:POLL:' . $poll_nid . ']', '', $story_body);
  }
  
  // remove FACTOIDS
  if (strpos($story_body, '[ITG:FACTOIDS]')) {
      $story_body = str_replace('[ITG:FACTOIDS]', '', $story_body);
  }
  
  // remove LISTICLES
  if (strpos($story_body, '[ITG:LISTICLES]')) {
      $story_body = str_replace('[ITG:LISTICLES]', '', $story_body);
  }
  

  // some tags remove
  /*$tags = array("table", "div");

  return preg_replace('#<(' . implode('|', $tags) . ')(?:[^>]+)?>.*?</\1>#s', '', $story_body);*/
  
    // remove div
    $patterns = array();
    $patterns[0] = '/<div[^>]*>/';
    $patterns[1] = '/<\/div>/';
    $replacements = array();
    $replacements[2] = '';
    $replacements[1] = '';
    $story_body = preg_replace($patterns, $replacements, $story_body);
    // remove iframe
    $story_body = preg_replace('/<iframe.*?\/iframe>/i','', $story_body);
    //remove table
    $pattern= '/<table[^>]*>.*?<\/table>/s';
    $story_body= preg_replace($pattern, '', $story_body, 1);
    return $story_body;
    
}
