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
    <?php
    $count = 0;
    foreach($rows as $row){
      $row['views_bulk_operations'] = '<div class="form-item form-type-checkbox form-item-views-bulk-operations-'.$count.'">
 <input type="checkbox" value="'.$row['field_primary_category'].'" name="views_bulk_operations['.$count.']" id="edit-views-bulk-operations-'.$count.'" class="vbo-select form-checkbox">
</div>';
      //$row['counter'] = $count;
      if(module_exists('itg_videogallery')){
        $row['field_primary_category'] = itg_videogallery_get_tname($row['field_primary_category']);
      }
      $array[$row['field_primary_category']] = $row;
      $count++;
    }
    $rows = array_values($array);
    ?>
    <?php $key=1; foreach ($rows as $row_count => $row): ?>
    <?php $row['counter'] = $key; ?>
      <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
        <?php foreach ($row as $field => $content): ?>
          <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
            <?php print $content; ?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php $key++; endforeach; ?>
  </tbody>
</table>