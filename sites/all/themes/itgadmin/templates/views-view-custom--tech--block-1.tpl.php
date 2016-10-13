<div class="row">
<div class="col-md-8">
    <div class="auto-block-1">
<div class="featured-news">

    <?php
    foreach ($rows as $index => $row) {
        $desc = $row['title'];
        
        $video_class = "";
        if (strtolower($row['type']) == 'videogallery') {
            $video_class = 'video-icon';
        }
        if ($index == 0) {
            ?>
            <div class="featured-post featured-post-first <?php echo $video_class; ?>">
            <?php print $row['field_story_extra_large_image_1']; ?>    
                <h2><?php echo l(mb_strimwidth(strip_tags($desc), 0, 70, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></h2>           
            </div>



    <?php } else if ($index > 0 && $index <= 2) { ?>
            <div class="featured-post <?php echo $video_class; ?>"><?php print $row['field_story_extra_large_image']; ?>
                <h3><?php echo l(mb_strimwidth(strip_tags($desc), 0, 70, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></h3>
            </div>

    <?php } ?>

    <?php } ?>
</div>
        </div>    
    </div>
    <div class="col-md-4">
        <div class="auto-block-2">
    <div class="special-top-news">

        <ul class="itg-listing">   
<?php

foreach ($rows as $index => $row) {
    
    $desc = $row['title'];
   
    if ($index > 2) {
    
        ?>
    <li><?php echo l(mb_strimwidth(strip_tags($desc), 0, 85, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></li>


     <?php } ?>

            <?php } ?>

        </ul>

    </div>
        </div>
</div>
    </div>