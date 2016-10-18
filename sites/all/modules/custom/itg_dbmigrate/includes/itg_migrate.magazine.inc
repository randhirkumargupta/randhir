<?php


/**
 * ItgMagazineMigration extends XMLMigration 
 */
class ItgMagazineMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of content (Magazine)');
    
    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'title' => t('Magazine name'),
      'magazine_issue_date' => t('Magazine issue date'),
      'magazine_publish' => t('Magazine publish'),
      'magazine_cover_photo' => t('Magazine cover photo'),
      'sefurl' => t('Sefurl'),
      'pagetitle' => t('Page title'),
      'description' => t('Description'),
      'keywords' => t('Keywords'),
    );
    
    // This can also be an URL instead of a local file path.
    $file_path = drupal_realpath('public://');
    
    $xml_folder = $file_path . '/' . 'migrate/xml_file/';
    
    $items_url = $xml_folder . 'magazine.xml';
    
    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/data/magazine';
    
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /story/item/id.
    $item_ID_xpath = 'id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('magazine');

    // The source ID here is the one retrieved from each data item in the XML
    // file, and used to identify specific items
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );
    
    // TIP: Note that for XML sources, in addition to the source field passed to
    // addFieldMapping (the name under which it will be saved in the data row
    // passed through the migration process) we specify the Xpath used to
    // retrieve the value from the XML.
    // TIP: Note that all xpaths for fields begin at the last element of the
    // item xpath since each item xml chunk is processed individually.
    // (ex. xpath=name is equivalent to a full xpath of
    // /categories/category/name)
    
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('field_print_magazine_issue_date', 'magazine_issue_date')->xpath('magazine_issue_date');//m/d/Y
    $this->addFieldMapping('field_magazine_publish', 'magazine_publish')->xpath('magazine_publish');    
    $this->addFieldMapping('field_magazine_cover_photo', 'magazine_cover_photo')->xpath('magazine_cover_photo');
    $this->addFieldMapping('field_magazine_cover_photo:alt', 'cover_alt')->xpath('cover_alt');
    $this->addFieldMapping('field_magazine_cover_photo:title', 'cover_title')->xpath('cover_title');
    $this->addFieldMapping('pathauto', 'sefurl')->xpath(t('metatags/sefurl'));
    $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
    $this->addFieldMapping('metatag_description', 'description')->xpath('metatags/description');
    $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/keywords');

  }
  
  /*public function prepareRow($row) {
    if (isset($row->xml->magazine_issue_date) && !empty($row->xml->magazine_issue_date)) {
      $issue_time = (string) $row->xml->magazine_issue_date;
      $issue_date_time = date('d/m/Y H:i', $issue_time);
      $row->xml->magazine_issue_date = $issue_date_time;
    }
    return TRUE;
  }*/
}