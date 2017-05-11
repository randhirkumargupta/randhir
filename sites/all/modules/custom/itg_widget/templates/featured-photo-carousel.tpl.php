<?php
if (!empty($data)) {
  ?>
  <div class="flexslider">
    <ul class="slides"> 
      <?php
      foreach ($data as $entity_data_node) {
        ?>
        <li>
          <a  href="<?php echo $entity_data_node['node_url']; ?>">
              <img src="<?php print $entity_data_node['file_url']; ?>" title="<?php echo $entity_data_node['image_title']; ?>" alt="<?php echo $entity_data_node['image_alt']; ?>" />
          </a>
          <div class="detail">
            <p class="flex-count"><i class="fa fa-camera"></i> <?php echo $entity_data_node['count'] .  t('Images'); ?> </p>
            <p class="flex-caption" title="<?php echo $entity_data_node['title']; ?>"><a  href="<?php echo $entity_data_node['node_url']; ?>"><?php print $entity_data_node['title']; ?></a></p>
          </div>
        </li>
      <?php } ?>
    </ul>
  </div>
<?php } ?>