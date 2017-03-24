<?php

/*
 * Inc file contains the common functions
 */

/**
 * Get itg layout list for admin
 * @return array $output
 */
/*
 * Inc file contains the common functions
 */

function itg_layout_list_delete() {
  // configure the table header columns
  $header = array(
    array('data' => t('ID')),
    array('data' => t('Section name')),
    array('data' => t('Template name')),
    array('data' => t('Delete')),
    array('data' => t('Edit')),
  );

  if ($_GET['items_per_page']) {
    $items_per_page = $_GET['items_per_page'];
  }
  else {
    $items_per_page = 10;
  }
  if (arg(1) == 'home') {
    $itg_query = db_select('itg_layout_tpl', 'layout_tpl');
    $itg_query->fields('layout_tpl', array('id', 'section_name', 'template_name', 'status', 'created_date'));

    $itg_query->condition('layout_tpl.section_name', 'home_page', '=');

    $itg_query->extend('PagerDefault')->limit($items_per_page);
  }
  else {
    $itg_query = db_select('itg_layout_tpl', 'layout_tpl');
    $itg_query->fields('layout_tpl', array('id', 'section_name', 'template_name', 'status', 'created_date'));
    $itg_query->join('taxonomy_term_data', 'ttd', 'ttd.tid = layout_tpl.section_name');
    $itg_query->fields('ttd', array('name'));
    $itg_query->groupBy('layout_tpl.section_name');
    $itg_query->extend('PagerDefault')->limit($items_per_page);
  }

  /* if (!empty($_GET['section'])) {
    $itg_query->condition('layout_tpl.section_name', $_GET['section']);
    }
    else {
    $itg_query->condition('layout_tpl.section_name', 'home_page', '!=');
    } */

  $itg_result = $itg_query->execute()->fetchAll();

  $rows = array();

  $count = 0;

  foreach ($itg_result as $row) {
    $rows[] = array(
      array('data' => $count + 1),
      array('data' => $row->name),
      array('data' => $row->template_name),
      array('data' => l(t('delete'), 'itg-delete-layout/' . $row->id)),
      array('data' => l(t('Edit'), 'itg-layout-manager/section', array('query' => array('section' => $row->section_name, 'template_name' => $row->template_name)))),
    );
    $count++;
  }

  $output = render(drupal_get_form('itg_layout_manager_filter_form'));
  $output .= '<div class="view"><div class="attachment"><span class="count">Count (' . $count . ') </span>';
  $output .= l(t('Add New Template'), 'itg-layout-manager/section') . '</div></div>';
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table')), 'empty' => 'No results found'));

  // add the pager
  $output .= theme('pager');

  return $output;
}

/**
 * for layout delete for admin
 * @return array $output
 */
function itg_layout_delete() {
  phpinfo();
//  $module_list = module_disable();
//  echo '@@@';
//  p($module_list);
////  $module_list = module_list();
//  foreach ($module_list as $key => $val) {
//    echo $val.'</br>';
//  }
  //SELECT * FROM `itg_layout_manager` WHERE widget_name = '';
  //db_delete('itg_layout_manager')->condition('widget_name', '')->execute();
  //exit;
  /* db_delete('itg_layout_manager')->condition('layout_id', arg(1))->execute();
    db_delete('itg_layout_tpl')->condition('id', arg(1))->execute();
    drupal_goto('itg-admin-layout-list'); */
}

/**
 * for layout delete for admin
 * @return array $output
 */
function itg_section_widgets_list_delete() {
  //$result = db_truncate('itg_section_widgets_list')->execute();
  //echo 'truncate';exit;
}

/**
 * Implement function for create index.xml
 */
function create_index_xml(){
  $xml_path = 'sites/default/files/xml_file_chunk/';
  $foldername = 'story/';
  $path = $xml_path.$foldername;
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path)) as $filename) {
    $rest = substr($filename, -4);
    if($rest == ".xml"){
      $xml_file = $filename->getFilename();
      //$files = end(explode($foldername, (string) $filename));
      $xml_id = explode('.xml', $xml_file);
      $file_id[$xml_id[0]] = $xml_id[0];
    }        
  }
  ksort($file_id);
  $domDocument = new DOMDocument('1.0', "UTF-8");
  $domElement = $domDocument->createElement('content');
  $domDocument->appendChild($domElement);
  foreach($file_id as $new_file){
      $domElement1 = $domDocument->createElement('sourceid', $new_file);
      $domElement->appendChild($domElement1);
  }
  //echo count($file_id);
  //p($file_id);
  $domDocument->save($xml_path.'index/index.xml');
}

/**
 * Callback for create-poll-table
 * @param 
 */
function create_poll_table() {
  /* $query = 'CREATE TABLE IF NOT EXISTS `itg_poll_count_content` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `content_id` int(11) NOT NULL,
    `poll_id` int(11) NOT NULL,
    `content_type` varchar(250) NOT NULL,
    PRIMARY KEY (`id`)
    ) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=16 ;';
    db_query($query); */ 

 $file_name = 'indiatoday-story_2016-06-01.xml';
  //$file_name = 'indiatoday-story_2016-06-11.xml';
  //$file_name = 'indiatoday-story_2016-06-21.xml';
  //$file_name = 'indiatoday-story_2016-07-01.xml';
  //$file_name = 'indiatoday-story_2016-08-01.xml';
  //$file_name = 'indiatoday-story_2016-09-01.xml';
  //$file_name = 'indiatoday-story_2016-10-01.xml';
  //$file_name = 'indiatoday-story_2016-11-01.xml';
 // $file_name = 'indiatoday-story_2016-12-01.xml';
  $xml_path = 'sites/default/files/xml_file_chunk/';
  $xml = simplexml_load_file($xml_path . $file_name, 'SimpleXMLElement');  
  $i = 0;
  foreach ($xml->story as $stories) {
    $xml_city_id = (array) $stories->cities->city;
    $original_id = array();    
    // map city
    _map_xml_city($xml_city_id, $stories);

    // Map createdby
    _map_xml_user($stories, 'createdby');

    // Map modifiedby
    _map_xml_user($stories, 'modifiedby');
    // Get folder name.
    $category_ids = (string) $stories->categories->category;
    $split_category = explode('#', $category_ids);
    $folder_name = '';
    $pti_section = 0;
    if (count($split_category) == 2 && $split_category[0] == 177 && $split_category[1] == 1) {
      $folder_name = 'pti';
      $pti_section = 177;
    }
    if ($split_category[0] == 177) {
      $folder_name = 'pti';
    }
    $issue_based_story = (string) $stories->story_issue;
    if ($issue_based_story == 'yes') {
      $folder_name = 'issue_based_story';
    }
    // Map category.      
    if ($pti_section) {
      _map_xml_category($stories, $pti_section);
    }
    else {
      _map_xml_category($stories);
    }

    // Map primary category.
    _map_xml_primary_category($stories);

    // Map tags.
    _map_xml_tags($stories);

    // Map byline
    _map_xml_byline($stories);    
    if (!empty($folder_name)) {
      $stories->asXml($xml_path . $folder_name . '/' . $stories->id . '.xml');
    }
    else {
      $stories->asXml($xml_path . 'story/' . $stories->id . '.xml');
    }    
    ++$i;
  }

  return 'hi';
}

/**
 * Map byline with DataBase.
 *
 * @param type $stories
 */
function _map_xml_byline(&$stories) {
  if (isset($stories->bylines->byline) && !empty($stories->bylines->byline)) {
    $i = 0;
    foreach ($stories->bylines->byline as $final_byline) {
      $source_bid = (string) $final_byline;
      if (!empty($source_bid)) {
        $orignal_byline = get_itg_destination_id('migrate_map_itgbyline', $source_bid);
        $stories->bylines->byline[$i] = $orignal_byline;
        ++$i;
      }
    }
  }
}

/**
 * Map tag name.
 *
 * @param stdObject $stories
 */
function _map_xml_tags(&$stories) {
  if (isset($stories->tags->tag) && !empty($stories->tags->tag)) {
    $i = 0;
    foreach ($stories->tags->tag as $final_tags) {
      $source_tags = (string) $final_tags;
      try {
        $orignal_tag = get_itg_destination_id('migrate_map_itgtags', $source_tags);
      }
      catch (Exception $ex) {
        drupal_set_message($ex->getMessage(), 'error');
      }
      $stories->tags->tag[$i] = $orignal_tag;
      ++$i;
    }
  }
}

/**
 * Map primary category.
 *
 * @param stdObject $stories
 */
function _map_xml_primary_category(&$stories) {
  if (isset($stories->primarycategory) && !empty($stories->primarycategory)) {
    $source_cid = (string) $stories->primarycategory;
    $pcategory_array = explode('#', $source_cid);
    $parray_count = count($pcategory_array);
    $table_name = itg_migrate_category_table($parray_count);
    $last_value = end($pcategory_array);
    $source_cid = (string) $last_value;
    $orignal_pcategory = get_itg_destination_id($table_name, $source_cid);
    $stories->primarycategory = $orignal_pcategory;
  }
}

/**
 * Map category to original category.
 * 
 * @param stdObject $stories
 */
function _map_xml_category(&$stories, $pti_section = NULL) {
  $data_category = '';
  if (isset($stories->categories->category) && !empty($stories->categories->category)) {
    $i = 0;
    foreach ($stories->categories->category as $final_category) {
      $category_array = explode('#', $final_category);
      $array_count = count($category_array);
      $table_name = itg_migrate_category_table($array_count);
      $last_value = end($category_array);
      $source_cid = (string) $last_value;      
      if ($pti_section != NULL) {
        $table_name = 'migrate_map_itgsection';
        $source_cid = $pti_section;
        $orignal_category = get_itg_destination_id($table_name, $source_cid);
      }
      else {
        $orignal_category = get_itg_destination_id($table_name, $source_cid);
      }      
      $stories->categories->category[$i] = $orignal_category;
      ++$i;
    }    
  }
}

/**
 * Map Author id to original DB id.
 *
 * @param stdObject $stories
 */
function _map_xml_user(&$stories, $op) {
  // manage created user
  if (isset($stories->{$op}) && !empty($stories->{$op})) {

    $created_uid = (string) $stories->{$op};
    try {
      $orignal_crated_uid = get_itg_destination_id('migrate_map_itguser', $created_uid);
    }
    catch (Exception $ex) {
      drupal_set_message($ex->getMessage(), 'error');
    }
    $stories->{$op} = $orignal_crated_uid;
  }
  else {
    $stories->{$op} = 0;
  }
}

/**
 * Map city to original id.
 *
 * @param array $xml_city_id
 * @param stdObject $stories
 */
function _map_xml_city($xml_city_id, &$stories) {
  // Get city original id.
  $errors = array_filter($xml_city_id);
  if (!empty($errors)) {
    foreach ($xml_city_id as $source_city) {
      $original_id[] = get_itg_destination_id('migrate_map_itgcity', $source_city);
    }

    // Map xml city id from databaase city id.
    $j = 0;
    foreach ($stories->cities->city as $key => $new_city) {
      $stories->cities->city[$j] = $original_id[$j];
      ++$j;
    }
  }
}
  
function create_section_cat_op($data, &$context) {
// Mongo code will be here
  if (function_exists('mongodb')) {
    $con = mongodb();
    $people = $con->taxonomy_term_data_mongo;

    // check connection
    if ($con) {
      $qry = array(
          "tid" => (int) $data->tid,
          "name" => $data->name,
          "parent" => (int) $data->parent,
          "vid" => (int) $data->vid,
          "machine_name" => $data->machine_name,
          "content_type" => get_content_type_list_for_this_term($data->tid),
          "status" => 1,
          'parent_data' => taxonomy_get_parents_all($data->tid),
      );
      $result = $people->insert($qry);
    }
    drupal_set_message('data inserted successfully for ' . json_encode($result));
  }
}

/**
 * Implements create_section_cat_op_batch_finished().
 */
function create_section_cat_op_batch_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t('migration processed successfully.'));
  } else {
    drupal_set_message(t('An error occurred while processing.'));
  }
}

/**
 * Implements get_content_type_list_for_this_term()
 */
function get_content_type_list_for_this_term($tid) {
  $data = array();
  $query = db_select('field_data_field_cm_select_type', 'td');
  $res = $query
          ->condition('td.entity_id', $tid)
          ->fields('td', array('field_cm_select_type_value',))
          ->execute();

  foreach ($res as $result) {
    $data[] = $result->field_cm_select_type_value;
  }
  if (!empty($data)) {
    return implode(',', $data);
  }
  return '';
}