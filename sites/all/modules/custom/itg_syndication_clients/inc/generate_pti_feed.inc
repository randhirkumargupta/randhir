<?php

/**
 * unction for Generate Article xml feed
 * @global string $base_url
 */
function itg_generate_pti_feed() {
  $sid = 1206640; // PTI Feed id
  $section_name = get_term_name_by_tid($sid);
  $type = array('story');
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');

  $query->fields('n', array('nid', 'title', 'created', 'changed'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('dbody', array('body_value'));
  $days_ago = strtotime(date('Y-m-d', strtotime('-10 minutes')));
  $query->condition('n.created', $days_ago, '>=');

  $query->condition('ti.tid', $sid, '=');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 25);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $xml = get_generate_pti_xml($result, $sid, $section_name);
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param int $sid
 * @param string $section_name
 * @return string
 */
function get_generate_pti_xml($result, $sid, $section_name) {
  if (!empty($result)) {
    $logo = theme_get_setting('logo');
    $xml_path = 'public://agencies/PTI_TVTN/';
    foreach ($result as $key => $value) {
      $pub_date = date("D, j M Y, H:i:s", strtotime($value['field_itg_content_publish_date_value']));
      $pub_dateutc = date("Ymd\THisP", strtotime($value['field_itg_content_publish_date_value'] . " UTC"));
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_remove_tags_from_body($body);
      $body = itg_remove_extra_custom_tags($body);
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);

      $file_name = 'pti-story-' . $value['nid'];
      $xml = '';
      $xml .= '<rss>';
      $xml .= '<channel>';
      $xml .= '<title>PTI</title>';
      $xml .= '<link> ' . $url . '</link>';
      $xml .= '<image>';
      $xml .= '<title>PTI</title>';
      $xml .= '<url>' . $logo . '</url>';
      $xml .= '<link>' . FRONT_URL . '</link>';
      $xml .= '<width></width>';
      $xml .= '<height></height>';
      $xml .= '</image>';

      $xml .= '<item>';
      $xml .= '<title>' . $value['title'] . '</title>';
      $xml .= '<author>PTI</author>';
      $xml .= '<enclosure></enclosure>';
      $xml .= '<description><![CDATA[' . $body . ']]></description>';
      $xml .= '<category>PTI</category>';
      $xml .= '<source>PTI</source>';
      $xml .= '<guid>' . $file_name . '</guid>';
      $xml .= '<pubdate>' . $pub_date . '</pubdate>';
      $xml .= '<pubdate_utc>' . $pub_dateutc . '</pubdate_utc>';
      $xml .= '</item>';
      $xml .= '</channel>';
      $xml .= '</rss>';

      $file_path = $xml_path . $file_name . '.xml';
      $fp = fopen($file_path, "w");
      fwrite($fp, $xml);
      fclose($fp);
    }
  }
}
