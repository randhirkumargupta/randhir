<div class="auto-road-trip">
    <ul class="trending-videos">
        <?php
        foreach ($rows as $index => $row) {
            $video_class = "";
            if (strtolower($row['type']) == 'videogallery') {
                $video_class = 'content-video';
            }
            $desc = $row['title'];
            if ($row['field_story_kicker_text'] != "") {
                $desc = $row['field_story_kicker_text'];
            } else if ($row['field_story_kicker_text'] == "" && $row['body'] != "") {
                $desc = $row['body'];
            } else if ($row['field_story_expert_description'] != "") {
                $desc = $row['field_story_expert_description'];
            }
            ?>
        <li class="trending-videos-list">
                <span class="pic video-none <?php echo $video_class; ?>"><?php print $row['field_story_extra_large_image']; ?></span>
                <spna><?php echo l(mb_strimwidth(strip_tags($desc), 0, 150, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></span>
            </li>
        <?php }; ?>
    </ul>
</div>

