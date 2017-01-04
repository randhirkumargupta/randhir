<?php
/**
 * @file
 * feature_for_budget_predictor.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function feature_for_budget_predictor_taxonomy_default_vocabularies() {
  return array(
    'cheaper_dearer' => array(
      'name' => 'cheaper dearer',
      'machine_name' => 'cheaper_dearer',
      'description' => 'cheaper / dearer for budget',
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
