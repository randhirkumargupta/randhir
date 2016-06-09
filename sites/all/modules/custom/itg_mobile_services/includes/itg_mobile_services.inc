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
      case 'xml':
        $file_path = itg_mobile_services_generate_xml($data);
        break;
      case 'rss':
        $file_path = itg_syndication_generate_rss($data);
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

    $association_nid = $node->field_service_association_title[LANGUAGE_NONE][0]['target_id'];
  
    $service_details = node_load($association_nid);
    $delivery_mode = $service_details->field_service_delivery_mode;
    $expiry_date = $service_details->field_story_expiry_date;    
        
    $get_clients_id = get_clients_id($association_nid);
    $client_id_array = $get_clients_id['target_id'];
    $service_association_id = $get_clients_id['service_association_id'];
    
    foreach ($client_id_array as $client_id) {
      $service_association_array = node_load($client_id);
      if(is_object($service_association_array) && count($service_association_array) > 0) {
        $content_type = isset($service_association_array->field_service_content_type) ? $service_association_array->field_service_content_type[LANGUAGE_NONE][0]['value'] : '';
        $content_count = isset($service_association_array->field_service_content_count) ? $service_association_array->field_service_content_count[LANGUAGE_NONE][0]['value'] : '';
        $char_limit = isset($service_association_array->field_service_char_limit) ? $service_association_array->field_service_char_limit[LANGUAGE_NONE][0]['value'] : '';
        $field_header = isset($service_association_array->field_header) ? $service_association_array->field_header[LANGUAGE_NONE][0]['value'] : '';
        $field_footer = isset($service_association_array->field_footer) ? $service_association_array->field_footer[LANGUAGE_NONE][0]['value'] : '';
      } 
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
    
    
    
    
    
    
    
    
    
    
    
  $syndication_node = unserialize($data->syndication);
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
    $result->appendChild($dom->createElement('body', strip_tags($node->body[LANGUAGE_NONE][0]['value'])));
    $result->appendChild($dom->createElement('headline', strip_tags($node->body[LANGUAGE_NONE][0]['value'])));
  }

  $dom->save($file_path . '/' . $data->client_title . '.xml') or die('XML Create Error');
  drupal_set_message('xml file has been created.', 'status');

  
  

  if (!filter_var($delivery_mode, FILTER_VALIDATE_EMAIL) === false) {
    $delivery_mode_type = 'Email';
  } else {
      $delivery_mode_type = 'FTP';
  }
  
  // Decide sharing mode
  switch ($delivery_mode) {
    // 1. Fetch web URL (our server)
    case '1':
      break;
    // 2. Via FTP location
      
    case 'FTP':
      itg_syndication_ftp_syndication($data, $file_path . '/' . $data->client_title . '.xml');
      break;
    // 3. Via Email
    case 'Email':
      itg_mobile_services_mail($data, $file_path . '/' . $data->client_title . '.xml');
      break;
  }
  
  return  $file_path . '/' . $data->title . '.xml';
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
      'To: '.$data['delivery_mode'] . "\r\n",
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
    while($record = $result->fetchAssoc()) {
       $target_id[] = $record['field_client_selection_target_id'];
       $service_association_id = $record['entity_id'];
    }
    $result = array('target_id' => $target_id, 'service_association_id' => $service_association_id);
   return $result;
}


function get_content_sharing_mode($entity_id) {
   if(isset($entity_id)) {
      $query = db_select('field_data_field_content_sharing_mode', 'csm')->fields('csm', array('field_content_sharing_mode_value'));
      $query->condition('csm.entity_id', $entity_id, '=');
      $query->range(0, 1);
      $result = $query->execute();
      $record = $result->fetchAssoc();
   } 
   return isset($record['field_content_sharing_mode_value']) ? $record['field_content_sharing_mode_value'] : '';
} 