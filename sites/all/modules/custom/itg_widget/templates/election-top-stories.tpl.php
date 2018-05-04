<?php if (!empty($data)) : global $base_url;?>

  <div class="ellection-top top-news">
    <ul>
      <?php  foreach ($data as $key => $node_data) {
        $node_data = (array)$node_data;
           $video_class = "";
        if (strtolower($node_data['type']) == 'videogallery') {
            $video_class = 'video-icon';
        }
          ?>
        <li class="ellection-top-listing">
          <?php if (!empty($node_data['uri'])) {           
            ?>
            <div class="dm-pic">
              <a class="<?php echo $video_class;?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_data['nid']}") ?>">
                <img src="<?php print image_style_url("widget_very_small", $node_data['uri']); ?>" alt="<?php echo $node_data['title'];?>" title="<?php echo $node_data['title'];?>" />
              </a>
            </div>
            <?php
          }
          else {
            ?>
            <div class="dm-pic">
              <a class="<?php echo $video_class;?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_data['nid']}") ?>">
                <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'itg'); ?>/images/itg_image88x50.jpg" alt="" title="" />
              </a>
            </div>
          <?php } ?>

          <div class="ellection-top-detail">

            <?php $title=$node_data['title'];
            if (!empty($node_data['extra'])) : ?>
              <h4><?php print $node_data['extra']; ?></h4>
            <?php endif; ?>

            <?php if (!empty($node_data['nid'])) : ?>    
              <p title="<?php echo strip_tags($title);?>" class="dont-miss-widget dont-miss-<?php echo $node_data['nid'] ?>">
                <?php //echo l(mb_strimwidth($title, 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/{$node_data['nid']}")) ?>
              <?php
              echo l(mb_strimwidth(strip_tags($title), 0, 100, ".."), "node/" . $node_data['nid']);
            ?>
              </p>
               
            <?php endif; ?>

          </div>
        </li>
      <?php } ?>
    </ul>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
  
<?php endif; ?>
