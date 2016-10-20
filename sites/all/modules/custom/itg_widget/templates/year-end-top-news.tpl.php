<?php if (!empty($data)) : global $base_url; ?>
    <div class="dont-miss top-news">
        <ul>
            <?php foreach ($data as $key => $node_data) {
                ?>
                <li class="dont-miss-listing" id="dont-miss-<?php print $key ?>">
                    <?php if (!empty($node_data['node_load_data']->field_story_extra_large_image['und'][0]['uri'])) { ?>
                        <div class="dm-pic">
                            <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_data['node_load_data']->nid}") ?>">
                                <img src="<?php print image_style_url("widget_very_small", $node_data['node_load_data']->field_story_extra_large_image['und'][0]['uri']); ?>" />
                            </a>
                        </div>
                        <?php
                    }
                    else {
                        ?>
                        <div class="dm-pic">
                            <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_data['node_load_data']->nid}") ?>">
                                <img height="66" width="88" src="<?php print $base_url . '/' . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
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
                            <?php
//                $desc=$node_data['node_load_data']->field_story_kicker_text['und'][0]['value'];
//                            if($desc=="")
//                            {
//                                $desc=$node_data['node_load_data']->body['und'][0]['value'];
//                            }
//                                
//                            echo mb_strimwidth($desc, 0, 70, "..") ;
                            ?>
        <?php endif; ?>

                    </div>
                </li>
    <?php } ?>
        </ul>
    </div>
<?php else : ?>
    <span class="no-result-found"><?php print t("Content Not Found") ?></span>

<?php endif; ?>
