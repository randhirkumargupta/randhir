<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

photo_field_update_cat_map();

function photo_field_update_cat_map() {
  $path_xml = 'sites/default/files/migrate/xml_file/photos-2009-2016/';
  $photo_array_val = category_mapping_multiple_script();
//p($photo_array_val);
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path_xml)) as $filename) {
    $file_name = $filename->getFilename();

    if ($file_name == '.' || $file_name == '..') {
      continue;
    }
    $xml_data = simplexml_load_file($path_xml . $file_name, 'SimpleXMLElement');
    foreach ($xml_data->photogallery as $xml) {
      $nid = '';
      $node = '';
      $final_array = '';
      $published_date = '';
      $published_date_ist = '';
      $published_dates = '';
      $node_sef = '';
      $node_new_sefurl = '';
      $path = '';
      $check_updated = '';

      $nid = _return_nid_by_xml_id_photo((int) $xml->id);
      if (!empty($nid)) {
        $check_updated = check_updated_node_photo($nid, $xml->id, $file_name);
      }
      if (!empty($nid)) {
        if (empty($check_updated)) {
          $node = node_load($nid);
          $new_photo_cat = '';
          $new_photo_cat_section = '';
          $new_photo_cat_category = '';
          $term = '';
          $primary_category = '';
          
          
          foreach ($node->field_story_category['und'] as $photo_cat) {
            foreach ($photo_array_val as $key => $photo_array) {
              if ($photo_cat['tid'] == $photo_array['photo_category']) {
                if (!empty($photo_array['section_id'])) {
                  $primary_category[$key] = $photo_array['section_id'];
                  $new_photo_cat_section[]['tid'] = $photo_array['section_id'];
                  $new_photo_cat_category[]['tid'] = $photo_array['category_id'];
                  //$new_photo_cat[]['tid'] = $photo_array['section_id'];
                }
              }
            }
          }

          $new_photo_cat_old = '';
          $new_photo_cat = '';    
          if(isset($new_photo_cat_section) && !empty($new_photo_cat_section) && isset($new_photo_cat_category) && !empty($new_photo_cat_category)) {
            $new_photo_cat_old = array_merge($new_photo_cat_section, $new_photo_cat_category);
            $new_photo_cat = array_unique($new_photo_cat_old, SORT_REGULAR);
          }

          if (!empty($new_photo_cat) && isset($new_photo_cat)) {
            $final_array = array_merge($node->field_story_category['und'], $new_photo_cat);
            unset($node->field_story_category['und']);
            $node->field_story_category['und'] = $final_array;
          }


          if (!empty($primary_category) && isset($primary_category)) {
            ksort($primary_category);
            $pri_cat = array_values($primary_category);
            $node->field_primary_category['und'][0]['value'] = $pri_cat[0];
          }


          if (!empty($primary_category) && isset($primary_category) && !empty($new_photo_cat) && isset($new_photo_cat)) {
            field_attach_update('node', $node);

            /* URl Alias Update Work */
            // if (!empty($xml->metatags->sef_url)) {
//Delete old sef url
           $nid = $node->nid;
            update_alias_deletes($nid);
            $node_sef_value = (string) $xml->metatags->sef_url;
            if (empty($node_sef_value)) {
              $title = (string) $xml->title;
              $node_sef_value = $title;
            }
            $node_sef = itg_common_custompath_insert_val($node_sef_value);
//$node_new_sefurl = itg_migrate_new_custompath($node, $published_dates, $node_sef);
            $newpath = itg_custompath_migrated_url_alias_photo($node, $published_dates, $node_sef);
            $path = array(
              'source' => "node/{$node->nid}",
              'alias' => $newpath, // Any alias that you want to set.
            );
            path_save($path);
            node_update_insert_status_update_photo_update($nid, $xml->id, $file_name);
          }
        }
      }
      node_update_insert_status_update_photo($nid, $xml->id, $file_name);
      echo $xml->id . ' nid ' . $nid . ', ';
    }
    if (copy($path_xml . $file_name, "sites/default/files/migrate/xml_file/photos_complete/" . $file_name)) {
      unlink($path_xml . $file_name);
    }
  }
}

function _return_nid_by_xml_id_photo($xml_id) {
  $query = db_select('migrate_map_itgphotogallery', 'm_map_i');
  $query->fields('m_map_i', array('destid1'));
  $query->isNotNull('destid1');
  $query->condition('sourceid1', $xml_id, '=');
  $result = $query->execute()->fetchField();
  return $result;
}

function category_mapping_multiple_script() {
  $category_array = array(
    '146' => array('category_id' => 1207843, 'section_id' => 1206689, 'photo_category' => 146),
    '147' => array('category_id' => 1208911, 'section_id' => 1206689, 'photo_category' => 147),
    '102' => array('category_id' => 1208912, 'section_id' => 1206801, 'photo_category' => 102),
    '105' => array('category_id' => 1208913, 'section_id' => 1206801, 'photo_category' => 105),
    '100' => array('category_id' => 1208914, 'section_id' => 1206707, 'photo_category' => 100),
    '125' => array('category_id' => 1207767, 'section_id' => 1206707, 'photo_category' => 125),
    '158' => array('category_id' => 1207964, 'section_id' => 1206707, 'photo_category' => 158),
    '159' => array('category_id' => 1208916, 'section_id' => 1206829, 'photo_category' => 159),
    '213' => array('category_id' => 1208917, 'section_id' => 1206829, 'photo_category' => 213),
  );
  
  foreach($category_array as $cat) {
    $category_final_array[$cat['photo_category']]['category_id'] = $cat['category_id'];
    $category_final_array[$cat['photo_category']]['section_id'] = $cat['section_id'];
    $category_final_array[$cat['photo_category']]['photo_category'] = get_itg_destination_id('migrate_map_itgphoto', $cat['photo_category']);
  }
  return $category_final_array;
}

/**
 * Implement function for url alias
 */
function itg_custompath_migrated_url_alias_photo($node, $published_dates, $node_sef_url) {
  if (!empty($node_sef_url)) {
    $node_sef = $node_sef_url;
  }


  $published_dat = explode(' ', $node->field_itg_content_publish_date['und'][0]['value']);
  $published_date = $published_dat[0];

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

function update_alias_deletes($nid) {
  $query = db_select('url_alias', 'ua');
  $query->fields('ua', array('pid'));
  $query->condition('source', "node/$nid", '=');
  $result = $query->execute();
  foreach ($result as $rel) {
    path_delete($rel->pid);
  }
}

function check_updated_node_photo($nid, $xml_id, $xml_file_name) {
  if ($xml_file_name != 'indiatoday-galler.xml') {
    $result = '';
    return $result;
  }
  $query = db_select('story_fields_update_script_check_photo', 'sfuus');
  $query->fields('sfuus', array('id'));
  $query->condition('nid', $nid, '=');
  $query->condition('xml_id', $xml_id, '=');
  $query->condition('image_update', 'photo_second_sheet', '=');
  $result = $query->execute()->fetchField();

  return $result;
}

function node_update_insert_status_update_photo($nid = NULL, $xml_id, $file_name) {
  db_insert('story_fields_update_script_check_photo')
      ->fields(array(
        'xml_id' => $xml_id,
        'nid' => $nid,
        'xml_name' => $file_name,
        'image_update' => 'photo_second_sheet',
      ))
      ->execute();
}

function node_update_insert_status_update_photo_update($nid = NULL, $xml_id, $file_name) {
  db_insert('story_fields_update_script_check_photo')
      ->fields(array(
        'xml_id' => $xml_id,
        'nid' => $nid,
        'xml_name' => $file_name,
        'image_update' => 'photo_second_sheet_update',
      ))
      ->execute();
}

?>
