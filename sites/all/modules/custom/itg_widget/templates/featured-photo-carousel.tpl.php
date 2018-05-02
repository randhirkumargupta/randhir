<?php
if(!empty($data)) {
    ?>
<?php 
  $data_tb_region_item = '';
  if(drupal_is_front_page()) {
	$data_tb_region_item = 'data-tb-region-item';  
  }
  else if(isset($_GET['is_home_front']) && $_GET['is_home_front']) {
	$data_tb_region_item = 'data-tb-region-item';  
}
?>
    <div class="flexslider">
        <ul class="slides"> 
            <?php
            foreach($data as $key => $entity_data_node) {
                ?>
                <li <?php echo $data_tb_region_item;?>>
    <?php 
        //$full_image = '<img src="'. $entity_data_node['file_url'] .'" title="'. $entity_data_node['image_title'] .'" alt="'. $entity_data_node['image_alt'].'" />';
        $full_image = theme('image', array('path' => $entity_data_node['file_url'], 'alt' => $entity_data_node['image_title'], 'title' => $entity_data_node['image_alt']));
    ?>                   
                    <?php
                        echo l($full_image , "node/".$entity_data_node['nid'] , array("html" => TRUE))
                    ?>
                    <div class="detail">
                        <p class="flex-count"><i class="fa fa-camera"></i> <?php echo $entity_data_node['count'] . t('Images'); ?> </p>
                        <p class="flex-caption" title="<?php echo $entity_data_node['title']; ?>">
                            <?php
                                echo l($entity_data_node['title'] , "node/".$entity_data_node['nid'] , array("html" => TRUE))
                            ?>
                        </p>
                    </div>
                </li>
            <?php } ?>
        </ul>
    </div>
<?php } ?>
