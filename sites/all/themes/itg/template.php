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

  // add condition to hide header and footer for signup, forgot-password page
  if (isset($_GET['ReturnTo']) && !empty($_GET['ReturnTo'])) {
    $variables['theme_hook_suggestions'][] = 'page__removeheader';
  }

  if ((!empty($arg[2]) && $arg[2] == 'ugc') || $arg[0] == 'signup' || $arg[0] == 'forgot-password' || $arg[0] == 'sso-user' || $arg[0] == 'sso' || $arg[0] == 'password-success' || $arg[0] == 'complete-page' || $arg[0] == 'associate-photo-video-content') {
    $variables['theme_hook_suggestions'][] = 'page__removeheader';
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


  // Code started for adding header , body start , body close for ads module
  $ads_code = get_header_body_start_end_code();
  foreach ($ads_code as $ads_key => $ads_chunk) {
    $code = implode(' ', $ads_chunk);
    $script_code = array(
      '#type' => 'markup',
      '#markup' => $code,
    );
    drupal_add_html_head($script_code, $ads_key);
  }
  // Code ends for adding header, body start, body close for ads module
}

/**
 * {@inheritdoc}
 */
function itg_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  $crumbs = '';
  if (!empty($breadcrumb) && arg(0) == 'site-search') {
    $crumbs = '<div id="breadcrumbs"><ul><li></li>';
    foreach ($breadcrumb as $value) {
      $crumbs .= '<li>' . $value . '</li>';
    }

    if (arg(0) == 'site-search') {
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
