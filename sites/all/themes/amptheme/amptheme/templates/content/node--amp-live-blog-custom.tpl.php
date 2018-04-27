<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
global $base_url;
$embed_image = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
if(!empty($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'])) {
  $embed_image = $embed_image;
} else {
  $embed_image = '';
}
$embed_path = $base_url . '/' . drupal_get_path_alias('node/' . $node->nid);
$embed_logo = $base_url . '/sites/all/themes/itg/logo.png';
$blog_created_date = date('Y-m-d', $node->created);
$blog_created_time = date('h:i:s', $node->created);
$coverage_start_date = $blog_created_date . 'T' . $blog_created_time;
$short_description_source = strip_tags($node->field_common_short_description[LANGUAGE_NONE][0]['value']);
$custom_content = get_custom_content_details($node->nid);
if (empty($node->field_breaking_coverage_end_time[LANGUAGE_NONE][0]['value'])) {
  $coverage_end = strtotime($node->changed);
}
else {
  $coverage_end = strtotime($node->field_breaking_coverage_end_time[LANGUAGE_NONE][0]['value']);  
}
$coverage_end_date = date('Y-m-d', $coverage_end);
$coverage_end_time = date('h:i:s', $coverage_end);
$coverage_end_final_date = $coverage_end_date . 'T' . $coverage_end_time;
$created_date = date('Y-m-d H:i:s', $node->created);
$modify_date = date('Y-m-d H:i:s', $node->changed);
$fb_appid = variable_get('itg_sharing_app_id');
?>
<!-- Live Schema Starts -->
<div itemtype="http://schema.org/LiveBlogPosting" itemscope="itemscope" id="blogIdjson">
  <meta itemprop="coverageStartTime" content="<?php print $coverage_start_date; ?>">
  <meta itemprop="coverageEndTime" content="<?php print $coverage_end_final_date; ?>">
  <meta itemprop="url" content="<?php print $embed_path; ?>">
  <meta itemprop="description" content="<?php print $short_description_source; ?>">
  <div class="bolg-content" id="bolgcontent">    
  <?php
  if (!empty($custom_content)) {
    foreach ($custom_content as $breaking_embed_item) {      
  ?>
      <div itemtype="http://schema.org/BlogPosting"   itemprop="liveBlogUpdate" itemscope="itemscope" data-type="text">
        <p itemprop="headline" content="<?php print $node->title; ?>"></p>
        <meta itemprop="datePublished" content="<?php print $created_date; ?>">
        <meta itemprop="author" content="IndiaToday.in">
        <meta itemprop="dateModified" content="<?php print $modify_date; ?>">
        <span itemprop="image" itemscope="itemscope" itemtype="https://schema.org/ImageObject">
          <meta itemprop="url" content="<?php print $embed_image; ?>">
          <meta itemprop="width" content="650">
          <meta itemprop="height" content="450">
        </span>
        <span itemprop="publisher" itemscope="itemscope" itemtype="https://schema.org/Organization">
          <span itemprop="logo" itemscope="itemscope" itemtype="https://schema.org/ImageObject">
            <meta itemprop="url" content="<?php print $embed_logo; ?>">
          </span>
          <meta itemprop="name" content="India Today">
        </span>
        <meta itemprop="mainEntityOfPage" content="<?php print $embed_path; ?>">
      </div>
    <?php }
  } ?> 
  </div> 
</div>
<!-- Live Schema Ends -->
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
    <div class="most-recent">Most Recent</div>
  <?php  
  if (!empty($custom_content)) {
    $breaking_output .= '';
    foreach ($custom_content as $breaking_item) {	  
      $user = !empty($breaking_item->update_uid) ? user_load($breaking_item->update_uid)->name : user_load($breaking_item->blog_uid)->name;      
      $breaking_title = preg_replace('#<script(.*?)>(.*?)</script>#is', '', $breaking_item->blog_title);
      $breaking_desc = itg_custom_amp_body_filter($breaking_item->blog_description);
      $breaking_desc = preg_replace('#<script(.*?)>(.*?)</script>#is', '', $breaking_desc);
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
      $breaking_output .= '<amp-social-share type="facebook" data-param-app_id="'.$fb_appid.'" data-param-text="'.$breaking_title.'"></amp-social-share>';
      $breaking_output .= '<amp-social-share type="twitter"></amp-social-share>';
      $breaking_output .= '<amp-social-share type="gplus"></amp-social-share>';      
      $breaking_output .= '</div>';      
    }
    print $breaking_output;       
  }
  ?>
</div>
<?php endif; ?>
<?php if(!empty(variable_get('amp_taboola_ad_script'))) { ?>
  <div class="amp-taboola">
    <?php print variable_get('amp_taboola_ad_script'); ?>
  </div>
<?php } ?>
<?php if(!empty(variable_get('amp_story_second_ad'))) { ?>
<div class="custom-amp-ad ad-btf">
  <?php print variable_get('amp_story_second_ad'); ?> 
</div>
<?php } ?>
   
