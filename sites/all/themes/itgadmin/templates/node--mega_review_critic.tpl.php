<a href="javascript:;" class="close-preview">&nbsp;</a>
<?php if (!empty($pre_object)) print render($pre_object) ?>

<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
    <div class='column-side'><div class='column-wrapper'>
  <?php endif; ?>

  <?php if (!empty($submitted)): ?>
    <div class='<?php print $hook ?>-submitted clearfix'><?php print $submitted ?></div>
  <?php endif; ?>

  <?php if (!empty($links)): ?>
    <div class='<?php print $hook ?>-links clearfix'>
      <?php print render($links) ?>
    </div>
  <?php endif; ?>

  <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
    </div></div>
  <?php endif; ?>

  <?php if ($layout): ?>
    <div class='column-main'><div class='column-wrapper'>
  <?php endif; ?>

  <?php if (!empty($title_prefix)) print render($title_prefix); ?>

  <?php if (!empty($title) && !$page): ?>
    <h2 <?php if (!empty($title_attributes)) print $title_attributes ?>>
      <?php if (!empty($new)): ?><span class='new'><?php print $new ?></span><?php endif; ?>
      <a href="<?php print $node_url ?>"><?php print $title ?></a>
    </h2>
  <?php endif; ?>

  <?php if (!empty($title_suffix)) print render($title_suffix); ?>

  <?php if (!empty($content)): ?>
    <div class='<?php print $hook ?>-content clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
      
<!--      for preview-->
      <?php if ($view_mode == 'full') { ?>
        <div class="field">
          <div class="field-label"><?php print t('Movie Title:'); ?></div>
          <div class="field-items"><?php print render($title); ?></div>
        </div>
        <?php print render($content['field_mega_review_cast']); ?>
        <?php print render($content['field_mega_review_type']); ?>
        <?php print render($content['field_mega_review_director']); ?>
        <?php print render($content['field_mega_review_movie_plot']); ?>
        <?php print render($content['field_mega_review_youtube_url']); ?>
        <?php print render($content['field_mega_review_photo_gallery']); ?>
        <?php print render($content['field_mega_review_twitter']); ?>
        <?php print render($content['field_story_extra_large_image']); ?>
        
        <?php print render($content['field_mega_review_video']); ?>
        <?php print render($content['field_mega_review_review']); ?>
        
      <?php } else { ?>
      <?php print render($content) ?>
      <?php } ?>
<!--end preview-->
    </div>
  <?php endif; ?>

  <?php if ($layout): ?>
    </div></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>

