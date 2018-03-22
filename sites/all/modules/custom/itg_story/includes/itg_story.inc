<?php

/**
 * @file
 * Inc file contains the functions
 */

/**
 * Reporter details callback
 */
function itg_story_reporter_details() {
    $reporter = substr($_POST['reporter_id'], 0, -1);
    $reporter_array = explode(" (", $reporter);
    $content = '';

    if (is_numeric($reporter_array[1])) {
        $node = node_load($reporter_array[1]);
        $email = $node->field_reporter_email_id[LANGUAGE_NONE][0]['value'];
        $twitter = $node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value'];
        $content = '<div>' . t("Byline’s  Email id: ") . $email . '</div><div>' . t("Byline’s Twitter Handle: ") . $twitter . '</div>';
    }

    echo $content;
}

/**
 * Reporter details callback
 */
function itg_story_issue_date_checked() {
    $date = $_GET['issue'];
    $date = strtotime($date);
    $issue_date = date('Y-m-d H:i:s', $date);
    $issue = itg_story_checked_issue($issue_date);

    if (!$issue) {
        echo '<div id="idIssue">' . t("Issue Does not exist.") . '</div>';
    }
}

/**
 * callback for all the story of title
 * @param $title
 */
function itg_story_get_content_title($title) {

    if (strlen(trim($title)) > 0) {
        $content_type = arg(1);
        $options = '';
        $title = strtolower(trim($title));
        $query = db_select('node', 'n');
        $query->fields('n', array('title'));
        $query->condition('title', '%' . $title . '%', 'LIKE');
        $query->condition('n.type', $content_type, '=');
        $query->condition('n.status', 1);
        $query->range(0, 20);

        $result = $query->execute();

        while ($record = $result->fetchAssoc()) {
            $options[$record['title']] = $record['title'];
        }

        drupal_json_output($options);
    }
}



/**
 * callback for all the story of title
 * @param $title
 */
function itg_state_get_content_title($title) {
    global $user;
    if (strlen(trim($title)) > 0) {
        $content_type = arg(1);
        $state = arg(2);
        $cur_date = date('Y-m-d H:i:s');
        $options = '';
        $title = strtolower(trim($title));
        $query = db_select('node', 'n');
        $query->fields('n', array('title'));
        
        if ($content_type == 'survey') {
          if ($state == 'unpublished') {
            $query->leftJoin('field_data_field_supp_publish', 'sp', 'sp.entity_id = n.nid');
            $query->leftjoin('field_data_field_survey_end_date' , 'ed' , 'n.nid = ed.entity_id');
            //$query->condition('sp.field_supp_publish_value', 1, '=');
            //$query->condition('n.status', 0);
            $query->condition('ed.field_survey_end_date_value', $cur_date , '<');
            //$query->condition(db_or()->isNull('ed.field_survey_end_date_value')->condition('ed.field_survey_end_date_value' , $cur_date , '=<'));
          } else if ($state == 'published') {
            $query->leftJoin('field_data_field_supp_publish', 'sp', 'sp.entity_id = n.nid');
            $query->leftjoin('field_data_field_survey_end_date' , 'ed' , 'n.nid = ed.entity_id');
            $query->condition('sp.field_supp_publish_value', 1, '=');
            $query->condition('n.status', 1);
            $query->condition(db_or()->isNull('ed.field_survey_end_date_value')->condition('ed.field_survey_end_date_value' , $cur_date , '>='));
          } else if ($state == 'draft') {
            $query->leftJoin('field_data_field_supp_publish', 'sp', 'sp.entity_id = n.nid');
            $query->leftjoin('field_data_field_survey_end_date' , 'ed' , 'n.nid = ed.entity_id');
            $query->isNull('sp.field_supp_publish_value');
            $query->condition('n.status', 0);          
            $query->condition(db_or()->isNull('ed.field_survey_end_date_value')->condition('ed.field_survey_end_date_value' , $cur_date , '>='));
            $query->condition('n.uid', $user->uid);
          }
        } else if ($content_type == 'quiz') {
            if ($state == 'unpublished') {
              $query->leftJoin('field_data_field_quuiz_publish', 'sp', 'sp.entity_id = n.nid');
              $query->leftjoin('field_data_field_survey_end_date' , 'ed' , 'n.nid = ed.entity_id');            
              $query->condition('ed.field_survey_end_date_value', $cur_date , '<');            
            } else if ($state == 'published') {
              $query->leftJoin('field_data_field_quuiz_publish', 'sp', 'sp.entity_id = n.nid');
              $query->leftjoin('field_data_field_survey_end_date' , 'ed' , 'n.nid = ed.entity_id');
              $query->condition('sp.field_quuiz_publish_value', 1, '=');
              $query->condition('n.status', 1);
              $query->condition(db_or()->isNull('ed.field_survey_end_date_value')->condition('ed.field_survey_end_date_value' , $cur_date , '>='));
            } else if ($state == 'draft') {
              $query->leftJoin('field_data_field_quuiz_publish', 'sp', 'sp.entity_id = n.nid');
              $query->leftjoin('field_data_field_survey_end_date' , 'ed' , 'n.nid = ed.entity_id');
              $query->isNull('sp.field_quuiz_publish_value');
              $query->condition('n.status', 0);          
              $query->condition(db_or()->isNull('ed.field_survey_end_date_value')->condition('ed.field_survey_end_date_value' , $cur_date , '>='));
              $query->condition('n.uid', $user->uid);
            }
        } else if ($content_type == 'poll') {
            if ($state == 'unpublished') {
              $query->leftJoin('field_data_field_poll_itg_state', 'sp', 'sp.entity_id = n.nid');
              $query->condition('sp.field_poll_itg_state_value', 1); 
              $query->condition('n.status', 0);           
            } else if ($state == 'published') {              
                $query->condition('n.status', 1);                
            } else if ($state == 'draft') {
                $query->leftJoin('field_data_field_poll_itg_state', 'sp', 'sp.entity_id = n.nid');
                $query->condition('sp.field_poll_itg_state_value', 0); 
                $query->condition('n.status', 0);
                $query->condition('n.uid', $user->uid);
            }
        }
        
        $query->condition('title', '%' . $title . '%', 'LIKE');
        $query->condition('n.type', $content_type, '=');
        
        $query->range(0, 20);

        $result = $query->execute();

        while ($record = $result->fetchAssoc()) {
            $options[$record['title']] = $record['title'];
        }

        drupal_json_output($options);
    }
}

/**
 * callback for all the workbench story of title
 * @param $title
 */
function itg_story_get_workbench_title($title) {
  global $user;
    if (strlen(trim($title)) > 0) {
        $current_time = date("Y-m-d H:i:s");
        $content_type = arg(1);
        $state = trim(arg(2));
        
        $state_array = array('mydraft-story' => 'draft', 'in-queue-story' => 'needs_review', 'my-queue-story' => 'needs_review', 'my-rejected-story' => 'rejected', 'my-unpublished-story' => 'draft', 'unpublished-story' => 'draft', 'archive-story' => 'draft');
        $options = '';
        $title = strtolower(trim($title));
        $query = db_select('node', 'n');
        $query->Join('field_data_field_story_source_type', 'sourcetype', 'sourcetype.entity_id = n.nid');
        if ($state =='my-published-story' || $state =='published-story') {
          $query->condition('n.status', 1, '=');
        } else if ($state !='expired-story' && $state !='my-expired-story') {
            $query->Join('workbench_moderation_node_history', 'wm', 'n.nid = wm.nid');
            $or = db_or();
            $or->condition('wm.state', $state_array[$state]);
            $or->condition('sourcetype.field_story_source_type_value', 'migrated');
            $query->condition($or);
           if ($state =='my-unpublished-story' || $state == 'published-story') {
            $un_or = db_or();
            $un_or->condition('wm.from_state', 'published');
            $un_or->condition('sourcetype.field_story_source_type_value', 'migrated');
            $query->condition($un_or);
           }
           $query->condition('wm.is_current', 1); 
           $query->condition('n.status', 0);
        }
        $query->leftJoin('field_data_field_story_expiry_date', 'expiry', 'n.nid = expiry.entity_id');
        $query->leftJoin('field_data_field_story_archive', 'archive', 'n.nid = archive.entity_id');
        $query->fields('n', array('title'));
        $query->condition('n.title', '%' . $title . '%', 'LIKE');
        $query->condition('n.type', $content_type, '=');        
        
        if ($state == 'mydraft-story' || $state == 'my-queue-story' || $state =='my-published-story' || $state =='my-expired-story' || $state == 'my-unpublished-story' || $state == 'my-rejected-story') {
          $query->condition('n.uid', $user->uid);
        }
        
        if ($state =='expired-story' || $state =='my-expired-story' || $state =='expired-video') {
          $query->condition('expiry.field_story_expiry_date_value', $current_time, '<');        
        } else {
          $query->condition(db_or()->isNull('expiry.field_story_expiry_date_value')->condition('expiry.field_story_expiry_date_value', $current_time, '>='));
        }
        
        
        if ($state == 'archive-story') {
         $query->condition('archive.field_story_archive_value', 'Yes'); 
        } else {
         $query->isNull('archive.field_story_archive_value');
        }
        
        $query->range(0, 20);

        $result = $query->execute();

        while ($record = $result->fetchAssoc()) {
            $options[$record['title']] = $record['title'];
        }

        drupal_json_output($options);
    }
}

/**
 * Callback for all the story of nid
 * @param $nid
 */
function itg_story_get_content_nid($nid) {
    if (strlen(trim($nid)) > 0) {
        $content_type = arg(1);
        $options = '';
        $nid = strtolower(trim($nid));
        $query = db_select('node', 'n');
        $query->fields('n', array('nid'));
        $query->condition('nid', '%' . $nid . '%', 'LIKE');
        $query->condition('n.type', $content_type, '=');
        $query->range(0, 20);

        $result = $query->execute();

        while ($record = $result->fetchAssoc()) {
            $options[$record['nid']] = $record['nid'];
        }

        drupal_json_output($options);
    }
}

/**
 * Callback for associate_photo_video_content
 * 
 */
function associate_photo_video_content() {
    if (arg(1) == 'video') {

        if (function_exists('itg_widget_dailymotion_get_videogallery_slider')) {
            print '<div class="big-story-popup"><span id="close-big-story"><a href="javascript:void(0)">X</a></span>';
            print $videoids = itg_widget_dailymotion_get_videogallery_slider(arg(2), 'video');
            print '</div>';
        }
    } else if (arg(1) == 'gallery') {
        print '<div class="big-story-popup"><span id="close-big-story"><a href="javascript:void(0)">X</a></span>';
        print views_embed_view('photo_landing_slider', 'block_1', arg(2));
        print '</div>';
    }
}


/**
 * Implements itg_story_byline().
 * @param string $title
 */
function itg_story_byline($title) {
  $options = '';
  $title = strtolower(trim($title));
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_reporter_email_id', 're', 'n.nid = re.entity_id');
  $query->leftJoin('field_data_field_reporter_profile_type', 'frq', 'n.nid = frq.entity_id');
  $query->fields('n');
  $query->fields('frq', array('field_reporter_profile_type_value'));
  $query->fields('re', array('field_reporter_email_id_value'));
  $query->condition('n.title', '%' . $title . '%', 'LIKE');
  $query->condition('n.type', 'reporter', '=');
  $query->condition('n.status', 1, '=');
  $query->range(0, 20);
  //field_reporter_profile_type_value
  $result = $query->execute();

  while ($record = $result->fetchAssoc()) {
    if (!empty($record['field_reporter_profile_type_value'])) {
      $reporter_type = '(' . $record['field_reporter_profile_type_value'] . ')';
    }
    if (!empty($record['field_reporter_email_id_value'])) {
      $reporter_email = '(' . $record['field_reporter_email_id_value'] . ')';
    }
    $name_format = $record['title'] . $reporter_type . $reporter_email . '{' . $record['nid'] . '}';
    $options[$name_format] = $name_format;
  }
  drupal_json_output($options);
}

/**
 * Implements itg_story_byline_save().
 */
function itg_story_byline_save() {

  $trigger_event = $_POST['byline_event'];
  
  preg_match_all('/{(.*?)}/', $_POST['nd_id'], $matches);
  if($trigger_event == 'unpublish') {  
    $byline_nid = trim($matches[1][0]);
  } else {
    $byline_nid = $_POST['nd_id'];
  }
  $nid = $_POST['nd_id'];
  $unique_id = $_POST['unique_id'];
  $byline_arr = itg_get_byline_detail($byline_nid);
  $byline_name = $byline_arr[0]['title'];
  $byline_type = $byline_arr[0]['field_reporter_profile_type_value'];
  $previous_byline = itg_get_previous_byline_detail($unique_id, $byline_nid);

  if ($trigger_event == 'unpublish') {
    if (!empty($byline_nid) && empty($previous_byline)) {
      $qry = db_insert('itg_multi_byline_info')
          ->fields(array(
            'byline_id' => $byline_nid,
            'uniqueid' => $unique_id,
            'created' => REQUEST_TIME
          ))
          ->execute();
      $remove = '<a href="javascript:void(0)" data-val="' . $byline_nid . '" data-tag="' . $qry . '" class="remove-byline">' . t('Remove') . '</a>';
      if (!empty($byline_type)) {
        $byline_type = '<span>' . $byline_type . '</span>';
      }
      $byline_res = '<li id="' . $qry . '"><i class="fa fa-arrows" aria-hidden="true"></i><input type="checkbox" name="bylinepublish" data-tag="' . $qry . '" value="' . $byline_nid . '" class="byline_publish"><span>' . t('Publish') . '</span><span>' . $byline_name . '</span>' . $byline_type . '<span>' . $remove . '</span></li>';
      $response = array('msg' => 'success', 'lnk' => $byline_res);
      print json_encode($response);
    }
    else
    {
      $response = array('msg' => 'error', 'description' => 'alreadyexist');
      print json_encode($response);
    }
  }

  if ($trigger_event == 'publish' && !empty($previous_byline)) {

    $status = $_POST['status'];
   
    if (!empty($nid) && !empty($unique_id)) {
      db_update('itg_multi_byline_info')
          ->fields(array(
            'publish_status' => $status,
          ))
          ->condition('id', $_POST['bl_id'], '=')
          ->condition('uniqueid', $unique_id, '=')
          ->execute();
      $response = array('msg' => 'success', 'response' => 'true');
      print json_encode($response);
    }
    else {
      $response = array('msg' => 'error', 'description' => 'alreadyupdate');
      print json_encode($response);
    }
  }

  if ($trigger_event == 'remove' && !empty($nid)) {
    db_delete('itg_multi_byline_info')
        ->condition('id', $nid)
        ->execute();
    $response = array('msg' => 'delete', 'byline' => $nid);
    print json_encode($response);
  }
}


/**
 * Add byline menu page callback
 * @global object $user
 * @param type $ajax
 */
function itg_story_add_byline_popup($ajax) {
  global $user;
  if ($ajax) {
    ctools_include('ajax');
    ctools_include('modal');

    ctools_include('node.pages', 'node', '');
    $node = (object) array(
          'uid' => $user->uid,
          'name' => (isset($user->name) ? $user->name : ''),
          'type' => 'reporter',
          'language' => LANGUAGE_NONE,
    );

    $form_state = array(
      'ajax' => TRUE,
      'title' => t('Add Byline'),
      'reporter_popup_form' => 1,
    );
    $form_state['build_info']['args'] = array($node);
    // Use ctools to generate ajax instructions for the browser to create
    // a form in a modal popup.
    $output = ctools_modal_form_wrapper('reporter_node_form', $form_state);

    // If the form has been submitted, there may be additional instructions
    // such as dismissing the modal popup.
    if (!empty($form_state['executed'])) {
      if (!empty($form_state['values']['field_reporter_profile_type'])) {
        $reporter_type = '(' . $form_state['values']['field_reporter_profile_type']['und'][0]['value'] . ')';
      }
      if (!empty($form_state['values']['field_reporter_email_id'])) {
        $reporter_email = '(' . $form_state['values']['field_reporter_email_id']['und'][0]['value'] . ')';
      }
      $name_format = $form_state['values']['title'] . $reporter_type . $reporter_email . '{' . $form_state['values']['nid'] . '}';
      $output = array();
      $output[] = ctools_modal_command_display(
          t('Node created'), 'Node creation successful.');/** Add success message */
      $output[] = ctools_modal_command_dismiss(); //Close modal automatically
      //$output[] = ctools_ajax_command_reload(); //reload parent window
      $output[] = ajax_command_invoke('#edit-field-story-reporter-und-0-target-id', 'val', array($name_format));
    };
    // Return the ajax instructions to the browser via ajax_render().
    print ajax_render($output);
    drupal_exit();
  }
}

/**
 * Breaking news create after story create.
 */
function itg_story_create_breaking_news() {
  global $user;
  $title = $_POST['title'];
  $publish_time = date('Y-m-d H:i');
  $node = new stdClass();
  $node->title = $title;
  $node->type = "breaking_news";

  node_object_prepare($node); //Invokes hook_prepare() and hook_node_prepare().

  $node->language = LANGUAGE_NONE;
  $node->field_content_type[LANGUAGE_NONE][0]['value'] = 'Story';
  $node->field_type[LANGUAGE_NONE][0]['value'] = 'Breaking News';
  $node->field_breaking_display_on[LANGUAGE_NONE][0]['value'] = 'home';
  $node->uid = $user->uid;
  $node->status = 1; //(1 or 0): Published or not
  $node->promote = 0; //(1 or 0): Promoted to front page
  $node->comment = 0; // 0 = Comments disabled, 1 = read only, 2 = read/write
  $field_collection_item = entity_create('field_collection_item', array('field_name' => 'field_breaking_content_details'));
  $field_collection_item->setHostEntity('node', $node);
  $field_collection_item->field_breaking_tile[LANGUAGE_NONE][0]['value'] = $title;
  $field_collection_item->field_mark_as_breaking_band[LANGUAGE_NONE][0]['value'] = '1';
  $field_collection_item->field_breaking_publish_time[LANGUAGE_NONE][0]['value'] = $publish_time;
  $field_collection_item->save();
  node_save($node);

  $response = array('story_nid' => $node->nid);
  print json_encode($response);
}

/**
 * Function for embeding megareview node in Story.
 * @global type $base_url
 * @param object $node
 */
function itg_story_mega_review_node_embed($node) {
  //$node = node_load($node_id);
  // config for sharing
  global $base_url;
  $nid = $node->nid;
  $actual_link = 'https://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
  $short_url = $actual_link;
  $fb_title = addslashes($node->title);
  $share_desc = '';
  $image = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);

  // get global comment config
  /* if (function_exists('global_comment_last_record')) {      
    $last_record = global_comment_last_record();
    $config_name = trim($last_record[0]->config_name);
    } */

  // get facebook share count 
  if (function_exists('itg_total_share_count')) {
    $tot_count = itg_total_share_count($actual_link);
  }
  if (function_exists('itg_report_get_node_share')) {
    $tot_count = itg_report_get_node_share($nid, $tot_count);
  }
  $cast_name = $node->field_mega_review_cast['und'][0]['entity']->title;
  $director = $node->field_mega_review_director['und'][0]['value'];
  $plot = $node->field_mega_review_movie_plot['und'][0]['value'];
  $display = array('label' => 'hidden');
  $theme_path = drupal_get_path('theme', 'itg');
  $external_review = $internal_review = FALSE;
  $average_ratings = 0;
  $num_of_ratings = 0;
  $node_alias = url(drupal_get_path_alias('node/' . $node->nid), array('absolute' => TRUE));
  foreach ($node->field_mega_review_review[LANGUAGE_NONE] as $field_collection) {
    $reviews = entity_load('field_collection_item', array($field_collection['value']));
    if ($reviews[$field_collection['value']]->field_story_review_type[LANGUAGE_NONE][0]['value'] == 'internal'):
      $internal = render(field_view_field('field_collection_item', $reviews[$field_collection['value']], 'field_story_reporter', $display));
      $internal_rating = $reviews[$field_collection['value']]->field_story_rating[LANGUAGE_NONE][0]['value'] * 20;
      $internal_review .= '<p>' . strip_tags($internal) . '</p>';
      $internal_review .= '<span class="other-reviews-rating" data-star-value="' . $internal_rating . '%"></span>';
    endif;
    if ($reviews[$field_collection['value']]->field_story_review_type[LANGUAGE_NONE][0]['value'] == 'external'):
      $external = render(field_view_field('field_collection_item', $reviews[$field_collection['value']], 'field_story_reporter', $display));
      $external_rating = $reviews[$field_collection['value']]->field_story_rating[LANGUAGE_NONE][0]['value'] * 20;
      $external_review .= '<p>' . strip_tags($external) . '</p>';
      $external_review .= '<span class="other-reviews-rating" data-star-value="' . $external_rating . '%"></span>';
    endif;
    $average_ratings += $reviews[$field_collection['value']]->field_story_rating[LANGUAGE_NONE][0]['value'];
    ++$num_of_ratings;
  }
  $average_rating = (float) $average_ratings / $num_of_ratings;
  $average_rating = round($average_rating, 1);
  $average_rating = itg_common_round_rating($average_rating);
  $average_rating = $average_rating * 20;
  $output = '';
  $output .= '<article class="node node-mega-review-critic view-mode-full clearfix">';
  $output .= '<script>if (typeof(jQuery) == "undefined") {';
  $output .= 'var iframeBody = document.getElementsByTagName("body")[0];';
  $output .= 'var jQuery = function (selector) { return parent.jQuery(selector, iframeBody); };';
  $output .= 'var $ = jQuery;}';
  $output .= '</script>';
  $output .= '<link type="text/css" rel="Stylesheet" href="' . $base_url . '/' . $theme_path . '/css/styles-new.css" />';
  $output .= '<link type="text/css" rel="Stylesheet" href="' . $base_url . '/' . $theme_path . '/css/itgd-style.css" />';
  $output .= '<link type="text/css" rel="Stylesheet" href="' . $base_url . '/' . $theme_path . '/css/font-awesome.css" />';
  $output .= '<link type="text/css" rel="Stylesheet" href="https://fonts.googleapis.com/css?family=Roboto+Slab" />';
  $output .= '<link type="text/css" rel="Stylesheet" href="https://fonts.googleapis.com/css?family=Roboto:300,400,500,700" />';
  $output .= '<script type="text/javascript" src="' . $base_url . '/' . drupal_get_path('module', 'itg_flag') . '/js/itg_flag.js" ></script>';
  $output .= '<div class="embed-mega-review">';
  $output .= '<a href="' . $node_alias . '" target="_blank"><h1>' . $node->title . '</h1></a>';
  $output .= '<div class="movie-description">';
  $output .= render(field_view_field('node', $node, 'field_story_movie_description', $display));
  $output .= '</div>';
  $output .= '<div class="rating-and-social-wrapper"><div class="movie-rating" data-star-value="' . $average_rating . '%"></div><div class="social-info">';
  $output .= '<span class="share-count"><i>';
  if (!empty($tot_count)) {
    $output .= $tot_count;
  }
  else {
    $output .= 0;
  }
  $output .= '</i>SHARES</span>';
  $output .= '<span><a title="share on google+" class="user-activity def-cur-pointer" rel="' . $node->nid . '" data-tag="' . $node->type . '" data-activity="google_share" onclick=\'return googleplusbtn("' . $node_alias . '")\' data-status="1"><i class="fa fa-google-plus"></i></a></span>';
  $output .= '<span><a class="def-cur-pointer" title ="share on facebook" onclick=\'fbpop("' . $actual_link . '", "' . urlencode($fb_title) . '", "' . urlencode($share_desc) . '", "' . $image . '", "' . $base_url . '", "' . $node->nid . '")\'><i class="fa fa-facebook"></i></a></span>';
  
  $output .= '<span><a class="user-activity def-cur-pointer" rel="' . $node->nid . '" data-tag="' . $node->type . '" data-activity="twitter_share" data-status="1" title="share on twitter" onclick=\'twitter_popup("' . urlencode($node->title) . '", "' . urlencode($short_url) . '")\'><i class="fa fa-twitter"></i></a></span>';
  $output .= '<span>';
  /* if ($config_name == 'vukkul') {
    $output .= '<a class= "def-cur-pointer" onclick ="scrollToAnchor("vuukle-emotevuukle_div");" title="comment"><i class="fa fa-comment" aria-hidden="true"></i></a>';
    }
    if ($config_name == 'other') {
    $output .=  '<a class= "def-cur-pointer" onclick ="scrollToAnchor("other-comment");" title="comment"><i class="fa fa-comment" aria-hidden="true"></i></a>';
    } */
  $output .= '</span>';
  $output .= '</div></div>';
  $output .= '<div class="movie-review-wrapper">';
  $output .= '<div class="movie-trailer">' . render(field_view_field('node', $node, 'field_mega_review_youtube_url', $display)) . '</div>';
  $output .= '<div class="movie-review-text">';
  //if (!empty($cast_name)):
  $output .= '<div class="review-row"><dfn class="review-label">' . t('Cast :') . '</dfn><span class="review-txt">' . render(field_view_field('node', $node, 'field_mega_review_cast', $display)) . '</span></div>';
  //endif;
  if (!empty($director)):
    $output .= '<div class="review-row"><dfn class="review-label">' . t('Director :') . '</dfn><span class="review-txt">' . $director . '</span></div>';
  endif;
  if (!empty($plot)):
    $output .= '<div class="review-row"><dfn class="review-label">' . t('Plot :') . '</dfn><span class="review-txt">' . $plot . '</span></div>';
  endif;
  $output .= '<div class="movie-reviewer our-review">';
  $output .= '<h3>OUR REVIEWERS</h3>';
  $output .= $internal_review;
  $output .= '</div>';
  $output .= '<div class="movie-reviewer movie-reviewer-other">';
  $output .= '<h3>OTHER REVIEWERS</h3>';
  $output .= $external_review;
  $output .= '</div>';
  $output .= '</div>';
  $output .= '</div>';
  $output .= '</div>';
  $output .= '</article>';
  print $output;
}

/**
 * Menu callback function for embeding tech gallery.
 * @param int $jsp_gallid
 * @return string
 */
function itg_story_technology_embedgalery($jsp_gallid) {
  $return = '';
  if (!empty($jsp_gallid) && is_numeric($jsp_gallid)) {
    $dest_nid = get_itg_destination_id('migrate_map_itgphotogallery', $jsp_gallid);
    if (!empty($dest_nid) && is_numeric($dest_nid)) {
      $gall_images = itg_commom_get_gallery_image_array_by_gid($dest_nid);
      $tech_gallery_alias = drupal_get_path_alias('node/' . $dest_nid);
      $return = itg_story_photogallery_plugin_data($gall_images, $tech_gallery_alias);
    }
  }
  return $return;
}
