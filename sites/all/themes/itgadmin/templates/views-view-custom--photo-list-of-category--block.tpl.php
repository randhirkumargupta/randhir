<?php
if (isset($_GET['category'])) {
  $section_cat_id = $_GET['category'];
} else {
  $section_cat_id = get_first_category_of_media_widget(arg(2), 'page--section_photo', 'photo_list_of_category');
}
?>
<ul class="photo-list">
  <?php foreach ($rows as $index => $row): ?>
    <li class="col-md-3">
      <div class="tile">
        <figure>
          <?php $img = $row['field_story_extra_large_image']; ?>
          <?php print l($img, 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id, 'sid' => arg(2)), 'html' => TRUE)); ?>
          <figcaption><i class="fa fa-camera" aria-hidden="true"></i><?php print $row['delta']; ?></figcaption>
        </figure>
        <span class="posted-on"><?php print $row['created']; ?></span>
        <?php $title = $row['title']; ?>
        <?php print html_entity_decode(l(t($title), 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id, 'sid' => arg(2)), 'html' => TRUE))); ?>
      </div>
    </li>
  <?php endforeach; ?>
</ul>
