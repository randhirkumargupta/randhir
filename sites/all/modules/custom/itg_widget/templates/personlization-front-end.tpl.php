<?php if (!empty($data)) { ?>
  <div class="recommended-slider">
    <?php
    global $base_url;
    $frist_block = array();
    $frist_block[] = $data[0];
    unset($data[0]);
    $frist_block[1] = $data[1];
    unset($data[1]);
    print '<div class=""><ul class="frist-ul common-list">';
    foreach ($frist_block as $frist_key => $node_info) {
      $height_width = 'width="170" height="127"';
      ?>
      <li class="recom-listing">

        <div class="pic">
            <a title="<?php echo $node_info['node_data']['title'] ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_info['node_data']['nid']}"); ?>">
            <?php
            if (isset($node_info['node_data']['uri'])) {
              $style_name = ($frist_key == 0) ? 'recommended_for_you_large' : "video_landing_page_170_x_127";
              print theme('image_style', array('style_name' => $style_name,'path' => $node_info['node_data']['uri'],  "title" => $node_info['node_data']['field_story_extra_large_image_title'] , "alt" => $node_info['node_data']['field_story_extra_large_image_alt']));
            }
            else {
              $right_img = ($frist_key == 0) ? 'itg_image370x208.jpg' : 'itg_image170x127.jpg';
              ?>
              <img src="<?php echo $base_url . "/" . drupal_get_path('theme', 'itg') ?>/images/<?php echo $right_img; ?>" alt="" />
            <?php } ?>
          </a>
        </div>
        <div class="detail">
          <h4><?php print l($node_info['taxonomy_name']->name, "taxonomy/term/" . $node_info['taxonomy_name']->tid , array("attributes" => array("title" => $node_info['taxonomy_name']->name))) ?>  </h4>
          <a title="<?php echo $node_info['node_data']['title']; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_info['node_data']['nid']}"); ?>">
            <?php
            if ($frist_key == 0) {
              echo mb_strimwidth($node_info['node_data']['title'], 0, 240, "..");
            }
            else {
              echo mb_strimwidth($node_info['node_data']['title'], 0, 80, "..");
            }
            ?>
          </a>
        </div>
      </li>
      <?php
    }
    print "</ul></div>";
    $front_data = array_chunk($data, 3);


    foreach ($front_data as $info) {
      print '<div class=""><ul class="rest-list common-list">';
      foreach ($info as $node_info) {
        ?>
        <li class="recom-listing">
          <div class="pic">
            <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_info['node_data']['nid']}"); ?>">
              <?php
              if (isset($node_info['node_data']['uri'])) {
                print theme('image_style', array(
                  'style_name' => 'video_landing_page_170_x_127',
                  'path' => $node_info['node_data']['uri'],
                  'alt' => $node_info['node_data']['field_story_extra_large_image_alt'],
                  'title' => $node_info['node_data']['field_story_extra_large_image_title'],
                        )
                );
              }
              else {
                ?>
                <img width="170" height="127" src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/itg_image170x127.jpg" alt="" />
              <?php } ?>
            </a>
          </div>

          <div class="detail">
            <h4><?php print l($node_info['taxonomy_name']->name, "taxonomy/term/" . $node_info['taxonomy_name']->tid , array("attributes" => array("title" => $node_info['taxonomy_name']->name))) ?>  </h4>
            <a title="<?php echo $node_info['node_data']['title']; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_info['node_data']['nid']}"); ?>">
              <?php echo mb_strimwidth($node_info['node_data']['title'], 0, 80, ".."); ?>
            </a>
          </div>

        </li>
        <?php
      }
      print "</ul></div>";
    }
    ?>
  </div>
<?php } ?>
