<?php if (!empty($data)) : global $base_url; ?>
  <!-- Big news Block -->
  <div class="big-news">
    <div class="row">
      <div class="big-story-col-1">
        <?php if (!empty($data['node_data']->field_story_extra_large_image['und'][0]['uri'])) { ?>
          <a href='<?php echo $base_url . '/' . drupal_get_path_alias("node/{$data['node_data']->nid}") ?>'>
            <img src="<?php print image_style_url("big_story_widget", $data['node_data']->field_story_extra_large_image['und'][0]['uri']); ?>" />
          </a>  
          <div class="story-tag"><?php print t("Big Story") ?></div>
          <?php
          // prepare configuration for sharing
          $image = file_create_url($data['node_data']->field_story_extra_large_image['und'][0]['uri']);
        }
        else {
          ?>
          <a href='<?php echo $base_url . '/' . drupal_get_path_alias("node/{$data['node_data']->nid}") ?>'>
            <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
          </a>  
          <div class="story-tag"><?php echo t("Big Story") ?></div>
        <?php } ?>
      </div>
      <div class="big-story-col-2">
        <?php if (!empty($data['node_data']->title)) : ?>
          <?php
          $red_dot_class = ($data['node_data']->type == 'breaking_news') ? 'breaking-news-red-dot' : "";
          // prepare configuration for sharing
          $share_title = mb_strimwidth($data['node_data']->title, 0, 65, "..");
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
            $share_desc = mb_strimwidth($data['node_data']->field_story_kicker_text['und'][0]['value'], 0, 165, '..');
            print mb_strimwidth($data['node_data']->field_story_kicker_text['und'][0]['value'], 0, 165, '..'); ?>
          <?php endif; ?>
          <!-- Live blog -->
          <?php if (!empty($data['node_data']->field_label['und'][0]['value'])) : ?>
            <?php 
            // prepare configuration for sharing
            $share_desc = mb_strimwidth($data['node_data']->field_story_kicker_text['und'][0]['value'], 0, 165, '..');
            print mb_strimwidth($data['node_data']->field_label['und'][0]['value'], 0, 165, '..'); ?>
          <?php endif; ?>

        </p>
        <div class="share-new">
          <ul>
            <li><a onclick="gogogo('<?php print $actual_link;?>', '<?php print $share_title; ?>', '<?php print $share_desc; ?>', '<?php print $image;?>')"><i class="fa fa-facebook"></i></a></li>
            <li><a href="javascript:" onclick="twitter_popup('<?php print urlencode($share_title);?>', '<?php print $short_url; ?>')"><i class="fa fa-twitter"></i></a></li>
            <li><a href="#" title=""><?php echo t('Follow the Story'); ?></a></li>
          </ul>
        </div>
        <div class="big-story-detail">                                
          <ul>
            <?php
            $extra = $data['related'];
            $realted_nodes = json_decode($extra);
            foreach ($realted_nodes as $related_node) {
              $url = "http://52.76.214.186";
              foreach ($related_node as $server => $data_id) {
                $url .= "/$server";
                $data_data = node_load($data_id);
                $alise = drupal_get_path_alias("node/$data_data->nid");
                $url .= "/$alise";
                $new_url = strtolower($url);
                if (!empty($data_data->title)) :
                  print "<li>" . l(mb_strimwidth($data_data->title, 0, 210, '..'), $new_url) . "</li>";
                  $url = "";
                endif;
              }
            }
            ?>
          </ul>                         
        </div>
      </div>
    </div>
  </div>
  <!-- Big news Block End -->
<?php endif; ?>