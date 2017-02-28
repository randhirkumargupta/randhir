<a href="javascript:;" class="close-preview">&nbsp;</a>
<div class='<?php print $classes ?>'>
  <?php
  $promote_class = "";
  if (!isset($node->op) && in_array('Social Media', $user->roles)) {
    $promote_class = 'promote-content';
  }
  ?>
  <div class='<?php echo $promote_class; ?>'>
    <?php if ($view_mode == 'full'): ?>
      <?php
      // Load custom block for social media integration              
      global $user;
      ?>
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
          </div>
        </div>
      <?php endif; ?>

      <!-- Social Media -->

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
            print render($content['field_story_facebook_vdescripti']);
            print render($content['field_story_facebook_video']);
            print render($content['field_story_tweet']);
            print render($content['field_story_tweet_image']);
            print render($content['field_story_twitter_video_desc']);
            print render($content['field_story_twitter_video']);
            ?>
          </div>
        </div>
      <?php endif; ?>

      <!-- Social Media Ends -->

      <?php
      $photocategory = render($content['field_story_category']);
      $termdata = "";

      if ($node->field_primary_category['und'][0]['value'] != "" && isset($node->field_primary_category['und'])) {
        $termdata = itg_videogallery_get_term_name($node->field_primary_category['und'][0]['value']);
      }
      if (!empty($photocategory)):
        ?>
        <div class="expert-details content-box">
          <h2><?php print t('Categorization'); ?></h2>
          <div class="content-details">
            <?php
            if (!empty($photocategory)): print render($content['field_story_category']);
            endif;
            ?>
            <div class="field field-name-field-story-categoryprim field-type-taxonomy-term-reference field-label-above"><div class="field-label">Primary Category:&nbsp;</div><div class="field-items"><div class="field-item even"><?php echo $termdata; ?></div></div></div>

          </div>  
        </div>
      <?php endif; ?>
      <?php
      $items = field_get_items('node', $node, 'field_gallery_image');
      foreach ($items as $imagecollection):
        $imgfid = $imagecollection['field_images'][LANGUAGE_NONE][0]['fid'];
        $audfid = $imagecollection['field_audio'][LANGUAGE_NONE][0]['fid'];
        if ($imgfid != 0) {
          $output .= '<li>';
          if (module_exists('itg_photogallery')) {
            if (!empty($imgfid)) {
              $imguri = _itg_photogallery_fid($imgfid);
              $style = 'photogallery_slide';
              $output .= '<img src="' . image_style_url($style, $imguri) . '"/><div class="details-parent">';
            }
          }

          if (isset($imagecollection['field_image_caption'][LANGUAGE_NONE]) && !empty($imagecollection['field_image_caption'][LANGUAGE_NONE][0]['value'])) {
            $output .= '<div class="photo-title"><strong>' . $imagecollection['field_image_caption'][LANGUAGE_NONE][0]['value'] . '</strong></div>';
          }

//    if (isset($imagecollection['field_credit'][LANGUAGE_NONE]) && !empty($imagecollection['field_credit'][LANGUAGE_NONE][0]['value'])) {
//      $output .= '<div class="photo-credit"><span>' . $imagecollection['field_credit'][LANGUAGE_NONE][0]['value'] . '</span></div>';
//    } elseif (isset($node->field_credit_name[LANGUAGE_NONE][0]) && isset($node->field_credit_to_all[LANGUAGE_NONE][0])) {
//      $output .= '<div class="photo-credit"><span>' . $node->field_credit_name['und'][0]['value'] . '</span></div>';
//    }

          if (isset($imagecollection['field_photo_byline'][LANGUAGE_NONE]) && !empty($imagecollection['field_photo_byline'][LANGUAGE_NONE][0]['target_id'])) {
            if (module_exists('itg_photogallery')) {
              $res_id = $imagecollection['field_photo_byline'][LANGUAGE_NONE][0]['target_id'];
              $res_val = itg_photogallery_byline_photoby('node', $res_id);
              $output .= '<div class="image-description"><span>' . $res_val . '</span></div>';
            }
          } else {
            $res_id = $node->field_photo_by[LANGUAGE_NONE][0]['target_id'];
            $res_val = itg_photogallery_byline_photoby('node', $res_id);
            $output .= '<div class="image-description"><span>' . $res_val . '</span></div>';
          }

          if (module_exists('itg_photogallery')) {
            if (!empty($audfid)) {
              $audiouri = _itg_photogallery_fid($audfid);
              $output .= '<audio controls>
                              <source src="' . file_create_url($audiouri) . '" type="audio/mpeg">
                              Your browser does not support the audio element.
                            </audio>';
            } elseif (isset($node->field_common_audio_file[LANGUAGE_NONE]) && !empty($node->field_common_audio_file[LANGUAGE_NONE][0]['uri'])) {
              if (isset($node->field_common_audio[LANGUAGE_NONE]) && $node->field_common_audio[LANGUAGE_NONE][0]['value'] == 1) {
                $audiouri = $node->field_common_audio_file[LANGUAGE_NONE][0]['uri'];
                $output .= '<div class="audio-div"><audio controls>
                                  <source src="' . file_create_url($audiouri) . '" type="audio/mpeg">
                                  Your browser does not support the audio element.
                                </audio></div>';
              }
            }
          }
          $output .= '</div></li>';
        }
      endforeach;
      if (isset($output) && !empty($output)):
        ?>
        <div class="expert-details content-box">
          <h2><?php print t('Gallery Images Upload'); ?></h2>
          <div class="content-details">  
            <?php
            $field_photo_by = render($content['field_photo_by']);
            if (!empty($field_photo_by)):
              ?>
              <div class="photobyline"><?php print render($content['field_photo_by']); ?></div>
            <?php endif; ?>      
            <?php echo '<div class="photogallery-list flexslider"><ul class="slides">' . $output . '</ul></div>'; ?>
            <div class="credit-source"><?php print render($content['field_credit_name']); ?></div>
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
  <?php
  if (!isset($node->op) && in_array('Social Media', $user->roles)):
    $block = module_invoke('itg_social_media', 'block_view', 'social_media_form');
    $data_in = itg_social_media_check_node_exist_lock($node->nid);
    global $user;
    if ($data_in[0]->uid == $user->uid || empty($data_in)) {

      itg_social_media_enter_in_lock($node->nid);
      ?>
      <div class="promote-sidebar">
        <?php print render($block['content']); ?>
      </div>
    <?php } else {
      ?>
      <div class="promote-sidebar">
        <div class="promote-lock">Someone  is already working on this</div>
      </div> 
    <?php }
    ?>
  <?php endif; ?>
</div>





