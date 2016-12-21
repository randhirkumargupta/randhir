<?php if (!empty($data)) : global $base_url; ?>
  <div class="dont-miss">
    <ul>
      <?php foreach ($data as $key => $node_data) { 
           $video_class = "";
        if (strtolower($node_data['type']) == 'videogallery') {
            $video_class = 'video-icon';
        }
        ?>
        <li class="dont-miss-listing" id="dont-miss-<?php print $key ?>">
          <?php if (!empty($node_data['si_file_uri'])) { ?>
            <div class="dm-pic">
              <a class="<?php echo $video_class;?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_data['nid']}") ?>">
                <img src="<?php print image_style_url("widget_small", $node_data['node_load_data']->field_story_small_image['und'][0]['uri']); ?>" />
              </a>
            </div>
            <?php
          }
          else {
            ?>
            <div class="dm-pic">
              <a class="<?php echo $video_class;?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_data['node_load_data']->nid}") ?>">
                <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
              </a>
            </div>
          <?php } ?>

          <div class="dm-detail">

            <?php if (!empty($node_data['custom_label'])) : ?>
              <h4><?php print $node_data['custom_label']; ?></h4>
            <?php endif; ?>

            <?php if (!empty($node_data['node_load_data']->title)) : ?> 
              <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/".$node_data["node_load_data"]->nid); ?>">
              <p class="dont-miss-widget dont-miss-<?php echo $node_data['node_load_data']->nid ?>">
               
                   <?php echo mb_strimwidth($node_data['node_load_data']->title, 0, 110, "..");?>
                   </p></a>
              <?php  
             endif; 
            
            /*        $desc = $node_data['node_load_data']->title;
                
                if($desc != "")
                {?>
               <p class="review-desc review-desc-<?php echo $node_data['node_load_data']->nid ?>">
                <?php echo l(mb_strimwidth($desc, 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/{$node_data['node_load_data']->nid}")) ?>
              </p>
                <?php } */ ?>
          </div>
        </li>
      <?php } ?>
    </ul>
  </div>

<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
