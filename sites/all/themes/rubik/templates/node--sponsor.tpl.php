<a href="javascript:;" class="close-preview">&nbsp;</a>
<?php if (!empty($pre_object)) print render($pre_object) ?>
<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
    <div class='column-side'><div class='column-wrapper'>
      <?php endif; ?>

      <?php if (!empty($submitted)): ?>
        <div class='<?php print $hook ?>-submitted clearfix'><?php print $submitted ?></div>
      <?php endif; ?>
      <!-- add && !$teaser for hide comment link -->
      <?php if (!empty($links) && !$teaser): ?>
        <div class='<?php print $hook ?>-links clearfix'>
          <?php print render($links) ?>
        </div>
      <?php endif; ?>

      <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
      </div>
    </div>
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
          <?php if ($view_mode == 'full'): ?>
            <div class="content-node-view">
              <div class="basic-details content-box">
                <h2><?php echo t('Basic Details'); ?></h2>
                <div class="content-details">
                  <div class="field">
                    <div class="field-label"><?php echo t('Sponsor'); ?>:</div>
                    <div class="field-items"><?php print $title; ?></div>
                  </div>
                 
                  <?php
                  $field_sponser_logo = render($content['field_sponser_logo']);
                  if (!empty($field_sponser_logo)): print render($content['field_sponser_logo']);
                  endif;
                  ?>
                  <?php
                  $body = render($content['body']);
                  if (!empty($body)): print render($content['body']);
                  endif;
                  ?>
                </div>
              </div>
            </div>
          <?php endif; ?>

        </div>
<?php endif; ?>

      <?php if ($layout): ?>
      </div></div>
      <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>
