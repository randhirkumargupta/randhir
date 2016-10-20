<?php
/**
 * @file
 * Theme implementation for Live TV form in tab display.
 * 
 */
?>

<div id="BasicDetails">
   <?php print drupal_render($form['title']); ?>
             </div>

<div id="WebDetails">
    <h2 class="breaking-title">Web</h2>
    <?php print drupal_render($form['field_ads_ad_code']); ?>
     </div>

<div id="Mobiledetails">
    <h2 class="breaking-title">Mobile</h2>
    <?php print drupal_render($form['field_ads_header_script']); ?>
        </div>


<div id="Appdetails">
    <h2 class="breaking-title">App</h2>
  <?php print drupal_render($form['field_story_expert_description']); ?>
  <?php print drupal_render($form['field_mega_review_description']); ?>
  <?php print drupal_render($form['field_recipe_ingredients']); ?>
  
             </div>


 <?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>
