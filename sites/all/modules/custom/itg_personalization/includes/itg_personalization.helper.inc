<?php

/*
 * @file
 *   Helper file for moduel itg personalization.
 */

/**
 * Ajax callback for getting saved content all block.
 *
 * @param string $view_name
 *   Name of the view.
 * @param string $type
 *   Type of the ajax callback.
 */
function _personalized_saved_content($view_name, $type = 'ajax') {
  if ($type == 'ajax') {
    $commands = array();
    switch ($view_name) {
      case 'all':
        $content = views_embed_view('personalization_saved_content', 'block_1');
        $commands[] = ajax_command_invoke('#block-itg-personalization-personalized-saved-content', 'show');
        $commands[] = ajax_command_invoke('.view-display-id-block_5', 'hide');
        break;
      case 'articles':
        $content = views_embed_view('personalization_saved_content', 'block_2');
        break;
      case 'videos':
        $content = views_embed_view('personalization_saved_content', 'block_3');
        break;
      case 'photogallery':
        $content = views_embed_view('personalization_saved_content', 'block_4');
        break;
      case 'author':
        $content = views_embed_view('personalization_saved_content', 'block_5');
        $commands[] = ajax_command_invoke('#block-itg-personalization-personalized-saved-content', 'hide');
        $commands[] = ajax_command_replace("#target-content", '<div id="target-content">' . $content . '</div>');
        break;
      case 'my-content':
        $content = '';
        $commands[] = ajax_command_invoke('#block-itg-personalization-user-my-content', 'show');
    }   
    $commands[] = ajax_command_replace("#target", '<div id="target">' . $content . '</div>');
    ajax_deliver(array('#type' => 'ajax', '#commands' => $commands));
  }
}