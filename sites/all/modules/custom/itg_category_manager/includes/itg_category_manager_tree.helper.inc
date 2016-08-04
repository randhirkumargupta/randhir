<?php

/**
 * @file
 * This file is used to render formated tree of taxonomy terms.
 *
 * Create html formatted list output of terms.
 */
function itg_autosave_custom_tree($tid) {
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
  itg_autosave_construct_nested_taxonomy_array($term_tree);
  $term_tree = array_reverse($term_tree);
  //generates the list items that are expected by theme_item_list.
  itg_autosave_construct_nested_taxonomy_item_list($term_tree, $item_list);

  return theme('item_list', array('items' => $item_list));
}

/**
 * takes the flat array of terms and nest terms underneath their parent items.
 *
 * @param array $tree
 */
function itg_autosave_construct_nested_taxonomy_array(&$tree) {  
  foreach (array_reverse($tree) as $term) {    
    if (array_key_exists($term->parents[0], $tree)) {
      $tree[$term->parents[0]]->children[$term->tid] = $term;      
      itg_autosave_construct_nested_taxonomy_array($tree[$term->parents[0]]->children);
      unset($tree[$term->tid]);
    }
  }  
}

/**
 * Nest children to parent term.
 *
 * @param array $tree
 * @param array $item_list
 */
function itg_autosave_construct_nested_taxonomy_item_list(&$tree, &$item_list) {
  foreach (array_reverse($tree) as $term) {
    $other_details = itg_autosave_tree_detail($term->tid);
    $output = '<div class="term-detail">' . $term->name . '</div>';
    $output .= '<div class="term-detail">' . format_date($other_details->created, 'custom_date_d_m_y_') . '</div>';
    $output .= '<div class="term-detail">' . format_date($other_details->changed, 'custom_date_d_m_y_') . '</div>';
    $term_status = $other_details->status == 1 ? t('Active') : t('Inactive');
    $output .= '<div class="term-detail">' . $term_status  . '</div>';    
    $output .= '<div class="term-detail">';
    $output .= l(t('Edit'), 'taxonomy/term/' . $term->tid . '/edit', array('attributes' => array('class' => ''), 'query' => array('destination' => arg(0))));
    $output .= '</div>';
    $item_list[$term->tid] = array('data' => $output);
    if ($term->children) {
      itg_autosave_construct_nested_taxonomy_item_list($term->children, $item_list[$term->tid]['children']);
    }
  }
}

/**
 * Get term detail from itg_category_manager table.
 */
function itg_autosave_tree_detail($term_tid) {
  $itg_query = db_select('itg_category_manager', 'itg');
  $itg_query->fields('itg')
      ->condition('tid', $term_tid);
  $itg_result = $itg_query->execute()->fetchObject();
  
  return $itg_result;
}