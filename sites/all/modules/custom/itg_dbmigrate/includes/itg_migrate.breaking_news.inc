<?php

//$fields complete
//maping pending

/**
 * ItgBreakingNewsMigration extends XMLMigration 
 */
class ItgBreakingNewsMigration extends XMLMigration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of content (breaking_news)');

    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'title' => t('title'),
      'type' => t('type'),
      'activatelivetv' => t('activatelivetv'),
      'content_type' => t('content_type'),
      'content_details' => t('content_details'),
      'shortdescription' => t('shortdescription'),
      'displayon' => t('displayon'),
      'extralargeimage' => t('extralargeimage'),
      'largeimage' => t('largeimage'),
      'mediumimage' => t('mediumimage'),
      'smallimage' => t('smallimage'),
      'extrasmallimage' => t('extrasmallimage'),
      'relatedcontent' => t('relatedcontent'),
      'tags' => t('tags'),
      'categories' => t('categories'),
      'highlights' => t('highlights'),
      'sefurl' => t('Sefurl'),
      'pagetitle' => t('Page title'),
      'description' => t('Description'),
      'keywords' => t('Keywords'),
    );


    // This can also be an URL instead of a local file path.
    $file_path = drupal_realpath('public://');

    $xml_folder = $file_path . '/' . 'migrate/xml_file/';

    $items_url = $xml_folder . 'breaking_news.xml';

    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/data/breaking_news';

    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /story/item/id.
    $item_ID_xpath = 'id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('breaking-news');

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
    $this->addFieldMapping('field_type', 'type')->xpath('type');
    $this->addFieldMapping('field_story_expires', 'activatelivetv')->xpath('activatelivetv');
    $this->addFieldMapping('field_breaking_content_details', 'content_type')->xpath('content_type');
    $this->addFieldMapping('field_label', 'shortdescription')->xpath('shortdescription');
    $this->addFieldMapping('field_display_on', 'displayon')->xpath('displayon');
    //$this->addFieldMapping('field_primary_category', 'primarycategory')->xpath('primarycategory');
    $this->addFieldMapping('field_story_extra_large_image', 'extralargeimage')->xpath('extralargeimage');
    $this->addFieldMapping('field_story_large_image', 'largeimage')->xpath('largeimage');
    $this->addFieldMapping('field_story_medium_image', 'mediumimage')->xpath('mediumimage');
    $this->addFieldMapping('field_story_small_image', 'smallimage')->xpath('smallimage');
    $this->addFieldMapping('field_story_extra_small_image', 'extrasmallimage')->xpath('extrasmallimage');
    $this->addFieldMapping('field_story_kicker_text', 'relatedcontent')->xpath('relatedcontent');

    $this->addFieldMapping('pathauto', 'sefurl')->xpath(t('metatags/sefurl'));
    $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
    $this->addFieldMapping('metatag_description', 'description')->xpath('metatags/description');
    $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/keywords');
  }

  public function prepareRow($row) {
    // Category migrate
    $data_category = '';

    if (isset($row->xml->categories->category) && !empty($row->xml->categories->category)) {
      foreach ($row->xml->categories->category as $final_category) {
        $source_cid = (string) $final_category;
        $orignal_category = get_itg_destination_id($source_cid);
        $data_category[]['tid'] = $orignal_category;
      }
    }
    $row->category_new = $data_category;    
    
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
    
    if (!empty($row->brifcase_new)) {
      $node->field_story_highlights[LANGUAGE_NONE] = $row->brifcase_new;
    }
    if (!empty($row->category_new)) {
      $node->field_story_category[LANGUAGE_NONE] = $row->category_new;
    }
    if (!empty($row->tag_new)) {
      $node->field_story_itg_tags[LANGUAGE_NONE] = $row->tag_new;
    }
    $node->uid = 1;
  }

  public function complete($entity, $row) {
    $node = node_load($entity->nid);
    $key = 0;
    if (isset($row->xml->content_details->details)) {
      foreach ($row->xml->content_details->details as $value) {
        $content_title = (string) $value->content_title;
        $breaking_band = (string) $value->mark_as_breaking_band;
        $notification = (string) $value->notification;
        $mobile_subscribers = (string) $value->mobile_subscribers;
        $breaking_publish_time = (string) $value->breaking_publish_time;
        $breaking_redirection_url = (string) $value->breaking_redirection_url;        
        
        $values = array(
          'field_name' => 'field_breaking_content_details',
          'field_breaking_tile' => array(LANGUAGE_NONE => array(array('value' => $content_title))),
          'field_mark_as_breaking_band' => array(LANGUAGE_NONE => array(array('value' => $breaking_band))),
          'field_notification_' => array(LANGUAGE_NONE => array(array('value' => $notification))),
          'field_mobile_subscribers' => array(LANGUAGE_NONE => array(array('value' => $mobile_subscribers))),
          'field_breaking_publish_time' => array(LANGUAGE_NONE => array(array('value' => $breaking_publish_time))),
          'field_breaking_redirection_url' => array(LANGUAGE_NONE => array(array('value' => $breaking_redirection_url))),
        );
        $field_collection_item = entity_create('field_collection_item', $values);
        $field_collection_item->setHostEntity('node', $node);
        $field_collection_item->save(TRUE);
        $node->field_breaking_content_details[LANGUAGE_NONE][$key]['value'] = $field_collection_item->item_id;
        $key++;
      }
      field_attach_update('node', $node);
    }
  }

}
