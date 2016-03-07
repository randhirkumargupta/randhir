<?php
/**
 * @file
 * feature_for_breaking_news.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function feature_for_breaking_news_default_rules_configuration() {
  $items = array();
  $items['rules_ask_an_expert_node_update'] = entity_import('rules_config', '{ "rules_ask_an_expert_node_update" : {
      "LABEL" : "Ask an Expert node update",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--ask_an_expert" : { "bundle" : "ask_an_expert" } },
      "DO" : [
        { "mail" : {
            "to" : "[node:field-user-email]",
            "subject" : "[node:title]",
            "message" : "Reply submitted for Your Query please check url answer at  [node:url]",
            "from" : "no-reply@itg.com",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
