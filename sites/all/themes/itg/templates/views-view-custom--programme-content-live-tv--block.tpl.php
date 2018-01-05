<div class="programe-list">
    <ul class="photo-list">
  <?php
  $url = "#";
  global $base_url;
  foreach ($rows as $key => $row) :
    ?>
    <li class="col-md-3">          
      <span class="tile">
        <figure>
          <?php if (isset($row['field_story_extra_large_image'])) : ?>
            <?php
            $img = $row['field_story_extra_large_image'];
            ?>
            <?php print l($img, 'node/' . $row['nid'], array('html' => TRUE)); ?>
          <?php else : ?>
            <?php
            $img = "<img width='170' height='127'  src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg') ."' alt='' title='' />";
            ?>
            <?php print l($img, 'node/' . $row['nid'], array('html' => TRUE)); ?>

          <?php endif; ?>

          <?php if (isset($row['field_video_duration'])) : ?>
            <figcaption>
              <i class="fa fa-play-circle"></i> <?php print $row['field_video_duration']; ?>
            </figcaption>
          <?php endif; ?>
        </figure>
        <?php if (isset($row['created'])) : ?>
          <span class="posted-on">
            <?php print $row['created']; ?>
          </span>
        <?php endif; ?>

        <?php if (isset($row['title'])) : ?>
          
            <?php print l(html_entity_decode($row['title']), 'node/' . $row['nid'], array('html' => TRUE)); ?>
          
        <?php endif; ?>
      </span>
    </li>

  <?php endforeach; ?>
    </ul>
</div>
