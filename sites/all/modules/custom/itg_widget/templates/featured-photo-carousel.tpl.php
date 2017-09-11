<?php
if (!empty($data)) {
  ?>
  <div class="flexslider">
    <ul class="slides"> 
      <?php
      foreach ($data as $entity_data_node) {
        ?>
        <li>
          <?php  if(!empty($entity_data_node['file_url'])) : ?>
          <a   title="<?php echo $entity_data_node['image_title']; ?>" href="<?php echo $entity_data_node['node_url']; ?>">
              <img src="<?php print $entity_data_node['file_url']; ?>" title="<?php echo $entity_data_node['image_title']; ?>" alt="<?php echo $entity_data_node['image_alt']; ?>" />
          </a>
            <?php else : ?>
            <a   title="<?php echo $entity_data_node['image_title']; ?>" href="<?php echo $entity_data_node['node_url']; ?>">
              <img width="647" height="363" src="<?php print $base_url . '/' . drupal_get_path('theme', 'itg'); ?>/images/itg_image647x363.jpg" alt="" />
            </a> 
            <?php endif; ?>
          <div class="detail">
            <p class="flex-count"><i class="fa fa-camera"></i> <?php echo $entity_data_node['count'] .  t('Images'); ?> </p>
            <p class="flex-caption" title="<?php echo $entity_data_node['title']; ?>">
              <a  href="<?php echo $entity_data_node['node_url']; ?>">
                <?php print itg_common_get_smiley_title($entity_data_node['nid'], 0, 145, ".."); ?>
              </a>
            </p>
          </div>
        </li>
      <?php } ?>
    </ul>
  </div>
<?php } ?>