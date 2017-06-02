<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
if(function_exists('itg_get_related_story_content')) {
$related_data = itg_get_related_story_content($row->entity_id);
//$front_url = str_replace('-backend', '', $related_data->url);
  if (strpos($related_data->url, BACKEND_URL) !== false) {
    $front_url = str_replace(BACKEND_URL, FRONT_URL, $related_data->url);
  }
  else {
    $front_url = $related_data->url;
  }
}
 if(!empty($related_data->sm_field_custom_story_small_large_url[0])) {
 ?> 
<a href="<?php print $front_url; ?>" title="<?php print $related_data->label; ?>" target="_blank"><img alt="<?php print $related_data->label; ?>" style="width: 170px; height: 127px" src="<?php print $related_data->sm_field_custom_story_small_large_url[0]; ?>" title="<?php print $related_data->label; ?>"/></a>  
  
<?php }  else {
  $default_url = $base_url . '/sites/all/themes/itg/images/itg_image170x127.jpg';
?>
<a href="<?php print $front_url; ?>" title="<?php print $related_data->label; ?>" target="_blank"><img alt="default_image" src="<?php print $default_url; ?>" title="default_image" /></a>
<?php
} 
?>

