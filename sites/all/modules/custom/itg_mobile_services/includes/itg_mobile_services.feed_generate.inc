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
 * @return string
 */
function itg_mobile_services_generate_xml($node, $service_title, $field_header, $field_footer) {
  $doc = new DOMDocument('1.0', 'UTF-8');
  $doc->formatOutput = TRUE;

  $root = $doc->createElement('channel');
  $root = $doc->appendChild($root);
  $root->appendChild($doc->createElement('title', 'India Today | KARNATAKA NEWS'));
  $root->appendChild($doc->createElement('description', 'India Today'));
  $root->appendChild($doc->createElement('link', 'http://indiatoday.intoday.in/'));
  if (!empty($field_header)) {
    $root->appendChild($doc->createElement('header', $field_header));
  }
  if (!empty($field_footer)) {
    $root->appendChild($doc->createElement('footer', $field_footer));
  }
  // content field collection data
  $field_collect = node_load($node->nid);
  if (is_object($field_collect) && count($field_collect) > 0) {
    foreach ($field_collect->field_service_content[LANGUAGE_NONE] as $key => $val) {
      $field_collection_item = entity_load('field_collection_item', array($val['value']));
      $service_content_date = isset($field_collection_item[$val['value']]->field_service_content_date[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_service_content_date[LANGUAGE_NONE][0]['value'] : '';
      $service_content_text = isset($field_collection_item[$val['value']]->field_story_expert_description[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_story_expert_description[LANGUAGE_NONE][0]['value'] : '';
      $service_content_image = isset($field_collection_item[$val['value']]->field_story_large_image[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_story_large_image[LANGUAGE_NONE][0]['fid'] : '';
      $service_content_audio = isset($field_collection_item[$val['value']]->field_service_audio[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_service_audio[LANGUAGE_NONE][0]['fid'] : '';
      $service_content_video = isset($field_collection_item[$val['value']]->field_service_video[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_service_video[LANGUAGE_NONE][0]['fid'] : '';

      $item = $doc->createElement('item');
      $root->appendChild($item);

      // content date
      if (!empty($service_content_date)) {
        $service_content_date_arr = explode(' ', $service_content_date);
        $item->appendChild($doc->createElement('date', $service_content_date_arr[0]));
      }

      // content text
      if (!empty($service_content_text)) {
        $content = $doc->createElement('description');
        $content->appendChild($doc->createCDATASection($service_content_text));
        $item->appendChild($content);
      }

      // image
      if (!empty($service_content_image)) {
        $image_file = file_load($service_content_image);
        $image_url = file_create_url($image_file->uri);
        $image = $doc->createElement('image');
        $image->appendChild($doc->createCDATASection($image_url));
        $item->appendChild($image);
      }

      // audio
      if (!empty($service_content_audio)) {
        $audio_file = file_load($service_content_audio);
        $audio_url = file_create_url($audio_file->uri);
        $audio = $doc->createElement('audio');
        $audio->appendChild($doc->createCDATASection($audio_url));
        $item->appendChild($audio);
      }

      // video
      if (!empty($service_content_video)) {
        $video_file = file_load($service_content_video);
        $video_url = file_create_url($video_file->uri);
        $video = $doc->createElement('video');
        $video->appendChild($doc->createCDATASection($video_url));
        $item->appendChild($video);
      }
    }
  }

  $full_file_path = generate_file_name($node, $service_title, 'xml', 'xml');
  $doc->save($full_file_path) or die('XML Create Error');
  return $full_file_path;
}

/**
 * Function for generating rss files.
 * @param object $node
 * @param string $service_title
 * @param string $field_header
 * @param string $field_footer
 * @return string
 */
function itg_mobile_services_generate_rss($node, $service_title, $field_header, $field_footer) {
  $doc = new DOMDocument('1.0', 'UTF-8');
  $doc->formatOutput = TRUE;
  $root = $doc->createElement('rss');
  $root->setAttribute('version', '2.0');
  $root->setAttribute('xmlns:atom', 'http://www.w3.org/2005/Atom');
  $root = $doc->appendChild($root);

  $channel = $doc->createElement('channel');
  $channel->appendChild($doc->createElement('title', 'India Today | KARNATAKA NEWS'));
  $channel->appendChild($doc->createElement('link', 'http://indiatoday.intoday.in/'));
  $channel->appendChild($doc->createElement('description', 'India Today'));

  if (!empty($field_header)) {
    $channel->appendChild($doc->createElement('header', $field_header));
  }

  if (!empty($field_footer)) {
    $channel->appendChild($doc->createElement('footer', $field_footer));
  }

  $root->appendChild($channel);
  // content field collection data
  $field_collect = node_load($node->nid);
  if (is_object($field_collect) && count($field_collect) > 0) {
    foreach ($field_collect->field_service_content[LANGUAGE_NONE] as $key => $val) {
      $field_collection_item = entity_load('field_collection_item', array($val['value']));
      $service_content_text = isset($field_collection_item[$val['value']]->field_story_expert_description[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_story_expert_description[LANGUAGE_NONE][0]['value'] : '';
      $service_conten_image = isset($field_collection_item[$val['value']]->field_story_large_image[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_story_large_image[LANGUAGE_NONE][0]['fid'] : '';

      $item = $doc->createElement('item');
      $channel->appendChild($item);

      // content date
      if (!empty($service_content_date)) {
        $service_content_date_arr = explode(' ', $service_content_date);
        $item->appendChild($doc->createElement('date', $service_content_date_arr[0]));
      }

      // content text
      if (!empty($service_content_text)) {
        $item->appendChild($doc->createElement('description', $service_content_text));
      }

      // image
      if (!empty($service_conten_image)) {
        $image_file = file_load($service_conten_image);
        $image_url = file_create_url($image_file->uri);
        $item->appendChild($doc->createElement('image', $image_url));
      }
    }
  }

  $full_file_path = generate_file_name($node, $service_title, 'rss', 'xml');
  $doc->save($full_file_path) or die('RSS Create Error');
  return $full_file_path;
}

/**
 * Function for generating mrss files.
 * @param object $node
 * @param string $service_title
 * @param string $field_header
 * @param string $field_footer
 * @return string
 */
function itg_mobile_services_generate_mrss($node, $service_title, $field_header, $field_footer) {
  $doc = new DOMDocument('1.0', 'iso-8859-1');
  $doc->formatOutput = TRUE;
  $root = $doc->createElement('mrss');
  $root->setAttribute('version', '2.0');
  $root->setAttribute('xmlns:media', 'http://search.yahoo.com/mrss/');
  $root = $doc->appendChild($root);

  $channel = $doc->createElement('channel');
  $channel->appendChild($doc->createElement('title', 'India Today | KARNATAKA NEWS'));
  $channel->appendChild($doc->createElement('link', 'http://indiatoday.intoday.in/'));
  $channel->appendChild($doc->createElement('description', 'India Today'));

  if (!empty($field_header)) {
    $channel->appendChild($doc->createElement('header', $field_header));
  }
  if (!empty($field_footer)) {
    $channel->appendChild($doc->createElement('footer', $field_footer));
  }

  $root->appendChild($channel);

  // content field collection data
  $fieldcollect = node_load($node->nid);
  if (is_object($fieldcollect) && count($fieldcollect) > 0) {
    foreach ($fieldcollect->field_service_content[LANGUAGE_NONE] as $key => $val) {
      $field_collection_item = entity_load('field_collection_item', array($val['value']));
      $service_content_date = isset($field_collection_item[$val['value']]->field_service_content_date[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_service_content_date[LANGUAGE_NONE][0]['value'] : '';
      $service_content_text = isset($field_collection_item[$val['value']]->field_story_expert_description[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_story_expert_description[LANGUAGE_NONE][0]['value'] : '';
      $service_conten_image = isset($field_collection_item[$val['value']]->field_story_large_image[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_story_large_image[LANGUAGE_NONE][0]['fid'] : '';
      $service_conten_audio = isset($field_collection_item[$val['value']]->field_service_audio[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_service_audio[LANGUAGE_NONE][0]['fid'] : '';
      $service_conten_video = isset($field_collection_item[$val['value']]->field_service_video[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_service_video[LANGUAGE_NONE][0]['fid'] : '';

      $item = $doc->createElement('item');
      $channel->appendChild($item);

      // content date
      if (!empty($service_content_date)) {
        $service_content_date_arr = explode(' ', $service_content_date);
        $item->appendChild($doc->createElement('date', $service_content_date_arr[0]));
      }

      // content text
      if (!empty($service_content_text)) {
        $item->appendChild($doc->createElement('description', $service_content_text));
      }

      // image
      if (!empty($service_conten_image)) {
        $image_file = file_load($service_conten_image);
        $image_url = file_create_url($image_file->uri);
        $item->appendChild($doc->createElement('image', $image_url));
      }

      // audio
      if (!empty($service_conten_audio)) {
        $audio_file = file_load($service_conten_audio);
        $audio_url = file_create_url($audio_file->uri);
        $item->appendChild($doc->createElement('audio', $audio_url));
      }

      // video
      if (!empty($service_conten_video)) {
        $video_file = file_load($service_conten_video);
        $video_url = file_create_url($video_file->uri);
        $item->appendChild($doc->createElement('video', $video_url));
      }
    }
  }

  $full_file_path = generate_file_name($node, $service_title, 'mrss', 'xml');
  $doc->save($full_file_path) or die('MRSS Create Error');
  return $full_file_path;
}

/**
 * Function for generating sms files.
 * @param object $node
 * @param string $service_title
 * @param string $field_header
 * @param string $field_footer
 * @return string $full_file_path
 */
function itg_mobile_services_generate_sms($node, $service_title, $field_header, $field_footer) {
  $doc = new DOMDocument('1.0', 'UTF-8');
  $doc->formatOutput = TRUE;
  $root = $doc->createElement('rss');
  $root->setAttribute('version', '2.0');
  $root->setAttribute('xmlns:atom', 'http://www.w3.org/2005/Atom');
  $root = $doc->appendChild($root);

  $channel = $doc->createElement('channel');
  $channel->appendChild($doc->createElement('title', 'India Today | KARNATAKA NEWS'));
  $channel->appendChild($doc->createElement('link', 'http://indiatoday.intoday.in/'));
  $channel->appendChild($doc->createElement('description', 'India Today'));

  if (!empty($field_header)) {
    $channel->appendChild($doc->createElement('header', $field_header));
  }
  if (!empty($field_footer)) {
    $channel->appendChild($doc->createElement('footer', $field_footer));
  }

  $root->appendChild($channel);
  // content field collection data
  $field_collect = node_load($node->nid);
  if (is_object($field_collect) && count($field_collect) > 0) {
    foreach ($field_collect->field_service_content[LANGUAGE_NONE] as $key => $val) {
      $field_collection_item = entity_load('field_collection_item', array($val['value']));
      $service_content_text = isset($field_collection_item[$val['value']]->field_story_expert_description[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_story_expert_description[LANGUAGE_NONE][0]['value'] : '';
      $item = $doc->createElement('item');
      $channel->appendChild($item);
      // content date
      if (!empty($service_content_date)) {
        $service_content_date_arr = explode(' ', $service_content_date);
        $item->appendChild($doc->createElement('date', $service_content_date_arr[0]));
      }
      // content text
      if (!empty($service_content_text)) {
        $item->appendChild($doc->createElement('description', $service_content_text));
      }
    }
  }

  $full_file_path = generate_file_name($node, $service_title, 'sms', 'xml');
  $doc->save($full_file_path) or die('SMS Create Error');
  return $full_file_path;
}

/**
 * Function for generating Simple Text Feed.
 * @param object $node
 * @param string $service_title
 * @param string $field_header
 * @param string $field_footer
 * @return string $full_file_path
 */
function itg_mobile_services_generate_feed($node, $service_title, $field_header, $field_footer) {
  $doc = new DOMDocument('1.0', 'UTF-8');
  $doc->formatOutput = TRUE;
  $root = $doc->createElement('rss');
  $root->setAttribute('version', '2.0');
  $root->setAttribute('xmlns:atom', 'http://www.w3.org/2005/Atom');
  $root = $doc->appendChild($root);

  $channel = $doc->createElement('channel');
  $channel->appendChild($doc->createElement('title', 'India Today | KARNATAKA NEWS'));
  $channel->appendChild($doc->createElement('link', 'http://indiatoday.intoday.in/'));
  $channel->appendChild($doc->createElement('description', 'India Today'));

  if (!empty($field_header)) {
    $channel->appendChild($doc->createElement('header', $field_header));
  }
  if (!empty($field_footer)) {
    $channel->appendChild($doc->createElement('footer', $field_footer));
  }

  $root->appendChild($channel);
  // content field collection data
  $field_collect = node_load($node->nid);
  if (is_object($field_collect) && count($field_collect) > 0) {
    foreach ($field_collect->field_service_content[LANGUAGE_NONE] as $key => $val) {
      $field_collection_item = entity_load('field_collection_item', array($val['value']));
      $service_content_text = isset($field_collection_item[$val['value']]->field_story_expert_description[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_story_expert_description[LANGUAGE_NONE][0]['value'] : '';
      $item = $doc->createElement('item');
      $channel->appendChild($item);
      // content date
      if (!empty($service_content_date)) {
        $service_content_date_arr = explode(' ', $service_content_date);
        $item->appendChild($doc->createElement('date', $service_content_date_arr[0]));
      }
      // content text
      if (!empty($service_content_text)) {
        $item->appendChild($doc->createElement('description', $service_content_text));
      }
    }
  }

  $full_file_path = generate_file_name($node, $service_title, 'simple_feed', 'xml');
  $doc->save($full_file_path) or die('Simple feed Create Error');
  return $full_file_path;
}

/**
 * Function for generating ussd files.
 * @param object $node
 * @param string $service_title
 * @param string $field_header
 * @param string $field_footer
 * @return string
 */
function itg_mobile_services_generate_ussd($node, $service_title, $field_header, $field_footer) {
  $doc = new DOMDocument('1.0', 'UTF-8');
  $doc->formatOutput = TRUE;
  $root = $doc->createElement('rss');
  $root->setAttribute('version', '2.0');
  $root->setAttribute('xmlns:atom', 'http://www.w3.org/2005/Atom');
  $root = $doc->appendChild($root);

  $channel = $doc->createElement('channel');
  $channel->appendChild($doc->createElement('title', 'India Today | KARNATAKA NEWS'));
  $channel->appendChild($doc->createElement('link', 'http://indiatoday.intoday.in/'));
  $channel->appendChild($doc->createElement('description', 'India Today'));

  if (!empty($field_header)) {
    $channel->appendChild($doc->createElement('header', $field_header));
  }
  if (!empty($field_footer)) {
    $channel->appendChild($doc->createElement('footer', $field_footer));
  }

  $root->appendChild($channel);
  // content field collection data
  $field_collect = node_load($node->nid);
  if (is_object($field_collect) && count($field_collect) > 0) {
    foreach ($field_collect->field_service_content[LANGUAGE_NONE] as $key => $val) {
      $field_collection_item = entity_load('field_collection_item', array($val['value']));
      $service_content_text = isset($field_collection_item[$val['value']]->field_story_expert_description[LANGUAGE_NONE]) ? $field_collection_item[$val['value']]->field_story_expert_description[LANGUAGE_NONE][0]['value'] : '';
      $item = $doc->createElement('item');
      $channel->appendChild($item);
      // content date
      if (!empty($service_content_date)) {
        $service_content_date_arr = explode(' ', $service_content_date);
        $item->appendChild($doc->createElement('date', $service_content_date_arr[0]));
      }
      // content text
      if (!empty($service_content_text)) {
        $item->appendChild($doc->createElement('description', $service_content_text));
      }
    }
  }

  $full_file_path = generate_file_name($node, $service_title, 'ussd', 'xml');
  $doc->save($full_file_path) or die('USSD Create Error');
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
  $file_path = drupal_realpath('public://');
  $full_file_path = $file_path . '/mobile/' . $service_title . '/' . $feeds_type . $file_name;
  $files_path = $file_path . '/mobile/' . $service_title . '/' . $feeds_type;
  if (!file_exists($files_path)) {
    mkdir($files_path, 0777, TRUE);
  }
  return $full_file_path;
}
