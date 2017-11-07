<div class="page-sports-video">
  <div class="view-content">
    <ul class="photo-list row">
      <?php
      foreach ($rows as $index => $row) {
        $desc = $row['title'];
        if (!empty($row['field_story_small_image'])) {
          $img = $row['field_story_small_image'];
        }
        else {
          global $base_url;
          $img = "<img width='170' height='127'  src='" .  image_style_url("widget_small", drupal_get_path('theme', 'itg') . '/images/itg_image170x127.jpg') ."' alt='' title='' />";
        }
        ?>
        <li class="col-md-3 col-sm-3">
          <span class="tile">
            <figure>
              <?php print $img; ?> <figcaption><i class="fa fa-play-circle"></i><?php echo $row['field_video_duration']; ?></figcaption>
            </figure>  
            <p  title="<?php print strip_tags($row['title']) ; ?>">
            <?php echo l(mb_strimwidth(html_entity_decode(strip_tags($desc)), 0, 999, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?>   </span>
          </p>
        </li>
      <?php }; ?>
    </ul>
  </div>
</div>