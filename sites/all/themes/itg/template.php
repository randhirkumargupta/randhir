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
  unset($variables['content']['links']['node']['#links']['node-readmore']);
}

/**
 * Change comment date format
 * {@inheritdoc}
 */
function itg_preprocess_comment(&$variables) {
  $comment = $variables['elements']['#comment'];
  $node = $variables['elements']['#node'];
  if ($node->type == 'story' || $node->type == 'blog') {
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
  global $base_url; $base_root;
  $arg = arg();
  if ($arg[0] == 'taxonomy' && $arg[1] == 'term') {
    $term = taxonomy_term_load($arg[2]);
    if ($term->vocabulary_machine_name = 'category_management') {
      // remove the extra vocavolary information on page buttom.
      unset($variables['page']['content']['system_main']);
    }
  }
  
  // add condition to hide header and footer for signup, forgot-password page
  if (isset($_GET['ReturnTo']) && !empty($_GET['ReturnTo'])) {
    $variables['theme_hook_suggestions'][] = 'page__removeheader';
  }
  
  if ($arg[0] == 'signup' || $arg[0] == 'forgot-password') {
    $variables['theme_hook_suggestions'][] = 'page__removeheader';
  }
  
  // Access domain
  $format = domain_select_format();
  foreach (domain_domains() as $data) {
    if ($data['valid'] || user_access('access inactive domains')) {
      $options[$data['domain_id']] = empty($format) ? check_plain($data['sitename']) : $data['sitename'];
    }
  }
  
  // Add another page.tpl file for existing domains
  $parse = parse_url($base_url);

  if(in_array($parse['host'], $options)){
    $variables['theme_hook_suggestions'][] = 'page__event_domain';
  }
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

