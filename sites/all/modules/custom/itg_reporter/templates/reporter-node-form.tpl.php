<div id="BasicDetails">
    <h2 class="story-title"><?php print t('Quick File'); ?></h2>
    <?php print drupal_render($form['title']); ?>
    <?php print drupal_render($form['field_reporter_email_id']); ?>
    <?php print drupal_render($form['field_celebrity_pro_occupation']); ?>
    <?php print drupal_render($form['field_reporter_profile_type']); ?>
    <?php print drupal_render($form['field_byline_company']); ?>
    <?php print drupal_render($form['field_byline_department']); ?>
    <?php print drupal_render($form['field_reporter_twitter_handle']); ?>
    <?php print drupal_render($form['field_story_expert_name']); ?>
    <?php print drupal_render($form['field_story_new_title']); ?>
    <?php print drupal_render($form['field_reporter_movie_name']); ?>
    <?php print drupal_render($form['field_story_category']); ?>
    <?php print drupal_render($form['field_story_extra_large_image']); ?>
    <?php print drupal_render($form['body']); ?>
    
</div>

<!--<h2 id="title-metatags" class="story-title"><?php // echo t('SEO Meta Tags'); ?></h2>-->
<?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>
