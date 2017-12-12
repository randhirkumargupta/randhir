<h2><?php print t('Most'); ?> <span><?php print t('Watched'); ?></span></h2>
<ul class="photo-list">
    <?php foreach ($rows as $key => $value) : ?>
      <li class="col-md-3">
          <div class="tile">
              <figure>
                  <?php
                  if (!empty($value['field_story_extra_large_image'])) {
                    $video_image = $value['field_story_extra_large_image'];
                  }
                  else {
                    $video_image = "<img width='170' height='127'  src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg') . "' alt='' title='' />";
                  }
                  print l($video_image, 'node/' . $value['nid'], array('attributes' => array('class' => array('pic')), 'html' => TRUE));
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