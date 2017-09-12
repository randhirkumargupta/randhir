<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

photo_field_update_cat_map();

function photo_field_update_cat_map() {
  $path_xml = 'sites/default/files/migrate/xml_file/updated-conclave-xml-files-04-09-2017/conclave_gallery/';
  $photo_array_val = category_mapping_multiple_script_photo();
 // p($photo_array_val);
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
            ordering_set_of_content_cat_map($node, (string) $xml->ordering);
            echo $xml->id . ' nid ' . $nid . ', ';
          }
        }
      }
      
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

function category_mapping_multiple_script_photo() {
  $mannual_array = array(
    '2507' => array('category_id' => 1709043, 'section_id' => 1708923, 'photo_category' => 1709018),
    '2513' => array('category_id' => 1709044, 'section_id' => 1708923, 'photo_category' => 1709019),
  );
  
  $category_array = array(
    '2522' => array('category_id' => 2510, 'section_id' => 2532, 'photo_category' => 2522),
    '2523' => array('category_id' => 2511, 'section_id' => 2532, 'photo_category' => 2523),
    '2514' => array('category_id' => 2512, 'section_id' => 2532, 'photo_category' => 2514),
    '2539' => array('category_id' => 2538, 'section_id' => 2533, 'photo_category' => 2539),
    '2534' => array('category_id' => 2537, 'section_id' => 2533, 'photo_category' => 2534),
    '2545' => array('category_id' => 2551, 'section_id' => 2534, 'photo_category' => 2545),
    '2546' => array('category_id' => 2552, 'section_id' => 2534, 'photo_category' => 2546),
    '2558' => array('category_id' => 2556, 'section_id' => 2537, 'photo_category' => 2558),
    '2559' => array('category_id' => 2557, 'section_id' => 2537, 'photo_category' => 2559),
    '2566' => array('category_id' => 2570, 'section_id' => 2538, 'photo_category' => 2566),
    '2565' => array('category_id' => 2569, 'section_id' => 2538, 'photo_category' => 2565),
    '2577' => array('category_id' => 2573, 'section_id' => 2539, 'photo_category' => 2577),
    '2578' => array('category_id' => 2574, 'section_id' => 2539, 'photo_category' => 2578),
    '2593' => array('category_id' => 2585, 'section_id' => 2540, 'photo_category' => 2593),
    '2594' => array('category_id' => 2586, 'section_id' => 2540, 'photo_category' => 2594),
    '2601' => array('category_id' => 2595, 'section_id' => 2541, 'photo_category' => 2601),
    '2602' => array('category_id' => 2596, 'section_id' => 2541, 'photo_category' => 2602),
    '2608' => array('category_id' => 2603, 'section_id' => 2542, 'photo_category' => 2608),
    '2609' => array('category_id' => 2605, 'section_id' => 2542, 'photo_category' => 2609),
    '2617' => array('category_id' => 2615, 'section_id' => 2543, 'photo_category' => 2617),
    '2618' => array('category_id' => 2616, 'section_id' => 2543, 'photo_category' => 2618),
    '2624' => array('category_id' => 2622, 'section_id' => 2544, 'photo_category' => 2624),
    '2625' => array('category_id' => 2623, 'section_id' => 2544, 'photo_category' => 2625),
  );
  
  foreach($category_array as $cat) {
   $category_final_array[$cat['photo_category']]['category_id'] = get_itg_destination_id('migrate_map_itgcategory', $cat['category_id']);
    $category_final_array[$cat['photo_category']]['section_id'] = get_itg_destination_id('migrate_map_itgsection', $cat['section_id']);
    $category_final_array[$cat['photo_category']]['photo_category'] = get_itg_destination_id('migrate_map_itgphoto', $cat['photo_category']);
  }
  $final_array = $mannual_array + $category_final_array;
  return $final_array;
}


function check_updated_node_photo($nid, $xml_id, $xml_file_name) {
  $query = db_select('story_fields_update_script_check_photo', 'sfuus');
  $query->fields('sfuus', array('id'));
  $query->condition('nid', $nid, '=');
  $query->condition('xml_id', $xml_id, '=');
  $query->condition('image_update', 'photo_conclave', '=');
  $result = $query->execute()->fetchField();

  return $result;
}


function node_update_insert_status_update_photo_update($nid = NULL, $xml_id, $file_name) {
  db_insert('story_fields_update_script_check_video')
      ->fields(array(
        'xml_id' => $xml_id,
        'nid' => $nid,
        'xml_name' => $file_name,
        'image_update' => 'photo_conclave',
      ))
      ->execute();
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

/**
 * Ordering save in widget order table
 */
function ordering_set_of_content_cat_map($node, $count) {
  $nid = $node->nid;
  if (isset($node->field_story_category['und'])) {
    $cat_id = $node->field_story_category['und'];
      foreach ($cat_id as $category) {
        $exist_cat_id = '';
        $exist_cat_id = check_ordering_cat_id($nid, $category['tid']);
        if (empty($exist_cat_id)) {
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
?>
