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
<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
   <?php if (!empty($title) || !empty($caption)) : ?>
     <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
      <tr>
        <?php foreach ($header as $field => $label): ?>
          <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?> scope="col">
            <?php print $label; ?>
          </th>
        <?php endforeach; ?>
      </tr>
    </thead>
  <?php endif; ?>
  <tbody>
    <?php foreach ($rows as $row_count => $row): ?>
      <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
        <?php foreach ($row as $field => $content): ?>
          <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
            <?php 
            if($field == 'nothing_1') {
              print _get_term_report_view_count_data($row['tid']);
            }
            elseif($field == 'nothing_2') {
              $date_from = !(empty($_GET['week1_date_from'])) ? $_GET['week1_date_from'] : 'N/A';
              $date_to = !(empty($_GET['week1_date_to'])) ? $_GET['week1_date_to'] : 'N/A';
              $nothing_2 = _get_report_data_of_week($row['tid'] , $date_from , $date_to);
              print $nothing_2;
            }
            elseif($field == 'nothing_3') {
              $date_from = !(empty($_GET['week2_date_from'])) ? $_GET['week2_date_from'] : 'N/A';
              $date_to = !(empty($_GET['week2_date_to'])) ? $_GET['week2_date_to'] : 'N/A';
              $nothing_3 = _get_report_data_of_week($row['tid'] , $date_from , $date_to);
              print $nothing_3;
            }
            elseif($field == 'nothing_4') {
              if($nothing_2 != 'N/A') {
                $week1 = (int) $nothing_2;
              }
              else {
                $week1 = 0;
              }
              if($nothing_3 != 'N/A') {
                $week2 = (int) $nothing_3;
              }
              else {
                $week2 = 0;
              }
              print _get_percentage_growth($week1 , $week2);
            }
            else {
              print $content; 
            }
            ?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>