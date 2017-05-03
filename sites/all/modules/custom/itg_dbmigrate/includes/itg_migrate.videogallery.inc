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
      'multibitrate_flag' => t('multibitrate_flag'),
      'multipart_flag' => t('multipart_flag'),
      'state' => t('state'),
      'anchor' => t('anchor'),
      'bylines' => t('bylines'),
      'createddate' => t('createddate'),
      'publisheddate' => t('publisheddate'),
      'modifieddate' => t('modifieddate'),
      'createdby' => t('createdby'),
      'modifiedby' => t('modifiedby'),
      'courtesy' => t('courtesy'),
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
      'bigimage' => t('bigimage'),
      'syndications' => t('syndications'),
      'multi_bitrates' => t('multi_bitrates'), //multi
      'cities' => t('cities'), //multi
      'categories' => t('categories'), //multi
      'ordering' => t('ordering'),
      'tags' => t('tags'), //multi
      'title' => t('title'),
      'longheadline' => t('longheadline'),
      'like-dislike' => t('like-dislike'),
      'socialmediaintegration' => t('socialmediaintegration'), //checkbox
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
      'syndications_photo' => t('syndications_photo'),
      'noindex_nofollow' => t('noindex_nofollow'),
      'weburl' => t('weburl'),
      'archive' => t('archive'),
      //'video_duration' => t('video_duration'),
      'configurations' => t('configurations'), //checkbox
      'googlestandout' => t('googlestandout'),
      'comment' => t('comment'),
      'commentbox' => t('commentbox'),
      'commentquestion' => t('commentquestion'),
      'videoparts' => t('videoparts'), // MUltiple videos URL
      'relatedcontents' => t('relatedcontents'), //multi
//      'expirydate' => t('expirydate'),
//      'scheduledatetime' => t('scheduledatetime'),
      'sefurl' => t('Sefurl'),
      'pagetitle' => t('Page title'),
      'metadescription' => t('metadescription'),
      'keywords' => t('Keywords'),
    );


    // This can also be an URL instead of a local file path.
    //$file_path = drupal_realpath('public://');
    $file_path = DRUPAL_ROOT . '/' . 'sites/default/files';
    $xml_folder = $file_path . '/' . 'migrate/xml_file/';

    $items_url = $xml_folder . 'videogallery.xml';

    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/data/videogallery';

    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /story/item/id.
    $item_ID_xpath = 'id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('videogallery');

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
    // addFieldMapping (the name under which it will be saved in the data row
    // passed through the migration process) we specify the Xpath used to
    // retrieve the value from the XML.
    // TIP: Note that all xpaths for fields begin at the last element of the
    // item xpath since each item xml chunk is processed individually.
    // (ex. xpath=name is equivalent to a full xpath of
    // /categories/category/name).
    $this->addFieldMapping('title', 'longheadline')->xpath('longheadline');
    $this->addFieldMapping('field_story_short_headline', 'title')->xpath('title');
    // Byline mapped in prepare
    //$this->addFieldMapping('field_stroy_city', 'city')->xpath('city');
    $this->addFieldMapping('field_story_courtesy', 'courtesy')->xpath('courtesy');
    $this->addFieldMapping('field_video_anchor', 'anchor')->xpath('anchor');
    // configuration mapped in prepare
    $this->addFieldMapping('field_story_comment_question', 'commentquestion')->xpath('commentquestion');
    $this->addFieldMapping('field_story_schedule_date_time', 'publisheddate')->xpath('publisheddate'); // published date
    $this->addFieldMapping('field_itg_content_publish_date', 'publisheddate')->xpath('publisheddate'); // published date
    $this->addFieldMapping('field_story_expiry_date', 'expirydate')->xpath('expirydate');
    $this->addFieldMapping('field_story_expires', 'videoexpires')->xpath('videoexpires');
    // Image field 
    $this->addFieldMapping('field_story_extra_large_image', 'extralargeimage')->xpath('extralargeimage');
    $this->addFieldMapping('field_story_extra_large_image:preserve_files')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_extra_large_image:alt', 'extra_large_alt')->xpath('extra_large_alt');
    $this->addFieldMapping('field_story_extra_large_image:title', 'extra_large_title')->xpath('extra_large_title');
    $this->addFieldMapping('field_story_large_image', 'largeimage')->xpath('largeimage');
    $this->addFieldMapping('field_story_large_image:preserve_files')
        ->defaultValue(TRUE);
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
    $this->addFieldMapping('field_story_player_image', 'bigimage')->xpath('bigimage');
    $this->addFieldMapping('field_story_player_image:preserve_files')
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

    // source migrated
    $this->addFieldMapping('field_story_source_type')
        ->defaultValue('migrated');

    // Facebook and twitter image
    $this->addFieldMapping('field_story_facebook_narrative', 'facebooknarrative')->xpath('facebooknarrative');
    $this->addFieldMapping('field_story_facebook_image', 'facebookimage')->xpath('facebookimage');
    $this->addFieldMapping('field_story_facebook_image:file_replace')
        ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_story_facebook_image:preserve_files')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_facebook_image:alt', 'facebookimage_alt')->xpath('facebookimage_alt');
    $this->addFieldMapping('field_story_facebook_image:title', 'facebookimage_title')->xpath('facebookimage_title');
    $this->addFieldMapping('field_story_tweet', 'twitternarrative')->xpath('twitternarrative');
    $this->addFieldMapping('field_story_tweet_image', 'twitterimage')->xpath('twitterimage');
    $this->addFieldMapping('field_story_tweet_image:file_replace')
        ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_story_tweet_image:preserve_files')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_tweet_image:alt', 'twitterimage_alt')->xpath('twitterimage_alt');
    $this->addFieldMapping('field_story_tweet_image:title', 'twitterimage_title')->xpath('twitterimage_title');

    // Video migrate
    // $this->addFieldMapping('field_upload_video', 'video')->xpath('video');
    //$this->addFieldMapping('field_story_expert_name', 'shortdescription')->xpath('shortdescription');
    $this->addFieldMapping('field_video_kicker', 'shortdescription')->xpath('shortdescription');
    $this->addFieldMapping('field_story_expert_description', 'longdescription')->xpath('longdescription');

    // Section mapped in prepare

    $this->addFieldMapping('field_story_syndication', 'syndications')->xpath('syndications');
    $this->addFieldMapping('field_story_archive', 'archive')->xpath('archive');
    $this->addFieldMapping('field_primary_category', 'primarycategory')->xpath('primarycategory');
    $this->addFieldMapping('pathauto')->defaultValue(0);
    $this->addFieldMapping('path', 'sefurl')->xpath('metatags/sefurl');
    $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
    $this->addFieldMapping('metatag_description', 'metadescription')->xpath('metatags/metadescription');
    $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/keywords');
    //$this->addFieldMapping('workbench_moderation_state_new', 'workbench_moderation_state_new')->xpath('workbench_moderation_state_new');
    $this->addFieldMapping('created', 'createddate')->xpath('createddate');
    $this->addFieldMapping('changed', 'modifieddate')->xpath('modifieddate');
    $this->addFieldMapping('field_modified_by_video', 'modifiedby')->xpath('modifiedby');
    $this->addFieldMapping('status', 'state')->xpath('state');
    $this->addFieldMapping('field_noindex_nofollow', 'noindex_nofollow')->xpath('noindex_nofollow');
    $this->addFieldMapping('field_syndication_photo_video', 'syndications_photo')->xpath('syndications_photo');
    $this->addFieldMapping('migrate_redirects', 'weburl')->xpath('weburl');


    /* $this->addUnmigratedDestinations(array('promote', 'sticky', 'revision', 'log', 'language', 'tnid', 'translate', 'revision_uid', 'is_new',
      'status',
      'field_common_by_line_reporter_id',
      'field_common_related_content',
      'field_itg_common_by_line_name',
      'field_itg_common_by_line_twitter',
      'field_story_category',
      'field_story_category:source_type',
      'field_story_category:create_term',
      'field_story_category:ignore_case',
      'field_story_expiry_date:timezone',
      'field_story_expiry_date:rrule',
      'field_story_expiry_date:to',
      'field_story_extra_large_image:destination_dir',
      'field_story_extra_large_image:destination_file',
      'field_story_extra_large_image:file_replace',
      'field_story_extra_large_image:source_dir',
      'field_story_extra_large_image:urlencode',
      'field_story_extra_small_image:file_class',
      'field_story_extra_small_image:destination_dir',
      'field_story_extra_small_image:destination_file',
      'field_story_extra_small_image:source_dir',
      'field_story_extra_small_image:urlencode',
      'field_story_facebook_image:file_class',
      'field_story_large_image:destination_dir',
      'field_story_large_image:destination_file',
      'field_story_large_image:file_replace',
      'field_story_large_image:source_dir',
      'field_story_large_image:urlencode',
      'field_story_listicle',
      'field_story_listicle:revision_id',
      'field_story_medium_image:file_class',

      'field_story_itg_tags',
      'field_story_itg_tags:source_type',
      'field_story_itg_tags:create_term',
      'field_story_itg_tags:ignore_case',
      'field_story_large_image:file_class',

      'field_story_large_image:destination_dir',
      'field_story_large_image:destination_file',
      'field_story_large_image:file_replace',
      'field_story_large_image:source_dir',
      'field_story_large_image:urlencode',
      'field_story_listicle',
      'field_story_listicle:revision_id',
      'field_story_medium_image:file_class',
      //'field_story_medium_image:preserve_files',
      'field_story_medium_image:destination_dir ',
      'field_story_medium_image:destination_file',
      'field_story_medium_image:file_replace',
      'field_story_medium_image:source_dir',
      'field_story_medium_image:urlencode',
      'field_story_small_image:file_class',
      //'field_story_small_image:preserve_files',
      'field_story_small_image:destination_dir',
      'field_story_small_image:destination_file',
      'field_story_small_image:file_replace',
      'field_story_small_image:source_dir',
      'field_story_small_image:urlencode',
      'migrate_redirects_language',
      'metatag_abstract',
      'metatag_robots',
      'metatag_news_keywords',
      'metatag_standout',
      'metatag_rating',
      'metatag_referrer',
      'metatag_generator',
      'metatag_rights',
      'metatag_image_src',
      'metatag_canonical',
      'metatag_shortlink',
      'metatag_publisher',
      'metatag_author',
      'metatag_original-source',
      'metatag_prev',
      'metatag_next',
      'metatag_content-language',
      'metatag_geo.position',
      'metatag_geo.placename',
      'metatag_geo.region',
      'metatag_icbm',
      'metatag_refresh',
      'metatag_revisit-after',
      'metatag_pragma',
      'metatag_cache-control',
      'metatag_expires',
      'comment',
      'totalcount',
      'daycount',
      'timestamp',
      )); */
  }

  public function prepareRow($row) {
    if (!empty($row->xml->extralargeimage)) {
      $row->xml->extralargeimage = itg_dbmigrate_imagepath_url((string) $row->xml->extralargeimage);
    }

    if (!empty($row->xml->largeimage)) {
      $row->xml->largeimage = itg_dbmigrate_imagepath_url((string) $row->xml->largeimage);
    }
    if (!empty($row->xml->mediumimage)) {
      $row->xml->mediumimage = itg_dbmigrate_imagepath_url((string) $row->xml->mediumimage);
    }

    if (!empty($row->xml->smallimage)) {
      $row->xml->smallimage = itg_dbmigrate_imagepath_url((string) $row->xml->smallimage);
    }

    if (!empty($row->xml->extrasmallimage)) {
      $row->xml->extrasmallimage = itg_dbmigrate_imagepath_url((string) $row->xml->extrasmallimage);
    }
    if (!empty($row->xml->facebookimage)) {
      $row->xml->facebookimage = itg_dbmigrate_imagepath_url((string) $row->xml->facebookimage);
    }

    if (!empty($row->xml->twitterimage)) {
      $row->xml->twitterimage = itg_dbmigrate_imagepath_url((string) $row->xml->twitterimage);
    }



    if ((string) $row->xml->longheadline) {
      $row->xml->longheadline = trim((string) $row->xml->longheadline);
    }

    if ((string) $row->xml->syndications_photo == '1') {
      $row->xml->syndications_photo = 'syndications_photo';
    }

    //syndication
    if ((string) $row->xml->syndications == '1') {
      $row->xml->syndications = 'Yes';
    }
    else {
      $row->xml->syndications = '';
    }

    // Category migrate
    /*$data_category = '';

    if (isset($row->xml->categories->category) && !empty($row->xml->categories->category)) {
      foreach ($row->xml->categories->category as $final_category) {
        $category_array = explode('#', $final_category);
        $array_count = count($category_array);
        $table_name = itg_migrate_category_table($array_count);
        $last_value = end($category_array);
        $source_cid = (string) $last_value;
        $orignal_category = get_itg_destination_id($table_name, $source_cid);
        $data_category[]['tid'] = $orignal_category;
      }
    }
    $row->category_new = $data_category;*/
    
  $data_category = '';
  if (isset($row->xml->categories->category) && !empty($row->xml->categories->category)) {  
    $category_array = array();
    $tid_array = array();
    foreach ($row->xml->categories->category as $xm_cat) {
      $category_array = explode('#', $xm_cat);
      $k = 1;
      foreach ($category_array as $individal_cat) {

        $array_count = $k;
        $source_cid = (string) $individal_cat;

        $table_name = itg_migrate_category_table($array_count);
        if ($k != 1) {
          $str = '#';
        }
        $tid_array[] = get_itg_destination_id($table_name, $source_cid);
        $k++;
      }
    }
    $all_category = array_unique($tid_array);
    foreach ($all_category as $chunk_data) {
        $data_category[]['tid'] = $chunk_data;
      }
  }
 $row->category_new = $data_category;

    // Primary category
    if (isset($row->xml->primarycategory) && !empty($row->xml->primarycategory)) {
      $source_cid = (string) $row->xml->primarycategory;
      $pcategory_array = explode('#', $source_cid);
      $parray_count = count($pcategory_array);
      $table_name = itg_migrate_category_table($parray_count);
      $last_value = end($pcategory_array);
      $source_cid = (string) $last_value;
      $orignal_pcategory = get_itg_destination_id($table_name, $source_cid);
      $row->xml->primarycategory = $orignal_pcategory;
    }
    
    
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
    if (!empty($row->xml->commentbox) && (string) $row->xml->commentbox == 1) {
      $final_option[]['value'] = 'comment_box';
    }
    $row->final_config_option = $final_option;

    // No follo no index
    if ((string) $row->xml->noindex_nofollow == 1) {
      $row->xml->noindex_nofollow = 'noindex_nofollow';
    }


    // Multipart and bitrate flags
    if (!empty($row->xml->multibitrate_flag) && (string) $row->xml->multibitrate_flag == 1) {
      $multipart[]['value'] = 'multibitrate_flag';
    }
    if (!empty($row->xml->multipart_flag) && (string) $row->xml->multipart_flag == 1) {
      $multipart[]['value'] = 'multipart_flag';
    }
    $row->multipart_bitrate = $multipart;
    // City migrate
    $data_city = '';
    if (isset($row->xml->cities->city) && !empty($row->xml->cities->city)) {
      foreach ($row->xml->cities->city as $final_city) {
        $source_city = (string) $final_city;
        $orignal_city = get_itg_destination_id('migrate_map_itgcity', $source_city);
        $data_city[]['tid'] = $orignal_city;
      }
    }
    $row->city_new = $data_city;

    // Videogallery Date 2106
    $row->xml->expirydate = '4325600812';


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


    if (isset($row->xml->anchor) && !empty($row->xml->anchor)) {
      $source_aid = (string) $row->xml->anchor;
      $data_anchor = get_itg_destination_id('migrate_map_itgbyline', $source_aid);
    }
    $row->xml->anchor = $data_anchor;
    //multi bitrates
    $row->bitrates = '';
    if (isset($row->xml->multi_bitrates) && !empty($row->xml->multi_bitrates)) {
      //$arr = array();
      foreach ($row->xml->multi_bitrates->bitrate as $value) {
        $chk_variable = (string) $value;
        if (!empty($chk_variable)) {
          $type = (string) $value->attributes()->type;
          $bitrate_id = (string) $value;
          $data_bitrate[]['value'] = $type . '@' . $bitrate_id;
        }
      }
    }
    $row->bitrates = $data_bitrate;

    // Modified by
    if (isset($row->xml->modifiedby) && !empty($row->xml->modifiedby)) {
      $modi_uid = (string) $row->xml->modifiedby;
      $row->xml->modifiedby = get_itg_destination_id('migrate_map_itguser', $modi_uid);
    }

    // manage created user
    if (isset($row->xml->createdby) && !empty($row->xml->createdby)) {
      $created_uid = (string) $row->xml->createdby;
      $orignal_crated_uid = get_itg_destination_id('migrate_map_itguser', $created_uid);
      $row->xml->createdby = $orignal_crated_uid;
    }
    else {
      $row->xml->createdby = 970; //siteadmin;
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
    if (!empty($row->city_new)) {
      $node->field_stroy_city[LANGUAGE_NONE] = $row->city_new;
    }
    // Multi part flag
    if (!empty($row->multipart_bitrate)) {
      $node->field_video_flags[LANGUAGE_NONE] = $row->multipart_bitrate;
    }
    // Bitrate and type save in node
    if (!empty($row->bitrates)) {
      $node->field_multi_bitrate[LANGUAGE_NONE] = $row->bitrates;
    }
    $node->uid = $row->xml->createdby;
  }

  public function complete($entity, $row) {
    $node = $entity;

    //Video url migrate
    if (isset($row->xml->videoparts) && !empty($row->xml->videoparts)) {
      $key = 0;
      foreach ($row->xml->videoparts->part as $value) {
        $new_value = (string) $value->part_url;
        if (!empty($new_value)) {
          $video_url = (string) $value->part_url;
          $values = array(
            'field_name' => 'field_video_upload',
            'field_migrated_video_url' => array(LANGUAGE_NONE => array(array('value' => $video_url))),
          );

          $field_collection_item = entity_create('field_collection_item', $values);
          $field_collection_item->setHostEntity('node', $node);
          $field_collection_item->save(TRUE);
          $node->field_video_upload[LANGUAGE_NONE][$key]['value'] = $field_collection_item->item_id;
          if ($key == 0) {
            $node->field_video_duration[LANGUAGE_NONE][0]['value'] = (string) $value->part_duration;
          }
          $key++;
        }
        // multi bitrate save in custom table

        if (!empty($value->multi_bitrates)) {
          $chk_variable = '';
          foreach ($value->multi_bitrates->bitrate as $bitrate) {
            $chk_variable = (string) $bitrate;

            if (!empty($chk_variable)) {
              db_insert('itg_video_transcoding')
                  ->fields(array(
                    'nid' => $node->nid,
                    'bitrate' => ((int) $bitrate ? (int) $bitrate : NULL),
                    'bitrate_type' => ((string) $bitrate->attributes()->type ? (string) $bitrate->attributes()->type : NULL),
                    'bitrate_status' => ((string) $bitrate->attributes()->status ? (string) $bitrate->attributes()->status : NULL),
                    'file_size' => ((int) $bitrate->attributes()->file_size ? (int) $bitrate->attributes()->file_size : NULL),
                    'completion_datetime' => ((string) $bitrate->attributes()->completion_datetime ? (string) $bitrate->attributes()->completion_datetime : NULL),
                    'bitrate_ordering' => ((int) $bitrate->attributes()->ordering ? (int) $bitrate->attributes()->ordering : NULL),
                    'video_duration' => ((int) $value->part_duration ? (int) $value->part_duration : NULL),
                    'website' => ((string) $row->xml->website ? (string) $row->xml->website : NULL),
                    'transcoding_id' => ((int) $row->xml->transcoding_id ? (int) $row->xml->transcoding_id : NULL),
                    'transcoding_source' => ((string) $row->xml->transcoding_source ? (string) $row->xml->transcoding_source : NULL),
                    'bucket_output' => ((string) $row->xml->bucket_output ? (string) $row->xml->bucket_output : NULL),
                    'hls_domain' => ((string) $row->xml->hls_domain ? (string) $row->xml->hls_domain : NULL),
                    'video_url' => ($video_url ? $video_url : NULL),
                  ))
                  ->execute();
            }
          }
        }
      }
      field_attach_update('node', $node);
    }

    //code for like and dislike
    if (isset($row->xml->like_dislike->like) || isset($row->xml->like_dislike->dislike)) {
      itg_flag_insert_like_dislike($node->nid, $row->xml->like_dislike->like, $row->xml->like_dislike->dislike);
    }


    //code for order set
    //if (isset($row->xml->ordering)) {
    ordering_set_of_content($node, (string) $row->xml->ordering);
    //}
    // Related content save in db
    /* if (isset($row->xml->relatedcontents->relatedcontent) && !empty($row->xml->relatedcontents->relatedcontent)) {
      //$arr = array();
      foreach ($row->xml->relatedcontents->relatedcontent as $value) {
      $chk_variable = (string) $value;
      if(!empty($chk_variable)){
      db_insert('itg_dbmigrate_related_content')
      ->fields(array(
      'migrated_nid' => $node->nid,
      'source_id' => (string) $value,
      'type' => (string) $value->attributes()->type,
      'migration_node_type' => 'videogallery',
      'xml_id' => (string) $row->xml->id,
      ))
      ->execute();
      }
      }
      } */
  }

}
