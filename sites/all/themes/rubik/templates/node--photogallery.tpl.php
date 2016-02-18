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
          <?php
          //print render($content) 
          // print '<pre>';
          //print_r($content);
          //print '</pre>';
          ?>

          <?php if ($view_mode == 'full'): ?>

            <div class="basic-details content-box">
              <h2>Basic Gallery Details</h2>
              <div class="content-details">
                <div class="field">
                  <div class="field-label">Gallery Title:</div>
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
                  <?php print render($content['field_story_large_image']); ?>
                  <?php print render($content['field_story_medium_image']); ?>
                  <?php print render($content['field_story_small_image']); ?>
                  <?php print render($content['field_story_extra_small_image']); ?>
                </div>
              </div>
            <?php endif; ?>
          
           <?php
            $photocategory = render($content['field_story_category']);
            if (!empty($photocategory)):
              ?>
              <div class="expert-details content-box">
                <h2>Categorization</h2>
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
              $imgfid = $imagecollection['field_images']['und'][0]['fid'];
              $audfid = $imagecollection['field_audio']['und'][0]['fid'];
         if ($imgfid != 0) {
                $output .= '<li>';
              if (module_exists('itg_photogallery')) {
                if (!empty($imgfid)) {
                  $imguri = _itg_photogallery_fid($imgfid);
                  $style = 'photogallery_preview815x300';
                  $output .='<img src="' . image_style_url($style, $imguri) . '"/>';
                }
              }
              if (isset($imagecollection['field_title']['und']) && !empty($imagecollection['field_title']['und'][0]['value'])) {
              $output .= '<div class="details-parent"><div class="photo-title"><strong>' . $imagecollection['field_title']['und'][0]['value'] . '</strong></div>';
            }

            if (isset($imagecollection['field_credit']['und']) && !empty($imagecollection['field_credit']['und'][0]['value'])) {
              $output .= '<div class="photo-credit"><span>' . $imagecollection['field_credit']['und'][0]['value'] . '</span></div>';
            }
            elseif (isset($node->field_credit_name['und']) && $node->field_credit_to_all['und'][0]['value'] == 1) {
              $output .= '<div class="photo-credit"><span>' . $node->field_credit_name['und'][0]['value'] . '</span></div>';
            }

            if (isset($imagecollection['field_image_description']['und']) && !empty($imagecollection['field_image_description']['und'][0]['value'])) {
              $output .= '<div class="image-description"><span>' . $imagecollection['field_image_description']['und'][0]['value'] . '</span></div></div>';
            }
              if (module_exists('itg_photogallery')) {
                if (!empty($audfid)) {
                  $audiouri = _itg_photogallery_fid($audfid);
                  $output .= '<audio controls>
                              <source src="' . file_create_url($audiouri) . '" type="audio/mpeg">
                              Your browser does not support the audio element.
                            </audio>';
                }
                elseif (isset($node->field_common_audio_file['und']) && !empty($node->field_common_audio_file['und'][0]['uri'])) {
                  if (isset($node->field_common_audio['und']) && $node->field_common_audio['und'][0]['value'] == 1) {
                    $audiouri = $node->field_common_audio_file['und'][0]['uri'];
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
            if(isset($output) && !empty($output)): ?>
           <div class="expert-details content-box">
                <h2>Gallery Images Upload</h2>
                <div class="content-details">  
            <?php $field_photo_byline = render($content['field_photo_byline']); 
            if (!empty($field_photo_byline)): ?>
                  <div class="photobyline"><?php print render($content['field_photo_byline']); ?></div>
            <?php endif; ?>  
              <?php $field_photo_by = render($content['field_photo_by']); 
            if (!empty($field_photo_by)): ?>
                  <div class="photobyline"><?php print render($content['field_photo_by']); ?></div>
            <?php endif; ?>      
           <?php  echo '<div class="photogallery-list flexslider"><ul class="slides">' . $output . '</ul></div>'; ?>     
                </div>
           </div>
          <?php endif; ?> 
          
          <?php
            $syndication = render($content['field_syndication_']);
            $client_title = render($content['field_p_client_title']);
            if (!empty($syndication) || !empty($client_title)):
              ?>
              <div class="expert-details content-box">
                <h2>Configuration</h2>
                <div class="content-details">
                  <?php
                  $isfeatured = render($content['field_featured']);
                  if (!empty($isfeatured)): print '<div class="field field-name-field-featured field-type-list-text field-label-above"><div class="field-label">Set As Featured:&nbsp;</div><div class="field-items"><div class="field-item even">Yes</div></div></div>';
                  endif;
                  ?>
                  <?php
                  if (!empty($syndication)): print '<div class="field field-name-field-syndication- field-type-list-text field-label-above"><div class="field-label">Syndication :&nbsp;</div><div class="field-items"><div class="field-item even">Yes</div></div></div>';
                  endif;
                  ?>
                  <?php
                  if (!empty($client_title)): print render($content['field_p_client_title']);
                  endif;
                  ?>            
                </div>  
              </div>
            <?php endif; ?>
          
          
            <?php
            $ppl_tag = render($content['field_people_tag']);
            $brand_tag = render($content['field_brand_tag']);
            $product_tag = render($content['field_product_tag']);
            $content_tag = render($content['field_content_tag']);
            if (!empty($ppl_tag) || !empty($brand_tag) || !empty($product_tag) || !empty($content_tag)):
              ?>
              <div class="expert-details content-box">
                <h2>Tags to follow</h2>
                <div class="content-details">
                  <?php
                  if (!empty($ppl_tag)): print render($content['field_people_tag']);
                  endif;
                  ?>
                  <?php
                  if (!empty($brand_tag)): print render($content['field_brand_tag']);
                  endif;
                  ?>
                  <?php
                  if (!empty($product_tag)): print render($content['field_product_tag']);
                  endif;
                  ?>
                  <?php
                  if (!empty($content_tag)): print render($content['field_content_tag']);
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

<?php if (!empty($post_object)) print render($post_object)  ?>
