<?php if (!empty($rows)) : global $base_url; ?>
<?php $data_tb_region_item = 'fifa-data-tb-region-item';  ?>
  <div class="dont-miss">
    <ul>
      <?php foreach ($rows as $key => $node_data) { 
        if (!empty($node_data['field_story_small_image'])) {
          $img = $node_data['field_story_small_image'];
        }
        else {
          global $base_url;
          $img = "<img width='170' height='127'  src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg') ."' alt='' title='' />";
        }
        ?>
        <li <?php echo $data_tb_region_item;?> class="dont-miss-listing">
            <div class="dm-pic">
              <a  href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $node_data['nid']) ?>">
                  <?php print $img; ?>
                  <span class="vid-icon"></span>
              </a>
            </div>
          <div class="dm-detail">
            <?php if (!empty($node_data['title'])) : ?>    
              <h3 title="<?php echo $node_data['title'] ?>" class="dont-miss-widget dont-miss-<?php echo $node_data['nid'] ?>">
                <?php 
                  echo l(mb_strimwidth($node_data['title'], 0, 70, ".."), "node/" . $node_data['nid'] , array("attributes" => array("title" =>$node_data['title'])));
                
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
