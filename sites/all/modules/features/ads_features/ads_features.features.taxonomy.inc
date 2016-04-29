<?php
/**
 * @file
 * ads_features.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ads_features_taxonomy_default_vocabularies() {
  return array(
    'ads_content' => array(
      'name' => 'Ads Content',
      'machine_name' => 'ads_content',
      'description' => 'Helps in selecting content',
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
