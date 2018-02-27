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
if(isset($row->nid)) {
    $nid = $row->nid;
} elseif(isset($row->node_itg_widget_order_nid)) {
    $nid = $row->node_itg_widget_order_nid;
}
if ($view->name == 'manage_issues') {
  if ($row->node_status == 1) {
    $issue_title = $row->field_field_issue_title[0]['raw']['value'];
    $issue_title = date("d-m-Y", strtotime($issue_title));
    echo l('<span class="view-link">view  </span>', FRONT_URL . '/magazine/' . $issue_title, array("html" => TRUE, "attributes" => array("target" => "_blank")));
  }
}
else {
  if (is_widget_views($view)) {
    echo l('<span class="view-link">view  </span>', FRONT_URL . '/node/' . $nid, array("html" => TRUE, "attributes" => array("target" => "_blank")));
  }
  else {
    print $output;
  }
}
?>
