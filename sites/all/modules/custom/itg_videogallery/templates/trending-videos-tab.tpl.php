<?php if (!empty($data)) : global $base_url; ?>
  <ul class="trending-videos">
    <?php foreach ($data as $entity) { ?>
      <li class="<?php print $entity['type'] ?> trending-videos-list">
        <?php if (!empty($entity['eli_file_uri']) && file_exists($entity['eli_file_uri'])) { ?>            
          <a class="pic" href="<?php print $base_url . '/' . drupal_get_path_alias("node/".$entity['nid']); ?>">
            <?php $extra_large_image_url = image_style_url("170X127", $entity['eli_file_uri']); ?>
              <img src="<?php print $extra_large_image_url; ?>" alt="<?php echo $entity['field_story_extra_large_image_alt'] ?>" title="<?php echo $entity['field_story_extra_large_image_title'] ?>" />
          </a>
          <?php
        }
        else {
          ?>
          <a class="pic" href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $entity['nid']); ?>">
            <img src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/itg_image170x127.jpg" alt="" />
          </a>
        <?php } ?>
        <p title="<?php echo $entity['title']; ?>">
        <?php if (!empty($entity['title'])) : ?>
          <?php echo l(itg_common_get_smiley_title($entity['nid'], 0, 120, ".."), "node/" . $entity['nid'] , array("attributes" => array("title" => $entity['title']))) ?>
        <?php endif; ?>
        </p>
      </li>
    <?php } ?>
  </ul>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
