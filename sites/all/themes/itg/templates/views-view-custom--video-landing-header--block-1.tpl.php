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
    <li class="">
        <div class="tile">
     <figure>
          <a href="/itgcms/content/ftp-video?category=445&amp;sid=445"></a>        <figcaption><i class="fa fa-play-circle"></i> 00:05</figcaption>
        </figure>
            <a href="/itgcms/content/ftp-video?category=445&amp;sid=445">five-pakistani-balloons-found-in-fatehpur-pathankot</a>        </div>
    </li>
    <li class="">
        <div class="tile">
     <figure>
          <a href="/itgcms/content/ftp-video?category=445&amp;sid=445"></a>        <figcaption><i class="fa fa-play-circle"></i> 00:05</figcaption>
        </figure>
            <a href="/itgcms/content/ftp-video?category=445&amp;sid=445">five-pakistani-balloons-found-in-fatehpur-pathankot</a>        </div>
    </li>
<?php endforeach; ?>
</ul>
    </div>