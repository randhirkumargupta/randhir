<?php


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
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('title', 'title')->xpath('title');
   
    
    $this->addFieldMapping('pathauto', 'sefurl')->xpath(t('metatags/sefurl'));
    $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
    $this->addFieldMapping('metatag_description', 'description')->xpath('metatags/description');
    $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/keywords');

  }
}