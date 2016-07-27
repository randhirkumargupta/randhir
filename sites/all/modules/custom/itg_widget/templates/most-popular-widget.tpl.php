<ul class="top-stories-ordering">
    <?php
    foreach ($data as $entity_data) {
        $entity_info = get_required_data_from_entity_id($entity_data['entity_id']);
        $entity = $entity_info[$entity_data['entity_id']];
        if (!empty($entity->title)) :
            ?>
            <li class="<?php print $entity->type ?>">
                <a href="<?php print drupal_get_path_alias("node/$entity->nid"); ?>"><?php print $entity->title; ?></a>
            </li>
        <?php endif; ?>
    <?php } ?>
</ul>
