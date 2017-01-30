<?php

/*
 * Inc file contains the functions
 */

/**
 * Feed generator of selected contents
 * @param array $data
 * @return string $file_path 
 */

function feed_generator_of_contents($data) {
  $file_path = itg_syndication_generate_xml($data);
  return $file_path;
}

/**
 * Function for generating xml files.
 * @param array $data
 * @param string $file_path
 */
function itg_syndication_generate_xml($data) {
    
  $file = generate_custom_pattern_feed($data);
  
  $delivery_mode = $data['delivery_mode'];
  $delivery_mode_array = explode(': ', $delivery_mode);
  
  if ($delivery_mode_array[0] == 'Email') {
    $delivery_mode_type = 'Email';
  } 
  else if ($delivery_mode_array [0]== 'FTP') {
    $delivery_mode_type = 'FTP';
  } 
  else if ($delivery_mode_array[0] == 'Weburl') {
    $delivery_mode_type = 'web_url';
  }
  
  watchdog("Syndication", "delivery_mode_type : $delivery_mode_type");
  // Decide sharing mode
  switch ($delivery_mode_type) {
    // 1. Fetch web URL (our server)
    case 'web_url':
      if (isset($file['file_name'])) {
        itg_syndication_web_url_syndication($data, $file['file_path'], $delivery_mode_array[1]);
      }
      break;
    // 2. Via FTP location
      
    case 'FTP':
      if (isset($file['file_name'])) {
        itg_syndication_ftp_syndication($data, $file['file_path'], $file['file_name'], $delivery_mode_array[1]);
      }
      break;
    // 3. Via Email
    case 'Email':
      if (isset($file['file_name'])) {
        itg_syndication_mail_syndication($data, $file['real_path'], $delivery_mode_array[1]);
      }
      break;
  }
  
  return  $file;
}

/**
 * Callback function to send syndication by mail attachment.
 * @param array $data
 * @param string $file_path
 * @param string $delivery_mode
 */
function itg_syndication_mail_syndication($data, $file_path, $delivery_mode) {
  
  $attachment = array(
    'filepath' => $file_path,
  );
  $params = array(
    'key' => 'itg_syndication',
    'to' => $delivery_mode,
    'from' => 'noreply@indiatoday.com',
    'subject' => 'Test email',
    'body' => 'Please check attached xml file.',
    'attachment' => $attachment,
    'headers' => array(
      'MIME-Version: 1.0' . "\r\n",
      'Content-type: text/html; charset=iso-8859-1' . "\r\n",
      'To: '.$delivery_mode . "\r\n",
      'From: India Today <noreply@indiatoday.com>' . "\r\n",
    ),
  );
  $language = language_default();

  drupal_mail('itg_syndication', $params['key'], $params['to'], $language, $params, $params['from']);
}

/**
 * Implements hook_mail().
 * @param string $key
 * @param string $message
 * @param array $params
 */
function itg_syndication_mail($key, &$message, $params) {
  if ($key == 'itg_syndication') {
    $message['subject'] = $params['subject'];
    $message['body'][] = $params['body'];

    // Add attachment when available.
    if (isset($params['attachment'])) {
      $message['params']['attachments'][] = $params['attachment'];
    }
  }
}


/**
 * function to feed for syndication by ftp.
 * @param array $data
 * @param string $file_path
 * @param string $file_name
 * @param string $delivery_mode
 */
function itg_syndication_ftp_syndication($data, $file_path, $file_name, $delivery_mode) {  
  $ftp_details = get_ftp_details_by_client($data['client_title'], $delivery_mode);
  $file = $file_path;
 
  $remote_file = $file_name;
  $ftp_server = $ftp_details[0]->field_syndication_ftp_url_value;
  $ftp_user_name = $ftp_details[0]->field_syndication_ftp_username_value;
  $ftp_user_pass = $ftp_details[0]->field_syndication_ftp_password_value;  
  
  // set up basic connection
  //$conn_id = ftp_connect($ftp_server) or die("Couldn't connect to $ftp_server");
  $conn_id = ftp_connect($ftp_server);
  
  // login with username and password
  //$login_result = ftp_login($conn_id, $ftp_user_name, $ftp_user_pass) or die("You do not have access to this ftp server!");
  
  $login_result = ftp_login($conn_id, $ftp_user_name, $ftp_user_pass);
  if ((!$conn_id) || (!$login_result)) {    
    watchdog("WATCHDOG_INFO_XML", "FTP connection has failed");
  }
  
  //turn passive mode on
  ftp_pasv($conn_id, true);
  $upload = ftp_put($conn_id, $remote_file, $file, FTP_BINARY);
  
  if (!$upload) {
    echo "There was a problem while uploading $file\n";
  }
  else {
    echo "successfully uploaded $file\n";
  }
  
  // close the connection
  ftp_close($conn_id);
  
}

/**
 * function to feed for syndication by ftp.
 * @param type $data
 * @param string $file_path
 * @param string $delivery_mode
 */
function itg_syndication_web_url_syndication($data, $file_path, $delivery_mode) {
  if (!empty($file_path)) {
    $query = db_insert('itg_syndication_feed_url');
      $query->fields(array(
        'xml_name' => $file_path,
        'client_feed_url' => $delivery_mode,      
        'created_date' => time(),
        'status' => 1
      )); 
      $query->execute();
  }
}

/**
 * Get FTP details of client
 * @param string $client_name
 * @param string $ftp_name
 * @return array $itg_result (FTP details)
 */
function get_ftp_details_by_client($client_name, $ftp_name) {
  
  $client = explode('-', $client_name);
  $client_description = $client[1];
  $client_title = $client[0];
  
  $itg_query = db_select('node', 'n');
  $itg_query->condition('n.title', $client_description)
      ->fields('n', array('nid'))
      ->fields('ftp', array('field_syndication_ftp_details_value'))
      ->fields('ftp_name', array('field_syndication_ftp_name_value'))
      ->fields('ftp_url', array('field_syndication_ftp_url_value'))
      ->fields('ftp_username', array('field_syndication_ftp_username_value'))      
      ->fields('ftp_pass', array('field_syndication_ftp_password_value'));
  
  $itg_query->join('field_data_field_syndication_client_title', 'sc', 'n.nid = sc.entity_id');
  $itg_query->join('taxonomy_term_data', 'term', 'term.tid = sc.field_syndication_client_title_tid');
  $itg_query->join('field_data_field_syndication_ftp_details', 'ftp', 'ftp.entity_id = n.nid');
  $itg_query->join('field_data_field_syndication_ftp_url', 'ftp_url', 'ftp_url.entity_id = ftp.field_syndication_ftp_details_value');
  $itg_query->join('field_data_field_syndication_ftp_username', 'ftp_username', 'ftp_username.entity_id = ftp.field_syndication_ftp_details_value');
  $itg_query->join('field_data_field_syndication_ftp_password', 'ftp_pass', 'ftp_pass.entity_id = ftp.field_syndication_ftp_details_value');
  $itg_query->join('field_data_field_syndication_ftp_name', 'ftp_name', 'ftp_name.entity_id = ftp.field_syndication_ftp_details_value');
  $itg_query->condition('term.name', $client_title);
  $itg_query->condition('ftp_name.field_syndication_ftp_name_value', $ftp_name);
  $itg_result = $itg_query->execute()->fetchAll(); 

  return $itg_result;
}

/**
 * function for syndication content details
 * @return array $data
 */
function get_syndication_content_details() {
  $current_time = time();
  $cron_type = 'syndication_rule';
  
  $itg_query = db_select('itg_cron_time_scheduler', 'ts');
  $itg_query->fields('ts', array('cron_details'));
  $itg_query->fields('ts', array('last_cron_time'));
  $itg_query->fields('ts', array('scheduler_time'));
  $itg_query->fields('ts', array('id'));
  $itg_query->fields('ts', array('fid'));
  $itg_query->condition('ts.scheduler_time', $current_time, '<');  
  $itg_query->condition('ts.status', 1, '=');
  $itg_query->condition('ts.cron_type', $cron_type, '=');  
  $itg_query->condition(db_or()->isNull('ts.expiry_date')->condition('ts.expiry_date', $current_time, '>'));
  
  $itg_result = $itg_query->execute()->fetchAll();
  
  foreach ($itg_result as $itg_val) {    
    if (!empty($itg_val->cron_details)) {
      $data = unserialize($itg_val->cron_details);
      $data['fid'] = $itg_val->fid;
      
      watchdog("Syndication", "Rule id : $itg_val->id");
     
      $content_value = get_content_id_for_syndication($data, $itg_val->last_cron_time);
      
      //code for update cron time
      update_cron_time_after_feed_generate($data, $itg_val->id, $itg_val->scheduler_time);
      
    }
  }
  
  return $data;
}

/**
 * function for gat feed by url
 * @return type  
 */

function get_syndication_feed_byurl() {
  global $base_url;
  $url = $base_url.'/'.arg(0).'/'.arg(1).'/'.  arg(2);
  
  $itg_query = db_select('itg_syndication_feed_url', 'feed');
  $itg_query->fields('feed', array('xml_name'));
  $itg_query->fields('feed', array('created_date'));
  $itg_query->condition('feed.client_feed_url', $url);
  $itg_result = $itg_query->execute()->fetchAll();
  
  if (!empty($itg_result)) {
    foreach ($itg_result as $itg_val) {    
      $realpath = file_create_url($itg_val->xml_name);    
      $xml_date = date('d/m/Y',$itg_val->created_date);
      // $file_url = $itg_val->xml_name;
      echo 'Click to Download. <a href="'.$realpath.'" download>'.$xml_date.'</a>';
      echo '</br>';    
    }
  }
  exit;
 
}

/**
 * Implement itg_magazine_custom_callback
 */
function itg_magazine_custom_callback($mag_id = NULL) {

  if (isset($mag_id)) {
    $mag_id = $mag_id;
  }
  else {
    $mag_id = $_POST['magazine'];
  }

  $itg_query = db_select('node', 'n');
  $itg_query->fields('n', array('nid', 'title'));
  $itg_query->join('field_data_field_issue_magazine', 'sc', 'n.nid = sc.entity_id');
  $itg_query->condition('sc.field_issue_magazine_target_id', $mag_id);
  $itg_query->condition('n.type', 'issue');

  $itg_result = $itg_query->execute()->fetchAll();


  if (empty($_POST['magazine'])) {
    $select = t('- None -');
    $data = array('' => $select);
    foreach ($itg_result as $itg_val) {
      $dt = date('Y-m-d', strtotime($itg_val->title));
      $data[$dt] = date('d/m/Y', strtotime($itg_val->title));
    }
    return $data;
  }
  else {
    $drop = '<option value="">- Select -</option>';
    foreach ($itg_result as $itg_val) {
      $dt = date('Y-m-d', strtotime($itg_val->title));
      $data[$dt] = date('d/m/Y', strtotime($itg_val->title));
      $drop .= '<option value="' . $dt . '">' . date('d/m/Y', strtotime($itg_val->title)) . '</option>';
    }

    echo $drop;
  }
}

