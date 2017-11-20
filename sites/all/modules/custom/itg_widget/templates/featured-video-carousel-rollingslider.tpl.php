<?php
global $base_url;
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
  <div class="container">
    <div class="carousel">
      <div class="slides">                     
        <?php
        $i = 1;
        $countd = 1;
        foreach ($data as $entity_data_node) {
          ?>
          <div class="slideItem" <?php echo $data_tb_region_item;?>> 
              <?php //print $entity_data_node['file_url']; ?>
                <img src="<?php print $entity_data_node['file_url']; ?>" title="<?php echo $entity_data_node['image_title']; ?>" alt="<?php echo $entity_data_node['image_alt']; ?>" />
            <!--<img src="/itgcms/sites/all/themes/itg/images/demo-photo.jpg" alt="" />-->
            <a  href="<?php print $entity_data_node['node_url']; ?>?category=<?php print $entity_data_node['cat']; ?>&sid=<?php print $entity_data_node['sid']; ?>&pcat=<?php print $entity_data_node['primary_category']; ?>">
              <span class="flex-count text-right"><i class="fa fa-play-circle"></i></span>
              <span class="pic-tit" title="<?php echo $entity_data_node['title']; ?>"><?php print $entity_data_node['title']; ?></span>
              <span title="<?php echo $entity_data_node['image_title']; ?>" class="overlay"></span>
            </a>

          </div>  

          <?php
          $i++;
        }
        ?>

      </div>
    </div>
  </div>

<?php } ?>  
