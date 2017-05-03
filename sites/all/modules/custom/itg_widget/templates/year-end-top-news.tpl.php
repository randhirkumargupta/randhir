<?php if (!empty($data)) : global $base_url; ?>
    <div class="dont-miss top-news">
        <ul>
            <?php foreach ($data as $key => $node_data) {
                ?>
                <li class="dont-miss-listing" id="dont-miss-<?php print $key ?>">
                    <?php if (!empty($node_data['si_file_uri'])) { ?>
                        <div class="dm-pic">
                            <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_data['nid']}") ?>">
                                <img src="<?php print image_style_url("widget_small", $node_data['si_file_uri']); ?>" alt="<?php echo $node_data['field_story_extra_small_image_alt'];?>" title="<?php echo $node_data['field_story_extra_small_image_title'];?>" />
                            </a>
                        </div>
                        <?php
                    }
                    else {
                        ?>
                        <div class="dm-pic">
                            <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_data['nid']}") ?>">
                                <img width='170' height='127'  src='<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/itg_image170x127.jpg' alt="" />
                            </a>
                        </div>
                    <?php } ?>

                    <div class="dm-detail">

                        <?php $title = $node_data['title'];
                        if (!empty($node_data['extra'])) : ?>
                            <h4 title="<?php print $node_data['extra']; ?>"><?php print $node_data['extra']; ?></h4>
                        <?php endif; ?>


                        <?php if (!empty($title)) : ?>    
                            <p title="<?php print $title; ?>" class="dont-miss-widget dont-miss-<?php echo $node_data['nid'] ?>">
                                <?php
                                  if (function_exists('itg_common_get_smiley_title')) {
                                    echo l(itg_common_get_smiley_title($node_data['nid'], 0, 100), "node/" . $node_data['nid'], array("html" => TRUE));
                                  }
                                  else {
                                    echo l(mb_strimwidth($title, 0, 100, ".."), "node/" . $node_data['nid']);
                                  }
                                ?>
                            </p>
        <?php endif; ?>

                    </div>
                </li>
    <?php } ?>
        </ul>
    </div>
<?php else : ?>
    <span class="no-result-found"><?php print t("Content Not Found") ?></span>

<?php endif; ?>
