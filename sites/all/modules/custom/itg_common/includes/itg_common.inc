<?php

/*
 * Inc file contains the common functions
 */

/**
* callback for cms user dashboard
*  
*/

function itg_common_cms_user_dashboard() { 
   return theme('cms_user_dashboard', array('data' => $data));   
 }