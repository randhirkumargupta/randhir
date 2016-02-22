<?php
/**
 * @file
 * features_supplement_magazine.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function features_supplement_magazine_default_rules_configuration() {
  $items = array();
  $items['rules_magazine_redirect_to_listing_page'] = entity_import('rules_config', '{ "rules_magazine_redirect_to_listing_page" : {
      "LABEL" : "Magazine redirect to listing page",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--magazine" : { "bundle" : "magazine" } },
      "DO" : [ { "redirect" : { "url" : "manage-magazines" } } ]
    }
  }');
  return $items;
}
