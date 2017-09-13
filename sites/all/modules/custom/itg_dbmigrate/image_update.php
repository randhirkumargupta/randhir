<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

missing_image_update();

function missing_image_update() {
  $path = 'sites/default/files/migrate/xml_file/story_all/';
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path)) as $filename) {
    $file_name = $filename->getFilename();
    if ($file_name == '.' || $file_name == '..') {
      continue;
    }
    $xml_data = simplexml_load_file($path . $file_name, 'SimpleXMLElement');
    foreach ($xml_data->story as $xml) {
      $fid = '';
      $fid_large = '';
      $fid_medium = '';
      $fid_small = '';
      $fid_esmall = '';
      $fid_expert = '';
      $fid_quote = '';
      $fid_pros_cons = '';
      $fid_facebook_animated = '';
      $fid_big = '';
      $nid = _return_nid_by_xml_id($xml->id);
      $check_updated = check_updated_node_story($nid, $xml->id);
      $chk = 0;
      if (empty($check_updated)) {
        if (!empty($nid)) {
          $node = node_load($nid);
          if (!isset($node->field_story_extra_large_image['und']) && empty($node->field_story_extra_large_image['und'][0])) {
            $extralargeimage_url = (string) $xml->extralargeimage;
            if (!empty($extralargeimage_url)) {
              $fid = img_save_return_fid($extralargeimage_url, $node->nid, (int) $xml->id, 'extralargeimage');
              if (!empty($fid)) {
                $node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'] = $fid;
                $node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt'] = (string) $xml->extra_large_alt;
                $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title'] = (string) $xml->extra_large_title;
                $chk = 1;
              }
            }
          }
          if (!isset($node->field_story_large_image['und']) && empty($node->field_story_large_image['und'][0])) {
            $largeimage_url = (string) $xml->largeimage;

            if (!empty($largeimage_url)) {
              $fid_large = img_save_return_fid($largeimage_url, $node->nid, (int) $xml->id, 'largeimage');
              if (!empty($fid_large)) {
                $node->field_story_large_image[LANGUAGE_NONE][0]['fid'] = $fid_large;
                $node->field_story_large_image[LANGUAGE_NONE][0]['alt'] = (string) $xml->large_alt;
                $node->field_story_large_image[LANGUAGE_NONE][0]['title'] = (string) $xml->large_title;
                $chk = 1;
              }
            }
          }
          if (!isset($node->field_story_medium_image['und']) && empty($node->field_story_medium_image['und'][0])) {
            $medium_url = (string) $xml->mediumimage;

            if (!empty($medium_url)) {
              $fid_medium = img_save_return_fid($medium_url, $node->nid, (int) $xml->id, 'mediumimage');
              if (!empty($fid_medium)) {
                $node->field_story_medium_image[LANGUAGE_NONE][0]['fid'] = $fid_medium;
                $node->field_story_medium_image[LANGUAGE_NONE][0]['alt'] = (string) $xml->mediumimage_alt;
                $node->field_story_medium_image[LANGUAGE_NONE][0]['title'] = (string) $xml->mediumimage_title;
                $chk = 1;
              }
            }
          }
          if (!isset($node->field_story_small_image['und']) && empty($node->field_story_small_image['und'][0])) {
            $small_url = (string) $xml->smallimage;

            if (!empty($small_url)) {
              $fid_small = img_save_return_fid($small_url, $node->nid, (int) $xml->id, 'smallimage');
              if (!empty($fid_small)) {
                $node->field_story_small_image[LANGUAGE_NONE][0]['fid'] = $fid_small;
                $node->field_story_small_image[LANGUAGE_NONE][0]['alt'] = (string) $xml->smallimage_alt;
                $node->field_story_small_image[LANGUAGE_NONE][0]['title'] = (string) $xml->smallimage_title;
                $chk = 1;
              }
            }
          }
          if (!isset($node->field_story_extra_small_image['und']) && empty($node->field_story_extra_small_image['und'][0])) {
            $esmall_url = (string) $xml->extrasmallimage;

            if (!empty($esmall_url)) {
              $fid_esmall = img_save_return_fid($esmall_url, $node->nid, (int) $xml->id, 'extrasmallimage');
              if (!empty($fid_esmall)) {
                $node->field_story_extra_small_image[LANGUAGE_NONE][0]['fid'] = $fid_esmall;
                $node->field_story_extra_small_image[LANGUAGE_NONE][0]['alt'] = (string) $xml->extra_small_alt;
                $node->field_story_extra_small_image[LANGUAGE_NONE][0]['title'] = (string) $xml->extra_small_title;
                $chk = 1;
              }
            }
          }
          if (!isset($node->field_story_expert_image['und']) && empty($node->field_story_expert_image['und'][0])) {
            $expert_url = (string) $xml->expertimage;

            if (!empty($expert_url)) {
              $fid_expert = img_save_return_fid($expert_url, $node->nid, (int) $xml->id, 'expertimage');
              if (!empty($fid_expert)) {
                $node->field_story_expert_image[LANGUAGE_NONE][0]['fid'] = $fid_expert;
                $node->field_story_expert_image[LANGUAGE_NONE][0]['alt'] = (string) $xml->expert_alt;
                $node->field_story_expert_image[LANGUAGE_NONE][0]['title'] = (string) $xml->expert_title;
                $chk = 1;
              }
            }
          }
          if (!isset($node->field_story_quote_image['und']) && empty($node->field_story_quote_image['und'][0])) {
            $quote_url = (string) $xml->fulltext_conclaveformat->quote_image;

            if (!empty($quote_url)) {
              $fid_quote = img_save_return_fid($quote_url, $node->nid, (int) $xml->id, 'quote_image');
              if (!empty($fid_quote)) {
                $node->field_story_quote_image[LANGUAGE_NONE][0]['fid'] = $fid_quote;
                $chk = 1;
              }
            }
          }
          if (!isset($node->field_story_tech_pros_cons_image['und']) && empty($node->field_story_tech_pros_cons_image['und'][0])) {
            $pros_cons_url = (string) $xml->pros_cons->tech_pros_cons_main->pron_cons_img;

            if (!empty($pros_cons_url)) {
              $fid_pros_cons = img_save_return_fid($pros_cons_url, $node->nid, (int) $xml->id, 'pron_cons_img');
              if (!empty($fid_pros_cons)) {
                $node->field_story_tech_pros_cons_image[LANGUAGE_NONE][0]['fid'] = $fid_pros_cons;
                $chk = 1;
              }
            }
          }
          if (!isset($node->field_story_tech_image_gallery['und']) && empty($node->field_story_tech_image_gallery['und'][0])) {
            $fid_array = array();
            foreach ($xml->tech_image_gallery->image as $tech_img) {
              if (!empty($tech_img)) {
                $fid_array[]['fid'] = img_save_return_fid($tech_img, $node->nid, (int) $xml->id, 'tech_image_gallery');
              }
            }
            if (!empty($fid_array) && isset($fid_array)) {
              $node->field_story_tech_image_gallery[LANGUAGE_NONE] = $fid_array;
              $chk = 1;
            }
          }
          if (!isset($node->field_facebook_animated_image['und']) && empty($node->field_facebook_animated_image['und'][0])) {
            $facebook_animated_url = (string) $xml->facebook_instant_article_integration->animated_image;
            $fid_facebook_animated = '';
            if (!empty($facebook_animated_url)) {
              $fid_facebook_animated = img_save_return_fid($facebook_animated_url, $node->nid, (int) $xml->id, 'animated_image');
              if (!empty($fid_facebook_animated)) {
                $node->field_facebook_animated_image[LANGUAGE_NONE][0]['fid'] = $fid_facebook_animated;
                $chk = 1;
              }
            }
          }
          if (!isset($node->field_story_big_image['und']) && empty($node->field_story_big_image['und'][0])) {
            $big_url = (string) $xml->bigimage;

            if (!empty($big_url)) {
              $fid_big = img_save_return_fid($big_url, $node->nid, (int) $xml->id, 'big_image');
              if (!empty($fid_big)) {
                $node->field_story_big_image[LANGUAGE_NONE][0]['fid'] = $fid_big;
                $chk = 1;
              }
            }
          }
          field_attach_update('node', $node);
          node_update_insert_status($node->nid, $xml->id, $file_name, $chk);
          echo $node->nid . '->' . $xml->id . ', ';
        }
      }
    }
  }
}

/**
 * Image save and return fid
 */
function img_save_return_fid($image_url, $nid, $xml_id, $field_name) {
  if (!empty($image_url)) {
    try {
      $img_data = file_get_contents($image_url);
      if ($img_data === FALSE) {
        return '';
      }
      else {
        $file = file_save_data($img_data, file_default_scheme() . '://' . basename($image_url), FILE_EXISTS_RENAME);
        $file->status = 1;
        $image = (array) $file;
        return $image['fid'];
      }
    }
    catch (Exception $e) {
      db_insert('story_missed_image_update')
          ->fields(array(
            'xml_id' => $xml_id,
            'nid' => $nid,
            'image_fail_message' => $e->getMessage(),
            'image_field_name' => $field_name,
          ))
          ->execute();
    }
  }
}

function _return_nid_by_xml_id($xml_id) {
  $query = db_select('migrate_map_itgstorylist', 'm_map_i');
  $query->fields('m_map_i', array('destid1'));
  $query->isNotNull('destid1');
  $query->condition('sourceid1', $xml_id, '=');
  $result = $query->execute()->fetchField();
  return $result;
}

/**
 * node status save in db
 */
function node_update_insert_status($nid, $xml_id, $xml_name, $chk) {
  db_insert('story_fields_update_update_script')
      ->fields(array(
        'xml_id' => $xml_id,
        'nid' => $nid,
        'xml_name' => $xml_name,
        'image_update' => $chk,
      ))
      ->execute();
}

/**
 * Check updated node
 */
function check_updated_node_story($nid, $xml_id) {
  $query = db_select('story_fields_update_update_script', 'sfuus');
  $query->fields('sfuus', array('nid'));
  $query->condition('nid', $nid, '=');
  $query->condition('xml_id', $xml_id, '=');
  $result = $query->execute()->fetchField();
  return $result;
}

/*
  CREATE TABLE IF NOT EXISTS `story_fields_update_update_script` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nid` int(11) NOT NULL,
  `xml_id` int(11) NOT NULL,
  `xml_name` varchar(255) NOT NULL,
  `image_update` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
  ) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=28 ;
 */

/*
  CREATE TABLE IF NOT EXISTS `story_missed_image_update` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `xml_id` int(11) DEFAULT NULL,
  `nid` int(11) DEFAULT NULL,
  `image_fail_message` varchar(500) DEFAULT NULL,
  `image_field_name` varchar(500) DEFAULT NULL,
  PRIMARY KEY (`id`)
  ) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;
 */
?>
