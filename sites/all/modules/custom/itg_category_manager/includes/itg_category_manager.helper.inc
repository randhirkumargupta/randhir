<?php

/**
 * @file
 * Helper file for category manager module.
 */
/**
 * Implements hook_hierarchical_select_root_level()
 * @param array $params
 * @param boolean $dropbox
 * @return array
 */
function itg_category_manager_hierarchical_select_root_level($params,$dropbox = FALSE) {  // remove @$form_state second argument
  $vocabulary = taxonomy_vocabulary_load($params['vid']);
  $type = '';
  if(arg(0) == 'node' && arg(1) == 'add'){
      $type = arg(2);
  }elseif(arg(0) == 'node' && is_numeric(arg(1)) && arg(2) == 'edit'){
      $node = node_load(arg(1));
      $type = $node->type;
  }
  elseif(!empty ($_POST['cat_node_type']))
  {
     $type = $_POST['cat_node_type']; 
  }

  $terms = _hs_taxonomy_hierarchical_select_get_tree($params['vid'], 0, -1, 1);
  foreach ($terms as $key => $term) {    
    if (!itg_category_manager_term_state($term->tid)) {
      unset($terms[$key]);
    }
    if(!empty($type)){
    if(!itg_category_manager_term_state_content($type,$term->tid)) {
         unset($terms[$key]);
    }
    }
  }
  
  // If the root_term parameter is enabled, then prepend a fake "<root>" term.
  if (isset($params['root_term']) && $params['root_term'] === TRUE) {
    $root_term = new stdClass();
    $root_term->tid = 0;
    $root_term->name = '<' . t('root') . '>';
    $terms = array_merge(array($root_term), $terms);
  }
  
  return _hs_taxonomy_hierarchical_select_terms_to_options($terms); 
}

/**
 * Implements hook_hierarchical_select_params()
 * @return array
 */
function itg_category_manager_hierarchical_select_params() {
  return hs_taxonomy_hierarchical_select_params(); 
}

/**
 * Implements hook_hierarchical_select_children()
 * @global stdObj $user
 * @param int $parent
 * @param array $params
 * @param boolean $dropbox
 * @return array
 */
function itg_category_manager_hierarchical_select_children($parent, $params, $dropbox = FALSE) {
  global $user;
  if (isset($params['root_term']) && $params['root_term'] && $parent == 0) {
    return array();
  }

  $terms = taxonomy_get_children($parent, $params['vid']);
  foreach ($terms as $key => $term) {    
    if (!itg_category_manager_term_state($term->tid)) {
      unset($terms[$key]);
    }
  }

  // Unset the term that's being excluded, if it is among the children.
  if (isset($params['exclude_tid'])) {
    unset($terms[$params['exclude_tid']]);
  }

  // If the Term Permissions module is installed, honor its settings.
  if (function_exists('term_permissions_allowed')) {    
    foreach ($terms as $key => $term) {
      if (!term_permissions_allowed($term->tid, $user) ) {
        unset($terms[$key]);
      }
    }
  }

  return _hs_taxonomy_hierarchical_select_terms_to_options($terms);
}

/**
 * Implements hook_hierarchical_select_lineage()
 * @param int $item
 * @param array $params
 * @return array
 */
function itg_category_manager_hierarchical_select_lineage($item, $params) {
  return hs_taxonomy_hierarchical_select_lineage($item, $params);
}

/**
 * Implements hook_hierarchical_select_valid_item()
 * @param int $item
 * @param array $params
 * @return array
 */
function itg_category_manager_hierarchical_select_valid_item($item, $params) {
  return hs_taxonomy_hierarchical_select_valid_item($item, $params);
}

/**
 * 
 * @param int $item
 * @param array $params
 * @return array
 */
function itg_category_manager_hierarchical_select_item_get_label($item, $params) {
  return hs_taxonomy_hierarchical_select_item_get_label($item, $params);
}

/**
 * Implements hook_hierarchical_select_create_item()
 * @param string $label
 * @param int $parent
 * @param array $params
 * @return array
 */
function itg_category_manager_hierarchical_select_create_item($label, $parent, $params) {
  return hs_taxonomy_hierarchical_select_create_item($label, $parent, $params);
}

/**
 * Implements hook_hierarchical_select_entity_count
 * @param int $item
 * @param array $params
 * @return array
 */
function itg_category_manager_hierarchical_select_entity_count($item, $params) {
  return hs_taxonomy_hierarchical_select_entity_count($item, $params);
}

/**
 * Implements hook_hierarchical_select_implementation_info()
 * @return array
 */
function itg_category_manager_hierarchical_select_implementation_info() {
  return hs_taxonomy_hierarchical_select_implementation_info();
}

/**
 * Implements hook_hierarchical_select_config_info()
 * @return array
 */
function itg_category_manager_hierarchical_select_config_info() {
  return hs_taxonomy_hierarchical_select_config_info();
}
