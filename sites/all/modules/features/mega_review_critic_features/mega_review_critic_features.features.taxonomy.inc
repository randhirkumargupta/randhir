<?php
/**
 * @file
 * mega_review_critic_features.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function mega_review_critic_features_taxonomy_default_vocabularies() {
  return array(
    'itg_occupation' => array(
      'name' => 'Occupation',
      'machine_name' => 'itg_occupation',
      'description' => 'ITG Occupation',
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
    'mega_review_type' => array(
      'name' => 'Mega Review Type',
      'machine_name' => 'mega_review_type',
      'description' => '(Mega Review Type) - TV , Movie',
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
