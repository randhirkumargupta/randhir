<?php global $base_url; ?>
<div class="container">
<div class="row">
  <div class="col-md-8">
      <div class="podcast-header-container">
          <div class="podcast-header-top">
  <h1><?php print $podcast_title ?></h1>
  <script src="<?php print $base_url . '/' . drupal_get_path('module', 'itg_podcast'); ?>/jwplayer/jwplayer.js"></script>
  <script>jwplayer.key = "Cbz5fuKQAlYHtZgBSR0G/4GgYFO7YTb0k8Ankg==";</script>
  <?php
  //p($podcast_banner_array);
  $podcast_id = isset($_GET['podcast_id']) ? $_GET['podcast_id'] : 0;
  $podcast_image = $podcast_banner_array[$podcast_id]['image']['uri'];
  $description = $podcast_banner_array[$podcast_id]['desc'];
  ?>
  <div class="pic">
    <img src="<?php print image_style_url("widget_small", $podcast_image); ?>" />
  </div>
  <div class="podcast-detail">      
  <?php if (!empty($podcast_banner_array[$podcast_id]['audio']['uri'])) : ?>
    <div id="podcast-<?php print $podcast_id; ?>">Loading the player...</div>
    <script type="text/javascript">
      var playerInstance = jwplayer ("podcast-<?php print $podcast_id; ?>");
      playerInstance.setup ({
        file: "<?php print file_create_url($podcast_banner_array[$podcast_id]['audio']['uri']); ?>",
        width: 640,
        height: 40
      });
    </script>
  <?php endif; ?>
    <?php if(!empty($description)) : ?>
      <p>  <?php print  mb_strimwidth($description, 0, 210, "..")?></p>
      <?php endif; ?>
    </div>
    </div>
  <div class="podcast-header-bottom">
      <div class="other-list">
    <?php
    unset($podcast_banner_array[$podcast_id]);
    foreach ($podcast_banner_array as $bottom_keys => $bottem_podcast) {
      $podcast_bottem_image = $bottem_podcast['image']['uri'];
      $bottem_description = $bottem_podcast['desc'];
      $extra_large_image_url = image_style_url("widget_very_small", $podcast_bottem_image);
      ?>
      
        <a href="?podcast_id=<?php print $bottom_keys; ?>">
          <img src="<?php print $extra_large_image_url; ?>">
        </a>
      <a href="?podcast_id=<?php print $bottom_keys; ?>">
          <img src="<?php print $extra_large_image_url; ?>">
        </a>
          <a href="?podcast_id=<?php print $bottom_keys; ?>">
          <img src="<?php print $extra_large_image_url; ?>">
        </a>
          <a href="?podcast_id=<?php print $bottom_keys; ?>">
          <img src="<?php print $extra_large_image_url; ?>">
        </a>
          
    <?php } ?>
          </div>
  </div>
    </div>
    </div>
    <div class="col-md-4">
        <div class="itg-adds"></div>
        
    </div>
</div>
</div>
<script>
jQuery(document).ready(function(){    
    jQuery('.other-list').slick({
        slidesToShow: 7,
        slidesToScroll: 1,
        arrows: true,    
    });    
});

</script>