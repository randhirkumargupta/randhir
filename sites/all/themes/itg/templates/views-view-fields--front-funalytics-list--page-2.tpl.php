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
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$search_title = preg_replace("/'/", "\\'", $row->node_title);
$fb_share_title= htmlentities($search_title, ENT_QUOTES);    
$short_url = shorten_url($row->url, 'goo.gl');
$twitter_title = addslashes($row->node_title);
$share_desc = '';
$image = file_create_url($row->field_field_itg_funalytics_image[0]['rendered']['#item']['uri']);
$print_image = $row->field_field_itg_funalytics_image[0]['rendered']['#item']['uri'];
$changed = date("D j M Y", $row->node_changed);
?>
<div class="funalytics-tile">
  <div class="pic"><a class="funalytic-popup" href="javascript:;"><?php print theme('image_style', array('style_name' => 'funalytics_thump_wide', 'path' => $print_image)); ?></a></div>
  <div class="funalytics-text">
      <div class="updated-date"><?php print $changed; ?></div>
      <div class="title"><?php print $row->node_title; ?></div>
      <div class="social-share">
              <ul>
                  <li><a href="javascript:;" class="share"><i class="fa fa-share-alt"></i></a></li>
                  <li><a class="def-cur-pointer facebook" title = "share on facebook " href="javascript:void(0)"  onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_share_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>')"><i class="fa fa-facebook"></i></a></li>
                  <li><a class="def-cur-pointer twitter user-activity" title = "share on twitter" class="" rel="<?php print $row->nid; ?>" data-tag="itg_funalytics" data-activity="twitter_share" data-status="1" href="javascript:void(0)" onclick="twitter_popup('<?php print urlencode($twitter_title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
                  <li><a title="share on google+" class="def-cur-pointer google user-activity" rel="<?php print $row->nid; ?>" data-tag="itg_funalytics" data-activity="google_share" data-status="1" href="javascript:void(0)" onclick="return googleplusbtn('<?php print $actual_link; ?>')"></a></li>                  
              </ul>
          </div>
  </div>
</div>
