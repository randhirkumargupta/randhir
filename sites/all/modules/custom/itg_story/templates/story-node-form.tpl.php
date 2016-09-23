<div class="row">
  <div class="col-md-8 itg-form-main">
    <div id="BasicDetails" class="itg-form-section-wrapper">
      <h2 class="story-title active"><?php print t('Quick File'); ?></h2>
      <div class="itg-form-section">
        <?php print drupal_render($form['field_story_magazine_story_issue']); ?>
        <?php print drupal_render($form['field_story_select_magazine']); ?>
        <?php print drupal_render($form['field_story_select_supplement']); ?>
        <?php print drupal_render($form['field_story_issue_date']); ?>
        <?php print drupal_render($form['title']); ?>
        <?php print drupal_render($form['field_story_reporter']); ?>
        <div id="reporter-details"></div>
        <?php print drupal_render($form['field_stroy_city']); ?>
        <?php print drupal_render($form['field_story_category']); ?>
        <?php print drupal_render($form['field_primary_cat_data']); ?>
        <?php print drupal_render($form['field_story_extra_large_image']); ?>
        <div class="pre-desc"><?php print t('This image will be resized by the system into pre-defined dimensions'); ?></div>    
        <?php print drupal_render($form['field_story_large_image']); ?>
        <?php print drupal_render($form['field_story_medium_image']); ?>
        <?php print drupal_render($form['field_story_small_image']); ?>
        <?php print drupal_render($form['field_story_extra_small_image']); ?>
        <?php print drupal_render($form['field_story_kicker_text']); ?> 
        <?php print drupal_render($form['body']); ?>
        <?php print drupal_render($form['field_story_magazine_kicker_text']); ?>
        <?php print drupal_render($form['field_story_magazine_headline']); ?>
        <?php print drupal_render($form['field_story_itg_tags']); ?>
      </div>
    </div>
    <div id="Templates" class="itg-form-section-wrapper">
      <h2 class="story-title"><?php print t('Templates'); ?></h2>
      <div class="itg-form-section hide">
        <?php print drupal_render($form['field_story_templates']); ?>
        <?php print drupal_render($form['field_story_template_guru']); ?>
        <?php print drupal_render($form['field_story_template_quotes']); ?>
        <?php print drupal_render($form['field_story_template_factoids']); ?>
        <?php print drupal_render($form['field_story_template_buzz']); ?>
      </div>
    </div>
    <div id="StoryContent" class="itg-form-section-wrapper">
      <h2 class="story-title"><?php print t('More Details'); ?></h2>
      <div class="itg-form-section hide">
        <?php print drupal_render($form['field_story_short_headline']); ?>
        <?php print drupal_render($form['field_story_long_head_line']); ?>
        <!--<div class="pre-desc"><?php //print t('This title shows on the section page');    ?></div> -->
        <?php print drupal_render($form['field_story_rating']); ?>
        <?php print drupal_render($form['field_story_new_title']); ?>
        <?php print drupal_render($form['field_story_redirection_url_titl']); ?>
        <?php print drupal_render($form['field_story_courtesy']); ?>
        <?php print drupal_render($form['field_story_snap_post']); ?>
      </div>
    </div>
    <div id="ExpertChunk" class="itg-form-section-wrapper">
      <h2 class="story-title"><?php print t('Expert Chunk'); ?></h2> 
      <div class="itg-form-section hide">
        <?php print drupal_render($form['field_story_expert_name']); ?>
        <?php print drupal_render($form['field_story_expert_image']); ?>
        <?php print drupal_render($form['field_story_expert_description']); ?>
        <?php // print drupal_render($form['revision_information']['workbench_moderation_state_new']); ?>
        <?php // print drupal_render($form['revision_information']['log']); ?>
        <?php //unset($form['revision_information']); ?>
      </div>
    </div>
    <div class="itg-form-action">
      <?php print drupal_render($form['actions']); ?>
    </div>
  </div>
  <div class="col-md-4">
    <div class="itg-sidebar-form">
      <div id="Briefcase" class="itg-sidebar-form-section">
        <h2 class="story-title"><?php print t('Brief case'); ?></h2>
        <?php print drupal_render($form['field_story_highlights']); ?>
      </div>
      <div id="Configuration" class="itg-sidebar-form-section">
        <h2 class="story-title"><?php print t('Configuration'); ?></h2>
        <?php print drupal_render($form['field_story_configurations']); ?>
        <?php print drupal_render($form['field_poll_start_date']); ?>
        <?php print drupal_render($form['field_story_tv_time']); ?>
        <?php print drupal_render($form['field_story_featured_name']); ?>
        <?php print drupal_render($form['field_story_syndication']); ?>
        <?php print drupal_render($form['field_story_comment_question']); ?>
        <?php print drupal_render($form['field_story_client_title']); ?>
        <?php print drupal_render($form['field_story_media_files_syndicat']); ?>
        <?php print drupal_render($form['field_common_related_content']); ?>
      </div>
      <div id="DateTime" class="itg-sidebar-form-section">
        <h2 class="story-title"><?php print t('Date & Time'); ?></h2>
        <?php print drupal_render($form['field_story_schedule_date_time']); ?>
        <?php print drupal_render($form['field_story_expires']); ?> 
        <?php print drupal_render($form['field_story_expiry_date']); ?> 
      </div>
      <div id="SocialMedia" class="itg-sidebar-form-section">
        <h2 class="story-title"><?php print t('Social Media'); ?></h2>
        <?php print drupal_render($form['field_story_social_media_integ']); ?>
        <!-- Facebook fields -->
        <?php print drupal_render($form['field_story_facebook_narrative']); ?>
        <?php print drupal_render($form['field_story_facebook_image']); ?>
        <?php print drupal_render($form['field_story_facebook_vdescripti']); ?>
        <?php print drupal_render($form['field_story_facebook_video']); ?>
        <!-- Twitter fields -->
        <?php print drupal_render($form['field_story_tweet']); ?>
        <?php print drupal_render($form['field_story_tweet_image']); ?>  
        <?php print drupal_render($form['field_story_twitter_video_desc']); ?>  
        <?php print drupal_render($form['field_story_twitter_video']); ?>  
      </div>
      <div class="metatags-and-remarks">
      <h2 id="title-metatags" class="story-title"><?php print t('Remarks'); ?></h2>
      <?php print drupal_render_children($form); ?>
      </div>
    </div>
  </div>
</div>

