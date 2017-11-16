<?php
global $base_url;
$podcast_audio_element_id = array();
?>
<div class="container">
    <div class="row">
        <div class="col-md-8">
            <div class="podcast-header-container">
                <div class="podcast-header-top">
                    <h1 title="<?php print $podcast_title ?>"><?php print $podcast_title; ?></h1>
                    <script src="<?php print $base_url . '/' . drupal_get_path('module', 'itg_podcast'); ?>/jwplayer/jwplayer.js"></script>
                    <script>jwplayer.key = "Cbz5fuKQAlYHtZgBSR0G/4GgYFO7YTb0k8Ankg==";</script>
                    <div class="slider-header">
                        <?php
                        foreach ($podcast_banner_array as $podcast_id => $podcast_array) {
                          if (!empty($podcast_banner_array[$podcast_id]['audio']['uri'])) {
                            $podcast_audio_element_id[] = $podcast_id;
                          }
                        }
                        ?>
                        <!-- Header slider -->
                        <?php
                        $podcast_thumbnail = "";
                        if (!empty($podcast_banner_array)) :
                          foreach ($podcast_banner_array as $podcast_id => $podcast_array) {
                            $podcast_image = $podcast_banner_array[$podcast_id]['image']['uri'];
                            $description = $podcast_banner_array[$podcast_id]['desc'];
                            ?>
                            <div class="podcast-slide">
                                <div class="pic">
                                    <?php
                                    $podcat_uri = image_style_url("widget_small", $podcast_image);
                                    if (function_exists('url_exists') && url_exists($podcat_uri)) {
                                      ?>
                                      <img src="<?php print image_style_url("widget_small", $podcast_image); ?>" alt="" title="" />
                                      <?php
                                    }
                                    else {
                                      print "<img  src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg')."' alt='' title='' />";
                                    }
                                    ?>
                                </div>
                                <div class="podcast-detail">      
    <?php if (!empty($podcast_banner_array[$podcast_id]['audio']['uri'])) : ?>
                                      <div class="podcast-instance" id="podcast-<?php print $podcast_id; ?>">Loading the player...</div>
                                      <script type="text/javascript">
                                        var playerInstance = jwplayer("podcast-<?php print $podcast_id; ?>");
                                        playerInstance.setup({
                                            file: "<?php print file_create_url($podcast_banner_array[$podcast_id]['audio']['uri']); ?>",
                                            width: 440,
                                            height: 40,
                                            events: {
                                                onPlay: function () {
      <?php
      foreach ($podcast_audio_element_id as $pod_id) {
        if ($pod_id != $podcast_id) {
          echo "jwplayer('podcast-$pod_id').pause(true);";
        }
      }
      ?>
                                                }
                                            }
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
                            if (function_exists('url_exists') && url_exists($extra_large_image_url)) {
                              $extra_large_final_image = $extra_large_image_url;
                            }
                            else {
                              $extra_large_final_image = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image88x66.jpg');
                            }
                            $very_small_image = '<img class="podcast-thumb-img" src="' . $extra_large_final_image . '" alt="" title="" />';
                            $podcast_thumbnail .= "<div class='podcast-nav-item'> $very_small_image </div>";
                          }
                        endif;
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
                <?php
                $block = block_load('itg_ads', ADS_RHS1);
                $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                print render($render_array);
                ?>
            </div>
        </div>
    </div>
</div>