<?php if (!empty($data)) : global $base_url; ?>
  <div class="rhs-section-ordering">
    <?php
    foreach ($data as $count => $entity) {
      ?>
      <div class="rhs-section-item-container rhs-item-<?php echo $entity->nid ?>">      
        <div class="rhs-left-section">
          <?php if (!empty($entity->field_story_extra_large_image['und'][0]['uri'])) { ?>
            <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
              <img  src="<?php print image_style_url("widget_very_small", $entity->field_story_extra_large_image['und'][0]['uri']); ?>" />
            </a>
            <?php
          }
          else {
            ?>
            <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
              <img  height="66" width="88"  src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
            </a>
          <?php } ?>
        </div>
        <div class="rhs-right-section">
          <p class="<?php print $entity->type ?> section-order-<?php print $entity->nid ?>">
            <?php echo l(mb_strimwidth($entity->title, 0, 150, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?>
          </p>
        </div>
      </div>

    <?php } ?>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
