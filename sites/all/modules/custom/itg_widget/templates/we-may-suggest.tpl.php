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
    <h3><span><?php print t("May We Suggest") ?></span></h3>
    <ul>
      <?php foreach ($entity_data as $key => $entity_info) { ?>
        <li class="may-we-suggest" id="may-be-suggest-<?php print $key ?>">
          <?php if (!empty($entity_info->field_story_extra_large_image['und'][0]['uri'])) { ?>
            <a href="#" class="pic">
              <img width="88" height="66" src="<?php print image_style_url("thumbnail", $entity_info->field_story_extra_large_image['und'][0]['uri']); ?>" />
            </a>
            <?php
          }
          else {
            ?>
            <a href="#" class="pic">
              <img width="88" height="66" src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
            </a>
          <?php } ?>
          <?php if (!empty($entity_info->title)) : ?>
            <p class="title"><?php print $entity_info->title; ?></p>
          <?php endif; ?>

        </li>        
      <?php } ?>
    </ul>
  </div>
<?php } ?>

