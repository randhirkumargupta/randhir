<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */


?>
<?php
global $theme;
if ($theme != 'itgadmin') { ?>
<!--------------------------------Code for Front tpl---------------------------------------->

<?php } else { ?>
<!--------------------------------Code for Admin tpl---------------------------------------->
Admin Photo Tamplate
<div>
  <div id="front-block_1">
    Block 1
    <input type="text" maxlength="255" size="30" value="" name="block_title" class="block_title_id">
    <input type="text" maxlength="255" size="30" value="" name="widget_name" class="widget_name">
    <input type="text" maxlength="255" size="30" value="" name="filter_url" class="filter_url">
  </div>
  <div id="front-block_2">
    Block 2
    <input type="text" maxlength="255" size="30" value="" name="block_title" class="block_title_id">
    <input type="text" maxlength="255" size="30" value="" name="widget_name" class="widget_name">
    <input type="text" maxlength="255" size="30" value="" name="filter_url" class="filter_url">
  </div>
  <div id="front-block_3">
    Block 3
    <input type="text" maxlength="255" size="30" value="" name="block_title" class="block_title_id">
    <input type="text" maxlength="255" size="30" value="" name="widget_name" class="widget_name">
    <input type="text" maxlength="255" size="30" value="" name="filter_url" class="filter_url">
  </div>
  <div id="front-block_4">
    Block 4
    <input type="text" maxlength="255" size="30" value="" name="block_title" class="block_title_id">
    <input type="text" maxlength="255" size="30" value="" name="widget_name" class="widget_name">
    <input type="text" maxlength="255" size="30" value="" name="filter_url" class="filter_url">
  </div>
</div>
<?php }
