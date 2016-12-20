<?php
/**
 * @file
 * feature_for_photo_and_video_related_content.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function feature_for_photo_and_video_related_content_default_rules_configuration() {
  $items = array();
  $items['rules_send_mail_to_users_on_follow_story'] = entity_import('rules_config', '{ "rules_send_mail_to_users_on_follow_story" : {
      "LABEL" : "send mail to users on follow story",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "itg_ugc" ],
      "ON" : { "node_update" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "story" : "story" } } } }
      ],
      "DO" : [ { "itg_ugc_send_follow_story_content_mail" : { "node" : [ "node" ] } } ]
    }
  }');
  return $items;
}
