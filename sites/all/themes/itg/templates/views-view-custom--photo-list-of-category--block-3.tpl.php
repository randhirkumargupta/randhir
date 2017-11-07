
<?php
$category = itg_videogallery_get_term(arg(1));
if (!in_array(variable_get('ipl_for_widget'), $category)) {
    print '<h3><span>' . t('Other Galleries') . '</span></h3>';
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
                        $img = "<img width='170' height='127'  src='" .  image_style_url("widget_small", drupal_get_path('theme', 'itg') . '/images/itg_image170x127.jpg') ."' alt='' title='' />";
                    }
                    ?>
    <?php print l($img, 'node/' . $row['nid_1'], array('html' => TRUE)); ?>
                    <figcaption><i class="fa fa-camera" aria-hidden="true"></i><?php print $row['delta']; ?></figcaption>
                </figure>
                <span class="posted-on"><?php print $row['created']; ?></span>
    <?php $title = $row['title']; ?>
                <p title="<?php print strip_tags($title); ?>">
        <?php print html_entity_decode(l($title, 'node/' . $row['nid_1'], array('html' => TRUE))); ?>
                </p>
            </div>
        </li>
<?php endforeach; ?>
</ul>
