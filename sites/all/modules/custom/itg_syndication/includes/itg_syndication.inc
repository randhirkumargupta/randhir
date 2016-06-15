<?php

/*
 * Inc file contains the functions
 */

function feed_generator_of_content($client_name) {

  // Today date
  $today = date('Y/m/d') . ' 00:00:00';
  // Fetch syndication item from database whoes status is 0
  $itg_query = db_select('itg_row_selector', 'itg');
  $itg_query->fields('itg', array('id', 'web_property', 'syndication'))
      ->condition('created', $today)
      ->condition('client_title', $client_name)
      ->conditions('status', 0);
  $itg_result = $itg_query->execute()->fetchAll();
  // Count result
  if (count($itg_result) >= 1) {
    foreach ($itg_result as $synd_value) {
      $data = itg_syndication_client_details($client_name);
      // Check if client exist
      if (isset($data->nid) && $data->nid > 0) {
        $syndication_node = unserialize($synd_value->syndication);
        switch ($data->field_syndication_delivery_mode['und'][0]['value']) {
          case 'xml':
            itg_syndication_generate_xml($data, $syndication_node);
            break;
          case 'rss':
            itg_syndication_generate_rss($data, $syndication_node);
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
            itg_syndication_mail_syndication($data, $syndication_node);
            break;
        }
      }
    }
  }

  return 'XML File Generated';
}

function itg_syndication_client_details($client) {
  $itg_query = db_select('node', 'n');
  $itg_query->fields('n', array('nid'))
      ->condition('title', $client)
      ->condition('status', 1)
      ->condition('type', 'syndication_client');
  $itg_result = $itg_query->execute()->fetchField();
  $data = array();
  // Load client  
  if ($itg_result > 0) {
    $data = node_load($itg_result);
  }

  return $data;
}

/**
 * Function for generating xml files.
 * @param array $data
 * @param array $syndication_node
 */
function itg_syndication_generate_xml($data, $syndication_node) {
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

  $dom->save($file_path . '/' . $data->title . '.xml') or die('XML Create Error');
  drupal_set_message('xml file has been created.', 'status');

  // Decide sharing mode
  switch ($data->field_content_sharing_mode['und'][0]['value']) {
    // 1. Fetch web URL (our server)
    case '1':
      break;
    // 2. Via FTP location
    case '2':
      break;
    // 3. Via Email
    case '3':
      itg_syndication_mail_syndication($data, $syndication_node, $file_path . '/' . $data->title . '.xml');
      break;
  }
}

/**
 * Function to generate rss
 * @param array $data
 * @param array $syndication_node
 */
function itg_syndication_generate_rss($data, $syndication_node) {
  $file_path = drupal_realpath('public://');
  $dom = new DOMDocument('1.0', 'UTF-8');
  $dom->formatOutput = true;
  //create "RSS" element
  $rss = $dom->createElement("rss");
  $rss = $dom->appendChild($rss); //add RSS element to XML node
  $rss->setAttribute("version", "2.0"); //set RSS version


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

  $dom->save($file_path . '/itg_rss.xml') or die('rss Create Error');
  watchdog('syndication_rss', 'RSS created');
  drupal_set_message('rss file has been created.', 'status');
}

/**
 * Callback function to send syndication by mail attachment.
 * @param type $data
 * @param type $syndication_node
 */
function itg_syndication_mail_syndication($data, $syndication_node, $file_path) {
  $attachment = array(
    'filepath' => $file_path,
  );
  $params = array(
    'key' => 'itg_syndication',
    'to' => 'yogesh.kushwaha@kelltontech.com',
    'from' => 'noreply@indiatoday.com',
    'subject' => 'Test email',
    'body' => 'Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industrys standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.',
    'attachment' => $attachment,
    'headers' => array(
      'MIME-Version: 1.0' . "\r\n",
      'Content-type: text/html; charset=iso-8859-1' . "\r\n",
      'To: Yogesh Kushwaha <yogesh.kushwaha@kelltontech.com.com>' . "\r\n",
      'From: India Today <noreply@indiatoday.com>' . "\r\n",
    ),
  );
  $language = language_default();

  drupal_mail('itg_syndication', $params['key'], $params['to'], $language, $params, $params['from']);
}

/**
 * Implements hook_mail().
 * 
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
 * test funcation
 */
function feed_test() {
    generate_custom_feed();
    die;
}

/**
 * 
 */

function generate_custom_feed($nid=1474) {
    $node =   node_load($nid);
    $data_array =   array();
    $feed_data  = '';
    $text   =   "
        <story>
        <body>{{{body}}}</body>
        <newtitle>{{{field_story_new_title}}}</newtitle>
        <issues>{{{field_story_magazine_story_issue}}}</issues>
        <headline>{{{field_story_magazine_headline}}}</headline>
        <image>{{{field_story_large_image}}}</image>
        <city>{{{field_stroy_city}}}</city>
        <category>{{{field_story_category}}}</category>
        <expertname>{{{field_story_expert_name}}}</expertname>
        <facoids>{{{field_story_template_factoids}}}</facoids>
        <kicker>{{{field_story_kicker_text}}}</kicker>
        <image>{{{field_story_medium_image}}}</image>
        <fb>{{{field_story_posted_by_facebook}}}</fb>
        <issuedate>{{{field_story_issue_date}}}</issuedate>
        <tags>{{{field_story_itg_tags}}}</tags>
        <configuration>{{{field_story_configurations}}}</configuration>
        <quotes>{{{field_story_template_quotes}}}</quotes>
        </story>
    ";
    $isValidXml = isValidXml($text);
    if($isValidXml) {
        // extract fields name from text string
        $var_array  =   get_vars_from_feed_pattern($text);
        
        // validate fields w.r.t content type
        $content_type   =   $node->type;
        foreach ($var_array[1] as $field_name) {
            if(!isValidField($field_name,$content_type)) {
                $message[]  =   $field_name." is not a valid field in ".$content_type;
            }
        }
        
        //process if there is no message
        if(empty($message)) {
            $iteration  =   count($var_array[0]);
            $new_text   =   '';
            for($i=0;$i<$iteration;$i++) {        
                $data_array[] =  get_required_data_field_get_items('node', $node, $var_array[1][$i]);
            }
            foreach($var_array[0] as $key=>$pattren) {
                $replacement    =   implode(", ", $data_array[$key]);
                $new_text       =   str_replace($pattren, $replacement, $text);
                $text           =   $new_text;
            }
            $xml = new SimpleXMLElement($new_text);
            echo $xml->asXML();
        }else {
            drupal_set_message("not a valid field");
        }        
    }else {
        return drupal_set_message("Not a valid formet");
    }
    
}

/**
 * @param string $content_type
 * @return array which has all the fields name on perticular file type
 */

function fieldsArray($content_type) {
    $field_info =   array();
    $content_type_fields = field_info_instances('node', $content_type);
    foreach($content_type_fields as $field) {
        $field_info[]   =   $field['field_name'];
    }
    return $field_info;
}


/**
 * @param string $text
 * @return array $matches
 */

function get_vars_from_feed_pattern($text) {
    $matches   =   array();
    if(isset($text)) {
        preg_match_all('/{{{(.*?)}}}/', $text, $matches);
    }
    return $matches;
}

/**
 * @param string $fieldName
 * @param blooen $flag
 */

function isValidField($field_name,$content_type) {
    $flag   =   false;
    if(isset($field_name) && isset($content_type)) {
        if(in_array($field_name, fieldsArray($content_type))) {
            $flag   =   true;
        }
    }
    return $flag;
}

/**
 * @param string $xml
 * @return boolen $errors
 */

function isValidXml($xml) {
    libxml_use_internal_errors(true);
    $doc = new DOMDocument('1.0', 'utf-8');
    $doc->loadXML($xml);
    $errors = libxml_get_errors();
    return empty($errors);
}


function get_required_data_field_get_items($entity_type, $entity, $field_name) {
    $required_value =   '';
    $field_item     =   field_get_items($entity_type, $entity, $field_name);
    if(count($field_item)) {
        foreach($field_item as $delta=>$values) {
            $keys   = array_keys($values);
            $key_delta  =   $keys[0];
            switch ($key_delta) {
                case 'tid':
                    $tid_value          =   taxonomy_term_load($values['tid']);
                    $required_value[]   =   $tid_value->name;
                    break;
                case 'fid':
                    $fid_value          =   $values['fid'];
                    $file_load          =   file_load($fid_value);
                    $required_value[]   =   file_create_url($file_load->uri);
                    break;
                case 'uid':
                    $uid_values         =   entity_load('user',$values['uid']);
                    $required_value     =   $uid_values->name;
                    break;
                case 'value':
                    $required_value[]   =   $field_item[0]['value'];
                    break;
            }
        }
    }
   return $required_value;
}
