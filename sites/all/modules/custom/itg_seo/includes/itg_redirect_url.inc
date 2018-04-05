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
      
      /*$story_expiry_date = '';
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
      }*/
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

/*
 * Used this function to get Video id of Migrated content.
 * @param String $string
 * @return int
 */
function getdecryptForEmbed($string){
	$decrypter = gmp_strval(gmp_init($string, 36));
	$decrypter = gmp_shiftr_update($decrypter, 5);
	$decrypter = gmp_export($decrypter);
	return $decrypter;
}

function gmp_shiftr_update($x,$n) { // shift right 
  return(gmp_div($x,gmp_pow(2,$n))); 
}

/*
 * Fucnction to get new Embed url from old embed code.
 * @param String $videoembed
 * return String
 */
function getNewVideoEmbedUrl($videoembed) {
  global $base_url;
  $newurl = '';
  $videoid = getdecryptForEmbed($videoembed);
  $newvideoid = get_new_seccat_by_mig_id($videoid, 'migrate_map_itgvideogallery');
  if ($newvideoid) {
    $video_decode = base64_encode($newvideoid);
    $video_node = node_load($newvideoid);
    $tid = $video_node->field_primary_category[LANGUAGE_NONE][0]['value'];
    $term = taxonomy_term_load($tid);
    $primary_category_name = strtolower(itg_common_custompath_insert_val($term->name));
    $newurl = $base_url.'/video/' . $primary_category_name.'/embed/'.$video_decode;
  }
  return $newurl;
}

/*
 * Get Story url from .html pattern
 * @param String
 */
function getNewStoryUrl($storyarg, $table) {
  global $base_url;
  $newmatchurl = '';
  $storyarg_exp = explode('.html', $storyarg);
  $old_content_id = $storyarg_exp[0];
  //$table = 'migrate_map_itgstorylist';
  $newcontentid = get_new_seccat_by_mig_id($old_content_id, $table);
  if ($newcontentid) {
    $redirecturl = get_redirect_url($newcontentid);
    $newmatchurl = FRONT_URL.'/'.$redirecturl;
  }
  return $newmatchurl;
}

/**
 * function for get first issue from year
 * @param int $year
 * @return string $output
 */
function get_first_issue_by_year($year){
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_issue_title', 'ft', 'ft.entity_id = n.nid');
  $query->fields('ft', array('field_issue_title_value'));
  $query->condition('ft.field_issue_title_value', $year, '>=');
  $query->orderBy('n.title', 'ASC');
  $query->condition('n.type', 'issue', '=');
  $query->condition('n.status', 1, '=');
  $query->range(0, 1);
  $output = $query->execute()->fetchField();
  return $output;
}


/**
 * function of get issue URL
 * @param int nid
 * @return string $output
 */
function get_issue_by_id($nid) {
  $url = '';
  $query = db_select('migrate_map_itgissue', 'mmi');
  $query->leftJoin('field_data_field_issue_title', 'ft', 'ft.entity_id = mmi.destid1');
  $query->fields('ft', array('field_issue_title_value'));
  $query->condition('ft.bundle', 'issue', '=');
  $query->range(0, 1);
  $output = $query->execute()->fetchField();
  $current_issue = explode(' 00:', $output);
  if (!empty($current_issue)) {
    $url = 'magazine/'.format_date(strtotime($current_issue[0]),'custom', 'd-m-Y');
    $url = FRONT_URL.'/'.$url;
  }
  return $url;
}

