<?php


/**
 * ItgBylineMigration extends XMLMigration 
 */

//http://feeds.intoday.in/migration/byline-master.xml

class ItgBylineMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of content (Byline)');
    
    
    
    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'title' => t('title'),
      'reporter_email_id' => t('reporter_email_id'),
      'reporter_twitter_handle' => t('reporter_twitter_handle'),
      'facebook_page' => t('facebook_page'),
      'occupation' => t('occupation'),
      'categories' => t('categories'),
      'picture' => t('picture'),
      'designation' => t('designation'),
      'about' => t('about'),
      'field_reporter_facebook_id' => t('Facebook id'),
      'field_reporter_profile_type' => t('Profile type'),
      'field_reporter_company' => t('company'),
      'field_reporter_department' => t('Department'),
      'sefurl' => t('Sefurl'),
      'pagetitle' => t('Page title'),
      'description' => t('Description'),
      'keywords' => t('Keywords'),
    );
    
    // This can also be an URL instead of a local file path.
    $file_path = drupal_realpath('public://');
    
    $xml_folder = $file_path . '/' . 'migrate/xml_file/';
    
    $items_url = $xml_folder . 'byline.xml';
    
    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/data/row';
    
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /story/item/id.
    $item_ID_xpath = 'id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('reporter');

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
    
    $this->addFieldMapping('title', 'author_name')->xpath('author_name');
    $this->addFieldMapping('field_reporter_email_id', 'author_email')->xpath('author_email');
    $this->addFieldMapping('field_story_extra_large_image', 'profile_image')->xpath('profile_image');
    $this->addFieldMapping('field_story_new_title', 'designation')->xpath('designation');
    $this->addFieldMapping('body', 'full_description')->xpath('full_description');
    $this->addFieldMapping('pathauto', 'sefurl')->xpath(t('metatags/sefurl'));
    $this->addFieldMapping('field_reporter_twitter_handle', 'twitter_id')->xpath('twitter_id');
    $this->addFieldMapping('field_reporter_facebook_id', 'facebook_id')->xpath('facebook_id');    
    $this->addFieldMapping('created', 'created_datetime')->xpath('created_datetime');    
    $this->addFieldMapping('changed', 'modified_datetime')->xpath('modified_datetime');    
    $this->addFieldMapping('status', 'published')->xpath('published');
    
    $this->addFieldMapping('field_reporter_profile_type', 'profile_type')->xpath('profile_type');
    $this->addFieldMapping('field_reporter_company', 'company')->xpath('company');
    $this->addFieldMapping('field_reporter_department', 'department')->xpath('department'); 
    
    //$this->addFieldMapping('uid', 'created_by')->xpath('created_by');
    
    /*$this->addFieldMapping('field_story_expert_name', 'facebook_page')->xpath('facebook_page');
    $this->addFieldMapping('field_celebrity_pro_occupation', 'occupation')->xpath('occupation');
    $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
    $this->addFieldMapping('metatag_description', 'description')->xpath('metatags/description');
    $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/keywords');*/
    
  }
  
  public function prepareRow($row) {
    //$department_array = array('Mail Today Editorial' => 'mail_today_editorial');
  
    //$department = (string) $row->xml->department;
    //$row->department_new = $department_array[$department];
  }
  
  public function prepare($node, stdClass $row) {       
    $node->field_celebrity_pro_occupation[LANGUAGE_NONE][0]['tid'] = 403;
    $node->uid = 1;
  }
  
  public function complete($entity, $row) {    
   //code for order set
   if (!empty($row->xml->ordering)) {    
     ordering_set_for_byline($entity->nid, $row->xml->ordering);
   }
   
  }
}

 