<?php
if (!empty($data)) {
  ?>
  <div class="flexslider-video">
    <ul class="slides"> 
      <?php
      foreach ($data as $entity_data_node) {
        ?>
        <li>
          <a href="<?php echo $entity_data_node['node_url']; ?>"><?php print $entity_data_node['file_url']; ?></a>
          <p class="flex-count"><?php echo $entity_data_node['count']; ?> Images</p>
          <p class="flex-caption"><?php print $entity_data_node['caption']; ?></p>
        </li>
      <?php } ?>
    </ul>
  </div>


<?php } ?>