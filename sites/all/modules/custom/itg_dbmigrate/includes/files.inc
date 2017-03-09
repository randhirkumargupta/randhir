<?php

/**
 * @file
 * Support for migration from files sources.
 */

/**
 * Implementation of MigrateList, for retrieving a list of IDs to be migrated
 * from a directory listing. Each item is a file, it's ID is the path.
 *
 * DnnMigrateListFiles accepts a single directory and returns just the base name of each file as its ID, instead of the path.
 */
class ItgMigrateListFiles extends MigrateListFiles {
  
  public function __construct($folder) {
    parent::__construct(array($folder), '', '.*');
  }
  
  protected function getIDsFromFiles(array $files) {
    $ids = array();
    foreach ($files as $file) {
      $ids[] = $file->name;
    }
    return array_unique($ids);
  }
  
}