<div class="defalt-bar">
  <ul class="photo-list">
    <?php foreach ($rows as $index => $row): ?>
      <li class="">
        <div class="tile">
          <figure>
            <?php
            if (!empty($row['field_story_extra_large_image'])) {
              $img = $row['field_story_extra_large_image'];
            }
            else {
              global $base_url;
              $img = "<img width='170' height='127'  src='" .  image_style_url("widget_small", drupal_get_path('theme', 'itg') . '/images/itg_image170x127.jpg') ."' alt='' title='' />";
            }
            ?>
            <?php print l($img, 'node/' . $row['nid'], array('query' => array('category' => $_GET['category'], 'sid' => $_GET['sid']), 'html' => TRUE)); ?>
            <figcaption><i class="fa fa-play-circle"></i> <?php print $row['field_video_duration']; ?></figcaption>
          </figure>
          <?php $title = $row['title']; ?>
          <p title="<?php print strip_tags($row['title']); ?>">
          <?php print l(html_entity_decode(strip_tags($title)), 'node/' . $row['nid'], array('query' => array('category' => $_GET['category'], 'sid' => $_GET['sid']), 'html' => TRUE)); ?>
          </p>
        </div>
      </li>    
    <?php endforeach; ?>
  </ul>
</div>