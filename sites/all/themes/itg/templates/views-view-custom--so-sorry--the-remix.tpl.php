<?php
global $base_url;
$remix_data = $rows[0];
?>
<?php print t("<h2>THE <span>REMIX</span></h2>"); ?>
<div class="large-image">
    <?php
    if (!empty($remix_data['field_story_extra_large_image'])) {
      $video_image = $remix_data['field_story_extra_large_image'];
    }
    else {
      $video_image = "<img width='170' height='127'  src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg') . "' alt='' title='' />";
    }
    print l($video_image, 'node/' . $remix_data['nid'], array('attributes' => array('class' => array('pic')), 'html' => TRUE));
    ?>
</div>
<div class="title"  title="<?php print strip_tags($remix_data['title']); ?>">
    <?php print l(mb_strimwidth($remix_data['title'], 0, 45, ".."), "node/" . $remix_data['nid'] . "", array('html' => TRUE)); ?>
</div>