<div id="basicdetails">
    <?php print drupal_render($form['group_review_basic_settings']); ?>
    <?php print drupal_render($form['title']); ?>
    <?php print drupal_render($form['field_story_movie_description']); ?>
    <?php print drupal_render($form['field_mega_review_type']); ?>
    <?php print drupal_render($form['field_mega_review_cast']); ?>
    <?php print drupal_render($form['field_mega_review_career_graph']); ?>
    <?php print drupal_render($form['field_mega_review_director']); ?>
    <?php print drupal_render($form['field_mega_review_movie_plot']); ?>
    <?php print drupal_render($form['field_mega_review_youtube_url']); ?>
    <?php print drupal_render($form['field_story_associate_video']); ?>
    <?php print drupal_render($form['field_associate_photo_gallery']); ?>
    <?php print drupal_render($form['field_mega_review_twitter']); ?>
</div>


<div id="SectionCategory">
 <?php print drupal_render($form['group_review_section']); ?>
 <div class="itg-form-section">
  <?php print drupal_render($form['category_holder']); ?>
 </div>
</div>

<div id="browsemedia" class="browse-media-file">
    <?php print drupal_render($form['group_review_browse_media']); ?> 
    <?php print drupal_render($form['field_story_extra_large_image']); ?> 
    <?php print drupal_render($form['field_story_large_image']); ?>
    <?php print drupal_render($form['field_story_medium_image']); ?>
    <?php print drupal_render($form['field_story_small_image']); ?>
    <?php print drupal_render($form['field_story_extra_small_image']); ?>
</div>

<div id="moviereview">
    <?php print drupal_render($form['group_review_movie_review']); ?> 
    <?php print drupal_render($form['field_mega_review_review']); ?> 
</div>

<?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>

