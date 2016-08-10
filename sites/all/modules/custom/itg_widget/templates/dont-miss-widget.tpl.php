<?php if (!empty($data)) : ?>
  <div class="dont-miss">
    <ul>
      <?php foreach ($data as $key => $node_data) { ?>
        <li class="dont-miss-listing" id="dont-miss-<?php print $key ?>">
          <?php if (!empty($node_data['node_load_data']->field_story_extra_large_image['und'][0]['uri'])) { ?>
            <div class="dm-pic">
              <img src="<?php print image_style_url("widget_small", $node_data['node_load_data']->field_story_extra_large_image['und'][0]['uri']); ?>" />
            </div>
          <?php }
          else {
            ?>
            <div class="dm-pic">
              <img src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
            </div>
    <?php } ?>

          <div class="dm-detail">

            <?php if (!empty($node_data['custom_label'])) : ?>
              <h4><?php print $node_data['custom_label']; ?></h4>
            <?php endif; ?>

    <?php if (!empty($node_data['node_load_data']->title)) : ?>    
              <p class="dont-miss-widget dont-miss-<?php echo $node_data['node_load_data']->nid ?>">
                <a href="<?php print drupal_get_path_alias("node/{$node_data['node_load_data']->nid}"); ?>" title="<?php echo $node_data['node_load_data']->title; ?>">
      <?php print mb_strimwidth($node_data['node_load_data']->title, 0, 150, "..") ?>
                </a>
              </p>
    <?php endif; ?>

          </div>
        </li>
  <?php } ?>
    </ul>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
