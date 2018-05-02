<?php if (!empty($data)) : global $base_url; ?>
<?php if(isset($data[0])) : ?>
<?php 
  $data_tb_region_item = '';
  if(drupal_is_front_page()){
	$data_tb_region_item = 'data-tb-region-item';  
  }
?>
  <div class="featured-news">
    <div class="featured-post featured-post-first">
	  <?php if ((isset($data[0]['webcast_val'])) && (!empty($data[0]['webcast_val']))) : ?>
		<div class='live-webcast-coverage'><?php print $data[0]['webcast_val']; ?></div>
      <?php elseif (!empty($data[0]['uri'])) : ?>
        <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $data[0]['nid']); ?>">
            <img src="<?php print image_style_url("magazine_top_story_483x271", $data[0]['uri']); ?>" alt="<?php echo $data[0]['field_story_extra_large_image_alt'] ?>" title="<?php echo $data[0]['field_story_extra_large_image_title'] ?>" />
        </a>
      <?php else : ?>
        <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $data[0]['nid']); ?>">
          <img width="483" height="271" src="<?php print  file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image483x271.jpg'); ?>" alt="" title="" />

        </a>
      <?php endif; ?>

      <?php if (!empty($data[0]['title'])) : ?>
        <?php
          // code for add on story title and url
          if (function_exists('itg_common_get_addontitle')) {
            $add_on_data = itg_common_get_addontitle($data[0]['node_obj']);
            $pipelinetext = "";
            $pipelineclass = "";
            if (!empty($add_on_data['ad_title']) && !empty($add_on_data['ad_url'])) {
              $pipelinetext = ' <span class="add-on-story-pipline">|</span> <a target="_blank" href="' . $add_on_data['ad_url'] . '" title="' . $add_on_data['ad_title'] . '">' . ucfirst($add_on_data['ad_title']) . '</a>';
              $pipelineclass = ' pipeline-added';
            }
          }
        ?>
        <h2 class="<?php echo $pipelineclass; ?> home-page-feature-<?php echo $data[0]['nid'] ?>">
          <?php
          
          if (function_exists('itg_common_get_smiley_title')) {
            echo l(itg_common_get_smiley_title($data[0]['node_obj'], 0, 80), "node/" . $data[0]['nid'], array('html' => TRUE , 'attributes' => array("title" => _widget_title($data[0]['title']))));
            echo $pipelinetext;
          }
          else {
            echo l(mb_strimwidth($data[0]['title'], 0, 90, ".."), "node/" . $data[0]['nid']  , array('attributes' => array("title" => $data[0]['title'])));
            echo $pipelinetext;
          }
          ?>
        </h2>   
      <?php endif; ?>
    </div>
 <?php endif; ?>     
<?php if(isset($data[1])) : ?>
    <div class="featured-post">
      <?php if (!empty($data[1]['mi_file_uri'])) : ?>
        <a  href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $data[1]['nid']); ?>">
          <!-- <img src="<?php print image_style_url("home_page_feature_small", $data[1]['mi_file_uri']); ?>" alt="<?php echo $data[1]['field_story_medium_image_alt'];?>" title="<?php echo $data[1]['field_story_medium_image_title'];?>" /> -->
          <?php print theme('image_style', array('path' => $data[1]['mi_file_uri'], 'style_name' => 'home_page_feature_small', 'alt' => $data[1]['field_story_medium_image_alt'], 'title' => $data[1]['field_story_medium_image_title'])); ?> 
        </a>
      <?php else : ?>
        <a  href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $data[1]['nid']); ?>">
          <img src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/itg_image237x133.jpg" alt="" title="" />
        </a>
      <?php endif; ?>
      <?php if (!empty($data[1]['title'])) : ?>
        <?php 
          // code for add on story title and url
          if (function_exists('itg_common_get_addontitle')) {
            $add_on_data = itg_common_get_addontitle($data[1]['node_obj']);
            $pipelinetext = "";
            $pipelineclass = "";
            if (!empty($add_on_data['ad_title']) && !empty($add_on_data['ad_url'])) {
              $pipelinetext = ' <span class="add-on-story-pipline">|</span> <a target="_blank" href="' . $add_on_data['ad_url'] . '" title="' . $add_on_data['ad_title'] . '">' . ucfirst($add_on_data['ad_title']) . '</a>';
              $pipelineclass = ' pipeline-added';
            }
          }
        ?>
        <h3 title="<?php echo $data[1]['title'];  ?>" class="<?php echo $pipelineclass; ?> home-page-feature-small-<?php echo $data[1]['nid'] ?>">
          <?php
          if (function_exists('itg_common_get_smiley_title')) {
            echo l(itg_common_get_smiley_title($data[1]['node_obj'], 0, 60), "node/" . $data[1]['nid'], array('html' => TRUE , 'attributes' => array("title" => _widget_title($data[1]['title']))));
            echo $pipelinetext;
            
          }
          else {
            echo l(mb_strimwidth($data[1]['title'], 0, 70, ".."), "node/" . $data[1]['nid'] , array('attributes' => array("title" => $data[1]['title'])));
            echo $pipelinetext;
            
          }
          ?>
        </h3>   
      <?php endif; ?>
    </div>
 <?php endif; ?>     
    <?php if(isset($data[2])) : ?>
    <div class="featured-post">
      <?php if (!empty($data[2]['mi_file_uri'])) : ?>
        <a  href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $data[2]['nid']); ?>">
            <!-- <img src="<?php print image_style_url("home_page_feature_small", $data[2]['mi_file_uri']); ?>" alt="<?php echo $data[1]['field_story_medium_image_alt'];?>" title="<?php echo $data[1]['field_story_medium_image_title'];?>" /> -->
            <?php print theme('image_style', array('path' => $data[2]['mi_file_uri'], 'style_name' => 'home_page_feature_small', 'alt' => $data[2]['field_story_medium_image_alt'], 'title' => $data[2]['field_story_medium_image_title'])); ?> 
        </a>
      <?php else : ?>
        <a  href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $data[2]['nid']); ?>">
          <img src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/itg_image237x133.jpg" alt="" title=""/>
        </a>
      <?php endif; ?>
      <?php if (!empty($data[2]['title'])) : ?>
        <?php
          // code for add on story title and url
          if (function_exists('itg_common_get_addontitle')) {
            $add_on_data = itg_common_get_addontitle($data[2]['node_obj']);
            $pipelinetext = "";
            $pipelineclass = "";
            if (!empty($add_on_data['ad_title']) && !empty($add_on_data['ad_url'])) {
              $pipelinetext = ' <span class="add-on-story-pipline">|</span> <a target="_blank" href="' . $add_on_data['ad_url'] . '" title="' . $add_on_data['ad_title'] . '">' . ucfirst($add_on_data['ad_title']) . '</a>';
              $pipelineclass = ' pipeline-added';
            }
          }
        ?>
        <h3 title="<?php echo $data[2]['title'];  ?>" class="<?php echo $pipelineclass; ?> home-page-feature-small-<?php echo $data[2]['nid'] ?>">
          <?php
          if (function_exists('itg_common_get_smiley_title')) {
            echo l(itg_common_get_smiley_title($data[2]['node_obj'], 0, 60), "node/" . $data[2]['nid'], array('html' => TRUE , 'attributes' => array("title" => _widget_title($data[2]['title']))));
            echo $pipelinetext;
            
          }
          else {
            echo l(mb_strimwidth($data[2]['title'], 0, 70, ".."), "node/" . $data[2]['nid'] , array('attributes' => array("title" => _widget_title($data[2]['title']))));
            echo $pipelinetext;
            
          }
          ?>
        </h3>    
      <?php endif; ?>
    </div>
      <?php endif; ?>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
