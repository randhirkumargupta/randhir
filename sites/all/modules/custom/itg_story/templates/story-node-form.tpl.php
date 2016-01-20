<?php
/**
 * @file
 * Theme implementation for story form in tab display.
 * 
 */

?>
<div class=""><?php print drupal_render($form['actions']); ?></div>

<div id="BasicDetails">
  <?php print drupal_render($form['field_story_magazine_story_issue']); ?>
  <?php print drupal_render($form['field_story_select_magazine']); ?>
  <?php print drupal_render($form['field_story_select_supplement']); ?>
  <?php print drupal_render($form['field_story_long_head_line']); ?>
  <?php print drupal_render($form['title']); ?>
  <?php print drupal_render($form['field_story_short_headline']); ?>
  <?php print drupal_render($form['field_story_redirection_url']); ?>
  <?php print drupal_render($form['field_story_new_title']); ?>
  <?php print drupal_render($form['field_story_redirection_url_titl']); ?>
  <?php print drupal_render($form['field_story_magazine_headline']); ?>
  <?php print drupal_render($form['field_story_magazine_kicker_text']); ?>
  <?php print drupal_render($form['field_stroy_city']); ?>
  <?php print drupal_render($form['field_story_courtesy']); ?>
  <?php print drupal_render($form['field_story_reporter']); ?>
  <div id="reporter-details">
    
  </div>
  <?php print drupal_render($form['field_story_expert_name']); ?>
  <?php print drupal_render($form['field_story_expert_image']); ?>
  <?php print drupal_render($form['field_story_expert_description']); ?>
</div>
<div id="StoryContent">
  <?php print drupal_render($form['body']); ?>
</div>
<div id="Configuration">
  <?php print drupal_render($form['field_story_configurations']); ?>
  <?php print drupal_render($form['field_story_comment_question']); ?>
</div>
<div id="SocialMedia">
  <?php print drupal_render($form['field_story_social_media_integ']); ?>
  <?php print drupal_render($form['field_story_facebook_narrative']); ?>
  <?php print drupal_render($form['field_story_facebook_image']); ?>
  <?php print drupal_render($form['field_story_tweet']); ?>
</div>
<div id="BrowseMedia">
  <?php print drupal_render($form['field_story_extra_large_image']); ?>
  <?php print drupal_render($form['field_story_resize_extra_large']); ?>
  <?php print drupal_render($form['field_story_large_image']); ?>
  <?php print drupal_render($form['field_story_medium_image']); ?>
  <?php print drupal_render($form['field_story_small_image']); ?>
  <?php print drupal_render($form['field_story_extra_small_image']); ?>
</div>
<div id="Templates">
  <?php print drupal_render($form['field_story_templates']); ?>
  <?php print drupal_render($form['field_story_template_guru']); ?>
  <?php print drupal_render($form['field_story_template_quotes']); ?>
  <?php print drupal_render($form['field_story_template_factoids']); ?>
  <?php print drupal_render($form['field_story_template_buzz']); ?>
</div>
<!--<div class=""><?php //print drupal_render($form['path']); ?></div>-->
<!--<div class=""><?php print drupal_render($form['sss']); ?></div>
<div class=""><?php print drupal_render($form['sss']); ?></div>-->


<div class=""><?php print drupal_render($form['actions']); ?></div>


 <?php print drupal_render_children($form); ?>
