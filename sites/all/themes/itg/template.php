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
  return $items;
}

/**
 * Hide read more link from front page
 * {@inheritdoc}
 */
function itg_preprocess_node(&$variables) {
  $node = $variables['node'];
  unset($variables['content']['links']['node']['#links']['node-readmore']);
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
    if (function_exists('global_comment_last_record')) {
      $variables['global_comment_last_record'] = global_comment_last_record();
    }
  }

  if ($variables['type'] == 'webform') {
    unset($variables['submitted']);
    //$variables['submitted'] = t('Submitted by !username on !datetime', array('!username' => $variables['name'], '!datetime' => $variables['date']));
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
  //unset($variables['page']['content']);
  // add condition to hide header and footer for signup, forgot-password page
  if (isset($_GET['ReturnTo']) && !empty($_GET['ReturnTo'])) {
    $variables['theme_hook_suggestions'][] = 'page__removeheader';
  }

  if ((!empty($arg[2]) && $arg[2] == 'ugc') || $arg[0] == 'signup' || $arg[0] == 'forgot-password' || $arg[0] == 'sso-user' || $arg[0] == 'sso' || $arg[0] == 'password-success' || $arg[0] == 'complete-page' || $arg[0] == 'associate-photo-video-content' || $arg[0] == 'funalytics-popup' || $arg[1] == 'videogallery-embed') {
    $variables['theme_hook_suggestions'][] = 'page__removeheader';
  }

  if ($arg[0] == 'photogallery-embed' || $arg[0] == 'videogallery-embed') {
    $variables['theme_hook_suggestions'][] = 'page__itgembed';
  }
  
    
  // For single column page
  if ($arg[0] == 'be-lucky-today') {
    $variables['theme_hook_suggestions'][] = 'page__singlecolumn';
  }

  // Access domain
  if (function_exists('domain_select_format')) {
    $format = domain_select_format();
    foreach (domain_domains() as $data) {
      if ($data['valid'] || user_access('access inactive domains')) {
        $options[$data['domain_id']] = empty($format) ? check_plain($data['sitename']) : $data['sitename'];
      }
    }

    // Add another page.tpl file for existing domains
    $parse = parse_url($base_url);

    // Call Event Parent TPL
    if (in_array($parse['host'], $options)) {
      $variables['theme_hook_suggestions'][] = 'page__event_domain';
    }
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
    //pr($variables['theme_hook_suggestions']);
    $variables['theme_hook_suggestions'][] = 'page__itg_blog_page';
  }

  $progarm_cat_id = variable_get('program_category_id_for_programmes');

  if ($arg[0] == 'taxonomy' && $arg[1] == 'term' && $arg[2] == $progarm_cat_id) {
    $variables['theme_hook_suggestions'][] = 'page__taxonomy_term_program';
  }
}

/**
 * {@inheritdoc}
 */
function itg_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  $crumbs = '';
  if (!empty($breadcrumb) && arg(0) == 'topic') {
    $crumbs = '<div id="breadcrumbs"><ul><li></li>';
    foreach ($breadcrumb as $value) {
      $crumbs .= '<li>' . $value . '</li>';
    }

    if (arg(0) == 'topic') {
      if (!empty($_GET['keyword'])) {
        $keyword = '<li>' . $_GET['keyword'] . '</li>';
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
  global $base_url, $user;
  if ($base_url == BACKEND_URL && !empty($user->uid)) {
    $vars['classes_array'][] = 'pointer-event-none';
  }
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

  // Code ends for adding header, body start, body close for ads module
}

/**
 * page head alter for update the meta keywords
 */
function itg_html_head_alter(&$head_elements) {
  $arg = arg();
  global $base_url;
  if (!empty(arg(1)) && is_numeric(arg(1))) {
    $arg_data = node_load(arg(1));
    if ($arg_data->type == 'videogallery') {
      if (is_array($arg_data->field_video_configurations[LANGUAGE_NONE]) && !empty($arg_data->field_video_configurations[LANGUAGE_NONE])) {
        $configurableopt = $arg_data->field_video_configurations[LANGUAGE_NONE];
        foreach ($configurableopt as $key => $value) {
          $opt_value[] = $value['value'];
        }
        if (in_array("google_standout", $opt_value)) {
          $standout_path = $base_url . '/' . $arg_data->path['alias'];
          $head_elements['google_standout'] = array(
            '#type' => 'html_tag',
            '#tag' => 'link',
            '#attributes' => array('rel' => 'standout', 'href' => $standout_path),
          );
        }
      }
    }
    else if ($arg_data->type == 'photogallery') {
      if (is_array($arg_data->field_photogallery_configuration[LANGUAGE_NONE]) && !empty($arg_data->field_photogallery_configuration[LANGUAGE_NONE])) {
        $configurableopt = $arg_data->field_photogallery_configuration[LANGUAGE_NONE];
        foreach ($configurableopt as $key => $value) {
          $opt_value[] = $value['value'];
        }
        if (in_array("google_standout", $opt_value)) {
          $standout_path = $base_url . '/' . $arg_data->path['alias'];
          $head_elements['google_standout'] = array(
            '#type' => 'html_tag',
            '#tag' => 'link',
            '#attributes' => array('rel' => 'standout', 'href' => $standout_path),
          );
        }
      }
    }
    else if ($arg_data->type == 'podcast') {
      if (is_array($arg_data->field_podcast_configuration[LANGUAGE_NONE]) && !empty($arg_data->field_podcast_configuration[LANGUAGE_NONE])) {
        $configurableopt = $arg_data->field_podcast_configuration[LANGUAGE_NONE];
        foreach ($configurableopt as $key => $value) {
          $opt_value[] = $value['value'];
        }
        if (in_array("google_standout", $opt_value)) {
          $standout_path = $base_url . '/' . $arg_data->path['alias'];
          $head_elements['google_standout'] = array(
            '#type' => 'html_tag',
            '#tag' => 'link',
            '#attributes' => array('rel' => 'standout', 'href' => $standout_path),
          );
        }
      }
    }
    else if ($arg_data->type == 'story') {
      if (is_array($arg_data->field_story_configurations[LANGUAGE_NONE]) && !empty($arg_data->field_story_configurations[LANGUAGE_NONE])) {
        $configurableopt = $arg_data->field_story_configurations[LANGUAGE_NONE];
        foreach ($configurableopt as $key => $value) {
          $opt_value[] = $value['value'];
        }
        if (in_array("google_standout", $opt_value)) {
          $standout_path = $base_url . '/' . $arg_data->path['alias'];
          $head_elements['google_standout'] = array(
            '#type' => 'html_tag',
            '#tag' => 'link',
            '#attributes' => array('rel' => 'standout', 'href' => $standout_path),
          );
        }
      }
    }
  }
  // Updating meta name keywords to news_keyword sitewide
  $meta_name_keyword = array_keys($head_elements);
  if (in_array('metatag_keywords_0', $meta_name_keyword)) {
    $head_elements['metatag_keywords_0']['#name'] = 'news_keyword';
  }
  else {
    if ($arg[0] == 'node' && is_numeric($arg[1])) {
      $node = node_load($arg[1]);
      $meta_keywords = isset($node->metatags[LANGUAGE_NONE]['keywords']['value']) ? $node->metatags[LANGUAGE_NONE]['keywords']['value'] : '';
      if (!empty($meta_keywords)) {
        $head_elements['metatag_keywords_0'] = array(
          '#type' => 'html_tag',
          '#tag' => 'meta',
          '#attributes' => array(
            'name' => 'news_keyword',
            'content' => $meta_keywords
          ),
        );
      }
    }
    elseif ($arg[0] == 'taxonomy' && is_numeric($arg[2])) {
      $term = taxonomy_term_load($arg[2]);
      $meta_keywords = $term->metatags[LANGUAGE_NONE]['keywords']['value'];
      if (!empty($meta_keywords)) {
        $head_elements['metatag_keywords_0'] = array(
          '#type' => 'html_tag',
          '#tag' => 'meta',
          '#attributes' => array(
            'name' => 'news_keyword',
            'content' => $meta_keywords
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
      }
    }
  }
}

/**
 * @param array $variables
 * @return string
 */
function itg_link($variables) {
  $url_path = $variables['path'];
  // If internal url is used.
  if ((isset($url_path)) && (strpos($url_path, 'node/') !== FALSE)) {
    $node_path = explode('/', $url_path);
    $nid = $node_path[1];
    if(_is_sponsor_story_article($nid)){
      $variables['options']['attributes']['rel'] = 'nofollow';
      $variables['options']['attributes']['target'] = '_blank';
      $variables['options']['attributes']['class'][] = 'itg-sponsored';
    }    
  }
  // If url alias is used.
  elseif((isset($url_path)) && (strpos(drupal_get_normal_path($url_path), 'node/' ) !== FALSE)){
    $normal_path = drupal_get_normal_path($url_path);
    $node_path = explode('/', $normal_path);
    $nid = $node_path[1];
    if(_is_sponsor_story_article($nid)){
      $variables['options']['attributes']['rel'] = 'nofollow';
      $variables['options']['attributes']['target'] = '_blank';
      $variables['options']['attributes']['class'][] = 'itg-sponsored';
    }
  }
  // If url is used with base url.
  elseif((isset($url_path)) && (strpos(_get_int_path_from_url($url_path), 'node/' ) !== FALSE)){
    $normal_path = _get_int_path_from_url($url_path);
    $node_path = explode('/', $normal_path);
    $nid = $node_path[1];
    if(_is_sponsor_story_article($nid)){
      $variables['options']['attributes']['rel'] = 'nofollow';
      $variables['options']['attributes']['target'] = '_blank';
      $variables['options']['attributes']['class'][] = 'itg-sponsored';
    }
  }
  return '<a href="' . check_plain(url($variables['path'], $variables['options'])) . '"' . drupal_attributes($variables['options']['attributes']) . '>' . ($variables['options']['html'] ? $variables['text'] : check_plain($variables['text'])) . '</a>';return '<a href="' . check_plain(url($variables['path'], $variables['options'])) . '"' . drupal_attributes($variables['options']['attributes']) . '>' . ($variables['options']['html'] ? $variables['text'] : check_plain($variables['text'])) . '</a>';
}
  