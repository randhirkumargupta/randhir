<?php

/**
 * @file
 * The ITG Syndication clients for gist Photo
 */
function itg_gist_feed_galleries_syndication() {
 itg_genrate_gist_photo_syndication();
}

/**
 * menu callback for bsb story syndication
 */
function itg_genrate_gist_photo_syndication() {
 
    $type = array('photogallery');
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'smi', 'smi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');
    
    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('smi', array('field_story_medium_image_fid'));
    $query->fields('ssi', array('field_story_small_image_fid'));
    $query->condition('n.status', 1);
    $query->condition('n.type', $type, 'IN');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 15);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $xml = genrate_gist_photo_syndication_xml($result);
    $xml_path = 'sites/default/files/rss-feeds/ver1.0/gist/9b9fdf70/it/galleries/';
    $file_path = $xml_path . 'gallery.xml';
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  
}

function genrate_gist_photo_syndication_xml($result = NULL) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml_pub_date = date("Y-m-d H:i:s", $result[0]['created']);
    $logo = theme_get_setting('logo'); 
    $copy_right_yr = date("Y");
    $cat_link = $base_url . "/" . drupal_get_path_alias('taxonomy/term/1208589');
    $xml .= '<rss xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" version="2.0">';
    $xml .= '<channel>';
    $xml .= '<title><![CDATA[ India Today | Photos | Exclusive Photo ]]></title>';
    $xml .= '<description>India Today</description>';
    $xml .= '<link><![CDATA['.$base_url.']]></link>';
    $xml .= '<lastBuildDate>'.$xml_pub_date.'</lastBuildDate>';
    $xml .= '<generator>FeedCreator 1.7.2</generator>';
    $xml .= '<image>';
    $xml .= '<url>'.$logo.'</url>';
    $xml .= '<title><![CDATA[ India Today | Photos | Exclusive Photo ]]></title>';
    $xml .= '<link><![CDATA[ '.$cat_link.' ]]></link>';
    $xml .= '<description>India Today</description>';
    $xml .= '</image>';

    foreach ($result as $photo) {
      $nid = $photo['nid'];
      $url = $base_url . "/" . drupal_get_path_alias('node/' . $nid);
      $small_img = get_image_info_by_fid($photo['field_story_small_image_fid']);
      $medium_img = get_image_info_by_fid($photo['field_story_medium_image_fid']);
      $publish_date = date("D, j M Y H:i:s P", strtotime($photo['field_itg_content_publish_date_value']));
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $photo['title'] . ']]></title>';
      $xml .= '<link><![CDATA[' . $url . ']]></link>';
      $xml .= '<description><![CDATA[' . $photo['title'] . ']]></description>';
      $xml .= '<media:description type="html"><![CDATA[' . $photo['title'] . ']]></media:description>';
      $xml .= '<media:thumbnail url="'.$small_img["imag_url"].'"></media:thumbnail>';
      $xml .= '<media:content medium="image" type="image/'.$medium_img["mime_type"].'"  url="'.$medium_img["imag_url"].'"></media:content>';
      $xml .= '<media:copyright>© '.$copy_right_yr.' India Today Group. All Rights Reserved.</media:copyright>';
      $xml .= '<pubDate>'.$publish_date.'</pubDate>';
      $xml .= '</item>';
    }
    $xml .= '</channel>';
    $xml .= '</rss>';
  }
  return $xml;
}
