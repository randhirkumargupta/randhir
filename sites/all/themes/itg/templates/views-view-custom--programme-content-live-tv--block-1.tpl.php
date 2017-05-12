<div class="programe-list defalt-bar">
    <ul class="photo-list">
  <?php
  $url = "#";
  global $base_url;
  foreach ($rows as $key => $row) :
    $section_cat_id = trim($row['field_story_category']);
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
            $img = "<img width='170' height='127'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/itg_image170x127.jpg' alt='' />";
            ?>
            <?php print l($img, 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id), 'html' => TRUE)); ?>

          <?php endif; ?>

          <?php if (isset($row['field_video_duration'])) : ?>
            <figcaption>
              <i class="fa fa-play-circle"></i> <?php print $row['field_video_duration']; ?>
            </figcaption>
          <?php endif; ?>
        </figure>

        <?php if (isset($row['title'])) : ?>
        <p  title="<?php print strip_tags($row['title']) ; ?>">
            <?php print l($row['title'], 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id))); ?>
        </p>
        <?php endif; ?>
      </span>
    </li>

  <?php endforeach; ?>
    </ul>
</div>
