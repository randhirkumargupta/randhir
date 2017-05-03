<?php

/*
 * @file
 * Rules module hook implementation.
 */

/**
 * Implements hook_rules_action_info().
 *
 * @return array
 */
function itg_personalization_rules_action_info() {
  return array(
    'itg_personalization_send_new_content_mail' => array(
      'label' => t('Send Mail to users for new content'),
      'parameter' => array(
        'node' => array('type' => 'node', 'label' => t('Current Node')),
      ),
      'group' => t('ITG'),
    ),
  );
}

/**
 * Implements callback function for 'itg_personalization_send_new_content_mail'
 * @param type $node
 */
function itg_personalization_send_new_content_mail($node) {
  global $base_url;
  // $mail_ids = array();
  /*if (!empty($node->field_story_itg_tags['und']) && is_array($node->field_story_itg_tags['und'])) {
    foreach ($node->field_story_itg_tags['und'] as $k => $value) {
     $tid = $value['tid'];
      $query = db_select('flagging', 'f');
      $query->join('users', 'u', 'f.uid = u.uid');
      $query->leftJoin('field_data_field_first_name', 'n', 'u.uid = n.entity_id');
      $query->leftJoin('field_data_field_last_name', 'l', 'u.uid = l.entity_id');
      $query->fields('u', array('mail', 'name'));
      $query->fields('n', array('field_first_name_value'));
      $query->fields('l', array('field_last_name_value'));
      $query->condition('f.entity_id', $tid, '=');
      $result = $query->execute()->fetchAll();
    
      foreach ($result as $val) {        
        $alias = drupal_get_path_alias('node/' . $node->nid);
        $data = 'Hi ' . $val->field_first_name_value . ' ' . $val->field_last_name_value . ', new content has been published of your interest. ';
       $data .= 'Click ' . l('here', $base_url . '/' . $alias) . ' to see the content.';
        $key = 'personalization_mail';
        $subject = 'New content published';
        $to = $val->mail;
       itg_common_get_mail_content($data, $to, $key, $subject);
      }
      
    }
  }*/
}

/**
 * Implements callback function for 'itg_personalization_send_new_content_mail'
 * @param type $node
 */
/*function itg_personalization_send_new_content_mail_mongo($node) {
  global $base_url;
  // $mail_ids = array();
  if (!empty($node->field_story_itg_tags['und']) && is_array($node->field_story_itg_tags['und'])) {
    foreach ($node->field_story_itg_tags['und'] as $k => $value) {
     $tid = $value['tid'];
        $result = itg_user_list_by_tid($tid);
       if(!empty($result)) {
        foreach ($result as $key => $val) {
          if (function_exists('itg_custom_get_user_details')) {
            $user_arr = itg_custom_get_user_details($val['uid']);
          }
        $alias = drupal_get_path_alias('node/' . $node->nid);
        $data = 'Hi ' . $user_arr['fname'] . ' ' . $user_arr['lname'] . ', new content has been published of your interest. ';
        $data .= 'Click ' . l('here', $base_url . '/' . $alias) . ' to see the content.';
        $key = 'personalization_mail';
        $subject = 'New content published';
        $to = $user_arr['mail'];
        itg_common_get_mail_content($data, $to, $key, $subject);
        }
      }
    }
  }
}*/

/**
 * Helper function to get user id by tag id
 */
/*function itg_user_list_by_tid($tid) {
  $data = '';
  if (function_exists('mongodb') && !empty($tid)) {
    $con = mongodb();
    $people = $con->following_personalization;
    $cond = array('tid' => $tid);
    $cursor = $people->find($cond);
    foreach ($cursor as $key => $document) {
      $data[]['uid'] = $document['uid'];
    }
    return $data;
  }
}*/
