<?php

/**
 * Function for getting sitemap for listed section and categories.
 */
function itg_sitemap_chunks_get_section_category_sitemap() {
  $sitemap_string = "";
  $sitemap_string .= "<urlset xmlns='http://www.sitemaps.org/schemas/sitemap/0.9' xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance' xsi:schemaLocation='http://www.sitemaps.org/schemas/sitemap/0.9 http://www.sitemaps.org/schemas/sitemap/0.9/sitemap.xsd'>";
  $sitemap_string .= "<url>";
  $sitemap_string .= "<loc> ".FRONT_URL."/</loc>";
  $l_node_timestamp = get_last_node_updated_time_by_taxonomy();
  $l_node_time = date('Y-m-d\TH:i:s', $l_node_timestamp) . '+05:30';
  $sitemap_string .= "<lastmod>" . $l_node_time . "</lastmod>";
  $sitemap_string .= "</url>";
  $sitemap_string .= "<url>";
  $sitemap_string .= "<loc> ".FRONT_URL."/magazine</loc>";
  $l_node_timestamp = get_last_node_updated_time_by_taxonomy('magazine');
  $l_node_time = date('Y-m-d\TH:i:s', $l_node_timestamp) . '+05:30';
  $sitemap_string .= "<lastmod>" . $l_node_time . "</lastmod>";
  $sitemap_string .= "</url>";
  $section_cat_ids = variable_get('section_category_sitemap_tids');
  $section_cat_ids_arr = explode(",", $section_cat_ids);
  foreach ($section_cat_ids_arr as $key => $tax_id) {
    $tax_url = FRONT_URL . '/' . drupal_get_path_alias('taxonomy/term/' . $tax_id);
    $l_node_updated_timestamp = get_last_node_updated_time_by_taxonomy($tax_id);
    $l_node_updated_time = date('Y-m-d\TH:i:s', $l_node_updated_timestamp) . '+05:30';
    $sitemap_string .= "<url>";
    $sitemap_string .= "<loc> " . $tax_url . " </loc>";
    $sitemap_string .= "<lastmod>" . $l_node_updated_time . "</lastmod>";
    $sitemap_string .= "</url>";
  }
  $sitemap_string .= "</urlset>";
  header('Content-Type: text/xml');
  print $sitemap_string;
}

/**
 * Function for getting last node updated time by taxonomy.
 * @param int $tid
 * @return type
 */
function get_last_node_updated_time_by_taxonomy($tid = null) {
  $query = db_select('node', 'n');
  if(!empty($tid) && is_numeric($tid)){
    $query->join('field_data_field_story_category', 'sct', 'sct.entity_id = n.nid');
  }  
  $query->fields('n', array('changed'));
  if(!empty($tid) && is_numeric($tid)){
    $query->condition('sct.field_story_category_tid', $tid);
  }
  if($tid == 'magazine'){
     $query->condition('n.type', 'issue');
  }
  else{
	  $query->condition('n.type', array('story', 'videogallery', 'photogallery'), 'IN');
  }  
  $query->condition('n.status', 1);
  $query->orderBy('n.changed', 'DESC');
  $query->range(0, 1);
  return $query->execute()->fetchField();
}
