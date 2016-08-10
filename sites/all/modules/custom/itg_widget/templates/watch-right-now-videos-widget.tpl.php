<?php if (!empty($data)) : ?>
  <ul class="watch-right-now-video">
    <h3><span><?php print t("Watch Right Now") ?></span></h3>
    <?php foreach ($data as $video_key => $video_data) { ?>
      <li id="watch-right-now-<?php echo $video_data->nid ?>" class="watch-right-now-list watch-right-now-<?php echo $video_key ?>"">
        <?php if (!empty($video_data->title)) : ?>
          <p class="title">
            <a title="<?php print $video_data->title; ?>" href="<?php print drupal_get_path_alias("node/$video_data->nid"); ?>">
              <?php echo mb_strimwidth($video_data->title, 0, 140, ".."); ?>
            </a>
          </p>
        <?php endif; ?>

        <?php if (!empty($video_data->field_story_extra_large_image['und'][0]['uri'])) { ?>
          <a href="#" class="pic">
            <img  src="<?php print image_style_url("widget_small", $video_data->field_story_extra_large_image['und'][0]['uri']); ?>" />
          </a>
          <?php
        }
        else {
          ?>
          <a href="#" class="pic">
            <img  src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
          </a>
        <?php } ?>
      </li>
    <?php } ?>
  </ul>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
