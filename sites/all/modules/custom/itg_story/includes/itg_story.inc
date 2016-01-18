<?php

/*
 * Inc file contains the functions
 */

/**
 * Reporter details callback
 */
function _itg_story_reporter_details(){  
  $reporter = substr($_GET['reporter_id'], 0, -1);
  $reporter_array = explode(" (", $reporter);
  $content = '';
  
  if(is_numeric($reporter_array[1])){
    $node = node_load($reporter_array[1]);
    $email = $node->field_reporter_email_id[LANGUAGE_NONE][0]['value'];
    $twitter = $node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value'];
    $content = '<div>'.$email.'</div><div>'.$twitter.'</div>';
  }
  echo $content;
}