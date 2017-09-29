<?php
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
<table <?php
if ($classes) {
  print 'class="' . $classes . '" ';
}
?><?php print $attributes; ?>>
        <?php if (!empty($title) || !empty($caption)) : ?>
      <caption><?php print $caption . $title; ?></caption>
      <?php
    endif;
    $all_used_video = itg_videogallery_get_all_publish_video_of_video_content();
    ?>
    <?php if (!empty($header)) : ?>
      <thead>
          <tr>
              <th>&nbsp;<th>
              <?php foreach ($header as $field => $label): ?>
              <?php if($label != "") { ?>
                <th <?php
                if ($header_classes[$field]) {
                  print 'class="' . $header_classes[$field] . '" ';
                }
                ?> scope="col">
                        <?php print $label; ?>
                </th>
              <?php } endforeach; ?>
          </tr>
      </thead>
    <?php endif; ?>
    <tbody>
        <?php foreach ($rows as $row_count => $row): 

          ?>
          <?php
          $video_value = $row['sm_field_video_id'] . '#' . $row['sm_field_video_size'] . '#' . $row['label'] . '#' . $row['sm_field_video_thumb_url'] . '#' . $row['sm_field_video_duration'] . '#' . $row['sm_field_property'] . '#video_gallery##'.$row['sm_field_video_type'].'#'.$row['sm_field_all_xml_content'];
          $video_image = '<img  width="100" height="44" src="' . $row['sm_field_video_thumb_url'] . '">';
          $file_size = number_format($row['sm_field_video_size'] / (1024 * 1024), 2);
          ?>
          <tr <?php
          if ($row_classes[$row_count]) {
            print 'class="' . implode(' ', $row_classes[$row_count]) . '"';
          }
          ?>>
                  <?php foreach ($row as $field => $content): ?>

                <?php
                if ($field == 'nothing') {
                  ?>
                  <td>
                      <?php
                      if (in_array($row['sm_field_video_id'], $all_used_video)) {
                        $statusDis = 'disabled="disabled"';
                      }
                      else {
                        $statusDis = "";
                      }
                      ?>
                      <input <?php echo $statusDis; ?> data-video-type = "<?php echo $row['sm_field_video_type']; ?>" id = "video_id_<?php echo $row['sm_field_video_id']; ?>" type = "checkbox" name = "video-form" class = "form-radio video-checkbox-form" value = "<?php echo $video_value; ?>"/>
                  </td>
                  <?php
                }
                else if ($field == 'sm_field_video_thumb_url') {
                  ?>
<!--                  <td <?php
                  if ($field_classes[$field][$row_count]) {
                    print 'class="' . $field_classes[$field][$row_count] . '" ';
                  }
                  ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
                          <?php print $video_image; ?>
                  </td>-->
                  <?php
                }
                else if ($field == 'label'  || $field == 'sm_field_video_date_time') {
                  ?>
                  <td <?php
                  if ($field == 'label') {
                    print 'title="' . $content . '"';
                  }

                  if ($field_classes[$field][$row_count]) {
                    print 'class="' . $field_classes[$field][$row_count] . '" ';
                  }
                  ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
                          <?php
                          if ($field == 'label') {
                            print mb_strimwidth($content, 0, 17, '..');
                          }
                          else {
                            print $content;
                          }
                          ?>
                  </td>
                  <?php
                }
                else if ($field == 'sm_field_video_used') {
                  ?>
                  <td <?php
                  if ($field_classes[$field][$row_count]) {
                    print 'class="' . $field_classes[$field][$row_count] . '" ';
                  }
                  ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
                          <?php print '<a class="play solr-unpublish-icon video-in-form" href="javascript:void(0)" data-video-id = ' . $row['sm_field_video_id'] . '><i class="fa fa-play-circle" aria-hidden="true"></i> Play</a>'; ?>
                  </td>
                <?php }
                ?>
              <?php endforeach; ?>
          </tr>
        <?php endforeach; ?>
    </tbody>
</table>