<?php
  $live_tv_data = $rows[0];
  $video_code = "";
  if($live_tv_data['field_live_tv_device'] == 'Web') {
    $video_code = $live_tv_data['field_ads_ad_code'];
  } else {
    $video_code = $live_tv_data['field_ads_header_script'];
  }
  // initialized output from iframe
  $output_live_tv = $video_code;
  if (filter_var($video_code, FILTER_VALIDATE_URL)) {
    // if video code is url then change output 
    $output_live_tv = '<iframe frameborder="0" style="z-index:4" class="media__video--responsive" id="livetv_video1" scrolling="no" allowfullscreen="" src="'.$video_code.'"></iframe>';
  }
?>
<div class="live-tv">
  <?php print $output_live_tv; ?>
</div>