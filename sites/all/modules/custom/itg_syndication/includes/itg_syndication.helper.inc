<?php

/*
 * Inc file contains the helper functions
 */

/**
 * Get mode for syndication .
 * @param string $client_name
 * @return array $data
 */
function itg_syndication_get_mode($client_name) {
  
  $client = explode('-', $client_name);
  $client_description = !empty($client[1]) ? $client[1] : '';
  $client_title = $client[0];
  $itg_query = db_select('node', 'n');
  $itg_query->condition('n.title', $client_description)
      ->fields('n', array('nid'));
  $itg_query->join('field_data_field_syndication_client_title', 'sc', 'n.nid = sc.entity_id');
  $itg_query->join('taxonomy_term_data', 'term', 'term.tid = sc.field_syndication_client_title_tid');
  $itg_query->condition('term.name', $client_title);
  $itg_result = $itg_query->execute()->fetchField();

  $node = node_load($itg_result);
  $data['_none'] = '- None -';
  
  //Code for FTP
  if (!empty($node->field_syndication_ftp_details[LANGUAGE_NONE])) {
   foreach ($node->field_syndication_ftp_details[LANGUAGE_NONE] as $key => $val) {   
      $field_collection_item = entity_load('field_collection_item', array($val['value']));
      $ftp_name = $field_collection_item[$val['value']]->field_syndication_ftp_name[LANGUAGE_NONE][0]['value'];
      $data['FTP: '.$ftp_name] = $ftp_name;
   } 
  }
  
  
  //Code for Email id
  if (!empty($node->field_email_address[LANGUAGE_NONE])) {
    foreach ($node->field_email_address[LANGUAGE_NONE] as $key => $val) {
      $data['Email: '.$val['value']] = $val['value'];
    }
  }
  
  
  //Code for Weburl
  if (!empty($node->field_service_fetch_link[LANGUAGE_NONE][0]['value'])) {
    $data['Weburl: '.$node->field_service_fetch_link[LANGUAGE_NONE][0]['value']] = 'Web url';
  }
  
  return $data;
}

/**
 * Check duplicate client name.
 * @param string $client_title
 * @param string $client_description
 * @return integer $itg_result
 */
function itg_syndication_check_duplicate($client_title, $client_description) { 
  $itg_query = db_select('node', 'n');
  $itg_query->condition('n.title', $client_description)
      ->fields('n', array('nid'));
  $itg_query->join('field_data_field_syndication_client_title', 'sc', 'n.nid = sc.entity_id');
  $itg_query->condition('sc.field_syndication_client_title_tid', $client_title);
  $itg_result = $itg_query->execute()->fetchField();

  return $itg_result;
}

/**
 * Check duplicate client name for rule.
 * @param string $client_title 
 * @return integer $itg_result
 */
function itg_syndication_check_client_rule($client_title) { 
  $itg_query = db_select('field_data_field_syndication_rule_title', 'rule');
  $itg_query->condition('rule.field_syndication_rule_title_value', $client_title)
      ->fields('rule', array('entity_id')); 
  $itg_result = $itg_query->execute()->fetchField();

  return $itg_result;
}

/**
 * Get client for syndication
 * @param string $cond 
 * @return array $data
 */
function itg_syndication_get_client($cond = NULL) {
  
  // Create default option for list
  $data['_none'] = '- Select -';
  
  $itg_query = db_select('node', 'n');
  $itg_query->fields('tax', array('name'));
  $itg_query->fields('n', array('nid', 'title'));
  //$itg_query->fields('expiry', array('field_story_expiry_date_value'));
  $itg_query->join('field_data_field_syndication_client_title', 'sc', 'n.nid = sc.entity_id');
  $itg_query->join('taxonomy_term_data', 'tax', 'tax.tid = sc.field_syndication_client_title_tid');
  $itg_query->condition('n.type', 'syndication_client');
  
  if ($cond == 'yes') {
    $current_time = date('Y-m-d H:i:s');
    $itg_query->leftJoin('field_data_field_story_expiry_date', 'expiry', 'n.nid = expiry.entity_id');        
    $itg_query->condition(db_or()->isNull('expiry.field_story_expiry_date_value')->condition('expiry.field_story_expiry_date_value', $current_time, '>='));        
  }      
      
  $itg_result = $itg_query->execute()->fetchAll();
  
  foreach ($itg_result as $itg_val) {
    $data[$itg_val->name.'-'.$itg_val->title] = $itg_val->name.'-'.$itg_val->title;
  }
  
  return $data;
}

/**
 * function for Issue list
 * @return array $data
 */
function itg_syndication_get_issue_list($magazine = NULL) {
  $type = 'issue';
  if (isset($magazine)) {
    $type = 'magazine';
  }
  // Create default option for list
  $data[''] = '- Select -';

  $itg_query = db_select('node', 'n');
  $itg_query->fields('n', array('title', 'nid'));
  $itg_query->condition('n.type', $type);
  $itg_result = $itg_query->execute()->fetchAll();

  foreach ($itg_result as $itg_val) {
    if (isset($magazine)) {
      $type = 'magazine';
      $data[$itg_val->nid] = $itg_val->title;
    }
    else {
      $dt = date('Y-m-d', strtotime($itg_val->title));
      $data[$dt] = date('d/m/Y', strtotime($itg_val->title));
    }
  }

  return $data;
}


/**
 * function for syndication content id
 * @param array $data
 * @param string $created_date
 * @return string $file_url
 */
function get_content_id_for_syndication($data, $created_date) {
  $content_id = array();
  $itg_query = db_select('node', 'n');
  $itg_query->fields('n', array('nid'));
  $itg_query->join('field_data_field_story_syndication', 'syndication', 'syndication.entity_id = n.nid'); 
  $itg_query->join('field_data_field_story_category', 'cat', 'cat.entity_id = n.nid');
  $itg_query->condition('n.status', 1);
  $itg_query->condition('n.created', $created_date, '>');
  $itg_query->condition('n.type',$data['content_type']);
  $itg_query->condition('syndication.field_story_syndication_value','Yes');  
  $itg_query->condition('cat.field_story_category_tid',$data['section_id'], 'IN');//for multi section
  
  $delivery_mode_array = explode(': ', $data['delivery_mode']);  
  //if ($delivery_mode_array[0] == 'Weburl') {
    $itg_query->range(0, $data['num_of_feeds']);  
  //} 
  
  $itg_result = $itg_query->execute()->fetchAll();
  
  foreach ($itg_result as $itg_val) {
    $content_id[] = $itg_val->nid;
    $contentid .= $itg_val->nid.',';
  }
  
  watchdog("Syndication", '<pre>'. print_r($contentid, TRUE) .'</pre>');
  
  $data_array = array(
    'web_property' => $data['content_type'],
    'client_title' => $data['client_name'],
    'delivery_mode' => $data['syndication_mode'],
    'feed_type' => $data['feed_type'],
    'fid' => $data['fid'],
    'section_id' => $data['section_id'],
    'syndication' => serialize($content_id),    
  );
  
  $file_path = feed_generator_of_contents($data_array);
  $file_url = $file_path['file_path'];
  watchdog("Syndication", "File url : $file_url");
  
  return $file_url;
}

/**
 * save cron details for feed of syndication content
 * @param Object $node 
 */

function save_cron_details_of_syndication($node) {
  
  foreach($node->field_syndication_rule_details[LANGUAGE_NONE] as $key => $val ) {
      
    $field_collection_item = entity_load('field_collection_item', array($val['value']));
    //add code for multi section
    $section_array = $field_collection_item[$val['value']]->field_syndication_select_section[LANGUAGE_NONE];
    foreach($section_array as $section_key => $section_val) {
      $section_id[] = $section_val['tid'];
    }
    //end
    //$section_id = $field_collection_item[$val['value']]->field_syndication_select_section[LANGUAGE_NONE][0]['tid'];
    $feed_type = $field_collection_item[$val['value']]->field_syndication_feed_type[LANGUAGE_NONE][0]['value'];
    $syndication_mode = $field_collection_item[$val['value']]->field_syndication_mode[LANGUAGE_NONE][0]['value'];
    $content_type = $field_collection_item[$val['value']]->field_syndication_content_type[LANGUAGE_NONE][0]['value'];
    $client_name = $node->title;
    $frequency = $field_collection_item[$val['value']]->field_syndication_frequency[LANGUAGE_NONE][0]['value'];

    $time_rule = $field_collection_item[$val['value']]->field_syndication_time[LANGUAGE_NONE][0]['value'];      
    $day = $field_collection_item[$val['value']]->field_syndication_set_day[LANGUAGE_NONE][0]['value'];
    $dt = $field_collection_item[$val['value']]->field_syndication_set_day_month[LANGUAGE_NONE][0]['value'];    
    $num_of_feeds = $field_collection_item[$val['value']]->field_syndication_num_of_feeds[LANGUAGE_NONE][0]['value'];
    //get cron time
    $cron_time_array = get_cron_time($frequency, $time_rule, $day, $dt);
    $previous_time = $cron_time_array['previous_time'];
    $scheduler_time = $cron_time_array['scheduler_time'];
    
    $details_array = array('client_name' => $client_name, 
                             'section_id' => $section_id, 
                             'feed_type' => $feed_type, 
                             'syndication_mode' => $syndication_mode, 
                             'content_type' => $content_type, 
                             'frequency' => $frequency, 
                             'time_rule' => $time_rule, 
                             'day_name' => $day, 
                             'date' => $dt,
                             'num_of_feeds' => $num_of_feeds);
    
    $details = serialize($details_array);
    $expiry_date = get_client_expiry_date($client_name);
    $query = db_insert('itg_cron_time_scheduler');
    $query->fields(array(
      'content_id' => $node->nid,
      'fid' => $val['value'],
      'cron_type' => $node->type,
      'last_cron_time' => $previous_time,
      'scheduler_time' => $scheduler_time,
      'expiry_date' => $expiry_date,
      'cron_details' => $details,
      'status' => true
    )); 
    $query->execute();
  }
  
}



/**
 * Get web url for client
 * @param Object $node
 * @param  string $dir 
 * @return string url
 */
function get_weburl_for_syndication($dir, $node) {  
  global $base_url;
  $url = $base_url.'/'.$dir.'/';
  
  $six_digit_random_number = mt_rand(100000, 999999);
  $timestamps = date("Y-m-d H:i:s");
  $client_name = $node->field_syndication_client_title[LANGUAGE_NONE][0]['tid'].$node->title;
  $token = sha1($client_name. $timestamp . $six_digit_random_number);
  
  return $url.$token;
}

/**
 * function for cron time update
 * @param array $data
 * @param integer $id
 * @param string $cron_time 
 */
function update_cron_time_after_feed_generate($data, $id, $cron_time) {
  if ($data['frequency'] == 'Daily') {      
      $scheduler_time = strtotime('+1 day', $cron_time);
      $previous_time = $cron_time;
    } else if ($data['frequency'] == 'Weekly') {
      $scheduler_time = strtotime('+7 days', $cron_time);
      $previous_time = $cron_time;
    } else if ($data['frequency'] == 'Monthly') {         
       $scheduler_time = strtotime('+1 month', $cron_time);
      $previous_time = $cron_time;
    }
    
    db_update('itg_cron_time_scheduler')
          ->fields(array(
            'last_cron_time' => $previous_time,
            'scheduler_time' => $scheduler_time,            
          ))
          ->condition('id', $id)
          ->execute();
}

/**
 * function for gat cron time
 * @param string $frequency
 * @param string $time_rule
 * @param string $day
 * @param string $dt
 * @return array time
 */
function get_cron_time($frequency, $time_rule, $day = NULL, $dt = NULL) {
  
  if ($frequency == 'Daily') {
      $current_date = time();
      $cron_time = date('m/d/Y', $current_date).' '.$time_rule;
      $scheduler_time = strtotime($cron_time);
      $previous_time = strtotime($cron_time.' -1 day');
    } 
    else if ($frequency == 'Weekly') {
      //strtotime( "next monday" );
      $current_date = strtotime( "previous ".$day );        
      $cron_time = date('m/d/Y', $current_date).' '.$time_rule;
      $scheduler_time = strtotime($cron_time);
      $previous_time = strtotime($cron_time.' -7 days');
    } 
    else if ($frequency == 'Monthly') {         
       $cron_time_month = date('m');
       $cron_time_year = date('Y');
       $cron_time = $cron_time_month.'/'.$dt.'/'.$cron_time_year.' '.$time_rule;         
       $scheduler_time = strtotime($cron_time);
       $previous_time = strtotime($cron_time.' -1 month');
    }
    
    $date_array = array('scheduler_time' => $scheduler_time, 'previous_time' => $previous_time);
    
    return $date_array;
  
}

/**
 * Get rule by client name
 * @param string $client_name 
 * @return array $delivery
 */
function get_rule_by_client_name($client_name) {
  
  $itg_query = db_select('field_data_field_syndication_rule_title', 'rule');
  $itg_query->fields('rule', array('entity_id'));  
  $itg_query->condition('rule.field_syndication_rule_title_value', $client_name);
  $itg_result = $itg_query->execute()->fetchField();
  
  $node = node_load($itg_result);
  $delivery_mode_email = array();
  $delivery_mode_web = array();
  $delivery_mode_ftp = array();
  
  foreach ($node->field_syndication_rule_details[LANGUAGE_NONE] as $key => $val) {   
    $field_collection_item = entity_load('field_collection_item', array($val['value']));
    $delivery_mode = $field_collection_item[$val['value']]->field_syndication_mode[LANGUAGE_NONE][0]['value'];
    if (!empty($delivery_mode)) {
      
      $delivery_mode_data = explode(': ', $delivery_mode);
      
      if ($delivery_mode_data[0] == 'Email') {
        $delivery_mode_val['Email'] = 'Email';
      } 
      else if ($delivery_mode_data[0]== 'FTP') {
          $delivery_mode_val['FTP'] = 'FTP';
      } 
      else if ($delivery_mode_data[0] == 'Weburl') {
          $delivery_mode_val['web_url'] = 'web_url';
      }
      
      $delivery_mode_array[] = $delivery_mode_data[1];
    }
    
  }
  
  $delivery['mode_val'] = $delivery_mode_array;
  $delivery['mode_type'] = $delivery_mode_val;
   
  return $delivery;
  
}

/**
 * Get client expiry date by client name
 * @param string $client_name 
 * @return string $expiry_date
 */
function get_client_expiry_date($client_name) {
  
  $client = explode('-', $client_name);
  $client_description = $client[1];
  $client_title = $client[0];
  
  $itg_query = db_select('node', 'n');
  $itg_query->condition('n.title', $client_description)
      ->fields('expiry', array('field_story_expiry_date_value'));  
  $itg_query->join('field_data_field_syndication_client_title', 'sc', 'n.nid = sc.entity_id');
  $itg_query->join('taxonomy_term_data', 'term', 'term.tid = sc.field_syndication_client_title_tid');  
  $itg_query->join('field_data_field_story_expiry_date', 'expiry', 'expiry.entity_id = n.nid');
  $itg_query->condition('term.name', $client_title);
  $itg_query->condition('expiry.bundle', 'syndication_client');
  $itg_result = $itg_query->execute()->fetchField();
  $expiry_date = strtotime($itg_result);
  
  return $expiry_date;
}