<?php if ($video_data[0]->is_draft == 1) { ?>
  <div class="iframe-video1 video-iframe-wrapper" id="video_0">
      <span>Video Play Automatically After Publishing On Dailymotion</span>
  </div>
<?php }
else {
  ?>

  <div class="iframe-video1 video-iframe-wrapper" id="video_0">
  </div>
  <script src="https://api.dmcdn.net/all.js"></script>
  <script>
  
    var player_0 = DM.player(
            document.querySelector('#video_0'),
            {
                video: '<?php print $video_data[0]->video_embedded_url; ?>',
                width: '600px',
                height: '450px',
                params: {
                    autoplay: 1,
                    controls: 1,
                    'sharing-enable': 0,
                    'ui-start-screen-info': 0,
                    'ui-logo': 0,
                }
            }
    );
    player_0.addEventListener('video_end', function (event) {
        jQuery('.image_index_<?php print $tabindex + 1; ?>').trigger('click');
    });
  </script>
  <?php
} 