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
      'extra_large_alt' => t('extra_large_alt'),
      'extra_large_title' => t('extra_large_title'),
      'extrasmallimage' => t('extrasmallimage'),
      'extra_small_alt' => t('extra_small_alt'),
      'extra_small_title' => t('extra_small_title'),
      'largeimage' => t('largeimage'),
      'large_title' => t('large_title'),
      'large_alt' => t('large_alt'),
      'mediumimage' => t('mediumimage'),
      'mediumimage_alt' => t('mediumimage_alt'),
      'mediumimage_title' => t('mediumimage_title'),
      'smallimage' => t('smallimage'),
      'smallimage_alt' => t('smallimage_alt'),
      'smallimage_title' => t('smallimage_title'),
      'tags' => t('tags'),
      'categories' => t('categories'),
      'primarycategory' => t('primarycategory'),
      'commonaudio' => t('commonaudio'),
      'commonaudiofile' => t('commonaudiofile'),
      'credittoall' => t('credittoall'),
      'creditname' => t('creditname'),
      'gallery' => t('gallery'),
      'photo_by' => t('photo_by'),
      'photoby' => t('photoby'),
      'tags' => t('tags'),
      'archive' => t('archive'),
      'socialmediaintegration' => t('socialmediaintegration'),
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
      'timetwitter' => t('timetwitter'),
      'postedbyfacebook' => t('postedbyfacebook'),
      'timefacebook' => t('timefacebook'),
      'postedbyinstagram' => t('postedbyinstagram'),
      'timeinstagram' => t('timeinstagram'),
      'commonbyline' => t('commonbyline'),
      'commonbylinetwitter' => t('commonbylinetwitter'),
      'postedbytwitter' => t('postedbytwitter'),
      'relatedcontents' => t('relatedcontents'),
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
    $item_xpath = '/photogallery';

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
    $this->addFieldMapping('field_featured', 'featured')->xpath('featured');
    $this->addFieldMapping('field_primary_category', 'primarycategory')->xpath('primarycategory');
    // for image
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

    $this->addFieldMapping('field_common_audio', 'commonaudio')->xpath('commonaudio');
    $this->addFieldMapping('field_common_audio_file', 'commonaudiofile')->xpath('commonaudiofile');
    $this->addFieldMapping('field_credit_to_all', 'credittoall')->xpath('credittoall');
    $this->addFieldMapping('field_credit_name', 'creditname')->xpath('creditname');
    $this->addFieldMapping('field_story_archive', 'archive')->xpath('archive');
    $this->addFieldMapping('field_photo_by', 'photoby')->xpath('photoby');

    $this->addFieldMapping('field_story_facebook_narrative', 'facebooknarrative')->xpath('facebooknarrative');
    $this->addFieldMapping('field_story_facebook_image', 'facebookimage')->xpath('facebookimage');
    $this->addFieldMapping('field_story_facebook_image:alt', 'facebookimage_alt')->xpath('facebookimage_alt');
    $this->addFieldMapping('field_story_facebook_image:title', 'facebookimage_title')->xpath('facebookimage_title');
    $this->addFieldMapping('field_story_facebook_vdescripti', 'facebookvideonarrative')->xpath('facebookvideonarrative');
    //$this->addFieldMapping('field_story_facebook_video', 'facebookvideo')->xpath('facebookvideo');
    $this->addFieldMapping('field_story_posted_by_facebook', 'postedbyfacebook')->xpath('postedbyfacebook');
    $this->addFieldMapping('field_story_time_facebook', 'timefacebook')->xpath('timefacebook');

    $this->addFieldMapping('field_story_tweet', 'twitternarrative')->xpath('twitternarrative');
    $this->addFieldMapping('field_story_tweet_image', 'twitterimage')->xpath('twitterimage');
    $this->addFieldMapping('field_story_tweet_image:alt', 'twitterimage_alt')->xpath('twitterimage_alt');
    $this->addFieldMapping('field_story_tweet_image:title', 'twitterimage_title')->xpath('twitterimage_title');
    $this->addFieldMapping('field_story_twitter_video_desc', 'twittervideodescription')->xpath('twittervideodescription');
    //$this->addFieldMapping('field_story_twitter_video', 'twittervideo')->xpath('twittervideo');
    $this->addFieldMapping('field_story_time_twitter', 'timetwitter')->xpath('timetwitter');
    $this->addFieldMapping('field_story_posted_by_twitter', 'postedbytwitter')->xpath('postedbytwitter');


    $this->addFieldMapping('field_story_posted_by_instagram', 'postedbyinstagram')->xpath('postedbyinstagram');
    $this->addFieldMapping('field_story_time_instagram', 'timeinstagram')->xpath('timeinstagram');


    $this->addFieldMapping('field_common_related_content', 'relatedcontents')->xpath('relatedcontents');
    $this->addFieldMapping('field_story_syndication', 'syndication')->xpath('syndication');

    //$this->addFieldMapping('field_story_courtesy', 'commonbyline')->xpath('commonbyline');
    //$this->addFieldMapping('field_story_courtesy', 'commonbylinetwitter')->xpath('commonbylinetwitter');
    //$this->addFieldMapping('parent', 'category_parent')->xpath('category_parent');

    /* $this->addFieldMapping('description', 'details');
      $this->addFieldMapping('weight', 'ordering'); */
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
    if ((string) $row->xml->syndication == 'yes') {
      $row->xml->syndication = 'Yes';
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

    // Primary category
    if (isset($row->xml->primarycategory) && !empty($row->xml->primarycategory)) {
      $source_cid = (string) $row->xml->primarycategory;
      $orignal_pcategory = get_itg_destination_id('migrate_map_itgcategory', $source_cid);
      $row->xml->primarycategory = $orignal_pcategory;
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

    if ((string) $row->xml->credittoall == 'yes') {
      $row->xml->credittoall = 1;
    }
    if ((string) $row->xml->commonaudio == 'yes') {
      $row->xml->commonaudio = 1;
    }
    if ((string) $row->xml->syndication == 'yes') {
      $row->xml->syndication = 'Yes';
    }
    // Related content
    if (isset($row->xml->relatedcontents->relatedcontent) && !empty($row->xml->relatedcontents->relatedcontent)) {
      foreach ($row->xml->relatedcontents->relatedcontent as $related) {
        $related_content .= (string) $related . ', ';
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
    if (!empty($row->final_social_checkbox)) {
      $node->field_story_social_media_integ[LANGUAGE_NONE] = $row->final_social_checkbox;
    }
    // for byline
    $old_byline = (string) $row->xml->byline;
    $new_byline = get_itg_destination_id('migrate_map_itgbyline', $old_byline);
    //$node->field_photo_by[LANGUAGE_NONE][]['target_id'] = $new_byline;

    $node->uid = 1;
  }

  public function complete($entity, $row) {
    $node = node_load($entity->nid);
    if (isset($row->xml->gallery->image_details) && !empty($row->xml->gallery->image_details)) {
      $key = 0;
      foreach ($row->xml->gallery->image_details as $value) {
        $image_url = (string) $value->image_url;
        $caption = (string) $value->caption;
        $credit = (string) $value->credit;
        $data_byline = '';
        if (isset($row->xml->gallery->image_details->bylines->byline) && !empty($row->xml->gallery->image_details->bylines->byline)) {
          foreach ($row->xml->gallery->image_details->bylines->byline as $final_byline) {
            $source_bid = (string) $final_byline;
            $orignal_byline = get_itg_destination_id('migrate_map_itgbyline', $source_bid);
            $data_byline[]['target_id'] = $orignal_byline;
          }
        }
        $photo_by = (string) $value->photo_by;
        $audio = (string) $value->audio;
        $syndication = (string) $value->syndication;
        $file = file_save_data(file_get_contents($image_url), file_default_scheme() . '://' . basename($image_url), FILE_EXISTS_RENAME);
        $file->status = 1;
        $file->alt = (string) $value->gallery_alt;
        $file->title = (string) $value->gallery_title;
        $image = (array) $file;
        $values = array(
          'field_name' => 'field_gallery_image',
          'field_images' => array(LANGUAGE_NONE => array($image)),
          'field_image_caption' => array(LANGUAGE_NONE => array(array('value' => $caption))),
          'field_credit' => array(LANGUAGE_NONE => array(array('value' => $credit))),
          'field_photo_byline' => array(LANGUAGE_NONE => $data_byline),
          'field_photo_by' => array(LANGUAGE_NONE => array(array('target_id' => $photo_by))),
          //'field_audio' => array(LANGUAGE_NONE => array(array('value' => $credit))),
          'field_image_syndication' => array(LANGUAGE_NONE => array(array('value' => $syndication))),
        );

        $field_collection_item = entity_create('field_collection_item', $values);
        $field_collection_item->setHostEntity('node', $node);
        $field_collection_item->save(TRUE);
        $node->field_gallery_image[LANGUAGE_NONE][$key]['value'] = $field_collection_item->item_id;
        $key++;
      }
      field_attach_update('node', $node);
    }
  }

}
