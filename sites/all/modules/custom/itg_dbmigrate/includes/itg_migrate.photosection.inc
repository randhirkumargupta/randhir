<?php


/**
 * ItgSectionMigration extends XMLMigration 
 */
class ItgPhotoMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of terms (category)');

    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'title' => t('title'),
      'name' => t('Category name'),
      'metatitle' => t('metatitle'),
      'metadesc' => t('metadesc'),
      'metakey' => t('metakey'),
      'template_name' => t('template_name'),
      'sef_url' => t('sef_url'),     
      'published' => t('published'),      
      'ordering' => t('ordering'),      
      'content_url' => t('content_url'), 
    );

    // This can also be an URL instead of a local file path.
    $file_path = drupal_realpath('public://');
    
    $xml_folder = $file_path . '/' . 'migrate/xml_file/';
    
    $items_url = $xml_folder . 'photo_category.xml';
    
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
    $this->destination = new MigrateDestinationTerm('category_management', $destination_options);

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
    
    $this->addFieldMapping('name', 'name')->xpath('name'); 
    $this->addFieldMapping('field_cm_display_title', 'title')->xpath('title');
    $this->addFieldMapping('weight', 'ordering')->xpath('ordering');
    $this->addFieldMapping('metatag_title', 'metatitle')->xpath('metatitle');
    $this->addFieldMapping('metatag_description', 'metadesc')->xpath('metadesc');
    $this->addFieldMapping('metatag_keywords', 'metakey')->xpath('metakey');
    $this->addFieldMapping('pathauto')->defaultValue(0);
    $this->addFieldMapping('path', 'sef_url')->xpath(t('sef_url'));
    $this->addFieldMapping('field_cm_redirection_url', 'content_url')->xpath('content_url');
    // add parent of photo category
    $this->addFieldMapping('parent', 'section_id')->xpath('section_id');
   /* $this->addFieldMapping('field_sponser_logo', 'image')->xpath('image');
    $this->addFieldMapping('description', 'description')->xpath('description');
    $this->addFieldMapping('field_category_section_flag', 'section_flag')->xpath('section_flag'); 
    $this->addFieldMapping('field_cm_select_template_type', 'template_name')->xpath('template_name');
    $this->addFieldMapping('field_cm_select_type', 'content_type')->xpath('content_type');
    $this->addFieldMapping('field_cm_category_banner', 'header_image')->xpath('header_image');
    $this->addFieldMapping('field_cm_category_color', 'content_display_color')->xpath('header_image');
    $this->addFieldMapping('field_category_section_type', 'section_type')->xpath('section_type');*/    
    //<issue_free>0</issue_free> (not clear)
    //$this->addFieldMapping('metatag_abstract', 'nodeword_abstract');    
    //$this->addFieldMapping('metatag_robots', 'nodeword_robots');

  }
   public function prepareRow($row) {
     $term_name = 'Photo';
     $vid = 14;
     $parent_tid = itg_db_migrate_parent_term($term_name, $vid);
     $row->xml->section_id = $parent_tid;
   }
   
  public function complete($entity, $row) {  
    $created = !empty($row->xml->created) ? (string) $row->xml->created : time();
    $status = isset($row->xml->published) ? (string) $row->xml->published : 1;
    db_update('itg_category_manager')
        ->fields(array('created' => $created, 'uid' => 3, 'status' => $status))
        ->condition('tid', $entity->tid, '=')
        ->execute();
    
    
  }
}

 