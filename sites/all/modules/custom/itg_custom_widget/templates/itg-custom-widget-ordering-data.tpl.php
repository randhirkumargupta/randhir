<div class="section-ordering">
    <?php
    if (!empty($data)) {
      $extra_large_image_url = "";
      foreach ($data as $count => $entity) {
        $nid = $entity['nid'];
        $video_class = "pic-no-icon";
        if (strtolower($entity['type']) == 'videogallery') {
          $video_class = 'video-icon';
        }
        if ($count == 0 && (!empty($entity['mi_file_uri']) && isset($entity['mi_file_uri']))) {
          //$extra_large_image_url = image_style_url("section_ordering_widget", $entity->field_story_extra_large_image['und'][0]['uri']);
          $extra_large_image_url = file_create_url($entity['mi_file_uri']);
        }
        ?>
        <?php if ($count == 0) : ?>
          <?php if (!empty($extra_large_image_url)) { ?>
            <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                <img  src="<?php print $extra_large_image_url ?>" alt="" />
            </a>
            <?php
          }
          else {
            ?>
            <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                <img  height="208" width="370" src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/itg_image370x208.jpg" alt="" />
            </a>
          <?php } ?>
          <h3 class="frist-heading heading-<?php echo $nid ?> <?php echo $entity['type'] ?> ">
              <?php //echo l(mb_strimwidth($entity['title'], 0, 55, ".."), "node/" . $nid); ?>
              <?php
              if (function_exists('itg_common_get_smiley_title')) {
                echo l(itg_common_get_smiley_title($nid, 0, 45), "node/" . $nid, array("html" => TRUE));
              }
              else {
                echo l(mb_strimwidth($entity['title'], 0, 55, ".."), "node/" . $nid);
              }
              ?>
          </h3>
        <?php endif; ?>
        <?php if ($count != 0) : ?>
          <p class="<?php print $entity['type'] ?> section-order-<?php print $nid ?>">
              <?php // echo l(mb_strimwidth($entity['title'], 0, 100, ".."), "node/" . $nid); ?>
              <?php
              if (function_exists('itg_common_get_smiley_title')) {
                echo l(itg_common_get_smiley_title($nid, 0, 90), "node/" . $nid, array("html" => TRUE));
              }
              else {
                echo l(mb_strimwidth($entity['title'], 0, 100, ".."), "node/" . $nid);
              }
              ?>
          </p>
        <?php endif; ?>
      <?php
      }
    }
    else { ?>
      <span class="no-result-found"><?php print t("Content Not Found") ?></span>
    <?php }
    ?>
</div>