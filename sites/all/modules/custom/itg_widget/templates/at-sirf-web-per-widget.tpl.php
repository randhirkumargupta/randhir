<?php global $base_url; ?>
<div class="widget-container sirf-web-par">
  <div class="half-grey-bg">
    <h2><?php print t("Sirf web per"); ?></h2>
    <ul class="widget-list-wrapper slider-container">
      <?php foreach ($data as $key => $output) : ?>
        <li class="widget-list-row latest-video-rows-<?php print $key ?>">
          <div class="tile">
            <div class="cateogry-name cateogry-<?php print $keys; ?>">
              <?php
              if ($output->field_primary_category && isset($output->field_primary_category)) {
                $term_data = taxonomy_term_load($output->field_primary_category);
              }
              print $term_data->field_cm_display_title['und'][0]['value'];
              ?>
            </div>
            <div class="pic">
              <?php if (empty($output->field_story_extra_large_image)) : ?>
                <?php
                $image = array(
                    '#theme' => 'image_style_outside_files',
                    '#style_name' => 'live_tv_latest_video',
                    '#path' => drupal_get_path('theme', 'itg') . "/images/default_for_all.png",
                );
                print l(render($image), "node/$output->nid", array("html" => true));
                ?>
              <?php else : ?>
                <?php
                $title = '<img src="' . image_style_url("sirf_web_per", $output->field_story_extra_large_image['und'][0]['uri']) . '">';
                print l($title, "node/$output->nid", array("html" => true));
                ?>
              <?php endif; ?>
            </div>
            <div class="title">
              <?php print l($output->title, "node/$output->nid", array("html" => true)); ?>
            </div>
            <div class="reported-by">
              <span class="name">
                <?php print $output->field_video_anchor; ?>
              </span>
              <span class="date">
                <?php print date("d-m-Y", $output->created); ?>
              </span>
            </div>
          </div>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
</div>