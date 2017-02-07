<?php

/**
 * ItgCategoryMigration extends XMLMigration 
 */
class ItgCategoryMigration extends XMLMigration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of terms (category)');

    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'title' => t('title'),
      'name' => t('Category name'),
      'image' => t('image'),
      'section' => t('Parent_id'),
      'description' => t('description'),
      'published' => t('published'),
      'ordering' => t('ordering'),
      'metatitle' => t('metatitle'),
      'metadesc' => t('metadesc'),
      'metakey' => t('metakey'),
      'template_name' => t('template_name'),
      'sef_url' => t('sef_url'),
      'programme_schedule' => t('programme_schedule'),
      'app_description' => t('app_description'),
      'schedule_duration' => t('schedule_duration'),
      'telecasting_time' => t('Telecasting time'),
      'created' => t('created'),
      'content_url' => t('content_url'),
      'content_display_color' => t('content_display_color'),
    );


    // This can also be an URL instead of a local file path.
    $file_path = 'sites/default/files';

    $xml_folder = $file_path . '/' . 'migrate/xml_file/';

    $items_url = $xml_folder . 'categories-master.xml';

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
    $this->map = new MigrateSQLMap($this->machineName, array(
      'id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      )
        ), MigrateDestinationTerm::getKeySchema()
    );

    // TIP: Note that for XML sources, in addition to the source field passed to
    // addFieldMapping (the name under which it will be saved in the data row
    // passed through the migration process) we specify the Xpath used to
    // retrieve the value from the XML.
    // TIP: Note that all xpaths for fields begin at the last element of the
    // item xpath since each item xml chunk is processed individually.
    // (ex. xpath=name is equivalent to a full xpath of
    // /categories/category/name).

    $this->addFieldMapping('field_cm_display_title', 'title')->xpath('title');
    $this->addFieldMapping('name', 'name')->xpath('name');
    $this->addFieldMapping('field_sponser_logo', 'image')->xpath('image');
    $this->addFieldMapping('parent', 'section')->xpath('section');
    $this->addFieldMapping('description', 'description')->xpath('description');
    $this->addFieldMapping('weight', 'ordering')->xpath('ordering');
    $this->addFieldMapping('metatag_title', 'metatitle')->xpath('metatitle');
    $this->addFieldMapping('metatag_description', 'metadesc')->xpath('metadesc');
    $this->addFieldMapping('metatag_keywords', 'metakey')->xpath('metakey');
    $this->addFieldMapping('field_cm_select_template_type', 'template_name')->xpath('template_name');
    //$this->addFieldMapping('pathauto', 'sef_url')->xpath(t('sef_url'));
    $this->addFieldMapping('pathauto')->defaultValue(0);
    $this->addFieldMapping('path', 'sefurl')->xpath('sef_url');
    $this->addFieldMapping('field_user_city', 'programme_schedule')->xpath('programme_schedule');
    $this->addFieldMapping('field_user_name', 'schedule_duration')->xpath('schedule_duration');
    $this->addFieldMapping('field_category_app_description', 'app_description')->xpath('app_description');
    $this->addFieldMapping('field_program_timing_in_days', 'telecasting_time')->xpath('telecasting_time');
    $this->addFieldMapping('field_cm_redirection_url', 'content_url')->xpath('content_url');
    //$this->addFieldMapping('field_category_section_type', 'section_type')->xpath('section_type');
    $this->addFieldMapping('field_cm_category_color', 'content_display_color')->xpath('content_display_color');
    // Redirect
    $this->addFieldMapping('migrate_redirects', 'content_url')->xpath('content_url');
    //<simply_flag>0</simply_flag>(not clear)
    //<params>(not clear)
    //<schedule_duration>(not clear)
    //<telecasting_time>(not clear)
    //<created>(NULL)</created>(not clear)
  }

  public function prepareRow($row) {
    // manage parent id
    if (isset($row->xml->section) && !empty($row->xml->section)) {
      $source_cid = (string) $row->xml->section;
      $orignal_category = get_itg_destination_id('migrate_map_itgsection', $source_cid);
      $row->xml->section = $orignal_category;
      
      //sef url
      $sef_path = itg_db_migrate_term_sef('taxonomy/term/'.$orignal_category);
      $row->xml->sef_url = $sef_path.'/'.$row->xml->sef_url;
    }
    else {
      $row->xml->section = '';
    }
    
    
    if (isset($row->xml->programme_schedule) && !empty($row->xml->programme_schedule)) {
      $program_schedule = (string) $row->xml->programme_schedule;
      $program_data = explode('|', $program_schedule);
      $row->xml->programme_schedule = $program_data[0];
    }
    else {
      $row->xml->programme_schedule = '';
    }
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
