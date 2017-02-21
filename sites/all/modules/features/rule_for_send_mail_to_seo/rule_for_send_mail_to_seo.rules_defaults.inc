<?php
/**
 * @file
 * rule_for_send_mail_to_seo.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rule_for_send_mail_to_seo_default_rules_configuration() {
  $items = array();
  $items['rules_send_mail_to_seo'] = entity_import('rules_config', '{ "rules_send_mail_to_seo" : {
      "LABEL" : "Send Mail to SEO",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "taxonomy" ],
      "ON" : { "taxonomy_term_insert--category_management" : { "bundle" : "category_management" } },
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "19" : "19" } },
            "subject" : "New Term Added for [term:vocabulary] Vocabulary",
            "message" : "Dear SEO Team,\\r\\n\\r\\nNew term [term:name] added for [term:vocabulary] by [site:current-user]\\r\\nTo see this new Taxonomy Term visit [term:url]",
            "from" : "[site:name]"
          }
        }
      ]
    }
  }');
  return $items;
}
