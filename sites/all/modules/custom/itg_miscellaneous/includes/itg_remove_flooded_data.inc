<?php

/**
 * Function to delete flooded node from itg_widget_order table
 */
function itg_remove_flooded_nodes(){
  $time_start = microtime(true); 
  
  $keep_row = (int) variable_get('section_widget_keep_row_count', 100);
  $content_types = array('breaking_news', 'photogallery', 'story', 'videogallery');
  $deleted_cat_id = array();
  
  //Delete From Table itg_widget_order
  $query = db_select('itg_widget_order', 'widget');
  $query->fields('widget', array('cat_id'));
  $query->addExpression('COUNT(widget.cat_id)', 'count');
  $query->condition('widget.widget', 'section_wise_widget');
  $query->condition('widget.content_type', 'All');
  $query->groupBy('widget.cat_id');
  $query->havingCondition('count', $keep_row, '>');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);  
  foreach($result as $value){
    if($value['count'] <= 100){
      continue;
    }
    _delete_old_data_from_section_widget('itg_widget_order', $value['cat_id'], 'All');
    $deleted_cat_id[] = $value['cat_id'] . '#' . $value['count'];
  }
  
  //Delete From Table itg_widget_order_section
  $query = db_select('itg_widget_order_section', 'widget');
  $query->fields('widget', array('cat_id', 'content_type'));
  $query->addExpression('COUNT(widget.cat_id)', 'count');
  $query->condition('widget.widget', 'section_wise_widget');
  $query->groupBy('widget.cat_id');
  $query->groupBy('widget.content_type');
  $query->havingCondition('count', $keep_row, '>');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);  
  foreach($result as $value){
    if($value['count'] <= 100){
      continue;
    }
    _delete_old_data_from_section_widget('itg_widget_order_section', $value['cat_id'], $value['content_type']);
    $deleted_cat_id[] = $value['cat_id'] . '#' . $value['count'];
  }
  
  $time_end = microtime(true);
  $execution_time = ($time_end - $time_start)/60;
  
  $params = json_encode($deleted_cat_id);
  $params = 'Total Exe time: ' . $execution_time . $params;
  watchdog("delete_widget_table", $params);
  //$to_mail = 'shashank.singh@aajtak.com,randhirkumar.gupta@aajtak.com,vishal.kamal@aajtak.com';
  //drupal_mail('itg_miscellaneous', 'itg_miscellaneous_delete_widget_table', $to_mail, language_default(), $params, 'care@intoday.in', TRUE);
}