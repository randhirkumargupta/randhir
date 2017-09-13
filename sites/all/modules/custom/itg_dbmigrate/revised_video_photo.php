<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

revised_xml_field_update_video();

function revised_xml_field_update_video() {
  $path_xml = 'sites/default/files/migrate/xml_file/';
   $xml_data = simplexml_load_file($path_xml . 'indiatoday_video_update.xml', 'SimpleXMLElement');
  foreach ($xml_data->videogallery as $xml) {
      $file_name = 'indiatoday_video_update.xml';
    //foreach ($xml_data as $xml) {
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
//p($xml);
      $nid = _return_nid_by_xml_id($xml->id);
//p($nid);
      $check_updated = check_updated_node_stories($nid, $xml->id, $file_name);
      $chk = 0;
      if (empty($check_updated)) {
        if (!empty($nid)) {
          $node = node_load($nid);
//p($node);
// external url
          if (!empty($xml->external_url)) { // update for external url we have to create field in story form.
            $node->field_story_external_url[LANGUAGE_NONE][0]['value'] = (string) $xml->external_url;
          }
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
            $fid = $node->field_story_extra_large_image[LANGUAGE_NONE] [0]['fid'];
            if (!empty($fid) && !empty($caption_text)) {
              image_caption_insert_db($caption_text, $fid);
            }
          }
          node_update_insert_status_update($node->nid, $xml->id, $file_name);

          if (!empty($xml->longheadline)) { //Long Headine update
            $newtitle = (string) $xml->longheadline;
            db_update('node') // Update title in node table
                ->fields(array(
                  'title' => $newtitle,
                ))->condition('nid', $node->nid, '=')->execute();

            db_update('node_revision') // Update title in node revision
                ->fields(array(
                  'title' => $newtitle,
                ))->condition('nid', $node->nid, '=')
                ->execute();
          }

          echo $xml->id .'-'.$node->nid. ', ';
        }
      }
   // }
   // exit;
  }
}

/**
 * node status save in db
 */ function node_update_insert_status_update($nid, $xml_id, $file_name) {
  db_insert('story_fields_update_script_check')
      ->fields(array(
        'xml_id' => $xml_id,
        'nid' => $nid,
        'xml_name' => 'update_failed_story',
        'image_update' => 5,
      ))
      ->
      execute();
}

/**
 * Check updated node
 */ function check_updated_node_stories($nid, $xml_id, $xml_file_name) {
  $query = db_select('story_fields_update_script_check', 'sfuus');
  $query->fields('sfuus', array('id'));
  $query->condition('nid', $nid, '=');
  $query->condition('xml_id', $xml_id, '=');
  $query->condition('image_update', 2, '=');
  $result = $query->
          execute()->fetchField();

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
        'xml_name' => $file_name,
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
  if (!empty($getsection) && $node->type != 'reporter' || ($node->type == 'podcast' )) {
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
