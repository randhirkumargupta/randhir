<?php
if (!empty($data)) {
  $live_url = $data->field_ads_ad_code[LANGUAGE_NONE][0]['value'];
  if (filter_var($live_url, FILTER_VALIDATE_URL)) {
    $live_url = '<iframe frameborder="0" style="z-index:4" class="media__video--responsive" id="livetv_video1" scrolling="no" allowfullscreen="" src="'.$live_url.'"></iframe>';
  }
}
print $live_url;
?>