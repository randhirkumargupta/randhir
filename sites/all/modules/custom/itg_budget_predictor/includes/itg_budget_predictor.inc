<?php

/**
 * @file
 * itg_budget_predictor.inc
 *
 * Provides customizations and functions for Budget Predictor Widgets.
 *
 */

/**
 * function to get data of taxonomy
 * @global array $user
 * @return array
 */
function itg_budget_predictor_get_taxonomy() {
    global  $user;
    $user_id = $user->uid;
    $budget_type = 1;
    $ranking_array = array();
    $querys = db_select('itg_budget_predictor', 'r');
    $querys->fields('r', array('entity_id', 'ranking_column'));
    $querys->condition('r.user_id', $user_id);
    $querys->condition('r.budget_type', $budget_type);
    $results = $querys->execute()->fetchAll(PDO::FETCH_ASSOC);
    foreach ($results as $k=>$row) {
        $ranking_array[$k]['ranking_column'] = $row['ranking_column'];
        $ranking_array[$k]['entity_id'] = $row['entity_id'];
        $entity_array[] = $row['entity_id'];
    }
    $query = db_select('taxonomy_term_data', 'td');
    $query->leftJoin('taxonomy_vocabulary', 'v', 'td.vid=v.vid');
    $query->leftJoin('field_data_field_story_small_image', 'img', 'td.tid=img.entity_id');
    $query->leftJoin('itg_budget_predictor', 'r', 'td.tid=r.entity_id');
    $query->fields('td', array('name', 'vid', 'tid'));
    $query->fields('img', array('field_story_small_image_fid'));
    $query->condition('v.machine_name', 'cheaper_dearer');
    
    if(count($entity_array) > 0 && is_array($entity_array)) {
        $query->condition('td.tid', $entity_array, 'NOT IN');
    }
    //dpq($query);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $entity_data = array();
    foreach ($result as $key=>$entity_data_node) {  
        $entity_data[$key]['tid'] = $entity_data_node['tid'];
        $entity_data[$key]['name'] = $entity_data_node['name'];
        $entity_data[$key]['image'] = $entity_data_node['field_story_small_image_fid'];
    }
    
    $entity_data['ranking'] = $ranking_array;
    
    
    global $base_url, $user;
    $title = 'Budget Predictor';
    $actual_link = $base_url . '/budget-predictor';
    $budget_type = '1';
    $ip_address = $_SERVER['REMOTE_ADDR'];
    $column1 = '';
    $column2 = '';
    $column3 = '';

    $column4 = '';
    $user_id = $user->uid;
    foreach ($entity_data as $key => $node_data) {
        $tid = $node_data['tid'];
        $name = $node_data['name'];
        $fid = $node_data['image'];
        $file = file_load($fid);
        $uri = $file->uri;
        if ($tid) {
            $column4 .= '<li id="entry_' . $tid . '" class="ui-state-default"><img src="' . image_style_url("thumbnail", $uri) . '"></li>';
        }
    }
    foreach ($entity_data['ranking'] as $keys => $values) {
        $entity_id = $values['entity_id'];
        $fid = get_ranking_fid($entity_id);
        $file = file_load($fid);
        $uri = $file->uri;
        if ($values['ranking_column'] == '1') {
            $column1 .= '<li id="entry_' . $entity_id . '" class="ui-state-default"><img src="' . image_style_url("thumbnail", $uri) . '"></li>';
        }
        if ($values['ranking_column'] == '2') {
            $column2 .= '<li id="entry_' . $entity_id . '" class="ui-state-default"><img src="' . image_style_url("thumbnail", $uri) . '"></li>';
        }
        if ($values['ranking_column'] == '3') {
            $column3 .= '<li id="entry_' . $entity_id . '" class="ui-state-default"><img src="' . image_style_url("thumbnail", $uri) . '"></li>';
        }
    }

    
        $budget_data['column1'] = $column1;
        $budget_data['column2'] = $column2;
        $budget_data['column3'] = $column3;
        $budget_data['column4'] = $column4;
        $budget_data['title'] = $title;
        $budget_data['actual_link'] = $base_url . '/budget-predictor';
    return $budget_data;
}

/**
 * Budget Predictor Budget Insert/Update
 * @global array $user
 */
function itg_budget_predictor_update_budget() {
        global  $user;
        $user_id = $user->uid;
        $budget_type = 1;
	$ip_address = $_SERVER['REMOTE_ADDR'];
	$sort1 = '';
	$sort2 = '';
	$sort3 = '';
	$sort4 = '';

	// PARSES THE POSTS FROM EACH COLUMN INTO AN ARRAY
	parse_str($_POST['sort1'], $sort1);
	parse_str($_POST['sort2'], $sort2);
	parse_str($_POST['sort3'], $sort3);
	//parse_str($_POST['sort4'], $sort4);
            foreach($sort1['entry'] as $key=>$value){
                $count = itg_budget_predictor_check_ranking($value);
                if($count < 1) {
                    $nid = db_insert('itg_budget_predictor')
                        ->fields(array(
                          'entity_id' => $value,
                          'ranking_value' => $key,
                          'ranking_column' => 1,
                          'budget_type' => 1,
                          'user_id' => $user_id,
                          'status' => 1,
                          'timestamp' => REQUEST_TIME,
                          'ip_address' => $ip_address,
                        ))
                        ->execute();
                } else {
                    db_update('itg_budget_predictor')
                        ->fields(array(
                          'ranking_value' => $key,
                          'ranking_column' => 1,
                          'timestamp' => REQUEST_TIME,
                          'ip_address' => $ip_address,
                        ))
                        ->condition('entity_id', $value, '=')    
                        ->condition('user_id', $user_id, '=')    
                        ->execute();
                }
            } 
            
            
            
            foreach($sort2['entry'] as $key=>$value){
                $count = itg_budget_predictor_check_ranking($value);
                if($count < 1) {
                    $nid = db_insert('itg_budget_predictor')
                        ->fields(array(
                          'entity_id' => $value,
                          'ranking_value' => $key,
                          'ranking_column' => 2,
                          'budget_type' => 1,
                          'user_id' => $user_id,
                          'status' => 1,
                          'timestamp' => REQUEST_TIME,
                          'ip_address' => $ip_address,
                        ))
                        ->execute();
                } else {
                    db_update('itg_budget_predictor')
                        ->fields(array(
                          'ranking_value' => $key,
                          'ranking_column' => 2,
                          'timestamp' => REQUEST_TIME,
                          'ip_address' => $ip_address,
                        ))
                        ->condition('entity_id', $value, '=')    
                        ->condition('user_id', $user_id, '=')    
                        ->execute();
                }
            }
            foreach($sort3['entry'] as $key=>$value){
                $count = itg_budget_predictor_check_ranking($value);
                if($count < 1) {
                    $nid = db_insert('itg_budget_predictor')
                        ->fields(array(
                          'entity_id' => $value,
                          'ranking_value' => $key,
                          'ranking_column' => 3,
                          'budget_type' => 1,
                          'user_id' => $user_id,
                          'status' => 1,
                          'timestamp' => REQUEST_TIME,
                          'ip_address' => $ip_address,
                        ))
                        ->execute();
                } else {
                    db_update('itg_budget_predictor')
                        ->fields(array(
                          'ranking_value' => $key,
                          'ranking_column' => 3,
                          'timestamp' => REQUEST_TIME,
                          'ip_address' => $ip_address,
                        ))
                        ->condition('entity_id', $value, '=')    
                        ->condition('user_id', $user_id, '=')    
                        ->execute();
                }
            }
        
}

/**
 * Get date from itg_budget_predictor
 * @return array
 */
function itg_budget_predictor_get_budget_ranking() {
    $query = db_select('itg_budget_predictor', 'r');
    $query->leftJoin('field_data_field_story_small_image', 'img', 'td.tid=img.entity_id');
    $query->fields('td', array('name', 'vid', 'tid'));
    $query->fields('img', array('field_story_small_image_fid'));
    $query->condition('v.machine_name', 'cheaper_dearer');
    return $query->execute()->fetchAll(PDO::FETCH_ASSOC);
}

/**
 * chaeck budget predictor ranking
 * @global array $user
 * @param int $entity_id
 * @return int
 */
function itg_budget_predictor_check_ranking($entity_id) {
    global  $user;
    $user_id = $user->uid;
    $budget_type = 1;
    $query = db_select('itg_budget_predictor', 'r');
        $query->fields('r', array('entity_id'));
        $query->condition('r.user_id', $user_id);
        $query->condition('r.entity_id', $entity_id);
        $query->condition('r.budget_type', $budget_type);
        return $query->execute()->rowCount();
}

/**
 * Get fid from taxonomy
 * @param int $tid
 * @return int
 */
function get_ranking_fid($tid) {
    $query = db_select('taxonomy_term_data', 'td');
    $query->leftJoin('taxonomy_vocabulary', 'v', 'td.vid=v.vid');
    $query->leftJoin('field_data_field_story_small_image', 'img', 'td.tid=img.entity_id');
    $query->leftJoin('itg_budget_predictor', 'r', 'td.tid=r.entity_id');
    $query->fields('img', array('field_story_small_image_fid'));
    $query->condition('v.machine_name', 'cheaper_dearer');
    $query->condition('td.tid', $tid, '=');
    $result = $query->execute()->fetchAssoc();
    return $result['field_story_small_image_fid'];
}