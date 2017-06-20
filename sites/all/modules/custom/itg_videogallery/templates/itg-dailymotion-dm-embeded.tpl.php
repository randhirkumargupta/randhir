<?php

?>
<div class="itg-embed-wrapper">

  <div class="itg-embed-photo-wrapper">
    <?php

      $newimageds = '<div class="itg-embed-photo-thumb"><ul class="itg-embed-photo-thumb-slider">';
      ?>
      <div class="itg-embed-photo">
        <ul class="itg-embed-photo-slider">
          
            <li>
              <div class="<?php echo $hide_player; ?>" id="video_<?php echo $video_id; ?>">
                <div class="iframe-video">
                  <iframe frameborder="0" scrolling="no" src="https://www.dailymotion.com/embed/video/<?php print $video_id; ?>?autoplay=0&ui-logo=1&mute=1&endscreen-enable=1&ui-start-screen-info" allowfullscreen></iframe>
                </div>
              </div>  
             
            </li>


        </ul>
      </div>
      <?php
      $newimageds .= '</ul></div>';
   
    ?>

    <?php
    if (!empty($videoids) && count($videoids) > 1) {
      print $newimageds;
    }
    ?>
    
  </div>
</div>
