<?php


/**
 * ItgSupplementMigration extends XMLMigration 
 */
class ItgSupplementsMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of content (Supplement)');
    
    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'title' => t('Title'),
      'selectmagazine' => t('Select Magazine'),
      'issue' => t('Issue date'),
      'publish' => t('Publish date'),      
      'sefurl' => t('Sefurl'),
      'pagetitle' => t('Page title'),
      'description' => t('Description'),
      'keywords' => t('Keywords'),
    );
    
    // This can also be an URL instead of a local file path.
    $file_path = 'sites/default/files';
    
    $xml_folder = $file_path . '/' . 'migrate/xml_file/';
    
    $items_url = $xml_folder . 'indiatoday_suppliment_07_16.xml';
    
    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/data/supplement';
    
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /story/item/id.
    $item_ID_xpath = 'id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('supplement');

    // The source ID here is the one retrieved from each data item in the XML
    // file, and used to identify specific items
    $this->map = new MigrateSQLMap($this->machineName,
        
      array(
        'id' => array(
          'type' => 'varchar',
            'length' => 255,
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
    $this->addFieldMapping('field_supp_select_magazine', 'selectmagazine')->xpath('selectmagazine');
    $this->addFieldMapping('field_supp_issue', 'issue')->xpath('issue');
    $this->addFieldMapping('field_supp_publish', 'publish')->xpath('publish');
    $this->addFieldMapping('status', 'publish')->xpath('publish');
    
    $this->addFieldMapping('field_issue_supp_large_image', 'supplement_largecoverimage')->xpath('supplement_largecoverimage');
    $this->addFieldMapping('field_issue_supp_large_image:file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_issue_supp_large_image:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_issue_supp_large_image:alt', 'supplement_largecoverimage_alt')->xpath('supplement_largecoverimage_alt');
    $this->addFieldMapping('field_issue_supp_large_image:title', 'supplement_largecoverimage_title')->xpath('supplement_largecoverimage_title');
    
    
    $this->addFieldMapping('field_issue_supp_small_image', 'supplement_smallcoverimage')->xpath('supplement_smallcoverimage');
    $this->addFieldMapping('field_issue_supp_small_image:file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_issue_supp_small_image:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_issue_supp_small_image:alt', 'supplement_smallcoverimage_alt')->xpath('supplement_smallcoverimage_alt');
    $this->addFieldMapping('field_issue_supp_small_image:title', 'supplement_smallcoverimage_title')->xpath('supplement_smallcoverimage_title');
    
     // source migrated
    $this->addFieldMapping('field_story_source_type')
        ->defaultValue('migrated');
    
    $this->addFieldMapping('pathauto')->defaultValue(0);
    $this->addFieldMapping('path', 'sefurl')->xpath('metatags/sefurl');
    $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
    $this->addFieldMapping('metatag_description', 'metadescription')->xpath('metatags/description');
    $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/keywords');

  }
  
  public function prepareRow($row) {
     if (isset($row->xml->selectmagazine) && !empty($row->xml->selectmagazine)) {
      $row->xml->selectmagazine = 573; // magazine indiatoday by mail
   }
  }
  
  public function prepare($node, stdClass $row) {
    $node->uid = 970; //siteadmin;
  }
}