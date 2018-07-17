<?php
global $base_url;
$you_will_love_these = array_slice($rows, 4);
?>
<div class="you-will-love-these">
    <?php if(!isset($_GET['page'])):?>
    <h2><?php echo t("YOU'LL") ?> <span><?php echo t("LOVE THESE") ?></span></h2>
    <?php endif;?>
    <ul class="photo-list">
        <?php foreach ($you_will_love_these as $key => $value) : ?>
          <li class="col-md-3">
              <div class="tile">
                  <figure>
                      <div class="large-image">
                          <?php
                          if (!empty($value['field_story_extra_large_image'])) {
                            $video_images = $value['field_story_extra_large_image'];
                          }
                          else {
                            $video_images = "<img width='170' height='127'  src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg') . "' alt='' title='' />";
                          }
                          print l($video_images, 'node/' . $value['nid'], array('attributes' => array('class' => array('pic')), 'html' => TRUE));
                          ?>
                          <figcaption><i class="fa fa-play-circle"></i> <?php print $value['field_video_duration']; ?></figcaption>
                  </figure>
                  <span class="posted-on"><?php print date('D, d M, Y', strtotime($value['created'])) ?></span>
                  <p  title="<?php print strip_tags($value['title']); ?>">
                      <?php print l($value['title'], "node/" . $value['nid'] . "", array('html' => TRUE)) ?>
                  </p>
              </div>
          </li>
        <?php endforeach; ?>
    </ul>
</div>
</ul>

