<ul class="section-ordering">
    <?php
    $extra_large_image_url = "";
    foreach ($data as $count => $entity_data) {
        $entity_info = get_required_data_from_entity_id($entity_data['nid']);
        $entity = $entity_info[$entity_data['nid']];
        if ($count == 0 && (!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
            $extra_large_image_url = file_create_url($entity->field_story_extra_large_image['und'][0]['uri']);
        }
        ?>
        <?php if (!empty($extra_large_image_url) && $count == 0) : ?>
            <img src="<?php print $extra_large_image_url; ?>">
        <?php endif; ?>
        <li class="<?php print $entity->type ?>">
            <a href="<?php print drupal_get_path_alias("node/$entity->nid") ?>"><?php print $entity->title; ?></a>
        </li>
    <?php } ?>
</ul>