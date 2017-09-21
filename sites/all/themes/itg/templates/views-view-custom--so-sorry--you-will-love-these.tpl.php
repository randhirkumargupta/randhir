<?php
global $base_url;
$skip_nid = FALSE;
$count_feature = count_sosorry_feature();
$nid = get_recent_created_node_for_sosorry();
$arg = arg();
?>
<ul class="photo-list">
    <?php foreach ($rows as $key => $value) : ?>
      <?php if($value['nid'] == $nid && $count_feature == 0 && empty($arg[1])) {
          // Do not print this node because we dont want to display dublicate videos on page.
          continue;
      } ?>
        <li class="col-md-3">
            <div class="tile">
                <figure>
                    <div class="large-image">
                        <?php if (!empty($value['field_story_extra_large_image'])) : ?>
                            <a href="<?php print $base_url . '/' . "sosorry/" . $value['nid'] . "" ?>" class="pic">
                                <?php print $value['field_story_extra_large_image'] ?>
                            </a>
                        <?php else : ?>
                            <a href="<?php print $base_url . '/' . "sosorry/ " . $value['nid'] . "" ?>" class="pic">
                                
                                <img width='170' height='127'  src='<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/itg_image170x127.jpg' alt='' />
                            </a>
                        <?php endif; ?>
                        <figcaption><i class="fa fa-play-circle"></i> <?php print $value['field_video_duration']; ?></figcaption>
                </figure>
                <span class="posted-on"><?php print date ('D, d M, Y',  strtotime($value['created'])) ?></span>
                <p  title="<?php print strip_tags($value['title']) ; ?>">
                  <?php print l($value['title'], "sosorry/" . $value['nid'] . "" ,array('html' => TRUE)) ?>
                </p>
                </div>
        </li>
    <?php endforeach; ?>
</ul>

