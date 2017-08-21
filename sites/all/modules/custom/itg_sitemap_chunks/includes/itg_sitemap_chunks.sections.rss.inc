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
      header('Content-Type: text/xml');
      $xml = itg_sitemap_chunks_common_rss($section_tid, 'story');
      $dom = new DOMDocument;
      $dom->preserveWhiteSpace = false;
      $dom->formatOutput = true;
      $dom->loadXML($xml);
      echo $dom->saveXML();
      drupal_exit();
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
      header('Content-Type: text/xml');
      $dom = new DOMDocument;
      $dom->preserveWhiteSpace = false;
      $dom->formatOutput = true;
      $dom->loadXML($xml);
      echo $dom->saveXML();
      drupal_exit();
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
    header('Content-Type: text/xml');
    $dom = new DOMDocument;
    $dom->preserveWhiteSpace = false;
    $dom->formatOutput = true;
    $dom->loadXML($xml);
    echo $dom->saveXML();
    drupal_exit();
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
  $current_issue_date = '';
  $arg = arg();
  $result = array();
  $limit = variable_get('itg_rss_chunks_number', 50000);
  $headling = 'Latest Stories ';
  $landing_link = $base_url;
  $is_magazine = FALSE;
  if ($arg[0] == 'rss' && $arg[1] == 'magazine') {
    $is_magazine = TRUE;
  }
  try {
    if (!empty($rss_nids)) {
      $query = db_select('node', 'n');
      $query->leftJoin('field_data_field_story_short_headline', 'sh', 'sh.entity_id=n.nid');
      $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
      $query->leftJoin('file_managed', 'fm', 'fm.fid = eli.field_story_extra_large_image_fid');
      $query->leftJoin('field_data_field_itg_content_publish_date', 'pd', 'pd.entity_id = n.nid');
      $query->leftJoin('field_data_field_story_schedule_date_time', 'dt', 'dt.entity_id = n.nid');
      if ($is_magazine) {
        $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id = n.nid');
        $query->leftJoin('taxonomy_term_data', 'td', 'pc.field_primary_category_value = td.tid');
        $query->fields('td', array('name'));
      }
      $query->fields('n', array('title', 'nid', 'created'));
      $query->fields('sh', array('field_story_short_headline_value'));
      $query->fields('fm', array('uri'));
      $query->fields('pd', array('field_itg_content_publish_date_value'));
      $query->fields('dt', array('field_story_schedule_date_time_value'));
      $query->condition('n.status', 1);
      $query->condition('n.nid', $rss_nids, 'IN');
      $query->range(0, $limit);
      $result_data = $query->execute()->fetchAllAssoc('nid');
    }
  } catch (Exception $ex) {
    drupal_set_message($ex->getMessage(), 'error');
  }

  if (!empty($rss_nids)) {
    // Create same order as per given in nodeids.
    foreach ($rss_nids as $order_nids) {
      $result[] = (array) $result_data[$order_nids];
    }
  }

  if ($is_magazine) {
    $landing_link = $base_url . '/magazine';
    $current_issue_date = itg_msi_get_current_issue();
    $headling = date('M d , Y', strtotime($current_issue_date));
  }
  if (!empty($result)) {
    $xml = '<?xml version="1.0" encoding="UTF-8" ?>' . "\r\n";
    $xml .= '<rss version="2.0" xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom">' . "\r\n";
    $xml .= '<channel>' . "\r\n";
    $xml .= '<title> <![CDATA[ ' . ITG_INDIATODAY_SITENAME_XML . ' | ' . $headling . ' ]]> </title>' . "\r\n";
    $xml .= '<description>' . t('India Today') . '</description>' . "\r\n";
    $xml .= '<link><![CDATA[ http://indiatoday.intoday.in/ ]]></link>' . "\r\n";
    $xml .= '<lastBuildDate>' . gmdate('D, d M Y H:i:s T', time()) . ' </lastBuildDate>' . "\r\n";
    $xml .= '<generator>' . t('FeedCreator 1.7.2') . '</generator>' . "\r\n";
    $xml .= '<image>' . "\r\n";
    $xml .= '<url>' . theme_get_setting('logo', 'itg') . '</url>' . "\r\n";
    $xml .= '<title> <![CDATA[  ' . ITG_INDIATODAY_SITENAME_XML . ' ]]> </title>' . "\r\n";
    $xml .= '<link> <![CDATA[ ' . $landing_link . ' ]]> </link>' . "\r\n";
    $xml .= '<description>' . ITG_INDIATODAY_SITENAME_XML . '</description>' . "\r\n";
    $xml .= '</image>' . "\r\n";
    $xml .= itg_sitemap_print_section_rss($result);
    $xml .= '</channel>' . "\r\n";
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
//  $childrens = taxonomy_get_children_all($section_tid, CATEGORY_MANAGMENT);
// Include section too in childern and combine into single array.
  $childrens[] = $section_tid;
  sort($childrens);
  try {
    $query = db_select('node', 'n');
    $query->leftJoin('itg_widget_order_section', 'wos', 'n.nid=wos.nid');
    $query->leftJoin('field_data_field_story_short_headline', 'sh', 'sh.entity_id=wos.nid');
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_small_image', 'esi', 'esi.entity_id=n.nid');
    $query->leftJoin('file_managed', 'fm', 'fm.fid = eli.field_story_extra_large_image_fid');
    $query->leftJoin('file_managed', 'fm1', 'fm1.fid = esi.field_story_extra_small_image_fid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'pd', 'pd.entity_id = n.nid');
    $query->leftJoin('field_data_field_story_schedule_date_time', 'dt', 'dt.entity_id = n.nid');
    $query->fields('wos', array('nid'));
    $query->fields('n', array('title', 'created'));
    $query->fields('sh', array('field_story_short_headline_value'));
    $query->fields('fm', array('uri'));
    $query->fields('fm1', array('uri'));
    $query->fields('pd', array('field_itg_content_publish_date_value'));
    $query->fields('dt', array('field_story_schedule_date_time_value'));
    $query->condition('n.status', 1);
    if (!empty($childrens)) {
      $query->condition('wos.cat_id', $childrens, 'IN');
    }
    $query->condition('wos.content_type', $content_type);
    $query->condition('wos.widget', 'section_wise_widget');
    $query->range(0, $limit);
    $is_published_date_order = itg_sitemap_published_date_order();
    if ($is_published_date_order) {
      $query->orderBy('pd.field_itg_content_publish_date_value', 'DESC');
      $query->orderBy('n.created', 'DESC');
    } else {
      $query->orderBy('wos.weight', 'DESC');
      $query->orderBy('n.nid', 'DESC');
    }
    $query->groupBy('n.nid');
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  } catch (Exception $ex) {
    echo $ex->getMessage();
    exit;
  }
  if (!empty($result)) {
    $xml = '<?xml version="1.0" encoding="UTF-8" ?>' . "\r\n";
    $xml .= '<rss version="2.0" xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom">' . "\r\n";
    $xml .= '<channel>' . "\r\n";
    if (!empty($section_tid)) {
      $xml .= '<title><![CDATA[ ' . ITG_INDIATODAY_SITENAME_XML . ' | ' . get_term_name_from_tid_for_report($section_tid) . ' ]]></title>' . "\r\n";
    } else {
      $xml .= '<title><![CDATA[' . ITG_INDIATODAY_SITENAME_XML . ' ]]></title>' . "\r\n";
    }
    $xml .= '<description><![CDATA[' . t('India Today') . ' ]]></description>' . "\r\n";
    $xml .= '<link><![CDATA[ http://indiatoday.intoday.in/ ]]></link>' . "\r\n";
    $xml .= '<lastBuildDate><![CDATA[ ' . gmdate('D, d M Y H:i:s T', time()) . ' ]]></lastBuildDate>' . "\r\n";
    $xml .= '<generator><![CDATA[ ' . t('FeedCreator 1.7.2') . ' ]]></generator>' . "\r\n";
    $xml .= '<image>' . "\r\n";
    $xml .= '<url> <![CDATA[ ' . theme_get_setting('logo', 'itg') . ' ]]></url>' . "\r\n";
    if (!empty($section_tid)) {
      $xml .= '<title><![CDATA[' . ITG_INDIATODAY_SITENAME_XML . ' | ' . get_term_name_from_tid_for_report($section_tid) . ']]></title>' . "\r\n";
    } else {
      $xml .= '<title> <![CDATA[ ' . ITG_INDIATODAY_SITENAME_XML . ' ]]></title>' . "\r\n";
    }
    $xml .= '<link> <![CDATA[ ' . $base_url . '/' . drupal_get_path_alias("taxonomy/term/" . $section_tid) . ' ]]></link>' . "\r\n";
    $xml .= '<description> <![CDATA[ ' . ITG_INDIATODAY_SITENAME_XML . ' ]]></description>' . "\r\n";
    $xml .= '</image>' . "\r\n";
    $xml .= itg_sitemap_print_section_rss($result);
    $xml .= '</channel>' . "\r\n";
    $xml .= '</rss>' . "\r\n";
  }
  return trim($xml);
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
  global $base_url;
  $xml = NULL;
  $arg = arg();
  $limit = variable_get('itg_rss_chunks_number', 50000);
  if (!empty($arg[1])) {
    $section_tid = $arg[1];
  }
  $query = db_select('node', 'n')->distinct();
  if (!empty($section_tid)) {
    $query->leftJoin('itg_widget_order', 'wos', 'wos.nid=n.nid');
  }
  $query->leftJoin('field_data_field_story_short_headline', 'sh', 'sh.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $query->leftJoin('file_managed', 'fm', 'fm.fid = eli.field_story_extra_large_image_fid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'pd', 'pd.entity_id = n.nid');
  $query->leftJoin('field_data_field_story_schedule_date_time', 'dt', 'dt.entity_id = n.nid');
  $query->fields('n', array('title', 'nid', 'created'));
  $query->fields('sh', array('field_story_short_headline_value'));
  $query->fields('fm', array('uri'));
  $query->fields('pd', array('field_itg_content_publish_date_value'));
  $query->fields('dt', array('field_story_schedule_date_time_value'));
  $query->condition('n.status', 1);
  $query->condition('n.type', array('story', 'videogallery', 'photogallery'));
  if (!empty($section_tid)) {
    $query->condition('wos.cat_id', $section_tid);
  }
  $query->range(0, $limit);
  $is_published_date_order = itg_sitemap_published_date_order();
  if ($is_published_date_order) {
    $query->orderBy('pd.field_itg_content_publish_date_value', 'DESC');
    $query->orderBy('n.created', 'DESC');
  } else {
    $query->orderBy('wos.weight', 'DESC');
  }
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  if (!empty($result)) {
    $xml = '<?xml version="1.0" encoding="UTF-8" ?>';
    $xml .= '<rss version="2.0" xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom">';
    $xml .= '<channel>';
    if (!empty($section_tid)) {
      $xml .= '<title><![CDATA[ ' . ITG_INDIATODAY_SITENAME_XML . ' | ' . get_term_name_from_tid($section_tid)->name . ']]></title>' . "\r\n";
    } else {
      $xml .= '<title><![CDATA[ ' . ITG_INDIATODAY_SITENAME_XML . ' ]]></title>' . "\r\n";
    }
    $xml .= '<description><![CDATA[ ' . t('India Today') . ' ]]></description>' . "\r\n";
    $xml .= '<link><![CDATA[ http://indiatoday.intoday.in/ ]]></link>' . "\r\n";
    $xml .= '<lastBuildDate><![CDATA[ ' . gmdate('D, d M Y H:i:s T', time()) . ' ]]></lastBuildDate>' . "\r\n";
    $xml .= '<generator><![CDATA[ ' . t('FeedCreator 1.7.2') . ' ]]></generator>' . "\r\n";
    $xml .= '<image>';
    $xml .= '<url> <![CDATA[ ' . theme_get_setting('logo', 'itg') . ' ]]></url>' . "\r\n";
    $xml .= '<title><![CDATA[ ' . ITG_INDIATODAY_SITENAME_XML . ' ]]></title>' . "\r\n";
    $xml .= '<description><![CDATA[ ' . ITG_INDIATODAY_SITENAME_XML . ' ]]></description>' . "\r\n";
    if (!empty($section_tid)) {
      $xml .= '<link> <![CDATA[ ' . $base_url . '/' . drupal_get_path_alias("taxonomy/term/" . $section_tid) . ' ]]></link>' . "\r\n";
    } else {
      $xml .= '<link><![CDATA[ ' . $base_url . ' ]]></link>' . "\r\n";
    }
    $xml .= '</image>' . "\r\n";
    $xml .= itg_sitemap_print_section_rss($result);
    $xml .= '</channel>' . "\r\n";
    $xml .= '</rss>' . "\r\n";
  }
  header('Content-Type: text/xml');
  echo trim($xml);
  drupal_exit();
}

/**
 * Function which gives item tag string for given result.
 * 
 * @param array $result
 * @return string
 */
function itg_sitemap_print_section_rss($result) {
  global $base_url;
  $arg = arg();
  $xml .= '';
  foreach ($result as $data) {
    $add_item = TRUE;
    if (!empty($data['field_story_schedule_date_time_value']) && strtotime($data['field_story_schedule_date_time_value']) > time()) {
      $add_item = FALSE;
    }
    if ($add_item) {
      $xml .= '<item>' . "\r\n";
      $node_title = $data['title']; // Long Headline
      $node_link = $base_url . '/' . drupal_get_path_alias("node/" . $data ['nid']);
      if (!empty($data['uri'])) {
        $node_extra_large_image_url = file_create_url($data['uri']);
      } else {
        $node_extra_large_image_url = $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/itg_image647x363.jpg';
      }
      if (!empty($data['fm1_uri'])) {
        $node_extra_small_image_url = file_create_url($data['fm1_uri']);
      } else {
        $node_extra_small_image_url = $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/itg_image647x363.jpg';
      }
      $description = $data['field_story_short_headline_value'];
      if (!empty($data['field_itg_content_publish_date_value'])) {
        $db_date = $data['field_itg_content_publish_date_value'];
      } else {
        $db_date = $data['created'];
      }
      $published_date = gmdate('D, d M Y H:i:s T', strtotime($db_date));
      if (date('Y', strtotime($published_date)) == '1970') {
        $published_date = date('D, d M Y H:i:s', strtotime($data['created']));
      }
      $xml .= '<title> <![CDATA[ ' . html_entity_decode($node_title) . ' ]]></title>' . "\r\n";
      if (isset($data['name']) && !empty($data['name'])) {
        $xml .= '<sectionname> <![CDATA[ ' . $data['name'] . ' ]]></sectionname>' . "\r\n";
      }
      $xml .= '<link> <![CDATA[ ' . check_url($node_link) . ' ]]></link>' . "\r\n";
      if ($arg[0] == 'rss-gallery') {
        $description = $data['title'];
        $xml .='<description> <![CDATA[  <a href="' . $node_link . '"> <img align="left" hspace="2" align="left" hspace="2" height="82" width="107" alt="" border="0" src="' . $node_extra_large_image_url . '"> </a> ' . $description . '<br clear="all" /> ]]></description>' . "\r\n";
      } else if ($arg[0] == 'rss-video') {
        $xml .='<description> <![CDATA[  <a href="' . $node_link . '"> <img align="left" hspace="2" align="left" hspace="2" height="82" width="107" alt="" border="0" src="' . $node_extra_large_image_url . '"> </a> ' . $description . ' <br clear="all" /> ]]></description>' . "\r\n";
      } else {
        $xml .='<description> <![CDATA[  <a href="' . $node_link . '"> <img align="left" hspace="2" height="180" width="305" alt="" border="0" src="' . $node_extra_large_image_url . '"> </a> ' . $description . ']]></description>' . "\r\n";
      }
      $xml .= '<pubDate> ' . $published_date . '</pubDate>' . "\r\n";
      if ($arg[0] == 'rss-gallery') {
        $xml .='<media:description type="html">';
        $xml .= '<![CDATA[ <a href="' . $node_link . '"><img align="left" hspace="2" height="180" width="305" alt="" border="0" src="' . $node_extra_large_image_url . '"></a>';
        $xml .= ']]> </media:description>' . "\r\n";
        $xml .= '<media:thumbnail url="' . $node_extra_small_image_url . '"/>' . "\r\n";
        $xml .= '<media:content medium="image" type="image/jpg" url="' . $node_extra_small_image_url . '"/>' . "\r\n";
        $xml .= '<media:copyright>' . t("© @copyright India Today Group. All Rights Reserved.", array("@copyright" => date('Y'))) . '</media:copyright>' . "\r\n";
        //$xml .= '<pubDate>' . $published_date . '</pubDate>' . "\r\n";
      } else if ($arg[0] == 'rss-video') {
        $xml .= '<media:content type="video/quicktime" expression="full" url="' . $node_link . '">' . "\r\n";
        $xml .= '<media:category scheme="' . $node_link . '">' . get_term_name_from_tid_for_report(itg_widget_get_primary_cat($data['nid'], 1)) . '</media:category>' . "\r\n";
        $xml .= '<media:text type="plain"><![CDATA[ ' . check_plain($node_title) . ' ]]></media:text>' . "\r\n";
        $xml .= '<media:rating scheme="urn:simple">' . t('nonadult') . '</media:rating>' . "\r\n";
        $xml .= '<media:thumbnail width="107" height="82" url="' . $node_extra_small_image_url . '"/>' . "\r\n";
        $xml .= '</media:content>' . "\r\n";
      }

      $xml .= '</item>' . "\r\n";
    }
  }
  return $xml;
}
