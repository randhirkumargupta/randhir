<?php if (!empty($data)) : global $base_url; ?>
  <ul class="trending-videos">
    <?php foreach ($data as $entity) { ?>
      <li class="<?php print $entity['node_load_data']->type ?> trending-videos-list">
        <?php if (!empty($entity['node_load_data']->field_story_extra_large_image['und'][0]['uri'])) { ?>            
          <a class="pic" href="<?php print $base_url . '/' . drupal_get_path_alias("node/".$entity['node_load_data']->nid); ?>">
            <img src="<?php print image_style_url("widget_very_small", $entity['node_load_data']->field_story_extra_large_image['und'][0]['uri']); ?>" />
          </a>
          <?php
        }
        else {
          ?>
          <a class="pic" href="<?php print $base_url . '/' .  drupal_get_path_alias("node/".$entity['node_load_data']->nid); ?>">
            <img height="66" width="88" src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
          </a>
        <?php } ?>
        <?php if (!empty($entity['node_load_data']->title)) : ?>
          <?php echo l(mb_strimwidth($entity['node_load_data']->title, 0, 120, ".."), $base_url . '/' .  drupal_get_path_alias("node/".$entity['node_load_data']->nid)) ?>
        <?php endif; ?>
          <?php if (!empty($entity['node_load_data']->title)) : ?>
           <?php echo mb_strimwidth($entity['node_load_data']->body['und'][0]['value'], 0, 250, "..") ?>
        <?php endif; ?>
      </li>
    <?php } ?>
  </ul>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>