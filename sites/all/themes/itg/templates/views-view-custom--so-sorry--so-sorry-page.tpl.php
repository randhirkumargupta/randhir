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
$node_data = node_load($nid);
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

<div class="sosory-video iframe-video">
  <iframe frameborder="0"             
          src="https://www.dailymotion.com/embed/video/<?php print $video_fid; ?>?autoplay=<?php print $autoplay; ?>&mute=1&ui-start-screen-info"
          allowfullscreen>
  </iframe>
</div>
<h1> <?php print $video_title; ?> </h1>