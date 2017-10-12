<?php

/**
 * itg_get_node_redirect_url 
 * @param object $node
 * @param string $op
 */
function itg_get_node_redirect_url($node, $op) {
  global $base_url;
  
  if ($base_url == FRONT_URL) {
    $itg_status = $node->status;
    
    if (isset($node->type) && ($node->type == 'story' || $node->type == 'photogallery' || $node->type == 'videogallery' || $node->type == 'podcast' || $node->type == 'blog')) {
      
      $story_expiry_date = '';
      $current_time = time();

      if (!empty($node->field_story_expiry_date[LANGUAGE_NONE][0]['value'])) {
        $story_expiry_date = strtotime($node->field_story_expiry_date[LANGUAGE_NONE][0]['value']);
      }
      
      if (!empty($node->field_story_schedule_date_time[LANGUAGE_NONE][0]['value'])) {
        $story_schedule_date = strtotime($node->field_story_schedule_date_time[LANGUAGE_NONE][0]['value']);
      }

      if ($op == 'full' && (($itg_status == 0) || (!empty($story_expiry_date) && $story_expiry_date < $current_time) || (!empty($story_schedule_date) && $story_schedule_date > $current_time))) {
        if (!empty($node->field_primary_category[LANGUAGE_NONE][0]['value'])) {
          itg_get_redirect_url($node->field_primary_category[LANGUAGE_NONE][0]['value']);
        } else {
            drupal_goto('<front>');
        }       
      }
    } else {
        if ($op == 'full' && ($itg_status == 0)) {
          drupal_goto('<front>');
        }
    }
  }
  
}

/**
 * hook_taxonomy_term_load 
 * @param object $node
 * @param string $op
 */
function itg_seo_taxonomy_term_load($terms) {
  
    if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2)) && empty(arg(3))) {
      if (function_exists('itg_category_manager_term_state') && ($terms[arg(2)]->vid == CATEGORY_MANAGMENT)) {
        
        if (!itg_category_manager_term_state(arg(2))) {      
          itg_get_taxonomy_redirect_url(arg(2));
        }
      }
    }
  
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

/**
 * Implements hook_url_inbound_alter().
 */
function itg_seo_url_inbound_alter(&$path, $original_path, $path_language) {
  $old_content_id = '';
  $arg = arg();
  $type = 'story'; // use photogallery & videogallery in condition if you have
  
  if (!empty($_GET['sId']) && is_numeric($_GET['sId'])) { //code for this URL (story.jsp?sId=877)
    $old_content_id = $_GET['sId'];
  } else if (!empty($_GET['option']) && $_GET['option'] == 'com_content' && arg(0) == 'conclave') {//conclave/index.php?option=com_content&task=view&id=2968&sectionid=15&secid=1&issueid=34&Itemid=1
      $old_content_id = '200'.$_GET['id'];
  } else if (!empty($_GET['option']) && $_GET['option'] == 'com_content') {//code for this URL (option=com_content)
      $old_content_id = $_GET['id'];
  } 
  //else if ((!empty($arg[0]) && $arg[0] == 'site') && (!empty($arg[1]) && strtolower($arg[1]) == 'story') && (!empty($arg[2]) && is_numeric($arg[2]))) {  // Pattern site/Story/3578/2/i-am-too-old-for-bwood-gauri-khan.html
      //$old_content_id = $arg[2];
  //} 
  else if ((!empty($arg[0]) && $arg[0] == 'site') && (!empty($arg[1]) && $arg[1] == 'Photo') && (!empty($arg[2]) && is_numeric($arg[2]))) {  // Pattern site/Photo/3578/2/i-am-too-old-for-bwood-gauri-khan.html
      $old_content_id = $arg[2];
      $type = 'photogallery';
  } else if ((!empty($arg[0]) && $arg[0] == 'site') && (!empty($arg[1]) && $arg[1] == 'Video') && (!empty($arg[2]) && is_numeric($arg[2]))) {  // Pattern site/Video/3578/2/i-am-too-old-for-bwood-gauri-khan.html
      $old_content_id = $arg[2];
      $type = 'videogallery';
  } else if ((!empty($arg[0]) && $arg[0] == 'gallerylist') && !empty($arg[1]) && !empty($arg[2]) && !empty($arg[3])) {  // Pattern gallerylist/photos-television/6/163.html
      $photo_cat = $arg[3];
      $photo_cat_explode = explode('.html', $photo_cat);
      $old_content_id = $photo_cat_explode[0];
      $type = 'category';
      $table = 'migrate_map_itgcategory'; // We are using table name migration because KT team not store source id in drupal field.
  } else if ((!empty($arg[0]) && $arg[0] == 'site') && (!empty($arg[1]) && $arg[1] == 'photo') && ($arg[2]== 0) && (!empty($arg[3] && is_numeric($arg[3]))) && !empty($arg[4])) {  // Pattern site/photo/0/2/photo.html for category listing
      $old_content_id = $arg[3];
      $type = 'category';
      $table = 'migrate_map_itgcategory';
  } else if ((!empty($arg[0]) && $arg[0] == 'MoreGallery') && ($_GET['gId'] == 0) && (!empty($_GET['photocat']))) {  // Pattern site/photo/0/2/photo.html for category listing
      $old_content_id = $_GET['photocat'];
      $type = 'category';
      $table = 'migrate_map_itgcategory';
  }
  else if ($arg[0] == 'node' && empty($arg[1])) {
      drupal_goto(FRONT_URL);
  }
  
  //code for url redirection
  if (!empty($old_content_id)) {
      if ($type == 'category') {
        $content_id = get_new_seccat_by_mig_id($old_content_id, $table);
        $alias = drupal_get_path_alias('taxonomy/term/'.$content_id);
      } else {
        $content_id = get_new_content_id_by_migrated_id($old_content_id, $type);
        $alias = drupal_get_path_alias('node/'.$content_id);
      }
      //$alias = get_redirect_url($content_id);
      if (isset($alias)) {
        drupal_goto($alias);
      }
      drupal_not_found();
      drupal_exit();
  }
  
}

/**
 * get new content id of itg by old content id
 * @param int $sourceid
 * @param string $type
 * @return int new content id
 */
function get_new_content_id_by_migrated_id($sourceid, $type) {
  $query = db_select('field_data_field_story_source_id', 'ssi');
  $query->fields('ssi', array('entity_id'));  
  $query->condition('field_story_source_id_value', $sourceid);
  $query->condition('bundle', $type);
  
  return $query->execute()->fetchField();
}

/**
 * get $alias
 * @param int $sourceid
 * @param string $type
 * @return int new content id
 */
function get_redirect_url($content_id) {
  $alias = drupal_get_path_alias('node/'.$content_id);
  return $alias; 
}

/**
 * Get Drupal Section or category id from ITG old system section or category id
 * @param int $sourceid
 * @param string $table
 * @return int new section or cat id
 */
function get_new_seccat_by_mig_id($sourceid, $table) {
  $query = db_select($table, 'scc');
  $query->fields('scc', array('destid1'));  
  $query->condition('sourceid1', $sourceid);
  return $query->execute()->fetchField();
}