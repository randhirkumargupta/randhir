<?php

/**
 * @file
 * The ITG Syndication clients for IT latest Issue Story
 */
function itg_rss_it_latest_issue_article() {
  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'title', 'created'));
  $query->condition('n.status', 1);
  $query->condition('n.type', 'issue');
  $query->orderBy('n.nid', "DESC");
  $query->range(0, 1);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  itg_genrate_rss_it_latest_issue_syndication($result);
}

/**
 * Function for generate latest issue xml
 * @param array $issue_result
 */
function itg_genrate_rss_it_latest_issue_syndication($issue_result = NULL) {
  if (!empty($issue_result)) {
    $issue_title = date('Y-m-d H:i', strtotime($issue_result[0]['title']));
    $title = $issue_result[0]['title'];
    $query = db_select('node', 'n');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->join('field_data_field_story_issue_date', 'isuue', 'n.nid=isuue.entity_id');
    $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'smi', 'smi.entity_id=n.nid');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    $query->condition('isuue.field_story_issue_date_value', $title, '=');
    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    $query->groupBy('n.nid');
    $query->orderBy('n.created', 'DESC');
    $query->fields('dbody', array('body_value'));
    $query->fields('smi', array('field_story_medium_image_fid'));
    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('kt', array('field_story_kicker_text_value'));
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_rss_it_latest_issue_syndication_xml($result, $issue_title, $issue_result);
    $xml_path = 'public://indiatoday/rss/';
    $file_path = $xml_path . 'it-latest-issue.xml';
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param string $issue_title
 * @param array $issue_result
 * @return string
 */
function genrate_rss_it_latest_issue_syndication_xml($result = NULL, $issue_title, $issue_result) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<rss xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" xmlns:content="http://purl.org/rss/1.0/modules/content/" version="2.0">';
    $xml .= '<channel>';
    $xml .= '<title><![CDATA[ India Today | Magazine ]]></title>';
    $xml .= '<link><![CDATA[' . FRONT_URL . ']]></link>';
    $xml .= '<pubdate>' . $issue_title . '</pubdate>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $nid = $value['nid'];
      $author = get_byline_name_by_nid($nid);
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_extra_custom_tags($body);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $medium_img = get_image_info_by_fid($value['field_story_medium_image_fid']);
      $xml .= '<item>';
      $xml .= '<title>' . $value['title'] . '</title>';
      $xml .= '<author><![CDATA[' . $author . ']]></author>';
      $xml .= '<imgUrl>' . $medium_img["imag_url"] . '</imgUrl>';
      $xml .= '<link><![CDATA[' . $url . ']]></link>';
      $xml .= '<description><![CDATA[' . $kicker_text . ']]></description>';
      $xml .= '<text><![CDATA[' . $body . ']]></text>';
      $xml .= '</item>';
    }
    $xml .= '</channel>';
    $xml .= '</rss>';
  }
  return $xml;
}
