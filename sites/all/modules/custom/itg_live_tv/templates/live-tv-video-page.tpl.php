<?php
/**
 * @file
 * Theme implementation for Live TV Video page.
 * 
 */
$share_title = 'India Today Live TV';
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$short_url = shorten_url($actual_link, 'goo.gl');
?>
<div class="program-livetv">
<div class="live_tv_video">
  <?php print $data; ?>
</div>
    <div class="social-icon">
        <ul>
            <li><a class="def-cur-pointer" title="share on facebook" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $share_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>')"><i class="fa fa-facebook"></i> <span>Share</span></a></li>
            <li><a class="def-cur-pointer" title="share on twitter" onclick="twitter_popup('<?php print urlencode($share_title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i> <span>Tweet</span></a></li>
            <li><a href="#"><i class="fa fa-link"></i> <span>Embed</span></a></li>
            <li><a href="#"><i class="fa fa-lightbulb-o"></i> <span>Light on</span></a></li>            
        </ul>
    </div>
</div>
<?php
  $current_time_program_tid ='';
  if(function_exists('itg_live_tv_page_video_category')) {
    $current_time_program_tid = itg_live_tv_page_video_category();
  }?>
<div class="latest-livetv-video"><h4><?php print t('Latest Videos'); ?></h4><?php print views_embed_view('programme_content_live_tv', 'block_1', $current_time_program_tid); ?></div>
