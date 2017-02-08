<?php


/**
 * ItgCityMigration extends XMLMigration 
 */
class ItgStateMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of terms (city)');

    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'state' => t('state'),
      'country_id' => t('country_id'),
    );

    
    // This can also be an URL instead of a local file path.
    $file_path = 'sites/default/files';
    
    $xml_folder = $file_path . '/' . 'migrate/xml_file/';
    
    $items_url = $xml_folder . 'state_master.xml';
    
    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/data/row';
    
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /categories/category/id.
    $item_ID_xpath = 'id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);
    
    $destination_options = array(
      'allow_duplicate_terms' => TRUE,
    );
    $this->destination = new MigrateDestinationTerm('state', $destination_options);

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
      MigrateDestinationTerm::getKeySchema()
    );
    
    // TIP: Note that for XML sources, in addition to the source field passed to
    // addFieldMapping (the name under which it will be saved in the data row
    // passed through the migration process) we specify the Xpath used to
    // retrieve the value from the XML.
    // TIP: Note that all xpaths for fields begin at the last element of the
    // item xpath since each item xml chunk is processed individually.
    // (ex. xpath=name is equivalent to a full xpath of
    // /categories/category/name).
    
    $this->addFieldMapping('name', 'name')->xpath('state');    
    $this->addFieldMapping('field_state_county', 'country_id')->xpath('country_id');    
    //$this->addFieldMapping('pathauto', 'sef_url')->xpath(t('sef_url'));
//    $this->addFieldMapping('pathauto')->defaultValue(0);
//    $this->addFieldMapping('path', 'sef_url')->xpath('sef_url');
//    $this->addFieldMapping('metatag_title', 'metatitle')->xpath('metatitle');
//    $this->addFieldMapping('metatag_description', 'metadesc')->xpath('metadesc');
//    $this->addFieldMapping('metatag_keywords', 'metakey')->xpath('metakey');


  }
  public function prepareRow($row) {
     $final_term_name = '';
     
    if (isset($row->xml->country_id) && !empty($row->xml->country_id)) {
        $source_tags = (string) $row->xml->country_id;
        $orignal_tag = get_itg_destination_id('migrate_map_itgcountry', $source_tags);
        $final_term_name = itg_db_migrate_term_name($orignal_tag);
    }
    $row->xml->country_id = $final_term_name;
  }
}