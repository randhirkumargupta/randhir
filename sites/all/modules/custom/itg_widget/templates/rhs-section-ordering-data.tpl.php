<?php if (!empty($data)) : global $base_url; ?>
<?php 
  $data_tb_region_item = '';
  if(drupal_is_front_page()){
	$data_tb_region_item = 'data-tb-region-item';  
  }
?>
  <div class="rhs-section-ordering">
    <ul>
      <?php
      foreach ($data as $count => $entity) {
        ?>
        <li <?php echo $data_tb_region_item;?> class="rhs-section-item-container rhs-item-<?php echo $entity['nid'] ?> rhs-item-<?php echo $entity['type'] ?>">      

          <?php if (!empty($entity['uri'])) { ?>
            <a class="pic" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $entity['nid']); ?>">
              <img  src="<?php print image_style_url("widget_very_small", $entity['uri']); ?>" alt="" title="" />
            </a>
            <?php
          }
          else {
            ?>
            <a class="pic" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $entity['nid']); ?>">
              <img  height="66" width="88"  src="<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image88x66.jpg');?>" alt="" title="" />
            </a>
          <?php } ?>


          <p title="<?php echo $entity['title']; ?>" class="title <?php print $entity['type'] ?> section-order-<?php print $entity['nid'] ?>">
            <?php echo l(mb_strimwidth($entity['title'], 0, 150, ".."), "node/" . $entity['nid']); ?>
          </p>

        </li>

      <?php } ?>
    </ul>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
