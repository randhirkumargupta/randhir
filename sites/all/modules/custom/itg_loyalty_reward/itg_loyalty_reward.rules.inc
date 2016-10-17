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