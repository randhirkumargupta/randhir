<?php
if(!empty($data)) {
$entity_data = array();
foreach ($data as $entity_data) {
    $entity_info = get_required_data_from_entity_id($entity_data['entity_id']);
    $entity_data[] = $entity_info[$entity_data['entity_id']];
    ?>
<?php } ?>
<div class="featured-news">
    <div class="featured-post featured-post-first">
        <?php if (isset($entity_data[0]->field_story_extra_large_image) && $entity_data[0]->field_story_extra_large_image['und'][0]['uri']) : ?>
            <a href="#" title="">
                <img src="<?php print image_style_url("home_page_feature_large", $entity_data[0]->field_story_extra_large_image['und'][0]['uri']); ?>" />
            </a>
        <?php endif; ?>
        <?php if (!empty($entity_data[0]->title)) : ?>
            <h2><a href="#" title=""><?php echo $entity_data[0]->title ?></a></h2>   
        <?php endif; ?>
    </div>
    <div class="featured-post">
        <?php if (isset($entity_data[1]->field_story_extra_large_image) && $entity_data[1]->field_story_extra_large_image['und'][0]['uri']) : ?>
            <a href="#" title="">
                <img src="<?php print image_style_url("home_page_feature_small", $entity_data[1]->field_story_extra_large_image['und'][0]['uri']); ?>" />
            </a>
        <?php endif; ?>
        <?php if (!empty($entity_data[1]->title)) : ?>
            <h3><a href="#" title=""><?php echo $entity_data[1]->title ?></a></h3>   
        <?php endif; ?>
    </div>
    <div class="featured-post">
        <?php if (isset($entity_data[2]->field_story_extra_large_image) && $entity_data[2]->field_story_extra_large_image['und'][0]['uri']) : ?>
            <a href="#" title="">
                <img src="<?php print image_style_url("home_page_feature_small", $entity_data[2]->field_story_extra_large_image['und'][0]['uri']); ?>" />
            </a>
        <?php endif; ?>
        <?php if (!empty($entity_data[2]->title)) : ?>
            <h3><a href="#" title=""><?php echo $entity_data[2]->title ?></a></h3>   
        <?php endif; ?>
    </div>
</div>
<?php } else { ?>
 No Feature content found
<?php } ?>
