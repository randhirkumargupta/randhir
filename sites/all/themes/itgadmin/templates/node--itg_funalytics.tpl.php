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
                                    <div class="field-label"><?php print t('Title'); ?></div>
                                    <div class="field-items"><?php print $title; ?></div>
                                </div>
                                
                                <div class="field"> 
                                    <div class="field-label"><?php print t('Image'); ?></div>
                                    <div class="field-items"><?php print render($content['field_itg_funalytics_image']); ?></div>
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


                      

                <?php endif; ?>
                </div>
            <?php endif; ?>

    <?php if ($layout): ?>
            </div></div>
<?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>




