<?php

/**
 * @file
 * Drush support for the itg_dbmigrate module
 */

/**
 * Implementation of hook_drush_command().
 */
function itg_dbmigrate_drush_command() {
  $items = array();
  $items['associate-related-content'] = array(
    'callback' => 'associate_lead_image_video', // Callback function
    'description' => 'Drush command to run associate related content.',
    'aliases' => array('aliv'), // alias of command
  );
  $items['related-content-story'] = array(
    'callback' => 'related_story_migration', // Callback function
    'description' => 'Drush command to run related content story.',
    'aliases' => array('rcstory'), // alias of command
  );
  $items['related-content-photo'] = array(
    'callback' => 'related_photo_migration', // Callback function
    'description' => 'Drush command to run related content photo.',
    'aliases' => array('rcphoto'), // alias of command
  );
  $items['related-content-video'] = array(
    'callback' => 'related_video_migration', // Callback function
    'description' => 'Drush command to run related content video.',
    'aliases' => array('rcvideo'), // alias of command
  );
  $items['related-testing'] = array(
    'callback' => 'related_testing', // Callback function
    'description' => 'Drush command to testing.',
    'aliases' => array('testingved'), // alias of command
  );
  return $items;
}

function associate_lead_image_video() {
  if (!empty(read_folder_xml_associate_related())) {
    $file_path = 'sites/default/files';
    $path_xml = $file_path . '/' . 'migrate/xml_file/migrate_xml/xml_for_migrate/' . read_folder_xml_associate_related() . '/';
    $file_name = 'related_featured_master.xml';
    $xml_data = simplexml_load_file($path_xml . $file_name, 'SimpleXMLElement');
    $story_nid = '';
    $content_type = '';
    $content_nid = '';
    $node = '';
    $related_content_val = '';
    foreach ($xml_data->featuredcontents as $xml) {
      $story_nid = _return_nid_by_xml_id_story_associate((int) $xml->featuredcontent->id);
      $content_type = (string) $xml->featuredcontent->featuredcontenttype;
      $content_nid = _return_nid_by_xml_id_photo_video_associate((int) $xml->featuredcontent->featuredcontentid, $content_type);
      if (!empty($story_nid)) {
        $node = node_load($story_nid);
        if ($content_type == 'photo') {
          $node->field_story_associate_lead['und'][0]['value'] = 'gallery';
        }
        elseif ($content_type == 'video') {
          $node->field_story_associate_lead['und'][0]['value'] = 'video';
        }
        if (!empty($content_nid)) {
          if ($content_type == 'photo') {
            $node->field_associate_photo_gallery['und'][0]['target_id'] = $content_nid;
          }
          elseif ($content_type == 'video') {
            $node->field_story_associate_video['und'][0]['target_id'] = $content_nid;
          }
        }

        field_attach_update('node', $node);
        drush_print($story_nid . ', ');
      }
    }

    //After complete All migration move xml folder in complete folder.
    $file_path = 'sites/default/files';

    $xml_folder = $file_path . '/' . 'migrate/xml_file/migrate_xml/xml_for_migrate/' . read_folder_xml_associate_related();
    if (copy_source_dest_xml_folder($xml_folder, 'sites/default/files/migrate/xml_file/migrate_xml/xml_complete/' . read_folder_xml_associate_related())) {
      delete_xml_folder_after_move($xml_folder);
    }
  }
}

function _return_nid_by_xml_id_photo_video_associate($xml_id, $content_type) {
  $table = '';
  if ($content_type == 'photo') {
    $table = 'migrate_map_itgphotogallery';
  }
  elseif ($content_type == 'video') {
    $table = 'migrate_map_itgvideogallery';
  }
  $query = db_select($table, 'm_map_i');
  $query->fields('m_map_i', array('destid1'));
  $query->isNotNull('destid1');
  $query->condition('sourceid1', $xml_id, '=');
  $result = $query->execute()->fetchField();
  return $result;
}

function _return_nid_by_xml_id_story_associate($xml_id) {
  $query = db_select('migrate_map_itgstorylist', 'm_map_i');
  $query->fields('m_map_i', array('destid1'));
  $query->isNotNull('destid1');
  $query->condition('sourceid1', $xml_id, '=');
  $result = $query->execute()->fetchField();
  return $result;
}

function read_folder_xml_associate_related() {
  $path_xml = 'sites/default/files/migrate/xml_file/migrate_xml/xml_for_migrate/';
  $files = scandir($path_xml);
  if ($files[0] == '.') {
    unset($files[0]);
  }
  if ($files[1] == '..') {
    unset($files[1]);
  }
  $result = array_values($files);

  return $result[0];
}

/**
 * Implement function for crate directory and copy all xmls after complete migration.
 * @param type $src
 * @param type $dst
 * @return boolean
 */
function copy_source_dest_xml_folder($src, $dst) {
  $dir = opendir($src);
  @mkdir($dst, 0777);
  while (false !== ( $file = readdir($dir))) {
    if (( $file != '.' ) && ( $file != '..' )) {
      if (is_dir($src . '/' . $file)) {
        recurse_copy($src . '/' . $file, $dst . '/' . $file);
      }
      else {
        copy($src . '/' . $file, $dst . '/' . $file);
      }
    }
  }
  closedir($dir);
  return true;
}

/**
 * Delete Directory after complete Migration.
 * @param type $dir
 * @return type
 */
function delete_xml_folder_after_move($dir) {
  $files = array_diff(scandir($dir), array('.', '..'));

  foreach ($files as $file) {
    (is_dir("$dir/$file")) ? delTree("$dir/$file") : unlink("$dir/$file");
  }

  return rmdir($dir);
}

/**
 * Implement function for story related
 */
function related_story_migration() {
  //Code for related content
  //code for XML read
  if (!empty(read_folder_xml_associate_related())) {
    $file_path = 'sites/default/files';
    $path_xml = $file_path . '/' . 'migrate/xml_file/migrate_xml/xml_for_migrate/' . read_folder_xml_associate_related() . '/';
    $file_name = 'related_content_master_story.xml';
    $xml_data = simplexml_load_file($path_xml . $file_name, 'SimpleXMLElement');
    $c_type = '';
    foreach ($xml_data->relatedcontents as $xml) {
      $content_id = get_itg_destination_id('migrate_map_itgstorylist', (int) $xml->id);
      if (!empty($content_id)) {
        $related_content_with_title_val = '';
        $related_content_val = '';
        $content_revision_id = get_node_revision_id_related_content($content_id);
        foreach ($xml->relatedcontent as $relatedcontent_data) {
          $relatedcontent_type = (string) $relatedcontent_data->relatedcontenttype;
          if ($relatedcontent_type == 'text') {
            $relatedcontentid = get_itg_destination_id('migrate_map_itgstorylist', (int) $relatedcontent_data->relatedcontentid);
            $c_type = 'Story';
          }
          else if ($relatedcontent_type == 'photo') {
            $relatedcontentid = get_itg_destination_id('migrate_map_itgphotogallery', (int) $relatedcontent_data->relatedcontentid);
            $c_type = 'photogallery';
          }
          else if ($relatedcontent_type == 'video') {
            $relatedcontentid = get_itg_destination_id('migrate_map_itgvideogallery', (int) $relatedcontent_data->relatedcontentid);
            $c_type = 'Video';
          }
          if (!empty($relatedcontentid)) {
            $relatedcontenttitle = (string) $relatedcontent_data->relatedcontenttitle;
            $related_content_val .= 'IT_' . $relatedcontentid . '|~|';
            $related_content_with_title_val .= 'IT_' . $relatedcontentid . '@' . $c_type . '@' . $relatedcontenttitle . '|~|';
          }else{
          //data save for tracking
          related_content_tack((int) $xml->id, $relatedcontent_type, (int) $relatedcontent_data->relatedcontentid, $c_type);
        }
        }
        if (!empty($related_content_val)) {
          $related_content_insert_val = rtrim($related_content_val, '|~|');
          $related_content_insert_title_val = rtrim($related_content_with_title_val, '|~|');

          //insert data in Related Content field
          itg_data_insert_in_field_related_content($content_id, $content_revision_id, 'field_common_related_content', 'story', 'node', $related_content_insert_val);
          itg_data_insert_in_field_related_content($content_id, $content_revision_id, 'field_cm_related_content_detail', 'story', 'node', $related_content_insert_title_val);
          echo $content_id . ', '; //update content id
        }
      }
    }
  }
}

/**
 * Implement function for related content photo 
 */
function related_photo_migration() {
  if (!empty(read_folder_xml_associate_related())) {
    $file_path = 'sites/default/files';
    $path_xml = $file_path . '/' . 'migrate/xml_file/migrate_xml/xml_for_migrate/' . read_folder_xml_associate_related() . '/';
    $file_name = 'related_content_master_photo.xml';
    $xml_data = simplexml_load_file($path_xml . $file_name, 'SimpleXMLElement');
    $c_type = '';
    foreach ($xml_data->relatedcontents as $xml) {
      $content_id = get_itg_destination_id('migrate_map_itgphotogallery', (int) $xml->id);
      if (!empty($content_id)) {

        $related_content_with_title_val = '';
        $related_content_val = '';
        $content_revision_id = get_node_revision_id_related_content($content_id);
        foreach ($xml->relatedcontent as $relatedcontent_data) {
          $relatedcontent_type = (string) $relatedcontent_data->relatedcontenttype;
          if ($relatedcontent_type == 'text') {
            $relatedcontentid = get_itg_destination_id('migrate_map_itgstorylist', (int) $relatedcontent_data->relatedcontentid);
            $c_type = 'Story';
          }
          else if ($relatedcontent_type == 'photo') {
            $relatedcontentid = get_itg_destination_id('migrate_map_itgphotogallery', (int) $relatedcontent_data->relatedcontentid);
            $c_type = 'photogallery';
          }
          else if ($relatedcontent_type == 'video') {
            $relatedcontentid = get_itg_destination_id('migrate_map_itgvideogallery', (int) $relatedcontent_data->relatedcontentid);
            $c_type = 'Video';
          }
          if (!empty($relatedcontentid)) {
            $relatedcontenttitle = (string) $relatedcontent_data->relatedcontenttitle;
            $related_content_val .= 'IT_' . $relatedcontentid . '|~|';
            $related_content_with_title_val .= 'IT_' . $relatedcontentid . '@' . $c_type . '@' . $relatedcontenttitle . '|~|';
          }else{
          //data save for tracking
          related_content_tack((int) $xml->id, $relatedcontent_type, (int) $relatedcontent_data->relatedcontentid, $c_type);
        }
        }
        if (!empty($related_content_val)) {
          $related_content_insert_val = rtrim($related_content_val, '|~|');
          $related_content_insert_title_val = rtrim($related_content_with_title_val, '|~|');

          //insert data in Related Content field
          itg_data_insert_in_field_related_content($content_id, $content_revision_id, 'field_common_related_content', 'photogallery', 'node', $related_content_insert_val);
          itg_data_insert_in_field_related_content($content_id, $content_revision_id, 'field_cm_related_content_detail', 'photogallery', 'node', $related_content_insert_title_val);
          echo $content_id . ', '; //update content id
        }
      }
    }
  }
}

/**
 * Implement function for related video
 */
function related_video_migration() {
  if (!empty(read_folder_xml_associate_related())) {
    $file_path = 'sites/default/files';
    $path_xml = $file_path . '/' . 'migrate/xml_file/migrate_xml/xml_for_migrate/' . read_folder_xml_associate_related() . '/';
    $file_name = 'related_content_master_video.xml';
    $xml_data = simplexml_load_file($path_xml . $file_name, 'SimpleXMLElement');
    $c_type = '';
    foreach ($xml_data->relatedcontents as $xml) {
      $content_id = get_itg_destination_id('migrate_map_itgvideogallery', (int) $xml->id);
      if (!empty($content_id)) {
        $related_content_with_title_val = '';
        $related_content_val = '';
        $content_revision_id = get_node_revision_id_related_content($content_id);
        foreach ($xml->relatedcontent as $relatedcontent_data) {
          $relatedcontent_type = (string) $relatedcontent_data->relatedcontenttype;
          if ($relatedcontent_type == 'text') {
            $relatedcontentid = get_itg_destination_id('migrate_map_itgstorylist', (int) $relatedcontent_data->relatedcontentid);
            $c_type = 'Story';
          }
          else if ($relatedcontent_type == 'photo') {
            $relatedcontentid = get_itg_destination_id('migrate_map_itgphotogallery', (int) $relatedcontent_data->relatedcontentid);
            $c_type = 'photogallery';
          }
          else if ($relatedcontent_type == 'video') {
            $relatedcontentid = get_itg_destination_id('migrate_map_itgvideogallery', (int) $relatedcontent_data->relatedcontentid);
            $c_type = 'Video';
          }
          if (!empty($relatedcontentid)) {
            $relatedcontenttitle = (string) $relatedcontent_data->relatedcontenttitle;
            $related_content_val .= 'IT_' . $relatedcontentid . '|~|';
            $related_content_with_title_val .= 'IT_' . $relatedcontentid . '@' . $c_type . '@' . $relatedcontenttitle . '|~|';
          }else{
          //data save for tracking
          related_content_tack((int) $xml->id, $relatedcontent_type, (int) $relatedcontent_data->relatedcontentid, $c_type);
        }
        }
        if (!empty($related_content_val)) {
          $related_content_insert_val = rtrim($related_content_val, '|~|');
          $related_content_insert_title_val = rtrim($related_content_with_title_val, '|~|');

          //insert data in Related Content field
          itg_data_insert_in_field_related_content($content_id, $content_revision_id, 'field_common_related_content', 'videogallery', 'node', $related_content_insert_val);
          itg_data_insert_in_field_related_content($content_id, $content_revision_id, 'field_cm_related_content_detail', 'videogallery', 'node', $related_content_insert_title_val);
          echo $content_id . ', '; //update content id
        }
      }
    }
  }
}

/**
 * get new content id of itg by old content id
 * @param int $sourceid
 * @return int destination id
 */
function get_node_revision_id_related_content($nid) {
  $query = db_select('node', 'n');
  $query->fields('n', array('vid'));
  $query->condition('nid', $nid);

  return $query->execute()->fetchField();
}

function itg_data_insert_in_field_related_content($nid, $revision_id, $field_name, $bundle, $entity_type, $data) {

  $tb1 = 'field_data_' . $field_name;
  $field = $field_name . '_value';
  $tb2 = 'field_revision_' . $field_name;
  $la = 'und';


  //######################################################################################

  db_delete('field_data_' . $field_name)->condition('entity_id', $nid)->execute();
  db_delete('field_revision_' . $field_name)->condition('entity_id', $nid)->execute();

  //##############################################################################


  db_query("INSERT INTO {$tb1} (entity_type, bundle, deleted, entity_id, revision_id, language, delta, $field) VALUES (:entity_type, :bundle, :deleted, :entity_id, :revision_id, :language, :delta, :field_dt)", array(':entity_type' => $entity_type, ':bundle' => $bundle, ':deleted' => 0, ':entity_id' => $nid, ':revision_id' => $revision_id, ':language' => $la, ':delta' => 0, ':field_dt' => $data));
  db_query("INSERT INTO {$tb2} (entity_type, bundle, deleted, entity_id, revision_id, language, delta, $field) VALUES (:entity_type, :bundle, :deleted, :entity_id, :revision_id, :language, :delta, :field_dt)", array(':entity_type' => $entity_type, ':bundle' => $bundle, ':deleted' => 0, ':entity_id' => $nid, ':revision_id' => $revision_id, ':language' => $la, ':delta' => 0, ':field_dt' => $data));
}


/**
 * Implement function for test cron
 */
function related_testing() {
  $content = failed_record_xml_id('migrate_map_itgstorylist');
      if(!empty($content)) {
      $params = array(
      'body' => $content,
      'subject' => 'Failed Content in Story',
    );
      $mail = drupal_mail('itg_dbmigrate', 'send_mail_failed_content', mail_user_send(), language_default(), $params, 'no-reply@kelltontech.com', TRUE);
    }
  $content = failed_record_xml_id('migrate_map_itgvideogallery');
      if(!empty($content)) {
      $params = array(
      'body' => $content,
      'subject' => 'Failed Content in Video',
    );
      $mail = drupal_mail('itg_dbmigrate', 'send_mail_failed_content', mail_user_send(), language_default(), $params, 'no-reply@kelltontech.com', TRUE);
    }
  $content = failed_record_xml_id('migrate_map_itgphotogallery');
      if(!empty($content)) {
      $params = array(
      'body' => $content,
      'subject' => 'Failed Content in Photo',
    );
      $mail = drupal_mail('itg_dbmigrate', 'send_mail_failed_content', mail_user_send(), language_default(), $params, 'no-reply@kelltontech.com', TRUE);
    }
    //Last process folder mail.
  $last_process_folder = read_folder_last_xml_mail_status();
      if(!empty($last_process_folder)) {
//        $last_time = explode('_', $last_process_folder);
//        $human_time = date('d-m-Y H:i:s', $last_time[1]);
      $params = array(
      'body' => 'Last Migrated Folder name: '.$last_process_folder, //. ' </br > Folder Date & Time : '.$human_time,
      'subject' => 'completed folder name',
    );
      $mail = drupal_mail('itg_dbmigrate', 'send_mail_failed_content', mail_user_send(), language_default(), $params, 'no-reply@kelltontech.com', TRUE);
    }
}

function related_content_tack($content_id, $content_type, $r_content_id, $r_content_type) {
  db_insert('related_content_failed')
          ->fields(array(
            'content_id' => $content_id,
            'content_type' => $content_type,
            'related_content_id' => $r_content_id,
            'related_content_type' => $r_content_type,
          ))
          ->execute();
}

function read_folder_last_xml_mail_status() {
  $path_xml = 'sites/default/files/migrate/xml_file/migrate_xml/xml_complete/';
  $files = scandir($path_xml);
  if ($files[0] == '.') {
    unset($files[0]);
  }
  if ($files[1] == '..') {
    unset($files[1]);
  }
  $result = array_values($files);

  return end($result);
}