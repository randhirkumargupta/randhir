<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.
/*
 * This temp function
 */

function itg_common_node_for_video_update_image() {
  $result = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('type', 'videogallery', ' = ')
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
      $filedir = ITG_IMAGE_FOLDER . 'video_test' . '/' . $time_folder;
      if (!file_exists(file_default_scheme() . '://' . $filedir)) {
        mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
      }
      $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
      $inserted_data = db_delete('s3fs_file')->condition('uri', $extra_large_image['uri'], '=')
          ->execute();
      $inserted_data = db_update('file_managed')->fields(array(
            'uri' => $file))->condition('fid', $extra_large_image['fid'], '=')
          ->execute();
    }
    // large image
    $large_image['fid'] = $node->field_story_large_image['und'][0]['fid'];
    $large_image['uri'] = $node->field_story_large_image['und'][0]['uri'];
    if (isset($large_image['uri']) && !empty($large_image['uri'])) {
      $file_image = file_create_url($large_image['uri']);
      $imagedata = file_get_contents($file_image);
      $image_name = end(explode('/', $large_image['uri']));
      $filedir = ITG_IMAGE_FOLDER . 'video_test' . '/' . $time_folder;
      if (!file_exists(file_default_scheme() . '://' . $filedir)) {
        mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
      }
      $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
      $inserted_data = db_delete('s3fs_file')->condition('uri', $large_image['uri'], '=')
          ->execute();
      $inserted_data = db_update('file_managed')->fields(array(
            'uri' => $file))->condition('fid', $large_image['fid'], '=')
          ->execute();
    }
    // medium image
    $medium_image['fid'] = $node->field_story_medium_image['und'][0]['fid'];
    $medium_image['uri'] = $node->field_story_medium_image['und'][0]['uri'];
    if (isset($medium_image['uri']) && !empty($medium_image['uri'])) {
      $file_image = file_create_url($medium_image['uri']);
      $imagedata = file_get_contents($file_image);
      $image_name = end(explode('/', $medium_image['uri']));
      $filedir = ITG_IMAGE_FOLDER . 'video_test' . '/' . $time_folder;
      if (!file_exists(file_default_scheme() . '://' . $filedir)) {
        mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
      }
      $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
      $inserted_data = db_delete('s3fs_file')->condition('uri', $medium_image['uri'], '=')
          ->execute();
      $inserted_data = db_update('file_managed')->fields(array(
            'uri' => $file))->condition('fid', $medium_image['fid'], '=')
          ->execute();
    }
    // small image
    $small_image['fid'] = $node->field_story_small_image['und'][0]['fid'];
    $small_image['uri'] = $node->field_story_small_image['und'][0]['uri'];
    if (isset($small_image['uri']) && !empty($small_image['uri'])) {
      $file_image = file_create_url($small_image['uri']);
      $imagedata = file_get_contents($file_image);
      $image_name = end(explode('/', $small_image['uri']));
      $filedir = ITG_IMAGE_FOLDER . 'video_test' . '/' . $time_folder;
      if (!file_exists(file_default_scheme() . '://' . $filedir)) {
        mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
      }
      $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);

      $inserted_data = db_delete('s3fs_file')->condition('uri', $small_image['uri'], '=')
          ->execute();
      $inserted_data = db_update('file_managed')->fields(array(
            'uri' => $file))->condition('fid', $small_image['fid'], '=')
          ->execute();
    }
    //extra small image
    $extra_small_image['fid'] = $node->field_story_extra_small_image['und'][0]['fid'];
    $extra_small_image['uri'] = $node->field_story_extra_small_image['und'][0]['uri'];
    if (isset($extra_small_image['uri']) && !empty($extra_small_image['uri'])) {
      $file_image = file_create_url($extra_small_image['uri']);
      $imagedata = file_get_contents($file_image);
      $image_name = end(explode('/', $extra_small_image['uri']));
      $filedir = ITG_IMAGE_FOLDER . 'video_test' . '/' . $time_folder;
      if (!file_exists(file_default_scheme() . '://' . $filedir)) {
        mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
      }
      $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);

      $inserted_data = db_delete('s3fs_file')->condition('uri', $extra_small_image['uri'], '=')
          ->execute();
      $inserted_data = db_update('file_managed')->fields(array(
            'uri' => $file))->condition('fid', $extra_small_image['fid'], '=')
          ->execute();
    }
    //FAcebook  image
    $facebook_image['fid'] = $node->field_story_facebook_image['und'][0]['fid'];
    $facebook_image['uri'] = $node->field_story_facebook_image['und'][0]['uri'];
    if (isset($facebook_image['uri']) && !empty($facebook_image['uri'])) {
      $file_image = file_create_url($facebook_image['uri']);
      $imagedata = file_get_contents($file_image);
      $image_name = end(explode('/', $facebook_image['uri']));
      $filedir = ITG_IMAGE_FOLDER . 'video_test' . '/' . $time_folder;
      if (!file_exists(file_default_scheme() . '://' . $filedir)) {
        mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
      }
      $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
      $inserted_data = db_delete('s3fs_file')->condition('uri', $facebook_image['uri'], '=')
          ->execute();
      $inserted_data = db_update('file_managed')->fields(array(
            'uri' => $file))->condition('fid', $facebook_image['fid'], '=')
          ->execute();
    }
    //Tweet  image
    $tweet_image['fid'] = $node->field_story_tweet_image['und'][0]['fid'];
    $tweet_image['uri'] = $node->field_story_tweet_image['und'][0]['uri'];
    if (isset($tweet_image['uri']) && !empty($tweet_image['uri'])) {
      $file_image = file_create_url($tweet_image['uri']);
      $imagedata = file_get_contents($file_image);
      $image_name = end(explode('/', $tweet_image['uri']));
      $filedir = ITG_IMAGE_FOLDER . 'video_test' . '/' . $time_folder;
      if (!file_exists(file_default_scheme() . '://' . $filedir)) {
        mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
      }
      $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
      $inserted_data = db_delete('s3fs_file')->condition('uri', $tweet_image['uri'], '=')
          ->execute();
      $inserted_data = db_update('file_managed')->fields(array(
            'uri' => $file))->condition('fid', $tweet_image['fid'], '=')
          ->execute();
    }
    //Tweet  image
    $player_image['fid'] = $node->field_story_player_image['und'][0]['fid'];
    $player_image['uri'] = $node->field_story_player_image['und'][0]['uri'];
    if (isset($player_image['uri']) && !empty($player_image['uri'])) {
      $file_image = file_create_url($player_image['uri']);
      $imagedata = file_get_contents($file_image);
      $image_name = end(explode('/', $player_image['uri']));
      $filedir = ITG_IMAGE_FOLDER . 'video_test' . '/' . $time_folder;
      if (!file_exists(file_default_scheme() . '://' . $filedir)) {
        mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
      }
      $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
      $inserted_data = db_delete('s3fs_file')->condition('uri', $player_image['uri'], '=')
          ->execute();
      $inserted_data = db_update('file_managed')->fields(array(
            'uri' => $file))->condition('fid', $player_image['fid'], '=')
          ->execute();
    }
    print $node->nid . ',';
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
      $filedir = ITG_IMAGE_FOLDER . 'reporter_test' . '/' . $time_folder;
      if (!file_exists(file_default_scheme() . '://' . $filedir)) {
        mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
      }
      $file = file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
      $inserted_data = db_delete('s3fs_file')->condition('uri', $extra_large_image['uri'], '=')
          ->execute();
      $inserted_data = db_update('file_managed')->fields(array(
            'uri' => $file))->condition('fid', $extra_large_image['fid'], '=')
          ->execute();
    }
  }
}



/*
 * This function use for update image in photogallery
 */

function itg_common_node_for_photogallery_update_image() {
  $result = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('type', 'photogallery', ' = ')
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
    $node = node_load($res->nid);
  $node_created_date = $node->created;
  $time_folder =  date('Ym',$node_created_date);
  $node_type = $node->type;
   $filed_collection = $node->field_gallery_image['und'];
    if(!empty($filed_collection)) {
      foreach ($filed_collection as $collection) {
        $col = $collection['value'];
        $photo_details = entity_load('field_collection_item', array($col));
        $fid_gall = $photo_details[$col]->field_images['und'][0]['fid'];
        $fid_uri  = $photo_details[$col]->field_images['und'][0]['uri'];
        
        if(isset($fid_uri) && !empty($fid_uri)) {
         $file_image = file_create_url($fid_uri);
         $imagedata = file_get_contents($file_image);
         $image_name = end(explode('/', $fid_uri));
         $filedir = ITG_IMAGE_FOLDER . 'photogallery_test' . '/' . $time_folder;
          if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
          } 
         $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
         $inserted_data = db_delete('s3fs_file')->condition('uri', $fid_uri, '=')
        ->execute();
         $inserted_data = db_update('file_managed')->fields(array(
        'uri' => $file))->condition('fid', $fid_gall, '=')
        ->execute();
        
        }
 
         $fid_gall_small = $photo_details[$col]->field_photo_small_image['und'][0]['fid'];
        $fid_uri_small  = $photo_details[$col]->field_photo_small_image['und'][0]['uri'];
        if(isset($fid_uri_small) && !empty($fid_uri_small)) {
         $file_image = file_create_url($fid_uri_small);
         $imagedata = file_get_contents($file_image);
         $image_name = end(explode('/', $fid_uri_small));
         
         $filedir = ITG_IMAGE_FOLDER . 'photogallery_test' . '/' . $time_folder;
          if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
          } 
         $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
         $inserted_data = db_delete('s3fs_file')->condition('uri', $fid_uri_small, '=')
        ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
        'uri' => $file))->condition('fid', $fid_gall_small, '=')
        ->execute();
        
        }
        
        $fid_gall_api = $photo_details[$col]->field_api_image['und'][0]['fid'];
        $fid_uri_api  = $photo_details[$col]->field_api_image['und'][0]['uri'];
        if(isset($fid_uri_api) && !empty($fid_uri_api)) {
         $file_image = file_create_url($fid_uri_api);
         $imagedata = file_get_contents($file_image);
         $image_name = end(explode('/', $fid_uri_api));
         $filedir = ITG_IMAGE_FOLDER . 'photogallery_test' . '/' . $time_folder;
          if (!file_exists(file_default_scheme() . '://' . $filedir)) {
          mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
          } 
         $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
         $inserted_data = db_delete('s3fs_file')->condition('uri', $fid_uri_api, '=')
        ->execute();
        $inserted_data = db_update('file_managed')->fields(array(
        'uri' => $file))->condition('fid', $fid_gall_api, '=')
        ->execute();
        
        }
        
      }
    }
  $extra_large_image['fid'] = $node->field_story_extra_large_image['und'][0]['fid'];
  $extra_large_image['uri'] = $node->field_story_extra_large_image['und'][0]['uri'];
  if(isset($extra_large_image['uri']) && !empty($extra_large_image['uri'])) {
  $file_image = file_create_url($extra_large_image['uri']);
  $imagedata = file_get_contents($file_image);
  $image_name = end(explode('/', $extra_large_image['uri']));
   $filedir = ITG_IMAGE_FOLDER . 'photogallery_test' . '/' . $time_folder;
  if (!file_exists(file_default_scheme() . '://' . $filedir)) {
    mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  } 
  $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
   $inserted_data = db_delete('s3fs_file')->condition('uri', $extra_large_image['uri'], '=')
      ->execute();
   $inserted_data = db_update('file_managed')->fields(array(
        'uri' => $file))->condition('fid', $extra_large_image['fid'], '=')
      ->execute();
  }
  // large image
  $large_image['fid'] = $node->field_story_large_image['und'][0]['fid'];
  $large_image['uri'] = $node->field_story_large_image['und'][0]['uri'];
  if(isset($large_image['uri']) && !empty($large_image['uri'])) {
  $file_image = file_create_url($large_image['uri']);
  $imagedata = file_get_contents($file_image);
  $image_name = end(explode('/', $large_image['uri']));
   $filedir = ITG_IMAGE_FOLDER . 'photogallery_test' . '/' . $time_folder;
  if (!file_exists(file_default_scheme() . '://' . $filedir)) {
    mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  } 
  $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name,FILE_EXISTS_REPLACE);
  $inserted_data = db_delete('s3fs_file')->condition('uri', $large_image['uri'], '=')
      ->execute();
   $inserted_data = db_update('file_managed')->fields(array(
        'uri' => $file))->condition('fid', $large_image['fid'], '=')
      ->execute();
  }
   // medium image
  $medium_image['fid'] = $node->field_story_medium_image['und'][0]['fid'];
  $medium_image['uri'] = $node->field_story_medium_image['und'][0]['uri'];
  if(isset($medium_image['uri']) && !empty($medium_image['uri'])) {
  $file_image = file_create_url($medium_image['uri']);
  $imagedata = file_get_contents($file_image);
  $image_name = end(explode('/', $medium_image['uri']));
   $filedir = ITG_IMAGE_FOLDER . 'photogallery_test' . '/' . $time_folder;
  if (!file_exists(file_default_scheme() . '://' . $filedir)) {
    mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  } 
  $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name,FILE_EXISTS_REPLACE);
   $inserted_data = db_delete('s3fs_file')->condition('uri', $medium_image['uri'], '=')
      ->execute();
   $inserted_data = db_update('file_managed')->fields(array(
        'uri' => $file))->condition('fid', $medium_image['fid'], '=')
      ->execute();
  }
   // small image
  $small_image['fid'] = $node->field_story_small_image['und'][0]['fid'];
  $small_image['uri'] = $node->field_story_small_image['und'][0]['uri'];
  if(isset( $small_image['uri']) && !empty( $small_image['uri'])) {
   $file_image = file_create_url($small_image['uri']);
  $imagedata = file_get_contents($file_image);
  $image_name = end(explode('/', $small_image['uri']));
   $filedir = ITG_IMAGE_FOLDER . 'photogallery_test' . '/' . $time_folder;
  if (!file_exists(file_default_scheme() . '://' . $filedir)) {
    mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  } 
  $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name,FILE_EXISTS_REPLACE);

    $inserted_data = db_delete('s3fs_file')->condition('uri', $small_image['uri'], '=')
      ->execute();
   $inserted_data = db_update('file_managed')->fields(array(
        'uri' => $file))->condition('fid', $small_image['fid'], '=')
      ->execute();
  }
     //extra small image
  $extra_small_image['fid'] = $node->field_story_extra_small_image['und'][0]['fid'];
  $extra_small_image['uri'] = $node->field_story_extra_small_image['und'][0]['uri'];
  if(isset($extra_small_image['uri']) && !empty($extra_small_image['uri'])) {
  $file_image = file_create_url($extra_small_image['uri']);
  $imagedata = file_get_contents($file_image);
  $image_name = end(explode('/', $extra_small_image['uri']));
   $filedir = ITG_IMAGE_FOLDER . 'photogallery_test' . '/' . $time_folder;
  if (!file_exists(file_default_scheme() . '://' . $filedir)) {
    mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  } 
  $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name,FILE_EXISTS_REPLACE);

  $inserted_data = db_delete('s3fs_file')->condition('uri', $extra_small_image['uri'], '=')
      ->execute();
   $inserted_data = db_update('file_managed')->fields(array(
        'uri' => $file))->condition('fid', $extra_small_image['fid'], '=')
      ->execute();
  }
   //FAcebook  image
  $facebook_image['fid'] = $node->field_story_facebook_image['und'][0]['fid'];
  $facebook_image['uri'] = $node->field_story_facebook_image['und'][0]['uri'];
  if(isset( $facebook_image['uri']) && !empty( $facebook_image['uri'])) {
  $file_image = file_create_url($facebook_image['uri']);
  $imagedata = file_get_contents($file_image);
  $image_name = end(explode('/', $facebook_image['uri']));
   $filedir = ITG_IMAGE_FOLDER . 'photogallery_test' . '/' . $time_folder;
  if (!file_exists(file_default_scheme() . '://' . $filedir)) {
    mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  } 
  $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name,FILE_EXISTS_REPLACE);
    $inserted_data = db_delete('s3fs_file')->condition('uri', $facebook_image['uri'], '=')
      ->execute();
   $inserted_data = db_update('file_managed')->fields(array(
        'uri' => $file))->condition('fid', $facebook_image['fid'], '=')
      ->execute();
  }
  //Tweet  image
  $tweet_image['fid'] = $node->field_story_tweet_image['und'][0]['fid'];
  $tweet_image['uri'] = $node->field_story_tweet_image['und'][0]['uri'];
  if(isset( $tweet_image['uri']) && !empty( $tweet_image['uri'])) {
  $file_image = file_create_url($tweet_image['uri']);
  $imagedata = file_get_contents($file_image);
  $image_name = end(explode('/', $tweet_image['uri']));
   $filedir = ITG_IMAGE_FOLDER . 'photogallery_test' . '/' . $time_folder;
  if (!file_exists(file_default_scheme() . '://' . $filedir)) {
    mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  } 
  $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name,FILE_EXISTS_REPLACE);
    $inserted_data = db_delete('s3fs_file')->condition('uri', $tweet_image['uri'], '=')
      ->execute();
   $inserted_data = db_update('file_managed')->fields(array(
        'uri' => $file))->condition('fid', $tweet_image['fid'], '=')
      ->execute();
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
      ->condition('type', 'issue', ' = ')
      ->execute()
      ->fetchAll();
  foreach ($result as $res) {
    $issue_large_image = array();
    $issue_small_image = array();
    $node = node_load($res->nid);
 
    $node_created_date = $node->created;
    $time_folder =  date('Ym',$node_created_date);
    $node_type = $node->type;
   
  $issue_large_image['fid'] = $node->field_issue_large_cover_image['und'][0]['fid'];
  $issue_large_image['uri'] = $node->field_issue_large_cover_image['und'][0]['uri'];
  if(isset($issue_large_image['uri']) && !empty($issue_large_image['uri'])) {
  $file_image = file_create_url($issue_large_image['uri']);
  $imagedata = file_get_contents($file_image);
  $image_name = end(explode('/', $issue_large_image['uri']));
   $filedir = ITG_IMAGE_FOLDER . 'issue_test' . '/' . $time_folder;
  if (!file_exists(file_default_scheme() . '://' . $filedir)) {
    mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  } 
  $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
   $inserted_data = db_delete('s3fs_file')->condition('uri', $issue_large_image['uri'], '=')
      ->execute();
   $inserted_data = db_update('file_managed')->fields(array(
        'uri' => $file))->condition('fid', $issue_large_image['fid'], '=')
      ->execute();
  }
  
  // Issue small cover image
    $issue_small_image['fid'] = $node->field_issue_small_cover_image['und'][0]['fid'];
    $issue_small_image['uri'] = $node->field_issue_small_cover_image['und'][0]['uri'];
    if(isset($issue_small_image['uri']) && !empty($issue_small_image['uri'])) {
    $file_image = file_create_url($issue_small_image['uri']);
    $imagedata = file_get_contents($file_image);
    $image_name = end(explode('/', $issue_small_image['uri']));
    $filedir = ITG_IMAGE_FOLDER . 'issue_test' . '/' . $time_folder;
    if (!file_exists(file_default_scheme() . '://' . $filedir)) {
     mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
    } 
    $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
    $inserted_data = db_delete('s3fs_file')->condition('uri', $issue_small_image['uri'], '=')
       ->execute();
    $inserted_data = db_update('file_managed')->fields(array(
         'uri' => $file))->condition('fid', $issue_small_image['fid'], '=')
       ->execute();
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
      ->condition('type', 'supplement', ' = ')
      ->execute()
      ->fetchAll();
  foreach ($result as $res) {
    $supp_large_image = array();
    $supp_small_image = array();
    $node = node_load($res->nid);
    $node_created_date = $node->created;
    $time_folder =  date('Ym',$node_created_date);
    $node_type = $node->type;
   
  $supp_large_image['fid'] = $node->field_issue_supp_large_image['und'][0]['fid'];
  $supp_large_image['uri'] = $node->field_issue_supp_large_image['und'][0]['uri'];
  if(isset($supp_large_image['uri']) && !empty($supp_large_image['uri'])) {
  $file_image = file_create_url($supp_large_image['uri']);
  $imagedata = file_get_contents($file_image);
  $image_name = end(explode('/', $supp_large_image['uri']));
   $filedir = ITG_IMAGE_FOLDER . 'supplement_test' . '/' . $time_folder;
  if (!file_exists(file_default_scheme() . '://' . $filedir)) {
    mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  } 
  $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
   $inserted_data = db_delete('s3fs_file')->condition('uri', $supp_large_image['uri'], '=')
      ->execute();
   $inserted_data = db_update('file_managed')->fields(array(
        'uri' => $file))->condition('fid', $supp_large_image['fid'], '=')
      ->execute();
  }
  
  // Issue small cover image
    $supp_small_image['fid'] = $node->field_issue_supp_small_image['und'][0]['fid'];
    $supp_small_image['uri'] = $node->field_issue_supp_small_image['und'][0]['uri'];
    if(isset($supp_small_image['uri']) && !empty($supp_small_image['uri'])) {
    $file_image = file_create_url($supp_small_image['uri']);
    $imagedata = file_get_contents($file_image);
    $image_name = end(explode('/', $supp_small_image['uri']));
    $filedir = ITG_IMAGE_FOLDER . 'supplement_test' . '/' . $time_folder;
    if (!file_exists(file_default_scheme() . '://' . $filedir)) {
     mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
    } 
    $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
    $inserted_data = db_delete('s3fs_file')->condition('uri', $supp_small_image['uri'], '=')
       ->execute();
    $inserted_data = db_update('file_managed')->fields(array(
         'uri' => $file))->condition('fid', $supp_small_image['fid'], '=')
       ->execute();
    }
    
  }
}

/**
 * This is function use for update megareview image
 */

function itg_common_node_for_mega_review_critic_update_image() {
  $result = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('type', 'mega_review_critic', ' = ')
      ->execute()
      ->fetchAll();
  foreach ($result as $res) {
    $extra_large_image = array();
    $large_image = array();
    $medium_image = array();
    $small_image = array();
    $extra_small_image = array();
    
    $node = node_load($res->nid);
  $node_created_date = $node->created;
  $time_folder =  date('Ym',$node_created_date);
  $node_type = $node->type;
  
  $extra_large_image['fid'] = $node->field_story_extra_large_image['und'][0]['fid'];
  $extra_large_image['uri'] = $node->field_story_extra_large_image['und'][0]['uri'];
  if(isset($extra_large_image['uri']) && !empty($extra_large_image['uri'])) {
  $file_image = file_create_url($extra_large_image['uri']);
  $imagedata = file_get_contents($file_image);
  $image_name = end(explode('/', $extra_large_image['uri']));
   $filedir = ITG_IMAGE_FOLDER . 'mega_review_critic_test' . '/' . $time_folder;
  if (!file_exists(file_default_scheme() . '://' . $filedir)) {
    mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  } 
  $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name, FILE_EXISTS_REPLACE);
   $inserted_data = db_delete('s3fs_file')->condition('uri', $extra_large_image['uri'], '=')
      ->execute();
   $inserted_data = db_update('file_managed')->fields(array(
        'uri' => $file))->condition('fid', $extra_large_image['fid'], '=')
      ->execute();
  }
  // large image
  $large_image['fid'] = $node->field_story_large_image['und'][0]['fid'];
  $large_image['uri'] = $node->field_story_large_image['und'][0]['uri'];
  if(isset($large_image['uri']) && !empty($large_image['uri'])) {
  $file_image = file_create_url($large_image['uri']);
  $imagedata = file_get_contents($file_image);
  $image_name = end(explode('/', $large_image['uri']));
   $filedir = ITG_IMAGE_FOLDER . 'mega_review_critic_test' . '/' . $time_folder;
  if (!file_exists(file_default_scheme() . '://' . $filedir)) {
    mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  } 
  $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name,FILE_EXISTS_REPLACE);
  $inserted_data = db_delete('s3fs_file')->condition('uri', $large_image['uri'], '=')
      ->execute();
   $inserted_data = db_update('file_managed')->fields(array(
        'uri' => $file))->condition('fid', $large_image['fid'], '=')
      ->execute();
  }
   // medium image
  $medium_image['fid'] = $node->field_story_medium_image['und'][0]['fid'];
  $medium_image['uri'] = $node->field_story_medium_image['und'][0]['uri'];
  if(isset($medium_image['uri']) && !empty($medium_image['uri'])) {
  $file_image = file_create_url($medium_image['uri']);
  $imagedata = file_get_contents($file_image);
  $image_name = end(explode('/', $medium_image['uri']));
   $filedir = ITG_IMAGE_FOLDER . 'mega_review_critic_test' . '/' . $time_folder;
  if (!file_exists(file_default_scheme() . '://' . $filedir)) {
    mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  } 
  $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name,FILE_EXISTS_REPLACE);
   $inserted_data = db_delete('s3fs_file')->condition('uri', $medium_image['uri'], '=')
      ->execute();
   $inserted_data = db_update('file_managed')->fields(array(
        'uri' => $file))->condition('fid', $medium_image['fid'], '=')
      ->execute();
  }
   // small image
  $small_image['fid'] = $node->field_story_small_image['und'][0]['fid'];
  $small_image['uri'] = $node->field_story_small_image['und'][0]['uri'];
  if(isset( $small_image['uri']) && !empty( $small_image['uri'])) {
   $file_image = file_create_url($small_image['uri']);
  $imagedata = file_get_contents($file_image);
  $image_name = end(explode('/', $small_image['uri']));
   $filedir = ITG_IMAGE_FOLDER . 'mega_review_critic_test' . '/' . $time_folder;
  if (!file_exists(file_default_scheme() . '://' . $filedir)) {
    mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  } 
  $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name,FILE_EXISTS_REPLACE);

    $inserted_data = db_delete('s3fs_file')->condition('uri', $small_image['uri'], '=')
      ->execute();
   $inserted_data = db_update('file_managed')->fields(array(
        'uri' => $file))->condition('fid', $small_image['fid'], '=')
      ->execute();
  }
     //extra small image
  $extra_small_image['fid'] = $node->field_story_extra_small_image['und'][0]['fid'];
  $extra_small_image['uri'] = $node->field_story_extra_small_image['und'][0]['uri'];
  if(isset($extra_small_image['uri']) && !empty($extra_small_image['uri'])) {
  $file_image = file_create_url($extra_small_image['uri']);
  $imagedata = file_get_contents($file_image);
  $image_name = end(explode('/', $extra_small_image['uri']));
   $filedir = ITG_IMAGE_FOLDER . 'mega_review_critic_test' . '/' . $time_folder;
  if (!file_exists(file_default_scheme() . '://' . $filedir)) {
    mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  } 
  $file =  	file_unmanaged_save_data($imagedata, file_default_scheme() . '://' . $filedir . '/' . $image_name,FILE_EXISTS_REPLACE);

  $inserted_data = db_delete('s3fs_file')->condition('uri', $extra_small_image['uri'], '=')
      ->execute();
   $inserted_data = db_update('file_managed')->fields(array(
        'uri' => $file))->condition('fid', $extra_small_image['fid'], '=')
      ->execute();
  }
   
  }
}