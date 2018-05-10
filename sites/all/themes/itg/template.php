<?php

/**
 * @file
 * template.php
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */

/**
 * Implementation of hook_theme()
 * {@inheritdoc}
 */
function itg_theme() {
  $items = array();
  $items['user_login'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'itg') . '/templates',
    'template' => 'user-login',
  );
  $items['user_pass'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'itg') . '/templates',
    'template' => 'user-pass',
  );
  $items['internal_video_player'] = array(
    'path' => drupal_get_path('theme', 'itg') . '/templates',
    'template' => 'internal-video-player',
  );
  $items['migrated_video_player'] = array(
    'path' => drupal_get_path('theme', 'itg') . '/templates',
    'template' => 'migrated-video-player',
  );
  $items['internal_video_player_jw'] = array(
    'path' => drupal_get_path('theme', 'itg') . '/templates',
    'template' => 'internal-video-player-jw',
  );
  $items['itg_election_constituency'] = array(
    'path' => drupal_get_path('theme', 'itg') . '/templates',
    'template' => 'page--electionconstituency',
  );
  $items['itg_election_constituency_map'] = array(
    'path' => drupal_get_path('theme', 'itg') . '/templates',
    'template' => 'page--electionconstituencymap',
  );
  return $items;
}

/**
 * Hide read more link from front page
 * {@inheritdoc}
 */
function itg_preprocess_node(&$variables) {
  //p($variables['node']->type);
  $node = $variables['node'];
  unset($variables['content']['links']['node']['#links']['node-readmore']);
  if ($variables['node']->type == 'page') {
    // Inclue pathauto module
    module_load_all_includes('inc', 'pathauto', 'pathauto');
    if (function_exists('pathauto_cleanstring')) {
      // This assumes that you are using Pathauto for generating clean URLs.
      // Get the "clean" title.
      $title = pathauto_cleanstring($variables['node']->title);
      // Replace all dashes with underscores. This is necessary for recognizing the
      // template filenames.
      $title = str_replace('-', '_', $title);
      // Add new template variation.
      $variables['theme_hook_suggestions'][] = 'node__' . $title;
      $variables['static_page_menu'] = itg_block_render('menu', 'menu-about-us-page-menu');
     
    }
  }
  
  $content_type = array('story', 'photogallery', 'videogallery', 'blog', 'podcast', 'mega_review_critic');
  if ($variables['node']->type != 'page' && in_array($variables['node']->type, $content_type)) {
    if (function_exists('global_comment_last_record')) {
      $variables['global_comment_last_record'] = global_comment_last_record();
    }
  }

  if ($variables['type'] == 'webform') {
    unset($variables['submitted']);    
  }


  if ($variables['type'] == 'survey') {
    module_load_include('inc', 'itg_survey', 'includes/itg_survey_form');
    $variables['theme_hook_suggestions'][] = 'node__survey';
    $itg_survey_survey_form = drupal_get_form('itg_survey_survey_form');
    $variables['content'] = $itg_survey_survey_form;
  }

  if ($variables['type'] == 'quiz') {
    module_load_include('inc', 'itg_quiz', 'includes/itg_quiz_form');
    $itg_survey_survey_form = drupal_get_form('itg_quiz_quiz_form');
    $variables['theme_hook_suggestions'][] = 'node__survey';
    $variables['content'] = $itg_survey_survey_form;
  }

  if ($variables['type'] == 'poll') {
    module_load_include('inc', 'itg_poll', 'includes/itg_poll_current_poll');
    $variables['theme_hook_suggestions'][] = 'node__poll';
    $variables['poll_form'] = itg_poll_get_all_current_poll();
  }

  // code start for Akamai Puposes (Self refresh content)
  if ($variables['type'] == 'story') {
    drupal_add_js(drupal_get_path('theme', 'itg') . '/js/story_altr.js');
    $variables['story_zedo_ad'] = "<div id='z61b6b10d-8ff4-41e3-b8b0-c46bf2be1e7e' style='display:none' ></div>";
  }
  // Code ends for Akamai Purposes (Self refresh content)
  if (!empty($node) && $node->type == 'story' && arg(2) === null && (isset($node->field_story_technology[LANGUAGE_NONE]))) {
    drupal_add_css(drupal_get_path('theme', 'itg') . "/css/prettyPhoto.css");
    drupal_add_js(drupal_get_path('theme', 'itg') . "/js/jquery.prettyPhoto.js");
  }
  
  // multiuser template assign to live blog.
  if ($variables['type'] == 'breaking_news') {
    if ($variables['field_multi_user_allows'][0]['value'] && $variables['field_multi_user_allows'][0]['value'] == 1) {
       $variables['theme_hook_suggestions'][] = 'node__breaking_news_custom';
    }
  }
}

/**
 * Returns blocks.
 * @param string $module
 * @param string $block_id
 * @return array
 */
function itg_block_render($module, $block_id) {
  $block = block_load($module, $block_id);
  $block_content = _block_render_blocks(array($block));
  unset($block_content['menu_menu-about-us-page-menu']->subject);
  $build = _block_get_renderable_array($block_content);
  $block_rendered = drupal_render($build);
  return $block_rendered;
}

/**
 * Change comment date format
 * {@inheritdoc}
 */
function itg_preprocess_comment(&$variables) {
  $comment = $variables['elements']['#comment'];
  $node = $variables['elements']['#node'];
  if ($node->type == 'story' || $node->type == 'blog' || $node->type == 'photogallery' || $node->type == 'videogallery') {
    $variables['created'] = format_date($comment->created, 'custom', 'D, d/m/Y h:i');
    $variables['changed'] = format_date($comment->changed, 'custom', 'D, d/m/Y h:i');
    if ($comment->uid != 0) {
      $user = user_load($comment->uid);
      if (!empty($user->field_first_name[LANGUAGE_NONE][0]['value'])) {
        $submit_name = $user->field_first_name[LANGUAGE_NONE][0]['value'];
      }
      else {
        $submit_name = $variables['author'];
      }
    }
    else {
      $submit_name = $variables['author'];
    }
    $variables['submitted'] = t('Submitted by !username on !datetime', array('!username' => $submit_name, '!datetime' => $variables['created']));
  }
}

/**
 * Override the video field
 * {@inheritdoc}
 */
function itg_preprocess_field(&$vars) {
  if ($vars['element']['#field_name'] == 'field_upload_video') {
    $file_id = $vars['element']['#items'][0]['fid'];
    if (module_exists('itg_videogallery')) {
      $video_id = itg_videogallery_get_video($file_id);
      $vars['element'][0]['#file']->video_id = $video_id;
    }
  }
}

/**
 * {@inheritdoc}
 */
function itg_preprocess_page(&$variables) {
  global $base_url;
  $base_root;
  $arg = arg();
  $path_request = request_path();
  $path_request_array = explode('/', $path_request);
  
  // add condition to hide header and footer for signup, forgot-password page
  if (isset($_GET['ReturnTo']) && !empty($_GET['ReturnTo'])) {
    $variables['theme_hook_suggestions'][] = 'page__ssoheader';
  }

  if ($arg[0] == 'signup' || $arg[0] == 'forgot-password' || $arg[0] == 'sso' || $arg[0] == 'sso-user') {
    $variables['theme_hook_suggestions'][] = 'page__ssoheader';
  }

  if (!empty($arg[2]) && (($arg[2] == 'ugc') || $arg[0] == 'password-success' || $arg[0] == 'complete-page' || $arg[0] == 'associate-photo-video-content' || $arg[0] == 'funalytics-popup' || $arg[1] == 'videogallery-embed')) {
    $variables['theme_hook_suggestions'][] = 'page__removeheader';
  }

  if ($arg[0] == 'photogallery-embed' || $arg[0] == 'embed-video' || $arg[0] == 'embeded-video') {
    $variables['theme_hook_suggestions'][] = 'page__itgembed';
  }
  if ($arg[0] == 'photo' && $arg[2] == 'embed') {
    $variables['theme_hook_suggestions'][] = 'page__itgembed';
  }
  if ($arg[0] == 'video' && $arg[2] == 'embed') {
    $variables['theme_hook_suggestions'][] = 'page__itgembed';
  }

  // For single column page
  if ($arg[0] == 'be-lucky-today' || ($arg[0] == 'node' && $arg[1] == 1124436) || ($arg[0] == 'node' && $arg[1] == 1178342) || (arg(0) == 'scorecard' && arg(1) == 'matchcenter') || $arg[0] == 'state-elections') {
	  if($arg[0] == 'node' && $arg[1] == 1124436) {
		  drupal_set_title('');
    }		  
    $variables['theme_hook_suggestions'][] = 'page__singlecolumn';
  }
  
  if(($arg[0] == 'elections' && !empty($arg[1]) && $arg[2] == 'constituency' && !empty($arg[3])) || ($arg[0] == 'elections' && !empty($arg[1]) && $arg[2] == 'constituency-map')){
		$variables['theme_hook_suggestions'][] = 'page__singlecolumn';
	}
  // For single column page at live Blog for multi_user_allows
  if (!empty($variables['node']->type) && $variables['node']->type == 'breaking_news' && isset($variables['node']->field_multi_user_allows['und'][0]['value']) && $variables['node']->field_multi_user_allows['und'][0]['value'] == 1) {
    $variables['theme_hook_suggestions'][] = 'page__singlecolumn';
  }
  
  // Call Event Parent TPL
  if (!empty($variables['node']->type) && $variables['node']->type == 'event_backend' || $arg[0] == 'event') {
    $variables['theme_hook_suggestions'][] = 'page__event_domain';
  }

  if ($arg[0] == 'blog-listing') {
    drupal_add_css('#page-title  {display: none !important}', 'inline');
  }

  if ($arg[0] == 'blog') {
    drupal_add_css('#page-title , .feed-icon  {display: none !important}', 'inline');
    unset($variables['page']['content']);    
    $variables['theme_hook_suggestions'][] = 'page__itg_blog_page';
  }

  $progarm_cat_id = variable_get('program_category_id_for_programmes');

  if ($arg[0] == 'taxonomy' && $arg[1] == 'term' && $arg[2] == $progarm_cat_id) {
    $variables['theme_hook_suggestions'][] = 'page__taxonomy_term_program';
  }

  if ($arg[0] == 'rss') {
    drupal_set_title('Choose Your News Feeds');
  }
}

/**
 * {@inheritdoc}
 */
function itg_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  $crumbs = '';
  if (!empty($breadcrumb) && (arg(0) == 'topic' || arg(0) == 'advance_search')) {
    $crumbs = '<div id="breadcrumbs"><ul><li></li>';
    foreach ($breadcrumb as $value) {
      $crumbs .= '<li>' . $value . '</li>';
    }

    if (arg(0) == 'topic' || arg(0) == 'advance_search') {
      if (!empty(arg(1)) || !empty($_GET['keyword'])) {
        if (arg(0) == 'topic') {
          $s_name = str_replace("-", " ", arg(1));
        }
        else if (arg(0) == 'advance_search') {
          $s_name = $_GET['keyword'];
        }
        $keyword = '<li>' . $s_name . '</li>';
      }

      $crumbs .= '<li>Search</li>' . $keyword . '</li></ul></div>';
    }
    else {
      $crumbs .= '<li>' . drupal_get_title() . '</li></ul></div>';
    }
  }
  return $crumbs;
}

/**
 * {@inheritdoc}
 */
function itg_preprocess_html(&$vars) {
  $arg = arg();
  global $base_url, $user;
  if ($base_url == BACKEND_URL && !empty($user->uid)) {
    $vars['classes_array'][] = 'pointer-event-none';
  }
  
  if ($arg[2] != 'embed') {
  // Code started for adding header , body start , body close for ads module

  if (function_exists('get_header_body_start_end_code')) {
    $ads_code = get_header_body_start_end_code();
    foreach ($ads_code as $ads_key => $ads_chunk) {
      $code = implode(' ', $ads_chunk);
      $script_code = array(
        '#type' => 'markup',
        '#markup' => $code,
      );
      
      drupal_add_html_head($script_code, $ads_key);
    }
  }
  
  itgd_chart_beat_code();
  
  $newsroomjs = get_newsroom_js();
  $script_code = array(
	'#type' => 'markup',
	'#markup' => $newsroomjs,
  );
  drupal_add_html_head($script_code, 'newsroomjs');
    if($arg[0] == 'scorecard' && $arg[1] == 'matchcenter'){
        $newsroomjs = get_newsroom_screcard_js();
        $script_code = array(
            '#type' => 'markup',
            '#markup' => $newsroomjs,
        );
        drupal_add_html_head($script_code, 'newsroomjs');
    }
  if (!empty(FRONT_URL) && $base_url == FRONT_URL) {
    $add_script = variable_get('add_traffic_script');
    if ($add_script) {
      $script_js = variable_get('traffic_script_js');
      $script = array(
        '#tag' => 'script',
        '#attributes' => array('type' => 'text/javascript'),
        '#value' => $script_js,
      );
      drupal_add_html_head($script, 'script');
    }
  }
  if ($arg[0] == 'taxonomy' && is_numeric($arg[2])) {
    $term = menu_get_object('taxonomy_term', 2);
    if (!empty($term)) {
      $title = $term->metatags[LANGUAGE_NONE]['title']['value'];
      $vars['head_title'] = $title;
    }
  }
  
  if($arg[0] == 'magazine') {
      $vars['head_title'] = 'India Today Headlines Archive- Get News headlines by date | '.variable_get('site_name');
  }
  if($arg[0] == 'livetv' || $arg[0] == 'international-livetv') {
      $vars['head_title'] = 'India Today Live TV Online: Live TV News Streaming, Watch Live TV News | '.variable_get('site_name');
  }
  if($arg[0] == 'topic' && !empty($arg[1])) {
    $search_str = urldecode($arg[1]);
    $search_str = ucwords(str_replace("-", " ", $search_str));
    $search_str = preg_replace('/\s+/', ' ', $search_str);
    $vars['head_title'] = "$search_str News, Videos, Photos and Magazine Stories | " . variable_get('site_name');
  }
  if ($arg[0] == 'event' && !empty($arg[3]) && in_array($arg[3], array('programme', 'speakers', 'sponsors', 'flashback', 'speaker-details', 'sponsor-details', 'sing-and-win'))) {
    $event_nid = itg_event_backend_get_event_node();
    $event_tags = get_node_metatags_by_nid($event_nid);
    $event_tags = unserialize($event_tags['data']);
    if (!empty($event_tags['title']['value'])) {
      $vars['head_title'] = $event_tags['title']['value'] . ' | ' . variable_get('site_name');
    }
  }
  if ($arg[0] == 'node' && is_numeric($arg[1])) {
    $node_event = menu_get_object();
    if (!empty($node_event->metatags[LANGUAGE_NONE]['title']['value'])) {
      $vars['head_title'] = $node_event->metatags[LANGUAGE_NONE]['title']['value'] . ' | ' . variable_get('site_name');
    }
  }
  if (!empty(FRONT_URL) && $base_url == FRONT_URL && $arg[0] == 'elections' && ($arg[2] == 'constituency-map' || $arg[2] == 'constituency')) {
    
      $section_alias = $arg[0];
      $category_alias = $arg[1];
      $path_dest = drupal_lookup_path('source', $section_alias.'/'.$category_alias);

      if(empty($path_dest)){
        drupal_not_found();
      }
      $tax_data = explode('/', $path_dest);  
      if($tax_data[0] != 'taxonomy' || empty($tax_data[2]) || !is_numeric($tax_data[2])){
        drupal_not_found();
      }

      $get_election_nid = itg_get_election_nid($tax_data[2]);
      $entity_id = $get_election_nid['entity_id'];
      $content = node_load($entity_id);
      if ($arg[2] == 'constituency-map') {
        $vars['head_title'] = trim($content->field_constituency_title[LANGUAGE_NONE][0]['value']);
        $keyword = trim($content->field_constituency_keyword[LANGUAGE_NONE][0]['value']);
        $description = trim($content->field_constituency_description[LANGUAGE_NONE][0]['value']);
      } elseif ($arg[2] == 'constituency') {
        $constituency_str = ($arg[3]) ? $arg[3] : '';
        $constituency_arr = explode('-', $constituency_str);  
        $vars['head_title'] = str_replace('<Constituency Name>', ucfirst($constituency_arr[0]), trim($content->field_constituency_result_title[LANGUAGE_NONE][0]['value']));
        $keyword = str_replace('<Constituency Name>', ucfirst($constituency_arr[0]), trim($content->field_constituency_result_keywor[LANGUAGE_NONE][0]['value']));
        $description = str_replace('<Constituency Name>', ucfirst($constituency_arr[0]), trim($content->field_constituency_result_descri[LANGUAGE_NONE][0]['value']));
      }
 
      $html_head = array(
       'description' => array(
         '#tag' => 'meta',
         '#attributes' => array(
           'name' => 'description',
           'content' => $description,
         ),
       ),
       'news_keywords' => array(
         '#tag' => 'meta',
         '#attributes' => array(
           'name' => 'news_keywords',
           'content' => $keyword,
         ),
       ),
     );
     foreach ($html_head as $key => $data) {
       drupal_add_html_head($data, $key);
     }
    
  }
 } 
}

/**
 * page head alter for update the meta keywords
 */
function itg_html_head_alter(&$head_elements) {
  $arg = arg();
  global $base_url;
  
  if ($arg[0] == 'custom-search') {
    $head_elements['nofollow'] = array(
      '#tag' => 'meta',
      '#type' => 'html_tag',
      '#attributes' => array(
        'name' => 'robots',
        'content' => 'nofollow'
      )
    );

    $head_elements['noindex_nofollow'] = array(
      '#tag' => 'meta',
      '#type' => 'html_tag',
      '#attributes' => array(
        'name' => 'robots',
        'content' => 'noindex'
      )
    );
  }
  // canonical for home page
  if ($arg[0] == 'node' && is_numeric($arg[1])) {
    $node_event = menu_get_object();
    if (!empty($node_event->nid) && $node_event->type == "event_backend") {
      $event_canonical = FRONT_URL . $_SERVER['REQUEST_URI'];
      $head_elements['canonical_0'] = array(
        '#type' => 'html_tag',
        '#tag' => 'link',
        '#attributes' => array(
          'rel' => 'canonical',
          'href' => $event_canonical
        ),
      );
    }
  }
  if ($arg[0] == 'event' && !empty($arg[3]) && in_array($arg[3], array('programme', 'speakers', 'sponsors', 'flashback', 'speaker-details', 'sponsor-details', 'sing-and-win'))) {
    $event_nid = itg_event_backend_get_event_node();
    $event_tags = get_node_metatags_by_nid($event_nid);
    $event_tags = unserialize($event_tags['data']);
    if (!empty($event_tags['keywords']['value'])) {
      $head_elements['metatag_keywords_0'] = array(
        '#type' => 'html_tag',
        '#tag' => 'meta',
        '#attributes' => array(
          'name' => 'news_keywords',
          'content' => $event_tags['keywords']['value']
        ),
      );
    }
    if (!empty($event_tags['description']['value'])) {
      $head_elements['metatag_description_0'] = array(
        '#type' => 'html_tag',
        '#tag' => 'meta',
        '#attributes' => array(
          'name' => 'description',
          'content' => $event_tags['description']['value']
        ),
      );
    }
    $event_canonical = FRONT_URL . $_SERVER['REQUEST_URI'];
    $head_elements['canonical_0'] = array(
      '#type' => 'html_tag',
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'canonical',
        'href' => $event_canonical
      ),
    );
  }
  // canonical for home page
  if (drupal_is_front_page()) {
    $home_canonical = $base_url . '/';
    $head_elements['canonical_0'] = array(
      '#type' => 'html_tag',
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'canonical',
        'href' => $home_canonical
      ),
    );
  }
  // Updating meta name keywords to news_keyword sitewide
  $meta_name_keyword = array_keys($head_elements);
  if (in_array('metatag_keywords_0', $meta_name_keyword)) {
    $head_elements['metatag_keywords_0']['#name'] = 'news_keywords';
  }

  if ($arg[0] == 'taxonomy' && is_numeric($arg[2])) {
      $term = taxonomy_term_load($arg[2]);
      $term_url_alias = drupal_get_path_alias('taxonomy/term/'.$term->tid);
      $meta_keywords = $term->metatags[LANGUAGE_NONE]['keywords']['value'];
      if (!empty($meta_keywords)) {
        $head_elements['metatag_keywords_0'] = array(
          '#type' => 'html_tag',
          '#tag' => 'meta',
            
          '#attributes' => array(
            'name' => 'news_keywords',
            'content' => $meta_keywords
          ),
        );
      }
      $meta_description = $term->metatags[LANGUAGE_NONE]['description']['value'];
      if (isset($meta_description) && !empty($meta_description)) {
        $head_elements['metatag_description_0'] = array(
          '#type' => 'html_tag',
          '#tag' => 'meta',            
          '#attributes' => array(
            'name' => 'description',
            'content' => $meta_description
          ),
        );
      }

      if ($term->vid == CATEGORY_MANAGMENT) {

        if (!empty($term->field_cm_hide_cat_from_search[LANGUAGE_NONE]) && $term->field_cm_hide_cat_from_search[LANGUAGE_NONE][0]['value'] == 1) {
          if ($term->field_cm_no_follow[LANGUAGE_NONE][0]['value'] == 1) {
            $head_elements['nofollow'] = array(
              '#tag' => 'meta',
              '#type' => 'html_tag',
              '#attributes' => array(
                'name' => 'robots',
                'content' => 'nofollow'
              )
            );
          }
          if ($term->field_cm_no_follow[LANGUAGE_NONE][1]['value'] == 2) {
            $head_elements['noindex_nofollow'] = array(
              '#tag' => 'meta',
              '#type' => 'html_tag',
              '#attributes' => array(
                'name' => 'robots',
                'content' => 'noindex'
              )
            );
          }
          if ($term->field_cm_no_follow[LANGUAGE_NONE][0]['value'] == 2) {
            $head_elements['noindex_nofollow'] = array(
              '#tag' => 'meta',
              '#type' => 'html_tag',
              '#attributes' => array(
                'name' => 'robots',
                'content' => 'noindex'
              )
            );
          }
        }
        // Add canonical for taxonomy page:
        $head_elements['canonical_0'] = array(
          '#type' => 'html_tag',
          '#tag' => 'link',
          '#attributes' => array(
            'rel' => 'canonical',
            'href' => FRONT_URL.'/'.$term_url_alias
          ),
        );
      }
    }
  /*
  if ($default_mobile_metatags) {
    $head_elements['viewport'] = array(
      '#tag' => 'meta',
      '#type' => 'html_tag',
      '#attributes' => array(
        'name' => 'viewport',
        'content' => 'width=device-width, minimum-scale=1, initial-scale=1.0, maximum-scale=1.0, user-scalable=no'
      ),
      '#weight' => -980,
    );
  }*/
  unset($head_elements['system_meta_content_type']);
  $head_elements['metatag_description_0']['#weight'] = -1000;
  $head_elements['metatag_keywords_0']['#weight'] = -999;
  $head_elements['og_locale']['#weight'] = -997;
  $head_elements['og_sitename']['#weight'] = -996;
  $head_elements['twitter_tag2']['#weight'] = -995;
  $head_elements['twitter_tag3']['#weight'] = -994;
  $head_elements['twitter_tag1']['#weight'] = -993;
  $head_elements['twitter_tag0']['#weight'] = -992;
  $head_elements['twitter_tag4']['#weight'] = -991;
  $head_elements['fb_og_type']['#weight'] = -990;
  $head_elements['og_description']['#weight'] = -989;
  $head_elements['fb_og_title']['#weight'] = -988;
  $head_elements['fb_og_url']['#weight'] = -987;
  $head_elements['twitter_tag5']['#weight'] = -986;
  $head_elements['system_meta_generator']['#weight'] = -985;
  $head_elements['twitter_tag5']['#weight'] = -984;
  $head_elements['fia_pagesid']['#weight'] = -983;
  $head_elements['og_publish_time']['#weight'] = -982;
  $head_elements['metatag_generator_0']['#weight'] = -981;
  $head_elements['og_image_type']['#weight'] = -979;
  $head_elements['og_image_height']['#weight'] = -978;
  $head_elements['og_image_width']['#weight'] = -977;
  $head_elements['og_image']['#weight'] = -976;
  $head_elements['canonical_0']['#weight'] = -1001;
  $status = drupal_get_http_header("status");
  if ($status === '404 Not Found'){
	unset($head_elements['metatag_canonical']);
  }
}

/**
 * Implementation of theme_link().
 * {@inheritdoc}
 * @param array $variables
 * @return string
 */
function itg_link($variables) {
  $url_path = $variables['path'];
  // If internal url is used.
  if ((isset($url_path)) && (strpos($url_path, 'node/') !== FALSE)) {
    $node_path = explode('/', $url_path);
    $nid = $node_path[1];
    if (_is_sponsor_story_article($nid)) {
      $variables['options']['attributes']['rel'] = 'nofollow';
      $variables['options']['attributes']['target'] = '_blank';
      $variables['options']['attributes']['class'][] = 'itg-sponsored';
    }
  }
  // If url alias is used.
  elseif ((isset($url_path)) && (strpos(drupal_get_normal_path($url_path), 'node/') !== FALSE)) {
    $normal_path = drupal_get_normal_path($url_path);
    $node_path = explode('/', $normal_path);
    $nid = $node_path[1];
    if (_is_sponsor_story_article($nid)) {
      $variables['options']['attributes']['rel'] = 'nofollow';
      $variables['options']['attributes']['target'] = '_blank';
      $variables['options']['attributes']['class'][] = 'itg-sponsored';
    }
  }
  // If url is used with base url.
  elseif ((isset($url_path)) && (strpos(_get_int_path_from_url($url_path), 'node/') !== FALSE)) {
    $normal_path = _get_int_path_from_url($url_path);
    $node_path = explode('/', $normal_path);
    $nid = $node_path[1];
    if (_is_sponsor_story_article($nid)) {
      $variables['options']['attributes']['rel'] = 'nofollow';
      $variables['options']['attributes']['target'] = '_blank';
      $variables['options']['attributes']['class'][] = 'itg-sponsored';
    }
  }
  // If External url is used.
  if ((isset($url_path)) && (strpos($url_path, 'node/') !== FALSE)) {
    $node_path = explode('/', $url_path);
    $nid = $node_path[1];
    if ($external_url = _is_external_url_story_article($nid)) {
      global $base_url;
      $link_target = '_self';
      $baseurl = preg_replace('#^https?://#', '', $base_url);
      $baseurl = preg_replace('#^http?://#', '', $baseurl);
      if (strpos($external_url, $baseurl) === false) {
        $link_target = '_blank';
        $variables['options']['attributes']['rel'] = 'nofollow';
      }
      $variables['path'] = $external_url;
      $variables['options']['attributes']['target'] = $link_target;
    }
  }
  return '<a href="' . check_plain(url($variables['path'], $variables['options'])) . '"' . drupal_attributes($variables['options']['attributes']) . '>' . ($variables['options']['html'] ? $variables['text'] : check_plain($variables['text'])) . '</a>';
  return '<a href="' . check_plain(url($variables['path'], $variables['options'])) . '"' . drupal_attributes($variables['options']['attributes']) . '>' . ($variables['options']['html'] ? $variables['text'] : check_plain($variables['text'])) . '</a>';
}

/**
 * Implementation of hook_js_alter().
 * {@inheritdoc}
 * @param array $variables
 * @return string
 */
function itg_js_alter(&$javascript) {
  
  unset($javascript['sites/all/modules/custom/itg_common/js/itg_common_admin_form.js']);
  unset($javascript['sites/all/modules/custom/itg_image_croping/js/jquery.cropit.js']);
  unset($javascript['sites/all/modules/custom/itg_image_croping/js/imagecroping.js']);
  unset($javascript['sites/all/modules/custom/itg_image_search/js/imagesearch.js']);
  
  if (drupal_is_front_page()) {
    unset($javascript['sites/all/libraries/colorbox/jquery.colorbox-min.js']);
    unset($javascript['sites/all/modules/contrib/colorbox/js/colorbox.js']);
    unset($javascript['sites/all/modules/contrib/colorbox/styles/default/colorbox_style.js']);
    unset($javascript['sites/all/modules/contrib/colorbox/js/colorbox_load.js']);
    unset($javascript['sites/all/modules/contrib/colorbox/js/colorbox_inline.js']);
    
    //remove some js in footer for home page
    $javascript['misc/jquery.once.js']['scope'] = 'footer';
    $javascript['sites/all/modules/contrib/jquery_update/replace/ui/external/jquery.cookie.js']['scope'] = 'footer';
    $javascript['sites/all/modules/contrib/jquery_update/replace/misc/jquery.form.min.js']['scope'] = 'footer';
    $javascript['misc/ajax.js']['scope'] = 'footer';
    $javascript['sites/all/modules/contrib/jquery_update/js/jquery_update.js']['scope'] = 'footer';
    $javascript['misc/progress.js']['scope'] = 'footer';
    
  }  

  //remove some js in footer for all front page    
  $javascript['sites/all/themes/itg/js/script.js']['scope'] = 'footer';
  $javascript['sites/all/themes/itg/js/slick.js']['scope'] = 'footer';
  $javascript['sites/all/themes/itg/js/jquery.liMarquee.js']['scope'] = 'footer';
  $javascript['sites/all/themes/itg/js/ripple.js']['scope'] = 'footer';  
  $javascript['sites/all/themes/itg/js/jquery.mCustomScrollbar.concat.min.js']['scope'] = 'footer';
  $javascript['sites/all/themes/itg/js/stickyMojo.js']['scope'] = 'footer';
  $javascript['sites/all/themes/itg/js/ion.rangeSlider.js']['scope'] = 'footer';  
  $javascript['sites/all/modules/contrib/google_analytics/googleanalytics.js']['scope'] = 'footer';
  $javascript['sites/all/modules/contrib/google_analytics_et/js/google_analytics_et.js']['scope'] = 'footer';

}

/**
* Implementation of hook_css_alter().
* {@inheritdoc}
* @param array $variables
* @return string
*/
function itg_css_alter(&$css) {
   global $user;
   $type = '';
   if (arg(0) == 'node') {
     $node = menu_get_object();
     $type = $node->type;
   }
   $exclude = array(
     // Contrib CSS
     'modules/system/system.base.css' => FALSE,
     'modules/comment/comment.css' => FALSE,
     'sites/all/modules/contrib/date/date_api/date.css' => FALSE,
     'sites/all/modules/contrib/date/date_popup/themes/datepicker.1.7.css' => FALSE,
     'sites/all/modules/contrib/logintoboggan/logintoboggan.css' => FALSE,
     'modules/node/node.css' => FALSE,
     'modules/search/search.css' => FALSE,
     'modules/user/user.css' => FALSE,
     'sites/all/modules/contrib/youtube/css/youtube.css' => FALSE,
     'sites/all/modules/contrib/views/css/views.css' => FALSE,
     'sites/all/modules/contrib/ckeditor/css/ckeditor.css' => FALSE,
     'sites/all/modules/contrib/colorbox/styles/default/colorbox_style.css' => FALSE,
     'sites/all/modules/contrib/ctools/css/ctools.css' => FALSE,
     'sites/all/modules/custom/itg_akamai_block_refresh/css/itg_akamai_block_refresh.css' => FALSE,
   );
   // Exclude unnecessary CSS for anonymous users.
   if (($user->uid == 0) && ((drupal_is_front_page()) || $type == 'story')) {
     $css = array_diff_key($css, $exclude);
   }
}

function itg_image($variables) {
  $attributes = $variables['attributes'];
  // unset done for seo validation.
  unset($attributes['typeof']);
  $attributes['src'] = file_create_url($variables['path']);
  
  $attributes['width'] = !empty($variables['width']) ? $variables['width'] : " ";
  $attributes['alt'] = !empty($variables['alt']) ? $variables['alt'] : " ";
  $attributes['title'] = !empty($variables['title']) ? $variables['title'] : " ";
  $attributes['height'] = !empty($variables['height']) ? $variables['height'] : " ";

  return '<img' . drupal_attributes($attributes) . ' />';
}

/**
 * Get newsroom js ad code
 */ 
function get_newsroom_js(){
	if(drupal_is_front_page()){
		return <<<jscode
	<!-- NEWSROOM SCRIPT -->
<script>
window._newsroom = window._newsroom || [];
window._newsroom.push({pageTemplate: 'home'});
window._newsroom.push({pageDashboard: 'home-mobile'});
window._newsroom.push('auditClicks');
window._newsroom.push('trackPage');

!function (e, f, u) {
	e.async = 1;
	e.src = u;
	f.parentNode.insertBefore(e, f);
}(document.createElement('script'),
		document.getElementsByTagName('script')[0], '//c2.taboola.com/nr/indiatoday-indiatoday/newsroom.js');
</script>
<!-- END NEWSROOM SCRIPT -->
jscode;
	}else{
		return <<<jscode
		<!-- NEWSROOM SCRIPT -->
<script>
    window._newsroom = window._newsroom || [];
 
    !function (e, f, u) {
        e.async = 1;
        e.src = u;
        f.parentNode.insertBefore(e, f);
    }(document.createElement('script'),
            document.getElementsByTagName('script')[0], '//c2.taboola.com/nr/indiatoday-indiatoday/newsroom.js');
</script>
<!-- END NEWSROOM SCRIPT -->
jscode;
	}
}

/**
 * Get newsroom js ad code
 */
function get_newsroom_screcard_js(){
    return <<<jscode
		<!-- Scorecard NEWSROOM SCRIPT -->
<script type="text/javascript">
  window._taboola = window._taboola || [];
  _taboola.push({article:'auto'});
  !function (e, f, u, i) {
    if (!document.getElementById(i)){
      e.async = 1;
      e.src = u;
      e.id = i;
      f.parentNode.insertBefore(e, f);
    }
  }(document.createElement('script'),
  document.getElementsByTagName('script')[0],
  '//cdn.taboola.com/libtrc/indiatoday-indiatoday/loader.js',
  'tb_loader_script');
  if(window.performance && typeof window.performance.mark == 'function')
    {window.performance.mark('tbl_ic');}
</script>
<!-- END Scorecard NEWSROOM SCRIPT -->
jscode;
}

/**
 * Function for add chart beat js code
 */
function itgd_chart_beat_code() {
  global $base_url;
  $chart_sections = '';
  $chart_authors = '';
  $chart_title = '';
  $chart_path = $base_url;
  $chart_js = '//static.chartbeat.com/js/chartbeat.js';
  $node = menu_get_object('node');
  if (!drupal_is_front_page() && isset($node) && !empty($node)) {
    if (!empty($node->field_primary_category[LANGUAGE_NONE][0]['value']) && !empty($node->field_story_category['und'])) {
      $primary_cat = $node->field_primary_category[LANGUAGE_NONE][0]['value'];
      $section_tids = array_reverse(taxonomy_get_parents_all($primary_cat));
      $chart_sections = $section_tids[0]->name;
    }
    if (isset($node->field_reporter_publish_id[LANGUAGE_NONE][0]['value'])) {
      $get_authors_name = $node->field_reporter_publish_id[LANGUAGE_NONE][0]['value'];
    }
    $auths_name = '';
    if (!empty($get_authors_name)) {
      $auths_name = itg_get_story_authors_name($get_authors_name) . ',';
    }
    $chart_authors = $auths_name . 'Edited by ' . itg_get_story_edited_authors_name($node->uid);
    $chart_title = str_replace("'", "", $node->title);
    $chart_path = drupal_get_path_alias('node/' . $node->nid);
    $chart_path = '/' . $chart_path;
    if ($node->type == 'videogallery') {
      $chart_js = '//static.chartbeat.com/js/chartbeat_video.js';
    }
    
    if ($node->type == 'photogallery') {
      drupal_add_js('function EmbedScript() {
        var _Impulser = window.parent.document.createElement("script"); _Impulser.type = "text/javascript";
        _Impulser.async = true;
        _Impulser.src = ("https:" == window.parent.document.location.protocol ? "https://" : "http://") + "impulse.forkcdn.com/impulse3/config/impulse.js";
        var _scripter = window.parent.document.getElementsByTagName("script")[0]; _scripter.parentNode.insertBefore(_Impulser, _scripter);
        };
        function inIframe() {
            try {
                return window.self !== window.top;
            } catch (e) {
                return true;
            }
        }
        if (inIframe()) {
            window.parent.$ImpulseID = "IMPL-ITDG-INDIATODAY-RESP-GENERIC"; EmbedScript();
        } else {
            $ImpulseID = "IMPL-ITDG-INDIATODAY-RESP-GENERIC"; EmbedScript();
        }', array('type' => 'inline', 'scope' => 'footer'));
    }

    if ($node->type == 'story') {
      drupal_add_js('!function(a,n,e,t,r){tagsync=e;var c=window[a];if(tagsync){var d=document.createElement("script");d.src="https://821.tm.zedo.com/v1/7217327e-2fc7-4b32-bd53-1c943009b4ca/atm.js",d.async=!0;var i=document.getElementById(n);if(null==i||"undefined"==i)return;i.parentNode.appendChild(d,i),d.onload=d.onreadystatechange=function(){var a=new zTagManager(n);a.initTagManager(n,c,this.aync,t,r)}}else document.write("<script src=\'https://821.tm.zedo.com/v1/7217327e-2fc7-4b32-bd53-1c943009b4ca/tm.js?data="+a+"\'><\/script>")}("datalayer","z61b6b10d-8ff4-41e3-b8b0-c46bf2be1e7e",true, 1 , 1);', array('type' => 'inline', 'scope' => 'footer'));
      drupal_add_js('var unruly = window.unruly || {};
					unruly.native = unruly.native || {};
					unruly.native.siteId = 321603', array('type' => 'inline', 'scope' => 'footer'));
	  drupal_add_js('//video.unrulymedia.com/native/native-loader.js', array('type' => 'external', 'scope' => 'footer'));
    //Forkmedia ad code
    drupal_add_js('function EmbedScript() {
        var _Impulser = window.parent.document.createElement("script"); _Impulser.type = "text/javascript";
        _Impulser.async = true;
        _Impulser.src = ("https:" == window.parent.document.location.protocol ? "https://" : "http://") + "impulse.forkcdn.com/impulse3/config/impulse.js";
        var _scripter = window.parent.document.getElementsByTagName("script")[0]; _scripter.parentNode.insertBefore(_Impulser, _scripter);
        };
        function inIframe() {
            try {
                return window.self !== window.top;
            } catch (e) {
                return true;
            }
        }
        if (inIframe()) {
            window.parent.$ImpulseID = "IMPL-ITDG-INDIATODAY-RESP-GENERIC"; EmbedScript();
        } else {
            $ImpulseID = "IMPL-ITDG-INDIATODAY-RESP-GENERIC"; EmbedScript();
        }', array('type' => 'inline', 'scope' => 'footer'));    
    }
    drupal_add_js("var _sf_async_config = _sf_async_config || {};
      /** CONFIGURATION START **/
    _sf_async_config.uid = 60355;
    _sf_async_config.domain = 'indiatoday.in';
    _sf_async_config.useCanonical = true;
    _sf_async_config.sections = '" . $chart_sections . "';  
    _sf_async_config.authors = '" . $chart_authors . "';    
	_sf_async_config.title = '" . $chart_title . "';
	_sf_async_config.path = '" . $chart_path . "';
    /** CONFIGURATION END **/
     (function () {
          function loadChartbeat() { 
               window._sf_endpt = (new Date()).getTime();
               var e = document.createElement('script');
               e.setAttribute('language', 'javascript');
               e.setAttribute('type', 'text/javascript');
               e.setAttribute('src', '" . $chart_js . "');
               document.body.appendChild(e);
          }
          var oldonload = window.onload;
        window.onload = (typeof window.onload != 'function') ?
            loadChartbeat : function() {
                oldonload();
                loadChartbeat();
            };	  
		  
     })();", array('type' => 'inline', 'scope' => 'footer'));
  } else {
  drupal_add_js("var _sf_async_config = _sf_async_config || {};
      /** CONFIGURATION START **/
    _sf_async_config.uid = 60355;
    _sf_async_config.domain = 'indiatoday.in';
    _sf_async_config.useCanonical = true;
    _sf_async_config.sections = '" . $chart_sections . "';  
    _sf_async_config.authors = '" . $chart_authors . "';
    /** CONFIGURATION END **/
     (function () {
          function loadChartbeat() { 
               window._sf_endpt = (new Date()).getTime();
               var e = document.createElement('script');
               e.setAttribute('language', 'javascript');
               e.setAttribute('type', 'text/javascript');
               e.setAttribute('src', '" . $chart_js . "');
               document.body.appendChild(e);
          }
          var oldonload = window.onload;
        window.onload = (typeof window.onload != 'function') ?
            loadChartbeat : function() {
                oldonload();
                loadChartbeat();
            };	  
		  
     })();", array('type' => 'inline', 'scope' => 'footer'));
  }
}
