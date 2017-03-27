<?php

/**
 * Implement itg_api_mail_today_content
 */
function itg_api_mail_today_content() {
  $file_path = drupal_realpath('public://');
  global $user;
  module_load_include('php', 'itg_api', 'alchemy_api/alchemyapi');

  $vocab_id = taxonomy_vocabulary_machine_name_load('bad_words');
  $tax = taxonomy_get_tree($vocab_id->vid, $parent = 0, $max_depth = 1, $load_entities = FALSE);

  foreach ($tax as $key => $val) {
    $op[$val->tid] = $val->name;
  }

  //$direc = get_dir_content($file_path . '/feeds/mailtoday/');
  $final_dir = getcwd() . '/sites/all/modules/custom/itg_api/feeds/mailtoday/';
  $direc = get_dir_content($final_dir);

  foreach ($direc as $xm_file) {

    $xml_file_path = $xm_file;
    $xml_filename = basename($xml_file_path);
    $mail_today_xml = simplexml_load_file($xml_file_path, 'SimpleXMLElement', LIBXML_NOCDATA);
    if (empty(itg_api_get_xml_info($xml_filename))) {
      if (!empty($mail_today_xml)) {
        $i = 0;
        foreach ($mail_today_xml as $value) {
          $headline = htmlentities(strip_tags(trim(preg_replace('/\s+/', ' ', $value->Headline))));
          $category_name = trim($value->ArticleName);

          if (!empty($category_name)) {
            $category_name = $category_name;
          }
          else {
            $category_name = 'Mail Today';
          }

          $term_id = itg_api_get_term_id($category_name, CATEGORY_MANAGMENT);
          if (empty($term_id)) {
            $term_id = itg_api_get_term_id('Mail Today', CATEGORY_MANAGMENT);
          }

          $title = itg_api_check_title($headline);
          if (!$title) {
            $alchemyapi[$i] = new AlchemyAPI('cd95bc47470dedf7e5002748636e78848cd0a9f4');
            $response[$i] = $alchemyapi[$i]->keywords('text', $headline, array('sentiment' => 1));
            $final_keyword = '';
            if ($response[$i]['status'] == 'OK') {
              foreach ($response[$i]['keywords'] as $keyword) {
                $final_keyword[] = $keyword['text'];
              }
            }
            else {
              echo 'Error in the keyword extraction call: ', $response['statusInfo'];
            }
            $meta_keyword = implode(", ", $final_keyword);
            $description = $value->Bodytext->Bodytext;
            $description = strip_tags($description, '<p>');
            $description = trim($description);
            $kicker = substr($description, 0, 200);
            $kicker = strip_tags($kicker);
            $kicker = trim($kicker);
            $kicker1 = substr($description, 200);
            $kicker1 = strip_tags($kicker1);
            $pre_final_kicker = preg_split('/(?<!\d)\.(?!\d)/', $kicker1);
            $final_kicker = $kicker . ' ' . $pre_final_kicker[0];
            $final_kicker = str_replace(array('\'', '"'), '', $final_kicker);
            $final_kicker = substr($final_kicker, 0, 250);
            $final_kicker = $final_kicker . '..';
            $final_kicker = trim(preg_replace('/[\s\t\n\r\s]+/', ' ', $final_kicker));

            $publish_date_raw = $value->Publishdate;
            $publish_date_timestamp = strtotime($publish_date_raw);
            $publish_date = date('Y-m-d', $publish_date_timestamp);

            // create expiry date based on publish date 
            $exp_date = strtotime('+10 years', strtotime($publish_date));
            $exp_date = date('Y-m-d', $exp_date);

            // get byline id based on name 
            $by_line = itg_api_get_nid('mail today', 'reporter');
            $uniqueid = 'byline_' . uniqid();
            if (function_exists('itg_custom_byline_create')) {
              itg_custom_byline_create($uniqueid, $by_line);
            }

            $exp_description = strtolower($description);
            $exp_description = explode(" ", $exp_description);

            // Set values to node l54,s130
            $node = new stdClass();
            $node->title = trim(html_entity_decode($headline));
            $node->type = "story";
            node_object_prepare($node);
            $node->language = LANGUAGE_NONE;
            $node->uid = $user->uid;
            $node->promote = 0;
            $node->comment = 0;
            $node->body[$node->language][0]['value'] = $description ? $description : 'NA';
            $node->body[$node->language][0]['format'] = 'full_html';
            $node->field_story_long_head_line[LANGUAGE_NONE][0]['value'] = trim(html_entity_decode($headline));
            $node->field_story_magazine_kicker_text[LANGUAGE_NONE][0]['value'] = $final_kicker;
            $node->field_story_short_headline[LANGUAGE_NONE][0]['value'] = trim(html_entity_decode($headline));
            $node->metatags[LANGUAGE_NONE]['keywords']['value'] = $meta_keyword;
            $node->field_story_source_type[LANGUAGE_NONE][0]['value'] = 'Mail Today';
            if (!empty($node->field_story_reporter[LANGUAGE_NONE][0]['target_id'])) {
              $node->field_story_reporter[LANGUAGE_NONE][0]['target_id'] = $by_line;
            }
            if (!empty($term_id)) {
              $node->field_story_category[LANGUAGE_NONE][0]['tid'] = $term_id;
            }
            $node->field_story_schedule_date_time[LANGUAGE_NONE][0]['value'] = $publish_date ? $publish_date : date('Y-m-d', time());
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
            node_save($node); // Finally save node
            itg_api_insert_xml_info($node->nid, $xml_filename, 'story', 'Mail Today');
            $msg = $headline . ' imported sucessfully';
            watchdog('MAIL_TODAY_XML', $msg);
          }
          else {
            $msg = $headline . ' Already imported';
            watchdog('MAIL_TODAY_XML', $msg);
          }

          if ($i == 10)
            break;
          $i++;
        }
      }
    }
  }
}
