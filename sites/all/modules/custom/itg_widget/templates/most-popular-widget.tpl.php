<?php if (!empty($data)) : global $base_url; ?>
  <ul class="itg-listing">
    <?php
    foreach ($data as $entity) {
      if (!empty($entity->title)) :
        ?>
        <li class="<?php print $entity->type ?> most-popular-<?php print $entity->nid ?>">
          <?php echo l(mb_strimwidth($entity->title, 0, 110, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?>
        </li>
      <?php endif; ?>
    <?php } ?>
  </ul>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>