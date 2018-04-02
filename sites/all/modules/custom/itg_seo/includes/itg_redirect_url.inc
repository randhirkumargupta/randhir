<?php

/**
 * itg_get_node_redirect_url 
 * @param object $node
 * @param string $op
 */
function itg_get_node_redirect_url($node, $op) {
  global $base_url;
  
  if ($base_url == FRONT_URL) {
    $itg_status = $node->status;
    
    if (isset($node->type) && ($node->type == 'story' || $node->type == 'photogallery' || $node->type == 'videogallery' || $node->type == 'podcast' || $node->type == 'blog')) {
      
      /*$story_expiry_date = '';
      $current_time = time();

      if (!empty($node->field_story_expiry_date[LANGUAGE_NONE][0]['value'])) {
        $story_expiry_date = strtotime($node->field_story_expiry_date[LANGUAGE_NONE][0]['value']);
      }
      
      if (!empty($node->field_story_schedule_date_time[LANGUAGE_NONE][0]['value'])) {
        $story_schedule_date = strtotime($node->field_story_schedule_date_time[LANGUAGE_NONE][0]['value']);
      }

      if ($op == 'full' && (($itg_status == 0) || (!empty($story_expiry_date) && $story_expiry_date < $current_time) || (!empty($story_schedule_date) && $story_schedule_date > $current_time))) {
        if (!empty($node->field_primary_category[LANGUAGE_NONE][0]['value'])) {
          itg_get_redirect_url($node->field_primary_category[LANGUAGE_NONE][0]['value']);
        } else {
            drupal_goto('<front>');
        }       
      }*/
    } else {
        if ($op == 'full' && ($itg_status == 0)) {
          drupal_goto('<front>');
        }
    }
  }
  
}

/**
 * hook_taxonomy_term_load 
 * @param object $node
 * @param string $op
 */
function itg_seo_taxonomy_term_load($terms) {
  
    if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2)) && empty(arg(3))) {
      if (function_exists('itg_category_manager_term_state') && ($terms[arg(2)]->vid == CATEGORY_MANAGMENT)) {
        
        if (!itg_category_manager_term_state(arg(2))) {      
          itg_get_taxonomy_redirect_url(arg(2));
        }
      }
    }
  
}

/**
 * itg_get_taxonomy_redirect_url 
 * @param init $tid
 */
function itg_get_taxonomy_redirect_url($tid) {  
  $tid = itg_get_parents_taxonomy($tid);
  if ($tid != 0) {
    itg_get_redirect_url($tid);
  } else {
      drupal_goto('<front>');
  }  
}

/**
 * itg_get_redirect_url 
 * @param init $tid
 */
function itg_get_redirect_url($val) {  
  $red_url = drupal_get_path_alias('taxonomy/term/'.$val);   
  drupal_goto($red_url);
  exit;
}


/**
 * itg_get_parents
 * @param int $tid
 * @return $itg_result
 */
function itg_get_parents_taxonomy($tid) {
  $itg_query = db_select('taxonomy_term_hierarchy', 'itg')
      ->fields('itg', array('parent'))
      ->condition('tid', $tid, '=');      
  $itg_result = $itg_query->execute()->fetchField();
  return $itg_result;
}

/**
 * Implements hook_url_inbound_alter().
 */
function itg_seo_url_inbound_alter(&$path, $original_path, $path_language) {
  global $base_url;
  $old_content_id = '';
  $arg = arg();
  //p($_SERVER);
  if ($_SERVER['HTTP_HOST'] == 'indiatoday.intoday.in' || $_SERVER['HTTP_HOST'] == 'm.indiatoday.in') {
    $old_url = substr($_SERVER['REQUEST_URI'], 1);	  
    $source_url = redirect_load_by_source($old_url);    
    if (!empty($source_url)) {
      $new_url = drupal_get_path_alias($source_url->redirect);
      $url_re = 'https://www.indiatoday.in/'.$new_url;
    } else {
      if ($_SERVER['HTTP_HOST'] == 'm.indiatoday.in' || $_SERVER['HTTP_HOST'] == 'indiatoday.intoday.in') {
        if ((!empty($arg[0]) && ($arg[0] == 'lite')) && (!empty($arg[1]) && ($arg[1] == 'story')) ) {  // lite/story
          $storyarg = $arg[4];
          $storyarg_exp = explode('.html', $storyarg);
          $old_content_id = $storyarg_exp[0];
          $table = 'migrate_map_itgstorylist';
          $newcontentid = get_new_seccat_by_mig_id($old_content_id, $table);
          $redirecturl = get_redirect_url($newcontentid);
          $ampstoryurl = '/amp/'.$redirecturl;
          $newurl = 'https://www.indiatoday.in'.$ampstoryurl;
          drupal_goto($newurl, array(), 301);
        } else if ((!empty($arg[0]) && ($arg[0] == 'lite')) && (!empty($arg[1]) && ($arg[1] == 'gallery')) ) {  // lite/gallery
          $storyarg = $arg[4];
          $storyarg_exp = explode('.html', $storyarg);
          $old_content_id = $storyarg_exp[0];
          $table = 'migrate_map_itgphotogallery';
          $newcontentid = get_new_seccat_by_mig_id($old_content_id, $table);
          $redirecturl = get_redirect_url($newcontentid);
          $ampstoryurl = '/amp/'.$redirecturl;
          $newurl = 'https://www.indiatoday.in'.$ampstoryurl;
          drupal_goto($newurl, array(), 301);
        } else if ((!empty($arg[0]) && ($arg[0] == 'lite')) && (!empty($arg[1]) && ($arg[1] == 'live-blogs')) ) {  // lite/gallery
          $storyarg = $arg[3];
          $storyarg_exp = explode('.html', $storyarg);
          $old_content_id = $storyarg_exp[0];
          $table = 'migrate_map_itgbreakingnews';
          $newcontentid = get_new_seccat_by_mig_id($old_content_id, $table);
          $redirecturl = get_redirect_url($newcontentid);
          $ampstoryurl = '/amp/'.$redirecturl;
          $newurl = 'https://www.indiatoday.in'.$ampstoryurl;
          drupal_goto($newurl, array(), 301);
        } else if(($arg[0] == 'education' || $arg[0] == 'technology' || $arg[0] == 'auto' || $arg[0] == 'money' || $arg[0] == 'ipl2016' || $arg[0] == 'ipl2017' || $arg[0] == 'euro2016' || $arg[0] == 'olympics2016' || $arg[0] == 't20-world-cup-2016') && ($arg[1] == 'story') && !empty($arg[2]) && !empty($arg[3] && !empty($arg[4]))) {
          $storyarg = $arg[4];
          $table = 'migrate_map_itgstorylist';
          $newurl = getNewStoryUrl($storyarg, $table);
          if ($newurl) {
            drupal_goto($newurl, array(), 301);
          }
        } else if(($arg[0] == 'technology' || $arg[0] == 'auto' || $arg[0] == 'money' || $arg[0] == 'ipl2016' || $arg[0] == 'ipl2017' || $arg[0] == 'euro2016' || $arg[0] == 'olympics2016' || $arg[0] == 't20-world-cup-2016') && ($arg[1] == 'gallery') && !empty($arg[2]) && !empty($arg[3] && !empty($arg[4]))) {
          $storyarg = $arg[4];
          $table = 'migrate_map_itgphotogallery';
          $newurl = getNewStoryUrl($storyarg, $table);
          if ($newurl) {
            drupal_goto($newurl, array(), 301);
          }
        } else if(($arg[0] == 'education' || $arg[0] == 'technology' || $arg[0] == 'auto' || $arg[0] == 'money' || $arg[0] == 'ipl2016' || $arg[0] == 'ipl2017' || $arg[0] == 'euro2016' || $arg[0] == 'olympics2016' || $arg[0] == 't20-world-cup-2016') && ($arg[1] == 'video') && !empty($arg[2]) && !empty($arg[3] && !empty($arg[4]))) {
          $storyarg = $arg[4];
          $table = 'migrate_map_itgvideogallery';
          $newurl = getNewStoryUrl($storyarg, $table);
          if ($newurl) {
            drupal_goto($newurl, array(), 301);
          }
        } else {
            $url_re = 'https://www.indiatoday.in'.$_SERVER['REQUEST_URI'];
        }
      } else {
        $url_re = 'https://www.indiatoday.in'.$_SERVER['REQUEST_URI'];
      }
    }
    drupal_goto($url_re, array(), 301);    
    exit;
  }

  $type = 'story'; // use photogallery & videogallery in condition if you have
  $rss_url = '';
  $query_alias = '';
  $paging = array();
  if (!empty($_GET['sId']) && is_numeric($_GET['sId'])) { //code for this URL (story.jsp?sId=877)
    $old_content_id = $_GET['sId'];
  } else if ((!empty ($arg[0]) && $arg[0] == 'content_Email.jsp') && (!empty($_GET['sid']) && is_numeric($_GET['sid']))) {
    $old_content_id = $_GET['sid'];
  } else if ((!empty ($arg[0]) && $arg[0] == 'articlePrint.jsp') && (!empty($_GET['aid']) && is_numeric($_GET['aid']))) {
    $old_content_id = $_GET['aid'];
  } else if (!empty($_GET['option']) && $_GET['option'] == 'com_content' && arg(0) == 'conclave') {//conclave/index.php?option=com_content&task=view&id=2968&sectionid=15&secid=1&issueid=34&Itemid=1
      $old_content_id = '200'.$_GET['id'];
  } else if (!empty($_GET['option']) && $path == INDEX_PAGE_URL && $_GET['option'] == 'com_content') { //code for this URL (index.php?option=com_content)
      $old_content_id = $_GET['id'];
  } else if ((!empty($arg[0]) && $arg[0] == 'site') && (!empty($arg[1]) && $arg[1] == 'Photo') && (!empty($arg[2]) && is_numeric($arg[2]))) {  // Pattern site/Photo/3578/2/i-am-too-old-for-bwood-gauri-khan.html
      $old_content_id = $arg[2];
      $type = 'photogallery';
  } else if ((!empty($arg[0]) && $arg[0] == 'site') && (!empty($arg[1]) && $arg[1] == 'Video') && (!empty($arg[2]) && is_numeric($arg[2]))) {  // Pattern site/Video/3578/2/i-am-too-old-for-bwood-gauri-khan.html
      $old_content_id = $arg[2];
      $type = 'videogallery';
  } else if (!empty($arg[0]) && !empty($arg[1]) && ($arg[0] == 'gallerylist' || $arg[1] == 'gallerylist') && !empty($arg[2]) && !empty($arg[3])) {  // Pattern gallerylist/photos-television/6/163.html
      if ($arg[0] == 'gallerylist') {
        $photo_cat = $arg[3];
      } else if ($arg[1] == 'gallerylist') {
        $photo_cat = explode('.html', $arg[4]);
        $photo_cat = $photo_cat[0];
      } 
      $query_alias = $arg[2];
      $photo_cat_explode = explode('.html', $photo_cat);
      $old_content_id = $photo_cat_explode[0];
      $type = 'category';
      $table = 'migrate_map_itgphoto'; // We are using table name migration because KT team not store source id in drupal field.
  } else if ((!empty($arg[0]) && $arg[0] == 'site') && (!empty($arg[1]) && $arg[1] == 'photo') && ($arg[2]== 0) && (!empty($arg[3] && is_numeric($arg[3]))) && !empty($arg[4])) {  // Pattern site/photo/0/2/photo.html for category listing
      $old_content_id = $arg[3];
      $type = 'category';
      $table = 'migrate_map_itgphoto';
  } else if ((!empty($arg[0]) && $arg[0] == 'MoreGallery') && ($_GET['gId'] == 0) && (!empty($_GET['photocat']))) {  // Pattern site/photo/0/2/photo.html for category listing
      $old_content_id = $_GET['photocat'];
      $query_alias = $_GET['page'];
      $type = 'category';
      $table = 'migrate_map_itgphoto';
  } else if ((!empty($arg[0]) && $arg[0] == 'Simply') && ($_GET['secId']) && ($_GET['catId'])) {  // Pattern Simply?secId=20&catId=17
      $old_content_id = $_GET['catId'];
      $type = 'category';
      $table = 'migrate_map_itgcategory';
  } else if(!empty($arg[0]) && (!empty($arg[1]) && $arg[1] == 'category') && !empty($arg[2]) && (!empty($arg[3]) && is_numeric($arg[3])) && (!empty($arg[4]) && (strpos($arg[4], 'html')))) { // Pattern http://indiatoday.intoday.in/auto/category/cars/1/1186.html
      $lastarg = explode(".", $arg[4]);
      $old_content_id = $lastarg[0];
      $table = 'migrate_map_itgcategory';
      $type = 'category';
      $query_alias = $arg[3];
  } else if ((!empty($arg[0]) && ($arg[0] == 'videolist' || $arg[0] == 'programmelist')) && !empty($arg[1]) && !empty($arg[2]) && !empty($arg[3])) {  // Pattern gallerylist/photos-television/6/163.html
      $photo_cat = $arg[3];
      $query_alias = $arg[2];
      $photo_cat_explode = explode('.html', $photo_cat);
      $old_content_id = $photo_cat_explode[0];
      $type = 'category';
      $table = 'migrate_map_itgcategory'; 
  } else if(($arg[0] == 'story') && !empty($arg[1]) && !empty($arg[2] && !empty($arg[3]))) {
    $storyarg = $arg[3];
    $table = 'migrate_map_itgstorylist';
    $newurl = getNewStoryUrl($storyarg, $table);
    if ($newurl) {
      drupal_goto($newurl, array(), 301);
    }
  } else if((((!empty($arg[0]) && $arg[0] == 'rss') && (!empty($arg[1]) && $arg[1] == 'article.jsp')) || ((!empty($arg[0]) && $arg[0] == 'site') && (!empty($arg[1]) && $arg[1] == 'rss') && (!empty($arg[2]) && $arg[2] == 'article.jsp')))) {      
    if (!empty($_GET['sid']) || !empty($_GET['cid']) || !empty($_GET['scid']) || !empty($_GET['sscid'])) {
      if ($_GET['sid']) {        
        $old_content_id = $_GET['sid'];
        $table = 'migrate_map_itgsection';
      } else if ($_GET['cid']) {        
        $old_content_id = $_GET['cid'];
        $table = 'migrate_map_itgcategory';
      } else if ($_GET['scid']) {        
        $old_content_id = $_GET['scid'];
        $table = 'migrate_map_itgsubcategory';
      } else if ($_GET['sscid']) {        
        $old_content_id = $_GET['sscid'];
        $table = 'migrate_map_itgsubsubcategory';
      }
    }
    else {
      $old_content_id = 'nzero';
      $table = 'none';
    }
    $type = 'rss';
    $rss_url = 'rss';
  } else if(((!empty($arg[0]) && $arg[0] == 'rss') && (!empty($arg[1]) && $arg[1] == 'gallery.jsp'))) { // Pattern http://indiatoday.intoday.in/rss/gallery.jsp?gid=2 http://indiatoday.intoday.in/rss/gallery.jsp?gid=0 http://indiatoday.intoday.in/rss/gallery.jsp 
      $old_content_id = 'none';
      $table = 'none';
      $type = 'rss';
      $rss_url = 'rss-gallery';
      if ($_GET['gid'] > 0) {        
        $old_content_id = $_GET['gid'];
        $table = 'migrate_map_itgphoto';
      }
  } else if(((!empty($arg[0]) && $arg[0] == 'rss') && (!empty($arg[1]) && $arg[1] == 'video.jsp'))) { // Pattern http://indiatoday.intoday.in/rss/video.jsp?vcid=42 http://indiatoday.intoday.in/rss/video.jsp?vcid=0 http://indiatoday.intoday.in/rss/video.jsp
      $old_content_id = 'none';
      $table = 'none';
      $type = 'rss';
      $rss_url = 'rss-video';
      if ($_GET['vcid'] > 0) {        
        $old_content_id = $_GET['vcid'];
        $table = 'migrate_map_itgcategory';
      }
  } else if (($arg[0] == 'index.php' && !empty($_GET['option']) && $_GET['option'] == 'com_magazine')) { // Pattern http://indiatoday.intoday.in/index.php?option=com_magazine&opt=section&sectionid=89&Itemid=1&issueid=95
      drupal_goto(FRONT_URL, array(), 301);
  } else if ((!empty ($arg[0]) && $arg[0] == 'calendar') && !empty($arg[1]) && (!empty($arg[2]) && $arg[2] == 'online.html')) {  // Pattern calendar/16-10-2017/online.html
      $old_content_id = $arg[1];
      $table = 'none';
      $type = 'archives';
      $rss_url = 'archives/story';
  } else if ((!empty($arg[0]) && ($arg[0] == 'advanced_search.jsp' || $arg[0] == 'archivesearch.jsp')) && (!empty($_GET['searchtext']) || !empty($_GET['searchword']) || !empty($_GET['searchWord']))) {  // Pattern advanced_search.jsp?advsearch=1&searchtext=chinese+official+media&searchphrase=all&searchtype=archive
      if ($_GET['searchtext']) {
         $old_content_id = $_GET['searchtext']; 
      } elseif($_GET['searchword']) {
          $old_content_id = $_GET['searchword']; 
      } elseif ($_GET['searchWord']) {
          $old_content_id = $_GET['searchWord']; 
      }
      $table = 'none';
      $type = 'archives';
      $rss_url = 'topic';
  } else if ((!empty($arg[0]) && ($arg[0] == 'feedback.jsp')) && (!empty($_GET['refUrl']))) {  // Pattern advanced_search.jsp?advsearch=1&searchtext=chinese+official+media&searchphrase=all&searchtype=archive
      $refurl = $_GET['refUrl'];
      drupal_goto($refurl, array(), 301);
  } else if ((!empty($arg[0]) && ($arg[0] == 'scorecard')) && (!empty($arg[1]) && ($arg[1] == 'matchcenter.jsp' || $arg[1] == 'matchcenter-new.jsp')) && (!empty($_GET['matchid']))) {  // Pattern advanced_search.jsp?advsearch=1&searchtext=chinese+official+media&searchphrase=all&searchtype=archive
      $matchid = $_GET['matchid'];
      $paging = array('query' => array('matchid' => $matchid));
      $newmatchurl = $base_url.'/scorecard/live-cricket-score';
      drupal_goto($newmatchurl, $paging, 301);
  } else if ((!empty($arg[0]) && ($arg[0] == 'scorecard')) && (!empty($arg[1]) && ($arg[1] == 'matchcenter')) && (!empty($_GET['matchid']))) {  
      $matchid = $_GET['matchid'];
      $paging = array('query' => array('matchid' => $matchid));
      $newmatchurl = $base_url.'/scorecard/live-cricket-score';
      drupal_goto($newmatchurl, $paging, 301);
  } else if ((!empty($arg[0]) && ($arg[0] == 'scorecard')) && (!empty($arg[1]) && ($arg[1] == 'matchcenter')) && (!empty($_GET['matchid']))) {  
      $matchid = $_GET['matchid'];
      $paging = array('query' => array('matchid' => $matchid));
      $newmatchurl = $base_url.'/scorecard/live-cricket-score';
      drupal_goto($newmatchurl, $paging, 301);
  } else if ((!empty($arg[0]) && ($arg[0] == 'comment')) && (!empty($arg[1]) && $arg[1] == 'story') && (!empty($arg[2]) && (is_numeric($arg[2]))) && (!empty($arg[3]) && (is_numeric($arg[3])))) {  // Pattern embed/@#trfg
      $storyid = $arg[3];
      $table = 'migrate_map_itgstorylist';
      $newurl = getNewStoryUrl($storyid, $table);
      if ($newurl) {
        drupal_goto($newurl, array(), 301);
      }
  } else if ((!empty($arg[0]) && ($arg[0] == 'content_mail.php')) && (!empty($_GET['option']) && $_GET['option'] == 'com_content') && (!empty($_GET['name']) && $_GET['name'] == 'print') && (!empty($_GET['id']))) {  // Pattern embed/@#trfg
      $storyid = $_GET['id'];
      $table = 'migrate_map_itgstorylist';
      $newurl = getNewStoryUrl($storyid, $table);
      if ($newurl) {
        drupal_goto($newurl, array(), 301);
      }
  } else if ((!empty($arg[0]) && ($arg[0] == 'Story')) && (!empty($arg[1]) && is_numeric($arg[1])) && !empty($arg[2]) && !empty($arg[3])) {  // Pattern embed/@#trfg
      $storyid = $arg[1];
      $table = 'migrate_map_itgstorylist';
      $newurl = getNewStoryUrl($storyid, $table);
      if ($newurl) {
        drupal_goto($newurl, array(), 301);
      }
  } else if ((!empty($arg[0]) && ($arg[0] == 'Video')) && (!empty($arg[1]) && is_numeric($arg[1])) && (!empty($arg[2]) && is_numeric ($arg[2])) && (!empty($arg[3]) && $arg[3] == 'Videos') && !empty($arg[4])) {  // Pattern embed/@#trfg
      $videoid = $arg[1];
      $table = 'migrate_map_itgvideogallery';
      $newurl = getNewStoryUrl($videoid, $table);
      if ($newurl) {
        drupal_goto($newurl, array(), 301);
      }
  } else if ((!empty($arg[0]) && ($arg[0] == 'calendar')) && ($arg[1] == 0) && (is_numeric($arg[1])) && !empty ($arg[2]) && (is_numeric($arg[2]))) {
      $year = $arg[2];
      $current_time = date('Y-m-d', strtotime(date($year . '-01-01')));
      $output = get_first_issue_by_year($current_time);
      $current_issue = explode(' 00:', $output);
      $url = 'magazine/'.format_date(strtotime($current_issue[0]),'custom', 'd-m-Y');
      drupal_goto($url, array(), 301);
  } else if ((!empty($arg[0]) && ($arg[0] == 'embed')) && !empty ($arg[1])) {  // Pattern embed/@#trfg
      $videoembed = $arg[1];
      $newmatchurl = getNewVideoEmbedUrl($videoembed);
      if ($newmatchurl) {
        drupal_goto($newmatchurl, array(), 301);
      }
  } else if ((!empty($arg[0]) && ($arg[0] == 'gallery')) && !empty ($arg[1]) && !empty ($arg[2]) && !empty ($arg[3])) {  // Pattern gallery/2001-the-year-of-the-last-kumbh-mela-9-11-parliament-attack-and-some-major-events/31/8583.html
      /*$urlarg = $arg[2];
      if ($urlarg > 1) {
        $newmatchurl = $base_url.'/'.$arg[0].'/'.$arg[1].'/1/'.$arg[3];
        drupal_goto($newmatchurl, array(), 301);
      }*/
      $storyarg = $arg[3];
      $storyarg_exp = explode('.html', $storyarg);
	    $old_content_id = $storyarg_exp[0];
      $table = 'migrate_map_itgphotogallery';
      $newurl = getNewStoryUrl($old_content_id, $table);
      if ($newurl) {
        drupal_goto($newurl, array(), 301);
      }
  } else if ((!empty($arg[0]) && ($arg[0] == 'section')) && !empty ($arg[1]) && !empty ($arg[2]) && !empty ($arg[3])) {  // Pattern gallery/2001-the-year-of-the-last-kumbh-mela-9-11-parliament-attack-and-some-major-events/31/8583.html
      $old_content_id = $arg[1];
      $query_alias = $arg[2];
      $type = 'category';
      $table = 'migrate_map_itgsection';
  } else if ((!empty($arg[0]) && ($arg[0] == 'site')) && (!empty($arg[1]) && ($arg[1] == 'section')) && !empty ($arg[2]) && !empty ($arg[3]) && !empty ($arg[4])) {  // Pattern gallery/2001-the-year-of-the-last-kumbh-mela-9-11-parliament-attack-and-some-major-events/31/8583.html
      $old_content_id = $arg[2];
      $query_alias = $arg[3];
      $type = 'category';
      $table = 'migrate_map_itgsection';
  } else if ((!empty($arg[0]) && ($arg[0] == 'people' || $arg[0] == 'author')) && !empty ($arg[1]) && !empty ($arg[2])) {  // Pattern embed/@#trfg
      $people = $arg[1];
      $newmatchurl = $base_url.'/topic/'.$people;
      drupal_goto($newmatchurl, array(), 301);
  } else if((((!empty($arg[0]) && $arg[0] == 'site') && (!empty($arg[1]) && $arg[1] == 'rssGenerator.jsp')) && (!empty($_GET['secId'])) )) {      
    if ($_GET['secId']) {        
      $old_content_id = $_GET['secId'];
      $table = 'migrate_map_itgsection';
    } 
    $type = 'rss';
    $rss_url = 'rss';
  } else if ((!empty($arg[0]) && ($arg[0] == 'lite')) && (!empty($arg[1]) && ($arg[1] == 'story')) ) {  // lite/story
      $storyarg = $arg[4];
      $storyarg_exp = explode('.html', $storyarg);
      $old_content_id = $storyarg_exp[0];
      $table = 'migrate_map_itgstorylist';
      $newcontentid = get_new_seccat_by_mig_id($old_content_id, $table);
      $redirecturl = get_redirect_url($newcontentid);
      $ampstoryurl = '/amp/'.$redirecturl;
      $newurl = FRONT_URL.$ampstoryurl;
      drupal_goto($newurl, array(), 301);
    } else if ((!empty($arg[0]) && ($arg[0] == 'lite')) && (!empty($arg[1]) && ($arg[1] == 'gallery')) ) {  // lite/gallery
      $storyarg = $arg[4];
      $storyarg_exp = explode('.html', $storyarg);
      $old_content_id = $storyarg_exp[0];
      $table = 'migrate_map_itgphotogallery';
      $newcontentid = get_new_seccat_by_mig_id($old_content_id, $table);
      $redirecturl = get_redirect_url($newcontentid);
      $ampstoryurl = '/amp/'.$redirecturl;
      $newurl = FRONT_URL.$ampstoryurl;
      drupal_goto($newurl, array(), 301);
    } else if ((!empty($arg[0]) && ($arg[0] == 'lite')) && (!empty($arg[1]) && ($arg[1] == 'live-blogs')) ) {  // lite/gallery
      $storyarg = $arg[3];
      $storyarg_exp = explode('.html', $storyarg);
      $old_content_id = $storyarg_exp[0];
      $table = 'migrate_map_itgbreakingnews';
      $newcontentid = get_new_seccat_by_mig_id($old_content_id, $table);
      $redirecturl = get_redirect_url($newcontentid);
      $ampstoryurl = '/amp/'.$redirecturl;
      $newurl = FRONT_URL.$ampstoryurl;
      drupal_goto($newurl, array(), 301);
    } else if(($arg[0] == 'video' || $arg[0] == 'programme') && !empty($arg[1]) && (!empty($arg[2] && is_numeric($arg[2])) && !empty($arg[3]))) {
      $storyarg = $arg[3];
      $table = 'migrate_map_itgvideogallery';
      $newurl = getNewStoryUrl($storyarg, $table);
      if ($newurl) {
        drupal_goto($newurl, array(), 301);
      }
    } else if(($arg[0] == 'education' || $arg[0] == 'technology' || $arg[0] == 'auto' || $arg[0] == 'money' || $arg[0] == 'ipl2016' || $arg[0] == 'ipl2017' || $arg[0] == 'euro2016' || $arg[0] == 'olympics2016' || $arg[0] == 't20-world-cup-2016') && ($arg[1] == 'story') && !empty($arg[2]) && !empty($arg[3] && !empty($arg[4]))) {
      $storyarg = $arg[4];
      $table = 'migrate_map_itgstorylist';
      $newurl = getNewStoryUrl($storyarg, $table);
      if ($newurl) {
        drupal_goto($newurl, array(), 301);
      }
    } else if(($arg[0] == 'technology' || $arg[0] == 'auto' || $arg[0] == 'money' || $arg[0] == 'ipl2016' || $arg[0] == 'ipl2017' || $arg[0] == 'euro2016' || $arg[0] == 'olympics2016' || $arg[0] == 't20-world-cup-2016') && ($arg[1] == 'gallery') && !empty($arg[2]) && !empty($arg[3] && !empty($arg[4]))) {
      $storyarg = $arg[4];
      $table = 'migrate_map_itgphotogallery';
      $newurl = getNewStoryUrl($storyarg, $table);
      if ($newurl) {
        drupal_goto($newurl, array(), 301);
      }
    } else if(($arg[0] == 'education' || $arg[0] == 'technology' || $arg[0] == 'auto' || $arg[0] == 'money' || $arg[0] == 'ipl2016' || $arg[0] == 'ipl2017' || $arg[0] == 'euro2016' || $arg[0] == 'olympics2016' || $arg[0] == 't20-world-cup-2016') && ($arg[1] == 'video') && !empty($arg[2]) && !empty($arg[3] && !empty($arg[4]))) {
      $storyarg = $arg[4];
      $table = 'migrate_map_itgvideogallery';
      $newurl = getNewStoryUrl($storyarg, $table);
      if ($newurl) {
        drupal_goto($newurl, array(), 301);
      }
    } else if(!empty($arg[2]) && $arg[2] == 'comparecollege.jsp') { 
      $year1 = $_GET['year1'];
      if (!empty($year1)) {
        $bestclgurl = FRONT_URL.'/'.$arg[0].'/'.$arg[1].'/compare-college/'. strtolower($_GET['stream']) . "/" . $_GET['year1'] . "-" . $_GET['year2'];
      } else {
        $bestclgurl = FRONT_URL.'/'.$arg[0].'/'.$arg[1].'/compare-college/' . $_GET['year'] . "-" . strtolower($_GET['stream1']) . "-" . strtolower($_GET['stream2']);
      }
      drupal_goto($bestclgurl, array(), 301);
    } else if(!empty($arg[2]) && $arg[2] == 'emerging_colleges_rank.jsp') { 
      $bestclgurl = FRONT_URL.'/'.$arg[0].'/'.$arg[1].'/emerging-colleges-rank/'. strtolower($_GET['ST']);
      drupal_goto($bestclgurl, array(), 301);
    } else if(!empty($arg[2]) && $arg[2] == 'readyrecnor_directory_list.jsp') { 
      $bestclgurl = FRONT_URL.'/'.$arg[0].'/'.$arg[1].'/'. strtolower($_GET['ST']) . "-bestcollege";
      drupal_goto($bestclgurl, array(), 301);
    } else if(!empty($arg[2]) && $arg[2] == 'zone-wise-list.jsp') { 
      $bestclgurl = FRONT_URL.'/'.$arg[0].'/'.$arg[1]."/zonewiselist-" . strtolower($_GET['ST']);
      drupal_goto($bestclgurl, array(), 301);
    } else if(!empty($arg[2]) && $arg[2] == 'ranks.jsp') {
      if (!empty($_GET['ST'])) {
        $term_name = "Bestcolleges " . $arg['1'];
        $term = reset(array_values(taxonomy_get_term_by_name($term_name, 'category_management')));
        $term_data = reset(taxonomy_get_children($term->tid));
        if ($term_data->name == strtolower($_GET['ST'])) {
          $bestclgurl = FRONT_URL.'/'.$arg['0'] . "/" . $arg['1'] . "/ranks/" . $term_data->tid;
          drupal_goto($bestclgurl, array(), 301);
        } 
      }
    } else if(!empty($arg[0]) && $arg[0] == 'rssFeed_it.php') {
      if (!empty($_GET['secId'])) {     
        $old_content_id = $_GET['secId'];
        $table = 'migrate_map_itgsection';
      } else {
        $old_content_id = 'nzero';
        $table = 'none';
      }
      $type = 'rss';
      $rss_url = 'rss';
    } else if ((!empty($arg[0]) && ($arg[0] == 'article')) && !empty($arg[1]) && !empty($arg[2]) && !empty($arg[3])) {  // article/raina-finds-himself-in-unsavoury-controversy/1/117704.html
      $storyarg = $arg[3];
      $storyarg_exp = explode('.html', $storyarg);
      $old_content_id = $storyarg_exp[0];
      $table = 'migrate_map_itgstorylist';
      $newcontentid = get_new_seccat_by_mig_id($old_content_id, $table);
      $redirecturl = get_redirect_url($newcontentid);
      $newurl = FRONT_URL.'/'.$redirecturl;
      drupal_goto($newurl, array(), 301);
    } else if ((!empty($arg[0]) && ($arg[0] == 'calendar')) && (!empty($arg[1]) && is_numeric($arg[1])) && (!empty($arg[2]) && $arg[2] == 'magazine.html')) {
      $year = $arg[1];
      $current_time = date('Y-m-d', strtotime(date($year . '-01-01')));
      $output = get_first_issue_by_year($current_time);
      $current_issue = explode(' 00:', $output);
      $url = FRONT_URL.'/magazine/'.format_date(strtotime($current_issue[0]),'custom', 'd-m-Y');
      drupal_goto($url, array(), 301);
    } else if ((!empty($arg[0]) && ($arg[0] == 'Cartoon')) && (!empty($_GET['cId']))) {
      if (!empty($_GET['cId'])) {
        $content_id = 376019;
        $alias = drupal_get_path_alias('node/'.$content_id);
      }
      $url = FRONT_URL.'/'.$alias;
      drupal_goto($url, array(), 301);
    } else if ((!empty($arg[0]) && ($arg[0] == 'category')) && !empty($arg[1]) && !empty($arg[2]) && !empty($arg[3])) {  // Pattern category/americas/149/182.html
      $photo_cat = $arg[3];
      $query_alias = $arg[2];
      $photo_cat_explode = explode('.html', $photo_cat);
      $old_content_id = $photo_cat_explode[0];
      $type = 'category';
      $table = 'migrate_map_itgcategory'; 
    } else if(($arg[0] == 'education' || $arg[0] == 'technology' || $arg[0] == 'auto' || $arg[0] == 'money' || $arg[0] == 'ipl2016' || $arg[0] == 'ipl2017' || $arg[0] == 'euro2016' || $arg[0] == 'olympics2016' || $arg[0] == 't20-world-cup-2016') && ($arg[1] == 'subcategory' || $arg[1] == 'subsubcategory') && !empty($arg[2]) && !empty($arg[3] && !empty($arg[4]))) {
      $photo_cat = $arg[4];
      $query_alias = $arg[3];
      $photo_cat_explode = explode('.html', $photo_cat);
      $old_content_id = $photo_cat_explode[0];
      $type = 'category';
      $table = 'migrate_map_itgcategory';
    } else if ((!empty($arg[0]) && ($arg[0] == 'elections')) && !empty ($arg[1]) && !empty ($arg[2]) && !empty ($arg[3]) && !empty ($arg[4]) && !empty ($arg[5])) {  // Pattern gallery/2001-the-year-of-the-last-kumbh-mela-9-11-parliament-attack-and-some-major-events/31/8583.html
      $old_content_id = $arg[3];
      $query_alias = $arg[4];
      $type = 'category';
      $table = 'migrate_map_itgsection';
    } else if ((!empty($arg[0]) && ($arg[0] == 'site')) && (!empty($arg[1]) && $arg[1] == 'Story') && !empty($arg[2]) && !empty ($arg[3])) {
      $storyarg = $arg[2];
      $table = 'migrate_map_itgstorylist';
      $newcontentid = get_new_seccat_by_mig_id($storyarg, $table);
      $redirecturl = get_redirect_url($newcontentid);
      $newurl = FRONT_URL.'/'.$redirecturl;
      drupal_goto($newurl, array(), 301);
     } else if ((!empty($arg[0]) && ($arg[0] == 'site')) && (!empty($arg[1]) && $arg[1] == 'video') && !empty($arg[2]) && !empty ($arg[3]) && !empty ($arg[4])) {
      $storyarg = $arg[4];
      $storyarg_exp = explode('.html', $storyarg);
      $old_content_id = $storyarg_exp[0];
      $table = 'migrate_map_itgvideogallery';
      $newcontentid = get_new_seccat_by_mig_id($old_content_id, $table);
      $redirecturl = get_redirect_url($newcontentid);
      $newurl = FRONT_URL.'/'.$redirecturl;
      drupal_goto($newurl, array(), 301);
     } else if ((!empty($arg[0]) && ($arg[0] == 'story')) && !empty($arg[1]) && !empty($arg[2])) {
      $storyarg = $arg[2];
      $storyarg_exp = explode('.html', $storyarg);
      $old_content_id = $storyarg_exp[0];
      $table = 'migrate_map_itgstorylist';
      $newcontentid = get_new_seccat_by_mig_id($old_content_id, $table);
      $redirecturl = get_redirect_url($newcontentid);
      $newurl = FRONT_URL.'/'.$redirecturl;
      drupal_goto($newurl, array(), 301);
     } else if ((!empty($arg[0]) && ($arg[0] == 'story')) && !empty($arg[1]) && !empty($arg[2])) {
      $storyarg = $arg[2];
      $storyarg_exp = explode('.html', $storyarg);
      $old_content_id = $storyarg_exp[0];
      $table = 'migrate_map_itgstorylist';
      $newcontentid = get_new_seccat_by_mig_id($old_content_id, $table);
      $redirecturl = get_redirect_url($newcontentid);
      $newurl = FRONT_URL.'/'.$redirecturl;
      drupal_goto($newurl, array(), 301);
     } else if ((!empty($arg[0]) && ($arg[0] == 'Photo')) && !empty($arg[1]) && !empty($arg[2]) && !empty($arg[3])) {
      $storyarg = $arg[1];
      $storyarg_exp = explode('.html', $storyarg);
      $old_content_id = $storyarg_exp[0];
      $table = 'migrate_map_itgphotogallery';
      $newcontentid = get_new_seccat_by_mig_id($old_content_id, $table);
      $redirecturl = get_redirect_url($newcontentid);
      $newurl = FRONT_URL.'/'.$redirecturl;
      drupal_goto($newurl, array(), 301);
     } else if ((!empty($arg[0]) && ($arg[0] == 'site')) && (!empty($arg[1]) && $arg[1] == 'article') && !empty($arg[2]) && !empty($arg[3]) && !empty($arg[4])) {
      $storyarg = $arg[4];
      $storyarg_exp = explode('.html', $storyarg);
      $old_content_id = $storyarg_exp[0];
      $table = 'migrate_map_itgstorylist';
      $newcontentid = get_new_seccat_by_mig_id($old_content_id, $table);
      $redirecturl = get_redirect_url($newcontentid);
      $newurl = FRONT_URL.'/'.$redirecturl;
      drupal_goto($newurl, array(), 301);
     } else if ((!empty($arg[0]) && ($arg[0] == 'site')) && (!empty($arg[1]) && $arg[1] == 'gallery') && !empty($arg[2]) && !empty($arg[3]) && !empty($arg[4])) {
      $storyarg = $arg[4];
      $storyarg_exp = explode('.html', $storyarg);
      $old_content_id = $storyarg_exp[0];
      $table = 'migrate_map_itgphotogallery';
      $newcontentid = get_new_seccat_by_mig_id($old_content_id, $table);
      $redirecturl = get_redirect_url($newcontentid);
      $newurl = FRONT_URL.'/'.$redirecturl;
      drupal_goto($newurl, array(), 301);
     } else if ((!empty($arg[0]) && ($arg[0] == 'a-to-z.jsp')) && !empty($_GET['id'])) {
      $id = $_GET['id'];
      $newurl = "elections/a-to-z.jsp-@@-id=".$id;
      $newurl = FRONT_URL.'/'.$newurl;
      drupal_goto($newurl, array(), 301);
     } else if ((!empty($arg[0]) && ($arg[0] == 'Story')) && (!empty($arg[1])) && (!empty($arg[2]))) {
      $old_content_id = $arg[1];
      $table = 'migrate_map_itgstorylist';
      $newurl = getNewStoryUrl($old_content_id, $table);
      if ($newurl) {
        drupal_goto($newurl, array(), 301);
      }
     }
     else if ($arg[0] == 'node' && empty($arg[1])) {
      drupal_goto(FRONT_URL);
    }
  // Code for url redirection:
  if (!empty($old_content_id)) {
      if ($type == 'category') {
        $content_id = get_new_seccat_by_mig_id($old_content_id, $table);
        $alias = drupal_get_path_alias('taxonomy/term/'.$content_id);
        if (!empty($query_alias)) {
          $paging = array('query' => array('page' => $query_alias));
        }
      } else if($type == 'rss') {
        if ($old_content_id == 'none') {
          $alias = $base_url.'/'.$rss_url;
        } else if ($old_content_id == 'nzero') {
          $alias = $base_url.'/'.$rss_url.'/0';
        } else {
          $content_id = get_new_seccat_by_mig_id($old_content_id, $table);
          $alias = $base_url.'/'.$rss_url.'/'.$content_id;
        }
      } else if($type == 'archives') {
          $alias = $base_url.'/'.$rss_url.'/'.$old_content_id;
      } else {
        $content_id = get_new_content_id_by_migrated_id($old_content_id, $type);
        $alias = drupal_get_path_alias('node/'.$content_id);
      }
      //$alias = get_redirect_url($content_id);
      if (isset($alias)) {
        drupal_goto($alias, $paging, 301);
      }
      drupal_not_found();
      drupal_exit();
  }
}

/**
 * get new content id of itg by old content id
 * @param int $sourceid
 * @param string $type
 * @return int new content id
 */
function get_new_content_id_by_migrated_id($sourceid, $type) {
  $query = db_select('field_data_field_story_source_id', 'ssi');
  $query->fields('ssi', array('entity_id'));  
  $query->condition('field_story_source_id_value', $sourceid);
  $query->condition('bundle', $type);
  
  return $query->execute()->fetchField();
}

/**
 * get $alias
 * @param int $sourceid
 * @param string $type
 * @return int new content id
 */
function get_redirect_url($content_id) {
  $alias = drupal_get_path_alias('node/'.$content_id);
  return $alias; 
}

/**
 * Get Drupal Section or category id from ITG old system section or category id
 * @param int $sourceid
 * @param string $table
 * @return int new section or cat id
 */
function get_new_seccat_by_mig_id($sourceid, $table) {
  $query = db_select($table, 'scc');
  $query->fields('scc', array('destid1'));  
  $query->condition('sourceid1', $sourceid);
  return $query->execute()->fetchField();
}

/*
 * Used this function to get Video id of Migrated content.
 * @param String $string
 * @return int
 */
function getdecryptForEmbed($string){
	$decrypter = gmp_strval(gmp_init($string, 36));
	$decrypter = gmp_shiftr_update($decrypter, 5);
	$decrypter = gmp_export($decrypter);
	return $decrypter;
}

function gmp_shiftr_update($x,$n) { // shift right 
  return(gmp_div($x,gmp_pow(2,$n))); 
}

/*
 * Fucnction to get new Embed url from old embed code.
 * @param String $videoembed
 * return String
 */
function getNewVideoEmbedUrl($videoembed) {
  global $base_url;
  $newurl = '';
  $videoid = getdecryptForEmbed($videoembed);
  $newvideoid = get_new_seccat_by_mig_id($videoid, 'migrate_map_itgvideogallery');
  if ($newvideoid) {
    $video_decode = base64_encode($newvideoid);
    $video_node = node_load($newvideoid);
    $tid = $video_node->field_primary_category[LANGUAGE_NONE][0]['value'];
    $term = taxonomy_term_load($tid);
    $primary_category_name = strtolower(itg_common_custompath_insert_val($term->name));
    $newurl = $base_url.'/video/' . $primary_category_name.'/embed/'.$video_decode;
  }
  return $newurl;
}

/*
 * Get Story url from .html pattern
 * @param String
 */
function getNewStoryUrl($storyarg, $table) {
  global $base_url;
  $newmatchurl = '';
  $storyarg_exp = explode('.html', $storyarg);
  $old_content_id = $storyarg_exp[0];
  //$table = 'migrate_map_itgstorylist';
  $newcontentid = get_new_seccat_by_mig_id($old_content_id, $table);
  if ($newcontentid) {
    $redirecturl = get_redirect_url($newcontentid);
    $newmatchurl = FRONT_URL.'/'.$redirecturl;
  }
  return $newmatchurl;
}

/**
 * function for get first issue from year
 * @param int $year
 * @return string $output
 */
function get_first_issue_by_year($year){
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_issue_title', 'ft', 'ft.entity_id = n.nid');
  $query->fields('ft', array('field_issue_title_value'));
  $query->condition('ft.field_issue_title_value', $year, '>=');
  $query->orderBy('n.title', 'ASC');
  $query->condition('n.type', 'issue', '=');
  $query->condition('n.status', 1, '=');
  $query->range(0, 1);
  $output = $query->execute()->fetchField();
  return $output;
}
