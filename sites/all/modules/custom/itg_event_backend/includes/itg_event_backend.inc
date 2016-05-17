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

/**
 * Implements function ajax callback
 */
function itg_event_backend_title_event(){
  $daywise_val = $_GET['daywise'];
  //$daywise_val = 'Day-1:16-05-2016';  
  $enti_id = arg(1);
  $query = db_select('field_data_field_daywise_event', 'fd_event');
  $query->fields('fd_event', array('field_daywise_event_value'));
  $query->fields('f_schedule', array('field_program_schedule_value'));
  $query->fields('f_title', array('field_story_expert_name_value'));
  $query->join('field_data_field_program_schedule', 'f_schedule', 'fd_event.entity_id = f_schedule.field_program_schedule_value');
  $query->join('field_data_field_story_expert_name', 'f_title', 'fd_event.entity_id = f_title.entity_id');
  $query->condition('fd_event.field_daywise_event_value', $daywise_val, '=');
  $query->condition('fd_event.bundle', 'field_program_schedule', '=');
  $query->condition('f_title.bundle', 'field_program_schedule', '=');
  $query->condition('f_schedule.entity_id', $enti_id, '=');
  $result = $query->execute();
  $output = '';
  $output .= '<option value="_none">- Select gggDaywise -</option>';
  foreach($result as $val){
     $output .=  '<option value="'.$val->field_story_expert_name_value.'">'.$val->field_story_expert_name_value.'</option>';
    // $output =  array($val->field_story_expert_name_value => $val->field_story_expert_name_value);
  }
  echo $output;
  //$enti = entity_load('field_collection_item', array(1063, 1064));
 // p($enti);
}