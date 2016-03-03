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
      <?php //print render($content) ?>
      <?php if ($view_mode == 'full'): ?>
          <div class="content-node-view">            
            <?php //print render($content); ?>
              <div class="content-node-view">
                <h2>Basic Details</h2>
                    <div class="content-view">
                        <?php print render($content['field_astro_frequency']); ?>
                        <?php print render($content['field_astro_date_range']); ?>
                        <?php print render($content['field_story_category']); ?>
                    </div>
              </div>
              <div class="content-node-view">
                <h2>Zodiac Sign</h2>
                    <div class="content-view">                      
                      <?php $field_collection_item = 135; ?>                           
                      <?php for ($i = 0; $i <= 11; ++$i): ?>                         
                        <?php $name = itg_common_sunsign_name($i); ?>
                        <div class="root-label">
                        <?php print '<div class="field-label">'.$name.': </div>'; ?>                        
                        <?php print render($content['field_astro_zodiac'][$i]['entity']['field_collection_item'][$field_collection_item]['field_buzz_description']); ?>                            
                        <?php print '<div class="field-label">'.$name.' Thumbnail Icon: </div>'; ?>  
                        <?php $fid = $content['field_astro_zodiac'][$i]['entity']['field_collection_item'][$field_collection_item]['field_astro_thumb_icon'][0]['#item']['fid'];?>    
                        <?php $imgSrc = _itg_photogallery_fid($fid); ?>
                        <?php $style = 'photogallery_slide'; ?>    
                        <img src="<?php echo image_style_url($style, $imgSrc); ?>" />                         
                        <?php $audioFid = $content['field_astro_zodiac'][$i]['entity']['field_collection_item'][$field_collection_item]['field_audio'][0]['#file']->fid; ?>                                      
                        <?php $audioURL = _itg_photogallery_fid($audioFid); ?>
                        <?php if (isset($audioFid) && $audioFid != ''): ?> 
                          <?php print '<div class="field-label">'.$name.' Audio: </div>'; ?>                            
                          <img class="file-icon" src="/indiatoday/modules/file/icons/audio-x-generic.png" title="audio/mpeg" alt="Audio icon">                          
                          <a type="audio/mpeg; length=226115" href="<?php echo file_create_url($audioURL); ?>"><?php echo itg_common_file_name();?></a>
                          
                        <?php endif; ?>
                        <?php print '<div class="field-label">'.$name.' Video: </div>'; ?>  
                        <?php print render($content['field_astro_zodiac'][$i]['entity']['field_collection_item'][$field_collection_item]['field_astro_video']); ?>
                        <?php $field_collection_item++; ?>
                        </div>
                      <?php endfor; ?>  
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

