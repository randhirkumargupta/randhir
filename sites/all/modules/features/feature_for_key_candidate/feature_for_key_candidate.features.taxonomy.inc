<?php
/**
 * @file
 * feature_for_key_candidate.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function feature_for_key_candidate_taxonomy_default_vocabularies() {
  return array(
    'state_managment' => array(
      'name' => 'State Managment',
      'machine_name' => 'state_managment',
      'description' => 'State Managment',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
