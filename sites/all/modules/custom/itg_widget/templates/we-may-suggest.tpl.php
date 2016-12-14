<?php if (!empty($data)) : global $base_url; ?>
    <div class="may-be-suggest-container">
        <?php $is_fron_page = drupal_is_front_page();
        if (empty($is_fron_page)) { ?><h3><span><?php print t("May We Suggest") ?></span></h3><?php } ?>
        <ul>
                <?php foreach ($data as $key => $entity_info) { ?>
                <li class="may-we-suggest" id="may-be-suggest-<?php print $key ?>">
        <?php if (!empty($entity_info->field_story_extra_small_image['und'][0]['uri'])) { ?>
                        <a href="<?php print $base_url . '/' . drupal_get_path_alias("node/$entity_info->nid"); ?>" class="pic">
            <!--              <img  src="<?php print image_style_url("widget_very_small", $entity_info->field_story_extra_large_image['und'][0]['uri']); ?>" />-->
            <?php $file_uri = file_create_url($entity_info->field_story_extra_small_image['und'][0]['uri']); ?>
                            <img src="<?php print $file_uri; ?>" />
                        </a>
                        <?php
                    }
                    else {
                        ?>
                        <a href="<?php print $base_url . '/' . drupal_get_path_alias("node/$entity_info->nid"); ?>" class="pic">
                            <img height="66" width="88" src="<?php print $base_url . '/' . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
                        </a>
                    <?php } ?>
                        <?php if (!empty($entity_info->title)) : ?>
                        <p class="title may-be-suggest-<?php echo $entity_info->nid ?>">
                        <?php echo l(mb_strimwidth($entity_info->title, 0, 90, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity_info->nid")); ?>
                        </p>
                <?php endif; ?>
                </li>        
    <?php } ?>
        </ul>
    </div>
<?php else : ?>
    <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>

