<?php
/**
 * @file
 * feature_for_mobile_services.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_mobile_services_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create client_service_association content'.
  $permissions['create client_service_association content'] = array(
    'name' => 'create client_service_association content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create clients_creation content'.
  $permissions['create clients_creation content'] = array(
    'name' => 'create clients_creation content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create create_content content'.
  $permissions['create create_content content'] = array(
    'name' => 'create create_content content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create service_creation content'.
  $permissions['create service_creation content'] = array(
    'name' => 'create service_creation content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any client_service_association content'.
  $permissions['delete any client_service_association content'] = array(
    'name' => 'delete any client_service_association content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any clients_creation content'.
  $permissions['delete any clients_creation content'] = array(
    'name' => 'delete any clients_creation content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any create_content content'.
  $permissions['delete any create_content content'] = array(
    'name' => 'delete any create_content content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any service_creation content'.
  $permissions['delete any service_creation content'] = array(
    'name' => 'delete any service_creation content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own client_service_association content'.
  $permissions['delete own client_service_association content'] = array(
    'name' => 'delete own client_service_association content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own clients_creation content'.
  $permissions['delete own clients_creation content'] = array(
    'name' => 'delete own clients_creation content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own create_content content'.
  $permissions['delete own create_content content'] = array(
    'name' => 'delete own create_content content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own service_creation content'.
  $permissions['delete own service_creation content'] = array(
    'name' => 'delete own service_creation content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any client_service_association content'.
  $permissions['edit any client_service_association content'] = array(
    'name' => 'edit any client_service_association content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any clients_creation content'.
  $permissions['edit any clients_creation content'] = array(
    'name' => 'edit any clients_creation content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any create_content content'.
  $permissions['edit any create_content content'] = array(
    'name' => 'edit any create_content content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any service_creation content'.
  $permissions['edit any service_creation content'] = array(
    'name' => 'edit any service_creation content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own client_service_association content'.
  $permissions['edit own client_service_association content'] = array(
    'name' => 'edit own client_service_association content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own clients_creation content'.
  $permissions['edit own clients_creation content'] = array(
    'name' => 'edit own clients_creation content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own create_content content'.
  $permissions['edit own create_content content'] = array(
    'name' => 'edit own create_content content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own service_creation content'.
  $permissions['edit own service_creation content'] = array(
    'name' => 'edit own service_creation content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
