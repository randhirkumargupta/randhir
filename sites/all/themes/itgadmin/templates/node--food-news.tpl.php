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
                    <?php // print render($links) ?>
                </div>
            <?php endif; ?>

            <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
            </div></div>
    <?php endif; ?>

    <?php if ($layout): ?>
        <div class='column-main'><div class='column-wrapper'>
            <?php endif; ?>

            <?php if (!empty($content)): ?>
                <div class='<?php print $hook ?>-content clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
                    <?php // print render($content) ?>

                    <?php if ($view_mode == 'full'): ?>
                        <div class="content-node-view">
                            <h2><?php print t('Basic Details'); ?></h2>
                            <div class="content-details">
                                <div class="field">
                                    <div class="field-label"><?php print t('Strap headline (Short Headline)'); ?></div>
                                    <div class="field-items"><?php print $title; ?></div>
                                </div>
                                <?php
                                $long_headline = render($content['field_recipe_long_headline']);
                                if (!empty($long_headline)):
                                    print render($content['field_recipe_long_headline']);
                                    ?>
                                <?php endif; ?>
                                <?php
                                $kicker = render($content['field_story_kicker_text']);
                                if (!empty($kicker)):
                                    print render($content['field_story_kicker_text']);
                                    ?>
                                <?php endif; ?>
                                <?php
                                $byline = render($content['field_story_reporter']);
                                if (!empty($byline)):
                                    print render($content['field_story_reporter']);
                                    ?>
                                <?php endif; ?>
                                <?php
                                $byline = render($content['field_stroy_city']);
                                if (!empty($byline)):
                                    print render($content['field_stroy_city']);
                                    ?>
                                <?php endif; ?>
                                <div class="field"> 
                                    <div class="field-label"><?php print t('Description'); ?></div>
                                    <div class="field-items"><?php print render($content['body']); ?></div>
                                </div> 
                            </div></div>

                        <?php
                        if (isset($node->op) && $node->op == 'Preview') {
                            $browsemediaextralarg = render($content['field_story_extra_large_image']);
                            if (!empty($browsemediaextralarg)):
                                ?> 
                                <div class="content-node-view">
                                    <h2><?php print t('Browse Media'); ?></h2>
                                    <div class="content-details">
                                        <?php print render($content['field_story_extra_large_image']); ?>
                                    </div>
                                </div>
                                <?php
                            endif;
                        }else {
                            $browsemediaextralarg = render($content['field_story_extra_large_image']);
                            $browsemedialarg = render($content['field_story_large_image']);
                            $browsemediamediu = render($content['field_story_medium_image']);
                            $browsemediasmal = render($content['field_story_small_image']);
                            $browsemediawriter = render($content['field_recipe_writer_image']);
                            if (!empty($browsemediaextralarg) || !empty($browsemedialarg) || !empty($browsemediamediu) || !empty($browsemediasmal) || !empty($browsemediawriter)):
                                ?>
                                <div class="content-node-view">
                                    <h2><?php print t('Browse Media'); ?></h2>
                                    <div class="content-details">
                                        <?php print render($content['field_story_extra_large_image']); ?>
                                        <?php print render($content['field_story_large_image']); ?>
                                        <?php print render($content['field_story_medium_image']); ?>
                                        <?php print render($content['field_story_small_image']); ?>
                                        <?php print render($content['field_recipe_writer_image']); ?>
                                    </div>
                                </div>
                            <?php endif;
                        }
                        ?>


                        <?php
                        $syndication = render($content['field_story_syndication']);
                        ?>

        <?php if (!empty($syndication)): ?>
                            <div class="content-node-view">
                                <h2><?php print t('Syndication'); ?></h2>
                                <div class="content-details"> 
                                    <div class="description-details content-box">
            <?php if (!empty($syndication)): ?>
                                            <div class="breaking-content-details">
                                                <div class="field">
                                                    <div class="field-label">Syndication: </div>
                                                    <div class="field-items"><?php print ('yes'); ?></div>
                                                </div>
                                            </div>
            <?php endif; ?>
                                    </div>
                                </div>
                            </div>
        <?php endif; ?>


                        <div class="content-node-view">
                            <h2><?php print t('Sections'); ?></h2>
                            <div class="content-details">
                                <?php
                                $termdata = "";

                                 if ($node->field_primary_category['und'][0]['value'] != "" && isset($node->field_primary_category['und'])) {
                                    $termdata = itg_videogallery_get_term_name($node->field_primary_category['und'][0]['value']);
                                }
                                $selection = render($content['field_story_category']);
                                if (!empty($selection)):
                                    print render($content['field_story_category']);
                                    ?>
                       <?php endif; ?>
                                <div class="field field-name-field-story-categoryprim field-type-taxonomy-term-reference field-label-above"><div class="field-label">Primary Category:&nbsp;</div><div class="field-items"><div class="field-item even"><?php echo $termdata; ?></div></div></div>

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




