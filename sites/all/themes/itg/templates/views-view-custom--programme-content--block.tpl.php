<div class="programe-list">
    <ul class="photo-list">
  <?php
  $url = "#";
  $more_link = "";
  global $base_url;
  foreach ($rows as $key => $row) :
    if (isset($row['cat_id'])) {
      if ($key == 0) {
        $url = l("More »", 'taxonomy/term/' . $row['cat_id'], array('html' => TRUE));
      }
      if ($key > 3) {
        continue;
      }
    }
    ?>
    <li class="col-md-3 content-id-<?php print $row['nid'] ?>">          
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
        <p  title="<?php print strip_tags($row['title']) ; ?>">
            <?php print html_entity_decode(l(strip_tags($row['title']), 'node/' . $row['nid'])); ?>
        </p>
        <?php endif; ?>
      </span>
    </li>
    <?php
    if ($key == 3 && count($rows) > 3) {
      $more_link = '<div class="row"><div class="col-md-12"><div class="more">' . $url . '</div></div></div>';
    }
    ?>
  <?php endforeach; ?>
    </ul>
   <?php print $more_link ?> 
</div>
