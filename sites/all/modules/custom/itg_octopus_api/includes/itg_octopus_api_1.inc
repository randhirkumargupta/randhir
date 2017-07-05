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
  $file_path = 'sites/default/files';
  global $base_url, $user;
  header('Content-Type: text/html; charset=UTF-8');
  //$direc = get_dir_content($file_path . '/octopus/rundown/');
  //$direc = get_dir_content($file_path . '/octopus/testrundown/');

  $direc = array();
  $direc[] = variable_get('itg_octopus_url_current');
  $direc[] = variable_get('itg_octopus_url_next1');
  $direc[] = variable_get('itg_octopus_url_next2');

//p($direc);
  if (empty($direc)) {
    watchdog('ITG otopus error', t('OOPS, Octopus rundown URLs are missing'));
  }

  foreach ($direc as $xm_file) {
    $xml_file_path = $xm_file;
    //p($xml_file_path);
    //$xml_filename = basename($xml_file_path);
    //$rundown_xml = simplexml_load_file($xml_file_path, 'SimpleXMLElement', LIBXML_NOCDATA);

    $rundown_xml = simplexml_load_file($xml_file_path, 'SimpleXMLElement', LIBXML_NOCDATA);
    //p($rundown_xml);

    $rundown_id = (string) $rundown_xml->rundown->rundownId;
    $rundown_title = (string) $rundown_xml->rundown->rundownTitle;
    $rundown_start = (string) $rundown_xml->rundown->rundownStart;
    $rundown_type = (string) $rundown_xml->rundown->rundownType;
    $exported = strtotime((string) $rundown_xml->exported);
    $exported_by = (string) $rundown_xml->exportedBy;
    $exist_rundown = itg_octopus_api_check_rundown($rundown_id);


    $mnmnm = array(
      'exported' => $exported,
      'exported_by' => $exported_by,
      'rundown_type' => $rundown_type,
      'rundown_id' => $rundown_id,
      'rundown_title' => $rundown_title,
      'rundown_start' => $rundown_start,
      'rundown_start_timestamp' => strtotime($rundown_start),
    );

    //if (empty($exist_rundown)) {
    $qry = db_merge('itg_rundown') // Table name no longer needs {}
        ->key(array('rundown_id' => $rundown_id))
        ->fields(array(
          'exported' => $exported,
          'exported_by' => $exported_by,
          'rundown_type' => $rundown_type,
          'rundown_id' => $rundown_id,
          'rundown_title' => $rundown_title,
          'rundown_start' => $rundown_start,
          'rundown_start_timestamp' => strtotime($rundown_start),
        ))
        ->execute();
    //}
    $count_slug = 0;
    if (isset($rundown_xml->rundown->slugs->slug)) {
      foreach ($rundown_xml->rundown->slugs->slug as $key => $slug) {
        $element_type = $slug->script->main->body->element->elementType;
        //pr(variable_get('itg_octopus_rundown_element_type_name', 'pkg'));
        if (/* $slug->action == 'INSERT' && */ $element_type == variable_get('itg_octopus_rundown_element_type_name', 'pkg')) {
          //p($slug);
          $story_id = (int) $slug->storyId;
          $action = (string) $slug->action;
          $story_title = (string) $slug->storyTitle;
          $story_duration = (string) $slug->storyDur;
          $story_skip = (string) $slug->storySkip;
          $story_created = (string) $slug->storyCreated;
          $story_created_by = (string) $slug->storyCreatedBy;
          $story_modified = (string) $slug->storyModified;
          $story_modified_by = (string) $slug->storyModifiedBy;
          $element_id = $slug->script->main->body->element->elementId;
          $element_dur = (string) isset($slug->script->main->body->element->elementDur) ? $slug->script->main->body->element->elementDur : '';
          $clip_name = (string) isset($slug->script->main->body->element->clip->clipName) ? $slug->script->main->body->element->clip->clipName : '';
          $clip_mos_id = (string) $slug->script->main->body->element->clip->clipMosId;
          $clip_obj_id = (string) $slug->script->main->body->element->clip->clipObjId;
          $clip_job_id = (string) $slug->script->main->body->element->clip->clipJobId;
          $clip_file_path = (string) $slug->script->main->body->element->clip->clipFilePath;
          $clip_in = (string) $slug->script->main->body->element->clip->clipIn;
          $clip_out = (string) $slug->script->main->body->element->clip->clipOut;
          $commands = (string) $slug->script->main->body->element->clip->commands;
          $text = htmlentities($slug->script->main->body->element->text);
          $story_custom = json_encode($slug->storyCustom); // Storing the complete story
//        foreach ($slug->storyCustom as $key => $value) {
//          $arr[$value->attributes()->label] = $value;
//          $arr['rundown_id'] = $rundown_id;
////          $arr['storyid'] = $story_id;
//        }
          //$storycustom_details = serialize($arr);
          $slug_exist = itg_octopus_api_check_slug($story_id, $rundown_id);
          if (empty($slug_exist)) {
            db_insert('itg_octopus_slug')
                ->fields(array(
                  'rundown_id' => $rundown_id,
                  'storyid' => $story_id,
                  'action' => $action,
                  'story_title' => $story_title,
                  'story_skip' => $story_skip,
                  'story_duration' => $story_duration,
                  'story_created' => $story_created,
                  'story_created_by' => $story_created_by,
                  'story_modified' => $story_modified,
                  'story_modified_timestamp' => strtotime($story_modified),
                  'story_modified_by' => $story_modified_by,
                  'story_custom' => $story_custom,
                ))->execute();

            db_insert('itg_element_clip')
                ->fields(array(
                  'element_id' => $element_id,
                  'rundown_id' => $rundown_id,
                  'storyid' => $story_id,
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
                  'new_element_id' => 12,
                  'commands' => $commands,
                ))->execute();
//          db_insert('itg_octopus_slug_storycustom')
//              ->fields(array(
//                'rundown_id' => $rundown_id,
//                'storyid' => $story_id,
//                'story_custom_data' => $storycustom_details,
//              ))->execute();
          }
          elseif ($slug_exist[0]->story_modified != $story_modified) {
            db_update('itg_octopus_slug')
                ->fields(array(
                  'storyid' => $story_id,
                  'rundown_id' => $rundown_id,
                  'story_title' => $story_title,
                  'story_duration' => $story_duration,
                  'story_created' => $story_created,
                  'story_created_by' => $story_created_by,
                  'story_modified' => $story_modified,
                  'story_modified_timestamp' => strtotime($story_modified),
                  'story_modified_by' => $story_modified_by,
                  'story_custom' => $story_custom,
                ))
                ->condition('storyid', $story_id)
                ->condition('rundown_id', $rundown_id)
                ->execute();

            // Update in itg_element_clip table
            //get element id of clip
            $clipid = itg_octopus_api_clip_check($story_id, $rundown_id);
            try {
              db_update('itg_element_clip')
                  ->fields(array(
                    'element_id' => $element_id,
                    'rundown_id' => $rundown_id,
                    'storyid' => $story_id,
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
                    'new_element_id' => 12,
                    'commands' => $commands,
                  ))
                  ->condition('storyid', $story_id)
                  ->condition('rundown_id', $rundown_id)
                  ->execute();
            }
            catch (Exception $e) {
              
            }
          }
        }
      }
    }
  }
}

//die('done');

/**
 * Implements function for check existing rundown table
 * @param int $rundown_id
 * @return int
 */
function itg_octopus_api_check_rundown($rundown_id) {
  $result = db_select('itg_rundown', 'ir')
      ->condition('rundown_id', $rundown_id, '=')
      ->fields('ir')
      ->execute();
  $num_of_results = $result->rowCount();
  return $num_of_results;
}

/**
 * Implements function for check existing slug in table
 * @param int $slugid
 * @param int $rundown_id
 * @return array
 */
function itg_octopus_api_check_slug($story_id, $rundown_id) {
  $query = db_select('itg_octopus_slug', 'ios')
      ->fields('ios', array('story_modified'))
      ->condition('storyid', $story_id, '=')
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
function itg_octopus_api_clip_check($story_id, $rundown_id) {
  $query = db_select('itg_element_clip', 'iec')
      ->fields('iec', array('element_id', 'rundown_id', 'storyid'))
      ->condition('storyid', $story_id, '=')
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
function itg_octopus_api_storycustom_check($story_id, $rundown_id) {
  $query = db_select('itg_octopus_slug_storycustom', 'ioss')
      ->fields('ioss', array('rundown_id', 'story_custom_data'))
      ->condition('storyid', $story_id, '=')
      ->condition('rundown_id', $rundown_id, '=');
  $result = $query->execute()->fetchAll();
  return $result;
}

/*
 * Implements function for rundown listing.
 */

function itg_octopus_api_rundown_listing() {
  global $base_url;
  drupal_add_js(drupal_get_path('module', 'itg_octopus_api') . '/js/itg_octopus_api.js', array('weight' => 1, 'scope' => 'footer'));

  $query = db_select('itg_rundown', 'r')
      ->fields('r', array('rundown_id'));
  $result = $query->execute()->rowCount();
//p($result);
  # configure the table header columns
  $header = array(
    array('data' => t('ID'), 'field' => 'ios.id', 'sort' => 'ASC'),
    array('data' => t('Story ID'), 'field' => 'ios.storyid', 'sort' => 'ASC'),
    array('data' => t('Story Title'), 'field' => 'ios.story_title', 'sort' => 'ASC'),
    array('data' => t('Modified Date'), 'field' => 'ios.story_modified', 'sort' => 'ASC'),
    array('data' => t('Actions')),
  );

  if (isset($_GET['items_per_page']) && !empty($_GET['items_per_page'])) {
    $items_per_page = $_GET['items_per_page'];
  }
  else {
    $items_per_page = 20;
  }

  if (isset($_GET['title']) && !empty($_GET['title'])) {
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
    //$elementtype = db_query("SELECT element_type from {itg_element_clip} WHERE storyid = :storyid", array(":storyid" => $row->storyid))->fetchField();
    //if ($elementtype == 'pkg') {
    $ctype_text = l('File Video', $base_url . '/node/add/videogallery?element=vo&story_id=' . $row->storyid . '&destination=rundown/listing');
    //}
    //$link = '<a class="colorbox-load" href="' . $base_url . '/slug-details/' . $row->storyid . '?width=300&height=120">' . t('Video Details') . '</a>' . ' | <a href="#">' . $ctype_text . '</a>';
    $link = '<div><a class="octopus-slug-data" data="' . $row->id . '" href="javascript:void(0);">' . t('Video Details') . '</a>' . ' | <a href="#">' . $ctype_text . '</a></div>';
    $rows[] = array(
      array('data' => $row->id),
      array('data' => $row->storyid),
      array('data' => $row->story_title),
      array('data' => format_date(strtotime($row->story_modified), $type = 'itg_date_with_time', $format = '', $timezone = NULL, $langcode = NULL)),
      array('data' => $link),
    );
  }
  $itg_octopus_api_form = drupal_get_form('itg_octopus_api_form');

  $adjacents = 5;

  $query = db_select('itg_rundown', 'r')
      ->fields('r', array('rundown_id'));
  $result = $query->execute()->rowCount();

  $total_pages = $result;

  $limit = 1;                                //how many items to show per page
  $page = $_GET['page'];

  if ($page)
    $start = ($page - 1) * $limit;          //first item to display on this page
  else
    $start = 0;                             //if no page var is given, set start to 
    /* Get data. */

  $query = db_select('itg_rundown', 'r')
      ->fields('r', array('rundown_id'));
  $query->range($start, $limit);

  $result = $query->execute();

  // $result = $mysqli->query("select * from posts order by id  desc LIMIT $start, $limit");

  /* Setup page vars for display. */
  if ($page == 0)
    $page = 1;                  //if no page var is given, default to 1.
  $prev = $page - 1;                          //previous page is page - 1
  $next = $page + 1;                          //next page is page + 1
  $lastpage = ceil($total_pages / $limit);      //lastpage is = total pages / items per page, rounded up.
  //p($lastpage);
  $lpm1 = $lastpage - 1;                      //last page minus 1

  $pagination = "";
  if ($lastpage > 1) {
    $pagination .= "<div class=\"pagination\">";
    //previous button
    if ($page > 1)
      $pagination.= l('« previous ', 'rundown/listing', array('query' => array('page' => $prev)));
    else
      $pagination.= t('« previous ', array('attributes' => array('class' => 'disabled')));

    //next button
    if ($page < $lastpage)
      $pagination.= l('next » ', 'rundown/listing', array('query' => array('page' => $next)));
    else
      $pagination.= t('next » ', array('attributes' => array('class' => 'disabled')));
    $pagination.= "</div>\n";
  }
//p($pagination);
  $q = db_select('itg_rundown', 'r')
      ->fields('r', array('rundown_id'));
  $query->range($start, $limit);

  $result = $query->execute();

  while ($row = $result->fetchAll()) {


// LOOP Code
  };




  $custom_run_down_paginaton = l('Previous', 'sds') . ' ' . l('Current', 'sds') . ' ' . l('Next', 'sds');

  $output = render($itg_octopus_api_form);
  $output .= $pagination;
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
  $query->innerJoin('itg_octopus_slug_storycustom', 'ioss', 'ios.storyid = ioss.storyid');
  $query->innerJoin('itg_octopus_slug_storycustom', 'ioss', 'ios.rundown_id = ioss.rundown_id');
  $query->fields('ioss');
  $query->innerJoin('itg_element_clip', 'iec', 'ios.storyid = iec.storyid');
  $query->innerJoin('itg_element_clip', 'iec', 'ios.rundown_id = iec.rundown_id');
  $query->fields('iec');
  $query->condition('ios.id', arg(2), '=');
  $result = $query->execute()->fetchAssoc();
  $result['story_custom_data'] = unserialize($result['story_custom_data']);
  unset($result['story_custom_data']['storyid']);
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

/**
 * Implements callback for autocomplete
 * @param type $text
 */
function slug_details() {
  $sid = arg(1);
  $query = db_select('itg_octopus_slug', 'ios')
      ->fields('ios')
      ->condition('id', $sid, '=');
  $result = $query->execute()->fetchAll();
  $slug_data = reset($result);
  print theme('oct_slug_detail', array('result' => $slug_data));
  drupal_exit();
}

/**
 * This functon will return the Octopus setting form
 */
function itg_octopus_api_settings($form, &$form_state) {
  $form = array();
  $form['#attributes']['class'][] = 'node-form';

  $form['itg_octopus_holder'] = array(
    '#type' => 'fieldset',
    '#title' => 'Octopus Settings',
  );

  $form['itg_octopus_holder']['itg_octopus_support_team_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Support Team E-mail'),
    '#default_value' => variable_get('itg_octopus_support_team_email', ''),
    '#description' => t('Enter Support Team E-mail'),
    '#required' => TRUE,
  );
  $form['itg_octopus_holder']['itg_octopus_rundown_element_type_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Octopus Rundown element type name'),
    '#default_value' => variable_get('itg_octopus_rundown_element_type_name', 'pkg'),
    '#description' => t('Octopus Rundown element type name i.e PKG'),
    '#required' => TRUE,
  );


  $form['itg_octopus_holder']['itg_octopus_cron_frequency'] = array(
    '#type' => 'textfield',
    '#title' => t('Octopus Cron Frequency'),
    '#default_value' => variable_get('itg_octopus_cron_frequency'),
    '#description' => t('Enter Octopus Cron Frequency'),
    '#required' => TRUE,
  );
  $form['itg_octopus_holder']['itg_octopus_url'] = array(
    '#type' => 'fieldset',
    '#title' => 'Rundown URL\'s Settings',
  );


  $form['itg_octopus_holder']['itg_octopus_url']['itg_octopus_url_current'] = array(
    '#type' => 'textfield',
    '#title' => t('Current'),
    '#default_value' => variable_get('itg_octopus_url_current'),
    '#required' => TRUE,
  );

  $form['itg_octopus_holder']['itg_octopus_url']['itg_octopus_url_next1'] = array(
    '#type' => 'textfield',
    '#title' => t('Next1'),
    '#default_value' => variable_get('itg_octopus_url_next1'),
    '#required' => TRUE,
  );
  $form['itg_octopus_holder']['itg_octopus_url']['itg_octopus_url_next2'] = array(
    '#type' => 'textfield',
    '#title' => t('Next2'),
    '#default_value' => variable_get('itg_octopus_url_next2'),
    '#required' => TRUE,
  );



  return system_settings_form($form);
}

/**
 * Getting the detail of Slug
 * @param string $ajax
 * @param string $id
 */
function itg_octopus_slug_details($ajax, $id) {
  $is_ajax = $ajax === 'ajax';
  drupal_add_library('system', 'drupal.ajax');
  if ($is_ajax) {
    $commands = array();
    $complete_data = itg_octopus_api_rundown_complete_detail($id);
    $commands[] = ajax_command_html('#octopus-data-' . $id, $complete_data);
    ajax_deliver(array('#type' => 'ajax', '#commands' => $commands));
  }
  else {
    drupal_set_message(t('gfgd'));
    drupal_goto();
  }
}

/**
 * Getting complete detail of API rundown
 * @return type 
 */
function itg_octopus_api_rundown_complete_detail($id) {
  $query = db_select('itg_octopus_slug', 'ios');
  $query->fields('ios');
  $query->innerJoin('itg_octopus_slug_storycustom', 'ioss', 'ios.storyid = ioss.storyid');
  $query->innerJoin('itg_octopus_slug_storycustom', 'ioss', 'ios.rundown_id = ioss.rundown_id');
  $query->fields('ioss');
  $query->innerJoin('itg_element_clip', 'iec', 'ios.storyid = iec.storyid');
  $query->innerJoin('itg_element_clip', 'iec', 'ios.rundown_id = iec.rundown_id');
  $query->fields('iec');
  $query->condition('ios.id', 2, '=');
  $result = $query->execute()->fetchAssoc();

  $result['story_custom_data'] = unserialize($result['story_custom_data']);
  unset($result['story_custom_data']['storyid']);
  unset($result['story_custom_data']['rundown_id']);
  $output = theme('rundown_slug_detail', array('result' => $result));
  return $output;
}
