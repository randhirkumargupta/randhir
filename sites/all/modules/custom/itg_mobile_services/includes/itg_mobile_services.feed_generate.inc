<?php

/*
 * Inc file contains the functions
 */

/**
 * Function for generating xml files.
 * @param array $data
 * @param array $syndication_node
 */
function itg_mobile_services_generate_xml($node, $service_title) {

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

      //$root->appendChild($doc->createElement('keyword', 'indiatoday'));
      //$root->appendChild($doc->createElement('timestamp', 'en-US'));
      $item = $doc->createElement('content');
      $item->appendChild($doc->createCDATASection($service_content_text));

      //$root->appendChild($doc->createElement('transid', '31313131'));
      $root->appendChild($item);

      // image
      $image = $doc->createElement('image');
      $image->appendChild($doc->createCDATASection($service_conten_image));
      $root->appendChild($image);

      // audio
      $audio = $doc->createElement('audio');
      $audio->appendChild($doc->createCDATASection($service_conten_audio));
      $root->appendChild($audio);

      // video
      $video = $doc->createElement('video');
      $video->appendChild($doc->createCDATASection($service_conten_video));
      $root->appendChild($video);
    }
  }

  $file_name = generate_file_name($node, $service_title);
  $doc->save($file_path . $file_name) or die('XML Create Error');
  return $file_path . $file_name;

}


/**
 * function to generate_file_name.
 * @param object $node
 * @param type $file_name
 */
function generate_file_name($node, $service_title) {
  $service_frequency = $node->field_service_frequency[LANGUAGE_NONE][0]['value'];
  $frequency_from_arr = explode(' ', $node->field_service_frequency_date[LANGUAGE_NONE][0]['value']);
  $frequency_to_arr = explode(' ', $node->field_service_frequency_date[LANGUAGE_NONE][0]['value2']);
  $frequency_from_date = $frequency_from_arr[0];
  $frequency_to_date = $frequency_to_arr[0];
  switch ($service_frequency) {
    case '1': // daily 
      $file_name = '/daily-' . $service_title . '-' . $frequency_from_date . '-.xml';
      break;
    case '2': // weekly
      $frequency_from_date = $frequency_from_arr[0];
      $frequency_to_date = $frequency_to_arr[0];
      $file_name = '/weekly-' . $service_title . '-' . $frequency_from_date . '-' . $frequency_to_date . '-.xml';
      break;
    case '3': // monthly
      $frequency_from_date = $frequency_from_arr[0];
      $frequency_to_date = $frequency_to_arr[0];
      $file_name = '/monthly-' . $service_title . '-' . $frequency_from_date . '-' . $frequency_to_date . '-.xml';
      break;
  }
  $file_path = drupal_realpath('public://');
  $file_path = $file_path . '/mobile_xml' . $file_name;
  if (file_exists($file_path)) {
    unlink($file_path);
  }
  return $file_name;
}
