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
      'author_name' => t('title'),
      'author_email' => t('author_email'),
      'profile_image' => t('profile_image'),
      'designation' => t('designation'),
      'full_description' => t('full_description'),
      'sef_url' => t('sef_url'),
      'twitter_id' => t('twitter_id'),
      'facebook_id' => t('Facebook id'),
      'profile_type' => t('profile_type'),
      'created_datetime' => t('created_datetime'),
      'modified_datetime' => t('modified_datetime'),
      'created_by' => t('created_by'),
      'modified_by' => t('modified_by'),
      'published' => t('published'),
      'ordering' => t('ordering'),
      'company' => t('company'),
      'department' => t('department'),
      'occupation' => t('occupation'),
      'pagetitle' => t('Page title'),
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
    //$this->addFieldMapping('pathauto', 'sef_url')->xpath('sef_url');
    $this->addFieldMapping('pathauto')->defaultValue(0);
    $this->addFieldMapping('path', 'sef_url')->xpath('sef_url');
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
      // manage created user
    if (isset($row->xml->created_by) && !empty($row->xml->created_by)) {
      $created_uid = (string) $row->xml->created_by;
      $orignal_crated_uid = get_itg_destination_id('migrate_map_itguser', $created_uid);
      $row->xml->created_by = $orignal_crated_uid;
    }
    // Manage department in byline
    if (isset($row->xml->department) && !empty($row->xml->department)) {
      $department_value = (string) $row->xml->department;
      $department_option_value = itg_migrate_byline_department($department_value);
      $row->xml->department = $department_option_value;
    }
    
  }
  
  public function prepare($node, stdClass $row) {       
    $node->field_celebrity_pro_occupation[LANGUAGE_NONE][0]['tid'] = 403; // fix for reporter
    $node->uid = $row->xml->created_by;
  }
  
  public function complete($entity, $row) {
    print (string) $row->xml->id.' - ';
   //code for order set
   if (!empty($row->xml->ordering)) {    
     ordering_set_for_byline($entity->nid, $row->xml->ordering);
   }
   
  }
}

 function itg_migrate_byline_department($key){
   $department = array(
     'Mail Today Editorial' => 'mail_today_editorial',
     'Auto Shows - Magazine' => 'auto_shows_magazine',
     'Business Today Editorial' => 'business_today_editorial',
     'Consumer and Personal Finance' => 'consumer_and_personal_finance',
     'Corporate' => 'Corporate',
     'Cosmopolitan' => 'Cosmopolitan',
     'Editorial AT' => 'Editorial_AT',
     'Editorial DAT' => 'Editorial_DAT',
     'Editorial HLT' => 'Editorial_HLT',
     'Editorial India Today TV' => 'editorial_india_today_TV',
     'Editorial TVTN' => 'Editorial_TVTN',
     'Good Housekeeping' => 'good_housekeeping',
     "Harper's Bazaar" => 'harper_s_bazaar',
     "Harper's Bazaar Bride" => 'harper_s_bazaar_bride',
     'Impact' => 'Impact',
     'INDIA TODAY - SUPPLEMENTS' => 'INDIA_TODAY_SUPPLEMENTS',
     'ITE Editorial' => 'ITE_editorial',
     'ITGD - Editorial' => 'ITGD_editorial',
     'ITH Editorial' => 'ITH_editorial',
     'Mail Today S&D' => 'mail_today_S&D',
     "Reader's Digest Editorial" => 'reader_s_digest_editorial',
     'Robb Report Editorial' => 'robb_report_editorial',
     'SIMPLY' => 'simply',
     'Social Media & Content Services' => 'social_media_content_services',
     'Spice' => 'spice',
     'Technology-Development' => 'technology_development',
     'Woman' => 'Woman',
     "Men's Health" => 'men_s_health',
     
     
   );
   return $department[$key];
 }