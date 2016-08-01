<div class="dont-miss">
    <ul>
        <?php
        foreach ($data as $key => $dont_miss_data) {
            $node_data = node_load($dont_miss_data['nid']);
            ?>
            <li class="dont-miss-listing" id="dont-miss-<?php print $key ?>">

                <?php if (!empty($node_data->field_story_extra_large_image['und'][0]['uri'])) { ?>
                    <div class="dm-pic"><img src="<?php print image_style_url("thumbnail", $node_data->field_story_extra_large_image['und'][0]['uri']); ?>" /></div>
                <?php }
                else {
                    ?>
                    <div class="dm-pic">  <img width="100" height="75" src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" /> </div>
                    <?php } ?>
                <div class="dm-detail">
                    
                    <?php if (!empty($dont_miss_data['extra'])) : ?>
                        <h4><?php print $dont_miss_data['extra']; ?></h4>
                    <?php endif; ?>
                        <?php if (!empty($node_data->title)) : ?>    
                        <p><?php print $node_data->title ?></p>
                    <?php endif; ?>
                </div>
            </li>
<?php } ?>
    </ul>
</div>