<?php
if (!empty($data)) {
  ?>
<?php 
  $data_tb_region_item = '';
  if(drupal_is_front_page()){
	$data_tb_region_item = 'data-tb-region-item';  
  }else if(isset($_GET['is_home_front']) && $_GET['is_home_front']){
	$data_tb_region_item = 'data-tb-region-item';  
 }
?>
  <div class="flexslider-video">
    <ul class="slides"> 
      <?php
      foreach ($data as $entity_data_node) {
        ?>
        <li <?php echo $data_tb_region_item;?>>
            <a title="<?php echo _widget_title($entity_data_node['image_title']); ?>" href="<?php echo $entity_data_node['node_url']; ?>">
              <img src="<?php print $entity_data_node['file_url']; ?>" title="<?php echo $entity_data_node['image_title']; ?>" alt="<?php echo $entity_data_node['image_alt']; ?>" />
          </a>
          <p class="flex-count"><?php echo $entity_data_node['count']; ?> <?php echo t("Images") ?></p>
          <p class="flex-caption" title="<?php echo _widget_title($entity_data_node['title']);  ?>"><a  href="<?php echo $entity_data_node['node_url']; ?>"><?php print $entity_data_node['caption']; ?></a></p>
        </li>
      <?php } ?>
    </ul>
  </div>


<?php } ?>
