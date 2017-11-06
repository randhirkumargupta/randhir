<?php if (!empty($data)) : global $base_url; ?>
  <ul class="trending-videos">
    <?php foreach ($data as $entity) { ?>
      <li class="<?php print $entity['type'] ?> trending-videos-list">
        <?php if (!empty($entity['esi_file_uri']) && file_exists($entity['esi_file_uri'])) { ?>            
          <a class="pic" href="<?php print $base_url . '/' . drupal_get_path_alias("node/".$entity['nid']); ?>">
            <?php $extra_large_image_url = image_style_url("widget_very_small", $entity['esi_file_uri']); ?>
              <img src="<?php print $extra_large_image_url; ?>" alt="<?php echo $entity['field_story_extra_small_image_alt'] ?>" title="<?php echo $entity['field_story_extra_small_image_title'] ?>" />
          </a>
          <?php
        }
        else {
          ?>
          <a class="pic" href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $entity['nid']); ?>">
            <img height="66" width="88" src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/itg_image88x66.jpg" alt="" title="" />
          </a>
        <?php } ?>
        <p title="<?php echo $entity['title']; ?>">
        <?php if (!empty($entity['title'])) : ?>
          <?php echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 120, ".."), "node/" . $entity['nid'] , array("attributes" => array("title" => _widget_title($entity['title'])))) ?>
        <?php endif; ?>
        </p>
      </li>
    <?php } ?>
  </ul>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>