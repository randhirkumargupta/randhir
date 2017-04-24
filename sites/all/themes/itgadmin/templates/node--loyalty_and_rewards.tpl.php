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
        <?php if ($view_mode == 'full'): ?>
          <a href="javascript:;" class="close-preview">&nbsp;</a>
          <div class='<?php print $hook ?>-content clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>             
            <?php print render($content['field_lrp_image']); ?>
            <?php print render($content['body']); ?>
            <?php print render($content['field_lrp_product_count']); ?>
            <?php print render($content['field_story_expiry_date']); ?>
            <?php print render($content['field_lrp_actual_price']); ?>
            <?php print render($content['field_lrp_discounted_price']); ?>
            <?php print render($content['field_lrp_loyalty_points']); ?>
            <?php $other_item = $content['field_poll_itg_state']['#items'][0]['value']; ?>
            <?php if (!empty($other_item) && $other_item == 1): ?>
              <div class="field">
                <div class="field-label"><?php print t('Other Item:'); ?></div>
                <div class="field-items"><?php print t('Yes'); ?></div>
              </div>
              <?php else: ?>
              <div class="field">
                <div class="field-label"><?php print t('Other Item:'); ?></div>
                <div class="field-items"><?php print t('No'); ?></div>
              </div>
            <?php endif; ?>
            <?php $sold_out = $content['field_lrp_completed']['#items'][0]['value']; ?>
            <?php if (!empty($sold_out) && $sold_out == 'Sold out'): ?>
              <div class="field">
                <div class="field-label"><?php print t('Completed(Sold out):'); ?></div>
                <div class="field-items"><?php print t('Sold Out'); ?></div>
              </div>
              <?php else: ?>
              <div class="field">
                <div class="field-label"><?php print t('Completed(Sold out) :'); ?></div>
                <div class="field-items"><?php print t('In Stock'); ?></div>
              </div>
            <?php endif; ?>
          </div>
        <?php else: ?>
          <div class='<?php print $hook ?>-content clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>        
            <?php print render($content) ?>          
          </div>
        <?php endif; ?>
      <?php endif; ?>

      <?php if ($layout): ?>
      </div></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>

