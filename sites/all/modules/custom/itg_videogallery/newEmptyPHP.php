<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.
/*
 * This temp function
 */
itg_common_node_for_story_update_image();

function all_insert_orignal_image($uri, $fid) {
  $file_uri = file_create_url($uri);
  db_insert('itg_all_orignal_image')->fields(array(
    'fid' => $fid,
    'orignal_fid' => $fid,
    'url' => $file_url
  ))->execute();
}

function _insert_node_sucecss($nid, $node_type) {
  db_insert('itg_image_mapnode')->fields(array(
    'id' => $nid,
    'type' => $node_type,
  ))->execute();
}

function check_node_is_maped($nid) {
  $result = db_select('itg_image_mapnode', 'n')
      ->fields('n', array('id'))
      ->condition('id', $nid, ' = ')
      ->execute()
      ->fetchAll();
  return $result;
}

function itg_common_node_for_video_update_image() {
  $result = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('type', 'videogallery', ' = ')->range(0, 1000)
      ->execute()
      ->fetchAll();
  foreach ($result as $res) {
    $extra_large_image = array();
    $large_image = array();
    $medium_image = array();
    $small_image = array();
    $extra_small_image = array();
    $facebook_image = array();
    $tweet_image = array();
    $player_image = array();
    $check_node = check_node_is_maped($res->nid);
    if (empty($check_node)) {
      $node = node_load($res->nid);
      $node_created_date = $node->created;
      $time_folder = date('Ym', $node_created_date);
      $node_type = $node->type;
      $extra_large_image['fid'] = $node->field_story_extra_large_image['und'][0]['fid'];
      $extra_large_image['uri'] = $node->field_story_extra_large_image['und'][0]['uri'];
      if (isset($extra_large_image['uri']) && !empty($extra_large_image['uri'])) {
        $file_image = file_create_url($extra_large_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $extra_large_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'video' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $extra_large_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $extra_large_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $extra_large_image['fid']);
      }
      // large image
      $large_image['fid'] = $node->field_story_large_image['und'][0]['fid'];
      $large_image['uri'] = $node->field_story_large_image['und'][0]['uri'];
      if (isset($large_image['uri']) && !empty($large_image['uri'])) {
        $file_image = file_create_url($large_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $large_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'video' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $large_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $large_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $large_image['fid']);
      }
      // medium image
      $medium_image['fid'] = $node->field_story_medium_image['und'][0]['fid'];
      $medium_image['uri'] = $node->field_story_medium_image['und'][0]['uri'];
      if (isset($medium_image['uri']) && !empty($medium_image['uri'])) {
        $file_image = file_create_url($medium_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $medium_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'video' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $medium_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $medium_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $medium_image['fid']);
      }
      // small image
      $small_image['fid'] = $node->field_story_small_image['und'][0]['fid'];
      $small_image['uri'] = $node->field_story_small_image['und'][0]['uri'];
      if (isset($small_image['uri']) && !empty($small_image['uri'])) {
        $file_image = file_create_url($small_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $small_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'video' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);

        $inserted_data = db_delete('s3fs_file')->condition('uri', $small_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $small_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $small_image['fid']);
      }
      //extra small image
      $extra_small_image['fid'] = $node->field_story_extra_small_image['und'][0]['fid'];
      $extra_small_image['uri'] = $node->field_story_extra_small_image['und'][0]['uri'];
      if (isset($extra_small_image['uri']) && !empty($extra_small_image['uri'])) {
        $file_image = file_create_url($extra_small_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $extra_small_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'video' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);

        $inserted_data = db_delete('s3fs_file')->condition('uri', $extra_small_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $extra_small_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $extra_small_image['fid']);
      }
      //FAcebook  image
      $facebook_image['fid'] = $node->field_story_facebook_image['und'][0]['fid'];
      $facebook_image['uri'] = $node->field_story_facebook_image['und'][0]['uri'];
      if (isset($facebook_image['uri']) && !empty($facebook_image['uri'])) {
        $file_image = file_create_url($facebook_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $facebook_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'video' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $facebook_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $facebook_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $facebook_image['fid']);
      }
      //Tweet  image
      $tweet_image['fid'] = $node->field_story_tweet_image['und'][0]['fid'];
      $tweet_image['uri'] = $node->field_story_tweet_image['und'][0]['uri'];
      if (isset($tweet_image['uri']) && !empty($tweet_image['uri'])) {
        $file_image = file_create_url($tweet_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $tweet_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'video' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $tweet_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $tweet_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $tweet_image['fid']);
      }
      //Tweet  image
      $player_image['fid'] = $node->field_story_player_image['und'][0]['fid'];
      $player_image['uri'] = $node->field_story_player_image['und'][0]['uri'];
      if (isset($player_image['uri']) && !empty($player_image['uri'])) {
        $file_image = file_create_url($player_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $player_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'video' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $player_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $player_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $player_image['fid']);
      }
      //Image style create
//    $extralarge_image_fid = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'];
//    if (!empty($extralarge_image_fid)) {
//      $file = file_load($extralarge_image_fid);
//      itg_story_crate_image_style(EXTRA_LARGE_IMAGE_STYLES, $file->uri);
//    }
//
//    $large_image_fid = $node->field_story_large_image[LANGUAGE_NONE][0]['fid'];
//    if (!empty($large_image_fid)) {
//      $file_large = file_load($large_image_fid);
//      itg_story_crate_image_style(LARGE_IMAGE_STYLES, $file_large->uri);
//    }
//
//    $medium_image_fid = $node->field_story_medium_image[LANGUAGE_NONE][0]['fid'];
//    if (!empty($medium_image_fid)) {
//      $file_meduim = file_load($medium_image_fid);
//      itg_story_crate_image_style(MEDIUM_IMAGE_STYLES, $file_meduim->uri);
//    }
//
//    $small_image_fid = $node->field_story_small_image[LANGUAGE_NONE][0]['fid'];
//    if (!empty($small_image_fid)) {
//      $file_small = file_load($small_image_fid);
//      itg_story_crate_image_style(SMALL_IMAGE_STYLES, $file_small->uri);
//    }
//
//    $small_extra_image_fid = $node->field_story_extra_small_image[LANGUAGE_NONE][0]['fid'];
//    if (!empty($small_extra_image_fid)) {
//      $file_extra_small = file_load($small_extra_image_fid);
//      itg_story_crate_image_style(SMALL_EXTRA_IMAGE_STYLES, $file_extra_small->uri);
//    }
      _insert_node_sucecss($node->nid, $node_type);
      print $node->nid . ',';
    }
  }
}

// this function  use for byline
function itg_common_node_for_byline_update_image() {
  $result = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('type', 'reporter', ' = ')
      ->execute()
      ->fetchAll();
  foreach ($result as $res) {
    $extra_large_image = array();
    $large_image = array();
    $medium_image = array();
    $small_image = array();
    $extra_small_image = array();
    $facebook_image = array();
    $tweet_image = array();
    $player_image = array();
    $check_node = check_node_is_maped($res->nid);
    if (empty($check_node)) {

      $node = node_load($res->nid);

      $node_created_date = $node->created;
      $time_folder = date('Ym', $node_created_date);
      $node_type = $node->type;
      $extra_large_image['fid'] = $node->field_story_extra_large_image['und'][0]['fid'];
      $extra_large_image['uri'] = $node->field_story_extra_large_image['und'][0]['uri'];
      if (isset($extra_large_image['uri']) && !empty($extra_large_image['uri'])) {
        $file_image = file_create_url($extra_large_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $extra_large_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'reporter' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $extra_large_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $extra_large_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $extra_large_image['fid']);
      }
      _insert_node_sucecss($node->nid, $node_type);
      print $res->nid . ',';
    }
  }
}

/*
 * This function use for update image in photogallery
 */

function itg_common_node_for_photogallery_update_image() {
  $result = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('type', 'photogallery', ' = ')->range(0, 500)
      ->execute()
      ->fetchAll();
  foreach ($result as $res) {
    $extra_large_image = array();
    $large_image = array();
    $medium_image = array();
    $small_image = array();
    $extra_small_image = array();
    $facebook_image = array();
    $tweet_image = array();
    $player_image = array();
    $check_node = check_node_is_maped($res->nid);
    if (empty($check_node)) {
      $node = node_load($res->nid);
      $node_created_date = $node->created;
      $time_folder = date('Ym', $node_created_date);
      $node_type = $node->type;
      $filed_collection = $node->field_gallery_image['und'];
      if (!empty($filed_collection)) {
        foreach ($filed_collection as $collection) {
          $col = $collection['value'];
          $photo_details = entity_load('field_collection_item', array($col));
          $fid_gall = $photo_details[$col]->field_images['und'][0]['fid'];
          $fid_uri = $photo_details[$col]->field_images['und'][0]['uri'];

          if (isset($fid_uri) && !empty($fid_uri)) {
            $file_image = file_create_url($fid_uri);
            $imagedata = file_get_contents($file_image);
            $image_name = end(explode('/', $fid_uri));
            $filedir = ITG_IMAGE_FOLDER . 'photogallery' . '/' . $time_folder;
            if (!file_exists(file_default_scheme() . '://' . $filedir)) {
              mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
            }
            $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
            $inserted_data = db_delete('s3fs_file')->condition('uri', $fid_uri, '=')
                ->execute();
            $inserted_data = db_update('file_managed')->fields(array(
                  'uri' => $file))->condition('fid', $fid_gall, '=')
                ->execute();
            all_insert_orignal_image($file, $fid_gall);
          }

          $fid_gall_small = $photo_details[$col]->field_photo_small_image['und'][0]['fid'];
          $fid_uri_small = $photo_details[$col]->field_photo_small_image['und'][0]['uri'];
          if (isset($fid_uri_small) && !empty($fid_uri_small)) {
            $file_image = file_create_url($fid_uri_small);
            $imagedata = file_get_contents($file_image);
            $image_name = end(explode('/', $fid_uri_small));

            $filedir = ITG_IMAGE_FOLDER . 'photogallery' . '/' . $time_folder;
            if (!file_exists(file_default_scheme() . '://' . $filedir)) {
              mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
            }
            $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
            $inserted_data = db_delete('s3fs_file')->condition('uri', $fid_uri_small, '=')
                ->execute();
            $inserted_data = db_update('file_managed')->fields(array(
                  'uri' => $file))->condition('fid', $fid_gall_small, '=')
                ->execute();
            all_insert_orignal_image($file, $fid_gall_small);
          }

          $fid_gall_api = $photo_details[$col]->field_api_image['und'][0]['fid'];
          $fid_uri_api = $photo_details[$col]->field_api_image['und'][0]['uri'];
          if (isset($fid_uri_api) && !empty($fid_uri_api)) {
            $file_image = file_create_url($fid_uri_api);
            $imagedata = file_get_contents($file_image);
            $image_name = end(explode('/', $fid_uri_api));
            $filedir = ITG_IMAGE_FOLDER . 'photogallery' . '/' . $time_folder;
            if (!file_exists(file_default_scheme() . '://' . $filedir)) {
              mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
            }
            $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
            $inserted_data = db_delete('s3fs_file')->condition('uri', $fid_uri_api, '=')
                ->execute();
            $inserted_data = db_update('file_managed')->fields(array(
                  'uri' => $file))->condition('fid', $fid_gall_api, '=')
                ->execute();
            all_insert_orignal_image($file, $fid_gall_api);
          }
        }
      }
      $extra_large_image['fid'] = $node->field_story_extra_large_image['und'][0]['fid'];
      $extra_large_image['uri'] = $node->field_story_extra_large_image['und'][0]['uri'];
      if (isset($extra_large_image['uri']) && !empty($extra_large_image['uri'])) {
        $file_image = file_create_url($extra_large_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $extra_large_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'photogallery' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $extra_large_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $extra_large_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $extra_large_image['fid']);
      }
      // large image
      $large_image['fid'] = $node->field_story_large_image['und'][0]['fid'];
      $large_image['uri'] = $node->field_story_large_image['und'][0]['uri'];
      if (isset($large_image['uri']) && !empty($large_image['uri'])) {
        $file_image = file_create_url($large_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $large_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'photogallery' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $large_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $large_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $large_image['fid']);
      }
      // medium image
      $medium_image['fid'] = $node->field_story_medium_image['und'][0]['fid'];
      $medium_image['uri'] = $node->field_story_medium_image['und'][0]['uri'];
      if (isset($medium_image['uri']) && !empty($medium_image['uri'])) {
        $file_image = file_create_url($medium_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $medium_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'photogallery' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $medium_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $medium_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $medium_image['fid']);
      }
      // small image
      $small_image['fid'] = $node->field_story_small_image['und'][0]['fid'];
      $small_image['uri'] = $node->field_story_small_image['und'][0]['uri'];
      if (isset($small_image['uri']) && !empty($small_image['uri'])) {
        $file_image = file_create_url($small_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $small_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'photogallery' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);

        $inserted_data = db_delete('s3fs_file')->condition('uri', $small_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $small_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $small_image['fid']);
      }
      //extra small image
      $extra_small_image['fid'] = $node->field_story_extra_small_image['und'][0]['fid'];
      $extra_small_image['uri'] = $node->field_story_extra_small_image['und'][0]['uri'];
      if (isset($extra_small_image['uri']) && !empty($extra_small_image['uri'])) {
        $file_image = file_create_url($extra_small_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $extra_small_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'photogallery' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);

        $inserted_data = db_delete('s3fs_file')->condition('uri', $extra_small_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $extra_small_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $extra_small_image['fid']);
      }
      //FAcebook  image
      $facebook_image['fid'] = $node->field_story_facebook_image['und'][0]['fid'];
      $facebook_image['uri'] = $node->field_story_facebook_image['und'][0]['uri'];
      if (isset($facebook_image['uri']) && !empty($facebook_image['uri'])) {
        $file_image = file_create_url($facebook_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $facebook_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'photogallery' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $facebook_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $facebook_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $facebook_image['fid']);
      }
      //Tweet  image
      $tweet_image['fid'] = $node->field_story_tweet_image['und'][0]['fid'];
      $tweet_image['uri'] = $node->field_story_tweet_image['und'][0]['uri'];
      if (isset($tweet_image['uri']) && !empty($tweet_image['uri'])) {
        $file_image = file_create_url($tweet_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $tweet_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'photogallery' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $tweet_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $tweet_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $tweet_image['fid']);
      }

//    //Image style create
//    $extralarge_image_fid = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'];
//    if (!empty($extralarge_image_fid)) {
//      $file = file_load($extralarge_image_fid);
//      itg_story_crate_image_style(EXTRA_LARGE_IMAGE_STYLES, $file->uri);
//    }
//
//    $large_image_fid = $node->field_story_large_image[LANGUAGE_NONE][0]['fid'];
//    if (!empty($large_image_fid)) {
//      $file_large = file_load($large_image_fid);
//      itg_story_crate_image_style(LARGE_IMAGE_STYLES, $file_large->uri);
//    }
//
//    $medium_image_fid = $node->field_story_medium_image[LANGUAGE_NONE][0]['fid'];
//    if (!empty($medium_image_fid)) {
//      $file_meduim = file_load($medium_image_fid);
//      itg_story_crate_image_style(MEDIUM_IMAGE_STYLES, $file_meduim->uri);
//    }
//
//    $small_image_fid = $node->field_story_small_image[LANGUAGE_NONE][0]['fid'];
//    if (!empty($small_image_fid)) {
//      $file_small = file_load($small_image_fid);
//      itg_story_crate_image_style(SMALL_IMAGE_STYLES, $file_small->uri);
//    }
//
//    $small_extra_image_fid = $node->field_story_extra_small_image[LANGUAGE_NONE][0]['fid'];
//    if (!empty($small_extra_image_fid)) {
//      $file_extra_small = file_load($small_extra_image_fid);
//      itg_story_crate_image_style(SMALL_EXTRA_IMAGE_STYLES, $file_extra_small->uri);
//    }
      _insert_node_sucecss($node->nid, $node_type);
      print $node->nid . ',';
    }
  }
}

/**
 * This function use for update issue image.
 * 
 */
/*
 * This temp function
 */

function itg_common_node_for_issue_update_image() {
  $result = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('type', 'issue', ' = ')->range(0, 500)
      ->execute()
      ->fetchAll();
  foreach ($result as $res) {
    $issue_large_image = array();
    $issue_small_image = array();
    $check_node = check_node_is_maped($res->nid);
    if (empty($check_node)) {
      $node = node_load($res->nid);

      $node_created_date = $node->created;
      $time_folder = date('Ym', $node_created_date);
      $node_type = $node->type;

      $issue_large_image['fid'] = $node->field_issue_large_cover_image['und'][0]['fid'];
      $issue_large_image['uri'] = $node->field_issue_large_cover_image['und'][0]['uri'];
      if (isset($issue_large_image['uri']) && !empty($issue_large_image['uri'])) {
        $file_image = file_create_url($issue_large_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $issue_large_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'issue' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $issue_large_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $issue_large_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $issue_large_image['fid']);
      }

      // Issue small cover image
      $issue_small_image['fid'] = $node->field_issue_small_cover_image['und'][0]['fid'];
      $issue_small_image['uri'] = $node->field_issue_small_cover_image['und'][0]['uri'];
      if (isset($issue_small_image['uri']) && !empty($issue_small_image['uri'])) {
        $file_image = file_create_url($issue_small_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $issue_small_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'issue' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $issue_small_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $issue_small_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $issue_small_image['fid']);
      }
      _insert_node_sucecss($node->nid, $node_type);
      print $res->nid . ',';
    }
  }
}

/**
 * This function use for update suppliment images.
 * 
 */
function itg_common_node_for_supplement_update_image() {
  $result = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('type', 'supplement', ' = ')->range(0, 500)
      ->execute()
      ->fetchAll();
  foreach ($result as $res) {
    $supp_large_image = array();
    $supp_small_image = array();
    $check_node = check_node_is_maped($res->nid);
    if (empty($check_node)) {
      $node = node_load($res->nid);
      $node_created_date = $node->created;
      $time_folder = date('Ym', $node_created_date);
      $node_type = $node->type;

      $supp_large_image['fid'] = $node->field_issue_supp_large_image['und'][0]['fid'];
      $supp_large_image['uri'] = $node->field_issue_supp_large_image['und'][0]['uri'];
      if (isset($supp_large_image['uri']) && !empty($supp_large_image['uri'])) {
        $file_image = file_create_url($supp_large_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $supp_large_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'supplement' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $supp_large_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $supp_large_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $supp_large_image['fid']);
      }

      // Issue small cover image
      $supp_small_image['fid'] = $node->field_issue_supp_small_image['und'][0]['fid'];
      $supp_small_image['uri'] = $node->field_issue_supp_small_image['und'][0]['uri'];
      if (isset($supp_small_image['uri']) && !empty($supp_small_image['uri'])) {
        $file_image = file_create_url($supp_small_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $supp_small_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'supplement' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $supp_small_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $supp_small_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $supp_small_image['fid']);
      }
      _insert_node_sucecss($node->nid, $node_type);
      print $res->nid . ',';
    }
  }
}

/**
 * This is function use for update megareview image
 */
function itg_common_node_for_mega_review_critic_update_image() {
  $result = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('type', 'mega_review_critic', ' = ')->range(0, 500)
      ->execute()
      ->fetchAll();
  foreach ($result as $res) {
    $extra_large_image = array();
    $large_image = array();
    $medium_image = array();
    $small_image = array();
    $extra_small_image = array();
    $check_node = check_node_is_maped($res->nid);
    if (empty($check_node)) {
      $node = node_load($res->nid);
      $node_created_date = $node->created;
      $time_folder = date('Ym', $node_created_date);
      $node_type = $node->type;

      $extra_large_image['fid'] = $node->field_story_extra_large_image['und'][0]['fid'];
      $extra_large_image['uri'] = $node->field_story_extra_large_image['und'][0]['uri'];
      if (isset($extra_large_image['uri']) && !empty($extra_large_image['uri'])) {
        $file_image = file_create_url($extra_large_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $extra_large_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'mega_review_critic' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $extra_large_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $extra_large_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $extra_large_image['fid']);
      }
      // large image
      $large_image['fid'] = $node->field_story_large_image['und'][0]['fid'];
      $large_image['uri'] = $node->field_story_large_image['und'][0]['uri'];
      if (isset($large_image['uri']) && !empty($large_image['uri'])) {
        $file_image = file_create_url($large_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $large_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'mega_review_critic' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $large_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $large_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $large_image['fid']);
      }
      // medium image
      $medium_image['fid'] = $node->field_story_medium_image['und'][0]['fid'];
      $medium_image['uri'] = $node->field_story_medium_image['und'][0]['uri'];
      if (isset($medium_image['uri']) && !empty($medium_image['uri'])) {
        $file_image = file_create_url($medium_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $medium_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'mega_review_critic' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $medium_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $medium_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $medium_image['fid']);
      }
      // small image
      $small_image['fid'] = $node->field_story_small_image['und'][0]['fid'];
      $small_image['uri'] = $node->field_story_small_image['und'][0]['uri'];
      if (isset($small_image['uri']) && !empty($small_image['uri'])) {
        $file_image = file_create_url($small_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $small_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'mega_review_critic' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);

        $inserted_data = db_delete('s3fs_file')->condition('uri', $small_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $small_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $small_image['fid']);
      }
      //extra small image
      $extra_small_image['fid'] = $node->field_story_extra_small_image['und'][0]['fid'];
      $extra_small_image['uri'] = $node->field_story_extra_small_image['und'][0]['uri'];
      if (isset($extra_small_image['uri']) && !empty($extra_small_image['uri'])) {
        $file_image = file_create_url($extra_small_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $extra_small_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'mega_review_critic' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);

        $inserted_data = db_delete('s3fs_file')->condition('uri', $extra_small_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $extra_small_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $extra_small_image['fid']);
      }
      _insert_node_sucecss($node->nid, $node_type);
      print $res->nid . ',';
    }
  }
}

/*
 * This function use for update image in photogallery
 */

function itg_common_node_for_story_update_image() {
  $query = db_select('node', 'n');
  $query->fields('n', array('nid'));
  $query->join('field_data_field_story_category', 'fdfsc', 'fdfsc.entity_id = n.nid');
  $query->condition('n.type', 'story', ' = ');
  $query->condition('fdfsc.field_story_category_tid', '1206640', '!= ')->range(0, 2000);
  $result = $query->execute()->fetchAll();
  foreach ($result as $res) {
    $extra_large_image = array();
    $large_image = array();
    $medium_image = array();
    $small_image = array();
    $extra_small_image = array();
    $facebook_image = array();
    $tweet_image = array();
    $tweet_image = array();
    $animated_image = array();
    $expert_image = array();
    $quote_image = array();
    $big_image = array();
    $check_node = check_node_is_maped($res->nid);
    if (empty($check_node)) {
      $node = node_load($res->nid);

      $node_created_date = $node->created;
      $time_folder = date('Ym', $node_created_date);
      $node_type = $node->type;

      $filed_collection = $node->field_story_template_buzz['und'];
      if (!empty($filed_collection)) {
        foreach ($filed_collection as $collection) {
          $col = $collection['value'];
          $buzz_image_details = entity_load('field_collection_item', array($col));
          $fid_buzz = $buzz_image_details[$col]->field_buzz_image['und'][0]['fid'];
          $fid_buzz_uri = $buzz_image_details[$col]->field_buzz_image['und'][0]['uri'];
          if (isset($fid_buzz_uri) && !empty($fid_buzz_uri)) {
            $file_image_buzz = file_create_url($fid_buzz_uri);
            $imagedata = file_get_contents($file_image_buzz);
            $image_name = end(explode('/', $fid_buzz_uri));
            $filedir = ITG_IMAGE_FOLDER . 'story' . '/' . $time_folder;
            if (!file_exists(file_default_scheme() . '://' . $filedir)) {
              mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
            }
            $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
            $inserted_data = db_delete('s3fs_file')->condition('uri', $fid_buzz_uri, '=')
                ->execute();
            $inserted_data = db_update('file_managed')->fields(array(
                  'uri' => $file))->condition('fid', $fid_buzz, '=')
                ->execute();
            all_insert_orignal_image($file, $fid_buzz);
          }
        }
      }

      $filed_collection = $node->field_story_technology['und'];
      if (!empty($filed_collection)) {
        foreach ($filed_collection as $collection) {
          $col = $collection['value'];
          $buzz_image_details = entity_load('field_collection_item', array($col));
          $fid_buzz = $buzz_image_details[$col]->field_technology_sample_photo['und'][0]['fid'];
          $fid_buzz_uri = $buzz_image_details[$col]->field_technology_sample_photo['und'][0]['uri'];
          if (isset($fid_buzz_uri) && !empty($fid_buzz_uri)) {
            $file_image_buzz = file_create_url($fid_buzz_uri);
            $imagedata = file_get_contents($file_image_buzz);
            $image_name = end(explode('/', $fid_buzz_uri));
            $filedir = ITG_IMAGE_FOLDER . 'story' . '/' . $time_folder;
            if (!file_exists(file_default_scheme() . '://' . $filedir)) {
              mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
            }
            $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
            $inserted_data = db_delete('s3fs_file')->condition('uri', $fid_buzz_uri, '=')
                ->execute();
            $inserted_data = db_update('file_managed')->fields(array(
                  'uri' => $file))->condition('fid', $fid_buzz, '=')
                ->execute();
            all_insert_orignal_image($file, $fid_buzz);
          }
        }
      }



      $filed_collection_photo_story = $node->field_photo_story['und'];
      if (!empty($filed_collection_photo_story)) {
        foreach ($filed_collection_photo_story as $collection) {
          $col = $collection['value'];
          $photo_story_image_details = entity_load('field_collection_item', array($col));
          $fid_photo_story = $photo_story_image_details[$col]->field_photo_story_image['und'][0]['fid'];
          $fid_photo_story_uri = $photo_story_image_details[$col]->field_photo_story_image['und'][0]['uri'];
          if (isset($fid_photo_story_uri) && !empty($fid_photo_story_uri)) {
            $file_image_photo = file_create_url($fid_buzz_uri);
            $imagedata = file_get_contents($file_image_photo);
            $image_name = end(explode('/', $fid_photo_story_uri));
            $filedir = ITG_IMAGE_FOLDER . 'story' . '/' . $time_folder;
            if (!file_exists(file_default_scheme() . '://' . $filedir)) {
              mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
            }
            $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
            $inserted_data = db_delete('s3fs_file')->condition('uri', $fid_photo_story_uri, '=')
                ->execute();
            $inserted_data = db_update('file_managed')->fields(array(
                  'uri' => $file))->condition('fid', $fid_photo_story, '=')
                ->execute();
            all_insert_orignal_image($file, $fid_photo_story);
          }
        }
      }

      $extra_large_image['fid'] = $node->field_story_extra_large_image['und'][0]['fid'];
      $extra_large_image['uri'] = $node->field_story_extra_large_image['und'][0]['uri'];
      if (isset($extra_large_image['uri']) && !empty($extra_large_image['uri'])) {
        $file_image = file_create_url($extra_large_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $extra_large_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'story' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $extra_large_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $extra_large_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $extra_large_image['fid']);
      }
      // large image
      $large_image['fid'] = $node->field_story_large_image['und'][0]['fid'];
      $large_image['uri'] = $node->field_story_large_image['und'][0]['uri'];
      if (isset($large_image['uri']) && !empty($large_image['uri'])) {
        $file_image = file_create_url($large_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $large_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'story' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $large_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $large_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $large_image['fid']);
      }
      // medium image
      $medium_image['fid'] = $node->field_story_medium_image['und'][0]['fid'];
      $medium_image['uri'] = $node->field_story_medium_image['und'][0]['uri'];
      if (isset($medium_image['uri']) && !empty($medium_image['uri'])) {
        $file_image = file_create_url($medium_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $medium_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'story' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $medium_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $medium_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $medium_image['fid']);
      }
      // small image
      $small_image['fid'] = $node->field_story_small_image['und'][0]['fid'];
      $small_image['uri'] = $node->field_story_small_image['und'][0]['uri'];
      if (isset($small_image['uri']) && !empty($small_image['uri'])) {
        $file_image = file_create_url($small_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $small_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'story' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);

        $inserted_data = db_delete('s3fs_file')->condition('uri', $small_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $small_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $small_image['fid']);
      }
      //extra small image
      $extra_small_image['fid'] = $node->field_story_extra_small_image['und'][0]['fid'];
      $extra_small_image['uri'] = $node->field_story_extra_small_image['und'][0]['uri'];
      if (isset($extra_small_image['uri']) && !empty($extra_small_image['uri'])) {
        $file_image = file_create_url($extra_small_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $extra_small_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'story' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);

        $inserted_data = db_delete('s3fs_file')->condition('uri', $extra_small_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $extra_small_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $extra_small_image['fid']);
      }
      //FAcebook  image
      $facebook_image['fid'] = $node->field_story_facebook_image['und'][0]['fid'];
      $facebook_image['uri'] = $node->field_story_facebook_image['und'][0]['uri'];
      if (isset($facebook_image['uri']) && !empty($facebook_image['uri'])) {
        $file_image = file_create_url($facebook_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $facebook_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'story' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $facebook_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $facebook_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $facebook_image['fid']);
      }
      //Tweet  image
      $tweet_image['fid'] = $node->field_story_tweet_image['und'][0]['fid'];
      $tweet_image['uri'] = $node->field_story_tweet_image['und'][0]['uri'];
      if (isset($tweet_image['uri']) && !empty($tweet_image['uri'])) {
        $file_image = file_create_url($tweet_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $tweet_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'story' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $tweet_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $tweet_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $tweet_image['fid']);
      }

      $animated_image['fid'] = $node->field_facebook_animated_image['und'][0]['fid'];
      $animated_image['uri'] = $node->field_facebook_animated_image['und'][0]['uri'];
      if (isset($animated_image['uri']) && !empty($animated_image['uri'])) {
        $file_image = file_create_url($animated_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $animated_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'story' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $animated_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $animated_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $animated_image['fid']);
      }

      $expert_image['fid'] = $node->field_story_expert_image['und'][0]['fid'];
      $expert_image['uri'] = $node->field_story_expert_image['und'][0]['uri'];
      if (isset($expert_image['uri']) && !empty($expert_image['uri'])) {
        $file_image = file_create_url($expert_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $expert_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'story' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $expert_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $expert_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $expert_image['fid']);
      }

      $quote_image['fid'] = $node->field_story_quote_image['und'][0]['fid'];
      $quote_image['uri'] = $node->field_story_quote_image['und'][0]['uri'];
      if (isset($quote_image['uri']) && !empty($quote_image['uri'])) {
        $file_image = file_create_url($quote_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $quote_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'story' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $quote_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $quote_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $quote_image['fid']);
      }

      $big_image['fid'] = $node->field_story_big_image['und'][0]['fid'];
      $big_image['uri'] = $node->field_story_big_image['und'][0]['uri'];
      if (isset($quote_image['uri']) && !empty($big_image['uri'])) {
        $file_image = file_create_url($big_image['uri']);
        $imagedata = file_get_contents($file_image);
        $image_name = end(explode('/', $big_image['uri']));
        $filedir = ITG_IMAGE_FOLDER . 'story' . '/' . $time_folder;
        if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
        }
        $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
        $inserted_data = db_delete('s3fs_file')->condition('uri', $big_image['uri'], '=')
            ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
              'uri' => $file))->condition('fid', $big_image['fid'], '=')
            ->execute();
        all_insert_orignal_image($file, $big_image['fid']);
      }

      //Image style create
//    $extralarge_image_fid = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'];
//    if (!empty($extralarge_image_fid)) {
//      $file = file_load($extralarge_image_fid);
//      itg_story_crate_image_style(EXTRA_LARGE_IMAGE_STYLES, $file->uri);
//    }
//
//    $large_image_fid = $node->field_story_large_image[LANGUAGE_NONE][0]['fid'];
//    if (!empty($large_image_fid)) {
//      $file_large = file_load($large_image_fid);
//      itg_story_crate_image_style(LARGE_IMAGE_STYLES, $file_large->uri);
//    }
//
//    $medium_image_fid = $node->field_story_medium_image[LANGUAGE_NONE][0]['fid'];
//    if (!empty($medium_image_fid)) {
//      $file_meduim = file_load($medium_image_fid);
//      itg_story_crate_image_style(MEDIUM_IMAGE_STYLES, $file_meduim->uri);
//    }
//
//    $small_image_fid = $node->field_story_small_image[LANGUAGE_NONE][0]['fid'];
//    if (!empty($small_image_fid)) {
//      $file_small = file_load($small_image_fid);
//      itg_story_crate_image_style(SMALL_IMAGE_STYLES, $file_small->uri);
//    }
//
//    $small_extra_image_fid = $node->field_story_extra_small_image[LANGUAGE_NONE][0]['fid'];
//    if (!empty($small_extra_image_fid)) {
//      $file_extra_small = file_load($small_extra_image_fid);
//      itg_story_crate_image_style(SMALL_EXTRA_IMAGE_STYLES, $file_extra_small->uri);
//    }
      _insert_node_sucecss($node->nid, $node_type);
      print $res->nid . ',';
    }
  }
}
