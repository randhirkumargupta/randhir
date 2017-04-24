<?php

/*
 * Inc file contains the functions
 */

/**
 * Callback function for category name autocomplete.
 * 
 * @param string $string keyword for auto suggest.
 * @return json Autocomplete callback for category filter view
 */
function itg_category_autocomplete_list($string) {
  
  if (!empty(arg(1)) && arg(1) == 'section') {
    $result = custom_taxonomy_get_tree($string, CATEGORY_MANAGMENT, $parent = arg(2), $max_depth = NULL, $load_entities = FALSE);
  } else {
    $itg_query = db_select('taxonomy_term_data', 'itg');
    $itg_query->condition('vid', CATEGORY_MANAGMENT, '=');
    $itg_query->condition('name', '%' . $string . '%', 'LIKE')
              ->fields('itg', array('tid', 'name'));

    $result = $itg_query->execute()->fetchAll();
  }
    
 if (isset($result)) { 
   foreach ($result as $value) {    
     $name = $value->name.'('.$value->tid.')';
     $data[$name] = $name;
   }  

   return drupal_json_output($data);
 }

}

/**
 * Implements page callback.
 * @return
 */
function section_widgets_ajax() {
  global $user;  
  $arg = arg();
  
  if($arg[1] == 'insert') {
    // insert query
    if ((isset($_GET['section_name']) && ($_GET['section_name'] != '_none')) 
            && (isset($_GET['template_name']) 
            && ($_GET['template_name'] != '_none'))) {
      //widgets_type
      $category_array = explode('(', $_GET['category_name']);
      $cid = substr($category_array[1], 0,-1);
      // category exit or not for this section
      $check_cid = get_section_widgets_id($cid, $_GET['section_name'], $_GET['widgets_type']);
      
      if (empty($check_cid)) {
        $query_layout_tpl = db_insert('itg_section_widgets_list');
            $query_layout_tpl->fields(array(
              'template_section_name' => $_GET['section_name'],
              'template_name' => $_GET['template_name'],
              'category_name' => $category_array[0],
              'category_id' => $cid,
              'widget_type' => $_GET['widgets_type'],
              'created_date' => time()        
            ));

        $unpublish_tpl_id = $query_layout_tpl->execute();
      }
    }
  }
  elseif ($arg[1] == 'delete') {
    $query = db_select('itg_section_widgets_list', 'section');
    $query->fields('section', array('widget_type'));
    $query->condition('id', $_GET['id']);
    $_GET['widgets_type'] = $query->execute()->fetchField();
      
    db_delete('itg_section_widgets_list')->condition('id', $_GET['id'])->execute();
  }
  
  $content = display_section_widgets_list($_GET['section_name'], $_GET['template_name'], $_GET['widgets_type']); 
  
  echo $content;
  exit;
  
}

/**
 * Implements page callback for layout-search-widgets-list.
 * @return 
 */
function itg_search_widgets_list() {
  if (arg(1) == 'highlights') {
    $arg1 = 'heighlights';
  } else {
      $arg1 = arg(1);
  }
  
  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'title'));  
  $query->condition('type', $arg1);
  $query->condition('title', $_GET['html_title']);
  $itg_result = $query->execute()->fetchAll();
  
  foreach ($itg_result as $key => $val) {
    $content .= '<li id="'.$val->title.'" data-widget="'.arg(1).'#'.$val->nid.'" data-widget-info="">
    <span>'.$val->title.'</span></li>';
  }
  
  echo $content;
  exit;
}

/**
 * Create a hierarchical representation of a vocabulary.
 *
 * @param $vid
 *   Which vocabulary to generate the tree for.
 * @param $parent
 *   The term ID under which to generate the tree. If 0, generate the tree
 *   for the entire vocabulary.
 * @param $max_depth
 *   The number of levels of the tree to return. Leave NULL to return all levels.
 * @param $load_entities
 *   If TRUE, a full entity load will occur on the term objects. Otherwise they
 *   are partial objects queried directly from the {taxonomy_term_data} table to
 *   save execution time and memory consumption when listing large numbers of
 *   terms. Defaults to FALSE.
 *
 * @return
 *   An array of all term objects in the tree. Each term object is extended
 *   to have "depth" and "parents" attributes in addition to its normal ones.
 *   Results are statically cached. Term objects will be partial or complete
 *   depending on the $load_entities parameter.
 */
function custom_taxonomy_get_tree($string, $vid, $parent = 0, $max_depth = NULL, $load_entities = FALSE) {
  $children = &drupal_static(__FUNCTION__, array());
  $parents = &drupal_static(__FUNCTION__ . ':parents', array());
  $terms = &drupal_static(__FUNCTION__ . ':terms', array());

  // We cache trees, so it's not CPU-intensive to call taxonomy_get_tree() on a
  // term and its children, too.
  if (!isset($children[$vid])) {
    $children[$vid] = array();
    $parents[$vid] = array();
    $terms[$vid] = array();

    $query = db_select('taxonomy_term_data', 't');
    $query->join('taxonomy_term_hierarchy', 'h', 'h.tid = t.tid');
    $result = $query
      ->addTag('translatable')
      ->addTag('term_access')
      ->fields('t')
      ->fields('h', array('parent'))
      ->condition('t.vid', $vid)
      ->condition('t.name', '%' . $string . '%', 'LIKE')
      ->orderBy('t.weight')
      ->orderBy('t.name')
      ->execute();

    foreach ($result as $term) {      
      $children[$vid][$term->parent][] = $term->tid;
      $parents[$vid][$term->tid][] = $term->parent;
      $terms[$vid][$term->tid] = $term;
    }    
  }

  // Load full entities, if necessary. The entity controller statically
  // caches the results.
  if ($load_entities) {
    $term_entities = taxonomy_term_load_multiple(array_keys($terms[$vid]));
  }

  $max_depth = (!isset($max_depth)) ? count($children[$vid]) : $max_depth;
  $tree = array();

  // Keeps track of the parents we have to process, the last entry is used
  // for the next processing step.
  $process_parents = array();
  $process_parents[] = $parent;

  // Loops over the parent terms and adds its children to the tree array.
  // Uses a loop instead of a recursion, because it's more efficient.
  while (count($process_parents)) {
    $parent = array_pop($process_parents);
    // The number of parents determines the current depth.
    $depth = count($process_parents);
    if ($max_depth > $depth && !empty($children[$vid][$parent])) {
      $has_children = FALSE;
      $child = current($children[$vid][$parent]);
      do {
        if (empty($child)) {
          break;
        }
        $term = $load_entities ? $term_entities[$child] : $terms[$vid][$child];
        if (isset($parents[$vid][$term->tid])) {
          // Clone the term so that the depth attribute remains correct
          // in the event of multiple parents.
          $term = clone $term;
        }
        $term->depth = $depth;
        unset($term->parent);
        $term->parents = $parents[$vid][$term->tid];
        $tree[] = $term;
        if (!empty($children[$vid][$term->tid])) {
          $has_children = TRUE;

          // We have to continue with this parent later.
          $process_parents[] = $parent;
          // Use the current term as parent for the next iteration.
          $process_parents[] = $term->tid;

          // Reset pointers for child lists because we step in there more often
          // with multi parents.
          reset($children[$vid][$term->tid]);
          // Move pointer so that we get the correct term the next time.
          next($children[$vid][$parent]);
          break;
        }
      } while ($child = next($children[$vid][$parent]));

      if (!$has_children) {
        // We processed all terms in this hierarchy-level, reset pointer
        // so that this function works the next time it gets called.
        reset($children[$vid][$parent]);
      }
    }
  }
  //for section
  if(!empty($terms[$vid][$parent])) {
    $tree[] = $terms[$vid][$parent];
  }

  return $tree;
}

/**
 * callback for all the story of title
 * @param $title
 */
function content_custom_widgets_title($title) {

    if (strlen(trim($title)) > 0) {
        $options = '';
        $title = strtolower(trim($title));
        $query = db_select('itg_custom_widgets_data', 'icw');
        $query->fields('icw', array('widget'));
        $query->condition('widget', '%' . $title . '%', 'LIKE');
        $query->range(0, 20);

        $result = $query->execute();

        while ($record = $result->fetchAssoc()) {
            $options[$record['widget']] = $record['widget'];
        }

        drupal_json_output($options);
    }
}

/**
 * Implements page callback for layout-search-widgets-list.
 * @return 
 */
function custom_content_widgets() {
  $query = db_select('itg_custom_widgets_data', 'icw');
        $query->fields('icw', array('widget'));
        $query->condition('widget', $_GET['content_title']);
  $itg_result = $query->execute()->fetchAll();
  $val = $itg_result[0];
  //foreach ($itg_result as $key => $val) {
    $content .= '<li id="'.$val->widget.'" data-widget="custom_content_widgets#'.$val->widget.'" data-widget-info="">
    <span>'.$val->widget.'</span></li>';
  //}
  
  echo $content;
  exit;
}


