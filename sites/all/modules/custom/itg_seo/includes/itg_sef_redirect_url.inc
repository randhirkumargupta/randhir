<?php
/**
 * Implementing 'itg_common_custompath_insert_load'.
 * @param $node object
 * Creating Custom path alias for story, photogallery and videogallery
 */
function itg_common_custompath_insert_load($node) {
  $edited_sef_url = $node->path['alias'];
  if (!empty($edited_sef_url)) {
    $lencount_sef = strlen($edited_sef_url);
    if ($lencount_sef >= 160) {
      $node_sef = substr($edited_sef_url , 0 , 160);
    }
    else {
      $node_sef = $edited_sef_url;
    }
  }
  else {
    $title_lenght = strlen($node->title);
    if ($title_lenght >= 160) {
      $node_sef = substr($node->title , 0 , 160);
    }
    else {
      $node_sef = $node->title;
    }
  }
   
  if (!empty($node->workbench_moderation_state_new)) {
    if ($node->workbench_moderation_state_new == 'draft') {
      $published_date = date('Y-m-d' , $node->created);
    } else if ($node->workbench_moderation_state_new == 'published') {
        $published_date = date('Y-m-d' , $node->changed);
    }
  }
  else {
    if ($node->status == 0) {
      $published_date = date('Y-m-d' , $node->created);
    } else if ($node->status == 1) {
        $published_date = date('Y-m-d' , $node->changed);
    }
  }
  
  $getsection = !empty($node->field_primary_category[LANGUAGE_NONE][0]['value']) ? $node->field_primary_category[LANGUAGE_NONE][0]['value'] : '';
  if (!empty($getsection)) {
//    $parents = taxonomy_get_parents_all($getsection);
//    if (isset($parents) && !empty($parents)) {
//      foreach ($parents as $key => $val) {
//        $section_hierarchy[] = $val->name;
//      }
//    }
    if (is_issue_baised_magazine($node)) {
      $pathdata = 'magazine';
      $pathdata .= '/'. get_path_from_category($getsection);
      //Get node type.
      $pathdata .= '/' . $node->type;
      // Get issue date.
      $issue_date = $node->field_story_issue_date['und'][0]['value'];
      $issue_date_sef_format = date('Ymd' , strtotime($issue_date));
      // preapreurl with issue date.
      $pathdata .= '/' . $issue_date_sef_format;
      // Add node title.
      $pathdata .= '-' . trim($node_sef);
      // Add node id.
      $pathdata .= '-' . $node->nid;
      // Add workbanch date.
      $pathdata .= '-' . $published_date;
      // Prepare SEO friendly node url
      $newpath = itg_common_custompath_insert_val($pathdata);
      return $newpath;
      // Create url alise for magazine type story.
      //$node->path = array('alias' => $newpath , 'pathauto' => FALSE);
    }
    elseif (is_photo_story($node)) {
      //Add path from category.
      $pathdata = get_path_from_category($getsection);
      // Add static value for photo story.
      $pathdata .= '/photo-story';
      // Add node title.
      $pathdata .= '/' . trim($node_sef);
      // Add node id.
      $pathdata .= '/' . $node->nid;
      // Add workbanch date.
      $pathdata .= '/' . $published_date;
      // Prepare SEO friendly node url
      $newpath = itg_common_custompath_insert_val($pathdata);
      return $newpath;
      // Create url alise for magazine type story.
      //$node->path = array('alias' => $newpath , 'pathauto' => FALSE);
    }
    else {
      $set_hierarchy = get_path_from_category($getsection);
      $pathdata = $set_hierarchy . '/' . $node->type . '/' . trim($node_sef) . '-' . $node->nid . '-' . $published_date;
      $newpath = itg_common_custompath_insert_val($pathdata);
      return $newpath;
      //$node->path = array('alias' => $newpath , 'pathauto' => FALSE);
      
      /*$set_hierarchy = array_reverse($section_hierarchy);
      $pathdata = strtolower(implode("/" , $set_hierarchy)) . '/' . $node->type . '/' . trim($node_sef) . '-' . $node->nid . '-' . $published_date;
      $newpath = itg_common_custompath_insert_val($pathdata);
      $node->path = array('alias' => $newpath , 'pathauto' => FALSE);*/
    }
  }
}

function is_photo_story($node) {
  $flag = FALSE;
  if (!empty($node->field_story_type['und'][0]['value']) && $node->field_story_type['und'][0]['value'] == 'photo_story' && empty($node->field_story_magazine_story_issue['und'][0]['value'])) {
    $flag = TRUE;
  }
  return $flag;
}

function is_issue_baised_magazine($node) {
  $flag = FALSE;
  if (!is_photo_story($node) && !empty($node->field_story_magazine_story_issue['und'][0]['value']) && $node->field_story_magazine_story_issue['und'][0]['value'] == 'magazine_issue_story') {
    $flag = TRUE;
  }
  return $flag;
}

/**
 * Implementing 'itg_common_custompath_migrated_load'.
 * @param $node object
 * Creating Custom path alias for story, photogallery and videogallery
 */
function itg_common_custompath_migrated_load($node , $type = NULL) {
  if (!empty($node->path['alias'])) {

    $node_sef = $node->path['alias'];
  }
  else {
    $title_lenght = strlen($node->title);
    if ($title_lenght >= 160) {
      $node_sef = substr($node->title , 0 , 160);
    }
    else {
      $node_sef = $node->title;
    }
  }

  if ($node->type == 'photogallery') {
    $published_date = date('Y-m-d' , $node->created);
  }
  else {
    $published_dat = explode(' ' , $node->field_itg_content_publish_date['und'][0]['value']);
    $published_date = $published_dat[0];
  }
  $getsection = !empty($node->field_primary_category[LANGUAGE_NONE][0]['value']) ? $node->field_primary_category[LANGUAGE_NONE][0]['value'] : '';
  if (!empty($getsection)) {
    $parents = taxonomy_get_parents_all($getsection);
    if (isset($parents) && !empty($parents)) {
      foreach ($parents as $key => $val) {
        $section_hierarchy[] = $val->name;
      }
    }
    $set_hierarchy = array_reverse($section_hierarchy);
    if ($type != 'update_migrated') {
      $pathdata = strtolower(implode("/" , $set_hierarchy)) . '/' . $node->type . '/' . trim($node_sef) . '-' . $node->nid . '-' . $published_date;
      // $newpath = itg_common_custompath_insert_val($pathdata);
      $newpath = $pathdata;
    }
    else {
      $newpath = $node_sef;
    }
    $node->path = array('alias' => $newpath , 'pathauto' => FALSE);
  }
}

/**
 * Implementing 'itg_common_custompath_insert_val'.
 * @param $pathdata path alias content
 * Creating custom path alias 
 */
function itg_common_custompath_insert_val($pathdata) {

  if (preg_match("![^a-z0-9]!i" , $pathdata)) {
    $pathdata = preg_replace('/[^a-zA-Z0-9\/\\.\']/' , '-' , $pathdata);
    while (preg_match('/--/' , $pathdata)) {
      $pathdata = preg_replace('/--/' , '-' , $pathdata);
    }
    $pathdata = rtrim($pathdata , "-");
    $pathdata = strtolower($pathdata);
    $pathdata = str_replace(array(':' , '*' , '"' , "'" , '#') , "-" , $pathdata);
  }
  return $pathdata;
}

function get_path_from_category($tid) {
  $pathdata = '';
  
  $all_terms = taxonomy_get_parents_all($tid);
  
  foreach ($all_terms as $key => $val) {
    if ($val->tid == $tid) {
     $primary_cat_name = trim($val->name); 
    }    
    $section_name = trim($val->name);    
  }
  
  if ($section_name == $primary_cat_name) {
    //prepare ur with parimary cat only.
    $pathdata = strtolower($primary_cat_name);
  }
  else {
    //prepare ur with parimary cat and section both.
    $pathdata = strtolower($section_name) . '/' . strtolower($primary_cat_name);
  }
  
  
  // Get parent of primary category.
//  $all_terms = taxonomy_get_parents_all($getsection);
//  $terms_bunch = array_reverse($all_terms);
//  $section_name = $terms_bunch[0]->name; //section
  
  
  
  // Get parent of primary category.
//  $primary_cat_array = taxonomy_term_load($getsection);
//  $primary_cat_name = $primary_cat_array->name;
//  // Handle case if section and parimary category are same.
//  if ($section_name == $primary_cat_name) {
//    //prepare ur with parimary cat only.
//    $pathdata .= strtolower($primary_cat_name);
//  }
//  else {
//    //prepare ur with parimary cat and section both.
//    $pathdata .= strtolower($section_name) . '/' . strtolower($primary_cat_name);
//  }
  return $pathdata;
}