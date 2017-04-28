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
  $image = "<img src='" . $base_url . drupal_get_path('theme', 'itg') . "/images/default_for_all.png' alt='' />";
  $share_desc = $share_desc_fb = "";
  if ($data['node_data']->type == 'videogallery') {
    $is_videogallery = TRUE;
    $data_nid = "data-nid='" . $data['node_data']->nid . "'";
    $has_ajax = "class='has-ajax-big-story'";
    $href = "#";
    $video_icon = "<i class='fa fa-play-circle'></i>";
  }
  if ($data['node_data']->type == 'photogallery') {
    $photo_icon = "<i class='fa fa-camera'></i>";
  }
 
  if ($is_videogallery) {
    print '<div id="videogallery-iframe"></div>';
  }
  $fb_image = '';
  ?>
  <!-- Big news Block -->
  <div class="big-news big-news-content-<?php print $data['node_data']->type ?>">
    <div class="row">
      <div class="big-story-col-1">
        <!-- LIVE TV IS PUT IN PLACE OF EXTRA LARGE IMAGE  -->
        <?php if (!empty($data['live_tv'])) : ?>
          <div class='live-tv-big-story'> <?php print $data['live_tv']; ?> </div>
        <?php else : ?>
          <!-- EXTRA LARGE IMAGE IS PUT -->
          <?php if (!empty($data['node_data']->field_story_extra_large_image['und'][0]['uri'])) { ?>
          <a title="<?php echo $data['node_data']->title; ?>" href='<?php echo $href ?>' <?php print $data_nid . $has_ajax; ?>>
                <img alt="<?php echo $data['node_data']->field_story_extra_large_image['und'][0]['alt'] ?>" title="<?php echo $data['node_data']->field_story_extra_large_image['und'][0]['title'] ?>" src="<?php print image_style_url("big_story_widget", $data['node_data']->field_story_extra_large_image['und'][0]['uri']); ?>"/>
              <?php print $video_icon; ?>
              <?php print $photo_icon; ?>
            </a>
            <div class="story-tag"><?php print t("Big Story") ?></div>          
            <img class="loading-popup" src="<?php echo drupal_get_path('theme', 'itg') . '/images/tab-loading.gif' ?>" alt="loading" />
            <?php
            // prepare configuration for sharing
            $fb_image = file_create_url($data['node_data']->field_story_extra_large_image['und'][0]['uri']);
          }
          else {
            ?>
            <a title="<?php echo $data['node_data']->title; ?>" href='<?php echo $href ?>' <?php print $data_nid . $has_ajax; ?>>
              <img width="647" height="363" src="<?php print $base_url . '/' . drupal_get_path('theme', 'itg'); ?>/images/itg_image647x363.jpg" alt="" />
            </a>  
            <div class="story-tag"><?php echo t("Big Story") ?></div>          
            <img class="loading-popup" src="<?php echo drupal_get_path('theme', 'itg') . '/images/tab-loading.gif' ?>" alt="loading" />          
          <?php } ?>
          <!-- END EXTRA LARGE IMAGE --> 
        <?php endif; ?>
      </div>
      <div class="big-story-col-2">
        <?php if (!empty($data['node_data']->title)) : ?>
          <?php
          $red_dot_class = "";
          $red_dot_class = ($data['node_data']->type == 'breaking_news') ? 'breaking-news-red-dot' : "";
          if(function_exists('itg_common_get_smiley_title')) {
            $node_title = itg_common_get_smiley_title($data['node_data']->nid, 0, 65);
          }
          else {
            $node_title = mb_strimwidth($data['node_data']->title, 0, 65, "..");
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
          $bigstory_title = preg_replace("/'/", "\\'", $data['node_data']->title);
          $bigstory_fb_share = htmlentities($bigstory_title, ENT_QUOTES);
          $actual_link = $base_url . '/' . drupal_get_path_alias("node/{$data['node_data']->nid}");
          $short_url = shorten_url($actual_link, 'goo.gl');
          ?>
          <h1 class="big-story-first big-story-<?php print $data['node_data']->nid . ' ' . $red_dot_class ?>">
            <?php echo l($node_title, "node/" . $data['node_data']->nid, array('html' => TRUE , "attributes" => array("title" => $node_title))); ?>
          </h1>
        <?php endif; ?>
        <p>
          <!-- Story -->
          <?php if (!empty($data['node_data']->field_story_kicker_text['und'][0]['value'])) : ?>
            <?php
            // prepare configuration for sharing
            $share_desc = preg_replace("/'/", "\\'", $data['node_data']->field_story_kicker_text['und'][0]['value']);
            $share_desc_fb = htmlentities($share_desc, ENT_QUOTES);
            print mb_strimwidth($data['node_data']->field_story_kicker_text['und'][0]['value'], 0, 165, '..');
            ?>
          <?php endif; ?>
          <!-- Live blog -->
          <?php if (!empty($data['node_data']->field_label['und'][0]['value'])) : ?>
            <?php
            // prepare configuration for sharing
            if (!empty($data['node_data']->field_story_kicker_text['und'][0]['value'])) {
              $share_desc = preg_replace($data['node_data']->field_story_kicker_text['und'][0]['value']);
              $share_desc_fb = htmlentities($share_desc, ENT_QUOTES);
            }
            print mb_strimwidth($data['node_data']->field_label['und'][0]['value'], 0, 165, '..');
            ?>
          <?php endif; ?>

        </p>

        <?php if (!empty($data['node_data']->nid)) : ?>
          <div class="share-new">
            <ul>
              <li><a title="share on facebook" onclick="fbpop ('<?php print $actual_link; ?>', '<?php print $bigstory_fb_share; ?>', '<?php print $share_desc_fb; ?>', '<?php print $fb_image; ?>')"><i class="fa fa-facebook"></i></a></li>
              <li><a title="share on twitter" class="user-activity def-cur-pointer" rel="<?php print $data['node_data']->nid; ?>" data-tag="<?php print $data['node_data']->type; ?>" data-activity="twitter_share" data-status="1" href="javascript:" onclick="twitter_popup ('<?php print urlencode($share_title); ?>', '<?php print $short_url; ?>')"><i class="fa fa-twitter"></i></a></li>

              <?php
              if (!empty($data['node_data']->type) && $data['node_data']->type == 'story') :
                if (function_exists('itg_get_front_activity_info')) {
                  $follow_status = itg_get_front_activity_info($data['node_data']->nid, $data['node_data']->type, $user->uid, 'follow_story', $status = '');
                }
                if ($user->uid > 0):
                  if (!empty($follow_status['nid']) && $follow_status['status'] == '1'):
                    ?>  
                    <li class="follow-story"><a title = "Unfollow Story" href="javascript:" id="user-activity" rel="<?php print $data['node_data']->nid; ?>" data-tag="<?php print $data['node_data']->type; ?>" data-activity="follow_story" data-status="0" class="def-cur-pointer"><?php print t('Unfollow Story'); ?></a></li>
                  <?php else: ?>
                    <li class="follow-story"><a title = "Follow the Story" href="javascript:" id="user-activity" rel="<?php print $data['node_data']->nid; ?>" data-tag="<?php print $data['node_data']->type; ?>" data-activity="follow_story" data-status="1" class="def-cur-pointer"><?php print t('Follow the Story'); ?></a></li>
                  <?php endif;
                else: ?>
                  <li class="mhide"><?php if (function_exists('itg_sso_url')) {
            print itg_sso_url('Follow the Story');
          } ?></li>
            <?php endif; ?>
          <?php endif; ?>

            </ul>
          </div>
            <?php endif; ?>

            <?php if (!empty($data['node_data']->field_common_related_content['und'][0]['value'])) : ?>
          <div class="big-story-detail">
            <ul>
              <?php
              $related_string = $data['node_data']->field_common_related_content['und'][0]['value'];
              if (!empty($related_string)) {
                $nodes_with_prefix = explode(",", $related_string);
                foreach ($nodes_with_prefix as $nodes_with_prefix) {
                  $prefix_with_values = explode("_", $nodes_with_prefix);
                  $site_hash[] = $prefix_with_values;
                }
              }
              ?>
              <?php
              foreach ($site_hash as $site_hash_key => $nodes_array_with_prefix) {
                $current_site_hash = strtolower($nodes_array_with_prefix[0]);
                $current_entity_id = $nodes_array_with_prefix[1];
                $related_data = itg_get_link_from_hash_and_entity_solr_search($current_entity_id, $current_site_hash);
                $front_url = str_replace('-backend', '', $related_data->url);
                if (!empty($related_data)) {
                  print "<li>" . l($related_data->label, $front_url, array("attributes" => array("target" => "_blank" ,'title' => $related_data->label))) . "</li>";
                }
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