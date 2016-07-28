<?php $node = node_load($data[0]['nid']); ?>
<!-- Big news Block -->
<div class="big-news">
    <div class="row">
        <div class="big-story-col-1">
            <?php if (!empty($node->field_story_extra_large_image['und'][0]['uri'])) { ?>
                <img src="<?php print image_style_url("home_page_feature_large", $node->field_story_extra_large_image['und'][0]['uri']); ?>" />
                <div class="story-tag">Big Story</div>
            <?php
            }
            else {
                ?>
                <img src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
                <div class="story-tag">Big Story</div>
<?php } ?>
        </div>
        <div class="big-story-col-2">
            <?php if (!empty($node->title)) : ?>
                <h1><?php print $node->title; ?></h1>
                <?php endif; ?>
            <p>
                <?php if (!empty($node->field_story_kicker_text['und'][0]['value'])) : ?>
                    <?php print $node->field_story_kicker_text['und'][0]['value']; ?>
<?php endif; ?>
            </p>
            <div class="share-new">
                <ul>
                    <li><a href="#" title=""><i class="fa fa-facebook"></i></a></li>
                    <li><a href="#" title=""><i class="fa fa-twitter"></i></a></li>
                    <li><a href="#" title="">Follow the Story</a></li>
                </ul>
            </div>
            <div class="big-story-detail">                                
                <ul>
                    <?php
                    $extra = $data[0]['extra'];
                    $realted_nodes = json_decode($extra);
                    foreach ($realted_nodes as $related_node) {
                        if (!empty(node_load($related_node)->title)) :
                            print "<li><a href='#' title=''>" . node_load($related_node)->title . "</a></li>";
                        endif;
                    }
                    ?>
                </ul>                         
            </div>
        </div>
    </div>
</div>
<!-- Big news Block End -->