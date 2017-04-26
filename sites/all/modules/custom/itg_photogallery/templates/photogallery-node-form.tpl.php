<?php
/**
 * @file
 * Theme implementation for story form in tab display.
 * 
 */
//p($page);
?>
<!--<div class=""><?php //print drupal_render($form['actions']);    ?></div>-->
<div class="row">
  <div class="col-md-8 itg-form-main">
    <div id="Element" class="itg-form-section-wrapper">
      <h2 class="story-title active">Gallery Basic details</h2>
      <div class="itg-form-section">
        <?php print drupal_render($form['title']); ?>
        <?php print drupal_render($form['field_story_category']); ?>
        <?php print drupal_render($form['field_primary_cat_data']); ?>
        <?php print drupal_render($form['field_gallery_kicer']); ?>
        <?php print drupal_render($form['field_story_itg_tags']); ?>
        <!--<div class="description">This title shows on the section page</div> -->
      </div>
    </div>
    <div id="BrowseMedia" class="itg-form-section-wrapper browse-media-file">
      <h2 class="story-title">Gallery Cover Image</h2>
      <div class="itg-form-section hide">
        <?php print drupal_render($form['field_story_extra_large_image']); ?>
        <p class="pre-desc">This image will be resized by the system into pre-defined dimensions</p>
        <?php print drupal_render($form['field_story_resize_extra_large']); ?>
        <?php print drupal_render($form['field_story_large_image']); ?>
        <?php print drupal_render($form['field_story_medium_image']); ?>
        <?php print drupal_render($form['field_story_small_image']); ?>
        <?php print drupal_render($form['field_story_extra_small_image']); ?>
      </div>
    </div>
    <div id="GalleryIndividualImages" class="itg-form-section-wrapper">
      <h2 class="story-title">Gallery Images Upload</h2>
      <div class="itg-form-section hide">
        <?php print drupal_render($form['field_photo_by']); ?>
        <?php print drupal_render($form['field_credit_to_all']); ?>
        <?php print drupal_render($form['field_common_audio']); ?>
        <?php print drupal_render($form['field_common_audio_file']); ?>
        <?php print drupal_render($form['field_bulk_media_upload']); ?>
        <?php print drupal_render($form['upload']); ?>
        <?php print drupal_render($form['field_credit_name']); ?>
        <?php print drupal_render($form['field_gallery_image']); ?>
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
        <h2 class="story-title">Configuration</h2>
        <div class="itg-form-section hide">
          <?php print drupal_render($form['field_featured']); ?>

          <?php print drupal_render($form['field_common_related_content']); ?>
          <?php print drupal_render($form['field_story_syndication']); ?>
          <?php print drupal_render($form['field_photogallery_configuration']); ?>
          <?php print drupal_render($form['field_story_comment_question']); ?>    
        </div>
      </div>
      <!--<div id="Categorization" class="itg-sidebar-form-section">
        <h2 class="story-title">Categorization</h2>
      <?php //print drupal_render($form['field_story_category']); ?>
      <?php //print drupal_render($form['field_primary_cat_data']); ?>
      </div>-->
      <div id="SocialMedia" class="itg-sidebar-form-section image-repo-browse">
        <h2 class="story-title"><?php print t('Social Media'); ?></h2>
        <div class="itg-form-section hide">
          <?php print drupal_render($form['field_story_social_media_integ']); ?>
          <!-- Facebook fields -->
          <?php print drupal_render($form['field_story_facebook_narrative']); ?>
          <?php print drupal_render($form['field_story_facebook_image']); ?>  
          <?php print drupal_render($form['field_story_facebook_video']); ?>

          <!-- Twitter Fields -->
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