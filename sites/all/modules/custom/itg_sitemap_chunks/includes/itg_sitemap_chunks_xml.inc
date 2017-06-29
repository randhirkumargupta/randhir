<?php

/**
 * @file
 * Contains the function for  multiple sitemap xml files.
 */
module_load_include('inc', 'itg_sitemap_chunks', 'includes/itg_sitemap_chunks.db');

/**
 * Create xml sitemap.
 */
function itg_sitemap_chunks_create_xml_sitemap() {
  // Create main sitemap xml file.First we have to get all files name.
  $filesnames = itg_sitemap_chunks_get_files_name();
  // Create all sub files.
  foreach ($filesnames as $ms_id => $filesname) {
    itg_sitemap_chunks_create_sub_file($ms_id, $filesname);
  }
}

/**
 * Create sub files.
 *
 * @param int $ms_id
 *   File ms id.
 * @param string $filesname
 *   File name.
 */
function itg_sitemap_chunks_create_sub_file($ms_id, $filesname) {

  $total_links = itg_sitemap_chunks_get_sub_file_links($ms_id);

  if (!empty($total_links)) {
    header('Content-type: application/xml');
    $lastmod = date('Y-m-d');
    $xml = '<?xml version="1.0" encoding="UTF-8"?>';
    $xml .= '<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">';
    foreach ($total_links as $total_link) {
      $xml .= '<url>';
      $xml .= '<loc>' . $total_link['link'] . '</loc>';
      $xml .= '<lastmod>' . $lastmod . '</lastmod>';
      $xml .= '<priority>' . $total_link['changefreq'] . '</priority>';
      $xml .= '</url>';
    }
    $xml .= '</urlset>';
    echo $xml;
  }
}

/**
 * Get links for a subfile.
 *
 * @param int $ms_id
 *   Multiple sitemap id.
 *
 * @return array
 *   Having total links for sub file.
 */
function itg_sitemap_chunks_get_sub_file_links($ms_id) {
  // Get record for a file.
  $records = itg_sitemap_chunks_get_record($ms_id);


  $contents = !empty($records['content']) ? $records['content'] : array();
  $content_links = itg_sitemap_chunks_get_content_links($contents);
  $total_links = array_unique($content_links, SORT_REGULAR);

  $usedVals = array();
  $outArray = array();
  foreach ($total_links as $arrayItem) {
    if (!in_array($arrayItem['link'], $usedVals)) {
      $outArray[] = $arrayItem;
      $usedVals[] = $arrayItem['link'];
    }
  }
  return $outArray;
}

function itg_sitemap_chunks_for_section($section_tid) {
  $total_links = itg_sitemap_get_xml_data_for_section($section_tid);
  if (!empty($total_links)) {
    echo itg_sitemap_get_sitemap($total_links);
  }
}

/**
 * 
 * @param type $total_links
 * @return string
 */
function itg_sitemap_get_sitemap($total_links) {
  header('Content-type: application/xml');
  $xml = '<?xml version="1.0" encoding="UTF-8"?>';
  $xml .= '<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9" xmlns:news="http://www.google.com/schemas/sitemap-news/0.9">';
  foreach ($total_links as $total_link) {
    $xml .= '<url>';
    $xml .= '<loc>' . $total_link['url'] . '</loc>';
    $xml .= '<news:news>';
    // Publication tag start
    $xml .= '<news:publication>';
    // Language Name
    $xml .= '<news:name>';
    $xml .= $total_link['news_name'];
    $xml .= '</news:name>';
    // Language Tag
    $xml .= '<news:language>';
    $xml .= $total_link['news_language'];
    $xml .= '</news:language>';

    $xml .= '</news:publication>';
    //Publication tag END

    $xml .= '<news:publication_date>' . $total_link['news_publication_date'] . '</news:publication_date>';
    $xml .= '<news:title>' . $total_link['news_title'] . '</news:title>';
    $xml .= '<news:keywords>' . $total_link['news_keywords'] . '</news:keywords>';


    $xml .= '</news:news>';
    $xml .= '</url>';
  }
  $xml .= '</urlset>';
  return $xml;
}

function itg_sitemap_get_xml_data_for_section($section_tid) {
  $excluded_nodes = array();
  $xml_data_array = array();
  module_load_include('inc', 'itg_sitemap_chunks', 'includes/itg_sitemap_chunks_section.db');
  // Get all child of section.
  $childrens = taxonomy_get_children_all($section_tid, CATEGORY_MANAGMENT);
  // Include section too in childern and combine into single array.
  $childrens[] = $section_tid;
  sort($childrens);

  // Get database data to get frequency and type.
  $section_db_data = itg_sitemap_chunks_section_db_data($section_tid);
  $previous_time = itg_sitemap_get_previous_time($section_db_data);
  $content_types = itg_sitemap_get_required_content_type_for_xml();
  if (!empty(variable_get('itg_sitemap_exclude_nid'))) {
    $excluded_nodes = explode(",", variable_get('itg_sitemap_exclude_nid'));
  }
  // Get the all links for given type.
  $query = db_select('node', 'n');
  //In this table all the categories got sumited during the node submition.
  $query->leftJoin('field_data_field_story_category', 'fdsc', 'fdsc.entity_id=n.nid');
  $query->fields('n', array('nid'));
  // Add settings of content type condition.
  $query->condition('n.type', $content_types, 'IN');
  // get nodes of sub sub categories too.
  $query->condition('fdsc.field_story_category_tid', $childrens, 'IN');
  $query->condition('n.status', 1);
  //Condition to get nodes between frequency and current time.
  $query->condition('n.created', array($previous_time, REQUEST_TIME), 'BETWEEN');
  // Exclude node
  if (!empty($excluded_nodes)) {
    foreach ($excluded_nodes as $nid) {
      $query->condition('nid', $nid, "!=");
    }
  }
  $query->orderBy('n.nid', 'DESC');
  //get unique Noides.
  $query->groupBy('n.nid');
  $results = $query->execute()->fetchAllAssoc('nid');
  $nids_array = array_keys($results);
  if (!empty($nids_array)) {
    foreach ($nids_array as $nid) {
      $xml_data_array[] = itg_sitemap_get_section_sitemap_required_data($nid);
    }
  }
  return $xml_data_array;
}

function itg_sitemap_get_required_content_type_for_xml() {
  $query = db_select('itg_sitemap_chunks_content', 'iscc');
  $query->fields('iscc', array('content_type'));
  return$query->execute()->fetchCol();
}

/**
 * Function which gives previous timestamp as per the formate given.
 * Like if frequency type is "month" and frequency is "1" the this function will
 * return 1 month before's timestamp using strtotime("-1 month"));
 */
function itg_sitemap_get_previous_time($section_data) {
  // It Gives numaric value like 1,2,3,4 ....
  $frequency = $section_data->frequency;
  //$section_data->frequency_type gives three value day , month and year.
  //using below formate.
  // strtotime("-1 month"));
  return strtotime("-$frequency $section_data->frequency_type");
}

/**
 * Prepare array for xml
 * @param int $nid
 * @return array
 */
function itg_sitemap_get_section_sitemap_required_data($nid) {
  $final_data = array();
  $query = db_select('node', 'n');
  $query->fields('n', array('title', 'nid', 'created'));
  $query->condition('nid', $nid);
  $query->groupBy('n.nid');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  foreach ($result as $key => $data) {
    $final_data['news_title'] = itg_sitemap_get_xml_valid_data($data['title']);
    $final_data['news_keywords'] = itg_sitemap_get_xml_valid_data(itg_sitemap_get_metatag_of_node($data['nid']));
    $final_data['news_name'] = ITG_INDIATODAY_SITENAME_XML;
    $final_data['news_language'] = $GLOBALS['language']->language;
    $final_data['url'] = itg_sitemap_get_xml_valid_data(url(drupal_get_path_alias('node/' . $data['nid']), array('absolute' => TRUE)));
    $final_data['news_publication_date'] = date('c', $data['created']);
  }
  return $final_data;
}

/**
 * 
 * @param int $nid
 * @return type
 */
function itg_sitemap_get_metatag_of_node($nid) {
  $query = db_select('metatag', 'mt');
  $query->fields('mt', array('data'));
  $query->condition('mt.entity_id', $nid);
  $query->orderBy('mt.revision_id', 'DESC');
  $query->range(0, 1);
  $data = $query->execute()->fetchField();
  $unserialzed = unserialize($data);
  return $unserialzed['keywords']['value'];
}

/**
 * Function which is used to get xml validated data.
 */
function itg_sitemap_get_xml_valid_data($text) {
  return htmlspecialchars($text, ENT_XML1, 'UTF-8');
}

/**
 * Main function which gives liveblog sitemap
 */
function itg_sitemap_chunks_create_xml_sitemap_for_live_blog() {
  $live_blog_nid = array();
  $sitemap_xml_array = array();
  $limit = variable_get('itg_sitemap_chunks_number', 50000);
  // get all liveblog nids.
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_type', 'fdft', 'fdft.entity_id = n.nid');
  $query->fields('n', array('nid'));
  $query->condition('fdft.field_type_value', 'Live Blog');
  $query->orderBy('n.nid', 'DESC');
  $query->range(0, $limit);
  $live_blog_nids = $query->execute()->fetchCol();
  if (!empty($live_blog_nids)) {
    foreach ($live_blog_nids as $live_blog_nid) {
      // Get news sitemap required array.
      $sitemap_xml_array[] = itg_sitemap_get_section_sitemap_required_data($live_blog_nid);
    }
  }
  if (!empty($sitemap_xml_array)) {
    // Print news sitemap for given array.
    echo itg_sitemap_get_sitemap($sitemap_xml_array);
  }
}

function itg_sitemap_chunks_create_xml_sitemap_for_content_type() {
  $limit = variable_get('itg_sitemap_chunks_number', 50000);
  $content_types = array("story", "videogallery", "photogallery");
  foreach ($content_types as $CT) {
    
  }
}
