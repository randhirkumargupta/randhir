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
  //field_story_template_guru
  $field_name = 'field_story_template_guru';
  $new_length = '3000';
  itg_change_text_field_max_length($field_name, $new_length);
  
  //phpinfo();
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
}

function create_section_cat_op($data, &$context) {
// Mongo code will be here
  if (function_exists('mongodb')) {
    $con = mongodb();
    $people = $con->taxonomy_term_data_mongo;

    // check connection
    if ($con) {
      $qry = array(

//          "tid" => (int) $data->tid,
//          "name" => $data->name,
//          "parent" => (int) $data->parent,
//          "vid" => (int) $data->vid,
//          "machine_name" => $data->machine_name,
//          "content_type" => get_content_type_list_for_this_term($data->tid),
//          "status" => 1,
//          'parent_data' => taxonomy_get_parents_all($data->tid),

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


/*
 * Utility to change the max length of a text field
 */
function itg_change_text_field_max_length($field_name, $new_length) {
  $field_table = 'field_data_' . $field_name;
  $field_revision_table = 'field_revision_' . $field_name;
  $field_column = $field_name . '_value';
 
  // Alter value field length in fields table
  db_query("ALTER TABLE `{$field_table}` CHANGE `{$field_column}` `{$field_column}` VARCHAR( {$new_length} )");
  // Alter value field length in fields revision table
  db_query("ALTER TABLE `{$field_revision_table}` CHANGE `{$field_column}` `{$field_column}` VARCHAR( {$new_length} )");
 
  // Update field config with new max length
  $result = db_query("SELECT CAST(`data` AS CHAR(10000) CHARACTER SET utf8) FROM `field_config` WHERE field_name = '{$field_name}'");
  $config = $result->fetchField();
  $config_array = unserialize($config);
  $config_array['settings']['max_length'] = $new_length;
  $config = serialize($config_array);
  
  //update field config table
  db_update('field_config')
    ->fields(array('data' => $config))
    ->condition('field_name', $field_name)
    ->execute();
  // cache clean by field modyfie
  cache_clear_all();
}