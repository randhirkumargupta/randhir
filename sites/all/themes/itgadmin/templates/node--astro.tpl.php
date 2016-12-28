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

            <?php if (!empty($title) && !$page && !isset($node->op)): ?>    
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
                                    <div class="field">
                                        <div class="field-label">Astro Title: </div>
                                        <div class="field-items"><?php print $title; ?></div>
                                    </div>
                                    <div class="field">
                                        <?php print '<div class="field-label">' . t('Frequency') . ': </div>'; ?>                        
                                        <div class="field-items">
                                            <?php print render($content['field_astro_frequency']); ?>
                                        </div>
                                    </div>
                                    <?php print render($content['field_astro_date_range']); ?>
                                    <?php print render($content['field_story_expiry_date']); ?>
                                    <?php print render($content['field_astro_type']); ?>
                                    <?php print render($content['field_last_name']); ?>
                                </div>
                                <h2>Channel</h2>
                                <div class="content-view">
                                    <div class="field">
                                        <?php print '<div class="field-label">Program: </div>'; ?>
                                        <div class="field-items">
                                            <?php
                                            $termdata = "";

                                            if ($node->field_primary_category['und'][0]['value'] != "" && isset($node->field_primary_category['und'])) {
                                                $termdata = itg_videogallery_get_term_name($node->field_primary_category['und'][0]['value']);
                                            }
                                            print render($content['field_story_category']);
                                            ?>

                                        </div>
                                        <div class="field field-name-field-story-categoryprim field-type-taxonomy-term-reference field-label-above"><div class="field-label">Primary Category:&nbsp;</div><div class="field-items"><div class="field-item even"><?php echo $termdata; ?></div></div></div>

                                    </div>
                                </div>
                            </div>

                            <?php if (isset($node->field_astro_zodiac['und'][0]['field_buzz_description']) && $node->field_astro_zodiac['und'][0]['field_buzz_description']['und'][0]['value'] != ''): ?>              
                                <div class="content-node-view">                
                                    <h2>Zodiac Sign</h2>
                                    <?php if (isset($node->op) && $node->op == 'Preview'): ?>  
                                        <div class="content-view">                                                                                           
                                            <?php
                                            $zodiac_sign = itg_astro_zodiac_thumbnail();
                                            for ($i = 0; $i <= 11; ++$i) {
                                                $output = '';
                                                $output .= '<div class="root-label">';

                                                // Print sign name
                                                $output .= '<div class="field-label">';
                                                $output .= $zodiac_sign[$i]->name;
                                                $output .= '</div>';

                                                // Print all field
                                                $output .= '<div class="field-items">';

                                                // Print name field
                                                $output .= '<div class="inner-label">Text: </div>';
                                                $output .= '<div class="inner-item">' . $node->field_astro_zodiac['und'][$i]['field_buzz_description']['und'][0]['value'] . '</div>';
                                                $output .= '<div class="inner-label">Thumbnail Icon: </div>';
                                                $output .= '<div class="inner-item"><img src="' . image_style_url("thumbnail", $zodiac_sign[$i]->field_astro_thumb_icon['und'][0]['uri']) . '" alt="' . $zodiac_sign[$i]->field_astro_thumb_icon['und'][0]['alt'] . '" title="' . $zodiac_sign[$i]->field_astro_thumb_icon['und'][0]['title'] . '"></div>';
                                                print $output;

                                                // Print audio field 
                                                $audio_fid = isset($node->field_astro_zodiac['und'][$i]['field_audio']['und'][0]['fid']) ? $node->field_astro_zodiac['und'][$i]['field_audio']['und'][0]['fid'] : '';
                                                if ($audio_fid != '') {
                                                    $audio_uri = _itg_photogallery_fid($audio_fid);
                                                    $audio = '';
                                                    $audio .= '<div class="inner-label">Audio: </div>';
                                                    $audio = '<span class="file">';
                                                    $audio .= '<img class="file-icon" alt="Audio icon" src="' . $base_url . '/modules/file/icons/audio-x-generic.png"> ';
                                                    $audio .= '<a href="' . $audio_uri . '">' . itg_astro_file_name($audio_fid) . '</a>';
                                                    $audio .= '</span>';
                                                    print '<div class="inner-item">' . $audio . '</div>';
                                                }

                                                // Print video field
                                                $video_fid = isset($node->field_astro_zodiac['und'][$i]['field_astro_video']['und'][0]['fid']) ? $node->field_astro_zodiac['und'][$i]['field_astro_video']['und'][0]['fid'] : '';
                                                if ($video_fid != '') {
                                                    $url_video = _itg_photogallery_fid($video_fid);
                                                    $video = '';
                                                    $video .= '<div class="inner-label">Video: </div>';
                                                    $video = '<span class="file">';
                                                    $video .= '<img class="file-icon" alt="File" src="' . $base_url . '/modules/file/icons/video-x-generic.png"> ';
                                                    $video .= '<a href="' . $url_video . '">' . itg_astro_file_name($video_fid) . '</a>';
                                                    $video .= '</span>';
                                                    print '<div class="inner-item">' . $video . '</div>';
                                                }
                                                print '</div></div>';
                                            }
                                            ?>
                                        </div>
                                    <?php endif; ?>
                                </div>
                            <?php endif; ?>

                            <?php if (!isset($node->op) && isset($content['field_astro_type'][0]['#markup']) && $content['field_astro_type'][0]['#markup'] == 'Zodiac'): ?>
                                <div class="content-node-view">                
                                    <h2>Zodiac Sign</h2>
                                    <?php print render($content['field_astro_zodiac']); ?>
                                </div>
                            <?php endif; ?>
                            <?php if (isset($content['field_buzz_description'])): ?>  
                                <div class="content-node-view">                  
                                    <h2>Collective Content</h2>
                                    <div class="content-view">
                                        <?php
                                        print render($content['field_buzz_description']);
                                        print render($content['field_astro_video_thumbnail']);
                                        print render($content['field_astro_video']);
                                        print render($content['field_common_audio_file']);
                                        ?>
                                    </div>
                                </div>
                            <?php endif; ?>
                            <?php if (isset($content['field_astro_numerology_values'])): ?>
                                <div class="content-node-view">
                                    <h2>Numerology</h2>
                                    <div class="content-view">                  

                                        <?php if (isset($node->op) && $node->op == 'Preview') { ?>

                                            <div class="field">
                                                <div class="field-label">Numerology values: </div>
                                                <div class="field-items">
                                                    <?php foreach ($node->field_astro_numerology_values['und'] as $num_item) { ?>   

                                                        <div class="field-item">
                                                            <?php
                                                            // Print number field                                                        
                                                            $output = '';
                                                            $output .= '<div class="field"><div class="field-label">Number: </div><div class="field-items">' . itg_astro_get_term_name($num_item['field_astro_select_number']['und'][0]['tid']) . '</div></div>';
                                                            $output .= '<div class="field"><div class="field-label">Text: </div>';
                                                            $output .= '<div class="field-items">' . $num_item['field_buzz_description']['und'][0]['value'] . '</div></div>';
                                                            echo $output;

                                                            // Print video field
                                                            $video_fid = isset($num_item['field_astro_video']['und'][0]['fid']) ? $num_item['field_astro_video']['und'][0]['fid'] : '';
                                                            if ($video_fid != '') {
                                                                $url_video = _itg_photogallery_fid($video_fid);
                                                                $video = '';
                                                                $video .= '<div class="field-label">Video: </div>';
                                                                $video .= '<div class="field-items"><span class="file">';
                                                                $video .= '<img class="file-icon" alt="File" src="' . $base_url . '/modules/file/icons/video-x-generic.png"> ';
                                                                $video .= '<a href="' . $url_video . '">' . itg_astro_file_name($video_fid) . '</a>';
                                                                $video .= '</span></div>';
                                                                print '<div class="field">' . $video . '</div>';
                                                            }

                                                            // Print audio field 
                                                            $audio_fid = isset($num_item['field_common_audio_file']['und'][0]['fid']) ? $num_item['field_common_audio_file']['und'][0]['fid'] : '';
                                                            if ($audio_fid != '') {
                                                                $audio_uri = _itg_photogallery_fid($audio_fid);
                                                                $audio = '';
                                                                $audio .= '<div class="field-label">Audio: </div>';
                                                                $audio .= '<div class="field-items"><span class="file">';
                                                                $audio .= '<img class="file-icon" alt="Audio icon" src="' . $base_url . '/modules/file/icons/audio-x-generic.png"> ';
                                                                $audio .= '<a href="' . $audio_uri . '">' . itg_astro_file_name($audio_fid) . '</a>';
                                                                $audio .= '</span></div>';
                                                                print '<div class="field">' . $audio . '</div>';
                                                            }
                                                            ?>

                                                        </div>

                                                    <?php } ?> 

                                                </div>
                                            </div>

                                            <?php
                                        }

                                        if (!isset($node->op)) {
                                            print render($content['field_astro_numerology_values']);
                                        }
                                        ?>                        
                                    </div>
                                </div>
                            <?php endif; ?>
                        </div>
                    <?php endif; ?>  
                </div>
            <?php endif; ?>

            <?php if ($layout): ?>
            </div></div>
    <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>

