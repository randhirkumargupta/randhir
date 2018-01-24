<?php

/**
 * Custom form defination for Daily motion dashboard.
 * @param array $form
 * @param array $form_state
 */
function daily_motion_video_dashboard($form, &$form_state) {

  $form['fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => 'Daily Motion Video Dashboard',
  );
  $form['fieldset']['video_name'] = array(
    '#type' => 'textfield',
    '#title' => 'Name',
    '#attributes' => array(
      'placeholder' => t('Name'),
    ),
    '#default_value' => isset($_GET['video_name']) ? $_GET['video_name'] : '',
  );
  $form['fieldset']['video_title'] = array(
    '#type' => 'textfield',
    '#title' => 'Title',
    '#attributes' => array(
      'placeholder' => t('Title'),
    ),
    '#default_value' => isset($_GET['video_title']) ? $_GET['video_title'] : '',
  );
  $form['fieldset']['channel'] = array(
    '#type' => 'select',
    '#title' => 'Channel',
    '#options' => array('' => '-All-', 'ftp' => 'FTP', 'LOCAL' => 'LOCAL', 'S3' => 'S3', 'OCTOPUS' => 'OCTOPUS', 'INTERNAL' => 'ITG Internal'),
    '#default_value' => isset($_GET['channel']) ? $_GET['channel'] : '',
  );
  $form['fieldset']['video_source'] = array(
    '#type' => 'select',
    '#title' => 'Video Source',
    '#options' => array('' => '-All-', 'DM' => 'Dailymotion', 'INTERNAL' => 'AWS Transcode'),
    '#default_value' => isset($_GET['video_source']) ? $_GET['video_source'] : '',
  );

  $form['fieldset']['from_time'] = array(
    '#type' => 'date_popup',
    '#title' => t("From"),
    '#date_format' => 'd/m/Y H:i',
    '#attributes' => array('autocomplete' => 'off', 'readonly' => 'readonly', 'placeholder' => 'From Date'),
    '#default_value' => isset($_GET['from_time']) ? $_GET['from_time'] : format_date(REQUEST_TIME, 'custom', 'd/m/Y H:i'),
    '#date_timezone' => date_default_timezone(),
  );
// Facebook video schdule time.
  $form['fieldset']['to_time'] = array(
    '#type' => 'date_popup',
    '#title' => t("To"),
    '#date_format' => 'd/m/Y H:i',
    '#attributes' => array('autocomplete' => 'off', 'readonly' => 'readonly', 'placeholder' => 'To Date'),
    '#default_value' => isset($_GET['to_time']) ? $_GET['to_time'] : format_date(REQUEST_TIME, 'custom', 'd/m/Y H:i'),
    '#date_timezone' => date_default_timezone(),
  );
  $form['fieldset']['video_id'] = array(
    '#type' => 'textfield',
    '#title' => 'Video ID',
    '#attributes' => array(
      'placeholder' => t('Video ID'),
    ),
    '#default_value' => isset($_GET['video_id']) ? $_GET['video_id'] : '',
  );
  $form['fieldset']['video_art_id'] = array(
    '#type' => 'textfield',
    '#title' => 'Video Article id',
    '#attributes' => array(
      'placeholder' => t('Video Article Id'),
    ),
    '#default_value' => isset($_GET['video_art_id']) ? $_GET['video_art_id'] : '',
  );

  $form['fieldset']['filtertype'] = array(
    '#type' => 'select',
    '#title' => 'Status',
    '#options' => array('' => '-Select-', '1' => 'Published', '0' => 'Unpublished'),
    '#submit' => array('ge_custom_search_report_search_submit_dis'),
    '#default_value' => isset($_GET['filtertype']) ? $_GET['filtertype'] : '',
  );

  $form['fieldset']['display_button'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#submit' => array('daily_motion_video_dashboard_submit'),
  );
  $form['filters']['buttons']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset'),
    '#limit_validation_errors' => TRUE,
    '#submit' => array('itg_videogallery_daily_motion_video_reset'));


  $form['markup'] = array(
    '#markup' => daily_motion_video_dashboard_rows(),
  );

  return $form;
}

/**
 * 
 * @param type $form
 * @param type $form_state
 * @param type $form_id
 */
function daily_motion_video_dashboard_validate($form, &$form_state, $form_id) {
  $flag = 0;
  if (!empty($form_state['values']['from_time']['date']) && empty($form_state['values']['from_time']['time'])) {

    $array_error['from_time[time]'] = t("Please Enter From Time.");
    $flag = 1;
  }
  if (!empty($form_state['values']['to_time']['date']) && empty($form_state['values']['to_time']['time'])) {
    $array_error['to_time[time]'] = t("Please Enter To Time.");
    $flag = 1;
  }
  if ($flag == 1) {
    drupal_get_messages('error');
    foreach ($array_error as $key => $msgs) {
      form_set_error(check_plain($key), check_plain($msgs));
    }
  }
}

/*
 * Submit handler for ITG dailymotion dashboard
 */

function daily_motion_video_dashboard_submit($form, &$form_state) {

  $video_id = $form_state['values']['video_id'];
  $video_art_id = $form_state['values']['video_art_id'];
  $filtertype = $form_state['values']['filtertype'];
  $video_name = $form_state['values']['video_name'];
  $video_title = $form_state['values']['video_title'];
  $video_source = $form_state['values']['video_source'];
  $channel = $form_state['values']['channel'];
  $totime = $form_state['values']['to_time'];
  $fromtime = $form_state['values']['from_time'];
  drupal_goto('daily-motion-video-dashboard', array('query' => array(
      'video_title' => $video_title,
      'video_name' => $video_name,
      'channel' => $channel,
      'video_source' => $video_source,
      'filtertype' => $filtertype,
      'video_id' => $video_id,
      'video_art_id' => $video_art_id,
      'from_time' => $fromtime,
      'to_time' => $totime,
  )));
}

/**
 * This method returns the number of rows
 */
function daily_motion_video_dashboard_rows() {
  global $base_url;
  drupal_add_js(drupal_get_path('module', 'itg_videogallery') . '/js/itg_videogallery_dashbord.js', array('weight' => 1, 'scope' => 'footer'));
  $filtertype = isset($_GET['filtertype']) ? $_GET['filtertype'] : '';
  $video_id = isset($_GET['video_id']) ? $_GET['video_id'] : '';
  $video_art_id = isset($_GET['video_art_id']) ? $_GET['video_art_id'] : '';
  $video_title = isset($_GET['video_title']) ? $_GET['video_title'] : '';
  $video_source = isset($_GET['video_source']) ? $_GET['video_source'] : '';
  $video_name = isset($_GET['video_name']) ? $_GET['video_name'] : '';
  $channel = isset($_GET['channel']) ? $_GET['channel'] : '';
  $to_time = isset($_GET['to_time']) ? $_GET['to_time'] : '';
  $from_time = isset($_GET['from_time']) ? $_GET['from_time'] : '';
  $to_time = strtotime($to_time);
  $from_time = strtotime($from_time);
  $data = array();
  $html = '';
  $rows = array();
  $header = array(
    t('Sn no.'),
    t('Name'),
    t('Title'),
    t('Channel'),
    t('Uploaded Time'),
    t('Video Id'),
    t('Video Article ID'),
    t('Duration'),
    t('Video Status'),
    t('Status'),
    t('Action'),
  );

  $query = db_select('dailymotion_response_details', 'n');
  $query->fields('n');
  if (isset($filtertype) && $filtertype != "") {
    $query->condition('n.dailymotion_published', $filtertype, '=');
  }
  if (isset($video_id) && !empty($video_id)) {
    $query->condition('n.video_id', $video_id, '=');
  }
  if (isset($video_art_id) && !empty($video_art_id)) {
   $query->join('itg_solr_video_info', 'isvi', 'isvi.solr_video_id = n.video_id');
   $query->condition('isvi.nid', $video_art_id, '=');
   }
  if (isset($video_name) && !empty($video_name)) {

    $query->condition('n.name', '%' . db_like($video_name) . '%', 'LIKE');
  }
  if (isset($video_title) && !empty($video_title)) {

    $query->condition('n.title', '%' . db_like($video_title) . '%', 'LIKE');
  }
  if (isset($channel) && !empty($channel)) {

    $query->condition('n.type', $channel, '=');
  }
  if (isset($video_source) && !empty($video_source)) {

    $query->condition('n.video_type', $video_source, '=');
  }
  if (isset($from_time) && !empty($from_time)) {

    $query->condition('n.upload_time', $from_time, '>=');
  }
  if (isset($to_time) && !empty($to_time)) {

    $query->condition('n.upload_time', $to_time, '<=');
  }
  $pagelimit = 20;
  $query = $query->extend('PagerDefault')->limit($pagelimit);
  $query->orderBy('n.eid', 'DESC');
  $result = $query->execute();
  $num_of_results = $result->rowCount();
  $sn = 1;
  if (isset($_GET['page']) && !empty($_GET['page'])) {
    $sn = $pagelimit * $_GET['page'] + 1;
  }
  while ($record = $result->fetchObject()) {
    if ($record->dailymotion_published == 1) {
      $status_flag = '<span class="used-video">Used</span>';
      $delete_link = '';
       $nid = itg_videogallery_get_nid_by_video_id( $record->video_id);
     }
    else {
      $nid = "";
      $record->nid = "";
      if ($record->encoding_progress == '100') {
        $status_flag = '<span class="ready-to-use-video">Ready To Use</span>';
        if (strtoupper($record->type) != 'LOCAL') {
          $delete_link = "<a  class='dalymotion-video-delete' href='" . $base_url . "/delete_daily_motion_video/" . $record->video_id . "' > Delete </a>";
        }
      }
      if ($record->encoding_progress != '100' && $record->publishing_progress != '100') {
        if ($record->video_type == 'INTERNAL') {
          $status_flag = '<span class="under-precess">Completed</span>';
        }
        else {
          $status_flag = '<span class="under-precess">Processing (' . $record->publishing_progress . ')%</span>';
        }
        if (strtoupper($record->type) != 'LOCAL') {
          $delete_link = "<a  class='dalymotion-video-delete' href='" . $base_url . "/delete_daily_motion_video/" . $record->video_id . "' > Delete </a>";
        }
      }
      if ($record->encoding_progress != '100' && $record->publishing_progress == '100') {

        $status_flag = '<span class="under-precess">Ready to Use</span>';

        if (strtoupper($record->type) != 'LOCAL') {
          $delete_link = "<a  class='dalymotion-video-delete' href='" . $base_url . "/delete_daily_motion_video/" . $record->video_id . "' > Delete </a>";
        }
      }

      if ($record->encoding_progress == '100' && $record->publishing_progress == '100') {
        if ($record->is_draft) {
          $status_flag = '<span class="under-precess">Draft</span>';
          $delete_link = "";
        }
        else {
          $status_flag = '<span class="under-precess">Completed</span>';
          if ($record->dailymotion_published == 0) {
            $delete_link = "<a  class='dalymotion-video-delete' href='" . $base_url . "/delete_daily_motion_video/" . $record->video_id . "' > Delete </a>";
          }
        }
      }
    }
    if ($record->is_draft == 1) {
      $status_flag = '<span class="under-precess">Draft</span>';
      $delete_link = "";
    }
    if ($record->node_is_save_draft == 1) {
      $status_flag = '<span class="under-precess">Draft</span>';
      $delete_link = "";
    }
    if ($record->dailymotion_published == 1) {
      $video_status = 'Published';
    }
    else {
      $video_status = 'Unpublished';
    }
    $page_no = $_GET['page'];
    $rows[] = array(
      $sn++,
      $record->name,
      $record->title,
      strtoupper($record->type),
      date('d-M-Y H:i:s', $record->upload_time),
      $record->video_id,
      $nid,
      $record->video_duration,
      $video_status,
      $status_flag,
      $delete_link
    );
  }
  $total = count($rows);
  $html .= theme('table', array('header' => $header, 'rows' => $rows));
  $html .= theme('pager');
  return $html;
}
/**
 * function get node id by fid
 */
function itg_videogallery_get_nid_by_video_id($vid) {
  $query = db_select('itg_solr_video_info', 'drd');
  $query->fields('drd', array('nid'));
  $query->condition('solr_video_id', $vid, '=');
  $query->condition('content_type', 'video_gallery', '=');
  $result = $query->execute()->fetchField();
  return $result;
}



/*
 * This callback use for delete video from local and daily motion
 */

function delete_daily_motion_video_callback() {
  $video_id = arg(1);
  $query = db_delete('dailymotion_response_details');
  $query->condition('video_id', $video_id);
  if ($query->execute()) {
    $video_info = itg_videogallery_get_video_solrcontent($video_id);
    if (!empty($video_info[0]->nid)) {

      itg_node_exclude($video_info[0]->nid);

      node_delete($video_info[0]->nid);
    }
// insert delete video in content type
    global $user;
    $node = new stdClass();
    $node->title = $video_id;
    $node->type = "itg_delete_solr_video";
    node_object_prepare($node); //Invokes hook_prepare() and hook_node_prepare().
    $node->language = LANGUAGE_NONE;
    $node->uid = $user->uid;
    $node->field_video_is_delete[LANGUAGE_NONE][0]['value'] = 1;
    $node->status = 1; //(1 or 0): Published or not
    $node->promote = 0; //(1 or 0): Promoted to front page
    $node->comment = 0; // 0 = Comments disabled, 1 = read only, 2 = read/write
    $getnode = itg_videogallery_get_node_by_title($video_id);
    if (!empty($getnode)) {
      $node->nid = $getnode[0]->nid;
    }
    node_save($node);
    drupal_set_message(t('Video has been deleted successfully'));
    drupal_goto('daily-motion-video-dashboard');
  }
}


function itg_videogallery_get_publish_status() {
  $video_ids = $_GET['remoteIds'];
  if (!empty($video_ids)) {
    $video_ids = explode(',', $video_ids);
    $video_ids = array_map(function($vid) {
      return 'PROD' . $vid;
    }, $video_ids);
    $query = db_select('dailymotion_response_details', 'drd');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'pd', 'pd.entity_id=drd.nid');
    $query->fields('drd', array('nid', 'video_id', 'dailymotion_published', 'upload_time'));
    $query->fields('pd', array('field_itg_content_publish_date_value'));
    $query->condition('drd.video_id', $video_ids, 'IN');
    $query->condition('drd.dailymotion_published', 1);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = '<chanel>';
    foreach ($result as $value) {
      $publish_as = $value['nid'];
      $video_id = str_replace('PROD', '', $value['video_id']);
      $time_stamp = (empty($value['field_itg_content_publish_date_value']) ? $value['upload_time'] : strtotime($value['field_itg_content_publish_date_value']));
      $publish_datetime = date("Y-m-d H:i:s", $time_stamp);
      $xml .= '<item>';
      $xml .= '<id> ' . $video_id . ' </id>';
      $xml .= '<publish_as> ' . $publish_as . ' </publish_as>';
      $xml .= '<publish_datetime> ' . $publish_datetime . ' </publish_datetime>';
      $xml .= '</item>';
    }
    $xml .= '</chanel>';
    header('Content-Type: application/xml; charset=utf-8');
    print $xml;
    drupal_exit();
  }
}