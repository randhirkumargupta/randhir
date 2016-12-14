<?php if (!empty($data)) : global $base_url; ?>
    <div class="watch-right-now-video">
        <?php $is_fron_page = drupal_is_front_page();
        if (empty($is_fron_page)) { ?><h3><span><?php print t("Watch Right Now") ?></span></h3><?php } ?>
        <ul class="">    
                <?php foreach ($data as $video_key => $video_data) { ?>
                <li id="watch-right-now-<?php echo $video_data->nid ?>" class="watch-right-now-list watch-right-now-<?php echo $video_key ?>"">        
        <?php if (!empty($video_data->field_story_small_image['und'][0]['uri'])) { ?>
                        <a href="<?php print $base_url . '/' . drupal_get_path_alias("node/$video_data->nid"); ?>" class="pic">
           
               <!-- <img  src="<?php //print image_style_url("widget_small", $video_data->field_story_extra_large_image['und'][0]['uri']); ?>" />-->
            
                <?php $file_uri = file_create_url($video_data->field_story_small_image['und'][0]['uri']); ?>
                            <img src="<?php print $file_uri; ?>" />
                        </a>
                        <?php
                    }
                    else {
                        ?>
                        <a href="<?php print $base_url . '/' . drupal_get_path_alias("node/$video_data->nid"); ?>" class="pic">
                            <img width='170' height='127'  src='<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_video.jpg' />
                        </a>
                    <?php } ?>
                        <?php if (!empty($video_data->title)) : ?>
                        <p class="title">
                        <?php echo l(mb_strimwidth($video_data->title, 0, 140, ".."), $base_url . '/' . drupal_get_path_alias("node/$video_data->nid")); ?>
                        </p>
                <?php endif; ?>
                </li>
        <?php } ?>
        </ul>
    <?php else : ?>
        <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
</div>
