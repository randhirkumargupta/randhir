<?php
/**
 * @file
 * Theme implementation for story form in tab display.
 * 
 */
//p($page);
?>
<!--<div class=""><?php //print drupal_render($form['actions']); ?></div>-->

<div id="BasicDetails">
  <h2 class="story-title">Basic Details</h2>
  <?php print drupal_render($form['field_story_magazine_story_issue']); ?>
  <?php print drupal_render($form['field_story_select_magazine']); ?>
  <?php print drupal_render($form['field_story_select_supplement']); ?>
  <?php print drupal_render($form['field_story_issue_date']); ?>
  <?php print drupal_render($form['title']); ?>
  <?php print drupal_render($form['field_story_long_head_line']); ?>
  
  <div class="pre-desc">This title shows on the section page</div>
  <?php print drupal_render($form['field_story_short_headline']); ?>
  <?php print drupal_render($form['field_story_snap_post']); ?>  
  <?php print drupal_render($form['field_story_new_title']); ?>
  <?php print drupal_render($form['field_story_redirection_url_titl']); ?>
  <?php print drupal_render($form['field_story_magazine_headline']); ?>
  <?php print drupal_render($form['field_story_magazine_kicker_text']); ?>
  <?php print drupal_render($form['field_stroy_city']); ?>
  <?php print drupal_render($form['field_story_courtesy']); ?> 
</div>
<div id="StoryContent">
  <h2 class="story-title">Story Content</h2>
  <?php print drupal_render($form['field_story_reporter']); ?>
  <div id="reporter-details"></div>
  <?php print drupal_render($form['field_story_schedule_date_time']); ?>
  <?php print drupal_render($form['field_story_expires']); ?> 
  <?php print drupal_render($form['field_story_expiry_date']); ?>    
  <?php print drupal_render($form['field_story_expert_name']); ?>
  <?php print drupal_render($form['field_story_expert_image']); ?>
  <?php print drupal_render($form['field_story_expert_description']); ?>
  <?php print drupal_render($form['field_story_kicker_text']); ?>  
  <?php print drupal_render($form['body']); ?>
</div>
<div id="Configuration">
  <h2 class="story-title">Configuration</h2>
  <?php print drupal_render($form['field_story_configurations']); ?>
  <?php print drupal_render($form['field_story_comment_question']); ?>
  <?php print drupal_render($form['field_story_client_title']); ?>
  <?php print drupal_render($form['field_story_media_files_syndicat']); ?>
  <?php print drupal_render($form['field_story_rating']); ?>
</div>
<div id="SocialMedia">
  <h2 class="story-title">Social Media</h2>
  <?php print drupal_render($form['field_story_social_media_integ']); ?>
  <?php print drupal_render($form['field_story_facebook_narrative']); ?>
  <?php print drupal_render($form['field_story_facebook_image']); ?>
  <?php print drupal_render($form['field_story_tweet']); ?>
</div>
<div id="BrowseMedia">
  <h2 class="story-title">Browse Media</h2>
  <?php print drupal_render($form['field_story_extra_large_image']); ?>
  <div class="pre-desc">This image will be resized by the system into pre-defined dimensions</div>
  <?php //print drupal_render($form['field_story_resize_extra_large']); ?>
  <?php print drupal_render($form['field_story_large_image']); ?>
  <?php print drupal_render($form['field_story_medium_image']); ?>
  <?php print drupal_render($form['field_story_small_image']); ?>
  <?php print drupal_render($form['field_story_extra_small_image']); ?>
</div>
<div id="Templates">
  <h2 class="story-title">Templates</h2>
  <?php print drupal_render($form['field_story_templates']); ?>
  <?php print drupal_render($form['field_story_template_guru']); ?>
  <?php print drupal_render($form['field_story_template_quotes']); ?>
  <?php print drupal_render($form['field_story_template_factoids']); ?>
  <?php print drupal_render($form['field_story_template_buzz']); ?>
</div>
<div id="category">
  <h2 class="story-title">Category</h2>  
  <?php print drupal_render($form['field_story_itg_tags']); ?>  
  <?php print drupal_render($form['field_story_category']); ?>  
</div>
<h2 id="title-metatags" class="story-title">Remarks</h2>
 <?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>
