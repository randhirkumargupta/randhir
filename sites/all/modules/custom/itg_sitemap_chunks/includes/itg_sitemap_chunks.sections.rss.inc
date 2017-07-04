<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function itg_sitemap_chunks_get_rss_of_cat_with_order($section_tid) {
  global $base_url;

  $limit = variable_get('itg_sitemap_chunks_number', 50000);
  // Get all child of section.
  $childrens = taxonomy_get_children_all($section_tid, CATEGORY_MANAGMENT);
  // Include section too in childern and combine into single array.
  $childrens[] = $section_tid;
  sort($childrens);
  $query = db_select('itg_widget_order_section', 'wos');
  $query->leftJoin('node', 'n', 'n.nid=wos.nid');
  $query->leftJoin('field_data_field_story_short_headline', 'sh', 'sh.entity_id=wos.nid');
  $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $query->leftJoin('file_managed', 'fm', 'fm.fid = eli.field_story_extra_large_image_fid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'pd', 'pd.entity_id = n.nid');
  $query->fields('wos', array('nid'));
  $query->fields('n', array('title'));
  $query->fields('sh', array('field_story_short_headline_value'));
  $query->fields('fm', array('uri'));
  $query->fields('pd', array('field_itg_content_publish_date_value'));
  $query->condition('n.status', 1);
  if (!empty($childrens)) {
    $query->condition('wos.cat_id', $childrens, 'IN');
  }
  $query->condition('wos.content_type', 'story');
  $query->range(0, $limit);
  $query->orderBy('wos.weight', 'DESC');
  $query->orderBy('wos.nid', 'DESC');
  $query->groupBy('wos.nid');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  header("Content-Type: application/rss+xml; charset=ISO-8859-1");
  $xml = '<?xml version="1.0" encoding="UTF-8" ?>';
  $xml .= '<rss version="2.0">';
  $xml .= '<channel>';
  $xml .= '<title>' . ITG_INDIATODAY_SITENAME_XML . '|' . get_term_name_from_tid_for_report($section_tid) . '</title>';
  $xml .= '<description>' . t('India Today') . '</description>';
  $xml .= '<link><![CDATA[ http://indiatoday.intoday.in/ ]]></link>';
  $xml .= '<lastBuildDate>' . gmdate('D, d M Y H:i:s', time()) . ' GMT </lastBuildDate>';
  $xml .= '<generator>FeedCreator 1.7.2</generator>';
  $xml .= '<image>';
  $xml .= '<url>' . theme_get_setting('logo', 'itg') . '</url>';
  $xml .= '<title>' . ITG_INDIATODAY_SITENAME_XML . '|' . $section_tid . '</title>';
  $xml .= '<link>' . $base_url . '/' . drupal_get_path_alias("taxonomy/term/" . $section_tid) . '</link>';
  $xml .= '<description>' . ITG_INDIATODAY_SITENAME_XML . '</description>';
  $xml .= '</image>';
  $xml .= itg_sitemap_print_section_rss($result);
  $xml .= '</channel>';
  $xml .= '</rss>';
  echo $xml;
  exit;
}

function itg_sitemap_print_section_rss($result) {
  global $base_url;
  $xml .= '';
  foreach ($result as $data) {
    $xml .= '<item>';
    $node_title = $data['title']; // Long Headline
    $node_link = $base_url . '/' . drupal_get_path_alias("node/" . $data['nid']);
    if (!empty($data['uri'])) {
      $node_extra_large_image_url = file_create_url($data['uri']);
    } else {
      $node_extra_large_image_url = $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/itg_image647x363.jpg';
    }
    $description = $data['field_story_short_headline_value'];
    $published_date = gmdate('D, d M Y H:i:s', strtotime($data['field_itg_content_publish_date_value']));
    $xml .= '<title> <![CDATA[ ' . $node_title . ' ]]></title>';
    $xml .= '<link> <![CDATA[ ' . $node_link . ' ]]></link>';
    $xml .= '<description> <![CDATA[  ' . '<a src="' . $node_link . '"><img src="' . $node_extra_large_image_url . '" align="left" hspace="2" height="180" width="305" alt="" border="0"/></a>' . $description . ' ]]></description>';
    $xml .= '<pubDate> ' . $published_date . ' GMT </pubDate>';
    $xml .= '</item>';
  }
  return $xml;
}
