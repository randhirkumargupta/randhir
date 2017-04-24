<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */

// configuration for social sharing
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$search_title = preg_replace("/'/", "\\'", $row->label);
$search_share_title= htmlentities($search_title, ENT_QUOTES);    
$short_url = shorten_url($row->url, 'goo.gl');
$share_title = addslashes($row->label);
$share_desc = '';
preg_match('/(src=["\'](.*?)["\'])/', $row->sm_thumb_medium_field_story_extra_large_image[0], $match);  //find src="X" or src='X'
$split = preg_split('/["\']/', $match[0]); // split by quotes
$src = $split[1]; // X between quotes
?>

<?php foreach ($fields as $id => $field): ?>
  <?php if (!empty($field->separator)): ?>
    <?php print $field->separator; ?>
  <?php endif; ?>

  <?php print $field->wrapper_prefix; ?>
    <?php print $field->label_html; ?>
    <?php print $field->content; ?>
  <?php print $field->wrapper_suffix; ?>
<?php endforeach; ?>

<div class="social-share"><ul><li><a class="share def-cur-pointer"><i class="fa fa-share-alt"></i></a></li><li><a title="share on facebook" class= "facebook def-cur-pointer" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $search_share_title; ?>', '<?php print $share_desc; ?>', '<?php print $src; ?>')"><i class="fa fa-facebook"></i></a></li><li><a title="share on twitter" class= "twitter def-cur-pointer" onclick="twitter_popup('<?php print urlencode($share_title);?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li><li><a title="share on google+" class= "google def-cur-pointer" onclick="return googleplusbtn('<?php print $actual_link; ?>')"></a></li></ul></div>
