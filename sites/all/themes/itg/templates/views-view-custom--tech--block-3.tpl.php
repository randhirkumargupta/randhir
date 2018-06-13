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

            ?>
            <div class="featured-post featured-post-first <?php echo $video_class; ?>">
              <?php
              if ($row['field_story_large_image'] != "") {
                print $row['field_story_large_image'];
              }
              else {
                print "<img  src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image483x271.jpg') ."' alt='' title='' />";
              }
              ?> 

              <h2 title="<?php echo strip_tags($desc); ?>">
                <?php
                if (function_exists('itg_common_get_smiley_title')) {
                  echo l(itg_common_get_smiley_title($row['nid'], 0, 77), "node/" . $row['nid'], array("html" => TRUE));
                }
                else {
                  echo l(mb_strimwidth(html_entity_decode(strip_tags($desc)), 0, 70, ".."), "node/" . $row['nid']);
                }
              ?>
              </h2>           
            </div>

<?php } ?>
      </div>
    </div>    
  </div>  
</div>
