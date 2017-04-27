<?php

/**
 * @file
 * This file is used to render formated tree of taxonomy terms.
 *
 * Create html formatted list output of terms.
 */
function itg_category_manager_custom_tree($tid) {
  // The vocabulary name
  $cat_name = 'category_management';
  // $tree is an array of all the terms in the vocabulary
  $tree = taxonomy_get_tree(taxonomy_vocabulary_machine_name_load($cat_name)->vid, $tid);
  $parent_term = taxonomy_term_load($tid);
  array_unshift($tree, $parent_term);

  $term_tree = array();
  $item_list = array();

  // Here we restructure this a bit so we can work with array keys.
  // Only necessary to streamline the logic necessary in the recursive functions.
  foreach ($tree as $term) {
    $term_tree[$term->tid] = $term;
  }
  // takes the flat array of terms and nest terms underneath their parent items.
  itg_category_manager_construct_nested_taxonomy_array($term_tree);
  $term_tree = array_reverse($term_tree);
  //generates the list items that are expected by theme_item_list.
  itg_category_manager_construct_nested_taxonomy_item_list($term_tree, $item_list);

  return theme('item_list', array('items' => $item_list));
}

/**
 * takes the flat array of terms and nest terms underneath their parent items.
 *
 * @param array $tree
 */
function itg_category_manager_construct_nested_taxonomy_array(&$tree) {
  foreach (array_reverse($tree) as $term) {
    if (!empty($term->parents[0]) && array_key_exists($term->parents[0], $tree)) {
      $tree[$term->parents[0]]->children[$term->tid] = $term;
      itg_category_manager_construct_nested_taxonomy_array($tree[$term->parents[0]]->children);
      unset($tree[$term->tid]);
    }
  }
}

/**
 * Nest children to parent term.
 *
 * @global string $base_url
 *   Base url of the site.
 * @param array $tree
 *   Taxonomy category tree for single parent.
 * @param array $item_list
 *   Nested category list format.
 */
function itg_category_manager_construct_nested_taxonomy_item_list(&$tree, &$item_list) {
  global $base_url;
  
  if ($base_url == BACKEND_URL) {
    $actual_base_url = FRONT_URL;
  }
  else {
    $actual_base_url = $base_url;
  }

  foreach (array_reverse($tree) as $term) {
    $other_details = itg_category_manager_tree_detail($term->tid);
   // p($other_details);
    $content_cat = itg_category_manager_term_get_content($term->tid);
    $output = '<div class="term-wrapper"><div class="term-detail cmd-heading"><i class="fa fa-minus-square-o" aria-hidden="true"></i><i class="fa fa-plus-square-o" aria-hidden="true"></i><p>' . $term->name . '</p></div>';

    $output .= '<div class="term-detail" id ="sef-url-' . $term->tid . '">' . $actual_base_url . '/' . $other_details->sef_url;
    $output .= '<span title="Copy to clipboard" class="itg-clipboard" data-clipboard-target="#sef-url-' . $term->tid . '"><i class="fa fa-clipboard" aria-hidden="true"></i></span>';
    $output .= '</div>';
    $output .= '<div class="term-detail">' . $term->tid . '</div>';
    $output .= '<div class="term-detail">' . $content_cat . '</div>';
    $output .= '<div class="term-detail">' . format_date($other_details->created, 'custom_date_d_m_y_') . '</div>';
    $output .= '<div class="term-detail">' . format_date($other_details->changed, 'custom_date_d_m_y_') . '</div>';
    $term_status = $other_details->status == 1 ? t('Active') : t('Inactive');
    $output .= '<div class="term-detail">' . $term_status . '</div>';
    $output .= '<div class="term-detail action">';
    $output .= l(t('<i class="fa fa-pencil-square-o" aria-hidden="true"></i> Edit'), 'taxonomy/term/' . $term->tid . '/edit', array('attributes' => array('class' => ''), 'html' => TRUE, 'query' => array('destination' => arg(0))));
    $output .= '</div></div>';
    $item_list[$term->tid] = array('data' => $output);
    if (isset($term->children) && $term->children) {
      itg_category_manager_construct_nested_taxonomy_item_list($term->children, $item_list[$term->tid]['children']);
    }
  }
}

/**
 * Get term detail from itg_category_manager table.
 */
function itg_category_manager_tree_detail($term_tid) {
  $itg_query = db_select('itg_category_manager', 'itg');
  $itg_query->join('itg_sef_url', 'sef', 'itg.tid = sef.tid');
  $itg_query->fields('itg')
      ->fields('sef', array('sef_url'))
      ->orderBy('sef.changed', 'DESC')
      ->range(0, 1)
      ->condition('itg.tid', $term_tid);
  $itg_result = $itg_query->execute()->fetchObject();

  return $itg_result;
}
