<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

story_field_update();

function story_field_update() {
  $path_xml = 'sites/default/files/migrate/xml_file/PTI_SECOND/';
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path_xml)) as $filename) {
    $file_name = $filename->getFilename();
    if ($file_name == '.' || $file_name == '..') {
      continue;
    }
    $xml_data = simplexml_load_file($path_xml . $file_name, 'SimpleXMLElement');
    foreach ($xml_data->story as $xml) {
      $nid = '';
      $data_city = '';
      $published_date = '';
      $published_date_ist = '';
      $published_dates = '';
      $node_sef = '';
      $node_new_sefurl = '';
      $caption_text = '';
      $fid = '';
      $ptype = '';
      $ctype = '';
      $path = '';

      if (!empty((int) $xml->primarycategory) && !empty((int) $xml->categories->category)) { //Check primary cat and cat not blank
        $nid = _return_nid_by_xml_id($xml->id);
        $check_updated = check_updated_node_stories($nid, $xml->id, $file_name);
        $chk = 0;
        if (empty($check_updated)) {
          if (!empty($nid)) {
            $node = node_load($nid);
            if (!empty($node->field_story_redirection_url_titl[LANGUAGE_NONE][0]['value'])) {
              $node->field_story_redirection_url_titl[LANGUAGE_NONE][0]['value'] = '';
            }

// external url
            if (!empty($xml->external_url)) { // update for external url we have to create field in story form.
              $node->field_story_external_url[LANGUAGE_NONE][0]['value'] = (string) $xml->external_url;
            }

// multiple city
            /* multiple city update */
            if (isset($xml->cities->city) && !empty($xml->cities->city)) {
              foreach ($xml->cities->city as $final_city) {
                $data_city[]['tid'] = get_itg_destination_id('migrate_map_itgcity', (int) $final_city);
              }
            }

            if (!empty($data_city) && isset($data_city)) {
              unset($node->field_stroy_city[LANGUAGE_NONE]);
              $node->field_stroy_city[LANGUAGE_NONE] = $data_city;
            }
//source id in node
            $node->field_story_source_id['und'][0]['value'] = (int) $xml->id;


            if (!empty((int) $xml->publisheddate)) {
              $published_date = (int) $xml->publisheddate;
            }
            else {
              $published_date = (int) $xml->createddate;
            }
            if (!empty($published_date)) {
              $published_date_ist = $published_date;
              $published_dates = date('Y-m-d H:i:s', $published_date_ist);
            }
// publish date update according IST time zone
            $node->field_itg_content_publish_date[LANGUAGE_NONE][0]['value'] = $published_dates;

            field_attach_update('node', $node);

            /* URl Alias Update Work */
            if (!empty($xml->metatags->sefurl)) {
//Delete old sef url
              $nid = $node->nid;
              update_alias_deletes($nid);
              $node_sef = (string) $xml->metatags->sefurl;
              if (empty($node_sef)) {
                $title = (string) $xml->longheadline;
                $node_sef = itg_common_custompath_insert_val($title);
              }
//$node_new_sefurl = itg_migrate_new_custompath($node, $published_dates, $node_sef);
              $newpath = itg_custompath_migrated_url_alias($node, $published_dates, $node_sef);
              $path = array(
                'source' => "node/{$node->nid}",
                'alias' => $newpath, // Any alias that you want to set.
              );
              path_save($path);
            }

//image caption
            if (!empty((string) $xml->kicker_image_caption)) {
              $caption_text = (string) $xml->kicker_image_caption;
              $fid = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'];
              if (!empty($fid) && !empty($caption_text)) {
                image_caption_insert_db($caption_text, $fid);
              }
            }
            node_update_insert_status_update($node->nid, $xml->id, $file_name);
            echo $xml->id . ', ';
          }
        }
      }
      else {// primary cat blank or cat blank
        if (empty((int) $xml->primarycategory)) {
          $ptype = 'primary_category';
        }
        if (!empty((int) $xml->categories->category)) {
          $ctype = 'category';
        }
        node_update_blank_category($ptype, $ctype, $xml->id, $file_name, $node->nid);
      }
    }
    if (copy($path_xml . $file_name, "sites/default/files/migrate/xml_file/story_all_complete_pti/".$file_name)) {  unlink($path_xml . $file_name);}
  }
}

/**
 * node status save in db
 */
function node_update_insert_status_update($nid, $xml_id, $file_name) {
  db_insert('story_fields_update_script_check')
      ->fields(array(
        'xml_id' => $xml_id,
        'nid' => $nid,
        'xml_name' => $file_name,
        'image_update' => 'pti_second',
      ))
      ->execute();
}

/**
 * Check updated node
 */
function check_updated_node_stories($nid, $xml_id, $xml_file_name) {
  
  if($xml_file_name != 'indiatoday-story_2009-12-01.xml') {
    $result = '';
    return $result;
  }
    $query = db_select('story_fields_update_script_check', 'sfuus');
     $query->fields('sfuus', array('id'));
    $query->condition('nid', $nid, '=');
    $query->condition('xml_id', $xml_id, '=');
    $query->condition('image_update', 'pti_second', '=');
    $result = $query->execute()->fetchField();
  
  return $result;
}

function image_caption_insert_db($caption_text, $fid) {
  db_insert('image_info')
      ->fields(array(
        'image_caption' => $caption_text,
        'fid' => $fid,
      ))
      ->execute();
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
 * Primary and category blank entry
 */
function node_update_blank_category($ptype, $ctype, $xml_id, $file_name, $nid) {
  db_insert('primary_cat_blank_update')
      ->fields(array(
        'xml_id' => $xml_id,
        'xml_name' => $file_name.'_pti_second',
        'type' => $ptype . '-' . $ctype,
        'nid' => $nid,
      ))
      ->execute();
}

function update_alias_deletes($nid) {
  $query = db_select('url_alias', 'ua');
  $query->fields('ua', array('pid'));
  $query->condition('source', "node/$nid", '=');
  $result = $query->execute();
  foreach ($result as $rel) {
    path_delete($rel->pid);
  }
}

/**
 * Implement function for url alias
 */
function itg_custompath_migrated_url_alias($node, $published_dates, $node_sef_url) {
  if (!empty($node_sef_url)) {
    $node_sef = $node_sef_url;
  }

  if ($node->type == 'photogallery') {
    $published_date = date('Y-m-d', $node->created);
  }
  else {
    $published_dat = explode(' ', $node->field_itg_content_publish_date['und'][0]['value']);
    $published_date = $published_dat[0];
  }
  $getsection = !empty($node->field_primary_category[LANGUAGE_NONE][0]['value']) ? $node->field_primary_category[LANGUAGE_NONE][0]['value'] : '';
  if (!empty($getsection) && $node->type != 'reporter' || ($node->type == 'podcast')) {
    if ($node->type == 'story' && is_issue_baised_magazine($node)) {
      if (!empty($node->field_story_select_supplement['und'][0]['target_id'])) {
        $pathdata = 'magazine/supplement';
      }
      else {
        $pathdata = 'magazine';
        $pathdata .= '/' . get_path_from_category($getsection);
      }
//Get node type.
      $pathdata .= '/' . $node->type;
// Get issue date.
      $issue_date = $node->field_story_issue_date['und'][0]['value'];
      $issue_date_sef_format = date('Ymd', strtotime($issue_date));
// preapreurl with issue date.
      $pathdata .= '/' . $issue_date_sef_format;
// Add node title.
      $pathdata .= '-' . trim($node_sef);
// Add node id.
      $pathdata .= '-' . $node->nid;
// Add workbanch date.
      $pathdata .= '-' . $published_date;
// Prepare SEO friendly node url
      $newpath = itg_common_custompath_insert_val($pathdata);
      return $newpath;
// Create url alise for magazine type story.      
    }
    elseif ($node->type == 'story' && is_photo_story($node)) {
//Add path from category.
      $pathdata = get_path_from_category($getsection);
// Add static value for photo story.
      $pathdata .= '/photo-story';
// Add node title.
      $pathdata .= '/' . trim($node_sef);
// Add node id.
      $pathdata .= '-' . $node->nid;
// Add workbanch date.
      $pathdata .= '-' . $published_date;
// Prepare SEO friendly node url
      $newpath = itg_common_custompath_insert_val($pathdata);
      return $newpath;
// Create url alise for magazine type story.      
    }
    elseif ($node->type == 'breaking_news') {
//Add path from category.
      $pathdata = get_path_from_category($getsection);
// Add static value for photo story.
      $pathdata .= '/story';
// Add node title.
      $pathdata .= '/' . trim($node_sef);
// Add node id.
      $pathdata .= '-' . $node->nid;
// Add workbanch date.
      $pathdata .= '-' . $published_date;
// Prepare SEO friendly node url
      $newpath = itg_common_custompath_insert_val($pathdata);
      return $newpath;
    }
    else {
      $set_hierarchy = get_path_from_category($getsection);
      $node_CT = $node->type;
      if ($node_CT == 'photogallery') {
        $node_CT = 'photo';
      }
      elseif ($node_CT == 'videogallery') {
        $node_CT = 'videos';
      }
      $pathdata = $set_hierarchy . '/' . $node_CT . '/' . trim($node_sef) . '-' . $node->nid . '-' . $published_date;
      $newpath = itg_common_custompath_insert_val($pathdata);
      return $newpath;
    }
  }
  elseif ($node->type == 'reporter') {
    $occupation_tid = $node->field_celebrity_pro_occupation['und'][0]['tid'];
    $occupation = _occupation_from_tid_for_sef_url($occupation_tid);
    $pathdata = $occupation . '/' . $edited_sef_url;
    $newpath = itg_common_custompath_insert_val($pathdata);
    return $newpath;
  }
  elseif ($node->type == 'itg_funalytics') {
    $pathdata = 'understand' . '/' . $edited_sef_url;
    $newpath = itg_common_custompath_insert_val($pathdata);
    return $newpath;
  }
  elseif ($node->type == 'mega_review_critic') {
    $pathdata = 'movie/mega-review' . '/' . trim($node_sef) . '-' . $node->nid . '-' . $published_date;
    $newpath = itg_common_custompath_insert_val($pathdata);
    return $newpath;
  }
  elseif ($node->type == 'page' || $node->type == 'blog') {
    $pathdata = $edited_sef_url;
    $newpath = itg_common_custompath_insert_val($pathdata);
    return $newpath;
  }
  elseif ($node->type == 'survey' || $node->type == 'quiz' || $node->type == 'poll') {
    $pathdata = strtolower($node->type) . '/' . $edited_sef_url;
    $newpath = itg_common_custompath_insert_val($pathdata);
    return $newpath;
  }
  elseif ($node->type == 'breaking_news' && is_breaking_only($node)) {
// Add node title.
    $pathdata .= 'breakingnews/' . trim($node_sef);
// Prepare SEO friendly node url
    $newpath = itg_common_custompath_insert_val($pathdata);
    return $newpath;
  }
}

?>
