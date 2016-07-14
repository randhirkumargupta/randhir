  <?php if (!empty($content)): ?>
  <div class='<?php print $classes ?>'>
      <?php if ($view_mode == 'full'): ?>
      
        <?php  if ($node->op = 'Preview'):?>
        <a href="javascript:;" class="close-preview">&nbsp;</a>
        <?php endif; ?>
      
       
        <div class="basic-details content-box">
            <h2><?php print t('Basic Details'); ?></h2>
            <div class="content-details">
                 <div class="field">
                    <div class="field-label"><?php print t('Audio Title:'); ?></div>
                    <div class="field-items"><?php print $title; ?></div>
                </div>
                <?php print render($content['field_story_short_headline']); ?>
                <?php print render($content['field_story_kicker_text']); ?>
            </div>
        </div>
        
            <?php // if ($node->op != 'Preview'):?>
        <div class="Story-details">
            <h2><?php print t('Audio Upload'); ?></h2>
            <div class="content-details">
                <?php print render($content['field_podcast_audio_upload']); ?>
            </div>
        </div> 
        <?php // endif;   ?>
        
         <?php
    $browsemedia = render($content['field_story_extra_large_image']);
    if (!empty($browsemedia)):
      ?>
      <div class="BrowseMedia">
        <h2>Image Upload </h2>
        <div class="content-details">
          <?php print render($content['field_story_extra_large_image']); ?>
        </div>
      </div>
    <?php endif; ?>
      
     
        
        <?php
        $configuration = render($content['field_story_itg_tags']);
        if (!empty($configuration)):
          ?>
          <div class="configuration content-box">
              <h2><?php print t('Configuration'); ?></h2>
              <div class="content-details"><?php print render($content['field_story_itg_tags']); ?></div>
           </div>

        <?php endif; ?>
       
            
        <?php
        $field_story_category = render($content['field_story_category']);
        if (!empty($field_story_category)): ?>
      <?php print render($content['field_story_category']); ?>
        <?php endif; ?>
    
            
 <?php endif; // end of view mode full condition ?></div>
           
<?php endif; ?>