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

//    $mail_ids = array();
    foreach ($node->field_story_itg_tags['und'] as $k => $value) {
      $tid = $value['tid'];
      $query = db_select('flagging', 'f');
          $query->join('users', 'u', 'f.uid = u.uid');
          $query->fields('u', array('mail', 'name'));
          $query->condition('f.entity_id', $tid, '=');
      $result = $query->execute()->fetchAll();

      foreach ($result as $val) {
//        $mail_ids[] = $val->mail;
        
        $data = "Hi $val->name, new story has been published of your interest.";
        $key = 'personalization_mail';
        $subject = 'New content published';
        $to = $val->mail;
        
        itg_common_get_mail_content($data, $to, $key, $subject);
      } 
  }
//  watchdog('personalization mail',  'mail_ids = ' .'<pre>' . print_r($mail_ids, TRUE) . '</pre>');
}
