<?php if (!empty($data)) : ?>
  <div class="may-be-suggest-container">
    <h3><span><?php print t("May We Suggest") ?></span></h3>
    <ul>
      <?php foreach ($data as $key => $entity_info) { ?>
        <li class="may-we-suggest" id="may-be-suggest-<?php print $key ?>">
          <?php if (!empty($entity_info->field_story_extra_large_image['und'][0]['uri'])) { ?>
            <a href="#" class="pic">
              <img  src="<?php print image_style_url("widget_very_small", $entity_info->field_story_extra_large_image['und'][0]['uri']); ?>" />
            </a>
            <?php
          }
          else {
            ?>
            <a href="#" class="pic">
              <img  src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
            </a>
          <?php } ?>
          <?php if (!empty($entity_info->title)) : ?>
            <p class="title may-be-suggest-<?php echo $entity_info->nid ?>">
              <a title="<?php echo $entity_info->title; ?>" href="<?php print drupal_get_path_alias("node/$entity_info->nid"); ?>">
                <?php echo mb_strimwidth($entity_info->title, 0, 90, ".."); ?>
              </a>  
            </p>
          <?php endif; ?>

        </li>        
      <?php } ?>
    </ul>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>

