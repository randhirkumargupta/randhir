<div class="defalt-bar">
<ul class="photo-list">
  <?php foreach ($rows as $index => $row): ?>
    <li class="">
        <div class="tile">
     <figure>
        <?php
        $img = $row['field_story_extra_large_image'];
        ?>
  <?php print l($img, 'node/' . $row['nid'], array('query' => array('category' => $_GET['category'], 'sid' => $_GET['sid']), 'html' => TRUE)); ?>
        <figcaption><i class="fa fa-play-circle"></i> <?php print $row['field_video_duration']; ?></figcaption>
        </figure>
        <?php $title = $row['title']; ?>
    <?php print l($title, 'node/' . $row['nid'], array('query' => array('category' => $_GET['category'], 'sid' => $_GET['sid']), 'html' => TRUE)); ?>
        </div>
    </li>    
<?php endforeach; ?>
</ul>
    </div>