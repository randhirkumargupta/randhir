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
                    $section_cat_id = $row['field_story_category'];
                    ?>
                    <?php print l($img, 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id, 'sid' => $_GET['sid']), 'html' => TRUE)); ?>
                    <figcaption><i class="fa fa-camera" aria-hidden="true"></i><?php print $row['delta']; ?></figcaption>
                </figure>
                <span class="posted-on"><?php print $row['created']; ?></span>
                <?php $title = $row['title']; ?>
                <?php print l($title, 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id, 'sid' => $_GET['sid']), 'html' => TRUE)); ?>
            </div>
        </li>
    <?php endforeach; ?>
</ul>