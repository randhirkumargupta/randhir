<?php
global $base_url;
$most_popular = array_slice($rows, 0, 4);
$you_will_love_these = array_slice($rows, 4);
?>
<div class="most-popular">
      <h2><?php echo t('Most') ?> <span><?php echo t('Watched') ?></span></h2>
      <ul class="photo-list">
      <?php foreach ($most_popular as $key => $value) : ?>
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

                                <img width='170' height='127'  src='<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg'); ?>' alt='' title='' />
                            </a>
                          <?php endif; ?>
                          <figcaption><i class="fa fa-play-circle"></i> <?php print $value['field_video_duration']; ?></figcaption>
                  </figure>
                  <span class="posted-on"><?php print date('D, d M, Y', strtotime($value['created'])) ?></span>
                  <p  title="<?php print strip_tags($value['title']); ?>">
                      <?php print l($value['title'], "sosorry/" . $value['nid'] . "", array('html' => TRUE)) ?>
                  </p>
              </div>
          </li>
      <?php endforeach; ?>
        </ul>
  </div>
  <div class="you-will-love-these">
      <h2><?php echo t("YOU'LL") ?> <span><?php echo t("LOVE THESE") ?></span></h2>
      <ul class="photo-list">
        <?php foreach ($you_will_love_these as $key => $value) : ?>
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

                                <img width='170' height='127'  src='<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg'); ?>' alt='' title='' />
                            </a>
                          <?php endif; ?>
                          <figcaption><i class="fa fa-play-circle"></i> <?php print $value['field_video_duration']; ?></figcaption>
                  </figure>
                  <span class="posted-on"><?php print date('D, d M, Y', strtotime($value['created'])) ?></span>
                  <p  title="<?php print strip_tags($value['title']); ?>">
                      <?php print l($value['title'], "sosorry/" . $value['nid'] . "", array('html' => TRUE)) ?>
                  </p>
              </div>
          </li>
        <?php endforeach; ?>
      </ul>
  </div>
</ul>

