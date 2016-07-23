<?php $node = node_load($data[0]['nid']); ?>
<div class="big-sotry-contianer">
    <div class="big-story-left">
        <?php if (!empty($node->field_story_extra_large_image['und'][0]['uri'])) : ?>
            <a href="#" title="<?php (!empty($node->field_story_extra_large_image['und'][0]['title'])) ? print $node->field_story_extra_large_image['und'][0]['title']  : print $node->field_story_extra_large_image['und'][0]['filename']  ?>">
                <img src="<?php print image_style_url("home_page_feature_large", $node->field_story_extra_large_image['und'][0]['uri']); ?>" />
            </a>
        <?php endif; ?>
    </div>
    <div class="big-story-right">

        <h2><?php print $node->title; ?></h2>
        <?php if (!empty($node->field_story_kicker_text['und'][0]['value'])) : ?>
            <div class="kicker-text">
                <?php print $node->field_story_kicker_text['und'][0]['value']; ?>
            </div>
        <?php endif; ?>
        <ul><?php
            $extra = $data[0]['extra'];
            $realted_nodes = json_decode($extra);
            foreach ($realted_nodes as $related_node) {
                print "<li>" . node_load($related_node)->title . "</li>";
            }
            ?>
        </ul>
    </div>
</div>