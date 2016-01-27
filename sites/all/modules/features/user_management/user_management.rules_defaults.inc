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
