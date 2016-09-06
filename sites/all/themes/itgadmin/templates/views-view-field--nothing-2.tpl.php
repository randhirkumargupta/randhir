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

$class = 'live-tv-button';
$row_nid = $row->nid;
?>
<?php 
if($view->name == 'live_tv_integration') {
$output  = "<Input type = 'Radio' Name ='Web' value= 'Web' class = '$class' rel='$row_nid'> Web <Input type = 'Radio' Name ='Mobile' value= 'Mobile' class = '$class' rel='$row_nid'> Mobile <Input type = 'Radio' Name ='iOS' value= 'iOS' class = '$class' rel='$row_nid'> iOS <Input type = 'Radio' Name ='Android' value= 'Android' class = '$class' rel='$row_nid'> Android <Input type = 'Radio' Name ='Window' value= 'Window' class = '$class' rel='$row_nid'> Window";
} 
print $output; ?>

