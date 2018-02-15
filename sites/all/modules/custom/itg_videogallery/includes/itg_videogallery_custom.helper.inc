<?php
/**
 * Implements custom submit for move video on dailymotion.
 * @param array $form
 * @param array $form_state
 */
function itg_videogallery_custom_submit($form, &$form_state) {
  global $user;
  $filedir = ITG_IMAGE_FOLDER . 'video/' . date('Ym');
  if (!file_exists(file_default_scheme() . '://' . $filedir)) {
    mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  }
  chmod(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  foreach ($form_state['values']['field_story_itg_tags'][LANGUAGE_NONE] as $tags) {
    $tag[] = $tags['name'];
  }
  $request_destination = $_REQUEST['destination'];

  if ($request_destination == 'published-video') {
    $redirect_path .= "?field_story_syndication_value_op=all";
    $form_state['redirect'] = $redirect_path;
  }
// code insert image in custom table
  $node_id = $form_state['node']->nid;
  $fids = array();
  $thumg_to_crop = "";
  foreach ($form_state['values']['field_video_upload']['und'] as $videofields) {
    if ((int) $videofields['field_videogallery_video_upload']['und'][0]['fid'] != 0) {
      $query = db_select('itg_solr_video_info', 'drd');
      $query->fields('drd', array('solr_video_thumb', 'solr_video_duration'));
      $query->condition('fid', $videofields['field_videogallery_video_upload']['und'][0]['fid'], '=');
      $video_image = $query->execute()->fetchAll();
      if (!empty($video_image[0]->solr_video_thumb)) {
        $thumg_to_crop = $video_image[0]->solr_video_thumb;
        $slor_video_duration = $video_image[0]->solr_video_duration;
        break;
      }
    }
  }
  $tag_value = implode(', ', $tag);
  $tags_value = trim($tag_value, ",");
// assign image in field after resize
  if ($form_state['values']['field_story_extra_large_image'][LANGUAGE_NONE][0]['fid'] == 0 || $form_state['values']['field_story_large_image'][LANGUAGE_NONE][0]['fid'] == 0 || $form_state['values']['field_story_medium_image'][LANGUAGE_NONE][0]['fid'] == 0 || $form_state['values']['field_story_small_image'][LANGUAGE_NONE][0]['fid'] == 0 || $form_state['values']['field_story_extra_small_image'][LANGUAGE_NONE][0]['fid'] == 0) {
    $image_url = $thumg_to_crop;
    if (!empty($image_url)) {

      $imagedata = file_get_contents($image_url);
      $image_url = 'itg' . time() . end(explode('/', $image_url));
      $image_extension = end(explode('.', $image_url));
      $file_data_temp = file_save_data($imagedata, file_default_scheme() . '://' . $image_url);
    }
    if (!empty($file_data_temp)) {
    // This code for resize all images 
      if ($form_state['values']['field_story_extra_large_image'][LANGUAGE_NONE][0]['fid'] == 0) {
        $file_image = file_load($file_data_temp->fid);
        $image = image_load($file_image->uri);
        $filepath = file_default_scheme() . '://' . $filedir;
        if (!empty($image)) {
          $scaled = image_scale_and_crop($image, EXTRA_LARGE_IMAGE_WIDTH, EXTRA_LARGE_IMAGE_HEIGHT);
          $image_name = $image_name . time();
          $sav = image_save($image, $filepath . '/' . $image_name . '.' . $image_extension);
          $uri = $filepath . '/' . $image_name . '.' . $image_extension;
          $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
          $file = new StdClass;
          $file->uid = $user->uid;
          $file->filename = basename($uri);
          $file->uri = $uri;
          $file->filemime = file_get_mimetype($uri);
          $file->filesize = @filesize($uri);
          $file->timestamp = REQUEST_TIME;
          $file->is_new = TRUE;
          $file->status = FILE_STATUS_PERMANENT;
          $file = file_save($file);
          file_usage_add($file, 'itg_videogallery', 'file', $file->fid);
          $form_state['values']['field_story_extra_large_image'][LANGUAGE_NONE][0]['fid'] = $file->fid;
        }
      }

      if ($form_state['values']['field_story_large_image'][LANGUAGE_NONE][0]['fid'] == 0) {
        $file_image = file_load($file_data_temp->fid);
        $image = image_load($file_image->uri);
        $filepath = file_default_scheme() . '://' . $filedir;
        if (!empty($image)) {
          $scaled = image_scale_and_crop($image, LARGE_IMAGE_WIDTH, LARGE_IMAGE_HEIGHT);
          $image_name = $image_name . time();
          $sav = image_save($image, $filepath . '/' . $image_name . '.' . $image_extension);
          $uri = $filepath . '/' . $image_name . '.' . $image_extension;
          $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
          $file = new StdClass;
          $file->uid = $user->uid;
          $file->filename = basename($uri);
          $file->uri = $uri;
          $file->filemime = file_get_mimetype($uri);
          $file->filesize = @filesize($uri);
          $file->timestamp = REQUEST_TIME;
          $file->is_new = TRUE;
          $file->status = FILE_STATUS_PERMANENT;
          $file = file_save($file);
          file_usage_add($file, 'itg_videogallery', 'file', $file->fid);
          $form_state['values']['field_story_large_image'][LANGUAGE_NONE][0]['fid'] = $file->fid;
        }
      }

      if ($form_state['values']['field_story_large_image'][LANGUAGE_NONE][0]['fid'] == 0) {
        $file_image = file_load($file_data_temp->fid);
        $image = image_load($file_image->uri);
        $filepath = file_default_scheme() . '://' . $filedir;
        if (!empty($image)) {
          $scaled = image_scale_and_crop($image, LARGE_IMAGE_WIDTH, LARGE_IMAGE_HEIGHT);
          $image_name = $image_name . time();
          $sav = image_save($image, $filepath . '/' . $image_name . '.' . $image_extension);
          $uri = $filepath . '/' . $image_name . '.' . $image_extension;
          $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
          $file = new StdClass;
          $file->uid = $user->uid;
          $file->filename = basename($uri);
          $file->uri = $uri;
          $file->filemime = file_get_mimetype($uri);
          $file->filesize = @filesize($uri);
          $file->timestamp = REQUEST_TIME;
          $file->is_new = TRUE;
          $file->status = FILE_STATUS_PERMANENT;
          $file = file_save($file);
          file_usage_add($file, 'itg_videogallery', 'file', $file->fid);
          $form_state['values']['field_story_large_image'][LANGUAGE_NONE][0]['fid'] = $file->fid;
        }
      }
      if ($form_state['values']['field_story_medium_image'][LANGUAGE_NONE][0]['fid'] == 0) {
        $file_image = file_load($file_data_temp->fid);
        $image = image_load($file_image->uri);
        if (!empty($image)) {
          $filepath = file_default_scheme() . '://' . $filedir;
          $scaled = image_scale_and_crop($image, MEDIUM_IMAGE_WIDTH, MEDIUM_IMAGE_HEIGHT);
          $image_name = $image_name . time();
          $sav = image_save($image, $filepath . '/' . $image_name . '.' . $image_extension);
          $uri = $filepath . '/' . $image_name . '.' . $image_extension;
          $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
          $file = new StdClass;
          $file->uid = $user->uid;
          $file->filename = basename($uri);
          $file->uri = $uri;
          $file->filemime = file_get_mimetype($uri);
          $file->filesize = @filesize($uri);
          $file->timestamp = REQUEST_TIME;
          $file->is_new = TRUE;
          $file->status = FILE_STATUS_PERMANENT;
          $file = file_save($file);
          file_usage_add($file, 'itg_videogallery', 'file', $file->fid);
          $form_state['values']['field_story_medium_image'][LANGUAGE_NONE][0]['fid'] = $file->fid;
        }
      }
      if ($form_state['values']['field_story_small_image'][LANGUAGE_NONE][0]['fid'] == 0) {
        $file_image = file_load($file_data_temp->fid);
        $image = image_load($file_image->uri);
        if (!empty($image)) {
          $filepath = file_default_scheme() . '://' . $filedir;
          $scaled = image_scale_and_crop($image, SMALL_IMAGE_WIDTH, SMALL_IMAGE_HEIGHT);
          $image_name = $image_name . time();
          $sav = image_save($image, $filepath . '/' . $image_name . '.' . $image_extension);
          $uri = $filepath . '/' . $image_name . '.' . $image_extension;
          $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
          $file = new StdClass;
          $file->uid = $user->uid;
          $file->filename = basename($uri);
          $file->uri = $uri;
          $file->filemime = file_get_mimetype($uri);
          $file->filesize = @filesize($uri);
          $file->timestamp = REQUEST_TIME;
          $file->is_new = TRUE;
          $file->status = FILE_STATUS_PERMANENT;
          $file = file_save($file);
          file_usage_add($file, 'itg_videogallery', 'file', $file->fid);
          $form_state['values']['field_story_small_image'][LANGUAGE_NONE][0]['fid'] = $file->fid;
        }
      }
      if ($form_state['values']['field_story_extra_small_image'][LANGUAGE_NONE][0]['fid'] == 0) {
        $file_image = file_load($file_data_temp->fid);
        $image = image_load($file_image->uri);
        if (!empty($image)) {
          $filepath = file_default_scheme() . '://' . $filedir;
          $scaled = image_scale_and_crop($image, EXTRA_SMALL_IMAGE_WIDTH, EXTRA_SMALL_IMAGE_HEIGHT);
          $image_name = $image_name . time();
          $sav = image_save($image, $filepath . '/' . $image_name . '.' . $image_extension);
          $uri = $filepath . '/' . $image_name . '.' . $image_extension;
          $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
          $file = new StdClass;
          $file->uid = $user->uid;
          $file->filename = basename($uri);
          $file->uri = $uri;
          $file->filemime = file_get_mimetype($uri);
          $file->filesize = @filesize($uri);
          $file->timestamp = REQUEST_TIME;
          $file->is_new = TRUE;
          $file->status = FILE_STATUS_PERMANENT;
          $file = file_save($file);
          file_usage_add($file, 'itg_videogallery', 'file', $file->fid);
          $form_state['values']['field_story_extra_small_image'][LANGUAGE_NONE][0]['fid'] = $file->fid;
        }
      }
    }
  }
  if ($_GET['destination'] == 'published-video') {
    unset($_GET['destination']);
    $redirect_path = 'published-video?field_story_syndication_value_op=all';
    $_GET['destination'] = $redirect_path;
  }
// here first video duration assign
  if (empty($form_state['values']['field_video_duration'][LANGUAGE_NONE][0]['value'])) {

    if ($vid_result['video_duration'] != '0') {
      $form_state['values']['field_video_duration'][LANGUAGE_NONE][0]['value'] = $slor_video_duration;
    }
  }
  if ($node_id != "") {
  // for update on DM
    $extralarge_image_fid = $form_state['values']['field_story_extra_large_image'][LANGUAGE_NONE][0]['fid'];
    $main_fids = array();
    $draft_msg_flag = 0;
    $video_desc = strip_tags($form_state['values']['field_story_expert_description'][LANGUAGE_NONE][0]['value']);
   // start loop of videos field collection
    foreach ($form_state['values']['field_video_upload']['und'] as $keys => $videofields) {

      if ((int) $videofields['field_videogallery_video_upload']['und'][0]['fid'] != 0) {
        $video_image = itg_videogallery_get_video_info_by_fid($videofields['field_videogallery_video_upload']['und'][0]['fid']);
        $main_fids[] = $videofields['field_videogallery_video_upload']['und'][0]['fid'];
        if (!empty($video_image)) {
          if($video_image[0]->video_repo_type != 'INTERNAL') {
          if ($video_image[0]->property == VIDEO_PROPERTY) {
            $private_status = $videofields['field_video_private']['und'][0]['value'];
            $video_title = $videofields['field_video_title']['und'][0]['value'];
            $video_thumb_fid = $videofields['field_video_thumbnail']['und'][0]['fid'];
            $exclude_ads = $videofields['field_include_ads']['und'][0]['value'];
            if ($video_thumb_fid == 0 || empty($video_thumb_fid)) {
              $video_thumb_fid = $extralarge_image_fid;
            }
            // Update tags,image title on DM
              itg_videogallery_update_tags_video_private($tag_value, $video_image[0]->solr_video_id, $private_status, $video_desc, $video_title, $video_thumb_fid, $exclude_ads);
             }
          
          // Update embed code of this video.
           itg_videogallery_update_embedcode_url($video_image[0]->solr_video_id);
          }
          $file_video = $video_image;
          // this function use for delete itg_solr_delete_vide nid
          itg_videogallery_delele_node_reuse_video($file_video[0]->solr_video_id);
          if ($form_state['node']->status == 1) {
            $num_updated = db_update('dailymotion_response_details') // Table name no longer needs {}
                ->fields(array(
                  'dailymotion_published' => 1,
                  'is_replace' => 0,
                  'node_is_save_draft' => 0
                ))
                ->condition('video_id', $file_video[0]->solr_video_id, '=')
                ->execute();
            itg_videogallery_update_video_info_solr($file_video[0]->solr_video_id);
          }

// update nid in video
          $is_node_draft = 0;
          if ($form_state['node']->status == 0) {
            $is_node_draft = 1;
          }
          $num_updated = db_update('itg_solr_video_info') // Table name no longer needs {}
              ->fields(array(
                'nid' => $node_id,
                'is_node_draft' => $is_node_draft,
              ))
              ->condition('fid', $videofields['field_videogallery_video_upload']['und'][0]['fid'], '=')
              ->execute();
        }
      }
    }

// check loavl upaod file
    $is_loacl = 0;
    try {
      if ($form_state['values']['field_story_facebook_video'][LANGUAGE_NONE][0]['fid'] != 0) {
        itg_videogallery_update_node_id_for_video_fid($node_id, $form_state['values']['field_story_facebook_video'][LANGUAGE_NONE][0]['fid']);
      }
      if ($form_state['values']['field_story_twitter_video'][LANGUAGE_NONE][0]['fid'] != 0) {
        itg_videogallery_update_node_id_for_video_fid($node_id, $form_state['values']['field_story_twitter_video'][LANGUAGE_NONE][0]['fid']);
      }
      itg_videogallery_node_publish_video_to_unpublish($node_id, $main_fids);
    }
    catch (Exception $e) {
      watchdog_exception('video fid delete', $e);
    }
  }
}

/**
 * Implements function for custom validate.
 * @param array $form
 * @param array $form_state
 */
function itg_videogallery_custom_validate($form, &$form_state) {
//schedule date & expiry date validation
  $node = $form_state['node'];
  $is_migrate_validate = 0;
  $current_time = time();
  $schedule_date = strtotime($form_state['values']['field_story_schedule_date_time'][LANGUAGE_NONE][0]['value']);
  $expiry_date = strtotime($form_state['values']['field_story_expiry_date'][LANGUAGE_NONE][0]['value']);
  if (isset($expiry_date) && ($schedule_date > $expiry_date)) {
    form_set_error('field_story_expiry_date', t("Expiry date should be greater then schedule start date"));
  }

  if ($expiry_date < $current_time) {
    form_set_error('field_story_expiry_date', t("Expiry date should be greater from now."));
  }
  foreach ($form_state['values']['field_video_upload']['und'] as $videofields) {

    if ((int) $videofields['field_videogallery_video_upload']['und'][0]['fid'] != 0) {
      $fids[] = (int) $videofields['field_videogallery_video_upload']['und'][0]['fid'];
    }
  }

  foreach ($form_state['values']['field_video_upload']['und'] as $videofields) {
    if ($videofields['field_migrated_video_url']['und'][0]['value'] != "" && $videofields != 'Add another item') {

      $is_migrate_validate = 1;
    }
  }
  if ($form_state['values']['field_story_source_type'][LANGUAGE_NONE][0]['value'] != 'migrated') {
    if (empty($fids) && $node->status == 1) {
      form_set_error('field_video_upload', t("Please select video."));
    }
  }

  if ($is_migrate_validate == 1 && !empty($fids)) {
    form_set_error('field_video_upload', t("Please Remove Migrated Video Url."));
  }
  if ($is_migrate_validate == 0) {
    if (!in_array($form_state['values']['field_story_source_type'][LANGUAGE_NONE][0]['value'], array('UGC', 'OCTOPUS'))) {
      $form_state['values']['field_story_source_type'][LANGUAGE_NONE][0]['value'] = "videogallery";
    }
    // Setting source type if request occured from Octopus rundown  
    if (isset($_GET['octopus_ref']) && !empty($_GET['octopus_ref'])) {
      $form_state['values']['field_story_source_type'][LANGUAGE_NONE][0]['value'] = "OCTOPUS";
    }
  }
}
