<?php
//pending

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
    $this->addFieldMapping('field_story_short_headline', 'longheadline')->xpath('longheadline');
    $this->addFieldMapping('field_story_kicker_text', 'kicker')->xpath('kicker');
    $this->addFieldMapping('field_story_reporter', 'byline')->xpath('byline');    
    $this->addFieldMapping('body', 'description')->xpath('description');
    $this->addFieldMapping('field_story_syndication', 'syndication')->xpath('syndication');
    $this->addFieldMapping('field_story_short_headline', 'shortheadline')->xpath('shortheadline');
    $this->addFieldMapping('field_stroy_city', 'city')->xpath('city');
    
    // for category
    $this->addFieldMapping('field_story_category', 'categories')->xpath('categories/category');
    $this->addFieldMapping('field_primary_category', 'primarycategory')->xpath('primarycategory');
    
    // for image
    $this->addFieldMapping('field_story_extra_large_image', 'extralargeimage')->xpath('extralargeimage');    
    $this->addFieldMapping('field_story_large_image', 'largeimage')->xpath('largeimage');
    $this->addFieldMapping('field_story_medium_image', 'mediumimage')->xpath('mediumimage');
    $this->addFieldMapping('field_story_small_image', 'smallimage')->xpath('smallimage');
    $this->addFieldMapping('field_recipe_writer_image', 'writersimage')->xpath('writersimage');    
   
    // meta tags
    $this->addFieldMapping('pathauto', 'sefurl')->xpath(t('metatags/sefurl'));
    $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
    $this->addFieldMapping('metatag_description', 'description')->xpath('metatags/description');
    $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/keywords');

  }
}