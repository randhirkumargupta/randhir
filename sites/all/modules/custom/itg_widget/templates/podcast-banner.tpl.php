<?php global $base_url; ?>
<div class="container">
  <div class="row">
    <div class="col-md-8">
      <div class="podcast-header-container">
        <div class="podcast-header-top">
          <h1 title="<?php print $podcast_title ?>"><?php print mb_strimwidth($podcast_title, 0, 65, "..") ?></h1>
          <script src="<?php print $base_url . '/' . drupal_get_path('module', 'itg_podcast'); ?>/jwplayer/jwplayer.js"></script>
          <script>jwplayer.key = "Cbz5fuKQAlYHtZgBSR0G/4GgYFO7YTb0k8Ankg==";</script>
          <div class="slider-header">
            <!-- Header slider -->
            <?php
            $podcast_thumbnail = "";
            foreach ($podcast_banner_array as $podcast_id => $podcast_array) {
              $podcast_image = $podcast_banner_array[$podcast_id]['image']['uri'];
              $description = $podcast_banner_array[$podcast_id]['desc'];
              ?>
              <div class="slide-<?php print $podcast_id ?>">
                <div class="pic">
                  <img src="<?php print image_style_url("widget_small", $podcast_image); ?>" alt="" />
                </div>
                <div class="podcast-detail">      
                  <?php if (!empty($podcast_banner_array[$podcast_id]['audio']['uri'])) : ?>
                    <div id="podcast-<?php print $podcast_id; ?>">Loading the player...</div>
                    <script type="text/javascript">
                      var playerInstance = jwplayer ("podcast-<?php print $podcast_id; ?>");
                      playerInstance.setup ({
                        file: "<?php print file_create_url($podcast_banner_array[$podcast_id]['audio']['uri']); ?>",
                        width: 440,
                        height: 40
                      });
                    </script>
                  <?php endif; ?>
                  <?php if (!empty($description)) : ?>
                    <p>  <?php print mb_strimwidth($description, 0, 210, "..") ?></p>
                  <?php endif; ?>
                </div>
              </div>

              <?php
              $extra_large_image_url = image_style_url("widget_very_small", $podcast_image);
              $very_small_image = '<img src="' . $extra_large_image_url . '" alt="" />';
              $podcast_thumbnail .= "<li class='slide-" . $podcast_id . "'> $very_small_image </li>";
            }
            $podcast_thumbnail .= "";
            ?>
          </div>
        </div>
        <div class="podcast-header-bottom">
          <div class="other-list">
            <?php print $podcast_thumbnail ?>
          </div>
        </div>
      </div>
    </div>
    <div class="col-md-4">
      <div class="itg-adds">

      </div>
    </div>
  </div>
</div>