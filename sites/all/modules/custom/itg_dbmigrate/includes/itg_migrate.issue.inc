<?php


/**
 * ItgIssueMigration extends XMLMigration 
 */
class ItgIssueMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of content (Issue)');
    
    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'issue_date' => t('Issue date'),
      'magazine' => t('Magazine'),
      'supplement' => t('Supplement'),
      'issue_largecoverimage' => t('Issue large cover image'),
      'issue_smallcoverimage' => t('Issue small cover image'),
      'supplement_largecoverimage' => t('Supplement large cover image'),
      'supplement_smallcoverimage' => t('Supplement small cover image'),
      'sefurl' => t('Sefurl'),
      'pagetitle' => t('Page title'),
      'description' => t('Description'),
      'keywords' => t('Keywords'),
    );
    
    // This can also be an URL instead of a local file path.
    $file_path = 'sites/default/files';
    
    $xml_folder = $file_path . '/' . 'migrate/xml_file/';
    
    $items_url = $xml_folder . 'all_issue.xml';
    
    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/data/issue';
    
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /story/item/id.
    $item_ID_xpath = 'id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('issue');

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
    
    $this->addFieldMapping('title', 'issue_date')->xpath('issue_date');
    $this->addFieldMapping('field_issue_title', 'issue_date')->xpath('issue_date');
    $this->addFieldMapping('field_issue_magazine', 'magazine')->xpath('magazine');
    $this->addFieldMapping('status', 'publish')->xpath('publish');
    
    //$this->addFieldMapping('field_issue_supplement', 'supplement')->xpath('supplement');
    
    $this->addFieldMapping('field_issue_large_cover_image', 'issue_largecoverimage')->xpath('issue_largecoverimage');
    $this->addFieldMapping('field_issue_large_cover_image:file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_issue_large_cover_image:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_issue_large_cover_image:alt', 'issue_largecoverimage_alt')->xpath('issue_largecoverimage_alt');
    $this->addFieldMapping('field_issue_large_cover_image:title', 'issue_largecoverimage_title')->xpath('issue_largecoverimage_title');
    
    
    
    $this->addFieldMapping('field_issue_small_cover_image', 'issue_smallcoverimage')->xpath('issue_smallcoverimage');
    $this->addFieldMapping('field_issue_small_cover_image:file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_issue_small_cover_image:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_issue_small_cover_image:alt', 'issue_smallcoverimage_alt')->xpath('issue_smallcoverimage_alt');
    $this->addFieldMapping('field_issue_small_cover_image:title', 'issue_smallcoverimage_title')->xpath('issue_smallcoverimage_title');
    
    //$this->addFieldMapping('migrate_redirects', 'weburl')->xpath('weburl');
     // source migrated
    $this->addFieldMapping('field_story_source_type')
        ->defaultValue('migrated');
    
    // for meta tags
   $this->addFieldMapping('pathauto')->defaultValue(0);
    $this->addFieldMapping('path', 'sefurl')->xpath('metatags/sefurl');
    $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
    $this->addFieldMapping('metatag_description', 'metadescription')->xpath('metatags/description');
    $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/keywords');

  }  
  
    public function prepareRow($row) {
     if (isset($row->xml->magazine) && !empty($row->xml->magazine)) {
      $row->xml->magazine = 573; // magazine indiatoday by mail
   }
  }
  public function prepare($node, stdClass $row) {    
//    if (isset($row->xml->supplement) && !empty($row->xml->supplement)) {
//      $old_supplement = (string) $row->xml->supplement;
//      $new_supplement = get_itg_destination_id('migrate_map_itgsupplement', $old_supplement);
//      $node->field_issue_supplement[LANGUAGE_NONE][]['target_id'] = $new_supplement;
//    }
    
    $node->uid = 970; //siteadmin;
  }
  public function complete($entity, $row) {
  print $row->xml->id.' ';
    if(!empty($row->xml->weburl)){
      $year = date('Y', (string) $row->xml->issue_date);
      $new_redirect = 'calendar/'.$entity->nid.'/'.$year.'/magazine.html';
      $source = explode('indiatoday.intoday.in/', (string) $row->xml->weburl);
      $redirect = new StdClass();
      redirect_object_prepare($redirect);
      $redirect->source = $source[1];
      $redirect->redirect = $new_redirect;
      redirect_save($redirect);
    }
  }
}