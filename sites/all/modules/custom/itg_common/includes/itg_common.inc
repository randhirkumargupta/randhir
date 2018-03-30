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
  $query->groupBy('n.title');
  $query->orderBy('n.nid', 'DESC');
  $result = $query->execute();

  while ($record = $result->fetchAssoc()) {
    $data[$record['entity_id']] = $record['title'];
  }
  return $data;
}

/**
 * Impelements form for configuration.
 * {@inheritdoc}
 */
function itg_common_varnish_aws_setting_form($form) {
  $form['varnish_aws_access_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Varnish AWS Access Key'),
    '#default_value' => variable_get('varnish_aws_access_key', ''),
    '#required' => TRUE,
  );
  $form['varnish_aws_secret_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Varnish AWS Secret Key'),
    '#default_value' => variable_get('varnish_aws_secret_key', ''),
    '#required' => TRUE,
  );
  $form['varnish_aws_region'] = array(
    '#type' => 'textfield',
    '#title' => t('Varnish AWS Region'),
    '#default_value' => variable_get('varnish_aws_region', ''),
    '#required' => TRUE,
  );
  $form['varnish_DNSName'] = array(
    '#type' => 'textfield',
    '#title' => t('Varnish DNS'),
    '#default_value' => variable_get('varnish_DNSName', ''),
    '#required' => TRUE,
  );
   $form['varnish_aws_target_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Varnish AWS Target ARN'),
    '#default_value' => variable_get('varnish_aws_target_id', ''),
    '#required' => TRUE,
  );
   $form['varnish_aws_type'] = array(
    '#type' => 'radios',
    '#title' => t('Varnish AWS Type'),
    '#default_value' => variable_get('varnish_aws_type', ''),
     '#options' => array('target'=>t('Target Groups'),'LB'=> t('Load Balancer')),
    '#required' => TRUE,
  );
  return system_settings_form($form);
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
 * Get node status using nid
 * @param int $nid
 * @return string
 */
function itg_common_get_node_status($nid) {
  $query = db_select('node' , 'n')
      ->fields('n' , array('status'))
      ->condition('n.nid' , $nid , '=');

  return $query->execute()->fetchField();
}

/**
 * Get node type and primary category from nid
 * @param int $nid
 * @return string
 */
function itg_common_get_type_category($nid) {
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_primary_category', 'fc', 'n.nid = fc.entity_id');
  $query->fields('n', array('type'));
  $query->fields('fc', array('field_primary_category_value'));
  $query->condition('n.nid', $nid, '=');

  return $query->execute()->fetchAll(PDO::FETCH_ASSOC);
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
 * @param string $type
 * @return int
 *   total share count
 */
function itg_total_share_count($actual_link, $type = NULL) {
  //Need to remove share count from story page.
  return 0;
  if (!empty($actual_link)) {
    $fb_google_count = $fb_count = $google_count = $twitter_count = 0;

    if (function_exists('itg_facebook_share_count')) {
      //$fb_count = itg_facebook_share_count($actual_link);
      $query = db_select('itg_node_share_count', 'insc')
          ->fields('insc', array('share_count'))
          ->condition('insc.nid', $actual_link, '=');
      $result = $query->execute()->fetchField();
      if (!empty($result)) {
        $fb_count = (int) $fb_count + (int) $result;
      }
    }

    // get google share count
    if (function_exists('itg_google_share_count')) {
      $google_count = itg_google_share_count($actual_link);
    }
    
    if(function_exists('itg_common_mongo_share_count') && $type == 'story') {
      $twitter_count = itg_common_mongo_share_count($actual_link, 'twitter_share', 'front_user_activity');
    }

    $fb_google_count = $fb_count + $google_count + $twitter_count;

    return $fb_google_count;
  }
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
  if (function_exists('apachesolr_server_status')) {
    $ping = apachesolr_server_status(variable_get('solr_server_url'));
  }
  if (function_exists('apachesolr_get_solr') && $ping) {
    $solr = apachesolr_get_solr();
    //pr($solr);
    $query = apachesolr_drupal_query("custom", array('q' => "entity_id:$entity_id"));
    $query->addParam('rows', '4'); // How many rows of result to display default it is 10.
    $query->addParam('qf', 'entity_id'); // Only search in id
    $query->addParam('bs_status', 'true'); // Only search in title
    echo $query;
    $resp_search = $query->search();
    print_r($resp_search);die;
    return isset($resp_search->response->docs[0]) ? $resp_search->response->docs[0] : "";
  }
}

/**
 * Implements itg_get_related_story_id
 * @param string $entity_id
 */
function itg_get_related_story_id($related_content) {
  $related_content = explode('|~|' , $related_content);
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
      $url =  PARENT_SSO . '/saml_login/other/domain_info';
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
  $data = str_replace(array("\r","\n"),"",$data);

  return $data;
}

/**
 * Implements 'itg_common_get_latest_byline'.
 * @param int $nid
 * @param string $status
 */
function itg_common_get_latest_byline($nid , $status) {
  if (!empty($nid)) {
    $query = db_select('itg_multi_byline_info', 's');
    $query->fields('s', array('byline_id'))
        ->condition('s.nid', $nid, '=')
        ->condition('s.publish_status', $status, '=');
    $query->orderBy("byline_weight", "ASC");
    $query->range(0, 10);
    $result = $query->execute();
    return $result->fetchAll(PDO::FETCH_ASSOC);
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

/**
 * itg_get_multi_byline_details
 */
function itg_get_multi_byline_details($nid , $status = NULL) {
  $options = '';
  if (!empty($nid) && !empty($status)) {
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_story_extra_large_image', 're', 'n.nid = re.entity_id');
    $query->leftJoin('field_data_field_reporter_twitter_handle', 'frq', 'n.nid = frq.entity_id');
    $query->leftJoin('itg_multi_byline_info', 's', 'n.nid = s.byline_id');
    $query->fields('n');
    $query->fields('frq', array('field_reporter_twitter_handle_value'));
    $query->fields('re', array('field_story_extra_large_image_fid'));
    $query->condition('s.nid', $nid, '=');
    $query->condition('s.publish_status', $status, '=');
    $query->condition('n.type', 'reporter', '=');
    $query->orderBy("s.byline_weight", "ASC");
    $result = $query->execute();
    $key = 0;
    while ($record = $result->fetchAssoc()) {
      $options[$key]['nid'] = $record['nid'];
      $options[$key]['title'] = $record['title'];
      $options[$key]['extra_large_image'] = $record['field_story_extra_large_image_fid'];
      $options[$key]['twitter_handle'] = $record['field_reporter_twitter_handle_value'];
      ++$key;
    }
  }
  return $options;
}

/**
 * get domian name
 */

function itg_common_get_domain($url) {
  $pieces = parse_url($url);
  $domain = isset($pieces['host']) ? $pieces['host'] : $pieces['path'];
  if (preg_match('/(?P<domain>[a-z0-9][a-z0-9\-]{1,63}\.[a-z\.]{2,6})$/i', $domain, $regs)) {
    return $regs['domain'];
  }
  return $pieces['host'];
}

/**
 * Function is used to prepare node title with emoji.
 * @param int $nid
 *   Node id
 * @param int $min_limit
 *   Min limit to truncate node title
 * @param int $max_limit
 *   Max limit to truncate node title
 * @return string
 *   Returns node title.
 */
function itg_common_get_smiley_title($node_obj, $min_limit = 0, $max_limit = 255, $is_long_headline = FALSE) {
  $max_limit = 10000;
  $arg = arg();
  $titlte = "";
  $positions_array = array();
  $left_smiles = "";
  $right_smiles = "";
  $result = [];
  if (!empty($node_obj) && is_numeric($node_obj) && (int) $node_obj) {
   $result[] = get_field_value_for_smily($node_obj);
   
  } else {
      $result[] = array(
        'field_story_short_headline_value' => $node_obj['field_story_short_headline_value'],
        'field_emoji_position_value' => $node_obj['field_emoji_position_value'],
        'field_emoji_2_value' => $node_obj['field_emoji_2_value'],
        'field_emoji_value' => $node_obj['field_emoji_value'],
        'title' => $node_obj['title'],
      );
  }
  if (!empty($result[0]['field_story_short_headline_value'])) {
    foreach ($result[0]['field_emoji_position_value'] as $positions) {
        $positions_array[] = $positions;
    }
    if (in_array('left', $positions_array) && !empty($result[0]['field_emoji_2_value'])) {      
        // Get all the smiley images.
        preg_match_all('/<img[^>]*>/s', $result[0]['field_emoji_2_value'], $images);
        $left_smiles = '<span class="smilies-title">';
        // Implode all images in case of muliple smiley.
        $left_smiles .= implode("", $images[0]);

        $left_smiles .= '</span>';      
    }
    if (in_array('right', $positions_array) && !empty($result[0]['field_emoji_value'])) {
     
        // Get all the smiley images.
        preg_match_all('/<img[^>]*>/s', $result[0]['field_emoji_value'], $images_2);
        // Implode all images in case of muliple smiley.

        $right_smiles = '<span class="smilies-title">';
        // Implode all images in case of muliple smiley.
        $right_smiles .= implode("", $images_2[0]);

        $right_smiles .= '</span>';
      
    }
    if (count($result) && !$is_long_headline) {
      if (!empty($left_smiles) || !empty($right_smiles)) {
        $titlte = mb_strimwidth($result[0]['field_story_short_headline_value'], $min_limit, $max_limit, "..");
      }
      else {
        $max_limit += 10;
        $titlte = mb_strimwidth($result[0]['field_story_short_headline_value'], $min_limit, $max_limit, "..");
      }
      // Add smiley to right;
      $titlte = $left_smiles . _widget_title($titlte , FALSE) . $right_smiles;
      return $titlte;
    }
    else {
      if (!empty($left_smiles) || !empty($right_smiles)) {
        $titlte = mb_strimwidth($result[0]['title'], $min_limit, $max_limit, "..");
      }
      else {
        $max_limit += 10;
        $titlte = mb_strimwidth($result[0]['title'], $min_limit, $max_limit, "..");
      }
      $titlte = $left_smiles . _widget_title($titlte , FALSE) . $right_smiles;
      return $titlte;
    }
  }
  else {
    return mb_strimwidth(_widget_title($result[0]['title'] , FALSE), $min_limit, $max_limit, "..");
  }
}

/**
 * Helper function to get user details
 * @param int $uid 
 */
function itg_custom_get_user_details($uid) {
  if (!empty($uid)) {
    $query = db_select('users', 'u');
    $query->leftjoin('field_data_field_first_name', 'f', 'u.uid = f.entity_id');
    $query->leftjoin('field_data_field_last_name', 'g', 'u.uid = g.entity_id');
    $query->fields('u', array('uid'))
        ->fields('u', array('mail'))
        ->fields('u', array('name'))
        ->fields('f', array('field_first_name_value'))
        ->fields('g', array('field_last_name_value'))
        ->condition('u.status', 1)
        ->condition('u.uid', $uid);
    $result = $query->execute();

    while ($record = $result->fetchAssoc()) {
      $user_list['mail'] = $record['mail'];
      $user_list['name'] = $record['name'];
      $user_list['fname'] = $record['field_first_name_value'];
      $user_list['lname'] = $record['field_last_name_value'];
    }

    return $user_list;
  }
}

/**
 * Helper function to create image style
 * @param int $nid
 */
function create_node_image_style() {
  $arg = arg();
  
  if (is_numeric($arg[1])) {
    //add function by pavnish
  }
  
}

/**
 * This function is used to create settings.
 * 
 * {@inheritdoc}
 */
function itg_global_custom_variables() {
	$form = array();
  
  $form['itg_widgets_sports'] = array(
      '#type' =>'checkbox',
      '#title'=>t('Enable Sports widgets on Sports page '),      
      '#default_value' => variable_get('itg_widgets_sports'),
  );
  
  return system_settings_form($form);
}
