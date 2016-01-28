<?php
/**
 * @file
 * user_management.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function user_management_default_rules_configuration() {
  $items = array();
  $items['rules_unblock_user'] = entity_import('rules_config', '{ "rules_unblock_user" : {
      "LABEL" : "Unblock user",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "unblock_user" : { "label" : "Unblock Current User", "type" : "user" } },
      "ACTION SET" : [ { "user_unblock" : { "account" : [ "unblock-user" ] } } ]
    }
  }');
  $items['rules_user_logout_redirect'] = entity_import('rules_config', '{ "rules_user_logout_redirect" : {
      "LABEL" : "User Logout Redirect",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_logout" : [] },
      "DO" : [ { "redirect" : { "url" : "user" } } ]
    }
  }');
  $items['rules_user_save_redirect'] = entity_import('rules_config', '{ "rules_user_save_redirect" : {
      "LABEL" : "User Save Redirect",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "DO" : [ { "redirect" : { "url" : "manage-users", "destination" : "1" } } ]
    }
  }');
  return $items;
}
