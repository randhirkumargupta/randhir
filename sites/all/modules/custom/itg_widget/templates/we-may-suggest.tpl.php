<?php if (!empty($data)) : global $base_url; ?>
  <div class="may-be-suggest-container">
    <?php $is_fron_page = drupal_is_front_page();
    if (empty($is_fron_page)) {
	  $data_tb_region_item = '';
	  if($is_fron_page){
		$data_tb_region_item = 'data-tb-region-item';  
	  }
      ?><h3><span><?php print t("READ THIS") ?></span></h3><?php } ?>
    <ul>
        <?php foreach ($data as $key => $entity_info) { ?>
        <li <?php echo $data_tb_region_item;?> class="may-we-suggest">
            <?php if (!empty($entity_info['esi_file_uri'])) { ?>
            <a href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $entity_info['nid']); ?>" class="pic">
      <?php //$file_uri = file_create_url($entity_info['esi_file_uri']); ?>
              <?php print theme('image', array('path' => $entity_info['esi_file_uri'], 'alt' => $entity_info['field_story_extra_small_image_alt'], 'title' => $entity_info['field_story_extra_small_image_title'])); ?>
            </a>
            <?php
          }
          else {
            ?>
            <a href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $entity_info['nid']); ?>" class="pic">
              <img height="66" width="88" src="<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image88x66.jpg');?>" alt="" title="" />
            </a>
          <?php } ?>
            <?php if (!empty($entity_info['title'])) : ?>
            <p title="<?php echo $entity_info['title'] ?>" class="title may-be-suggest-<?php echo $entity_info['nid'] ?>">
            <?php 
            if(function_exists('itg_common_get_smiley_title')) {
              echo l(itg_common_get_smiley_title($entity_info['node_obj'], 0, 90), "node/" . $entity_info['nid'] , array('html' => TRUE , "attributes" => array("title" => _widget_title($entity_info['title'])))); 
            }
            else {
              echo l(mb_strimwidth($entity_info['title'], 0, 90, ".."), "node/" . $entity_info['nid'] , array("attributes" => array("title" => $entity_info['title']))); 
            }
            
            ?>
            </p>
        <?php endif; ?>
        </li>        
  <?php } ?>
    </ul>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>

