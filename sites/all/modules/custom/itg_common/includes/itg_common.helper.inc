<?php

/*
 * Inc file contains the helper functions
 * 
 * 
 */


/**
 * Function for get all role.
 * @return $itg_role_array
 */
function custom_user_roles() {
  $role_cached = cache_get('itg_all_role', 'cache');
  
  if (!empty($role_cached->data)) {    
    $itg_role_array = $role_cached->data;
  } else {    
    $query = db_select('role', 'r');  
    $query->fields('r', array('rid', 'name'));
    $query->orderBy('weight');
    $query->orderBy('name');
    
    $result = $query->execute();

    $roles = array();
    
    foreach ($result as $role) {
     $itg_role_array[$role->name] = $role->rid;
    }
    
    cache_set('itg_all_role', $itg_role_array, 'cache');
  }

  return $itg_role_array;
}

//find all role array

$role_array = custom_user_roles();

/**
 * value define for role.
 */
define('AUTHOR_GUEST', $role_array['Author/Guest']);
define('INTERN', $role_array['Intern']);
define('SUBEDITOR_SR_SUB', $role_array['Subeditor/Sr.Sub']);
define('COPY_EDITOR', $role_array['Copy Editor']);
define('SECTION_EDITOR_ANCHOR', $role_array['Section Editor/Anchor']);
define('EDITOR', $role_array['Editor']);
define('SITE_ADMIN', $role_array['Site Admin']);
define('SEO', $role_array['SEO']);
define('CORRESPONDENT', $role_array['Correspondent']);
define('CO_ORDINATOR', $role_array['Co-ordinator']);
define('PHOTO_COORDINATOR', $role_array['Photo Coordinator']);
define('PHOTO_HEAD', $role_array['Photo Head']);
define('DESIGN_HEAD', $role_array['Design Head']);
define('COPY_DESK', $role_array['Copy Desk']);
define('DESIGNER', $role_array['Designer']);
define('PHOTOGRAPHER', $role_array['Photographer']);
define('ADMINISTRATOR', $role_array['administrator']);
define('UGC_MODERATOR', $role_array['UGC Moderator']);
define('EXPERT', $role_array['Expert']);
define('ANONYMOUS_USER', $role_array['anonymous user']);
define('AUTHENTICATED_USER', $role_array['authenticated user']);
define('SOCIAL_MEDIA', $role_array['Social Media']);
define('MARKETING_MANAGER', $role_array['Marketing Manager']);
define('FRONT_USER', $role_array['Front User']);
define('KNOWLEDGE_CENTRE', $role_array['Knowledge Centre']);
define('QUIZ_TAXONOMY_TID', variable_get('quiz_taxonomy_tid'));
define('ITG_SUPPORT_EMAIL', 'support@indiatoday.in');


/**
 * value define for image.
 */
define('EXTRA_LARGE_IMAGE_WIDTH', 647);
define('EXTRA_LARGE_IMAGE_HEIGHT', 363);
define('LARGE_IMAGE_WIDTH', 483);
define('LARGE_IMAGE_HEIGHT', 271);
define('MEDIUM_IMAGE_WIDTH', 370);
define('MEDIUM_IMAGE_HEIGHT', 208);
define('SMALL_IMAGE_WIDTH', 170);
define('SMALL_IMAGE_HEIGHT', 127);
define('EXTRA_SMALL_IMAGE_WIDTH', 88);
define('EXTRA_SMALL_IMAGE_HEIGHT', 66);
define('ISSUE_LARGE_IMAGE_WIDTH', 300);
define('ISSUE_LARGE_IMAGE_HEIGHT', 225);
define('ISSUE_SMALL_WIDTH', 210);
define('ISSUE_SMALL_HEIGHT', 145);

/**
 * value define for Ad.
 */
define('ADS_RHS1', 'ads_medium_rectangl_rhs1_300x250');
define('ADS_RHS2', 'ads_medium_rectangl_rhs2_300x250');
define('ADS_FOOTER', 'ads_super_banner_bottomnav728x90');
define('ADS_HEADER', 'ads_super_banner_top_nav_728x90');

define('ITGDATE', 'd/m/Y');
define('FRONT_THEME_NAME', 'itg');
define('EXTRA_SECTION_CARDS', 21);
define('SECTION_TAB', 20);
//define('CATEGORY_MANAGMENT', 4);
define('CATEGORY_MANAGMENT', variable_get('category_manager_vid'));
define('CITY_MANAGMENT', variable_get('city_manager_vid'));
define('POLITICIAN_TID', variable_get('tid_politician'));
define('ANCHOR_TID', variable_get('anchor_tid'));
define('REPORTER_TID', variable_get('reporter_tid'));
define('TAG_ID', 1);
define('VIDEO_MAIN_URL', 'http://medias3d.intoday.in');
define('VIDEO_BITRATE_URL', 'http://indiatoday-vh.akamaihd.net/i');

define('NEWSLETTER_EDUCATION_TID', variable_get('newsletter_education_tid'));

define('PARENT_SSO', 'uat-sso.indiatodayonline.in');

define('FRONT_URL', 'http://uat-it.indiatodayonline.in');
define('BACKEND_URL', 'http://uat-it-backend.indiatodayonline.in');
define('SSO_URL', 'http://uat-sso.indiatodayonline.in');
define('ACCORD_URL', 'http://businesstoday.accordhostings.com/TopIndicesCtrl.aspx');



//define('FRONT_URL', 'http://itgd-mum-lb-dev-frontend-app-1144451114.ap-south-1.elb.amazonaws.com');
//define('BACKEND_URL', 'http://itgd-mum-lb-dev-backend-app-678057722.ap-south-1.elb.amazonaws.com');
//define('FRONT_URL', 'http://localhost/itg-cms');
//define('BACKEND_URL', 'http://192.168.14.45/itg-cms');




// set comment config in variable
if (function_exists('global_comment_last_record')) {
  variable_set('COMMENT_CONFIG', global_comment_last_record());
}



/**
 * Function for debugging arrays and objects.
 * @param $arg
 *  array or object to be printed.
 */
function p($arg) {
  print '<pre>';
  print_r($arg);
  die;
}

function pr($arg) {
  print '<pre>';
  print_r($arg);
  print '</pre>';
}

