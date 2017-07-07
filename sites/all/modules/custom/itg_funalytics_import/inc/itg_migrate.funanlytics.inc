<?php

/**
 * ItgFunanlyticsMigration extends XMLMigration 
 */
class ItgFunanlyticsMigration extends XMLMigration {

    public function __construct($arguments) {
        parent::__construct($arguments);
        $this->description = t('XML feed (multi items) of content (itg_funalytics)');

        // "fields" from an XML feed, so we pass an explicit list of source fields
        $fields = array(
          'title' => t('title'),
          'image' => t('image'),
          'state' => t('state'),
          'createddate' => t('createddate'),
          'sefurl' => t('Sefurl'),
          'pagetitle' => t('Page title'),
          'metadescription' => t('Description'),
          'keywords' => t('Keywords'),
        );


        // This can also be an URL instead of a local file path.
       // $file_path = drupal_realpath('public://');
        $file_path = drupal_get_path('module', 'itg_funalytics_import');
        
        $file_path1 = drupal_realpath($file_path);
        $xml_folder = $file_path1 . '/' . 'migrate/xml_file/';
       
        $items_url = $xml_folder . 'itg_funalytics-old.xml';
        // This is the xpath identifying the items to be migrated, relative to the
        // document.
        $item_xpath = '/data/funalytics';

        // This is the xpath relative to the individual items - thus the full xpath
        // of an ID will be /story/item/id.
        $item_ID_xpath = 'id';

        $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
        $this->source = new MigrateSourceMultiItems($items_class, $fields);

        $this->destination = new MigrateDestinationNode('itg_funalytics');

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
        $current_date = date('d-m-y');
        $image_file_path =  'itg_funalytics/' . $current_date;
        $image_upload_path = $file_path . '/' . $image_file_path;
        if (!file_exists($image_upload_path)) {
            drupal_mkdir('public://' . $image_upload_path, 0777, true);
        }
        
        $this->addFieldMapping('title', 'title')->xpath('title');
        $this->addFieldMapping('field_itg_funalytics_image', 'image')->xpath('image');
        $this->addFieldMapping('field_itg_funalytics_image:preserve_files')
            ->defaultValue(TRUE);
        $this->addFieldMapping('field_itg_funalytics_image:destination_dir')
            ->defaultValue('public://' . $image_file_path);
        $this->addFieldMapping('created', 'createddate')->xpath('createddate');
        $this->addFieldMapping('changed', 'createddate')->xpath('createddate');
        $this->addFieldMapping('status', 'state')->xpath('state');
        $this->addFieldMapping('pathauto')->defaultValue(0);
        $this->addFieldMapping('path', 'sefurl')->xpath('metatags/sefurl');
        $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('pagetitle');
        $this->addFieldMapping('metatag_description', 'metadescription')->xpath('metadescription');
        $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('keywords');
        
    }

    public function prepareRow($row) {
        
        // manage created user
        if (isset($row->xml->createdby) && !empty($row->xml->createdby)) {
            $created_uid = (string) $row->xml->createdby;
            $orignal_crated_uid = get_itg_destination_id('migrate_map_itguser', $created_uid);
            if (empty($orignal_crated_uid) || !isset($orignal_crated_uid)) {
                $row->xml->createdby = 1;
            }
            else {
                $row->xml->createdby = $orignal_crated_uid;
            }
        }
        else {
            $row->xml->createdby = 1;
        }
        return TRUE;
    }

    public function prepare($node, stdClass $row) {
        $node->uid = $row->xml->createdby;
    }

}
