<?php

/**
 * General Settings for block refresh
 */


/**
 *  page callback for /itg_akamai_block_refresh/[module]/[delta]
 *  displays the block content, without any other page information
 */
function itg_akamai_block_refresh_block_content($module = NULL, $delta = NULL) {
  // If there is a request directly to /itg_akamai_block_refresh...
  if (!isset($module) || !isset($delta)) {
    drupal_not_found();
  }

  $block_id = drupal_html_id('block-' . $module . '-' . $delta);
  $settings = variable_get('itg_akamai_block_refresh_settings', array());
  // If automatic refresh AND manual refresh are both disabled...
  if (empty($settings[$block_id]) || (!$settings[$block_id]['auto'] && !$settings[$block_id]['manual'] &&
      !$settings[$block_id]['init'])) {
    drupal_not_found();
  }
  //Validate args and get referrering page args from end.  Set as path.
  // @todo: extract to a method.
  $args = arg();
  if(!empty($args[3]) && $args[0] == 'itg_akamai_block_refresh' && $args[1] == $module && $args[2] == $delta) {
    unset($args[0]);
    unset($args[1]);
    unset($args[2]);
    $_GET['q'] = implode('/', $args);
  } else {
    $_GET['q'] = '';  $args = arg();

  }

  //Bypass page cache if set
  if(isset($settings[$block_id]['bypass_page_cache']) && $settings[$block_id]['bypass_page_cache'] == 1) {
    $GLOBALS['conf']['cache'] = FALSE;
  }

  // Override external cache max age if set
  if (isset($settings[$block_id]['bypass_external_cache']) && $settings[$block_id]['bypass_external_cache'] != '') {
      drupal_add_http_header('Cache-Control', 'public, max-age=' . intval($settings[$block_id]['bypass_external_cache']));
      $formated_expire_date = itg_akamai_block_refresh_set_expiration_date(intval($settings[$block_id]['bypass_external_cache']));
      drupal_add_http_header('Edge-control', 'cache-maxage=' . intval($settings[$block_id]['bypass_external_cache']) . 's');
      drupal_add_http_header('Expires', $formated_expire_date);
  }

  $block  = block_load($module, $delta);
  $renderable_array = _block_get_renderable_array(_block_render_blocks(array($block)));
  $output = drupal_render($renderable_array);

   // Print out the content of the proceeding call
   print $output;
}
