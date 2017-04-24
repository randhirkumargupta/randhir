<?php
/**
 * @file
 * Theme implementation for poll form in tab display.
 * 
 */
?>
<div id="GalleryIndividualImages">
  <h2 class="story-title"><?php echo t('Basic Details'); ?></h2>
  <?php print drupal_render($form['field_poll_question']); ?>
  <?php print drupal_render($form['title']); ?>
  <?php //print drupal_render($form['field_poll_question_text']); ?>  
  <?php print drupal_render($form['field_poll_question_image']); ?>
  <?php print drupal_render($form['field_poll_question_video']); ?>
  <?php print drupal_render($form['field_poll_answer_option']); ?>
  <?php print drupal_render($form['field_poll_answer']); ?> 
  <?php print drupal_render($form['field_story_url']); ?>
  <?php print drupal_render($form['field_poll_banner']); ?>
  <?php print drupal_render($form['field_poll_call_to_action_image']); ?>
</div>
<div id="Configuration">
  <h2 class="story-title"><?php echo t('Configuration'); ?></h2>
    <?php print drupal_render($form['field_poll_start_date']); ?>
  <?php print drupal_render($form['field_end_date']); ?>
  <?php print drupal_render($form['field_show_end_date']); ?>
  <?php print drupal_render($form['field_poll_end_date']); ?>
  <?php print drupal_render($form['field_result_format']); ?>
  <?php print drupal_render($form['field_display_result']); ?>
  <?php print drupal_render($form['field_associate_poll']); ?>
</div>
<!--<h2 id="title-metatags" class="story-title"><?php //echo t('SEO Meta Tags'); ?></h2>-->
<?php print drupal_render_children($form); ?>
<?php print drupal_render($form['actions']); ?>
