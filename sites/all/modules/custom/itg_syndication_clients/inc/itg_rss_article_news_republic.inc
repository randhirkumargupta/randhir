<?php

/**
 * Function is used to generate story feed
 */
function itg_rss_article_news_republic() {

  $sid = $_GET['sid'];
  $query = db_select('node', 'n');
  $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $query->fields('n', array('nid', 'title', 'created'));
  $query->fields('dbody', array('body_value'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('kt', array('field_story_kicker_text_value'));
  $query->fields('eli', array('field_story_extra_large_image_fid'));

  $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  if (!empty($sid)) {
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->condition('ti.tid', $sid, '=');
    if ($days_ago = get_content_fetch_time($sid)) {
      $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
      $query->condition('n.created', $days_ago, '>=');
    }
  }
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 25);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $xml = get_rss_article_news_republic_xml($result);
  header('Content-Type: text/xml');
  print $xml;
  drupal_exit();
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @return string
 */
function get_rss_article_news_republic_xml($result) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;

    $xml .= '<rss xmlns:content="http://purl.org/rss/1.0/modules/content" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" version="2.0">';
    $xml .= '<channel>';
    $xml .= '<title>India Today</title>';
    $xml .= '<link>' . FRONT_URL . '</link>';
    $xml .= '<description>India Today</description>';
    $xml .= '<language>en-us</language>';
    $xml .= '<atom:link rel="hub" href="http://pubsubhubbub.appspot.com"/>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $nid = $value['nid'];
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);
      $author = get_byline_name_by_nid($nid);
      $pub_date = date("D, j M Y H:i:s P", strtotime($value['field_itg_content_publish_date_value']));
      $kicker_text = $value['field_story_kicker_text_value'];
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_extra_custom_tags($body);
      $medium_img = get_image_info_by_fid($value['field_story_extra_large_image_fid']);
      $large_img = '';
      if (!empty($medium_img)) {
        $large_img = '<figure><img src="' . $medium_img["imag_url"] . '" width="650"  /><figcaption>' . $medium_img["caption"] . '</figcaption></figure>';
      }
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<link><![CDATA[' . $url . ']]></link>';
      $xml .= '<guid>' . $value['nid'] . '</guid>';
      $xml .= '<pubDate>' . $pub_date . '</pubDate>';
      $xml .= '<dc:creator>' . $author . '</dc:creator>';
      $xml .= '<description><![CDATA[' . $kicker_text . ']]></description>';
      $xml .= '<content:encoded><![CDATA[' . $large_img . $body . ']]></content:encoded>';
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

/**
 * Function for geerate Education repblic feed
 */
function itg_rss_education_article_news_republic() {

  $cid = (isset($_GET['cid']) ? $_GET['cid'] : 1207013); // other wise Education Today category
  $query = db_select('node', 'n');
  $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $query->fields('eli', array('field_story_extra_large_image_fid'));
  $query->fields('n', array('nid', 'title', 'created'));
  $query->fields('dbody', array('body_value'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('kt', array('field_story_kicker_text_value'));
  $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  if (!empty($cid)) {
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->condition('ti.tid', $cid, '=');
  }
  if ($days_ago = get_content_fetch_time($cid)) {
    $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
    $query->condition('n.created', $days_ago, '>=');
  }
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 11);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $xml = get_rss_education_article_news_republic_xml($result);
  header('Content-Type: text/xml');
  print $xml;
  drupal_exit();
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @return string
 */
function get_rss_education_article_news_republic_xml($result) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $edu_cat_link = FRONT_URL . "/" . drupal_get_path_alias('taxonomy/term/1207412');
    $xml .= '<rss xmlns:content="http://purl.org/rss/1.0/modules/content" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" version="2.0">';
    $xml .= '<channel>';
    $xml .= '<title>Education Today</title>';
    $xml .= '<link>' . $edu_cat_link . '</link>';
    $xml .= '<description>Education Today</description>';
    $xml .= '<language>en-us</language>';
    $xml .= '<atom:link rel="hub" href="http://pubsubhubbub.appspot.com"/>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $nid = $value['nid'];
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);
      $author = get_byline_name_by_nid($nid);
      $pub_date = date("D, j M Y H:i:s P", strtotime($value['field_itg_content_publish_date_value']));
      $kicker_text = $value['field_story_kicker_text_value'];
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_extra_custom_tags($body);
      $medium_img = get_image_info_by_fid($value['field_story_extra_large_image_fid']);
      $large_img = '';
      if (!empty($medium_img)) {
        $large_img = '<figure><img src="' . $medium_img["imag_url"] . '" width="650"  /><figcaption>' . $medium_img["caption"] . '</figcaption></figure>';
      }
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<link><![CDATA[' . $url . ']]></link>';
      $xml .= '<guid>' . $value['nid'] . '</guid>';
      $xml .= '<pubDate>' . $pub_date . '</pubDate>';
      $xml .= '<dc:creator>' . $author . '</dc:creator>';
      $xml .= '<description><![CDATA[' . $kicker_text . ']]></description>';
      $xml .= '<content:encoded><![CDATA[' . $large_img . $body . ']]></content:encoded>';
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
