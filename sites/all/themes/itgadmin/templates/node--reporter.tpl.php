<?php if (!empty($content)): ?>
  <div class='<?php print $classes ?>'>
    <?php //print render($content) ?>
    <?php if ($view_mode == 'full'): ?>
      <a href="javascript:;" class="close-preview">&nbsp;</a>
      <?php
          if(!empty($node->title)) {
          ?>
            <div class="field">
            <div class="field-label"><?php print t('Name:'); ?></div>
            <div class="field-items"><?php print $node->title; ?></div>
          </div>
          <?php  
          }
          ?>
       <?php
          if(!empty($node->field_reporter_email_id[LANGUAGE_NONE][0][value])) {
          ?>
            <div class="field">
            <div class="field-label"><?php print t('Email:'); ?></div>
            <div class="field-items"><?php print $node->field_reporter_email_id[LANGUAGE_NONE][0][value]; ?></div>
          </div>
          <?php  
          }
          ?>
      <?php
          if(!empty($node->field_reporter_twitter_handle[LANGUAGE_NONE][0][value])) {
          ?>
            <div class="field">
            <div class="field-label"><?php print t('Twitter Handle:'); ?></div>
            <div class="field-items"><?php print $node->field_reporter_twitter_handle[LANGUAGE_NONE][0][value]; ?></div>
          </div>
          <?php  
          }
          ?>
      <?php
          if(!empty($node->field_story_expert_name[LANGUAGE_NONE][0][value])) {
          ?>
            <div class="field">
            <div class="field-label"><?php print t('Facebook Page:'); ?></div>
            <div class="field-items"><?php print $node->field_story_expert_name[LANGUAGE_NONE][0][value]; ?></div>
          </div>
          <?php  
          }
          ?>
      
      
      <?php
          $occupation = $content['field_celebrity_pro_occupation'];
          if (!empty($occupation)) {
            print render($content['field_celebrity_pro_occupation']);
          }
          ?>
      
      <?php
          $extra_large = $content['field_story_extra_large_image'];
          if (!empty($extra_large)) {
            print render($content['field_story_extra_large_image']);
          }
          ?>
      <?php
          if(!empty($node->body[LANGUAGE_NONE][0][value])) {
          ?>
            <div class="field">
            <div class="field-label"><?php print t('About:'); ?></div>
            <div class="field-items"><?php print $node->body[LANGUAGE_NONE][0][value]; ?></div>
          </div>
          <?php  
          }
          ?>

  <?php endif; // end of view mode full condition ?>
  </div>
<?php endif; ?>


