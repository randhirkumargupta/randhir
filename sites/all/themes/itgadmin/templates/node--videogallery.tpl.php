<?php if (!empty($content)): ?>
    <div class='<?php print $classes ?>'>
        <?php if ($view_mode == 'full'): ?>
            <a href="javascript:;" class="close-preview">&nbsp;</a>
            <?php
            // Load custom block for social media integration 
            global $user;
            if (!isset($node->op) && in_array('Social Media', $user->roles)):
                $block = module_invoke('itg_social_media', 'block_view', 'social_media_form');
                ?>
                <div class="itg-smi">
                    <button data-id="smi-popup" class="btn data-popup-link">Promote Content</button>
                </div>
                <div id="smi-popup" class="itg-popup">
                    <div class="popup-content">
                        <div class="popup-head">
                            <div class="popup-title">&nbsp;</div>
                            <a class="itg-close-popup" href="javascript:;"> Close </a>
                        </div>
                        <div class="popup-body">
                            <?php print render($block['content']); ?>
                        </div>
                    </div>
                </div>
            <?php endif; ?>
            <div class="basic-details content-box">
                <h2><?php print t('Basic Details'); ?></h2>
                <div class="content-details">
                    <div class="field">
                        <div class="field-label"><?php print t('Long headline:'); ?></div>
                        <div class="field-items"><?php print $title; ?></div>
                    </div>
                    <?php print render($content['field_story_short_headline']); ?>
                    <?php print render($content['field_story_reporter']); ?>
                    <?php print render($content['field_stroy_city']); ?>
                    <?php print render($content['field_story_courtesy']); ?>
                    <?php print render($content['field_video_anchor']); ?>
                </div>
            </div>
            <?php if (!isset($node->op) && $node->op != 'Preview') { ?>
                <div class="Story-details">
                    <h2><?php print t('Video Upload'); ?></h2>
                    <div class="content-details">
                        <?php
                        
                        $items = field_get_items('node', $node, 'field_video_upload');
           
                        foreach ($items as $imagecollection):
                           $video_fid_data = get_video_filed_collection_by_its_id($imagecollection['value']);
                                
                            if ($video_fid_data[0]->field_videogallery_video_upload_fid !="") {
                                $video_data = itg_videogallery_get_videoid($video_fid_data[0]->field_videogallery_video_upload_fid);
                            }
   
                            if (!empty($video_data)) {
                                
                                $output .= ' <iframe frameborder="0" src="https://www.dailymotion.com/embed/video/' . $video_data . '?autoplay=0&mute=1&ui-start-screen-info" allowfullscreen></iframe>';
                            }

                            if (isset($video_fid_data) && !empty($video_fid_data[0]->field_videogallery_description_value)) {
                                $output .= '<div class="field-audio-image">Description:</div><div class="photo-title"><strong>' . $video_fid_data[0]->field_videogallery_description_value . '</strong></div>';
                            }
                            
                              if (isset($video_fid_data) && !empty($video_fid_data[0]->field_include_ads_valu)) {
                                $output .= '<div class="field-audio-image">Include Ads:</div><div class="photo-title"><strong>' .$video_fid_data[0]->field_videogallery_description_value . '</strong></div>';
                            }
                        endforeach;
                        ?>
                        <?php print $output; ?>
                        <?php
                        $short_des = render($content['field_story_expert_name']);
                        if (!empty($short_des)):
                            ?>
                            <?php print render($content['field_story_expert_name']); ?>
                            <?php
                        endif;
                        $short_des = render($content['field_story_expert_description']);
                        if (!empty($short_des)):
                            ?>
                            <?php print render($content['field_story_expert_description']); ?>
                        <?php endif; ?>
                    </div>
                </div> 
            <?php } else { ?>
                <div class="Story-details">
                    <h2><?php print t('Video Upload'); ?></h2>
                    <div class="content-details">
                        <?php
                        
                        $items = field_get_items('node', $node, 'field_video_upload');
                        foreach ($items as $imagecollection):
                            $video_fid = $imagecollection['field_videogallery_video_upload'][LANGUAGE_NONE][0]['fid'];
                            if ($video_fid != "") {
                                $video_data = itg_videogallery_get_videoid($video_fid);
                            }

                            if (!empty($video_data)) {

                                $output .= ' <iframe frameborder="0" src="https://www.dailymotion.com/embed/video/' . $video_data . '?autoplay=0&mute=1&ui-start-screen-info" allowfullscreen></iframe>';
                            }
                               
                            if (isset($imagecollection['field_videogallery_description'][LANGUAGE_NONE]) && !empty($imagecollection['field_videogallery_description'][LANGUAGE_NONE][0]['value'])) {
                                $output .= '<div class="field-audio-image">Description:</div><div class="photo-title"><strong>' . $imagecollection['field_videogallery_description'][LANGUAGE_NONE][0]['value'] . '</strong></div>';
                            }
                              if (isset($imagecollection['field_include_ads'][LANGUAGE_NONE]) && !empty($imagecollection['field_include_ads'][LANGUAGE_NONE][0]['value'])) {
                                $output .= '<div class="field-audio-image">Include Ads:</div><div class="photo-title"><strong>' . $imagecollection['field_include_ads'][LANGUAGE_NONE][0]['value'] . '</strong></div>';
                            }


                        endforeach;
                        ?>
                        <?php print $output; ?>
                    </div>
                </div> 
            <?php } ?>
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
            $social_media = render($content['field_story_social_media_integ']);
            if (!empty($social_media)):
                ?>
                <div class="SocialMedia content-box">
                    <h2><?php print t('Social Media'); ?></h2>
                    <div class="content-details"><?php print render($content['field_story_social_media_integ']); ?>                  
                        <?php foreach ($node->field_story_social_media_integ['und'] as $value): ?>
                            <?php
                            switch ($value['value']) {
                                case 'facebook':
                                    print render($content['field_story_facebook_narrative']);
                                    print render($content['field_story_facebook_image']);

                                    break;
                                case 'twitter':
                                    print render($content['field_story_tweet']);
                                    print render($content['field_story_tweet_image']);

                                    break;
                                case 'facebook_video':
                                    print render($content['field_story_facebook_vdescripti']);
                                    print render($content['field_story_facebook_video']);

                                    break;
                                case 'twitter_video':
                                    print render($content['field_story_twitter_video_desc']);
                                    print render($content['field_story_twitter_video']);
                            }
                            ?>
                        <?php endforeach; ?>
                    </div>
                </div>
            <?php endif; ?>

            <?php
            $configuration = render($content['field_video_configurations']);
            if (!empty($configuration)):
                ?>
                <div class="configuration content-box">
                    <h2><?php print t('Configuration'); ?></h2>
                    <div class="content-details"><?php print render($content['field_video_configurations']); ?></div>

                </div>

            <?php endif; ?>
            <?php
            $comment_question = render($content['field_video_configurations']);
            if (!empty($comment_question)):
                ?>
                <div class="Comment content-box">
                    <div class="content-details"><?php print render($content['field_story_comment_question']); ?>
                    </div>
                </div>
            <?php endif; ?>

            <?php
            $field_story_itg_tags = render($content['field_story_itg_tags']);
            if (!empty($field_story_itg_tags)):
                ?>
                <?php print render($content['field_story_itg_tags']); ?>
            <?php endif; ?>
            <?php
            $playlist = render($content['field_dailymotion_playlist']);
            if (!empty($playlist)):
                ?>
                <?php print render($content['field_dailymotion_playlist']); ?>
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

            <div class="Story-details">
                <div class="content-details">
                    <?php print render($content['field_story_schedule_date_time']); ?>
                    <?php $story_exp_chk = $content['field_story_expires']['#items']['0']['value']; ?>
                    <?php
                    if (!empty($story_exp_chk)):
                        print render($content['field_story_expiry_date']);
                    endif;
                    ?>

                </div>
            </div> 

        <?php endif; // end of view mode full condition  ?></div>
        <?php
//            $comment_checkbox = $node->field_video_configurations[LANGUAGE_NONE];
//            if(isset($comment_checkbox)){
//              foreach ($node->field_video_configurations[LANGUAGE_NONE] as $key => $val) {
//              if($val['value'] == 'comment'){
//                  print render($content['comment_form']);
//                  print render($content['comments']);
//              }
//             }
//            }
    ?>
<?php endif; ?>