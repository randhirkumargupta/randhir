<?php
/**
 * @file
 * feature_for_xml_sitemap_chunks.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_xml_sitemap_chunks_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer itg sitemap'.
  $permissions['administer itg sitemap'] = array(
    'name' => 'administer itg sitemap',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_sitemap_chunks',
  );

  return $permissions;
}
