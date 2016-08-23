<?php

/* 
 * @file
 *   Helper file for moduel itg personalization.
 */

/**
 * Ajax callback for getting saved content all block.
 */
function _personalized_saved_content($view_name, $type = 'ajax') {  
  switch ($view_name) {
    case 'all':      
      $content = views_embed_view('personalization_saved_content', 'block_1');
      break;
    case 'articles':
      $content = views_embed_view('personalization_saved_content', 'block_2');
      break;   
    case 'videos':
      $content = views_embed_view('personalization_saved_content', 'block_3');
      break;   
    case 'photogallery':
      $content = views_embed_view('personalization_saved_content', 'block_4');      
  }  
  $commands = array();  
  $commands[] = ajax_command_replace("#target", '<div id="target">' . $content . '</div>');  
  ajax_deliver(array('#type' => 'ajax', '#commands' => $commands));
}

