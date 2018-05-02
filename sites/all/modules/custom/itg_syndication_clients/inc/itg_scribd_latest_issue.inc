<?php

/**
 * @file
 * The ITG Syndication clients for Scribd Story Issue
 */

/**
 * Function for generate scribd latest issue
 */
function itg_scribd_feed_latest_issue() {
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_issue_large_cover_image', 'fsli', 'fsli.entity_id=n.nid');
  $query->fields('n', array('nid', 'title', 'created'));
  $query->fields('fsli', array('field_issue_large_cover_image_fid'));
  $query->condition('n.status', 1);
  $query->condition('n.type', 'issue');
  $query->orderBy('n.nid', "DESC");
  $query->range(0, 1);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  itg_genrate_scribd_latest_issue_syndication($result);
}

/**
 * 
 * @param array $issue_result
 */
function itg_genrate_scribd_latest_issue_syndication($issue_result = NULL) {
  if (!empty($issue_result)) {
    $issue_title = date('F d, Y', strtotime($issue_result[0]['title']));
    $title = $issue_result[0]['title'];
    $field_issue_large_cover_image_fid = $issue_result[0]['field_issue_large_cover_image_fid'];
    $query = db_select('node', 'n');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->join('field_data_field_story_issue_date', 'isuue', 'n.nid=isuue.entity_id');
    $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'smi', 'smi.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    $query->condition('isuue.field_story_issue_date_value', $title, '=');
    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    $query->groupBy('n.nid');
    $query->orderBy('n.created', 'DESC')->range(0, 30);
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('smi', array('field_story_medium_image_fid'));
    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('kt', array('field_story_kicker_text_value'));
    $query->fields('dbody', array('body_value'));
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_scribd_latest_issue_syndication_xml($result, $issue_title, $issue_result, $field_issue_large_cover_image_fid);
    $xml_path = 'public://rss-feeds/xml_data/scribd/it/stories/';
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
function genrate_scribd_latest_issue_syndication_xml($result = NULL, $issue_title, $issue_result, $field_issue_large_cover_image_fid) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $issue_title_n = "India Today Magazine - ".$issue_title;
    $issue_identifier = $issue_title;
    //$issue_cover_image = getIssueCoverImgScribed($issue_title);
    $issue_cover_image = completeFilePath($field_issue_large_cover_image_fid);
    $xml = '<rss xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" xmlns:content="http://purl.org/rss/1.0/modules/content/" version="2.0">';
    $xml .= '<channel>';
    $xml .= '<title><![CDATA[' . $issue_title . ']]></title>';
    $xml .= '<link><![CDATA[' . FRONT_URL . ']]></link>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $nid = $value['nid'];
      $publish_date = date("Y-m-d H:i", strtotime($value['field_itg_content_publish_date_value']));
      $author = get_byline_name_by_nid($nid);
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_extra_custom_tags($body);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $medium_img = get_image_info_by_fid($value['field_story_medium_image_fid']);
      $issue_cover_image_ar = explode("?",$issue_cover_image);
      $medium_img_ar = explode("?",$medium_img["imag_url"]);
      $xml .= '<item>';      
      $xml .= '<issue_title><![CDATA[' . $issue_title_n . ']]></issue_title>';
      $xml .= '<issue_identifier><![CDATA[' . $issue_identifier . ']]></issue_identifier>';
      $xml .= '<issue_cover_image>'.$issue_cover_image_ar[0].'</issue_cover_image>';      
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<pubdate>' . $publish_date . '</pubdate>';
      $xml .= '<author><![CDATA[' . $author . ']]></author>';
      $xml .= '<imgUrl>' . $medium_img_ar[0] . '</imgUrl>';
      $xml .= '<link><![CDATA[' . $url . ']]></link>';
      $xml .= '<description><![CDATA[' . $kicker_text . ']]></description>';
      $xml .= '<content:encoded><![CDATA[' . $body . ']]></content:encoded>';
      $xml .= '</item>';
    }
    $xml .= '</channel>';
    $xml .= '</rss>';
  }
  return $xml;
}
