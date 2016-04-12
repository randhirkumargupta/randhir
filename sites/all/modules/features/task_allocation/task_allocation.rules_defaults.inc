<?php
/**
 * @file
 * task_allocation.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function task_allocation_default_rules_configuration() {
  $items = array();
  $items['rules_send_email_when_task_assign'] = entity_import('rules_config', '{ "rules_send_email_when_task_assign" : {
      "LABEL" : "Send email when task assign",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--task_idea_allocation_tracking" : { "bundle" : "task_idea_allocation_tracking" } },
      "DO" : [
        { "mail" : {
            "to" : "[node:field_user_mail]",
            "subject" : "New task has been assign to you",
            "message" : "[node:field_add_task_idea]",
            "from" : "demosingh707@gmail.com",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
