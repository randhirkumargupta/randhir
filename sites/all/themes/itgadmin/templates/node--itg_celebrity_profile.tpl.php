<?php if (!empty($content)): ?>
  <div class='<?php print $classes ?>'>
    <?php if ($view_mode == 'full') { ?>
      <a href="javascript:;" class="close-preview">&nbsp;</a>
      <div class="field">
        <div class="field-label"><?php print t('Name:'); ?></div>
        <div class="field-items"><?php print render($title); ?></div>
      </div>
      <?php print render($content['field_user_picture']); ?>
      <?php print render($content['field_reporter_email_id']); ?>
      <?php print render($content['field_reporter_twitter_handle']); ?>
      <?php print render($content['field_celebrity_facebook_page']); ?>
      <?php print render($content['field_celebrity_pro_occupation']); ?>
      <div class="field celebrity-about">
        <div class="field-label"><?php print t('About:'); ?></div>
        <div class="field-items"><?php print render($content['body']); ?></div>        
      </div>
    <?php } else { ?>
      <?php print render($content) ?>
    <?php } ?>
  </div>
<?php endif; ?>


