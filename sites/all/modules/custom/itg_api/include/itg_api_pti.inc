<?php
module_load_include('php', 'itg_videogallery', 'vendor/autoload');

use Aws\S3\S3Client;
use Aws\S3\Exception\S3Exception;
use Aws\Common\Credentials\Credentials;

/**
 * Implement itg_pti_content
 */
function itg_pti_content() {
  if (!empty(variable_get('api_info'))) {
    global $user;
    module_load_include('php', 'itg_api', 'alchemy_api/alchemyapi');

    $vocab_id = taxonomy_vocabulary_machine_name_load('bad_words');
    $tax = taxonomy_get_tree($vocab_id->vid, $parent = 0, $max_depth = 1, $load_entities = FALSE);

    foreach ($tax as $key => $val) {
      $op[$val->tid] = strtolower($val->name);
    }
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
          if ($exp[2] != 'XmlBhasha') {
            $xml_file_path = $s3->getObjectUrl($bucket, $object['Key']);
            if (empty($exp[3])) {
              $file_path = "s3://{$bucket}" . '/' . $exp[0] . '/' . $exp[1] . '/' . $exp[2];
            }
            else {
              $file_path = "s3://{$bucket}" . '/' . $exp[0] . '/' . $exp[1] . '/' . $exp[2] . '/' . $exp[3];
            }
            $xml_filename = basename(trim($file_path));
            $pti_xml = simplexml_load_file($file_path, 'SimpleXMLElement', LIBXML_NOCDATA);

            if (empty(itg_api_get_xml_info($xml_filename))) {
              if (!empty($pti_xml)) {
                $pti_body = $pti_xml->channel->item;
                foreach ($pti_body as $pti_value) {

                  $headline = htmlentities(strip_tags(trim(preg_replace('/\s+/', ' ', $pti_value->title))));
                  $title_length = strlen($pti_value->title);

                  $category_name = trim($pti_value->category);

                  if (!empty($category_name)) {
                    $category_name = 'PTI feed'; //$category_name;
                  }
                  else {
                    $category_name = 'PTI feed';
                  }

                  $term_id = itg_api_get_term_id($category_name, CATEGORY_MANAGMENT);

                  if (empty($term_id)) {
                    $term_id = itg_api_get_term_id('PTI', CATEGORY_MANAGMENT);
                  }

                  $title = itg_api_check_title($headline);
                  if (!$title) {
                    $alchemyapi[$pti] = new AlchemyAPI('cd95bc47470dedf7e5002748636e78848cd0a9f4');
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
                    $meta_keyword = implode(", ", $final_keyword);
                    $description = $pti_value->description;
                    $description = trim(strip_tags($description, '<p>'));
                    $body_description = '<p>'.$description.'</p>';
                    $body_description = str_replace('\\t', '</p><p>', $body_description);
                    $kicker = substr($description, 0, 200);
                    $kicker = trim(strip_tags($kicker));
                    $kicker1 = substr($description, 200);
                    $kicker1 = trim(strip_tags($kicker1));
                    $pre_final_kicker = preg_split('/(?<!\d)\.(?!\d)/', $kicker1);
                    $final_kicker = $kicker . ' ' . $pre_final_kicker[0];
                    $final_kicker = str_replace(array('\'', '"'), '', $final_kicker);
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
                    $node = new stdClass();
                    $node->title = trim(html_entity_decode($headline));
                    $node->type = "story";
                    node_object_prepare($node);
                    $node->language = LANGUAGE_NONE;
                    $node->uid = ADMINISTRATOR;
                    $node->promote = 0;
                    $node->comment = 0;
                    $node->body[$node->language][0]['value'] = $body_description ? $body_description : '';
                    $node->body[$node->language][0]['format'] = 'full_html';
                    $node->field_story_long_head_line[LANGUAGE_NONE][0]['value'] = trim(html_entity_decode($headline));
                    $node->field_story_magazine_headline[LANGUAGE_NONE][0]['value'] = $final_kicker;
                    $node->field_story_short_headline[LANGUAGE_NONE][0]['value'] = trim(html_entity_decode($headline));
                    $node->metatags[LANGUAGE_NONE]['keywords']['value'] = $meta_keyword;
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
                    $exp_description = strtolower($description);
                    $exp_description = explode(" ", $exp_description);
                    $exclude_word = array('embargoed', 'ap', 'afp', 'dpa');
                    if (array_intersect($op, $exp_description)) {
                      $node->log = 'State Changed to Review';
                      $node->workbench_moderation_state_new = workbench_moderation_state_review();
                    }
                    else if (array_intersect($exclude_word, $exp_description)) {
                      $node->log = 'State Changed to Review';
                      $node->workbench_moderation_state_new = workbench_moderation_state_review();
                    }
                    else if (preg_match('/embargoed/', $headline)) {
                      $node->log = 'State Changed to Review';
                      $node->workbench_moderation_state_new = workbench_moderation_state_review();
                    }
                    else if (preg_match('/pwr/', $xml_filename)) {
                      $node->log = 'State Changed to Review';
                      $node->workbench_moderation_state_new = workbench_moderation_state_review();
                    }
                    else {
                      if ($title_length > 15) {
                        $node->log = 'State Changed to published';
                        $node->workbench_moderation_state_new = workbench_moderation_state_published();
                      }

                      if ($title_length < 15) {
                        $node->log = 'State Changed to Review';
                        $node->workbench_moderation_state_new = workbench_moderation_state_review();
                      }
                    }
                    $node = node_submit($node); // Prepare node for saving
                    $node->created = $publish_date_timestamp;
                    node_save($node); // Finally save node
                    $newpath = itg_api_path_insert($node);
                    $path = array(
                      'source' => "node/{$node->nid}",
                      'alias' => $newpath, // Any alias that you want to set.
                    );
                    path_save($path);
                    itg_api_insert_xml_info($node->nid, $xml_filename, 'story', 'PTI');
                    $msg = $headline . ' imported sucessfully';
                    watchdog('PTI_XML', $msg);
                  }
                  else {
                    $msg = $headline . ' Already imported';
                    watchdog('PTI_XML', $msg);
                  }
                }
              }
              if ($pti == variable_get('api_content_limit'))
                break;
              $pti++;
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
