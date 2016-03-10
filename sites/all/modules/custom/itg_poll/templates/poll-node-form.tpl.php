<?php
/**
 * @file
 * Theme implementation for story form in tab display.
 * 
 */
?>
<!--<div class=""><?php //print drupal_render($form['actions']);  ?></div>-->

<div id="Element">
  <h2 class="story-title">Poll Title</h2>
  <?php print drupal_render($form['title']); ?>
  <!--<div class="description">This title shows on the section page</div> -->
</div>
<div id="BrowseMedia">
  <h2 class="story-title">Poll Question</h2>
  <?php print drupal_render($form['field_poll_question']); ?>
  <?php print drupal_render($form['field_poll_question_text']); ?>
  
  <?php print drupal_render($form['field_poll_question_image']); ?>
  <?php print drupal_render($form['field_poll_question_video']); ?>
  
  <?php print drupal_render($form['field_poll_answer_option']); ?>
  <?php print drupal_render($form['field_poll_answer']); ?>
</div>
<div id="GalleryIndividualImages">
  <h2 class="story-title">Poll configuration</h2>
  
  <?php print drupal_render($form['field_story_url']); ?>
  <?php print drupal_render($form['field_poll_banner']); ?>
  <?php print drupal_render($form['field_poll_call_to_action_image']); ?>
</div>
<div id="Configuration">
  <h2 class="story-title">Configuration</h2>
    <?php print drupal_render($form['field_poll_start_date']); ?>
  <?php print drupal_render($form['field_end_date']); ?>
  <?php print drupal_render($form['field_result_format']); ?>
  <?php print drupal_render($form['field_display_result']); ?>
  <?php print drupal_render($form['field_associate_poll']); ?>
</div>
<h2 id="title-metatags" class="story-title">Meta Tags</h2>
<?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>
