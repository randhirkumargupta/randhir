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
        echo '<div id="idIssue">' . t("Issue dose not exist.") . '</div>';
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
