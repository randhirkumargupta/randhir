<?php
/**
 * @file
 * photogallery.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function photogallery_taxonomy_default_vocabularies() {
  return array(
    'photo_by' => array(
      'name' => 'Photo by',
      'machine_name' => 'photo_by',
      'description' => 'This term is using by photogallery for add photo by.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -7,
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
