<?php

/**
 * Implement itg_pti_content
 */
function itg_reuters_content() {
  $file_path = drupal_realpath('public://');
  global $user;
  module_load_include('php', 'itg_api', 'alchemy_api/alchemyapi');

  $vocab_id = taxonomy_vocabulary_machine_name_load('bad_words');
  $tax = taxonomy_get_tree($vocab_id->vid, $parent = 0, $max_depth = 1, $load_entities = FALSE);

  foreach ($tax as $key => $val) {
    $op[$val->tid] = strtolower($val->name);
  }

  //$direc = get_dir_content($file_path . '/feeds/reuters/');
  $final_dir = getcwd() . '/sites/all/modules/custom/itg_api/feeds/reuters/';
  $direc = get_dir_content($final_dir);

  foreach ($direc as $xm_file) {
    $xml_file_path = $xm_file;
    $xml_filename = basename($xml_file_path);
    $reuters_xml = simplexml_load_file($xml_file_path, 'SimpleXMLElement', LIBXML_NOCDATA);
    if (empty(itg_api_get_xml_info($xml_filename))) {
      if (!empty($reuters_xml)) {
        $reuters = 0;
        $reuters_body = $reuters_xml->itemSet;
        foreach ($reuters_body as $reuters_value) {

          $headline = htmlentities(strip_tags(trim(preg_replace('/\s+/', ' ', $reuters_value->newsItem->contentMeta->headline))));
          $title_length = strlen($reuters_value->newsItem->contentMeta->headline);
          $title = itg_api_check_title($headline);
          foreach ($reuters_value->newsItem->contentSet->inlineXML->html->body->p as $value) {
            $description .= '<p>' . $value . '</p>';
          }
          if (!$title) {
            $alchemyapi[$reuters] = new AlchemyAPI('cd95bc47470dedf7e5002748636e78848cd0a9f4');
            $response[$reuters] = $alchemyapi[$reuters]->keywords('text', $headline, array('sentiment' => 1));
            $final_keyword = '';
            if ($response[$reuters]['status'] == 'OK') {
              foreach ($response[$reuters]['keywords'] as $keyword) {
                $final_keyword[] = $keyword['text'];
              }
            }
            else {
              echo 'Error in the keyword extraction call: ', $response['statusInfo'];
            }
            $meta_keyword = implode(", ", $final_keyword);
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

            $publish_date = date('Y-m-d', time());
            // create expiry date based on publish date 
            $exp_date = strtotime('+10 years', strtotime($publish_date));
            $exp_date = date('Y-m-d', $exp_date);

            //Set values to node
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
            $node->field_story_source_type[LANGUAGE_NONE][0]['value'] = 'Reuters';
            $node->field_story_schedule_date_time[LANGUAGE_NONE][0]['value'] = $publish_date ? $publish_date : date('Y-m-d', time());
            $node->field_story_expiry_date[LANGUAGE_NONE][0]['value'] = $exp_date;
            $node->field_story_type[LANGUAGE_NONE][0]['value'] = 'other_story';
            $exp_description = strtolower($description);
            $exp_description = explode(" ", $exp_description);
            if (array_intersect($op, $exp_description)) {
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
            node_save($node); // Finally save node
            itg_api_insert_xml_info($node->nid, $xml_filename, 'story', 'PTI');
            $msg = $headline . ' imported sucessfully';
            watchdog('REUTERS_XML', $msg);
          }
          else {
            $msg = $headline . ' Already imported';
            watchdog('REUTERS_XML', $msg);
          }

          if ($reuters == 2)
            break;
          $reuters++;
        }
      }
    }
  }
}
