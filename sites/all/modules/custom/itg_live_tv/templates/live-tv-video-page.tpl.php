<?php
/**
 * @file
 * Theme implementation for Live TV Video page.
 * 
 */
?>

<div class="live_tv_video">
  <?php print $data; ?>
</div>
  <div class="social-icon mhide">
            <ul>
              <li><a href="#"><i class="fa fa-facebook"></i></a></li>
                <li><a href="javascript:" onclick="twitter_popup('<?php print urlencode($share_title);?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
                <li><a href="#"><i class="fa fa-link"></i></a></li>
            </ul>
        </div>
     <?php 
     //itg_live_tv_page_video_category();
     ?>