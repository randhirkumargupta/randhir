<?php


/**
 * ItgUserMigration extends XMLMigration 
 */
class ItgUserMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of content (User)');
    
    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'first_name' => t('First name'),
      'last_name' => t('Last name'),
      'mobile_number' => t('Mobile number'),
      'user_picture' => t('User_picture'),
      'role' => t('role'),
      'mark_as_expert' => t('Mark as expert'),
      'section' => t('Section'),
      'user_name' => t('User name'),
      'email' => t('Email'),
      'password' => t('Password'),
      'expiry_date' => t('Expiry date'),
      'dob' => t('DOB'),
      'gender' => t('Gender'),      
      'qualification' => t('Qualification'),
      'pincode' => t('Pincode')
    );
    
    // This can also be an URL instead of a local file path.
    $file_path = drupal_realpath('public://');
    
    $xml_folder = $file_path . '/' . 'migrate/xml_file/';
    
    $items_url = $xml_folder . 'users.xml';
    
    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/users/user_data';
    
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /story/item/id.
    $item_ID_xpath = 'id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationUser();

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
    
    $this->addFieldMapping('field_first_name', 'first_name')->xpath('first_name');
    $this->addFieldMapping('field_last_name', 'last_name')->xpath('last_name');
    $this->addFieldMapping('field_mobile_number', 'mobile_number')->xpath('mobile_number');
    $this->addFieldMapping('field_user_picture', 'user_picture')->xpath('user_picture');
    $this->addFieldMapping('field_user_picture:alt', 'user_picture_alt')->xpath('user_picture_alt');
    $this->addFieldMapping('field_user_picture:title', 'user_picture_title')->xpath('user_picture_title');
    $this->addFieldMapping('roles', 'role')->xpath('role');
    $this->addFieldMapping('field_user_section', 'section')->xpath('section');
    $this->addFieldMapping('name', 'user_name')->dedupe('users', 'name')->xpath('user_name'); 
    $this->addFieldMapping('mail', 'email')->xpath('email');
    $this->addFieldMapping('field_story_expiry_date', 'expiry_date')->xpath('expiry_date');
    $this->addFieldMapping('field_story_issue_date', 'dob')->xpath('dob');
    $this->addFieldMapping('field_user_gender', 'gender')->xpath('gender');
    $this->addFieldMapping('field_user_qualification', 'qualification')->xpath('qualification');
    $this->addFieldMapping('field_user_pincode', 'pincode')->xpath('pincode');
    $this->addFieldMapping('field_short_description', 'description')->xpath('description');
    $this->addFieldMapping('field_mark_as_expert', 'mark_as_expert')->xpath('mark_as_expert');
    // for meta tags
    /*$this->addFieldMapping('pathauto', 'sefurl')->xpath(t('metatags/sefurl'));
    $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
    $this->addFieldMapping('metatag_description', 'description')->xpath('metatags/description');
    $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/keywords');*/

  }  
  
  public function prepareRow($row) {
    // Primary category
//    if (isset($row->xml->section) && !empty($row->xml->section)) {
//      $source_cid = (string) $row->xml->section;
//      $orignal_pcategory = get_itg_destination_id('migrate_map_itgcategory', $source_cid);
//      $row->xml->section = $orignal_pcategory;
//    }
    //$row->xml->section;
  }
  
  public function prepare($account, $row) {
   //$account->roles[32] =  'Migrated User';
    $account->field_user_section[LANGUAGE_NONE][0]['tid'] = (string) $row->xml->section;
    $account->field_user_qualification[LANGUAGE_NONE][0]['tid'] = (string) $row->xml->qualification;
    $account->status = 1;
    watchdog("test shravan", '<pre>'. print_r($account, TRUE) .'</pre>'); 
  }  
  
}