<div class="top-takes-video-container">
<h3><span><?php print t("Top Takes") ?></span></h3>
<ul>  
  <?php foreach ($data as $video_key => $video_data) { ?>
  <li id="top-takes-<?php echo $video_data->nid ?>" class="top-takes-video top-takes-list top-takes-<?php echo $video_key ?>"">
      <?php if (!empty($video_data->field_story_extra_large_image['und'][0]['uri'])) { ?>
        <a href="<?php print drupal_get_path_alias("node/$video_data->nid"); ?>" class="pic">         
          <img width="88" height="66" src="<?php print image_style_url("thumbnail", $video_data->field_story_extra_large_image['und'][0]['uri']); ?>" />
        </a>
        <?php
      }
      else {
        ?>
        <a href="<?php print drupal_get_path_alias("node/$video_data->nid"); ?>" class="pic">
          <img width="88" height="66" src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
        </a>
      <?php } ?>
      <?php if (!empty($video_data->title)) : ?>
        <p class="title">           
          <a href="<?php print drupal_get_path_alias("node/$video_data->nid"); ?>"><?php print $video_data->title; ?></a>
        </p>
      <?php endif; ?>
    </li>
  <?php } ?>
</ul>
</div>