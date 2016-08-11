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

    $variables['submitted'] = t('Submitted by !username on !datetime', array('!username' => $variables['author'], '!datetime' => $variables['created']));
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
  $arg = arg();
  if ($arg[0] == 'taxonomy' && $arg[1] == 'term') {
    $term = taxonomy_term_load($arg[2]);
    if ($term->vocabulary_machine_name = 'category_management') {
      // remove the extra vocavolary information on page buttom.
      unset($variables['page']['content']['system_main']);
    }
  }
}
