<?php

//$fields complete
//maping pending

/**
 * ItgBreakingNewsMigration extends XMLMigration 
 */
class ItgBreakingNewsMigration extends XMLMigration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of content (breaking_news, Live blog, Cricket live blog, news tech live blog)');

    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'type' => t('type'),
      'activatelivetv' => t('activatelivetv'),
      'display_title_landing_page' => t('display_title_landing_page'),
      'title' => t('title'),
      'content_type' => t('content_type'),
      'match_id' => t('match_id'),
      'blog_closed' => t('blog_closed'),
      'content_details' => t('content_details'),
      'shortdescription' => t('shortdescription'),
      //'displayon' => t('displayon'),
      'extralargeimage' => t('extralargeimage'),
      'extra_large_alt' => t('extra_large_alt'),
      'extra_large_title' => t('extra_large_title'),
      'largeimage' => t('largeimage'),
      'large_title' => t('large_title'),
      'large_alt' => t('large_alt'),
      'mediumimage' => t('mediumimage'),
      'mediumimage_alt' => t('mediumimage_alt'),
      'mediumimage_title' => t('mediumimage_title'),
      'smallimage' => t('smallimage'),
      'smallimage_alt' => t('smallimage_alt'),
      'smallimage_title' => t('smallimage_title'),
      'extrasmallimage' => t('extrasmallimage'),
      'extra_small_alt' => t('extra_small_alt'),
      'extra_small_title' => t('extra_small_title'),
      'highlights' => t('highlights'),
      'highlight' => t('highlight'),
      'state' => t('state'),
      'createddate' => t('createddate'),
      'modifieddate' => t('modifieddate'),
      'createdby' => t('createdby'),
      'redirection_url' => t('redirection_url'),
      'sefurl' => t('sefurl'),
      'pagetitle' => t('pagetitle'),
      'metadescription' => t('metadescription'),
      'keywords' => t('keywords'),
    );


    // This can also be an URL instead of a local file path.
    $file_path = 'sites/default/files';

    $xml_folder = $file_path . '/' . 'migrate/xml_file/live-blogs/';

    //$items_url = $xml_folder . 'tech_liveblog.xml';
    $items_url = $xml_folder . 'news_liveblog.xml';

    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/Root/data/breaking_news'; // live blog, news
    //$item_xpath = '/Root/data/cricket_live_blog'; // cricket live blog
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /story/item/id.
    $item_ID_xpath = 'id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('breaking_news');

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
    // /categories/category/name).
    $this->addFieldMapping('field_type', 'type')->xpath('type');
    $this->addFieldMapping('field_story_expires', 'activatelivetv')->xpath('activatelivetv');
    //$this->addFieldMapping('field_constituancy', 'display_title_landing_page')->xpath('display_title_landing_page');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('field_breaking_match_id', 'match_id')->xpath('match_id');
    $this->addFieldMapping('field_breaking_blog_closed', 'blog_closed')->xpath('blog_closed');
    //$this->addFieldMapping('field_common_short_description', 'shortdescription')->xpath('shortdescription');
    $this->addFieldMapping('field_common_short_description', 'shortdescription')->xpath('shortdescription');
    // Image field
    $this->addFieldMapping('field_story_extra_large_image', 'extralargeimage')->xpath('extralargeimage');
    $this->addFieldMapping('field_story_extra_large_image:preserve_files')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_extra_large_image:alt', 'extra_large_alt')->xpath('extra_large_alt');
    $this->addFieldMapping('field_story_extra_large_image:title', 'extra_large_title')->xpath('extra_large_title');
    $this->addFieldMapping('field_story_large_image', 'largeimage')->xpath('largeimage');
    $this->addFieldMapping('field_story_large_image:preserve_files')
        ->defaultValue(TRUE);
    /* $this->addFieldMapping('field_story_large_image:destination_dir')
      ->defaultValue('s3fs-public/dailymotion_video'); */
    $this->addFieldMapping('field_story_large_image:alt', 'large_alt')->xpath('large_alt');
    $this->addFieldMapping('field_story_large_image:title', 'large_title')->xpath('large_title');
    $this->addFieldMapping('field_story_medium_image', 'mediumimage')->xpath('mediumimage');
    $this->addFieldMapping('field_story_medium_image:preserve_files')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_medium_image:alt', 'mediumimage_alt')->xpath('mediumimage_alt');
    $this->addFieldMapping('field_story_medium_image:title', 'mediumimage_title')->xpath('mediumimage_title');
    $this->addFieldMapping('field_story_small_image', 'smallimage')->xpath('smallimage');
    $this->addFieldMapping('field_story_small_image:preserve_files')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_small_image:alt', 'smallimage_alt')->xpath('smallimage_alt');
    $this->addFieldMapping('field_story_small_image:title', 'smallimage_title')->xpath('smallimage_title');
    $this->addFieldMapping('field_story_extra_small_image', 'extrasmallimage')->xpath('extrasmallimage');
    $this->addFieldMapping('field_story_extra_small_image:preserve_files')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_extra_small_image:file_replace')
        ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_story_extra_small_image:alt', 'extra_small_alt')->xpath('extra_small_alt');
    $this->addFieldMapping('field_story_extra_small_image:title', 'extra_small_title')->xpath('extra_small_title');

    $this->addFieldMapping('pathauto')->defaultValue(0);
    $this->addFieldMapping('path', 'sefurl')->xpath('metatags/sefurl'); // add condition for blank sef url

    $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
    $this->addFieldMapping('metatag_description', 'metadescription')->xpath('metatags/metadescription');
    $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/keywords');
    $this->addFieldMapping('status', 'state')->xpath('state');
    $this->addFieldMapping('field_story_highlights', 'highlight')->xpath('highlights/highlight');

    //code for date
    $this->addFieldMapping('created', 'createddate')->xpath('createddate');
    $this->addFieldMapping('uid', 'createdby')->xpath('createdby')
        ->defaultValue(970); //siteadmin
    $this->addFieldMapping('changed', 'modifieddate')->xpath('modifieddate');
    $this->addFieldMapping('migrate_redirects', 'redirection_url')->xpath('redirection_url');
    $this->addFieldMapping('field_story_source_type')
        ->defaultValue('migrated');
    $this->addFieldMapping('field_story_source_id', 'id')->xpath('id'); // source id
    //$this->addFieldMapping('field_itg_content_publish_date', 'modifieddate')->xpath('modifieddate'); // source id
    $this->addUnmigratedDestinations(array(
      'promote',
      'sticky',
      'revision',
      'log',
      'language',
      'tnid',
      'translate',
      'revision_uid',
      'is_new',
    ));
  }

  public function prepareRow($row) {
    // Tags migration
    // tags not provide by itg
    if ((string) $row->xml->type == 'Tech Live Blog') {
      $row->xml->type = 'Live Blog';
    }

    if (empty((string) $row->xml->metatags->sefurl)) {
      $row->xml->metatags->sefurl = itg_common_custompath_insert_val((string) $row->xml->title);
    }
    
    if (empty((int) $row->xml->modifieddate)) {
      $row->xml->modifieddate = (int) $row->xml->createddate;
    }
    // manage created user
    if (isset($row->xml->createdby) && !empty($row->xml->createdby)) {
      $created_uid = (int) $row->xml->createdby;
      $orignal_crated_uid = get_itg_destination_id('migrate_map_itguser', $created_uid);
      $row->xml->createdby = $orignal_crated_uid;
    }
    else {
      $row->xml->createdby = 970; //siteadmin;
    }

    return TRUE;
  }

  public function prepare($node, stdClass $row) {
    // Manually add category Live Blogs (section), News Live Blog (category), Technology Live Blog (category), Cricket Live Blog (category) FROM ITG MAIL  
     $data_category[0]['tid'] = 1208836; // Live Blogs on migration server 
    $primary_category = '';
  /* if ((string) $row->xml->type == 'Live Blog') { // Tech LIve Blog *************
    //$data_category[1]['tid'] = 1208994; //Technology Live Blog (category)
      $data_category[1]['tid'] = 1208837; //Technology Live Blog (category) on migration server
      $primary_category = 1208837;
    }
    else*/if ((string) $row->xml->type == 'Live Blog') {
      $data_category[1]['tid'] = 1208838; //News Live Blog (category)
      $primary_category = 1208838;
    }
    else if ((string) $row->xml->type == 'Cricket Live Blog') {
      $data_category[1]['tid'] = 1208839; //Cricket Live Blog (category)
      $primary_category = 1208839;
    }

    $node->field_story_category[LANGUAGE_NONE] = $data_category; // category for shif marking
    $node->field_primary_category[LANGUAGE_NONE][0]['value'] = $primary_category; // primary category
    $modified_time = (int) $row->xml->modifieddate; // TIme migrate as IST
    $mod_time = $modified_time;
    $modi_time = date('Y-m-d h:i:s', $mod_time);
    $node->field_itg_content_publish_date[LANGUAGE_NONE][0]['value'] = $modi_time;  
}

  public function complete($entity, $row) {
    $node = $entity;
    if (isset($row->xml->content_details->details) && !empty($row->xml->content_details->details)) {
      $key = 0;
      foreach ($row->xml->content_details->details as $value) {
        try {
          $content_title = (string) $value->content_title;
        }
        catch (customException $e) {
          //display custom message
          echo $e->errorMessage();
        }
        // $breaking_band = (string) $value->mark_as_breaking_band; // breaking news field
        $notification_val = (int) $value->notification;
        // $mobile_subscribers = (string) $value->mobile_subscribers; // ITG NOT provided (No data available) field mapping xml
         $breaking_publish_times = (int) $value->update_publish_time; // time make ist
         $breaking_publish_time = date('Y-m-d H:i:s', $breaking_publish_times);
        // $breaking_redirection_url = (string) $value->breaking_redirection_url;  // ITG NOT provided (No data available) field mapping xml

        $values = array(
          'field_name' => 'field_breaking_content_details',
          'field_breaking_tile' => (!empty($content_title)) ? array(LANGUAGE_NONE => array(array('value' => $content_title))) : '',
          //'field_mark_as_breaking_band' => (!empty($breaking_band)) ? array(LANGUAGE_NONE => array(array('value' => $breaking_band))) : '',
          'field_notification_' => (!empty($notification)) ? array(LANGUAGE_NONE => array(array('value' => $notification))) : '',
            //'field_mobile_subscribers' => (!empty($mobile_subscribers)) ? array(LANGUAGE_NONE => array(array('value' => $mobile_subscribers))) : '',
          'field_breaking_publish_time' => (!empty($breaking_publish_time)) ? array(LANGUAGE_NONE => array(array('value' => $breaking_publish_time))) : '',
            //'field_breaking_redirection_url' => (!empty($breaking_redirection_url)) ? array(LANGUAGE_NONE => array(array('value' => $breaking_redirection_url))) : '',
        );

        $field_collection_item = entity_create('field_collection_item', $values);
        $field_collection_item->setHostEntity('node', $node);
        $field_collection_item->save(TRUE);
        $node->field_breaking_content_details[LANGUAGE_NONE][$key]['value'] = $field_collection_item->item_id;
        $key++;
      }
      field_attach_update('node', $node);
    }
    print (string) $row->xml->id . ' - ';
  }

}
