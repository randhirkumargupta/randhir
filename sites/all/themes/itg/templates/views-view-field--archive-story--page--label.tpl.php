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
?>
<?php
if (function_exists(itg_story_clone_data))
{
  
  $emoji_title = itg_story_clone_data($row->entity_id, '');
  $clone_arr_response = $emoji_title->response->docs[0];
  $position = $clone_arr_response->sm_field_emoji_position[0];
  $emoji_image = $clone_arr_response->sm_field_custom_emoji[0];
  preg_match_all('/<img[^>]*>/s', $emoji_image, $images);
  $smilies = implode("", $images[0]);
  $label = html_entity_decode($clone_arr_response->label, ENT_QUOTES);
}
if(!empty($position) && $position == 'left') {
  ?>
<div class="n-title search-detail"><h2 title="<?php print $label; ?>"><span class="smily-im"><?php print $smilies; ?></span><?php print l(mb_strimwidth($label, 0, 65, ".."), $clone_arr_response->url, array("attributes" => array("target" => "_blank", "title" => $label))); ?></h2></div>
<?php } else { ?>
<div class="n-title search-detail"><h2 title="<?php print $label; ?>"><?php print l(mb_strimwidth($label, 0, 65, ".."), $clone_arr_response->url, array("attributes" => array("target" => "_blank", "title" => $label))); ?><span class="smily-im"><?php print $smilies; ?></span></h2></div>
<?php } ?>
