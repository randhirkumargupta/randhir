<?php

/*
 * Inc file contains the common functions
 */

/**
 * Helper function to populate the second dropdown.
 * @param string $id
 * @return array $data
 */
function itg_common_dropdown_supplement($id = '') {
  // Fetch supplements for selected magazine
  $select = t('- None -');
  $data = array('_none' => $select);
  $query = db_select('field_data_field_supp_select_magazine' , 'm');
  $query->join('node' , 'n' , 'm.entity_id = n.nid');
  $query->fields('m' , array('entity_id'));
  $query->fields('n' , array('title'));
  $query->condition('n.status' , 1 , '=');
  $query->condition('m.field_supp_select_magazine_target_id' , $id , '=');
  $result = $query->execute();

  while ($record = $result->fetchAssoc()) {
    $data[$record['entity_id']] = $record['title'];
  }
  return $data;
}

/**
 * Helper function to populate the second dropdown.
 * @param string $id
 * @return array $data
 */
function itg_common_dropdown_mazine($id = '') {
  // Fetch supplements for selected magazine
  $select = t('- None -');
  $data = array('_none' => $select);
  $query = db_select('node' , 'n');
  $query->fields('n' , array('title' , 'nid'));
  $query->condition('n.status' , 1 , '=');
  $query->condition('n.type' , 'magazine' , '=');
  $result = $query->execute();

  while ($record = $result->fetchAssoc()) {
    $data[$record['nid']] = $record['title'];
  }
  return $data;
}

/**
 * Get survey count.
 * @param int $nid
 * @param string $tbl_name
 * @param string $field_name
 * @return int
 */
function itg_common_check_record_existance($nid , $tbl_name , $field_name) {
  $result = db_select($tbl_name , 'tbl')
      ->fields('tbl')
      ->condition('tbl.' . $field_name , $nid , '=')
      ->execute();
  $total_survey = $result->rowCount();

  if ($total_survey) {
    return $total_survey;
  }
  else {
    return 0;
  }
}

/**
 * Get any field value using table name and field name
 * @param string $field_name
 * @param string $tbl_name
 * @param string $cid_name
 * @param string $cid_val
 * @return array
 */
function itg_common_select_field_value($field_name , $tbl_name , $cid_name , $cid_val) {
  $query = db_select($tbl_name , 'tbl')
      ->fields('tbl' , array($field_name))
      ->condition('tbl.' . $cid_name , $cid_val , '=');

  $result = $query->execute();

  while ($record = $result->fetchAssoc()) {
    $records[] = $record[$field_name];
  }

  return $records;
}

/**
 * Get content type name by content type machine name.
 * @param string $type
 * @return string $content_type_name
 */
function get_content_type_name($type) {
  $content_type_name = db_select('node_type' , 'n')
          ->fields('n' , array('name'))
          ->condition('type' , $type)
          ->execute()->fetchField();

  return $content_type_name;
}

/**
 * Get node title using nid
 * @param int $nid
 * @return string
 */
function itg_common_get_node_title($nid) {
  $query = db_select('node' , 'n')
      ->fields('n' , array('title'))
      ->condition('n.nid' , $nid , '=');

  return $query->execute()->fetchField();
}

/**
 * Get node type using nid
 * @param int $nid
 * @return string
 */
function itg_common_get_node_type($nid) {
  $query = db_select('node' , 'n')
      ->fields('n' , array('type'))
      ->condition('n.nid' , $nid , '=');

  return $query->execute()->fetchField();
}

/**
 * Get node count.
 * @param string $content_type
 * @param int $uid
 * @return int
 */
function itg_get_all_node($content_type , $uid) {

  $query = "SELECT COUNT(*) amount FROM {node} n " .
      "WHERE n.type = :type AND n.uid = :uid";
  $result = db_query($query , array(':type' => $content_type , ':uid' => $uid))->fetch();
  return $result->amount;
}

/**
 * Get node publish count.
 * @param string $content_type
 * @param int $uid
 * @return int
 */
function itg_get_all_publish_node($content_type , $uid) {
  $query = "SELECT COUNT(*) amount FROM {node} n " .
      "WHERE n.type = :type AND n.uid = :uid AND n.status = '1'";
  $result = db_query($query , array(':type' => $content_type , ':uid' => $uid))->fetch();

  return $result->amount;
}

/**
 * Get node type.
 * @param int $uid
 * @return array $type
 */
function itg_get_all_node_type($uid) {
  $result = db_select('node' , 'n')
      ->fields('n' , array('type'))
      ->condition('uid' , $uid , '=')
      ->groupBy('type')
      ->execute();

  while ($record = $result->fetchAssoc()) {
    $type[] = $record['type'];
  }

  return $type;
}

/**
 * Get Last node created by user.
 * @param int $uid
 * @return array $last_record_info
 */
function itg_last_node_user($uid) {

  $last_result = db_select('node' , 'n')
      ->fields('n' , array('title' , 'type' , 'nid'))
      ->condition('uid' , $uid , '=')
      ->orderBy('created' , 'DESC')//ORDER BY created
      ->range(0 , 1)
      ->execute();

  while ($last_record = $last_result->fetchAssoc()) {
    $last_record_info['title'] = $last_record['title'];
    $last_record_info['type'] = $last_record['type'];
    $last_record_info['nid'] = $last_record['nid'];
  }

  return $last_record_info;
}

/**
 * Get Last node published by user.
 * @param int $uid
 * @param int $publish_id
 * @return array $last_record_info_user
 */
function itg_last_publish_user_node($uid , $publish_id) {
  $last_result_user = db_select('node' , 'n')
      ->fields('n' , array('title' , 'type' , 'nid'))
      ->condition('uid' , $uid , '=')
      ->condition('status' , $publish_id , '=')
      ->orderBy('created' , 'DESC')
      ->range(0 , 1)
      ->execute();

  while ($last_record_user = $last_result_user->fetchAssoc()) {
    $last_record_info_user['title'] = $last_record_user['title'];
    $last_record_info_user['type'] = $last_record_user['type'];
    $last_record_info_user['nid'] = $last_record_user['nid'];
  }

  return $last_record_info_user;
}

/**
 * Get Last node published by user using workflow.
 * @param int $uid
 * @param int $publish_id
 * @return array $last_publish_record_info
 */
function itg_last_node_published_user($uid , $publish_id) {
  $last_publish_result = db_select('workbench_moderation_node_history' , 'w')
      ->fields('w' , array('nid' , 'vid'))
      ->condition('uid' , $uid , '=')
      ->condition('published' , $publish_id , '=')
      // ->orderBy('stamp', 'ASC')//ORDER BY created
      ->range(0 , 1)
      ->execute();

  while ($last_publish_record = $last_publish_result->fetchAssoc()) {
    $last_publish_record_info['vid'] = $last_publish_record['vid'];
    $last_publish_record_info['nid'] = $last_publish_record['nid'];
  }

  return $last_publish_record_info;
}

/**
 * Get Last node published by user using workflow.
 * @param int $uid
 * @param int $publish_id
 * @return array $last_publish_record_info
 */
function itg_last_node_published_on($nid , $publish_id) {
  $query = db_select('workbench_moderation_node_history' , 'w')
      ->fields('w')
      ->condition('nid' , $nid , '=')
      ->condition('state' , 'published' , '=')
      ->orderBy('stamp' , 'ASC')//ORDER BY created
      ->range(0 , 1);

  $result = $query->execute()->fetchall();
  return $result;
}

/**
 * Get Role create permission.
 * @param int $rid
 * @return
 */
function itg_common_check_role_access($rid) {
  $role_not_create_per = array(AUTHOR_GUEST , INTERN , EXPERT);
  if (in_array($rid , $role_not_create_per)) {
    return FALSE;
  }
  else {
    return TRUE;
  }
}

/**
 * Implements itg_ugc_bad_words
 * @param type string
 * @return string
 */
function itg_ugc_bad_words($description) {
  $vocab_id = taxonomy_vocabulary_machine_name_load('bad_words');
  $tax = taxonomy_get_tree($vocab_id->vid , $parent = 0 , $max_depth = 1 , $load_entities = FALSE);

  foreach ($tax as $key => $val) {
    $op[$val->tid] = $val->name;
  }

  // implode bad words array
  $keyword = implode("#" , $op);
  $keyword = implode('|' , explode('#' , preg_quote($keyword)));

  return $final_description = preg_replace("/($keyword)/i" , "<b style='font-size:14px; color:#FF0000; font-weight:bold;'>$0</b>" , $description);
}

/**
 * Helper function to check for duplicate node titles
 * @param string $title
 * @param string $type
 * @param int $nid
 * @return int
 */
function itg_common_check_duplicate_title($title , $type , $nid) {
  if (trim($type)) { // Validate duplicate title for content type
    $results = db_select('node')->fields('node' , array('title'))
        ->condition('title' , $title , '=')
        ->condition('type' , $type);
    if (isset($nid)) {
      $results->condition('nid' , $nid , '!=');
    }

    return $results->execute()->rowCount();
  }
}

/**
 * Round average rating into interval of 0.5.
 *
 * @param float $average_rating
 * @return real
 */
function itg_common_round_rating($average_rating) {
  $temp = fmod($average_rating , 1);
  $temp = (string) $temp;
  $average_rating -= $temp;
  switch ($temp) {
    case '0.1':
    case '0.2':
    case '0.3':
    case '0.4':
    case '0.5':
      $average_rating += 0.5;
      break;
    case '0.6':
    case '0.7':
    case '0.8':
    case '0.9':
      ++$average_rating;
  }

  return $average_rating;
}

/**
 * Implements itg_total_share_count
 * @param string $actual_link
 *   Send url for facebook share
 * 
 * @return int
 *   total share count
 */
function itg_total_share_count($actual_link) {
  $fb_google_count = $fb_count = $google_count = 0;

  if (function_exists('itg_facebook_share_count')) {
    $fb_count = itg_facebook_share_count($actual_link);
  }

  // get google share count
  if (function_exists('itg_google_share_count')) {
    $google_count = itg_google_share_count($actual_link);
  }

  $fb_google_count = $fb_count + $google_count;

  return $fb_google_count;
}

/**
 * Check story state(draft, unpublished, published etc.)
 * @param int $nid
 * @return boolean
 */
function itg_common_get_story_status($nid) {
  $query = db_select('workbench_moderation_node_history' , 's');
  $query->fields('s' , array('state'))
      ->condition('s.nid' , $nid , '=')
      ->condition('s.is_current' , 1 , '=');
  $result = $query->execute();
  $story_status = $result->fetchField();
  if ($story_status) {
    return $story_status;
  }
  else {
    return FALSE;
  }
}

/**
 * Implements itg_get_related_story
 * @param int $entity_id
 */
function itg_get_related_story_content($entity_id) {
  if (function_exists('apachesolr_get_solr')) {
    $solr = apachesolr_get_solr();
    $query = apachesolr_drupal_query("custom" , array('q' => "entity_id:$entity_id"));
    $query->addParam('rows' , '4'); // How many rows of result to display default it is 10.
    $query->addParam('qf' , 'entity_id'); // Only search in id
    $query->addParam('bs_status' , 'true'); // Only search in title
    $resp_search = $query->search();
    return isset($resp_search->response->docs[0]) ? $resp_search->response->docs[0] : "";
  }
}

/**
 * Implements itg_get_related_story_id
 * @param string $entity_id
 */
function itg_get_related_story_id($related_content) {
  $related_content = explode(',' , $related_content);
  foreach ($related_content as $fn_result) {
    $related_content = explode('_' , $fn_result);
    $final_related [] = $related_content[1];
  }
  $final_related = implode(',' , $final_related);
  $final_related = explode(',' , $final_related);

  return $final_related;
}

/**
 * Implements itg_sso_url
 * @param string $link_name
 *   Link text.
 * @param string $link_title
 *   In case link text is an Icon.
 */
function itg_sso_url($link_name , $link_title = NULL) {
  global $user;
  $site = 'indiatoday';
  if ($_SERVER['HTTP_HOST'] == PARENT_SSO) {
    if ($user->uid == 0) {
      $url = 'http://' . PARENT_SSO . '/saml_login/other/domain_info';
      if ($link_title !== NULL) {
        return '<a title ="' . $link_title . '" href="javascript:void(0)" onclick="CenterWindow (550, 500, 50, ' . "'" . $url . "'" . ', ' . "'" . $site . "'" . ')">' . $link_name . '</a>';
      }
      else {
        return '<a title ="' . $link_name . '" href="javascript:void(0)" onclick="CenterWindow (550, 500, 50, ' . "'" . $url . "'" . ', ' . "'" . $site . "'" . ')">' . $link_name . '</a>';
      }
    }
  }
  else {
    if ($user->uid == 0) {
      $url = PARENT_SSO;
      $sam_param = '/saml_login/other';
      if ($link_title !== NULL) {
        return '<a title ="' . $link_title . '" href="javascript:void(0)" onclick="Go (550, 500, 50, ' . "'" . $site . "'" . ', ' . "'" . $site . "'" . ', ' . "'" . $url . "'" . ', ' . "'" . $sam_param . "'" . ')">' . $link_name . '</a>';
      }
      else {
        return '<a title ="' . $link_name . '" href="javascript:void(0)" onclick="Go (550, 500, 50, ' . "'" . $site . "'" . ', ' . "'" . $site . "'" . ', ' . "'" . $url . "'" . ', ' . "'" . $sam_param . "'" . ')">' . $link_name . '</a>';
      }
    }
  }
}

/**
 * Implements 'itg_common_only_text_string'.
 * 
 * This function return filtered plain text string.
 * 
 * @param string $str
 *   String with html tags and special characters.
 * @return type
 *   Only text string.
 */
function itg_common_only_text_string($str) {
  $data = strip_tags($str);
  $data = preg_replace("/'/" , "\\'" , $data);
  $data = htmlentities($data , ENT_QUOTES);
  $data = trim(str_replace('&nbsp;' , ' ' , $data));

  return $data;
}

/**
 * Implements 'itg_common_get_latest_byline'.
 * @param int $nid
 * @param string $status
 */
function itg_common_get_latest_byline($nid , $status) {
  $query = db_select('itg_multi_byline_info' , 's');
  $query->fields('s' , array('byline_id'))
      ->condition('s.nid' , $nid , '=')
      ->condition('s.publish_status' , $status , '=');
  $query->orderBy("byline_weight" , "ASC");
  $query->range(0 , 1);
  $result = $query->execute();
  $byline_id = $result->fetchField();
  if ($byline_id) {
    return $byline_id;
  }
  else {
    return FALSE;
  }
}

/**
 * Helper function to show fb share count.
 * @param int $id
 */
function itg_get_fb_share($id , $type) {
  $result = db_select('itg_lrp_loyalty_points' , 'n')
      ->fields('n' , array('id'))
      ->condition('n.loyalty_type' , $type)
      ->condition('n.node_id' , $id)
      ->execute();
  return $result->rowCount();
}
