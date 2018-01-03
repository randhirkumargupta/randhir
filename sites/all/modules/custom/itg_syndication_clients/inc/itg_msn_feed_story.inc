<?php

/**
 * @file
 * The ITG Syndication clients for MSN Story
 */
function itg_msn_feed_story_syndication() {
  $sections = getmsn_story_section_array();
  foreach ($sections as $file_name => $section_id) {
    itg_genrate_msn_feed_story_syndication($section_id, $file_name);
  }
}

/**
 * menu callback
 * Function for generate msn static feed
 */
function itg_rss_msnstaticfeeds() {
  itg_generate_msn_static_stories_what_to_expect();
  itg_generate_msn_static_stories_top_news();
}

/**
 * Generate static msn stories feed
 */
function itg_generate_msn_static_stories_what_to_expect() {
  $data = array();
  $xml = theme('msn_static_stories_what_to_expect', array('data' => $data));
  $xml_path = 'public://msn/stories/';
  $file_path = $xml_path . 'what-to-expect-msn.xml';
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $xml);
  fclose($fpd);
}

/**
 * Generate static msn stories feed
 */
function itg_generate_msn_static_stories_top_news() {
  $data = array();
  $xml = theme('msn_static_stories_top_news', array('data' => $data));
  $xml_path = 'public://msn/stories/';
  $file_path = $xml_path . 'top-news-msn.xml';
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $xml);
  fclose($fpd);
}

/**
 * Function is used to Generate MSN xml feed
 * @param int $section_id
 * @param string $file_name
 */
function itg_genrate_msn_feed_story_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    $section_name = get_terms_name_by_ids(array($section_id));
    $section_name = $section_name[0]['name'];
    $type = array('story');
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');

    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    $query->condition('ti.tid', $section_id, '=');
    $query->fields('n', array('nid', 'title', 'created', 'changed'));
    $query->fields('dbody', array('body_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));


    $query->condition('n.status', 1);
    $query->condition('n.type', $type, 'IN');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 20);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_msn_feed_story_syndication_xml($result, $section_name);
    $xml_path = 'public://';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

/**
 * 
 * @global string $base_url
 * @param Array $result
 * @param string $category
 * @return string
 */
function genrate_msn_feed_story_syndication_xml($result = NULL, $category) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $current_date = date("Ymd\THisP");
    $xml = '<NewsML>';
    $xml .= '<NewsEnvelope>';
    $xml .= '<DateAndTime>' . $current_date . '</DateAndTime>';
    $xml .= '</NewsEnvelope>';

    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $nid = $value['nid'];
      $publish_date = date("Ymd\THisP", $value['created']);
      $modify_date = date("Ymd\THisP", $value['changed']);
      $reporter = get_byline_name_by_nid($nid);
      if (empty($reporter)) {
        $reporter = 'IndiaToday.in';
      }
      $url = $base_url . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $body = remove_extra_tag_in_body($value["body_value"]);

      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $title = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['title']));

      $year = date('Y');
      $xml .= '<NewsItem LinkType="normal">';
      $xml .= '<Identification>';
      $xml .= '<NewsIdentifier>';
      $xml .= '<ProviderId>' . $reporter . '</ProviderId>';
      $xml .= '</NewsIdentifier>';
      $xml .= '</Identification>';
      $xml .= '<NewsManagement>';
      $xml .= '<NewsItemType FormalName="News"/>';
      $xml .= '<FirstCreated>' . $publish_date . '</FirstCreated>';
      $xml .= '<ThisRevisionCreated>' . $modify_date . '</ThisRevisionCreated>';
      $xml .= '<Status FormalName="Usable"/>';
      $xml .= '</NewsManagement>';
      $xml .= '<NewsComponent EquivalentsList="no" Essential="no" Duid="' . $nid . '">';
      $xml .= '<NewsLines>';
      $xml .= '<CopyrightLine>' . $year . ' India Today.</CopyrightLine>';
      $xml .= '</NewsLines>';
      $xml .= '<NewsComponent Duid="' . $nid . '">';
      $xml .= '<DateLine>' . $publish_date . '</DateLine>';
      $xml .= '<Author>' . $reporter . '</Author>';
      $xml .= '<NewsComponent>';
      $xml .= '<Role FormalName="Main"/>';
      $xml .= '<NewsLines>';
      $xml .= '<HeadLine>' . $title . '</HeadLine>';
      $xml .= '<SlugLine>' . $kicker_text . '</SlugLine>';
      $xml .= '<MoreLink/>';
      $xml .= '</NewsLines>';
      $xml .= '<ContentItem>';
      $xml .= '<MediaType FormalName="ComplexData"/>';
      $xml .= '<MimeType FormalName="text/vnd.IPTC.NITF"/>';
      $xml .= '<DataContent>';
      $xml .= '<nitf>';
      $xml .= '<body>';
      $xml .= '<body.content><![CDATA[' . $body . ']]></body.content>';
      $xml .= '</body>';
      $xml .= '</nitf>';
      $xml .= '<weburl>' . $url . '</weburl>';
      $xml .= '</DataContent>';
      $xml .= '</ContentItem>';
      $xml .= '</NewsComponent>';
      $xml .= '</NewsComponent>';
      $xml .= '</NewsComponent>';
      $xml .= '</NewsItem>';
    }
    $xml .= '</NewsML>';
  }
  return $xml;
}
