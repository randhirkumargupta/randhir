<?php

/**
 * ItgBestCollegeMigration extends Migration
 */
class ItgBestCollegeMigration extends Migration {
  public function __construct() {
    parent::__construct();

    //The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns = array(
      0 => array('id_csv', 'id'),
      1 => array('collegeid', 'collegeid'),
      2 => array('collegename', 'collegename'),
      3 => array('city', 'city'),
      4 => array('description', 'description'),
      5 => array('image', 'image'),
      6 => array('websiteurl', 'websiteurl'),
      7 => array('storyids', 'storyids'),
      8 => array('photoids', 'photoids'),
      9 => array('videoids', 'videoids'),
    );

    //The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('Import of page content.');

    //The Source of the import
    $this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/../data/page.csv', $columns, array('delimiter' => ',', 'header_rows' => 1));

    //The destination CCK (boundle)
    $this->destination = new MigrateDestinationNode('page');

    //Source and destination relation for rollbacks
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'id_csv' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'alias' => 'import'
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    //Field ampping
    $this->addFieldMapping('title', 'title_csv');
    $this->addFieldMapping('body', 'body_csv');
  }
}
$this->addFieldMapping('title', 'title')->xpath('title');
