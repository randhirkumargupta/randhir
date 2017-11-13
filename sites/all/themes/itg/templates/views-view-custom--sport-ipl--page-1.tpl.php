<div class="page-sports-photo">
  <div class="view-content">
    <ul class="photo-list"> 
      <?php
      foreach ($rows as $index => $row) {
        if (!empty($row['field_story_small_image'])) {
          $img = $row['field_story_small_image'];
        }
        else {
          global $base_url;
          $img = "<img width='170' height='127'  src='" . file_create_url(file_build_uri(drupal_get_path('theme', 'itg') . '/images/itg_image170x127.jpg')) ."' alt='' title='' />";
        }
        ?>

        <li class="col-md-3">

          <div class="tile">
            <figure><?php print $img; ?>
              <figcaption><i class="fa fa-camera"></i> <?php echo $row['delta']; ?></figcaption>
            </figure>
            <span class="posted-on"><?php echo $row['created']; ?></span>
            <p  title="<?php print strip_tags($row['title']); ?>">
              <?php echo l(mb_strimwidth(html_entity_decode(strip_tags($desc)), 0, 999, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?>   </span>
            </p>
          </div>         
        </li>
      <?php }; ?>
    </ul>
  </div>
</div>