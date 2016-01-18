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

/**
* callback for all the story of title
*  
*/

function _get_story_title_in_autocomplete($title) {
 
    if(strlen(trim($title)) > 0) {
      $title = strtolower(trim($title));
      $query = db_select('node', 'n');
      $query->fields('n', array('title'));
      $query->condition('title', '%'.$title.'%', 'LIKE');
      $query->condition('n.type', 'story', '=');          
      $query->range(0, 20);
      
      $result = $query->execute(); 
      while($record = $result->fetchAssoc()) {     
        $options[$record['title']] = $record['title'];
      }    
      drupal_json_output($options);    
  }
    
 }
 
 /**
* callback for all the story of nid
*  
*/

function _get_story_nid_in_autocomplete($nid) {
 
    if(strlen(trim($nid)) > 0) {
      $nid = strtolower(trim($nid));
      $query = db_select('node', 'n');
      $query->fields('n', array('nid'));
      $query->condition('nid', '%'.$nid.'%', 'LIKE');
      $query->condition('n.type', 'story', '=');          
      $query->range(0, 20);
      
      $result = $query->execute(); 
      while($record = $result->fetchAssoc()) {     
        $options[$record['nid']] = $record['nid'];
      }    
      drupal_json_output($options);    
  }
    
 }