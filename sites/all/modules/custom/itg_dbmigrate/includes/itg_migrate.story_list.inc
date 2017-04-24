<?php

//$fields complete
//maping pending

/**
 * ItgStoryMigration extends XMLMigration 
 */
class ItgStoryListMigration extends XMLMigration {

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
      //'byline' => t('byline'),
      'categories' => t('categories'),
      'category' => t('category'),
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
      'storykicker' => t('storykicker'),
      'storybody' => t('storybody'),
      'magazinekicker' => t('magazinekicker'),
      'magazineheadline' => t('magazineheadline'),
      //'tags' => t('tags'), //multi
      'shortheadline' => t('shortheadline'),
      'storytitle' => t('storytitle'),
      'storyrating' => t('storyrating'),
      'newtitle' => t('newtitle'),
      'redirectionurl' => t('redirectionurl'),
      'courtesy' => t('courtesy'),
      'snappost' => t('snappost'),
      //'socialmediaintegration' => t('socialmediaintegration'), //checkbox
      'facebooknarrative' => t('facebooknarrative'),
      'facebookimage' => t('facebookimage'),
      'facebookimage_alt' => t('facebookimage_alt'),
      'facebookimage_title' => t('facebookimage_title'),
      //'facebookvideonarrative' => t('facebookvideonarrative'),
      //'facebookvideo' => t('facebookvideo'),
      'twitternarrative' => t('twitternarrative'),
      'twitterimage' => t('twitterimage'),
      'twitterimage_alt' => t('twitterimage_alt'),
      'twitterimage_title' => t('twitterimage_title'),
      //'twittervideodescription' => t('twittervideodescription'),
      //'twittervideo' => t('twittervideo'),
      'syndication' => t('syndication'),
      //'mediafiles' => t('mediafiles'),
      //'client_title' => t('client_title'),
      //'configurations' => t('configurations'), //checkbox
      'commentquestion' => t('commentquestion'),
      'featuredname' => t('featuredname'), //id
      //'relatedcontents' => t('relatedcontents'), //multi
      //'scheduledatetime' => t('scheduledatetime'),
      //'storyexpires' => t('storyexpires'),
      //'storyexpirydate' => t('storyexpirydate'),
      'selectlisticletemplates' => t('selectlisticletemplates'),
      //'listicle_content' => t('listicle_content'), //multi
      //'quotes' => t('quotes'), //multi
      //'factoids_content' => t('factoids_content'), //multi
      //'buzz_content' => t('buzz_content'), //fieldcollection
      //'briefcase_content' => t('briefcase_content'), //multi
      'expertname' => t('expertname'),
      'expertimage' => t('expertimage'),
      'expert_alt' => t('expert_alt'),
      'expert_title' => t('expert_title'),
      'expertdescription' => t('expertdescription'),
      'archive' => t('archive'),
      //'common_by_line_name' => t('common_by_line_name'),
      //'common_by_line_twitter' => t('common_by_line_twitter'),
      //'associatetvdate' => t('associatetvdate'),
      //'field_story_syndications_photo' => t('field_story_syndications_photo'),
      'kicker_image_caption' => t('kicker_image_caption'),
      'short_introtext' => t('short_introtext'),
      'listicle_title' => t('listicle_title'),
      'quote_title' => t('quote_title'),
      'quote_image' => t('quote_image'),
      'factoids_title' => t('factoids_title'),
      'title' => t('title'),
      'rating' => t('rating'),
      'pron_cons_img' => t('pron_cons_img'),
      'item' => t('item'),
      'factoids_title' => t('factoids_title'),
      'sefurl' => t('sefurl'),
      'pagetitle' => t('Page title'),
      //'description' => t('Description'),
      'keywords' => t('Keywords'),
      'audio_position' => t('audio_position'),
      'audio_url' => t('audio_url'),
      'animated_image_position' => t('animated_image_position'),
      'animated_image' => t('animated_image'),
      'map_embed_code_position' => t('map_embed_code_position'),
      'map_embed_code' => t('map_embed_code'),
      'social_embed_code_position' => t('social_embed_code_position'),
      'social_embed_code' => t('social_embed_code'),
      // warnings msg
      'format' => t('format'),
      'modifieddate' => t('modifieddate'),
      'createddate' => t('createddate'),
      'publisheddate' => t('publisheddate'),
      'strapheadline' => t('strapheadline'),
      'image' => t('image'),
      'state' => t('state'),
      'syndications_photo' => t('syndications_photo'),
      'uid' => t('uid'),
      'tech_image_gallery' => t('tech_image_gallery'),
      'tech_cons' => t('tech_cons'),
      'tech_pros' => t('tech_pros'),
      'bigimage' => t('bigimage'),
      'metadescription' => t('metadescription'),
    );


    // This can also be an URL instead of a local file path.
    $file_path = DRUPAL_ROOT . '/' .'sites/default/files';

    //$xml_folder = $file_path . '/' . 'migrate/xml_file/stories';

    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/story';

    
     $this->map = new MigrateSQLMap($this->machineName, array(
      'id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      )
        ), MigrateDestinationNode::getKeySchema()
    );
    $xml_folder = $file_path.'/migrate/xml_file/stories';
    $list_url = $xml_folder . '/index.xml';


    $item_url = $xml_folder . '/:id.xml';
    $item_ID_xpath = 'id';
//    $this->source = new MigrateSourceList(new MigrateListFiles($xml_folder),
//      new MigrateItemXML($item_url), $fields);
    $this->source = new MigrateSourceList(new MigrateListXML($list_url),
      new MigrateItemXML($item_url), $fields);
    $this->destination = new MigrateDestinationNode('story');

    // The source ID here is the one retrieved from each data item in the XML
    // file, and used to identify specific items
   

    // TIP: Note that for XML sources, in addition to the source field passed to
    // addFieldMapping (the name under which it will be saved in the data row
    // passed through the migration process) we specify the Xpath used to
    // retrieve the value from the XML.
    // TIP: Note that all xpaths for fields begin at the last element of the
    // item xpath since each item xml chunk is processed individually.
    // (ex. xpath=name is equivalent to a full xpath of
    // /categories/category/name).
    $this->addFieldMapping('field_story_long_head_line', 'storytitle')->xpath('storytitle');
    $this->addFieldMapping('status', 'state')->xpath('state');
    
    //code for date
    $this->addFieldMapping('created', 'createddate')->xpath('createddate');   
    $this->addFieldMapping('uid', 'createdby')->xpath('createdby')
        ->defaultValue(1);    
    $this->addFieldMapping('changed', 'modifieddate')->xpath('modifieddate');
    $this->addFieldMapping('field_story_schedule_date_time', 'publisheddate')->xpath('publisheddate');
    $this->addFieldMapping('field_itg_content_publish_date', 'publisheddate')->xpath('publisheddate');
    //$this->addFieldMapping('field_story_expires', 'storyexpires')->xpath('storyexpires');
    //$this->addFieldMapping('field_story_expiry_date', 'storyexpirydate')->xpath('storyexpirydate');

    //code for user
    //<createdby>2345</createdby><modifiedby>2345</modifiedby>//save in custom table
    
    //code for issue
    $this->addFieldMapping('field_story_magazine_story_issue', 'story_issue')->xpath('story_issue');
    $this->addFieldMapping('field_story_select_magazine', 'select_magazine')->xpath('select_magazine');
    $this->addFieldMapping('field_story_select_supplement', 'select_supplement')->xpath('select_supplement');
    $this->addFieldMapping('field_story_issue_date', 'issue_date')->xpath('issue_date'); //for issue date migration*/
    //$this->addFieldMapping('field_poll_start_date', 'associatetvdate')->xpath('associatetvdate');
    
    $this->addFieldMapping('title', 'longheadline')->xpath('longheadline');
    $this->addFieldMapping('field_story_short_headline', 'shortheadline')->xpath('shortheadline');
    
    $this->addFieldMapping('field_primary_category', 'primarycategory')->xpath('primarycategory');
    
    //code for body
    $this->addFieldMapping('body', 'storybody')->xpath('storybody');
    $this->addFieldMapping('body:format', 'format')
         ->defaultValue('full_html');
    //code for image
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
    $this->addFieldMapping('field_story_small_image:alt', 'smallimage_alt')->xpath('smallimage_alt');
    $this->addFieldMapping('field_story_small_image:title', 'smallimage_title')->xpath('smallimage_title');
    
    $this->addFieldMapping('field_story_extra_small_image', 'extrasmallimage')->xpath('extrasmallimage');
    $this->addFieldMapping('field_story_extra_small_image:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_extra_small_image:file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_story_extra_small_image:alt', 'extra_small_alt')->xpath('extra_small_alt');
    $this->addFieldMapping('field_story_extra_small_image:title', 'extra_small_title')->xpath('extra_small_title');
    
    $this->addFieldMapping('field_story_kicker_text', 'storykicker')->xpath('storykicker');
    $this->addFieldMapping('field_story_magazine_kicker_text', 'magazinekicker')->xpath('magazinekicker');
    $this->addFieldMapping('field_story_magazine_headline', 'magazineheadline')->xpath('magazineheadline');
    $this->addFieldMapping('field_story_rating', 'storyrating')->xpath('storyrating');
    $this->addFieldMapping('field_story_new_title', 'newtitle')->xpath('newtitle');
    //$this->addFieldMapping('field_story_redirection_url_titl', 'redirectionurl')->xpath('redirectionurl');
    $this->addFieldMapping('field_story_courtesy', 'courtesy')->xpath('courtesy');
    $this->addFieldMapping('field_story_snap_post', 'snappost')->xpath('snappost');
    
    //code for social media
   /* $this->addFieldMapping('field_story_facebook_narrative', 'facebooknarrative')->xpath('facebooknarrative');
    $this->addFieldMapping('field_story_facebook_image', 'facebookimage')->xpath('facebookimage');
    $this->addFieldMapping('field_story_facebook_image:file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_story_facebook_image:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_facebook_image:alt', 'facebookimage_alt')->xpath('facebookimage_alt');
    $this->addFieldMapping('field_story_facebook_image:title', 'facebookimage_title')->xpath('facebookimage_title');
    //$this->addFieldMapping('field_story_facebook_vdescripti', 'facebookvideonarrative')->xpath('facebookvideonarrative');
    //$this->addFieldMapping('field_story_facebook_video', 'facebookvideo')->xpath('facebookvideo'); confirmed no data in xml
    $this->addFieldMapping('field_story_tweet', 'twitternarrative')->xpath('twitternarrative');
    $this->addFieldMapping('field_story_tweet_image', 'twitterimage')->xpath('twitterimage');
    $this->addFieldMapping('field_story_tweet_image:file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_story_tweet_image:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_tweet_image:alt', 'twitterimage_alt')->xpath('twitterimage_alt');
    $this->addFieldMapping('field_story_tweet_image:title', 'twitterimage_title')->xpath('twitterimage_title');*/
    //$this->addFieldMapping('field_story_twitter_video_desc', 'twittervideodescription')->xpath('twittervideodescription');
    //$this->addFieldMapping('field_story_twitter_video', 'twittervideo')->xpath('twittervideo'); confirmed no data in xml    
    //$this->addFieldMapping('field_story_media_files_syndicat', 'mediafiles')->xpath('mediafiles');
    //$this->addFieldMapping('field_story_client_title', 'client_title')->xpath('client_title');
    $this->addFieldMapping('field_story_syndication', 'syndication')->xpath('syndication');
    $this->addFieldMapping('field_story_archive', 'archive')->xpath('archive');
    $this->addFieldMapping('field_story_comment_question', 'commentquestion')->xpath('commentquestion');
    $this->addFieldMapping('field_story_featured_name', 'featuredname')->xpath('featuredname'); //id
    
    $this->addFieldMapping('field_story_templates', 'selectlisticletemplates')->xpath('selectlisticletemplates');
    $this->addFieldMapping('field_story_expert_name', 'expertname')->xpath('expertname');
    $this->addFieldMapping('field_story_expert_image', 'expertimage')->xpath('expertimage'); // image
    $this->addFieldMapping('field_story_expert_image:file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_story_expert_image:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_expert_image:alt', 'expert_alt')->xpath('expert_alt');
    $this->addFieldMapping('field_story_expert_image:title', 'expert_title')->xpath('expert_title');
    $this->addFieldMapping('field_story_expert_description', 'expertdescription')->xpath('expertdescription');
    
    //New field
    $this->addFieldMapping('field_story_syndications_photo', 'syndications_photo')->xpath('syndications_photo');
    $this->addFieldMapping('field_story_kicker_image_caption', 'kicker_image_caption')->xpath('kicker_image_caption');
    $this->addFieldMapping('field_story_short_introtext', 'short_introtext')->xpath('short_introtext');
    $this->addFieldMapping('field_story_strap_headline', 'strapheadline')->xpath('strapheadline');
    $this->addFieldMapping('field_story_template_guru', 'listicle_title')->xpath('fulltext_conclaveformat/listicle_title');
    $this->addFieldMapping('field_story_quote_title', 'quote_title')->xpath('fulltext_conclaveformat/quote_title');
    $this->addFieldMapping('field_story_factoids_title', 'factoids_title')->xpath('fulltext_conclaveformat/factoids_title');
    $this->addFieldMapping('field_story_quote_image', 'quote_image')->xpath('fulltext_conclaveformat/quote_image'); // image
     $this->addFieldMapping('field_story_quote_image:file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_story_quote_image:preserve_files')
         ->defaultValue(TRUE);
    
    //confused
    $this->addFieldMapping('field_story_tech_pros_cons_title', 'title')->xpath('pros_cons/tech_pros_cons_main/title');
    $this->addFieldMapping('field_story_tech_pros_cons_ratin', 'rating')->xpath('pros_cons/tech_pros_cons_main/rating');
    $this->addFieldMapping('field_story_tech_pros_cons_image', 'pron_cons_img')->xpath('pros_cons/tech_pros_cons_main/pron_cons_img');
    $this->addFieldMapping('field_story_tech_pros_cons_image:file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_story_tech_pros_cons_image:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_technology_pros', 'item')->xpath('pros_cons/tech_pros/item');
    $this->addFieldMapping('field_story_technology_cons', 'item')->xpath('pros_cons/tech_cons/item');
    $this->addFieldMapping('field_story_tech_image_gallery', 'image')->xpath('tech_image_gallery/image'); // image
    $this->addFieldMapping('field_story_tech_image_gallery:file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_story_tech_image_gallery:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('pathauto')->defaultValue(0);
    $this->addFieldMapping('path', 'sefurl')->xpath('metatags/sefurl');
    $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
    $this->addFieldMapping('metatag_description', 'metadescription')->xpath('metatags/metadescription');
    $this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/keywords');
    // Facebook instant Article migrate code
    $this->addFieldMapping('field_facebook_audio_position', 'audio_position')->xpath('facebook_instant_article_integration/audio_position');
    $this->addFieldMapping('field_facebook_instant_audio_url', 'audio_url')->xpath('facebook_instant_article_integration/audio_url');
    $this->addFieldMapping('field_animated_image_position', 'animated_image_position')->xpath('facebook_instant_article_integration/animated_image_position');
    $this->addFieldMapping('field_facebook_animated_image', 'animated_image')->xpath('facebook_instant_article_integration/animated_image');
    $this->addFieldMapping('field_facebook_animated_image:file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_facebook_animated_image:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_story_big_image', 'bigimage')->xpath('bigimage');
    $this->addFieldMapping('field_story_big_image:file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_story_big_image:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_facebook_map_position', 'map_embed_code_position')->xpath('facebook_instant_article_integration/map_embed_code_position');
    $this->addFieldMapping('field_map_embed_code', 'map_embed_code')->xpath('facebook_instant_article_integration/map_embed_code');
    $this->addFieldMapping('field_social_embed_code', 'social_embed_code')->xpath('facebook_instant_article_integration/social_embed_code');
    $this->addFieldMapping('field_social_embed_code_position', 'social_embed_code_position')->xpath('facebook_instant_article_integration/social_embed_code_position');
    $this->addFieldMapping('migrate_redirects', 'redirectionurl')->xpath('redirectionurl');
    // source migrated
    $this->addFieldMapping('field_story_source_type')
        ->defaultValue('migrated');
    //$this->addFieldMapping('field_story_category', 'category')->xpath('categories/category');
    $this->addFieldMapping('field_story_mosimage', 'mosimage')->xpath('mosimage/image');
    
    $this->addUnmigratedDestinations(array('promote', 'sticky', 'revision', 'log', 'language', 'tnid', 'translate', 'revision_uid', 'is_new', 'body:summary', 'field_common_by_line_reporter_id', 'field_common_related_content', 'field_emoji', 'field_emoji:format', 'field_emoji_position', 'field_facebook_animated_image:file_class',
      'field_facebook_animated_image:destination_dir',
      'field_facebook_animated_image:destination_file',
      //'field_facebook_animated_image:file_replace',
      'field_facebook_animated_image:source_dir',
      'field_facebook_animated_image:urlencode',
      'field_facebook_animated_image:alt',
      'field_facebook_animated_image:title',
      'field_facebook_gallery_associate',
      'field_facebook_gallery_associate:revision_id',
      'field_itg_common_by_line_name',
      'field_itg_common_by_line_twitter',
      'field_photo_story',
      'field_photo_story:revision_id',
      'field_reporter_publish_id',
      'field_reporter_unique_id',
      'field_story_associate_lead',
      /*'field_story_category',*/
//      'field_story_category:source_type',
//      'field_story_category:create_term',
//      'field_story_category:ignore_case',
      'field_story_configurations',
      'field_story_expert_image:file_class',
      //'field_story_expert_image:preserve_files',
      'field_story_expert_image:destination_dir',
      'field_story_expert_image:destination_file',
      //'field_story_expert_image:file_replace',
      'field_story_expert_image:source_dir',
      'field_story_expert_image:urlencode',
      'field_story_expertise',
      'field_story_expiry_date:timezone',
      'field_story_expiry_date:rrule',
      'field_story_expiry_date:to',
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
      'field_story_featured_name:source_type',
      'field_story_featured_name:create_term',
      'field_story_featured_name:ignore_case',
      'field_story_highlights',
      'field_story_issue_date:timezone',
      'field_story_issue_date:rrule',
      'field_story_issue_date:to',
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
      'field_story_listicle',
      'field_story_listicle:revision_id',
      'field_story_medium_image:file_class',
      //'field_story_medium_image:preserve_files',
      'field_story_medium_image:destination_dir ',
      'field_story_medium_image:destination_file',
      'field_story_medium_image:file_replace',
      'field_story_medium_image:source_dir',
      'field_story_medium_image:urlencode',
      //'field_story_mosimage',
      'field_story_node_identity',
      'field_story_quote_image:file_class',
      //'field_story_quote_image:preserve_files',
      'field_story_quote_image:destination_dir',
      'field_story_quote_image:destination_file',
      //'field_story_quote_image:file_replace',
      'field_story_quote_image:source_dir',
      'field_story_quote_image:urlencode',
      'field_story_quote_image:alt',
      'field_story_quote_image:title',
      'field_story_reporter',
      'field_story_schedule_date_time:timezone',
      'field_story_schedule_date_time:rrule',
      'field_story_schedule_date_time:to',
      'field_story_select_templates',
      'field_story_small_image:file_class',
      //'field_story_small_image:preserve_files',
      'field_story_small_image:destination_dir',
      'field_story_small_image:destination_file',
      'field_story_small_image:file_replace',
      'field_story_small_image:source_dir',
      'field_story_small_image:urlencode',
      'field_story_social_media_integ',
      'field_story_source_id',
      'field_story_tech_image_gallery:file_class',
      //'field_story_tech_image_gallery:preserve_files',
      'field_story_tech_image_gallery:destination_dir',
      'field_story_tech_image_gallery:destination_file',
      //'field_story_tech_image_gallery:file_replace',
      'field_story_tech_image_gallery:source_dir',
      'field_story_tech_image_gallery:urlencode',
      'field_story_tech_image_gallery:alt',
      'field_story_tech_image_gallery:title',
      'field_story_tech_pros_cons_image:file_class',
      //'field_story_tech_pros_cons_image:preserve_files',
      'field_story_tech_pros_cons_image:destination_dir',
      'field_story_tech_pros_cons_image:destination_file',
      //'field_story_tech_pros_cons_image:file_replace',
      'field_story_tech_pros_cons_image:source_dir',
      'field_story_tech_pros_cons_image:urlencode',
      'field_story_tech_pros_cons_image:alt',
      'field_story_tech_pros_cons_image:title',
      'field_story_tech_review_chunk',
      'field_story_tech_review_chunk:summary',
      'field_story_tech_review_chunk:format',
      'field_story_technology',
      'field_story_technology:revision_id',
      'field_story_technology_rating',
      'field_story_template_buzz',
      'field_story_template_buzz:revision_id',
      'field_story_template_factoids',
      'field_story_template_quotes',
      'field_story_tv_time',
      'field_story_tweet_image:file_class',
      //'field_story_tweet_image:preserve_files',
      'field_story_tweet_image:destination_dir',
      'field_story_tweet_image:destination_file',
      //'field_story_tweet_image:file_replace',
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
      'field_story_type',
      'field_story_ugc_source_id',
      'field_stroy_city',
      'field_stroy_city:source_type',
      'field_stroy_city:create_term',
      'field_stroy_city:ignore_case',
      'field_associate_photo_gallery',
      'field_mega_review_cast',
      'field_mega_review_director',
      'field_mega_review_movie_plot',
      'field_poll_start_date:timezone',
      'field_poll_start_date:rrule',
      'field_poll_start_date:to',
      'field_preview_unique_id',
      'field_story_associate_video',
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
      'field_story_facebook_video',
      'field_story_twitter_video',
      'field_story_expiry_date',
      'field_story_expires',
      'field_story_medium_image:destination_dir',
      'field_poll_start_date',
      'field_story_category',
      'field_story_category:source_type',
      'field_story_category:create_term',
      'field_story_category:ignore_case',
      'field_itg_content_publish_date:timezone',
      'field_itg_content_publish_date:rrule',
      'field_itg_content_publish_date:to',
      'field_story_big_image:file_class',
      'field_story_big_image:destination_dir',
      'field_story_big_image:destination_file',
      'field_story_big_image:source_dir',
      'field_story_big_image:urlencode',
      'field_emoji_2',
      'field_emoji_2:format',
      'field_cm_related_content_detail',
      'field_story_extra_data',
      ));
  }

  public function prepareRow($row) {
    if(empty($row->xml->modifieddate) || ((string) $row->xml->modifieddate == 0)) {
      $row->xml->modifieddate = $row->xml->createddate;
    }
    
    if(!empty($row->xml->pros_cons->tech_pros_cons_main->pron_cons_img)) {
      $row->xml->pros_cons->tech_pros_cons_main->pron_cons_img = itg_dbmigrate_imagepath_url((string)$row->xml->pros_cons->tech_pros_cons_main->pron_cons_img);
    }
    // tech images
    if(!empty($row->xml->tech_image_gallery->image)) {
      $key = 0;
      foreach($row->xml->tech_image_gallery->image as $image){
        $img_val = (string) $image;
        if(!empty($img_val)){
          try{
            $row->xml->tech_image_gallery->image[$key] = itg_dbmigrate_imagepath_url($img_val);
            $key++;
          } catch(Exception $e) {
              // echo 'Message: ' .$e->getMessage();
          }
        }
      }
    }
    
    // Image prepare
    if(!empty($row->xml->facebook_instant_article_integration->animated_image)) {
      $row->xml->facebook_instant_article_integration->animated_image = itg_dbmigrate_imagepath_url((string)$row->xml->facebook_instant_article_integration->animated_image);
    }
    
    if(!empty($row->xml->extralargeimage)) {
      $row->xml->extralargeimage = itg_dbmigrate_imagepath_url((string)$row->xml->extralargeimage);
    }
    
    if(!empty($row->xml->largeimage)) {
      $row->xml->largeimage = itg_dbmigrate_imagepath_url((string)$row->xml->largeimage);
    }    
    if(!empty($row->xml->mediumimage)) {
      $row->xml->mediumimage = itg_dbmigrate_imagepath_url((string)$row->xml->mediumimage);
    }
    
    if(!empty($row->xml->smallimage)) {
      $row->xml->smallimage = itg_dbmigrate_imagepath_url((string)$row->xml->smallimage);
    }
    
    if(!empty($row->xml->extrasmallimage)) {
      $row->xml->extrasmallimage = itg_dbmigrate_imagepath_url((string)$row->xml->extrasmallimage);
    }
    
    if(!empty($row->xml->bigimage)) {
      $row->xml->bigimage = itg_dbmigrate_imagepath_url((string)$row->xml->bigimage);
    }
    
    if(!empty($row->xml->facebookimage)) {
      $row->xml->facebookimage = itg_dbmigrate_imagepath_url((string)$row->xml->facebookimage);
    }
    
    if(!empty($row->xml->twitterimage)) {
      $row->xml->twitterimage = itg_dbmigrate_imagepath_url((string)$row->xml->twitterimage);
    }
    
    if(!empty($row->xml->quote_image)) {
      $row->xml->quote_image = itg_dbmigrate_imagepath_url((string)$row->xml->quote_image);
    }

    // prepare row for quote
    $data_quotes = '';
    if (isset($row->xml->fulltext_conclaveformat->quotes->quote) && !empty($row->xml->fulltext_conclaveformat->quotes->quote)) {
      foreach ($row->xml->fulltext_conclaveformat->quotes->quote as $final_quote) {
        $data_quotes[]['value'] = (string) $final_quote;
      }
    }
    $row->quotes_new = $data_quotes;
    // end prepare row for quote
    // prepare row for factoids
    $data_factoids = '';
    if (isset($row->xml->fulltext_conclaveformat->factoids_content->factoids) && !empty($row->xml->fulltext_conclaveformat->factoids_content->factoids)) {
      foreach ($row->xml->fulltext_conclaveformat->factoids_content->factoids as $final_factoids) {
        $data_factoids[]['value'] = (string) $final_factoids;
      }
    }
    $row->factoids_new = $data_factoids;
    // end prepare row for factoids
    
    // Category migrate with shift marking
    $data_category = '';
    if (isset($row->xml->categories->category) && !empty($row->xml->categories->category)) {
      $cat = array();
      $tid_array = array();
      foreach ($row->xml->categories->category as $final_category) {
        $cat = explode('#', $final_category);
        foreach ($cat as $cc) {
          $tid_array[] = (string) $cc;
        }
      }
      $all_category = array_unique($tid_array);
      foreach ($all_category as $chunk_data) {
        $data_category[]['tid'] = $chunk_data;
      }
    }
    $row->category_new = $data_category;
    // End category migrate
    // Story tags migration
    $data_tags = '';

    if (isset($row->xml->tags->tag) && !empty($row->xml->tags->tag)) {
      foreach ($row->xml->tags->tag as $final_tags) {
        $data_tags[]['tid'] = (string) $final_tags;
      }
    }
    $row->tag_new = $data_tags;
    // End story tags migration
    
    // Story city migration
    $data_city = '';

    if (isset($row->xml->cities->city) && !empty($row->xml->cities->city)) {
      foreach ($row->xml->cities->city as $final_city) {
        $data_city[]['tid'] = (string) $final_city;
      }
    }
    $row->city_new = $data_city;
    // End story city migration
    
    // Brifcase migration
    $data_brifcase = '';

    if (isset($row->xml->briefcase_content->briefcase) && !empty($row->xml->briefcase_content->briefcase)) {
      foreach ($row->xml->briefcase_content->briefcase as $final_briefcase) {
        $data_brifcase[]['value'] = (string) $final_briefcase;
      }
    }
    $row->brifcase_new = $data_brifcase;


    // change checkboxes value
    if ((string) $row->xml->story_issue == 'yes') {
      $row->xml->story_issue = 'magazine_issue_story';
    }else{
      $row->xml->story_issue = '';
    }
    // select magazine select_magazine
    if ((string) $row->xml->select_magazine == 0) {
      $row->xml->select_magazine = '';
    }
    
    if ((string) $row->xml->selectlisticletemplates == 1) {
      $row->xml->selectlisticletemplates = 'bullet_points';
    }
    elseif ((string) $row->xml->selectlisticletemplates == 2) {
      $row->xml->selectlisticletemplates = 'number_list';
    }
    //Story expire
    if ((string) $row->xml->storyexpires == true) {
      $row->xml->storyexpires = 'Yes';
    }
    //social media integration checkboxes
    if (isset($row->xml->socialmediaintegration) && !empty($row->xml->socialmediaintegration)) {
      foreach ($row->xml->socialmediaintegration as $key => $social_option) {
        if ((string) $social_option->facebook == 1) {
          $final_social[]['value'] = 'facebook';
        }
        if ((string) $social_option->facebook_instant_article == 1) {
          $final_social[]['value'] = 'facebook_instant_article';
        }
        if ((string) $social_option->twitter == 1) {
          $final_social[]['value'] = 'twitter';
        }
      }
    }
    $row->final_social_checkbox = $final_social;
    // Configuration settings

    if (isset($row->xml->configurations) && !empty($row->xml->configurations)) {
      foreach ($row->xml->configurations as $key => $option) {
        if ((string) $option->breakingnews == 1) {
          $final_option[]['value'] = 'breaking_news';
        }
        if ((string) $option->googlestandout == 1) {
          $final_option[]['value'] = 'google_standout';
        }
        if ((string) $option->comment == 1) {
          $final_option[]['value'] = 'comment';
        }
        if ((string) $option->mediumstylecomment == 1) {
          $final_option[]['value'] = 'medium_style_comment';
        }
        if ((string) $option->setfeature == 1) {
          $final_option[]['value'] = 'display_lock';
        }
        if ((string) $option->displaylock == 1) {
          $final_option[]['value'] = 'set_as_featured';
        }
        if ((string) $option->associatetv == 1) {
          $final_option[]['value'] = 'tv';
        }        
      }
    }
    if ((string) $row->xml->commentbox == 1 && !empty($row->xml->commentbox)) {
          $final_option[]['value'] = 'commentbox';
        }
    
    if ((string) $row->xml->noindex_nofollow == 1) {
      $final_option[]['value'] = 'noindex_nofollow';
    }
    $row->final_config_option = $final_option;
    return TRUE;
  }

  public function prepare($node, stdClass $row) {
    $node->teaser = (string) $row->xml->storybody;
    if (!empty($row->quotes_new)) {
      $node->field_story_template_quotes[LANGUAGE_NONE] = $row->quotes_new;
    }
    if (!empty($row->factoids_new)) {
      $node->field_story_template_factoids[LANGUAGE_NONE] = $row->factoids_new;
    }
    if (!empty($row->brifcase_new)) {
      $node->field_story_highlights[LANGUAGE_NONE] = $row->brifcase_new;
    }
    if (!empty($row->category_new)) {
      $node->field_story_category[LANGUAGE_NONE] = $row->category_new;
    }
    if (!empty($row->tag_new)) {
      $node->field_story_itg_tags[LANGUAGE_NONE] = $row->tag_new;
    }
    
    if (!empty($row->city_new)) {
      $node->field_stroy_city[LANGUAGE_NONE] = $row->city_new;
    }
    if (!empty($row->final_config_option)) {
      $node->field_story_configurations[LANGUAGE_NONE] = $row->final_config_option;
    }
    if (!empty($row->final_social_checkbox)) {
      $node->field_story_social_media_integ[LANGUAGE_NONE] = $row->final_social_checkbox;
    }
    if(!empty($row->featuredname)){
      $node->field_story_featured_name[LANGUAGE_NONE][0]['tid'] = (string) $row->featuredname;
    }
  }

  public function complete($entity, $row) {
  print $row->xml->id.' ';
    $node = $entity;
    if (isset($row->xml->buzz_content->buzz) && (!empty($row->xml->buzz_content->buzz->headline) || !empty($row->xml->buzz_content->buzz->image) || !empty($row->xml->buzz_content->buzz->description))) {
      
      $key = 0;
      foreach ($row->xml->buzz_content->buzz as $buzz_value) {
        if(!empty($buzz_value->headline) || !empty($buzz_value->image) || !empty($buzz_value->description)){
        $headline = (string) $buzz_value->headline;
        $image_url = (string) $buzz_value->image;
        if (!empty($image_url)) {
            try{
            $file = file_save_data(file_get_contents($image_url), file_default_scheme() . '://' . basename($image_url), FILE_EXISTS_RENAME);
            $file->status = 1;
            $file->alt = (string) $buzz_value->buzz_alt;
            $file->title = (string) $buzz_value->buzz_title;
            $image = (array) $file;
            }
            catch(Exception $e) {
              // echo 'Message: ' .$e->getMessage();
            }
          }
        
        $description = (string) $buzz_value->description;
        $buzz_values = array(
          'field_name' => 'field_story_template_buzz',
          'field_buzz_headline' => array(LANGUAGE_NONE => array(array('value' => $headline))),
          'field_buzz_image' => array(LANGUAGE_NONE => array($image)),
          'field_buzz_description' => array(LANGUAGE_NONE => array(array('value' => $description))),
        );
        $field_collection_item = entity_create('field_collection_item', $buzz_values);
        $field_collection_item->setHostEntity('node', $node);
        $field_collection_item->save(TRUE);
        $node->field_story_template_buzz[LANGUAGE_NONE][$key]['value'] = $field_collection_item->item_id;
        $key++;
        }
      }
    }
    if (isset($row->xml->fulltext_conclaveformat->listicle_content->listicle)) {
      $count=0;
     
      foreach ($row->xml->fulltext_conclaveformat->listicle_content->listicle as $value) {
        $listicle = (string) $value;
        $values = array(
          'field_name' => 'field_story_listicle',
          'field_story_listicle_description' => array(LANGUAGE_NONE => array(array('value' => $listicle))),          
        );
        $field_collection_item_listicle = entity_create('field_collection_item', $values);
        $field_collection_item_listicle->setHostEntity('node', $node);
        $field_collection_item_listicle->save(TRUE);
        $node->field_story_listicle[LANGUAGE_NONE][$count]['value'] = $field_collection_item_listicle->item_id;
        $count++;
      }
    }
    
    //facebook instant article filed
    /*if (isset($row->xml->facebook_instant_article_integration->gallery_associate_content->gallery_associate) && !empty($row->xml->facebook_instant_article_integration->gallery_associate_content->gallery_associate->gallery_id)) {
      $pos_count=0;
      foreach ($row->xml->facebook_instant_article_integration->gallery_associate_content->gallery_associate as $facebook_article) {
       if(!empty($facebook_article->gallery_id_position) || !empty($facebook_article->gallery_id)){
        $position = (string) $facebook_article->gallery_id_position;
        $gallery_id = (string) $facebook_article->gallery_id;
        $values = array(
          'field_name' => 'field_facebook_gallery_associate',
          'field_gallery_position' => array(LANGUAGE_NONE => array(array('value' => $position))),          
          //'field_associate_gallery_id' => array(LANGUAGE_NONE => array(array('target_id' => $gallery_id))),          
        );
        $field_collection_item_facebook = entity_create('field_collection_item', $values);
        $field_collection_item_facebook->setHostEntity('node', $node);
        $field_collection_item_facebook->save(TRUE);
        $node->field_facebook_gallery_associate[LANGUAGE_NONE][$pos_count]['value'] = $field_collection_item_facebook->item_id;
        $pos_count++;
       }
      }
    }*/
    $node->field_reporter_unique_id[LANGUAGE_NONE][0]['value'] = 'migrated-'.$node->nid;
   if (isset($row->xml->buzz_content->buzz) || isset($row->xml->fulltext_conclaveformat->listicle_content->listicle) || (isset($row->xml->facebook_instant_article_integration->gallery_associate_content->gallery_associate) || !empty($row->xml->facebook_instant_article_integration->gallery_associate_content->gallery_associate))) {
      
      field_attach_update('node', $node);
   }
   //code for like and dislike
   if (isset($row->xml->like_dislike->like) || isset($row->xml->like_dislike->dislike)) {
     itg_flag_insert_like_dislike($node->nid, $row->xml->like_dislike->like, $row->xml->like_dislike->dislike);
   }

   
   //code for order set
   //if (isset($row->xml->ordering)) {
     ordering_set_of_content($node, $row->xml->ordering);
   //}
   
   // Related content save in db
     /*if (isset($row->xml->relatedcontents->relatedcontent) && !empty($row->xml->relatedcontents->relatedcontent)) {
     //$arr = array();
      foreach ($row->xml->relatedcontents->relatedcontent as $value) {
        $chk_variable = (string) $value;
        if(!empty($chk_variable)){
          db_insert('itg_dbmigrate_related_content')
                            ->fields(array(
                                'migrated_nid' => $node->nid,
                                'source_id' => (string) $value,
                                'type' => (string) $value->attributes()->type,
                                'migration_node_type' => 'story',
                                'xml_id' => (string) $row->xml->id,
                            ))
                            ->execute();
        }
      }
    }*/
     if (isset($row->xml->bylines->byline) && !empty($row->xml->bylines->byline)) {
       
      foreach ($row->xml->bylines->byline as $final_byline) {
       
        $source_bid = (string) $final_byline;
         if(!empty($source_bid)){
          $value = itg_db_migrate_bylines($source_bid, $node->nid);
         }
      }
    }
   
    // left field save in table
    if (isset($row->xml->facebook_instant_article_integration->gallery_associate_content->gallery_associate) && !empty($row->xml->facebook_instant_article_integration->gallery_associate_content->gallery_associate->gallery_id)) {
      $keys = 0;
      foreach ($row->xml->facebook_instant_article_integration->gallery_associate_content->gallery_associate as $facebook_article) {
        if (!empty($facebook_article->gallery_id_position) || !empty($facebook_article->gallery_id)) {
            $gal_id[$keys]['galleryid'] = (string) $facebook_article->gallery_id->image;
            $gal_id[$keys]['position'] = (string) $facebook_article->gallery_id_position;
            $keys++;
        }
      }
    }
    
    if(!empty($gal_id)){
      $gall_id = serialize($gal_id);
    }
    
    db_insert('story_migrate_left_field')
      ->fields(array(
          'source_id' => (string) $row->xml->id,
          'nid' => $node->nid,
          'modified_by' => (string) $row->xml->modifiedby,
          'modified_date' => (string) $row->xml->modifieddate,
          'gallery_position' => 'story',
          'gallery_id' => $gall_id,
      ))->execute();
  }
}

/*
 below tags will remain blank in the story xml file provide by santosh in mail

 

<featuredname></featuredname> 

<scheduledatetime></scheduledatetime>

<storyexpires></storyexpires>

<storyexpirydate></storyexpirydate>

<selectlisticletemplates></selectlisticletemplates>

<expertname></expertname>

<expertimage></expertimage>

<expertdescription></expertdescription>

<archive></archive>

<associatetvdate></associatetvdate>

<facebookvideo/>

<twittervideo/>
 */