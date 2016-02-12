<?php
/**
 * @file
 * feature_for_recipe.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function feature_for_recipe_taxonomy_default_vocabularies() {
  return array(
    'recipe_ailment' => array(
      'name' => 'Ailment',
      'machine_name' => 'recipe_ailment',
      'description' => 'Ailment (e.g. Cancer, Hypertension etc.)',
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
    'recipe_calorie_type' => array(
      'name' => 'Calorie Type',
      'machine_name' => 'recipe_calorie_type',
      'description' => 'Calorie Type (e.g. Medium etc.)',
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
    'recipe_cuisine_type' => array(
      'name' => 'Cuisine Type',
      'machine_name' => 'recipe_cuisine_type',
      'description' => 'Please enter Cuisine Type (Chinese, Thai etc.)',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -9,
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
    'recipe_festivals' => array(
      'name' => 'Festivals',
      'machine_name' => 'recipe_festivals',
      'description' => 'Festivals (e.g. Holi, Christmas etc.)',
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
    'recipe_meal_for' => array(
      'name' => 'Meal For',
      'machine_name' => 'recipe_meal_for',
      'description' => 'No. of people, e.g.1-2, 2-4 etc.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -8,
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
    'recipe_meal_type' => array(
      'name' => 'Meal Type',
      'machine_name' => 'recipe_meal_type',
      'description' => 'Meal Type (e.g. Breakfast, Snacks etc.)',
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
    'recipe_time' => array(
      'name' => 'Time',
      'machine_name' => 'recipe_time',
      'description' => 'Time (e.g.15-30 min, 30 min - 1hr etc.) ',
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
