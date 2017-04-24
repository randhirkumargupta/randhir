<div class="row">
    <div class="col-md-8 itg-form-main">
        <div id="BasicDetails" class="itg-form-section-wrapper">
            <h2 class="story-title active"><?php print t('Basic Details'); ?></h2>
            <div class="itg-form-section">
                <?php print drupal_render($form['title']); ?>
                <?php print drupal_render($form['field_story_short_headline']); ?>
                <?php print drupal_render($form['field_story_category']); ?>
                <?php print drupal_render($form['field_primary_cat_data']); ?>
                <?php print drupal_render($form['field_story_reporter']); ?>
                <div id="reporter-details"></div>
                <?php print drupal_render($form['field_stroy_city']); ?>
                <?php print drupal_render($form['field_story_itg_tags']); ?>
                <?php print drupal_render($form['field_story_courtesy']); ?>
                <?php print drupal_render($form['field_video_anchor']); ?>
            </div>
        </div>

        <div id="videoupload" class="itg-form-section-wrapper">
            <h2 class="story-title"><?php print t('Video Upload'); ?></h2>
            <div class="itg-form-section hide">
                <div class="browse-ftp">
                    <div id="itg_video_content">
                        <div class="video-ftp active"><?php print t('Server'); ?></div>
                        <div class="video-local"><?php print t('Local Browse'); ?></div>
                        <div id="loader-data"><img class="widget-loader" style="display: none" align="center" src="<?php echo base_path(); ?>/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." /></div>

                        <div class="ftp-server">
                            <div class="video_filters">
                                <label><?php echo t('Filter') ?>:</label><select class="used-unused-select">
                                    <option value="unused"><?php print t("Un Published"); ?></option>
                                    <option value="used"><?php print t("Published"); ?></option>
                                </select>
                                <div class="time-filter">
                                    <label><?php echo t('Select Time') ?>:</label><select class="time-filter-select">
                                        <option value="-all-"><?php print t("All"); ?></option>  
                                        <option value="2"><?php print t("2 Hours"); ?></option>
                                        <option value="4"><?php print t("4 Hours"); ?></option>
                                        <option value="6"><?php print t("6 Hours"); ?></option>
                                        <option value="10"><?php print t("10 Hours"); ?></option>
                                        <option value="24"><?php print t("24 Hours"); ?></option>
                                    </select>
                                </div>
                            </div>
                            <div class="video-options-wrapper"></div>
                            <a href="javascript:void(0)" class = "button"><?php print t('Attach Video'); ?></a>
                        </div>  
                        <?php //print drupal_render($form['video_browse_select']); ?>
                        <div class="local_browse" style="display: none">
                            <span class="button browse-local"><?php print t('Browse Video'); ?></span>
                        </div>
                    </div>
                </div>
                <?php print drupal_render($form['field_video_duration']); ?>
                <div class="browse-video-form"><?php print drupal_render($form['field_video_upload']); ?>
        <!--          <div class="ftp_browse_field"><label for="edit-field-upload-video-und-0-upload">Video <span title="This field is required." class="form-required">*</span></label><span class="browse-ftp-click">Browse Video</span></div>-->
                    <span class="error vid-error"></span>
                </div>
                <?php //print drupal_render($form['field_story_expert_name']); ?>
                <?php print drupal_render($form['field_video_kicker']); ?>
                <?php print drupal_render($form['field_story_expert_description']); ?>
            </div>
        </div>

        <div id="Imageupload" class="itg-form-section-wrapper browse-media-file">
            <h2 class="story-title"><?php print t('Image'); ?></h2>
            <div class="itg-form-section hide">
                <?php print drupal_render($form['field_story_extra_large_image']); ?> 
                <?php print drupal_render($form['field_story_player_image']); ?> 
                <?php print drupal_render($form['field_story_large_image']); ?>
                <?php print drupal_render($form['field_story_medium_image']); ?>
                <?php print drupal_render($form['field_story_small_image']); ?>
                <?php print drupal_render($form['field_story_extra_small_image']); ?>
            </div>
        </div>
        <div class="itg-form-action"><?php print drupal_render($form['actions']); ?></div>
    </div>


    <div class="col-md-4">
        <div class="itg-sidebar-form">
            <div id="Sidebarsectioncategory" class="itg-sidebar-form-section">
                <h2 class="story-title active"><?php print t('Section/Category'); ?></h2>
                <div class="itg-form-section">
                    <?php print drupal_render($form['category_holder']); ?>
                </div>
            </div>
          
            <div id="Configuration" class="itg-sidebar-form-section">
                <h2 class="story-title"><?php print t('Configuration'); ?></h2>
                <div class="itg-form-section hide">
                <?php print drupal_render($form['field_video_configurations']); ?>
                <?php print drupal_render($form['field_story_comment_question']); ?>
                <?php print drupal_render($form['field_story_syndication']); ?>
                <?php print drupal_render($form['field_dailymotion_playlist']); ?>
                <?php print drupal_render($form['field_story_schedule_date_time']); ?>
                <?php print drupal_render($form['field_story_expires']); ?> 
                <?php print drupal_render($form['field_story_expiry_date']); ?> 
                <?php print drupal_render($form['field_common_related_content']); ?>
                </div>
            </div>
            <div id="SocialMedia" class="itg-sidebar-form-section image-repo-browse">
                <h2 class="story-title"><?php print t('Social Media'); ?></h2>
                <div class="itg-form-section hide">
                <?php print drupal_render($form['field_story_social_media_integ']); ?>
                <!-- Facebook fields -->     
                <?php print drupal_render($form['field_story_facebook_narrative']); ?>
                <?php print drupal_render($form['field_story_facebook_image']); ?>
                <?php print drupal_render($form['field_story_facebook_video']); ?>
                <!-- Twitter fields -->
                <?php print drupal_render($form['field_story_tweet']); ?>
                <?php print drupal_render($form['field_story_tweet_image']); ?>
                <?php print drupal_render($form['field_story_twitter_video']); ?>                                
                </div>
            </div>
          
             <div id="AkamaiSettings" class="itg-sidebar-form-section">
                <h2 class="story-title"><?php print t('Akamai Setting'); ?></h2>
                <div class="itg-form-section hide">
                    <?php print drupal_render($form['akamai_timeout']); ?>
                </div>
          </div>
            <div class="metatags-and-remarks">
                <h2 id="title-metatags" class="story-title"><?php print t('Remarks'); ?></h2>
                <?php print drupal_render_children($form); ?>
            </div>
        </div>

    </div>
</div>







