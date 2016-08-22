<ul class="photo-list">
  <?php foreach ($rows as $index => $row): ?>
    <?php
    $img = $row['field_story_extra_large_image'];
    $section_cat_id = $row['field_story_category'];
    ?>
    <li class="col-md-3">
        <div class="tile">
      <figure>
  <?php print l($img, 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id, 'sid' => $_GET['sid']), 'html' => TRUE)); ?>
        <figcaption><i class="fa fa-camera" ></i> <?php print $row['field_video_duration']; ?></figcaption>

      </figure>

      <span class="posted-on"><?php print $row['created']; ?></span>
    <?php print l($row['title'], 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id, 'sid' => $_GET['sid']), 'html' => TRUE)); ?>
      </div>
    </li>
<?php endforeach; ?>
</ul>


