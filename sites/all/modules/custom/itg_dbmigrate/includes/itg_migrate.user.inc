<?php

/**
 * ItgUserMigration extends XMLMigration 
 */
class ItgUserMigration extends XMLMigration {
  public $user_consvalue;
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of content (User)');
    $this->user_consvalue = $this->read_folder_xml_user(); // get current folder name
    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'first_name' => t('First name'),
      'last_name' => t('Last name'),
      'username' => t('User name'),
      'email' => t('Email'),
      'password' => t('Password'),
      'block' => t('block'),
      'usertype' => t('role'),
      'registerDate' => t('created'),
      'lastvisitDate' => t('last_access'),
    );

    // This can also be an URL instead of a local file path.
    $file_path = 'sites/default/files';

    $xml_folder = $file_path . '/' . 'migrate/xml_file/migrate_xml/xml_for_migrate/' . $this->user_consvalue . '/';

    $items_url = $xml_folder . 'user-master.xml';

    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/data/row';

    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /story/item/id.
    $item_ID_xpath = 'id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);
    $this->destination = new MigrateDestinationUser(array('md5_passwords' => TRUE));

    // The source ID here is the one retrieved from each data item in the XML
    // file, and used to identify specific items
    $this->map = new MigrateSQLMap($this->machineName, array(
      'id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      )
        ), MigrateDestinationNode::getKeySchema()
    );

    // TIP: Note that for XML sources, in addition to the source field passed to
    // addFieldMapping (the name under which it will be saved in the data row
    // passed through the migration process) we specify the Xpath used to
    // retrieve the value from the XML.
    // TIP: Note that all xpaths for fields begin at the last element of the
    // item xpath since each item xml chunk is processed individually.
    // (ex. xpath=name is equivalent to a full xpath of
    // /categories/category/name)

    $this->addFieldMapping('field_first_name', 'first_name')->xpath('firstname');
    $this->addFieldMapping('field_last_name', 'last_name')->xpath('lastname');
    $this->addFieldMapping('roles', 'usertype')->xpath('usertype')
        ->defaultValue(DRUPAL_AUTHENTICATED_RID);
    $this->addFieldMapping('name', 'username')->dedupe('users', 'name')->xpath('username');
    $this->addFieldMapping('mail', 'email')->xpath('email');
    $this->addFieldMapping('pass', 'password')->xpath('password');
    $this->addFieldMapping('created', 'registerDate')->xpath('registerDate');
    $this->addFieldMapping('access', 'lastvisitDate')->xpath('lastvisitDate');
    $this->addFieldMapping('status', 'block')->xpath('block');

    // for meta tags
    /* $this->addFieldMapping('pathauto', 'sefurl')->xpath(t('metatags/sefurl'));
      $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
      $this->addFieldMapping('metatag_description', 'description')->xpath('metatags/description');
      $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/keywords'); */
  }
  
  public function prepareRow($row) {
    // manage parent id
    if (isset($row->xml->usertype) && !empty($row->xml->usertype)) {
      $row->xml->usertype = 6;
    }
    if(empty($row->xml->lastvisitDate)){
      $row->xml->lastvisitDate = 0;
    }
  }
  
   public function read_folder_xml_user() {
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
    $content = failed_record_xml_id('migrate_map_itguser');
      if(!empty($content)) {
      $params = array(
      'body' => $content,
      'subject' => 'Failed Content in User',
    );
      $mail = drupal_mail('itg_dbmigrate', 'send_mail_failed_content', mail_user_send(), language_default(), $params, 'no-reply@kelltontech.com', TRUE);
    }
  }
}
