<?php
foreach ($data as $key => $dont_miss_data) {
    $node_data = node_load($dont_miss_data['nid']);
    ?>
    <div class="dont-miss" id="dont-miss-<?php print $key ?>">

        <?php if (!empty($node_data->field_story_extra_large_image['und'][0]['uri'])) : ?>
            <img src="<?php print image_style_url("thumbnail", $node_data->field_story_extra_large_image['und'][0]['uri']); ?>" />
        <?php endif; ?>
        <p><?php print $dont_miss_data['extra']; ?></p>
        <h2><?php print $node_data->title ?></h2>
    </div>
<?php } ?>