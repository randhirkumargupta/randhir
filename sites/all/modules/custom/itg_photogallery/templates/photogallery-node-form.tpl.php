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
  <h2 class="story-title">Element</h2>
  <?php print drupal_render($form['title']); ?>
  <?php print drupal_render($form['field_gallery_kicer']); ?>
  <?php print drupal_render($form['field_headline']); ?>
  <?php print drupal_render($form['field_photogallery_description']); ?>
  <?php print drupal_render($form['field_featured']); ?>
  <!--<div class="description">This title shows on the section page</div> -->
</div>
<div id="Tagstofollow">
  <h2 class="story-title">Tags to follow</h2>
  <?php print drupal_render($form['field_people_tag']); ?>
  <?php print drupal_render($form['field_brand_tag']); ?> 
  <?php print drupal_render($form['field_product_tag']); ?>    
  <?php print drupal_render($form['field_content_tag']); ?>
</div>
<div id="BrowseMedia">
  <h2 class="story-title">Gallery Image Upload</h2>
  <?php print drupal_render($form['field_story_extra_large_image']); ?>
  <span>This image will be resized by the system into pre-defined dimensions</span>
  <?php print drupal_render($form['field_story_resize_extra_large']); ?>
  <?php print drupal_render($form['field_story_large_image']); ?>
  <?php print drupal_render($form['field_story_medium_image']); ?>
  <?php print drupal_render($form['field_story_small_image']); ?>
  <?php print drupal_render($form['field_story_extra_small_image']); ?>
</div>
<div id="AddSyndication">
  <h2 class="story-title">Add Syndication</h2>
  <?php print drupal_render($form['field_syndication_']); ?>
  <?php print drupal_render($form['field_p_client_title']); ?>
</div>
<div id="Categorization">
  <h2 class="story-title">Categorization</h2>
  <?php print drupal_render($form['field_story_category']); ?>
</div>
<div id="GalleryIndividualImages">
  <h2 class="story-title">Gallery Individual Images</h2>

  <?php print drupal_render($form['field_bulk_media_upload']); ?>
  <?php print drupal_render($form['upload']); ?>
  <?php print drupal_render($form['field_common_audio']); ?>
  <?php print drupal_render($form['field_common_audio_file']); ?>
  <?php print drupal_render($form['field_credit_to_all']); ?>
  <?php print drupal_render($form['field_credit_name']); ?>
  <?php print drupal_render($form['field_gallery_image']); ?>

</div>

<h2 id="title-metatags" class="story-title">Meta Tags</h2>
<?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>
