<?php


/**
 * ItgAstroMigration extends XMLMigration 
 */
class ItgAstroMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of content (Astro)');
    
    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'title' => t('title'),
      'selectfrequency' => t('selectfrequency'),
      'daterange' => t('daterange'),
      'selectprogram' => t('selectprogram'),
      'primarycategory' => t('primarycategory'),
      'panchaangcalendar' => t('panchaangcalendar'),
      'astrotype' => t('astrotype'),
      'zodiacs' => t('zodiacs'),
      'numerologyvalues' => t('numerologyvalues'),
      'collectivetextforallzodiacsigns' => t('collectivetextforallzodiacsigns'),
      'videothumbnail' => t('videothumbnail'),
      'collectivevideoforallzodiacsigns' => t('collectivevideoforallzodiacsigns'),
      'collectiveaudioforallzodiacsigns' => t('collectiveaudioforallzodiacsigns'),
      'day' => t('day'),
      'sefurl' => t('Sefurl'),
      'pagetitle' => t('Page title'),
      'description' => t('Description'),
      'keywords' => t('Keywords'),
    );
    
    // This can also be an URL instead of a local file path.
    $file_path = drupal_realpath('public://');
    
    $xml_folder = $file_path . '/' . 'migrate/xml_file/';
    
    $items_url = $xml_folder . 'astro.xml';
    
    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/data/astro';
    
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /story/item/id.
    $item_ID_xpath = 'id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('astro');

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
    
    $this->addFieldMapping('title', 'title')->xpath('title');//m/d/Y
    $this->addFieldMapping('field_print_magazine_issue_date', 'selectfrequency')->xpath('selectfrequency');
    $this->addFieldMapping('field_magazine_publish', 'daterange')->xpath('daterange');//m/d/Y    
    //$this->addFieldMapping('field_magazine_cover_photo', 'primarycategory')->xpath('primarycategory');
    $this->addFieldMapping('field_magazine_cover_photo', 'panchaangcalendar')->xpath('panchaangcalendar');
    $this->addFieldMapping('field_magazine_cover_photo', 'collectivetextforallzodiacsigns')->xpath('collectivetextforallzodiacsigns');
    $this->addFieldMapping('field_magazine_cover_photo', 'videothumbnail')->xpath('videothumbnail');
    $this->addFieldMapping('field_magazine_cover_photo', 'collectivevideoforallzodiacsigns')->xpath('collectivevideoforallzodiacsigns');
    $this->addFieldMapping('field_magazine_cover_photo', 'collectiveaudioforallzodiacsigns')->xpath('collectiveaudioforallzodiacsigns');
    $this->addFieldMapping('field_magazine_cover_photo', 'day')->xpath('day');
    
    $this->addFieldMapping('pathauto', 'sefurl')->xpath(t('metatags/sefurl'));
    $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
    $this->addFieldMapping('metatag_description', 'description')->xpath('metatags/description');
    $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/keywords');

  }
  
  public function prepareRow($row) {
    // Category migrate
    $data_category = '';

    if (isset($row->xml->selectprogram->category) && !empty($row->xml->selectprogram->category)) {
      foreach ($row->xml->selectprogram->category as $final_category) {
        $source_cid = (string) $final_category;
        $orignal_category = get_itg_destination_id('migrate_map_itgcategory', $source_cid);
        $data_category[]['tid'] = $orignal_category;
      }
    }
    $row->category_new = $data_category;
    
    return TRUE;
  }

  public function prepare($node, stdClass $row) {
    
    if (!empty($row->category_new)) {
      $node->field_story_category[LANGUAGE_NONE] = $row->category_new;
    }
    
    $node->uid = 1;
  }

  public function complete($entity, $row) {
    $node = node_load($entity->nid);
    $key = 0;
    if (isset($row->xml->zodiacs->zodiac)) {
      foreach ($row->xml->zodiacs->zodiac as $value) {
        $zodiacsignname = (string) $value->zodiacsignname;
       // $zodiacsign = (string) $value->zodiacsign;//
        $text = (string) $value->text;
        //$thumb_icon = (string) $value->thumb_icon;
        $audio = (string) $value->audio;
        $video = (string) $value->video;        
        
        $values = array(
          'field_name' => 'field_astro_zodiac',
          'field_astro_zodiac_sign_name' => array(LANGUAGE_NONE => array(array('value' => $zodiacsignname))),
          'field_buzz_description' => array(LANGUAGE_NONE => array(array('value' => $text))),
          'field_audio' => array(LANGUAGE_NONE => array(array('value' => $audio))),
          'field_astro_video' => array(LANGUAGE_NONE => array(array('value' => $video))),
          //'field_zodiac_sign' => array(LANGUAGE_NONE => array(array('value' => $zodiacsign))),          
        );
        $field_collection_item = entity_create('field_collection_item', $values);
        $field_collection_item->setHostEntity('node', $node);
        $field_collection_item->save(TRUE);
        $node->field_breaking_content_details[LANGUAGE_NONE][$key]['value'] = $field_collection_item->item_id;
        $key++;
      }
      //field_attach_update('node', $node);
    }
    
    if (isset($row->xml->numerologyvalues->numerologyvalue)) {
      foreach ($row->xml->numerologyvalues->numerologyvalue as $value) {
        //$selectnumber = (string) $value->selectnumber;      
        $entertext = (string) $value->entertext;        
        $audio1 = (string) $value->audio;
        $video1 = (string) $value->video;        
        
        $values = array(
          'field_name' => 'field_astro_numerology_values',
          //'field_astro_select_number' => array(LANGUAGE_NONE => array(array('value' => $selectnumber))),
          'field_buzz_description' => array(LANGUAGE_NONE => array(array('value' => $entertext))),
          'field_common_audio_file' => array(LANGUAGE_NONE => array(array('value' => $audio1))),
          'field_astro_video' => array(LANGUAGE_NONE => array(array('value' => $video1))),
        );
        $field_collection_item = entity_create('field_collection_item', $values);
        $field_collection_item->setHostEntity('node', $node);
        $field_collection_item->save(TRUE);
        $node->field_breaking_content_details[LANGUAGE_NONE][$key]['value'] = $field_collection_item->item_id;
        $key++;
      }      
    }
    
    field_attach_update('node', $node);
  }
}