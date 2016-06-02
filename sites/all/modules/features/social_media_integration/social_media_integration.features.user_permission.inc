<?php
/**
 * @file
 * social_media_integration.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function social_media_integration_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer facebook publication types'.
  $permissions['administer facebook publication types'] = array(
    'name' => 'administer facebook publication types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'administer facebook publications'.
  $permissions['administer facebook publications'] = array(
    'name' => 'administer facebook publications',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'administer fb_autopost'.
  $permissions['administer fb_autopost'] = array(
    'name' => 'administer fb_autopost',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fb_autopost',
  );

  // Exported permission: 'administer itg_social_media edit_content settings'.
  $permissions['administer itg_social_media edit_content settings'] = array(
    'name' => 'administer itg_social_media edit_content settings',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'Social Media' => 'Social Media',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_social_media',
  );

  // Exported permission: 'edit any album facebook publication'.
  $permissions['edit any album facebook publication'] = array(
    'name' => 'edit any album facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'edit any event facebook publication'.
  $permissions['edit any event facebook publication'] = array(
    'name' => 'edit any event facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'edit any link facebook publication'.
  $permissions['edit any link facebook publication'] = array(
    'name' => 'edit any link facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'edit any note facebook publication'.
  $permissions['edit any note facebook publication'] = array(
    'name' => 'edit any note facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'edit any photo facebook publication'.
  $permissions['edit any photo facebook publication'] = array(
    'name' => 'edit any photo facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'edit any post facebook publication'.
  $permissions['edit any post facebook publication'] = array(
    'name' => 'edit any post facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'edit any question facebook publication'.
  $permissions['edit any question facebook publication'] = array(
    'name' => 'edit any question facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'edit any status facebook publication'.
  $permissions['edit any status facebook publication'] = array(
    'name' => 'edit any status facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'edit any video facebook publication'.
  $permissions['edit any video facebook publication'] = array(
    'name' => 'edit any video facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'edit own album facebook publication'.
  $permissions['edit own album facebook publication'] = array(
    'name' => 'edit own album facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'edit own event facebook publication'.
  $permissions['edit own event facebook publication'] = array(
    'name' => 'edit own event facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'edit own link facebook publication'.
  $permissions['edit own link facebook publication'] = array(
    'name' => 'edit own link facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'edit own note facebook publication'.
  $permissions['edit own note facebook publication'] = array(
    'name' => 'edit own note facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'edit own photo facebook publication'.
  $permissions['edit own photo facebook publication'] = array(
    'name' => 'edit own photo facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'edit own post facebook publication'.
  $permissions['edit own post facebook publication'] = array(
    'name' => 'edit own post facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'edit own question facebook publication'.
  $permissions['edit own question facebook publication'] = array(
    'name' => 'edit own question facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'edit own status facebook publication'.
  $permissions['edit own status facebook publication'] = array(
    'name' => 'edit own status facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'edit own video facebook publication'.
  $permissions['edit own video facebook publication'] = array(
    'name' => 'edit own video facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'set facebook permissions'.
  $permissions['set facebook permissions'] = array(
    'name' => 'set facebook permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fb_permissions',
  );

  // Exported permission: 'view any album facebook publication'.
  $permissions['view any album facebook publication'] = array(
    'name' => 'view any album facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'view any event facebook publication'.
  $permissions['view any event facebook publication'] = array(
    'name' => 'view any event facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'view any link facebook publication'.
  $permissions['view any link facebook publication'] = array(
    'name' => 'view any link facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'view any note facebook publication'.
  $permissions['view any note facebook publication'] = array(
    'name' => 'view any note facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'view any photo facebook publication'.
  $permissions['view any photo facebook publication'] = array(
    'name' => 'view any photo facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'view any post facebook publication'.
  $permissions['view any post facebook publication'] = array(
    'name' => 'view any post facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'view any question facebook publication'.
  $permissions['view any question facebook publication'] = array(
    'name' => 'view any question facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'view any status facebook publication'.
  $permissions['view any status facebook publication'] = array(
    'name' => 'view any status facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'view any video facebook publication'.
  $permissions['view any video facebook publication'] = array(
    'name' => 'view any video facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'view own album facebook publication'.
  $permissions['view own album facebook publication'] = array(
    'name' => 'view own album facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'view own event facebook publication'.
  $permissions['view own event facebook publication'] = array(
    'name' => 'view own event facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'view own link facebook publication'.
  $permissions['view own link facebook publication'] = array(
    'name' => 'view own link facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'view own note facebook publication'.
  $permissions['view own note facebook publication'] = array(
    'name' => 'view own note facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'view own photo facebook publication'.
  $permissions['view own photo facebook publication'] = array(
    'name' => 'view own photo facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'view own post facebook publication'.
  $permissions['view own post facebook publication'] = array(
    'name' => 'view own post facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'view own question facebook publication'.
  $permissions['view own question facebook publication'] = array(
    'name' => 'view own question facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'view own status facebook publication'.
  $permissions['view own status facebook publication'] = array(
    'name' => 'view own status facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  // Exported permission: 'view own video facebook publication'.
  $permissions['view own video facebook publication'] = array(
    'name' => 'view own video facebook publication',
    'roles' => array(),
    'module' => 'fb_autopost_entity',
  );

  return $permissions;
}
