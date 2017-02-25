<?php if (!empty($data)) : global $base_url; ?>
<?php if(isset($data[0])) : ?>
  <div class="featured-news">
    <div class="featured-post featured-post-first">
      <?php if (!empty($data[0]['li_file_uri'])) : ?>
        <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $data[0]['nid']); ?>">
          <?php $extra_large_image_url = file_create_url($data[0]['li_file_uri']);
          ?>
          <img src="<?php print $extra_large_image_url; ?>" alt="" />
        </a>
      <?php else : ?>
        <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $data[0]['nid']); ?>">
          <img width="483" height="271" src="<?php print $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/itg_image483x271.jpg' ?>" alt="" />
        </a>
      <?php endif; ?>

      <?php if (!empty($data[0]['title'])) : ?>
        <h2 class="home-page-feature-<?php echo $data[0]['nid'] ?>">
          <?php
          if (function_exists('itg_common_get_smiley_title')) {
            echo l(itg_common_get_smiley_title($data[0]['nid'], 0, 80), "node/" . $data[0]['nid'], array('html' => TRUE));
          }
          else {
            echo l(mb_strimwidth($data[0]['title'], 0, 90, ".."), "node/" . $data[0]['nid']);
          }
          ?>
        </h2>   
      <?php endif; ?>
    </div>
 <?php endif; ?>     
<?php if(isset($data[1])) : ?>
    <div class="featured-post">
      <?php if (!empty($data[1]['mi_file_uri'])) : ?>
        <a  href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $data[1]['nid']); ?>">
          <img src="<?php print image_style_url("home_page_feature_small", $data[1]['mi_file_uri']); ?>" alt="" />
        </a>
      <?php else : ?>
        <a  href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $data[1]['nid']); ?>">
          <img src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/itg_image237x133.jpg" alt="" />
        </a>
      <?php endif; ?>
      <?php if (!empty($data[1]['title'])) : ?>
        <h3 class="home-page-feature-small-<?php echo $data[1]['nid'] ?>">
          <?php
          if (function_exists('itg_common_get_smiley_title')) {
            echo l(itg_common_get_smiley_title($data[1]['nid'], 0, 70), "node/" . $data[1]['nid'], array('html' => TRUE));
          }
          else {
            echo l(mb_strimwidth($data[1]['title'], 0, 90, ".."), "node/" . $data[1]['nid']);
          }
          ?>
        </h3>   
      <?php endif; ?>
    </div>
 <?php endif; ?>     
    <?php if(isset($data[2])) : ?>
    <div class="featured-post">
      <?php if (!empty($data[2]['mi_file_uri'])) : ?>
        <a  href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $data[2]['nid']); ?>">
          <img src="<?php print image_style_url("home_page_feature_small", $data[2]['mi_file_uri']); ?>" alt="" />
        </a>
      <?php else : ?>
        <a  href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $data[2]['nid']); ?>">
          <img src="<?php print$base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/itg_image237x133.jpg" alt="" />
        </a>
      <?php endif; ?>
      <?php if (!empty($data[2]['title'])) : ?>
        <h3 class="home-page-feature-small-<?php echo $data[2]['nid'] ?>">
          <?php
          if (function_exists('itg_common_get_smiley_title')) {
            echo l(itg_common_get_smiley_title($data[2]['nid'], 0, 70), "node/" . $data[2]['nid'], array('html' => TRUE));
          }
          else {
            echo l(mb_strimwidth($data[2]['title'], 0, 90, ".."), "node/" . $data[2]['nid']);
          }
          ?>
        </h3>    
      <?php endif; ?>
    </div>
      <?php endif; ?>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>