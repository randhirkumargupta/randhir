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
  }
  else {
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
define('ADS_MANAGER', $role_array['Ads Manager']);
define('SYNDICATION', $role_array['Syndication']);
define('MOBILE_VAS', $role_array['Mobile VAS']);
define('QUIZ_TAXONOMY_TID', variable_get('quiz_taxonomy_tid'));
define('ITG_SUPPORT_EMAIL', 'support@indiatoday.in');
define('ITG_IMAGE_FOLDER', 'images/');
define('ITG_NEWSLETTER_EMAIL', 'desk-itgd@intoday.com');
define('ITG_NEWSLETTER_FROMNAME', 'India Today');
define('JWPLAYER_DFP_TAG','https://pubads.g.doubleclick.net/gampad/ads?sz=400x300|640x480&iu=/1007232/Indiatoday_VOD_Pre_Roll_WEB&impl=s&gdfp_req=1&env=vp&output=xml_vast2&unviewed_position_start=1&url=[referrer_url]&description_url=[description_url]&correlator=[timestamp]');
define('ITG_GA_CODE', 'UA-795349-17');


/**
 * value define for image.
 */
define('EXTRA_BIG_IMAGE_WIDTH', 1024);
define('EXTRA_BIG_IMAGE_HEIGHT', 768);
 
define('EXTRA_LARGE_IMAGE_WIDTH', 647);
define('EXTRA_LARGE_IMAGE_HEIGHT', 363);
define('LARGE_IMAGE_WIDTH', 483);
define('LARGE_IMAGE_HEIGHT', 271);
define('MEDIUM_IMAGE_WIDTH', 370);
define('MEDIUM_IMAGE_HEIGHT', 208);
define('SMALL_IMAGE_WIDTH', 170);
define('SMALL_IMAGE_HEIGHT', 96);
//define('SMALL_IMAGE_HEIGHT', 127);
define('EXTRA_SMALL_IMAGE_WIDTH', 88);
define('EXTRA_SMALL_IMAGE_HEIGHT', 50);
//define('EXTRA_SMALL_IMAGE_HEIGHT', 66);
define('ISSUE_LARGE_IMAGE_WIDTH', 172);
define('ISSUE_LARGE_IMAGE_HEIGHT', 240);
define('ISSUE_SMALL_WIDTH', 100);
define('ISSUE_SMALL_HEIGHT', 140);

/**
 * value define for Ad.
 */
define('ADS_RHS1', 'ads_medium_rectangl_rhs1_300x250');
define('ADS_RHS2', 'ads_medium_rectangl_rhs2_300x250');
define('ADS_RHS_MTF', 'ads_medium_rectangl_mtf_300x200');
define('ADS_FOOTER', 'ads_super_banner_bottomnav728x90');
define('ADS_HEADER', 'ads_super_banner_top_nav_728x90');

define('ITGDATE', 'd/m/Y');
define('ITG_INDIATODAY_SITENAME_XML', 'India Today');
define('FRONT_THEME_NAME', 'itg');
define('AMP_THEME_NAME', 'amptheme');
define('EXTRA_SECTION_CARDS', 9);
define('SECTION_TAB', 20);
//$extra_large_image_style = array('photgallery_landing_slider_753x543', 'big_story_widget' ,'photo_slider_753x543', 'image_750x363', 'photogallery_slide');
//define('EXTRA_LARGE_IMAGE_STYLES', $extra_large_image_style);

//$large_image_style = array('magazine_top_story_483x271');
//define('LARGE_IMAGE_STYLES', $large_image_style);

//$medium_image_style = array('home_page_feature_small', 'section_ordering_widget' , 'anchors_landing', 'magazine_top_three_story_237x133');
//define('MEDIUM_IMAGE_STYLES', $medium_image_style);

//$small_image_style = array('image170x127' , 'video_landing_page_170_x_127');
//$small_image_style = array('image170x127');
//define('SMALL_IMAGE_STYLES', $small_image_style);

//$small_extra_image_style = array('widget_very_small');
//define('SMALL_EXTRA_IMAGE_STYLES', $small_extra_image_style);

define('CATEGORY_MANAGMENT', variable_get('category_manager_vid'));
define('CITY_MANAGMENT', variable_get('city_manager_vid'));
define('POLITICIAN_TID', variable_get('tid_politician'));
define('ANCHOR_TID', variable_get('anchor_tid'));
define('REPORTER_TID', variable_get('reporter_tid'));
define('TAG_ID', 1);
define('VIDEO_MAIN_URL', 'http://medias3d.intoday.in');
define('VIDEO_BITRATE_URL', 'http://indiatoday-vh.akamaihd.net/i');
define('VIDEO_PROPERTY', variable_get('video_property'));
define('NEWSLETTER_EDUCATION_TID', variable_get('newsletter_education_tid'));
define('SITEMAP_BUCKET', variable_get('itg_sitemap_chunks_s3_bucket_folder_name', 'sitemapxml_other'));
//define('PARENT_SSO', variable_get('parent_sso'));
define('FRONT_URL_VIDEO', variable_get('FRONT_URL_VIDEO'));
define('FRONT_URL', variable_get('itg_front_url'));
define('BACKEND_URL', variable_get('itg_backend_url'));
define('INDEX_PAGE_URL', 'node/2');
define('ACCORD_URL', 'http://businesstoday.accordhostings.com/TopIndicesCtrl.aspx');
define('taxonomy_terms_per_page_admin' , 20);
define('SSO_COOKIE_DOMAIN' , variable_get('sso_cookie_domain'));
define('BUCKET_FOLDER' , 'indiatoday');
/*define('PARENT_SSO', 'https://staging-sso.indiatodayonline.in');
define('SSO_URL', 'https://staging-sso.indiatodayonline.in');*/
define('PARENT_SSO', 'https://auth.indiatoday.in/');
define('SSO_URL', 'https://auth.indiatoday.in/');

/*if(isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] == "on") { 
    $site_protocol = 'https://';
} else { 
    $site_protocol = 'http://';
}*/

$site_protocol = 'https://';
define('SITE_PROTOCOL' , $site_protocol);
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

/**
 * Function for getting content by section
 * @param int $section_id
 * @param string $type
 * @return array
 */
function itg_common_get_content_by_section($section_id, $type) {
  $item_per_page = 4;
  $table = 'itg_widget_order_section';
  if (strtolower($type) == 'all') {
    $table = 'itg_widget_order';
  }
  $db_query = db_select($table, 'iwo')->extend('PagerDefault')->limit($item_per_page);
  $db_query->join('node', 'n', 'n.nid = iwo.nid');
  $db_query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $db_query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
  if ($type == 'videogallery') {
    $db_query->leftJoin('field_data_field_video_duration', 'fdv', 'fdv.entity_id=n.nid');
  }
  $db_query->fields('n', array('nid', 'title', 'created'));
  $db_query->fields('eli_file', array('uri'));
  if ($type == 'videogallery') {
    $db_query->fields('fdv', array('field_video_duration_value'));
  }
  $db_query->condition('iwo.widget', 'section_wise_widget');
  $db_query->condition('iwo.content_type', $type);
  $db_query->condition('iwo.cat_id', $section_id);
  $db_query->orderBy('iwo.weight', 'DESC');
  $result = $db_query->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result;
}

/**
 * Get email by roll
 * @param string $key
 * @param string $message
 * @param array $params
 */
function get_email_by_roll($id) {
  $query = db_select('users', 'u');
  $query->fields('u', array('mail'));
  $query->join('users_roles', 'ur', 'ur.uid = u.uid');
  $query->condition('ur.rid', $id, 'IN');
  $query->condition('u.status', 1);
  $result = $query->execute();

  foreach ($result as $val) {
    $value[] = $val->mail;
  }
  return $value;
}

/*
 * Implements _widget_title().
 */
function _widget_title($string , $is_for_attribute = TRUE) {
  if($is_for_attribute) {
    return str_replace(array('\'', '"' , '>' , '<' , '\/'), '', html_entity_decode($string));
  } else {
    return str_replace(array('>' , '<' , '\/'), '', html_entity_decode($string));
  }
}

/**
 * Function for counting the images in photogallery.
 * @param type $nid
 * @return type
 */
function itg_common_count_images_in_photogallery($nid) {
  $query = db_select('field_data_field_gallery_image', 'fdg')
      ->fields('fdg', array('field_gallery_image_value'))
      ->condition('fdg.entity_id', $nid);
  $result = $query->execute()->rowCount();
  return $result;
}

/**
 * itg_fronturl_check
 * 
 */
function itg_fronturl_check() {
  global $base_url;
  $baseUrl = explode('//', $base_url);
  $fUrl = explode('//', FRONT_URL);  
  if ($baseUrl[1] == $fUrl[1]) {
    return true;
  } else {
      return false;
  }
}

/**
 * Function is used to prepare node title with emoji.
 * 
 * @param type $nid
 * @return type
 */
function get_field_value_for_smily($nid) {
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_story_short_headline', 'sh', 'sh.entity_id=n.nid');
  $query->leftJoin('field_data_field_emoji', 'emoji', 'emoji.entity_id=n.nid');
  $query->leftJoin('field_data_field_emoji_2', 'emoji_2', 'emoji_2.entity_id=n.nid');
  $query->leftJoin('field_data_field_emoji_position', 'emoji_pos', 'emoji_pos.entity_id=n.nid');
  $query->fields('n', array('title'));
  $query->fields('emoji', array('field_emoji_value'));
  $query->fields('sh', array('field_story_short_headline_value'));
  $query->fields('emoji_2', array('field_emoji_2_value'));
  $query->fields('emoji_pos', array('field_emoji_position_value'));
  $query->condition('n.nid', $nid);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  return array(
    'field_story_short_headline_value' => $result[0]['field_story_short_headline_value'],
    'field_emoji_position_value' => array($result[0]['field_emoji_position_value'] , $result[1]['field_emoji_position_value']),
    'field_emoji_2_value' => $result[0]['field_emoji_2_value'],
    'field_emoji_value' => $result[0]['field_emoji_value'],
    'title' => $result[0]['title'],
  );
}

/**
 * This function use for remove html special chars
 */
function itg_common_remove_extra_html($string) {
  $return_data = "";
  if (!empty($string)) {
    $return_data = preg_replace("/&#?[a-z0-9]{2,8};/i", "", $string);
  }
  return $return_data;
}

/**
 * Function which returns true is case of special page.
 */
function itg_is_special_page() {
  $flag = FALSE;
  $arg = arg();
  if($arg[0] == 'taxonomy' && $arg[1] == 'term' && is_numeric($arg[2])) {
    $query = db_select('itg_layout_tpl' ,'tpl');
    $query->fields("tpl" , array("id"));
    $query->condition("tpl.status" , 1);
    $query->condition("tpl.section_name" , $arg[2]);
    $result = $query->execute()->rowCount();
    if($result) {
      $flag = TRUE;
    }
  }
  return $flag;
}

/**
 * Implements _occupation_from_tid_for_sef_url.
 * {@inheritdoc}
 */
function _occupation_from_tid_for_sef_url($tid) {
  $term_data = taxonomy_term_load($tid);
  return $term_data->name;
}

/*
 * get_other_gallery_amp
 *  @param int $primary_category
 */
function get_other_gallery_amp($primary_category, $nid, $bundle, $limit) {
   if (!empty($primary_category)) {
    $query = db_select('field_data_field_primary_category', 'fg');
    $query->leftjoin('node', 'n', 'n.nid = fg.entity_id');
    $query->leftjoin('field_data_field_story_small_image', 'sm', 'sm.entity_id = fg.entity_id');
    $query->fields('fg', array('entity_id'))
          ->fields('n', array('title', 'created','nid'))
          ->fields('sm', array('field_story_small_image_fid'))
          ->condition('fg.entity_id', array($nid), 'NOT IN')
          ->condition('fg.field_primary_category_value', $primary_category)
          ->condition('n.status', 1)
          ->condition('fg.bundle', $bundle);
    $query->orderBy('n.created', 'DESC'); 
    $query->range(0, $limit);
    $result = $query->execute();

    return $record = $result->fetchAll(PDO::FETCH_ASSOC);
  }
}

/**
 * WatchDog helper function for debug
 */
function itg_watchdog($error_type , $message) {
    watchdog($error_type, "<pre>".print_r($message , 1)."</pre>");
}

/**
 * Function for getting collection id array for gallery images.
 * @param int $gallery_id
 * @return type array
 */
function itg_commom_get_gallery_image_array_by_gid($gallery_id) {
  $query = db_select('field_data_field_gallery_image', 'fdg');
  $query->fields('fdg', array('field_gallery_image_value'));
  $query->condition('fdg.entity_id', $gallery_id);
  $query->condition('fdg.entity_type', 'node');
  $query->condition('fdg.bundle', 'photogallery');
  $result = $query->execute()->fetchAll();
  return $result;
}


/**
 * Function for get Byline Emails
 * @param type $node
 * @return type
 */
function get_node_byline_emails($node) {
  $emails = '';
  if ($node->field_common_by_line_reporter_id[LANGUAGE_NONE][0]['value']) {
    $byline_ids = $node->field_common_by_line_reporter_id[LANGUAGE_NONE][0]['value'];
    $byline_ids = explode(',', $byline_ids);
    $query = db_select('field_data_field_reporter_email_id', 'frei');
    $query->fields('frei', array('field_reporter_email_id_value'));
    $query->condition('frei.entity_id', $byline_ids, 'IN');
    $result = $query->execute()->fetchAll();
    $email = array();
    foreach ($result as $value) {
      $email[] = $value->field_reporter_email_id_value;
    }
    $emails = implode(',', $email);
  }
  return $emails;
}
