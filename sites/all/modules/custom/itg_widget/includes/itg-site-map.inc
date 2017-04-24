<?php

/**
 * @file
 * Main file for sitemap.
 */

/**
 * function to get sitemap.
 * @return type
 */
function itg_widget_site_map() {
  drupal_add_css(".nested-taxonomy-tree a:hover {color: #a00606 !important}", array("type" => "inline", "scope" => "footer"));
  $tree = extranet_get_nested_tree((int) CATEGORY_MANAGMENT);
  $keys = array_keys($tree);
  foreach ($keys as $index => $data) {
    $term_array = array($keys[$index] => $tree[$keys[$index]]);
    if ($index % 2 == 0) {
      $left_tree .= extranet_output_nested_tree($term_array);
    }
    else {
      $right_tree .= extranet_output_nested_tree($term_array);
    }
  }
  $print_tree = '<div class="row site-map"><div class="col-md-6">' . $left_tree . '</div> <div class="col-md-6">' . $right_tree . '</div></div>';
  return $print_tree;
}

/**
 * Function create nested tree ul li for given array format.
 * @param array $tree
 * @return string
 */
function extranet_output_nested_tree($tree) {
  if (count($tree)) {
    $output = '<ul class="nested-taxonomy-tree">';
    foreach ($tree as $term) {
      if (function_exists('itg_category_manager_term_state')) {
        if (itg_category_manager_term_state($term->tid)) {
          $output .= '<li class="taxonomy-term">';
          $output .= l($term->name, "taxonomy/term/$term->tid");
          if ($term->children) {
            $output .= extranet_output_nested_tree($term->children);
          }
          $output .= '</li>';
        }
      }
      else {
        $output .= '<li class="taxonomy-term">';
        $output .= l($term->name, "taxonomy/term/$term->tid");
        if ($term->children) {
          $output .= extranet_output_nested_tree($term->children);
        }
        $output .= '</li>';
      }
    }
    $output .= '</ul>';
  }
  return $output;
}

/**
 * Function to get array of active category tree array format.
 * @param array $terms
 * @param int $max_depth
 * @param int $parent
 * @param array $parents_index
 * @param int $depth
 * @return array
 */
function extranet_get_nested_tree($terms = array(), $max_depth = NULL, $parent = 0, $parents_index = array(), $depth = 0) {
  if (is_int($terms)) {
    $terms = taxonomy_get_tree($terms);
  }

  foreach ($terms as $term) {
    foreach ($term->parents as $term_parent) {
      if ($term_parent == $parent) {
        if (function_exists('itg_category_manager_term_state') && itg_category_manager_term_state($term->tid)) {
          $return[$term->tid] = $term;
        }
        else {
          $return[$term->tid] = $term;
        }
      }
      else {
        if (function_exists('itg_category_manager_term_state') && itg_category_manager_term_state($term->tid)) {
          $parents_index[$term_parent][$term->tid] = $term;
        }
        else {
          $parents_index[$term_parent][$term->tid] = $term;
        }
      }
    }
  }

  foreach ($return as &$term) {
    if (isset($parents_index[$term->tid]) && (is_null($max_depth) || $depth < $max_depth)) {
      $term->children = extranet_get_nested_tree($parents_index[$term->tid], $max_depth, $term->tid, $parents_index, $depth + 1);
    }
  }
  return $return;
}
