<div class="special-top-news">
    <?php if (!empty($rows)) : global $base_url; ?> 
        <ul class="itg-listing">
            <?php foreach ($rows as $index => $row) { ?>
                <?php
                $desc = $row['title'];
                if ($row['field_story_kicker_text'] != "") {
                    $desc = $row['field_story_kicker_text'];
                } else if ($row['field_story_kicker_text'] == "" && $row['body'] != "") {
                    $desc = $row['body'];
                }
                ?>
                <li><?php echo l(mb_strimwidth(strip_tags($desc), 0, 150, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></li>


            <?php }; ?>
        </ul>
    <?php else : ?>
        <span class="no-result-found"><?php print t("Content Not Found") ?></span>
    <?php endif; ?>

</div>