<?php if (!empty($content)): ?>
    <div class='<?php print $classes ?>'>
        <?php if ($view_mode == 'full'): ?>
            <a href="javascript:;" class="close-preview">&nbsp;</a>


            <div class="basic-details content-box">
                <h2><?php print t('Basic Details'); ?></h2>
                <div class="content-details">
                    <div class="field">
                        <div class="field-label"><?php print t('Audio Title:'); ?></div>
                        <div class="field-items"><?php print $title; ?></div>
                    </div>
                    <?php print render($content['field_story_short_headline']); ?>
                    <?php print render($content['field_podcast_kicker_message']); ?>
                </div>
            </div>

       <?php if(!isset($node->op) && $node->op != 'Preview'){ 
?>
        <div class="Story-details">
            <h2><?php print t('Audio Upload'); ?></h2>
            <div class="content-details">
                <?php print render($content['field_podcast_audio_upload']); ?>
            </div>
        </div> 
        <?php  } else {  ?>
            <div class="Story-details">
                <h2><?php print t('Audio Upload'); ?></h2>
                <div class="content-details">
                    <?php
                    $items = field_get_items('node', $node, 'field_podcast_audio_upload');
                    foreach ($items as $imagecollection):
                        $imgfid = $imagecollection['field_podcast_audio_image_upload'][LANGUAGE_NONE][0]['fid'];
                        $audfid = $imagecollection['field_podcast_upload_audio_file'][LANGUAGE_NONE][0]['fid'];
                         if ($audfid != "") {

                            if (module_exists('itg_photogallery')) {
                                if (!empty($audfid)) {
                                    $audiouri = _itg_photogallery_fid($audfid);
                                    $output .= '<div class="field-audio-audio">Upload Audio: </div><audio controls>
                              <source src="' . file_create_url($audiouri) . '" type="audio/mpeg">
                              Your browser does not support the audio element.
                            </audio> </div>';
                                }
                            }
                        }
                         if (isset($imagecollection['field_podcast_description'][LANGUAGE_NONE]) && !empty($imagecollection['field_podcast_description'][LANGUAGE_NONE][0]['value'])) {
                            $output .= '<div class="field-audio-image">Description:</div><div class="photo-title"><strong>' . $imagecollection['field_podcast_description'][LANGUAGE_NONE][0]['value'] . '</strong></div>';
                        }
                        if ($imgfid != 0) {
                            $output .= '';
                            if (module_exists('itg_photogallery')) {
                                if (!empty($imgfid)) {
                                    $imguri = _itg_photogallery_fid($imgfid);
                                    $style = 'photogallery_slide';
                                    $output .='<div class="field-audio-image">Audio Image Upload: </div><img  src="' . image_style_url($style, $imguri) . '"/>';
                                }
                            }
                        }
                       

                        
                        $output .= '';

                    endforeach;
                    ?>
                    <?php print $output; ?>
                </div>
            </div> 
            <?php  }  ?>

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
            $termdata = "";

            if ($node->field_primary_category['und'][0]['value'] != "" && isset($node->field_primary_category['und'])) {
                $termdata = itg_videogallery_get_term_name($node->field_primary_category['und'][0]['value']);
            }
            $field_story_category = render($content['field_story_category']);
            if (!empty($field_story_category)):
                ?>
                <?php print render($content['field_story_category']); ?>
            <?php endif; ?>
            <div class="field field-name-field-story-categoryprim field-type-taxonomy-term-reference field-label-above"><div class="field-label">Primary Category:&nbsp;</div><div class="field-items"><div class="field-item even"><?php echo $termdata; ?></div></div></div>


        <?php endif; // end of view mode full condition   ?></div>

<?php endif; ?>