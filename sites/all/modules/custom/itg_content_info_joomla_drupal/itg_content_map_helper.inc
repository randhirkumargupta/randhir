<?php

/**
 * Function is used for content type mapping
 * @param string $contenttype
 * @return array
 */
function get_mapping_array($contenttype = 'story') {
  $arr = array(
    'story' => array(
      'table' => 'migrate_map_itgstorylist',
      'type' => 'node',
      'contenttype' => 'story'
    ),
    'video' => array(
      'table' => 'migrate_map_itgvideogallery',
      'type' => 'node',
      'contenttype' => 'videogallery'
    ),
    'photo' => array(
      'table' => 'migrate_map_itgphotogallery',
      'type' => 'node',
      'contenttype' => 'photogallery'
    ),
    'section' => array(
      'table' => 'migrate_map_itgsection',
      'type' => 'taxonomy',
      'contenttype' => 'section',
    ),
    'category' => array(
      'table' => 'migrate_map_itgcategory',
      'type' => 'taxonomy',
      'contenttype' => 'category',
    ),
    'subcategory' => array(
      'table' => 'migrate_map_itgsubcategory',
      'type' => 'taxonomy',
      'contenttype' => 'subcategory',
    ),
    'subsubcategory' => array(
      'table' => 'migrate_map_itgsubsubcategory',
      'type' => 'taxonomy',
      'contenttype' => 'subsubcategory',
    )
  );

  return $arr[$contenttype];
}
