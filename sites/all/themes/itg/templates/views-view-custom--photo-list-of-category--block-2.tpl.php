<?php
if (isset($_GET['category'])) {
    $section_cat_id = $_GET['category'];
}
?>
<h3><span><?php print t('Other Galleries'); ?></span></h3>
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
                    ?>
    <?php print l($img, 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id, 'sid' => $_GET['sid']), 'html' => TRUE)); ?>
                    <figcaption><i class="fa fa-camera" aria-hidden="true"></i><?php print $row['delta']; ?></figcaption>
                </figure>
                <span class="posted-on"><?php print $row['created']; ?></span>
    <?php $title = $row['title']; ?>
                <p title="<?php print strip_tags($title); ?>">
        <?php print html_entity_decode(l($title, 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id, 'sid' => $_GET['sid']), 'html' => TRUE))); ?>
                </p>
            </div>
        </li>
<?php endforeach; ?>
</ul>
