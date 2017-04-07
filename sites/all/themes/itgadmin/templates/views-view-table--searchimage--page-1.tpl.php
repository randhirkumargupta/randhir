<?php
global $base_url;
/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */
?>

<script src="<?php echo $base_url; ?>/sites/all/themes/itgadmin/js/jquery-pagination-min.js"></script>
<script src="<?php echo $base_url; ?>/sites/all/themes/itgadmin/js/bootstrap.min.js"></script>
<script src="<?php echo $base_url; ?>/sites/all/themes/itgadmin/js/jquery.snippet.min.js"></script>
<script src="<?php echo $base_url; ?>/sites/all/themes/itgadmin/js/jquery.easyPaginate.js"></script>

<?php
$video_data = "";
?>
<div class="video-ftp-div">
  <?php
  $all_used_video = itg_videogallery_get_all_publish_video_of_video_content();

  foreach ($rows as $id => $row) {
    if ($row['sm_field_video_used'] == 0 && VIDEO_PROPERTY == $row['sm_field_property']) {
      if (!in_array($row['sm_field_video_id'], $all_used_video)) {
        $video_value = $row['sm_field_video_id'] . '#' . $row['sm_field_video_size'] . '#' . $row['label'] . '#' . $row['sm_field_video_thumb_url'] . '#' . $row['sm_field_video_duration'] . '#' . $row['sm_field_property']. '#video_gallery';
        if (!empty($row['sm_field_video_thumb_url'])) {
          $video_image = '<img  width="100" height="44" src="' . $row['sm_field_video_thumb_url'] . '">';
          $file_size = number_format($row['sm_field_video_size'] / (1024 * 1024), 2);
          $video_data .= '<span class="ftp_video_radio"><input id = "video_id_' . $row['sm_field_video_id'] . '" type="radio" name="video-form" class="form-radio" value="' . $video_value . '"/><label for = "video_id_' . $key . '"><span class="show_video_id">'.$row['sm_field_video_id'].'</span><br>' . $video_image . $row['label'] . '<span class="file_size">' . $file_size . 'MB</span><span class="file_size_duration">' . $row['sm_field_video_duration'] . '</span></label></span>';
        }
      }
    }
    
     if (VIDEO_PROPERTY != $row['sm_field_property']) {
     // if (!in_array($row['sm_field_video_id'], $all_used_video)) {
        $video_value = $row['sm_field_video_id'] . '#' . $row['sm_field_video_size'] . '#' . $row['label'] . '#' . $row['sm_field_video_thumb_url'] . '#' . $row['sm_field_video_duration'] . '#' . $row['sm_field_property']. '#video_gallery';
        if (!empty($row['sm_field_video_thumb_url'])) {
          $video_image = '<img  width="100" height="44" src="' . $row['sm_field_video_thumb_url'] . '">';
          $file_size = number_format($row['sm_field_video_size'] / (1024 * 1024), 2);
          $video_data .= '<span class="ftp_video_radio"><input id = "video_id_' . $row['sm_field_video_id'] . '" type="radio" name="video-form" class="form-radio" value="' . $video_value . '"/><label for = "video_id_' . $key . '"><span class="show_video_id">'.$row['sm_field_video_id'].'</span><br>' . $video_image . $row['label'] . '<span class="file_size">' . $file_size . 'MB</span><span class="file_size_duration">' . $row['sm_field_video_duration'] . '</span></label></span>';
        }
      //}
    }
  }
  echo '<div id="edit-video-browse-select">' . $video_data . '</div><script>jQuery("#edit-video-browse-select").easyPaginate({
		paginateElement: ".ftp_video_radio",
		elementsPerPage: 21,
		effect: "climb"
	});</script>';
  ?>

</div>