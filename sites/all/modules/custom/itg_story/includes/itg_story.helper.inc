<?php

/*
 * Inc file contains the helper functions
 */
/**
 * Get breakingnews  id
 * @param int $breaking_id
 * @return int $itg_result
 */
function get_breaking_id($breaking_id) {  
  $query = db_select('field_data_field_source', 'fs');
  $query->fields('fs', array('entity_id'));  
  $query->condition('fs.bundle', 'breaking_news');
  $query->condition('fs.field_source_value', $breaking_id);
  $itg_result = $query->execute()->fetchField();
  
  return $itg_result;
}

/**
 * Implements function for issue exit or not
 * @param string $issue_date
 * @return bool
 */
function itg_story_checked_issue($issue_date) {
  $result = db_select('node', 'node')
    ->fields('node', array('title'))
    ->condition('title', $issue_date, '=')
    ->condition('type', 'issue', '=')
    ->execute()->fetchAssoc();

  if (empty($result['title'])) {
    return FALSE;
  }

  return TRUE;
}


/**
 * Callback for migatred content count
 * 
 */
function itg_get_migrated_like_count($nid) {
  if (!empty($nid)) {
    $query = db_select('itg_custom_flag_count', 'mg');
    $query->fields('mg');
    $query->condition('mg.nid', $nid);
    $query->orderBy('mg.created', 'DESC'); //ORDER BY created
    $result = $query->execute();
    return $record = $result->fetchAll(PDO::FETCH_ASSOC);
  }
}

/**
 * Getting follow story for story pages for akamai purposes
 */
function itg_story_load_follow_story() {
  global $user;
  //if ($user->uid > 0) {
    if (isset($_POST['id']) && !empty($_POST['id'])) {
      $nid = base64_decode($_POST['id']);
      if (isset($nid) && !empty($nid)) {
        $node = node_load($nid);
      }
      if ($node->type == 'story') {
        print theme('itg_story_load_follow_story', array('data' => array('node' => $node)));
        drupal_exit();
      }
    }
  //}
}

/**
 * Implement global_comment_last_record
 */
function itg_story_global_comment_last_record() {
  $query = db_select('itg_global_comment_config', 'ir')
      ->fields('ir', array('config_name', 'created'))
      ->orderBy('id', 'DESC')//ORDER BY created
      ->range(0, 1);
  $result = $query->execute()->fetchAll();
  return $result;
}

/**
 * function for story assign to widget
 * @param int $nid
 * @param array $story_widget
 * @param int $cat_id
 */
function itg_story_assign_to_widget($nid, array $story_widget, $category_tid, $previous_story_assign) {
  if (!empty($story_widget) && count($story_widget)) {
    $result = array();
    foreach ($story_widget as $widget_name) {
      if (!empty($widget_name) && $widget_name != '_none') {
        $result[$widget_name] = $widget_name;
        $is_node_in_widget = itg_widget_check_node_in_widget($nid, $widget_name);
        if (!$is_node_in_widget) {
          if ($widget_name == 'big_story_format_widget') {
            $extra = '[]';
              db_delete('itg_widget_order')
                ->condition('widget' , $widget_name)
                ->condition('extra' , '[]')
                ->execute();
              $node_load_data = itg_widget_get_required_node_data_for_widget($node);
              $query = db_insert('itg_widget_order')
                ->fields(array(
                  'nid' => $nid ,
                  'widget' => $widget_name ,
                  'content_type' => $node_load_data->type,
                  'cat_id' => 0 ,
                  'weight' => 0 ,
                  'extra' => $extra ,
                ))
                ->execute();

          }
          else {
            itg_widget_insert_widget_data($nid, $widget_name, 0);
            itg_widget_delete_old_data_by_limit($widget_name);
          }
        }
      }
    }

    foreach ($previous_story_assign as $row) {
      $widget_value = $row['value'];
      if ($widget_value != $result[$row['value']]) {
        //itg_watchdog('widget_value_inner', $widget_value);
        if (!empty($widget_value)) {
          itg_widget_delete_data_from_widget($widget_value, $nid);
        }
      }
    }
  }
}

/**
 * 
 * @global object $user
 * @param integer $fid
 * @return integer fid
 */
function itg_story_save_original_sample_image($fid) {
  global $user;
  $content_type = 'story';
  $filedir = ITG_IMAGE_FOLDER . $content_type . '/' . date('Ym');
  if (!file_exists(file_default_scheme() . '://' . $filedir)) {
    mkdir(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  }
  chmod(file_default_scheme() . '://' . $filedir, 0777, TRUE);
  $file_image = file_load($fid);
  $file_url_orignal = file_create_url($file_image->uri);
  $image = image_load($file_image->uri);
  if (!empty($image)) {
    $image_exten = end(explode('.', $file_image->uri));
    $filepath = file_default_scheme() . '://' . $filedir;
    $image_width = EXTRA_LARGE_IMAGE_WIDTH;
    $image_height = EXTRA_LARGE_IMAGE_HEIGHT;
    if ($image->info['width'] < $image_width || $image->info['height'] < $image_height) {
      $scaled = image_scale($image, $image_width, $image_height, true);
    }
    else {
      $scaled = image_scale_and_crop($image, $image_width, $image_height);
    }
    $image_name_orignal = $file_image->filename;
    $image_name_orignal = substr($image_name_orignal, 0, (strrpos($image_name_orignal, ".")));
    $image_name = $image_name_orignal . '-' . $image_width . 'x' . $image_height;
    $image_name = preg_replace("/[^A-Za-z0-9\_\-\.]/", '_', $image_name);
    $sav = image_save($image, $filepath . '/' . $image_name . '.' . $image_exten);
    $uri = $filepath . '/' . $image_name . '.' . $image_exten;
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
    file_usage_add($file, 'file', 'field_collection_item', 1);
    if ($file->fid) {
      db_insert('itg_all_orignal_image')->fields(array(
        'fid' => $file->fid,
        'orignal_fid' => $fid,
        'url' => $file_url_orignal
      ))->execute();
    }
    return $file->fid;
  }
}

 /** 
 * Function return tech photogallery html
 * @param Array $tech_photo_arr
 * @return string
 */
function itg_story_photogallery_plugin_data($tech_gallery_images, $tech_gallery_alias, $view_mode = null) {
  $count = 0;
  if ($view_mode == 'amp') {
    $count = -1;
  }
  $output = '';
  $output .= '<div class="tech-photos">';
  $output .= '<div class="tech-photos-head-section"><h3 class="tech-photo-head">Photos</h3>';
  $output .= '<span class="tech-photos-count">' . count($tech_gallery_images) . ' Photos</span></div>';
  foreach ($tech_gallery_images as $num => $val) {
    if ($count == 3) {
      break;
    }
    $photo_img_alt = '';
    $photo_img_title = '';
    if ($view_mode == 'amp') {
      $gallery_entity = entity_load('field_collection_item', array($val['value']));
      $photo_img_path = $gallery_entity[$val['value']]->field_images[LANGUAGE_NONE][0]['uri'];
      $photo_img = image_style_url('video_landing_page_170_x_127', $photo_img_path);
      $photo_img_alt = $gallery_entity[$val['value']]->field_images[LANGUAGE_NONE][0]['alt'];
      $photo_img_title = $gallery_entity[$val['value']]->field_images[LANGUAGE_NONE][0]['title'];
    }
    else {
      $gallery_entity = entity_load('field_collection_item', array($val->field_gallery_image_value));
      $photo_img_path = $gallery_entity[$val->field_gallery_image_value]->field_images[LANGUAGE_NONE][0]['uri'];
      $photo_img = image_style_url('video_landing_page_170_x_127', $photo_img_path);
      $photo_img_alt = $gallery_entity[$val->field_gallery_image_value]->field_images[LANGUAGE_NONE][0]['alt'];
      $photo_img_title = $gallery_entity[$val->field_gallery_image_value]->field_images[LANGUAGE_NONE][0]['title'];
    }
    $output .= '<div class="tech-photo-item">';
    $output .= '<a href="/' . $tech_gallery_alias . '" target="_blank">';
    if ($view_mode == 'amp') {
      $output .= '<amp-img height="127" width="135" src="' . $photo_img . '"  alt="' . $photo_img_alt . '" title="' . $photo_img_title . '"></amp-img>';
    }
    else {
      $output .= '<img src="' . $photo_img . '"  alt="' . $photo_img_alt . '" title="' . $photo_img_title . '"/>';
    }
    $output .= '</a>';
    if ($count == 2) {
      $output .= '<div class="tech-photo-overlay">';
      $output .= '<a href="/' . $tech_gallery_alias . '" target="_blank" title="More"><span class="tech-photo-seemore"> +SEE MORE</span> </a>';
      $output .= '</div>';
    }
    $output .= '</div>';
    $count++;
  }
  $output .= '</div>';
  return $output;
}

/**
 * 
 * @param type $node_id
 * @return string
 */
function itg_story_photo_story_bottom_html($node) {
  $current_url = $_SERVER['REQUEST_URI'];
  // generate the html for photo story bottom slider
  if (!empty($node->nid)) {
    $photo_story = $node->field_photo_story[LANGUAGE_NONE];
    $count = sizeof($photo_story);
    $html = '';
    $html .= '<div class="photo-story-img multiple-photo common-photo">';

    for ($i = 0; $i < $count; $i++) {
      $entity_obj = entity_load('field_collection_item', array($photo_story[$i]['value']));
      $photo_story_img_path = $entity_obj[$photo_story[$i]['value']]->field_photo_story_image['und'][0]['uri'];
      $photo_story_file_name = $entity_obj[$photo_story[$i]['value']]->field_photo_story_image['und'][0]['filename'];
      $photo_story_img = image_style_url('photo_story_small_88x66', $photo_story_img_path);
      $html .= '<div class="photo-slider">';
      $html .= '<span class="img-wrapper"><img src="' . $photo_story_img . '" title="' . $photo_story_file_name . '" alt="photo_story" />';
      $html .= '<em class="photo-count">' . ($i + 1) . '</em></span>';
      $html .= '</div>';
    }
    $html .= '</div>';
    return $html;
  }
}

/**
 * 
 * @param type $node_id
 * @return string
 */
function itg_story_photo_amp_html($node) {
  // generate the html for photo story top slider
  if (!empty($node->nid)) {
    $photo_story = $node->field_photo_story[LANGUAGE_NONE];
    $next = itg_story_photo_story_redirect($node_id, 'next');
    $previous = itg_story_photo_story_redirect($node_id, 'prev');
    $next_link_count = count($photo_story) - 1;
    $html = '';
    $html .='<amp-carousel id="carousel-with-preview"
    width="400"
    height="300"
    layout="responsive"
    type="slides">';
    $i = 1;
    foreach ($photo_story as $key => $val) {

      $entity_obj = entity_load('field_collection_item', array($val['value']));
      $photo_story_img_path = $entity_obj[$val['value']]->field_photo_story_image['und'][0]['uri'];
      $photo_story_img = image_style_url('photo_story_771x432', $photo_story_img_path);
      $photo_story_desc = $entity_obj[$val['value']]->field_photo_story_description['und'][0]['value'];
      $photo_story_img_title = $entity_obj[$val['value']]->field_photo_story_image['und'][0]['title'];
      $photo_story_img_alt = $entity_obj[$val['value']]->field_photo_story_image['und'][0]['alt'];
      if (function_exists('itg_story_get_image_info')) {
        $getImageInfo = itg_story_get_image_info($entity_obj[$val['value']]->field_photo_story_image['und'][0]['fid']);
      }
      $photo_story_src_set = '';
      if (!empty($photo_story_img_path)) {
        $photo_image_uri = file_create_url($photo_story_img_path);
        $photo_image_data = getimagesize($photo_image_uri);
        $photo_story_src_set = $photo_image_uri . ' ' . $photo_image_data[0] . 'w';
      }
      $html .='<div class="slide"><div class="photo-slide"><amp-img src="' . $photo_story_img . '?image=' . $i . '"
      width="771"
      height="432"
      layout="responsive"
      alt="' . $photo_story_img_alt . '" title="' . $photo_story_img_title . '" srcset="'.$photo_story_src_set.'"><div fallback>offline</div></amp-img><div class="caption">' . $getImageInfo[0]->image_photo_grapher . '</div></div>
      <div class="image-alt">' . $getImageInfo[0]->image_caption . '</div><span>' . $photo_story_desc . '</span></div>';
      $i++;
    }
    $html .= '</amp-carousel>';
    return $html;
  }
}

/**
 * 
 * @param type $node_id
 * @return string
 */
function itg_story_photo_amp_bottom_html($node) {
  // generate the html for photo story top slider
  if (!empty($node->nid)) {
    $photo_story = $node->field_photo_story[LANGUAGE_NONE];
    $count = sizeof($photo_story);
    $html = '';
    //$html = '<div class="photo-story-img multiple-photo common-photo">';
    $html .= '<div class="carousel-preview">';
    $index = 0;
    $slide = 1;
    for ($i = 0; $i < $count; $i++) {
      $entity_obj = entity_load('field_collection_item', array($photo_story[$i]['value']));
      $photo_story_img_path = $entity_obj[$photo_story[$i]['value']]->field_photo_story_image['und'][0]['uri'];
      $photo_story_file_name = $entity_obj[$photo_story[$i]['value']]->field_photo_story_image['und'][0]['filename'];
      $photo_story_img_title = $entity_obj[$photo_story[$i]['value']]->field_photo_story_image['und'][0]['title'];
      $photo_story_img = image_style_url('photo_story_small_88x66', $photo_story_img_path);
      $photo_story_src_set = '';
      if (!empty($photo_story_img_path)) {
        $photo_image_uri = file_create_url($photo_story_img_path);
        $photo_image_data = 88;
        $photo_story_src_set = ', ' . $photo_image_uri . ' ' . $photo_image_data . 'w';
      }
      $html .= '<button on="tap:carousel-with-preview.goToSlide(index=' . $index . ')">
      <amp-img src="' . $photo_story_img . '?image=' . $slide . '"
        width="88"
        height="66"
       alt="' . $photo_story_img_title . '" srcset="'.$photo_story_src_set.'"><div fallback>offline</div></amp-img><span class="counter">' . $slide . '</span>
    </button>';
      $index++;
      $slide++;
    }
    $html .= '</div>';
    return $html;
  }
}

/**
 * 
 * @param type $node_id
 * @return string
 */
function itg_story_photo_story_html($node, $primary_cat = NULL) {
  // generate the html for photo story top slider
  if (!empty($node->nid)) {
    $photo_story = $node->field_photo_story[LANGUAGE_NONE];
    $next = itg_story_photo_story_redirect($node->nid, 'next', $primary_cat);
    $previous = itg_story_photo_story_redirect($node->nid, 'prev', $primary_cat);
    $next_link_count = count($photo_story) - 1;
    $html = '';
    $html .= '<div class="photo-story-img multiple-photo-disc">';
    foreach ($photo_story as $key => $val) {
      if ($key == 0 && !empty($previous)) {
        $previous_link = "<a rel='prev' class='fa fa-chevron-left prev-story-link' href='" . $previous . "'></a>";
      }
      else {
        $previous_link = "";
      }
      if ($key == $next_link_count && !empty($next)) {
        $next_link = "<a rel='next'class='fa fa-chevron-right next-story-link' href='" . $next . "'></a>";
      }
      else {
        $next_link = "";
      }

      $entity_obj = entity_load('field_collection_item', array($val['value']));
      $photo_story_img_path = $entity_obj[$val['value']]->field_photo_story_image['und'][0]['uri'];

      $photo_story_img = image_style_url('photo_story_771x432', $photo_story_img_path);
      $photo_story_desc = $entity_obj[$val['value']]->field_photo_story_description['und'][0]['value'];
      $photo_story_img_title = $entity_obj[$val['value']]->field_photo_story_image['und'][0]['title'];
      $photo_story_img_alt = $entity_obj[$val['value']]->field_photo_story_image['und'][0]['alt'];
      if (function_exists('itg_story_get_image_info')) {
        $getImageInfo = itg_story_get_image_info($entity_obj[$val['value']]->field_photo_story_image['und'][0]['fid']);
      }
      $html .= '<div class="photo-slider">';
      $html .= $next_link . '<div class="image-caption"><img src="' . $photo_story_img . '" title="' . $photo_story_img_title . '" alt="' . $photo_story_img_alt . '" /><span class="photo-caption">' . $getImageInfo[0]->image_photo_grapher . '</span></div>' . $previous_link;
      $html .= '<div class="photo-description">' . $getImageInfo[0]->image_caption . '</div><div class="description"><p>' . $photo_story_desc . '</p></div>';
      $html .= '</div>';
    }
    $html .= '</div>';
    return $html;
  }
}

/**
 * Implements itg_story_photo_story_previous()
 * @param type $node_id
 */
function itg_story_photo_story_redirect($node_id, $type = 'prev', $cat_id) {
  if (!empty($node_id)) {
    global $base_url;
    $current_time = date("Y-m-d H:i:s");
    $query = db_select('field_data_field_story_type', 'fst');
    $query->leftJoin('node', 'n', 'n.nid=fst.entity_id');
    $query->leftJoin('field_data_field_story_expiry_date', 'expiry', 'fst.entity_id = expiry.entity_id');
    $query->leftJoin('field_data_field_story_expires', 'expiry_status', 'n.nid = expiry_status.entity_id');
    $query->leftJoin('field_data_field_primary_category', 'pr', 'pr.entity_id = fst.entity_id');
    $query->fields('fst', array('entity_id'));
    $query->condition('fst.field_story_type_value', 'photo_story');
    if ($type == 'next') {
      $query->condition('fst.entity_id', $node_id, '>');
      $query->condition('pr.field_primary_category_value', $cat_id);
      $query->orderBy('fst.entity_id', 'ASC');
    }
    else {
      $query->condition('fst.entity_id', $node_id, '<');
      $query->condition('pr.field_primary_category_value', $cat_id);
      $query->orderBy('fst.entity_id', 'DESC');
    }

    $query->range(0, 1);
    $query->condition('n.status', 1);
    $query->condition('n.type', array('story'), 'IN');
    $or = db_or()->isNull('expiry.field_story_expiry_date_value')->condition('expiry.field_story_expiry_date_value', $current_time, '>=');
    $query->condition($or);
    $result = $query->execute()->fetchAll();

    if ($result[0]->entity_id) {
      $required_node_id = 'node/' . $result[0]->entity_id;
      $href = $base_url . '/' . $required_node_id;
    }
    else {
      $href = '';
    }
    return $href;
  }
}

/**
 * Implements itg_story_movie_image_plugin_data()
 * @param type $node_id
 */
function itg_story_movie_image_plugin_data($node_obj, $source = NULL) {
  //Store the node id of the story from the argument
  
  if (!empty($node_obj->nid)) {
    $dty = date("D j M Y", $node_obj->changed);
    //store entity id of multi value field collection field
    if (isset($node_obj->field_story_technology[LANGUAGE_NONE])) {
      $technology_entity = $node_obj->field_story_technology[LANGUAGE_NONE];
    }

    $html = '';
    if (!empty($technology_entity)) {
      $html .= '<div class="story-photo-list-wrapper"><h3 class="story-photo-list-heading"><span>SAMPLE PHOTOS</span></h3><div class="story-photo-list">';

      foreach ($technology_entity as $key => $val) {
        $entity = entity_load('field_collection_item', array($val['value']));
        // store the actual image path
        $sample_img_path = $entity[$val['value']]->field_technology_sample_photo['und'][0]['uri'];
        $sample_img = image_style_url('video_landing_page_170_x_127', $sample_img_path);
        $ori_img_fid = $entity[$val['value']]->field_technology_sample_photo['und'][0]['fid'];
        $href_sample_img = itg_story_sample_image_path($ori_img_fid);
        // store image title
        $sample_title = mb_strimwidth($entity[$val['value']]->field_technology_photo_title['und'][0]['value'], 0, 35, "..");
        // generate html 
        $html .= '<div class="story-photo-list-item">';
        if ($source == 'amp') {
          $html .='<amp-img height="127" width="170" alt="sample photo" src="' . $sample_img . '"></amp-img>';
        }
        else {
          $html .= '<a rel="prettyPhoto[gallery2]" href="'.$href_sample_img.'"><img src="' . $sample_img . '"  alt="" title=""/></a>';
        }
        $html .= '<span class="smp-date">' . $dty . '</span>';
        $html .= '<p>' . $sample_title . '</p>';
        $html .= '</div>';
      }
      $html .= '</div></div>';
    }
    return $html;
  }
  else {
    return t('No content id found');
  }
}

/**
 * Implements itg_get_emoji_amp_html().
 */
function itg_get_emoji_amp_html($result, $arr = NULL) {
  if (!empty($result)) {
    $emoji_html = '<span class="smilies-title">';
    if (empty($arr)) {
      foreach ($result as $key => $value) {
        $html = $value;
        $html = str_ireplace(
            ['<img', '<video', '/video>', '<audio', '/audio>'], ['<amp-img', '<amp-video', '/amp-video>', '<amp-audio', '/amp-audio>'], $html
        );
        $emoji_html .= preg_replace('/<amp-img(.*?)\/?>/', '<amp-img$1></amp-img>', $html);
      }
    }
    else {
      $html = $result;
      $html = str_ireplace(
          ['<img', '<video', '/video>', '<audio', '/audio>'], ['<amp-img', '<amp-video', '/amp-video>', '<amp-audio', '/amp-audio>'], $html
      );
      $emoji_html .= preg_replace('/<amp-img(.*?)\/?>/', '<amp-img$1></amp-img>', $html);
    }
    $emoji_html .= '</span>';
    return $emoji_html;
  }
}

/**
 * Function for check external url in story
 * @return false or external url
 */
function _is_external_url_story_article($nid) {
  $is_external_url = FALSE;
  if (isset($nid)) {
    $query = db_select('field_data_field_story_external_url', 'eu');
    $query->fields('eu', array('field_story_external_url_value'));
    $query->isNotNull('eu.field_story_external_url_value');
    $query->condition('eu.entity_id', $nid, '=');
    $query->condition('eu.bundle', 'story', '=');
    $query->condition('eu.entity_type', 'node', '=');
    $query_result = $query->execute()->fetchAll();
    if (!empty($query_result) && !empty($query_result[0]->field_story_external_url_value) && filter_var(trim($query_result[0]->field_story_external_url_value), FILTER_VALIDATE_URL)) {
      $is_external_url = trim($query_result[0]->field_story_external_url_value);
    }
  }
  return $is_external_url;
}
