<?php

/**
 * Function which gives rss for blogs and live blogs
 * widget data as per the order in widgets.
 * 
 * @global string $base_url
 * @param  array $rss_nids
 * @return string
 */
function itg_sitemap_chunks_get_rss_of_blogs() {
  global $base_url;
  $arg = arg();
  $is_live_blogs = FALSE;
  $landing_page = $base_url . '/' . 'blog';
  $heading = 'Blogs';
  if ($arg[0] == 'rss-live-blogs') {
    $is_live_blogs = TRUE;
    $heading = 'Live Blogs';
    $landing_page = $base_url;
  }
  module_load_include('inc', 'itg_sitemap_chunks', 'includes/itg_sitemap_chunks.sections.rss');
  $xml = NULL;
  $limit = variable_get('itg_rss_chunks_number', 50000);
  try {
    $query = db_select('node', 'n');
    if ($is_live_blogs) {
      $query->leftJoin('field_data_field_type', 'fdft', 'fdft.entity_id = n.nid');
    }
    $query->leftJoin('field_data_field_common_short_description', 'sh', 'sh.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
    $query->leftJoin('file_managed', 'fm', 'fm.fid = eli.field_story_extra_large_image_fid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'pd', 'pd.entity_id = n.nid');
    $query->fields('n', array('title', 'nid'));
    $query->fields('sh', array('field_common_short_description_value'));
    $query->fields('pd', array('field_itg_content_publish_date_value'));
    $query->fields('fm', array('uri'));
    $query->condition('n.status', 1);
    if ($is_live_blogs) {
      $query->condition('fdft.field_type_value', 'Live Blog');
    }
    if (!$is_live_blogs) {
      $query->condition('n.type', 'blog');
    }
    $query->range(0, $limit);
    $query->orderBy('pd.field_itg_content_publish_date_value', 'DESC');
    $query->orderBy('n.created', 'DESC');
    $result = $query->execute();
  } catch (Exception $ex) {
    drupal_set_message($ex->getMessage(), 'error');
  }


  if (!empty($result)) {
    header('Content-Type: text/xml');
    $xml = '<?xml version="1.0" encoding="UTF-8" ?>' . "\r\n";
    $xml .= '<rss version="2.0" xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom">' . "\r\n";
    $xml .= '<channel>' . "\r\n";
    $xml .= '<title> <![CDATA[ ' . ITG_INDIATODAY_SITENAME_XML . '|' . $heading . ' ]]> </title>' . "\r\n";
    $xml .= '<description>' . t('India Today') . '</description>' . "\r\n";
    $xml .= '<link><![CDATA[ http://indiatoday.intoday.in/ ]]></link>' . "\r\n";
    $xml .= '<lastBuildDate>' . gmdate('D, d M Y H:i:s', time()) . ' GMT </lastBuildDate>' . "\r\n";
    $xml .= '<generator>FeedCreator 1.7.2</generator>' . "\r\n";
    $xml .= '<image>' . "\r\n";
    $xml .= '<url>' . theme_get_setting('logo', 'itg') . '</url>' . "\r\n";
    $xml .= '<title> <![CDATA[  ' . ITG_INDIATODAY_SITENAME_XML . ' ]]> </title>' . "\r\n";
    $xml .= '<description>' . ITG_INDIATODAY_SITENAME_XML . '</description>' . "\r\n";
    $xml .= '<link>' . $landing_page . '</link>' . "\r\n";
    $xml .= '</image>' . "\r\n";
    foreach ($result as $data) {
      $xml .= '<item>' . "\r\n";
      $node_title = $data->title; // Long Headline
      $node_link = $base_url . '/' . drupal_get_path_alias("node/" . $data->nid);
      if (!empty($data->uri)) {
        $node_extra_large_image_url = file_create_url($data->uri);
      } else {
        $node_extra_large_image_url = $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/itg_image647x363.jpg';
      }
      $description = $data->field_common_short_description_value;
      $published_date = date('D, d M Y H:i:s', strtotime($data->field_itg_content_publish_date_value));
      $xml .= '<title> <![CDATA[ ' . $node_title . ' ]]></title>' . "\r\n";
      $xml .= '<link> <![CDATA[ ' . $node_link . ' ]]></link>' . "\r\n";
      $xml .='<description> <![CDATA[  <a href="' . $node_link . '"> <img align="left" hspace="2" height="180" width="305" alt="" border="0" src="' . $node_extra_large_image_url . '"> </a> ' . $description . ']]></description>';
      $xml .= '<pubDate> ' . $published_date . ' GMT </pubDate>' . "\r\n";
      $xml .= '</item>' . "\r\n";
    }
    $xml .= '</channel>' . "\r\n";
    $xml .= '</rss>' . "\r\n";
  }

  echo trim($xml);
  drupal_exit();
}
