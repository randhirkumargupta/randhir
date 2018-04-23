<?php
module_load_include('php', 'itg_videogallery', 'vendor/autoload');

use Aws\S3\S3Client;
use Aws\S3\Exception\S3Exception;
use Aws\Common\Credentials\Credentials;

/**
 * Implement itg_pti_content
 */
function itg_pti_content() {
	$t=time();
	$t = date("Y-m-d H:i:s",$t);
	$msg_t = $t.' Test Message';
	watchdog('PTI Test', $msg_t);
	echo $t."in function check";die;
  if (!empty(variable_get('api_info'))) {
    global $user;
    module_load_include('php', 'itg_api', 'alchemy_api/alchemyapi');

   /* $vocab_id = taxonomy_vocabulary_machine_name_load('bad_words');
    $tax = taxonomy_get_tree($vocab_id->vid, $parent = 0, $max_depth = 1, $load_entities = FALSE);

    foreach ($tax as $key => $val) {
      $op[$val->tid] = strtolower($val->name);
    }*/
    $op = array();
    $bucket = variable_get('api_bucket');
    $aws_access_key = variable_get('aws_access_key');
    $aws_secret_key = variable_get('aws_secret_key');
    $aws_region = variable_get('aws_region');

    $s3 = S3Client::factory(array('key' => $aws_access_key, 'secret' => $aws_secret_key, 'signature' => 'v4', 'region' => $aws_region));
    $s3->registerStreamWrapper();
    try {
      $objects = $s3->getIterator('ListObjects', array(
        'Bucket' => $bucket,
        "Prefix" => 'agencies/pti/'
      ));
      $pti = 1;
      foreach ($objects as $object) {
        $exp = explode('/', $object['Key']);
        $xml_extension = pathinfo(end($exp), PATHINFO_EXTENSION);
        if ($exp[0] == 'agencies' && $exp[1] == 'pti' && $xml_extension == 'xml') {
          if ($exp[2] != 'XmlBhasha' && $exp[2] != 'Complete_xml' && $exp[2] != 'already_imported') {
            $xml_file_path = $s3->getObjectUrl($bucket, $object['Key']);
            if (empty($exp[3])) {
              $file_path = "s3://{$bucket}" . '/' . $exp[0] . '/' . $exp[1] . '/' . $exp[2];
            }
            else {
              $file_path = "s3://{$bucket}" . '/' . $exp[0] . '/' . $exp[1] . '/' . $exp[2] . '/' . $exp[3];
            }
            $xml_filename = basename(trim($file_path));
            $pti_xml = simplexml_load_file($file_path, 'SimpleXMLElement', LIBXML_NOCDATA);
            $row_count = itg_api_get_xml_info($xml_filename);
            if ($row_count == 0) {
              if (!empty($pti_xml)) {
                $pti_body = $pti_xml->channel->item;
                foreach ($pti_body as $pti_value) {

                  $headline = htmlentities(strip_tags(trim(preg_replace('/\s+/', ' ', $pti_value->title))));
                  $title_length = strlen($pti_value->title);

                  $category_name = trim($pti_value->category);

                /*  if (!empty($category_name)) {
                    $category_name = 'PTI feed'; //$category_name;
                  }
                  else {
                    $category_name = 'PTI feed';
                  }

                  $term_id = itg_api_get_term_id($category_name, CATEGORY_MANAGMENT);
                  

                  if (empty($term_id)) {
                    $term_id = itg_api_get_term_id('PTI', CATEGORY_MANAGMENT);
                  }
                  */
                  $term_id = variable_get('pti_section_id');
                  $title = itg_api_check_title($headline);
                  if (!$title) {
                    /*$alchemyapi[$pti] = new AlchemyAPI('cd95bc47470dedf7e5002748636e78848cd0a9f4');
                    $response[$pti] = $alchemyapi[$pti]->keywords('text', $headline, array('sentiment' => 1));
                    $final_keyword = '';
                    if ($response[$pti]['status'] == 'OK') {
                      foreach ($response[$pti]['keywords'] as $keyword) {
                        $final_keyword[] = $keyword['text'];
                      }
                    }
                    else {
                     watchdog('PTI Error in the keyword extraction call:', '<pre>' . print_r($response['statusInfo'], true) . '</pre>');
                    }
                    $meta_keyword = implode(", ", $final_keyword);*/
                    $description = $pti_value->description;
                    $description = trim(strip_tags($description, '<p>'));
                    $body_description = $description;
                    if (preg_match('/[\t]+/', $body_description, $matches)) {
                      $body_description = trim(preg_replace('/[\t]+/', '</p><p>', $body_description));
                    }
                    else {
                      $body_description = preg_replace('/[^(\x20-\x7F)\x0A\x0D]*/', '', $body_description);
                      $body_description = trim(preg_replace('/\s\s+/', '</p><p>', $body_description));
                    }
                    $body_arr = explode('</p><p>', $body_description);
                    $first_para_arr = explode(' ', $body_arr[0]);
                    if (count($first_para_arr) < 5) {
                      $body_arr[0] = $body_arr[0] . ' ' . $body_arr[1];
                      unset($body_arr[1]);
                      $body_arr = array_values($body_arr);
                      $body_description = implode('</p><p>', $body_arr);
                    }
                    else {
                      $body_description = $body_description;
                    }
                    $body_description = '<p>' . $body_description . '</p>';
                    $kicker = substr($description, 0, 200);   
                    $kicker = trim(strip_tags($kicker));
                    $kicker1 = substr($description, 200);
                    $kicker1 = trim(strip_tags($kicker1));
                    $pre_final_kicker = preg_split('/(?<!\d)\.(?!\d)/', $kicker1);
                    $final_kicker = $kicker . ' ' . $pre_final_kicker[0];
                    //$final_kicker = str_replace(array('\'', '"'), '', $final_kicker);
                    $final_kicker = substr($final_kicker, 0, 250);
                    $final_kicker = $final_kicker . '..';
                    $final_kicker = trim(preg_replace('/[\s\t\n\r\s]+/', ' ', $final_kicker));

                    // get pubdate
                    $publish_date_raw = $pti_value->pubdate;
                    if(!empty($publish_date_raw)) {
                      $publish_date_timestamp = strtotime($publish_date_raw);
                    } else {
                      $publish_date_timestamp = time();
                    }
                    $publish_date = date('Y-m-d', $publish_date_timestamp);

                    // create expiry date based on publish date 
                    $exp_date = strtotime('+10 years', strtotime($publish_date));
                    $exp_date = date('Y-m-d', $exp_date);

                    // get byline id based on name 
                    $by_line = itg_api_get_nid('PTI', 'reporter');
                    $uniqueid = 'byline_' . uniqid();
                    if (function_exists('itg_custom_byline_create')) {
                      itg_custom_byline_create($uniqueid, $by_line);
                    }
                    //Set values to node
                    $headline_flag = FALSE;
                    $full_headline = '';
                    $headline = stripInvalidXml($headline);
                    $headline_len = strlen($headline);
                    if ($headline_len >= 250) {
                      $full_headline = $headline;
                      $headline = substr($headline, 0, 250);
                      $headline_flag = TRUE;
                    }
                    $node = new stdClass();
                    $node->title = trim($headline);
                    $node->type = "story";
                    //node_object_prepare($node);
                    $node->language = LANGUAGE_NONE;
                    $node->uid = ADMINISTRATOR;
                    $node->promote = 0;
                    $node->comment = 0;
                    $node->revision = 1;
                    $node->body[$node->language][0]['value'] = $body_description ? $body_description : '';
                    $node->body[$node->language][0]['format'] = 'full_html';
                    $node->field_story_long_head_line[LANGUAGE_NONE][0]['value'] = trim($headline);
                    //$node->field_story_magazine_headline[LANGUAGE_NONE][0]['value'] = $final_kicker;
                    $node->field_story_short_headline[LANGUAGE_NONE][0]['value'] = trim($headline);
                    if ($headline_flag) {
                      $node->field_story_kicker_text[LANGUAGE_NONE][0]['value'] = trim($full_headline);
                    }
                    //$node->metatags[LANGUAGE_NONE]['keywords']['value'] = $meta_keyword;
                    $node->field_story_source_type[LANGUAGE_NONE][0]['value'] = 'PTI';
                    if (!empty($term_id)) {
                      $node->field_story_category[LANGUAGE_NONE][0]['tid'] = $term_id;
                      $node->field_primary_category[LANGUAGE_NONE][0]['value'] = $term_id;
                    }
                    $node->field_story_schedule_date_time[LANGUAGE_NONE][0]['value'] = $publish_date ? $publish_date : date('Y-m-d', time());
                    $node->field_itg_content_publish_date[LANGUAGE_NONE][0]['value'] = $publish_date ? $publish_date : date('Y-m-d', time());
                    $node->field_story_expiry_date[LANGUAGE_NONE][0]['value'] = $exp_date;
                    $node->field_story_type[LANGUAGE_NONE][0]['value'] = 'other_story';
                    $node->field_reporter_unique_id[LANGUAGE_NONE][0]['value'] = trim($uniqueid);
                    // Attach random image to PTI Story
                    $file_name_arr = array('latest-news.jpg', 'news-flash.jpg', 'news-update.jpg');
                    $k = array_rand($file_name_arr);
                    $filename = $file_name_arr[$k];
                    $image = file_get_contents(file_create_url('public://'.$filename));
                    $file = file_save_data($image, 'public://' . $filename, FILE_EXISTS_REPLACE);
                    $node->field_story_extra_large_image = array(LANGUAGE_NONE => array('0' => (array)$file));
                    // Attach random image to PTI Story
                    $exp_description = strtolower($description);
                    $exp_headline = strtolower($headline);
                    $exp_xml_filename = strtolower($xml_filename);
                    $exp_description = explode(" ", $exp_description);
                    $f3_filename = substr($exp_xml_filename, 0, 3);
                    $exclude_word = array('embargoed', 'ap', 'afp', 'dpa');
                    if (array_intersect($op, $exp_description)) {
                      $node->log = 'State Changed to Review';
                      $node->workbench_moderation_state_new = workbench_moderation_state_review();
                    }
                    else if (array_intersect($exclude_word, $exp_description)) {
                      $node->log = 'State Changed to Review';
                      $node->workbench_moderation_state_new = workbench_moderation_state_review();
                    }
                    else if (preg_match('/embargoed/', $exp_headline)) {
                      $node->log = 'State Changed to Review';
                      $node->workbench_moderation_state_new = workbench_moderation_state_review();
                    }
                    else if (preg_match('/newsalert/', $exp_headline)) {
                      $node->log = 'State Changed to Review';
                      $node->workbench_moderation_state_new = workbench_moderation_state_review();
                    }
                    else if (preg_match('/reopens/', $exp_headline)) {
                      $node->log = 'State Changed to Review';
                      $node->workbench_moderation_state_new = workbench_moderation_state_review();
                    }
                    else if ($f3_filename == 'pwr') {
                      $node->log = 'State Changed to Review';
                      $node->workbench_moderation_state_new = workbench_moderation_state_review();
                    }
                    else if (preg_match('/newsalert/', $exp_xml_filename)) {
                      $node->log = 'State Changed to Review';
                      $node->workbench_moderation_state_new = workbench_moderation_state_review();
                    }
                    else if (preg_match('/reopens/', $exp_xml_filename)) {
                      $node->log = 'State Changed to Review';
                      $node->workbench_moderation_state_new = workbench_moderation_state_review();
                    }
                    else {
                      if (($title_length < 15) || ($headline_flag)) {
                        $node->log = 'State Changed to Review';
                        $node->workbench_moderation_state_new = workbench_moderation_state_review();
                      }
                      else {
                        $node->log = 'State Changed to published';
                        //$node->workbench_moderation_state_new = workbench_moderation_state_published();
                        workbench_moderation_moderate($node, 'published');
                      }
                    }
                    //$node = node_submit($node); // Prepare node for saving
                    $node->created = $publish_date_timestamp;
                    node_save($node); // Finally save node
                    db_update('node') // Table name no longer needs {}
                        ->fields(array(
                          'changed' => $publish_date_timestamp,
                        ))
                        ->condition('nid', $node->nid, '=')
                        ->execute();
                    
                      db_update('node_revision') // Table name no longer needs {}
                        ->fields(array(
                          'timestamp' => $publish_date_timestamp,
                        ))
                        ->condition('nid', $node->nid, '=')
                        ->condition('vid', $node->vid, '=')      
                        ->execute();
                  /*  $newpath = itg_api_path_insert($node);
                    $path = array(
                      'source' => "node/{$node->nid}",
                      'alias' => $newpath, // Any alias that you want to set.
                    );
                    path_save($path);*/
                    itg_api_insert_xml_info($node->nid, $xml_filename, 'story', 'PTI');
                    // move xml files/
                    $complete_folder_path = "s3://{$bucket}".'/agencies/pti/Complete_xml/';
                    if (copy($file_path, $complete_folder_path.$xml_filename)) {
                      unlink($file_path);
                    }
                    $msg = $headline . ' imported sucessfully';
                    watchdog('PTI_XML', $msg);
//                    if ($pti == variable_get('api_content_limit'))
//                    break;
//                  $pti++;
                  }
                  else {
                   $complete_folder_path = "s3://{$bucket}".'/agencies/pti/already_imported/';
                    if (copy($file_path, $complete_folder_path.$xml_filename)) {
                      unlink($file_path);
                    }
                    $msg = $headline . ' Already imported';
                    watchdog('PTI_XML', $msg);
                  }
                }
              }
            }
            else{
              $msg2 = 'Filename '. $xml_filename . ' is exist in DB';
              watchdog('PTI_XML', $msg2);
            }
          }
        }
      }
    }
    catch (S3Exception $e) {
      echo $e->getMessage() . "\n";
    }
  }
  else {
    watchdog('Agency_configuration_warning', 'Enable agency feed from configuration');
  }
}

/**
 * Function for Deleting One day old Pti XML from S3 Bucket.
 * @global type $user
 */
function itg_delete_pti_old_xml() {
  if (!empty(variable_get('api_info'))) {    
    // Delete Data From DB.	
    if (!empty(get_itg_variable('delete_pti_xmlfile_days'))) {
      $days = get_itg_variable('delete_pti_xmlfile_days');
      $days = '-' . $days . ' day';
      $db_delete_date = date('Y-m-d', strtotime($days));
      $num_deleted = db_delete('itg_api_xml_info')
          ->condition('source', 'PTI')
          ->where("(DATE_FORMAT(created, '%Y-%m-%d') <= :filter_date)", array(':filter_date' => $db_delete_date))
          ->execute();
    }
    //Delete Data from S3 Bucket.
    $delete_date = date('Y-m-d', strtotime(' -1 day'));
    $deleted = 0;
    $not_deleted = 0;
    $op = array();
    $bucket = variable_get('api_bucket');
    $aws_access_key = variable_get('aws_access_key');
    $aws_secret_key = variable_get('aws_secret_key');
    $aws_region = variable_get('aws_region');
    $s3 = S3Client::factory(array('key' => $aws_access_key, 'secret' => $aws_secret_key, 'signature' => 'v4', 'region' => $aws_region));
    $s3->registerStreamWrapper();
    try {
      $objects = $s3->getIterator('ListObjects', array(
        'Bucket' => $bucket,
        "Prefix" => 'agencies/pti/'
      ));
      foreach ($objects as $object) {
        $exp = explode('/', $object['Key']);
        $xml_extension = pathinfo(end($exp), PATHINFO_EXTENSION);
        if ($exp[0] == 'agencies' && $exp[1] == 'pti' && $xml_extension == 'xml') {
          if ($exp[2] != 'XmlBhasha' && $exp[2] != 'Complete_xml' && $exp[2] != 'already_imported') {
            $xml_file_path = $s3->getObjectUrl($bucket, $object['Key']);
            if (empty($exp[3])) {
              $file_path = "s3://{$bucket}" . '/' . $exp[0] . '/' . $exp[1] . '/' . $exp[2];
            }
            else {
              $file_path = "s3://{$bucket}" . '/' . $exp[0] . '/' . $exp[1] . '/' . $exp[2] . '/' . $exp[3];
            }
            $file_time = filemtime($file_path);
            $file_date = gmdate('Y-m-d', $file_time);
            if ((!empty($file_date)) && ($file_date == $delete_date)) {
              $unlink_return = unlink($file_path);
              if ($unlink_return) {
                $deleted++;
              }
              else {
                $not_deleted++;
              }
            }
          }
        }
      }

      $msg = $deleted . ' of Date ' . $delete_date . ' Deleted sucessfully';
      watchdog('PTI_DELETE_XML', $msg);
      $msg1 = $not_deleted . ' of Date ' . $delete_date . ' Not Deleted sucessfully';
      watchdog('PTI_DELETE_XML', $msg1);
      echo "Deleted" . $deleted . " Not Deleted" . $not_deleted;
    }
    catch (S3Exception $e) {
      echo $e->getMessage() . "\n";
    }    
  }
  else {
    watchdog('Agency_configuration_warning', 'Enable agency feed from configuration');
  }
}
