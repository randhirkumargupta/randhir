<?php

/*
 * Inc file contains the functions
 */

/**
 * Feed generator of selected contents
 * @param array $data 
 */
function itg_mobile_services_feed_generator_of_contents($node) {
  // get service id  
  $association_nid = $node->field_service_association_title[LANGUAGE_NONE][0]['target_id'];
  $service_clients = $node->field_footer[LANGUAGE_NONE][0]['value'];
  $frequency = $node->field_service_frequency[LANGUAGE_NONE][0]['value'];

  // load service node  
  $service_details = node_load($association_nid);
  // service titile
  $service_title = str_replace(' ', '', $service_details->title);
  // delivery mode
  $delivery_mode = $service_details->field_service_delivery_mode[LANGUAGE_NONE][0]['value'];
  // expiry date
  $expiry_date = $service_details->field_story_expiry_date[LANGUAGE_NONE][0]['value'];

  $get_clients_id = get_clients_id($association_nid);
  // client ids
  $client_id_array = $get_clients_id['target_id'];
  // service association id
  $service_association_id = $get_clients_id['service_association_id'];
  $service_association_info = node_load($service_association_id);
  // service association data
  if (is_object($service_association_info) && count($service_association_info) > 0) {
    $content_type = isset($service_association_info->field_service_content_type[LANGUAGE_NONE]) ? $service_association_info->field_service_content_type[LANGUAGE_NONE][0]['value'] : '';
    $content_count = isset($service_association_info->field_service_content_count[LANGUAGE_NONE]) ? $service_association_info->field_service_content_count[LANGUAGE_NONE][0]['value'] : '';
    $char_limit = isset($service_association_info->field_service_char_limit[LANGUAGE_NONE]) ? $service_association_info->field_service_char_limit[LANGUAGE_NONE][0]['value'] : '';
    $field_header = isset($service_association_info->field_header[LANGUAGE_NONE]) ? $service_association_info->field_header[LANGUAGE_NONE][0]['value'] : '';
    $field_footer = isset($service_association_info->field_footer[LANGUAGE_NONE]) ? $service_association_info->field_footer[LANGUAGE_NONE][0]['value'] : '';
  }

  // Load itg_mobile_services.inc from the node module.
  module_load_include('inc', 'itg_mobile_services', 'includes/itg_mobile_services.feed_generate');

  switch ($delivery_mode) {
    case 1: // xml
      $file_path = itg_mobile_services_generate_xml($node, $service_title);
      break;
    case 2: // rss
      $file_path = itg_syndication_generate_rss($data);
      break;
    case 3: // mrss

      break;
    case 4: //ussd

      break;
    case 5: //sms

      break;
    case 'html':
      $file_path = itg_syndication_mail_syndication($data);
      break;
  }


  foreach ($client_id_array as $client_id) {
    $client_info = node_load($client_id);
    if (is_object($client_info) && count($client_info) > 0) {
      $content_sharing_mode = isset($client_info->field_content_sharing_mode[LANGUAGE_NONE]) ? $client_info->field_content_sharing_mode[LANGUAGE_NONE][0]['value'] : '';
      // Decide sharing mode
      switch ($content_sharing_mode) {
        // 1. Fetch web URL (our server)
        case '1':
          $service_fetch_link = isset($client_info->field_service_fetch_link[LANGUAGE_NONE]) ? $client_info->field_service_fetch_link[LANGUAGE_NONE][0]['value'] : '';
          itg_mobile_web_url_mobile($service_fetch_link, $file_path);
          break;
        case 2: // 2. Via FTP location
          $ftp_ip_address = isset($client_info->field_ftp_ip_address[LANGUAGE_NONE]) ? $client_info->field_ftp_ip_address[LANGUAGE_NONE][0]['value'] : '';
          $ftp_username = isset($client_info->field_ftp_username[LANGUAGE_NONE]) ? $client_info->field_ftp_username[LANGUAGE_NONE][0]['value'] : '';
          $ftp_password = isset($client_info->field_ftp_password[LANGUAGE_NONE]) ? $client_info->field_ftp_password[LANGUAGE_NONE][0]['value'] : '';
          $data = array('ftp_ip_address' => $ftp_ip_address, 'ftp_username' => $ftp_username, 'ftp_password' => $ftp_password);
          itg_mobile_services_ftp_feeds($data, $file_path);
          break;
        case 3: // 3. Via Email
          $service_email_address = isset($client_info->field_service_email_address[LANGUAGE_NONE]) ? $client_info->field_service_email_address[LANGUAGE_NONE][0]['value'] : '';
          itg_mobile_services_mail($service_email_address, $file_path);
          break;
      }

      $client_array[$client_id] = 1;
    }
  }

  itg_mobile_cron_after_feed_generate($node, $client_array, $content_count);


  return $file_path . '/' . $data->title . '.xml';
}

/**
 * Callback function to send syndication by mail attachment.
 * @param type $data
 * @param type $syndication_node
 */
function itg_mobile_services_mail($service_email_address, $file_path) {
  $attachment = array(
    'filepath' => $file_path,
  );
  $params = array(
    'key' => 'itg_syndication',
    'to' => 'mishrasoft2009@gmail.com',
    'from' => 'noreply@indiatoday.com',
    'subject' => 'Test email',
    'body' => 'Lorem Ipsum is simply dummy text of the printing and typesetting industry.',
    'attachment' => $attachment,
    'headers' => array(
      'MIME-Version: 1.0' . "\r\n",
      'Content-type: text/html; charset=iso-8859-1' . "\r\n",
      'To: ' . $service_email_address . "\r\n",
      'From: India Today <noreply@indiatoday.com>' . "\r\n",
    ),
  );
  $language = language_default();

  drupal_mail('itg_syndication', $params['key'], $params['to'], $language, $params, $params['from']);
}

function get_clients_id($association_nid) {
  $query = db_select('node', 'node')->fields('cs', array('field_client_selection_target_id'));
  $query->fields('sat', array('entity_id'));
  $query->leftJoin('field_data_field_client_selection', 'cs', "node.nid = cs.entity_id");
  $query->leftJoin('field_data_field_service_association_title', 'sat', "node.nid = sat.entity_id");
  $query->condition('sat.field_service_association_title_target_id', $association_nid, '=');
  $query->condition('node.type', array('client_service_association'), 'IN');
  $query->range(0, 20);
  $result = $query->execute();
  while ($record = $result->fetchAssoc()) {
    $target_id[] = $record['field_client_selection_target_id'];
    $service_association_id = $record['entity_id'];
  }
  $result = array('target_id' => $target_id, 'service_association_id' => $service_association_id);
  return $result;
}

/**
 * function get_content_sharing_mode().
 * @param int $entity_id
 * @return int $record
 */
function get_content_sharing_mode($entity_id) {
  if (isset($entity_id)) {
    $query = db_select('field_data_field_content_sharing_mode', 'csm')->fields('csm', array('field_content_sharing_mode_value'));
    $query->condition('csm.entity_id', $entity_id, '=');
    $query->range(0, 1);
    $result = $query->execute();
    $record = $result->fetchAssoc();
  }
  return isset($record['field_content_sharing_mode_value']) ? $record['field_content_sharing_mode_value'] : '';
}

/**
 * function to feed for syndication by ftp.
 * @param type $data
 * @param type $file_path
 */
function itg_mobile_services_ftp_feeds($data, $file) {

  $file_array = explode('/', $file);
  $last = count($file_array) - 1;
  $remote_file = $file_array[$last];
  // $remote_file = 'readmefeeds.txt';

  $ftp_server = $data['ftp_ip_address'];
  $ftp_user_name = $data['ftp_username'];
  $ftp_user_pass = $data['ftp_password'];

  // set up basic connection
  $conn_id = ftp_connect($ftp_server);

  // login with username and password
  $login_result = ftp_login($conn_id, $ftp_user_name, $ftp_user_pass);

  // upload a file
  if (ftp_put($conn_id, $remote_file, $file, FTP_ASCII)) {
    echo "successfully uploaded $file\n";
  }
  else {
    echo "There was a problem while uploading $file\n";
  }

  // close the connection
  ftp_close($conn_id);
}

/**
 * function validate_content_count().
 * @param int $nid
 * @return type $record
 */
function validate_content_count($nid) {
  $record = array();
  if (isset($nid)) {
    $query = db_select('itg_cron_time_scheduler', 's');
    $query->fields('s', array('cron_details'));
    $query->condition('s.cron_type', 'vas_service_content', '=');
    $query->condition('s.content_id', $nid, '=');
    $query->range(0, 1);
    $result = $query->execute();
    $record = $result->fetchAssoc();
  }
  return isset($record['cron_details']) ? $record['cron_details'] : '';
}

/**
 * function for cron time update
 * @param array $node
 * @param array $id
 * @param array $cron_time 
 */
function itg_mobile_cron_after_feed_generate($node, $client_array, $content_count) {

  // get service id  
  $association_nid = $node->field_service_association_title[LANGUAGE_NONE][0]['target_id'];
  $frequency_from_date = $node->field_service_frequency_date[LANGUAGE_NONE][0]['value'];
  $frequency = $node->field_service_frequency[LANGUAGE_NONE][0]['value'];

  $scheduler_time = strtotime($frequency_from_date);
  $details_array = array('service_id' => $association_nid,
    'frequency' => $frequency,
    'feed_type' => $node->type,
    'file_name' => $file_name,
    'clients' => $client_array,
  );

  $details = serialize($details_array);
  $nid = $node->nid;
  $validate_content = validate_content_count($nid);

  if (isset($validate_content)) {
    $data = unserialize($validate_content);
    if (is_array($data['clients']) && count($data['clients']) > 0) {
      foreach ($data['clients'] as $key => $val) {
        if ($content_count >= $val) {
          $client[$key] = $val + 1;
        }
      }
    }


    $details_array = array('service_id' => $association_nid,
      'frequency' => $frequency,
      'feed_type' => $node->type,
      'file_name' => $file_name,
      'clients' => $client,
    );

    $details = serialize($details_array);
    if ($nid) {
      db_delete('itg_cron_time_scheduler')
          ->condition('cron_type', 'vas_service_content', '=')
          ->condition('content_id', $nid, '=')
          ->execute();

      $query = db_insert('itg_cron_time_scheduler');
      $query->fields(array(
        'content_id' => $node->nid,
        'fid' => $node->nid,
        'cron_type' => $node->type,
        'last_cron_time' => $scheduler_time,
        'scheduler_time' => $scheduler_time,
        'cron_details' => $details,
        'status' => true
      ));
      $query->execute();
    }
  }
  else {
    $query = db_insert('itg_cron_time_scheduler');
    $query->fields(array(
      'content_id' => $node->nid,
      'fid' => $node->nid,
      'cron_type' => $node->type,
      'last_cron_time' => $scheduler_time,
      'scheduler_time' => $scheduler_time,
      'cron_details' => $details,
      'status' => true
    ));
    $query->execute();
  }
}

/**
 * function to feed for syndication by ftp.
 * @param type $data
 * @param type $file_path
 */
function itg_mobile_web_url_mobile($service_fetch_link, $file_path) {

  $query = db_insert('itg_syndication_feed_url');
  $query->fields(array(
    'xml_name' => $file_path,
    'client_feed_url' => $service_fetch_link,
    'created_date' => time(),
    'status' => 1
  ));
  $query->execute();
}
