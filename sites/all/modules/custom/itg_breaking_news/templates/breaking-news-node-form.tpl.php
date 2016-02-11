<?php
/**
 * @file
 * Theme implementation for Breaking News form in tab display.
 * 
 */
//p($page);
?>
<!--<div class=""><?php //print drupal_render($form['actions']); ?></div>-->

<div id="BreakingNewsBasicDetails">
  <h2 class="breaking-title">Basic Details</h2>
  <?php print drupal_render($form['field_type']); ?>
  <?php print drupal_render($form['field_display_name']); ?>
  <?php print drupal_render($form['field_publish_time']); ?>
   <?php print drupal_render($form['title']); ?>
  <?php print drupal_render($form['field_title_link']); ?>
   <?php print drupal_render($form['field_title_2']); ?>
   <?php print drupal_render($form['field_title_link_2']); ?>
    </div>


<div id="ContentType">
    <?php print drupal_render($form['field_content_type']); ?>
     </div>

<div id="BrowseMedia">
  <h2 class="story-title">Browse Media</h2>
  <?php print drupal_render($form['field_story_extra_large_image']); ?>
  <p class="pre-desc">This image will be resized by the system into pre-defined dimensions</p>
  <?php print drupal_render($form['field_story_large_image']); ?>
  <?php print drupal_render($form['field_story_medium_image']); ?>
  <?php print drupal_render($form['field_story_small_image']); ?>
  <?php print drupal_render($form['field_story_extra_small_image']); ?>
</div>

<div id="Description">
  <h2 class="breaking-title">Description</h2>
  <?php print drupal_render($form['field_label']); ?>
  <?php print drupal_render($form['body']); ?>
       </div>

<div id="City">
    <?php print drupal_render($form['field_stroy_city']); ?>
         </div>

<div id="Configuration">
  <h2 class="breaking-title">Configuration</h2>
  <?php print drupal_render($form['field_notification']); ?>
  <?php print drupal_render($form['field_mobile_subscribers']); ?>
         </div>

<div id="DisplayOn">
  <?php print drupal_render($form['field_display_on']); ?>
  <?php print drupal_render($form['field_section']); ?>
             </div>

<div id="Keywords">
  <?php print drupal_render($form['field_keywords']); ?>
               </div>
<h2 id="title-metatags" class="story-title">Meta Tags</h2>
 <?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>
