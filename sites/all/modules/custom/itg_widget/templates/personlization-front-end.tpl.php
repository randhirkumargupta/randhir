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
          <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_info['node_data']['nid']}"); ?>">
            <?php
            if (isset($node_info['node_data']['uri'])) {
              $style_name = ($frist_key == 0) ? 'recommended_for_you_large' : "video_landing_page_170_x_127";
              print theme('image_style', array(
                  'style_name' => $style_name,
                  'path' => $node_info['node_data']['uri'],
                              )
              );
            }
            else {
              $height_width = ($frist_key == 0) ? 'width="370" height="208"' : 'width="170" height="127"';
              ?>
              <img <?php print $height_width; ?> src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
            <?php } ?>
          </a>
        </div>
        <div class="detail">
          <h4><?php print $node_info['taxonomy_name']; ?>  </h4>
          <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_info['node_data']['nid']}"); ?>">
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
                                )
                );
              }
              else {
                ?>
                <img width="170" height="127" src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
              <?php } ?>
            </a>
          </div>

          <div class="detail">
            <h4><?php print $node_info['taxonomy_name']; ?></h4>
            <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_info['node_data']['nid']}"); ?>">
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
