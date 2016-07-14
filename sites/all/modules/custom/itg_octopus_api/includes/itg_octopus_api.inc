<?php

/**
 * @file
 * ITG Octopus Api inc.
 *
 * Fetch the xml value in database from octopus api.
 *
 */

/**
 * Implement itg_pti_content
 */
function itg_octopus_api_rundown() {
  $file_path = drupal_realpath('public://');
  global $base_url, $user;
  header('Content-Type: text/html; charset=UTF-8');
  $direc = get_dir_content($file_path . '/octopus/rundown/');
  foreach ($direc as $xm_file) {
    $xml_file_path = $xm_file;
    $xml_filename = basename($xml_file_path);
    $rundown_xml = simplexml_load_file($xml_file_path, 'SimpleXMLElement', LIBXML_NOCDATA);
    $rundown_id = (string) $rundown_xml->rundown->rundownId;
    $rundown_title = (string) $rundown_xml->rundown->rundownTitle;
    $rundown_start = (string) $rundown_xml->rundown->rundownType;
    $exported = strtotime((string) $rundown_xml->exported);
    $exported_by = (string) $rundown_xml->exportedBy;
    $exist_rundown = itg_octopus_api_check_rundown($rundown_id);
    if ($exist_rundown == '') {
      $nid = db_insert('itg_rundown') // Table name no longer needs {}
          ->fields(array(
            'exported' => $exported,
            'exported_by' => $exported_by,
            'rundown_id' => $rundown_id,
            'rundown_title' => $rundown_title,
            'rundown_start' => $rundown_start,
              //'created' => REQUEST_TIME,
          ))
          ->execute();
    }
    $count_slug = 0;
    foreach ($rundown_xml->rundown->slugs->slug as $key => $slug) {
      $story_id = (string) $slug->storyId;
      $story_title = (string) $slug->storyTitle;
      $story_status = (string) $slug->storyStatus;
      $story_duration = (string) $slug->storyDur;
      $story_created = strtotime((string) $slug->storyCreated);
      $story_created_by = (string) $slug->storyCreatedBy;
      $story_modified = strtotime((string) $slug->storyModified);
      $story_modified_by = (string) $slug->storyModifiedBy;
      $slug_id = (string) $slug->slugId;
      $element_id = (string) $slug->script->main->body->element->elementId;
      $element_type = (string) $slug->script->main->body->element->elementType;
      $element_dur = (string) $slug->script->main->body->element->elementDur;
      $clip_name = (string) $slug->script->main->body->element->clip->clipName;
      $clip_mos_id = (string) $slug->script->main->body->element->clip->clipMosId;
      $clip_obj_id = (string) $slug->script->main->body->element->clip->clipObjId;
      $clip_job_id = (string) $slug->script->main->body->element->clip->clipJobId;
      $clip_file_path = (string) $slug->script->main->body->element->clip->clipFilePath;
      $clip_in = (string) $slug->script->main->body->element->clip->clipIn;
      $clip_out = (string) $slug->script->main->body->element->clip->clipOut;
      $text = htmlentities((string) $slug->script->main->body->element->text);
      // Get story custom value
      foreach ($slug->storyCustom as $key => $value) {
        $arr[(string) $value->attributes()->label] = (string) $value;
        $arr['rundown_id'] = $rundown_id;
        $arr['slug_id'] = $slug_id;
      }
      $storycustom_details = serialize($arr);
      //$count_slug++;
      //End Get story custom value      
      $slug_exist = itg_octopus_api_check_slug($slug_id, $rundown_id);
      if (empty($slug_exist)) {
        db_insert('itg_octopus_slug')
            ->fields(array(
              'storyid' => $story_id,
              'rundown_id' => $rundown_id,
              'slug_id' => $slug_id,
              'story_title' => $story_title,
              'story_status' => $story_status,
              'story_duration' => $story_duration,
              'story_created' => $story_created,
              'story_created_by' => $story_created_by,
              'story_modified' => $story_modified,
              'story_modified_by' => $story_modified_by,
            ))->execute();
        db_insert('itg_element_clip')
            ->fields(array(
              'element_id' => $element_id,
              'rundown_id' => $rundown_id,
              'slug_id' => $slug_id,
              'element_type' => $element_type,
              'element_dur' => $element_dur,
              'clipname' => $clip_name,
              'clipmosid' => $clip_mos_id,
              'clipobj_id' => $clip_obj_id,
              'clipjobid' => $clip_job_id,
              'clipfilepath' => $clip_file_path,
              'clipin' => $clip_in,
              'clipout' => $clip_out,
              'text' => $text,
            ))->execute();

        // Value insert in "itg_octopus_slug_storycustom" Table

        db_insert('itg_octopus_slug_storycustom')
            ->fields(array(
              'rundown_id' => $rundown_id,
              'slug_id' => $slug_id,
              'story_custom_data' => $storycustom_details,
            ))->execute();
      }
      else {
        if ($slug_exist[0]->story_modified != $story_modified) {
          db_update('itg_octopus_slug')
              ->fields(array(
                'storyid' => $story_id,
                'rundown_id' => $rundown_id,
                'slug_id' => $slug_id,
                'story_title' => $story_title,
                'story_status' => $story_status,
                'story_duration' => $story_duration,
                'story_created' => $story_created,
                'story_created_by' => $story_created_by,
                'story_modified' => $story_modified,
                'story_modified_by' => $story_modified_by,
              ))
              ->condition('slug_id', $slug_exist[0]->slug_id)
              ->condition('rundown_id', $rundown_id)
              ->execute();

          // Update in itg_element_clip table
          //get element id of clip
          $clipid = itg_octopus_api_clip_check($slug_id, $rundown_id);
          db_update('itg_element_clip')
              ->fields(array(
                'element_id' => $element_id,
                'rundown_id' => $rundown_id,
                'slug_id' => $slug_id,
                'element_type' => $element_type,
                'element_dur' => $element_dur,
                'clipname' => $clip_name,
                'clipmosid' => $clip_mos_id,
                'clipobj_id' => $clip_obj_id,
                'clipjobid' => $clip_job_id,
                'clipfilepath' => $clip_file_path,
                'clipin' => $clip_in,
                'clipout' => $clip_out,
                'text' => $text,
              ))
              ->condition('slug_id', $clipid[0]->slug_id)
              ->condition('rundown_id', $clipid[0]->rundown_id)
              ->execute();
          // UPdate data in itg_octopus_slug_storycustom
          $story_custom = itg_octopus_api_storycustom_check($slug_id, $rundown_id);
          db_update('itg_octopus_slug_storycustom')
              ->fields(array(
                'rundown_id' => $rundown_id,
                'slug_id' => $slug_id,
                'story_custom_data' => $storycustom_details,
              ))
              ->condition('slug_id', $story_custom[0]->slug_id)
              ->condition('rundown_id', $story_custom[0]->rundown_id)
              ->execute();
        }
      }
    }
  }
}

/**
 * Implements function for check existing rundown table
 * @param int $rundown_id
 * @return int
 */
function itg_octopus_api_check_rundown($rundown_id) {
  $query = db_select('itg_rundown', 'ir')
      ->fields('ir', array('rundown_id'))
      ->condition('rundown_id', $rundown_id, '=');
  $result = $query->execute()->fetchField();
  return $result;
}

/**
 * Implements function for check existing slug in table
 * @param int $slugid
 * @param int $rundown_id
 * @return array
 */
function itg_octopus_api_check_slug($slug_id, $rundown_id) {
  $query = db_select('itg_octopus_slug', 'ios')
      ->fields('ios', array('slug_id', 'story_modified'))
      ->condition('slug_id', $slug_id, '=')
      ->condition('rundown_id', $rundown_id, '=');
  $result = $query->execute()->fetchAll();
  return $result;
}

/**
 * Implements function for check existing slug in table
 * @param int $slugid
 * @param int $rundown_id
 * @return array
 */
function itg_octopus_api_clip_check($slug_id, $rundown_id) {
  $query = db_select('itg_element_clip', 'iec')
      ->fields('iec', array('slug_id', 'element_id', 'rundown_id'))
      ->condition('slug_id', $slug_id, '=')
      ->condition('rundown_id', $rundown_id, '=');
  $result = $query->execute()->fetchAll();
  return $result;
}

/**
 * Implements function for check existing slug in table
 * @param int $slugid
 * @param int $rundown_id
 * @return array
 */
function itg_octopus_api_storycustom_check($slug_id, $rundown_id) {
  $query = db_select('itg_octopus_slug_storycustom', 'ioss')
      ->fields('ioss', array('slug_id', 'rundown_id', 'story_custom_data'))
      ->condition('slug_id', $slug_id, '=')
      ->condition('rundown_id', $rundown_id, '=');
  $result = $query->execute()->fetchAll();
  return $result;
}

/*
 * Implements function for rundown listing.
 */

function itg_octopus_api_rundown_listing() {
  # configure the table header columns
  $header = array(
    array('data' => t('ID'), 'field' => 'ios.id', 'sort' => 'ASC'),
    array('data' => t('Slug ID'), 'field' => 'ios.slug_id', 'sort' => 'ASC'),
    array('data' => t('Slug Title'), 'field' => 'ios.story_title', 'sort' => 'ASC'),
    array('data' => t('Modified Date'), 'field' => 'ios.story_modified', 'sort' => 'ASC'),
    array('data' => t('View')),
  );
  if ($_GET['items_per_page']) {
    $items_per_page = $_GET['items_per_page'];
  }
  else {
    $items_per_page = 20;
  }
  if ($_GET['title']) {
    $query = db_select('itg_octopus_slug', 'ios')
            ->fields('ios')
            ->condition('story_title', $_GET['title'], '=')
            ->extend('TableSort')
            ->orderByHeader($header)
            ->extend('PagerDefault')->limit($items_per_page);
  }
  else {
    $query = db_select('itg_octopus_slug', 'ios')
            ->fields('ios')
            ->extend('TableSort')
            ->orderByHeader($header)
            ->extend('PagerDefault')->limit($items_per_page);
  }

  $result = $query->execute();
  $rows = array();
  foreach ($result as $row) {
    $rows[] = array(
      array('data' => $row->id),
      array('data' => $row->slug_id),
      array('data' => $row->story_title),
      array('data' => format_date($row->story_modified, $type = 'itg_date_with_time', $format = '', $timezone = NULL, $langcode = NULL)),
      array('data' => l(t('Slug Details'), 'slug/detail/' . $row->id)),
    );
  }


  $output = render(drupal_get_form('itg_octopus_api_form'));
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table')), 'empty' => 'No results found'));

  # add the pager
  $output .= theme('pager');

  return $output;
}

/**
 * Implements function for slug detail page
 */
function itg_octopus_api_rundown_detail() {
  $query = db_select('itg_octopus_slug', 'ios');
  $query->fields('ios');
  $query->innerJoin('itg_octopus_slug_storycustom', 'ioss', 'ios.slug_id = ioss.slug_id');
  $query->innerJoin('itg_octopus_slug_storycustom', 'ioss', 'ios.rundown_id = ioss.rundown_id');
  $query->fields('ioss');
  $query->innerJoin('itg_element_clip', 'iec', 'ios.slug_id = iec.slug_id');
  $query->innerJoin('itg_element_clip', 'iec', 'ios.rundown_id = iec.rundown_id');
  $query->fields('iec');
  $query->condition('ios.id', arg(2), '=');
  $result = $query->execute()->fetchAssoc();
  $result['story_custom_data'] = unserialize($result['story_custom_data']);
  unset($result['story_custom_data']['slug_id']);
  unset($result['story_custom_data']['rundown_id']);
  $output = theme('rundown_slug_detail', array('result' => $result));
  return $output;
}

/**
 * Implements callback for autocomplete
 * @param type $text
 */
function demo_autocomplete($text) {
  $query = db_select('itg_octopus_slug', 'ios')
      ->fields('ios', array('id', 'story_title'))
      ->condition('story_title', '%' . db_like($text) . '%', 'LIKE')
      ->distinct()
      ->range(0, 20)
      ->execute();
  foreach ($query as $result) {
    $final_val[$result->story_title] = $result->story_title;
  }
  drupal_json_output($final_val);
}
