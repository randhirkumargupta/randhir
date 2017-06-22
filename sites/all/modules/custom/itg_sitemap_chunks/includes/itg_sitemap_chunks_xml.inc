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
