<?php
if (!empty($data)) : 
  global $base_url;
  $is_videogallery = FALSE;
  $href = $base_url . '/' . drupal_get_path_alias("node/{$data['node_data']->nid}");
  $data_nid = "";
  $has_ajax = "";
  $image = "<img src='".$base_url .drupal_get_path('theme', 'itg') . "/images/default_for_all.png />";
  $share_desc = $share_desc_fb = "";
  if ($data['node_data']->type == 'videogallery') {
    $is_videogallery = TRUE;
    $data_nid = "data-nid='" . $data['node_data']->nid . "'";
    $has_ajax = "class='has-ajax-big-story'";
    $href = "#";
  }
  ?>
  <?php
  if ($is_videogallery) {
    print '<div id="videogallery-iframe"></div>';
  }
  ?>
  <!-- Big news Block -->
  <div class="big-news big-news-content-<?php print $data['node_data']->type ?>">
    <div class="row">
      <div class="big-story-col-1">
        <!-- LIVE TV IS PUT IN PLACE OF EXTRA LARGE IMAGE  -->
        <?php if(!empty($data['live_tv'])) : ?>
          <div class='live-tv-big-story'> <?php print $data['live_tv']; ?> </div>
        <?php else : ?>
        <!-- EXTRA LARGE IMAGE IS PUT -->
          <?php if (!empty($data['node_data']->field_story_extra_large_image['und'][0]['uri'])) {
          ?>
          <a href='<?php echo $href ?>' <?php print $data_nid . $has_ajax; ?>>
            <img src="<?php print image_style_url("big_story_widget", $data['node_data']->field_story_extra_large_image['und'][0]['uri']); ?>" />
          </a>  
          <div class="story-tag"><?php print t("Big Story") ?></div>          
          <img class="loading-popup" src="<?php echo drupal_get_path('theme', 'itg').'/images/tab-loading.gif' ?>" alt="loading">
          <?php
          // prepare configuration for sharing
          $image = file_create_url($data['node_data']->field_story_extra_large_image['und'][0]['uri']);
        }
        else {
          ?>
          <a href='<?php echo $href ?>' <?php print $data_nid . $has_ajax; ?>>
            <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
          </a>  
          <div class="story-tag"><?php echo t("Big Story") ?></div>          
          <img class="loading-popup" src="<?php echo drupal_get_path('theme', 'itg').'/images/tab-loading.gif' ?>" alt="loading">          
        <?php } ?>
         <!-- END EXTRA LARGE IMAGE --> 
        <?php endif; ?>
      </div>
      <div class="big-story-col-2">
        <?php if (!empty($data['node_data']->title)) : ?>
          <?php
          $red_dot_class = ($data['node_data']->type == 'breaking_news') ? 'breaking-news-red-dot' : "";
          // prepare configuration for sharing
          $share_title = $data['node_data']->title;
          $bigstory_title = preg_replace("/'/", "\\'", $data['node_data']->title);
          $bigstory_fb_share= htmlentities($bigstory_title, ENT_QUOTES);
          $actual_link = $base_url . '/' . drupal_get_path_alias("node/{$data['node_data']->nid}");
          $short_url = shorten_url($actual_link, 'goo.gl');
          ?>
          <h1 class="big-story-first big-story-<?php print $data['node_data']->nid . ' ' . $red_dot_class ?>">
            <?php echo l(mb_strimwidth($data['node_data']->title, 0, 65, ".."), $base_url . '/' . drupal_get_path_alias("node/{$data['node_data']->nid}")); ?>
          </h1>
        <?php endif; ?>
        <p>
          <!-- Story -->
          <?php if (!empty($data['node_data']->field_story_kicker_text['und'][0]['value'])) : ?>
            <?php
            // prepare configuration for sharing
            $share_desc = preg_replace($data['node_data']->field_story_kicker_text['und'][0]['value']);
            $share_desc_fb= htmlentities($share_desc, ENT_QUOTES);
            print mb_strimwidth($data['node_data']->field_story_kicker_text['und'][0]['value'], 0, 165, '..');
            ?>
          <?php endif; ?>
          <!-- Live blog -->
          <?php if (!empty($data['node_data']->field_label['und'][0]['value'])) : ?>
            <?php
            // prepare configuration for sharing
            $share_desc = preg_replace($data['node_data']->field_story_kicker_text['und'][0]['value']);
            $share_desc_fb= htmlentities($share_desc, ENT_QUOTES);
            print mb_strimwidth($data['node_data']->field_label['und'][0]['value'], 0, 165, '..');
            ?>
          <?php endif; ?>

        </p>
        
        <?php if(!empty($data['node_data']->nid)) : ?>
          <div class="share-new">
            <ul>
              <li><a onclick="fbpop ('<?php print $actual_link; ?>', '<?php print $bigstory_fb_share; ?>', '<?php print $share_desc_fb; ?>', '<?php print $image; ?>')"><i class="fa fa-facebook"></i></a></li>
              <li><a href="javascript:" onclick="twitter_popup ('<?php print urlencode($share_title); ?>', '<?php print $short_url; ?>')"><i class="fa fa-twitter"></i></a></li>
              <li><a href="#" title=""><?php echo t('Follow the Story'); ?></a></li>
            </ul>
          </div>
        <?php endif; ?>
        
        <?php if(!empty($data['node_data']->field_common_related_content['und'][0]['value'])) : ?>
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
                if (!empty($related_data)) {
                  print "<li>" . l($related_data->label, $related_data->url, array("attributes" => array("target" => "_blank"))) . "</li>";
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