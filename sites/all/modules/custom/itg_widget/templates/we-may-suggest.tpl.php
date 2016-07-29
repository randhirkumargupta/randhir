<?php
$entity_data = array();
if (!empty($data)) {
    foreach ($data as $entity_data_node) {
        $entity_info = get_required_data_from_entity_id($entity_data_node['nid']);
        $entity_data[] = $entity_info[$entity_data_node['nid']];
    }
}
?>
<?php if (!empty($entity_data)) { ?>
    <div class="may-be-suggest-container">
        <?php foreach ($entity_data as $key => $entity_info) { ?>
            <div class="may-be-suggest" id="may-be-suggest-<?php print $key ?>">
                <?php if (!empty($entity_info->title)) : ?>
                    <h2><?php print $entity_info->title; ?></h2>
                <?php endif; ?>
                <?php if (!empty($entity_info->field_story_extra_large_image['und'][0]['uri'])) { ?>
                    <a href="#" title="<?php (!empty($entity_info->field_story_extra_large_image['und'][0]['title'])) ? print $entity_info->field_story_extra_large_image['und'][0]['title']  : print $entity_info->field_story_extra_large_image['und'][0]['filename']  ?>">
                        <img src="<?php print image_style_url("thumbnail", $entity_info->field_story_extra_large_image['und'][0]['uri']); ?>" />
                    </a>
                <?php }
                else {
                    ?>
                    <a href="#">
                        <img src="<?php print base_path() . "/" .drupal_get_path('theme', 'itg');?>/images/default_for_all.png" />
                    </a>
            <?php } ?>
            </div>
    <?php } ?>
    </div>
<?php } ?>

