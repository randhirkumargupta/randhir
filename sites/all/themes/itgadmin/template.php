<?php

/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */
/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
/* -- Delete this line if you want to use this function
  function itgadmin_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  itgadmin_preprocess_html($variables, $hook);
  itgadmin_preprocess_page($variables, $hook);
  }
  // */

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
/* -- Delete this line if you want to use this function
  function itgadmin_preprocess_html(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // The body tag's classes are controlled by the $classes_array variable. To
  // remove a class from $classes_array, use array_diff().
  //$variables['classes_array'] = array_diff($variables['classes_array'], array('class-to-remove'));
  }
  // */

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
/* -- Delete this line if you want to use this function
  function itgadmin_preprocess_page(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
  }
  // */

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
/* -- Delete this line if you want to use this function
  function itgadmin_preprocess_node(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // Optionally, run node-type-specific preprocess functions, like
  // itgadmin_preprocess_node_page() or itgadmin_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
  $function($variables, $hook);
  }
  }
  // */

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
  function itgadmin_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
  }
  // */

/**
 * Override or insert variables into the region templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
/* -- Delete this line if you want to use this function
  function itgadmin_preprocess_region(&$variables, $hook) {
  // Don't use Zen's region--sidebar.tpl.php template for sidebars.
  //if (strpos($variables['region'], 'sidebar_') === 0) {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('region__sidebar'));
  //}
  }
  // */

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
  function itgadmin_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  // $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  //if ($variables['block_html_id'] == 'block-system-main') {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('block__no_wrapper'));
  //}
  }
  // */

/**
 * Preprocessor for theme('comment').
 */
function itgadmin_preprocess_comment(&$vars) {
  // Remove comment title from display

  $vars['title'] = '';
  $comment = $vars['elements']['#comment'];
  $node = $vars['elements']['#node'];

  if ( $node->type == 'story' || $node->type == 'blog' ) {
    $vars['created'] = format_date($comment->created , 'custom' , 'D, d/m/Y h:i');
    $vars['changed'] = format_date($comment->changed , 'custom' , 'D, d/m/Y h:i');

    $vars['submitted'] = t('Submitted by !username on !datetime' , array('!username' => $vars['author'] , '!datetime' => $vars['created']));
  }
  else if ( $node->type == 'task_idea_allocation_tracking' ) {
    $vars['created'] = format_date($comment->created , 'custom' , 'D, d/m/Y h:i');
    $vars['changed'] = format_date($comment->changed , 'custom' , 'D, d/m/Y h:i');
    $vars['submitted'] = t('Commented by !username on !datetime' , array('!username' => $vars['author'] , '!datetime' => $vars['created']));
  }
}

/**
 * Implements hook_preprocess_html().
 */
function itgadmin_preprocess_html(&$variables) {
  // Make sure current page is node/nid
  // It will even if use aliases.
//  pr($variables);
//  pr(arg());
//  if(arg(0) == 'menu-manager' && arg(1) == 'second'){
//    $variables['head_title'] = "Test";
//  }
}

/**
 * Preprocessor for theme('textfield').
 */
//function rubik_preprocess_textfield(&$vars) {
//  if ($vars['element']['#size'] >= 30 && empty($vars['element']['#field_prefix']) && empty($vars['element']['#field_suffix'])) {
//    // Set text field to default size.
//    $vars['element']['#size'] = 20;/////
//    if (!isset($vars['element']['#attributes']['class'])
//      || !is_array($vars['element']['#attributes']['class'])) {
//       $vars['element']['#attributes']['class'] = array();
//    }
//    $vars['element']['#attributes']['class'][] = 'fluid';
//  }
//}
//function _rubik_submitted($node) {
//  $byline = t('Posted by !username', array('!username' => theme('username', array('account' => $node))));
//  // $date = format_date($node->created, 'small');
//  $date = date('d/m/Y', $node->created);//////
//  return "<div class='byline'>{$byline}</div><div class='date'>$date</div>";
//}

function itgadmin_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';


  if ( $element['#theme'] == 'menu_link__menu_menu_manager' ) {
    $element['#localized_options']['attributes']['class'][] = "colorbox-load";
  }

  if ( $element['#below'] ) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'] , $element['#href'] , $element['#localized_options']);

  // if link class is active, make li class as active too
  if ( strpos($output , "active") > 0 ) {
    $element['#attributes']['class'][] = "active";
  }
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function itgadmin_node_preview($variables) {
  global $base_url;
  $node = $variables['node'];
// print  $node->field_newsl_select_template[LANGUAGE_NONE][0]['target_id'];
//  itg_newsletter_content_preview_data($node);
  $output = '<div class="preview-wrapper"><div class="preview">';
  $preview_trimmed_version = FALSE;
  $elements = node_view(clone $node , 'teaser');
  $trimmed = drupal_render($elements);
  $elements = node_view($node , 'full');
  $full = drupal_render($elements);

  // Do we need to preview trimmed version of post as well as full version?
  if ( $trimmed != $full ) {
    //drupal_set_message(t('The trimmed version of your post shows what your post looks like when promoted to the main page or when exported for syndication.<span class="no-js"> You can insert the delimiter "&lt;!--break--&gt;" (without the quotes) to fine-tune where your post gets split.</span>'));
    $output .= '<h3>' . t('Preview trimmed version') . '</h3>';
    $output .= $trimmed;
    $output .= '<h3>' . t('Preview full version') . '</h3>';
    $output .= $full;
    if ( $node->type == 'newsletter' ) {
      $selectedTemplatenid = $node->field_newsl_select_template[LANGUAGE_NONE][0]['target_id'];
      $newletterContents = $node->field_newsl_newsletter_content[LANGUAGE_NONE][0]['value'];
      foreach ($node->field_story_category[LANGUAGE_NONE] as $key => $values) {
        $cat_array[] = $values['tid'];
      }
      $tid_val = implode(',' , $cat_array);
      $output .= l(t('Download HTML') , 'newsletter_data_preview/' . $selectedTemplatenid . '/' . $newletterContents . '/' . $tid_val , array('attributes' => array('class' => 'download-html') , 'html' => true));
    }
  }
  else {
    $output .= $full;
  }
  $output .= "</div></div>\n";
  return $output;
}

function itgadmin_date_all_day_label() {
  return '- 00:00';
}

/**
 * Override of theme('breadcrumb').
 */
function itgadmin_breadcrumb($vars) {
  $output = '';

  // Add current page onto the end.
  if ( !drupal_is_front_page() ) {
    $item = menu_get_item();
    $end = end($vars['breadcrumb']);
    $title = drupal_get_title();
    if ( $end && strip_tags($end) !== $title ) {
      //$vars['breadcrumb'][] = (isset($item['localized_options']['html']) && $item['localized_options']['html']) ? $item['title'] : check_plain($item['title']);
      if ( arg(2) == 'edit' ) {
        $node = node_load(arg(1));
        if ( $node->type == 'issue' ) {
          $title_arr = explode('00:' , $node->title);
          $vars['breadcrumb'][1] = date('d/m/Y' , strtotime($title_arr[0]));
        }

        $vars['breadcrumb'][] = (isset($item['localized_options']['html']) && $item['localized_options']['html']) ? $item['title'] : check_plain($item['title']);
      }
      else {
        $vars['breadcrumb'][] = (isset($item['localized_options']['html']) && $item['localized_options']['html']) ? $title : decode_entities(check_plain($title));
        $node = node_load(arg(1));

        //Set issue view page breadcrumb
        if ( !empty($node->type) && $node->type == 'issue' ) {
          $title_arr = explode('00:' , $node->title);
          $vars['breadcrumb'][1] = date('d/m/Y' , strtotime($title_arr[0]));
        }

        //Set UGC view page breadcrumb
        if ( !empty($node->type) && $node->type == 'ugc' ) {
          $vars['breadcrumb'][1] = $node->title;
        }
      }
    }


    //Story Listing
    if ( arg(0) == 'issue-listing' ) {
      $list_story_parent_link = 'manage-' . arg(1) . 's';
      ;
      $list_story_link = 'issue-listing' . '/' . arg(1) . '/' . arg(2);
      $breadcrumb[] = '<li>' . l('Home' , 'cms-user-dashboard') . '</li><li>' . l('List ' . ucfirst(arg(1)) . 's' , $list_story_parent_link) . '</li><li>' . l('List Stories' , $list_story_link) . '</li>';
      return '<div class="breadcrumb"><ol>' . implode(' » ' , $breadcrumb) . '</ol></div>';
    }

    // get first argument from url 
    $content_url = arg(0);
    // make title for breadcrumb
    $content_title = ucfirst(str_replace('-' , ' ' , $content_url));

    $story_tab = array('in-queue-story' , 'published-story' , 'expired-story' , 'unpublished-story' , 'archive-story');
    $photogallery_tab = array('in-queue-photogallery' , 'published-photogallery' , 'unpublished-photogallery' , 'archive-photogallery');
    $bolg_tab = array('published-blogs' , 'unpublished-blogs' , 'my-queue-blogs' , 'in-queue-blogs' , 'archive-blogs' , 'my-unpublished-blogs' , 'mydraft-blogs' , 'my-rejected-blogs' , 'my-published-blogs');
    $podcast_tab = array('published-podcast' , 'unpublished-podcast' , 'my-unpublished-podcast' , 'mydraft-podcast' , 'my-published-podcast' , 'my-queue-podcast' , 'in-queue-podcast' , 'archive-podcast' , 'my-rejected-podcast');
    $videogallery_tab = array('published-video' , 'unpublished-video' , 'my-unpublished-video' , 'mydraft-video' , 'my-published-video' , 'my-queue-video' , 'in-queue-video' , 'archive-video' , 'my-rejected-video');

    //story tab breadcrumb
    if ( in_array($content_url , $story_tab) ) {
      $breadcrumb[] = '<li>' . l('Home' , 'cms-user-dashboard') . '</li><li>' . l('Content Management ' , $content_url) . '</li><li>' . l($content_title , $content_url) . '</li>';
      return '<div class="breadcrumb"><ol>' . implode('  ' , $breadcrumb) . '</ol></div>';
    }

    //Photogallery tab breadcrumb
    if ( in_array($content_url , $photogallery_tab) ) {
      $breadcrumb[] = '<li>' . l('Home' , 'cms-user-dashboard') . '</li><li>' . l('Content Management ' , $content_url) . '</li><li>' . l($content_title , $content_url) . '</li>';
      return '<div class="breadcrumb"><ol>' . implode('  ' , $breadcrumb) . '</ol></div>';
    }


    //Blog tab breadcrumb
    if ( in_array($content_url , $bolg_tab) ) {
      $breadcrumb[] = '<li>' . l('Home' , 'cms-user-dashboard') . '</li><li>' . l('Content Management ' , $content_url) . '</li><li>' . l($content_title , $content_url) . '</li>';
      return '<div class="breadcrumb"><ol>' . implode('  ' , $breadcrumb) . '</ol></div>';
    }

    //podcast tab breadcrumb
    if ( in_array($content_url , $podcast_tab) ) {
      $breadcrumb[] = '<li>' . l('Home' , 'cms-user-dashboard') . '</li><li>' . l('Content Management ' , $content_url) . '</li><li>' . l($content_title , $content_url) . '</li>';
      return '<div class="breadcrumb"><ol>' . implode('  ' , $breadcrumb) . '</ol></div>';
    }

    //videogallery tab breadcrumb
    if ( in_array($content_url , $videogallery_tab) ) {
      $breadcrumb[] = '<li>' . l('Home' , 'cms-user-dashboard') . '</li><li>' . l('Content Management ' , $content_url) . '</li><li>' . l($content_title , $content_url) . '</li>';
      return '<div class="breadcrumb"><ol>' . implode('  ' , $breadcrumb) . '</ol></div>';
    }
  }

  // Optional: Add the site name to the front of the stack.
  if ( !empty($vars['prepend']) ) {
    $site_name = empty($vars['breadcrumb']) ? "<strong>" . check_plain(variable_get('site_name' , '')) . "</strong>" : l(variable_get('site_name' , '') , '<front>' , array('purl' => array('disabled' => TRUE)));
    array_unshift($vars['breadcrumb'] , $site_name);
  }

  $depth = 0;
  foreach ($vars['breadcrumb'] as $link) {

    // If the item isn't a link, surround it with a strong tag to format it like
    // one.
    if ( !preg_match('/^<a/' , $link) && !preg_match('/^<strong/' , $link) ) {
      $link = '<span>' . $link . '</span>';
    }

    $output .= "<li class='breadcrumb-link breadcrumb-depth-{$depth}'>{$link}</li>";
    $depth++;
  }
  return ('<div class="breadcrumb"><ol>' . $output . '</ol></div>');
}

/**
 * Preprocessor for theme('page').
 */
function itgadmin_preprocess_page(&$vars) {
  global $base_url;
  // Handel theme for custom widget batch processing.
  $referal_page = $_SERVER['HTTP_REFERER'];
  $pos = strpos($referal_page , "itg-custom-widget-content");
  if ( isset($_GET['op']) && isset($_GET['id']) && $pos !== false ) {
    $vars['theme_hook_suggestions'][] = 'page__relatedcontent';
  }
  // Change create category page title.
  $arg0 = arg(0);
  if ( arg(2) == 'taxonomy' && arg(3) == 'category_management' && arg(4) == 'add' ) {
    drupal_set_title('Create Category');
  }
  //  // Change create Tag page title.
  if ( arg(2) == 'taxonomy' && arg(3) == 'tags' && arg(4) == 'add' ) {
    drupal_set_title('Create Tag');
  }

  if ( $arg0 == 'survey-result' && is_numeric(arg(1)) ) {
    $node = node_load(arg(1));
    drupal_set_title('Survey Result: ' . ucwords($node->title));
  }

  if ( !empty($vars['node']) && $vars['node']->type == 'ugc' ) {
    drupal_set_title('');
  }

  // Add tpl for related content view page
  $page_url_except_header_footer = array(
    'getimagetocroper'
    , 'searchimage'
    , 'imagetotag'
    , 'imagetagedit'
    , 'anchor-list-order-reorder'
    , 'big-story-widget-list'
    , 'highlights-widget-list'
    , 'photo-list-widget-listing'
    , 'home-page-feature-widget'
    , 'we-may-suggest-content-ordering-list'
    , 'story-list-widget-listing'
    , 'top-takes-video-widget-order-reorder'
    , 'trending-video-widget-order-reorder'
    , 'watch-right-now-video-widget-order-reorder'
    , 'so-sorry-video-widget-order-reorder'
    , 'video-list-widget-listing'
    , 'issue-magazin-widget-list'
    , 'poll-format-widget-list'
    , 'special-how-made-it-widget-list'
    , 'video-status'
    , 'related-content'
    , 'feature-content-section-widget-list'
    , 'most-read-widget-list'
    , 'yearend-left-widget-list'
    , 'special-auto-review-widget-lsit'
    , 'issue-magazin-widget-list'
    , 'special-key-candidate-widget-list'
    , 'most-popular-widget-order-reorder'
    , 'dont-miss-widget-list'
    , 'dailymotion-ftp-template'
    , 'issue-magazin-primary-cat-widget-list'
    , 'supplement-base-magazin-widget-list'
    , 'speaker-order-reorder'
    , 'event-according-type'
    , 'itg-social-log'
    , 'search-unpublish-video'
    , 'search-unpublish-video-radio'
    , 'search-publish-video-radio'
    , 'search-publish-video'
    , 'itg-registered-user-report'
    , 'itg-registered-user-section-wise-breakup'
  );

  if ( in_array(arg(0) , $page_url_except_header_footer) || (arg(0) == 'itg-layout-manager' && arg(2) == 'preview') ) {
    $vars['theme_hook_suggestions'][] = 'page__relatedcontent';
  }

  if ( arg(0) == "itg-custom-widget-content" && isset($_REQUEST['widget_name_delete']) && !empty($_SESSION['widget_name']) ) {
    unset($_SESSION['widget_name']);
  }
  if ( arg(0) == "itg-custom-widget-content" || arg(0) == "itg-custom-widget-content-order" ) {
    $vars['theme_hook_suggestions'][] = 'page__customwidget';
  }

  //Add tpl for event registration view page
  if ( (!empty($vars['node']->type) && $vars['node']->type == 'event_registration') || $arg0 == 'comment_view' || $arg0 == 'event-users-list' || arg(1) == 'associate-with-story' || $arg0 == 'comment_edit' || $arg0 === 'social-media-logs' || (!empty($vars['node']->type) && $vars['node']->type == 'print_team_integration' && $_GET['type'] == 'commentform' ) ) {
    $vars['theme_hook_suggestions'][] = 'page__event_registration';
  }

  if ( arg(0) == 'event-registration-config' && is_numeric(arg(1)) ) {
    $vars['theme_hook_suggestions'][] = 'page__registration_config';
  }
}

/**
 * Override the video field
 */
function itgadmin_preprocess_field(&$vars) {
  if ( $vars['element']['#field_name'] == 'field_upload_video' ) {
    $file_id = $vars['element']['#items'][0]['fid'];
    if ( module_exists('itg_videogallery') ) {
      $video_id = itg_videogallery_get_video($file_id);
      $vars['element'][0]['#file']->video_id = $video_id;
    }
  }

  // For Audio field
  if ( $vars['element']['#field_name'] == 'field_podcast_upload_audio_file' ) {
    $file_id = $vars['element']['#items'][0]['fid'];
    if ( module_exists('itg_podcast') ) {
      $audio_id = itg_videogallery_get_video($file_id);
      $vars['element'][0]['#file']->audio_id = $audio_id;
    }
  }
}
