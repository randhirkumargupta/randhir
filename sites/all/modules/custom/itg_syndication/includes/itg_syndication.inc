<?php

/*
 * Inc file contains the functions
 */

function feed_generator_of_content() {
  // Today date
  $today = date('Y/m/d') . ' 00:00:00';
  // Fetch syndication item from database whoes status is 0
  $itg_query = db_select('itg_row_selector', 'itg');
  $itg_query->fields('itg', array('id', 'web_property', 'client_title', 'syndication'))
      ->condition('created', $today)
      ->conditions('status', 0);
  $itg_result = $itg_query->execute()->fetchAll();

  // Count result
  if (count($itg_result) >= 1) {
    foreach ($itg_result as $synd_value) {
      $data = itg_syndication_client_details($synd_value->client_title);      
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

  $dom->save($file_path . '/'.$data->title.'.xml') or die('XML Create Error');
  drupal_set_message('xml file has been created.', 'status');
  
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
  $rss->setAttribute("version","2.0"); //set RSS version


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