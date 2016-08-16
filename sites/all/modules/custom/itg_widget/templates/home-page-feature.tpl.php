<?php if (!empty($data)) : global $base_url; ?>
  <div class="featured-news">
    <div class="featured-post featured-post-first">
      <?php if (isset($data[0]->field_story_extra_large_image) && $data[0]->field_story_extra_large_image['und'][0]['uri']) : ?>
        <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$data[0]->nid}"); ?>">
          <img src="<?php print image_style_url("home_page_feature_large", $data[0]->field_story_extra_large_image['und'][0]['uri']); ?>" />
        </a>
      <?php else : ?>
        <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$data[0]->nid}"); ?>">
          <img src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
        </a>
      <?php endif; ?>

      <?php if (!empty($data[0]->title)) : ?>
        <h2 class="home-page-feature-<?php echo $data[0]->nid ?>">
          <?php echo l(mb_strimwidth($data[0]->title, 0, 90, ".."), $base_url . '/' . drupal_get_path_alias("node/{$data[0]->nid}")); ?>
        </h2>   
      <?php endif; ?>
    </div>

    <div class="featured-post">
      <?php if (isset($data[1]->field_story_extra_large_image) && $data[1]->field_story_extra_large_image['und'][0]['uri']) : ?>
        <a  href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$data[1]->nid}"); ?>">
          <img src="<?php print image_style_url("home_page_feature_small", $data[1]->field_story_extra_large_image['und'][0]['uri']); ?>" />
        </a>
      <?php else : ?>
        <a  href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$data[1]->nid}"); ?>">
          <img src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
        </a>
      <?php endif; ?>
      <?php if (!empty($data[1]->title)) : ?>
        <h3 class="home-page-feature-small-<?php echo $data[1]->nid ?>">
          <?php echo l(mb_strimwidth($data[1]->title, 0, 150, ".."), $base_url . '/' . drupal_get_path_alias("node/{$data[1]->nid}")) ?>
        </h3>   
      <?php endif; ?>
    </div>

    <div class="featured-post">
      <?php if (isset($data[2]->field_story_extra_large_image) && $data[2]->field_story_extra_large_image['und'][0]['uri']) : ?>
        <a  href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$data[2]->nid}"); ?>">
          <img src="<?php print image_style_url("home_page_feature_small", $data[2]->field_story_extra_large_image['und'][0]['uri']); ?>" />
        </a>
      <?php else : ?>
        <a  href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$data[2]->nid}"); ?>">
          <img src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
        </a>
      <?php endif; ?>
      <?php if (!empty($data[2]->title)) : ?>
        <h3 class="home-page-feature-small-<?php echo $data[2]->nid ?>">
          <?php echo l(mb_strimwidth($data[2]->title, 0, 150, ".."), $base_url . '/' . drupal_get_path_alias("node/{$data[2]->nid}")) ?>
        </h3>    
      <?php endif; ?>
    </div>

  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>