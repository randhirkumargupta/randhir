<?php
/**
 * Implements function for get options for Local FTP file list and used
 * @return array
 */
function itg_videogallery_ftp_file_insert_cron() {

  global $user;
  $file_path = drupal_realpath('public://');
  $connection_id = itg_videogallery_ftp_video_list();
  ftp_pasv($connection_id, TRUE);
  $ftp_video_folder = variable_get('ftp_upload_video_folder', '');
  $ftp_filess = ftp_nlist($connection_id, "/" . FOLDER_FTP_ROOT . "/" . $ftp_video_folder . "/");

  foreach ($ftp_filess as $files_n) {

    $file_data_array = explode('/' . FOLDER_FTP_ROOT . '/' . $ftp_video_folder . '/', $files_n);
    $path_info_data = pathinfo($file_data_array[1]);
    $filename = $path_info_data['filename'];
    $extension = $path_info_data['extension'];
    $exist_space = preg_match('/\s/', $filename);
    if ($exist_space) {
      $newfile = str_replace(' ', '_', $filename);
      ftp_rename($connection_id, $files_n, '/' . FOLDER_FTP_ROOT . '/' . $ftp_video_folder . '/' . $newfile . '.' . $extension);
    }
  }

  $ftp_files = ftp_nlist($connection_id, "/" . FOLDER_FTP_ROOT . "/" . $ftp_video_folder . "/");
  foreach ($ftp_files as $files) {
    $file_array = explode('/' . FOLDER_FTP_ROOT . '/' . $ftp_video_folder . '/', $files);

    $path_info = pathinfo($file_array[1]);
    $extension = $path_info['extension'];
    $filename = $path_info['filename'];
    if (isset($extension) && $extension == 'mp4') {
      $file_size = ftp_size($connection_id, $files);
      $url_to_check = FTP_URL_VIDEO . $file_array[1];
      $fileresize = ftp_size($connection_id, $files);


      if ($fileresize == $file_size) {
        $existfile = check_file_already_exist_or_not_by_ftp($file_array[1]);
        if (empty($existfile)) {

          $realfilename = check_file_already_exist_or_not($file_array[1]);

// Adding managed file
          $uri = 'public://' . LOCAL_VIDEO_DIR . '/' . date('Ym') . '/' . $realfilename;
          try {

            $fid = db_insert('file_managed')
                ->fields(array(
                  'uid' => $user->uid,
                  'filename' => $realfilename,
                  'uri' => $uri,
                  'filemime' => file_get_mimetype($uri),
                  'filesize' => $file_size,
                  'status' => 1,
                  'timestamp' => REQUEST_TIME,
                ))
                ->execute();
            $file = file_load($fid);
            file_usage_add($file, 'itg_videogallery', 'file', $file->fid);
          }
          catch (Exception $e) {
          }

          $file_details = file_load($fid);
          $real_path = drupal_realpath($file_details->uri);
          $response = itg_videogallery_dailymotion_add_video($real_path, $file_array[1], $realfilename, $fid);
// Perform playlist and tags when new video create.

          if (!empty($response)) {
            $response_result['video_id'] = $response['id'];
            $response_result['fid'] = $response['fid'];
            try {

              $nid = db_insert('dailymotion_response_details')
                  ->fields(array(
                    'title' => $response['title'],
                    'channel' => $response['channel'], 
                    'video_type' => 'DM',
                    'fid' => $response['fid'],
                    'tags' => ' ',
                    'video_id' => $response['id'],
                    'nid' => 0,
                    'video_size' => $file_size,
                    'encoding_progress' => $response['encoding_progress'],
                    'publishing_progress' => $response['publishing_progress'],
                    'upload_time' => REQUEST_TIME,
                    'video_duration' => $response['duration'],
                    'dailymotion_published' => 0,
                    'type' => 'ftp',
                    'name' => $file_array[1],
                  ))
                  ->execute();
              $title = $_POST['title'];
// data insert into node
            }
            catch (Exception $e) {
            }
// Code start for Adding  video in daily motion 
          }
        }
      }
    }
  }

  ftp_close($connection_id);
}

/**
 * This is temp function use for test dailymotion video resploce no we will 
 */
function itg_videogallery_video_update_embeded_url() {
  $api = itg_videogallery_dailymotion_api();
  $query = db_select('itg_solr_video_info', 'drd');
  $query->fields('drd', array('solr_video_id', 'video_embedded_url'));
  $result = $query->execute()->fetchall();
  foreach ($result as $vid) {
    if ($vid->video_embedded_url != "") {
      itg_videogallery_update_embedcode_url($vid->solr_video_id);
    }
  }
}

/**
 * Implements function for get options for FTP file list
 * @return array
 */
function itg_videogallery_ftp_file_insert() {
  $file_path = drupal_realpath('public://');
  $connection_id = itg_videogallery_ftp_video_list();
  ftp_pasv($connection_id, TRUE);
  $ftp_video_folder = variable_get('ftp_upload_video_folder', '');
  $ftp_files = ftp_nlist($connection_id, "/" . FOLDER_FTP_ROOT . "/" . $ftp_video_folder . "/");

  ftp_close($connection_id);
  foreach ($ftp_files as $files) {
    $file_array = explode('/' . FOLDER_FTP_ROOT . '/' . $ftp_video_folder . '/', $files);
    $path_info = pathinfo($file_array[1]);
    $extension = $path_info['extension'];
    if (isset($extension) && $extension == 'mp4') {
      itg_video_check_exist_file_browse($file_array[1]);
    }
  }
}

/**
 * Implements function check exist filename
 * @param array $form
 * @param array $form_state
 * @return string
 */
function itg_video_check_exist_file_browse($filename) {
  global $user;
  $connection_id = itg_videogallery_ftp_video_list();
  $ftp_video_folder = variable_get('ftp_upload_video_folder', '');
  ftp_pasv($connection_id, TRUE);
  $ftp_files = ftp_nlist($connection_id, "/" . FOLDER_FTP_ROOT . "/" . $ftp_video_folder . "/");
  $results = itg_videogallery_getfile_details($filename);
  if ($results == '' && empty($results)) {
    $file_size = ftp_size($connection_id, '/' . FOLDER_FTP_ROOT . '/' . $ftp_video_folder . '/' . $filename);
    if ($res != -1) {
      $path_info = pathinfo($filename);
      $extension = $path_info['extension'];
      if (isset($extension) && $extension == 'mp4') {
        $uri = 'public://' . LOCAL_VIDEO_DIR . '/' . date('Ym') . '/' . $filename;
        $fid = db_insert('file_managed')
            ->fields(array(
              'uid' => $user->uid,
              'filename' => $filename,
              'uri' => $uri,
              'filemime' => file_get_mimetype($uri),
              'filesize' => $file_size,
              'status' => 1,
              'timestamp' => REQUEST_TIME,
            ))
            ->execute();
        $file = file_load($fid);
        file_usage_add($file, 'itg_videogallery', 'file', $file->fid);
// Entry for FTP Video
        db_insert('itg_dailymotion_ftp_video')
            ->fields(array(
              'fid' => $fid,
            ))
            ->execute();
      }
    }
  }
  ftp_close($connection_id);
  return $results;
}

/**
 * Implements function for get FTP exist file
 * @param string $filename
 * @return array
 */
function itg_videogallery_getfile_details($filename) {
  $uri = 'public://' . LOCAL_VIDEO_DIR . '/' . date('Ym') . '/' . $filename;
  $query = db_select('file_managed', 'fm');
  $query->condition('filename', $filename, '=');
  $query->condition('uri', $uri, '=');
  $query->fields('fm');
  $query->orderBy('fm.fid', 'DESC');
  $query->range(0, 1);
  $results = $query->execute()->fetchAssoc();
  return $results;
}

/**
 * This method is used to add the video for daily motion from FTP
 * @return array
 */
function itg_videogallery_dailymotion_add_video($real_path, $name, $realfilename, $fid) {

  $api = itg_videogallery_dailymotion_api();
  try {

    $ftp_file = explode('public://' . LOCAL_VIDEO_DIR . '/' . date('Ym') . '/', $real_path);
    $uri = 'public://dailymotion-ftp/' . $realfilename;
    $url = FTP_URL_VIDEO . $name;

    $result = $api->post(
        '/me/videos', array(
      'url' => $url,
      'title' => $realfilename,
      'channel' => 'tv',
      'private' => 'true',
      'published' => TRUE,
        )
    );

    $dur = $api->get(
        '/video/' . $result['id'], array('fields' => array('duration', 'encoding_progress', 'publishing_progress'))
    );
    $playlist_id = variable_get('dailymotion_playlist_id');
    $result['duration'] = $dur['duration'];
    $result['encoding_progress'] = $dur['encoding_progress'];
    $result['publishing_progress'] = $dur['publishing_progress'];
    $a = new Dailymotion();
    $a->logout();
    $result['fid'] = $fid;
    $result['tags'] = $tags_value;
  }
  catch (Exception $e) {
    if ($e->getMessage() == "This `client_id' doesn't exist.") {
      if (isset($_GET['destination'])) {
        unset($_GET['destination']);
      }
      drupal_set_message(t('API Key is wrong.'), 'error');
    }
    elseif ($e->getMessage() == "Invalid `client_secret'") {
      if (isset($_GET['destination'])) {
        unset($_GET['destination']);
      }
      drupal_set_message(t('Secret Key is wrong.'), 'error');
    }
    elseif ($e->getCode() == 6) {
      if (isset($_GET['destination'])) {
        unset($_GET['destination']);
      }
      drupal_set_message(t('There is some issue with internet connection.'), 'error');
    }
    elseif ($e->getCode() == 400) {
      if (isset($_GET['destination'])) {
        unset($_GET['destination']);
      }
      drupal_get_messages();
      drupal_set_message(t('Do not use space in FTP filename. Please remove and again upload file without space in file name.'), 'error');
    }
    else {
      drupal_set_message($e->getMessage(), 'error');
    }
  }

  return $result;
}