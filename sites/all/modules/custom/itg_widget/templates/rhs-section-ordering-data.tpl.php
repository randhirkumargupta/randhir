<?php if (!empty($data)) : global $base_url; ?>
  <div class="rhs-section-ordering">
    <ul>
      <?php
      foreach ($data as $count => $entity) {
        ?>
        <li class="rhs-section-item-container rhs-item-<?php echo $entity['nid'] ?> rhs-item-<?php echo $entity['type'] ?>">      

          <?php if (!empty($entity['uri'])) { ?>
            <a class="pic" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $entity['nid']); ?>">
              <img  src="<?php print image_style_url("widget_very_small", $entity['uri']); ?>" alt="" />
            </a>
            <?php
          }
          else {
            ?>
            <a class="pic" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $entity['nid']); ?>">
              <img  height="66" width="88"  src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/itg_image88x66.jpg" alt="" />
            </a>
          <?php } ?>


          <p class="title <?php print $entity['type'] ?> section-order-<?php print $entity['nid'] ?>">
            <?php echo l(mb_strimwidth($entity['title'], 0, 150, ".."), "node/" . $entity['nid']); ?>
          </p>

        </li>

      <?php } ?>
    </ul>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
