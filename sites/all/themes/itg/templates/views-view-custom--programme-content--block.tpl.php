<div class="programe-list">
    <ul class="photo-list">
  <?php
  $url = "#";
  global $base_url;
  foreach ($rows as $key => $row) :
    $section_cat_id = trim($row['field_story_category']);
    if ($key == 0) {
      $url = l("More »", 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id), 'html' => TRUE));
    }
    if ($key > 3) {
      continue;
    }
    ?>
    <li class="col-md-3">          
      <span class="tile">
        <figure>
          <?php if (isset($row['field_story_extra_large_image'])) : ?>
            <?php
            $img = $row['field_story_extra_large_image'];
            ?>
            <?php print l($img, 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id), 'html' => TRUE)); ?>
          <?php else : ?>
            <?php
            $img = "<img width='170' height='127'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/default_video.jpg' />";
            ?>
            <?php print l($img, 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id), 'html' => TRUE)); ?>

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
          
            <?php print l($row['title'], 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id))); ?>
          
        <?php endif; ?>
      </span>
    </li>
    <?php
    if ($key == 3 && count($rows) > 3) {
      print '<div class="col-md-12"><div class="more">' . $url . '</div></div>';
    }
    ?>
  <?php endforeach; ?>
    </ul>
</div>
