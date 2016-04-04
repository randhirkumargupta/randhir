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
          <div class="field-label"><?php print t('Name:'); ?></div>
          <div class="field-items"><?php print render($title); ?></div>
        </div>
         <?php print render($content['field_user_picture']); ?>
        <?php print render($content['field_reporter_email_id']); ?>
        <?php print render($content['field_reporter_twitter_handle']); ?>
        <?php print render($content['field_celebrity_facebook_page']); ?>
        <?php print render($content['field_celebrity_pro_occupation']); ?>
        <?php //print render($content['field_user_picture']); ?>
        <div class="field-label"><?php print t('About:'); ?></div>
        <?php print render($content['body']); ?>        
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

