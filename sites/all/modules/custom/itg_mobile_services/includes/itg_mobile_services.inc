<?php

/*
 * Inc file contains the functions
 */

function mobile_services_generator_of_content() {

  $result = get_services_result();

  foreach ($result as $item) {

    $sid = $item->association_service_target_id;
    $content_type = $item->service_content_type;
    $content_count = $item->service_content_count_value;
    $header = $item->header;
    $footer = $item->footer;
    $delivery_mode = $item->delivery_mode_value;
    $frequency = $item->frequency_value;
    $sharing_mode = $item->sharing_mode;


    $query = db_query("SELECT service_association.field_service_association_title_target_id AS association_service_target_id, 
          content_text.entity_id AS content_nid,
content_text.field_story_expert_description_value AS content_text,
content_image.field_story_large_image_fid AS content_image_fid,
content_image.field_story_large_image_width AS content_image_width,
content_image.field_story_large_image_height AS content_image_height
FROM field_data_field_service_association_title service_association 
left join field_data_field_story_expert_description as content_text ON service_association.entity_id = content_text.entity_id
left join field_data_field_story_large_image as content_image ON service_association.entity_id = content_image.entity_id
where service_association.field_service_association_title_target_id = '$sid' AND content_text.entity_id <>  'NULL'")->fetchAll();


    switch ($delivery_mode) {
      case 1:
        // Code for XMLs
        print_xml($query);
        // itg_mobile_services_generate_rss($query);


        break;
      case 2:
        // Code for RSS
        itg_mobile_services_generate_rss($query);
        break;
      case 3:
        // Code for MRSS
        break;
      case 4:
        // Code for USSD
        break;
      case 5:
        // Code for SMS
        break;
      case 6:
        // Code for Simple Text Feed
        break;
    }
  }
}

function get_services_result($client_id, $service_id) {
  // $service_id = '210';
  // $client_id = '2569';

  return $result = db_query("SELECT service_association.field_service_association_title_target_id AS association_service_target_id, 
      service_association.entity_id AS service_nid,
      service_content_type.field_service_content_type_value AS service_content_type,
      service_content_count.field_service_content_count_value AS service_content_count_value,
      service_header.field_header_value AS header,
      service_footer.field_footer_value AS footer,
      service_delivery.field_service_delivery_mode_value AS delivery_mode_value,
      service_frequency.field_service_frequency_value AS frequency_value,
      sharing_mode.field_content_sharing_mode_value AS sharing_mode,
      service_expiry_date.field_story_expiry_date_value,
      client_selection.field_client_selection_target_id AS client_target_id
      FROM field_data_field_service_association_title service_association 
      left join field_data_field_service_content_type as service_content_type ON service_association.entity_id = service_content_type.entity_id
      left join field_data_field_service_content_count as service_content_count ON service_association.entity_id = service_content_count.entity_id
      left join field_data_field_header AS service_header ON service_association.entity_id = service_header.entity_id
      left join field_data_field_footer AS service_footer ON service_association.entity_id = service_footer.entity_id
      left join field_data_field_service_delivery_mode AS service_delivery ON service_association.field_service_association_title_target_id = service_delivery.entity_id
      left join field_data_field_service_frequency AS service_frequency ON service_association.field_service_association_title_target_id = service_frequency.entity_id
      left join field_data_field_content_sharing_mode AS sharing_mode ON service_association.field_service_association_title_target_id = sharing_mode.entity_id
      left join field_data_field_story_expiry_date AS service_expiry_date ON service_association.field_service_association_title_target_id = service_expiry_date.entity_id
      left join field_data_field_client_selection AS client_selection ON service_association.entity_id = client_selection.entity_id
      where service_expiry_date.field_story_expiry_date_value > now() AND client_selection.field_client_selection_target_id = '$client_id' AND service_association.field_service_association_title_target_id = '$service_id'")->fetchAll();
}

function print_xml($query) {

  foreach ($query as $row) {
    //echo "<pre>";
    //print_r($row);
    //echo "</pre>";
    $content_text = $row->content_text;
    $content_image_fid = $row->content_image_fid;
    $content_image_width = $row->content_image_width;
    $content_image_height = $row->content_image_height;

    $short_title1 = "<![CDATA[
Ramdev's business plan: Make Nestle's bird, Colgate's gate disappear
]]>";
    $short_title = "Ramdev's business plan: Make Nestle's bird, Colgate's gate disappear";

    $file_path = drupal_realpath('public://');
    $file_path = '/var/www/html/itgcms/sites/default/files/mobile_xml';
    // $dom = new DOMDocument('1.0','UTF-8');
    // $dom->formatOutput = true;
    $doc = new DOMDocument('1.0', 'UTF-8');
    $doc->formatOutput = true;
    //$doc->preserveWhiteSpace = false;     

    $root = $doc->appendChild($doc->createElement('feed'));
    $root = $doc->appendChild($root);
    $root->appendChild($doc->createElement('provider', 'indiatoday'));
    $root->appendChild($doc->createElement('language', 'en-US'));

    $items = $root->appendChild($doc->createElement('news'));

    $item = $doc->createElement('item');
    $item->appendChild($doc->createElement('id', 'Noodle'));
    $item->appendChild($doc->createCDATASection($short_title));
    $item->appendChild($doc->createCDATASection($short_title));
    $item->appendChild($doc->createElement('publish_date', 'Noodle'));
    $item->appendChild($doc->createElement('last_update', 'Noodle'));
    $item->appendChild($doc->createElement('detail', 'Noodle'));

    $items->appendChild($item);


    $item = $doc->createElement('item');
    $item->appendChild($doc->createElement('name', 'Sausage'));
    $item->appendChild($doc->createElement('age', '3'));
    $items->appendChild($item);
  }
  // echo $doc->saveXML();
  $doc->save($file_path . '/result.xml') or die('XML Create Error');
}

/**
 * Function to generate rss
 * @param array $data
 * @param array $syndication_node
 */
function itg_mobile_services_generate_rss($query) {

// The XML structure

  $data = '<?xml version="1.0"?><rss version="2.0" xmlns:atom="http://www.w3.org/2005/Atom">';
  $data .= '<channel>';
  $data .= '<title>India Today | KARNATAKA NEWS</title>';
  $data .= '<description>India Today</description>';
  $data .= '<link>http://indiatoday.intoday.in/</link>';
  $data .= '<lastBuildDate>Mon, 03 Feb 2014 12:38:02 IST</lastBuildDate>';
  $data .= '<generator>FeedCreator 1.7.2</generator>';
  $data .= '<image>';
  $data .= '<url>http://mobileservice.digitaltoday.in/content/img/rss/karnataka.jpg</url>';
  $data .= '<title>India Today | KARNATAKA NEWS</title>';
  $data .= '<description>India Today</description>';
  $data .= '</image>';

  foreach ($query as $row) {
    $content_text = $row->content_text;
    $short_title = "Ramdev's business plan: Make Nestle's bird, Colgate's gate disappear";

    $file_path = drupal_realpath('public://');
    $file_path = '/var/www/html/itgcms/sites/default/files/mobile_xml';
    $data .= '<item>';
    $data .= '<title>Karnataka team gets Rs 1 crore</title>';
    $data .= '<link>http://indiatoday.intoday.in/</link>';
    $data .= "<description>" . $content_text . "</description>";
    $data .= '<image></image>';
    $data .= '<image></image>';
    $data .= '</item>';
  }
  $data .= '</channel>';
  $data .= '</rss>';
  //$doc->save($file_path.'/result_rss.xml') or die('XML Create Error');   
  // header('Content-Type: application/xml');
  echo $data;
  watchdog('mobile_rss', 'RSS created');
  drupal_set_message('rss file has been created.', 'status');
}

/**
 * Function to generate rss
 * @param array $data
 * @param array $syndication_node
 */
function itg_mobile_services_generate_simple_text($query) {

// The XML structure

  $data .= '<channel>';
  $data .= '<title>India Today | KARNATAKA NEWS</title>';
  $data .= '<description>India Today</description>';
  $data .= '<link>http://indiatoday.intoday.in/</link>';
  $data .= '<lastBuildDate>Mon, 03 Feb 2014 12:38:02 IST</lastBuildDate>';
  $data .= '<generator>FeedCreator 1.7.2</generator>';
  $data .= '<image>';
  $data .= '<url>http://mobileservice.digitaltoday.in/content/img/rss/karnataka.jpg</url>';
  $data .= '<title>India Today | KARNATAKA NEWS</title>';
  $data .= '<description>India Today</description>';
  $data .= '</image>';

  foreach ($query as $row) {
    $content_text = $row->content_text;
    $short_title = "Ramdev's business plan: Make Nestle's bird, Colgate's gate disappear";

    $file_path = drupal_realpath('public://');
    $file_path = '/var/www/html/itgcms/sites/default/files/mobile_xml';
    $data .= '<item>';
    $data .= '<title>Karnataka team gets Rs 1 crore</title>';
    $data .= '<link>http://indiatoday.intoday.in/</link>';
    $data .= "<description>" . $content_text . "</description>";
    $data .= '<image></image>';
    $data .= '<image></image>';
    $data .= '</item>';
  }
  $data .= '</channel>';
  $data .= '</rss>';
  //$doc->save($file_path.'/result_rss.xml') or die('XML Create Error');   
  // header('Content-Type: application/xml');
  echo $data;
  watchdog('mobile_rss', 'RSS created');
  drupal_set_message('rss file has been created.', 'status');
}

function mobile_services_generator_data() {
  $arg = arg();
  //p(arg());
  watchdog("service arg", '<pre>' . print_r($arg, true) . '</pre>');
  if ($arg[1] == 'token' && !empty($arg[2])) {
    $token = base64_decode(arg(2));
    $record = itg_mobile_service_get_client_token($token);
    if (is_array($record) && count($record) > 0) {
      watchdog("check_client_token", '<pre>' . print_r($record, true) . '</pre>');
      $cid = $record['cid'];
      $sid = $record['sid'];

      $delivery_mode = $record['delivery_mode'];
      $service_frequency = $record['service_frequency'];
      $content_sharing_mode = $record['content_sharing_mode'];
      $ftp_ip_address = $record['ftp_ip_address'];
      $ftp_username = $record['ftp_username'];
      $ftp_password = $record['ftp_password'];
      $service_email_address = $record['service_email_address'];
      $service_expiry_date = $record['service_expiry_date'];
    }
  }
//echo $cid . " = " .$sid;
  $result = get_services_result($cid, $sid);
  watchdog("check_service_result", '<pre>' . print_r($result, true) . '</pre>');
  foreach ($result as $item) {

    $sid = $item->association_service_target_id;
    $content_type = $item->service_content_type;
    $content_count = $item->service_content_count_value;
    $header = $item->header;
    $footer = $item->footer;
    $delivery_mode = $item->delivery_mode_value;
    $frequency = $item->frequency_value;
    $sharing_mode = $item->sharing_mode;


    $query = db_query("SELECT service_association.field_service_association_title_target_id AS association_service_target_id, 
          content_text.entity_id AS content_nid,
content_text.field_story_expert_description_value AS content_text,
content_image.field_story_large_image_fid AS content_image_fid,
content_image.field_story_large_image_width AS content_image_width,
content_image.field_story_large_image_height AS content_image_height,
content_audio.field_service_audio_fid AS content_audio_fid,
content_video.field_service_video_fid AS content_video_fid
FROM field_data_field_service_association_title service_association 
left join field_data_field_story_expert_description as content_text ON service_association.entity_id = content_text.entity_id
left join field_data_field_story_large_image as content_image ON service_association.entity_id = content_image.entity_id
left join field_data_field_service_audio as content_audio ON service_association.entity_id = content_audio.entity_id
left join field_data_field_service_video as content_video ON service_association.entity_id = content_video.entity_id
where service_association.field_service_association_title_target_id = '$sid' AND content_text.entity_id <>  'NULL'")->fetchAll();


    // watchdog("check_content_result", $query);

    switch ($delivery_mode) {
      case 1:
        // Code for XMLs
        print_mobile_xml($query);
        // watchdog('print_mobile_xml', $query);

        break;
      case 2:
        // Code for RSS
        print_mobile_rss($query);
        // watchdog('print_mobile_rss', $query);
        break;
      case 3:
        // Code for MRSS
        print_mobile_mrss($query);
        //  watchdog('print_mobile_mrss', $query);
        break;
      case 4:
        // Code for USSD
        print_mobile_ussd($query);
        //  watchdog('print_mobile_ussd', $query);
        break;
      case 5:
        // Code for SMS
        print_mobile_sms($query);
        //  watchdog('print_mobile_sms', $query);
        break;
      case 6:
        // Code for Simple Text Feed
        print_mobile_simple_feed($query);
        //  watchdog('print_mobile_simple_feed', $query);
        break;
    }
  }
}

/**
 * Get check service token by token
 * @param type $token
 *   
 */
function itg_mobile_service_get_client_token($token) {
  $query = db_select('itg_client_token', 't');
  $query->fields('t', array('cid', 'sid', 'delivery_mode', 'service_frequency', 'content_sharing_mode', 'service_fetch_link', 'ftp_ip_address', 'ftp_username', 'ftp_password', 'service_email_address', 'service_expiry_date'));
  $query->condition('t.token', $token, '=');
  $query->range(0, 1);
  $result = $query->execute();
  return $record = $result->fetchAssoc();
}

function print_mobile_xml($query) {

  global $base_url;
  $file_path = drupal_realpath('public://');
  $file_path = $file_path . '/mobile_xml';
  $doc = new DOMDocument('1.0', 'UTF-8');
  $doc->formatOutput = true;
  //$doc->preserveWhiteSpace = false;     

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
}

function print_mobile_rss($query) {
  global $base_url;
  $file_path = drupal_realpath('public://');
  echo $file_path = $file_path . '/mobile_xml';
  //exit;
  $doc = new DOMDocument('1.0', 'UTF-8');
  $doc->formatOutput = true;
  //$doc->preserveWhiteSpace = false;     

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
    $file = file_load($content_image_fid)->filename;
    $items = $root->appendChild($doc->createElement('item'));

    $item = $doc->createElement('image');
    $item->appendChild($doc->createElement('url', $base_url . "/sites/default/files/mobile_image/" . $file));
    $item->appendChild($doc->createElement('title', 'India Today | KARNATAKA NEWS<'));
    $item->appendChild($doc->createElement('description', $content_text));

    $items->appendChild($item);
  }

  $doc->save($file_path . '/result_rss.xml') or die('XML Create Error');
  drupal_goto($base_url . "/sites/default/files/mobile_xml/result_rss.xml");
}

function print_mobile_mrss($query) {
  global $base_url;
  $file_path = drupal_realpath('public://');
  $file_path = $file_path . '/mobile_xml';
  // header("Content-Type: application/rss+xml; charset=UTF-8");
  $doc = new DOMDocument('1.0', 'iso-8859-1');
  $doc->formatOutput = true;
  //$doc->preserveWhiteSpace = false;     

  $root = $doc->appendChild($doc->createElement('rss'));
  $root->setAttribute('version', '2.0');
  $root->setAttribute('xmlns:media', 'http://search.yahoo.com/mrss/');
  $root = $doc->appendChild($root);

  $channel = $root->appendChild($doc->createElement('channel'));
  $channel->appendChild($doc->createElement('title', 'India Today | KARNATAKA NEWS'));
  $channel->appendChild($doc->createElement('link', 'http://indiatoday.intoday.in/'));
  $channel->appendChild($doc->createElement('description', 'India Today'));


  $items = $root->appendChild($doc->createElement('item'));

  foreach ($query as $row) {

    $content_text = $row->content_text;
    $content_image_fid = $row->content_image_fid;
    $content_image_width = $row->content_image_width;
    $content_image_height = $row->content_image_height;

    $content_audio_fid = $row->content_audio_fid;
    $content_video_fid = $row->content_video_fid;

    $file = file_load($content_image_fid)->filename;

    $file_audio = ($content_audio_fid) ? file_load($content_audio_fid) : '';
    $file_video = ($content_video_fid) ? file_load($content_video_fid) : '';

    // $item = $doc->createElement('media');
    if (!empty($file_audio->filename)) {
      $itemaudio = $doc->createElement('media:category');
      $itemaudio->setAttribute('url', $base_url . "/sites/default/files/mobile_image/" . $file_audio->filename);
      $itemaudio->setAttribute('type', $file_audio->filemime);
      //$item->setAttribute('duration', '00:19');
      $itemaudio->appendChild($doc->createElement('media:title', htmlspecialchars('ARIES_27042016')));
      $itemaudio->appendChild($doc->createElement('media:description'));
      $itemaudio->appendChild($doc->createElement('media:thumbnail'));
      $itemaudio->appendChild($doc->createElement('media:keywords'));
      $itemaudio->appendChild($doc->createElement('description', $content_text));

      $items->appendChild($itemaudio);
    }


    // $item = $doc->createElement('media');
    if (!empty($file_video->filename)) {
      $item = $doc->createElement('media:category');
      $item->setAttribute('url', $base_url . "/sites/default/files/mobile_image/" . $file_video->filename);
      $item->setAttribute('type', $file_video->filemime);
      //$item->setAttribute('duration', '00:19');
      $item->appendChild($doc->createElement('media:title', htmlspecialchars('ARIES_27042016')));
      $item->appendChild($doc->createElement('media:description'));
      $item->appendChild($doc->createElement('media:thumbnail'));
      $item->appendChild($doc->createElement('media:keywords'));
      $item->appendChild($doc->createElement('media:category'));
      $item->appendChild($doc->createElement('url', $base_url . "/sites/default/files/mobile_image/" . $file));
      $item->appendChild($doc->createElement('title', 'India Today | KARNATAKA NEWS<'));
      $item->appendChild($doc->createElement('description', $content_text));
      $items->appendChild($item);
    }
  }

  $channel->appendChild($items);
  $doc->save($file_path . '/result_mrss.xml') or die('XML Create Error');
  drupal_goto($base_url . "/sites/default/files/mobile_xml/result_mrss.xml");
}

function print_mobile_sms($query) {
  global $base_url;
  $file_path = drupal_realpath('public://');
  $file_path = $file_path . '/mobile_xml';
  $doc = new DOMDocument('1.0', 'UTF-8');
  $doc->formatOutput = true;
  //$doc->preserveWhiteSpace = false;     

  $root = $doc->appendChild($doc->createElement('data'));
  $root = $doc->appendChild($root);
  $root->appendChild($doc->createElement('keyword', 'indiatoday'));
  $root->appendChild($doc->createElement('timestamp', 'en-US'));
  foreach ($query as $row) {

    $content_text = $row->content_text;
    $item = $doc->createElement('content');
    $item->appendChild($doc->createCDATASection($content_text));
    $root->appendChild($item);
  }
  $root->appendChild($doc->createElement('transid', '31313131'));

  $doc->save($file_path . '/result_sms.xml') or die('XML Create Error');
  // drupal_goto($base_url . "/sites/default/files/mobile_image/result_sms.xml");
  drupal_goto($base_url . "/sites/default/files/mobile_xml/result_sms.xml");
}

function print_mobile_simple_feed($query) {
  global $base_url;
  $file_path = drupal_realpath('public://');
  $file_path = $file_path . '/mobile_xml';

  foreach ($query as $row) {
    $content_text .= $row->content_text;
  }
  print $content_text;
}

function print_mobile_ussd($query) {
  global $base_url;
  $file_path = drupal_realpath('public://');
  $file_path = $file_path . '/mobile_xml';

  foreach ($query as $row) {
    $content_text .= $row->content_text;
  }
  print $content_text;
}

function mobile_services_token_list() {

  $query = db_select('itg_client_token', 't');
  $query->fields('t', array('cid', 'sid', 'delivery_mode', 'service_frequency', 'content_sharing_mode', 'service_fetch_link'));
  $query->range(0, 100);
  $result = $query->execute();
  $table = '<table cellpadding="0" cellspacing="0" width="100%" style="border: 1px;">';
  $table .= '<tbody>';
  $table .= '<tr>';
  $table .= '<th style="width: 96px;">Client Name</th>';
  $table .= '<th style="width: 96px;">Service Name</th>';
  $table .= '<th style="width: 96px;">Link</th>';
  $table .= '</tr>';

  while ($record = $result->fetchAssoc()) {
    $cid = $record['cid'];
    $sid = $record['sid'];
    $service_fetch_link = $record['service_fetch_link'];
    if ($cid) {
      $term = taxonomy_term_load($cid);

      $client_name = $term->name;
    }
    $sname = itg_mobile_services_get_service_title($sid);

    $table .= '<tr>';
    $table .= '<td style="width: 96px;">' . $client_name . '</td>';
    $table .= '<td style="width: 96px;">' . $sname . '</td>';
    $table .= '<td style="width: 96px;">' . $service_fetch_link . '</td>';
    $table .= '</tr>';
  }
  $table .= '</tbody>';
  return $table .= '</table>';
}

/**
 * callback for all the mobile service association of title
 *  
 */
function itg_mobile_services_get_service_title($sid) {

  if ($sid) {
    $content_type = 'service_creation';
    $options = '';
    $title = strtolower(trim($title));
    $query = db_select('node', 'n');
    $query->fields('n', array('title', 'nid'));
    $query->condition('nid', $sid, '=');
    $query->condition('n.type', $content_type, '=');
    //$query->condition('n.status', 1, '=');
    $query->range(0, 1);

    $result = $query->execute();
    $record = $result->fetchAssoc();
    return $record['title'];
  }
}
