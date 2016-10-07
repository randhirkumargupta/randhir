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
      'largeimage' => t('largeimage'),
      'mediumimage' => t('mediumimage'),
      'smallimage' => t('smallimage'),
      'extrasmallimage' => t('extrasmallimage'),
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
      'facebookvideonarrative' => t('facebookvideonarrative'),
      'facebookvideo' => t('facebookvideo'),
      'twitternarrative' => t('twitternarrative'),
      'twitterimage' => t('twitterimage'),
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
    $this->addFieldMapping('title', 'storytitle')->xpath('storytitle');
    $this->addFieldMapping('field_story_long_head_line', 'story_issue')->xpath('story_issue');
//    //$this->addFieldMapping('field_story_reporter', 'select_magazine')->xpath('select_magazine');
//
//    $this->addFieldMapping('field_story_category', 'select_supplement')->xpath('select_supplement');
//    $this->addFieldMapping('field_primary_category', 'issue_date')->xpath('issue_date');
    $this->addFieldMapping('field_story_kicker_text', 'longheadline')->xpath('longheadline');
    $this->addFieldMapping('body', 'byline')->xpath('byline');
    $this->addFieldMapping('field_story_magazine_kicker_text', 'city')->xpath('city');
    $this->addFieldMapping('field_story_magazine_headline', 'categories')->xpath('categories'); //multi
    //$this->addFieldMapping('field_story_itg_tags', 'primarycategory')->xpath('primarycategory');
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
    $this->addFieldMapping('field_story_courtesy', 'relatedcontents')->xpath('relatedcontents'); //multi
    $this->addFieldMapping('field_story_courtesy', 'scheduledatetime')->xpath('scheduledatetime');
    $this->addFieldMapping('field_story_courtesy', 'storyexpires')->xpath('storyexpires');

    $this->addFieldMapping('field_story_courtesy', 'storyexpirydate')->xpath('storyexpirydate');
    $this->addFieldMapping('field_story_courtesy', 'selectlisticletemplates')->xpath('selectlisticletemplates');
    //$this->addFieldMapping('field_story_courtesy', 'listicle_content')->xpath('listicle_content');//multi
    // $this->addFieldMapping('field_story_courtesy', 'quotes')->xpath('quotes'); //multi
    // $this->addFieldMapping('field_story_courtesy', 'factoids_content')->xpath('factoids_content'); //multi
    //$this->addFieldMapping('field_story_courtesy', 'buzz_content')->xpath('buzz_content');//fieldcollection
    $this->addFieldMapping('field_story_courtesy', 'briefcase_content')->xpath('briefcase_content'); //multi
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
        $orignal_category = get_itg_destination_id($source_cid);
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
        $orignal_tag = get_itg_destination_id($source_tags);
        $data_tags[]['tid'] = $orignal_tag;
      }
    }
    $row->tag_new = $data_tags;
    // End story tags migration
    // Brifcase migration
    $data_brifcase = '';

    if (isset($row->xml->briefcase_content->briefcase) && !empty($row->xml->briefcase_content->briefcase)) {
      foreach ($row->xml->briefcase_content->briefcase as $final_briefcase) {
        $source_briefcase = (string) $final_briefcase;
        $orignal_briefcase = get_itg_destination_id($source_briefcase);
        $data_brifcase[]['tid'] = $orignal_tag;
      }
    }
    $row->brifcase_new = $data_brifcase;
    // End Brifcase migration
    //$row->status = $row->xml->publicationName;
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
    $node->uid = 1;
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
