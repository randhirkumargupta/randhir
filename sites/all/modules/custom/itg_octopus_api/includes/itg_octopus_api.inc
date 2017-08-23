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
                  'new_element_id' => 12,
                  'commands' => $commands,
                ))->execute();
          }
          catch (Exception $e) {
            itg_octopus_api_send_email_to_support("Octopus error while inserting/updating data in db rundown", $e->getMessage());
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
  $query->fields('clip',array('text'));

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

// p($query->__toString());
  $result = $query->execute();
  $rows = array();
  $sn = 1;

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
    $video_description = substr($video_description, 0, 150);

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
  $output .= '<div class="octopus-pagination"><span style="float:right;">Count(' . count($rows) . ')</span></div>';
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

/**
 * Getting slug video 
 */
function slug_video() {
  $sid = arg(1);
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
  }

  $success = new SimpleXmlIterator($result->data);
  $success_data = (array) $success->COPYFILE;
  $success_id = (int) $success_data['@attributes']['REQUEST_ID'];
  print $success_id;
  drupal_exit();
}

/**
 * itg_octopus_dumping_video_status
 */
function itg_octopus_dumping_video_status() {
  $id = $_POST['id'];
  $url = variable_get('itg_octopus_high_resoln_vid_copy_status') . "?REQUEST_ID=" . $id;
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
  }

  $success = new SimpleXmlIterator($result->data);
  $success_data = (array) $success->COPIEDFILEDETAILS;
  $success_array['IS_COPIED'] = $success_data['@attributes']['IS_COPIED'];
//  $success_array['OPERATION_MESSAGE'] = $success_data['@attributes']['OPERATION_MESSAGE'];
  print json_encode($success_array);
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

  $form['itg_octopus_holder']['itg_octopus_notify_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Octopus Notify E-mail'),
    '#default_value' => variable_get('itg_octopus_notify_email', ''),
    '#description' => t('Notification Email address for Octopus'),
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
 * Sending dumping machine video to S3 bucket
 */
function itg_octopus_api_move_dump_server_to_s3() {
  // set_time_limit(0);
  // ini_set('memory_limit', '-1');
  $files_path = variable_get('file_public_path', conf_path() . '/files');
  global $base_url;
  $data = array();
  // $post_video_id = $_POST['id'];
  $post_video_id = $_POST['id'];
  // $video_path = $base_url . '/' . $post_video_id;
  $video_path = OCTOPUS_DUMPING_MACHINE_URL;  // TODO
  $conn_id = itg_octopus_api_ftp_connection_setup();
  if (empty($conn_id)) {
    // Handling error when there is some problem while creating connection
    $data['success'] = 'no';
    $data['msg'] = 'OOPS::Something went wrong while connecting to FTP, please try again';
    print json_encode($data);
    drupal_exit();
  }
  ftp_pasv($conn_id, true);
  $video_name = $_POST['id'];
  $file_size = ftp_size($conn_id, '/' . $post_video_id);
  $local_file = $files_path . '/' . $video_name;
  $server_file = $video_name;
  $file_d_success = 0;
  $success_get = false;
//  try {
//    $success_get = ftp_get($conn_id, $local_file, $server_file, FTP_BINARY);
//  }
//  catch (Exception $e) {
//    // p('Error:' . $e->getMessage());
//    $s3_success['success'] = 'no';
//    $s3_success['msg'] = 'OOPS::Unable to download FTP file to our server, please try again';
//    itg_octopus_api_send_email_to_support("Octopus:Unable to download FTP file to our server", 'Unable to download FTP file to our server due to error:' .  $e->getMessage());
//    print json_encode($s3_success);
//    drupal_exit();
//  }
//  if ($success_get) {
//    //echo "Successfully written to $local_file\n";
//    // TODO
//    $file_d_success = 1;
//  }
//  else {
//    // echo "There was a problem\n";
//    $file_d_success = 0;
//  }


  $file_d_success = 1;
  // close the connection
  //ftp_close($conn_id);

  if ($file_d_success == 1) {
    module_load_include('inc', 'itg_videogallery', 'includes/itg_videogallery_aws_s3');
    if (function_exists('itg_video_send_dm_to_s3')) {
      $local_file = OCTOPUS_DUMPING_MACHINE_URL;  // [TODO]
      $s3_success = itg_video_send_dm_to_s3_for_octopus($local_file, $video_name);
      $s3_success['file_size'] = $file_size;
      if ($s3_success['success'] == 'no') {
        $s3_success['msg'] = 'OOPS::Unable to send s3 file to daily motion, please try again';
        itg_octopus_api_send_email_to_support("Octopus:Unable to send s3 file to daily motion", 'Unable to send s3 file to daily motion due to error:' . $s3_success->msg);
      }
      unlink($local_file);
      print json_encode($s3_success);
      drupal_exit();
    }
  }
}

/**
 * Sending Video to s3 to Daily motion
 * @param string $s3video_url
 */
function itg_octopus_api_video_s3_to_dm() {
  $data = array();
  module_load_include('inc', 'itg_videogallery', 'includes/itg_videogallery_aws_s3');
  $s3video_url = trim($_POST['s3_video_uri']);
  $file_size = trim($_POST['file_size']);

  $s3video_url = OCTOPUS_DUMPING_MACHINE_URL;  // [TODO] for testing only
  $filename = drupal_basename($s3video_url);
  $slug_id = trim($_POST['slug_id']);
  $response = itg_videogallery_dailymotion_send_video($s3video_url);
  if (!empty($response)) {
    $response_result['video_id'] = $response['id'];
    // Added entry in file browse
    $file_object = itg_octopus_api_check_exist_file_browse($filename, $file_size);
    $response_result['fid'] = (int) $file_object;
    try {
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
            'encoding_progress' => $response['encoding_progress'],
            'publishing_progress' => $response['publishing_progress'],
            'upload_time' => REQUEST_TIME,
            'video_duration' => $response['duration'],
            'dailymotion_published' => 0,
            'type' => 'S3',
            'name' => $response['name'],
          ))
          ->execute();
      $data['success'] = 'yes';
    }
    catch (Exception $e) {
      $data['success'] = 'no';
    }
    print json_encode($data);
    drupal_exit();
  }
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
    
  }
  return TRUE;
}
