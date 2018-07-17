<?php

/**
 * This function use for get file daily motion file details.
 */
function itg_videogallery_internal_video_play() {
  $video_data = $_POST['videodata'];
  $data_from_solr = itg_videogallery_getsolr_data_for_internal_video($video_data);
  print theme('itg_videogallery_internal_video_play', array('video_data' => $data_from_solr[0], 'width' => $width, 'height' => $height));
}

/*
 * Submit handler for ITG video  Repo
 */

function itg_videogallery_ftp_template() {

  $field_id = $_GET['input_filed'];
  $file_field_name = $_GET['file_filed_name'];

  $settings = array();
  $settings['base_url'] = $base_url;
  $settings['video_field_id'] = $field_id;
  $settings['video_field_file'] = $file_field_name;
  drupal_add_js(array('itg_dailymotion' => array('settings' => $settings)), array('type' => 'setting'));
  drupal_add_js(drupal_get_path('module', 'itg_videogallery') . '/js/itg_dailymotion.js', array('weig
ht' => 1));
  return theme('itg_dailymotion_ftp_template');
}

/**
 * Implements cron function for get thumburl in dailymotion custom table
 */
function itg_videogallery_thumb_url() {
  itg_videogallery_remove_video_id_parent_site_delete_or_unpublish();
  $query = db_select('dailymotion_response_details', 'drd');
  $query->fields('drd');
  $db_or = db_or();
  $db_or->condition('encoding_progress', '100', '!=');
  $db_or->condition('drd.publishing_progress', '100', '!=');
  $db_or->isNull('drd.dailymotion_thumb_url');
  $db_or->isNull('drd.publishing_progress');
  $db_or->isNull('drd.encoding_progress');
  $query->condition($db_or);
  $query->condition('drd.video_type', 'DM', '=');
  $result = $query->execute()->fetchAll();
  $api = itg_videogallery_dailymotion_api();
  foreach ($result as $val) {
    try {
      if ($val->encoding_progress != "100" || $val->dailymotion_thumb_url == "" || $val->publishing_progress != "100") {
        $thumb_url = $api->get(
            '/video/' . $val->video_id, array('fields' => array('thumbnail_720_url', 'duration', 'encoding_progress', 'publishing_progress'))
        );

        $duration = '';
        if ($thumb_url['duration'] < 3600) {
          $duration = gmdate("i:s", $thumb_url['duration']);
        }
        else {
          $duration = gmdate("H:i:s", $thumb_url['duration']);
        }

        $image_url = $thumb_url['thumbnail_720_url'];
        db_update('dailymotion_response_details')
            ->fields(array(
              'dailymotion_thumb_url' => $image_url,
              'encoding_progress' => $thumb_url['encoding_progress'],
              'publishing_progress' => $thumb_url['publishing_progress'],
              'video_duration' => $duration
            ))
            ->condition('eid', $val->eid, '=')
            ->execute();
      }
    }
    catch (Exception $e) {
      
    }
  }
  $query = db_select('dailymotion_response_details', 'drd');
  $query->fields('drd');
  $query->condition('publishing_progress', '100', '=');
  $query->condition('video_type', 'DM', '=');
  $result_new = $query->execute()->fetchAll();
  $api = itg_videogallery_dailymotion_api();
  foreach ($result_new as $val) {
    if ($val->is_draft != 1) {
      $video_status_used = $val->dailymotion_published;
      $video_is_draft = 0;
    }
    else {
      $video_status_used = 0;
      $video_is_draft = 1;
    }
    global $user;
    $node = new stdClass();
    $node->title = $val->title;
    $node->type = "itg_solr_video";
    node_object_prepare($node); //Invokes hook_prepare() and hook_node_prepare().
    $node->language = LANGUAGE_NONE;
    $node->field_video_id[LANGUAGE_NONE][0]['value'] = $val->video_id;
    $node->field_property [LANGUAGE_NONE][0]['value'] = VIDEO_PROPERTY;
    $node->field_video_duration [LANGUAGE_NONE][0]['value'] = $val->video_duration;
    $node->field_video_used [LANGUAGE_NONE][0]['value'] = $video_status_used;
    $node->field_video_thumb_url[LANGUAGE_NONE][0]['value'] = $val->dailymotion_thumb_url;
    $node->field_video_size[LANGUAGE_NONE][0]['value'] = $val->video_size;
    $node->field_is_replace[LANGUAGE_NONE][0]['value'] = $val->is_replace;
    $node->field_video_type[LANGUAGE_NONE][0]['value'] = $val->video_type;
    $node->field_video_is_draft[LANGUAGE_NONE][0]['value'] = $video_is_draft;
    $node->uid = 1;
    $node->field_video_date_time[LANGUAGE_NONE][0]['value'] = date('Y-m-d H:i:s', $val->upload_time);
    $node->field_video_time[LANGUAGE_NONE][0]['value'] = date('Y-m-d H:i:s', $val->upload_time);
    $node->status = 1; //(1 or 0): Published or not
    $node->promote = 0; //(1 or 0): Promoted to front page
    $node->comment = 0; // 0 = Comments disabled, 1 = read only, 2 = read/write
    $video_exist_innode = itg_videogallery_get_video_solrcontent($val->video_id);
    if (!empty($video_exist_innode)) {
      $node->nid = $video_exist_innode[0]->nid;
      node_save($node);
    }
    node_save($node);
  }
  itg_videogallery_publish_node_after_video_ready_by_dm();
  itg_videogallery_remove_video_with_child();
// Here deleted video
// This crone use for remove video if parent site remove this video from video article
// This crone use for if node is publish.
  itg_videogallery_video_draft_node_check();
//on use for make publish node after check video status ready to play
}

/**
 * This function use for removed parent deleted video
 * 
 */
function itg_videogallery_remove_video_id_parent_site_delete_or_unpublish() {
  // Here remove unpublish video iframe.
  $query = db_select('itg_story_body_videos', 'isbv');
  $query->fields('isbv');
  $query->condition('is_node', '1');
  $video_data = $query->execute()->fetchAll();
  if (isset($video_data) && !empty($video_data)) {
    foreach ($video_data as $story_body_video) {
      $nid = $story_body_video->nid;
      $main_video_nid = base64_decode($story_body_video->video_id);
      $node_data = itg_videogallery_get_node_status($main_video_nid);
      if ($node_data == 0) {
        $node = node_load($nid);
        $node_body = $node->body['und'][0]['value'];
        preg_match_all('/src="([^"]+)"/', $node_body, $match);
        $video_url = $match[1];
        if (!empty($video_url)) {
          foreach ($video_url as $video_value) {
            $post_check = strpos($video_value, '/embed/' . $story_body_video->video_id);
            if ($post_check) {
              $ifreame = '<iframe allowfullscreen="" frameborder="0" height="480" src="' . $story_body_video->url . '" width="648"></iframe>';
              $html = str_replace($ifreame, "", $node_body);
              $node->body['und'][0]['value'] = $html;
              field_attach_update('node', $node);
              // delete video.
              $url = drupal_get_path_alias('node/' . $nid);
              if (function_exists('itg_akamai_clear_url')) {
                $url = drupal_get_path_alias('node/' . $nid);
                itg_akamai_clear_url($url);
              }
              db_delete('itg_story_body_videos')
                  ->condition('id', $story_body_video->id)
                  ->execute();
            }
          }
        }
      }
    }
  }


  $solr_data = itg_videogallery_getsolr_data_unpublish();
  $unpublish_video_id = $solr_data['unpubliash_video_id'];
  $unpublish_replace_id = $solr_data['replace_video'];
  $solr_data_deleted = itg_videogallery_getsolr_data();

  //  Here node dekete and unpublish
  if (!empty($solr_data_deleted)) {
    $query = db_select('itg_solr_video_info', 'drd');
    $query->fields('drd', array('fid', 'nid', 'solr_video_id', 'id', 'property', 'content_type'));
    $query->condition('solr_video_id', $solr_data_deleted, 'IN');
    $video_data = $query->execute()->fetchAll();
    if (!empty($video_data)) {
      $node_by_video = array();
      foreach ($video_data as $data_delete) {
        $node_by_videop['fid'][$data_delete->nid][] = $data_delete->fid;
        $node_by_videop['video_id'][$data_delete->nid][] = $data_delete->solr_video_id;
        if ($data_delete->content_type == 'video_gallery') {
          $node_by_videop['nid'][$data_delete->nid][] = $data_delete->nid;
          $node_by_videop['content_type'][$data_delete->nid] = $data_delete->content_type;
        }
      }

      foreach ($node_by_videop['fid'] as $nkey => $fids) {
        foreach ($fids as $nky => $vide_fid) {
          try {
            $getnode = itg_videogallery_get_node_by_title($vide_fid);
            if (!empty($getnode)) {
              node_delete($getnode[0]->nid);
            }

            $deleted = db_delete('file_managed')
                ->condition('fid', $vide_fid)
                ->execute();
            $deleted = db_delete('itg_solr_video_info')
                ->condition('fid', $vide_fid, ' = ')
                ->execute();
          }
          catch (Exception $e) {
            watchdog_exception('file manage delete', $e);
          }
        }
      }
      foreach ($node_by_videop['nid'] as $key => $nid) {
        $query = db_select('itg_solr_video_info', 'drd');
        $query->fields('drd', array('fid'));
        $query->condition('nid', $nid, 'IN');
        $query->condition('content_type', 'video_gallery', '=');
        $video_data = $query->execute()->fetchAll();
        if (count($video_data) <= 0) {
          $node_data = node_load($nid[0]);
          if (!empty($node_data)) {
            $node_data->status = 0;
            node_save($node_data);
          }
        }
      }
    }
  }

  $video_data = "";
  // Here corne for CK Editor.
  if (!empty($unpublish_video_id)) {
    $query = db_select('itg_story_body_videos', 'isbv');
    $query->fields('isbv');
    $query->condition('video_id', $unpublish_video_id, 'IN');
    $query->condition('is_node', '0');
    $video_data = $query->execute()->fetchAll();
    if (isset($video_data) && !empty($video_data)) {
      foreach ($video_data as $story_body_video) {
        $nid = $story_body_video->nid;
        $node = node_load($nid);
        $node_body = $node->body['und'][0]['value'];
        preg_match_all('/src="([^"]+)"/', $node_body, $match);
        $video_url = $match[1];
        if (!empty($video_url)) {
          foreach ($video_url as $video_value) {
            $post_check = strpos($video_value, '/embeded-video/' . $story_body_video->video_id);
            if ($post_check) {
              $ifreame = '<iframe allowfullscreen="" class="video_data" frameborder="0" id="video_frame_' . $story_body_video->video_id . '" scrolling="no" src="' . FRONT_URL_VIDEO . '/embeded-video/' . $story_body_video->video_id . '"></iframe>';
              $video_id = "$story_body_video->video_id";
              $html = str_replace($ifreame, "", $node_body);
              $node->body['und'][0]['value'] = $html;
              field_attach_update('node', $node);
              if (function_exists('itg_akamai_clear_url')) {
                $url = drupal_get_path_alias('node/' . $nid);
                itg_akamai_clear_url($url);
              }
              // delete video.
              db_delete('itg_story_body_videos')
                  ->condition('id', $story_body_video->id)
                  ->execute();
            }
          }
        }
      }
    }
  }


  //  Here node dekete and unpublish
  if (!empty($unpublish_replace_id)) {
    $query = db_select('itg_solr_video_info', 'drd');
    $query->fields('drd', array('fid', 'nid', 'solr_video_id', 'id', 'property', 'content_type'));
    $query->condition('solr_video_id', $unpublish_replace_id, 'IN');
    $video_data = $query->execute()->fetchAll();
    if (!empty($video_data)) {
      $node_by_video = array();
      foreach ($video_data as $data_delete) {
        $node_by_videop['fid'][$data_delete->nid][] = $data_delete->fid;
        $node_by_videop['video_id'][$data_delete->nid][] = $data_delete->solr_video_id;
        if ($data_delete->content_type == 'video_gallery') {
          $node_by_videop['nid'][$data_delete->nid][] = $data_delete->nid;
          $node_by_videop['content_type'][$data_delete->nid] = $data_delete->content_type;
        }
      }

      foreach ($node_by_videop['fid'] as $nkey => $fids) {
        foreach ($fids as $nky => $vide_fid) {
          try {

            $deleted = db_delete('file_managed')
                ->condition('fid', $vide_fid)
                ->execute();
            $deleted = db_delete('itg_solr_video_info')
                ->condition('fid', $vide_fid, ' = ')
                ->execute();
          }
          catch (Exception $e) {
            watchdog_exception('file manage delete', $e);
          }
        }
      }
      foreach ($node_by_videop['nid'] as $key => $nid) {
        $query = db_select('itg_solr_video_info', 'drd');
        $query->fields('drd', array('fid'));
        $query->condition('nid', $nid, 'IN');
        $query->condition('content_type', 'video_gallery', '=');
        $video_data = $query->execute()->fetchAll();
        if (count($video_data) <= 0) {
          $node_data = node_load($nid[0]);
          if (!empty($node_data)) {
            $node_data->status = 0;
            node_save($node_data);
          }
        }
      }
    }
  }
}

/**
 * Implement function make  node publish after check video status ready to play.
 */
function itg_videogallery_publish_node_after_video_ready_by_dm() {

  $node_video_id = array();
  $query = db_select('dailymotion_response_details', 'drd');
  $query->fields('drd', array('nid'));
  $query->addExpression('GROUP_CONCAT(video_id)', 'video_ids');
  $query->condition('drd.is_draft', '1', '=');
  $query->condition('drd.nid', 'null', '!=');
  $query->groupBy('nid');
  $result = $query->execute()->fetchAll();
  $video_ids = array();
  foreach ($result as $key => $video_id) {
    $node_flag = 0;
    $exception_flag = 0;
    $all_vid = explode(',', $video_id->video_ids);
    foreach ($all_vid as $keyof => $dmvid_id) {
      $api = itg_videogallery_dailymotion_api();
      try {
        if ($dmvid_id) {
          $dm_data = $api->get(
              '/video/' . $dmvid_id, array('fields' => array('thumbnail_720_url', 'duration', 'encoding_progress', 'publishing_progress'))
          );
          if ($dm_data['encoding_progress'] == 100 || $dm_data['publishing_progress'] == 100) {
            $image_url = $dm_data['thumbnail_720_url'];
            $query = db_update('dailymotion_response_details');
            $query->fields(array('dailymotion_published' => 1, 'dailymotion_thumb_url' => $image_url, 'encoding_progress' => $dm_data['encoding_progress'], 'publishing_progress' => $dm_data['publishing_progress']));
            $query->condition('video_id', $dmvid_id, '=');
            $query->execute();
            $num_updated = db_update('itg_solr_video_info') // Table name no longer needs {}
                ->fields(array(
                  'solr_video_thumb' => $image_url
                ))
                ->condition('solr_video_id', $dmvid_id, '=')
                ->execute();
          }
          else {
            $node_flag = 1;
          }
        }
      }
      catch (Exception $e) {
        $exception_flag = 1;
        $video_ids[] = $dmvid_id;
      }
    }
    $node_ids = $video_id->nid;
    if ($exception_flag == 1) {
      if (!empty($video_ids)) {
        $query = db_select('dailymotion_response_details', 'drd');
        $query->fields('drd', array('nid'));
        $query->condition('drd.is_notify', '0', '=');
        $query->condition('video_id', $video_ids, 'IN');
        $result = $query->execute()->fetchAll();
        if (!empty($result)) {
          itg_videogallery_send_video_exception_notification($node_ids, $video_ids);
        }
      }
    }

    if ($node_flag == 0) {
      $node = node_load($video_id->nid);
      if ($node->field_op_flag[LANGUAGE_NONE][0]['value'] != 'draft') {
        foreach ($all_vid as $keyof => $dmvid_id) {
          $query = db_update('dailymotion_response_details');
          $query->fields(array('is_draft' => 0, 'node_is_save_draft' => 0));
          $query->condition('video_id', $dmvid_id, '=');
          $query->execute();
          itg_videogallery_update_video_info_solr($dmvid_id);
        }
        if ($node->field_video_status_flag[LANGUAGE_NONE][0]['value'] != 'low_level') {
          if ($node->status == 0) {
            $node->status = 1;
          }
        }
        if ($node->workbench_moderation['current']->state == 'draft') {
          $node->revision = 0;
        }

        if ($node->field_video_status_flag[LANGUAGE_NONE][0]['value'] == 'low_level') {

          workbench_moderation_moderate($node, 'needs_review');
        }
        else {

          workbench_moderation_moderate($node, 'published');
        }
        node_save($node);
      }
    }
  }
}

/**
 * This function use for removed or replaced video from other content
 * 
 */
function itg_videogallery_remove_video_with_child() {
  $video_data = "";
  global $user;
  $query = db_select('itg_solr_video_info', 'drd');
  $query->fields('drd', array('fid', 'nid', 'solr_video_id', 'id', 'property', 'video_repo_type'));
  $query->condition('is_delete', '1', ' = ');
  $video_data = $query->execute()->fetchAll();
  foreach ($video_data as $data_delete) {

    if ($data_delete->fid != "") {
      //Getting all fids of this video id
      $query = db_select('itg_solr_video_info', 'drd');
      $query->fields('drd', array('fid'));
      $query->condition('solr_video_id', $data_delete->solr_video_id, ' = ');
      $video_data1 = $query->execute()->fetchAll();
      foreach ($video_data1 as $viddata) {

        try {
          $deleted = db_delete('file_managed')
              ->condition('fid', $viddata->fid)
              ->execute();
        }
        catch (Exception $e) {
          watchdog_exception('file manage delete', $e);
        }
      }
      if ($data_delete->property == VIDEO_PROPERTY) {
        $query = db_update('dailymotion_response_details');
        $query->fields(array('dailymotion_published' => 0, 'is_replace' => 1));
        $query->condition('video_id', $data_delete->solr_video_id, ' = ');
        $query->execute();
        itg_videogallery_update_video_info_solr($data_delete->solr_video_id);
        if ($data_delete->video_repo_type != 'INTERNAL') {
          itg_videogallery_video_private_public($data_delete->solr_video_id, FALSE);
        }
      }

// delete from itg_solr_video_info table
      $deleted = db_delete('itg_solr_video_info')
          ->condition('solr_video_id', $data_delete->solr_video_id, ' = ')
          ->condition('property', VIDEO_PROPERTY, ' = ')
          ->execute();
    }
  }
}

/**
 * This is temp function use for test dailymotion video resploce no we will 
 */
function itg_videogallery_video_draft_node_check() {
  $api = itg_videogallery_dailymotion_api();
  $query = db_select('itg_solr_video_info', 'drd');
  $query->fields('drd', array('id', 'nid'));
  $query->condition('is_node_draft', 1);
  $query->groupBy('nid');
  $result = $query->execute()->fetchall();
  foreach ($result as $vid) {
    $check_node_status = itg_videogallery_get_node_status($vid->nid);
    if ($check_node_status == 1) {
      $query = db_update('itg_solr_video_info')
          ->fields(array('is_node_draft' => 0));
      $query->condition('nid', $vid->nid);
      $query->execute();
    }
  }
}

/**
 * Implement cron function for add video thumb from dailymotion
 */
function itg_videogallery_thumb_assign() {
  $filedir = ITG_IMAGE_FOLDER . 'video/' . date('Ym');
  if (!file_exists(file_default_scheme() . '://' . $filedir)) {
    mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  }
  chmod(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  $mainresult = array();
  $query = db_select('field_data_field_videogallery_video_upload', 'up_video');
  $query->fields('up_video', array('entity_id'));
  $query->join('dailymotion_response_details', 'drd', 'drd.fid = up_video.field_videogallery_video_upload_fid');
  $query->join('field_data_field_video_upload', 'fvd', 'fvd.field_video_upload_value = up_video.entity_id');
  $query->fields('fvd', array('entity_id'));
  $query->fields('drd', array('fid', 'video_id', 'dailymotion_thumb_url'));
  $query->fields('up_video', array('entity_id'));
  $query->orderBy('entity_id', 'desc');
  $query->distinct('fvd.entity_id');
  $result = $query->execute()->fetchAll();
  foreach ($result as $data_reslut) {
    $mainresult[$data_reslut->fvd_entity_id] = $data_reslut;
  }

  if (isset($mainresult) && !empty($mainresult)) {

    $api = itg_videogallery_dailymotion_api();
    foreach ($mainresult as $val) {

      $thumb_url = $api->get(
          '/video/' . $val->video_id, array('fields' => array('thumbnail_720_url', 'duration'))
      );

      $node = node_load($val->fvd_entity_id);
      if ($thumb_url['duration'] > 0) {
        $duration = '';
        if ($thumb_url['duration'] < 3600) {
          $duration = gmdate("i:s", $thumb_url['duration']);
        }
        else {
          $duration = gmdate("H:i:s", $thumb_url['duration']);
        }
        $node->field_video_duration[LANGUAGE_NONE][0]['value'] = $duration;
        field_attach_update('node', $node);
      }

// assign image in field after resize
      if ($node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'] == 0 || $node->field_story_large_image[LANGUAGE_NONE][0]['fid'] == 0 || $node->field_story_medium_image[LANGUAGE_NONE][0]['fid'] == 0 || $node->field_story_small_image[LANGUAGE_NONE][0]['fid'] == 0 || $node->field_story_extra_small_image[LANGUAGE_NONE][0]['fid'] == 0 || $node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'] == "" || $node->field_story_large_image[LANGUAGE_NONE][0]['fid'] == "" || $node->field_story_medium_image[LANGUAGE_NONE][0]['fid'] == "" || $node->field_story_small_image[LANGUAGE_NONE][0]['fid'] == "" || $node->field_story_extra_small_image[LANGUAGE_NONE][0]['fid'] == "") {
        $image_url = $thumb_url['thumbnail_720_url'];
        $imagedata = file_get_contents($image_url);
        $image_url = 'itg' . time() . end(explode('/', $image_url));
        $image_extension = end(explode('.', $image_url));
        $file_data_temp = file_save_data($imagedata, file_default_scheme() . '://' . $image_url);

// This code for resize all images 
        if ($node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'] == 0 || $node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'] == "") {
          $file_image = file_load($file_data_temp->fid);
          $image = image_load($file_image->uri);
          $filepath = file_default_scheme() . '://' . $filedir;
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
          $node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'] = $file->fid;
          field_attach_update('node', $node);
        }
        if ($node->field_story_large_image[LANGUAGE_NONE][0]['fid'] == 0 || $node->field_story_large_image[LANGUAGE_NONE][0]['fid'] == "") {
          $file_image = file_load($file_data_temp->fid);
          $image = image_load($file_image->uri);
          $filepath = file_default_scheme() . '://' . $filedir;
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
          $node->field_story_large_image[LANGUAGE_NONE][0]['fid'] = $file->fid;
          field_attach_update('node', $node);
        }
        if ($node->field_story_medium_image[LANGUAGE_NONE][0]['fid'] == 0 || $node->field_story_medium_image[LANGUAGE_NONE][0]['fid'] == "") {
          $file_image = file_load($file_data_temp->fid);
          $image = image_load($file_image->uri);
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
          $node->field_story_medium_image[LANGUAGE_NONE][0]['fid'] = $file->fid;
          field_attach_update('node', $node);
        }

        if ($node->field_story_small_image[LANGUAGE_NONE][0]['fid'] == 0 || $node->field_story_small_image[LANGUAGE_NONE][0]['fid'] == "") {
          $file_image = file_load($file_data_temp->fid);
          $image = image_load($file_image->uri);
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
          $node->field_story_small_image[LANGUAGE_NONE][0]['fid'] = $file->fid;
          field_attach_update('node', $node);
        }
        if ($node->field_story_extra_small_image[LANGUAGE_NONE][0]['fid'] == 0 || $node->field_story_extra_small_image[LANGUAGE_NONE][0]['fid'] == "") {
          $file_image = file_load($file_data_temp->fid);
          $image = image_load($file_image->uri);
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
          $node->field_story_extra_small_image[LANGUAGE_NONE][0]['fid'] = $file->fid;
          field_attach_update('node', $node);
        }
      }
    }
  }
}

/**
 * This function use for get file daily motion file details.
 */
function itg_videogallery_dailymotion_video_play() {
  $video_id = $_POST['videoid'];
  global $conf;
  $conf['preprocess_js'] = 0;
  $width = 760;
  $height = '90%';
  if (isset($_POST['width']) && !empty($_POST['width'])) {
    $width = $_POST['width'];
  }
  if (isset($_POST['height']) && !empty($_POST['height'])) {
    $height = $_POST['height'];
  }
  $data_video_info = itg_videogallery_get_all_video_info_by_video_id($_POST['videoid']);
  if ($data_video_info[0]->video_type == 'INTERNAL' || $_POST['getvideo_repo'] == 'INTERNAL') {
    $data_from_solr = itg_videogallery_getsolr_data_for_internal_video($_POST['videoid']);
    print theme('itg_videogallery_internal_video_play', array('video_data' => $data_from_solr[0], 'width' => $width, 'height' => 400));
  }
  else {
    $api = itg_videogallery_dailymotion_api();
    $thumb_url = $api->get(
        '/video/' . $video_id, array('fields' => array('embed_url'))
    );
    $embed_id = "";
    if ($thumb_url['embed_url']) {
      $embed_id = end(explode('/', $thumb_url['embed_url']));
    }

    print theme('itg_videogallery_dailymotion_video_play', array('video_id' => $embed_id, 'width' => $width, 'height' => $height));
  }
}

/**
 * This is temp function use for test dailymotion video resploce no we will 
 */
function itg_videogallery_video_bitrate() {
  $api = itg_videogallery_dailymotion_api();
  $totime = strtotime('-5 days', time());
  $query = db_select('dailymotion_response_details', 'drd');
  $query->fields('drd', array('video_id', 'encoding_progress', 'name', 'video_duration'));
  $query->condition('encoding_progress', '100', '=');
  $query->condition('video_type', 'DM', '=');
  $query->condition('upload_time', $totime, '>=');
  $result = $query->execute()->fetchall();
  $bitrates_info = itg_videogallery_url_with_bitates();
  foreach ($result as $ke => $vid) {
    itg_videogallery_update_embedcode_url($vid->video_id);
    $decode_json = $api->get(
        '/video/' . $vid->video_id, array('fields' => array('stream_h264_hd1080_url','stream_h264_hd_url','stream_h264_hq_url','stream_h264_ld_url','stream_h264_url','stream_h264_l1_url','stream_h264_l2_url','stream_h264_qhd_url','stream_h264_uhd_url'))
    );
    if (!empty($decode_json)) {
      foreach ($decode_json as $keys => $json_url) {
        if ($json_url != "") {
          $query = db_select('itg_video_bitrates_data', 'ivbd');
          $query->fields('ivbd');
          $query->condition('video_id', $vid->video_id);
          $query->condition('bitates_field', $keys);
          $result = $query->execute()->fetchall();
          if (!empty($result)) {
            if ($result[0]->is_download != 1) {
              db_update('itg_video_bitrates_data')
                  ->fields(array(
                    'video_id' => $vid->video_id,
                    'bitate_url' => $json_url,
                    'duration' => $vid->video_duration,
                    'framesize' => $bitrates_info['framesize'][$keys],
                    'bitrate' => $bitrates_info['bitrate'][$keys],
                    'video_name' => $vid->name,
                    'bitates_field' => $keys,
                    'is_download' => 0,
                  ))->condition('id', $result[0]->id)
                  ->execute();
            }
          }
          else {
            db_insert('itg_video_bitrates_data')
                ->fields(array(
                  'video_id' => $vid->video_id,
                  'bitate_url' => $json_url,
                  'framesize' => $bitrates_info['framesize'][$keys],
                  'bitrate' => $bitrates_info['bitrate'][$keys],
                  'bitates_field' => $keys,
                  'duration' => $vid->video_duration,
                  'video_name' => $vid->name,
                  'is_download' => 0,
                ))
                ->execute();
          }
        }
      }
    }
  }
}
/**
 * Implement itg_videogallery_getsolr_data_for_internal_video
 * @param string $video_id
 */
function itg_videogallery_getsolr_data_for_internal_video($video_id) {
  if (function_exists('apachesolr_server_status')) {
    $ping = apachesolr_server_status(variable_get('solr_server_url'));
  }
  if ($ping) {
    $solr = apachesolr_get_solr();
    if (function_exists('itg_apache_solr_get_site_hash')) {
      $hash = itg_apache_solr_get_site_hash();
    }
    $all_video_ids = array();
    $hashvalue = implode(' OR ', array_keys($hash));
    $str = 'hash:(' . $hashvalue . ')';
    $query = apachesolr_drupal_query("custom");
    $query->addParam('rows', '1'); // How many rows of result to display default it is 10.
    $query->addParam('qf', 'sm_field_video_id'); // Only search in title
//The bundle which you want to search
    $query->replaceParam("fq", '(' . $str . ')');
    $query->addFilter("bundle", "itg_solr_video");
    $query->addFilter("sm_field_video_id", $video_id);
    $query->setSolrsort('sort_label', 'desc');
    $resp_search = $query->search();
    $all_data = $resp_search->response->docs;
    if (!empty($all_data)) {
      return $all_data[0]->sm_field_all_xml_content;
    }
  }
}

/**
 * Implement itg_clone_story_data
 * @param int $keyword
 * @param string $type
 */
function itg_videogallery_getsolr_data_unpublish() {
  if (function_exists('apachesolr_server_status')) {
    $ping = apachesolr_server_status(variable_get('solr_server_url'));
  }
  if ($ping) {
    $solr = apachesolr_get_solr();
    if (function_exists('itg_apache_solr_get_site_hash')) {
      $hash = itg_apache_solr_get_site_hash();
    }
    $hashvalue = implode(' OR ', array_keys($hash));
    $str = 'hash:(' . $hashvalue . ')';
    $str_pub = 'sm_field_video_used:(0)';
    $str = $str . ' AND ' . $str_pub;
    $query = apachesolr_drupal_query("custom");
    $query->addParam('rows', '100000'); // How many rows of result to display default it is 10.
    $query->addParam('qf', 'label'); // Only search in title
//The bundle which you want to search
    $query->replaceParam("fq", '(' . $str . ')');
    $query->addFilter("bundle", "itg_solr_video");
    $query->setSolrsort('sort_label', 'asc');
    $resp_search = $query->search();

    $all_data = $resp_search->response->docs;
    if (!empty($all_data)) {
      foreach ($all_data as $datasolr) {
        $all_video_ids['unpubliash_video_id'][] = $datasolr->sm_field_video_id[0];
        if ($datasolr->sm_field_is_replace[0] == 1) {
          $all_video_ids['replace_video'][] = $datasolr->sm_field_video_id[0];
        }
      }
    }
    return $all_video_ids;
  }
}

/**
 * Implement itg_clone_story_data
 * @param int $keyword
 * @param string $type
 */
function itg_videogallery_getsolr_data() {
  if (function_exists('apachesolr_server_status')) {
    $ping = apachesolr_server_status(variable_get('solr_server_url'));
  }
  if ($ping) {
    $solr = apachesolr_get_solr();
    if (function_exists('itg_apache_solr_get_site_hash')) {
      $hash = itg_apache_solr_get_site_hash();
    }
    $all_video_ids = array();
    $hashvalue = implode(' OR ', array_keys($hash));
    $str = 'hash:(' . $hashvalue . ')';
    $query = apachesolr_drupal_query("custom");
    $query->addParam('rows', '10000'); // How many rows of result to display default it is 10.
    $query->addParam('qf', 'label'); // Only search in title
//The bundle which you want to search
    $query->replaceParam("fq", '(' . $str . ')');
    $query->addFilter("bundle", "itg_delete_solr_video");
    $query->setSolrsort('sort_label', 'asc');
    $resp_search = $query->search();
    $all_data = $resp_search->response->docs;
    if (!empty($all_data)) {
      foreach ($all_data as $datasolr) {
        $all_video_ids[] = $datasolr->label;
      }
    }
    return array_reverse($all_video_ids);
  }
}

function itg_videogallery_send_video_exception_notification($nid, $video_ids) {
  global $base_url;
  $node = node_load($nid);
  $node_url = $base_url . '/node/' . $node->nid . '/edit';
  $to_mail = $to;
  $getuser_info = user_load($node->uid);
  $name = ucfirst($getuser_info->field_first_name[LANGUAGE_NONE][0]['value']) . ' ' . ucfirst($getuser_info->field_last_name[LANGUAGE_NONE][0]['value']);
  if (isset($getuser_info->status) && $getuser_info->status == 1) {
    $email = $getuser_info->email;
  }
  $subject = 'A new ' . $content_type . ' has been unpublished, please find details below.';
  $mail_content = '<div style="max-width: 502px; margin: 0 auto; font-family: sans-serif; color: #000;">
                      <table style="border-collapse: collapse; border: 1px solid #ececec;"> 
                          <tr>
                              <td style="background-color:#ececec;">
                                  <img src="template_logo.png" alt="Indiatoday" title="Indiatoday" />
                              </td>
                          </tr>
                          <tr>
                              <td style="padding: 10px 20px;">
                                  <h2 style="font-size: 18px; margin: 20px 0 30px;">Draft Video Notification :</h2>
                                  <strong style="font-size: 16px;">Dear ' . $name . ',</strong>
                                  <p style="font-size: 16px; color: #595959; margin: 20px 0;"> ' . mb_strimwidth(strip_tags($node->title), 0, 55, "..") . '<strong style="color: #000;">title.</strong></p>
                                  <p style="font-size: 16px; color: #595959; margin: 20px 0;">Geting Some Error from dailymotion while publishing.</p>
                                  <p style="font-size: 16px; color: #595959; margin: 20px 0;"><a href="' . $node_url . '"><span class="btn">Click Here</span> </a>To view this node</p>
                                 <p style="font-size: 16px; color: #595959; margin: 20px 0;"><strong style="color: #000;">Thanks,</strong><br>India Today Team</p>
                              </td>
                          </tr>
                          <tr>
                              <td style="background-color: #000; font-size: 11px; color: #7c7c7c; padding: 10px; text-align: center; font-weight: bold;">COPYRIGHT &copy; 2017 LIVING MEDIA INDIA LIMITED. ALL RIGHT RESERVED.</td>
                          </tr>
                      </table>
                  </div>';

  $mail_content = preg_replace("/\[([^\[\]]++|(?R))*+\]/", "", $mail_node_author);
  $content = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
              <html xmlns:v="urn:schemas-microsoft-com:vml">
                <head><title></title></head>
                <body style="margin:0; padding:0;">';
  $content .= $mail_content;
  $content .= '</body>';
  $content .= '</html>';
  $params = array(
    'body' => $content,
    'subject' => $subject,
  );
  $mail = drupal_mail('itg_workflow', 'send_mail_to_task', $email, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
  if ($mail['result']) {
    $query = db_update('dailymotion_response_details');
    $query->fields(array('is_notify' => '1'));
    $query->condition('video_id', $video_ids, 'IN');
    $query->execute();
  }
}

/**
 * Implements itg_videogallery_get_all_video_info_by_video_id
 * @param string $video_id
 * @param array $result
 */
function itg_videogallery_get_all_video_info_by_video_id($video_id) {
  $query = db_select('dailymotion_response_details', 'drd');
  $query->fields('drd');
  $query->condition('video_id', $video_id, '=');
  $result = $query->execute()->fetchAll();
  return $result;
}
