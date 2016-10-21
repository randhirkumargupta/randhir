<?php

/**
 * ItgFoodNewsMigration extends XMLMigration 
 */
class ItgFoodNewsMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of content (Food news)');
    
    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'title' => t('title'),
      'longheadline' => t('longheadline'),
      'kicker' => t('kicker'),
      'byline' => t('byline'),
      'description' => t('description'),
      'categories' => t('categories'),
      'primarycategory' => t('primarycategory'),
      'extralargeimage' => t('extralargeimage'),
      'largeimage' => t('largeimage'),
      'smallimage' => t('smallimage'),
      'writersimage' => t('writersimage'),
      'syndication' => t('syndication'),
      'shortheadline' => t('shortheadline'),
      'city' => t('city'),
      'sefurl' => t('Sefurl'),
      'pagetitle' => t('Page title'),
      'description' => t('Description'),
      'keywords' => t('Keywords'),
    );
    
    // This can also be an URL instead of a local file path.
    $file_path = drupal_realpath('public://');
    
    $xml_folder = $file_path . '/' . 'migrate/xml_file/';
    
    $items_url = $xml_folder . 'food_news.xml';
    
    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/data/food_news';
    
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /story/item/id.
    $item_ID_xpath = 'id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('food_news');

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
    
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('field_recipe_long_headline', 'longheadline')->xpath('longheadline');
    $this->addFieldMapping('field_story_kicker_text', 'kicker')->xpath('kicker');
    $this->addFieldMapping('field_story_reporter', 'byline')->xpath('byline');    
    $this->addFieldMapping('body', 'description')->xpath('description');
    $this->addFieldMapping('field_story_syndication', 'syndication')->xpath('syndication');
    $this->addFieldMapping('field_story_short_headline', 'shortheadline')->xpath('shortheadline');
    $this->addFieldMapping('field_stroy_city', 'city')->xpath('city');
    
    // for image
    $this->addFieldMapping('field_story_extra_large_image', 'extralargeimage')->xpath('extralargeimage'); 
    $this->addFieldMapping('field_story_extra_large_image:alt', 'extralargeimage_alt')->xpath('extralargeimage_alt');
    $this->addFieldMapping('field_story_extra_large_image:title', 'extralargeimage_title')->xpath('extralargeimage_title');
    
    $this->addFieldMapping('field_story_large_image', 'largeimage')->xpath('largeimage');
    $this->addFieldMapping('field_story_large_image:alt', 'largeimage_alt')->xpath('largeimage_alt');
    $this->addFieldMapping('field_story_large_image:title', 'largeimage_title')->xpath('largeimage_title');
    
    $this->addFieldMapping('field_story_medium_image', 'mediumimage')->xpath('mediumimage');
    $this->addFieldMapping('field_story_medium_image:alt', 'mediumimage_alt')->xpath('mediumimage_alt');
    $this->addFieldMapping('field_story_medium_image:title', 'mediumimage_title')->xpath('mediumimage_title');
    
    $this->addFieldMapping('field_story_small_image', 'smallimage')->xpath('smallimage');
    $this->addFieldMapping('field_story_small_image:alt', 'smallimage_alt')->xpath('smallimage_alt');
    $this->addFieldMapping('field_story_small_image:title', 'smallimage_title')->xpath('smallimage_title');
    
    $this->addFieldMapping('field_recipe_writer_image', 'writersimage')->xpath('writersimage');
    $this->addFieldMapping('field_recipe_writer_image:alt', 'writersimage_alt')->xpath('writersimage_alt');
    $this->addFieldMapping('field_recipe_writer_image:title', 'writersimage_title')->xpath('writersimage_title');
   
    // meta tags
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
        $orignal_category = get_itg_destination_id('migrate_map_itgcategory', $source_cid);
        $data_category[]['tid'] = $orignal_category;
      }
    }
    
    $row->category_new = $data_category;
    
    //Byline associate with Food news
    $data_byline = '';
    if (isset($row->xml->bylines->byline) && !empty($row->xml->bylines->byline)) {
      foreach ($row->xml->bylines->byline as $final_byline) {
        $source_bid = (string) $final_byline;
        $orignal_byline = get_itg_destination_id('migrate_map_itgbyline', $source_bid);
        $data_byline[]['target_id'] = $orignal_byline;
      }
    }
    
    $row->byline_new = $data_byline;
    
    // Primary category
    if (isset($row->xml->primarycategory) && !empty($row->xml->primarycategory)) {
      $source_cid = (string) $row->xml->primarycategory;
      $orignal_pcategory = get_itg_destination_id('migrate_map_itgcategory', $source_cid);
      $row->xml->primarycategory = $orignal_pcategory;
    }
  }
  
  public function prepare($node, stdClass $row) {
    // for category
    if (!empty($row->category_new)) {
      $node->field_story_category[LANGUAGE_NONE] = $row->category_new;
    }
    
    // for byline
    if (!empty($row->byline_new)) {
      $node->field_story_reporter[LANGUAGE_NONE] = $row->byline_new;
    }
    
    // for city
    $old_city = (string) $row->xml->city;
    $new_city = get_itg_destination_id('migrate_map_itgcity', $old_city);    
    $node->field_stroy_city[LANGUAGE_NONE][]['tid'] = (string) $row->xml->city;
    
    $node->uid = 1;
  }
}