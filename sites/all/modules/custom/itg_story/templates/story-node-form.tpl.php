<div class="row">
    <div class="col-md-8 itg-form-main">
        <div id="BasicDetails" class="itg-form-section-wrapper">
            <h2 class="story-title active"><?php print t('Quick File'); ?></h2>
            <div class="itg-form-section">
                <?php print drupal_render($form['field_story_type']); ?>
                <?php print drupal_render($form['field_story_magazine_story_issue']); ?>
                <?php print drupal_render($form['field_story_select_magazine']); ?>
                <?php print drupal_render($form['field_story_select_supplement']); ?>
                <?php print drupal_render($form['field_story_issue_date']); ?>
                <?php print drupal_render($form['title']); ?>
                <?php print drupal_render($form['field_emoji_position']); ?>
                <?php print drupal_render($form['field_emoji']); ?>
                <?php print drupal_render($form['field_emoji_2']); ?>
                <?php print drupal_render($form['field_story_magazine_headline']); ?>
                <?php print drupal_render($form['field_story_category']); ?>
                <?php print drupal_render($form['field_primary_cat_data']); ?>
                <?php print drupal_render($form['field_story_kicker_text']); ?> 
                <?php print drupal_render($form['field_story_magazine_kicker_text']); ?>
                <?php print drupal_render($form['body']); ?>
                <?php print drupal_render($form['field_story_reporter']); ?>
                <div id="reporter-details"></div>
                <?php print drupal_render($form['field_stroy_city']); ?>
                <?php print drupal_render($form['field_story_itg_tags']); ?>
            </div>
        </div>
        <div id="Templates" class="itg-form-section-wrapper">
            <h2 class="story-title"><?php print t('Templates'); ?></h2>
            <div class="itg-form-section hide">
                <div class="templates-tab-wrapper">
                    <?php print drupal_render($form['field_story_select_templates']); ?>
                    <div class="listicle-tab-form tab-form">
                        <?php print drupal_render($form['field_story_templates']); ?>
                        <?php print drupal_render($form['field_story_template_guru']); ?>
                        <?php print drupal_render($form['field_story_listicle']); ?>    
                    </div>
                    <div class="quote-tab-form tab-form hide">
                        <?php print drupal_render($form['field_story_quote_title']); ?>
                        <?php print drupal_render($form['field_story_quote_image']); ?>
                        <?php print drupal_render($form['field_story_template_quotes']); ?>
                    </div>            
                    <div class="factoid-tab-form tab-form hide">
                        <?php print drupal_render($form['field_story_factoids_title']); ?>
                        <?php print drupal_render($form['field_story_template_factoids']); ?>
                    </div>
                    <div class="buzz-tab-form tab-form hide">
                        <?php print drupal_render($form['field_story_template_buzz']); ?>
                    </div>
                </div>
            </div>
        </div>
        <div id="browse-image" class="itg-form-section-wrapper browse-media-file">
            <h2 class="story-title"><?php print t('Browse Image'); ?></h2>
            <div class="itg-form-section hide">
                <?php print drupal_render($form['field_story_extra_large_image']); ?>
                <div class="pre-desc"><?php print t('This image will be resized by the system into pre-defined dimensions'); ?></div>    
                <?php print drupal_render($form['field_story_large_image']); ?>
                <?php print drupal_render($form['field_story_medium_image']); ?>
                <?php print drupal_render($form['field_story_small_image']); ?>
                <?php print drupal_render($form['field_story_extra_small_image']); ?>
            </div>
        </div>
        <div id="StoryContent" class="itg-form-section-wrapper">
            <h2 class="story-title"><?php print t('More Details'); ?></h2>
            <div class="itg-form-section hide">
                <?php print drupal_render($form['field_story_short_headline']); ?>
                <?php print drupal_render($form['field_story_long_head_line']); ?>
              <!--<div class="pre-desc"><?php //print t('This title shows on the section page');       ?></div> -->

                <?php print drupal_render($form['field_story_new_title']); ?>
                <?php print drupal_render($form['field_story_redirection_url_titl']); ?>
                <?php print drupal_render($form['field_story_courtesy']); ?>
                <?php print drupal_render($form['field_story_snap_post']); ?>

                <?php print drupal_render($form['field_story_associate_lead']); ?>
                <?php print drupal_render($form['field_associate_photo_gallery']); ?>
                <?php print drupal_render($form['field_story_associate_video']); ?>
            </div>
        </div>
        <div id="ExpertChunk" class="itg-form-section-wrapper">
            <h2 class="story-title"><?php print t('Expert Chunk'); ?></h2> 
            <div class="itg-form-section hide">
                <?php print drupal_render($form['field_story_expert_name']); ?>
                <?php print drupal_render($form['field_story_expert_image']); ?>
                <?php print drupal_render($form['field_story_expertise']); ?>
                <?php print drupal_render($form['field_story_expert_description']); ?>
                <?php // print drupal_render($form['revision_information']['workbench_moderation_state_new']); ?>
                <?php // print drupal_render($form['revision_information']['log']); ?>
                <?php //unset($form['revision_information']); ?>
            </div>
        </div>

        <div id="StoryMovie" class="itg-form-section-wrapper">
            <h2 class="story-title"><?php print t('Story Movie'); ?></h2> 
            <div class="itg-form-section hide">
                <?php print drupal_render($form['field_story_rating']); ?>
                <?php print drupal_render($form['field_mega_review_cast']); ?>
                <?php print drupal_render($form['field_mega_review_director']); ?>
                <?php print drupal_render($form['field_mega_review_movie_plot']); ?>
            </div>
        </div>

        <div id="StoryTech" class="itg-form-section-wrapper">
            <h2 class="story-title"><?php print t('Story Technology'); ?></h2> 
            <div class="itg-form-section hide">
                <?php print drupal_render($form['field_story_technology']); ?>
                <?php print drupal_render($form['field_story_technology_rating']); ?>
                <?php print drupal_render($form['field_story_tech_review_chunk']); ?>
            </div>
        </div>

        <div id="StoryPhoto" class="itg-form-section-wrapper">
            <h2 class="story-title"><?php print t('Photo Story'); ?></h2> 
            <div class="itg-form-section hide">
                <?php print drupal_render($form['field_photo_story']); ?>
            </div>
        </div>

        <div class="itg-form-action">
            <?php print drupal_render($form['actions']); ?>
        </div>
    </div>
    <div class="col-md-4">
        <div class="itg-sidebar-form">
            <div id="Briefcase" class="itg-sidebar-form-section">
                <h2 class="story-title active"><?php print t('Section/Category'); ?></h2>
                <div class="itg-form-section">
                    <?php print drupal_render($form['category_holder']); ?>
                </div>
            </div>

            <div id="Briefcase" class="itg-sidebar-form-section">
                <h2 class="story-title"><?php print t('Highlights'); ?></h2>
                <div class="itg-form-section hide">
                    <?php print drupal_render($form['field_story_highlights']); ?>
                </div>
            </div>
            <div id="Configuration" class="itg-sidebar-form-section">
                <h2 class="story-title"><?php
                    print t('Configuration');
                    ?></h2>
                <div class="itg-form-section hide">
                    <?php print drupal_render($form['field_story_configurations']); ?>
                    <?php print drupal_render($form['field_story_comment_question']); ?>
                    <?php print drupal_render($form['field_poll_start_date']); ?>
                    <?php print drupal_render($form['field_story_tv_time']); ?>
                    <?php print drupal_render($form['field_story_featured_name']); ?>
                    <?php print drupal_render($form['field_story_syndication']); ?>
                    <?php print drupal_render($form['field_story_syndications_photo']); ?>
                    <?php print drupal_render($form['field_story_client_title']); ?>
                    <?php print drupal_render($form['field_story_media_files_syndicat']); ?>
                    <?php print drupal_render($form['field_common_related_content']); ?>
                </div>
            </div>
            <div id="DateTime" class="itg-sidebar-form-section">
                <h2 class="story-title"><?php print t('Date & Time'); ?></h2>
                <div class="itg-form-section hide">
                    <?php print drupal_render($form['field_story_schedule_date_time']); ?>
                    <?php print drupal_render($form['field_story_expires']); ?> 
                    <?php print drupal_render($form['field_story_expiry_date']); ?> 
                </div>
            </div>
            <div id="SocialMedia" class="itg-sidebar-form-section">
                <h2 class="story-title"><?php print t('Social Media'); ?></h2>
                <div class="itg-form-section hide">
                    <?php print drupal_render($form['field_story_social_media_integ']); ?>
                    <!-- Facebook fields -->
                    <?php print drupal_render($form['field_story_facebook_narrative']); ?>
                    <?php print drupal_render($form['field_story_facebook_image']); ?>
                    <?php print drupal_render($form['field_story_facebook_video']); ?>                    <!-- Facebook Instant Article -->
                    <?php print drupal_render($form['field_facebook_audio_position']); ?>
                    <?php print drupal_render($form['field_facebook_instant_audio_url']); ?>
                    <?php print drupal_render($form['field_story_big_image']); ?>

                    <?php print drupal_render($form['field_animated_image_position']); ?>
                    <?php print drupal_render($form['field_facebook_animated_image']); ?>
                    <?php print drupal_render($form['field_facebook_map_position']); ?>
                    <?php print drupal_render($form['field_map_embed_code']); ?>
                    <?php print drupal_render($form['field_facebook_gallery_associate']); ?>
                    <?php print drupal_render($form['field_social_embed_code_position']); ?>
                    <?php print drupal_render($form['field_social_embed_code']); ?>

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

