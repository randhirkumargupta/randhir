<div class="featured-news">

    <?php
    foreach ($rows as $index => $row) {
        $desc = $row['title'];
        if ($row['field_story_kicker_text'] != "") {
            $desc = $row['field_story_kicker_text'];
        } else if ($row['field_story_kicker_text'] == "" && $row['body'] != "") {
            $desc = $row['body'];
        } else if ($row['field_story_expert_description'] != "") {
            $desc = $row['field_story_expert_description'];
        }
        $video_class = "";
        if (strtolower($row['type']) == 'videogallery') {
            $video_class = 'content-video';
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
    <div class="special-top-news">
<div class="itg-listing-wrapper">
        <ul class="itg-listing" style="padding-top: 0px;">   
<?php

foreach ($rows as $index => $row) {
    
    $desc = $row['title'];
    if ($row['field_story_kicker_text'] != "") {
        $desc = $row['field_story_kicker_text'];
    } else if ($row['field_story_kicker_text'] == "" && $row['body'] != "") {
        $desc = $row['body'];
    } else if ($row['field_story_expert_description'] != "") {
        $desc = $row['field_story_expert_description'];
    }


    if ($index > 2) {
    
        ?>
    <li><?php echo l(mb_strimwidth(strip_tags($desc), 0, 140, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></li>


     <?php } ?>

            <?php } ?>

        </ul>
</div>
    </div>
</div>