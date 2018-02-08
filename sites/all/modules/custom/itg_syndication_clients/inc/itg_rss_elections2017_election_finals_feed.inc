<?php

/**
 * @file
 * The ITG Syndication clients for Hltapps
 */

/**
 * Menu callback
 */
function itg_rss_elections2017_election_finals_feed() {
  $sections = get_elections2017_election_finals_sections();
  $xml = '';
  $xml .= '<xml>';
  $xml .= '<status>1</status>';
  $xml .= '<name>Assembly Elections 2017</name>';
  $xml .= '<bannerurl>http://electionresults.intoday.in/elections/2017/banner-elections.xml</bannerurl>';
  $xml .= '<livetv>http://feeds.intoday.in/hltapps/api/livetv_test.xml</livetv>';
  $xml .= '<details>';
  foreach ($sections as $section_id => $section_name) {
    $xml .= itg_genrate_elections2017_election_finals_syndication($section_id, $section_name);
  }
  $xml .= '</details>';
  $xml .= '</xml>';
  $xml_path = 'public://elections2017/xml/';
  $file_path = $xml_path . 'election-finals.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * 
 * @param int $section_id
 * @param string $section_name
 * @return string
 */
function itg_genrate_elections2017_election_finals_syndication($section_id = NULL, $section_name) {
  $xml_d = '';
  if (!empty($section_id)) {
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_large_image', 'sli', 'sli.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'smi', 'smi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_courtesy', 'sc', 'sc.entity_id=n.nid');
    $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id=n.nid');

    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->condition('ti.tid', $section_id, '=');
    if($days_ago = get_content_fetch_time($section_id)){
      $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
      $query->condition('n.created', $days_ago, '>=');
    }
    $query->fields('n', array('nid', 'title', 'created', 'changed'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('sli', array('field_story_large_image_fid'));
    $query->fields('ssi', array('field_story_small_image_fid'));
    $query->fields('smi', array('field_story_medium_image_fid'));
    $query->fields('sc', array('field_story_courtesy_value'));
    $query->fields('pc', array('field_primary_category_value'));

    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 4);

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml_d = genrate_elections2017_election_finals_xml($result, $section_name, $section_id);
  }
  return $xml_d;
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param string $category
 * @param int $section_id
 * @return string
 */
function genrate_elections2017_election_finals_xml($result = NULL, $category, $section_id) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<state>';
    $xml .= '<name>' . $category . '</name>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $nid = $value['nid'];
      $content_url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value["nid"]);
      $xml_story_file = 'story' . $nid . '.xml';
      $xml .= '<nlink>';
      $xml .= '<news>';
      $xml .= '<title><![CDATA[ ' . $value["title"] . ' ]]></title>';
      $xml .= '<link><![CDATA[ ' . $content_url . ' ]]></link>';
      $xml .= '<url>' . $xml_story_file . '</url>';
      $xml .= '</news>';
      $xml .= '</nlink>';
      genrate_elections2017_election_finals_detail_xml($value, $category, $xml_story_file, $section_id);
    }
    $xml .= '<tally>' . get_state_tally($category) . '</tally>';
    $xml .= '</state>';
  }
  return $xml;
}

/**
 * function used to get static xml url
 * @param string $state
 * @return string
 */
function get_state_tally($state) {
  switch ($state) {
    case 'UP':
      return 'http://electionresults.intoday.in/elections/2017/xml/party-tally/uttar_pradesh-assembly-party-tally-itapp.xml';
      break;
    case 'punjab':
      return 'http://electionresults.intoday.in/elections/2017/xml/party-tally/punjab-assembly-party-tally-itapp.xml';
      break;
    case 'Goa':
      return 'http://electionresults.intoday.in/elections/2017/xml/party-tally/goa-assembly-party-tally-itapp.xml';
      break;
    case 'Manipur':
      return 'http://electionresults.intoday.in/elections/2017/xml/party-tally/manipur-assembly-party-tally-itapp.xml';
      break;
    case 'uttarakhand':
      return 'http://electionresults.intoday.in/elections/2017/xml/party-tally/uttarakhand-assembly-party-tally-itapp.xml';
      break;
    default:
      return '';
  }
}

/**
 * 
 * @global string $base_url
 * @param array $value
 * @param string $category
 * @param string $xml_story_file
 * @param int $section_id
 */
function genrate_elections2017_election_finals_detail_xml($value, $category, $xml_story_file, $section_id) {
  global $base_url;
  $date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
  $publish_date = date("Y-m-d\TH:i:sP", strtotime($value['field_itg_content_publish_date_value']));
  $byline = get_byline_name_by_nid($value['nid']);
  $place = get_content_city($value['nid']);
  $body = remove_extra_tag_in_body($value["body_value"]);
  $body = itg_replace_token_with_data($body, $value['nid']);
  $body = itg_remove_extra_custom_tags($body);
  $sectionname = get_term_name_by_tid($section_id);
  $content_url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value["nid"]);
  $courtesy = $value['field_story_courtesy_value'];
  $related = related_content_node_type($value['nid'], 'story');
  $xml_detail = '<Root>';
  $xml_detail .= '<item>';
  $xml_detail .= '<storyid>' . $value["nid"] . '</storyid>';
  $xml_detail .= '<idsection>' . $value['field_primary_category_value'] . '</idsection>';
  $xml_detail .= '<section>' . $sectionname . '</section>';
  $xml_detail .= '<headline><![CDATA[ ' . $value["title"] . ' ]]></headline>';
  $xml_detail .= '<credit><![CDATA[ ' . $byline . ' ]]></credit>';
  $xml_detail .= '<date> ' . $date . '</date>';
  $xml_detail .= '<datetime> ' . $publish_date . ' </datetime>';
  $xml_detail .= '<city><![CDATA[' . $place . ' ]]></city>';
  $xml_detail .= '<courtesy><![CDATA[' . $courtesy . ' ]]></courtesy>';
  $xml_detail .= '<body><![CDATA[' . $body . ' ]]></body>';
  $xml_detail .= '<body_android><![CDATA[' . $body . ' ]]></body_android>';
  $xml_detail .= get_video_embed_tags($value["body_value"]);
  $xml_detail .= get_img_tag_detail($value);
  $xml_detail .= '<weburl><![CDATA[' . $content_url . ' ]]></weburl>';
  $xml_detail .= '<related>';
  $xml_detail .= '<stories>' . $related['stories'] . '</stories>';
  $xml_detail .= '<photos>' . $related['photos'] . '</photos>';
  $xml_detail .= '<videos>' . $related['videos'] . '</videos>';
  $xml_detail .= '</related>';
  $xml_detail .= get_comment_xml_tag($value['nid']);
  $xml_detail .= '</item>';
  $xml_detail .= '</Root>';
  $xml_path = 'public://elections2017/xml/';
  $file_path = $xml_path . $xml_story_file;
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $xml_detail);
  fclose($fpd);
}
