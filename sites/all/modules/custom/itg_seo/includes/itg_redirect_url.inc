<?php

/**
 * itg_get_node_redirect_url 
 * @param object $node
 * @param string $op
 */
function itg_get_node_redirect_url($node, $op) {
  global $base_url;
  
  //if ($base_url == FRONT_URL) {
    if (isset($node->type) && ($node->type == 'story' || $node->type == 'photogallery' || $node->type == 'videogallery' || $node->type == 'podcast' || $node->type == 'blog')) {
      $story_expiry_date = '';
      $current_time = time();

      if (!empty($node->field_story_expiry_date[LANGUAGE_NONE][0]['value'])) {
        $story_expiry_date = strtotime($node->field_story_expiry_date[LANGUAGE_NONE][0]['value']);
      }

      if ($op == 'view' && (($node->status == 0) || (!empty($story_expiry_date) && $story_expiry_date < $current_time))) {
        if (!empty($node->field_primary_category[LANGUAGE_NONE][0]['value'])) {
          itg_get_redirect_url($node->field_primary_category[LANGUAGE_NONE][0]['value']);
        } else {
            drupal_goto('<front>');
        }       
      }
    } else {
        if ($op == 'view' && ($node->status == 0)) {
          drupal_goto('<front>');
        }
    }
 // }
  
}

/**
 * hook_taxonomy_term_load 
 * @param object $node
 * @param string $op
 */
function itg_seo_taxonomy_term_load($terms) {
  //if ($base_url == FRONT_URL) {
    if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2)) && empty(arg(3))) {
      if (function_exists('itg_category_manager_term_state')) { 
        if (!itg_category_manager_term_state(arg(2))) {      
          itg_get_taxonomy_redirect_url(arg(2));
        }
      }
    }
  //}
}

/**
 * itg_get_taxonomy_redirect_url 
 * @param init $tid
 */
function itg_get_taxonomy_redirect_url($tid) {  
  $tid = itg_get_parents_taxonomy($tid);
  if ($tid != 0) {
    itg_get_redirect_url($tid);
  } else {
      drupal_goto('<front>');
  }
  
  /*$section_tids = taxonomy_get_parents_all($tid); 
  foreach($section_tids as $key => $val) {
    if (itg_category_manager_term_state($val)) {
      itg_get_redirect_url($val);
    }
  }*/
  
}

/**
 * itg_get_redirect_url 
 * @param init $tid
 */
function itg_get_redirect_url($val) {  
  $red_url = drupal_get_path_alias('taxonomy/term/'.$val);   
  drupal_goto($red_url);
  exit;
}


/**
 * itg_get_parents
 * @param int $tid
 * @return $itg_result
 */
function itg_get_parents_taxonomy($tid) {
  $itg_query = db_select('taxonomy_term_hierarchy', 'itg')
      ->fields('itg', array('parent'))
      ->condition('tid', $tid, '=');      
  $itg_result = $itg_query->execute()->fetchField();
  return $itg_result;
}