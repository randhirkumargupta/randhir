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
                        $img = "<img width='170' height='127'  src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg') ."' alt='' title='' />";
                    }
                    //$section_cat_id = $row['field_story_category'];
                    ?>
                    <?php print l($img, 'node/' . $row['nid'], array('html' => TRUE)); ?>
                    <figcaption><i class="fa fa-camera" aria-hidden="true"></i><?php print $row['delta']; ?></figcaption>
                </figure>
                <span class="posted-on"><?php print $row['created']; ?></span>
                <?php $title = $row['title']; ?>
                <p title="<?php print html_entity_decode(strip_tags($title)); ?>">
                <?php print html_entity_decode(l($title, 'node/' . $row['nid'], array('html' => TRUE))); ?>
                </p>
            </div>
        </li>
    <?php endforeach; ?>
</ul>