<?php if (!empty($data)) : global $base_url; ?>
<?php $data_tb_region_item = 'fifa-data-tb-region-item';  ?>
<style type="text/css">
 .fifa-wcup .dont-miss{background-color: #f0f0f0; display: block;padding: 10px; width: 100%; box-sizing:border-box;}
 .fifa-wcup .dont-miss ul li img{width: 147px; height: 82px;}
 .fifa-wcup .dont-miss ul li .dm-pic{width: auto;}

</style>
  <div class="dont-miss">
    <ul>
      <?php foreach ($data as $key => $node_data) { ?>
        <li <?php echo $data_tb_region_item;?> class="dont-miss-listing">
          <?php if (!empty($node_data['si_file_uri']) && file_exists($node_data['si_file_uri'])) { ?>
            <div class="dm-pic">
              <a  href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $node_data['nid']) ?>">
                <?php //$file_uri = image_style_url("image170x127", $node_data['si_file_uri']);?>
                <?php //$file_uri = file_create_url($node_data['si_file_uri']); ?>
                  <?php print theme('image', array('path' => $node_data['si_file_uri'], 'alt' => $node_data['field_story_small_image_alt'], 'title' => $node_data['field_story_small_image_title'])); ?>
              </a>
            </div>
            <?php
          }
          else {
            ?>
            <div class="dm-pic">
              <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $node_data['nid']) ?>">
                <img width="170" height="127" src="<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg');?>" alt="" title="" />
              </a>
            </div>
          <?php } ?>

          <div class="dm-detail">

            <?php if (!empty($node_data['extra'])) : ?>
              <h4><?php print $node_data['extra']; ?></h4>
            <?php endif; ?>

            <?php if (!empty($node_data['title'])) : ?>    
              <h3 title="<?php echo $node_data['title'] ?>" class="dont-miss-widget dont-miss-<?php echo $node_data['nid'] ?>">
                <?php 
                if(function_exists('itg_common_get_smiley_title')) {
                  echo l(itg_common_get_smiley_title($node_data['node_obj'], 0, 60), "node/" . $node_data['nid'] , array('html' => TRUE , "attributes" => array("title" =>$node_data['title'])));
                } else {
                  echo l(mb_strimwidth($node_data['title'], 0, 70, ".."), "node/" . $node_data['nid'] , array("attributes" => array("title" =>$node_data['title'])));
                }
                ?>
              </h3>
            <?php endif; ?>

          </div>
        </li>
      <?php } ?>
    </ul>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
