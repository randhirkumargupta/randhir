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

    if ($element['#below']) {
        $sub_menu = drupal_render($element['#below']);
    }
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);

    // if link class is active, make li class as active too
    if(strpos($output,"active")>0){
        $element['#attributes']['class'][] = "active";
    }
    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function itgadmin_node_preview($variables) {
  $node = $variables['node'];

  $output = '<div class="preview-wrapper"><div class="preview">';

  $preview_trimmed_version = FALSE;

  $elements = node_view(clone $node, 'teaser');
  $trimmed = drupal_render($elements);
  $elements = node_view($node, 'full');
  $full = drupal_render($elements);

  // Do we need to preview trimmed version of post as well as full version?
  if ($trimmed != $full) {
    drupal_set_message(t('The trimmed version of your post shows what your post looks like when promoted to the main page or when exported for syndication.<span class="no-js"> You can insert the delimiter "&lt;!--break--&gt;" (without the quotes) to fine-tune where your post gets split.</span>'));
    $output .= '<h3>' . t('Preview trimmed version') . '</h3>';
    $output .= $trimmed;
    $output .= '<h3>' . t('Preview full version') . '</h3>';
    $output .= $full;
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

//breadcome


/**
 * Preprocessor for theme('page').
 */
function itgadmin_preprocess_page(&$vars) {  
  
  // Change create category page title.
  if (arg(2) == 'taxonomy' && arg(3) == 'category_management' && arg(4) == 'add') {
    drupal_set_title('Create Category');
  }
  //  // Change create Tag page title.
  if (arg(2) == 'taxonomy' && arg(3) == 'tags' && arg(4) == 'add') {
    drupal_set_title('Create Tag');
  }

  if (arg(0) == 'survey-result' && is_numeric(arg(1))) {
    $node = node_load(arg(1));
    drupal_set_title('Survey Result: ' . ucwords($node->title));
  }

  //Add tpl for event registration view page
  if ($vars['node']->type == 'event_registration' && arg(1) != 'add') {
    $vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
  }
}
