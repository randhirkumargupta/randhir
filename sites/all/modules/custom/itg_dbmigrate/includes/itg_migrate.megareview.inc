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
      'title' => t('Movie Title'),
      'movie_description' => t('Movie Description'),
      'megareviewtype' => t('Mega Review Type'),
      'career_graph' => t('career_graph'),
      'director' => t('Director'),
      'movieplot' => t('Movie Plot'),
      'youtubeurl' => t('Youtube Url'),
      'associatevideos' => t('Associate Video'),
      'associatevideo' => t('associatevideo'),
      'associatephotogallerys' => t('Associate Photo Gallery'),
      'associatephotogallery' => t('associatephotogallery'),
      'twitterhandletagwidget' => t('Twitter handle & tag (widget)'),
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
      'reviews' => t('Review'), //Fieldcollection
      'sefurl' => t('Sefurl'),
      'pagetitle' => t('Page title'),
      'description' => t('Description'),
      'keywords' => t('Keywords'),
      'state' => t('state'),
      'createddate' => t('createddate'),
      'modifieddate' => t('modifieddate'),
      'createdby' => t('createdby'),
      'redirectionurl' => t('redirectionurl'),
      'cast' => t('cast'),
      'casts' => t('casts'),
    );


    // This can also be an URL instead of a local file path.
    $file_path = 'sites/default/files';

    $xml_folder = $file_path . '/' . 'migrate/xml_file/movie-review-xmls-19-06-2017/';

    $items_url = $xml_folder . 'indiatoday-movie-review.xml';

    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/Root/mega_review_critic';

    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /story/item/id.
    $item_ID_xpath = 'id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('mega_review_critic');

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
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('field_story_movie_description', 'movie_description')->xpath('movie_description');
    $this->addFieldMapping('field_mega_review_director', 'director')->xpath('director');
    $this->addFieldMapping('field_mega_review_movie_plot', 'movieplot')->xpath('movieplot'); //more then 255
    $this->addFieldMapping('field_mega_review_youtube_url', 'youtubeurl')->xpath('youtubeurl');
    $this->addFieldMapping('field_mega_review_cast', 'cast')->xpath('casts/cast');
    $this->addFieldMapping('field_story_associate_video', 'associatevideo')->xpath('associatevideos/associatevideo'); // single in field but multi in xml
    $this->addFieldMapping('field_associate_photo_gallery', 'associatephotogallery')->xpath('associatephotogallerys/associatephotogallery'); // single in filed but multi in xml
    $this->addFieldMapping('field_mega_review_twitter', 'twitterhandletagwidget')->xpath('twitterhandletagwidget');
    // Image field
    $this->addFieldMapping('field_story_extra_large_image', 'extralargeimage')->xpath('extralargeimage');
    $this->addFieldMapping('field_story_extra_large_image:preserve_files')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_extra_large_image:alt', 'extra_large_alt')->xpath('extra_large_alt');
    $this->addFieldMapping('field_story_extra_large_image:title', 'extra_large_title')->xpath('extra_large_title');
    $this->addFieldMapping('field_story_large_image', 'largeimage')->xpath('largeimage');
    $this->addFieldMapping('field_story_large_image:preserve_files')
        ->defaultValue(TRUE);
    /*$this->addFieldMapping('field_story_large_image:destination_dir')
      ->defaultValue('s3fs-public/dailymotion_video');*/
    $this->addFieldMapping('field_story_large_image:alt', 'large_alt')->xpath('large_alt');
    $this->addFieldMapping('field_story_large_image:title', 'large_title')->xpath('large_title');
    $this->addFieldMapping('field_story_medium_image', 'mediumimage')->xpath('mediumimage');
    $this->addFieldMapping('field_story_medium_image:preserve_files')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_medium_image:alt', 'mediumimage_alt')->xpath('mediumimage_alt');
    $this->addFieldMapping('field_story_medium_image:title', 'mediumimage_title')->xpath('mediumimage_title');
    $this->addFieldMapping('field_story_small_image', 'smallimage')->xpath('smallimage');
    $this->addFieldMapping('field_story_small_image:preserve_files')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_small_image:alt', 'smallimage_alt')->xpath('smallimage_alt');
    $this->addFieldMapping('field_story_small_image:title', 'smallimage_title')->xpath('smallimage_title');
    $this->addFieldMapping('field_story_extra_small_image', 'extrasmallimage')->xpath('extrasmallimage');
    $this->addFieldMapping('field_story_extra_small_image:preserve_files')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_extra_small_image:file_replace')
        ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_story_extra_small_image:alt', 'extra_small_alt')->xpath('extra_small_alt');
    $this->addFieldMapping('field_story_extra_small_image:title', 'extra_small_title')->xpath('extra_small_title');
    $this->addFieldMapping('pathauto')->defaultValue(0);
    $this->addFieldMapping('path', 'sefurl')->xpath('metatags/sefurl'); // add condition for blank sef url
    $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
    $this->addFieldMapping('metatag_description', 'metadescription')->xpath('metatags/description');
    $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/keywords');
    $this->addFieldMapping('status', 'state')->xpath('state');

    //code for date
    $this->addFieldMapping('created', 'createddate')->xpath('createddate');
    $this->addFieldMapping('uid', 'createdby')->xpath('createdby')
        ->defaultValue(970); //siteadmin
    $this->addFieldMapping('changed', 'modifieddate')->xpath('modifieddate');
    $this->addFieldMapping('migrate_redirects', 'redirectionurl')->xpath('redirectionurl');
    $this->addFieldMapping('field_story_source_type')
        ->defaultValue('migrated');
    $this->addFieldMapping('field_story_source_id', 'id')->xpath('id'); // source id
    $this->addUnmigratedDestinations(array(
      'promote',
      'sticky',
      'revision',
      'log',
      'language',
      'tnid',
      'translate',
      'revision_uid',
      'is_new',
    ));
  }

  public function prepareRow($row) {
    if (!empty($row->xml->casts->cast)) {
      $key = 0;
      foreach ($row->xml->casts->cast as $cast) {
          $cast_source_id = (int) $cast;
          if(!empty($cast_source_id)) {
            $row->xml->casts->cast[$key] = get_itg_destination_id('migrate_map_itgcast', $cast_source_id);
            $key++;
          }
      }
    }
    
    if (!empty($row->xml->associatevideos->associatevideo)) {
      $key_video = 0;
      foreach ($row->xml->associatevideos->associatevideo as $video) {
          $video_source_id = (int) $video;
          if(!empty($video_source_id)) {
            $row->xml->associatevideos->associatevideo[$key_video] = get_itg_destination_id('migrate_map_itgvideogallery', $video_source_id);
            $key_video++;
          }
      }
    }
    
    if (!empty($row->xml->associatephotogallerys->associatephotogallery)) {
      $photo_key = 0;
      foreach ($row->xml->associatephotogallerys->associatephotogallery as $photo) {
          $photo_source_id = (int) $photo;
          if(!empty($photo_source_id)) {
            $row->xml->associatephotogallerys->associatephotogallery[$photo_key] = get_itg_destination_id('migrate_map_itgphotogallery', $photo_source_id);
            $photo_key++;
          }
      }
    }

    // manage created user
    if (isset($row->xml->createdby) && !empty($row->xml->createdby)) {
      $created_uid = (int) $row->xml->createdby;
      $orignal_crated_uid = get_itg_destination_id('migrate_map_itguser', $created_uid);
      $row->xml->createdby = $orignal_crated_uid;
    }
    else {
      $row->xml->createdby = 970; //siteadmin;
    }

    if (!empty($row->xml->megareviewtype) && (string) $row->xml->megareviewtype == 'movie') {
      $row->xml->megareviewtype = 285703; // movie type
    }
    
    if(empty($row->xml->metatags->sefurl)) {
       $row->xml->metatags->sefurl =  itg_common_custompath_insert_val((string) $row->xml->author_name);
    }
    if (empty((int) $row->xml->modifieddate)) {
      $row->xml->modifieddate = (int) $row->xml->createddate;
    }
    return TRUE;
  }

  public function prepare($node, stdClass $row) {
    $node->teaser = (string) $row->xml->description;
    if (!empty($row->xml->megareviewtype)) {
      $node->field_mega_review_type[LANGUAGE_NONE][0]['tid'] = (int) $row->xml->megareviewtype;
    }
    
    $modified_time = (int) $row->xml->modifieddate; // TIme migrate as IST
    $mod_time = $modified_time;
    $modi_time = date('Y-m-d h:i:s', $mod_time);
    $node->field_itg_content_publish_date[LANGUAGE_NONE][0]['value'] = $modi_time;
  }

  public function complete($entity, $row) {
     print (string) $row->xml->id.' - ';
    $node = $entity;

    if (isset($row->xml->reviews->review) && !empty($row->xml->reviews->review)) {
      $key = 0;
      foreach ($row->xml->reviews->review as $value) {

        $headline = (string) $value->headLine;
        $review_type = (string) $value->review_type;
        $data_reviewer = array();
        if (!empty($value->reviewer)) {
          $source_bid = (string) $value->reviewer;
          $orignal_byline = get_itg_destination_id('migrate_map_itgbyline', $source_bid);
          if(!empty($orignal_byline)) {
            $data_reviewer[]['target_id'] = $orignal_byline;
          }
        }

        $review_url_link = (string) $value->review_url_link;
        $description = (string) $value->review_description;
        $rating = (string) $value->rating;
        $values = array(
          'field_name' => 'field_mega_review_review',
          'field_story_review_type' => (!empty($review_type)) ? array(LANGUAGE_NONE => array(array('value' => $review_type))) : '',
          'field_buzz_headline' => (!empty($headline)) ? array(LANGUAGE_NONE => array(array('value' => $headline))) : '',
          'field_story_reporter' => (!empty($data_reviewer)) ? array(LANGUAGE_NONE => $data_reviewer) : '',
          'field_mega_review_url_link' => (!empty($review_url_link)) ? array(LANGUAGE_NONE => array(array('value' => $review_url_link))) : '',
          'field_mega_review_description' => (!empty($description)) ? array(LANGUAGE_NONE => array(array('value' => $description))) : '',
          'field_story_rating' => (!empty($rating)) ? array(LANGUAGE_NONE => array(array('value' => $rating))) : '',
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
