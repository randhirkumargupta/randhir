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
 * callback for all the workbench story of title
 * @param $title
 */
function itg_story_get_workbench_title($title) {
  global $user;
    if (strlen(trim($title)) > 0) {
        $current_time = date("Y-m-d H:i:s");
        $content_type = arg(1);
        $state = trim(arg(2));
        
        $state_array = array('mydraft-story' => 'draft', 'in-queue-story' => 'needs_review', 'my-queue-story' => 'needs_review', 'my-rejected-story' => 'rejected', 'my-unpublished-story' => 'draft', 'unpublished-story' => 'draft', 'archive-story' => 'published');
        $options = '';
        $title = strtolower(trim($title));
        $query = db_select('node', 'n');
        if ($state =='my-published-story' || $state =='published-story') {
          $query->condition('n.status', 1, '=');
        } else if ($state !='expired-story' && $state !='my-expired-story') {
           $query->Join('workbench_moderation_node_history', 'wm', 'n.nid = wm.nid');
           $query->condition('wm.state', $state_array[$state]);
           if ($state =='my-unpublished-story' || $state == 'published-story') {
            $query->condition('wm.from_state', 'published');
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
  $field_collection_item->save();
  node_save($node);

  $response = array('story_nid' => $node->nid);
  print json_encode($response);
}