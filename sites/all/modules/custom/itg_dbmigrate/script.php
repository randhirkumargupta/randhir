<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.
//delete_itg_widget_table();
//update_itg_widget_table();
//update_meta_description_in_photo();
//print_name();
//file_move_backup();
//final_database_testing_with_xml();

//issue_bases_suppliment_story_verify();

function issue_bases_suppliment_story_verify() {
  $path = 'sites/default/files/indiatoday_suppliment_15052017.xml';
  $xml = simplexml_load_file($path, 'SimpleXMLElement');
  foreach ($xml->story as $xml_data) {
    $source_id = (int) $xml_data->id;
    echo $source_id . ', ';
    $result = get_data_from_storylist_table($source_id);
    if (empty($result)) {
      $value[] = $source_id;
    }
  }
  p($value);
}

function final_database_testing_with_xml_new_shravan() {
  $path = 'sites/default/files/story/';
  $tcount = 0;
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path)) as $filename) {
    $file_name = $filename->getFilename();
    echo '"' . $file_name . '", ';
    if ($file_name == '.' || $file_name == '..') {
      continue;
    }
    $array_issue_based[] = $file_name;
  }

  foreach ($array_issue_based as $story_value) {
    $xml = simplexml_load_file($path . $story_value, 'SimpleXMLElement');
    foreach ($xml->story as $xml_data) {
      $source_id = (int) $xml_data->id;
      echo $source_id . ', ';
      $result = get_data_from_storylist_table($source_id);
      if (empty($result)) {
        db_insert('itg_migrate_data_test') // Table name no longer needs {}
            ->fields(array(
              'source_id1' => $source_id,
              'destid1' => $source_id,
              'xml_name' => $file_name,
              'type' => 'story',
            ))
            ->execute();
      }
      $count ++;
    }
    $tcount = $tcount + $count;
  }
}

function final_database_testing_with_xml() {
  $path = 'sites/default/files/story/';
  $tcount = 0;
  $array_issue_based = array("indiatoday-story_2011-10-01.xml", "indiatoday-story_2013-02-01.xml", "indiatoday-story_2010-07-01.xml", "indiatoday-story_2015-12-01.xml", "indiatoday-story_2009-08-01.xml", "indiatoday-story_2015-10-01.xml", "indiatoday-story_2011-11-01.xml", "indiatoday-story_2015-06-01.xml", "indiatoday-story_2014-03-01.xml", "indiatoday-story_2015-02-01.xml", "indiatoday-story_2011-01-15-m-nc.xml", "indiatoday-story_2008-10-01.xml", "indiatoday-story_2016-01-01.xml", "indiatoday-story_2016-10-01.xml", "indiatoday-story_2009-03-01.xml", "indiatoday-story_2007-06-01.xml", "indiatoday-story_2008-08-01.xml", "indiatoday-story_2007-07-01.xml", "indiatoday-story_2010-03-01.xml", "indiatoday-story_2013-01-15-m.xml", "indiatoday-story_2016-03-01.xml", "indiatoday-story_2012-11-01.xml", "indiatoday-story_2014-12-01.xml", "indiatoday-story_2009-05-01.xml", "indiatoday-story_2015-01-01.xml", "indiatoday-story_2011-05-01.xml", "indiatoday-story_2016-11-01.xml", "indiatoday-story_2014-05-01.xml", "indiatoday-story_2007-03-01.xml", "indiatoday-story_2011-01-01.xml", "indiatoday-story_2008-09-01.xml", "indiatoday-story_2008-12-01.xml", "indiatoday-story_2014-02-01.xml", "indiatoday-story_2009-09-01.xml", "indiatoday-story_2016-02-01.xml", "indiatoday-story_2014-11-01.xml", "indiatoday-story_2012-09-01.xml", "indiatoday-story_2013-05-01.xml", "indiatoday-story_2008-07-01.xml", "indiatoday-story_2014-08-01.xml", "indiatoday-story_2012-07-01.xml", "indiatoday-story_2012-04-01.xml", "indiatoday-story_2008-01-01.xml", "indiatoday-story_2014-09-21.xml", "indiatoday-story_2016-05-01.xml", "indiatoday-story_2013-11-01.xml", "indiatoday-story_2015-02-15-m.xml", "indiatoday-story_2013-01-01.xml", "indiatoday-story_2008-11-01.xml", "indiatoday-story_2009-07-01.xml", "indiatoday-story_2014-09-11.xml", "indiatoday-story_2012-06-01.xml", "indiatoday-story_2009-04-01.xml", "indiatoday-story_2008-04-01.xml", "indiatoday-story_2011-04-01.xml", "indiatoday-story_2008-05-01.xml", "indiatoday-story_2011-09-01.xml", "indiatoday-story_2009-10-01.xml", "indiatoday-story_2007-11-01.xml", "indiatoday-story_2016-12-01.xml", "indiatoday-story_2008-03-01.xml", "indiatoday-story_2010-12-01.xml", "indiatoday-story_2013-08-01.xml", "indiatoday-story_2010-11-01.xml", "indiatoday-story_2015-05-01.xml", "indiatoday-story_2007-09-01.xml", "indiatoday-story_2014-04-01.xml", "indiatoday-story_2011-02-01.xml", "indiatoday-story_2014-03-15-m.xml", "indiatoday-story_2014-04-15-m.xml", "indiatoday-story_2007-04-01.xml", "indiatoday-story_2007-05-01.xml", "indiatoday-story_2007-08-01.xml", "indiatoday-story_2015-01-15-m.xml", "indiatoday-story_2016-04-01.xml", "indiatoday-story_2012-08-01.xml", "indiatoday-story_2010-02-01.xml", "indiatoday-story_2014-09-01.xml", "indiatoday-story_2010-05-01.xml", "indiatoday-story_2016-08-01.xml", "indiatoday-story_2012-02-01.xml", "indiatoday-story_2010-06-01.xml", "indiatoday-story_2015-08-01.xml", "indiatoday-story_2009-11-01.xml", "indiatoday-story_2014-06-01.xml", "indiatoday-story_2008-06-01.xml", "indiatoday-story_2013-06-01.xml", "indiatoday-story_2009-01-01.xml", "indiatoday-story_2015-11-01.xml", "indiatoday-story_2011-07-01.xml", "indiatoday-story_2007-01-01.xml", "indiatoday-story_2015-03-01.xml", "indiatoday-story_2013-02-15-m.xml", "indiatoday-story_2011-08-01.xml", "indiatoday-story_2012-12-01.xml", "indiatoday-story_2016-09-01.xml", "indiatoday-story_2013-03-01.xml", "indiatoday-story_2014-01-01.xml", "indiatoday-story_2008-02-01.xml", "indiatoday-story_2007-02-01.xml", "indiatoday-story_2013-10-01.xml", "indiatoday-story_2011-03-01.xml", "indiatoday-story_2014-10-01.xml", "indiatoday-story_2012-05-01.xml", "indiatoday-story_2010-04-01.xml", "indiatoday-story_2015-07-01.xml", "indiatoday-story_2009-12-01.xml", "indiatoday-story_2007-10-01.xml", "indiatoday-story_2009-02-01.xml", "indiatoday-story_2010-10-01.xml", "indiatoday-story_2014-07-01.xml", "indiatoday-story_2016-06-01.xml", "indiatoday-story_2013-09-01.xml", "indiatoday-story_2011-12-01.xml", "indiatoday-story_2014-02-15-m.xml", "indiatoday-story_2011-06-01.xml", "indiatoday-story_2012-10-01.xml", "indiatoday-story_2016-07-01.xml", "indiatoday-story_2014-01-15-m.xml", "indiatoday-story_2013-04-01.xml", "indiatoday-story_2010-01-01.xml", "indiatoday-story_2011-02-15-nm-nc.xml", "indiatoday-story_2013-03-15-m.xml", "indiatoday-story_2012-03-01.xml", "indiatoday-story_2015-04-01.xml", "indiatoday-story_2007-12-01.xml", "indiatoday-story_2009-06-01.xml", "indiatoday-story_2013-07-01.xml", "indiatoday-story_2012-01-01.xml", "indiatoday-story_2013-12-01.xml", "indiatoday-story_2015-09-01.xml", "indiatoday-story_2010-09-01.xml", "indiatoday-story_2010-08-01.xml");
  foreach ($array_issue_based as $story_value) {
    $xml = simplexml_load_file($path . $story_value, 'SimpleXMLElement');
    foreach ($xml->story as $xml_data) {
      $source_id = (int) $xml_data->id;
      echo $source_id . ', ';
      $result = get_data_from_storylist_table($source_id);
      if (empty($result)) {
        db_insert('itg_migrate_data_test') // Table name no longer needs {}
            ->fields(array(
              'source_id1' => $source_id,
              'destid1' => $source_id,
              'xml_name' => $file_name,
              'type' => 'story',
            ))
            ->execute();
      }
      $count ++;
    }
    $tcount = $tcount + $count;
  }
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path)) as $filename) {
    $file_name = $filename->getFilename();
    echo '"' . $file_name . '", ';
    if ($file_name == '.' || $file_name == '..') {
      continue;
    }
    $xml = simplexml_load_file($path . $file_name, 'SimpleXMLElement');
    $count = 0;
    foreach ($xml->story as $xml_data) {
      $source_id = (int) $xml_data->id;
      echo $source_id . ', ';
      $result = get_data_from_storylist_table($source_id);
      if (empty($result)) {
        db_insert('itg_migrate_data_test') // Table name no longer needs {}
            ->fields(array(
              'source_id1' => $source_id,
              'destid1' => $source_id,
              'xml_name' => $file_name,
              'type' => 'story',
            ))
            ->execute();
      }
      $count ++;
    }
    $xml_name[$file_name]['xml_year'] = '----' . $file_name . '---';
    $xml_name[$file_name]['count'] = $count;
    $tcount = $tcount + $count;
  }
  // pr($xml_name);
  // echo '******'. $tcount . '******';
}

function get_data_from_storylist_table($source_id) {
  $query = db_select('migrate_map_itgstorylist', 'mm_story');
  $query->fields('mm_story', array('sourceid1', 'destid1'));
  $query->condition('sourceid1', $source_id, '=');
  $result = $query->execute();
  foreach ($result as $rel) {
    $value_rel['source_id'] = $rel->sourceid1;
    $value_rel['destid'] = $rel->destid1;
  }
  return $value_rel;
}

function story_issue_array() {
  $array_issue_based = array("indiatoday-story_2011-10-01.xml", "indiatoday-story_2013-02-01.xml", "indiatoday-story_2010-07-01.xml", "indiatoday-story_2015-12-01.xml", "indiatoday-story_2009-08-01.xml", "indiatoday-story_2015-10-01.xml", "indiatoday-story_2011-11-01.xml", "indiatoday-story_2015-06-01.xml", "indiatoday-story_2014-03-01.xml", "indiatoday-story_2015-02-01.xml", "indiatoday-story_2011-01-15-m-nc.xml", "indiatoday-story_2008-10-01.xml", "indiatoday-story_2016-01-01.xml", "indiatoday-story_2016-10-01.xml", "indiatoday-story_2009-03-01.xml", "indiatoday-story_2007-06-01.xml", "indiatoday-story_2008-08-01.xml", "indiatoday-story_2007-07-01.xml", "indiatoday-story_2010-03-01.xml", "indiatoday-story_2013-01-15-m.xml", "indiatoday-story_2016-03-01.xml", "indiatoday-story_2012-11-01.xml", "indiatoday-story_2014-12-01.xml", "indiatoday-story_2009-05-01.xml", "indiatoday-story_2015-01-01.xml", "indiatoday-story_2011-05-01.xml", "indiatoday-story_2016-11-01.xml", "indiatoday-story_2014-05-01.xml", "indiatoday-story_2007-03-01.xml", "indiatoday-story_2011-01-01.xml", "indiatoday-story_2008-09-01.xml", "indiatoday-story_2008-12-01.xml", "indiatoday-story_2014-02-01.xml", "indiatoday-story_2009-09-01.xml", "indiatoday-story_2016-02-01.xml", "indiatoday-story_2014-11-01.xml", "indiatoday-story_2012-09-01.xml", "indiatoday-story_2013-05-01.xml", "indiatoday-story_2008-07-01.xml", "indiatoday-story_2014-08-01.xml", "indiatoday-story_2012-07-01.xml", "indiatoday-story_2012-04-01.xml", "indiatoday-story_2008-01-01.xml", "indiatoday-story_2014-09-21.xml", "indiatoday-story_2016-05-01.xml", "indiatoday-story_2013-11-01.xml", "indiatoday-story_2015-02-15-m.xml", "indiatoday-story_2013-01-01.xml", "indiatoday-story_2008-11-01.xml", "indiatoday-story_2009-07-01.xml", "indiatoday-story_2014-09-11.xml", "indiatoday-story_2012-06-01.xml", "indiatoday-story_2009-04-01.xml", "indiatoday-story_2008-04-01.xml", "indiatoday-story_2011-04-01.xml", "indiatoday-story_2008-05-01.xml", "indiatoday-story_2011-09-01.xml", "indiatoday-story_2009-10-01.xml", "indiatoday-story_2007-11-01.xml", "indiatoday-story_2016-12-01.xml", "indiatoday-story_2008-03-01.xml", "indiatoday-story_2010-12-01.xml", "indiatoday-story_2013-08-01.xml", "indiatoday-story_2010-11-01.xml", "indiatoday-story_2015-05-01.xml", "indiatoday-story_2007-09-01.xml", "indiatoday-story_2014-04-01.xml", "indiatoday-story_2011-02-01.xml", "indiatoday-story_2014-03-15-m.xml", "indiatoday-story_2014-04-15-m.xml", "indiatoday-story_2007-04-01.xml", "indiatoday-story_2007-05-01.xml", "indiatoday-story_2007-08-01.xml", "indiatoday-story_2015-01-15-m.xml", "indiatoday-story_2016-04-01.xml", "indiatoday-story_2012-08-01.xml", "indiatoday-story_2010-02-01.xml", "indiatoday-story_2014-09-01.xml", "indiatoday-story_2010-05-01.xml", "indiatoday-story_2016-08-01.xml", "indiatoday-story_2012-02-01.xml", "indiatoday-story_2010-06-01.xml", "indiatoday-story_2015-08-01.xml", "indiatoday-story_2009-11-01.xml", "indiatoday-story_2014-06-01.xml", "indiatoday-story_2008-06-01.xml", "indiatoday-story_2013-06-01.xml", "indiatoday-story_2009-01-01.xml", "indiatoday-story_2015-11-01.xml", "indiatoday-story_2011-07-01.xml", "indiatoday-story_2007-01-01.xml", "indiatoday-story_2015-03-01.xml", "indiatoday-story_2013-02-15-m.xml", "indiatoday-story_2011-08-01.xml", "indiatoday-story_2012-12-01.xml", "indiatoday-story_2016-09-01.xml", "indiatoday-story_2013-03-01.xml", "indiatoday-story_2014-01-01.xml", "indiatoday-story_2008-02-01.xml", "indiatoday-story_2007-02-01.xml", "indiatoday-story_2013-10-01.xml", "indiatoday-story_2011-03-01.xml", "indiatoday-story_2014-10-01.xml", "indiatoday-story_2012-05-01.xml", "indiatoday-story_2010-04-01.xml", "indiatoday-story_2015-07-01.xml", "indiatoday-story_2009-12-01.xml", "indiatoday-story_2007-10-01.xml", "indiatoday-story_2009-02-01.xml", "indiatoday-story_2010-10-01.xml", "indiatoday-story_2014-07-01.xml", "indiatoday-story_2016-06-01.xml", "indiatoday-story_2013-09-01.xml", "indiatoday-story_2011-12-01.xml", "indiatoday-story_2014-02-15-m.xml", "indiatoday-story_2011-06-01.xml", "indiatoday-story_2012-10-01.xml", "indiatoday-story_2016-07-01.xml", "indiatoday-story_2014-01-15-m.xml", "indiatoday-story_2013-04-01.xml", "indiatoday-story_2010-01-01.xml", "indiatoday-story_2011-02-15-nm-nc.xml", "indiatoday-story_2013-03-15-m.xml", "indiatoday-story_2012-03-01.xml", "indiatoday-story_2015-04-01.xml", "indiatoday-story_2007-12-01.xml", "indiatoday-story_2009-06-01.xml", "indiatoday-story_2013-07-01.xml", "indiatoday-story_2012-01-01.xml", "indiatoday-story_2013-12-01.xml", "indiatoday-story_2015-09-01.xml", "indiatoday-story_2010-09-01.xml", "indiatoday-story_2010-08-01.xml");
}


function print_name() {
  $query = db_select('url_alias', 'ua');
  $query->fields('ua', array('source'));
  $query->condition('source', '%' . db_like('taxonomy/term') . '%', LIKE);
  $result = $query->execute();
  foreach ($result as $rel) {
    $gg = explode('/term/', $rel->source);
    $tids[] = $gg[1];
  }

  $query = db_select('taxonomy_term_data', 'ttd');
  $query->fields('ttd', array('tid', 'vid'));
  $query->condition('tid', $tids, 'IN');
  $query->condition('vid', 1, '=');
  $result1 = $query->execute()->fetchAll();

  p($result1);
}

function update_meta_description_in_photo() {
  $xml_path = 'sites/default/files/xml_file_chunk/gallery/';
  //$file_name = 'indiatoday-galleries.xml';
  $xml = simplexml_load_file($xml_path . $file_name, 'SimpleXMLElement');
  foreach ($xml->photogallery as $photo_gallery) {
    $description = (string) $photo_gallery->metatags->description;
    $sour_id = $photo_gallery->id;
    $query = db_select('migrate_map_itgphotogallery', 'mm_photo');
    $query->fields('mm_photo', array('sourceid1', 'destid1'));
    $query->isNotNull('mm_photo.destid1');
    $query->condition('sourceid1', $sour_id, '=');
    $result = $query->execute();

    foreach ($result as $rel) {

      $val = meta_table_values($rel->destid1);
      $val['description']['value'] = $description;
      $new_val = serialize($val);
      if (!empty($new_val)) {
        db_update('metatag') // Table name no longer needs {}
            ->fields(array(
              'data' => $new_val,
            ))
            ->condition('entity_id', $rel->destid1, '=')
            ->execute();
      }
      echo $rel->destid1;
    }
  }
}

/**
 * Get meta table description fields.
 * @param type $nid
 * @return type
 */
function meta_table_values($nid) {
  $query = db_select('metatag', 'm');
  $query->fields('m', array('data', 'entity_id'));
  $query->condition('entity_id', $nid, '=');
  $result = $query->execute();
  foreach ($result as $rel) {
    $data = unserialize($rel->data);
  }
  return $data;
}

function delete_itg_widget_table() {
  $query = db_select('migrate_map_itgstorylist', 'mm_story');
  $query->fields('mm_story', array('sourceid1', 'destid1'));
  $query->isNotNull('mm_story.destid1');
  //$query->range(0,1);
  $result = $query->execute();
  foreach ($result as $rel) {
    db_delete('itg_widget_order')
        ->condition('nid', $rel->destid1)
        ->execute();
    echo $rel->sourceid1 . '---';
  }
}

function update_itg_widget_table() {
  $xml_path = 'sites/default/files/mig_story/story/';
  $query = db_select('migrate_map_itgstorylist', 'mm_story');
  $query->fields('mm_story', array('sourceid1', 'destid1'));
  $query->isNotNull('mm_story.destid1');
  $query->range(0, 1);
  $result = $query->execute();
  foreach ($result as $rel) {
    echo $rel->sourceid1 . ' - ' . $rel->destid1;

    // Add entry in itg widget orger
    $xml = simplexml_load_file($xml_path . $rel->sourceid1 . '.xml', 'SimpleXMLElement');
    if (isset($xml->categories->category) && !empty($xml->categories->category)) {
      $data_category = array();
      foreach ($xml->categories->category as $final_category) {
        $data_category[] = (string) $final_category;
      }
    }
    $primary_cat_wegiht = (string) $xml->ordering;
    $primary_cat = (string) $xml->primarycategory;
//    echo '  '.$primary_cat . '---' .$rel->sourceid1;
//    pr($data_category);
    update_correct_data_in_itg_widget_order_tbl($rel->destid1, 'story', $data_category, $primary_cat, $primary_cat_wegiht);
  }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function update_correct_data_in_itg_widget_order_tbl($nid = 0, $node_type = "", $categories = array(), $primary_cat = 0, $primary_cat_wegiht = 0) {
  if ($nid && !empty($categories) && $primary_cat && $primary_cat_wegiht && $node_type != "") {
    itg_widget_insert_master_query($nid, $primary_cat, $node_type, $primary_cat_wegiht, $primary_cat, TRUE);
    // Foreach for all categories;
    foreach ($categories as $category) {
      if ($category != $primary_cat) {
        itg_widget_insert_master_query($nid, $category, $node_type, $primary_cat_wegiht, $primary_cat);
      }
    }
    //Handel case for primary category.
  }
}

function itg_widget_insert_master_query($nid, $category, $node_type, $primary_cat_wegiht, $primary_cat, $is_primary = FALSE) {
  $single_max_result = gets_max_weight_for_node_insert($category, $node_type);
  $max_weight_for_actual_CT = $single_max_result['content_type'];
  $max_weight_for_all_CT = $single_max_result['All'];
  $single_insert_query = db_insert('itg_widget_order')->fields(
      array(
        'nid',
        'widget',
        'content_type',
        'cat_id',
        'weight',
        'extra',
      )
  );
  $single_insert_query->values(
      array(
        'nid' => $nid,
        'widget' => 'section_wise_widget',
        'content_type' => $node_type,
        'cat_id' => ($is_primary) ? $primary_cat : $category,
        'weight' => ($is_primary) ? $primary_cat_wegiht : ++$max_weight_for_actual_CT,
        'extra' => '',
      )
  )->execute();
  // handel case for All.
  $single_insert_query_all = db_insert('itg_widget_order')->fields(
      array(
        'nid',
        'widget',
        'content_type',
        'cat_id',
        'weight',
        'extra',
      )
  );
  $single_insert_query_all->values(
      array(
        'nid' => $nid,
        'widget' => 'section_wise_widget',
        'content_type' => 'All',
        'cat_id' => ($is_primary) ? $primary_cat : $category,
        'weight' => ++$max_weight_for_all_CT,
        'extra' => '',
      )
  )->execute();
}

function gets_max_weight_for_node_insert($tid, $type) {
  $max_query = db_select('itg_widget_order');
  $max_query->addExpression('MAX(weight)', 'weight');
  $max_query->condition('cat_id', $tid);
  $max_query->condition('content_type', array($type, 'All'), 'IN');
  $max_query->condition('widget', 'section_wise_widget');
  $max_query->groupBy('content_type');
  $max_result = $max_query->execute()->fetchAll();
  $all_weight = !empty($max_result[0]->weight) ? $max_result[0]->weight : 1;
  $ct_weight = !empty($max_result[1]->weight) ? $max_result[1]->weight : 1;
  $weight_array = array("All" => $all_weight, "content_type" => $ct_weight);
  return $weight_array;
}

function file_move_backup() {
  $query = db_select('s3fs_file', 'sfile');
  $query->fields('sfile', array('uri'));
  //$query->range(0, 10);
  $result = $query->execute();
  $rels = array();

  foreach ($result as $rel) {
    //$rels = explode('public://', $rel->uri);
    $rels[1] = 'shravan.jpg';
    $path_info = pathinfo($rels[1]);
    $extension = $path_info['extension'];
    if (file_exists('sites/default/files/' . $rels[1]) && ($extension == 'jpg' || $extension == 'png')) {
      echo $rels[1];
      unlink('sites/default/files/' . $rels[1]);
    }
  }
  // unlink($rels[1]);
}

function testing($mail) {
  $query = db_select('migrate_map_itguser', 'mmu');
  $query->join('users', 'u', 'mmu.destid1 = u.uid');
  $query->fields('u', array('mail'));
  $query->condition('u.mail', $mail, '=');
  $result = $query->execute()->fetchField();
  return $result;
}

function final_database_testing_with_xml_new_shrava() {
  $path = 'sites/default/files/story/';
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path)) as $filename) {
    $file_name = $filename->getFilename();
    echo '"' . $file_name . '", ';
    if ($file_name == '.' || $file_name == '..') {
      continue;
    }
    $array_issue_based[] = $file_name;
  }
  //p($array_issue_based);

  foreach ($array_issue_based as $story_value) {
    $xml = simplexml_load_file($path . $story_value, 'SimpleXMLElement');
    $tcount = 0;
    foreach ($xml->story as $xml_data) {
      $source_id = (int) $xml_data->id;
      echo $source_id . ', ';
      $result = get_data_from_storylist_table($source_id);
      if (empty($result)) {
        db_insert('itg_migrate_data_test') // Table name no longer needs {}
            ->fields(array(
              'source_id1' => $source_id,
              'destid1' => $source_id,
              'xml_name' => $file_name,
              'type' => 'story',
            ))
            ->execute();
      }
      $count ++;
    }
    $tcount = $tcount + $count;
  }
  pr($tcount);
}

function final_database_testing_with_xml_new_matching_record() {
  $path = 'sites/default/files/story/';
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path)) as $filename) {
    $file_name = $filename->getFilename();
    // echo '"'.$file_name.'", ';
    if ($file_name == '.' || $file_name == '..') {
      continue;
    }
    $array_issue_based[] = $file_name;
  }
  //p($array_issue_based);
  $tcount = 0;
  foreach ($array_issue_based as $story_value) {
    $xml = simplexml_load_file($path . $story_value, 'SimpleXMLElement');
    $count = 0;
    foreach ($xml->story as $xml_data) {
      $source_id = (int) $xml_data->id;
//p($source_id);
      echo $source_id . ', ';
      $result = get_data_from_storylist_table($source_id);
      if (!empty($result)) {
        db_insert('itg_migrate_data_test_new') // Table name no longer needs {}
            ->fields(array(
              'source_id1' => $source_id,
              'destid1' => $source_id,
              'xml_name' => $file_name,
              'type' => 'story',
            ))
            ->execute();
      }
      $count ++;
    }
    $tcount = $tcount + $count;
  }
}

/**
 * implement function for get diff from maigare_map_storylist
 */
function migrate_table_difference() {
  $query = db_select('migrate_map_itgstorylist', 'mm_story');
  $query->fields('mm_story', array('sourceid1', 'destid1'));
  $result = $query->execute();
  foreach ($result as $rel) {
    $subquery = db_select('itg_migrate_data_test_new', 'mm_story_new');
    $subquery->fields('mm_story_new', array('source_id1'));
    $subquery->condition('source_id1', $rel->sourceid1, '!=');
    $rels = $subquery->execute();
    if (!empty($rels)) {
      foreach ($rels as $re) {

        db_insert('itg_migrate_data_test_diff_table') // Table name no longer needs {}
            ->fields(array(
              'source_id1' => $re->source_id1,
              'destid1' => $re->source_id1,
              'xml_name' => 'file_name',
              'type' => 'story',
            ))
            ->execute();
      }
    }
  }
}

/*
 * itg_migrate_data_test
 * itg_migrate_data_test_new
  CREATE TABLE IF NOT EXISTS `itg_migrate_data_test_diff_table` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `source_id1` varchar(255) NOT NULL,
  `destid1` varchar(255) NOT NULL,
  `xml_name` varchar(255) NOT NULL,
  `type` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
  ) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=1;
 */

function update_node_revision_status() {
  db_update('node_revision') // Table name no longer needs {}
      ->fields(array(
        'status' => 1,
      ))
      ->condition('vid', $result->node_vid, '=')
      ->execute();
  echo 'VID ' . $result->node_vid . ' Node_Id ' . $result->node_nid;
}

//Shravan



function itg_db_migrate_related_content() {
  //code for XML read

  $xml_dir = 'test-related-story/';

  $path_xml = 'sites/default/files/migrate/xml_file/' . $xml_dir;


  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path_xml)) as $filename) {
    $file_name = $filename->getFilename();

    if ($file_name == '.' || $file_name == '..') {
      continue;
    }

    $xml_data = simplexml_load_file($path_xml . $file_name, 'SimpleXMLElement');

    $c_type = '';

    foreach ($xml_data->relatedcontents as $xml) {
      $content_id = get_itg_destination_id('migrate_map_itgstorylist', (int) $xml->id);
      $related_content_with_title_val = '';
      $related_content_val = '';
      $content_revision_id = get_node_revision_id($nid);
      foreach ($xml->relatedcontent as $relatedcontent_data) {

        $relatedcontent_type = (string) $relatedcontent_data->relatedcontenttype;

        if ($relatedcontent_type == 'text') {
          $relatedcontentid = get_itg_destination_id('migrate_map_itgstorylist', (int) $relatedcontent_data->relatedcontentid);
          $c_type = 'Story';
        }
        else if ($relatedcontent_type == 'photo') {
          $relatedcontentid = get_itg_destination_id('migrate_map_itgphotogallery', (int) $relatedcontent_data->relatedcontentid);
          $c_type = 'photogallery';
        }
        else if ($relatedcontent_type == 'video') {
          $relatedcontentid = get_itg_destination_id('migrate_map_itgvideogallery', (int) $relatedcontent_data->relatedcontentid);
          $c_type = 'Video';
        }

        $ordering = (string) $relatedcontent_data->ordering;
        $featured_content = (string) $relatedcontent_data->featuredcontent;
        $relatedcontenttitle = (string) $relatedcontent_data->relatedcontenttitle;
        $related_content_val .= 'IT_' . $relatedcontentid . ',';
        $related_content_with_title_val .= 'IT_' . $relatedcontentid . '@' . $c_type . '@' . $relatedcontenttitle . '!#!';
      }

      $related_content_insert_val = rtrim($related_content_val, ',');
      $related_content_insert_title_val = rtrim($related_content_with_title_val, '!#!');
      //insert data in Related Content field
      itg_data_insert_in_field($content_id, $content_revision_id, 'field_common_related_content', 'story', $related_content_insert_val);
      itg_data_insert_in_field($content_id, $content_revision_id, 'field_cm_related_content_detail', 'story', $related_content_insert_title_val);
    }
     if (copy($path_xml . $file_name, "sites/default/files/migrate/xml_file/story_all_complete_new/".$file_name)) {  unlink($path_xml . $file_name);}
  }
}

function itg_data_insert_in_field($nid, $revision_id, $field_name, $bundle, $data) {
  //$field_name = 'field_common_related_content';
  db_insert('field_data_' . $field_name)->fields(array(
    'entity_type' => 'node',
    'bundle' => $bundle,
    'deleted' => 0,
    'entity_id' => $nid,
    'revision_id' => $revision_id,
    'language' => 'und',
    'delta' => 0,
    $field_name . '_value' => $data))->execute();

  db_insert('field_revision_' . $field_name)->fields(array(
    'entity_type' => 'node',
    'bundle' => 'story',
    'deleted' => 0,
    'entity_id' => $nid,
    'revision_id' => $revision_id,
    'language' => 'und',
    'delta' => 0,
    $field_name . '_value' => $data))->execute();
}

/**
 * get new content id of itg by old content id
 * @param int $sourceid
 * @return int destination id
 */
function get_node_revision_id($nid) {
  $query = db_select('node', 'n');
  $query->fields('n', array('vid'));
  $query->condition('nid', $nid);

  return $query->execute()->fetchField();
}

final_database_testing_with_xml_failed_story_find();
/**
 * Implement function for failed story find
 */

function final_database_testing_with_xml_failed_story_find() {
  $path = 'sites/default/files/migrate/xml_file/story_all/';
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path)) as $filename) {
    $file_name = $filename->getFilename();
    echo '"' . $file_name . '", ';
    if ($file_name == '.' || $file_name == '..') {
      continue;
    }
    $array_issue_based[] = $file_name;
  }
  //p($array_issue_based);

  foreach ($array_issue_based as $story_value) {
    $xml = simplexml_load_file($path . $story_value, 'SimpleXMLElement');
    $tcount = 0;
    foreach ($xml->story as $xml_data) {
      $source_id = (int) $xml_data->id;
      echo $source_id . ', ';
      $result = get_data_from_storylist_table_value($source_id);
      if (!empty($result)) {
        db_insert('itg_migrate_data_test') // Table name no longer needs {}
            ->fields(array(
              'source_id1' => $source_id,
              'destid1' => $source_id,
              'xml_name' => $story_value,
              'type' => 'story_failed',
            ))
            ->execute();
      }
      $count ++;
    }
    $tcount = $tcount + $count;
  }
  pr($tcount);
}

/***
 * get failed story
 */
function get_data_from_storylist_table_value($source_id) {
  $query = db_select('migrate_map_itgstorylist', 'mm_story');
  $query->fields('mm_story', array('sourceid1', 'destid1'));
  $query->condition('sourceid1', $source_id, '=');
  $query->condition->isNull('destid1');
  $result = $query->execute();
  foreach($result as $rel) {
    $value_rel['source_id'] = $rel->sourceid1;
    $value_rel['destid'] = $rel->destid1;
  }
  return $value_rel;

}
?>
