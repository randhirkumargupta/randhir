<a href="javascript:;" class="close-preview">&nbsp;</a>
<?php if (!empty($pre_object)) print render($pre_object) ?>
<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
    <div class='column-side'><div class='column-wrapper'>
      <?php endif; ?>

      <?php if (!empty($submitted)): ?>
        <div class='<?php print $hook ?>-submitted clearfix'><?php print $submitted ?></div>
      <?php endif; ?>
      <?php
      //p($node);
      echo $node->moderation_history_block;
      ?>
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
          <?php
          //print render($content) 
          // print '<pre>';
          //print_r($content);
          //print '</pre>';
          ?>

          <?php if ($view_mode == 'full'): ?>
            <?php
                        // Load custom block for social media integration              
                        if (!isset($node->op)):
                          $block = module_invoke('itg_social_media', 'block_view', 'social_media_form');
                          ?>
                          <div class="itg-smi">
                              <button data-id="smi-popup" class="btn data-popup-link">Create Social media</button>
                          </div>
                          <div id="smi-popup" class="itg-popup">
                              <div class="popup-body">
                                  <a class="itg-close-popup" href="javascript:;"> Close </a>
                                  <?php print render($block['content']); ?>
                              </div>
                          </div>
                        <?php endif; ?>
            <div class="basic-details content-box">
              <h2>Basic Gallery Details</h2>
              <div class="content-details">
                <div class="field">
                  <div class="field-label"><?php print t('Gallery Title'); ?>:</div>
                  <div class="field-items"><?php print $title; ?></div>
                </div>
                <?php print render($content['field_gallery_kicer']); ?>
                <?php
                $field_headline = render($content['field_headline']);
                if (!empty($field_headline)): print render($content['field_headline']);
                endif;
                ?>
                <?php print render($content['field_photogallery_description']); ?>
              </div>
            </div>

            <?php
            $browsemedia = render($content['field_story_extra_large_image']);
            if (!empty($browsemedia)):
              ?>
              <div class="BrowseMedia">
                <h2>Gallery Cover Image </h2>
                <div class="content-details">
                  <?php print render($content['field_story_extra_large_image']); ?>
                  <?php //print render($content['field_story_large_image']); ?>
                  <?php //print render($content['field_story_medium_image']); ?>
                  <?php //print render($content['field_story_small_image']); ?>
                  <?php //print render($content['field_story_extra_small_image']); ?>
                </div>
              </div>
            <?php endif; ?>
            
            <!-- Social Media -->
            <!-- Preview case -->
            <?php if (isset($node->op) && $node->op == 'preview'): ?>
            <?php endif; ?>
            <!-- view case -->
            <?php $social_media = render($content['field_story_social_media_integ']); ?>
            <?php if (!empty($social_media)): ?>
            <div class="BrowseMedia">
                <h2>Social media </h2>
                <div class="content-details">
                <?php 
                print render($content['field_story_social_media_integ']);
                print render($content['field_story_facebook_narrative']);
                print render($content['field_story_facebook_image']);
                print render($content['field_story_tweet']);
                print render($content['field_story_tweet_image']);
                ?>
               </div>
            <?php endif; ?>
            
            <!-- Social Media Ends -->

            <?php
            $photocategory = render($content['field_story_category']);
            if (!empty($photocategory)):
              ?>
              <div class="expert-details content-box">
                <h2><?php print t('Categorization'); ?></h2>
                <div class="content-details">
                  <?php
                  if (!empty($photocategory)): print render($content['field_story_category']);
                  endif;
                  ?>

                </div>  
              </div>
            <?php endif; ?>
            <?php
            $items = field_get_items('node', $node, 'field_gallery_image');
            foreach ($items as $imagecollection) {
              $imgfid = $imagecollection['field_images'][LANGUAGE_NONE][0]['fid'];
              $audfid = $imagecollection['field_audio'][LANGUAGE_NONE][0]['fid'];
              if ($imgfid != 0) {
                $output .= '<li>';
                if (module_exists('itg_photogallery')) {
                  if (!empty($imgfid)) {
                    $imguri = _itg_photogallery_fid($imgfid);
                    $style = 'photogallery_slide';
                    $output .='<img src="' . image_style_url($style, $imguri) . '"/>';
                  }
                }
                if (isset($imagecollection['field_image_caption'][LANGUAGE_NONE]) && !empty($imagecollection['field_image_caption'][LANGUAGE_NONE][0]['value'])) {
                  $output .= '<div class="details-parent"><div class="photo-title"><strong>' . $imagecollection['field_image_caption'][LANGUAGE_NONE][0]['value'] . '</strong></div>';
                }

                if (isset($imagecollection['field_credit'][LANGUAGE_NONE]) && !empty($imagecollection['field_credit'][LANGUAGE_NONE][0]['value'])) {
                  $output .= '<div class="photo-credit"><span>' . $imagecollection['field_credit'][LANGUAGE_NONE][0]['value'] . '</span></div>';
                }
                elseif (isset($node->field_credit_name[LANGUAGE_NONE][0]) && isset($node->field_credit_to_all[LANGUAGE_NONE][0])) {
                  $output .= '<div class="photo-credit"><span>' . $node->field_credit_name['und'][0]['value'] . '</span></div>';
                }
                if (isset($imagecollection['field_photo_byline'][LANGUAGE_NONE]) && !empty($imagecollection['field_photo_byline'][LANGUAGE_NONE][0]['target_id'])) {
                  if (module_exists('itg_photogallery')) {
                    $res_id = $imagecollection['field_photo_byline'][LANGUAGE_NONE][0]['target_id'];
                    $res_val = itg_photogallery_byline_photoby('node', $res_id);
                    $output .= '<div class="image-description"><span>' . $res_val . '</span></div></div>';
                  }
                }
                if (module_exists('itg_photogallery')) {
                  if (!empty($audfid)) {
                    $audiouri = _itg_photogallery_fid($audfid);
                    $output .= '<audio controls>
                              <source src="' . file_create_url($audiouri) . '" type="audio/mpeg">
                              Your browser does not support the audio element.
                            </audio>';
                  }
                  elseif (isset($node->field_common_audio_file[LANGUAGE_NONE]) && !empty($node->field_common_audio_file[LANGUAGE_NONE][0]['uri'])) {
                    if (isset($node->field_common_audio[LANGUAGE_NONE]) && $node->field_common_audio[LANGUAGE_NONE][0]['value'] == 1) {
                      $audiouri = $node->field_common_audio_file[LANGUAGE_NONE][0]['uri'];
                      $output .= '<div class="audio-div"><audio controls>
                                <source src="' . file_create_url($audiouri) . '" type="audio/mpeg">
                                Your browser does not support the audio element.
                              </audio></div>';
                    }
                  }
                }


                $output .= '</li>';
              }
            }
            if (isset($output) && !empty($output)):
              ?>
              <div class="expert-details content-box">
                <h2><?php print t('Gallery Images Upload'); ?></h2>
                <div class="content-details">  
                  <?php $field_photo_by = render($content['field_photo_by']);
                  if (!empty($field_photo_by)):
                    ?>
                    <div class="photobyline"><?php print render($content['field_photo_by']); ?></div>
      <?php endif; ?>      
              <?php echo '<div class="photogallery-list flexslider"><ul class="slides">' . $output . '</ul></div>'; ?>     
                </div>
              </div>
            <?php endif; ?> 

            <?php
            $syndication = render($content['field_syndication_']);
            $client_title = render($content['field_p_client_title']);
            if (!empty($syndication) || !empty($client_title)):
              ?>
              <div class="expert-details content-box">
                <h2><?php print t('Configuration'); ?></h2>
                <div class="content-details">
                  <?php
                  $isfeatured = render($content['field_featured']);
                  if (!empty($isfeatured)): print '<div class="field field-name-field-featured field-type-list-text field-label-above"><div class="field-label">Set As Featured:&nbsp;</div><div class="field-items"><div class="field-item even">Yes</div></div></div>';
                  endif;
                  ?>          
                </div>  
              </div>
            <?php endif; ?>


            <?php
            $ppl_tag = render($content['field_story_itg_tags']);
            if (!empty($ppl_tag)):
              ?>
              <div class="expert-details content-box">
                <h2><?php print t('Tags to follow'); ?></h2>
                <div class="content-details">
                  <?php
                  if (!empty($ppl_tag)): print render($content['field_story_itg_tags']);
                  endif;
                  ?>
                </div>  
              </div>
            <?php endif; ?>

  <?php endif; ?>


        </div>
      <?php endif; ?>

  <?php if ($layout): ?>
      </div></div>
<?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>
