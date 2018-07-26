<?php

/**
 * @file
 * Inc file contains the functions
 */

module_load_include('inc', 'itg_app_api', 'itg_app_api.services');

/**
 * List of briefly
 * @return type
 */
function itg_briefly_data() {
  $data = news_wrap_list();
  return theme('itg_story_load_briefly', array('data' => $data));
  
}

function itg_briefly_modal_page() {

   $html .= '<button onclick="brieflyShowDialog()">Show dialog</button>';
   // $html .=  l('click me', $href, array( 'attributes' => array('class' => array( 'ctools-use-modal' )) ));
  // $html = '<a class="btn" href="/itg-breifly/get/ajax/10" rel="lightframe">Ajax Test</a>';
  $html .= '<div id="ajax-target">Ajax goes here!!!</div>';
  return $html;
}

