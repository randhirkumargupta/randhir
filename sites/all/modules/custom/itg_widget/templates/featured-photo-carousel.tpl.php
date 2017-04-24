<?php
if (!empty($data)) {
  ?>
  <div class="flexslider">
    <ul class="slides"> 
      <?php
      foreach ($data as $entity_data_node) {
        ?>
        <li>
          <a href="<?php echo $entity_data_node['node_url']; ?>"><img src="<?php print $entity_data_node['file_url']; ?>" alt="" /></a>
          <div class="detail">
            <p class="flex-count"><i class="fa fa-camera"></i> <?php echo $entity_data_node['count']; ?> Images</p>
            <p class="flex-caption"><?php print $entity_data_node['title']; ?></p>
          </div>
        </li>
      <?php } ?>
    </ul>
  </div>
<?php } ?>