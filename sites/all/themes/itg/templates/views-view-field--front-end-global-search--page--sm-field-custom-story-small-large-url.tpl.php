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
  if (function_exists('itg_apache_solr_get_site_url')) {
      $hash_url = itg_apache_solr_get_site_url();
  }
  $front_url = $hash_url[$related_data->hash] . '/' . $related_data->path_alias;
}
if(!empty($related_data->sm_field_magazine_small_url[0]) && $related_data->bundle == 'magazine' && getimagesize($related_data->sm_field_magazine_small_url[0]) !== false) {
?>
<a href="<?php print $front_url; ?>" title="<?php print $related_data->label; ?>" target="_blank"><img alt="<?php print $related_data->label; ?>" style="width: 170px; height: 127px" src="<?php print $related_data->sm_field_magazine_small_url[0]; ?>" title="<?php print $related_data->label; ?>"/></a>
<?php
} else if(!empty($related_data->sm_field_custom_story_small_large_url[0]) && getimagesize($related_data->sm_field_custom_story_small_large_url[0]) !== false) {
 ?> 
  
<a href="<?php print $front_url; ?>" title="<?php print $related_data->label; ?>" target="_blank"><img alt="<?php print $related_data->label; ?>" style="width: 170px; height: 127px" src="<?php print $related_data->sm_field_custom_story_small_large_url[0]; ?>" title="<?php print $related_data->label; ?>"/></a>  
  
<?php }  else {
  $default_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg');
?>
<a href="<?php print $front_url; ?>" title="<?php print $related_data->label; ?>" target="_blank"><img alt="default_image" src="<?php print $default_url; ?>" title="default_image" /></a>
<?php
} 

 //code for title
  //$related_data = itg_get_related_story_content($row->entity_id);
  $position = $related_data->sm_field_emoji_position[0];
  $emoji_image = $related_data->sm_field_custom_emoji[0];
  preg_match_all('/<img[^>]*>/s', $emoji_image, $images);
  $smilies = implode("", $images[0]);
  $label = html_entity_decode($related_data->label, ENT_QUOTES);
  if (function_exists('itg_apache_solr_get_site_url')) {
    $hash_url = itg_apache_solr_get_site_url();
  }
  $front_url = $hash_url[$related_data->hash] . '/' . $related_data->path_alias;

  if(!empty($position) && $position == 'left') {
?>
<div class="n-title search-detail"><h2 title="<?php print strip_tags($label); ?>"><span class="smily-im"><?php print $smilies; ?></span> <?php print l(mb_strimwidth($label, 0, 500, ".."), $front_url, array("attributes" => array("target" => "_blank", "title" => $label))); ?></h2></div>
<?php } else { ?>
<div class="n-title search-detail"><h2 title="<?php print strip_tags($label); ?>"><?php print l(mb_strimwidth($label, 0, 500, ".."), $front_url, array("attributes" => array("target" => "_blank", "title" => $label))); ?> <span class="smily-im"><?php print $smilies; ?></span></h2></div>
<?php } ?>
