<?php
/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php
$color_box_query = array("width" => "900", "height" => "600", "iframe" => "true", "widget_name" => $row->itg_custom_widgets_data_widget);
$color_box_class = array("class" => array("colorbox-load"));
echo l("<span class='edit-link'>" . t("Edit") . "</span>", "itg-custom-widget-content-order/$row->itg_custom_widgets_data_widget", array('html' => TRUE, 'query' => $color_box_query, 'attributes' => $color_box_class));
echo "&nbsp; | &nbsp;";
echo l("<span class='add-link'>" . t("Add Content") . "</span>", "itg-custom-widget-content", array('html' => TRUE, 'query' => $color_box_query, 'attributes' => $color_box_class));
?>