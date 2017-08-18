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
