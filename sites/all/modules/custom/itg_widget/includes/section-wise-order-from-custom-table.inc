<?php

/**
 * @file
 * home page feature ordering and reordering
 */

/**
 * function to get data of nodes in sequence which is saved in draggableviews_structure table
 * @param array $info
 * @return array
 */
function itg_widget_section_wise_ordering_from_custom_table($info, $widget_style = NULL) {
  if (is_array($info)) {
      $range = 3; 
    // set range of data here
      $rangearray=array('auto-road-trip'=>2,'auto-tips-and-tricks'=>3,'buying-guid'=>6,'tech-tips'=>4,'in-depth'=>6,'talking-point'=>4 , 'movies-lifestyle'=>7 , 'movies-celebrities'=>7 ,'oscar-news'=>5 , 'oscar-features'=>6);
    
       if(array_key_exists($widget_style, $rangearray))
       {
           $range = $rangearray[$widget_style]; 
      }
      if($widget_style=='talking-point')
      {
          return itg_widget_section_wise_ordering_from_custom_table_by_content($info, 'story',$widget_style);
      }
      
      
      
    $cat_id = $info['section'];
    $view_name = $info['view_name'];
    $widget_name = _get_widget_name($view_name, 'page');
    $query = db_select('itg_widget_order', 'iwo');
    $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
    $query->fields('iwo', array('nid', 'weight'))
            ->condition('iwo.cat_id', $cat_id)
            // fix for getting all content type
            ->condition('iwo.widget', $widget_name)
            ->condition('n.status', '1')
            ->orderBy('iwo.weight','DESC')
            ->groupBy('iwo.nid')
            ->range(0, $range);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $weight_sum = 0;
    foreach ($result as $data) {
      $weight_sum += $data['weight'];
    }

    if ($weight_sum == 0) {
      $query = db_select('node', 'n');
      $query->leftJoin('itg_widget_order', 'iwo', 'n.nid=iwo.nid');
       $query->Join('taxonomy_index', 'tx', 'n.nid=tx.nid');
      $query->fields('iwo', array('nid', 'weight'))
             ->condition('tx.tid', $cat_id)
              ->condition('n.status', '1')
              ->orderBy('n.nid', 'DESC')
              ->groupBy('n.nid')
              ->range(0, $range);
      $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    }

    $entity_data = array();
    foreach ($result as $entity_data_node) {
      $entity_info = get_required_data_from_entity_id($entity_data_node['nid']);
      $entity_data[] = $entity_info[$entity_data_node['nid']];
    }
  
    return $entity_data;
  }
}

/**
 * function to get data of nodes in sequence which is saved in draggableviews_structure table
 * @param array $info
 * @return array
 */
function itg_widget_section_wise_ordering_from_custom_table_by_content($info, $content=NULL,$widget_style = NULL) {
  if (is_array($info)) {
      $range = 3; 
    // set range of data here
      $rangearray=array('auto-road-trip'=>2,'auto-tips-and-tricks'=>3,'buying-guid'=>6,'tech-tips'=>4,'in-depth'=>6,'talking-point'=>4 , 'oscar-news'=>5 , 'oscar-features'=>6);
    
       if(array_key_exists($widget_style, $rangearray))
       {
           $range = $rangearray[$widget_style]; 
      }
      
      
      
    $cat_id = $info['section'];
    $view_name = $info['view_name'];
    $widget_name = _get_widget_name($view_name, 'page');
    $query = db_select('itg_widget_order', 'iwo');
    $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
    $query->fields('iwo', array('nid', 'weight'))
            ->condition('iwo.cat_id', $cat_id)
            // fix for getting all content type
            ->condition('iwo.widget', $widget_name)
             ->condition('n.type', $content)
            ->condition('n.status', '1')
            ->orderBy('iwo.weight')
            ->groupBy('iwo.nid')
            ->range(0, $range);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $weight_sum = 0;
    foreach ($result as $data) {
      $weight_sum += $data['weight'];
    }

    if ($weight_sum == 0) {
      $query = db_select('node', 'n');
      $query->leftJoin('itg_widget_order', 'iwo', 'n.nid=iwo.nid');
       $query->Join('taxonomy_index', 'tx', 'n.nid=tx.nid');
      $query->fields('iwo', array('nid', 'weight'))
             ->condition('tx.tid', $cat_id)
              ->condition('n.type', $content)
              ->condition('n.status', '1')
              ->orderBy('n.nid', 'DESC')
              ->groupBy('n.nid')
              ->range(0, $range);
      $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    }

    $entity_data = array();
    foreach ($result as $entity_data_node) {
      $entity_info = get_required_data_from_entity_id($entity_data_node['nid']);
      $entity_data[] = $entity_info[$entity_data_node['nid']];
    }
    return $entity_data;
  }
}

/**
 * function to get data of nodes in sequence which is saved in draggableviews_structure table
 * @param array $info
 * @return array
 */
function itg_widget_section_wise_ordering_for_rhs_from_custom_table($info) {
  if (is_array($info)) {
    $cat_id = $info['section'];
    $view_name = $info['view_name'];
    $widget_name = _get_widget_name($view_name, 'page');
    $query = db_select('itg_widget_order', 'iwo');
    $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
    $query->fields('iwo', array('nid'))
            ->condition('iwo.cat_id', $cat_id)
            // fix for getting all content type
            ->condition('iwo.widget', $widget_name)
            ->condition('n.status', '1')
            ->orderBy('iwo.weight','DESC')
            ->range(0, 5);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $entity_data = array();
    foreach ($result as $entity_data_node) {
      $entity_info = get_required_data_from_entity_id($entity_data_node['nid']);
      $entity_data[] = $entity_info[$entity_data_node['nid']];
    }
    return $entity_data;
  }
}


