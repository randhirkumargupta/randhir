<?php
/**
 * @file
 * social_media_integration.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function social_media_integration_default_rules_configuration() {
  $items = array();
  $items['rules_story_social_media_integration'] = entity_import('rules_config', '{ "rules_story_social_media_integration" : {
      "LABEL" : "Story Social Media Integration",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "SMI" ],
      "REQUIRES" : [ "rules", "fb_autopost_entity" ],
      "ON" : {
        "node_insert--story" : { "bundle" : "story" },
        "node_update--story" : { "bundle" : "story" },
        "node_insert--recipe" : { "bundle" : "recipe" },
        "node_update--recipe" : { "bundle" : "recipe" }
      },
      "IF" : [
        { "node_is_published" : { "node" : [ "node" ] } },
        { "NOT data_is_empty" : { "data" : [ "node:field-story-facebook-narrative" ] } },
        { "fb_autopost_entity_rules_condition_valid_access_token" : { "valid_access_token" : "1" } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "facebook_publication",
              "param_type" : "post",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-link" ],
            "value" : [ "node:url" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-message" ],
            "value" : [ "node:field-story-facebook-narrative" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-picture" ],
            "value" : [ "node:field-story-facebook-image:file:url" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-name" ],
            "value" : [ "node:title" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-facebook-caption" ],
            "value" : "I am caption content."
          }
        },
        { "publish_to_facebook" : {
            "USING" : { "publication" : [ "entity-created" ], "pages" : "134823840249879" },
            "PROVIDE" : { "facebook_publication_id" : { "facebook_publication_id" : "Facebook publication returned ID" } }
          }
        },
        { "drupal_message" : { "message" : "Content has been posted to Facebook page." } }
      ]
    }
  }');
  return $items;
}
