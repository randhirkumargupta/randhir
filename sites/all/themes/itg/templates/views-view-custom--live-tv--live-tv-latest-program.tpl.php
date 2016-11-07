<div class="live-tv-latest-video-container container">
  <h2><?php print t("Latest program"); ?></h2>
  <?php foreach ($rows as $key => $output) : ?>
    <div class="latest-video-rows latest-video-rows-<?php print $key ?>">
      <div class="cateogry cateogry-<?php print $keys; ?>">
        <?php
        if ($output['field_primary_category'] && isset($output['field_primary_category'])) {
          $term_data = taxonomy_term_load($output['field_primary_category']);
        }
        print $term_data->field_cm_display_title['und'][0]['value'];
        ?>
      </div>
      <div class="extra-large-image">
        <?php print $output['field_story_extra_large_image'] ?>
      </div>
      <div class="title">
        <?php print $output['title'] ?>
      </div>
      <div class="video-anchor">
        <?php print $output['field_video_anchor'] ?>
      </div>
      <div class="changed">
        <?php print $output['changed'] ?>
        <?php print t("IST"); ?>
      </div>
    </div>
  <?php endforeach; ?>
</div>