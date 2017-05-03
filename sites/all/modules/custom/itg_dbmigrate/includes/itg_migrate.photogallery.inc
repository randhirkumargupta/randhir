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
      //'issue_date' => t('issue_date'),
      'extralargeimage' => t('extralargeimage'),
      'extra_large_alt' => t('extra_large_alt'),
      'extra_large_title' => t('extra_large_title'),
      'extrasmallimage' => t('extrasmallimage'),
      'extra_small_alt' => t('extra_small_alt'),
      'extra_small_title' => t('extra_small_title'),
      'large_image' => t('large_image'),
      'large_title' => t('large_title'),
      'large_alt' => t('large_alt'),
      'mediumimage' => t('mediumimage'),
      'mediumimage_alt' => t('mediumimage_alt'),
      'mediumimage_title' => t('mediumimage_title'),
      'smallimage' => t('smallimage'),
      'smallimage_alt' => t('smallimage_alt'),
      'smallimage_title' => t('smallimage_title'),
      // 'tags' => t('tags'),
      // 'categories' => t('categories'),
      'primary_category' => t('primary_category'),
      'commonaudio' => t('commonaudio'),
      'commonaudiofile' => t('commonaudiofile'),
      'credittoall' => t('credittoall'),
      'creditname' => t('creditname'),
      'photoby' => t('photoby'),
      'archive' => t('archive'),
      //'socialmediaintegration' => t('socialmediaintegration'),
     // 'facebooknarrative' => t('facebooknarrative'),
      //'facebookimage' => t('facebookimage'),
      //'facebookimage_alt' => t('facebookimage_alt'),
      //'facebookimage_title' => t('facebookimage_title'),
      //'facebookvideonarrative' => t('facebookvideonarrative'),
      //'facebookvideo' => t('facebookvideo'),
      //'twitternarrative' => t('twitternarrative'),
      //'twitterimage' => t('twitterimage'),
      //'twitterimage_alt' => t('twitterimage_alt'),
      //'twitterimage_title' => t('twitterimage_title'),
      //'twittervideodescription' => t('twittervideodescription'),
      //'twittervideo' => t('twittervideo'),
      'timetwitter' => t('timetwitter'),
      'postedbyfacebook' => t('postedbyfacebook'),
      'timefacebook' => t('timefacebook'),
      'postedbyinstagram' => t('postedbyinstagram'),
      'timeinstagram' => t('timeinstagram'),
      //'commonbyline' => t('commonbyline'),
      //'commonbylinetwitter' => t('commonbylinetwitter'),
      'postedbytwitter' => t('postedbytwitter'),
      //'photo_by' => t('photo_by'),
      'syndication' => t('syndication'),
      //'created_by' => t('created_by'),
      //'modified_by' => t('modified_by'),
      'short_description' => t('short_description'),
      'strap_headline' => t('strap_headline'),
      'content_url' => t('content_url'),
      //'gallery' => t('gallery'),
      // 'relatedcontents' => t('relatedcontents'),
      'sef_url' => t('sef_url'),
      'pagetitle' => t('Page title'),
      'description' => t('Description'),
      'keywords' => t('Keywords'),
      'published' => t('published'),
      'created' => t('created'),
      'modified' => t('modified'),
      'featured_ordering' => t('featured_ordering'),
      'description' => t('description'),
      'metadescription' => t('metadescription'),
    );


    // This can also be an URL instead of a local file path.
    $file_path = DRUPAL_ROOT . '/' . 'sites/default/files';

    $xml_folder = $file_path . '/' . 'migrate/xml_file/';

    $items_url = $xml_folder . 'indiatoday-galleries.xml';

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
    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('field_gallery_kicer', 'galleryslug')->xpath('galleryslug');
    $this->addFieldMapping('field_gallery_kicer:format', 'format')
        ->defaultValue('full_html');
    $this->addFieldMapping('field_featured', 'featured')->xpath('featured');

    // for image
    $this->addFieldMapping('field_story_extra_large_image', 'extralargeimage')->xpath('extralargeimage');
    $this->addFieldMapping('field_story_extra_large_image:preserve_files')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_extra_large_image:alt', 'extra_large_alt')->xpath('extra_large_alt');
    $this->addFieldMapping('field_story_extra_large_image:title', 'extra_large_title')->xpath('extra_large_title');

    $this->addFieldMapping('field_story_large_image', 'large_image')->xpath('large_image');
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
    $this->addFieldMapping('field_story_small_image:alt', 'smallimage_alt')->xpath('smallimage_alt');
    $this->addFieldMapping('field_story_small_image:title', 'smallimage_title')->xpath('smallimage_title');

    $this->addFieldMapping('field_story_extra_small_image', 'extrasmallimage')->xpath('extrasmallimage');
    $this->addFieldMapping('field_story_extra_small_image:preserve_files')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_extra_small_image:file_replace')
        ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_story_extra_small_image:alt', 'extra_small_alt')->xpath('extra_small_alt');
    $this->addFieldMapping('field_story_extra_small_image:title', 'extra_small_title')->xpath('extra_small_title');

    $this->addFieldMapping('field_primary_category', 'primary_category')->xpath('primary_category');

    //code for date
    $this->addFieldMapping('created', 'created')->xpath('created');
    $this->addFieldMapping('changed', 'modified')->xpath('modified');
    $this->addFieldMapping('status', 'published')->xpath('published');
   

    $this->addFieldMapping('field_common_audio', 'commonaudio')->xpath('commonaudio');
    $this->addFieldMapping('field_common_audio_file', 'commonaudiofile')->xpath('commonaudiofile');
    $this->addFieldMapping('field_credit_to_all', 'credittoall')->xpath('credittoall');
    $this->addFieldMapping('field_credit_name', 'creditname')->xpath('creditname');
    $this->addFieldMapping('field_story_archive', 'archive')->xpath('archive');
    $this->addFieldMapping('field_photo_by', 'photoby')->xpath('photoby');

    //code for social media
    /*$this->addFieldMapping('field_story_facebook_narrative', 'facebooknarrative')->xpath('facebooknarrative');
    $this->addFieldMapping('field_story_facebook_image', 'facebookimage')->xpath('facebookimage');
    $this->addFieldMapping('field_story_facebook_image:file_replace')
        ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_story_facebook_image:preserve_files')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_facebook_image:alt', 'facebookimage_alt')->xpath('facebookimage_alt');
    $this->addFieldMapping('field_story_facebook_image:title', 'facebookimage_title')->xpath('facebookimage_title');*/

    //$this->addFieldMapping('field_story_facebook_video', 'facebookvideo')->xpath('facebookvideo');
    $this->addFieldMapping('field_story_posted_by_facebook', 'postedbyfacebook')->xpath('postedbyfacebook');
    $this->addFieldMapping('field_story_time_facebook', 'timefacebook')->xpath('timefacebook');

    /*$this->addFieldMapping('field_story_tweet', 'twitternarrative')->xpath('twitternarrative');
    $this->addFieldMapping('field_story_tweet_image', 'twitterimage')->xpath('twitterimage');
    $this->addFieldMapping('field_story_tweet_image:file_replace')
        ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_story_tweet_image:preserve_files')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_tweet_image:alt', 'twitterimage_alt')->xpath('twitterimage_alt');
    $this->addFieldMapping('field_story_tweet_image:title', 'twitterimage_title')->xpath('twitterimage_title');
    //$this->addFieldMapping('field_story_twitter_video_desc', 'twittervideodescription')->xpath('twittervideodescription');*/
    //$this->addFieldMapping('field_story_twitter_video', 'twittervideo')->xpath('twittervideo');
    $this->addFieldMapping('field_story_time_twitter', 'timetwitter')->xpath('timetwitter');
    $this->addFieldMapping('field_story_posted_by_twitter', 'postedbytwitter')->xpath('postedbytwitter');


    $this->addFieldMapping('field_story_posted_by_instagram', 'postedbyinstagram')->xpath('postedbyinstagram');
    $this->addFieldMapping('field_story_time_instagram', 'timeinstagram')->xpath('timeinstagram');


    // $this->addFieldMapping('field_common_related_content', 'relatedcontents')->xpath('relatedcontents');
    $this->addFieldMapping('field_story_syndication', 'syndication')->xpath('syndication');
    $this->addFieldMapping('pathauto')->defaultValue(0);
    $this->addFieldMapping('path', 'sef_url')->xpath('metatags/sef_url');
    $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
    $this->addFieldMapping('metatag_description', 'metadescription')->xpath('metatags/metadescription');
    $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/keywords');
    //For New field
    $this->addFieldMapping('field_story_expert_description', 'short_description')->xpath('short_description');
    $this->addFieldMapping('field_story_strap_headline', 'strap_headline')->xpath('strap_headline');
    $this->addFieldMapping('field_story_short_introtext', 'content_url')->xpath('content_url');
    $this->addFieldMapping('migrate_redirects', 'content_url')->xpath('content_url');
    // source migrated
    $this->addFieldMapping('field_story_source_type')
        ->defaultValue('migrated');
    $this->addFieldMapping('field_itg_content_publish_date', 'created')->xpath('created'); // published date
    $this->addFieldMapping('field_featured_ordering', 'featured_ordering')->xpath('featured_ordering'); // published date
    $this->addFieldMapping('field_large_image_description', 'description')->xpath('description'); // Large image description
    
    
    $this->addUnmigratedDestinations(array('uid', 'promote', 'sticky', 'revision', 'log', 'language', 'tnid', 'translate', 'revision_uid', 'is_new',
//      'field_story_expiry_date:timezone',
//      'field_story_expiry_date:rrule',
//      'field_story_expiry_date:to',
      'field_story_extra_large_image:file_class',
      //'field_story_extra_large_image:preserve_files',
      'field_story_extra_large_image:destination_dir',
      'field_story_extra_large_image:destination_file',
      'field_story_extra_large_image:file_replace',
      'field_story_extra_large_image:source_dir',
      'field_story_extra_large_image:urlencode',
      'field_story_extra_small_image:file_class',
      //'field_story_extra_small_image:preserve_files',
      'field_story_extra_small_image:destination_dir',
      'field_story_extra_small_image:destination_file',
      //'field_story_extra_small_image:file_replace',
      'field_story_extra_small_image:source_dir',
      'field_story_extra_small_image:urlencode',
      'field_story_facebook_image:file_class',
      //'field_story_facebook_image:preserve_files',
      'field_story_facebook_image:destination_dir',
      'field_story_facebook_image:destination_file',
      //'field_story_facebook_image:file_replace',
      'field_story_facebook_image:source_dir',
      'field_story_facebook_image:urlencode',
      'field_story_facebook_video:file_class',
      'field_story_facebook_video:preserve_files',
      'field_story_facebook_video:destination_dir',
      'field_story_facebook_video:destination_file',
      'field_story_facebook_video:file_replace',
      'field_story_facebook_video:source_dir',
      'field_story_facebook_video:urlencode',
      'field_story_facebook_video:description',
      'field_story_facebook_video:display',
      'field_story_itg_tags',
      'field_story_itg_tags:source_type',
      'field_story_itg_tags:create_term',
      'field_story_itg_tags:ignore_case',
      'field_story_large_image:file_class',
      //'field_story_large_image:preserve_files',
      'field_story_large_image:destination_dir',
      'field_story_large_image:destination_file',
      'field_story_large_image:file_replace',
      'field_story_large_image:source_dir',
      'field_story_large_image:urlencode',
      'field_story_medium_image:file_class',
      //'field_story_medium_image:preserve_files',
      'field_story_medium_image:destination_file',
      'field_story_medium_image:file_replace',
      'field_story_medium_image:source_dir',
      'field_story_medium_image:urlencode',
      //'field_story_mosimage',
      'field_bulk_media_upload',
      'field_common_audio_file:file_class',
      'field_common_audio_file:preserve_files',
      'field_common_audio_file:destination_dir',
      'field_common_audio_file:destination_file',
      'field_common_audio_file:file_replace',
      'field_common_audio_file:source_dir',
      'field_common_audio_file:urlencode',
      'field_common_audio_file:description',
      'field_common_audio_file:display',
      'field_gallery_image',
      'field_gallery_image:revision_id',
      'field_story_time_facebook:timezone',
      'field_story_time_facebook:rrule',
      'field_story_time_facebook:to',
      'field_story_time_instagram:timezone',
      'field_story_time_instagram:rrule',
      'field_story_time_instagram:to',
      'field_story_time_twitter:timezone',
      'field_story_time_twitter:rrule',
      'field_story_time_twitter:to',
      'field_story_category',
      'field_story_category:source_type',
      'field_story_category:create_term',
      'field_story_category:ignore_case',
      'field_photogallery_configuration',
      //'field_itg_content_publish_date',
      'field_itg_content_publish_date:timezone',
      'field_itg_content_publish_date:rrule',
      'field_itg_content_publish_date:to',
      'field_itg_common_by_line_name',
      'field_common_related_content',
      'field_itg_common_by_line_twitter',
      'field_preview_unique_id',
      'field_story_medium_image:destination_dir',
      'field_story_node_identity',
      'field_story_small_image:file_class',
      'field_story_small_image:destination_dir',
      'field_story_small_image:destination_file',
      'field_story_small_image:file_replace',
      'field_story_small_image:source_dir',
      'field_story_small_image:urlencode',
      'field_story_social_media_integ',
      'field_story_source_id',
      'field_story_tweet_image:file_class',
      'field_story_tweet_image:destination_dir',
      'field_story_tweet_image:destination_file',
      'field_story_tweet_image:source_dir',
      'field_story_tweet_image:urlencode',
      'field_story_twitter_video:file_class',
      'field_story_twitter_video:preserve_files',
      'field_story_twitter_video:destination_dir',
      'field_story_twitter_video:destination_file',
      'field_story_twitter_video:file_replace',
      'field_story_twitter_video:source_dir',
      'field_story_twitter_video:urlencode',
      'field_story_twitter_video:description',
      'field_story_twitter_video:display',
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
      //'metatag_publisher',
      //'metatag_author',
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
      'field_story_facebook_video',
      'field_story_twitter_video',
      'field_story_facebook_image',
      'field_story_facebook_image:preserve_files',
      'field_story_facebook_image:file_replace',
      'field_story_facebook_image:alt',
      'field_story_facebook_image:title',
      'field_story_facebook_narrative',
      'field_story_tweet',
      'field_story_tweet_image',
      'field_story_tweet_image:preserve_files',
      'field_story_tweet_image:file_replace',
      'field_story_tweet_image:alt',
      'field_story_tweet_image:title',
      'field_cm_related_content_detail',
      'field_story_extra_data',
      'field_story_comment_question',
    ));
  }

  public function prepareRow($row) {

    if(empty($row->xml->modified) || (string) $row->xml->modified == 0) {
      $row->xml->modified = (string) $row->xml->created;
    }
    
    if (!empty($row->xml->extralargeimage)) {
      $row->xml->extralargeimage = itg_dbmigrate_imagepath_url((string) $row->xml->extralargeimage);
    }

    if (!empty($row->xml->large_image)) {
      $row->xml->large_image = itg_dbmigrate_imagepath_url((string) $row->xml->large_image);
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



    //syndication
    if ((string) $row->xml->syndication == '1') {
      $row->xml->syndication = 'Yes';
    }
    else {
      $row->xml->syndication = '';
    }

    // Category migrate
   /* $data_category = '';

    if (isset($row->xml->categories->category) && !empty($row->xml->categories->category)) {
      foreach ($row->xml->categories->category as $final_category) {
        $category_array = explode('#', $final_category);
        $last_value = end($category_array);
        $source_cid = (string) $final_category;
        $orignal_category = get_itg_destination_id('migrate_map_itgphoto', $source_cid);
        $data_category[]['tid'] = $orignal_category;
      }
    }
    $row->category_new = $data_category;*/
    
     $data_category = '';
    if (isset($row->xml->categories->category) && !empty($row->xml->categories->category)) {
      $cat = array();
      $tid_array = array();
      foreach ($row->xml->categories->category as $final_category) {
        $cat = explode('#', $final_category);
        foreach ($cat as $cc) {
          if(!empty($cc)) {
            $tid_array[] = get_itg_destination_id('migrate_map_itgphoto', $cc);
          }
        }
      }
      $tid_array[] = 1208521;
      $all_category = array_unique($tid_array);
      foreach ($all_category as $chunk_data) {
        $data_category[]['tid'] = $chunk_data;
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

    // Primary category
    if (isset($row->xml->primary_category) && !empty($row->xml->primary_category)) {
      $category_primary_array = explode('#', $row->xml->primary_category);
      $last_primary_value = end($category_primary_array);
      $source_cid = (string) $last_primary_value;
      $orignal_pcategory = get_itg_destination_id('migrate_map_itgphoto', $source_cid);
      $row->xml->primary_category = $orignal_pcategory;
    }


    if ((string) $row->xml->credittoall == 'yes') {
      $row->xml->credittoall = 1;
    }
    if ((string) $row->xml->commonaudio == 'yes') {
      $row->xml->commonaudio = 1;
    }
//    if ((string) $row->xml->syndication == 'yes') {
//      $row->xml->syndication = 'Yes';
//    }
    if (((string) $row->xml->featured == 1 ) && !empty($row->xml->featured)) {
      $row->xml->featured = 'yes';
    }
    return TRUE;
  }

  public function prepare($node, stdClass $row) {
    //drupal_set_message('<pre>'.print_r($row->xml->workbench_moderation_state_new, 1).'<pre>');
    $node->teaser = (string) $row->xml->description;

    if (!empty($row->category_new)) {
      $node->field_story_category[LANGUAGE_NONE] = $row->category_new;
    }
    if (!empty($row->tag_new)) {
      $node->field_story_itg_tags[LANGUAGE_NONE] = $row->tag_new;
    }
    if (!empty($row->final_social_checkbox)) {
      $node->field_story_social_media_integ[LANGUAGE_NONE] = $row->final_social_checkbox;
    }

    // modified by
    if (isset($row->xml->modified_by) && !empty($row->xml->modified_by)) {
      $modified_uid = (string) $row->xml->modified_by;
      $orignal_modified_uid = get_itg_destination_id('migrate_map_itguser', $modified_uid);
      $node->field_modify_by[LANGUAGE_NONE][0]['value'] = $orignal_modified_uid;
    }
    
    // manage created user
    if (isset($row->xml->created_by) && !empty($row->xml->created_by)) {
      $created_uid = (string) $row->xml->created_by;
      $orignal_crated_uid = get_itg_destination_id('migrate_map_itguser', $created_uid);
      $row->xml->created_by = $orignal_crated_uid;
    }
    else {
      $row->xml->created_by = 970; //siteadmin
    }
    $node->uid = (string) $row->xml->created_by;
  }

  public function complete($entity, $row) {
    print $row->xml->id.' ';
    $node = $entity;
    
     //code for order set
    //if (isset($row->xml->ordering) && !empty($row->xml->ordering)) {
    ordering_set_of_content($node, (string) $row->xml->ordering);
    //}
    //code for like and dislike
    if (isset($row->xml->like_dislike->like) || isset($row->xml->like_dislike->dislike)) {
      itg_flag_insert_like_dislike($node->nid, $row->xml->like_dislike->like, $row->xml->like_dislike->dislike);
    }
    // Related content save in db
    if (isset($row->xml->relatedcontents->relatedcontent) && !empty($row->xml->relatedcontents->relatedcontent)) {
      //$arr = array();
      foreach ($row->xml->relatedcontents->relatedcontent as $value) {
        $chk_variable = (string) $value;
        if (!empty($chk_variable)) {
          db_insert('itg_dbmigrate_related_content')
              ->fields(array(
                'migrated_nid' => $node->nid,
                'source_id' => (string) $value,
                'type' => (string) $value->attributes()->type,
                'migration_node_type' => 'photogallery',
                'xml_id' => (string) $row->xml->id,
              ))
              ->execute();
        }
      }
    }
    
    if (isset($row->xml->gallery->image_details) && !empty($row->xml->gallery->image_details)) {
      $key = 0;
      foreach ($row->xml->gallery->image_details as $value) {
        if ((string) $value->enable == 1) {
          $image_url = itg_dbmigrate_imagepath_url((string) $value->image_url);
          $caption = (string) $value->caption;
          $credit = (string) $value->credit;
          $strap_headline = (string) $value->strap_headline;
          $image_id = (string) $value->imageid;
          $img_meta_key = (string) $value->image_metakey;
          $api_image_url = '';
          if(!empty($value->api_image)){
            $api_image_url = itg_dbmigrate_imagepath_url((string) $value->api_image);
          }
           $small_image_url = '';
          if(!empty($value->gallery_smallimage)){
            $small_image_url = itg_dbmigrate_imagepath_url((string) $value->gallery_smallimage);
          }
          $enable = (string) $value->enable;
          // photoby
          $data_byline = '';
          if (isset($value->photo_by) && !empty($value->photo_by)) {
            $source_bid = (string) $value->photo_by;
            $orignal_byline = get_itg_destination_id('migrate_map_itgbyline', $source_bid);
            $data_byline[0]['target_id'] = $orignal_byline;
            $data_byline = array(LANGUAGE_NONE => $data_byline);
          }
          //$photo_by = (string) $value->photo_by;
          $audio = (string) $value->audio;
          $syndication = (string) $value->syndication;
          if (!empty($syndication)) {
            $syndication = 'yes';
          }
          //$image_url = (string) $value->image_url;
          $image = '';
          if (!empty($image_url)) {
            try{
            $file = file_save_data(file_get_contents($image_url), file_default_scheme() . '://' . basename($image_url), FILE_EXISTS_RENAME);
            $file->status = 1;
            $file->alt = (string) $value->gallery_alt;
            $file->title = (string) $value->gallery_title;
            $image = (array) $file;
            }
            catch(Exception $e) {
               //echo 'Message: ' .$e->getMessage();
            }
          }

          // Api image
          $api_image_file = '';
          $api_image_files = '';
          if (!empty($api_image_url)) {
            try{
            $api_file = file_save_data(file_get_contents($api_image_url), file_default_scheme() . '://' . basename($api_image_url), FILE_EXISTS_RENAME);
            $api_file->status = 1;
            $api_image_file = (array) $api_file;
            $api_image_files = array(LANGUAGE_NONE => array($api_image_file));
            }
            catch(Exception $e) {
              // echo 'Message: ' .$e->getMessage();
            }
          }
          
           // Small image
          $small_image_file = '';
          $small_image_files = '';
          if (!empty($small_image_url)) {
            try{
            $small_file = file_save_data(file_get_contents($small_image_url), file_default_scheme() . '://' . basename($small_image_url), FILE_EXISTS_RENAME);
            $small_file->status = 1;
            $small_image_file = (array) $small_file;
            $small_image_files = array(LANGUAGE_NONE => array($small_image_file));
            }
            catch(Exception $e) {
              // echo 'Message: ' .$e->getMessage();
            }
          }
          
          $values = array(
            'field_name' => 'field_gallery_image',
            'field_images' => array(LANGUAGE_NONE => array($image)),
            'field_image_caption' => array(LANGUAGE_NONE => array(array('value' => $caption))),
            'field_credit' => array(LANGUAGE_NONE => array(array('value' => $credit))),
            'field_photo_byline' => $data_byline, // photoby
            'field_story_strap_headline' => array(LANGUAGE_NONE => array(array('value' => $strap_headline))),
            //'field_audio' => array(LANGUAGE_NONE => array(array('value' => $credit))),
            'field_image_syndication' => array(LANGUAGE_NONE => array(array('value' => $syndication))),
            'field_image_id' => array(LANGUAGE_NONE => array(array('value' => $image_id))),
            'field_image_metakey' => array(LANGUAGE_NONE => array(array('value' => $img_meta_key))),
            'field_api_image' => $api_image_files,
            'field_photo_small_image' => $small_image_files,
            'field_photo_enable' => array(LANGUAGE_NONE => array(array( 'value' => $enable))),
          );
          $field_collection_item = entity_create('field_collection_item', $values);
          $field_collection_item->setHostEntity('node', $node);
          $field_collection_item->save(TRUE);
          $node->field_gallery_image[LANGUAGE_NONE][$key]['value'] = $field_collection_item->item_id;
          $key++;
        }
        else {

          $image_url_new = (string) $value->image_url;
          $caption_new = (string) $value->caption;
          $credit_credit = (string) $value->credit;
          $strap_headline_new = (string) $value->strap_headline;
          $image_id_new = (string) $value->imageid;
          $img_meta_key_new = (string) $value->image_metakey;
          $api_image_url_new = (string) $value->api_image;
          // photoby
          $data_byline_new = '';
          if (isset($value->photo_by) && !empty($value->photo_by)) {
            $source_bid = (string) $value->photo_by;
            $orignal_byline = get_itg_destination_id('migrate_map_itgbyline', $source_bid);
            $data_byline_new = $orignal_byline;
          }
          //$photo_by = (string) $value->photo_by;
          $audio_new = (string) $value->audio;
          $syndication_new = (string) $value->syndication;

          db_insert('itg_left_photo_gallery')
              ->fields(array(
                'nid' => $node->nid,
                'imageid' => $image_id_new,
                'image_url' => $image_url_new,
                'gallery_alt' => (string) $value->gallery_alt,
                'gallery_title' => (string) $value->gallery_title,
                'credit' => $credit_credit,
                'caption' => $caption_new,
                'ordering' => (string) $value->ordering,
                'enable' => (string) $value->enable,
                'smallimage' => (string) $value->smallimage,
                'image_metakey' => $img_meta_key_new,
                'strap_headline' => $strap_headline_new,
                'api_image' => $api_image_url_new,
                'photo_by' => $data_byline_new,
                'syndication' => $syndication_new,
                'audio' => (string) $value->audio,
              ))
              ->execute();
        }
      }
      field_attach_update('node', $node);
    }
  }

}
