<div class="programe-video-view-container">
  <?php
  $url = "#";
  foreach ($rows as $key => $row) :
    $section_cat_id = $row['field_story_category'];
    if ($key == 0) {
      $url = l("more>>", 'node/' . $row['nid'], array('attributes' => array('class' => 'more-link')), array('query' => array('category' => $section_cat_id), 'html' => TRUE));
    }
    if ($key > 3) {
      continue;
    }
    ?>
    <div class="video-container">
      <?php if (isset($row['field_story_extra_large_image'])) : ?>
        <?php
        $img = $row['field_story_extra_large_image'];
        ?>
        <div class="large-image">
          <?php print l($img, 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id), 'html' => TRUE)); ?>
        </div>
      <?php endif; ?>

      <?php if (isset($row['field_video_duration'])) : ?>
        <div class="duration">
          <?php print $row['field_video_duration']; ?>
        </div>
      <?php endif; ?>

      <?php if (isset($row['created'])) : ?>
        <div class="date">
          <?php print $row['created']; ?>
        </div>
      <?php endif; ?>

      <?php if (isset($row['title'])) : ?>
        <div class="description">
          <?php print $row['title']; //l($row['title'], 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id))); ?>
        </div>
      <?php endif; ?>
    </div>
    <?php
    if ($key == 3 && count($rows) > 3) {
      print $url;
    }
    ?>
  <?php endforeach; ?>
</div>
