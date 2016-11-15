

<?php if (!empty($data)) : global $base_url; ?>
    <div class="dont-miss top-video">
        <ul>
            <?php foreach ($data as $key => $node_data) { ?>
                <li class="<?php print $node_data['node_load_data']->type ?> dont-miss-listing">
                    <?php if (!empty($node_data['node_load_data']->field_story_extra_large_image['und'][0]['uri'])) { ?>            
                        <div class="dm-pic">
                            <a class="pic" href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $node_data['node_load_data']->nid); ?>">
                                <img src="<?php print image_style_url("widget_small", $node_data['node_load_data']->field_story_extra_large_image['und'][0]['uri']); ?>" />
                            </a>
                            <span><i class="fa fa-play-circle"></i> <?php echo $node_data['node_load_data']->field_video_duration['und'][0]['value']; ?></span>
                        </div>
                        <?php
                    }
                    else {
                        ?>
                        <div class="dm-pic">
                            <a class="pic" href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $node_data['node_load_data']->nid); ?>">
                                <img width='170' height='127'  src='<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_video.jpg' />
                            </a>                            
                        </div>
                        <?php } ?>
                    <div class="dm-detail">
                        <?php $title = $node_data['node_load_data']->title;
                        if (!empty($node_data['custom_label'])) : ?>
                            <h4><?php print $node_data['custom_label']; ?></h4>
                            <?php endif; ?>
                            <?php if (!empty($title)) : ?>    
                            <p class="dont-miss-widget dont-miss-<?php echo $node_data['node_load_data']->nid ?>">
                            <?php echo l(mb_strimwidth($title, 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/{$node_data['node_load_data']->nid}")) ?>
                            </p>
            <?php //echo mb_strimwidth($node_data['node_load_data']->body['und'][0]['value'], 0, 70, "..")  ?>
                <?php endif; ?>              
                    </div>
                </li>
    <?php } ?>
        </ul>
    </div>
<?php else : ?>
    <span class="no-result-found"><?php print t("Content Not Found") ?></span>

<?php endif; ?>
