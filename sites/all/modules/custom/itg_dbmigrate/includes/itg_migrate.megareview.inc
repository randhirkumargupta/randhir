<?php
//pending

/**
 * ItgVideogalleryMigration extends XMLMigration 
 */
class ItgMegareviewMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('XML feed (multi items) of content (Videogallery)');

    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'long_headline' => t('longheadline'),
      'shortheadline' => t('shortheadline'),
      'video' => t('Video'),
      'city' => t('city'),
      'courtesy' => t('courtesy'),
      'anchor' => t('anchor'),
      'categories' => t('categories'),//multi
      'primarycategory' => t('primarycategory'),
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
      'tags' => t('tags'),//multi
      'courtesy' => t('courtesy'),
      'socialmediaintegration' => t('socialmediaintegration'),//checkbox
      'facebooknarrative' => t('facebooknarrative'),
      'facebookimage' => t('facebookimage'),
      'facebookimage_alt' => t('facebookimage_alt'),
      'facebookimage_title' => t('facebookimage_title'),
      'twitternarrative' => t('twitternarrative'),
      'twitterimage' => t('twitterimage'),
      'twitterimage_alt' => t('twitterimage_alt'),
      'twitterimage_title' => t('twitterimage_title'),
      'shortdescription' => t('shortdescription'),
      'longdescription' => t('longdescription'),
      'syndication' => t('syndication'),
      'archive' => t('archive'),
      'video_duration' => t('video_duration'),
      'primarycategory' => t('primarycategory'),
      'configurations' => t('configurations'),//checkbox
      'commentquestion' => t('commentquestion'),
      'relatedcontents' => t('relatedcontents'),//multi
      'expirydate' => t('expirydate'),
      'scheduledatetime' => t('scheduledatetime'),
      'sefurl' => t('Sefurl'),
      'pagetitle' => t('Page title'),
      'description' => t('Description'),
      'keywords' => t('Keywords'),
    );

    
    // This can also be an URL instead of a local file path.
    $file_path = drupal_realpath('public://');
    
    $xml_folder = $file_path . '/' . 'migrate/xml_file/';
    
    $items_url = $xml_folder . 'videogallery.xml';
    
    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/videogallery';
    
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
    $this->addFieldMapping('title', 'long_headline')->xpath('long_headline');
    $this->addFieldMapping('field_story_short_headline', 'shortheadline')->xpath('shortheadline');
    //$this->addFieldMapping('field_story_reporter', 'byline')->xpath('byline');
    // Byline mapped in prepare
    $this->addFieldMapping('field_stroy_city', 'city')->xpath('city');
    $this->addFieldMapping('field_story_courtesy', 'courtesy')->xpath('courtesy');
    $this->addFieldMapping('field_video_anchor', 'anchor')->xpath('anchor');
    // configuration mapped in prepare
    $this->addFieldMapping('field_story_comment_question', 'commentquestion')->xpath('commentquestion');
    $this->addFieldMapping('field_story_schedule_date_time', 'scheduledatetime')->xpath('scheduledatetime');
    $this->addFieldMapping('field_story_expiry_date', 'expirydate')->xpath('expirydate');
    $this->addFieldMapping('field_story_expires', 'videoexpires')->xpath('videoexpires');
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
    
    // Tags mapped in prepare
    // Social media integration mapped in prepare
    
    // Facebook and twitter image
    $this->addFieldMapping('field_story_facebook_narrative', 'facebooknarrative')->xpath('facebooknarrative');
    $this->addFieldMapping('field_story_facebook_image', 'facebookimage')->xpath('facebookimage');
    $this->addFieldMapping('field_story_facebook_image:alt', 'facebookimage_alt')->xpath('facebookimage_alt');
    $this->addFieldMapping('field_story_facebook_image:title', 'facebookimage_title')->xpath('facebookimage_title');
    $this->addFieldMapping('field_story_tweet', 'twitternarrative')->xpath('twitternarrative');
    $this->addFieldMapping('field_story_tweet_image', 'twitterimage')->xpath('twitterimage');
    $this->addFieldMapping('field_story_tweet_image:alt', 'twitterimage_alt')->xpath('twitterimage_alt');
    $this->addFieldMapping('field_story_tweet_image:title', 'twitterimage_title')->xpath('twitterimage_title');
    
    // Video migrate
    // $this->addFieldMapping('field_upload_video', 'video')->xpath('video');
   
    $this->addFieldMapping('field_story_expert_name', 'shortdescription')->xpath('shortdescription');
    $this->addFieldMapping('field_story_expert_description', 'longdescription')->xpath('longdescription');
    
    // Section mapped in prepare
    
    $this->addFieldMapping('field_story_syndication', 'syndication')->xpath('syndication');
    
    // Dailymotion playlist pending only one category save
    
    $this->addFieldMapping('field_story_archive', 'archive')->xpath('archive');
    
    //video duration
    $this->addFieldMapping('field_video_duration', 'video_duration')->xpath('video_duration');
    $this->addFieldMapping('field_primary_category', 'primarycategory')->xpath('primarycategory');
    $this->addFieldMapping('field_common_related_content', 'relatedcontent')->xpath('relatedcontent');
    
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

    //social media integration checkboxes
    if (isset($row->xml->socialmediaintegration) && !empty($row->xml->socialmediaintegration)) {
      foreach ($row->xml->socialmediaintegration as $key => $social_option) {
        if ((string) $social_option->facebook == true) {
          $final_social[]['value'] = 'facebook';
        }
        if ((string) $social_option->facebook_instant_article == true) {
          $final_social[]['value'] = 'facebook_instant_article';
        }
        if ((string) $social_option->twitter == true) {
          $final_social[]['value'] = 'twitter';
        }
      }
    }
    $row->final_social_checkbox = $final_social;
    // Configuration settings

    if (isset($row->xml->configurations) && !empty($row->xml->configurations)) {
      foreach ($row->xml->configurations as $key => $option) {
        if ((string) $option->googlestandout == true) {
          $final_option[]['value'] = 'google_standout';
        }
        if ((string) $option->comment == true) {
          $final_option[]['value'] = 'comment';
        }
      }
    }
    $row->final_config_option = $final_option;

    // Primary category
    if (isset($row->xml->primarycategory) && !empty($row->xml->primarycategory)) {
      $source_cid = (string) $row->xml->primarycategory;
      $orignal_pcategory = get_itg_destination_id('migrate_map_itgcategory', $source_cid);
      $row->xml->primarycategory = $orignal_pcategory;
    }

    // Videogallery Date
    if (isset($row->xml->storyexpirydate) && !empty($row->xml->storyexpirydate)) {
      $expire_time = (string) $row->xml->storyexpirydate;
      $expire_date_time = date('m/d/Y H:i', $expire_time);
      $row->xml->storyexpirydate = $expire_date_time;
    }
    if (isset($row->xml->scheduledatetime) && !empty($row->xml->scheduledatetime)) {
      $schedule_time = (string) $row->xml->scheduledatetime;
      $schedule_date_time = date('m/d/Y H:i', $schedule_time);
      $row->xml->scheduledatetime = $schedule_date_time;
    }
    
    //Byline associate with story
    $data_byline = '';
    if (isset($row->xml->bylines->byline) && !empty($row->xml->bylines->byline)) {
      foreach ($row->xml->bylines->byline as $final_byline) {
        $source_bid = (string) $final_byline;
        $orignal_byline = get_itg_destination_id('migrate_map_itgbyline', $source_bid);
        $data_byline[]['target_id'] = $orignal_byline;
      }
    }
    $row->byline_new = $data_byline;
      // Related content
    if (isset($row->xml->relatedcontents->relatedcontent) && !empty($row->xml->relatedcontents->relatedcontent)) {
      foreach($row->xml->relatedcontents->relatedcontent as $related){
        $related_content .= (string) $related.', ';
      }
      $final_related_content = rtrim($related_content, ', ');
      $row->xml->relatedcontents = $final_related_content;
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
    if (!empty($row->final_config_option)) {
      $node->field_video_configurations[LANGUAGE_NONE] = $row->final_config_option;
    }
    if (!empty($row->final_social_checkbox)) {
      $node->field_story_social_media_integ[LANGUAGE_NONE] = $row->final_social_checkbox;
    }
    if (!empty($row->byline_new)) {
      $node->field_story_reporter[LANGUAGE_NONE] = $row->byline_new;
    }
    if(!empty($row->city)){
      $node->field_stroy_city[LANGUAGE_NONE][0]['tid'] = (string) $row->city;
    }
  
    $node->uid = 291;
  }

}