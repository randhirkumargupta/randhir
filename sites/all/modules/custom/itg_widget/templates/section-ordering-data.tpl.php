<?php if (!empty($data)) : global $base_url; ?>
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
          <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
            <img  src="<?php print $extra_large_image_url ?>" />
          </a>
          <?php
        }
        else {
          ?>
          <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
            <img  src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
          </a>
        <?php } ?>
        <h3 class="frist-heading heading-<?php echo $entity->nid ?> <?php echo $entity->type ?> ">
          <?php echo l(mb_strimwidth($entity->title, 0, 55, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?>
        </h3>
      <?php endif; ?>
      <?php if ($count != 0) : ?>
        <p class="<?php print $entity->type ?> section-order-<?php print $entity->nid ?>">
          <?php echo l(mb_strimwidth($entity->title, 0, 150, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?>
        </p>
      <?php endif; ?>
    <?php } ?>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
