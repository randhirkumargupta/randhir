<?php

/**
 * Implement itg_ap_content
 */
function itg_ap_content() {
  $file_path = drupal_realpath('public://');
  global $user;
  module_load_include('php', 'itg_api', 'alchemy_api/alchemyapi');
  $vocab_id = taxonomy_vocabulary_machine_name_load('bad_words');
  $tax = taxonomy_get_tree($vocab_id->vid, $parent = 0, $max_depth = 1, $load_entities = FALSE);

  foreach ($tax as $key => $val) {
    $op[$val->tid] = $val->name;
  }


  //$direc = get_dir_content($file_path . '/feeds/ap/');
  $final_dir = getcwd() . '/sites/all/modules/custom/itg_api/feeds/ap/';
  $direc = get_dir_content($final_dir);

  foreach ($direc as $xm_file) {

    $xml_file_path = $xm_file;
    $xml_filename = basename($xml_file_path);
    $ap_xml = simplexml_load_file($xml_file_path, 'SimpleXMLElement', LIBXML_NOCDATA);
    if (empty(itg_api_get_xml_info($xml_filename))) {
      if (!empty($ap_xml)) {
        $ap = 0;

        $xml_body = $ap_xml->content->nitf->body;

        foreach ($xml_body as $ap_value) {

          $headline = htmlentities(strip_tags(trim(preg_replace('/\s+/', ' ', $ap_value->{'body.head'}->hedline->hl1))));
          $original_headline = htmlentities(strip_tags(trim(preg_replace('/\s+/', ' ', $ap_value->{'body.head'}->hedline->hl2))));
          $category_name = trim(itg_api_get_term_id('AP', CATEGORY_MANAGMENT));

          $by_line = itg_api_get_nid($ap_value->{'body.head'}->byline, 'reporter');

          if (empty($by_line)) {
            $by_line = itg_api_get_nid('AP', 'reporter');
          }

          $uniqueid = 'byline_' . uniqid();
          if (function_exists('itg_custom_byline_create')) {
            itg_custom_byline_create($uniqueid, $by_line);
          }
          $description = '';
          foreach ($ap_value->{'body.content'}->block->p as $body_text) {
            $description .= '<p>' . ucfirst(htmlentities($body_text)) . '</p>';
          }

          $title = itg_api_check_title($headline);

          if (!$title) {
            $alchemyapi[$ap] = new AlchemyAPI('cd95bc47470dedf7e5002748636e78848cd0a9f4');
            $response[$ap] = $alchemyapi[$ap]->keywords('text', $headline, array('sentiment' => 1));
            $final_keyword = '';
            if ($response[$ap]['status'] == 'OK') {
              foreach ($response[$ap]['keywords'] as $keyword) {

                $final_keyword[] = $keyword['text'];
              }
            }
            else {
              echo 'Error in the keyword extraction call: ', $response['statusInfo'];
            }
            $meta_keyword = implode(", ", $final_keyword);
            $description = strip_tags($description, '<p>');
            $description = trim($description);
            $kicker = substr($description, 0, 200);
            $kicker = trim(strip_tags($kicker));
            $kicker1 = substr($description, 200);
            $pre_final_kicker = preg_split('/(?<!\d)\.(?!\d)/', $kicker1);
            $final_kicker = $kicker . ' ' . $pre_final_kicker[0];
            $final_kicker = str_replace(array('\'', '"'), '', $final_kicker);
            $final_kicker = substr($final_kicker, 0, 250);
            $final_kicker = $final_kicker . '..';
            $final_kicker = trim(preg_replace('/[\s\t\n\r\s]+/', ' ', $final_kicker));
            $publish_date_raw = date('Y-m-d', time());
            $publish_date_timestamp = strtotime($publish_date_raw);
            $publish_date = date('Y-m-d', $publish_date_timestamp);
            $exp_date = strtotime('+10 years', strtotime($publish_date));
            $exp_date = date('Y-m-d', $exp_date);

            $exp_description = strtolower($description);
            $exp_description = explode(" ", $exp_description);

            $node = new stdClass();
            $node->title = trim(html_entity_decode($original_headline));
            $node->type = "story";
            node_object_prepare($node);
            $node->language = LANGUAGE_NONE;
            $node->uid = $user->uid;
            $node->promote = 0;
            $node->comment = 0;
            $node->body[$node->language][0]['value'] = $description ? $description : 'NA';
            $node->body[$node->language][0]['format'] = 'full_html';
            $node->field_story_long_head_line[LANGUAGE_NONE][0]['value'] = trim(html_entity_decode($original_headline));
            $node->field_story_magazine_kicker_text[LANGUAGE_NONE][0]['value'] = $final_kicker;
            $node->field_story_short_headline[LANGUAGE_NONE][0]['value'] = trim($headline);
            $node->metatags[LANGUAGE_NONE]['keywords']['value'] = $meta_keyword;
            $node->field_story_source_type[LANGUAGE_NONE][0]['value'] = 'AP';
            //$node->field_story_reporter[LANGUAGE_NONE][0]['target_id'] = $by_line;
            if ($category_name) {
              $node->field_story_category[LANGUAGE_NONE][0]['tid'] = $category_name;
            }
            $node->field_story_schedule_date_time[LANGUAGE_NONE][0]['value'] = $publish_date;
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
            itg_api_insert_xml_info($node->nid, $xml_filename, 'story', 'AP');
            $msg = $headline . ' imported sucessfully';
            watchdog('AP_XML', $msg);
          }
          else {
            $msg = $headline . ' Already imported';
            watchdog('AP_XML', $msg);
          }
          $ap++;
          if ($ap == 2)
            break;
        }
      }
    }
  }
}
