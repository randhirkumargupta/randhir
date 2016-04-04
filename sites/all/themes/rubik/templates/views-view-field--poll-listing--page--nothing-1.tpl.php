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
//pr($row->_field_data['nid']['entity']->field_poll_start_date);
//pr($row->_field_data['nid']['entity']->field_poll_end_date);
if(isset($row->_field_data['nid']['entity']->field_poll_start_date)){
  $start_date = $row->_field_data['nid']['entity']->field_poll_start_date[LANGUAGE_NONE][0]['value'];
 $starttime = strtotime($start_date);
 if(isset($row->_field_data['nid']['entity']->field_poll_end_date[LANGUAGE_NONE])){
  $end_date = $row->_field_data['nid']['entity']->field_poll_end_date[LANGUAGE_NONE][0]['value'];
  $etime = strtotime($end_date);
  $endtime = mktime(23, 59, 59, date("m", $etime), date("d", $etime), date("Y", $etime));
}
 if(($starttime <= time()) && empty($end_date)){
   $status = "Active";
 }elseif(($starttime <= time()) && ($endtime >= time())){
   $status = "Active";
 }else{
   $status = "InActive";
 }
 
}
$output = $status;

print $output; ?>