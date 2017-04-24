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
                <div class="content-details">
                  <div class="field">
                    <div class="field-label"><?php echo t('Title'); ?>:</div>
                    <div class="field-items"><?php print $title; ?></div>
                  </div>
                  <?php
                  // All fields widget will be render here

                  $field_ads_template_selection = render($content['field_ads_template_selection']);
                  if (!empty($field_ads_template_selection)): print render($content['field_ads_template_selection']);
                  endif;


                  $field_adds_code_holder = render($content['field_adds_code_holder']);
                  if (!empty($field_adds_code_holder)): print $field_adds_code_holder;
                  endif;

                  $field_code_visibility_flag = render($content['field_code_visibility_flag']);
                  if (!empty($field_code_visibility_flag)): print $field_code_visibility_flag;
                  endif;

                  $field_ads_header_script = render($content['field_ads_header_script']);
                  if (!empty($field_ads_header_script)): print $field_ads_header_script;
                  endif;

                  $field_ads_body_start = render($content['field_ads_body_start']);
                  if (!empty($field_ads_body_start)): print $field_ads_body_start;
                  endif;

                  $field_ads_body_close = render($content['field_ads_body_close']);
                  if (!empty($field_ads_body_close)): print $field_ads_body_close;
                  endif;

                  $field_ads_start_date = render($content['field_ads_start_date']);
                  if (!empty($field_ads_start_date)): print $field_ads_start_date;
                  endif;

                  $field_ads_end_date = render($content['field_ads_end_date']);
                  if (!empty($field_ads_end_date)): print $field_ads_end_date;
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
