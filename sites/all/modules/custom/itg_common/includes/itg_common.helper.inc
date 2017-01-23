<?php

/*
 * Inc file contains the helper functions
 */

define('AUTHOR_GUEST', 4);
define('INTERN', 7);
define('SUBEDITOR_SR_SUB', 9);
define('COPY_EDITOR', 5);
define('SECTION_EDITOR', 8);
define('SECTION_EDITOR_ANCHOR', 20);
define('EDITOR', 6);
define('SITE_ADMIN', 10);
define('SEO', 19);
define('CORRESPONDENT', 13);
define('CO_ORDINATOR', 11);
define('PHOTO_COORDINATOR', 16);
define('PHOTO_HEAD', 17);
define('DESIGN_HEAD', 14);
define('COPY_DESK', 12);
define('DESIGNER', 15);
define('PHOTOGRAPHER', 18);
define('ADMINISTRATOR', 3);
define('UGC_MODERATOR', 22); //
define('CATEGORY_MANAGMENT', 4);
define('EXPERT', 21);
define('ITGDATE', 'd/m/Y');
define('FRONT_THEME_NAME', 'itg');
define('EXTRA_SECTION_CARDS', 21);
define('SECTION_TAB', 20);
define('FRONT_USER', 25);
define('PARENT_SSO', 'dev.indiatodayonline.in');
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
define('ADS_RHS1', 'ads_medium_rectangl_rhs1_300x250');
define('ADS_RHS2', 'ads_medium_rectangl_rhs2_300x250');
define('ADS_FOOTER', 'ads_super_banner_bottomnav728x90');
define('ADS_HEADER', 'ads_super_banner_top_nav_728x90');
define('NEWSLETTER_EDUCATION_TID', 515);



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

