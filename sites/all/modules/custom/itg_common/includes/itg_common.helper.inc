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
define('CONSUMER_KEY', 'uGJXyulHiHPLV15k5j3IPgjfp');
define('CONSUMER_SECRET', 'QH5KVfp1MCuTwrrx3o0cII0B2un8RveV4OfmKLXyS94W67RvOP');    
define('OAUTH_TOKEN', ' 732461289138585601-xyJ0I8ONeqedMDdMoW8pJo94TKLpbji');    
define('OAUTH_TOKEN_SECRET', 'tTFu7ga7eJFgpwCr2L9RtxQqd7kbRR4VMc5quMNCQd4U0');        

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

