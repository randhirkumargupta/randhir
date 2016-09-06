<?php
/**
 * @file
 * feature_for_live_tv_integration.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function feature_for_live_tv_integration_taxonomy_default_vocabularies() {
  return array(
    'live_tv' => array(
      'name' => 'Live tv',
      'machine_name' => 'live_tv',
      'description' => 'Live tv',
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
