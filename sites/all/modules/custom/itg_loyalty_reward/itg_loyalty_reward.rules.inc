<?php

/* 
 * @file
 *   Rules module hook implementation.
 */

/**
 * Implements hook_rules_action_info().
 *
 * @return array
 */
function itg_loyalty_reward_rules_action_info() {
  return array(
    'itg_loyalty_reward_ugc_content_points' => array(
      'label' => t('Earn Loyalty Points - UGC Content'),
      'parameter' => array(
        'node' => array('type' => 'node', 'label' => t('Current Node')),
        'ugc_node' => array('type' => 'integer', 'label' => t('UGC content is going to approve.')),
      ),
      'group' => t('ITG'),            
    ),
    'itg_loyalty_reward_visit_content_points' => array(
      'label' => t('Earn Loyalty Points - Content Visit'),
      'parameter' => array(
        'node' => array('type' => 'node', 'label' => t('Current Node')),
        'user' => array('type' => 'user', 'label' => t('Current logged in user.')),
      ),
      'group' => t('ITG'),            
    ),
  );
}

/**
 * Action callback function for 'itg_loyalty_reward_ugc_content_points'.
 *
 * @param type $node
 *   Standard node object.
 * @param int $ugc_node
 *   Node id of the old ugc node.
 */
function itg_loyalty_reward_ugc_content_points($node, $ugc_node) {  
  $ugc_user = node_load($ugc_node);
  itg_loyalty_reward_earnpoint($node->nid, 'ugc', $ugc_user->uid);
}

/**
 * Action callback function for 'itg_loyalty_reward_visit_content_points'.
 *
 * @param stdObject $node
 *   Standard node object.
 * @param stdObject $user
 *   User user object for current logged in user.
 */
function itg_loyalty_reward_visit_content_points($node, $user) {
  itg_loyalty_reward_earnpoint($node->nid, 'visit', $user->uid);
}

/**
 * Implements hook_rules_condition_info().
 *
 * Add new condition to view to check user first visit on node.
 * @return array
 */
function itg_loyalty_reward_rules_condition_info() {
  return array(
    'itg_loyalty_reward_visit_content_condition' => array(
      'label' => t('Validate user is visiting node first time.'),
      'parameter' => array(
        'node' => array('type' => 'node', 'label' => t('Current Node')),
        'user' => array('type' => 'user', 'label' => t('Current logged in user.')),
      ),
      'group' => t('ITG'),            
    ),
  );
}

/**
 * Callback function for 'itg_loyalty_reward_visit_content_condition'.
 *
 * @param stdObject $node
 * @param stdObject $user
 * @return boolean
 */
function itg_loyalty_reward_visit_content_condition($node, $user) {  
  $itg_result = 0;
  $pointer_key = itg_loyalty_reward_unique_expiration($user->uid);  
  $itg_query = db_select('itg_lrp_loyalty_points', 'p')
      ->fields('p', array('id'))
      ->condition('pointer_key', $pointer_key)
      ->condition('uid', $user->uid)
      ->condition('node_id', $node->nid);
  $itg_result = $itg_query->execute()->fetchField();
  // If visit is first time then earn point else not.
  if ($itg_result == 0) {
    return TRUE;
  }
  else {
    return FALSE;
  }  
}