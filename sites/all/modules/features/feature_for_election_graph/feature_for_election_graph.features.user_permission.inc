<?php
/**
 * @file
 * feature_for_election_graph.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_election_graph_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create election_graph_xml content'.
  $permissions['create election_graph_xml content'] = array(
    'name' => 'create election_graph_xml content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any election_graph_xml content'.
  $permissions['delete any election_graph_xml content'] = array(
    'name' => 'delete any election_graph_xml content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own election_graph_xml content'.
  $permissions['delete own election_graph_xml content'] = array(
    'name' => 'delete own election_graph_xml content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any election_graph_xml content'.
  $permissions['edit any election_graph_xml content'] = array(
    'name' => 'edit any election_graph_xml content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own election_graph_xml content'.
  $permissions['edit own election_graph_xml content'] = array(
    'name' => 'edit own election_graph_xml content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
