<?php

/**
 * @file
 * The ITG Syndication clients for factiva Story
 */
function syndication_interface_cms() {
  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'title', 'created'));
  $query->condition('n.status', 1);
  $query->condition('n.type', 'issue');
  $query->orderBy('n.nid', "DESC");
  $query->range(0, 1);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  itgd_genrate_factiva_syndication($result);
}

/**
 * Function is used to generate factiva Story XML
 * @param int $section_id
 * @param string $file_name
 */
function itgd_genrate_factiva_syndication($issue_result) {
  if (!empty($issue_result)) {
    $issue_title = date('F d, Y', strtotime($issue_result[0]['title']));
    $title = $issue_result[0]['title'];
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('field_data_field_story_issue_date', 'isuue', 'n.nid=isuue.entity_id');
    $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
    $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->condition('isuue.field_story_issue_date_value', $title, '=');
    $query->condition('n.type', 'story', '=');
    $query->groupBy('n.nid');
    $query->orderBy('n.created', 'DESC');
    $query->fields('dbody', array('body_value'));
    $query->fields('pc', array('field_primary_category_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('kt', array('field_story_kicker_text_value'));
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    genrate_factiva_latest_issue_xml($result, $issue_title, $issue_result);
    genrate_para_text_latest_issue_xml($result, $issue_title, $issue_result);
    genrate_syndication_xml_latest_issue_xml($result, $issue_title, $issue_result);
  }
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param string $category
 * @return string
 */
function genrate_factiva_latest_issue_xml($result, $issue_title, $issue_result) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<artical>';
    $xml .= '<magazine>India Today</magazine>';
    $xml .= '<frequency>Weekly</frequency>';
    foreach ($result as $key => $value) {
      $primary_cat = get_term_name_by_tid($value['field_primary_category_value']);
      $byline = get_byline_name_by_nid($value['nid']);
      $byline = empty($byline) ? 'IndiaToday.in' : $byline;
      $publish_date = date("F d, Y", strtotime($issue_title));
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_remove_tags_from_body($body);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));

      $xml .= '<section>' . $primary_cat . '</section>';
      $xml .= '<edition>' . $publish_date . '</edition>';
      $xml .= '<byline>' . $byline . '</byline>';
      $xml .= '<headline>' . $value['field_story_short_headline_value'] . '</headline>';
      $xml .= '<introtext>' . $kicker_text . '</introtext>';
      $xml .= '<bodytext>' . $body;
      $xml .= '<copyright>Reproduced From India Today Online. Copyright ' . date("Y") . '. LMIL. All rights reserved.</copyright>';
      $xml .= '</bodytext>';
    }
    $xml .= '</artical>';
  }
  $xml_path = 'public://syndications/';
  $file_path = $xml_path . 'factiva-latest-issue.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param string $category
 * @return string
 */
function genrate_para_text_latest_issue_xml($result, $issue_title, $issue_result) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;



    foreach ($result as $key => $value) {
      $primary_cat = get_term_name_by_tid($value['field_primary_category_value']);
      $byline = get_byline_name_by_nid($value['nid']);
      $byline = empty($byline) ? 'IndiaToday.in' : $byline;
      $publish_date = date("F d, Y", strtotime($issue_title));
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_remove_tags_from_body($body);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $xml .= '<article>';
      $xml .= '<magazine>India Today</magazine>';
      $xml .= '<articletype>' . $primary_cat . '</articletype>';
      $xml .= '<edition>' . $publish_date . '</edition>';
      $xml .= '<page></page>';
      $xml .= '<frequency>Weekly</frequency>';
      $xml .= '<author></author>';
      $xml .= '<byline>' . $byline . '</byline>';
      $xml .= '<volumenumber></volumenumber>';
      $xml .= '<intellectualpropertyowner>Living Media India Limited</intellectualpropertyowner>';
      $xml .= '<headline>' . $value['field_story_short_headline_value'] . '</headline>';
      $xml .= '<secondaryheadline>' . $kicker_text . '</secondaryheadline>';
      $xml .= '<bodytext>' . $body . '</bodytext>';
      $xml .= '</article>';
    }
  }
  $xml_path = 'public://syndications/';
  $file_path = $xml_path . 'para-feed.txt';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param string $category
 * @return string
 */
function genrate_syndication_xml_latest_issue_xml($result, $issue_title, $issue_result) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $publish_date = date("F d, Y", strtotime($issue_title));
    $xml = '<?xml version="1.0" encoding="ISO-8859-1"?>';
    $xml .= '<root>';
    $xml .= '<magazine>India Today</magazine>';
    $xml .= '<frequency>Weekly</frequency>';
    $xml .= '<edition>' . $publish_date . '</edition>';
    $xml .= '<items>';
    foreach ($result as $key => $value) {
      $primary_cat = get_term_name_by_tid($value['field_primary_category_value']);
      $byline = get_byline_name_by_nid($value['nid']);
      $byline = empty($byline) ? 'IndiaToday.in' : $byline;
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_remove_tags_from_body($body);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));

      $xml .= '<section name="' . $primary_cat . '">';
      $xml .= '<article>';
      $xml .= '<headline>' . $value['field_story_short_headline_value'] . '</headline>';
      $xml .= '<byline>' . $byline . '</byline>';
      $xml .= '<introtext>' . $kicker_text . '</introtext>';
      $xml .= '<bodytext>' . $body . '</bodytext>';
      $xml .= '<copyright>Reproduced From India Today Online. Copyright ' . date("Y") . '. LMIL. All rights reserved.</copyright>';
      $xml .= '</article>';
      $xml .= '</section>';
    }
    $xml .= '</items>';
  }
  $xml .= '</root>';
  $xml_path = 'public://syndications/';
  $file_path = $xml_path . 'syndication-xml-latest-issue.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}
