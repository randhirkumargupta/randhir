<?php

/**
 * Implement itg_pti_content
 */
function itg_import_common_agency_feeds($agency_name) {
  //drupal_page_is_cacheable(FALSE);
  if (!empty(variable_get('api_info'))) {
    global $user;
    try {
      $agency_feed_url = 'http://agencyfeeds.intoday.in/fs/R/indiatoday?agency=' . $agency_name . '&language=en';
      $agency_str = file_get_contents($agency_feed_url);
      $agency_json = json_decode($agency_str, true);
      foreach ($agency_json['data']['lists'] as $agency_item) {
        $ref_id = $agency_item['ref_id'];
        $row_count = itg_api_get_xml_info($ref_id);
        if ($agency_item['feed_source'] == $agency_name && $agency_item['exported'] == 0) {
          itg_api_insert_xml_info(0, $ref_id, 'story', $agency_name);
          $publish_flag = FALSE;
          $caps_agency_name = strtoupper($agency_name);
          $term_name = $caps_agency_name . ' Feed';
          $headline = htmlentities(strip_tags(trim(preg_replace('/\s+/', ' ', $agency_item['title']))));
          $title_length = strlen($agency_item['title']);
          // get pubdate
          $publish_date_raw = $agency_item['pubdate'];
          if (!empty($publish_date_raw)) {
            $publish_date_timestamp = strtotime($publish_date_raw);
          }
          else {
            $publish_date_timestamp = time();
          }
          $publish_date = date('Y-m-d', $publish_date_timestamp);
          $publish_date_time = date('Y-m-d H:i', $publish_date_timestamp);
          $schedule_date_time = gmdate('Y-m-d H:i', $publish_date_timestamp);
          $term_id = itg_api_get_term_id($term_name, CATEGORY_MANAGMENT);
          $title = itg_api_check_title($headline, $term_id, $publish_date);
          if (!$title) {
            $description = $agency_item['description'];
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

            // create expiry date based on publish date 
            $exp_date = strtotime('+10 years', strtotime($publish_date));
            $exp_date = date('Y-m-d', $exp_date);

            // get byline id based on name 
            $by_line = itg_api_get_nid($caps_agency_name, 'reporter');
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
            $node->field_story_source_type[LANGUAGE_NONE][0]['value'] = $caps_agency_name;
            if (!empty($term_id)) {
              $node->field_story_category[LANGUAGE_NONE][0]['tid'] = $term_id;
              $node->field_primary_category[LANGUAGE_NONE][0]['value'] = $term_id;
            }
            $node->field_story_schedule_date_time[LANGUAGE_NONE][0]['value'] = $schedule_date_time ? $schedule_date_time : date('Y-m-d H:i', time());
            $node->field_itg_content_publish_date[LANGUAGE_NONE][0]['value'] = $publish_date_time ? $publish_date_time : date('Y-m-d H:i', time());
            $node->field_story_expiry_date[LANGUAGE_NONE][0]['value'] = $exp_date;
            $node->field_story_type[LANGUAGE_NONE][0]['value'] = 'other_story';
            $node->field_reporter_unique_id[LANGUAGE_NONE][0]['value'] = trim($uniqueid);
            $node->field_story_configurations[LANGUAGE_NONE][0]['value'] = array('commentbox');
            $node->field_story_configurations[LANGUAGE_NONE][1]['value'] = array('noindex_nofollow');
            $node->field_story_configurations[LANGUAGE_NONE][2]['value'] = array('nofollow');
            // E Extra large image Image
            $e_extra_large_image = $agency_item['default_image'][0]['extra_large'];
            $e_extra_large_image_name = basename($e_extra_large_image);
            $e_extra_large_image_uri = 'public://' . $e_extra_large_image_name;
            $e_extra_large_image_files = file_load_multiple(array(), array('uri' => $e_extra_large_image_uri));
            $e_extra_large_image_file = reset($e_extra_large_image_files);
            if (empty($e_extra_large_image_file)) {
              $e_extra_large_image_content = file_get_contents($e_extra_large_image);
              $e_extra_large_image_file = file_save_data($e_extra_large_image_content, 'public://' . $e_extra_large_image_name, FILE_EXISTS_RENAME);
            }
            $node->field_story_e_extra_large_image = array(LANGUAGE_NONE => array('0' => (array) $e_extra_large_image_file));
            // E Extra large image Image   
            // Extra Large Image
            $extra_large_image = $agency_item['default_image'][0]['large'];
            $extra_large_image_name = basename($extra_large_image);
            $extra_large_image_uri = 'public://' . $extra_large_image_name;
            $extra_large_image_files = file_load_multiple(array(), array('uri' => $extra_large_image_uri));
            $extra_large_image_file = reset($extra_large_image_files);
            if (empty($extra_large_image_file)) {
              $extra_large_image_content = file_get_contents($extra_large_image);
              $extra_large_image_file = file_save_data($extra_large_image_content, 'public://' . $extra_large_image_name, FILE_EXISTS_RENAME);
            }
            $node->field_story_extra_large_image = array(LANGUAGE_NONE => array('0' => (array) $extra_large_image_file));
            // Extra Large Image
            //Large Image
            $large_image = $agency_item['default_image'][0]['medium'];
            $large_image_name = basename($large_image);
            $large_image_uri = 'public://' . $large_image_name;
            $large_image_files = file_load_multiple(array(), array('uri' => $large_image_uri));
            $large_image_file = reset($large_image_files);
            if (empty($large_image_file)) {
              $large_image_content = file_get_contents($large_image);
              $large_image_file = file_save_data($large_image_content, 'public://' . $large_image_name, FILE_EXISTS_RENAME);
            }
            $node->field_story_large_image = array(LANGUAGE_NONE => array('0' => (array) $large_image_file));
            //Large Image
            // Medium Image
            $medium_image = $agency_item['default_image'][0]['regular'];
            $medium_image_name = basename($medium_image);
            $medium_image_uri = 'public://' . $medium_image_name;
            $medium_image_files = file_load_multiple(array(), array('uri' => $medium_image_uri));
            $medium_image_file = reset($medium_image_files);
            if (empty($medium_image_file)) {
              $medium_image_content = file_get_contents($medium_image);
              $medium_image_file = file_save_data($medium_image_content, 'public://' . $medium_image_name, FILE_EXISTS_RENAME);
            }
            $node->field_story_medium_image = array(LANGUAGE_NONE => array('0' => (array) $medium_image_file));
            // Medium Image
            // Small Image
            $small_image = $agency_item['default_image'][0]['thumbnail'];
            $small_image_name = basename($small_image);
            $small_image_uri = 'public://' . $small_image_name;
            $small_image_files = file_load_multiple(array(), array('uri' => $small_image_uri));
            $small_image_file = reset($small_image_files);
            if (empty($small_image_file)) {
              $small_image_content = file_get_contents($small_image);
              $small_image_file = file_save_data($small_image_content, 'public://' . $small_image_name, FILE_EXISTS_RENAME);
            }
            $node->field_story_small_image = array(LANGUAGE_NONE => array('0' => (array) $small_image_file));
            // Small Image
            // Extra Small Image
            $extra_small_image = $agency_item['default_image'][0]['small'];
            $extra_small_image_name = basename($extra_small_image);
            $extra_small_image_uri = 'public://' . $extra_small_image_name;
            $extra_small_image_files = file_load_multiple(array(), array('uri' => $extra_small_image_uri));
            $extra_small_image_file = reset($extra_small_image_files);
            if (empty($extra_small_image_file)) {
              $extra_small_image_content = file_get_contents($extra_small_image);
              $extra_small_image_file = file_save_data($extra_small_image_content, 'public://' . $extra_small_image_name, FILE_EXISTS_RENAME);
            }
            $node->field_story_extra_small_image = array(LANGUAGE_NONE => array('0' => (array) $extra_small_image_file));
            // Extra Small Image

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
            else if ($headline == '' || empty($headline) || $headline == '.') {
              $node->log = 'State Changed to Review';
              $node->workbench_moderation_state_new = workbench_moderation_state_review();
            }
            else if (strtoupper($headline) == $headline) {
              $node->log = 'State Changed to Review';
              $node->workbench_moderation_state_new = workbench_moderation_state_review();
            }
            else {
              if (($title_length < 30) || ($headline_flag)) {
                $node->log = 'State Changed to Review';
                $node->workbench_moderation_state_new = workbench_moderation_state_review();
              }
              else {
                $node->log = 'State Changed to published';
                //$node->workbench_moderation_state_new = workbench_moderation_state_published();
                //workbench_moderation_moderate($node, 'published');
                $publish_flag = TRUE;
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

            if ($publish_flag) {
              db_update('workbench_moderation_node_history') // Table name no longer needs {}
                  ->fields(array(
                    'state' => workbench_moderation_state_published(),
                    'published' => 1,
                    'uid' => ADMINISTRATOR,
                  ))
                  ->condition('nid', $node->nid, '=')
                  ->condition('is_current', 1, '=')
                  ->execute();
            }
            itg_api_update_xml_info($node->nid, $ref_id, 'story', $ref_id);
          }
          else {
            $msg = $headline . ' Already imported';
            watchdog('PTI_XML', $msg);
          }
        }
        die;
      }
    }
    catch (S3Exception $e) {
      echo $e->getMessage() . "\n";
    }
    echo "Success";
  }
  else {
    echo "Failure";
    watchdog('Agency_configuration_warning', 'Enable agency feed from configuration');
  }
}
