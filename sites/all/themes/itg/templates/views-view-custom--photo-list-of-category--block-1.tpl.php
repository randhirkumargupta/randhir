<ul class="photo-list">
  <?php foreach ($rows as $index => $row): ?>
    <li class="col-md-3">
     <figure>
        <?php
        $img = $row['field_story_extra_large_image'];
        $section_cat_id = $row['field_story_category'];
        ?>
  <?php print l($img, 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id, 'sid' => $_GET['sid']), 'html' => TRUE)); ?>
        <figcaption><i class="fa fa-camera" aria-hidden="true"></i><?php print $row['delta']; ?></figcaption>>
        </figure>
        <span class="posted-on"><?php print $row['created']; ?></span>
        <?php $title = $row['title']; ?>
    <?php print l($title, 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id, 'sid' => $_GET['sid']), 'html' => TRUE)); ?>
    </li>
<?php endforeach; ?>
</ul>