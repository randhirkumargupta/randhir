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
global $base_url;

if ($field->view->name == 'autocomplete_for_event' 
        || $field->view->name == 'autocomplete_event_photo' 
        || $field->view->name == 'podcast_for_event' 
        || $field->view->name == 'manage_survey' 
        || $field->view->name == 'manage_quiz') {
  print $output;
} else
if (isset($row->_field_data['nid']['entity']->type) && ($row->_field_data['nid']['entity']->type == 'event_backend' || $row->_field_data['nid']['entity']->type == 'itg_funalytics')) {
  print $output;
} else if (isset($row->_field_data['nid']['entity']->type) && ($row->_field_data['nid']['entity']->type == 'blog' || 
        $row->_field_data['nid']['entity']->type == 'photogallery' || 
        $row->_field_data['nid']['entity']->type == 'videogallery' ||
        $row->_field_data['nid']['entity']->type == 'mega_review_critic' ||
        $row->_field_data['nid']['entity']->type == 'podcast' ||
        $row->_field_data['nid']['entity']->type == 'story' ||
        $row->_field_data['nid']['entity']->type == 'breaking_news')) {
  
    if (isset($row->_field_data['nid']['entity']->status) && $row->_field_data['nid']['entity']->status == 0) {
      print l(strip_tags($output), 'node/'.$row->nid, array('attributes' => array('target' => '_blank')));
    } else {
        if (BACKEND_URL == $base_url) {
            $node_url = FRONT_URL.'/node/'.$row->nid; 
            print '<a href="'.$node_url.'" target="_blank">'.strip_tags($output).'</a>';
        } else {
            print l(strip_tags($output), 'node/'.$row->nid, array('attributes' => array('target' => '_blank')));
        }
    
    } 
  
} else {   
    print l(strip_tags($output), 'node/'.$row->nid);    
}
  
?>

