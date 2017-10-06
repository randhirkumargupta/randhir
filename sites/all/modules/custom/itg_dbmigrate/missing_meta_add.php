<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

function missing_meta_add() {
  // The type of entity being edited.
  $entity_type = 'node';
// The ID of the entity being changed.
  $entity_id = 42;
// The revision ID for this entity, leave as NULL to ignore revisioning.
  $revision_id = NULL;
// The language code for this entity.
  $langcode = LANGUAGE_NONE;
// Set the new meta tags. Most meta tags have a 'value' attribute.
  $metatags[$langcode]['title']['value'] = 'PICS: Taimur Ali Khan and Kareena Kapoor at the airport, Kangana promotes Simran';
  $metatags[$langcode]['description']['value'] = 'While Taimur Ali Khan was clicked with mommy Kareena Kapoor at the airport, Kangana Ranaut was seen promoting Simran.';
  $metatags[$langcode]['keyword']['value'] = 'taimur ali khan, kareena kapoor, ranbir kapoor, ranveer singh, kangana ranaut, hrithik roshan';
// Update the meta tags. This also clears the entity's cache.
  metatag_metatags_save($entity_type, $entity_id, $revision_id, $metatags);
}
?>

