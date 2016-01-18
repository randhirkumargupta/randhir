<?php
/**
 * @file
 * user_management.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function user_management_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'SEO' => 'SEO',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'assign Author/Guest role'.
  $permissions['assign Author/Guest role'] = array(
    'name' => 'assign Author/Guest role',
    'roles' => array(
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Copy Editor role'.
  $permissions['assign Copy Editor role'] = array(
    'name' => 'assign Copy Editor role',
    'roles' => array(
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Editor role'.
  $permissions['assign Editor role'] = array(
    'name' => 'assign Editor role',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Intern role'.
  $permissions['assign Intern role'] = array(
    'name' => 'assign Intern role',
    'roles' => array(
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign SEO role'.
  $permissions['assign SEO role'] = array(
    'name' => 'assign SEO role',
    'roles' => array(
      'SEO' => 'SEO',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Section Editor/Anchor role'.
  $permissions['assign Section Editor/Anchor role'] = array(
    'name' => 'assign Section Editor/Anchor role',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Site Admin role'.
  $permissions['assign Site Admin role'] = array(
    'name' => 'assign Site Admin role',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Subeditor/Sr.Sub role'.
  $permissions['assign Subeditor/Sr.Sub role'] = array(
    'name' => 'assign Subeditor/Sr.Sub role',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign all roles'.
  $permissions['assign all roles'] = array(
    'name' => 'assign all roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Intern' => 'Intern',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Intern' => 'Intern',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Intern' => 'Intern',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
