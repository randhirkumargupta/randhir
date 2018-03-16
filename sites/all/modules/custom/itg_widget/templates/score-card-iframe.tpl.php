<?php global $base_url;
$node_title = '';
if(!empty($data->score_story)){
  $node_title = itg_common_get_node_title($data->score_story);
}
?>
<div id="itg-scorecard-container">
    <div class="container">
        <div class="clearfix">
            <div class="col-lg-8 col-sm-12 col-xs-12">
                <?php print $data->score_description; ?>
            </div>
            <div class="col-lg-4 col-sm-12 mhide scorecard-stripcontent">
                <ul>
                  <?php if (!empty($data->score_story)) : ?>
                    <li><a href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $data->score_story); ?>" title=""><?php print $node_title; ?></a></li>
                  <?php endif; ?>
                  <?php if (!empty($data->score_photo)) : ?>
                    <li><a href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $data->score_photo); ?>" title=""><i class="fa fa-camera"></i> Photo</a></li>
                  <?php endif; ?>
                  <?php if (!empty($data->score_video)) : ?>
                    <li><a href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $data->score_video); ?>" title=""><i class="fa fa-play-circle"></i> Video</a></li>
                  <?php endif; ?>
                </ul>
            </div>
        </div>
    </div>
</div>
