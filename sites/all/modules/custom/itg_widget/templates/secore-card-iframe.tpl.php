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

<style>

#itg-scorecard-container{background: #000;padding: 10px 0;}

#itg-scorecard-container .scorecard-stripcontent ul li{list-style: none; display: inline-block; border-right: 1px solid #4f4f4f; padding: 0 5px;}

#itg-scorecard-container .scorecard-stripcontent ul li:nth-child(3){border-right:0px}

#itg-scorecard-container .scorecard-stripcontent{ padding:0px;position: relative; height: 20px;}

#itg-scorecard-container .scorecard-stripcontent ul{position: absolute;top: 50%;transform: translateY(-50%);-webkit-transform: translateY(-50%);}

#itg-scorecard-container .scorecard-stripcontent ul li a{color: #fff; font-family: "Roboto-Regular";font-weight:normal; font-size: 14px; }

#itg-scorecard-container .scorecard-stripcontent ul li:nth-child(1) a{white-space: nowrap;overflow: hidden;text-overflow: ellipsis;width: 438px;display: inline-block;line-height: 14px;}

</style>
