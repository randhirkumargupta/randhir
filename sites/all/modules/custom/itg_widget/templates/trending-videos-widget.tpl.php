<?php if (!empty($data)) : global $base_url; ?>
  <ul class="trending-videos">
    <?php foreach ($data as $entity) { ?>
      <li class="<?php print $entity->type ?> trending-videos-list">
        <?php if (!empty($entity->field_story_extra_large_image['und'][0]['uri'])) { ?>            
          <a class="pic" href="<?php print $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
            <img src="<?php print image_style_url("widget_very_small", $entity->field_story_extra_large_image['und'][0]['uri']); ?>" />
          </a>
          <?php
        }
        else {
          ?>
          <img src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
        <?php } ?>
        <?php if (!empty($entity->title)) : ?>
          <?php echo l(mb_strimwidth($entity->title, 0, 120, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")) ?>
        <?php endif; ?>
      </li>
    <?php } ?>
  </ul>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>