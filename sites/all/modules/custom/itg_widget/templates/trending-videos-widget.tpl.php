<ul class="trending-videos">
    <?php
    foreach ($data as $entity_data) {
        $entity_info = get_required_data_from_entity_id($entity_data['entity_id']);
        $entity = $entity_info[$entity_data['entity_id']];
        ?>
        <li class="<?php print $entity->type ?>">
            <?php if (!empty($entity->field_story_extra_large_image['und'][0]['uri'])) { ?>            
                <a class="pic" href="#" title="<?php (!empty($entity->field_story_extra_large_image['und'][0]['title'])) ? print $entity->field_story_extra_large_image['und'][0]['title']  : print $entity->field_story_extra_large_image['und'][0]['filename']  ?>">
                    <img src="<?php print image_style_url("thumbnail", $entity->field_story_extra_large_image['und'][0]['uri']); ?>" />
                </a>
            <?php }
            else { ?>
                <img src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
            <?php } ?>
            <?php if (!empty($entity->title)) : ?>
                <a class="title" href="<?php print drupal_get_path_alias("node/$entity->nid"); ?>"><?php print $entity->title; ?></a>
        <?php endif; ?>
        </li>
<?php } ?>
</ul>