<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */

global $base_url;
$share_page_link = SITE_PROTOCOL . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$short_url = $share_page_link; //shorten_url($share_page_link, 'goo.gl');
$share_desc = '';
$share_image = '';
if (!empty($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'])) {
  $share_image = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
}
$source_type = $node->field_story_source_type[LANGUAGE_NONE][0]['value'];
?>
 
<?php
// code for schema header script
if($node->field_type['und']['0']['value'] == 'Live Blog') {
$embed_path = $base_url.'/'.drupal_get_path_alias('node/'.$node->nid);
$embed_image = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
if(!empty($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'])) {
  $embed_image = $embed_image;
} else {
  $embed_image = '';
}
$embed_logo = $base_url.'/sites/all/themes/itg/logo.png';
$blog_created_date = date('Y-m-d', $node->created);
$blog_created_time = date('h:i:s', $node->created);
$coverage_start_date = $blog_created_date.'T'.$blog_created_time;
$short_description_source = strip_tags($node->field_common_short_description[LANGUAGE_NONE][0]['value']);
$custom_content = get_custom_content_details($node->nid);
if (empty($node->field_breaking_coverage_end_time[LANGUAGE_NONE][0]['value'])) {
  $coverage_end = $node->changed;
}
else {
  $coverage_end = strtotime($node->field_breaking_coverage_end_time[LANGUAGE_NONE][0]['value']);  
}
$coverage_end_date = date('Y-m-d', $coverage_end);
$coverage_end_time = date('h:i:s', $coverage_end);
$coverage_end_final_date = $coverage_end_date . 'T' . $coverage_end_time;
$created_date = date('Y-m-d H:i:s', $node->created);
$modify_date = date('Y-m-d H:i:s', $node->changed);
 // for call custom form value
?>
<div itemtype="http://schema.org/LiveBlogPosting" itemscope="itemscope" id="blogIdjson">
    <meta itemprop="coverageStartTime" content="<?php print $coverage_start_date; ?>">
    <meta itemprop="coverageEndTime" content="<?php print $coverage_end_final_date; ?>">
    <meta itemprop="url" content="<?php print $embed_path; ?>">
    <meta itemprop="description" content="<?php print $short_description_source; ?>">
    <?php if($node->field_type['und']['0']['value'] == 'Live Blog'):?>
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
    <?php endif;?>
    </div> 
<?php if($node->field_type['und']['0']['value'] == 'Live Blog'):?>
</div>
<?php endif;?>
<?php } ?>
<div class="liveBlog-indiatoday">
<div class="row">
  <div class="col-lg-12 col-md-12 col-sm-12 liveblog-heading">
     <?php
    if (!empty($content)):
      $type = $node->field_type['und']['0']['value'];
      if ($type == 'Live Blog') {
        if (!empty($node->field_constituancy[LANGUAGE_NONE][0]['value'])) {
          $title = '<h1><span>' . $node->field_constituancy[LANGUAGE_NONE][0]['value'] . ': </span>' . $node->title . '</h1>';
        }
        else {
          $title = '<h1>' . $node->title . '</h1>';
        }

        $share_title = $node->title;
        ?>
        <?php print ($title) ?>
        <?php $blog_city = ($node->field_blog_city[LANGUAGE_NONE][0]['value']) ? $node->field_blog_city[LANGUAGE_NONE][0]['value'] . " | " : ''; ?>
        <div class="locationdate"><?php print $blog_city .  date("F d, Y", strtotime($node->field_itg_content_publish_date[LANGUAGE_NONE][0]['value'])); ?><!-- April 24, 2018 --></div>
        <p class="short-discription"> <?php print ($node->field_common_short_description[LANGUAGE_NONE][0]['value']) ?></p>
  </div>


  <div class="col-md-4 col-xs-12 liveblog-Lhs mhide">
   <?php if (empty($node->field_blog_commentary[LANGUAGE_NONE])) { ?>  
   <h4>KEY UPDATES</h4>
  <?php 
   $left_side = get_custom_left_side_data($node->nid);
   foreach ($left_side as $lvalue) {
     print "<div class='lhs-detailList'><a href='#".$lvalue->bid."' class='leftblog-publish-time'>".$lvalue->blog_publish_time." IST</a>";
     print "<div class='leftblog-title'><a href='#".$lvalue->bid."'>".$lvalue->blog_title."</a></div></div>";
    }
   } else {
  ?>  
  <div class="livebolg-videos">
      <div class="livevideo"><?php print trim($node->field_blog_commentary[LANGUAGE_NONE][0]['value']); ?></div>
     
  </div> 
  <?php } ?>

  </div>
  <div class="col-md-8 col-xs-12 liveblog-Rhs">
    <div class="new-live-block">
         
        <?php
        if (!empty($node->field_story_expires['und']['0']['value']) && $node->field_story_expires['und']['0']['value'] == 'Yes') {
            $useragent = $_SERVER['HTTP_USER_AGENT'];
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
                        echo '<iframe frameborder="0" class="media__video--responsive" id="livetv_video1" scrolling="no" allowfullscreen="" src="' . $live_url . '"></iframe>';
                      }
                      elseif (is_string(is_youtube_url($live_url))) {
                        echo '<iframe frameborder="0" class="media__video--responsive" id="livetv_video1" scrolling="no" allowfullscreen="" src="https://www.youtube.com/embed/' . is_youtube_url($live_url) . '"></iframe>';
                      }
                    }
                    else {
                      print $live_url;
                    }
                  }
                  ?>
              </div>
             

      <?php } elseif (isset($embed_image) && !empty($embed_image)) { ?>
         <div class="stryimg" id="liveblog" >
                 <img  alt="<?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt']; ?>" title="<?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title']; ?>" src="<?php print $embed_image; ?>">
         </div>
        <?php } ?>    

        <div class="timeline">
          <?php
            if (!empty($node->field_live_blog_timeline_active[LANGUAGE_NONE]['0']['value'])) { ?>
                <input id="slider-range" class="irs-hidden-input" readonly="">
            <?php } ?>
    <?php
    
    $custom_content = get_custom_content_details($node->nid);
    if (!empty($custom_content)) {
      $breaking_output .= '';
      $i = 0;
			foreach ($custom_content as $breaking_item) {
        $i++;
        $user = !empty($breaking_item->blog_uid) ? user_load($breaking_item->blog_uid) : '';
        $user_name = ($user->field_last_name[LANGUAGE_NONE][0]['value']) ? $user->field_first_name[LANGUAGE_NONE][0]['value'] . " " . $user->field_last_name[LANGUAGE_NONE][0]['value'] : $user->field_first_name[LANGUAGE_NONE][0]['value'];

        // $user
        $breaking_output .= '<div class="breaking-section"><a name="'.$breaking_item->bid.'"></a>';
        $html = preg_replace('#<script(.*?)>(.*?)</script>#is', '', $breaking_item->blog_description);
        $fb_title = $string = preg_replace('/\s+/', ' ', itg_common_only_text_string($html));
        $pub_time = date("H:i", strtotime($breaking_item->blog_publish_time));
        $pub_display_time = date("H:i A", strtotime($breaking_item->blog_publish_time));
        $pub_time2 = str_replace(":", "", $pub_time);
        $current_time = str_replace(":", "", date('H:i'));
        
          $breaking_output .= '<div class="dwrap" timevalue="' . $pub_time2 . '" tcount="' . count($custom_content) . '"><div class="dateauthor"><div class="breaking-date">' . $pub_display_time . ' IST</div><div class="breaking-author"> Posted by ' . $user_name . '</div></div>';
          $breaking_output .= '<div class="blog-multi-title">'. $breaking_item->blog_title .'</div>';
          $breaking_output .= '<div class="blog-multi-desc">'. $html .'</div>';
          $breaking_output .= '<div class="breaking-social-share">' . $redirection_url . '</div><div class="social-share-new"><ul><li><a title="share on facebook" onclick=\'fbpop("' . $share_page_link . '" , "' . urlencode($fb_title) . '" , "' . urlencode($share_desc) . '" , "' . $share_image . '")\' class="facebook def-cur-pointer"><i class="fa fa-facebook"></i></a></li><li><a title="share on twitter" rel="' . $node->nid . '" data-tag="' . $node->type . '" data-activity="twitter_share" data-status="1" onclick=\'twitter_popup("' . urlencode($fb_title) . '" , "' . urlencode($short_url) . '")\' class="user-activity twitter def-cur-pointer"><i class="fa fa-twitter"></i></a></li><li><a title="share on google+" rel="' . $node->nid . '" data-tag="' . $node->type . '" data-activity="google_share" data-status="1" onclick=\'return googleplusbtn("' . $share_page_link . '" )\' class="user-activity google def-cur-pointer"><i class="fa fa-google-plus"></i></a></li></ul></div>';
          $breaking_output .= '</div></div>';
          if($i == 3) {
            $breaking_output .= '<div class="breaking-section">';
                $block = block_load('itg_ads', ADS_RHS1);
                $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                if(is_array($render_array)) {
                  $breaking_output .=  render($render_array);
                } else {
                   if (!empty($itg_ad['200*200_right_bar_ad1'])) {
                    $breaking_output .=  $itg_ad['200*200_right_bar_ad1'];
                  }
                }
            $breaking_output .= '</div>'; 
          // $i = 0;
        }                          
      }
      $breaking_output .= '<span class="no-record" style="display:none">' . t('No Record Found') . '</span>';
      print $breaking_output;
       
    }
  }

endif;
?>
</div>
            
  </div>
</div>
</div>
