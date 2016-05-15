<?php

/**
 * @file: itg_event_backend.inc
 */

/**
 * Implements function for publish event.
 */
function itg_event_backend_publish_event(){
  $current_time = time();
  $start_time = mktime(0, 0, 0, date("m", $current_time), date("d", $current_time), date("Y", $current_time));
  $end_time = mktime(23, 59, 59, date("m", $current_time), date("d", $current_time), date("Y", $current_time));
  $query = db_select('node','n');
  $query->join('field_data_field_event_start_date','fstartd','n.nid = fstartd.entity_id');
  $query->join('field_data_field_event_close_date','fendd','n.nid = fendd.entity_id');
  
  $query->fields('n', array('title'));
  $query->fields('fstartd', array('field_event_start_date_value'));
  $query->fields('fendd', array('field_event_close_date_value'));
  
  $query->condition('n.status', 0, '=');
  //$query->condition('start_date', array($start_time, $end_time), 'IN BETWEEN');
  $query->addExpression("UNIX_TIMESTAMP(fstartd.field_event_start_date_value )", 'start_date');
  
  //UNIX_TIMESTAMP(STR_TO_DATE(
  $result = $query->execute()->fetchAll();
   
  pr(date('d-m-Y H:i:s', $start_time));
  pr(date('d-m-Y H:i:s', '1463077800'));
  
 
  p($result);    
}
//, 'field_start_date' array('field_event_start_date_value')
/**
 * Implements function for unpublish event.
 */
function itg_event_backend_unpublish_event(){
  $current_time = time();
  $start_time = mktime(0, 0, 0, date("m", $current_time), date("d", $current_time), date("Y", $current_time));
  $end_time = mktime(23, 59, 59, date("m", $current_time), date("d", $current_time), date("Y", $current_time));
}