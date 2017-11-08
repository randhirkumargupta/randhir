<?php
global $base_url;
/**
 * @file_field_delete_file
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

<?php
$video_data = "";
?>
<div class="video-ftp-div">
    <div class="main-top-wraper">
        <div class="search-checkbox-wraper"></div>
        <div class="search-image-wraper"><?php echo t('Image'); ?></div>
        <div class="search-video-id-wraper"><?php echo t('Video Id'); ?></div>
        <div class="search-title-wraper"><?php echo t('Title'); ?></div>
        <div class="search-size-wraper"><?php echo t('Size'); ?></div>
        <div class="search-duration-wraper"><?php echo t('Duration'); ?></div>
        <div class="search-date-wraper"><?php echo t('Video Time'); ?></div>
        <div class="search-image-wraper"><?php echo t('Play'); ?></div>
    </div>
    <?php
    $all_used_video = itg_videogallery_get_all_publish_video_of_video_content();
    foreach ($rows as $id => $row) {
      $image_path = $row['sm_field_video_thumb_url'];
      if (empty($row['sm_field_video_thumb_url'])) {
         $image_path = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image88x66.jpg');
          }
          if (VIDEO_PROPERTY != $row['sm_field_property'] ) {

          if ($_GET['sm_field_video_used'] == "") {
          $video_value = $row['sm_field_video_id'] . '#' . $row['sm_field_video_size'] . '#' . $row['label'] . '#' . $row['sm_field_video_thumb_url'] . '#' . $row['sm_field_video_duration'] . '#' . $row['sm_field_property'] . '#video_gallery##INTERNAL#'.$row['sm_field_all_xml_content'];
          if ( $row['sm_field_video_used']  == 0) {
          $video_image = '<img  width="100" height="44" src="' . $image_path . '">';
          $file_size = number_format($row['sm_field_video_size'] / (1024 * 1024), 2);
          $video_data .= '<div class="ftp_video_radio"><div class="video-checkbox-wraper"><input id = "video_id_' . $row['sm_field_video_id'] . '" type="checkbox" name="video-form" class="form-radio" value="' . $video_value . '"/></div><div class="serch-image">' . $video_image . '</div><div class="show_video_id">' . $row['sm_field_video_id'] . '</div><div class="show_video_title"><span>' . $row['label'] . '</span></div><div class="file_size">' . $file_size . 'MB</div><div class="file_size_duration">' . $row['sm_field_video_duration'] . '</div><div class="file_size_date_time">' . $row['sm_field_video_date_time'] . '</div><div><a href="javascript:void(0)" data-video-id ="' . $row['sm_field_video_id'] . '" class="play-video"><i class="fa fa-play-circle" aria-hidden="true"></i> Play</a></div></div>';
          }
          }
          else {
          // if(!in_array($row['sm_field_video_id'], $all_used_video)) {
          $video_value = $row['sm_field_video_id'] . '#' . $row['sm_field_video_size'] . '#' . $row['label'] . '#' . $row['sm_field_video_thumb_url'] . '#' . $row['sm_field_video_duration'] . '#' . $row['sm_field_property'] .  '#video_gallery##INTERNAL#'.$row['sm_field_all_xml_content'];

          $video_image = '<img  width="100" height="44" src="' . $image_path . '">';
          $file_size = number_format($row['sm_field_video_size'] / (1024 * 1024), 2);
          $video_data .= '<div class="ftp_video_radio"><div class="video-checkbox-wraper"><input id = "video_id_' . $row['sm_field_video_id'] . '" type="checkbox" name="video-form" class="form-radio" value="' . $video_value . '"/></div><div class="serch-image">' . $video_image . '</div><div class="show_video_id">' . $row['sm_field_video_id'] . '</div><div class="show_video_title"><span>' . $row['label'] . '</span></div><div class="file_size">' . $file_size . 'MB</div><div class="file_size_duration">' . $row['sm_field_video_duration'] . '</div><div class="file_size_date_time">' . $row['sm_field_video_date_time'] . '</div><div><a href="javascript:void(0)" data-video-id ="' . $row [ 'sm_field_video_id'] . '" class="play-video"><i class="fa fa-play-circle" aria-hidden="true"></i> Play</a></div></div>' ;

          }
          //  }
          }
          if ( $row['sm_field_video_used'] == 0 && VIDEO_PROPERTY == $row [ 'sm_field_property']) {
          if ( ! in_array($row['sm_field_video_id'], $all_used_video ) ) {
          $video_value = $row['sm_field_video_id'] . '#'. $row['sm_field_video_size'] . '#' . $row [ 'label'] . '#' . $row['sm_field_video_thumb_url'] . '#' . $row['sm_field_video_duration'] . '#' . $row['sm_field_property']  . '#video_gallery##INTERNAL#'.$row['sm_field_all_xml_content'];
          $video_image = '<img  width="100" height="44" src="' . $image_path . '">';
          $file_size = number_format($row['sm_field_video_size'] / (1024 * 1024), 2);
          $video_data .= '<div class="ftp_video_radio"><div class="video-checkbox-wraper"><input id = "video_id_' . $row['sm_field_video_id'] . '" type="checkbox" name="video-form" class="form-radio" value="' . $video_value . '"/></div><div class="serch-image">' . $video_image . '</div><div class="show_video_id">' . $row['sm_field_video_id'] . '</div><div class="show_video_title"><span>' . $row['label'] . '</span></div><div class="file_size">' . $file_size . 'MB</div><div class="file_size_duration">' . $row['sm_field_video_duration'] . '</div><div class="file_size_date_time">' . $row['sm_field_video_date_time'] . '</div><div><a href="javascript:void(0)" data-video-id ="' . $row['sm_field_video_id'] . '" class="play-video"><i class="fa fa-play-circle" aria-hidden="true"></i> Play</a></div></div>';
          }
        }
      
    }
    echo '<div id="edit-video-browse-select">' . $video_data . '</div><div id="video_play_div"></div>';
    ?>

</div>