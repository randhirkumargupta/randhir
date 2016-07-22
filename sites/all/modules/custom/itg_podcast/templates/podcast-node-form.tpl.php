<div id="BasicDetails">
    <h2 class="story-title"><?php print t('Basic Details'); ?></h2>
    <?php print drupal_render($form['title']); ?>
    <?php print drupal_render($form['field_story_short_headline']); ?>
    <?php print drupal_render($form['field_podcast_kicker_message']); ?>
    <?php print drupal_render($form['field_story_source_id']); ?>
    <?php print drupal_render($form['field_story_source_type']); ?>
</div>
<div id="audioupload">
  <h2 class="story-title"><?php print t('Audio Upload'); ?></h2>
  <?php print drupal_render($form['upload']); ?>
  <?php print drupal_render($form['field_podcast_audio_upload']); ?>
</div>
<div id="Imageupload">
  <h2 class="story-title"><?php print t('Image upload'); ?></h2>
    <?php print drupal_render($form['field_story_extra_large_image']); ?> 
    <?php print drupal_render($form['field_story_large_image']); ?>
    <?php print drupal_render($form['field_story_medium_image']); ?>
    <?php print drupal_render($form['field_story_small_image']); ?>
    <?php print drupal_render($form['field_story_extra_small_image']); ?>
</div>

<div id="Configuration">
    <h2 class="story-title"><?php print t('Configuration'); ?></h2>
    <?php print drupal_render($form['field_story_itg_tags']); ?>
    <?php print drupal_render($form['field_dailymotion_playlist']); ?>
    <?php print drupal_render($form['field_story_category']); ?>

</div>
<h2 id="title-metatags" class="story-title"><?php print t('Meta Tags'); ?></h2>
<?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>
