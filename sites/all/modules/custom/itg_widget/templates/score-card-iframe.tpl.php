<?php global $base_url;?>
<div id="itg-scorecard-container">
    <div class="container">
        <div class="clearfix">
            <div class="col-lg-6 col-ms-6 col-xs-12">
                <?php print $data->score_description; ?>
            </div>
            <div class="col-lg-6 col-ms-6 mhide scorecard-stripcontent">
                <ul>
                    <li><a href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $data->score_story); ?>" title="">Live Cricket Score, 3rd Test Day 2: India aim to bounce back after dismal batting display</a></li>
                    <li><a href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $data->score_photo); ?>" title=""><i class="fa fa-camera"></i> Photo</a></li>
                    <li><a href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $data->score_video); ?>" title=""><i class="fa fa-play-circle"></i> Video</a></li>
                </ul>
            </div>
        </div>
    </div>
</div>
