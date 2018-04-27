<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
global $base_url;
$embed_path = $base_url.'/'.drupal_get_path_alias('node/'.$node->nid);
$embed_image = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
if(!empty($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'])) {
  $embed_image = $embed_image;
} else {
  $embed_image = '';
}
?>
<?php if (!empty($content)): ?>
<div class="title-block">
<?php
  
    if (!empty($node->field_constituancy[LANGUAGE_NONE][0]['value'])) {
      $title = '<h1><span>' . $node->field_constituancy[LANGUAGE_NONE][0]['value'] . '</span>: ' . $node->title . '</h1>';
    }
    else {
      $title = '<h1>' . $node->title . '</h1>';
    }
    $share_title = $node->title;
    $blog_city = ($node->field_blog_city[LANGUAGE_NONE][0]['value']) ? $node->field_blog_city[LANGUAGE_NONE][0]['value'] . " | " : '';
    $fb_url = 'https://www.facebook.com/sharer/sharer.php?u='.$amp_link.'&title='.$share_title.'&picture='.$share_image;
    $twitter_url = 'https://twitter.com/intent/tweet?text='.urlencode($share_title).'&url='.$short_url.'&via=IndiaToday';
    $google_url = 'https://plus.google.com/share?url='.  urlencode($amp_link);
?>
<?php print ($title) ?>
<div class="locationdate"><?php print $blog_city .  date("F d, Y", strtotime($node->field_itg_content_publish_date[LANGUAGE_NONE][0]['value'])); ?></div>
<p class="short-discription">
  <?php
    $pattern = "#<p>(\s|&nbsp;|</?\s?br\s?/?>)*</?p>#";
    print preg_replace($pattern, '', $node->field_common_short_description[LANGUAGE_NONE][0]['value']);
  ?>
</p>
<!-- Image Or Live TV -->
<?php 
  $useragent = $_SERVER['HTTP_USER_AGENT'];  
  if (!empty($node->field_story_expires['und']['0']['value']) && $node->field_story_expires['und']['0']['value'] == 'Yes') {
?>
    <div class="iframe-video">
    <?php
      if (function_exists('mobile_user_agent_switch')) {
        $flag = mobile_user_agent_switch();
        if ($flag) {
          $current_device = 'Web Mobile';
          $field_name = 'field_ads_header_script';
        }
        else {
          $current_device = 'Web';
          $field_name = 'field_ads_ad_code';
        }
      }
      $device = itg_live_tv_company($current_device);
      if (!empty($device[0])) {
        $live_tv_get_details = node_load($device[0]);
        $live_url = $live_tv_get_details->{$field_name}[LANGUAGE_NONE][0]['value'];
        if (filter_var($live_url, FILTER_VALIDATE_URL)) {
          if (is_bool(is_youtube_url($live_url))) {
            echo '<amp-iframe width="640" height="360" frameborder="0" class="media__video--responsive" id="livetv_video1" scrolling="no" allowfullscreen="" src="' . $live_url . '"></iframe>';
          }
          elseif (is_string(is_youtube_url($live_url))) {
            echo '<amp-iframe width="640" height="360" frameborder="0" class="media__video--responsive" id="livetv_video1" scrolling="no" allowfullscreen="" src="https://www.youtube.com/embed/' . is_youtube_url($live_url) . '"></iframe>';
          }
        }
        else {
          preg_match_all('/<iframe.*src=\"(.*)\".*>(.*)<\/iframe>/isU', $live_url, $iframes);
          foreach ($iframes[0] as $iframes) {
            preg_match('/src="([^"]+)"/', $iframes, $match);
            $frame_url = parse_url($match[1]);
            if ($frame_url['scheme'] != 'https') {
              $live_url = str_replace($iframes, "", $live_url);
            }
            else {
              $frame = '<amp-iframe width="200" height="100"
        sandbox="allow-scripts allow-same-origin"
        layout="responsive"
        frameborder="0"
        src="' . $match[1] . '">
        </amp-iframe>';
              $live_url = str_replace($iframes, $frame, $live_url);
            }
          }
          print $live_url;
        }
      }
    ?>
    </div>
<?php
  } 
  elseif (isset($embed_image) && !empty($embed_image)) { ?>
    <div class="stryimg" id="liveblog" >
      <amp-img height="363" width="647" layout="responsive" alt="<?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt']; ?>" title="<?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title']; ?>" src="<?php print $embed_image; ?>"></amp-img>
    </div>
  <?php } ?> 
</div>
<div class="timeline">
  <?php
  $custom_content = get_custom_content_details($node->nid);
  //print_r($custom_content);die;
  if (!empty($custom_content)) {
    $breaking_output .= '';
    foreach ($custom_content as $breaking_item) {	  
      $user = !empty($breaking_item->update_uid) ? user_load($breaking_item->update_uid)->name : user_load($breaking_item->blog_uid)->name;      
      $breaking_title = preg_replace('#<script(.*?)>(.*?)</script>#is', '', $breaking_item->blog_title);
      $breaking_desc = itg_custom_amp_body_filter($breaking_item->blog_description);
      
      $fb_title = $string = preg_replace('/\s+/', ' ', itg_common_only_text_string($html));
      $pub_time = date("H:i", strtotime($breaking_item->blog_publish_time));
      $pub_display_time = date("H:i A", strtotime($breaking_item->blog_publish_time));
      $pub_time2 = str_replace(":", "", $pub_time);
      $current_time = str_replace(":", "", date('H:i'));
      $breaking_output .= '<div class="breaking-section">';
      $breaking_output .= '<div class="dateauthor">';
      $breaking_output .= '<div class="breaking-date">' . $pub_display_time . ' IST</div>';
      $breaking_output .= '<div class="breaking-author"> Posted by ' . $user . '</div>';
      $breaking_output .= '</div>';
      $breaking_output .= '<div class="blog-multi-title">'. $breaking_title .'</div>';
      $breaking_output .= '<div class="blog-multi-desc">'. $breaking_desc .'</div>';
      //$breaking_output .= '<div class="social-share-new"><ul><li><a title="share on facebook" onclick=\'fbpop("' . $share_page_link . '" , "' . urlencode($fb_title) . '" , "' . urlencode($share_desc) . '" , "' . $share_image . '")\' class="facebook def-cur-pointer"><i class="fa fa-facebook"></i></a></li><li><a title="share on twitter" rel="' . $node->nid . '" data-tag="' . $node->type . '" data-activity="twitter_share" data-status="1" onclick=\'twitter_popup("' . urlencode($fb_title) . '" , "' . urlencode($short_url) . '")\' class="user-activity twitter def-cur-pointer"><i class="fa fa-twitter"></i></a></li><li><a title="share on google+" rel="' . $node->nid . '" data-tag="' . $node->type . '" data-activity="google_share" data-status="1" onclick=\'return googleplusbtn("' . $share_page_link . '" )\' class="user-activity google def-cur-pointer"><i class="fa fa-google-plus"></i></a></li></ul></div>';
      $breaking_output .= '</div>';      
    }
    print $breaking_output;       
  }
  ?>
</div>
<?php endif; ?>
   
