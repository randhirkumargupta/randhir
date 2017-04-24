<?php

/**
 * @file
 * Theme implementation for story form in tab display.
 */
?>

<div id="BasicDetails">
    <h2 class="story-title"><?php echo t('Basic Details'); ?></h2>
    <?php print drupal_render($form['title']); ?>
    <?php print drupal_render($form['field_astro_frequency']); ?>
    <?php print drupal_render($form['field_astro_date_range']); ?>
    <?php print render($form['field_story_expiry_date']); ?>
    <?php print render($form['field_last_name']); ?>
    <?php print render($form['field_astro_type']); ?>    
</div>
<div id="SocialMedia">    
    <?php print drupal_render($form['itg_zodiac']); ?>
    <?php print drupal_render($form['field_astro_zodiac']); ?>
</div>
<div id="SocialMedia">    
    <?php print drupal_render($form['itg_numerology']); ?>
    <?php print drupal_render($form['field_numerology']); ?>
    <?php print drupal_render($form['field_astro_frequency2']); ?>
    <?php print drupal_render($form['field_field_astro_date_range2']); ?>
    <?php print drupal_render($form['field_astro_numerology_values']); ?>
</div>
<div id="SocialMedia">    
    <?php print drupal_render($form['itg_collective']); ?>
    <?php print drupal_render($form['field_buzz_description']); ?>
    <?php print drupal_render($form['field_astro_video_thumbnail']); ?>
    <?php print drupal_render($form['field_astro_video']); ?>
    <?php print drupal_render($form['field_common_audio_file']); ?>
</div>
<div id="channel">
  <h2 class="story-title"><?php echo t('Channel'); ?></h2>
  <?php print drupal_render($form['field_story_category']); ?>    
  <?php print drupal_render($form['field_primary_cat_data']); ?>
</div>

<!--<h2 id="title-metatags" class="story-title"><?php //echo t('SEO Meta Tags'); ?></h2>-->
 <?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>
