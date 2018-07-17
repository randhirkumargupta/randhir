<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

video_field_update_sub_category_map_11();

function video_field_update_sub_category_map_11() {
  $path_xml = 'sites/default/files/migrate/xml_file/videos_category_complete_2008-10/';
  $photo_array_val = category_mapping_script();
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path_xml)) as $filename) {
    $file_name = $filename->getFilename();

    if ($file_name == '.' || $file_name == '..') {
      continue;
    }
    $xml_data = simplexml_load_file($path_xml . $file_name, 'SimpleXMLElement');
    foreach ($xml_data->videogallery as $xml) {
      $nid = '';
      $node = '';
      $final_array = '';
      $published_date = '';
      $published_date_ist = '';
      $published_dates = '';
      $node_sef = '';
      $node_sef_value = '';
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
          $term = '';
          $primary_category = '';
          $primary_category_new = '';
          $new_photo_sec = '';
          $new_photo_category = '';
          $new_photo_sub_category = '';
          //Check all category

          foreach ($node->field_story_category['und'] as $photo_cat) {
            foreach ($photo_array_val as $key => $photo_array) {
              if ($photo_cat['tid'] == $photo_array['video_category_id']) {
                  
                if (!empty($photo_array['section']) && !empty($photo_array['category_id']) && !empty($photo_array['sub_category_id'])) {
                  if($photo_array['section'] != $photo_cat['tid']) {
                    $new_photo_sec[]['tid'] = $photo_array['section'];
                  }
                 if($photo_array['category_id'] != $photo_cat['tid']) {
                   $new_photo_category[]['tid'] = $photo_array['category_id'];
                  } 
                 if($photo_array['sub_category_id'] != $photo_cat['tid']) {
                   $new_photo_sub_category[]['tid'] = $photo_array['sub_category_id'];
                  } 
                }
              }
            }
          }
                   if(!empty($new_photo_sec) && !empty($new_photo_category) && !empty($new_photo_sub_category)){
                      $new_photo_cat = array_merge($new_photo_sec, $new_photo_category, $new_photo_sub_category);
                  }

          // Primary category code.
          $p_catgory = (string) $xml->primarycategory;
          $priy_cat = explode('#', $p_catgory);
          $original_primary_category = end($priy_cat);
          $primary_category = get_itg_destination_id('migrate_map_itgcategory', $original_primary_category);
          foreach ($photo_array_val as $key => $photo_array) {
              if ($primary_category == $photo_array['video_category_id']) {
                if (!empty($photo_array['sub_category_id'])) {
                  $primary_category_new = $photo_array['sub_category_id'];
                }
              }
            }

          if (!empty($primary_category_new) && isset($primary_category_new)) {
            $node->field_primary_category['und'][0]['value'] = $primary_category_new;
          }

          if (!empty($new_photo_cat) && isset($new_photo_cat)) {
            $final_array = array_merge($node->field_story_category['und'], $new_photo_cat);
            unset($node->field_story_category['und']);
            $node->field_story_category['und'] = $final_array;
          }
          field_attach_update('node', $node);

          /* URl Alias Update Work */
          // if (!empty($xml->metatags->sef_url)) {
//Delete old sef url
          $nid = $node->nid;
          update_alias_deletes($nid);
          $node_sef_value = (string) $xml->metatags->sefurl;
          if (empty($node_sef_value)) {
            $title = (string) $xml->title;
            $node_sef_value = $title;
          }
          $node_sef = itg_common_custompath_insert_val($node_sef_value);
//$node_new_sefurl = itg_migrate_new_custompath($node, $published_dates, $node_sef);
          $newpath = itg_custompath_migrated_url_alias_photo($node, $node_sef);
          $path = array(
            'source' => "node/{$node->nid}",
            'alias' => $newpath, // Any alias that you want to set.
          );
          path_save($path);
        }
      }
      node_update_insert_status_update_photo($nid, $xml->id, $file_name);
      update_table_taxonomy_index($node);
     // ordering_set_of_content_cat_map($node, (string) $xml->ordering);
      echo $xml->id . ' nid ' . $nid . ', ';
      // echo $xml->id . ' nid ' . $nid . ', '.$primary_category_new.',,';
    }
    if (copy($path_xml . $file_name, "sites/default/files/migrate/xml_file/videos_sub_cateogory_complete_2008_10/" . $file_name)) {
      unlink($path_xml . $file_name);
    }
  }
}

function _return_nid_by_xml_id_photo($xml_id) {
  $query = db_select('migrate_map_itgvideogallery', 'm_map_i');
  $query->fields('m_map_i', array('destid1'));
  $query->isNotNull('destid1');
  $query->condition('sourceid1', $xml_id, '=');
  $result = $query->execute()->fetchField();
  return $result;
}

// Total value : 375
// Total remove : 'na' and text:237
// Total value for use : 138 // confirm with santosh // 4 multiple in photo
function category_mapping_script() {
  $file_path = 'sites/default/files/migrate/xml_file/new_cat_map_video_08_10/';
  $file_name = 'ContentMapping-Complete-Master_KT_SubCategory.csv';

  $row = 1;
  $count = 0;
  if (($handle = fopen($file_path . $file_name, "r")) !== FALSE) {
    while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
      $num = count($data);
      $row++;
      $count++;
      for ($c = 0; $c < $num; $c++) {
        $value_photo[$count]['video_category_id'] = (!empty($data[9] && is_numeric($data[9])) ? get_itg_destination_id('migrate_map_itgcategory', $data[9]) : 'NA');
        $value_photo[$count]['section'] = ($data[0] == '*')?(!empty($data[2] && is_numeric($data[2])) ? $data[2] : 'NA') : (!empty($data[0] && is_numeric($data[0])) ? get_itg_destination_id('migrate_map_itgsection', $data[0]) : 'NA');
        $value_photo[$count]['section_mannual_add'] = (!empty($data[2] && is_numeric($data[2])) ? $data[2] : 'NA');
        $value_photo[$count]['section_title'] = (!empty($data[1]) ? $data[1] : 'NA');
        $value_photo[$count]['video_orig_category_id'] = (!empty($data[9] && is_numeric($data[9])) ? $data[9] : 'NA');
        $value_photo[$count]['orignal_section'] = (!empty($data[0]) ? $data[0] : 'NA');
        $value_photo[$count]['category_id'] = ($data[3] == '*')?(!empty($data[5] && is_numeric($data[5])) ? $data[5] : 'NA') : (!empty($data[3] && is_numeric($data[3])) ? get_itg_destination_id('migrate_map_itgcategory', $data[3]) : 'NA');
        $value_photo[$count]['orignal_category_id'] = (!empty($data[3] && is_numeric($data[3])) ? $data[3] : 'NA');
        $value_photo[$count]['category_title'] = (!empty($data[4]) ? $data[4] : 'NA');
        $value_photo[$count]['category_mannual_add'] = (!empty($data[5] && is_numeric($data[5])) ? $data[5] : 'NA');
        $value_photo[$count]['sub_category_title'] = (!empty($data[7]) ? $data[7] : 'NA');
        $value_photo[$count]['sub_category_id'] = ($data[6] == '*')?(!empty($data[8] && is_numeric($data[8])) ? $data[8] : 'NA') : (!empty($data[6] && is_numeric($data[6])) ? get_itg_destination_id('migrate_map_itgsubcategory', $data[6]) : 'NA');
        $value_photo[$count]['sub_category_mannual_add'] = (!empty($data[8] && is_numeric($data[8])) ? $data[8] : 'NA');
      }
    }
  }
  //p($value_photo);
  $photo_csv_array = array_slice($value_photo, 1);
  return $photo_csv_array;
  fclose($handle);
}

/**
 * Implement function for url alias
 */
function itg_custompath_migrated_url_alias_photo($node, $node_sef_url) {
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
        $node_CT = 'video';
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
  $query = db_select('story_fields_update_script_check_photo', 'sfuus');
  $query->fields('sfuus', array('id'));
  $query->condition('nid', $nid, '=');
  $query->condition('xml_id', $xml_id, '=');
  $query->condition('image_update', 'video_final_sub_category_updatess', '=');
  $result = $query->execute()->fetchField();

  return $result;
}

function node_update_insert_status_update_photo($nid = NULL, $xml_id, $file_name) {
  db_insert('story_fields_update_script_check_photo')
      ->fields(array(
        'xml_id' => $xml_id,
        'nid' => $nid,
        'xml_name' => $file_name,
        'image_update' => 'video_final_sub_category_updatess',
      ))
      ->execute();
}


/***********INSERT DATA IN TAXONOMY TERM INDEX******************************/

/**
 * Ordering save in widget order table
 */
function ordering_set_of_content_cat_map($node, $count) {
  $nid = $node->nid;
  if (isset($node->field_story_category['und'])) {
    $cat_id = $node->field_story_category['und'];
      foreach ($cat_id as $category) {
        $exist_cat_id = '';
        $exist_cat_section_id = '';
        $exist_cat_id = check_ordering_cat_id($nid, $category['tid']);
        $exist_cat_section_id = check_ordering_cat_id_section($nid, $category['tid']);
        if (empty($exist_cat_section_id)) {
        if (function_exists('__itg_widget_helper_data_insert')) {
                            __itg_widget_helper_data_insert($node->nid);
                        }
        
         $query = db_insert('itg_widget_order_section')
        ->fields(array(
          'nid' => $nid,
          'widget' => 'section_wise_widget',
          'content_type' => $node->type,
          'cat_id' => $category['tid'],
          'weight' => $count,
          'extra' => "",
        ))
        ->execute();
         _delete_old_data_from_section_widget('itg_widget_order_section', $category['tid'], $node->type);
        }
if (empty($exist_cat_id)) {
  if (function_exists('__itg_widget_helper_data_insert')) {
                            __itg_widget_helper_data_insert($node->nid);
                        }
        $query = db_insert('itg_widget_order')
        ->fields(array(
          'nid' => $nid,
            'widget' => 'section_wise_widget',
            'content_type' => 'All',
            'cat_id' => $category['tid'],
            'weight' => $count,
            'extra' => '',
        ))
        ->execute();  
       _delete_old_data_from_section_widget('itg_widget_order', $category['tid'], "all");
      }
    }
  }
}

/**
 * Implement function for check category id for order
 */
function check_ordering_cat_id($nid, $cat_id) {
  $query = db_select('itg_widget_order', 'iwo');
  $query->fields('iwo', array('cat_id'));
  $query->condition('cat_id', $cat_id, '=');
  $query->condition('nid', $nid, '=');
  $result = $query->execute()->fetchField();
  return $result;
}
/**
 * Implement function for check category id for order
 */
function check_ordering_cat_id_section($nid, $cat_id) {
  $query = db_select('itg_widget_order_section', 'iwos');
  $query->fields('iwos', array('cat_id'));
  $query->condition('cat_id', $cat_id, '=');
  $query->condition('nid', $nid, '=');
  $result = $query->execute()->fetchField();
  return $result;
}


/**
 * Insert data in taxonomy_index table
 * @param type $tid
 * @param type $nid
 * @return type
 */
function update_table_taxonomy_index($node) {
  $nid = $node->nid;
  if (isset($node->field_story_category['und'])) {
    $cat_id = $node->field_story_category['und'];
      foreach ($cat_id as $category) {
        $exist_cat_idss = '';
        $exist_cat_idss = check_term_index_value($category['tid'], $nid);
        if (empty($exist_cat_idss)) {
        $query = db_insert('taxonomy_index')
            ->fields(array(
              'nid' => $nid,
              'tid' => $category['tid'],
              'sticky' => 0,
              'created' => $node->created,
            ))
            ->execute();

      }
    }
  }
}

function check_term_index_value($tid, $nid) {
  $query = db_select('taxonomy_index', 'iwo');
  $query->fields('iwo', array('tid'));
  $query->condition('tid', $tid, '=');
  $query->condition('nid', $nid, '=');
  $result = $query->execute()->fetchField();
  return $result;
}
?>
