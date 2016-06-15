<?php

/*
 * Inc file contains the functions
 */

/**
 * Feed generator of selected contents
 * @param array $data 
 */
function itg_mobile_services_feed_generator_of_contents($delivery_mode, $data) {
  switch ($delivery_mode) {
    case 1: // xml
      $file_path = itg_mobile_services_generate_xml($data);
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


  return $file_path;
}

/**
 * Function for generating xml files.
 * @param array $data
 * @param array $syndication_node
 */
function itg_mobile_services_generate_xml($node) {
  // get service id  
  $association_nid = $node->field_service_association_title[LANGUAGE_NONE][0]['target_id'];
  // load service node  
  $service_details = node_load($association_nid);
  
  // delivery mode
  $delivery_mode = $service_details->field_service_delivery_mode;
  // expiry date
  $expiry_date = $service_details->field_story_expiry_date;

  $get_clients_id = get_clients_id($association_nid);
  watchdog('get_clients_id', '<pre>' . print_r($get_clients_id, 1) . '</pre>'); 
  // client ids
  $client_id_array = $get_clients_id['target_id'];
  // service association id
  $service_association_id = $get_clients_id['service_association_id'];
  $service_association_info = node_load($service_association_id);
  // service association data
  if (is_object($service_association_info) && count($service_association_info) > 0) {
    $content_type  = isset($service_association_info->field_service_content_type) ? $service_association_info->field_service_content_type[LANGUAGE_NONE][0]['value'] : '';
    $content_count = isset($service_association_info->field_service_content_count) ? $service_association_info->field_service_content_count[LANGUAGE_NONE][0]['value'] : '';
    $char_limit    = isset($service_association_info->field_service_char_limit) ? $service_association_info->field_service_char_limit[LANGUAGE_NONE][0]['value'] : '';
    $field_header  = isset($service_association_info->field_header) ? $service_association_info->field_header[LANGUAGE_NONE][0]['value'] : '';
    $field_footer  = isset($service_association_info->field_footer) ? $service_association_info->field_footer[LANGUAGE_NONE][0]['value'] : '';
  }


  $data_array = array('service_id' => $association_nid,
    'frequency' => $frequency,
    'frequency_date_start' => $frequency_date_start,
    'frequency_date_end' => $frequency_date_end,
    'content_type' => $content_type,
    'content_count' => $content_count,
    'char_limit' => $char_limit,
    'field_header' => $field_header,
    'field_footer' => $field_footer,
  );


  // content field collection data
  $fieldcollect = node_load($node->nid);
  if (is_object($fieldcollect) && count($fieldcollect) > 0) {
    foreach($fieldcollect->field_service_content[LANGUAGE_NONE] as $key => $val) {   
      $field_collection_item = entity_load('field_collection_item', array($val['value']));
      $service_content_date = $field_collection_item[$val['value']]->field_service_content_date[LANGUAGE_NONE][0]['value'];
      $service_content_text = $field_collection_item[$val['value']]->field_story_expert_description[LANGUAGE_NONE][0]['value'];
      $service_conten_image = $field_collection_item[$val['value']]->field_story_large_image[LANGUAGE_NONE][0]['fid'];
      $service_conten_audio = $field_collection_item[$val['value']]->field_service_audio[LANGUAGE_NONE][0]['fid'];
      $service_conten_video = $field_collection_item[$val['value']]->field_service_video[LANGUAGE_NONE][0]['fid'];
    }
  }



      global $base_url;
      $file_path = drupal_realpath('public://');
      $file_path = $file_path . '/mobile_xml';
      $doc = new DOMDocument('1.0', 'UTF-8');
      $doc->formatOutput = TRUE;

      $root = $doc->appendChild($doc->createElement('channel'));
      $root = $doc->appendChild($root);
      $root->appendChild($doc->createElement('title', 'India Today | KARNATAKA NEWS'));
      $root->appendChild($doc->createElement('description', 'India Today'));
      $root->appendChild($doc->createElement('link', 'http://indiatoday.intoday.in/'));
      $root->appendChild($doc->createElement('lastBuildDate', 'Mon, 03 Feb 2014 12:38:02 IST'));
      $root->appendChild($doc->createElement('generator', 'FeedCreator 1.7.2'));

      foreach ($query as $row) {

        $content_text = $row->content_text;
        $content_image_fid = $row->content_image_fid;
        $content_image_width = $row->content_image_width;
        $content_image_height = $row->content_image_height;

        $root->appendChild($doc->createElement('keyword', 'indiatoday'));
        $root->appendChild($doc->createElement('timestamp', 'en-US'));
        $item = $doc->createElement('content');
        $item->appendChild($doc->createCDATASection($content_text));
        $root->appendChild($doc->createElement('transid', '31313131'));
        $root->appendChild($item);
      }
      $doc->save($file_path . '/result.xml') or die('XML Create Error');
      drupal_goto($base_url . "/sites/default/files/mobile_xml/result.xml");


  foreach ($client_id_array as $client_id) {
    $client_info = node_load($client_id);
    if (is_object($client_info) && count($client_info) > 0) {
      $content_sharing_mode = isset($client_info->field_content_sharing_mode) ? $client_info->field_content_sharing_mode[LANGUAGE_NONE][0]['value'] : '';
        // Decide sharing mode
        switch ($content_sharing_mode) {
          // 1. Fetch web URL (our server)
          case '1':
            break;
          case 2: // 2. Via FTP location
            $ftp_ip_address = isset($client_info->field_ftp_ip_address) ? $client_info->field_ftp_ip_address[LANGUAGE_NONE][0]['value'] : '';
            $ftp_username = isset($client_info->field_ftp_username) ? $client_info->field_ftp_username[LANGUAGE_NONE][0]['value'] : '';
            $ftp_password = isset($client_info->field_ftp_password) ? $client_info->field_ftp_password[LANGUAGE_NONE][0]['value'] : '';
            $data = array('ftp_ip_address' => $ftp_ip_address, 'ftp_username' => $ftp_username, 'ftp_password' => $ftp_password);
            itg_mobile_services_ftp_feeds($data, $file_path . '/' . $data->client_title . '.xml');
            break;
          case 3: // 3. Via Email
            $service_email_address = isset($client_info->field_service_email_address) ? $client_info->field_service_email_address[LANGUAGE_NONE][0]['value'] : '';
            itg_mobile_services_mail($data, $file_path . '/' . $data->client_title . '.xml');
            break;
        }
  
    }
  }
  
  return $file_path . '/' . $data->title . '.xml';
}

/**
 * Callback function to send syndication by mail attachment.
 * @param type $data
 * @param type $syndication_node
 */
function itg_mobile_services_mail($data, $file_path) {
  $attachment = array(
    'filepath' => $file_path,
  );
  $params = array(
    'key' => 'itg_syndication',
    'to' => $data['delivery_mode'],
    'from' => 'noreply@indiatoday.com',
    'subject' => 'Test email',
    'body' => 'Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industrys standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.',
    'attachment' => $attachment,
    'headers' => array(
      'MIME-Version: 1.0' . "\r\n",
      'Content-type: text/html; charset=iso-8859-1' . "\r\n",
      'To: ' . $data['delivery_mode'] . "\r\n",
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
  $query->range(0, 10);
  $result = $query->execute();
  while ($record = $result->fetchAssoc()) {
    $target_id[] = $record['field_client_selection_target_id'];
    $service_association_id = $record['entity_id'];
  }
  $result = array('target_id' => $target_id, 'service_association_id' => $service_association_id);
  return $result;
}

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
function itg_mobile_services_ftp_feeds($data, $file_path) {  
  $ftp_details = get_ftp_details_by_client($data['client_title'], $data['delivery_mode']);
  
  $file = $file_path;
  $remote_file = 'readme.txt';
  
  $ftp_server = $ftp_details->field_syndication_ftp_url_value;
  $ftp_user_name = $ftp_details->field_syndication_ftp_username_value;
  $ftp_user_pass = $ftp_details->field_syndication_ftp_password_value;
  
  // set up basic connection
  $conn_id = ftp_connect($ftp_server);

  // login with username and password
  $login_result = ftp_login($conn_id, $ftp_user_name, $ftp_user_pass);

  // upload a file
  if (ftp_put($conn_id, $remote_file, $file, FTP_ASCII)) {
   echo "successfully uploaded $file\n";
  } else {
   echo "There was a problem while uploading $file\n";
  }

  // close the connection
  ftp_close($conn_id);
}