<?php if (!empty($data)) : global $base_url; ?>
  <div class="top-takes-video-container">
    <?php $is_fron_page = drupal_is_front_page();
    if (empty($is_fron_page)) {
      ?><h3><span><?php print t("Top Takes") ?></span></h3><?php } ?>
    <ul>  
        <?php foreach ($data as $video_key => $video_data) { ?>
        <li id="top-takes-<?php echo $video_data['nid'] ?>" class="top-takes-video top-takes-list top-takes-<?php echo $video_key ?>"">
            <?php if (!empty($video_data['esi_file_uri'])) { ?>
            <a href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $video_data['nid']); ?>" class="pic">         
      <?php $file_uri = file_create_url($video_data['esi_file_uri']); ?>
              <img src="<?php print $file_uri; ?>" />
            </a>
            <?php
          }
          else {
            ?>
            <a href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $video_data['nid']); ?>" class="pic">
              <img height="66" width="88" src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
            </a>
          <?php } ?>
            <?php if (!empty($video_data['title'])) : ?>
            <p class="title top-takes-<?php echo $video_data['nid'] ?>">
            <?php echo l(mb_strimwidth($video_data['title'], 0, 140, ".."), $base_url . '/' . drupal_get_path_alias("node/". $video_data['nid'])); ?>
            </p>
        <?php endif; ?>
        </li>
  <?php } ?>
    </ul>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>