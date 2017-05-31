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
    }
    else if ($node->workbench_moderation_state_new == 'published') {
      $published_date = date('Y-m-d' , $node->changed);
    }
  }
  else {
    if ($node->status == 0) {
      $published_date = date('Y-m-d' , $node->created);
    }
    else if ($node->status == 1) {
      $published_date = date('Y-m-d' , $node->changed);
    }
  }

  $getsection = !empty($node->field_primary_category[LANGUAGE_NONE][0]['value']) ? $node->field_primary_category[LANGUAGE_NONE][0]['value'] : '';
  if (!empty($getsection) && $node->type != 'reporter' || ($node->type == 'podcast')) {
    if ($node->type == 'story' && is_issue_baised_magazine($node)) {
      if (!empty($node->field_story_select_supplement['und'][0]['target_id'])) {
        $pathdata = 'magazine/supplement';
      }
      else {
        $pathdata = 'magazine';
        $pathdata .= '/' . get_path_from_category($getsection);
      }
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
    }
    elseif ($node->type == 'story' && is_photo_story($node)) {
      //Add path from category.
      $pathdata = get_path_from_category($getsection);
      // Add static value for photo story.
      $pathdata .= '/photo-story';
      // Add node title.
      $pathdata .= '/' . trim($node_sef);
      // Add node id.
      $pathdata .= '-' . $node->nid;
      // Add workbanch date.
      $pathdata .= '-' . $published_date;
      // Prepare SEO friendly node url
      $newpath = itg_common_custompath_insert_val($pathdata);
      return $newpath;
      // Create url alise for magazine type story.      
    }
    else {
      $set_hierarchy = get_path_from_category($getsection);
      $node_CT = $node->type;
      if ($node_CT == 'photogallery') {
        $node_CT = 'photo';
      }
      elseif ($node_CT == 'videogallery') {
        $node_CT = 'videos';
      }
      $pathdata = $set_hierarchy . '/' . $node_CT . '/' . trim($node_sef) . '-' . $node->nid . '-' . $published_date;
      $newpath = itg_common_custompath_insert_val($pathdata);
      return $newpath;
    }
  }
  elseif ($node->type == 'reporter') {
    $occupation_tid = $node->field_celebrity_pro_occupation['und'][0]['tid'];
    $occupation = _occupation_from_tid_for_sef_url($occupation_tid);
    $pathdata = $occupation . '/' . $edited_sef_url;
    $newpath = itg_common_custompath_insert_val($pathdata);
    return $newpath;
  }
  elseif ($node->type == 'itg_funalytics') {
    $pathdata = 'understand' . '/' . $edited_sef_url;
    $newpath = itg_common_custompath_insert_val($pathdata);
    return $newpath;
  }
  elseif ($node->type == 'mega_review_critic') {
    $pathdata = 'movie/review/story' . '/' . trim($node_sef) . '-' . $node->nid . '-' . $published_date;
    $newpath = itg_common_custompath_insert_val($pathdata);
    return $newpath;
  }
  elseif ($node->type == 'page' || $node->type == 'blog') {
    $pathdata = $edited_sef_url;
    $newpath = itg_common_custompath_insert_val($pathdata);
    return $newpath;
  }
  elseif ($node->type == 'survey' || $node->type == 'quiz') {
    $pathdata = strtolower($node->type) . '/' . $edited_sef_url;
    $newpath = itg_common_custompath_insert_val($pathdata);
    return $newpath;
  }
}

/**
 * @param array $node
 * @return boolean
 */
function is_photo_story($node) {
  $flag = FALSE;
  if (!empty($node->field_story_type['und'][0]['value']) && $node->field_story_type['und'][0]['value'] == 'photo_story' && empty($node->field_story_magazine_story_issue['und'][0]['value'])) {
    $flag = TRUE;
  }
  return $flag;
}

/**
 * @param array $node
 * @return boolean
 */
function is_issue_baised_magazine($node) {
  $flag = FALSE;
  if (!is_photo_story($node) && !empty($node->field_story_magazine_story_issue['und'][0]['value']) && $node->field_story_magazine_story_issue['und'][0]['value'] == 'magazine_issue_story') {
    $flag = TRUE;
  }
  return $flag;
}

/**
 * @param array $node
 * @return boolean
 */
function is_reporter($node) {
  $flag = FALSE;
  if ($node->type == 'reporter') {
    $flag = TRUE;
  }
  return $flag;
}

/**
 * @param array $node
 * @return boolean
 */
function is_survey($node) {
  $flag = FALSE;
  if ($node->type == 'survey') {
    $flag = TRUE;
  }
  return $flag;
}

/**
 * @param array $node
 * @return boolean
 */
function is_quiz($node) {
  $flag = FALSE;
  if ($node->type == 'quiz') {
    $flag = TRUE;
  }
  return $flag;
}

/**
 * @param array $node
 * @return boolean
 */
function is_itg_funalytics($node) {
  $flag = FALSE;
  if ($node->type == 'itg_funalytics') {
    $flag = TRUE;
  }
  return $flag;
}

/**
 * @param array $node
 * @return boolean
 */
function is_mega_review_critic($node) {
  $flag = FALSE;
  if ($node->type == 'mega_review_critic') {
    $flag = TRUE;
  }
  return $flag;
}

/**
 * @param array $node
 * @return boolean
 */
function is_basic_page($node) {
  $flag = FALSE;
  if ($node->type == 'page') {
    $flag = TRUE;
  }
  return $flag;
}

/**
 * @param array $node
 * @return boolean
 */
function is_podcast($node) {
  $flag = FALSE;
  if ($node->type == 'podcast') {
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

/**
 * Function which gives sef url's section/subsection part.
 * @param int $tid
 * @return string
 */
function get_path_from_category($tid) {
  $section = array();
  $all_terms = taxonomy_get_parents_all($tid);
  $number_parent = count($all_terms);
  $section_key = $number_parent - 1;
  $subsection_key = $number_parent - 2;
  //Section
  if (isset($all_terms[$section_key]->name)) {
    $section[] = strtolower($all_terms[$section_key]->name);
  }
  if (isset($all_terms[$subsection_key]->name)) {
    $section[] = strtolower($all_terms[$subsection_key]->name);
  }
  return implode('/' , $section);
}

/**
 * @param string $entity_type
 *  Type of entity.
 * @param int $entity_id
 *  Entity id.
 * @param int $pathauto_state
 *  Pathauto state 0 or 1.
 */
function itg_custom_pathauto_state_save($entity_type , $entity_id , $pathauto_state) {
  try {
    db_merge('itg_pathauto_state')
        ->key(array(
          'entity_type' => $entity_type ,
          'entity_id' => $entity_id ,
        ))
        ->fields(array(
          'pathauto' => $pathauto_state ? 1 : 0 ,
        ))
        ->execute();
  }
  catch (Exception $ex) {
    drupal_set_message($ex->getMessage());
  }
}

/**
 * This function is called via ajax when sef checkbox is unchecked.
 * @param int $node_id
 * @param string $node_type
 * @param blooean $pathauto_state
 */
function itg_custom_pathauto_state_unset($node_id , $node_type , $pathauto_state) {
  itg_custom_pathauto_state_save($node_type , $node_id , $pathauto_state);
}

/**
 * Give status of pathauto.
 * @param int $entity_id
 * @param string $entity_type
 * @return int
 */
function itg_custom_pathauto_get_sef_url_state($entity_id , $entity_type) {
  $query = db_select('itg_pathauto_state' , 'ips');
  $query->addField('ips' , 'pathauto');
  $query->condition('entity_id' , $entity_id);
  $query->condition('entity_type' , $entity_type);
  return $query->execute()->fetchField();
}

/**
 * Function which saves Pathauto status value in custom table after form submit.
 */
function itg_custom_pathauto_save_sef_status($form , &$form_state) {
  $pathauto_state = 0;
  $pathauto = $form_state['values']['path']['pathauto'];
  $node_id = $form_state['values']['nid'];
  $node_type = $form_state['values']['type'];
  if ($pathauto) {
    $pathauto_state = 1;
  }
  itg_custom_pathauto_state_save($node_type , $node_id , $pathauto_state);
}

/**
 * Return SEF Url
 */
function itg_get_sef_url($sef_path , $nodeid) {
  if (isset($sef_path) && !empty($sef_path)) {
    $node_object = node_load($nodeid);
    // Handel edit case for issue baised story.
    $is_issue_magazine = is_issue_baised_magazine($node_object);
    $is_photo_story = is_photo_story($node_object);
    $is_reporter = is_reporter($node_object);
    $is_itg_funalytics = is_itg_funalytics($node_object);
    $is_mega_review_critic = is_mega_review_critic($node_object);
    $is_basic_page = is_basic_page($node_object);
    $is_podcast = is_podcast($node_object);
    $is_survey = is_survey($node_object);
    $is_quiz = is_quiz($node_object);
    if ($is_issue_magazine) {
      $path_alias_set = $sef_path;
      $path_data = explode("/" , $path_alias_set);
      $edit_path_data = end($path_data);
      $new_url_array = explode('-' , $edit_path_data);
      $array_size = count($new_url_array);
      unset($new_url_array[0]);
      unset($new_url_array[$array_size - 4]);
      unset($new_url_array[$array_size - 3]);
      unset($new_url_array[$array_size - 2]);
      unset($new_url_array[$array_size - 1]);
      $edited_sef_url = implode('-' , $new_url_array);
    }
    elseif ($is_photo_story || $is_mega_review_critic || $is_podcast) {
      $path_alias_set = $sef_path;
      $path_data = explode("/" , $path_alias_set);
      $edit_path_data = end($path_data);
      $new_url_array = explode('-' , $edit_path_data);
      $array_size = count($new_url_array);
      unset($new_url_array[$array_size - 4]);
      unset($new_url_array[$array_size - 3]);
      unset($new_url_array[$array_size - 2]);
      unset($new_url_array[$array_size - 1]);
      $edited_sef_url = implode('-' , $new_url_array);
    }
    elseif ($is_reporter || $is_itg_funalytics || $is_survey || $is_quiz) {
      $path_data = explode("/" , $sef_path);
      $edited_sef_url = rtrim($path_data[1]);
    }
    elseif ($is_basic_page) {
      $path_data = explode("/" , $sef_path);
      $edited_sef_url = rtrim($path_data[0]);
    }
    else {
      $path_alias_set = $sef_path;
      $path_data = explode("/" , $path_alias_set);
      $set_hierarchy = array_reverse($path_data);
      $seftitle = $set_hierarchy[0];
      $sef_url = explode($nodeid , $seftitle);
      $edited_sef_url = rtrim($sef_url[0] , '-');
    }
    return $edited_sef_url;
  }
}

//Get custompath of migrate.

function itg_migrate_custompath($node , $published_date , $node_sef) {

  //$published_date = 'date';//2014-02-31

  $getsection = !empty($node->field_primary_category[LANGUAGE_NONE][0]['value']) ? $node->field_primary_category[LANGUAGE_NONE][0]['value'] : '';
  if (!empty($getsection)) {
    if ($node->type == 'story' && is_issue_baised_magazine($node)) {
      if (!empty($node->field_story_select_supplement['und'][0]['target_id'])) {
        $pathdata = 'magazine/supplement';
      }
      else {
        $pathdata = 'magazine';
        $pathdata .= '/' . get_path_from_category($getsection);
      }

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
    }
    else {
      $set_hierarchy = get_path_from_category($getsection);
      $node_CT = $node->type;
      if ($node_CT == 'story') {
        $node_CT = 'story';
      }
      elseif ($node_CT == 'photogallery') {
        $node_CT = 'photo';
      }
      elseif ($node_CT == 'videogallery') {
        $node_CT = 'videos';
      }
      $pathdata = $set_hierarchy . '/' . $node_CT . '/' . trim($node_sef) . '-' . $node->nid . '-' . $published_date;
      $newpath = itg_common_custompath_insert_val($pathdata);
      return $newpath;
    }
  }
}
