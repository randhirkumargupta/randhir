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
if($node->field_type['und']['0']['value'] == 'Live Blog' || $node->field_type['und']['0']['value'] == 'Cricket Live Blog') {
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

if(empty($node->field_breaking_coverage_end_time[LANGUAGE_NONE][0]['value'])) {
if (!empty($node->field_breaking_content_details[LANGUAGE_NONE])) {
      foreach ($node->field_breaking_content_details['und'] as $blog_item) {
        $collection_ids[] = $blog_item['value'];
      }
}
$last_item = end($collection_ids);
$first_item = reset($collection_ids);

$entity = entity_load('field_collection_item', array($last_item));
$last_cov_tm = explode(" ", $entity[$last_item]->field_breaking_publish_time['und'][0]['value']);
$coverage_end_date = $last_cov_tm[0];
$coverage_end_time = $last_cov_tm[1];
$coverage_end_final_date = '';
if(!empty($last_cov_tm[0])){
 $coverage_end_final_date = $coverage_end_date.'T'.$coverage_end_time; 
}
} else {
$coverage_end = strtotime($node->field_breaking_coverage_end_time[LANGUAGE_NONE][0]['value']);
$coverage_end_date = date('Y-m-d', $coverage_end);
$coverage_end_time = date('h:i:s', $coverage_end);
$coverage_end_final_date = '';
if(!empty($coverage_end)){
 $coverage_end_final_date = $coverage_end_date.'T'.$coverage_end_time; 
}
}
?>
<div itemtype="http://schema.org/LiveBlogPosting" itemscope="itemscope" id="blogIdjson">
    <meta itemprop="coverageStartTime" content="<?php print $coverage_start_date; ?>">
    <meta itemprop="coverageEndTime" content="<?php print $coverage_end_final_date; ?>">
    <meta itemprop="url" content="<?php print $embed_path; ?>">
    <meta itemprop="description" content="<?php print $short_description_source; ?>">
    <?php if($node->field_type['und']['0']['value'] == 'Live Blog'):?>
    <div class="bolg-content" id="bolgcontent">    
    <?php endif;?>	    
<?php
  if ($node->field_type['und']['0']['value'] == 'Live Blog' && !empty($node->field_breaking_content_details[LANGUAGE_NONE])) {
      foreach ($node->field_breaking_content_details['und'] as $blog_item) {
        $collection_ids[] = $blog_item['value'];
      }

      foreach ($collection_ids as $breaking_embed_item) {
        $field_collection_embed_id = $breaking_embed_item;
        $entity = entity_load('field_collection_item', array($field_collection_embed_id));
        $title = $entity[$field_collection_embed_id]->field_breaking_tile['und'][0]['value'];
        //$embed_display_time = date("H:i", strtotime($entity[$field_collection_embed_id]->field_breaking_publish_time['und'][0]['value']) + 19800);
        $embed_display_time = date("H:i", strtotime($entity[$field_collection_embed_id]->field_breaking_publish_time['und'][0]['value']));
        $created_date = date('Y-m-d H:i:s', $node->created);
        $modify_date = date('Y-m-d H:i:s', $node->changed);
      
?>
                    <div itemtype="http://schema.org/BlogPosting"   itemprop="liveBlogUpdate" itemscope="itemscope" data-type="text">
                        <p itemprop="headline" content="<?php print $node->title; ?>"></p>
                        <h2 itemprop="articleBody" style="display:none"><strong><?php print $embed_display_time;?> IST: </strong><?php print strip_tags($title); ?></h2>
                        <meta itemprop="datePublished" content="<?php print $created_date;?>">
                        <meta itemprop="author" content="IndiaToday.in">
                        <meta itemprop="dateModified" content="<?php print $modify_date;?>">
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
        


<?php } } ?> 
 <?php if ($node->field_type['und']['0']['value'] == 'Cricket Live Blog'){
        $created_date = date('Y-m-d H:i:s', $node->created);
        $modify_date = date('Y-m-d H:i:s', $node->changed); ?>
        <div itemtype="http://schema.org/BlogPosting"   itemprop="liveBlogUpdate" itemscope="itemscope" data-type="text">
          <p itemprop="headline" content="<?php print $node->title; ?>"></p>
          <h2 itemprop="articleBody" style="display:none"></h2>
          <meta itemprop="datePublished" content="<?php print $created_date;?>">
          <meta itemprop="author" content="IndiaToday.in">
          <meta itemprop="dateModified" content="<?php print $modify_date;?>">
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
 <?php } ?>       
</div> 
<?php if($node->field_type['und']['0']['value'] == 'Live Blog'):?>
</div>
<?php endif;?>
<?php } ?>

<div class="live-block">

    <?php
    if (!empty($content)):
      $type = $node->field_type['und']['0']['value'];
      if ($type == 'Cricket Live Blog') {
        $settings = array(
          'base_url' => $base_url,
          'nid'=> $node->nid,
          'match_id' => (empty($node->field_match_id['und'][0]['value'])? FALSE:$node->field_match_id['und'][0]['value'])
        );
        drupal_add_js(array('itg_cricket_live_blog' => array('settings' => $settings)), array('type' => 'setting'));
        drupal_add_js(drupal_get_path('module', 'itg_breaking_news') . '/js/itg_cricket_live_blog.js', array('scope' => 'footer'));
        $embed_image = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
        if (!empty($node->field_constituancy[LANGUAGE_NONE][0]['value'])) {
            $title = '<h1><span>' . $node->field_constituancy[LANGUAGE_NONE][0]['value'] . '</span>: ' . $node->title . '</h1>';
        }
        else {
            $title = '<h1>' . $node->title . '</h1>';
        }
        print $title;
        ?>
                <p class="short-discription"> <?php print ($node->field_common_short_description[LANGUAGE_NONE][0]['value']) ?></p>
                <div class="social-share">
                    <ul>
                        <li><a class="share" href="javascript:void(0)"><i class="fa fa-share-alt"></i></a></li>
                        <li><a title="share on facebook" class="facebook def-cur-pointer" onclick='fbpop("<?php print $share_page_link; ?>", "<?php print urlencode($share_title); ?>", "<?php print urlencode($share_desc); ?>", "<?php print $share_image; ?>", "<?php print $base_url; ?>", "<?php print $nid; ?>")'><i class="fa fa-facebook"></i></a></li>
                        <li><a title="share on twitter" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="twitter_share" data-status="1" class="user-activity twitter def-cur-pointer" onclick='twitter_popup("<?php print urlencode($share_title); ?>", "<?php print urlencode($short_url); ?>")'><i class="fa fa-twitter"></i></a></li>
                        <li><a title="share on google+" class="user-activity google def-cur-pointer" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="google_share" data-status="1" onclick='return googleplusbtn("<?php print $share_page_link; ?>")'></a></li>

                    </ul>
                </div>
                <div class="stryimg" id="cricketblog" >
                    <img  alt="<?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt']; ?>" title="<?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title']; ?>" src="<?php print $embed_image; ?>">
                    <div class="bolg-content" id="bolgcontent">
                        <?php if(!empty($node->field_match_id['und'][0]['value'])):?>
                          <?php if(function_exists('get_commentary_data_db')){ ?>
                          <?php print get_cricket_live_blog_data($node->field_match_id['und'][0]['value'], 50); ?>
                          <?php } ?>
                        <?php else:?>
                        <?php if(function_exists('get_commentary_data_db')){
                                  print get_commentary_data_db($node->nid,0);                          
                              } 
                        ?>
                        <?php endif;?>
                    </div>       
                </div>
        <?php
	  } else if ($type == 'Live Blog' || $type == 'Breaking News') {
        if (!empty($node->field_constituancy[LANGUAGE_NONE][0]['value'])) {
          $title = '<h1><span>' . $node->field_constituancy[LANGUAGE_NONE][0]['value'] . '</span>: ' . $node->title . '</h1>';
        }
        else {
          $title = '<h1><span>' . $type . '</span>: ' . $node->title . '</h1>';
        }

        $share_title = $node->title;
        ?>
        <!--<h1><?php if ($type == 'Breaking News') { ?><span><?php print ($type) ?></span>: <?php } print ($title) ?></h1>-->
        <?php print ($title) ?>
        <p class="short-discription"> <?php print ($node->field_common_short_description[LANGUAGE_NONE][0]['value']) ?></p>
        <div class="social-share">
            <ul>
                <li><a class="share" href="javascript:void(0)"><i class="fa fa-share-alt"></i></a></li>
                <li><a title="share on facebook" class="facebook def-cur-pointer" onclick='fbpop("<?php print $share_page_link; ?>", "<?php print urlencode($share_title); ?>", "<?php print urlencode($share_desc); ?>", "<?php print $share_image; ?>", "<?php print $base_url; ?>", "<?php print $nid; ?>")'><i class="fa fa-facebook"></i></a></li>
                <li><a title="share on twitter" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="twitter_share" data-status="1" class="user-activity twitter def-cur-pointer" onclick='twitter_popup("<?php print urlencode($share_title); ?>", "<?php print urlencode($short_url); ?>")'><i class="fa fa-twitter"></i></a></li>
                <li><a title="share on google+" class="user-activity google def-cur-pointer" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="google_share" data-status="1" onclick='return googleplusbtn("<?php print $share_page_link; ?>")'></a></li>
				
            </ul>
            <?php if($node->field_type['und']['0']['value'] == 'Live Blog'):?>
             <span class="refresh-icon">Check Latest Updates <i onclick="location.reload();" style="cursor: pointer;" class="fa fa-refresh" aria-hidden="true"></i></span>
             <?php if (isset($embed_image) && !empty($embed_image)) { ?>
			   <div class="stryimg" id="liveblog" >
                 <img  alt="<?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt']; ?>" title="<?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title']; ?>" src="<?php print $embed_image; ?>">
			   </div>
			  <?php } ?>
			<?php endif; ?>
        </div>

        <?php
        if ($type == 'Live Blog') {
          $useragent = $_SERVER['HTTP_USER_AGENT'];
          if (function_exists(itg_live_tv_company)) {
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
                  <?php
                }
              }
              ?>


          <div class="live-hightlight">
          <?php if (!empty($node->field_story_highlights[LANGUAGE_NONE][0]['value'])) { ?>
                <h3><?php print t('Highlights'); ?></h3>
          <?php } ?>
              <ul>
      <?php
      $h_count = 1;
      foreach ($node->field_story_highlights['und'] as $high) {
        if($high['value'] != '<br/>') {
        print '<li>' . $high['value'] . '</li>';
        $h_count++;
        }
      }
      ?>

              </ul>
          </div>
                <?php } ?>
        <div class="timeline">
          <?php
            if (!empty($node->field_live_blog_timeline_active[LANGUAGE_NONE]['0']['value'])) { ?>
                <h3><?php print t('Timeline'); ?></h3>
                <input id="slider-range" class="irs-hidden-input" readonly="">
            <?php } ?>
    <?php
    if (!empty($node->field_breaking_content_details[LANGUAGE_NONE])) {
      $breaking_output .= '';
      foreach ($node->field_breaking_content_details['und'] as $blog_item) {
        $field_collection_ids[] = $blog_item['value'];
      }
      
      if($source_type != 'migrated') {
      rsort($field_collection_ids);
      }
      // code for slider first/ last time
			$slider_last_item = entity_load('field_collection_item', array(reset($field_collection_ids)));
			$slider_last_time = date("H:i A", strtotime($slider_last_item[reset($field_collection_ids)]->field_breaking_publish_time['und'][0]['value']));
			$slider_first_item = entity_load('field_collection_item', array(end($field_collection_ids)));
			$slider_first_time = date("H:i A", strtotime($slider_first_item[end($field_collection_ids)]->field_breaking_publish_time['und'][0]['value']));

			$settings = array();
			$settings['last'] = $slider_last_time;
			$settings['first'] = $slider_first_time;
			drupal_add_js(array('itg_front_end_common' => array('settings' => $settings)), array('type' => 'setting'));

			foreach ($field_collection_ids as $breaking_item) {
        $breaking_output .= '<div class="breaking-section">';
        $field_collection_id = $breaking_item;
        $entity = entity_load('field_collection_item', array($field_collection_id));
        $html = preg_replace('#<script(.*?)>(.*?)</script>#is', '', $entity[$field_collection_id]->field_breaking_tile['und'][0]['value']);
        $fb_title = $string = preg_replace('/\s+/', ' ', itg_common_only_text_string($html));
        //$pub_time = date("H:i", strtotime($entity[$field_collection_id]->field_breaking_publish_time['und'][0]['value']) + 19800);
        $pub_time = date("H:i", strtotime($entity[$field_collection_id]->field_breaking_publish_time['und'][0]['value']));
        //$pub_display_time = date("H:i A", strtotime($entity[$field_collection_id]->field_breaking_publish_time['und'][0]['value']) + 19800);
        $pub_display_time = date("H:i A", strtotime($entity[$field_collection_id]->field_breaking_publish_time['und'][0]['value']));
        $pub_time2 = str_replace(":", "", $pub_time);
        $current_time = str_replace(":", "", date('H:i'));
        if (!empty($entity[$field_collection_id]->field_breaking_redirection_url['und'][0]['value'])) {
          $url = preg_replace('#^https?://#', '', $entity[$field_collection_id]->field_breaking_redirection_url['und'][0]['value']);
          $redirection_url = l($entity[$field_collection_id]->field_breaking_tile['und'][0]['value'], 'http://' . $url, array("attributes" => array("target" => "_blank", "title" => $entity[$field_collection_id]->field_breaking_tile['und'][0]['value']), 'html' => TRUE));
        }
        else {
          $redirection_url = $entity[$field_collection_id]->field_breaking_tile['und'][0]['value'];
        }
        
        //if ($pub_time2 < $current_time) {
          $breaking_output .= '<div class="dwrap" timevalue="' . $pub_time2 . '" tcount="' . count($field_collection_ids) . '"><div class="breaking-date">' . $pub_display_time . ' IST</div>';
          $breaking_output .= '<div class="breaking-discription">' . $redirection_url . '</div><div class="social-share"><ul><li><a class="share" href="javascript:void(0)"><i class="fa fa-share-alt"></i></a></li><li><a title="share on facebook" onclick=\'fbpop("' . $share_page_link . '" , "' . urlencode($fb_title) . '" , "' . urlencode($share_desc) . '" , "' . $share_image . '")\' class="facebook def-cur-pointer"><i class="fa fa-facebook"></i></a></li><li><a title="share on twitter" rel="' . $node->nid . '" data-tag="' . $node->type . '" data-activity="twitter_share" data-status="1" onclick=\'twitter_popup("' . urlencode($fb_title) . '" , "' . urlencode($short_url) . '")\' class="user-activity twitter def-cur-pointer"><i class="fa fa-twitter"></i></a></li><li><a title="share on google+" rel="' . $node->nid . '" data-tag="' . $node->type . '" data-activity="google_share" data-status="1" onclick=\'return googleplusbtn("' . $share_page_link . '" )\' class="user-activity google def-cur-pointer"></a></li></ul></div>';
          $breaking_output .= '</div></div>';
        //}
      }
      $breaking_output .= '<span class="no-record" style="display:none">' . t('No Record Found') . '</span>';
      print $breaking_output;
    }
  }

endif;
?>
    </div>
