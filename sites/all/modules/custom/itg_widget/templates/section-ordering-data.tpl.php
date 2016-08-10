<?php if (!empty($data)) : ?>
  <div class="section-ordering">
    <?php
    $extra_large_image_url = "";
    foreach ($data as $count => $entity) {
      if ($count == 0 && (!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
        $extra_large_image_url = image_style_url("section_ordering_widget", $entity->field_story_extra_large_image['und'][0]['uri']);
      }
      ?>
      <?php if ($count == 0) : ?>
        <?php if (!empty($extra_large_image_url)) { ?>
          <img  src="<?php print $extra_large_image_url ?>" />
        <?php }
        else {
          ?>
          <img  src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
      <?php } ?>
        <h3>
          <a title="<?php echo $entity->title; ?>" href="<?php print drupal_get_path_alias("node/$entity->nid") ?>">
      <?php print mb_strimwidth($entity->title, 0, 85, ".."); ?>
          </a>
        </h3>
      <?php endif; ?>
    <?php if ($count != 0) : ?>
        <p class="<?php print $entity->type ?> section-order-<?php print $entity->nid ?>">
          <a href="<?php print drupal_get_path_alias("node/$entity->nid") ?>">
      <?php print mb_strimwidth($entity->title, 0, 150, ".."); ?>
          </a>
        </p>
      <?php endif; ?>
  <?php } ?>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
