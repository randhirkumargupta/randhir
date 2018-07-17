<?php

/**
 * ItgCricketliveblog extends XMLMigration 
 */
class ItgCricketliveblog extends XMLMigration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of content (Itg_ cricketliveblog)');

    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'title' => t('title'),
      'constituancy' => t('constituancy'),
      'type' => t('type'),
      'activatelivetv' => t('activatelivetv'),
      'match_id' => t('match_id'),
      'content_details' => t('content_details'),
      'shortdescription' => t('shortdescription'),
      'extralargeimage' => t('extralargeimage'),
      'largeimage' => t('largeimage'),
      'mediumimage' => t('mediumimage'),
      'smallimage' => t('smallimage'),
      'extrasmallimage' => t('extrasmallimage'),
      'tags' => t('tags'),
      'highlights' => t('highlights'),
      'sefurl' => t('sefurl'),
      'pagetitle' => t('Page title'),
      'metadescription' => t('Description'),
      'keywords' => t('Keywords'),
      'createddate' => t('createddate'),
      'modifieddate' => t('modifieddate'),
    );


    // This can also be an URL instead of a local file path.
    // $file_path = drupal_realpath(drupal_get_path('module', 'itg_breaking_news'));
    // $xml_folder = $file_path . '/' . 'migrate/xml_file/';
    // $items_url = $xml_folder . 'cricket_blog.xml';

    $file_path = 'sites/default/files';

    $xml_folder = $file_path . '/' . 'migrate/xml_file/live-blogs/';

    //$items_url = $xml_folder . 'tech_liveblog.xml';
    $items_url = $xml_folder . 'cricket_blog.xml';

    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/Root/data/cricket_live_blog';

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

    $this->addFieldMapping('title', 'title')->xpath('title');
    //$this->addFieldMapping('field_constituancy', 'display_title_landing_page')->xpath('display_title_landing_page');
    $this->addFieldMapping('field_type', 'type')->xpath('type');
    $this->addFieldMapping('field_story_expires', 'activatelivetv')->xpath('activatelivetv');
    //$this->addFieldMapping('field_breaking_content_details', 'content_details')->xpath('content_details');
    $this->addFieldMapping('field_common_short_description', 'shortdescription')->xpath('shortdescription');
    //$this->addFieldMapping('field_primary_category', 'primarycategory')->xpath('primarycategory');

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


    $this->addFieldMapping('created', 'createddate')->xpath('createddate');
    $this->addFieldMapping('changed', 'modifieddate')->xpath('modifieddate');
    $this->addFieldMapping('pathauto')->defaultValue(0);
    $this->addFieldMapping('path', 'sefurl')->xpath(t('metatags/sefurl'));

    $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
    $this->addFieldMapping('metatag_description', 'metadescription')->xpath('metatags/metadescription');
    $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/keywords');
    $this->addFieldMapping('migrate_redirects', 'redirection_url')->xpath('redirection_url');
    $this->addFieldMapping('field_story_source_type')
        ->defaultValue('migrated');
    $this->addFieldMapping('field_story_source_id', 'id')->xpath('id'); // source id
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

    // Match_id migrate
    $row->match_id_new = '';
    if (isset($row->xml->match_id) && !empty($row->xml->match_id)) {
      $match_id = explode('##', $row->xml->match_id);
      $row->match_id_new = $match_id[0];
    }

    // Tags migration
    $data_tags = '';
    if (isset($row->xml->tags->tag) && !empty($row->xml->tags->tag)) {
      foreach ($row->xml->tags->tag as $final_tags) {
        $source_tags = (string) $final_tags;
        $orignal_tag = get_itg_destination_id('migrate_map_itgtags', $source_tags);
        $data_tags[]['tid'] = $orignal_tag;
      }
    }
    $row->tag_new = $data_tags;

    // Brifcase migration
    $data_brifcase = '';
    if (isset($row->xml->highlights->highlight) && !empty($row->xml->highlights->highlight)) {
      foreach ($row->xml->highlights->highlight as $final_briefcase) {
        $source_briefcase = (string) $final_briefcase;
        $data_brifcase[] = $source_briefcase;
      }
    }
    $row->brifcase_new = $data_brifcase;
    
    return TRUE;
  }

  public function prepare($node, stdClass $row) {
    $node->uid = $row->xml->createdby;
    if (!empty($row->brifcase_new)) {
      $node->field_story_highlights[LANGUAGE_NONE] = $row->brifcase_new;
    }
    if (!empty($row->tag_new)) {
      $node->field_story_itg_tags[LANGUAGE_NONE] = $row->tag_new;
    }

    $node->field_story_category[LANGUAGE_NONE][0]['tid'] = '1208836'; // Section
    $node->field_story_category[LANGUAGE_NONE][1]['tid'] = '1208839'; // Category
    $node->field_primary_category[LANGUAGE_NONE][0]['value'] = '1208839'; // primary category
    $node->field_display_on[LANGUAGE_NONE][0]['value'] = 'Section';

    if (!empty($row->match_id_new)) {
      $node->field_match_id[LANGUAGE_NONE][0]['value'] = $row->match_id_new;
    }
    
    $node->field_constituancy[LANGUAGE_NONE][0]['value'] = '';
    $modified_time = (int) $row->xml->modifieddate; // TIme migrate as IST
    $mod_time = $modified_time;
    $modi_time = date('Y-m-d h:i:s', $mod_time);
    $node->field_itg_content_publish_date[LANGUAGE_NONE][0]['value'] = $modi_time;  
  }

  public function complete($entity, $row) {
	$node = node_load($entity->nid);
    $key = 0;
    
    if (isset($row->xml->content_details->details)) {
      foreach ($row->xml->content_details->details as $value) {
        $content_title = (string) $value->content_title;
        //$breaking_band = (string) $value->mark_as_breaking_band;
        $notification = (string) $value->notification;
        //$mobile_subscribers = (string) $value->mobile_subscribers;
        $breaking_publish_time = (string) $value->update_publish_time;
        //$breaking_redirection_url = (string) $value->breaking_redirection_url;

        $values = array(
          'field_name' => 'field_breaking_content_details',
          'field_breaking_tile' => array(LANGUAGE_NONE => array(array('value' => $content_title)))
        );
        $field_collection_item = entity_create('field_collection_item', $values);
        $field_collection_item->setHostEntity('node', $node);
        $field_collection_item->save(TRUE);
        $node->field_breaking_content_details[LANGUAGE_NONE][$key]['value'] = $field_collection_item->item_id;
        $key++;
      }
      field_attach_update('node', $node);
    }
    ordering_set_of_content($node, $row->xml->id);
  }

}
