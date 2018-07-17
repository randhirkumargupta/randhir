<?php
// Handel case if there is not any bigstory selected in widget then hide all bug story.
if (!empty($data['node_data'])) :
  global $base_url, $user;
  $is_videogallery = FALSE;
  $href = $base_url . '/' . drupal_get_path_alias("node/{$data['node_data']->nid}");
  $data_nid = "";
  $has_ajax = "";
  $photo_icon = "";
  $video_icon = "";
  $image = "<img src='" . $base_url . drupal_get_path('theme', 'itg') . "/images/default_for_all.png' alt='' title='' />";
  $share_desc = $share_desc_fb = "";
  if ($data['node_data']->type == 'videogallery') {
    $is_videogallery = TRUE;
    $data_nid = "data-nid='" . $data['node_data']->nid . "'";
    $has_ajax = " class='has-ajax-big-story'";
    $href = "#";
    $video_icon = "<i class='fa fa-play-circle'></i>";
  }
  if ($data['node_data']->type == 'photogallery') {
    $photo_icon = "<i class='fa fa-camera'></i>";
  }

  if ($is_videogallery) {
    print '<div id="videogallery-iframe"></div>';
  }
  $data_tb_region_item = '';
  if(drupal_is_front_page()){
    $data_tb_region_item = 'data-tb-region-item';
  }
  $fb_image = '';
  $uri = base64_encode(SITE_PROTOCOL . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']);
  ?>
  <!-- Big news Block -->
  <span class="widget-title"><a title="<?php echo _widget_title($data['node_data']->title); ?>" href='<?php echo $href ?>' <?php print $data_nid . $has_ajax; ?>>News</a></span>
  <div data-tb-region="homeBigStory" class="big-news big-news-content-<?php print $data['node_data']->type ?>">
      <div class="row">
          <div class="big-story-col-1">
              <!-- LIVE TV IS PUT IN PLACE OF EXTRA LARGE IMAGE  -->
              <?php if (!empty($data['live_tv'])) : ?>
                <div class='live-tv-big-story iframe-video'> <?php print $data['live_tv']; ?> </div>
              <?php else : ?>
                <!-- EXTRA LARGE IMAGE IS PUT -->
                <?php if (!empty($data['node_data']->field_story_extra_large_image['und'][0]['uri'])) { ?>
                  <a  href='<?php echo $href ?>' <?php print $data_nid . $has_ajax; ?>>
                      <img alt="<?php echo $data['node_data']->field_story_extra_large_image['und'][0]['alt'] ?>" title="<?php echo $data['node_data']->field_story_extra_large_image['und'][0]['title'] ?>" src="<?php print image_style_url("big_story_widget", $data['node_data']->field_story_extra_large_image['und'][0]['uri']); ?>"/>
                      <?php print $video_icon; ?>
                      <?php print $photo_icon; ?>
                  </a>                  
                  <img class="loading-popup" src="<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/tab-loading.gif');?>" alt="loading" />
                  <?php
                  // prepare configuration for sharing
                  $fb_image = file_create_url($data['node_data']->field_story_extra_large_image['und'][0]['uri']);
                } else {
                  ?>
                  <a title="<?php echo _widget_title($data['node_data']->title); ?>" href='<?php echo $href ?>' <?php print $data_nid . $has_ajax; ?>>
                    <img width="647" height="363" src="<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/itg_image647x363.jpg');?>" alt="" title="" />
                  </a>  

                  <img class="loading-popup" src="<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/tab-loading.gif');?>" alt="loading" />          
                <?php } ?>
                <!-- END EXTRA LARGE IMAGE --> 
              <?php endif; ?>
          </div>
          <div class="big-story-col-2">
              <?php if (!empty($data['node_data']->title)) : ?>
                <?php
                $red_dot_class = "";
                $red_dot_class = ($data['node_data']->type == 'breaking_news') ? 'breaking-news-red-dot' : "";
                if (function_exists('itg_common_get_smiley_title')) {
                  $big_story_simly_array = array(
                    'field_story_short_headline_value' => $data['node_data']->field_story_short_headline['und'][0]['value'],
                    'field_emoji_position_value' => $data['node_data']->field_emoji_position['und'][0]['value'],
                    'field_emoji_2_value' => $data['node_data']->field_emoji_2['und'][0]['value'],
                    'field_emoji_value' => $data['node_data']->field_emoji['und'][0]['value'],
                    'title' => $data['node_data']->title,
                  );
                  $node_title = itg_common_get_smiley_title($big_story_simly_array, 0, 100);
                } else {
                  $node_title = mb_strimwidth($data['node_data']->title, 0, 110, "..");
                }
                // get developing story status
                if (function_exists('itg_msi_get_lock_story_status') && $data['node_data']->type == 'story') {
                  $get_develop_story_status = itg_msi_get_lock_story_status($data['node_data']->nid, 'developing_story');
                  if (!empty($get_develop_story_status)) {
                    $red_dot_class = "";
                    $node_title = $node_title . "<i class='fa fa-circle' aria-hidden='true' title='Development story'></i>";
                  }
                }

                // prepare configuration for sharing
                $share_title = $data['node_data']->title;
                $bigstory_fb_share = "";
                if(function_exists('itg_common_only_text_string')) {
                  $bigstory_fb_share = itg_common_only_text_string($share_title);
                }
                $actual_link = $base_url . '/' . drupal_get_path_alias("node/{$data['node_data']->nid}");
                $short_url = $actual_link;
                $pipelinetext = "";
                $pipelineclass = "";
                if (!empty($data['node_data']->type) && $data['node_data']->type == 'story') {
                  if (function_exists('itg_common_get_addontitle')) {
                    $add_on_data = array(
                      'ad_title' => $data['node_data']->field_story_new_title['und'][0]['value'],
                      'ad_url' => $data['node_data']->field_story_redirection_url_titl['und'][0]['value'],
                    );
                    if (!empty($add_on_data['ad_title']) && !empty($add_on_data['ad_url'])) {
                      $pipelinetext = ' <span class="add-on-story-pipline">|</span> <a target="_blank" href="' . $add_on_data['ad_url'] . '" title="' . $add_on_data['ad_title'] . '">' . ucfirst($add_on_data['ad_title']) . '</a>';
                      $pipelineclass = 'pipeline-added';
                    }
                  }
                }
                ?>
                <h1 <?php echo $data_tb_region_item;?> title="<?php echo strip_tags($node_title); ?>" class="<?php echo $pipelineclass; ?> big-story-first big-story-<?php print $data['node_data']->nid . ' ' . $red_dot_class ?> <?php print $pipelineclass; ?>">
                <?php echo l($node_title, "node/" . $data['node_data']->nid, array('html' => TRUE, "attributes" => array("title" => $share_title))); ?>
                <?php echo $pipelinetext; ?>
                </h1>
                  <?php endif; ?>
              <p>
                  <!-- Story -->
                  <?php if (!empty($data['node_data']->field_story_kicker_text['und'][0]['value'])) : ?>
                  <?php
                  // prepare configuration for sharing
                  $share_desc = preg_replace("/'/", "\\'", $data['node_data']->field_story_kicker_text['und'][0]['value']);
                  $share_desc_fb = trim(htmlentities($share_desc, ENT_QUOTES));
                  print mb_strimwidth($data['node_data']->field_story_kicker_text['und'][0]['value'], 0, 200, '..');
                  ?>
                  <?php endif; ?>
                  <!-- Live blog -->
                  <?php if (!empty($data['node_data']->field_label['und'][0]['value'])) : ?>
                    <?php
                    // prepare configuration for sharing
                    if (!empty($data['node_data']->field_story_kicker_text['und'][0]['value'])) {
                      $share_desc = preg_replace($data['node_data']->field_story_kicker_text['und'][0]['value']);
                      $share_desc_fb = trim(htmlentities($share_desc, ENT_QUOTES));
                    }
                    print mb_strimwidth($data['node_data']->field_label['und'][0]['value'], 0, 165, '..');
                    ?>
                  <?php endif; ?>

              </p>

  <?php if (!empty($data['node_data']->nid)) :?>
                <div class="share-new">
                    <ul>
                        <li><a title="share on facebook" onclick='fbpop("<?php print $actual_link; ?>", "<?php print urlencode($bigstory_fb_share); ?>", "", "<?php print $fb_image; ?>", "<?php print $base_url; ?>", "<?php print $data['node_data']->nid;?>")'><i class="fa fa-facebook"></i></a></li>
                        <li><a title="share on twitter" class="user-activity def-cur-pointer" data-rel="<?php print $data['node_data']->nid; ?>" data-tag="<?php print $data['node_data']->type; ?>" data-activity="twitter_share" data-status="1" href="javascript:" onclick="twitter_popup('<?php print urlencode($share_title); ?>', '<?php print $short_url; ?>')"><i class="fa fa-twitter"></i></a></li>

    <?php
    if (!empty($data['node_data']->type) && $data['node_data']->type == 'story') :
      
      if (drupal_is_front_page() && !empty(variable_get('photo_block_refresh'))) {
        $settings = array();
        $settings['follow_nid'] = $data['node_data']->nid;
        drupal_add_js(array('itg_story' => array('settings' => $settings)), array('type' => 'setting'));
        drupal_add_js(drupal_get_path('module', 'itg_story') . '/js/itg_follow_story_refresh.js', array('scope' => 'footer')); 
      }
      
      if (function_exists('itg_get_front_activity_info')) {
        $follow_status = itg_get_front_activity_info($data['node_data']->nid, $data['node_data']->type, $user->uid, 'follow_story', $status = '');
      } ?>
      <li class="follow-story follow-akamai-refresh"> <?php
                if ($user->uid > 0):
                  if (!empty($follow_status['nid']) && $follow_status['status'] == '1'):
                    ?>  
                    <a title = "Unfollow Story" href="javascript:" id="user-activity" data-rel="<?php print $data['node_data']->nid; ?>" data-tag="<?php print $data['node_data']->type; ?>" data-activity="follow_story" data-status="0" class="def-cur-pointer"><?php print t('Unfollow Story'); ?></a>
                  <?php else: ?>
                    <a title = "Follow the Story" href="javascript:" id="user-activity" data-rel="<?php print $data['node_data']->nid; ?>" data-tag="<?php print $data['node_data']->type; ?>" data-activity="follow_story" data-status="1" class="def-cur-pointer"><?php print t('Follow the Story'); ?></a>
                  <?php
                  endif;
                else:
                  ?>
                  <a title="Follow the Story" href="<?php print PARENT_SSO; ?>/saml_login/other/<?php print $uri; ?>" class=""><?php print t('Follow the Story'); ?></a>

                <?php endif; ?>
          <?php endif; ?>
          </li>
                    </ul>
                </div>
  <?php endif; ?>

              <?php if (!empty($data['node_data']->field_common_related_content['und'][0]['value'])) : ?>
                <div class="big-story-detail">
                    <ul>
    <?php
    if (function_exists('itg_front_big_story_related')) {
      print itg_front_big_story_related($data['node_data']->nid);
    }
    ?>                         
                    </ul>
                </div>
  <?php endif; ?>
          </div>
      </div>
  </div>
  <!-- Big news Block End -->
<?php endif; ?>
