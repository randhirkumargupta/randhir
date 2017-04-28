<?php
if (!empty($data)) {
  ?>
  <div class="flexslider-video">
    <ul class="slides"> 
      <?php
      foreach ($data as $entity_data_node) {
        ?>
        <li>
            <a title="<?php echo $entity_data_node['title'];  ?>" href="<?php echo $entity_data_node['node_url']; ?>">
              <img src="<?php print $entity_data_node['file_url']; ?>" title="<?php echo $entity_data_node['image_title']; ?>" alt="<?php echo $entity_data_node['image_alt']; ?>" />
          </a>
          <p class="flex-count"><?php echo $entity_data_node['count']; ?> Images</p>
          <p class="flex-caption"><?php print $entity_data_node['caption']; ?></p>
        </li>
      <?php } ?>
    </ul>
  </div>


<?php } ?>