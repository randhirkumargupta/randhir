<?php
if (isset($_GET['category'])) {
    $section_cat_id = $_GET['category'];
}
else {
    $section_cat_id = get_first_category_of_media_widget(arg(2), 'page--section_photo', 'photo_list_of_category');
}
?>
<ul class="photo-list">
<?php foreach ($rows as $index => $row): ?>
        <li class="col-md-3">
            <div class="tile">
                <figure>
                    <?php
                    if (!empty($row['field_story_small_image'])) {
                        $img = $row['field_story_small_image'];
                    }
                    else {
                        global $base_url;
                        $img = "<img width='170' height='127'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/itg_image170x127.jpg' alt='' />";
                    }
                    ?>
                <?php print l($img, 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id, 'sid' => arg(2)), 'html' => TRUE)); ?>
                    <figcaption><i class="fa fa-camera" aria-hidden="true"></i><?php print $row['delta']; ?></figcaption>
                </figure>
                <span class="posted-on"><?php print $row['created']; ?></span>
        <?php $title = strip_tags($row['title']); ?>
                <p title="<?php print strip_tags($title); ?>">
        <?php print html_entity_decode(l($title, 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id, 'sid' => arg(2)), 'html' => TRUE))); ?>
                </p>
            </div>
        </li>
<?php endforeach; ?>
</ul>
