<?php

/*
 * Inc file contains the functions
 */

/**
 * Feed generator of selected contents
 * @param array $data 
 */

function feed_generator_of_contents($data) {
    
    switch ($data['feed_type']) {
      case 'xml':
        $file_path = itg_syndication_generate_xml($data);
        break;
      case 'rss':
        //$file_path = itg_syndication_generate_rss($data);
        break;
      case 'mrss':

        break;
      case 'ussd':

        break;
      case 'sms':

        break;
      case 'stf':
        watchdog('syndication_stf', 'I am in queue!');
        break;
      case 'html':
        //$file_path = itg_syndication_mail_syndication($data);
        break;
    }
      

  return $file_path;
}

/**
 * Function for generating xml files.
 * @param array $data
 * @param array $syndication_node
 */
function itg_syndication_generate_xml($data) {
  
  //work start this line
  $syndication_node = unserialize($data['syndication']);
  $file_path = drupal_realpath('public://');
  $dom = new DOMDocument('1.0', 'UTF-8');
  $dom->formatOutput = true;
  $root = $dom->createElement('syndication');
  $dom->appendChild($root);

  foreach ($syndication_node as $key => $val) {
    $node = node_load($val);
    $result = $dom->createElement('content');
    $root->appendChild($result);
    $result->setAttribute('id', $key + 1);
    $result->appendChild($dom->createElement('title', $node->title));
    $result->appendChild($dom->createElement('body', '<![CDATA['.strip_tags($node->body[LANGUAGE_NONE][0]['value']).']]>'));
    $result->appendChild($dom->createElement('headline', strip_tags($node->body[LANGUAGE_NONE][0]['value'])));
    
    /*$result1 = $dom->createElement('body');
    $result->appendChild($result1);
    $result1->appendChild($dom->createElement('CDATA', strip_tags($node->body[LANGUAGE_NONE][0]['value'])));*/
    
  }
  
  $timestamp = time();
  $token = sha1($data['client_title']. $timestamp);
  $dt = date('d-m-Y');
  $xml_name = 'xml/'.$data['client_title'].'_'.$data['section_id'].'_'.$dt.'_'.$token;
  
  $dom->save($file_path . '/' . $xml_name . '.xml') or die('XML Create Error');
  drupal_set_message('xml file has been created.', 'status');
  
  $delivery_mode = $data['delivery_mode'];

  if (!filter_var($delivery_mode, FILTER_VALIDATE_EMAIL) === false) {
    $delivery_mode_type = 'Email';
  } else {
      $check_mode = explode('/syndication/', $delivery_mode);
      if (isset($check_mode[1])) {
        $delivery_mode_type = 'web_url';
      } else {
          $delivery_mode_type = 'FTP';
      }
  }
  
  // Decide sharing mode
  switch ($delivery_mode_type) {
    // 1. Fetch web URL (our server)
    case 'web_url':
      itg_syndication_web_url_syndication($data, $file_path . '/' . $xml_name . '.xml');
      break;
    // 2. Via FTP location
      
    case 'FTP':
      itg_syndication_ftp_syndication($data, $file_path . '/' . $data['client_title'] . '.xml');
      break;
    // 3. Via Email
    case 'Email':
      itg_syndication_mail_syndication($data, $file_path . '/' . $data['client_title'] . '.xml');
      break;
  }
  
  return  $file_path . '/' . $data['client_title'] . '.xml';
}

/**
 * Callback function to send syndication by mail attachment.
 * @param type $data
 * @param type $syndication_node
 */
function itg_syndication_mail_syndication($data, $file_path) {
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
      'To: '.$data['delivery_mode'] . "\r\n",
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
 * @param type $data
 * @param type $file_path
 */
function itg_syndication_ftp_syndication($data, $file_path) {  
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

/**
 * function to feed for syndication by ftp.
 * @param type $data
 * @param type $file_path
 */
function itg_syndication_web_url_syndication($data, $file_path) {
  
  $query = db_insert('itg_syndication_feed_url');
    $query->fields(array(
      'xml_name' => $file_path,
      'client_feed_url' => $data['delivery_mode'],      
      'created_date' => time(),
      'status' => 1
    )); 
    $query->execute();
}

/**
 * Get FTP details of client
 * @param $client_name
 * @param $ftp_name
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
  
  return $data;
}