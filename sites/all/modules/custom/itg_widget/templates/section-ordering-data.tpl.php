<?php if ($widget_style == 'auto-road-trip') {?>
<div class="auto-road-trip">
    <ul class="trending-videos">
        <?php
      
        foreach ($data as $count => $entity) {
            $video_class = "";
            if (strtolower($row['type']) == 'videogallery') {
                $video_class = 'content-video';
            }
            $desc = $entity->title;
           
            if ($entity->field_gallery_kicer['und'][0]['values'] != "") {
                $desc = strip_tags($entity->field_gallery_kicer['und'][0]['values']);
            } 
           // p($entity);
            ?>
            <li class="trending-videos-list">
               <?php  if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("video_landing_page_170_x_127", $entity->field_story_extra_large_image['und'][0]['uri']);
                    }
                ?>
               
        <?php if (!empty($extra_large_image_url)) { ?>
          <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
              <div class="pic video-none <?php echo $video_class; ?>">  <img  src="<?php print $extra_large_image_url ?>" /></div>
          </a>
          <?php
        } ?>
                     
                <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><div><?php echo l(mb_strimwidth(strip_tags($desc), 0, 55, ".."), $base_url . '/' . drupal_get_path_alias("node/{$entity->nid}")) ?></div></a>
            </li>
        <?php } ?>
    </ul>
</div>
<?php }else if ($widget_style == 'auto-tips-and-tricks'){?>
    <div class="auto-tips-n-tricks">
    <ul>
        <?php
 
        foreach ($data as $count => $entity) {
            $video_class = "";
            if (strtolower($row['type']) == 'videogallery') {
                $video_class = 'content-video';
            }
            
            if ($entity->field_gallery_kicer['und'][0]['values'] != "") {
                $desc = strip_tags($entity->field_gallery_kicer['und'][0]['values']);
            } 
           // p($entity);
         
            ?><li>
                <p class="title"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><?php echo ucfirst($entity->title); ?></a></p>

                <p><?php echo mb_strimwidth(strip_tags($desc), 0, 55, ".."); ?></p>
            </li>


        <?php }; ?>
    </ul>
</div>


<?php }
    else { ?>

<?php if (!empty($data)) : global $base_url; ?>
  <div class="section-ordering">
    <?php
    $extra_large_image_url = "";
    foreach ($data as $count => $entity) {
      if ($count == 0 && (!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
        $extra_large_image_url = image_style_url("section_ordering_widget", $entity->field_story_extra_large_image['und'][0]['uri']);
      }
      ?>
      <?php if ($count == 0) : ?>
        <?php if (!empty($extra_large_image_url)) { ?>
          <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
            <img  src="<?php print $extra_large_image_url ?>" />
          </a>
          <?php
        }
        else {
          ?>
          <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
            <img  src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
          </a>
        <?php } ?>
        <h3 class="frist-heading heading-<?php echo $entity->nid ?> <?php echo $entity->type ?> ">
          <?php echo l(mb_strimwidth($entity->title, 0, 55, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?>
        </h3>
      <?php endif; ?>
      <?php if ($count != 0) : ?>
        <p class="<?php print $entity->type ?> section-order-<?php print $entity->nid ?>">
          <?php echo l(mb_strimwidth($entity->title, 0, 150, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?>
        </p>
      <?php endif; ?>
    <?php } ?>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
<?php } ?>






