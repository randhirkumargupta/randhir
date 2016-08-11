<!-- Big news Block -->
<div class="big-news">
  <div class="row">
    <div class="big-story-col-1">
      <?php if (!empty($data['node_data']->field_story_extra_large_image['und'][0]['uri'])) { ?>
        <img src="<?php print image_style_url("big_story_widget", $data['node_data']->field_story_extra_large_image['und'][0]['uri']); ?>" />
        <div class="story-tag"><?php print t("Big Story") ?></div>
        <?php
      }
      else {
        ?>
        <img src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
        <div class="story-tag"><?php echo t("Big Story") ?></div>
      <?php } ?>
    </div>
    <div class="big-story-col-2">
      <?php if (!empty($data['node_data']->title)) : ?>
      <h1 class="big-story-first big-story-<?php print $data['node_data']->nid ?>">
          <?php print mb_strimwidth($data['node_data']->title , 0 , 65 , ".."); ?>
        </h1>
      <?php endif; ?>
      <p>
        <!-- Story -->
        <?php if (!empty($data['node_data']->field_story_kicker_text['und'][0]['value'])) : ?>
          <?php print mb_strimwidth($data['node_data']->field_story_kicker_text['und'][0]['value'] , 0 , 165 , '..'); ?>
        <?php endif; ?>
        <!-- Live blog -->
        <?php if (!empty($data['node_data']->field_label['und'][0]['value'])) : ?>
          <?php print mb_strimwidth($data['node_data']->field_label['und'][0]['value'] , 0 , 165 , '..'); ?>
        <?php endif; ?>
        
      </p>
      <div class="share-new">
        <ul>
          <li><a href="#" title=""><i class="fa fa-facebook"></i></a></li>
          <li><a href="#" title=""><i class="fa fa-twitter"></i></a></li>
          <li><a href="#" title=""><?php echo t('Follow the Story');?></a></li>
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
              $url .=  "/$alise" ;
              $new_url = strtolower ( $url );
              if (!empty($data_data->title)) :
                print "<li><a href='$new_url' title=''>" . mb_strimwidth($data_data->title , 0 , 210 , '..') . "</a></li>";
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