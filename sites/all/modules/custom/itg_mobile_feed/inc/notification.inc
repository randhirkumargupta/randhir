<?php

/*
 * Common function to define the some Primary values
 */

function get_notification_config() {
  $config = array();
  $config['start_index'] = 0;
  $config['end_index'] = 20;
  $config['idsection'] = 1;
  $config['section'] = 'Notifications';
  $config['footersharemsg'] = 'Shared via India Today News App  http://bit.ly/1DBXcjS';
  return $config;
}

//notification?website=aajtak&contentid=11&title=Test Aaj Tak&kicker=Test Kicker&contenttype=test&app_id=12&device=232
function notification_page() {
  $params = drupal_get_query_parameters();
  generate_notification_all($params);
}

/*  Create notification file based on args
 *  And Write data with in the file,
 */

function generate_notification_all($params) {

  $idsection = 1;
  $section = 'Notifications';
  $file_name = '';
  $output = '';
  $app_file_name = '';
  $app_output = '';
  $return_flag .= '';

  $footersharemsg = isset($params['title']) ? $params['title'] : '';
  $website = isset($params['website']) ? $params['website'] : '';
  //Application ID 1-India Today 4-India Today Ipad
  $app_id = isset($params['app_id']) ? $params['app_id'] : '';
  //1 - iOS; 2 - BB; 3 - Android; 4 - Nokia ASHA; 5 - Windows Phone; 7 - OS X; 8 - Windows 8; 9 - Amazon; 10 - Safari; 11 - Chrome
  $device = isset($params['device']) ? $params['device'] : '';
  //defined the path in tidconfig.inc
  $term_feed_path = getcwd() . FEED_NOTIFICATION_PATH;

  //XML Files Generation Based on App Id
  if ($app_id == '4') {

    $app_file_name = 'notification_ipad.xml';
    $app_output .= ipad_notification_xml();
  }
  elseif ($app_id == '1') {
    // XML Files Generation Based on Device Id
    $dev = explode(',', $params['device']);
    foreach ($dev as $dev_id) {
      if ($dev_id == '1') {
        $file_name = 'notification_ios.xml';
        $output .= default_xml_feed();
      }
      elseif ($dev_id == '2') {
        $file_name = 'notification_bb.xml';
        $output = bb_notification_xml();
      }
      elseif ($dev_id == '3') {
        $file_name = 'notification_android.xml';
        $output = default_xml_feed();
      }
      elseif ($dev_id == '4') {
        $file_name = 'notification_nokiaasha.xml';
        $output = nokiaasha_notification_xml();
      }
      elseif ($dev_id == '5') {
        $file_name = 'notification_windowsphone.xml';
        $output = default_xml_feed();
      }
      elseif ($dev_id == '7') {
        $file_name = 'notification_osx.xml';
        $output = osx_notification_xml();
      }
      elseif ($dev_id == '8') {
        $file_name = 'notification_windows8.xml';
        $output = windows8_notification_xml();
      }
      elseif ($dev_id == '9') {
        $file_name = 'notification_amazon.xml';
        $output = amazon_notification_xml();
      }
      elseif ($dev_id == '10') {
        $file_name = 'notification_safari.xml';
        $output = safari_notification_xml();
      }
      elseif ($dev_id == '11') {
        $file_name = 'notification_chrome.xml';
        $output = chrome_notification_xml();
      }
      else {
        
      }

      if ($output && $output != '') {
        $return_flag .= writeFeedFile($term_feed_path, $file_name, $output);
      }
    }
  }

  $default_output = default_xml_feed();
  $default_file_name = 'notification_all.xml';
  $return_flag .= writeFeedFile($term_feed_path, $default_file_name, $default_output);

  if (isset($app_output) && $app_output != '') {
    $return_flag .= writeFeedFile($term_feed_path, $app_file_name, $app_output);
  }
  echo $return_flag;
  die();
}

/* Common Function to get weburl 
 * args nid
 * return string weburl
 */

function get_web_url($nid) {
  global $base_url;
  $alias = drupal_get_path_alias('node/' . $nid . '');
  $weburl = $base_url . "/" . $alias;
  return $weburl;
}

/*
 * Function for getting the xml output for notification_all, android, ios
 */

function default_xml_feed() {

  $totalarticle = count(message_data());
  $config = get_notification_config();

  $output = '';
  $output .= getMobileFeedXmlHeader();
  $output .= "<idsection>" . $config['idsection'] . "</idsection><section>" . $config['section'] . "</section><totalarticle>" . $totalarticle . "</totalarticle><start_index>" . $config['start_index'] . "</start_index><end_index>" . $config['end_index'] . "</end_index><footersharemsg>" . $config['footersharemsg'] . "</footersharemsg>";
  $output .= notifications_article();
  $output .= getMobileFeedXmlFooter();

  return $output;
}

/*
 * Function for getting the Ipad notification Xml Output
 */

function ipad_notification_xml() {

  $all_data = message_data();
  $totalarticle = count($all_data);
  $config = get_notification_config();

  $output = '';
  $output .= getMobileFeedXmlHeader();
  $output .= "<idsection>" . $config['idsection'] . "</idsection><section>" . $config['section'] . "</section><totalarticle>" . $totalarticle . "</totalarticle><start_index>" . $config['start_index'] . "</start_index><end_index>" . $config['end_index'] . "</end_index>";

  if ($totalarticle > 0) {
    foreach ($all_data as $data) {
      $msg_node = node_load($data->content_id);
      $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
      $kicker_image = '';
      $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
      if ($msg_node->type == 'story') {
        $url = 'story' . $msg_node->nid . '.xml';
        generateStoryDetailPageFeed($msg_node->nid);
      }
      elseif ($msg_node->type == 'videogallery') {
        $url = 'video' . $msg_node->nid . '.xml';
        generateVideoDetailPageFeed($msg_node->nid);
      }
      elseif ($msg_node->type == 'photogallery') {
        $url = 'photo' . $msg_node->nid . '.xml';
        generatePhotoDetailPageFeed($msg_node->nid);
      }
      $created_date = format_date($msg_node->created, 'custom', 'M d, Y');
      $created_date_time = format_date($msg_node->created, 'custom', 'Y-m-d H:i:s P');

      if ($data->content_id > 0) {
        $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $kicker_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>";
      }
      else {
        $msg_created_date = format_date(strtotime($data->created_datetime), 'custom', 'M d, Y');
        $msg_created_date_time = format_date(strtotime($data->created_datetime), 'custom', 'Y-m-d H:i:s P');

        $output .= "<article><title><![CDATA[" . $data->message . "]]></title><thumbimage></thumbimage><kickerimage></kickerimage><create_date>" . $msg_created_date . "</create_date><create_datetime>" . $msg_created_date_time . "</create_datetime></article>";
      }
    }
  }
  $output .= getMobileFeedXmlFooter();

  return $output;
}

/*
 * Function for getting the chrome notification Xml Output
 */

function chrome_notification_xml() {

  $all_data = message_data();
  $totalarticle = count($all_data);
  $config = get_notification_config();

  $output = '';
  $output .= getMobileFeedXmlHeader();
  $output .= "<idsection>" . $config['idsection'] . "</idsection><section>" . $config['section'] . "</section><totalarticle>" . $totalarticle . "</totalarticle><start_index>" . $config['start_index'] . "</start_index><end_index>" . $config['end_index'] . "</end_index><footersharemsg>" . $config['footersharemsg'] . "</footersharemsg>";

  if ($totalarticle > 0) {
    foreach ($all_data as $data) {
      $msg_node = node_load($data->content_id);
      $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
      $kicker_image = '';
      $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
      if ($msg_node->type == 'story') {
        $url = 'story' . $msg_node->nid . '.xml';
        generateStoryDetailPageFeed($msg_node->nid);
      }
      elseif ($msg_node->type == 'videogallery') {
        $url = 'video' . $msg_node->nid . '.xml';
        generateVideoDetailPageFeed($msg_node->nid);
      }
      elseif ($msg_node->type == 'photogallery') {
        $url = 'photo' . $msg_node->nid . '.xml';
        generatePhotoDetailPageFeed($msg_node->nid);
      }
      $created_date = format_date($msg_node->created, 'custom', 'M d, Y');
      $created_date_time = format_date($msg_node->created, 'custom', 'Y-m-d H:i:s P');
      if ($data->content_id > 0) {
        $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $kicker_image . "</kickerimage><url>" . $url . "</url><weburl><![CDATA[" . $weburl . "]]></weburl><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>";
      }
      else {
        $msg_created_date = format_date(strtotime($data->created_datetime), 'custom', 'M d, Y');
        $msg_created_date_time = format_date(strtotime($data->created_datetime), 'custom', 'Y-m-d H:i:s P');

        $output .= "<article><title><![CDATA[" . $data->message . "]]></title><thumbimage></thumbimage><kickerimage></kickerimage><url></url><weburl></weburl ><create_date>" . $msg_created_date . "</create_date><create_datetime>" . $msg_created_date_time . "</create_datetime></article>";
      }
    }
  }
  $output .= getMobileFeedXmlFooter();

  return $output;
}

/*
 * Function for getting the safari notification Xml Output
 */

function safari_notification_xml() {

  $all_data = message_data();
  $totalarticle = count($all_data);
  $config = get_notification_config();

  $output = '';
  $output .= getMobileFeedXmlHeader();
  $output .= "<idsection>" . $config['idsection'] . "</idsection><section>" . $config['section'] . "</section><totalarticle>" . $totalarticle . "</totalarticle><start_index>" . $config['start_index'] . "</start_index><end_index>" . $config['end_index'] . "</end_index>";

  if ($totalarticle > 0) {
    foreach ($all_data as $data) {
      $msg_node = node_load($data->content_id);
      $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
      $kicker_image = '';
      $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
      if ($msg_node->type == 'story') {
        $url = 'story' . $msg_node->nid . '.xml';
        generateStoryDetailPageFeed($msg_node->nid);
      }
      elseif ($msg_node->type == 'videogallery') {
        $url = 'video' . $msg_node->nid . '.xml';
        generateVideoDetailPageFeed($msg_node->nid);
      }
      elseif ($msg_node->type == 'photogallery') {
        $url = 'photo' . $msg_node->nid . '.xml';
        generatePhotoDetailPageFeed($msg_node->nid);
      }
      $created_date = format_date($msg_node->created, 'custom', 'M d, Y');
      $created_date_time = format_date($msg_node->created, 'custom', 'Y-m-d H:i:s P');

      if ($data->content_id > 0) {
        $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $kicker_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>";
      }
      else {
        $msg_created_date = format_date(strtotime($data->created_datetime), 'custom', 'M d, Y');
        $msg_created_date_time = format_date(strtotime($data->created_datetime), 'custom', 'Y-m-d H:i:s P');

        $output .= "<article><title><![CDATA[" . $data->message . "]]></title><thumbimage></thumbimage><kickerimage></kickerimage><create_date>" . $msg_created_date . "</create_date><create_datetime>" . $msg_created_date_time . "</create_datetime></article>";
      }
    }
  }

  $output .= getMobileFeedXmlFooter();

  return $output;
}

/*
 * Function for getting the amazon notification Xml Output
 */

function amazon_notification_xml() {

  $all_data = message_data();
  $totalarticle = count($all_data);
  $config = get_notification_config();

  $output = '';
  $output .= getMobileFeedXmlHeader();
  $output .= "<idsection>" . $config['idsection'] . "</idsection><section>" . $config['section'] . "</section><totalarticle>" . $totalarticle . "</totalarticle><start_index>" . $config['start_index'] . "</start_index><end_index>" . $config['end_index'] . "</end_index>";

  if ($totalarticle > 0) {
    foreach ($all_data as $data) {
      $msg_node = node_load($data->content_id);
      $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
      $kicker_image = '';
      $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
      if ($msg_node->type == 'story') {
        $url = 'story' . $msg_node->nid . '.xml';
        generateStoryDetailPageFeed($msg_node->nid);
      }
      elseif ($msg_node->type == 'videogallery') {
        $url = 'video' . $msg_node->nid . '.xml';
        generateVideoDetailPageFeed($msg_node->nid);
      }
      elseif ($msg_node->type == 'photogallery') {
        $url = 'photo' . $msg_node->nid . '.xml';
        generatePhotoDetailPageFeed($msg_node->nid);
      }
      $created_date = format_date($msg_node->created, 'custom', 'M d, Y');
      $created_date_time = format_date($msg_node->created, 'custom', 'Y-m-d H:i:s P');

      if ($data->content_id > 0) {
        $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $kicker_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>";
      }
      else {
        $msg_created_date = format_date(strtotime($data->created_datetime), 'custom', 'M d, Y');
        $msg_created_date_time = format_date(strtotime($data->created_datetime), 'custom', 'Y-m-d H:i:s P');

        $output .= "<article><title><![CDATA[" . $data->message . "]]></title><thumbimage></thumbimage><kickerimage></kickerimage><create_date>" . $msg_created_date . "</create_date><create_datetime>" . $msg_created_date_time . "</create_datetime></article>";
      }
    }
  }
  $output .= getMobileFeedXmlFooter();

  return $output;
}

/*
 * Function for getting the Window 8 notification Xml Output
 */

function windows8_notification_xml() {

  $all_data = message_data();
  $totalarticle = count($all_data);
  $config = get_notification_config();

  $output = '';
  $output .= getMobileFeedXmlHeader();
  $output .= "<idsection>" . $config['idsection'] . "</idsection><section>" . $config['section'] . "</section><totalarticle>" . $totalarticle . "</totalarticle><start_index>" . $config['start_index'] . "</start_index><end_index>" . $config['end_index'] . "</end_index>";

  if ($totalarticle > 0) {
    foreach ($all_data as $data) {
      $msg_node = node_load($data->content_id);
      $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
      $kicker_image = '';
      $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
      if ($msg_node->type == 'story') {
        $url = 'story' . $msg_node->nid . '.xml';
        generateStoryDetailPageFeed($msg_node->nid);
      }
      elseif ($msg_node->type == 'videogallery') {
        $url = 'video' . $msg_node->nid . '.xml';
        generateVideoDetailPageFeed($msg_node->nid);
      }
      elseif ($msg_node->type == 'photogallery') {
        $url = 'photo' . $msg_node->nid . '.xml';
        generatePhotoDetailPageFeed($msg_node->nid);
      }
      $created_date = format_date($msg_node->created, 'custom', 'M d, Y');
      $created_date_time = format_date($msg_node->created, 'custom', 'Y-m-d H:i:s P');

      if ($data->content_id > 0) {
        $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $kicker_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>";
      }
      else {
        $msg_created_date = format_date(strtotime($data->created_datetime), 'custom', 'M d, Y');
        $msg_created_date_time = format_date(strtotime($data->created_datetime), 'custom', 'Y-m-d H:i:s P');

        $output .= "<article><title><![CDATA[" . $data->message . "]]></title><thumbimage></thumbimage><kickerimage></kickerimage><create_date>" . $msg_created_date . "</create_date><create_datetime>" . $msg_created_date_time . "</create_datetime></article>";
      }
    }
  }

  $output .= getMobileFeedXmlFooter();

  return $output;
}

/*
 * Function for getting the osx notification Xml Output
 */

function osx_notification_xml() {

  $all_data = message_data();
  $totalarticle = count($all_data);
  $config = get_notification_config();

  $output = '';
  $output .= getMobileFeedXmlHeader();
  $output .= "<idsection>" . $config['idsection'] . "</idsection><section>" . $config['section'] . "</section><totalarticle>" . $totalarticle . "</totalarticle><start_index>" . $config['start_index'] . "</start_index><end_index>" . $config['end_index'] . "</end_index>";

  if ($totalarticle > 0) {
    foreach ($all_data as $data) {
      $msg_node = node_load($data->content_id);
      $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
      $kicker_image = '';
      $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
      if ($msg_node->type == 'story') {
        $url = 'story' . $msg_node->nid . '.xml';
        generateStoryDetailPageFeed($msg_node->nid);
      }
      elseif ($msg_node->type == 'videogallery') {
        $url = 'video' . $msg_node->nid . '.xml';
        generateVideoDetailPageFeed($msg_node->nid);
      }
      elseif ($msg_node->type == 'photogallery') {
        $url = 'photo' . $msg_node->nid . '.xml';
        generatePhotoDetailPageFeed($msg_node->nid);
      }
      $created_date = format_date($msg_node->created, 'custom', 'M d, Y');
      $created_date_time = format_date($msg_node->created, 'custom', 'Y-m-d H:i:s P');

      if ($data->content_id > 0) {
        $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $kicker_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>";
      }
      else {
        $msg_created_date = format_date(strtotime($data->created_datetime), 'custom', 'M d, Y');
        $msg_created_date_time = format_date(strtotime($data->created_datetime), 'custom', 'Y-m-d H:i:s P');

        $output .= "<article><title><![CDATA[" . $data->message . "]]></title><thumbimage></thumbimage><kickerimage></kickerimage><create_date>" . $msg_created_date . "</create_date><create_datetime>" . $msg_created_date_time . "</create_datetime></article>";
      }
    }
  }

  $output .= getMobileFeedXmlFooter();

  return $output;
}

/*
 * Function for getting the Nokia Asha notification Xml Output
 */

function nokiaasha_notification_xml() {

  $all_data = message_data();
  $totalarticle = count($all_data);
  $config = get_notification_config();

  $output = '';
  $output .= getMobileFeedXmlHeader();
  $output .= "<idsection>" . $config['idsection'] . "</idsection><section>" . $config['section'] . "</section><totalarticle>" . $totalarticle . "</totalarticle><start_index>" . $config['start_index'] . "</start_index><end_index>" . $config['end_index'] . "</end_index>";

  if ($totalarticle > 0) {
    foreach ($all_data as $data) {
      $msg_node = node_load($data->content_id);
      $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
      $kicker_image = '';
      $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
      if ($msg_node->type == 'story') {
        $url = 'story' . $msg_node->nid . '.xml';
        generateStoryDetailPageFeed($msg_node->nid);
      }
      elseif ($msg_node->type == 'videogallery') {
        $url = 'video' . $msg_node->nid . '.xml';
        generateVideoDetailPageFeed($msg_node->nid);
      }
      elseif ($msg_node->type == 'photogallery') {
        $url = 'photo' . $msg_node->nid . '.xml';
        generatePhotoDetailPageFeed($msg_node->nid);
      }
      $created_date = format_date($msg_node->created, 'custom', 'M d, Y');
      $created_date_time = format_date($msg_node->created, 'custom', 'Y-m-d H:i:s P');

      if ($data->content_id > 0) {
        $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $kicker_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>";
      }
      else {
        $msg_created_date = format_date(strtotime($data->created_datetime), 'custom', 'M d, Y');
        $msg_created_date_time = format_date(strtotime($data->created_datetime), 'custom', 'Y-m-d H:i:s P');

        $output .= "<article><title><![CDATA[" . $data->message . "]]></title><thumbimage></thumbimage><kickerimage></kickerimage><create_date>" . $msg_created_date . "</create_date><create_datetime>" . $msg_created_date_time . "</create_datetime></article>";
      }
    }
  }

  $output .= getMobileFeedXmlFooter();

  return $output;
}

/*
 * Function for getting the BB Xml Output
 */

function bb_notification_xml() {

  $all_data = message_data();
  $totalarticle = count($all_data);
  $config = get_notification_config();

  $output = '';
  $output .= getMobileFeedXmlHeader();
  $output .= "<idsection>" . $config['idsection'] . "</idsection><section>" . $config['section'] . "</section><totalarticle>" . $totalarticle . "</totalarticle><start_index>" . $config['start_index'] . "</start_index><end_index>" . $config['end_index'] . "</end_index>";

  if ($totalarticle > 0) {
    foreach ($all_data as $data) {
      $msg_node = node_load($data->content_id);
      $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
      $kicker_image = '';
      $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
      if ($msg_node->type == 'story') {
        $url = 'story' . $msg_node->nid . '.xml';
        generateStoryDetailPageFeed($msg_node->nid);
      }
      elseif ($msg_node->type == 'videogallery') {
        $url = 'video' . $msg_node->nid . '.xml';
        generateVideoDetailPageFeed($msg_node->nid);
      }
      elseif ($msg_node->type == 'photogallery') {
        $url = 'photo' . $msg_node->nid . '.xml';
        generatePhotoDetailPageFeed($msg_node->nid);
      }
      $created_date = format_date($msg_node->created, 'custom', 'M d, Y');
      $created_date_time = format_date($msg_node->created, 'custom', 'Y-m-d H:i:s P');

      if ($data->content_id > 0) {
        $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $kicker_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>";
      }
      else {
        $msg_created_date = format_date(strtotime($data->created_datetime), 'custom', 'M d, Y');
        $msg_created_date_time = format_date(strtotime($data->created_datetime), 'custom', 'Y-m-d H:i:s P');

        $output .= "<article><title><![CDATA[" . $data->message . "]]></title><thumbimage></thumbimage><kickerimage></kickerimage><create_date>" . $msg_created_date . "</create_date><create_datetime>" . $msg_created_date_time . "</create_datetime></article>";
      }
    }
  }
  $output .= getMobileFeedXmlFooter();

  return $output;
}

function notifications_article() {

  $all_data = message_data();

  $totalarticle = count($all_data);
  if ($totalarticle > 0) {
    foreach ($all_data as $data) {
      $msg_node = node_load($data->content_id);

      $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
      $kicker_image = '';
      $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
      $title = isset($msg_node->title) ? $msg_node->title : '';
      if ($msg_node->type == 'story') {
        $url = 'story' . $msg_node->nid . '.xml';
        generateStoryDetailPageFeed($msg_node->nid);
      }
      elseif ($msg_node->type == 'videogallery') {
        $url = 'video' . $msg_node->nid . '.xml';
        generateVideoDetailPageFeed($msg_node->nid);
      }
      elseif ($msg_node->type == 'photogallery') {
        $url = 'photo' . $msg_node->nid . '.xml';
        generatePhotoDetailPageFeed($msg_node->nid);
      }
      $created_date = format_date($msg_node->created, 'custom', 'M d, Y');
      $created_date_time = format_date($msg_node->created, 'custom', 'Y-m-d H:i:s P');

      if ($data->content_id > 0) {
        $output .= "<article><title><![CDATA[" . $title . "]]></title><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $kicker_image . "</kickerimage><url>" . $url . "</url><weburl><![CDATA[" . $weburl . "]]></weburl><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>";
      }
      else {
        $msg_created_date = format_date(strtotime($data->created_datetime), 'custom', 'M d, Y');
        $msg_created_date_time = format_date(strtotime($data->created_datetime), 'custom', 'Y-m-d H:i:s P');

        $output .= "<article><title><![CDATA[" . $data->message . "]]></title><thumbimage></thumbimage><kickerimage></kickerimage><url></url><weburl></weburl><create_date>" . $msg_created_date . "</create_date><create_datetime>" . $msg_created_date_time . "</create_datetime></article>";
      }
      //Attach the node type details
    }
  }
  return $output;
}

function message_data() {
  $config = get_notification_config();
  $params = drupal_get_query_parameters();

  $res = db_select('message', 'm')
          ->fields('m')
          ->condition('m.website', $params['website'])
          ->range($config['start_index'], $config['end_index'])
          ->execute()->fetchAll();
  return $res;
}
