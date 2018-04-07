<?php

/**
 * @file
 * The ITG Syndication clients for gist Photo
 */
function itg_gist_feed_galleries_syndication() {
  itg_genrate_gist_photo_syndication();
}

/**
 * Generate Gist Photo xml feed
 */
function itg_genrate_gist_photo_syndication() {

  $type = array('photogallery');
  $query = db_select('node', 'n');
  $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_medium_image', 'smi', 'smi.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');

  $query->fields('n', array('nid', 'title', 'created'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('smi', array('field_story_medium_image_fid'));
  $query->fields('ssi', array('field_story_small_image_fid'));
  
  $days_ago = strtotime(date('Y-m-d', strtotime('-10 days')));
  $query->condition('n.created', $days_ago, '>=');
  
  $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'photogallery', '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 15);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  $xml = genrate_gist_photo_syndication_xml($result);
  $xml_path = 'public://rss-feeds/xml_data/gist/it/galleries/';
  $file_path = $xml_path . 'gallery.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @return string
 */
function genrate_gist_photo_syndication_xml($result = NULL) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml_pub_date = date("Y-m-d H:i:s", $result[0]['created']);
    $logo = theme_get_setting('logo');
    $copy_right_yr = date("Y");
    $cat_link = FRONT_URL . "/" . drupal_get_path_alias('taxonomy/term/1208589');
    $xml .= '<rss xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" version="2.0">';
    $xml .= '<channel>';
    $xml .= '<title><![CDATA[ India Today | Photos | Exclusive Photo ]]></title>';
    $xml .= '<description>India Today</description>';
    $xml .= '<link><![CDATA[' . FRONT_URL . '/?utm_source=rss]]></link>';
    $xml .= '<lastBuildDate>' . $xml_pub_date . '</lastBuildDate>';
    $xml .= '<generator>FeedCreator 1.7.2</generator>';
    $xml .= '<image>';
    $xml .= '<url>' . $logo . '</url>';
    $xml .= '<title><![CDATA[ India Today | Photos | Exclusive Photo ]]></title>';
    $xml .= '<link><![CDATA[ ' . $cat_link . '?utm_source=rss ]]></link>';
    $xml .= '<description>India Today</description>';
    $xml .= '</image>';

    foreach ($result as $photo) {
      $nid = $photo['nid'];
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);
      $small_img = get_image_info_by_fid($photo['field_story_small_image_fid']);
      $medium_img = get_image_info_by_fid($photo['field_story_medium_image_fid']);
      $publish_date = date("D, j M Y H:i:s P", strtotime($photo['field_itg_content_publish_date_value']));
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $photo['title'] . ']]></title>';
      $xml .= '<link><![CDATA[' . $url . '?utm_source=rss]]></link>';
      $xml .= '<description><![CDATA[' . $photo['title'] . ']]></description>';
      $xml .= '<media:description type="html"><![CDATA[' . $photo['title'] . ']]></media:description>';
      $xml .= '<media:thumbnail url="' . $small_img["imag_url"] . '"></media:thumbnail>';
      $xml .= '<media:content medium="image" type="image/' . $medium_img["mime_type"] . '"  url="' . $medium_img["imag_url"] . '"></media:content>';
      $xml .= '<media:copyright>© ' . $copy_right_yr . ' India Today Group. All Rights Reserved.</media:copyright>';
      $xml .= '<pubDate>' . $publish_date . '</pubDate>';
      $xml .= '</item>';
    }
    $xml .= '</channel>';
    $xml .= '</rss>';
  }
  return $xml;
}
