<?php
//pending

/**
 * ItgVideogalleryMigration extends XMLMigration 
 */
class ItgVideogalleryMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of content (Videogallery)');

    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'story_issue' => t('story_issue'),
      'select_magazine' => t('select_magazine'),
      'select_supplement' => t('select_supplement'),
      'issue_date' => t('issue_date'),
      'longheadline' => t('longheadline'),
      'byline' => t('byline'),
      'city' => t('city'),
      'categories' => t('categories'),//multi
      'primarycategory' => t('primarycategory'),
      'extralargeimage' => t('extralargeimage'),
      'largeimage' => t('largeimage'),
      'mediumimage' => t('mediumimage'),
      'smallimage' => t('smallimage'),
      'extrasmallimage' => t('extrasmallimage'),
      'storykicker' => t('storykicker'),
      'storybody' => t('storybody'),
      'magazinekicker' => t('magazinekicker'),
      'magazineheadline' => t('magazineheadline'),
      'tags' => t('tags'),//multi
      'shortheadline' => t('shortheadline'),
      'storytitle' => t('storytitle'),
      'storyrating' => t('storyrating'),
      'newtitle' => t('newtitle'),
      'redirectionurl' => t('redirectionurl'),
      'courtesy' => t('courtesy'),
      'snappost' => t('snappost'),
      'socialmediaintegration' => t('socialmediaintegration'),//checkbox
      'facebooknarrative' => t('facebooknarrative'),
      'facebookimage' => t('facebookimage'),
      'facebookvideonarrative' => t('facebookvideonarrative'),
      'facebookvideo' => t('facebookvideo'),
      'twitternarrative' => t('twitternarrative'),
      'twitterimage' => t('twitterimage'),
      'twittervideodescription' => t('twittervideodescription'),
      'twittervideo' => t('twittervideo'),
      'syndication' => t('syndication'),
      'mediafiles' => t('mediafiles'),
      'client_title' => t('client_title'),
      'configurations' => t('configurations'),//checkbox
      'commentquestion' => t('commentquestion'),
      'featuredname' => t('featuredname'), //id
      'relatedcontents' => t('relatedcontents'),//multi
      'scheduledatetime' => t('scheduledatetime'),
      'storyexpires' => t('storyexpires'),
      'storyexpirydate' => t('storyexpirydate'),
      'selectlisticletemplates' => t('selectlisticletemplates'),
      'listicle_content' => t('listicle_content'),//multi
      'quotes' => t('quotes'),//multi
      'factoids_content' => t('factoids_content'),//multi
      'buzz_content' => t('buzz_content'),//fieldcollection
      'briefcase_content' => t('briefcase_content'),//multi
      'expertname' => t('expertname'),
      'expertimage' => t('expertimage'),
      'expertdescription' => t('expertdescription'),
      'archive' => t('archive'),
      'common_by_line_name' => t('common_by_line_name'),
      'common_by_line_twitter' => t('common_by_line_twitter'),
      'associatetvdate' => t('associatetvdate'),
      'associatetvtime' => t('associatetvtime'),
      'sefurl' => t('Sefurl'),
      'pagetitle' => t('Page title'),
      'description' => t('Description'),
      'keywords' => t('Keywords'),
    );

    
    // This can also be an URL instead of a local file path.
    $file_path = drupal_realpath('public://');
    
    $xml_folder = $file_path . '/' . 'migrate/xml_file/';
    
    $items_url = $xml_folder . 'story.xml';
    
    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/story/item';
    
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /story/item/id.
    $item_ID_xpath = 'id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('videogallery');

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
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('field_story_long_head_line', 'longheadline')->xpath('longheadline');
    $this->addFieldMapping('field_story_reporter', 'byline')->xpath('byline');
    
    $this->addFieldMapping('field_story_category', 'categories')->xpath('categories/category');
    $this->addFieldMapping('field_primary_category', 'primarycategory')->xpath('primarycategory');
    $this->addFieldMapping('field_story_kicker_text', 'storykicker')->xpath('storykicker');
    $this->addFieldMapping('body', 'storybody')->xpath('storybody');
    $this->addFieldMapping('field_story_magazine_kicker_text', 'magazinekicker')->xpath('magazinekicker');
    $this->addFieldMapping('field_story_magazine_headline', 'magazineheadline')->xpath('magazineheadline');
    $this->addFieldMapping('field_story_itg_tags', 'tag')->xpath('tags/tag');
    $this->addFieldMapping('field_story_short_headline', 'shortheadline')->xpath('shortheadline');
    $this->addFieldMapping('field_story_long_head_line', 'storytitle')->xpath('storytitle');
    $this->addFieldMapping('field_story_rating', 'storyrating')->xpath('storyrating');
    $this->addFieldMapping('field_story_new_title', 'newtitle')->xpath('newtitle');
    $this->addFieldMapping('field_story_redirection_url_titl', 'redirectionurl')->xpath('redirectionurl');
    $this->addFieldMapping('field_story_courtesy', 'courtesy')->xpath('courtesy');    
    $this->addFieldMapping('field_story_snap_post', 'snappost')->xpath('snappost');
    
    /*$this->addFieldMapping('field_story_courtesy', 'courtesy')->xpath('courtesy');
    $this->addFieldMapping('field_story_courtesy', 'courtesy')->xpath('courtesy');
    $this->addFieldMapping('field_story_courtesy', 'courtesy')->xpath('courtesy');
    $this->addFieldMapping('field_story_courtesy', 'courtesy')->xpath('courtesy');
    $this->addFieldMapping('field_story_courtesy', 'courtesy')->xpath('courtesy');
    $this->addFieldMapping('field_story_courtesy', 'courtesy')->xpath('courtesy');
    $this->addFieldMapping('field_story_courtesy', 'courtesy')->xpath('courtesy');
    $this->addFieldMapping('field_story_courtesy', 'courtesy')->xpath('courtesy');
    $this->addFieldMapping('field_story_courtesy', 'courtesy')->xpath('courtesy');
    */
    
    //$this->addFieldMapping('parent', 'category_parent')->xpath('category_parent');
    
    /*$this->addFieldMapping('description', 'details');
    $this->addFieldMapping('weight', 'ordering');*/

  }
}