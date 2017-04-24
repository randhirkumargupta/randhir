<?php
/**
 * @file
 * features_for_loyalty_and_rewards.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function features_for_loyalty_and_rewards_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-loyalty-management-tab.
  $menus['menu-loyalty-management-tab'] = array(
    'menu_name' => 'menu-loyalty-management-tab',
    'title' => 'Loyalty Management Tab',
    'description' => 'Admin tab links for loyalty listing page.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Admin tab links for loyalty listing page.');
  t('Loyalty Management Tab');

  return $menus;
}
