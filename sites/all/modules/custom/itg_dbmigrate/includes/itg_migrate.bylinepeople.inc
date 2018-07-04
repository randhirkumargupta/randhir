<?php


/**
 * ItgBylineMigration extends XMLMigration
 */

//http://feeds.intoday.in/migration/byline-master.xml

class ItgBylinePeopleMigration extends XMLMigration {
  public $byline_consvalue;
  public function __construct($arguments) {
  parent::__construct($arguments);
  $this->description = t('XML feed (multi items) of content (Byline)');
   // $this->byline_consvalue = $this->read_folder_xml_byline(); // get current folder name

//die('In');
    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'headline' => t('title'),
      'kicker_image_alt_text' => t('kicker_image_alt_text'),
      'kicker_image' => t('kicker_image'),
      //'byline' => t('byline'),
      'main_text' => t('main_text'),
      'sef_url' => t('sef_url'),
      'created' => t('created'),
      'modified' => t('modified'),
      'metatitle' => t('metatitle'),
      'metakey' => t('metakey'),
      'metadesc' => t('metadesc'),
      'redirectionurl' => t('redirectionurl'),
      //'created_by' => t('created_by'),
      //'id' => t('id'),
    );

    // This can also be an URL instead of a local file path.
    $file_path = 'sites/default/files/';

    $xml_folder = $file_path . '/' . 'migrate_people/';

    $items_url = $xml_folder . 'people-data.xml';


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

    $this->addFieldMapping('title', 'headline')->xpath('headline');
    $this->addFieldMapping('body', 'main_text')->xpath('main_text');
    $this->addFieldMapping('body:format', 'format')->defaultValue('full_html');

    $this->addFieldMapping('field_story_extra_large_image', 'kicker_image')->xpath('kicker_image');
    $this->addFieldMapping('field_story_extra_large_image:preserve_files')->defaultValue(TRUE);

    $this->addFieldMapping('field_story_extra_large_image:alt', 'kicker_image_alt_text')->xpath('kicker_image_alt_text');
    $this->addFieldMapping('field_story_extra_large_image:title','kicker_image_alt_text')->xpath('kicker_image_alt_text');

    $this->addFieldMapping('pathauto')->defaultValue(0);
    $this->addFieldMapping('path', 'sef_url')->xpath('sef_url');

    $this->addFieldMapping('created', 'created')->xpath('created');
    $this->addFieldMapping('changed', 'modified')->xpath('modified');
    $this->addFieldMapping('metatag_title', 'metatitle')->xpath('metatitle');
    $this->addFieldMapping('metatag_description', 'metadesc')->xpath('metadesc');
    $this->addFieldMapping('metatag_keywords', 'metakey')->xpath('metakey');
    $this->addFieldMapping('migrate_redirects', 'redirectionurl')->xpath('redirectionurl');



  }

  public function prepareRow($row) {
    //$row->xml->sef_url =  itg_common_custompath_insert_val((string) $row->xml->headline);
    $existing_filepath = 'http://media2.intoday.in/indiatoday/images/stories/';
    $row->xml->kicker_image = $existing_filepath.$row->xml->kicker_image;
    return true;
  }

  public function prepare($node, stdClass $row) {

    $term_id  = get_itg_variable('occupation_people_termid');
    $node->field_celebrity_pro_occupation[LANGUAGE_NONE][0]['tid'] = $term_id; // fix for people
    $node->field_select_url_type[LANGUAGE_NONE][0]['tid'] = $term_id;
    $node->uid = 1;
    $node->path['alias']=itg_common_custompath_insert_val((string) $row->xml->headline);
    // print_r($node);
    // die;
  }

  public function complete($entity, $row) {
    print (string) $row->xml->id.' - ';
  }

  public function postImport() {
    parent::postImport();
    // mail send if city failed.
    $content = failed_record_xml_id('migrate_map_peoplebyline');
      if(!empty($content)) {
      $params = array(
      'body' => $content,
      'subject' => 'Failed Content in Byline',
    );
      $mail = drupal_mail('itg_dbmigrate', 'send_mail_failed_content', mail_user_send(), language_default(), $params, 'shashi.modanwal@aajtak.com', TRUE);
    }
  }
}
