<?php
/**
 * @file
 * Theme implementation for Breaking News form in tab display.
 * 
 */
//p($page);
?>
<!--<div class=""><?php //print drupal_render($form['actions']); ?></div>-->

<div id="BreakingNewsBasicDetails">
  <h2 class="breaking-title">Basic Details</h2>
  <?php print drupal_render($form['field_type']); ?>
  <?php print drupal_render($form['field_story_expires']); ?>
  <?php print drupal_render($form['field_story_snap_post']); ?>
  <?php print drupal_render($form['field_constituancy']); ?>
  <?php //print drupal_render($form['field_content_type']); ?>
  <?php print drupal_render($form['title']); ?>
           </div>

<div id="ContentDetails">
    <?php print drupal_render($form['field_breaking_content_details']); ?>
     </div>

<div id="Shortdescriptions">
    <?php print drupal_render($form['field_common_short_description']); ?>
        </div>


<div id="DisplayOn">
  <?php print drupal_render($form['field_breaking_display_on']); ?>
  <?php print drupal_render($form['field_section']); ?>
             </div>
<?php print drupal_render($form['field_story_itg_tags']); ?>

<div id="BrowseMedia" class='browse-media-file'>
  <h2 class="story-title">Browse Media</h2>
  <?php print drupal_render($form['field_story_extra_large_image']); ?>
  <p class="pre-desc">This image will be resized by the system into pre-defined dimensions</p>
  <?php print drupal_render($form['field_story_large_image']); ?>
  <?php print drupal_render($form['field_story_medium_image']); ?>
  <?php print drupal_render($form['field_story_small_image']); ?>
  <?php print drupal_render($form['field_story_extra_small_image']); ?>
</div>

<div id="Highlights">
  <h2 class="highlight-title">Highlights</h2>
  <?php print drupal_render($form['field_story_highlights']); ?>
</div>

  <div id="AkamaiSettings" class="itg-sidebar-form-section">
                <h2 class="story-title"><?php print t('Akamai Setting'); ?></h2>
                <div class="itg-form-section">
                    <?php print drupal_render($form['akamai_timeout']); ?>
                </div>
          </div>

<!--<div id="Relatedcontent">
  <h2 class="story-title">Related content</h2>
  <?php //print drupal_render($form['field_common_related_content']); ?>
</div>-->


<!--<h2 id="title-metatags" class="story-title"><?php //echo t('SEO Meta Tags'); ?></h2>-->

 <?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>
