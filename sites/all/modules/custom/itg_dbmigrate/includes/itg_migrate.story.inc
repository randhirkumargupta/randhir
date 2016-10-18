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
      'categories' => t('categories'), //multi
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
      'tags' => t('tags'), //multi
      'shortheadline' => t('shortheadline'),
      'storytitle' => t('storytitle'),
      'storyrating' => t('storyrating'),
      'newtitle' => t('newtitle'),
      'redirectionurl' => t('redirectionurl'),
      'courtesy' => t('courtesy'),
      'snappost' => t('snappost'),
      'socialmediaintegration' => t('socialmediaintegration'), //checkbox
      'facebooknarrative' => t('facebooknarrative'),
      'facebookimage' => t('facebookimage'),
      'facebookimage_alt' => t('facebookimage_alt'),
      'facebookimage_title' => t('facebookimage_title'),
      'facebookvideonarrative' => t('facebookvideonarrative'),
      'facebookvideo' => t('facebookvideo'),
      'twitternarrative' => t('twitternarrative'),
      'twitterimage' => t('twitterimage'),
      'twitterimage_alt' => t('twitterimage_alt'),
      'twitterimage_title' => t('twitterimage_title'),
      'twittervideodescription' => t('twittervideodescription'),
      'twittervideo' => t('twittervideo'),
      'syndication' => t('syndication'),
      'mediafiles' => t('mediafiles'),
      'client_title' => t('client_title'),
      'configurations' => t('configurations'), //checkbox
      'commentquestion' => t('commentquestion'),
      'featuredname' => t('featuredname'), //id
      'relatedcontents' => t('relatedcontents'), //multi
      'scheduledatetime' => t('scheduledatetime'),
      'storyexpires' => t('storyexpires'),
      'storyexpirydate' => t('storyexpirydate'),
      'selectlisticletemplates' => t('selectlisticletemplates'),
      'listicle_content' => t('listicle_content'), //multi
      'quotes' => t('quotes'), //multi
      'factoids_content' => t('factoids_content'), //multi
      'buzz_content' => t('buzz_content'), //fieldcollection
      'briefcase_content' => t('briefcase_content'), //multi
      'expertname' => t('expertname'),
      'expertimage' => t('expertimage'),
      'expert_alt' => t('expert_alt'),
      'expert_title' => t('expert_title'),
      'expertdescription' => t('expertdescription'),
      'archive' => t('archive'),
      'common_by_line_name' => t('common_by_line_name'),
      'common_by_line_twitter' => t('common_by_line_twitter'),
      'associatetvdate' => t('associatetvdate'),
      'associatetime' => t('associatetime'),
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
    $item_xpath = '/story';

    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /story/item/id.
    $item_ID_xpath = 'id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('story');

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
    $this->addFieldMapping('field_story_long_head_line', 'storytitle')->xpath('storytitle');
    $this->addFieldMapping('field_story_magazine_story_issue', 'story_issue')->xpath('story_issue');
    $this->addFieldMapping('field_story_select_magazine', 'select_magazine')->xpath('select_magazine');
    $this->addFieldMapping('field_story_select_supplement', 'select_supplement')->xpath('select_supplement');
    $this->addFieldMapping('field_story_issue_date', 'issue_date')->xpath('issue_date');
    $this->addFieldMapping('title', 'longheadline')->xpath('longheadline');
    $this->addFieldMapping('field_story_short_headline', 'shortheadline')->xpath('shortheadline');

    $this->addFieldMapping('field_stroy_city', 'city')->xpath('city'); //id
    $this->addFieldMapping('field_primary_category', 'primarycategory')->xpath('primarycategory');
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
    $this->addFieldMapping('field_story_kicker_text', 'storykicker')->xpath('storykicker');
    $this->addFieldMapping('body', 'storybody')->xpath('storybody');
//
    $this->addFieldMapping('field_story_magazine_kicker_text', 'magazinekicker')->xpath('magazinekicker');
    $this->addFieldMapping('field_story_magazine_headline', 'magazineheadline')->xpath('magazineheadline');
    $this->addFieldMapping('field_story_rating', 'storyrating')->xpath('storyrating');
    $this->addFieldMapping('field_story_new_title', 'newtitle')->xpath('newtitle');
    $this->addFieldMapping('field_story_redirection_url_titl', 'redirectionurl')->xpath('redirectionurl');
    $this->addFieldMapping('field_story_courtesy', 'courtesy')->xpath('courtesy');
    $this->addFieldMapping('field_story_snap_post', 'snappost')->xpath('snappost');
    $this->addFieldMapping('field_story_facebook_narrative', 'facebooknarrative')->xpath('facebooknarrative');
    $this->addFieldMapping('field_story_facebook_image', 'facebookimage')->xpath('facebookimage');
    $this->addFieldMapping('field_story_facebook_image:alt', 'facebookimage_alt')->xpath('facebookimage_alt');
    $this->addFieldMapping('field_story_facebook_image:title', 'facebookimage_title')->xpath('facebookimage_title');
    $this->addFieldMapping('field_story_facebook_vdescripti', 'facebookvideonarrative')->xpath('facebookvideonarrative');
    $this->addFieldMapping('field_story_facebook_video', 'facebookvideo')->xpath('facebookvideo');
    $this->addFieldMapping('field_story_tweet', 'twitternarrative')->xpath('twitternarrative');
    $this->addFieldMapping('field_story_tweet_image', 'twitterimage')->xpath('twitterimage');
    $this->addFieldMapping('field_story_tweet_image:alt', 'twitterimage_alt')->xpath('twitterimage_alt');
    $this->addFieldMapping('field_story_tweet_image:title', 'twitterimage_title')->xpath('twitterimage_title');
    $this->addFieldMapping('field_story_twitter_video_desc', 'twittervideodescription')->xpath('twittervideodescription');
    $this->addFieldMapping('field_story_twitter_video', 'twittervideo')->xpath('twittervideo');
    $this->addFieldMapping('field_story_syndication', 'syndication')->xpath('syndication');
    $this->addFieldMapping('field_story_media_files_syndicat', 'mediafiles')->xpath('mediafiles');
    $this->addFieldMapping('field_story_client_title', 'client_title')->xpath('client_title');

    $this->addFieldMapping('field_story_comment_question', 'commentquestion')->xpath('commentquestion');
    $this->addFieldMapping('field_story_featured_name', 'featuredname')->xpath('featuredname'); //id
    $this->addFieldMapping('field_common_related_content', 'relatedcontents')->xpath('relatedcontents');
    $this->addFieldMapping('field_story_schedule_date_time', 'scheduledatetime')->xpath('scheduledatetime');
    $this->addFieldMapping('field_story_expires', 'storyexpires')->xpath('storyexpires');
    $this->addFieldMapping('field_story_expiry_date', 'storyexpirydate')->xpath('storyexpirydate');
    $this->addFieldMapping('field_story_templates', 'selectlisticletemplates')->xpath('selectlisticletemplates');
    $this->addFieldMapping('field_story_expert_name', 'expertname')->xpath('expertname');
    $this->addFieldMapping('field_story_expert_image', 'expertimage')->xpath('expertimage');
    $this->addFieldMapping('field_story_expert_image:alt', 'expert_alt')->xpath('expert_alt');
    $this->addFieldMapping('field_story_expert_image:title', 'expert_title')->xpath('expert_title');
    $this->addFieldMapping('field_story_expert_description', 'expertdescription')->xpath('expertdescription');
    $this->addFieldMapping('field_story_archive', 'archive')->xpath('archive');
    $this->addFieldMapping('field_poll_start_date', 'associatetvdate')->xpath('associatetvdate');
    //$this->addFieldMapping('field_story_tv_time', 'associatetime')->xpath('associatetime');

    $this->addFieldMapping('pathauto', 'sefurl')->xpath(t('metatags/sefurl'));
    $this->addFieldMapping('metatag_title', 'pagetitle')->xpath('metatags/pagetitle');
    $this->addFieldMapping('metatag_description', 'description')->xpath('metatags/description');
    //$this->addFieldMapping('metatag_keywords', 'keywords')->xpath('metatags/keywords');
  }

  public function prepareRow($row) {
    // prepare row for listicle
    $data_listicle = '';
    if (isset($row->xml->listicle_content->listicle) && !empty($row->xml->listicle_content->listicle)) {
      foreach ($row->xml->listicle_content->listicle as $final_listicle) {
        $data_listicle[]['value'] = (string) $final_listicle;
      }
    }
    $row->listicle_new = $data_listicle;
    // end prepare row for listicle
    // prepare row for quote
    $data_quotes = '';
    if (isset($row->xml->quotes->quote) && !empty($row->xml->quotes->quote)) {
      foreach ($row->xml->quotes->quote as $final_quote) {
        $data_quotes[]['value'] = (string) $final_quote;
      }
    }
    $row->quotes_new = $data_quotes;
    // end prepare row for quote
    // prepare row for factoids
    $data_factoids = '';
    if (isset($row->xml->factoids_content->factoids) && !empty($row->xml->factoids_content->factoids)) {
      foreach ($row->xml->factoids_content->factoids as $final_factoids) {
        $data_factoids[]['value'] = (string) $final_factoids;
      }
    }
    $row->factoids_new = $data_factoids;
    // end prepare row for factoids
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
        if ((string) $option->breakingnews == true) {
          $final_option[]['value'] = 'breaking_news';
        }
        if ((string) $option->googlestandout == true) {
          $final_option[]['value'] = 'google_standout';
        }
        if ((string) $option->comment == true) {
          $final_option[]['value'] = 'comment';
        }
        if ((string) $option->mediumstylecomment == true) {
          $final_option[]['value'] = 'medium_style_comment';
        }
        if ((string) $option->setfeature == true) {
          $final_option[]['value'] = 'display_lock';
        }
        if ((string) $option->displaylock == true) {
          $final_option[]['value'] = 'set_as_featured';
        }
        if ((string) $option->associatetv == true) {
          $final_option[]['value'] = 'tv';
        }
      }
    }
    $row->final_config_option = $final_option;
    // end checkboxes values
    // End Brifcase migration
    // Primary category
    if (isset($row->xml->primarycategory) && !empty($row->xml->primarycategory)) {
      $source_cid = (string) $row->xml->primarycategory;
      $orignal_pcategory = get_itg_destination_id('migrate_map_itgcategory', $source_cid);
      $row->xml->primarycategory = $orignal_pcategory;
    }
    //End primary category
    //$row->status = $row->xml->publicationName;
    // story date
    if (isset($row->xml->storyexpirydate) && !empty($row->xml->storyexpirydate)) {
      $expire_time = (string) $row->xml->storyexpirydate;
      $expire_date_time = date('m/d/Y H:i', $expire_time);
      $row->xml->storyexpirydate = $expire_date_time;
    }
    if (isset($row->xml->issue_date) && !empty($row->xml->issue_date)) {
      $issue_time = (string) $row->xml->issue_date;
      $issue_date_time = date('m/d/Y H:i', $issue_time);
      $row->xml->issue_date = $issue_date_time;
    }
    if (isset($row->xml->scheduledatetime) && !empty($row->xml->scheduledatetime)) {
      $schedule_time = (string) $row->xml->scheduledatetime;
      $schedule_date_time = date('m/d/Y H:i', $schedule_time);
      $row->xml->scheduledatetime = $schedule_date_time;
    }
    if (isset($row->xml->associatetvdate) && !empty($row->xml->associatetvdate)) {
      $associate_time = (string) $row->xml->associatetvdate;
      $associate_date_time = date('m/d/Y H:i', $associate_time);
      $row->xml->associatetvdate = $associate_date_time;
    }
    //End story date
    
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
    if (!empty($row->listicle_new)) {
      $node->field_story_template_guru[LANGUAGE_NONE] = $row->listicle_new;
    }
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
    if (!empty($row->final_config_option)) {
      $node->field_story_configurations[LANGUAGE_NONE] = $row->final_config_option;
    }
    if (!empty($row->final_social_checkbox)) {
      $node->field_story_social_media_integ[LANGUAGE_NONE] = $row->final_social_checkbox;
    }
    if (!empty($row->byline_new)) {
      $node->field_story_reporter[LANGUAGE_NONE] = $row->byline_new;
    }
    if(!empty($row->featuredname)){
      $node->field_story_featured_name[LANGUAGE_NONE][0]['tid'] = (string) $row->featuredname;
    }
    if(!empty($row->city)){
      $node->field_stroy_city[LANGUAGE_NONE][0]['tid'] = (string) $row->city;
    }
  
    $node->uid = 291;
  }

  public function complete($entity, $row) {
    $node = node_load($entity->nid);
    $key = 0;
    if (isset($row->xml->buzz_content->buzz)) {
      foreach ($row->xml->buzz_content->buzz as $value) {
        $headline = (string) $value->headline;
        $image_url = (string) $value->image;
        $file = file_save_data(file_get_contents($image_url), file_default_scheme() . '://' . basename($image_url), FILE_EXISTS_RENAME);
        $file->status = 1;
        $file->alt = (string) $value->buzz_alt;
        $file->title = (string) $value->buzz_title;
        $image = (array) $file;
        $description = (string) $value->description;
        $values = array(
          'field_name' => 'field_story_template_buzz',
          'field_buzz_headline' => array(LANGUAGE_NONE => array(array('value' => $headline))),
          'field_buzz_image' => array(LANGUAGE_NONE => array($image)),
          'field_buzz_description' => array(LANGUAGE_NONE => array(array('value' => $description))),
        );
        $field_collection_item = entity_create('field_collection_item', $values);
        $field_collection_item->setHostEntity('node', $node);
        $field_collection_item->save(TRUE);
        $node->field_story_template_buzz[LANGUAGE_NONE][$key]['value'] = $field_collection_item->item_id;
        $key++;
      }
      field_attach_update('node', $node);
    }
  }

}
