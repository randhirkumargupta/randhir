<div class="auto-tips-n-tricks">
    <ul>
        <?php
        foreach ($rows as $index => $row) {

            $desc = "";
            if ($row['field_story_kicker_text'] != "") {
                $desc = $row['field_story_kicker_text'];
            } else if ($row['field_story_kicker_text'] == "" && $row['body'] != "") {
                $desc = $row['body'];
            }
            ?><li>
                <p class="title"><?php echo $row['title']; ?></p>

                <p>The whole country is rejoicing the arrival of the monsoons thanks to the fact that it gives respite from the scorching heat. But it also brings a lot of other issues. Here is how you should be ready.<?php echo mb_strimwidth(strip_tags($desc), 0, 150, ".."); ?></p>
            </li>


        <?php }; ?>
    </ul>
</div>

