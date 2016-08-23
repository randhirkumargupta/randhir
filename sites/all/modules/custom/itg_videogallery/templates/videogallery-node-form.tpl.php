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
      <div class="video-ftp active">Server</div>
      <div class="video-local">Local Browse</div>
      <div id="loader-data"><img class="widget-loader" style="display: none" align="center" src="<?php echo base_path(); ?>/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." /></div>

      <div class="ftp-server">
        <div class="video_filters">
          <label><strong><?php echo t('Filter') ?>: </strong><select class="used-unused-select">
              <option value="unused">Un Published</option>
              <option value="used">Published</option>
            </select></label>
          <div class="time-filter">
            <label><strong><?php echo t('Select Time') ?>: </strong><select class="time-filter-select">
                <option value="-all-">All</option>  
                <option value="2">2 Hours</option>
                <option value="4">4 Hours</option>
                <option value="6">6 Hours</option>
                <option value="10">10 Hours</option>
                <option value="24">24 Hours</option>
              </select></label>
          </div>
        </div>
        <div class="video-options-wrapper"></div>
        <a href="javascript:void(0)" class = "button">Attach Video</a>
      </div>  
      <?php //print drupal_render($form['video_browse_select']); ?>
      <div class="local_browse" style="display: none">
        <span class="button browse-local">Browse Video</span>
      </div>
    </div>
  </div>
  <?php print drupal_render($form['field_video_duration']); ?>
  <div class="browse-video-form"><?php print drupal_render($form['field_upload_video']); ?>
    <div class="ftp_browse_field"><label for="edit-field-upload-video-und-0-upload">Video <span title="This field is required." class="form-required">*</span></label><span class="browse-ftp-click">Browse Video</span></div>
    <span class="error vid-error"></span>
  </div>
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
