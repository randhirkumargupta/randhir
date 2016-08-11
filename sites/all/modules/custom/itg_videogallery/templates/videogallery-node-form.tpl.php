<div id="BasicDetails">
    <h2 class="story-title"><?php print t('Basic Details'); ?></h2>
    <?php print drupal_render($form['title']); ?>
    <?php print drupal_render($form['field_story_short_headline']); ?>
    <?php print drupal_render($form['field_story_reporter']); ?>
    <div id="reporter-details"></div>
    <?php print drupal_render($form['field_stroy_city']); ?>
    <?php print drupal_render($form['field_story_courtesy']); ?>
    <?php print drupal_render($form['field_video_anchor']); ?>
</div>
<div id="videoupload">
  <h2 class="story-title"><?php print t('Video Upload'); ?></h2>
  <div class="browse-ftp">
    <div id="itg_video_content">
        <div class="video-ftp">Server</div>
        <div class="video-local">Local Browse</div>
        <div class="ftp-server">
          <?php print drupal_render($form['video_browse_select']); ?>
        </div>
        <div class="local_browse" style="display: none">
          <span class="button browse-local">Local Browse</span>
        </div>

    </div>
</div>
  <span class="browse-ftp-click button">Browse Video</span>
  <span class="error vid-error"></span>
  <?php print drupal_render($form['field_video_duration']); ?>
  <?php print drupal_render($form['field_upload_video']); ?>
  <?php print drupal_render($form['field_story_expert_name']); ?>
  <?php print drupal_render($form['field_story_expert_description']); ?>
</div>

<div id="Imageupload">
  <h2 class="story-title"><?php print t('Image'); ?></h2>
    <?php print drupal_render($form['field_story_extra_large_image']); ?> 
    <?php print drupal_render($form['field_story_large_image']); ?>
    <?php print drupal_render($form['field_story_medium_image']); ?>
    <?php print drupal_render($form['field_story_small_image']); ?>
    <?php print drupal_render($form['field_story_extra_small_image']); ?>
</div>
<div id="SocialMedia">
  <h2 class="story-title"><?php print t('Social Media'); ?></h2>
  <?php print drupal_render($form['field_story_social_media_integ']); ?>
  <?php print drupal_render($form['field_story_facebook_narrative']); ?>
  <?php print drupal_render($form['field_story_facebook_image']); ?>
  <?php print drupal_render($form['field_story_facebook_video']); ?>
  <?php print drupal_render($form['field_story_tweet']); ?>
  <?php print drupal_render($form['field_story_tweet_image']); ?>
  <?php print drupal_render($form['field_story_posted_by_facebook']); ?>
  <?php print drupal_render($form['field_story_time_facebook']); ?>
  <?php print drupal_render($form['field_story_posted_by_twitter']); ?>
  <?php print drupal_render($form['field_story_time_twitter']); ?>
  <?php print drupal_render($form['field_story_posted_by_instagram']); ?>
  <?php print drupal_render($form['field_story_time_instagram']); ?>
  <?php print drupal_render($form['field_story_facebook_video']); ?>
  <?php print drupal_render($form['field_story_facebook_vdescripti']); ?>
  <?php print drupal_render($form['field_story_twitter_video']); ?>
  <?php print drupal_render($form['field_story_twitter_video_desc']); ?>
</div>
<div id="Configuration">
    <h2 class="story-title"><?php print t('Configuration'); ?></h2>
    <?php print drupal_render($form['field_video_configurations']); ?>
    <?php print drupal_render($form['field_story_comment_question']); ?>
    <?php print drupal_render($form['field_story_syndication']); ?>
    <?php print drupal_render($form['field_story_itg_tags']); ?>
    <?php print drupal_render($form['field_dailymotion_playlist']); ?>
    <?php print drupal_render($form['field_story_category']); ?>
    <?php print drupal_render($form['field_primary_cat_data']); ?>
    <?php print drupal_render($form['field_story_schedule_date_time']); ?>
    <?php print drupal_render($form['field_story_expires']); ?> 
    <?php print drupal_render($form['field_story_expiry_date']); ?> 
</div>
<div id="Relatedcontent">
  <h2 class="story-title">Related content</h2>
  <?php print drupal_render($form['field_common_related_content']); ?>
</div>
<h2 id="title-metatags" class="story-title"><?php print t('Meta Tags'); ?></h2>
<?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>
