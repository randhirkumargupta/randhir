<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
global $base_url;
$actual_link = SITE_PROTOCOL . $_SERVER['HTTP_HOST'] .'/amp'. $_SERVER['REQUEST_URI'];
$amp_link = str_replace('?amp', '', $actual_link);
$short_url = $amp_link; //shorten_url($amp_link, 'goo.gl');
$share_desc = '';
$share_image = '';
$source_type = $node->field_story_source_type[LANGUAGE_NONE][0]['value'];
?>

<?php
// code for schema header script
if ($node->field_type['und']['0']['value'] == 'Live Blog') {
  $embed_path = $base_url . '/' . drupal_get_path_alias('node/' . $node->nid);
  $embed_image = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
  if (!empty($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'])) {
    $embed_image = $embed_image;
  }
  else {
    $embed_image = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image647x363.jpg');
  }
  $embed_logo = $base_url . '/sites/all/themes/itg/logo.png';
  $blog_created_date = date('Y-m-d', $node->created);
  $blog_created_time = date('H:i:s', $node->created);
  $coverage_start_date = $blog_created_date . 'T' . $blog_created_time.'+05:30';
  $short_description_source = strip_tags($node->field_common_short_description[LANGUAGE_NONE][0]['value']);
  if (empty($node->field_breaking_coverage_end_time[LANGUAGE_NONE][0]['value'])) {
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
    $coverage_end_final_date = $coverage_end_date . 'T' . $coverage_end_time.'+05:30';
  }
  else {
    $coverage_end = strtotime($node->field_breaking_coverage_end_time[LANGUAGE_NONE][0]['value']);
    $coverage_end_date = date('Y-m-d', $coverage_end);
    $coverage_end_time = date('H:i:s', $coverage_end);
    $coverage_end_final_date = $coverage_end_date . 'T' . $coverage_end_time.'+05:30';
  }
  ?>
  <div itemtype="http://schema.org/LiveBlogPosting" itemscope="itemscope" id="blogIdjson">
      <meta itemprop="coverageStartTime" content="<?php print $coverage_start_date; ?>">
      <meta itemprop="coverageEndTime" content="<?php print $coverage_end_final_date; ?>">
      <meta itemprop="url" content="<?php print $embed_path; ?>">
      <meta itemprop="description" content="<?php print $short_description_source; ?>">
      <div class="bolg-content" id="bolgcontent">    
          <?php
          if (!empty($node->field_breaking_content_details[LANGUAGE_NONE])) {
			$collection_ids = array();
            foreach ($node->field_breaking_content_details['und'] as $blog_item) {
              $collection_ids[] = $blog_item['value'];
            }
            foreach ($collection_ids as $breaking_embed_item) {
              $field_collection_embed_id = $breaking_embed_item;
              $entity = entity_load('field_collection_item', array($field_collection_embed_id));
              $title = $entity[$field_collection_embed_id]->field_breaking_tile['und'][0]['value'];
              $embed_display_time = date("H:i", strtotime($entity[$field_collection_embed_id]->field_breaking_publish_time['und'][0]['value']));
              $created_date = date('Y-m-d\TH:i:s', $node->created);
              $modify_date = date('Y-m-d\TH:i:s', $node->changed);              
			  $created_date = $created_date.'+05:30';
		      $modify_date = $modify_date.'+05:30';
		      $embed_created = date("Y-m-d\TH:i:s", strtotime($entity[$field_collection_embed_id]->field_breaking_publish_time['und'][0]['value']));
		      $embed_created = $embed_created.'+05:30'; 
              ?>
              <div itemtype="http://schema.org/BlogPosting"   itemprop="liveBlogUpdate" itemscope="itemscope" data-type="text">
                  <p itemprop="headline" content="<?php print $node->title; ?>"></p>
                  <meta itemprop="datePublished" content="<?php print $embed_created; ?>">
                  <meta itemprop="author" content="IndiaToday.in">
                  <meta itemprop="dateModified" content="<?php print $embed_created; ?>">
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
      </div> </div>
<?php } ?>

<div class="live-block">
    <?php
    if (!empty($content)):
      $type = $node->field_type['und']['0']['value'];
      if ($type == 'Live Blog') {
        if (!empty($node->field_constituancy[LANGUAGE_NONE][0]['value'])) {
          $title = '<h1><span>' . $node->field_constituancy[LANGUAGE_NONE][0]['value'] . '</span>: ' . $node->title . '</h1>';
        }
        else {
          $title = '<h1>' . $node->title . '</h1>';
        }
        $share_title = $node->title;
        $fb_url = 'https://www.facebook.com/sharer/sharer.php?u='.$amp_link.'&title='.$share_title.'&picture='.$share_image;
        $twitter_url = 'https://twitter.com/intent/tweet?text='.urlencode($share_title).'&url='.$short_url.'&via=IndiaToday';
        $google_url = 'https://plus.google.com/share?url='.  urlencode($amp_link);
        ?>
        <?php print ($title) ?>
        <p class="short-discription">
            <?php
            $pattern = "#<p>(\s|&nbsp;|</?\s?br\s?/?>)*</?p>#";
            print preg_replace($pattern, '', $node->field_common_short_description[LANGUAGE_NONE][0]['value']);
            ?>
        </p>
        <div id="live-blog-amp-share"><div class="social-share">
          <amp-accordion disable-session-states>
          <section>
            <h2>
              <span class="show-more"><i class="fa fa-share-alt" aria-hidden="true"></i></span>
              <span class="show-less"><i class="fa fa-share-alt" aria-hidden="true"></i></span>
            </h2>
            <div class="share-link">
              <a href="<?php print $twitter_url; ?>" target="_blank" title="share on twitter"><i class="fa fa-twitter-square" aria-hidden="true"></i></a>
              <a href="<?php print $fb_url; ?>" target="_blank" title="share on facebook"><i class="fa fa-facebook-official" aria-hidden="true"></i></a>
              <a href="<?php print $google_url;?>" target="_blank" title="share on G+"><i class="fa fa-google-plus-square" aria-hidden="true"></i></a>
            </div>
          </section>
          </amp-accordion>
        </div></div>
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
                    if ($high['value'] != '<br/>') {
                      print '<li>' . $high['value'] . '</li>';
                      $h_count++;
                    }
                  }
                  ?>

              </ul>
          </div>
        <?php } ?>
        <div class="timeline">
    <?php if (!empty($node->field_live_blog_timeline_active[LANGUAGE_NONE]['0']['value'])) { ?>
              <h3><?php print t('Timeline'); ?></h3>
              <input id="slider-range" class="irs-hidden-input" readonly="">
            <?php } ?>
            <?php
            if (!empty($node->field_breaking_content_details[LANGUAGE_NONE])) {
              $breaking_output .= '';
              foreach ($node->field_breaking_content_details['und'] as $blog_item) {
                $field_collection_ids[] = $blog_item['value'];
              }
              if ($source_type != 'migrated') {
                rsort($field_collection_ids);
              }
              // code for slider first/ last time
              $slider_last_item = entity_load('field_collection_item', array(reset($field_collection_ids)));
              $slider_last_time = date("H:i A", strtotime($slider_last_item[reset($field_collection_ids)]->field_breaking_publish_time['und'][0]['value']));
              $slider_first_item = entity_load('field_collection_item', array(end($field_collection_ids)));
              $slider_first_time = date("H:i A", strtotime($slider_first_item[end($field_collection_ids)]->field_breaking_publish_time['und'][0]['value']));              
			   $i =0;
              foreach ($field_collection_ids as $breaking_item) {
                $breaking_output .= '<div class="breaking-section">';
                $field_collection_id = $breaking_item;
                $entity = entity_load('field_collection_item', array($field_collection_id));
                $html = preg_replace('#<script(.*?)>(.*?)</script>#is', '', $entity[$field_collection_id]->field_breaking_tile['und'][0]['value']);
                $fb_title = $string = preg_replace('/\s+/', ' ', itg_common_only_text_string($html));
                $pub_time = date("H:i", strtotime($entity[$field_collection_id]->field_breaking_publish_time['und'][0]['value']));
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
                
                $i++;
                $redirection_url = itg_custom_amp_body_filter($redirection_url);
                $redirection_url = preg_replace('#<script(.*?)>(.*?)</script>#is', '', $redirection_url);
                $breaking_output .= '<div class="dwrap"><div class="breaking-date">' . $pub_display_time . ' IST</div>';
                $breaking_output .= '<div class="breaking-discription">' . $redirection_url . '</div>';
                $breaking_output .= '<div id="live-blog-amp-share"><div class="social-share"><amp-accordion disable-session-states><section><h2><span class="show-more"><i class="fa fa-share-alt" aria-hidden="true"></i></span><span class="show-less"><i class="fa fa-share-alt" aria-hidden="true"></i></span></h2><div class="share-link">';
                $breaking_output .= '<a href="'.$twitter_url.'" target="_blank" title="share on twitter"><i class="fa fa-twitter-square" aria-hidden="true"></i></a>';
                $breaking_output .= '<a href="'.$fb_url.'" target="_blank" title="share on facebook"><i class="fa fa-facebook-official" aria-hidden="true"></i></a>';
                $breaking_output .= '<a href="'.$google_url.'" target="_blank" title="share on G+"><i class="fa fa-google-plus-square" aria-hidden="true"></i></a>';
                $breaking_output .= '</div></section></amp-accordion></div></div>';
                $breaking_output .= '</div></div>';
              }
              print $breaking_output;
            }
          }
        endif;
        ?>
    </div>
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
