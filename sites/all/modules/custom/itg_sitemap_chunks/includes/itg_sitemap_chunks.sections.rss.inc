<?php

/**
 * Function provides rss for any category/section.

 * @param int $section_tid
 */
function itg_sitemap_chunks_get_rss_of_cat_with_order() {
  $arg = arg();
  $section_tid = NULL;
  if (!empty($arg[1])) {
    $section_tid = $arg[1];
  }
  if (!is_null($section_tid)) {
    if ($section_tid == 'home') {
      itg_sitemap_chunks_get_rss_of_home();
    } else if ($section_tid == 'magazine') {
      itg_sitemap_chunks_get_rss_of_magazine();
    } else {
      // Print Rss for provides sections.
      header("Content-Type: application/rss+xml; charset=ISO-8859-1");
      $xml = itg_sitemap_chunks_common_rss($section_tid, 'story');
      echo $xml;
    }
  } else {
    return theme('rss_landing_page');
  }
}

/**
 *  Function to provide rss for latest issue magazine.
 */
function itg_sitemap_chunks_get_rss_of_magazine() {
  if (function_exists('itg_msi_get_current_issue')) {
    $current_issue = itg_msi_get_current_issue();
    $query = db_select('itg_widget_order', 'iwo');
    $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
    $query->leftjoin('field_data_field_story_issue_date', 'sid', 'sid.entity_id=n.nid');
    $query->fields('iwo', array('nid'));
    $query->condition('iwo.widget', 'issue_magazin_widget');
    $query->condition('sid.field_story_issue_date_value', $current_issue);
    $query->orderBy('iwo.weight', 'ASC');
    //$query->groupBy('n.nid');
    $rss_nids = $query->execute()->fetchCol();
    $xml = itg_sitemap_chunks_common_rss_for_home_page($rss_nids);
    if (!is_null($xml)) {
      header("Content-Type: application/rss+xml; charset=ISO-8859-1");
      echo $xml;
    } else {
      return drupal_not_found();
    }
  }
}

/**
 *  Function provides rss for home page 
 *  i.e. Big Story + Home page feature + top Stories
 */
function itg_sitemap_chunks_get_rss_of_home() {
  $big_story = db_select('itg_widget_order', 'iwo');
  $big_story->leftJoin('node', 'n', 'iwo.nid=n.nid');
  $big_story->fields('iwo', array('nid'));
  $big_story->condition('iwo.widget', 'big_story_format_widget');
  $big_story->condition('iwo.nid', 0, '!=');
  $big_story->condition('n.status', 1);
  $data['big_story_widget'] = $big_story->execute()->fetchCol();

  $home_page_feature = db_select('itg_widget_order', 'iwo');
  $home_page_feature->leftJoin('node', 'n', 'iwo.nid=n.nid');
  $home_page_feature->fields('iwo', array('nid'));
  $home_page_feature->condition('iwo.widget', 'home_page_feature_widget');
  $home_page_feature->orderBy('iwo.weight', 'ASC');
  $home_page_feature->condition('n.status', 1);
  $home_page_feature->range(0, HOME_PAGE_FEATURE_MAX_RANGE);
  $data['home_page_feature_widget'] = $home_page_feature->execute()->fetchCol();

  $top_story = db_select('itg_widget_order', 'iwo');
  $top_story->leftJoin('node', 'n', 'iwo.nid=n.nid');
  $top_story->fields('iwo', array('nid'));
  $top_story->condition('iwo.widget', 'top_stories_widget');
  $top_story->orderBy('iwo.weight', 'ASC');
  $top_story->condition('n.status', 1);
  $top_story->range(0, TOP_STORIES_LIMIT);
  $data['top_story_widget'] = array_values($top_story->execute()->fetchCol());

  $real_array = array_merge($data['big_story_widget'], $data['home_page_feature_widget'], $data['top_story_widget']);
  $rss_nids = array_unique($real_array);
  $xml = itg_sitemap_chunks_common_rss_for_home_page($rss_nids);
  if (!is_null($xml)) {
    header("Content-Type: application/rss+xml; charset=ISO-8859-1");
    echo $xml;
  } else {
    return drupal_not_found();
  }
}

/**
 * Function which gives rss for home page  which is big story + home page feautre + topstories
 * widget data as per the order in widgets.
 * 
 * @global string $base_url
 * @param  array $rss_nids
 * @return string
 */
function itg_sitemap_chunks_common_rss_for_home_page($rss_nids) {
  global $base_url;
  $xml = NULL;
  $result = array();
  $limit = variable_get('itg_rss_chunks_number', 50000);

  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_story_short_headline', 'sh', 'sh.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $query->leftJoin('file_managed', 'fm', 'fm.fid = eli.field_story_extra_large_image_fid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'pd', 'pd.entity_id = n.nid');
  $query->fields('n', array('title', 'nid'));
  $query->fields('sh', array('field_story_short_headline_value'));
  $query->fields('fm', array('uri'));
  $query->fields('pd', array('field_itg_content_publish_date_value'));
  $query->condition('n.status', 1);

  $query->condition('n.nid', $rss_nids, 'IN');
  $query->range(0, $limit);
  $result_data = $query->execute()->fetchAllAssoc('nid');
// Create same order as per given in nodeids.
  foreach ($rss_nids as $order_nids) {
    $result[] = (array) $result_data[$order_nids];
  }

  if (!empty($result)) {
    $xml = '<?xml version="1.0" encoding="UTF-8" ?>';
    $xml .= '<rss version="2.0">';
    $xml .= '<channel>';
    $xml .= '<title> <![CDATA[ ' . ITG_INDIATODAY_SITENAME_XML . ' ]]> </title>';
    $xml .= '<description>' . t('India Today') . '</description>';
    $xml .= '<link><![CDATA[ http://indiatoday.intoday.in/ ]]></link>';
    $xml .= '<lastBuildDate>' . gmdate('D, d M Y H:i:s', time()) . ' GMT </lastBuildDate>';
    $xml .= '<generator>FeedCreator 1.7.2</generator>';
    $xml .= '<image>';
    $xml .= '<url>' . theme_get_setting('logo', 'itg') . '</url>';
    $xml .= '<title> <![CDATA[  ' . ITG_INDIATODAY_SITENAME_XML . '|' . get_term_name_from_tid_for_report($section_tid) . ' ]]> </title>';
    $xml .= '<link> <![CDATA[ ' . $base_url . '/' . drupal_get_path_alias("taxonomy/term/" . $section_tid) . ' ]]> </link>';
    $xml .= '<description>' . ITG_INDIATODAY_SITENAME_XML . '</description>';
    $xml .= '</image>';
    $xml .= itg_sitemap_print_section_rss($result);
    $xml .= '</channel>';
    $xml .= '</rss>';
  }
  return $xml;
}

/**
 * Function which gives xml tags string w.r.t section tid and cotnent type.
 * 
 * @param int $section_tid
 * @param string $content_type
 * @global string $base_url
 * @return string
 */
function itg_sitemap_chunks_common_rss($section_tid, $content_type) {
  global $base_url;
  $arg = arg();
  $xml = NULL;
  $limit = variable_get('itg_rss_chunks_number', 50000);
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
  $query->condition('wos.content_type', $content_type);
  $query->range(0, $limit);
  if (!empty($arg[1])) {
    $query->orderBy('pd.field_itg_content_publish_date_value', 'DESC');
  }
  $query->orderBy('wos.weight', 'DESC');
  $query->orderBy('wos.nid', 'DESC');
  $query->groupBy('wos.nid');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  if (!empty($result)) {
    $xml = '<?xml version="1.0" encoding="UTF-8" ?>';
    $xml .= '<rss version="2.0">';
    $xml .= '<channel>';
    if (!empty($section_tid)) {
      $xml .= '<title>' . ITG_INDIATODAY_SITENAME_XML . '|' . get_term_name_from_tid_for_report($section_tid) . '</title>';
    } else {
      $xml .= '<title>' . ITG_INDIATODAY_SITENAME_XML . '</title>';
    }
    $xml .= '<description>' . t('India Today') . '</description>';
    $xml .= '<link><![CDATA[ http://indiatoday.intoday.in/ ]]></link>';
    $xml .= '<lastBuildDate>' . gmdate('D, d M Y H:i:s', time()) . ' GMT </lastBuildDate>';
    $xml .= '<generator>FeedCreator 1.7.2</generator>';
    $xml .= '<image>';
    $xml .= '<url>' . theme_get_setting('logo', 'itg') . '</url>';
    if (!empty($section_tid)) {
      $xml .= '<title>' . ITG_INDIATODAY_SITENAME_XML . '|' . get_term_name_from_tid_for_report($section_tid) . '</title>';
    } else {
      $xml .= '<title>' . ITG_INDIATODAY_SITENAME_XML . '</title>';
    }
    $xml .= '<link>' . $base_url . '/' . drupal_get_path_alias("taxonomy/term/" . $section_tid) . '</link>';
    $xml .= '<description>' . ITG_INDIATODAY_SITENAME_XML . '</description>';
    $xml .= '</image>';
    $xml .= itg_sitemap_print_section_rss($result);
    $xml .= '</channel>';
    $xml .= '</rss>';
  }
  return $xml;
}

/**
 * Function which gives xml tags string w.r.t section tid and cotnent type.
 * 
 * @param int $section_tid
 * @param string $content_type
 * @global string $base_url
 * @return string
 */
function itg_sitemap_chunks_get_rss_of_mixed_content() {
  $xml = NULL;
  $arg = arg();
  $limit = variable_get('itg_rss_chunks_number', 50000);
  if (!empty($arg[1])) {
    $section_tid = $arg[1];
  }
  $query = db_select('node', 'n')->distinct();
  if (!empty($section_tid)) {
    $query->leftJoin('itg_widget_order_section', 'wos', 'wos.nid=n.nid');
  }
  $query->leftJoin('field_data_field_story_short_headline', 'sh', 'sh.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $query->leftJoin('file_managed', 'fm', 'fm.fid = eli.field_story_extra_large_image_fid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'pd', 'pd.entity_id = n.nid');
  $query->fields('n', array('title', 'nid'));
  $query->fields('sh', array('field_story_short_headline_value'));
  $query->fields('fm', array('uri'));
  $query->fields('pd', array('field_itg_content_publish_date_value'));
  $query->condition('n.status', 1);
  $query->condition('n.type', array('story', 'videogallery', 'photogallery'));
  if (!empty($section_tid)) {
    $query->condition('wos.cat_id', $section_tid);
  }
  $query->range(0, $limit);
  $query->orderBy('pd.field_itg_content_publish_date_value', 'DESC');
  $query->orderBy('n.created', 'DESC');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  if (!empty($result)) {
    $xml = '<?xml version="1.0" encoding="UTF-8" ?>';
    $xml .= '<rss version="2.0">';
    $xml .= '<channel>';
    $xml .= '<title>' . ITG_INDIATODAY_SITENAME_XML . '</title>';
    $xml .= '<description>' . t('India Today') . '</description>';
    $xml .= '<link><![CDATA[ http://indiatoday.intoday.in/ ]]></link>';
    $xml .= '<lastBuildDate>' . gmdate('D, d M Y H:i:s', time()) . ' GMT </lastBuildDate>';
    $xml .= '<generator>FeedCreator 1.7.2</generator>';
    $xml .= '<image>';
    $xml .= '<url>' . theme_get_setting('logo', 'itg') . '</url>';
    $xml .= '<title>' . ITG_INDIATODAY_SITENAME_XML . '</title>';
    $xml .= '<description>' . ITG_INDIATODAY_SITENAME_XML . '</description>';
    $xml .= '</image>';
    $xml .= itg_sitemap_print_section_rss($result);
    $xml .= '</channel>';
    $xml .= '</rss>';
  }
  header("Content-Type: application/rss+xml; charset=ISO-8859-1");
  echo $xml;
}

/**
 * Function which gives item tag string for given result.
 * 
 * @param array $result
 * @return string
 */
function itg_sitemap_print_section_rss($result) {
  global $base_url;
  $xml .= '';
  foreach ($result as $data) {
    $xml .= '<item>';
    $node_title = $data['title']; // Long Headline
    $node_link = $base_url . '/' . drupal_get_path_alias("node/" . $data ['nid']);
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
