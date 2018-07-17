<?php


/**
 * ItgBylineMigration extends XMLMigration 
 */

//http://feeds.intoday.in/migration/byline-master.xml

class ItgBylineMigration extends XMLMigration {
  public $byline_consvalue;
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of content (Byline)');
    $this->byline_consvalue = $this->read_folder_xml_byline(); // get current folder name
    
    
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
      'metakeywords' => t('metakeywords'),
      'matadescription' => t('Matadescription'),
      'id' => t('id'),
    );
    
    // This can also be an URL instead of a local file path.
    $file_path = 'sites/default/files';
    
    $xml_folder = $file_path . '/' . 'migrate/xml_file/migrate_xml/xml_for_migrate/' . $this->byline_consvalue . '/';

    $items_url = $xml_folder . 'byline-master.xml';
    
    
    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/data/row';
    
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /story/item/id.
    $item_ID_xpath = 'id';

    //$items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    //$this->source = new MigrateSourceMultiItems($items_class, $fields);
    $this->source = new MigrateSourceXML($items_url, $item_xpath, $item_ID_xpath, $fields);

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
     $this->addFieldMapping('body:format', 'format')
         ->defaultValue('full_html');
    $this->addFieldMapping('pathauto')->defaultValue(0);
    $this->addFieldMapping('path', 'sef_url')->xpath('sef_url');
    $this->addFieldMapping('field_reporter_twitter_handle', 'twitter_id')->xpath('twitter_id');
    $this->addFieldMapping('field_reporter_facebook_id', 'facebook_id')->xpath('facebook_id');    
    $this->addFieldMapping('created', 'created_datetime')->xpath('created_datetime');    
    $this->addFieldMapping('changed', 'modified_datetime')->xpath('modified_datetime');    
    $this->addFieldMapping('status', 'published')->xpath('published');  
    $this->addFieldMapping('field_reporter_profile_type', 'profile_type')->xpath('profile_type');   
    $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
    $this->addFieldMapping('metatag_description', 'description')->xpath('metatags/matadescription');
    $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/metakeywords');
    
  }
  
  public function prepareRow($row) {
      // manage created user
    if (isset($row->xml->created_by) && !empty($row->xml->created_by) && $row->xml->created_by != 0) {
      $created_uid = (string) $row->xml->created_by;
      $orignal_crated_uid = get_itg_destination_id('migrate_map_itguser', $created_uid);
      $row->xml->created_by = $orignal_crated_uid;
    }else {
      $row->xml->created_by = 970; // siteadmin
    } 
    if(empty($row->xml->sef_url)) {
       $row->xml->sef_url =  itg_common_custompath_insert_val((string) $row->xml->author_name);
    }
  }
  
  public function prepare($node, stdClass $row) {
       
    $node->field_celebrity_pro_occupation[LANGUAGE_NONE][0]['tid'] = 285750; // fix for reporter
    $node->uid = $row->xml->created_by;
    // Manage department in byline
    if (!empty((string)$row->xml->company)) {
      $company_value = (string) $row->xml->company;
      $vid = itg_db_migrate_vocab_id('byline_company'); // Company byline vocab
      $company_option_value = itg_db_migrate_parent_term($company_value, $vid);
        if(!empty($company_option_value)){
          $node->field_byline_company[LANGUAGE_NONE][0]['tid'] = $company_option_value;
        }
    }
    if (!empty((string)$row->xml->department)) {
      $department_value = (string) $row->xml->department;
      $vid = itg_db_migrate_vocab_id('byline_department'); // Department byline vacab
      $department_option_value = itg_db_migrate_parent_term($department_value, $vid);
      $row->depart_value = $department_option_value;
        if(!empty($department_option_value)){
          $node->field_byline_department[LANGUAGE_NONE][0]['tid'] = $department_option_value;
        }
    }
    $node->field_old_content_source_id['und'][0]['value'] = 'byline-'. (int) $row->xml->id;
  }
  
  public function complete($entity, $row) {    
    print (string) $row->xml->id.' - ';
   //code for order set
   if (!empty($row->xml->ordering)) {    
     ordering_set_for_byline($entity->nid, $row->xml->ordering);
   }
   
  }
  
   public function read_folder_xml_byline() {
    $path_xml = 'sites/default/files/migrate/xml_file/migrate_xml/xml_for_migrate/';
    $files = scandir($path_xml);
    if ($files[0] == '.') {
      unset($files[0]);
    }
    if ($files[1] == '..') {
      unset($files[1]);
    }
    $result = array_values($files);

    return $result[0];
  }
  
  public function postImport() {
    parent::postImport();
    // mail send if city failed.
    $content = failed_record_xml_id('migrate_map_itgbyline');
      if(!empty($content)) {
      $params = array(
      'body' => $content,
      'subject' => 'Failed Content in Byline',
    );
      $mail = drupal_mail('itg_dbmigrate', 'send_mail_failed_content', mail_user_send(), language_default(), $params, 'no-reply@kelltontech.com', TRUE);
    }
  }
}