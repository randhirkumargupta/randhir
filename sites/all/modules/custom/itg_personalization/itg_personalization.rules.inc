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
 * Implements callback function for 'itg_personalization_send_new_content_mail_mongo'
 * @param type $node
 */
function itg_personalization_send_new_content_mail($node) {
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
        $here_link = l('here', FRONT_URL . '/' . $alias);
        if (function_exists('itg_mail_templates_get_mailcontent')) {
          $get_mail_content = itg_mail_templates_get_mailcontent('My Following', $task_event = NULL, $ugc_status = NULL);
          $subject = $get_mail_content->field_mail_subject_loyalty[LANGUAGE_NONE][0]['value'];
          $fname = str_replace('[itg_mail_token:itg_account_user_fname]', $user_arr['fname'], $get_mail_content->field_mail_body_loyalty[LANGUAGE_NONE][0]['value']);
          $lname = str_replace('[itg_mail_token:itg_account_user_lname]', $user_arr['lname'], $fname);
          $data = str_replace('[itg_mail_token:itg_node_title_link]', $here_link, $lname);
        }

        $key = 'personalization_mail';
        $to = $user_arr['mail'];
        itg_common_get_mail_content($data, $to, $key, $subject);
        }
      }
    }
  }
}

/**
 * Helper function to get user id by tag id
 */
function itg_user_list_by_tid($tid) {
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
}
