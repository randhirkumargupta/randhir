<?php

/**
 * @file
 * ITG Octopus Api inc.
 *
 * Fetch the xml value in database from octopus api.
 *
 */

/**
 * Rundown API callback for Octopus
 */
function itg_octopus_api_rundown() {
  global $base_url, $user;
  header('Content-Type: text/html; charset=UTF-8');
  $direc = array();
  $direc['current'] = variable_get('itg_octopus_url_current');
  $direc['next1'] = variable_get('itg_octopus_url_next1');
  $direc['next2'] = variable_get('itg_octopus_url_next2');

  if (empty($direc)) {
    watchdog('ITG otopus error', t('OOPS, Octopus rundown URLs are missing'));
  }

  foreach ($direc as $key => $xm_file) {
    $xml_file_path = $xm_file;

    try {
      $rundown_xml = simplexml_load_file($xml_file_path, 'SimpleXMLElement', LIBXML_NOCDATA);
    }
    catch (Exception $e) {
      // Sending mail to support team 
      itg_octopus_api_send_email_to_support("Octopus error while fatching rundown", $e->getMessage());
      watchdog("Octopus Error", $e->getMessage());
    }

    $rundown_id = (int) $rundown_xml->rundown->rundownId;
    $rundown_title = (string) $rundown_xml->rundown->rundownTitle;
    $rundown_start = (string) $rundown_xml->rundown->rundownStart;
    $rundown_type = (string) $rundown_xml->rundown->rundownType;
    $exported = strtotime((string) $rundown_xml->exported);
    $exported_by = (string) $rundown_xml->exportedBy;
    $exist_rundown = itg_octopus_api_check_rundown($rundown_id);

    // Managing Previous Rundown if $key is 0 means rundown is current      
    if ($key == 'current') {
      itg_octopus_current_to_prev_rundown($rundown_id, 'current');
    }

    try {
      $qry = db_merge('itg_rundown') // Table name no longer needs {}
          ->key(array('rundown_id' => $rundown_id))
          ->fields(array(
            'exported' => $exported,
            'exported_by' => $exported_by,
            'rundown_type' => $rundown_type,
            'rundown_id' => $rundown_id,
            'rundown_title' => $rundown_title,
            'rundown_start' => $rundown_start,
            'rundown_start_timestamp' => (int) strtotime($rundown_start),
            'type' => $key,
          ))
          ->execute();
    }
    catch (Exception $e) {
      itg_octopus_api_send_email_to_support("Octopus error while inserting/updating data in db rundown", $e->getMessage());
      watchdog("Octopus Error", $e->getMessage());
    }
    $count_slug = 0;
    if (isset($rundown_xml->rundown->slugs->slug)) {
      foreach ($rundown_xml->rundown->slugs->slug as $slug_key => $slug) {
        $element_type = $slug->script->main->body->element->elementType;
        if ($element_type == variable_get('itg_octopus_rundown_element_type_name', 'pkg')) {
          $story_id = (int) $slug->storyId;
          $action = (string) $slug->action;
          $story_title = (string) $slug->storyTitle;
          // Adding Octopus Log 
          $msg = '';
          $hyperlink = 'rundown-listing';
          $query_string = array(
            'parm' => array('rundowntype' => $key),
          );
          $query_string_json = json_encode($query_string);
          $msg = '[' . $action . '] ' . $story_title . '(' . $story_id . ')[RUNDOWN]';
          itg_octopus_add_notification('RUNDOWN', $msg, $hyperlink, $query_string_json, REQUEST_TIME, 1);
          // End Adding Octopus Log
          // Sending mail to Octopus user where 
          $story_com_data = '';
          if ($action == 'UPDATE') {
            $story_com_data = 'Story Title= ' . $story_title . ' Video ID=' . $story_id;
            itg_octopus_api_send_email_to_octopus("You have received UPDATE tag in XML(Rundown)", 'You have received UPDATE tag in XML for story:' . $story_com_data);
          }

          if ($action == 'DELETE') {
            $story_com_data = 'Story Title= ' . $story_title . ' Video ID=' . $story_id;
            itg_octopus_api_send_email_to_octopus("You have received DELETE tag in XML(Rundown)", 'You have received DELETE tag in XML for story:' . $story_com_data);
          }

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

          try {
            db_merge('itg_octopus_slug')
                ->key(array('rundown_id' => $rundown_id, 'storyid' => $story_id))
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
                  'timestamp' => REQUEST_TIME,
                  'story_modified_by' => $story_modified_by,
                  'story_custom' => $story_custom,
                  'category' => $slug->storyCustom[1],
                  'location' => $slug->storyCustom[0],
                ))->execute();
          }
          catch (Exception $e) {
            itg_octopus_api_send_email_to_support("Octopus error while inserting/updating data in db rundown", $e->getMessage());
            watchdog("Octopus Error", $e->getMessage());
          }
          try {
            db_merge('itg_element_clip')
                ->key(array('rundown_id' => $rundown_id, 'storyid' => $story_id))
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
                  'commands' => $commands,
                ))->execute();
          }
          catch (Exception $e) {
            itg_octopus_api_send_email_to_support("Octopus error while inserting/updating data in db rundown", $e->getMessage());
            watchdog("Octopus Error", $e->getMessage());
          }
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
  global $theme;
  $settings = array();
  $settings['loader_url'] = base_path() . drupal_get_path('theme', $theme) . '/images/loader.svg';
  drupal_add_js(array('itg_octopus_holder' => array('settings' => $settings)), array('type' => 'setting'));
  drupal_add_js(drupal_get_path('module', 'itg_octopus_api') . '/js/itg_octopus_api.js', array('weight' => 1, 'scope' => 'footer'));
  drupal_add_css(drupal_get_path('module', 'itg_octopus_api') . '/css/itg_octopus_api.css');
  // Added code for Notification read 
  if (isset($_GET['onotify']) && !empty($_GET['onotify'])) {
    itg_octopus_notification_by_uid($_GET['onotify']);
  }
  $query = db_select('itg_rundown', 'r')
      ->fields('r', array('rundown_id'));
  $result = $query->execute()->rowCount();


  $pagination = '';
  $current_rundown = '';

  if (isset($_GET['rundowntype']) && $_GET['rundowntype'] == 'previous') {
    $pagination.= '<li class="pager-current">' . t(' Previous ', array('attributes' => array('class' => 'disabled'))) . '</li>';
    $current_rundown = 'previous';
  }
  else {
    $pagination.= '<li class="pager-item">' . l(' Previous ', 'rundown-listing', array('query' => array('rundowntype' => 'previous'))) . '</li>';
  }

  if (!isset($_GET['rundowntype']) || (isset($_GET['rundowntype']) && empty($_GET['rundowntype'])) || (isset($_GET['rundowntype']) && $_GET['rundowntype'] == 'current')) {
    $pagination.= '<li class="pager-current">' . t(' Current ', array('attributes' => array('class' => 'disabled'))) . '</li>';
    $current_rundown = 'current';
  }
  else {
    $pagination.= '<li class="pager-item">' . l(' Current ', 'rundown-listing', array('query' => array('rundowntype' => 'current'))) . '</li>';
  }

  if (isset($_GET['rundowntype']) && $_GET['rundowntype'] == 'next1') {
    $pagination.= '<li class="pager-current">' . t(' Next1 ', array('attributes' => array('class' => 'disabled'))) . '</li>';
    $current_rundown = 'next1';
  }
  else {
    $pagination.= '<li class="pager-item">' . l(' Next1 ', 'rundown-listing', array('query' => array('rundowntype' => 'next1'))) . '</li>';
  }

  if (isset($_GET['rundowntype']) && $_GET['rundowntype'] == 'next2') {
    $pagination.= '<li class="pager-current">' . t(' Next2 ', array('attributes' => array('class' => 'disabled'))) . '</li>';
    $current_rundown = 'next2';
  }
  else {
    $pagination.= '<li class="pager-item">' . l(' Next2 ', 'rundown-listing', array('query' => array('rundowntype' => 'next2'))) . '</li>';
  }

  if (empty($current_rundown)) {
    $current_rundown = 'current';
  }

  $query = db_select('itg_rundown', 'rund')->extend('PagerDefault')->limit(50);
  $query->join('itg_octopus_slug', 'ios', 'rund.rundown_id=ios.rundown_id');
  $query->join('itg_element_clip', 'clip', 'clip.storyid=ios.storyid');
  $query->fields('ios');
  $query->fields('clip', array('text'));

  if (isset($_GET['title']) && !empty($_GET['title'])) { // Title
    $query->condition('ios.story_title', $_GET['title'], '=');
  }

  if (isset($_GET['video_id']) && !empty($_GET['video_id'])) { // For Video ID
    $query->condition('ios.storyid', $_GET['video_id'], '=');
  }

  if (isset($_GET['category']) && !empty($_GET['category'])) { // For Category
    $category_data = explode(',', trim($_GET['category']));
    $category_data = array_map('trim', $category_data);
    $query->condition('ios.category', $category_data, 'IN');
  }

  $start_date = isset($_GET['start_date']) && !empty($_GET['start_date']) && $_GET['start_date'] != ' ' ? trim($_GET['start_date']) : '';
  $end_date = isset($_GET['end_date']) && !empty($_GET['end_date']) && $_GET['end_date'] != ' ' ? trim($_GET['end_date']) : '';

  if (isset($start_date) && !empty($start_date)) { // start date
    $query->condition('ios.story_modified_timestamp', strtotime($start_date), '>=');
  }

  if (isset($end_date) && !empty($end_date)) { // end date
    $query->condition('ios.story_modified_timestamp', strtotime($end_date), '<=');
  }

  if (isset($current_rundown) && !empty($current_rundown)) {
    $query->condition('rund.type', $current_rundown, '=');
  }

  $query->orderBy('ios.id', 'DESC');

  $result = $query->distinct()->execute();


  $rows = array();
  $sn = 1;
  $row_count = itg_octopus_api_rundown_listing_count($current_rundown);

  $header = array(
    array('data' => t('Sn.')),
    array('data' => t('Video ID')),
    array('data' => t('Video Title')),
    array('data' => t('Video Description')),
    array('data' => t('Category')),
    array('data' => t('Created By')),
    array('data' => t('Modified By')),
    array('data' => t('Created Date & Time')),
    array('data' => t('Modified Date & Time')),
    array('data' => t('Location')),
    array('data' => t('Actions')),
  );

  foreach ($result as $row) {
    $ctype_text = l('File Video', $base_url . '/node/add/videogallery?element=vo&story_id=' . $row->storyid . '&destination=rundown-listing');
    $link = '<div><a class="octopus-slug-data" data="' . $row->id . '" href="javascript:void(0);">' . t('View') . '</a>';
    $background_color = 'bg-none';
    if ($row->action == 'DELETE') {
      $background_color = 'bg-red';
    }
    elseif ($row->action == 'UPDATE') {
      $background_color = 'bg-yellow';
    }
    else {
      $background_color = 'bg-none';
    }

    $video_description = itg_octopus_api_remove_cdata($row->text);
    $video_description = substr($video_description, 0, 100);

    $rows[] = array(
      array('data' => $sn++),
      array('data' => $row->storyid),
      array('data' => $row->story_title),
      array('data' => $video_description),
      array('data' => $row->category),
      array('data' => $row->story_created_by),
      array('data' => $row->story_modified_by),
      array('data' => date('d/m/Y - H:i:s', strtotime($row->story_created))),
      array('data' => date('d/m/Y - H:i:s', strtotime($row->story_modified)), 'class' => $background_color),
      array('data' => $row->location),
      array('data' => $link),
    );
  }
  $itg_octopus_api_form = drupal_get_form('itg_octopus_api_form');
  $rundown_active_class = '';
  $rfa_active_class = '';
  if (isset($_GET['q']) && $_GET['q'] == 'rundown-listing') {
    $rundown_active_class = 'active-trail';
  }
  elseif (isset($_GET['q']) && $_GET['q'] == 'rfa-dashboard') {
    $rfa_active_class = 'active-trail';
  }
  $output = '<div class="content-block-menu">
            <ul class="menu">
           <li>' . l('Rundown', 'rundown-listing', array('attributes' => array('class' => array($rundown_active_class)))) . '</li>
           <li>' . l('RFA', 'rfa-dashboard', array('attributes' => array('class' => array($rfa_active_class)))) . '</li>
           </ul>
           </div>';
  $output .= render($itg_octopus_api_form);
  $output .= '<div class="octopus-pagination"><ul class="pager">' . $pagination . '</ul></div>';
  $output .= '<div class="octopus-pagination"><span style="float:right;">Count(' . $row_count . ')</span></div>';
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table')), 'empty' => 'No results found'));
  # add the pager
  $output .= theme('pager');
  return $output;
}

/**
 * Implements function itg_octopus_api_rundown_listing_count for get all count
 */
function itg_octopus_api_rundown_listing_count($current_rundown) {
  $query = db_select('itg_rundown', 'rund');
  $query->join('itg_octopus_slug', 'ios', 'rund.rundown_id=ios.rundown_id');
  $query->join('itg_element_clip', 'clip', 'clip.storyid=ios.storyid');
  $query->fields('ios');
  $query->fields('clip', array('text'));

  if (isset($_GET['title']) && !empty($_GET['title'])) { // Title
    $query->condition('ios.story_title', $_GET['title'], '=');
  }

  if (isset($_GET['video_id']) && !empty($_GET['video_id'])) { // For Video ID
    $query->condition('ios.storyid', $_GET['video_id'], '=');
  }

  if (isset($_GET['category']) && !empty($_GET['category'])) { // For Category
    $category_data = explode(',', trim($_GET['category']));
    $category_data = array_map('trim', $category_data);
    $query->condition('ios.category', $category_data, 'IN');
  }

  $start_date = isset($_GET['start_date']) && !empty($_GET['start_date']) && $_GET['start_date'] != ' ' ? trim($_GET['start_date']) : '';
  $end_date = isset($_GET['end_date']) && !empty($_GET['end_date']) && $_GET['end_date'] != ' ' ? trim($_GET['end_date']) : '';

  if (isset($start_date) && !empty($start_date)) { // start date
    $query->condition('ios.story_modified_timestamp', strtotime($start_date), '>=');
  }

  if (isset($end_date) && !empty($end_date)) { // end date
    $query->condition('ios.story_modified_timestamp', strtotime($end_date), '<=');
  }

  if (isset($current_rundown) && !empty($current_rundown)) {
    $query->condition('rund.type', $current_rundown, '=');
  }

  $query->orderBy('ios.id', 'DESC');

  return $result = $query->distinct()->execute()->rowCount();
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
  $query = db_select('itg_octopus_slug', 'ios');
  $query->leftjoin('itg_element_clip', 'clip', 'clip.storyid=ios.storyid');
  $query->fields('ios');
  $query->fields('clip', array('text'));
  $query->condition('ios.id', $sid, '=');
  $result = $query->execute()->fetchAll();
  $slug_data = reset($result);
  $slug_data->clip_data = itg_octopus_slug_clip($slug_data);
  $slug_data->dm_success = itg_octopus_dm_success($sid);
  $slug_data->itg_octopus_low_resoln_video_url = variable_get('itg_octopus_low_resoln_video_url');
  print theme('oct_slug_detail', array('result' => $slug_data));
  drupal_exit();
}

function itg_octopus_check_slug_inprogress() {
  // Getting all request from Queue
  if (isset($_POST['id']) && !empty($_POST['id'])) {
    $slug_id = $_POST['id'];
    try {
      $query = db_select('itg_octopus_cron', 'z')
          ->fields('z', array('slug_id'))
          ->condition('z.slug_id', $slug_id)
          ->condition('z.final_success', OCTOPUS_FAIL_STATUS)
          ->execute();
      $result = $query->fetchObject();
      if (isset($result->slug_id) && !empty($result->slug_id)) {
        print TRUE;
      }
      else {
        print FALSE;
      }
      drupal_exit();
    }
    catch (Exception $e) {
      itg_octopus_api_send_email_to_support("Octopus error while fatching data from itg_octopus_cron table", $e->getMessage());
      watchdog('Octopus Error', 'Error:' . $e->getMessage());
    }
  }
}

/**
 * Getting slug video 
 */
function slug_video() {
  $sid = arg(1);
  $parms = isset($_POST) ? $_POST : array();


  // Getting video name and video mysql slug ID(Video id) in variable
  $video_name = isset($_POST['id']) ? $_POST['id'] : NULL;
  $db_slug_id = isset($_POST['attr_id']) ? $_POST['attr_id'] : NULL;



  $url = variable_get('itg_octopus_high_resoln_video_copyr') . "?FILE_NAME=" . $sid;
  $options = array(
    'method' => 'GET',
    'data' => '',
    'timeout' => 15,
  );

  try {
    $result = drupal_http_request($url, $options);
  }
  catch (Exception $e) {
    itg_octopus_api_send_email_to_support("Octopus error while sending file copy request to TV team", $e->getMessage());
    watchdog("Octopus Error", $e->getMessage());
  }

  $success = new SimpleXmlIterator($result->data);
  $success_data = (array) $success->COPYFILE;
  $success_id = (int) $success_data['@attributes']['REQUEST_ID'];
  print $success_id;
  //Sending the meta data for first cron run 


  drupal_exit();
}

/**
 * itg_octopus_dumping_video_status
 */
function itg_octopus_background_video_status() {
  $id = isset($_POST['id']) ? $_POST['id'] : NULL;
  if (isset($id) && !empty($id)) {
    try {
      $query = db_select('itg_octopus_cron_log', 'z')
          ->fields('z', array('message', 'type'))
          ->condition('z.cron_id', $id)
          ->orderBy("z.id", "DESC")
          ->range(0, 1)
          ->execute();
      $result = $query->fetchObject();
      print json_encode($result);
      drupal_exit();
    }
    catch (Exception $e) {
      itg_octopus_api_send_email_to_support("Octopus error while getting s3_path from  Table: itg_octopus_s3_path_for_cron", $e->getMessage());
      watchdog('Octopus Error', 'Error:' . $e->getMessage());
    }
  }
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

  $form['itg_octopus_holder']['itg_octopus_notify_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Octopus Notify E-mail'),
    '#default_value' => variable_get('itg_octopus_notify_email', ''),
    '#description' => t('Notification Email address for Octopus'),
    '#required' => TRUE,
  );

  $form['itg_octopus_holder']['itg_octopus_oct_fromemail'] = array(
    '#type' => 'textfield',
    '#title' => t('Reply to E-mail'),
    '#default_value' => variable_get('itg_octopus_oct_fromemail', ''),
    '#description' => t('Reply to E-mail address for Octopus'),
    '#required' => TRUE,
  );

  $form['itg_octopus_holder']['itg_octopus_rundown_element_type_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Octopus Rundown element type name'),
    '#default_value' => variable_get('itg_octopus_rundown_element_type_name', 'pkg'),
    '#description' => t('Octopus Rundown element type name i.e PKG'),
    '#required' => TRUE,
  );

  $form['itg_octopus_url'] = array(
    '#type' => 'fieldset',
    '#title' => 'Rundown URL\'s Settings',
  );

  $form['itg_octopus_url']['itg_octopus_url_current'] = array(
    '#type' => 'textfield',
    '#title' => t('Current'),
    '#default_value' => variable_get('itg_octopus_url_current'),
    '#required' => TRUE,
  );

  $form['itg_octopus_url']['itg_octopus_url_next1'] = array(
    '#type' => 'textfield',
    '#title' => t('Next1'),
    '#default_value' => variable_get('itg_octopus_url_next1'),
    '#required' => TRUE,
  );

  $form['itg_octopus_url']['itg_octopus_url_next2'] = array(
    '#type' => 'textfield',
    '#title' => t('Next2'),
    '#default_value' => variable_get('itg_octopus_url_next2'),
    '#required' => TRUE,
  );

  $form['itg_octopus_ftp'] = array(
    '#type' => 'fieldset',
    '#title' => 'Octopus FTP Settings',
  );

  $form['itg_octopus_ftp']['itg_octopus_ftp_ip'] = array(
    '#type' => 'textfield',
    '#title' => t('FTP Server IP'),
    '#default_value' => variable_get('itg_octopus_ftp_ip'),
    '#required' => TRUE,
  );

  $form['itg_octopus_ftp']['itg_octopus_ftp_port'] = array(
    '#type' => 'textfield',
    '#title' => t('Port'),
    '#default_value' => variable_get('itg_octopus_ftp_port'),
    '#required' => TRUE,
  );

  $form['itg_octopus_ftp']['itg_octopus_ftp_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => variable_get('itg_octopus_ftp_username'),
    '#required' => TRUE,
  );

  $form['itg_octopus_ftp']['itg_octopus_ftp_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#default_value' => variable_get('itg_octopus_ftp_password'),
    '#required' => TRUE,
  );

  $form['itg_octopus_someurls'] = array(
    '#type' => 'fieldset',
    '#title' => 'Octopus URL\'s Settings',
  );

  $form['itg_octopus_someurls']['itg_octopus_low_resoln_video_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Low resolution Video URL'),
    '#default_value' => variable_get('itg_octopus_low_resoln_video_url'),
    '#required' => TRUE,
  );

  $form['itg_octopus_someurls']['itg_octopus_high_resoln_video_copyr'] = array(
    '#type' => 'textfield',
    '#title' => t('High resolution Video Copy request URL'),
    '#default_value' => variable_get('itg_octopus_high_resoln_video_copyr'),
    '#required' => TRUE,
  );

  $form['itg_octopus_someurls']['itg_octopus_high_resoln_vid_copy_status'] = array(
    '#type' => 'textfield',
    '#title' => t('High resolution Video Copy request status URL'),
    '#default_value' => variable_get('itg_octopus_high_resoln_vid_copy_status'),
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

/**
 * Returns Slug object for clip
 * @param object $slug
 * @return array
 */
function itg_octopus_slug_clip($slug) {
  $query = db_select('itg_element_clip', 'ios')
      ->fields('ios', array('clipobj_id'))
      ->condition('rundown_id', $slug->rundown_id, '=')
      ->condition('storyid', $slug->storyid, '=');
  $result = $query->execute()->fetchAll();
  return $result;
}

/**
 * Getting Daily motion video article status filed against slug id
 * @param int $id
 * @return boolean
 */
function itg_octopus_dm_success($id) {
  if (isset($id) && !empty($id)) {
    $result = db_select('itg_octopus_dm_response', 'dmr')
        ->fields('dmr')
        ->condition('slug_id', $id)
        ->execute();
    $num_of_results = $result->rowCount();
    return $num_of_results;
  }
}

/**
 * Helper method for octopus file video to ITG vodeo
 */
function itg_octopus_file_video() {
  $slug_id = $_POST['slug_id'];
  global $base_url;
  if (isset($slug_id) && !empty($slug_id)) {
    $dm_res = itg_octopus_getting_oct_dm_response($slug_id);
    if (function_exists('itg_videogallery_dailymotion_api')) {
      $api = itg_videogallery_dailymotion_api();
      $dur = $api->get(
          '/video/' . $dm_res->video_id, array('fields' => array('duration', 'embed_url', 'encoding_progress', 'publishing_progress'))
      );
      $playlist_id = variable_get('dailymotion_playlist_id');
      $result = array();
      $result['duration'] = itg_octopus_get_duration($dur['duration']);
      $result['encoding_progress'] = $dur['encoding_progress'];
      $result['publishing_progress'] = $dur['publishing_progress'];
      itg_octopus_send_dm_octopus_res_update($result, $slug_id);
      $instance_daily_motion = new Dailymotion();
      $instance_daily_motion->logout();
      // Adding Entry for dailymotion_response_details 
      itg_octopus_add_dm_response_details((array) $dm_res, $result);
      $oct_meta_info = array(
        'fid' => $dm_res->fid,
        'slug_id' => $slug_id,
      );
      $octopus_ref = base64_encode(json_encode($oct_meta_info));
      $return_url = $base_url . '/node/add/videogallery?destination=rundown-listing&octopus_ref=' . $octopus_ref;
      print $return_url;
      drupal_exit();
    }
  }
}

/**
 * Getting octopus response for daily motion
 * @param type $id
 * @return type
 */
function itg_octopus_getting_oct_dm_response($id) {
  if (isset($id) && !empty($id)) {
    $result = db_select('itg_octopus_dm_response', 'dmr')
        ->fields('dmr')
        ->condition('dmr.slug_id', $id)
        ->execute();
    $results = $result->fetchObject();
    return $results;
  }
}

/**
 * Getting Duration for Octopus in i:s, H:i:s format
 * @param type $time
 * @return type
 */
function itg_octopus_get_duration($time) {
  $duration = "";
  if ($time < 3600) {
    $duration = gmdate("i:s", $time);
  }
  else {
    $duration = gmdate("H:i:s", $time);
  }
  return $duration;
}

/**
 * This method is for updating the daily motion octopus response
 * @param type $time
 * @return type
 */
function itg_octopus_send_dm_octopus_res_update($object, $slug_id) {
  $result['duration'] = itg_octopus_get_duration($dur['duration']);
  $result['encoding_progress'] = $dur['encoding_progress'];
  $result['publishing_progress'] = $dur['publishing_progress'];
  try {
    $num_updated = db_update('itg_octopus_dm_response') // Table name no longer needs {}
        ->fields(array(
          'video_duration' => $object['duration'],
          'encoding_progress' => $object['encoding_progress'],
          'publishing_progress' => $object['publishing_progress'],
        ))
        ->condition('slug_id', $slug_id, '=')
        ->execute();
  }
  catch (Exception $e) {
    watchdog("Octopus Error", $e->getMessage());
  }
  return isset($num_updated) ? $num_updated : null;
}

/**
 * Adding entry for daily motion response
 */
function itg_octopus_add_dm_response_details($response, $result) {
  try {
    $nid = db_merge('dailymotion_response_details')
        ->key(array('fid' => $response['fid'], 'video_id' => $response['video_id']))
        ->fields(array(
          'title' => $response['title'],
          'channel' => $response['channel'],
          'fid' => $response['fid'],
          'tags' => ' ',
          'video_type' => 'DM',
          'video_id' => $response['video_id'],
          'nid' => 0,
          'video_size' => $response['video_size'],
          'encoding_progress' => $result['encoding_progress'],
          'publishing_progress' => $result['publishing_progress'],
          'upload_time' => $response['upload_time'],
          'video_duration' => $result['duration'],
          'dailymotion_published' => 0,
          'type' => 'octopus',
          'name' => $response['name'],
        ))
        ->execute();
  }
  catch (Exception $e) {
    watchdog("Octopus Error", $e->getMessage());
  }
  try {
    db_merge('itg_solr_video_info')
        ->key(array('fid' => $response['fid'], 'solr_video_id' => $response['video_id']))
        ->fields(array(
          'fid' => $response['fid'],
          'solr_video_id' => $response['video_id'],
          'nid' => 0,
          'property' => VIDEO_PROPERTY,
          'content_type' => 'video_gallery',
          'solr_video_duration' => $result['duration'],
          'solr_video_size' => $response['video_size'],
          'solr_video_thumb' => "",
        ))
        ->execute();
  }
  catch (Exception $e) {
    watchdog("Octopus Error", $e->getMessage());
  }
}

/**
 * Chanding current rundown to Previous Rundown
 * @param int $rundown_id
 * @param string $type
 */
function itg_octopus_current_to_prev_rundown($rundown_id, $type) {
  try {
    db_update('itg_rundown')
        ->fields(array(
          'type' => 'previous',
        ))
        ->condition('type', $type)
        ->condition('rundown_id', $rundown_id, '<>')
        ->execute();
  }
  catch (Exception $e) {
    watchdog("Octopus Error", $e->getMessage());
  }
  return TRUE;
}

/**
 * This method will send request to TV team
 */
function itg_octopus_sending_request_to_tv_team() {
  $sid = arg(1);
  $parms = isset($_POST) ? $_POST : array();
  // Getting video name and video mysql slug ID(Video id) in variable
  $sid = isset($_POST['slug_id']) ? $_POST['slug_id'] : NULL;
  $db_slug_id = isset($_POST['attr_id']) ? $_POST['attr_id'] : NULL;
  $check_already_process_flag_cron = itg_octopus_check_queued_process_cron($db_slug_id);
  if (isset($check_already_process_flag_cron) && !empty($check_already_process_flag_cron)) {
    print $check_already_process_flag_cron;
    drupal_exit();
  }
  else {
    $url = variable_get('itg_octopus_high_resoln_video_copyr') . "?FILE_NAME=" . $sid;
    $options = array(
      'method' => 'GET',
      'data' => '',
      'timeout' => 15,
    );

    try {
      $result = drupal_http_request($url, $options);
    }
    catch (Exception $e) {
      itg_octopus_api_send_email_to_support("Octopus error while sending file copy request to TV team", $e->getMessage());
      watchdog("Octopus Error", $e->getMessage());
    }
    $success = new SimpleXmlIterator($result->data);
    $success_data = (array) $success->COPYFILE;
    $success_id = (int) $success_data['@attributes']['REQUEST_ID'];
    if (isset($success_id) && !empty($success_id) && isset($db_slug_id) && !empty($db_slug_id)) {
      $cron_id = itg_octopus_api_first_init_entry_cron($success_id, $db_slug_id);
      if (isset($cron_id) && !empty($cron_id)) {
        itg_octopus_generate_cron_log($cron_id, $db_slug_id, DEF_OCTOPUS_REQ_TV_TEAM, 'request_tv_to_s3');
      }
    }

    // Send this for cron entry 
    print $cron_id;

    //Sending the meta data for first cron run 
    drupal_exit();
  }
}

/**
 * Send Object  for cron processing queue
 * This function is responsible for adding the entry for cron
 * @param array $object
 */
function itg_octopus_api_first_init_entry_cron($success_id, $db_slug_id) {
  if (isset($success_id) && !empty($success_id) && isset($db_slug_id) && !empty($db_slug_id)) {
    try {
      $cron_id = db_insert('itg_octopus_cron')
          ->fields(array(
            'slug_id' => $db_slug_id,
            'video_request_id' => $success_id,
            'request_tv_to_s3' => OCTOPUS_SUCCESS_STATUS,
            'file_copied_dump_machine' => OCTOPUS_FAIL_STATUS,
            'file_copied_to_s3' => OCTOPUS_FAIL_STATUS,
            'request_s3_to_dm' => OCTOPUS_FAIL_STATUS,
            'cron_init_time' => REQUEST_TIME,
            'last_cron_run_time' => REQUEST_TIME,
            'final_success' => OCTOPUS_FAIL_STATUS,
          ))
          ->execute();
      // Generating Octopus Cron Log
      //itg_octopus_generate_cron_log($cron_id, $db_slug_id, DEF_OCTOPUS_REQ_TV_TEAM);
      return isset($cron_id) ? $cron_id : NULL;
    }
    catch (Exception $e) {
      itg_octopus_api_send_email_to_support("Octopus error while inserting/updating data in itg_octopus_cron table", $e->getMessage());
      watchdog('Octopus Error', 'Error:' . $e->getMessage());
    }
  }
}

/**
 * This method is responsible for running all background process for octopus
 */
function itg_octopus_cron_bkprocess() {
  // Getting all request from Queue
  try {
    $qry = db_select('itg_octopus_cron', 'n');
    $qry->fields('n');
    $qry->condition('n.final_success', OCTOPUS_FAIL_STATUS);
    $res = $qry->execute();
    $final_data = array();
    foreach ($res as $resdata) {
      $final_data[] = $resdata;
    }
  }
  catch (Exception $e) {
    itg_octopus_api_send_email_to_support("Octopus error while fatching data from itg_octopus_cron table", $e->getMessage());
    watchdog('Octopus Error', 'Error:' . $e->getMessage());
  }


  foreach ($final_data as $chunk_data) {
    if (isset($chunk_data) && !empty($chunk_data)) {
      // Start code for checking whether file have been copied on  dumping machine or not 
      if (isset($chunk_data->request_tv_to_s3) && $chunk_data->request_tv_to_s3 == 1 &&
          isset($chunk_data->file_copied_dump_machine) && $chunk_data->file_copied_dump_machine == 0 &&
          isset($chunk_data->file_copied_to_s3) && $chunk_data->file_copied_to_s3 == 0 &&
          isset($chunk_data->request_s3_to_dm) && $chunk_data->request_s3_to_dm == 0 &&
          isset($chunk_data->final_success) && $chunk_data->final_success == 0
      ) {
        //Checking dumping video status
        $dumping_machine_req_status = itg_octopus_api_check_dump_video_status($chunk_data->video_request_id);
        // Updating dumping video status whenever file copied to dumping machine
        if (isset($dumping_machine_req_status) && !empty($dumping_machine_req_status) && $dumping_machine_req_status == 'YES') {
          itg_octopus_api_update_cron_status('file_copied_dump_machine', 1, $chunk_data->cron_id);
          // Generating Octopus Cron Log
          itg_octopus_generate_cron_log($chunk_data->cron_id, $chunk_data->slug_id, DEF_OCTOPUS_REQ_DMP_MACHINE, 'file_copied_dump_machine');
        }
      }
      // End code for checking whether file have been copied on dumping machine or not
      // Start code for checking file copied status to S3
      if (isset($chunk_data->request_tv_to_s3) && $chunk_data->request_tv_to_s3 == 1 &&
          isset($chunk_data->file_copied_dump_machine) && $chunk_data->file_copied_dump_machine == 1 &&
          isset($chunk_data->file_copied_to_s3) && $chunk_data->file_copied_to_s3 == 0 &&
          isset($chunk_data->request_s3_to_dm) && $chunk_data->request_s3_to_dm == 0 &&
          isset($chunk_data->final_success) && $chunk_data->final_success == 0
      ) {
        $s3_copied_success = itg_octopus_api_check_s3_copied_status($chunk_data->video_request_id, $chunk_data->cron_id);
        if (isset($s3_copied_success) && !empty($s3_copied_success) && $s3_copied_success == 'YES') {
          itg_octopus_api_update_cron_status('file_copied_to_s3', 1, $chunk_data->cron_id);
          // Generating Octopus Cron Log
          itg_octopus_generate_cron_log($chunk_data->cron_id, $chunk_data->slug_id, DEF_OCTOPUS_REQ_CPY_DMP_S3_BKT, 'file_copied_to_s3');
        }
      }
      // End code for checking file copied status to S3
      // Start code for sending s3 video to Dailymotion 
      if (isset($chunk_data->request_tv_to_s3) && $chunk_data->request_tv_to_s3 == 1 &&
          isset($chunk_data->file_copied_dump_machine) && $chunk_data->file_copied_dump_machine == 1 &&
          isset($chunk_data->file_copied_to_s3) && $chunk_data->file_copied_to_s3 == 1 &&
          isset($chunk_data->request_s3_to_dm) && $chunk_data->request_s3_to_dm == 0 &&
          isset($chunk_data->final_success) && $chunk_data->final_success == 0
      ) {

        // Getting s3 path by Cron ID
        $s3_object = itg_octopus_api_get_s3_path_by_cron_id($chunk_data->cron_id);
        if (isset($s3_object) && !empty($s3_object)) {
          $dm_success = itg_octopus_api_video_s3_to_dm_via_cron($s3_object->s3_path, $s3_object->file_size, $chunk_data->slug_id);
          if ($dm_success == 'yes') {
            // Updating request status s3 to DM
            itg_octopus_api_update_cron_status('request_s3_to_dm', 1, $chunk_data->cron_id);
            itg_octopus_generate_cron_log($chunk_data->cron_id, $chunk_data->slug_id, DEF_OCTOPUS_REQ_PROCS_DM, 'request_s3_to_dm');
          }
        }
      }
      // End code for sending s3 video to Dailymotion
      // Start code for updating final status
      if (isset($chunk_data->request_tv_to_s3) && $chunk_data->request_tv_to_s3 == 1 &&
          isset($chunk_data->file_copied_dump_machine) && $chunk_data->file_copied_dump_machine == 1 &&
          isset($chunk_data->file_copied_to_s3) && $chunk_data->file_copied_to_s3 == 1 &&
          isset($chunk_data->request_s3_to_dm) && $chunk_data->request_s3_to_dm == 1 &&
          isset($chunk_data->final_success) && $chunk_data->final_success == 0
      ) {
        itg_octopus_api_update_cron_status('final_success', 1, $chunk_data->cron_id);
        itg_octopus_generate_cron_log($chunk_data->cron_id, $chunk_data->slug_id, DEF_OCTOPUS_REQ_READY_TO_USE, 'final_success');
      }
      // Start code for updating final status
    }
  }
}

/**
 * Updating cron status
 * @param string $field
 * @param int $value
 * @param int $cron_id
 * @return boolean
 */
function itg_octopus_api_update_cron_status($field, $value, $cron_id) {
  try {
    $itg_octopus_cron = db_update('itg_octopus_cron')
        ->fields(array(
          $field => (int) $value,
          'last_cron_run_time' => REQUEST_TIME,
        ))
        ->condition('cron_id', $cron_id)
        ->execute();
    if ($itg_octopus_cron) {
      return TRUE;
    }
  }
  catch (Exception $e) {
    itg_octopus_api_send_email_to_support("Octopus error while updating data from itg_octopus_cron table", $e->getMessage());
    watchdog('Octopus Error', 'Error:' . $e->getMessage());
  }
  return FALSE;
}

/**
 * Getting dumping video status whether video have been copied or not
 * @param int $video_request_id
 * @return string
 */
function itg_octopus_api_check_dump_video_status($video_request_id) {
  if (isset($video_request_id) && !empty($video_request_id)) {
    $url = variable_get('itg_octopus_high_resoln_vid_copy_status') . "?REQUEST_ID=" . $video_request_id;
    $options = array(
      'method' => 'GET',
      'data' => '',
      'timeout' => 15,
    );
    try {
      $result = drupal_http_request($url, $options);
    }
    catch (Exception $e) {
      itg_octopus_api_send_email_to_support("Octopus error while getting file copy request status to TV team", $e->getMessage());
      watchdog('Octopus Error', 'Error:' . $e->getMessage());
    }
    $success = new SimpleXmlIterator($result->data);
    $success_data = (array) $success->COPIEDFILEDETAILS;
    if (isset($success_data['@attributes']['IS_COPIED']) &&
        !empty($success_data['@attributes']['IS_COPIED']) &&
        $success_data['@attributes']['IS_COPIED'] == 'YES') {
      return $success_data['@attributes']['IS_COPIED'];
    }
  }
  return; // Returning by default with no value
}

/**
 * Getting status whether file have been copied or not on s3 bucket
 * @param int $video_request_id
 * @param int $cron_id
 * @return string
 */
function itg_octopus_api_check_s3_copied_status($video_request_id, $cron_id) {
  if (isset($video_request_id) && !empty($video_request_id)) {
    $url = variable_get('itg_octopus_high_resoln_vid_copy_status') . "?REQUEST_ID=" . $video_request_id;
    $options = array(
      'method' => 'GET',
      'data' => '',
      'timeout' => 15,
    );
    try {
      $result = drupal_http_request($url, $options);
      $success = new SimpleXmlIterator($result->data);
      $success_data = (array) $success->COPIEDFILEDETAILS;
      // Sending file copied status 
      if (isset($success_data['@attributes']['IS_COPIED']) &&
          !empty($success_data['@attributes']['IS_COPIED']) &&
          $success_data['@attributes']['IS_COPIED'] == 'YES') {

        if (isset($success_data['@attributes']['MP4_FILE_PATH']) &&
            !empty($success_data['@attributes']['MP4_FILE_PATH'])) {
          // Setting s3 path for Cron that will be further reused for Daily motion request
          $mp4_path = $success_data['@attributes']['MP4_FILE_PATH'];
          $file_size = itg_octopus_api_get_file_size($mp4_path); // Getting file size
          itg_octopus_set_s3_path_for_cron($video_request_id, $mp4_path, $file_size, $cron_id);
          return true;
        }
      }
    }
    catch (Exception $e) {
      itg_octopus_api_send_email_to_support("Octopus error while getting file copy request status to TV team", $e->getMessage());
      watchdog('Octopus Error', 'Error:' . $e->getMessage());
    }
  }
  return; // Returning by default with no value
}

/**
 * Setting s3 path for cron against video request Id and cron Id 
 * @param type $video_request_id
 * @param type $mp4_file_path
 * @param type $cron_id
 */
function itg_octopus_set_s3_path_for_cron($video_request_id, $s3_path,
    $file_size, $cron_id) {
  try {
    $qry = db_merge('itg_octopus_s3_path_for_cron');
    $qry->key(array('cron_id' => $cron_id));
    $qry->fields(array(
          'cron_id' => (int) $cron_id,
          'video_request_id' => (int) $video_request_id,
          's3_path' => $s3_path,
          'file_size' => $file_size,
          'timestamp' => REQUEST_TIME,
            )
        )
        ->execute();
  }
  catch (Exception $e) {
    itg_octopus_api_send_email_to_support("Octopus error while inserting/updating s3 path in Table: itg_octopus_s3_path_for_cron", $e->getMessage());
    watchdog('Octopus Error', 'Error:' . $e->getMessage());
  }
}

/**
 * Generating cron log for each cron request
 * @param object $cron_object
 */
function itg_octopus_generate_cron_log($cron_id, $slug_id, $message, $type) {
  try {
    $qry = db_insert('itg_octopus_cron_log');
    $qry->fields(array(
      'cron_id' => (int) $cron_id,
      'slug_id' => (int) $slug_id,
      'message' => $message,
      'type' => $type,
      'timestamp' => REQUEST_TIME,
    ));
    $res = $qry->execute();
    return isset($res) ? TRUE : FALSE;
  }
  catch (Exception $e) {
    itg_octopus_api_send_email_to_support("Octopus error while generating cron log Table: itg_octopus_cron_log", $e->getMessage());
    watchdog('Octopus Error', 'Error:' . $e->getMessage());
  }
  return;
}

/**
 * Getting s3 path by Cron ID 
 * @param type $cron_id
 */
function itg_octopus_api_get_s3_path_by_cron_id($cron_id) {
  try {
    $query = db_select('itg_octopus_s3_path_for_cron', 'z')
        ->fields('z', array('s3_path', 'file_size'))
        ->condition('z.cron_id', $cron_id)
        ->range(0, 1)
        ->execute();
    $result = $query->fetchObject();
    if (isset($result) && !empty($result)) {
      return $result;
    }
  }
  catch (Exception $e) {
    itg_octopus_api_send_email_to_support("Octopus error while getting s3_path from  Table: itg_octopus_s3_path_for_cron", $e->getMessage());
    watchdog('Octopus Error', 'Error:' . $e->getMessage());
  }
}

/**
 * Sending s3 video to Daily motion via Cron
 * @param type $s3video_url
 * @param type $file_size
 * @param type $slug_id
 */
function itg_octopus_api_video_s3_to_dm_via_cron($s3video_url, $file_size,
    $slug_id) {
  $data = array();
  $filename = drupal_basename($s3video_url);
  if (function_exists('itg_videogallery_dailymotion_send_video')) {
    $response = itg_videogallery_dailymotion_send_video($s3video_url);
  }
  if (!empty($response)) {
    $response_result['video_id'] = $response['id'];
    $api = itg_videogallery_dailymotion_api();
    $thumb_url = $api->get(
        '/video/' . $response['id'], array('fields' => array('thumbnail_720_url'))
    );

    $image_url = $thumb_url['thumbnail_720_url'];
    // Added entry in file browse
    $file_object = itg_octopus_api_check_exist_file_browse($filename, $file_size);
    $response_result['fid'] = (int) $file_object;
    try {
      $dm_upload_time = REQUEST_TIME;
      $nid = db_insert('itg_octopus_dm_response')
          ->fields(array(
            'title' => $response['title'],
            'channel' => $response['channel'],
            'fid' => (int) $file_object,
            'tags' => ' ',
            'video_id' => $response['id'],
            'nid' => 0,
            'slug_id' => $slug_id,
            'video_size' => $file_size,
            'dailymotion_thumb_url' => $image_url,
            'encoding_progress' => $response['encoding_progress'],
            'publishing_progress' => $response['publishing_progress'],
            'upload_time' => $dm_upload_time,
            'video_duration' => $response['duration'],
            'dailymotion_published' => 0,
            'type' => 'S3',
            'name' => $response['name'],
          ))
          ->execute();
      $success = 'yes';

      $dm_object = new stdClass();
      $dm_object->title = $response['title'];
      $dm_object->video_id = $response['id'];
      $dm_object->video_duration = $response['duration'];
      $dm_object->dailymotion_thumb_url = $image_url;
      $dm_object->video_size = $file_size;
      $dm_object->upload_time = $dm_upload_time;

      itg_octopus_api_update_itg_solr_video($dm_object);

      // Adding entry for ITG-solr Video
    }
    catch (Exception $e) {
      $success = 'no';
      itg_octopus_api_send_email_to_support("Octopus error while updating  Table: itg_octopus_dm_response", $e->getMessage());
      watchdog('Octopus Error', 'Error:' . $e->getMessage());
    }
    return $success;
  }
}

/**
 * itg_octopus_api_update_itg_solr_video
 * @global type $user
 * @param object $val
 */
function itg_octopus_api_update_itg_solr_video($val) {
  if (isset($val) && !empty($val)) {
    global $user;
    $node = new stdClass();
    $node->title = $val->title;
    $node->type = "itg_solr_video";
    node_object_prepare($node); //Invokes hook_prepare() and hook_node_prepare().
    $node->language = LANGUAGE_NONE;
    $node->field_video_id[LANGUAGE_NONE][0]['value'] = $val->video_id;
    $node->field_property [LANGUAGE_NONE][0]['value'] = VIDEO_PROPERTY;
    $node->field_video_duration [LANGUAGE_NONE][0]['value'] = $val->video_duration;
    $node->field_video_used [LANGUAGE_NONE][0]['value'] = 0;
    $node->field_video_thumb_url[LANGUAGE_NONE][0]['value'] = $val->dailymotion_thumb_url;
    $node->field_video_size[LANGUAGE_NONE][0]['value'] = $val->video_size;
    $node->field_is_replace[LANGUAGE_NONE][0]['value'] = 0;
    $node->field_video_type[LANGUAGE_NONE][0]['value'] = 'DM';
    $node->field_video_is_draft[LANGUAGE_NONE][0]['value'] = 0;
    $node->uid = 1;
    $node->field_video_date_time[LANGUAGE_NONE][0]['value'] = date('Y-m-d H:i:s', $val->upload_time);
    $node->field_video_time[LANGUAGE_NONE][0]['value'] = date('Y-m-d H:i:s', $val->upload_time);
    $node->status = 1; //(1 or 0): Published or not
    $node->promote = 0; //(1 or 0): Promoted to front page
    $node->comment = 0; // 0 = Comments disabled, 1 = read only, 2 = read/write
    if (function_exists('itg_videogallery_get_video_solrcontent')) {
      $video_exist_innode = itg_videogallery_get_video_solrcontent($val->video_id);
    }
    if (isset($video_exist_innode) && !empty($video_exist_innode)) {
      $node->nid = $video_exist_innode[0]->nid;

      try {
        node_save($node);
      }
      catch (Exception $e) {
        itg_octopus_api_send_email_to_support("Octopus error while saving node Type: itg_solr_video", $e->getMessage());
        watchdog('Octopus Error', 'Error:' . $e->getMessage());
      }
    }
    try {
      node_save($node);
    }
    catch (Exception $e) {
      itg_octopus_api_send_email_to_support("Octopus error while saving node Type: itg_solr_video", $e->getMessage());
      watchdog('Octopus Error', 'Error:' . $e->getMessage());
    }
  }
}

/**
 * itg_octopus_dumping_video_status
 */
function itg_octopus_get_current_cron_info($id, $field) {
  if (isset($id) && !empty($id)) {
    try {
      $query = db_select('itg_octopus_cron', 'c')
          ->fields('c', array($field, 'final_success'))
          ->condition('c.cron_id', (int) $id)
          ->range(0, 1)
          ->execute();
      $result = $query->fetchObject();
      if (isset($result) && !empty($result)) {
        return $result;
      }
    }
    catch (Exception $e) {
      itg_octopus_api_send_email_to_support("Octopus error while getting s3_path from  Table: itg_octopus_cron", $e->getMessage());
      watchdog('Octopus Error', 'Error:' . $e->getMessage());
    }
  }
}

function itg_octopus_check_queued_process_cron($id) {
  if (isset($id) && !empty($id)) {
    try {
      $query = db_select('itg_octopus_cron', 'c')
          ->fields('c', array('cron_id'))
          ->condition('c.slug_id', (int) $id)
          ->range(0, 1)
          ->execute();
      $result = $query->fetchObject();
      if (isset($result->cron_id) && !empty($result->cron_id)) {
        return $result->cron_id;
      }
    }
    catch (Exception $e) {
      itg_octopus_api_send_email_to_support("Octopus error while getting data from Table: itg_octopus_cron", $e->getMessage());
      watchdog('Octopus Error', 'Error:' . $e->getMessage());
    }
  }
}

/**
 * Restoring background process Callback
 */
function itg_octopus_restore_back_g_process() {
  // Getting all request from Queue
  try {
    $qry = db_select('itg_octopus_cron', 'n');
    $qry->fields('n', array('slug_id'));
    $qry->condition('n.final_success', OCTOPUS_FAIL_STATUS);
    $res = $qry->execute();
    $final_data = array();
    foreach ($res as $resdata) {
      $final_data[] = (int) $resdata->slug_id;
    }
    print json_encode($final_data);
    drupal_exit();
  }
  catch (Exception $e) {
    itg_octopus_api_send_email_to_support("Octopus error while fatching data from itg_octopus_cron table", $e->getMessage());
    watchdog('Octopus Error', 'Error:' . $e->getMessage());
  }
}

/**
 * Getting file size by passing s3 public path
 * @param type $s3_url
 */
function itg_octopus_api_get_file_size($s3_url) {
  stream_context_set_default(
      array(
        'http' => array(
          'method' => 'HEAD'
        )
      )
  );
  $headers = get_headers($s3_url, 1);
  $headers = array_change_key_case($headers);
  $size = trim($headers['content-length'], '"');
  if (isset($size) && !empty($size)) {
    return $size;
  }
  else {
    return 1;
  }
}
