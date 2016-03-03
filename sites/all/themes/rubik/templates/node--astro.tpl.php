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
        <?php global $base_url; ?>
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
                        <div class="field-item">    
                          <img src="<?php echo image_style_url($style, $imgSrc); ?>" />                         
                        </div>
                        <?php $audio_fid = isset($content['field_astro_zodiac'][$i]['entity']['field_collection_item'][$field_collection_item]['field_audio'][0]['#file']->fid) ? $content['field_astro_zodiac'][$i]['entity']['field_collection_item'][$field_collection_item]['field_audio'][0]['#file']->fid : NULL; ?>                                      
                        <?php if (isset($audio_fid) && $audio_fid != ''): ?> 
                          <?php $audio_url = _itg_photogallery_fid($audio_fid); ?>                        
                          <?php print '<div class="field-label">'.$name.' Audio: </div>'; ?>                            
                          <div class="field-item">    
                          <img class="file-icon" src="<?php echo $base_url; ?>/modules/file/icons/audio-x-generic.png" title="audio/mpeg" alt="Audio icon">                                    
                          <a type="audio/mpeg; length=226115" href="<?php echo file_create_url($audio_url); ?>"><?php echo itg_common_file_name($audio_fid);?></a>                          
                          </div>
                        <?php endif; ?>
                        <?php $video_fid = isset($content['field_astro_zodiac'][$i]['entity']['field_collection_item'][$field_collection_item]['field_astro_video'][0]['#file']->fid) ? $content['field_astro_zodiac'][$i]['entity']['field_collection_item'][$field_collection_item]['field_astro_video'][0]['#file']->fid : NULL; ?>                                      
                        <?php if (isset($video_fid) && $video_fid != NULL ): ?>   
                          <?php $video_url = _itg_photogallery_fid($video_fid); ?>                        
                          <?php print '<div class="field-label">'.$name.' Video: </div>'; ?>                            
                          <div class="field-item">  
                          <img class="file-icon" src="<?php echo $base_url; ?>/modules/file/icons/video-x-generic.png" title="audio/mpeg" alt="Audio icon">                                    
                          <a type="video/mp4" href="<?php echo file_create_url($video_url); ?>"><?php echo itg_common_file_name($audio_fid);?></a>
                          </div>
                        <?php endif; ?>  
                        <?php $field_collection_item++; ?>
                        </div>
                      <?php endfor; ?>  
                    </div>
              </div>
              <div class="content-node-view">
                <h2>Collective Content</h2>
                    <div class="content-view">
                        <?php
                        print render($content['field_buzz_description']);
                        print render($content['field_astro_video']);
                        print render($content['field_common_audio_file']);
                        ?>
                    </div>
              </div>
              <div class="content-node-view">
                <h2>Numerology</h2>
                    <div class="content-view">                  
                        <?php print render($content['field_numerology']); ?>
                        <?php if ($content['field_numerology'][0]['#markup'] == 'Yes'): ?>
                          <?php print render($content['field_astro_frequency2']); ?>
                          <?php print render($content['field_field_astro_date_range2']); ?>                          
                          <?php
                            $count = count($content['field_astro_numerology_values']['#items']);
                            for ($i = 0; $i < $count; ++$i) {
                              print '<div class="root-label">';
                              print '<div class="field-label">Number: </div>';
                              print '<div class="field-items">';
                              print $content['field_astro_numerology_values']['#items'][$i]['field_story_source_id']['und'][0]['value'];
                              print '</div>';
                              print '<div class="field-label">Text: </div>';
                              print '<div class="field-items">';
                              print $content['field_astro_numerology_values']['#items'][$i]['field_buzz_description']['und'][0]['value'];
                              print '</div>';
                              $fid = isset($content['field_astro_numerology_values']['#items'][$i]['field_common_audio_file']['und'][0]['fid']) ? $content['field_astro_numerology_values']['#items'][$i]['field_common_audio_file']['und'][0]['fid']: NULL;    
                              if ($fid != NULL) {
                                print '<div class="field-label">Audio: </div>'; 
                                $audio_url = _itg_photogallery_fid($fid);
                                $output = '';
                                $output .= '<div class="field-item">';
                                $output = '<img class="file-icon" src="/indiatoday/modules/file/icons/audio-x-generic.png" title="audio/mpeg" alt="Audio icon">';                                    
                                $output .= '<a type="audio/mpeg; length=226115" href="'. file_create_url($audio_url).'">'.itg_common_file_name($fid).'</a>';                          
                                $output .= '</div>';
                                print $output;
                              }
                              $video_fid = isset($content['field_astro_numerology_values']['#items'][$i]['field_astro_video']['und'][0]['fid']) ? $content['field_astro_numerology_values']['#items'][$i]['field_astro_video']['und'][0]['fid']: NULL;
                              if (isset($video_fid) && $video_fid != NULL) {
                                print '<div class="field-label">Video: </div>'; 
                                $video_url = _itg_photogallery_fid($video_fid);
                                $output = '';
                                $output .= '<div class="field-item">';
                                $output = '<img class="file-icon" src="'.$base_url.'/modules/file/icons/video-x-generic.png" title="audio/mpeg" alt="Audio icon">';                                    
                                $output .= '<a type="video/mpeg; length=226115" href="'. file_create_url($video_url).'"> '.itg_common_file_name($video_fid).'</a>';                          
                                $output .= '</div>';
                                print $output;
                              }
                              print '</div>';
                            }
                          ?>
                        <?php endif; ?>                        
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

