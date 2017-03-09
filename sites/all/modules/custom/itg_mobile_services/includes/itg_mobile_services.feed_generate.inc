<?php

/**
 * Inc file contains the functions
 */

/**
 * Function for generating xml files.
 * @param object $node
 * @param string $service_title
 * @param string $field_header
 * @param string $field_footer
 * @param string $xmlstring
 * @param int $astro
 * @return string
 */
function itg_mobile_services_generate_xml($node, $service_title, $field_header = NULL, $field_footer = NULL, $xmlstring, $astro = NULL) {
  // Load itg_syndication.inc from the node module.
  module_load_include('inc', 'itg_syndication', 'includes/itg_syndication_custom_feed');
  $xml = simplexml_load_string($xmlstring, "SimpleXMLElement", LIBXML_NOCDATA);
  $json = json_encode($xml);
  $xmlarray = json_decode($json, TRUE);
  $root_tag = $xml->getName();
  $xml = '<?xml version="1.0" encoding="ISO-8859-1" ?>';
  $field_collect = node_load($node->nid);
  $tags = array("header", "footer");
  $xml_file = preg_replace('#<(' . implode('|', $tags) . ')(?:[^>]+)?>.*?</\1>#s', '', $xmlstring);
  $xml_file = str_replace("<" . $root_tag . ">", "", $xml_file);
  $xml_file = str_replace("</" . $root_tag . ">", "", $xml_file);
  $data_array = get_required_data_field_get_items_mobile($field_collect, $astro);

  // header
  foreach ($xmlarray['header'] as $label => $pattren) {
    if ($pattren == '{field_header}') {
      $pattren = $field_header;
    }
    if ($pattren == '{field_footer}') {
      $pattren = $field_footer;
    }
    $header .= '<' . $label . '>' . $pattren . '</' . $label . '>';
  }
  // footer
  foreach ($xmlarray['footer'] as $label => $pattren) {
    if ($pattren == '{field_header}') {
      $pattren = $field_header;
    }
    if ($pattren == '{field_footer}') {
      $pattren = $field_footer;
    }
    $footer .= '<' . $label . '>' . $pattren . '</' . $label . '>';
  }

  $xml .= "<" . $root_tag . ">";
  $xml .= $header;
  foreach ($data_array as $keys => $value) {
    $xml .= get_custom_feeds_files_mobile($field_collect, $xml_file, $keys, $astro);
  }
  $xml .= $footer;
  $xml .= "</" . $root_tag . ">";

  $feed_dir = "public://";
  $full_file_path = generate_file_name($node, $service_title, 'xml', 'xml');
  file_save_data($xml, $feed_dir . $full_file_path);
  drupal_set_message(t('Your xml has been generated'));
  return $full_file_path;
}

/**
 * Function for generating rss files.
 * @param object $node
 * @param string $service_title
 * @param string $field_header
 * @param string $field_footer
 * @param string $xmlstring
 * @param int $astro
 * @return string
 */
function itg_mobile_services_generate_rss($node, $service_title, $field_header = NULL, $field_footer = NULL, $xmlstring, $astro = NULL) {
  // Load itg_syndication.inc from the node module.
  module_load_include('inc', 'itg_syndication', 'includes/itg_syndication_custom_feed');
  $xml = simplexml_load_string($xmlstring, "SimpleXMLElement", LIBXML_NOCDATA);
  $json = json_encode($xml);
  $xmlarray = json_decode($json, TRUE);
  $root_tag = $xml->getName();

  $xml = '<?xml version="1.0" encoding="UTF-8"?>';
  $xml .= '<rss version="2.0">';
  $field_collect = node_load($node->nid);
  $tags = array("header", "footer");
  $xml_file = preg_replace('#<(' . implode('|', $tags) . ')(?:[^>]+)?>.*?</\1>#s', '', $xmlstring);

  $xml_file = str_replace("<" . $root_tag . ">", "", $xml_file);
  $xml_file = str_replace("</" . $root_tag . ">", "", $xml_file);
  $data_array = get_required_data_field_get_items_mobile($field_collect, $astro);

  // header
  foreach ($xmlarray['header'] as $label => $pattren) {
    if ($pattren == '{field_header}') {
      $pattren = $field_header;
    }
    if ($pattren == '{field_footer}') {
      $pattren = $field_footer;
    }
    $header .= '<' . $label . '>' . $pattren . '</' . $label . '>';
  }

  // footer
  foreach ($xmlarray['footer'] as $label => $pattren) {
    if ($pattren == '{field_header}') {
      $pattren = $field_header;
    }
    if ($pattren == '{field_footer}') {
      $pattren = $field_footer;
    }
    $footer .= '<' . $label . '>' . $pattren . '</' . $label . '>';
  }

  $xml .= "<" . $root_tag . ">";
  $xml .= $header;

  foreach ($data_array as $keys => $value) {
    $xml .= get_custom_feeds_files_mobile($field_collect, $xml_file, $keys, $astro);
  }
  $xml .= $footer;
  $xml .= "</" . $root_tag . ">";
  $xml .= "</rss>";

  $feed_dir = "public://";
  $full_file_path = generate_file_name($node, $service_title, 'rss', 'xml');
  file_save_data($xml, $feed_dir . $full_file_path);
  drupal_set_message(t('Your RSS has been generated'));
  return $full_file_path;
}

/**
 * Function for generating mrss files.
 * @param object $node
 * @param string $service_title
 * @param string $field_header
 * @param string $field_footer
 * @param string $xmlstring
 * @param int $astro
 * @return string
 */
function itg_mobile_services_generate_mrss($node, $service_title, $field_header = NULL, $field_footer = NULL, $xmlstring, $astro = NULL) {
  // Load itg_syndication.inc from the node module.
  module_load_include('inc', 'itg_syndication', 'includes/itg_syndication_custom_feed');
  $xml = simplexml_load_string($xmlstring, "SimpleXMLElement", LIBXML_NOCDATA);
  $json = json_encode($xml);
  $xmlarray = json_decode($json, TRUE);
  $root_tag = $xml->getName();

  $xml = '<?xml version="1.0" encoding="ISO-8859-1" ?>';
  $xml .= '<rss version="2.0" xmlns:media="http://search.yahoo.com/mrss/">';
  $field_collect = node_load($node->nid);
  $tags = array("header", "footer");
  $xml_file = preg_replace('#<(' . implode('|', $tags) . ')(?:[^>]+)?>.*?</\1>#s', '', $xmlstring);

  $xml_file = str_replace("<" . $root_tag . ">", "", $xml_file);
  $xml_file = str_replace("</" . $root_tag . ">", "", $xml_file);
  $data_array = get_required_data_field_get_items_mobile($field_collect, $astro);

  // header
  foreach ($xmlarray['header'] as $label => $pattren) {
    if ($pattren == '{field_header}') {
      $pattren = $field_header;
    }
    if ($pattren == '{field_footer}') {
      $pattren = $field_footer;
    }
    $header .= '<' . $label . '>' . $pattren . '</' . $label . '>';
  }

  // footer
  foreach ($xmlarray['footer'] as $label => $pattren) {
    if ($pattren == '{field_header}') {
      $pattren = $field_header;
    }
    if ($pattren == '{field_footer}') {
      $pattren = $field_footer;
    }
    $footer .= '<' . $label . '>' . $pattren . '</' . $label . '>';
  }
  $xml .= "<" . $root_tag . ">";
  $xml .= $header;

  foreach ($data_array as $keys => $value) {
    $xml .= get_custom_feeds_files_mobile($field_collect, $xml_file, $keys, $astro);
  }

  $xml .= "</" . $root_tag . ">";
  $xml .= $footer;
  $xml .= "</rss>";

  $feed_dir = "public://";
  $full_file_path = generate_file_name($node, $service_title, 'mrss', 'xml');
  file_save_data($xml, $feed_dir . $full_file_path);
  drupal_set_message(t('Your MRSS has been generated'));
  return $full_file_path;
}

/**
 * Function for generating sms files.
 * @param object $node
 * @param string $service_title
 * @param string $field_header
 * @param string $field_footer
 * @param string $xmlstring
 * @param int $astro
 * @return string
 */
function itg_mobile_services_generate_sms($node, $service_title, $field_header = NULL, $field_footer = NULL, $xmlstring, $astro = NULL) {
  // Load itg_syndication.inc from the node module.
  module_load_include('inc', 'itg_syndication', 'includes/itg_syndication_custom_feed');
  $xml = simplexml_load_string($xmlstring, "SimpleXMLElement", LIBXML_NOCDATA);
  $json = json_encode($xml);
  $xmlarray = json_decode($json, TRUE);
  $root_tag = $xml->getName();

  $xml = '<?xml version="1.0"?>';
  $xml .= '<rss version="2.0" xmlns:atom="http://www.w3.org/2005/Atom">';
  $field_collect = node_load($node->nid);
  $tags = array("header", "footer");
  $xml_file = preg_replace('#<(' . implode('|', $tags) . ')(?:[^>]+)?>.*?</\1>#s', '', $xmlstring);

  $xml_file = str_replace("<" . $root_tag . ">", "", $xml_file);
  $xml_file = str_replace("</" . $root_tag . ">", "", $xml_file);
  $data_array = get_required_data_field_get_items_mobile($field_collect, $astro);

  // header
  foreach ($xmlarray['header'] as $label => $pattren) {
    if ($pattren == '{field_header}') {
      $pattren = $field_header;
    }
    if ($pattren == '{field_footer}') {
      $pattren = $field_footer;
    }
    $header .= '<' . $label . '>' . $pattren . '</' . $label . '>';
  }

  // footer
  foreach ($xmlarray['footer'] as $label => $pattren) {
    if ($pattren == '{field_header}') {
      $pattren = $field_header;
    }
    if ($pattren == '{field_footer}') {
      $pattren = $field_footer;
    }
    $footer .= '<' . $label . '>' . $pattren . '</' . $label . '>';
  }

  $xml .= "<" . $root_tag . ">";
  $xml .= $header;

  foreach ($data_array as $keys => $value) {
    $xml .= get_custom_feeds_files_mobile($field_collect, $xml_file, $keys, $astro);
  }
  $xml .= $footer;
  $xml .= "</" . $root_tag . ">";
  $xml .= "</rss>";
  $feed_dir = "public://";
  $full_file_path = generate_file_name($node, $service_title, 'sms', 'xml');
  file_save_data($xml, $feed_dir . $full_file_path);
  drupal_set_message(t('Your feed has been generated'));
  return $full_file_path;
}

/**
 * Function for generating Simple Text Feed.
 * @param object $node
 * @param string $service_title
 * @param string $field_header
 * @param string $field_footer
 * @param string $xmlstring
 * @param int $astro
 * @return string
 */
function itg_mobile_services_generate_feed($node, $service_title, $field_header = NULL, $field_footer = NULL, $xmlstring, $astro = NULL) {
  // Load itg_syndication.inc from the node module.
  module_load_include('inc', 'itg_syndication', 'includes/itg_syndication_custom_feed');
  $xml = simplexml_load_string($xmlstring, "SimpleXMLElement", LIBXML_NOCDATA);
  $json = json_encode($xml);
  $xmlarray = json_decode($json, TRUE);
  $root_tag = $xml->getName();

  $xml = '<?xml version="1.0"?>';
  $xml .= '<rss version="2.0" xmlns:atom="http://www.w3.org/2005/Atom">';
  $field_collect = node_load($node->nid);
  $tags = array("header", "footer");
  $xml_file = preg_replace('#<(' . implode('|', $tags) . ')(?:[^>]+)?>.*?</\1>#s', '', $xmlstring);

  $xml_file = str_replace("<" . $root_tag . ">", "", $xml_file);
  $xml_file = str_replace("</" . $root_tag . ">", "", $xml_file);
  $data_array = get_required_data_field_get_items_mobile($field_collect, $astro);

  // header
  foreach ($xmlarray['header'] as $label => $pattren) {
    if ($pattren == '{field_header}') {
      $pattren = $field_header;
    }
    if ($pattren == '{field_footer}') {
      $pattren = $field_footer;
    }
    $header .= '<' . $label . '>' . $pattren . '</' . $label . '>';
  }

  // footer
  foreach ($xmlarray['footer'] as $label => $pattren) {
    if ($pattren == '{field_header}') {
      $pattren = $field_header;
    }
    if ($pattren == '{field_footer}') {
      $pattren = $field_footer;
    }
    $footer .= '<' . $label . '>' . $pattren . '</' . $label . '>';
  }

  $xml .= "<" . $root_tag . ">";
  $xml .= $header;

  foreach ($data_array as $keys => $value) {
    $xml .= get_custom_feeds_files_mobile($field_collect, $xml_file, $keys, $astro);
  }
  $xml .= $footer;
  $xml .= "</" . $root_tag . ">";
  $xml .= "</rss>";

  $feed_dir = "public://";
  $full_file_path = generate_file_name($node, $service_title, 'text_feed', 'xml');
  file_save_data($xml, $feed_dir . $full_file_path);
  drupal_set_message(t('Your feed has been generated'));
  return $full_file_path;
}

/**
 * Function for generating ussd files.
 * @param object $node
 * @param string $service_title
 * @param string $field_header
 * @param string $field_footer
 * @param string $xmlstring
 * @param int $astro
 * @return string
 */
function itg_mobile_services_generate_ussd($node, $service_title, $field_header = NULL, $field_footer = NULL, $xmlstring, $astro = NULL) {
  // Load itg_syndication.inc from the node module.
  module_load_include('inc', 'itg_syndication', 'includes/itg_syndication_custom_feed');
  $xml = simplexml_load_string($xmlstring, "SimpleXMLElement", LIBXML_NOCDATA);
  $json = json_encode($xml);
  $xmlarray = json_decode($json, TRUE);
  $root_tag = $xml->getName();

  $xml = '<?xml version="1.0"?>';
  $xml .= '<rss version="2.0" xmlns:atom="http://www.w3.org/2005/Atom">';
  $field_collect = node_load($node->nid);
  $tags = array("header", "footer");
  $xml_file = preg_replace('#<(' . implode('|', $tags) . ')(?:[^>]+)?>.*?</\1>#s', '', $xmlstring);

  $xml_file = str_replace("<" . $root_tag . ">", "", $xml_file);
  $xml_file = str_replace("</" . $root_tag . ">", "", $xml_file);
  $data_array = get_required_data_field_get_items_mobile($field_collect, $astro);

  // header
  foreach ($xmlarray['header'] as $label => $pattren) {
    if ($pattren == '{field_header}') {
      $pattren = $field_header;
    }
    if ($pattren == '{field_footer}') {
      $pattren = $field_footer;
    }
    $header .= '<' . $label . '>' . $pattren . '</' . $label . '>';
  }

  // footer
  foreach ($xmlarray['footer'] as $label => $pattren) {
    if ($pattren == '{field_header}') {
      $pattren = $field_header;
    }
    if ($pattren == '{field_footer}') {
      $pattren = $field_footer;
    }
    $footer .= '<' . $label . '>' . $pattren . '</' . $label . '>';
  }

  $xml .= "<" . $root_tag . ">";
  $xml .= $header;

  foreach ($data_array as $keys => $value) {
    $xml .= get_custom_feeds_files_mobile($field_collect, $xml_file, $keys, $astro);
  }
  $xml .= $footer;
  $xml .= "</" . $root_tag . ">";
  $xml .= "</rss>";
  $feed_dir = "public://";
  $full_file_path = generate_file_name($node, $service_title, 'ussd', 'xml');
  file_save_data($xml, $feed_dir . $full_file_path);
  drupal_set_message(t('Your ussd has been generated'));
  return $full_file_path;
}

/**
 * Function for generating sms files.
 * @param object $node
 * @param string $service_title
 * @param string $field_header
 * @param string $field_footer
 * @param string $xmlstring
 * @param int $astro
 * @return string
 */
function itg_mobile_services_generate_astro_mrss($node, $service_title, $field_header = NULL, $field_footer = NULL, $xmlstring, $astro = NULL) {
  // Load itg_syndication.inc from the node module.
  module_load_include('inc', 'itg_syndication', 'includes/itg_syndication_custom_feed');
  $xml = simplexml_load_string($xmlstring, "SimpleXMLElement", LIBXML_NOCDATA);
  $json = json_encode($xml);
  $xmlarray = json_decode($json, TRUE);
  $root_tag = $xml->getName();

  $xml = '<?xml version="1.0" encoding="ISO-8859-1" ?>';
  $xml .= '<rss version="2.0" xmlns:media="http://search.yahoo.com/mrss/">';
  $field_collect = node_load($node->nid);
  $tags = array("header", "footer");
  $xml_file = preg_replace('#<(' . implode('|', $tags) . ')(?:[^>]+)?>.*?</\1>#s', '', $xmlstring);

  $xml_file = str_replace("<" . $root_tag . ">", "", $xml_file);
  $xml_file = str_replace("</" . $root_tag . ">", "", $xml_file);
  $data_array = get_required_data_field_get_items_mobile($field_collect, $astro);

  // header
  foreach ($xmlarray['header'] as $label => $pattren) {
    if ($pattren == '{field_header}') {
      $pattren = $field_header;
    }
    if ($pattren == '{field_footer}') {
      $pattren = $field_footer;
    }
    $header .= '<' . $label . '>' . $pattren . '</' . $label . '>';
  }

  // footer
  foreach ($xmlarray['footer'] as $label => $pattren) {
    if ($pattren == '{field_header}') {
      $pattren = $field_header;
    }
    if ($pattren == '{field_footer}') {
      $pattren = $field_footer;
    }
    $footer .= '<' . $label . '>' . $pattren . '</' . $label . '>';
  }

  $xml .= "<" . $root_tag . ">";
  $xml .= $header;
  foreach ($data_array as $keys => $value) {
    $xml .= get_custom_feeds_files_mobile($field_collect, $xml_file, $keys, $astro);
  }
  $xml .= "</" . $root_tag . ">";
  $xml .= $footer;
  $xml .= "</rss>";

  $feed_dir = "public://";
  $full_file_path = generate_file_name($node, $service_title, 'mrss', 'xml');
  file_save_data($xml, $feed_dir . $full_file_path);
  drupal_set_message(t('Your MRSS has been generated'));
  return $full_file_path;
}

/**
 * Function for generating Astro sms files.
 * @param object $node
 * @param string $service_title
 * @param string $field_header
 * @param string $field_footer
 * @param string $xmlstring
 * @param int $astro
 * @return string
 */
function itg_mobile_services_generate_astro_sms($node, $service_title, $field_header = NULL, $field_footer = NULL, $xmlstring, $astro = NULL) {
  // Load itg_syndication.inc from the node module.
  module_load_include('inc', 'itg_syndication', 'includes/itg_syndication_custom_feed');
  $xml = simplexml_load_string($xmlstring, "SimpleXMLElement", LIBXML_NOCDATA);
  $json = json_encode($xml);
  $xmlarray = json_decode($json, TRUE);
  $root_tag = $xml->getName();

  $xml = '<?xml version="1.0" encoding="ISO-8859-1" ?>';
  $field_collect = node_load($node->nid);
  $tags = array("header", "footer");
  $xml_file = preg_replace('#<(' . implode('|', $tags) . ')(?:[^>]+)?>.*?</\1>#s', '', $xmlstring);

  $xml_file = str_replace("<" . $root_tag . ">", "", $xml_file);
  $xml_file = str_replace("</" . $root_tag . ">", "", $xml_file);
  $data_array = get_required_data_field_get_items_mobile($field_collect, $astro);

  // header
  foreach ($xmlarray['header'] as $label => $pattren) {
    if ($pattren == '{field_header}') {
      $pattren = $field_header;
    }
    if ($pattren == '{field_footer}') {
      $pattren = $field_footer;
    }
    $header .= '<' . $label . '>' . $pattren . '</' . $label . '>';
  }

  // footer
  foreach ($xmlarray['footer'] as $label => $pattren) {
    if ($pattren == '{field_header}') {
      $pattren = $field_header;
    }
    if ($pattren == '{field_footer}') {
      $pattren = $field_footer;
    }
    $footer .= '<' . $label . '>' . $pattren . '</' . $label . '>';
  }

  $xml .= "<" . $root_tag . ">";
  $xml .= $header;
  foreach ($data_array as $keys => $value) {
    $xml .= get_custom_feeds_files_mobile($field_collect, $xml_file, $keys, $astro);
  }
  $xml .= $footer;
  $xml .= "</" . $root_tag . ">";

  $feed_dir = "public://";
  $full_file_path = generate_file_name($node, $service_title, 'sms', 'xml');
  file_save_data($xml, $feed_dir . $full_file_path);
  drupal_set_message(t('Your sms has been generated'));
  return $full_file_path;
}

/**
 * function to generate_file_name.
 * @param object $node
 * @param string $service_title
 * @param string $feeds_type
 * @param string $ext
 * @return string
 */
function generate_file_name($node, $service_title, $feeds_type, $ext) {
  $service_frequency = $node->field_service_frequency[LANGUAGE_NONE][0]['value'];
  $frequency_from_arr = explode(' ', $node->field_service_frequency_date[LANGUAGE_NONE][0]['value']);
  $frequency_to_arr = explode(' ', $node->field_service_frequency_date[LANGUAGE_NONE][0]['value2']);
  $frequency_from_date = $frequency_from_arr[0];
  $frequency_to_date = $frequency_to_arr[0];
  $timestamp = time();
  switch ($service_frequency) {
    case '1': // daily 
      $file_name = '/daily_' . $service_title . '_' . $frequency_from_date . '_' . $timestamp . '.' . $ext;
      break;
    case '2': // weekly
      $frequency_from_date = $frequency_from_arr[0];
      $frequency_to_date = $frequency_to_arr[0];
      $file_name = '/weekly_' . $service_title . '_' . $frequency_from_date . '-to-' . $frequency_to_date . '_' . $timestamp . '.' . $ext;
      break;
    case '3': // monthly
      $frequency_from_date = $frequency_from_arr[0];
      $frequency_to_date = $frequency_to_arr[0];
      $file_name = '/monthly_' . $service_title . '_' . $frequency_from_date . '-to-' . $frequency_to_date . '_' . $timestamp . '.' . $ext;
      break;
  }
//  $file_path = drupal_realpath('public://');
//  $feed_dir = "public://mobile/";
//  if (!file_exists($feed_dir)) {
//    drupal_mkdir($feed_dir, 0777, TRUE);
//  }
//
//  $full_file_path = $file_path . '/mobile/' . $service_title . '/' . $feeds_type . $file_name;
//  $files_path = $file_path . '/mobile/' . $service_title . '/' . $feeds_type;
//
//  if (!file_exists($files_path)) {
//    drupal_mkdir($files_path, 0777, TRUE);
//  }
  $file_path = drupal_realpath('public://');
  $feed_dir = "public://mobile/";
  drupal_mkdir($feed_dir, 0777, TRUE);
  $full_file_path =  'public://mobile/' . $service_title . '/' . $feeds_type . $file_name;
  $files_path =  'public://mobile/' . $service_title . '/' . $feeds_type;
  if (!file_exists($files_path)) {
    drupal_mkdir($files_path, 0777, TRUE);
  }

  return '/mobile/' . $service_title . '/' . $feeds_type . $file_name;
}

/**
 * 
 * @param object $field_collect
 * @param type $text
 * @param type $keys
 * @return type string
 */
function get_custom_feeds_mobile($field_collect = NULL, $text = NULL, $keys, $astro) {
  //$text = str_replace("<p>", "", $text);
  //$text = str_replace("</p>", "", $text);
  $var_array = get_vars_from_mobile_feed_pattern($text);
  $data_array = get_required_data_field_get_items_mobile($field_collect, $astro);
  foreach ($var_array[1] as $key => $pattren) {
    $replacement = is_array($data_array[$keys]) ? $data_array[$keys][$pattren] : " ";
    $xmlstring = str_replace('{' . $pattren . '}', $replacement, $text);
  }
  return $xmlstring;
}

/**
 * 
 * @param object $field_collect
 * @param type $text
 * @param type $keys
 * @return type string
 */
function get_custom_feeds_files_mobile($field_collect = NULL, $text = NULL, $keys, $astro) {
  //$text = str_replace("<item data='multiple'>", "<item>", $text);
  $var_array = get_vars_from_mobile_feed_pattern($text);
  $data_array = get_required_data_field_get_items_mobile($field_collect, $astro);
  foreach ($var_array[1] as $key => $pattren) {
    $replacement = is_array($data_array[$keys]) ? $data_array[$keys][$pattren] : " ";
    $text = str_replace('{' . $pattren . '}', $replacement, $text);
  }
  return $text;
}

/**
 * Get required field for mobile
 * @param object $field_collect
 * @return type array
 */
function get_required_data_field_get_items_mobile($field_collect, $astro) {

  if (is_object($field_collect) && count($field_collect) > 0) {
    foreach ($field_collect->field_service_content[LANGUAGE_NONE] as $key => $val) {
      $field_collection_item = entity_load('field_collection_item', array($val['value']));
      $service_content_date = isset($field_collection_item[$val['value']]->field_service_content_date[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_service_content_date[LANGUAGE_NONE][0]['value'] : '';
      // content date
      if (!empty($service_content_date)) {
        $service_content_date_arr = explode(' ', $service_content_date);
        $required_value[$key]['field_service_content_date'] = date('r', strtotime($service_content_date_arr[0]));
      }
 
      $required_value[$key]['field_client_short_description'] = isset($field_collection_item[$val['value']]->field_client_short_description[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_client_short_description[LANGUAGE_NONE][0]['value'] : '';
      $required_value[$key]['field_story_expert_description'] = isset($field_collection_item[$val['value']]->field_story_expert_description[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_story_expert_description[LANGUAGE_NONE][0]['value'] : '';
      $service_content_image = isset($field_collection_item[$val['value']]->field_story_large_image[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_story_large_image[LANGUAGE_NONE][0]['fid'] : '';
      $service_content_image_desc = isset($field_collection_item[$val['value']]->field_story_large_image[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_story_large_image[LANGUAGE_NONE][0]['alt'] : '';
      $service_content_image_keyword = isset($field_collection_item[$val['value']]->field_story_large_image[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_story_large_image[LANGUAGE_NONE][0]['title'] : '';
      $service_content_audio = isset($field_collection_item[$val['value']]->field_service_audio[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_service_audio[LANGUAGE_NONE][0]['fid'] : '';
      $service_content_audio_desc = isset($field_collection_item[$val['value']]->field_service_audio[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_service_audio[LANGUAGE_NONE][0]['description'] : '';
      $service_content_audio_keyword = isset($field_collection_item[$val['value']]->field_service_audio_keyword[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_service_audio_keyword[LANGUAGE_NONE][0]['value'] : '';
      $service_content_video = isset($field_collection_item[$val['value']]->field_service_video[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_service_video[LANGUAGE_NONE][0]['fid'] : '';
      $service_content_video_desc = isset($field_collection_item[$val['value']]->field_service_video[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_service_video[LANGUAGE_NONE][0]['description'] : '';
      $service_content_video_keyword = isset($field_collection_item[$val['value']]->field_service_video_keyword[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_service_video_keyword[LANGUAGE_NONE][0]['value'] : '';

      // image
      if (!empty($service_content_image)) {
        $image_file = file_load($service_content_image);
        $image_url = file_create_url($image_file->uri);
        $required_value[$key]['field_story_large_image'] = $image = $image_url;
        $required_value[$key]['field_story_large_image_description'] = $service_content_image_desc;
        $required_value[$key]['field_story_large_image_keyword'] = $service_content_image_keyword;
      }

      // audio
      if (!empty($service_content_audio)) {
        $audio_file = file_load($service_content_audio);
        $audio_url = file_create_url($audio_file->uri);
        $required_value[$key]['field_service_audio'] = $audio = $audio_url;
        $required_value[$key]['field_service_audio_description'] = $service_content_audio_desc;
        $required_value[$key]['field_service_audio_keyword'] = $service_content_audio_keyword;
      }

      // video
      if (!empty($service_content_video)) {
        $video_file = file_load($service_content_video);
        $video_url = file_create_url($video_file->uri);
        $required_value[$key]['field_service_video'] = $video_url;
        $required_value[$key]['field_service_video_description'] = $service_content_video_desc;
        $required_value[$key]['field_service_video_keyword'] = $service_content_video_keyword;       
      }

      // astro
      if ($astro) {
        $description = substr($required_value[$key]['field_story_expert_description'], 0, 12);
        $description_array = explode('-', $description);
        $required_value[$key]['field_zodiac'] = trim($description_array[0]);
      }
    }
  }
  return $required_value;
}

/**
 * Generate variables from pattern
 * @param string $text
 * @return array $matches
 */
function get_vars_from_mobile_feed_pattern($text) {
  $matches = array();
  if (isset($text)) {
    preg_match_all('/{(.*?)}/', $text, $matches);
  }
  return $matches;
}
