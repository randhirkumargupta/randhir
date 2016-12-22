<?php if (!empty($data)) : global $base_url; ?>
  <ul class="trending-videos">
    <?php foreach ($data as $entity) { ?>
      <li class="<?php print $entity['type'] ?> trending-videos-list">
        <?php if (!empty($entity['esi_file_uri'])) { ?>            
          <a class="pic" href="<?php print $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
          <?php $file_uri = file_create_url($entity['esi_file_uri']); ?>
                  <img src="<?php print $file_uri; ?>" />
          </a>
          <?php
        }
        else {
          ?>
          <a class="pic" href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $entity['nid']); ?>">
            <img height="66" width="88" src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
          </a>
        <?php } ?>
        <?php if (!empty($entity['title'])) : ?>
          <?php echo l(mb_strimwidth($entity['title'], 0, 120, ".."), $base_url . '/' . drupal_get_path_alias("node/" . $entity['nid'])) ?>
        <?php endif; ?>
      </li>
    <?php } ?>
  </ul>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>