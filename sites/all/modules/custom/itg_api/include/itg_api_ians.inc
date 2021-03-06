<?php
module_load_include('php', 'itg_videogallery', 'vendor/autoload');

use Aws\S3\S3Client;
use Aws\S3\Exception\S3Exception;
use Aws\Common\Credentials\Credentials;

/**
 * Implement itg_ians_content
 */
function itg_ians_content() {
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
        "Prefix" => 'agencies/ians/'
      ));
      $ians = 1;
      foreach ($objects as $object) {
        //pr($object['Key']);
        $exp = explode('/', $object['Key']);
        $ext = pathinfo($exp[2], PATHINFO_EXTENSION);
        if ($ext == 'xml' && !empty($exp[2])) {
          $xml_file_path = $s3->getObjectUrl($bucket, $object['Key']);

          $file_path = "s3://{$bucket}" . '/' . $exp[0] . '/' . $exp[1] . '/' . $exp[2];
          $xml_filename = basename($file_path);
          $ans_xml = simplexml_load_file($file_path, 'SimpleXMLElement', LIBXML_NOCDATA);
          if (empty(itg_api_get_xml_info($xml_filename))) {
            if (!empty($ans_xml)) {

              foreach ($ans_xml as $ans_value) {
                $headline = trim(htmlentities(strip_tags(trim(preg_replace('/\s+/', ' ', $ans_value->headline)))));

                $category_name = trim(itg_api_get_term_id($ans_value->cats, CATEGORY_MANAGMENT));
                $subcat_name = trim(itg_api_get_term_id($ans_value->subcats, CATEGORY_MANAGMENT));

                if (empty($category_name)) {
                  $category_name = itg_api_get_term_id('IANS', CATEGORY_MANAGMENT);
                }
                else {
                  $category_name = trim(itg_api_get_term_id($ans_value->cats, CATEGORY_MANAGMENT));
                }

                $title = itg_api_check_title($headline);

                if (!$title) {
                  $alchemyapi[$ians] = new AlchemyAPI('cd95bc47470dedf7e5002748636e78848cd0a9f4');
                  $response[$ians] = $alchemyapi[$ians]->keywords('text', $headline, array('sentiment' => 1));
                  $final_keyword = '';
                  if ($response[$ians]['status'] == 'OK') {
                    foreach ($response[$ians]['keywords'] as $keyword) {
                      $final_keyword[] = $keyword['text'];
                    }
                  }
                  else {
                    // echo 'Error in the keyword extraction call: ', $response['statusInfo'];
                    watchdog('IANS Error in the keyword extraction call:', '<pre>' . print_r($response['statusInfo'], true) . '</pre>');
                  }
                  $meta_keyword = implode(", ", $final_keyword);
                  // description
                  $description = '';
                  foreach ($ans_value->content->p as $body_text) {
                    $description .= '<p>' . ucfirst(htmlentities($body_text)) . '</p>';
                  }
                  $description = trim(strip_tags($description, '<p>'));
                  $kicker = $ans_value->summary;
                  $final_kicker = substr($kicker, 0, 200);
                  $final_kicker = $final_kicker . '..';
                  $final_kicker = trim(preg_replace('/[\s\t\n\r\s]+/', ' ', $final_kicker));

                  // get pubdate
                  $publish_date_raw = $ans_value->Publishdate;

                  if (empty($publish_date_raw)) {
                    $publish_date_raw = date('Y-m-d', time());
                  }

                  $publish_date_timestamp = strtotime($publish_date_raw);
                  $publish_date = date('Y-m-d', $publish_date_timestamp);

                  // create expiry date based on publish date 
                  $exp_date = strtotime('+10 years', strtotime($publish_date));
                  $exp_date = date('Y-m-d', $exp_date);

                  // get byline id based on name 
                  $by_line = itg_api_get_nid('IANS', 'reporter');
                  $uniqueid = 'byline_' . uniqid();
                  if (function_exists('itg_custom_byline_create')) {
                    itg_custom_byline_create($uniqueid, $by_line);
                  }

                  $exp_description = strtolower($description);
                  $exp_description = explode(" ", $exp_description);
                  //Set values to node l54,s130
                  $node = new stdClass();
                  $node->title = trim($headline);
                  $node->type = "story";
                  node_object_prepare($node);
                  $node->language = LANGUAGE_NONE;
                  $node->uid = $user->uid;
                  $node->promote = 0;
                  $node->comment = 0;
                  $node->body[$node->language][0]['value'] = $description ? $description : 'NA';
                  $node->body[$node->language][0]['format'] = 'full_html';
                  $node->field_story_long_head_line[LANGUAGE_NONE][0]['value'] = trim($headline);
                  $node->field_story_magazine_headline[LANGUAGE_NONE][0]['value'] = $final_kicker;
                  $node->field_story_short_headline[LANGUAGE_NONE][0]['value'] = trim($headline);
                  $node->metatags[LANGUAGE_NONE]['keywords']['value'] = $meta_keyword;
                  $node->field_story_source_type[LANGUAGE_NONE][0]['value'] = 'IANS';
                  if (!empty($category_name)) {
                    $node->field_story_category[LANGUAGE_NONE][0]['tid'] = $category_name;
                    $node->field_primary_category[LANGUAGE_NONE][0]['value'] = $category_name;
                  }
                  $node->field_story_schedule_date_time[LANGUAGE_NONE][0]['value'] = $publish_date;
                  $node->field_itg_content_publish_date[LANGUAGE_NONE][0]['value'] = $publish_date;
                  $node->field_story_expiry_date[LANGUAGE_NONE][0]['value'] = $exp_date;
                  $node->field_story_type[LANGUAGE_NONE][0]['value'] = 'other_story';
                  $node->field_reporter_unique_id[LANGUAGE_NONE][0]['value'] = trim($uniqueid);
                  if (array_intersect($op, $exp_description)) {
                    $node->log = 'State Changed to Review';
                    $node->workbench_moderation_state_new = workbench_moderation_state_review();
                  }
                  else {
                    $node->workbench_moderation_state_new = workbench_moderation_state_published();
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
                  itg_api_insert_xml_info($node->nid, $xml_filename, 'story', 'IANS');
                  $msg = $headline . ' imported sucessfully';
                  watchdog('IANS_XML', $msg);
                }
                else {
                  $msg = $headline . ' Already imported';
                  watchdog('IANS_XML', $msg);
                }
              }
            }
            if ($ians == variable_get('api_content_limit'))
              break;
            $ians++;
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
