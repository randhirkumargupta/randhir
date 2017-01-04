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
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
      <tr>
        <?php foreach ($header as $field => $label): ?>
          <th <?php ($field == 'weight' || $field == 'id' || $field == 'tid') ? print "style='display:none'"  : print ""; ?> <?php
          if ($header_classes[$field]) {
            print 'class="' . $header_classes[$field] . '" ';
          }
          ?> scope="col">
              <?php print $label; ?>
          </th>
        <?php endforeach; ?>
      </tr>
    </thead>
  <?php endif; ?>
  <tbody>
    <?php
    $limit = 2 * count($rows);
    foreach ($rows as $row_count => $row):
      ?>
      <tr <?php
      if ($row_classes[$row_count]) {
        print 'class="' . implode(' ', $row_classes[$row_count]) . '"';
      }
      ?>>
          <?php foreach ($row as $field => $content): ?>
            <?php
            if ($field == 'draggableviews') {
              ?>
            <td style="display: none">
              <select class="draggableviews-weight form-select" id="edit-draggableviews-2-weight" name="draggableviews[<?php print $row_count ?>][weight]">
                <?php
                for ($i = 0; $i <= $limit; $i++) {
                  $selected = "";
                  if ($row['weight'] == $i) {
                    $selected = "selected";
                  }
                  print '<option value="' . $i . '" ' . $selected . ' >' . $i . '</option>';
                }
                ?>
              </select>
              <?php
              $draggableviews_id = "";
              if ($row['tid']) {
                $draggableviews_id = $row['tid'];
              }
              else {
                $draggableviews_id = $row['title'];
              }
              ?>
              <input class="draggableviews-id" type="text" name="draggableviews[<?php print $row_count ?>][id]" value="<?php print $draggableviews_id; ?>">
            </td>
            <?php
          }
          else if ($field == 'nothing') {
            $arg = arg();
            $destination = '';
            global $base_url;
            if ($arg[1] == 'third') {
              $link = l("<span class='delete-link'>Remove</span>", $base_url . "/itg-menu-manager-remove/" . $row['id'], array("html" => TRUE, "attributes" => array("class" => array("menu-manager-delete")), "query" => array("delete_path" => "menu-manager/third", "section_id" => $_GET['section_id'], "section_child" => $_GET['section_child'])));
            }
            else if ($arg[1] == 'vertical') {
              $link = l("<span class='delete-link'>Remove</span>", $base_url . "/itg-menu-manager-remove/" . $row['id'], array("html" => TRUE, "attributes" => array("class" => array("menu-manager-delete")), "query" => array("delete_path" => "menu-manager/vertical", "section_id" => $_GET['section_id'], "section_child" => $_GET['section_child'])));
            }
            else {
              $link = l("<span class='delete-link'>Remove</span>", $base_url . "/itg-menu-manager-remove/" . $row['id'], array("html" => TRUE, "attributes" => array("class" => array("menu-manager-delete")), "query" => array("destination" => "menu-manager/second")));
            }
            ?>
            <td>
              <?php print $link; ?>
              |
              <a class="menu-manager-edit" href="<?php print $base_url; ?>/itg-menu-manager/?edit_id=<?php print $row['id'] ?>&term_id=<?php print $row['tid'] ?>&prev_page=<?php print arg(0) . "/" . arg(1) ?>"><span class="edit-link">Edit</span></a>
            </td>
            <?php
          }
          else {
            ?>
            <td <?php ($field == 'weight' || $field == 'id' || $field == 'tid') ? print "style='display:none'"  : print ""; ?> <?php
            if ($field_classes[$field][$row_count]) {
              print 'class="' . $field_classes[$field][$row_count] . '" ';
            }
            ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
                <?php print $content; ?>
            </td>
            <?php
          }
          ?>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>