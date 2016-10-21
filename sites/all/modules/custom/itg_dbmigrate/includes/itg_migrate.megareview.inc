<?php
//pending

/**
 * ItgMegareviewMigration extends XMLMigration 
 */
class ItgMegareviewMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of content (Mega review)');

    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'movietitle' => t('Movie Title'),
      'megareviewtype' => t('Mega Review Type'),
      'video' => t('Video'),
      'cast' => t('Cast'),
      'director' => t('Director'),
      'movieplot' => t('Movie Plot'),
      'youtubeurl' => t('Youtube Url'),//multi
      'associatevideo' => t('Associate Video'),
      'associatephotogallery' => t('Associate Photo Gallery'),
      'twitterhandletagwidget' => t('Twitter handle & tag (widget)'),
      'associate_photo_gallery' => t('Associate Photo Gallery'),
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
      'reviews' => t('Review'),//Fieldcollection
      'sefurl' => t('Sefurl'),
      'pagetitle' => t('Page title'),
      'description' => t('Description'),
      'keywords' => t('Keywords'),
    );

    
    // This can also be an URL instead of a local file path.
    $file_path = drupal_realpath('public://');
    
    $xml_folder = $file_path . '/' . 'migrate/xml_file/';
    
    $items_url = $xml_folder . 'mega_review_critic.xml';
    
    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/megareviewcritic';
    
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /story/item/id.
    $item_ID_xpath = 'id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('mega_review_critic');

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
    // /categories/category/name).
    $this->addFieldMapping('title', 'movietitle')->xpath('movietitle');
    $this->addFieldMapping('field_mega_review_director', 'director')->xpath('director');
    $this->addFieldMapping('field_mega_review_movie_plot', 'movieplot')->xpath('movieplot');
    $this->addFieldMapping('field_mega_review_youtube_url', 'youtubeurl')->xpath('youtubeurl');
    //$this->addFieldMapping('field_mega_review_video', 'associatevideo')->xpath('associatevideo'); // Video
    $this->addFieldMapping('field_mega_review_photo_gallery', 'associatephotogallery')->xpath('associatephotogallery');
    $this->addFieldMapping('field_mega_review_twitter', 'twitterhandletagwidget')->xpath('twitterhandletagwidget');
    // Image field
    $this->addFieldMapping('field_story_extra_large_image', 'extralargeimage')->xpath('extralargeimage');
    $this->addFieldMapping('field_story_extra_large_image:alt', 'extra_large_alt')->xpath('extra_large_alt');
    $this->addFieldMapping('field_story_extra_large_image:title', 'extra_large_title')->xpath('extra_large_title');
    $this->addFieldMapping('field_story_large_image', 'largeimage')->xpath('largeimage');
    $this->addFieldMapping('field_story_large_image:alt', 'large_alt')->xpath('large_alt');
    $this->addFieldMapping('field_story_large_image:title', 'large_title')->xpath('large_title');
    $this->addFieldMapping('field_story_medium_image', 'mediumimage')->xpath('mediumimage');
    $this->addFieldMapping('field_story_medium_image:alt', 'mediumimage_alt')->xpath('mediumimage_alt');
    $this->addFieldMapping('field_story_medium_image:title', 'mediumimage_title')->xpath('mediumimage_title');
    $this->addFieldMapping('field_story_small_image', 'smallimage')->xpath('smallimage');
    $this->addFieldMapping('field_story_small_image:alt', 'smallimage_alt')->xpath('smallimage_alt');
    $this->addFieldMapping('field_story_small_image:title', 'smallimage_title')->xpath('smallimage_title');
    $this->addFieldMapping('field_story_extra_small_image', 'extrasmallimage')->xpath('extrasmallimage');
    $this->addFieldMapping('field_story_extra_small_image:alt', 'extra_small_alt')->xpath('extra_small_alt');
    $this->addFieldMapping('field_story_extra_small_image:title', 'extra_small_title')->xpath('extra_small_title');   
  }
  
   public function prepareRow($row) {
    // Category migrate
   /* $data_category = '';

    if (isset($row->xml->categories->category) && !empty($row->xml->categories->category)) {
      foreach ($row->xml->categories->category as $final_category) {
        $source_cid = (string) $final_category;
        $orignal_category = get_itg_destination_id('migrate_map_itgcategory', $source_cid);
        $data_category[]['tid'] = $orignal_category;
      }
    }
    $row->category_new = $data_category;

    // Story tags migration
    $data_tags = '';
    if (isset($row->xml->tags->tag) && !empty($row->xml->tags->tag)) {
      foreach ($row->xml->tags->tag as $final_tags) {
        $source_tags = (string) $final_tags;
        $orignal_tag = get_itg_destination_id('migrate_map_itgtags', $source_tags);
        $data_tags[]['tid'] = $orignal_tag;
      }
    }
    $row->tag_new = $data_tags;

    return TRUE; */
  }

  public function prepare($node, stdClass $row) {
    $node->teaser = (string) $row->xml->description;  
    $node->uid = 291;
  }
  
   public function complete($entity, $row) {
    $node = node_load($entity->nid);
    $key = 0;
    
    if (isset($row->xml->reviews->review) && !empty($row->xml->reviews->review)) {
      foreach ($row->xml->reviews->review as $value) {
        $headline = (string) $value->headline;
        $data_reviewer = '';
        if (isset($row->xml->reviews->review->reviewers->reviewer) && !empty($row->xml->reviews->review->reviewers->reviewer)) {
          foreach ($row->xml->reviews->review->reviewers->reviewer as $final_byline) {
            $source_bid = (string) $final_byline;
            $orignal_byline = get_itg_destination_id('migrate_map_itgbyline', $source_bid);
            $data_reviewer[]['target_id'] = $orignal_byline;
          }
        }
        $review_url_link = (string) $value->review_url_link;
        $description = (string) $value->review_description;
        $rating = (string) $value->rating;
        $values = array(
          'field_name' => 'field_mega_review_review',
          'field_buzz_headline' => array(LANGUAGE_NONE => array(array('value' => $headline))),
          'field_story_reporter' => array(LANGUAGE_NONE => $data_reviewer),
          'field_mega_review_url_link' => array(LANGUAGE_NONE => array(array('value' => $review_url_link))),
          'field_mega_review_description' => array(LANGUAGE_NONE => array(array('value' => $description))),
          'field_story_rating' => array(LANGUAGE_NONE => array(array('value' => $rating))),
        );
        $field_collection_item = entity_create('field_collection_item', $values);
        $field_collection_item->setHostEntity('node', $node);
        
        $field_collection_item->save(TRUE);
        
        $node->field_mega_review_review[LANGUAGE_NONE][$key]['value'] = $field_collection_item->item_id;
        $key++;
      }
      field_attach_update('node', $node);
    }
   }

}