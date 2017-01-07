<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

// Logic for default feature video on sosorry page if feature is not selected in widget.
$node_data = array();
$nid = get_recent_created_node_for_sosorry();
//$node_data = node_load($nid);
$videoids = "";
if (function_exists('get_video_in_fieldcollection_by_nid')) {
    $videoids = get_video_in_fieldcollection_by_nid($nid);
}
$video_fid = itg_videogallery_get_videoid($node_data->field_upload_video['und'][0]['fid']);
?>
<?php foreach ($rows as $id => $row): ?>
  <?php
  if (isset($row['fid']) && !empty($row['fid'])) {
    $video_fid = $row['fid'];
  }
  ?>
  <?php
  if (isset($row['title']) && !empty($row['title'])) {
    $video_title = $row['title'];
  }
  else {
    $video_title = $node_data->title;
  }
  ?>
<?php endforeach; ?>

<?php
$arg = arg();
$autoplay = 0;
if (isset($arg[1])) {
  $autoplay = 1;
}
?>
 <?php
    if (!empty($videoids)) {
        $hide_player = "";
        $description_slider="";
        $newimageds = '<div class="row"><div class="col-md-12"><div class="video-slider-images"><ul>';
        foreach ($videoids as $keys => $video_value) {
            if ($keys != 0) {
                $hide_player = 'hide-player';
            }
            ?> <div class="<?php echo $hide_player; ?>" id="video_<?php echo $video_value->video_id; ?>"><?php
                                if ($video_value->dailymotion_thumb_url != "") {
                                    $newimageds.= '<li><img data-tag="video_' . $video_value->video_id . '" src="' . $video_value->dailymotion_thumb_url . '" height="66" width="88"></li>';
                                }
                                else {
                                    $newimageds.= '<li><img data-tag="video_' . $video_value->video_id . '" src="' . $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/default_for_all.png" height="66" width="88"></li>';
                                }
                                $ads_flag = 0;
                                if ($video_value->field_include_ads_value == 'yes') {
                                    $ads_flag = 1;
                                }
                                ?>
                                    <div class="iframe-video">
                                        <iframe frameborder="0"
                                                src="https://www.dailymotion.com/embed/video/<?php print $video_value->video_id; ?>?autoplay=<?php print $autoplay; ?>&mute=1&endscreen-enable=<?php echo $ads_flag; ?>&ui-start-screen-info"
                                                allowfullscreen></iframe>
                                    </div>
                                    <?php print ucfirst($video_value->field_videogallery_description_value) ?>
                                </div>

            <?php
        }
        $newimageds.='</ul></div></div></div>';
        if (count($videoids) > 1) {
        print $newimageds;
        }
    }
    ?>