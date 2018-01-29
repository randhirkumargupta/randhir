<?php

/**
 * @file
 * ITG Videogallery inc.
 */

/**
 * Impelements form for configuration.
 * {@inheritdoc}
 */
function itg_videogallery_ftp_video_form($form) {
  $form['dailymotion_ftp_url'] = array(
    '#type' => 'textfield',
    '#title' => t('FTP URL'),
    '#default_value' => variable_get('dailymotion_ftp_url', ''),
    '#required' => TRUE,
  );

  $form['dailymotion_ftp_host'] = array(
    '#type' => 'textfield',
    '#title' => t('Host Name'),
    '#default_value' => variable_get('dailymotion_ftp_host', ''),
    '#required' => TRUE,
  );
  $form['ftp_upload_video_folder'] = array(
    '#type' => 'textfield',
    '#title' => t('Video Folder'),
    '#default_value' => variable_get('ftp_upload_video_folder', ''),
    '#required' => TRUE,
  );
  $form['ftp_move_archive'] = array(
    '#type' => 'textfield',
    '#title' => t('Video Moved In'),
    '#default_value' => variable_get('ftp_move_archive', ''),
    '#required' => TRUE,
  );
  $form['dailymotion_ftp_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Ftp Username'),
    '#default_value' => variable_get('dailymotion_ftp_username'),
    '#required' => TRUE,
  );
  $form['dailymotion_ftp_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Ftp Password'),
    '#default_value' => variable_get('dailymotion_ftp_password', ''),
    '#required' => TRUE,
  );
  $form['ftp_root_folder'] = array(
    '#type' => 'textfield',
    '#title' => t('Ftp Root Folder'),
    '#default_value' => variable_get('ftp_root_folder', ''),
    '#required' => TRUE,
  );
  $form['xml_root_folder'] = array(
    '#type' => 'textfield',
    '#title' => t('Video XML Folder'),
    '#default_value' => variable_get('xml_root_folder', ''),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

/**
 * Impelements form for configuration.
 * {@inheritdoc}
 */
function itg_videogallery_s3_video_form($form) {

  $form['aws_access_key'] = array(
    '#type' => 'textfield',
    '#title' => t('AWS S3 Access Key'),
    '#default_value' => variable_get('aws_access_key', ''),
    '#required' => TRUE,
  );
  $form['aws_secret_key'] = array(
    '#type' => 'textfield',
    '#title' => t('AWS S3 Secret Key'),
    '#default_value' => variable_get('aws_secret_key', ''),
    '#required' => TRUE,
  );
  $form['aws_region'] = array(
    '#type' => 'textfield',
    '#title' => t('AWS S3 Region'),
    '#default_value' => variable_get('aws_region', ''),
    '#required' => TRUE,
  );
  $form['aws_video_dir'] = array(
    '#type' => 'textfield',
    '#title' => t('AWS S3 Video Dir'),
    '#default_value' => variable_get('aws_video_dir', ''),
    '#description' => 'Example : s3fs-public/dailymotion_video/',
    '#required' => TRUE,
  );
  $form['aws_video_dir_to_move'] = array(
    '#type' => 'textfield',
    '#title' => t('AWS S3 Old Video Dir'),
    '#default_value' => variable_get('aws_video_dir_to_move', ''),
    '#description' => 'Example : s3fs-public/dailymotion_video/',
    '#required' => TRUE,
  );

  $form['aws_bucket'] = array(
    '#type' => 'textfield',
    '#title' => t('AWS S3 Bucket'),
    '#default_value' => variable_get('aws_bucket', ''),
    '#required' => TRUE,
  );

  $form['api_bucket'] = array(
    '#type' => 'textfield',
    '#title' => t('API S3 Bucket'),
    '#default_value' => variable_get('api_bucket', ''),
  );

  $form['aws_video_dm_data'] = array(
    '#type' => 'textfield',
    '#title' => t('AWS S3 Video DM Data Folder'),
    '#default_value' => variable_get('aws_video_dm_data', ''),
    '#required' => TRUE,
  );
  $form['local_s3_video_folder'] = array(
    '#type' => 'textfield',
    '#title' => t('Local Video Folder'),
    '#default_value' => variable_get('local_s3_video_folder', ''),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

/**
 * 
 */
function _get_dfp_tags_by_id($id) {
  $query = db_select('itg_dfp_tags_setting', 'idts');
  $query->fields('idts');
  $query->condition('id', $id, '=');
  $result = $query->execute()->fetchAll();
  return $result;
}

/**
 * Impelements form for ITG DFP Tags .
 * {@inheritdoc}
 */
function itg_videogallery_dfp_tags_setting_form($form, &$form_state) {

  $data_form = _get_dfp_tags_by_id(arg(1));
  $website_options = array(
    'indiatoday' => 'Indiatoday',
    'idaplex' => 'Idaplex',
  );
  $form['wesbite'] = array(
    '#type' => 'select',
    '#title' => t('Website'),
    '#options' => $website_options,
    '#default_value' => ($data_form[0]->wesbite) ? $data_form[0]->wesbite : '',
    '#required' => TRUE
  );

  $client_options = array(
    'internal' => 'Internal',
    'ruptly' => 'Ruptly',
    'amazon' => 'Amazon'
  );
  $form['client'] = array(
    '#type' => 'select',
    '#title' => t('Client'),
    '#options' => $client_options,
    '#default_value' => ($data_form[0]->client) ? $data_form[0]->client : '',
    '#required' => TRUE,
  );
  $form['dfp_tags'] = array(
    '#type' => 'textarea',
    '#default_value' => ($data_form[0]->dfp_tags) ? $data_form[0]->dfp_tags : '',
    '#title' => t('Page DFP Tags '),
  );
  $form['hidden_id'] = array(
    '#type' => 'hidden',
    '#default_value' => ($data_form[0]->id) ? $data_form[0]->id : '',
  );
  $form['dfp_tags_internal'] = array(
    '#type' => 'textarea',
    '#default_value' => ($data_form[0]->dfp_tags_internal) ? $data_form[0]->dfp_tags_internal : '',
    '#title' => t('Embed DFP Tags Internal'),
  );
  $form['dfp_tags_external'] = array(
    '#type' => 'textarea',
    '#default_value' => ($data_form[0]->dfp_tags_external) ? $data_form[0]->dfp_tags_external : '',
    '#title' => t('Embed DFP Tags External'),
  );
  $form['ga_tag_internal'] = array(
    '#type' => 'textfield',
    '#default_value' => ($data_form[0]->ga_tag_internal) ? $data_form[0]->ga_tag_internal : '',
    '#title' => t('GA Tags Internal'),
  );
  $form['ga_tag_extarnal'] = array(
    '#type' => 'textfield',
    '#default_value' => ($data_form[0]->ga_tag_extarnal) ? $data_form[0]->ga_tag_extarnal : '',
    '#title' => t('GA Tags External'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );

  return $form;
}

/**
 * {@inheritdoc}
 * @param type $form
 * @param type $form_state
 */
function itg_videogallery_dfp_tags_setting_form_submit($form, &$form_state) {

  $wesbite = $form_state['values']['wesbite'];
  $client = $form_state['values']['client'];
  $dfp_tags = $form_state['values']['dfp_tags'];
  $dfp_tags_internal = $form_state['values']['dfp_tags_internal'];
  $dfp_tags_external = $form_state['values']['dfp_tags_external'];
  $ga_tag_internal = $form_state['values']['ga_tag_internal'];
  $ga_tag_extarnal = $form_state['values']['ga_tag_extarnal'];
  if ($form_state['values']['hidden_id'] > 0) {
     $result = db_update('itg_dfp_tags_setting')
        ->condition('id', $form_state['values']['hidden_id'], '=')
        ->fields(array(
          'wesbite' => $wesbite,
          'client' => $client,
          'dfp_tags' => $dfp_tags,
          'dfp_tags_internal' => $dfp_tags_internal,
          'dfp_tags_external' => $dfp_tags_external,
          'ga_tag_internal' => $ga_tag_internal,
          'ga_tag_extarnal' => $ga_tag_extarnal
        ))
        ->execute();
    drupal_set_message(t('DFP Tags Configuration update successfully '));
    drupal_goto('itg-dfp-tags-list');
  }
  else {
    $result = db_merge('itg_dfp_tags_setting')
        ->key(array('wesbite' => $wesbite, 'client' => $client))
        ->fields(array(
          'wesbite' => $wesbite,
          'client' => $client,
          'dfp_tags' => $dfp_tags,
          'dfp_tags_internal' => $dfp_tags_internal,
          'dfp_tags_external' => $dfp_tags_external,
          'ga_tag_internal' => $ga_tag_internal,
          'ga_tag_extarnal' => $ga_tag_extarnal
        ))
        ->execute();
    drupal_set_message(t('DFP Tags Configuration Saved successfully '));
    drupal_goto('itg-dfp-tags-list');
  }
}

/**
 * Custom form defination for DFP Tags list .
 * @param array $form
 * @param array $form_state
 */
function itg_videogallery_dfp_tags_list() {
 $form['fieldset'] = array(
    '#markup' => l(t('Add'), '/itg-dfp-tags-setting', array('attributes' => array('class' => 'btn-submit'))),
  );

  $form['markup'] = array(
    '#markup' => itg_videogallery_dfp_tags_list_data(),
  );

  return $form;
}

/**
 * This method returns the number of rows
 */
function itg_videogallery_dfp_tags_list_data() {
  global $base_url;
  drupal_add_js(drupal_get_path('module', 'itg_videogallery') . '/js/itg_videogallery_dashbord.js', array('weight' => 1, 'scope' => 'footer'));

  $data = array();
  $html = '';
  $rows = array();
  $header = array(
    t('Sn no.'),
    t('Website'),
    t('Client'),
    t('Action'),
  );

  $query = db_select('itg_dfp_tags_setting', 'idts');
  $query->fields('idts');
  $pagelimit = 20;
  $query = $query->extend('PagerDefault')->limit($pagelimit);
  $query->orderBy('idts.id', 'DESC');
  $result = $query->execute();
  $num_of_results = $result->rowCount();
  $sn = 1;
  if (isset($_GET['page']) && !empty($_GET['page'])) {
    $sn = $pagelimit * $_GET['page'] + 1;
  }
  while ($record = $result->fetchObject()) {
    $edit_link = "<a  class='itg-dfp-tags-edit' href='" . $base_url . "/itg-dfp-tags-setting/" . $record->id . "' > Edit </a>";
    $page_no = $_GET['page'];
    $rows[] = array(
      $sn++,
      ucfirst($record->wesbite),
      ucfirst($record->client),
      $edit_link
    );
  }
  $total = count($rows);
  $html .= theme('table', array('header' => $header, 'rows' => $rows));
  $html .= theme('pager');
  return $html;
}

/**
 * This function use for get file daily motion file details.
 */
function itg_videogallery_dm_embed() {
  $video_id = arg(1);
  $data_video_info = itg_videogallery_info_by_video_id_form_itg_solr_video($video_id);
  if($data_video_info[0]->video_repo_type == 'INTERNAL') {
  print  theme('itg_videogallery_internal_video_play', array('video_data' => $data_video_info[0]->video_xml_data, 'width'=>600 , 'height'=>400 ));
  }else {
  $api = itg_videogallery_dailymotion_api();
  $thumb_url = $api->get(
      '/video/' . $video_id, array('fields' => array('embed_url'))
  );
  $embed_id = "";
  if ($thumb_url['embed_url']) {
    $embed_id = end(explode('/', $thumb_url['embed_url']));
  }
  return theme('itg_videogallery_dm_embed', array('video_id' => $embed_id));
  }
}

/**
 * This function use for get file daily motion video to play.
 */
function itg_videogallery_getvideoplayer() {
  $fid= $_GET['fid'];
  $getvideousedon= $_GET['getvideousedon'];
  $tabindex = $_GET['tabindex'];
  $video_title = $_GET['video_title'];
  $video_data = itg_videogallery_get_video_info_by_fid($fid);
  $nid = $_GET['nid'];
  if($video_data[0]->video_repo_type == 'INTERNAL') {
   print theme('internal_video_player' , array("data" => $fid , 'used_on' =>$getvideousedon,'title' => $video_title, 'nid' => $nid)); 
  }else {
  print theme('itg_videogallery_getvideoplayer' , array('video_data' => $video_data , 'tabindex' => $tabindex));
  }
}

/**
 * This function use for get file daily motion video to play.
 */
function itg_videogallery_getvideoplayer_migrated() {
  $image= $_GET['video_image'];
  $video_url = $_GET['video_url'];
  $getvideousedon = $_GET['getvideousedon'];
  $nid = $_GET['nid'];
  
   print theme('migrated_video_player', array("url" =>$video_url, 'nid' => $nid, 'image' => $image, 'used_on'=>$getvideousedon));
}

/**
 * This is temp function use for move Dailymotion send video to ftv Archive
 */
function itg_videogallery_move_ftp_videos() {
  global $user;
  module_load_include('inc', 'itg_videogallery', 'includes/itg_videogallery_aws_s3');
  $api = itg_videogallery_dailymotion_api();
  $totime = strtotime('-1 days', time());
  $query = db_select('dailymotion_response_details', 'drd');
  $query->fields('drd');
  $query->condition('upload_time', $totime, '>=');
  $result = $query->execute()->fetchall();
  $connection_id = itg_videogallery_ftp_video_list();
  ftp_pasv($connection_id, TRUE);
  $ftp_video_folder = variable_get('ftp_upload_video_folder', '');
  $ftp_move_archive = variable_get('ftp_move_archive', '');
  foreach ($result as $ke => $vid) {
    if ($vid->type == 'ftp') {
      $datefolder = date('Ym', $vid->upload_time);
      $file_name = '/' . FOLDER_FTP_ROOT . '/' . $ftp_video_folder . '/' . $vid->name;
      $file_name_to_folder = '/' . FOLDER_FTP_ROOT . '/' . $ftp_move_archive . '/' . $datefolder . '/';
      $file_name_to_folder_file = '/' . FOLDER_FTP_ROOT . '/' . $ftp_move_archive . '/' . $datefolder . '/' . $vid->name;
      $ftp_exist = ftp_chdir($connection_id, $file_name_to_folder);

      if (!$ftp_exist) {
        ftp_mkdir($connection_id, $file_name_to_folder);
      }
      if (ftp_rename($connection_id, $file_name, $file_name_to_folder_file)) {
      }
    }

    if ($vid->type == 'S3') {
      $datefolder = date('Ym', $vid->upload_time);

      $pav = itg_video_copy_onfile_to_anoter($vid->name, $datefolder);
    }
  }
}

/**
 * This function use for get file daily motion file details.
 */
function itg_videogallery_get_file_details() {
  $getids = $_POST['checkvalue'];
  global $base_url;
  $responce = "";
  foreach ($getids as $key => $file_value) {
    $video_id = explode('#', $file_value);
    $videoid = $video_id[0];
    if($video_id[8] != 'INTERNAL') {
    $api = itg_videogallery_dailymotion_api();
    $thumb_url = $api->get(
        '/video/' . $video_id[0], array('fields' => array('embed_url'))
    );
    }
    db_insert('itg_solr_video_info')
        ->fields(array(
          'fid' => 0,
          'solr_video_id' => $video_id[0],
          'solr_video_duration' => $video_id[4],
          'solr_video_size' => $video_id[1],
          'property' => $video_id[5],
          'content_type' => 'CK_Editor',
          'is_alredy_used' => 1,
          'video_repo_type' => $video_id[8],
           'video_xml_data' => $video_id[9],
          'solr_video_thumb' => $video_id[3],
        ))
        ->execute();
    if($video_id[8] != 'INTERNAL') {
    if ($thumb_url['embed_url']) {
      $video_id = end(explode('/', $thumb_url['embed_url']));
      $query = db_update('itg_solr_video_info')
          ->fields(array('video_embedded_url' => $video_id));
      $query->condition('solr_video_id', $video_id[0]);
      $query->execute();
    }
  }
    $responce .=' <iframe frameborder="0" scrolling="no" class="video_data" id="video_frame_' . $videoid . '" frameborder="0" src="' . FRONT_URL_VIDEO . '/embeded-video/' . $videoid . '" allowfullscreen></iframe>';

  }
  exit($responce);
}

/**
 * Implements function for get videoid by file id
 * @param int $fid
 */
function itg_videogallery_info_by_video_id_form_itg_solr_video($video_id) {
  $query = db_select('itg_solr_video_info', 'drd');
  $query->fields('drd');
  $query->condition('solr_video_id', $video_id, '=')->range(0, 1);
  $result = $query->execute()->fetchAll();
  return $result;
}

/**
 * @argument struing $bitrate_url, $video_name
 * @return $result array
 */
function itg_video_copy_onfile_to_anoter($video_name, $folder) {
    $bucket = variable_get('aws_bucket');
    $aws_access_key = variable_get('aws_access_key');
    $aws_secret_key = variable_get('aws_secret_key');
    $aws_region = variable_get('aws_region');
    $aws_video_dir = variable_get('aws_video_dir');
    $aws_video_dir_to_move = variable_get('aws_video_dir_to_move');
    $s3 = S3Client::factory(array('key' => $aws_access_key, 'secret' => $aws_secret_key, 'signature' => 'v4', 'region' => $aws_region));
    $result = $s3->copyObject(array(
        'Bucket' => $bucket,
        'Key' => urldecode($aws_video_dir_to_move . $folder . '/' . $video_name),
        'CopySource' => urldecode($bucket . '/' . $aws_video_dir . $video_name),
    ));
    if (!empty($result)) {
        $keyvalue = urldecode($aws_video_dir . $video_name);
        $result_delete = $s3->deleteObject(array(
            'Bucket' => $bucket,
            'Key' => $keyvalue
        ));
    }
}
