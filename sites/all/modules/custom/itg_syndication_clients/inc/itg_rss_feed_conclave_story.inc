<?php

/**
 * Function for GEnerate Conclave story feed
 * @global string $base_url
 */
function itg_rss_conclave_story_syndication() {
  global $base_url;
  $sid = 1206584; // need to change conclave category

  $section_name = get_term_name_by_tid($sid);
  $type = array('story');
  $query = db_select('node', 'n');

  $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
  $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
  $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_large_image', 'sli', 'sli.entity_id=n.nid');

  $query->fields('n', array('nid', 'title', 'created', 'changed'));
  $query->fields('synopsis', array('field_story_kicker_text_value'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('sli', array('field_story_large_image_fid'));
  
  if($days_ago = get_content_fetch_time($sid)){
    $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
    $query->condition('n.created', $days_ago, '>=');
  }
  
  $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
  $query->condition('ti.tid', $sid, '=');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 25);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $xml = get_rss_conclave_story_sid_xml($result, $sid, $section_name);

  $xml_path = 'public://xml/conclave/stories/';
  $file_path = $xml_path . 'conclave_story.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param int $sid
 * @param string $section_name
 * @return string
 */
function get_rss_conclave_story_sid_xml($result, $sid, $section_name) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $logo = theme_get_setting('logo');
    $xml .= '<rss xmlns:atom="http://www.w3.org/2005/Atom" xmlns:media="http://conclave.intoday.in/2017/44/index.html/" version="2.0">';
    $xml .= '<channel>';
    $xml .= '<atom:link type="application/rss+xml" rel="self" href="http://feeds.intoday.in/xml/conclave/stories/conclave_story.xml"/>';
    $xml .= '<title>India Today - Jio</title>';
    $xml .= '<link>http://conclave.intoday.in/</link>';
    $xml .= '<description>Conclave updates from ' . FRONT_URL . ' for Jio </description>';
    $xml .= '<language>en-gb</language><copyright></copyright><docs>http://conclave.intoday.in/</docs>';
    $xml .= '<image>';
    $xml .= '<title>India Today - Jio</title>';
    $xml .= '<link>http://conclave.intoday.in/</link>';
    $xml .= '<url>' . $logo . '</url>';
    $xml .= '</image>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $pub_date = date("Y-m-d\TH:i:sP", strtotime($value['field_itg_content_publish_date_value']));
      $kicker_text = $value['field_story_kicker_text_value'];
      $large_img = get_image_info_by_fid($value['field_story_large_image_fid']);
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<description><![CDATA[' . $kicker_text . ']]></description>';
      $xml .= '<link><![CDATA[' . $url . ']]></link>';
      $xml .= '<guid><![CDATA[' . $url . ']]></guid>';
      $xml .= '<pubDate><![CDATA[' . $pub_date . ']]></pubDate>';
      $xml .= '<media:content url="' . $large_img["imag_url"] . '" medium="image" height="350" width="225"></media:content>';
      $xml .= '</item>';
    }
    $xml .= '</channel>';
    $xml .= '</rss>';
    return $xml;
  }
  else {
    return not_found_syndication_xml();
  }
}
