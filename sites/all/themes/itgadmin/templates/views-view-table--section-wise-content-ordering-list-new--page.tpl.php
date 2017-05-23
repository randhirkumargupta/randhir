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
$custom_weight_array = _get_custom_weight_from_table();
?>
<table <?php if ($classes) {
  print 'class="' . $classes . '" ';
} ?><?php print $attributes; ?>>
    <?php if (!empty($title) || !empty($caption)) : ?>
      <caption><?php print $caption . $title; ?></caption>
    <?php endif; ?>
<?php if (!empty($header)) : ?>
      <thead>
          <tr>
              <?php foreach ($header as $field => $label): ?>

                    <?php if ($field == 'weight') : ?>
                  <th style="display:none;" <?php if ($header_classes[$field]) {
                        print 'class="' . $header_classes[$field] . '" ';
                      } ?> scope="col">
                      <?php print $label; ?>
                  </th>
                <?php else : ?>
                  <th <?php if ($header_classes[$field]) {
                    print 'class="' . $header_classes[$field] . '" ';
                  } ?> scope="col">
          <?php print $label; ?>
                  </th>
            <?php endif; ?>
          <?php endforeach; ?>
          </tr>
      </thead>
            <?php endif; ?>
    <tbody>
                <?php foreach ($rows as $row_count => $row): ?>
          <tr <?php if ($row_classes[$row_count]) {
                    print 'class="' . implode(' ' , $row_classes[$row_count]) . '"';
                  } ?>>
  <?php  foreach ($row as $field => $content):
    if ($field != 'draggableviews') {
      ?>
                  <td <?php ($field == 'weight') ? print "style='display:none;'" : ""; ?> <?php if ($field_classes[$field][$row_count]) {
        print 'class="' . $field_classes[$field][$row_count] . '" ';
      } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
      <?php print $content; ?>
                  </td>
                <?php }
                else { 
                  ?>
                  <td>
                      <div class="custom-weight-draggable" style="display: inline-block !important;">
                          <input id="custom-drag-weight" type="number" min="0" required="required" name="draggableviews[<?php print $row_count ?>][weight]" value="<?php print $custom_weight_array[$row['nid']]; ?>">
                          <select class="draggableviews-weight form-select" id="edit-draggableviews-<?php print $row_count ?>-weight" name="draggableviews[<?php print $row_count ?>][weight]">
                              <option value="<?php print $row['weight']; ?>" selected="selected"><?php print $custom_weight_array[$row['nid']]; ?></option>
                          </select>
                          <input type="text" min="0" required="required" name="draggableviews[<?php print $row_count ?>][nid]" value="<?php print $row['nid']; ?>">
                      </div>
                  </td>
    <?php } ?>
  <?php endforeach; ?>
          </tr>
<?php endforeach; ?>
    </tbody>
</table>

<script>
  jQuery(".custom-weight-draggable #custom-drag-weight").on('change', function () {
    var el_val = jQuery(this).val();
    jQuery(this).next().html("<option value='"+el_val+"'>"+el_val+"</option>");
  });
</script>