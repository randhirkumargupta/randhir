<?php
//working

/**
 * ItgRecipeMigration extends XMLMigration 
 */
class ItgRecipeMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of content (Recipe)');
    
    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'title' => t('Strap headline (Short headline)'),
      'contenttype' => t('contenttype'),
      'audio' => t('audio'),
      'video' => t('video'),
      'foodtype' => t('foodtype'),
      'longheadline' => t('longheadline'),
      'wapheadline' => t('wapheadline'),
      'kicker' => t('kicker'),
      'byline' => t('byline'),
      'courtesy' => t('courtesy'),
      'ingredients' => t('ingredients'),
      'garnishing' => t('garnishing'),
      'cuisinetype' => t('cuisinetype'),
      'mealfor' => t('mealfor'),
      'calorietype' => t('calorietype'),
      'caloriecount' => t('caloriecount'),
      'time' => t('time'),
      'ailment' => t('ailment'),
      'mealtype' => t('mealtype'),
      'festivals' => t('festivals'),
      'description' => t('description'),
      'largeimage' => t('largeimage'),
      'mediumimage' => t('mediumimage'),
      'smallimage' => t('smallimage'),
      'extralargeimage' => t('extralargeimage'),
      'writersimage' => t('writersimage'),
      'clienttitle' => t('clienttitle'),
      'primarycategory' => t('primarycategory'),
      'syndication' => t('syndication'),
      'associatephotogallery' => t('associatephotogallery'),
      'socialmediaintegration' => t('socialmediaintegration'),
      'facebooknarrative' => t('facebooknarrative'),
      'facebookimage' => t('facebookimage'),
      'twitternarrative' => t('twitternarrative'),
      'twitterimage' => t('twitterimage'),
      'facebookvideonarrative' => t('facebookvideonarrative'),
      'facebookvideo' => t('facebookvideo'),
      'twittervideodescription' => t('twittervideodescription'),
      'twittervideo' => t('twittervideo'),
      'sefurl' => t('Sefurl'),
      'pagetitle' => t('Page title'),
      'description' => t('Description'),
      'keywords' => t('Keywords'),
    );
    
    // This can also be an URL instead of a local file path.
    $file_path = drupal_realpath('public://');
    
    $xml_folder = $file_path . '/' . 'migrate/xml_file/';
    
    $items_url = $xml_folder . 'recipe.xml';
    
    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/data/recipe';
    
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /story/item/id.
    $item_ID_xpath = 'id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('recipe');

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
    $this->addFieldMapping('title', 'contenttype')->xpath('contenttype');
    $this->addFieldMapping('title', 'audio')->xpath('audio');
    $this->addFieldMapping('title', 'video')->xpath('video');
    $this->addFieldMapping('title', 'foodtype')->xpath('foodtype');
    $this->addFieldMapping('title', 'longheadline')->xpath('longheadline');
    $this->addFieldMapping('title', 'wapheadline')->xpath('wapheadline');
    $this->addFieldMapping('title', 'kicker')->xpath('kicker');
    $this->addFieldMapping('title', 'byline')->xpath('byline');
    $this->addFieldMapping('title', 'courtesy')->xpath('courtesy');
    $this->addFieldMapping('title', 'ingredients')->xpath('ingredients');
    $this->addFieldMapping('title', 'garnishing')->xpath('garnishing');
    $this->addFieldMapping('title', 'caloriecount')->xpath('caloriecount');
    $this->addFieldMapping('title', 'description')->xpath('description');
    
    // $this->addFieldMapping('title', 'cuisinetype')->xpath('cuisinetype');
    // $this->addFieldMapping('title', 'mealfor')->xpath('mealfor');
    // $this->addFieldMapping('title', 'calorietype')->xpath('calorietype');    
    // $this->addFieldMapping('title', 'time')->xpath('time');
    // $this->addFieldMapping('title', 'ailment')->xpath('ailment');
    // $this->addFieldMapping('title', 'mealtype')->xpath('mealtype');
    // $this->addFieldMapping('title', 'festivals')->xpath('festivals');
    
    
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
    
    $this->addFieldMapping('title', 'clienttitle')->xpath('clienttitle');
    $this->addFieldMapping('title', 'syndication')->xpath('syndication');
    // $this->addFieldMapping('title', 'associatephotogallery')->xpath('associatephotogallery');
    $this->addFieldMapping('title', 'socialmediaintegration')->xpath('socialmediaintegration');
    $this->addFieldMapping('title', 'facebooknarrative')->xpath('facebooknarrative');
    $this->addFieldMapping('title', 'facebookimage')->xpath('facebookimage');
    $this->addFieldMapping('title', 'twitternarrative')->xpath('twitternarrative');
    $this->addFieldMapping('title', 'twitterimage')->xpath('twitterimage');
    $this->addFieldMapping('title', 'facebookvideonarrative')->xpath('facebookvideonarrative');
    $this->addFieldMapping('title', 'facebookvideo')->xpath('facebookvideo');
    $this->addFieldMapping('title', 'twittervideodescription')->xpath('twittervideodescription');
    $this->addFieldMapping('title', 'twittervideo')->xpath('twittervideo');
      
    
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
    
    $node->uid = 1;
  }
}