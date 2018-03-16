<?php

/**
 * Function for getting sitemap for listed section and categories.
 */
function itg_sitemap_chunks_get_section_category_sitemap() {
  $sitemap_string = "";
  $sitemap_string .= "<urlset xmlns='http://www.sitemaps.org/schemas/sitemap/0.9' xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance' xsi:schemaLocation='http://www.sitemaps.org/schemas/sitemap/0.9 http://www.sitemaps.org/schemas/sitemap/0.9/sitemap.xsd'>";
  $section_cat_ids = variable_get('section_category_sitemap_tids');
  $section_cat_ids_arr = explode(",", $section_cat_ids);
  foreach ($section_cat_ids_arr as $key => $tax_id) {
    $tax_url = FRONT_URL . '/' . drupal_get_path_alias('taxonomy/term/' . $tax_id);
    $l_node_updated_time = get_last_node_updated_time_by_taxonomy($tax_id);
    $current_time = date('Y-m-d\TH:i:s', $l_node_updated_time) . '+00:00';
    $sitemap_string .= "<url>";
    $sitemap_string .= "<loc> " . $tax_url . " </loc>";
    $sitemap_string .= "<lastmod>" . $current_time . "</lastmod>";
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
function get_last_node_updated_time_by_taxonomy($tid) {
  $query = db_select('node', 'n');
  $query->join('field_data_field_story_category', 'sct', 'sct.entity_id = n.nid');
  $query->fields('n', array('changed'));
  $query->condition('sct.field_story_category_tid', $tid);
  $query->condition('n.type', array('story', 'videogallery', 'photogallery'), 'IN');
  $query->condition('n.status', 1);
  $query->orderBy('n.changed', 'DESC');
  $query->range(0, 1);
  return $query->execute()->fetchField();
}
