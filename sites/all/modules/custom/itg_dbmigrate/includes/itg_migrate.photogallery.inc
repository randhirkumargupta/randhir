<?php
//pending

/**
 * ItgPhotogalleryMigration extends XMLMigration 
 */
class ItgPhotogalleryMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of content (Photogallery)');

    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'title' => t('title'),
      'galleryslug' => t('galleryslug'),
      'featured' => t('featured'),
      'issue_date' => t('issue_date'),
      'extralargeimage' => t('extralargeimage'),
      'extrasmallimage' => t('extrasmallimage'),
      'largeimage' => t('largeimage'),
      'mediumimage' => t('mediumimage'),
      'smallimage' => t('smallimage'),
      'tags' => t('tags'),
      'categories' => t('categories'),
      'primarycategory' => t('primarycategory'),
      'commonaudio' => t('commonaudio'),
      'commonaudiofile' => t('commonaudiofile'),
      'credittoall' => t('credittoall'),
      'creditname' => t('creditname'),
      'gallery' => t('gallery'),
      'photoby' => t('photoby'),
      'tags' => t('tags'),
      'archive' => t('archive'),
      'socialmediaintegration' => t('socialmediaintegration'),
      'facebooknarrative' => t('facebooknarrative'),
      'facebookimage' => t('facebookimage'),
      'facebookvideonarrative' => t('facebookvideonarrative'),
      'facebookvideo' => t('facebookvideo'),
      'twitternarrative' => t('twitternarrative'),
      'twitterimage' => t('twitterimage'),//checkbox
      'twittervideodescription' => t('twittervideodescription'),
      'twittervideo' => t('twittervideo'),
      'timetwitter' => t('timetwitter'),
      'postedbyfacebook' => t('postedbyfacebook'),
      'timefacebook' => t('timefacebook'),
      'postedbyinstagram' => t('postedbyinstagram'),
      'timeinstagram' => t('timeinstagram'),
      'commonbyline' => t('commonbyline'),
      'commonbylinetwitter' => t('commonbylinetwitter'),
      'postedbytwitter' => t('postedbytwitter'),
      'relatedcontent' => t('relatedcontent'),
      'syndication' => t('syndication'),
      'sefurl' => t('Sefurl'),
      'pagetitle' => t('Page title'),
      'description' => t('Description'),
      'keywords' => t('Keywords'),
    );

    
    // This can also be an URL instead of a local file path.
    $file_path = drupal_realpath('public://');
    
    $xml_folder = $file_path . '/' . 'migrate/xml_file/';
    
    $items_url = $xml_folder . 'photogallery.xml';
    
    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/data/photogallery';
    
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /story/item/id.
    $item_ID_xpath = 'id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('photogallery');

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
    $this->addFieldMapping('field_gallery_kicer', 'galleryslug')->xpath('galleryslug');
    $this->addFieldMapping('field_featured', 'featured')->xpath('featured');
    
    // for image
    $this->addFieldMapping('field_story_extra_large_image', 'extralargeimage')->xpath('extralargeimage');
    $this->addFieldMapping('field_story_large_image', 'largeimage')->xpath('largeimage');
    $this->addFieldMapping('field_story_medium_image', 'mediumimage')->xpath('mediumimage');
    $this->addFieldMapping('field_story_small_image', 'smallimage')->xpath('smallimage');
    $this->addFieldMapping('field_story_extra_small_image', 'extrasmallimage')->xpath('extrasmallimage');    
    
    $this->addFieldMapping('field_common_audio', 'commonaudio')->xpath('commonaudio');
    $this->addFieldMapping('field_common_audio_file', 'commonaudiofile')->xpath('commonaudiofile');
    $this->addFieldMapping('field_credit_to_all', 'credittoall')->xpath('credittoall');
    $this->addFieldMapping('field_credit_name', 'creditname')->xpath('creditname');    
    $this->addFieldMapping('field_story_archive', 'archive')->xpath('archive');
    
    $this->addFieldMapping('field_story_courtesy', 'facebooknarrative')->xpath('facebooknarrative');    
    
    
    $this->addFieldMapping('field_story_courtesy', 'facebookimage')->xpath('facebookimage');
    $this->addFieldMapping('field_story_courtesy', 'facebookvideonarrative')->xpath('facebookvideonarrative');
    $this->addFieldMapping('field_story_courtesy', 'facebookvideo')->xpath('facebookvideo');
    $this->addFieldMapping('field_story_courtesy', 'twitternarrative')->xpath('twitternarrative');
    $this->addFieldMapping('field_story_courtesy', 'twitterimage')->xpath('twitterimage');
    $this->addFieldMapping('field_story_courtesy', 'twittervideodescription')->xpath('twittervideodescription');
    $this->addFieldMapping('field_story_courtesy', 'twittervideo')->xpath('twittervideo');
    $this->addFieldMapping('field_story_courtesy', 'timetwitter')->xpath('timetwitter');
    $this->addFieldMapping('field_story_courtesy', 'postedbyfacebook')->xpath('postedbyfacebook');
    $this->addFieldMapping('field_story_courtesy', 'timefacebook')->xpath('timefacebook');
    $this->addFieldMapping('field_story_courtesy', 'postedbyinstagram')->xpath('postedbyinstagram');
    $this->addFieldMapping('field_story_courtesy', 'timeinstagram')->xpath('timeinstagram');
    $this->addFieldMapping('field_story_courtesy', 'commonbyline')->xpath('commonbyline');
    $this->addFieldMapping('field_story_courtesy', 'commonbylinetwitter')->xpath('commonbylinetwitter');
    $this->addFieldMapping('field_story_courtesy', 'postedbytwitter')->xpath('postedbytwitter');
    $this->addFieldMapping('field_story_courtesy', 'relatedcontent')->xpath('relatedcontent');
    $this->addFieldMapping('field_story_courtesy', 'syndication')->xpath('syndication');
    
    
    
    
    //$this->addFieldMapping('parent', 'category_parent')->xpath('category_parent');
    
    /*$this->addFieldMapping('description', 'details');
    $this->addFieldMapping('weight', 'ordering');*/

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
    // End category migrate
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
    // End story tags migration
    
    // Syndication checkbox
    if((string) $row->xml->syndication == 'yes'){
        $row->xml->syndication = 'Yes';
    }
   
    //social media integration checkboxes
    if(isset($row->xml->socialmediaintegration) && !empty($row->xml->socialmediaintegration)){
    foreach($row->xml->socialmediaintegration as $key => $social_option){
      if((string)$social_option->facebook == true){
            $final_social[]['value'] = 'facebook';
      }
      if((string)$social_option->facebook_instant_article == true){
           $final_social[]['value'] = 'facebook_instant_article';
      }
      if((string)$social_option->twitter == true){
            $final_social[]['value'] = 'twitter';
      }      
    }
  }
  $row->final_social_checkbox =  $final_social; 
    
    // Primary category
    if(isset($row->xml->primarycategory) && !empty($row->xml->primarycategory)){
      $source_cid = (string)$row->xml->primarycategory;
      $orignal_pcategory = get_itg_destination_id('migrate_map_itgcategory', $source_cid);
      $row->xml->primarycategory = $orignal_pcategory;
    }
    
    return TRUE;
  }

  public function prepare($node, stdClass $row) {
    $node->teaser = (string) $row->xml->description;
    
    if (!empty($row->category_new)) {
      $node->field_story_category[LANGUAGE_NONE] = $row->category_new;
    }
    if (!empty($row->tag_new)) {
      $node->field_story_itg_tags[LANGUAGE_NONE] = $row->tag_new;
    }
    
    // for byline
    $old_byline = (string) $row->xml->byline;
    $new_byline = get_itg_destination_id('migrate_map_itgbyline', $old_byline);
    $node->field_photo_by[LANGUAGE_NONE][]['target_id'] = $new_byline;
    
    $node->uid = 1;
  }

  public function complete($entity, $row) {
    
  }
}