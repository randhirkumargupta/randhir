<?php
/**
 * @file
 * Theme implementation for story form in tab display.
 * 
 */
?>

<div id="BasicDetails">
    <h2 class="story-title">Basic Details</h2>
    <?php print drupal_render($form['title']); ?>
    <?php print drupal_render($form['field_astro_frequency']); ?>
    <?php print drupal_render($form['field_astro_date_range']); ?>
    <?php print drupal_render($form['field_story_category']); ?>
</div>
<div id="StoryContent">
    <h2 class="story-title">Zodiac Sign</h2>
    <?php print drupal_render($form['field_astro_zodiac']); ?>

</div>
<div id="Configuration">
    <h2 class="story-title">Collective Content</h2>
    <?php print drupal_render($form['field_buzz_description']); ?>
    <?php print drupal_render($form['field_astro_video']); ?>
    <?php print drupal_render($form['field_common_audio_file']); ?>
</div>
<div id="SocialMedia">
    <h2 class="story-title">Numerology</h2>
    <?php print drupal_render($form['field_numerology']); ?>
    <?php print drupal_render($form['field_astro_frequency2']); ?>
    <?php print drupal_render($form['field_field_astro_date_range2']); ?>
    <?php print drupal_render($form['field_astro_numerology_values']); ?>
</div>