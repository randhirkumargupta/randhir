<?php
//Check for idea approval users 
$idea_review_flag_user = itg_print_team_check_approval_users();
if ($_GET['type'] == 'commentform') {
    print render($content['comment_form']);
    print render($content['comments']);
}
else {
    ?>

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
                        <div class="content-node-view">
                            <div class="basic-details content-box">
                                <h2><?php echo t('Basic Details'); ?></h2>
                                <div class="content-details">
                                    <div class="field">
                                        <div class="field-label"><?php echo t('Idea Headline:'); ?></div>
                                        <div class="field-items"><?php echo ucwords($node->title); ?></div>
                                    </div>

                                    <div class="field">
                                        <div class="field-label"><?php echo t('Idea Brief:'); ?></div>
                                        <div class="field-items"><?php echo ucfirst($node->body[LANGUAGE_NONE][0]['value']); ?></div>
                                    </div>
                                    <?php if ($node->field_pti_magazine_kicker[LANGUAGE_NONE][0]['value']) { ?>
                                        <div class="field">
                                            <div class="field-label"><?php echo t('Magazine Kicker:'); ?></div>
                                            <div class="field-items"><?php echo ucfirst($node->field_pti_magazine_kicker[LANGUAGE_NONE][0]['value']); ?></div>
                                        </div>
                                    <?php } ?>
                                </div>
                            </div>
                        </div>
                        <?php
                        $termdata = "";

                        if ($node->field_primary_category['und'][0]['value'] != "" && isset($node->field_primary_category['und'])) {
                            $termdata = itg_videogallery_get_term_name($node->field_primary_category['und'][0]['value']);
                        }
                        if ($node->field_story_category[LANGUAGE_NONE][0]['taxonomy_term']->name) {
                            ?>
                            <div class="content-node-view">            
                                <div class="basic-details content-box">
                                    <h2><?php echo t('Categorization'); ?></h2>
                                    <div class="content-details">
                                        <div class="field">
                                            <div class="field-label"><?php echo t('Section:'); ?></div>
                                            <div class="field-items"><?php echo $node->field_story_category[LANGUAGE_NONE][0]['taxonomy_term']->name; ?></div>
                                        </div>
                                        <div class="field field-name-field-story-categoryprim field-type-taxonomy-term-reference field-label-above"><div class="field-label"><?php echo t('Primary Category:'); ?>&nbsp;</div><div class="field-items"><div class="field-item even"><?php echo $termdata; ?></div></div></div>

                                    </div>
                                </div>
                            </div>      
                        <?php } ?>

                        <?php
                        if ($node->field_pti_idea_status[LANGUAGE_NONE][0]['value'] == 'Approved') {

                            if (count($node->field_pti_print_media[LANGUAGE_NONE]) > 0) {
                                ?>
                                <div class="content-node-view">            
                                    <div class="basic-details content-box">
                                        <h2><?php echo t('Image Section'); ?></h2>
                                        <div class="content-details">
                                            <?php
                                            foreach ($node->field_pti_print_media[LANGUAGE_NONE] as $media_arr) {
                                                $media_detail = entity_load('field_collection_item', array($media_arr['value']));
                                                $image = image_style_url("thumbnail", $media_detail[$media_arr['value']]->field_pti_upload_image[LANGUAGE_NONE][0]['uri']);
                                                $video = $media_detail[$media_arr['value']]->field_pti_upload_video[LANGUAGE_NONE][0]['uri'];
                                                ?>
                                                <div class="field">
                                                    <div class="field-label"><?php print t('Image:') ?></div>
                                                    <div class="field-items"><img src="<?php echo $image; ?>" /></div>
                                                </div>
                                            <?php } ?>
                                        </div>
                                    </div>
                                </div> 
                            <?php } ?>
                            <div class="content-node-view">            
                                <div class="basic-details content-box">
                                    <h2><?php echo t('Settings'); ?></h2>
                                    <div class="content-details">
                                        <?php if ($node->field_pti_idea_status[LANGUAGE_NONE][0]['value']) { ?>
                                            <div class="field">
                                                <div class="field-label"><?php echo t('Status:'); ?></div>
                                                <div class="field-items"><?php echo str_replace('-', ' ', $node->field_pti_idea_status[LANGUAGE_NONE][0]['value']); ?></div>
                                            </div>
                                        <?php } if ($node->field_pti_words_limit[LANGUAGE_NONE][0]['value']) { ?>
                                            <div class="field">
                                                <div class="field-label"><?php echo t('Words Limit:'); ?></div>
                                                <div class="field-items"><?php echo $node->field_pti_words_limit[LANGUAGE_NONE][0]['value'] . ' '.t('words'); ?></div>
                                            </div>
                                        <?php } ?>

                                        <?php if ($node->field_survey_end_date[LANGUAGE_NONE][0]['value']) { ?>
                                            <div class="field">
                                                <div class="field-label"><?php echo t('Timeline:'); ?></div>
                                                <div class="field-items"><?php echo date('d/m/Y', strtotime($node->field_survey_end_date[LANGUAGE_NONE][0]['value'])); ?></div>
                                            </div>
                                        <?php
                                        }

                                        if ($node->field_story_rating[LANGUAGE_NONE][0]['value']) {
                                            ?>
                                            <div class="field">
                                                <div class="field-label"><?php echo t('Rating:'); ?></div>
                                                <div class="field-items"><?php echo $node->field_story_rating[LANGUAGE_NONE][0]['value']; ?></div>
                                            </div>
                                        <?php
                                        }
                                        if ($node->field_pti_mark_as_complete[LANGUAGE_NONE][0]['value']) {
                                            ?>
                                            <div class="field">
                                                <div class="field-label"><?php echo t('Mark as Complete:'); ?></div>
                                                <div class="field-items"><?php echo $node->field_pti_mark_as_complete[LANGUAGE_NONE][0]['value']; ?></div>
                                            </div>
            <?php }
        }
        ?>
                                </div>
                            </div>
                        </div> 
        <?php if ($idea_review_flag_user) { ?>
                            
                    <?php } ?>
                    </div>   
        <?php endif; ?>
    <?php if ($layout): ?>
                </div></div>
    <?php endif; ?>
    </div>

    <?php if (!empty($post_object)) print render($post_object) ?>
<?php } ?>

