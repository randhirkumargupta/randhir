<?php
/**
 * @file
 * Theme implementation for story form in tab display.
 * 
 */
//p($page);
?>
<!--<div class=""><?php //print drupal_render($form['actions']);  ?></div>-->

<div id="Element">
  <h2 class="story-title">Gallery Basic details</h2>
  <?php print drupal_render($form['title']); ?>
  <?php print drupal_render($form['field_gallery_kicer']); ?>
  <!--<div class="description">This title shows on the section page</div> -->
</div>
<div id="BrowseMedia">
  <h2 class="story-title">Gallery Cover Image</h2>
  <?php print drupal_render($form['field_story_extra_large_image']); ?>
  <p class="pre-desc">This image will be resized by the system into pre-defined dimensions</p>
  <?php print drupal_render($form['field_story_resize_extra_large']); ?>
  <?php print drupal_render($form['field_story_large_image']); ?>
  <?php print drupal_render($form['field_story_medium_image']); ?>
  <?php print drupal_render($form['field_story_small_image']); ?>
  <?php print drupal_render($form['field_story_extra_small_image']); ?>
</div>
<div id="GalleryIndividualImages">
  <h2 class="story-title">Gallery Images Upload</h2>
  
  <?php print drupal_render($form['field_bulk_media_upload']); ?>
  <?php print drupal_render($form['upload']); ?>
  <?php print drupal_render($form['field_common_audio']); ?>
  <?php print drupal_render($form['field_common_audio_file']); ?>
  <?php print drupal_render($form['field_credit_to_all']); ?>
  <?php print drupal_render($form['field_credit_name']); ?>
  <?php print drupal_render($form['field_photo_by']);?>
  <?php print drupal_render($form['field_gallery_image']); ?>

</div>
<div id="Configuration">
  <h2 class="story-title">Configuration</h2>
  <?php print drupal_render($form['field_featured']); ?>
</div>
<div id="Categorization">
  <h2 class="story-title">Categorization</h2>
  <?php print drupal_render($form['field_story_category']); ?>
</div>
<h2 id="title-metatags" class="story-title">Meta Tags</h2>
<?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>
