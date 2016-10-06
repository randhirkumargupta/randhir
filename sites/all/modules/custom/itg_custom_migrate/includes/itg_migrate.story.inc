<?php
//$fields complete
//maping pending

/**
 * ItgStoryMigration extends XMLMigration 
 */
class ItgStoryMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of content (story)');

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

    $this->destination = new MigrateDestinationNode('story');

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
    $this->addFieldMapping('field_story_long_head_line', 'story_issue')->xpath('story_issue');
    $this->addFieldMapping('field_story_reporter', 'select_magazine')->xpath('select_magazine');
    
    $this->addFieldMapping('field_story_category', 'select_supplement')->xpath('select_supplement');
    $this->addFieldMapping('field_primary_category', 'issue_date')->xpath('issue_date');
    $this->addFieldMapping('field_story_kicker_text', 'longheadline')->xpath('longheadline');
    $this->addFieldMapping('body', 'byline')->xpath('byline');
    $this->addFieldMapping('field_story_magazine_kicker_text', 'city')->xpath('city');
    $this->addFieldMapping('field_story_magazine_headline', 'categories')->xpath('categories');//multi
    $this->addFieldMapping('field_story_itg_tags', 'primarycategory')->xpath('primarycategory');
    $this->addFieldMapping('field_story_short_headline', 'extralargeimage')->xpath('extralargeimage');
    $this->addFieldMapping('field_story_long_head_line', 'largeimage')->xpath('largeimage');
    $this->addFieldMapping('field_story_rating', 'mediumimage')->xpath('mediumimage');
    $this->addFieldMapping('field_story_new_title', 'smallimage')->xpath('smallimage');
    $this->addFieldMapping('field_story_redirection_url_titl', 'extrasmallimage')->xpath('extrasmallimage');
    $this->addFieldMapping('field_story_courtesy', 'storykicker')->xpath('storykicker');    
    $this->addFieldMapping('field_story_snap_post', 'storybody')->xpath('storybody');
    
    $this->addFieldMapping('field_story_courtesy', 'magazinekicker')->xpath('magazinekicker');
    $this->addFieldMapping('field_story_courtesy', 'magazineheadline')->xpath('magazineheadline');
    $this->addFieldMapping('field_story_courtesy', 'tags')->xpath('tags'); //multi
    $this->addFieldMapping('field_story_courtesy', 'shortheadline')->xpath('shortheadline');
    $this->addFieldMapping('field_story_courtesy', 'storytitle')->xpath('storytitle');
    $this->addFieldMapping('field_story_courtesy', 'storyrating')->xpath('storyrating');
    $this->addFieldMapping('field_story_courtesy', 'newtitle')->xpath('newtitle');
    $this->addFieldMapping('field_story_courtesy', 'redirectionurl')->xpath('redirectionurl');
    $this->addFieldMapping('field_story_courtesy', 'courtesy')->xpath('courtesy');    
    $this->addFieldMapping('field_story_courtesy', 'snappost')->xpath('snappost');
    
    $this->addFieldMapping('field_story_courtesy', 'facebook')->xpath('socialmediaintegration/facebook');
    $this->addFieldMapping('field_story_courtesy', 'facebook_instant_article')->xpath('socialmediaintegration/facebook_instant_article');
    $this->addFieldMapping('field_story_courtesy', 'twitter')->xpath('socialmediaintegration/twitter');
    
    $this->addFieldMapping('field_story_courtesy', 'facebooknarrative')->xpath('facebooknarrative');
    $this->addFieldMapping('field_story_courtesy', 'facebookimage')->xpath('facebookimage');
    $this->addFieldMapping('field_story_courtesy', 'facebookvideonarrative')->xpath('facebookvideonarrative');
    $this->addFieldMapping('field_story_courtesy', 'facebookvideo')->xpath('facebookvideo');
    $this->addFieldMapping('field_story_courtesy', 'twitternarrative')->xpath('twitternarrative');
    $this->addFieldMapping('field_story_courtesy', 'twitterimage')->xpath('twitterimage');
    $this->addFieldMapping('field_story_courtesy', 'twittervideodescription')->xpath('twittervideodescription');
    
    $this->addFieldMapping('field_story_courtesy', 'twittervideo')->xpath('twittervideo');
    $this->addFieldMapping('field_story_courtesy', 'syndication')->xpath('syndication');
    $this->addFieldMapping('field_story_courtesy', 'mediafiles')->xpath('mediafiles');
    $this->addFieldMapping('field_story_courtesy', 'client_title')->xpath('client_title');
    
    $this->addFieldMapping('field_story_courtesy', 'breakingnews')->xpath('configurations/breakingnews');
    $this->addFieldMapping('field_story_courtesy', 'googlestandout')->xpath('configurations/googlestandout');
    $this->addFieldMapping('field_story_courtesy', 'comment')->xpath('configurations/comment');
    $this->addFieldMapping('field_story_courtesy', 'mediumstylecomment')->xpath('configurations/mediumstylecomment');
    $this->addFieldMapping('field_story_courtesy', 'displaylock')->xpath('configurations/displaylock');
    
    $this->addFieldMapping('field_story_courtesy', 'commentquestion')->xpath('commentquestion');
    $this->addFieldMapping('field_story_courtesy', 'featuredname')->xpath('featuredname');
    $this->addFieldMapping('field_story_courtesy', 'relatedcontents')->xpath('relatedcontents');//multi
    $this->addFieldMapping('field_story_courtesy', 'scheduledatetime')->xpath('scheduledatetime');
    $this->addFieldMapping('field_story_courtesy', 'storyexpires')->xpath('storyexpires');
    
    $this->addFieldMapping('field_story_courtesy', 'storyexpirydate')->xpath('storyexpirydate');
    $this->addFieldMapping('field_story_courtesy', 'selectlisticletemplates')->xpath('selectlisticletemplates');
    $this->addFieldMapping('field_story_courtesy', 'listicle_content')->xpath('listicle_content');//multi
    $this->addFieldMapping('field_story_courtesy', 'quotes')->xpath('quotes');//multi
    $this->addFieldMapping('field_story_courtesy', 'factoids_content')->xpath('factoids_content');//multi
    
    $this->addFieldMapping('field_story_courtesy', 'buzz_content')->xpath('buzz_content');//fieldcollection
    $this->addFieldMapping('field_story_courtesy', 'briefcase_content')->xpath('briefcase_content');//multi
    $this->addFieldMapping('field_story_courtesy', 'expertname')->xpath('expertname');
    $this->addFieldMapping('field_story_courtesy', 'expertimage')->xpath('expertimage');
    $this->addFieldMapping('field_story_courtesy', 'expertdescription')->xpath('expertdescription');
    $this->addFieldMapping('field_story_courtesy', 'archive')->xpath('archive');
    $this->addFieldMapping('field_story_courtesy', 'common_by_line_name')->xpath('common_by_line_name');
    $this->addFieldMapping('field_story_courtesy', 'common_by_line_twitter')->xpath('common_by_line_twitter');
    $this->addFieldMapping('field_story_courtesy', 'associatetvdate')->xpath('associatetvdate');
    $this->addFieldMapping('field_story_courtesy', 'associatetvtime')->xpath('associatetvtime');
    
    $this->addFieldMapping('pathauto', 'sefurl')->xpath(t('metatags/sefurl'));
    $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
    $this->addFieldMapping('metatag_description', 'description')->xpath('metatags/description');
    $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/keywords');
    
  }
  
  public function prepareRow($row) {
    //$row->status = $row->xml->publicationName;
    return TRUE;
  }
  
  public function prepare($node, stdClass $row) {
   $node->teaser = (string) $row->xml->description;
  }
  
  public function complete($node, $row) {
    $dst = 'node/' . strval($node->nid);
    $src = '/legacy/' . $row->legacy_id;
    itg_404_redirect_add_src($src, $dst);
  } 
}