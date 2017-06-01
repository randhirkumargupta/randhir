<div class="row">
  <div class="col-md-8">
    <div class="auto-block-1">
      <div class="featured-news">

        <?php
        global $base_url;

        foreach ($rows as $index => $row) {

          $desc = $row['title'];
          if (function_exists('itg_common_remove_extra_html')) {
            $desc = itg_common_remove_extra_html($desc);
          }

          $video_class = "";
          if (strtolower($row['type']) == 'videogallery') {
            $video_class = 'video-icon';
          }
          if ($index == 0) {
            ?>
            <div class="featured-post featured-post-first <?php echo $video_class; ?>">
              <?php
              if ($row['field_story_large_image'] != "") {
                print $row['field_story_large_image'];
              }
              else {
                print "<img  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/itg_image483x271.jpg' />";
              }
              ?> 

              <h2 title="<?php echo strip_tags($desc); ?>"><?php echo l(mb_strimwidth(strip_tags($desc), 0, 70, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></h2>           
            </div>



            <?php }
            else if ($index > 0 && $index <= 2) { ?>
            <div class="featured-post <?php echo $video_class; ?>">
              <?php
              if ($row['field_story_medium_image'] != "") {
                print $row['field_story_medium_image'];
              }
              else {
                print "<img  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/itg_image237x133.jpg' />";
              }
              ?>
              <h3 title="<?php echo strip_tags($desc); ?>"><?php echo l(mb_strimwidth(strip_tags($desc), 0, 70, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></h3>
            </div>

  <?php } ?>

<?php } ?>
      </div>
    </div>    
  </div>
  <div class="col-md-4">
    <div class="auto-block-2">
      <div class="special-top-news">
        <div class="itg-listing-wrapper">
        <ul class="itg-listing">   
          <?php
          foreach ($rows as $index => $row) {

            $desc = $row['title'];

            if ($index > 2) {
              ?>
              <li title="<?php echo strip_tags($desc); ?>"><?php echo l(mb_strimwidth(strip_tags($desc), 0, 85, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></li>


            <?php } ?>

<?php } ?>

        </ul>
        </div>
      </div>
    </div>
  </div>
</div>