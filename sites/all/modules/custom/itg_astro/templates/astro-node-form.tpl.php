<?php
/**
 * @file
 * Theme implementation for story form in tab display.
 * 
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
    <h2 class="story-title"><?php echo t('Channel'); ?></h2>
    <?php print drupal_render($form['field_story_category']); ?>    
</div>
<div id="StoryContent">
    <h2 class="story-title"><?php echo t('Zodiac Sign'); ?></h2>
    <?php print drupal_render($form['field_astro_zodiac']); ?>

</div>
<div id="Configuration">
    <h2 class="story-title"><?php echo t('Collective Content'); ?></h2>
    <?php print drupal_render($form['field_buzz_description']); ?>
    <?php print drupal_render($form['field_astro_video_thumbnail']); ?>
    <?php print drupal_render($form['field_astro_video']); ?>
    <?php print drupal_render($form['field_common_audio_file']); ?>
</div>
<div id="SocialMedia">
    <h2 class="story-title"><?php echo t('Numerology'); ?></h2>
    <?php print drupal_render($form['field_numerology']); ?>
    <?php print drupal_render($form['field_astro_frequency2']); ?>
    <?php print drupal_render($form['field_field_astro_date_range2']); ?>
    <?php print drupal_render($form['field_astro_numerology_values']); ?>
</div>
<h2 id="title-metatags" class="story-title"><?php echo t('Meta Tags'); ?></h2>
 <?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>