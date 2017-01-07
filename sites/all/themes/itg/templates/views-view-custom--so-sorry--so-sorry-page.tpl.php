<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
// Logic for default feature video on sosorry page if feature is not selected in widget.
if (function_exists('get_recent_created_node_for_sosorry')) {
  $nid = get_recent_created_node_for_sosorry();
}
if (is_numeric(arg(1))) {
  $nid = arg(1);
  if (function_exists('itg_widget_dailymotion_get_videogallery_slider')) {
    itg_widget_dailymotion_get_videogallery_slider($nid);
  }
}
