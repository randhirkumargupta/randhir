<?php

/*
 * Inc file contains the common functions
 */

/**
 * Get itg layout list for admin
 * @return array $output
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
function create_index_xml() {
  $xml_path = 'sites/default/files/xml_file_chunk/';
  $foldername = 'story/';
  $path = $xml_path . $foldername;
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path)) as $filename) {
    $rest = substr($filename, -4);
    if ($rest == ".xml") {
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
  foreach ($file_id as $new_file) {
    $domElement1 = $domDocument->createElement('sourceid', $new_file);
    $domElement->appendChild($domElement1);
  }
  //echo count($file_id);
  //p($file_id);
  $domDocument->save($xml_path . 'index/index.xml');
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
 * Implements create_section_category_in_mongo()
 */
// Code started for sending the section and it category data into mongo DB


function create_section_category_in_mongo() {

  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Please submit for bulk insert section and its category'),
  );

  return $form;
}

/**
 * Implements create_section_category_in_mongo_submit().
 */
function create_section_category_in_mongo_submit($form, &$form_state) {

  $query = db_select('taxonomy_term_data', 'td');
  $query->leftJoin('taxonomy_term_hierarchy', 'th', 'th.tid = td.tid');
  $query->leftJoin('itg_category_manager', 'icm', 'icm.tid = td.tid');
  $query->leftJoin('taxonomy_vocabulary', 'tv', 'tv.vid=td.vid');
  $result = $query
      ->condition('td.vid', CATEGORY_MANAGMENT)
      ->fields('td', array('tid', 'name', 'vid'))
      ->fields('th', array('parent'))
      ->fields('tv', array('machine_name'))
      ->fields('icm', array('status'))
      ->execute();


  foreach ($result as $chunk_data) {
    if (!empty($chunk_data) && isset($chunk_data)) {
      $operations[] = array('create_section_cat_op', array($chunk_data));
    }
  }

  $batch = array(
    'title' => t('Migrating data finally....please wait....!'),
    'operations' => $operations,
    'finished' => 'create_section_cat_op_batch_finished',
    'init_message' => t('Migration started...please wait....!'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Migration checking process has encountered an error.'),
    'file' => drupal_get_path('module', 'itg_miscellaneous') . '/includes/itg_miscellaneous.inc',
  );

  batch_set($batch);
  batch_process('create-section-category-in-mongo');
}

/**
 * Implements create_section_cat_op().
 */
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
        "status" => (int) $data->status,
        'parent_data' => taxonomy_get_parents_all($data->tid),
      );
      $result = $people->insert($qry);
    }
    //drupal_set_message('data inserted successfully for ' . json_encode($result));
  }
}

/**
 * Implements create_section_cat_op_batch_finished().
 */
function create_section_cat_op_batch_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t('migration processed successfully.'));
  }
  else {
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

/**
 * Helper function to show mongo detail
 */
function itg_get_mongo_detail() {
  $type = arg(1);
  $id = arg(2);
  $data = '';
  if (function_exists('mongodb')) {
    $con = mongodb();
    if ($type == 'likedislike') {
      $people = $con->itg_custom_flag_count;
      $cond = array('nid' => $id);
      $cursor = $people->find($cond);
      foreach ($cursor as $document) {
        print 'Like : ' . $document['like_count'];
        print '<br/>';
        print 'DisLike : ' . $document['dislike_count'];
      }
    }
    if ($type == 't_share') {
      $people = $con->front_user_activity;
      $cond = array('nid' => $id, 'activity' => 'twitter_share');
      $cursor = $people->count($cond);
      print 'Twitter share : ' . $cursor;
    }

    if ($type == 'g_share') {
      $people = $con->front_user_activity;
      $cond = array('nid' => $id, 'activity' => 'google_share');
      $cursor = $people->count($cond);
      print 'Google share : ' . $cursor;
    }
    
    if ($type == 'comment') {
      $people = $con->itgcms_comment;
      $cond = array('page_id' => $id);
      $cursor = $people->count($cond);
      print 'Comment : ' . $cursor;
    }
    if ($type == 'view') {
      $people = $con->pagedetails;
      $cond = array('nid' => $id);
      $cursor = $people->count($cond);
      print 'Number of View : ' . $cursor;
    }
  }
  if ($type == 'f_share') {
    $fb_share = itg_get_fb_share($id, 'Facebook Share');
    print 'Facebook Share : '.$fb_share;
  }
  
}
