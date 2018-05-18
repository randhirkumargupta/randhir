<?php

/**
 * Function to delete flooded node from itg_widget_order table
 */
function itg_remove_flooded_nodes(){
  $time_start = microtime(true);   
  $keep_row = (int) variable_get('section_widget_keep_row_count', 100);
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
    if($value['count'] <= $keep_row){
      continue;
    }
    _delete_old_data_from_section_widget('itg_widget_order', $value['cat_id'], 'All');
    $deleted_cat_id[] = $value['cat_id'] . '#' . $value['count'];
  }
  
  //Delete From Table itg_widget_order_section
  $query1 = db_select('itg_widget_order_section', 'widget');
  $query1->fields('widget', array('cat_id', 'content_type'));
  $query1->addExpression('COUNT(widget.cat_id)', 'count');
  $query1->condition('widget.widget', 'section_wise_widget');
  $query1->groupBy('widget.cat_id');
  $query1->groupBy('widget.content_type');
  $query1->havingCondition('count', $keep_row, '>');
  $result1 = $query1->execute()->fetchAll(PDO::FETCH_ASSOC);  
  foreach($result1 as $value1){
    if($value1['count'] <= $keep_row){
      continue;
    }
    _delete_old_data_from_section_widget('itg_widget_order_section', $value1['cat_id'], $value1['content_type']);
    $deleted_cat_id[] = $value1['cat_id'] . '#' . $value1['count'];
  }
  
  $time_end = microtime(true);
  $execution_time = ($time_end - $time_start)/60;
  
  $params = json_encode($deleted_cat_id);
  $params = 'Total Exe time: ' . $execution_time . $params;
  watchdog("delete_widget_table", $params);
  //$to_mail = 'shashank.singh@aajtak.com,randhirkumar.gupta@aajtak.com,vishal.kamal@aajtak.com';
  //drupal_mail('itg_miscellaneous', 'itg_miscellaneous_delete_widget_table', $to_mail, language_default(), $params, 'care@intoday.in', TRUE);
}

function remove_old_widgets_from_table() {
  $widget_to_be_delete = array('top_stories_widget', 'trending_videos_widget', 'most_popular_widget', 'top_takes_video_widget', 'watch_right_now_widget', 'home_page_feature_widget', 'photo_carousel_list_widget', 'video_carousel_list_widget', 'we_may_suggest_widget', 'anchors_listing_widget');
  foreach ($widget_to_be_delete as $key => $value) {
    itg_widget_delete_old_data_by_limit($value);
  }
}


function remove_old_widgets_from_table_by_tid(){
  $tid = arg(1);
  if (!empty($tid)) {
    $keep_row = (int) variable_get('section_widget_keep_row_count', 100);
    _delete_old_data_from_section_widget('itg_widget_order', $tid, 'All');  
    
    $query1 = db_select('itg_widget_order_section', 'widget');
    $query1->fields('widget', array('cat_id', 'content_type'));
    $query1->addExpression('COUNT(widget.cat_id)', 'count');
    $query1->condition('widget.widget', 'section_wise_widget');
    $query1->condition('widget.cat_id', $tid);
    $query1->groupBy('widget.content_type');
    $result1 = $query1->execute()->fetchAll(PDO::FETCH_ASSOC);  
    foreach($result1 as $value1){
      if($value1['count'] <= $keep_row){
        continue;
      }
      _delete_old_data_from_section_widget('itg_widget_order_section', $value1['cat_id'], $value1['content_type']);
    }
  }
  print 'Done';
  drupal_exit();
}
