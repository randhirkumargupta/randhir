<?php

/**
 * @file
 * Contain admin function for multiple sitemap.
 */
module_load_include('inc', 'itg_sitemap_chunks', 'includes/itg_sitemap_chunks.db');

/**
 * Form callback.
 */
function itg_sitemap_chunks_add_sitemap($form, &$form_state) {
  $arguments = itg_sitemap_chunks_get_content_data();
  $form['file_name'] = array(
    '#title' => t('Enter Sitemap Name'),
    '#type' => 'textfield',
    '#default_value' => time(),
    '#description' => t('Enter file name without xml extension.Allowed only "a-z, - and _"'),
    '#required' => TRUE,
    '#prefix' => '<div class="hide">',
    '#suffix' => '</div>',
  );

  $content_types = itg_sitemap_chunks_get_node_types();

  $entities = array(
    0 => array('entity_type' => 'content', 'types' => $content_types),
  );

  foreach ($entities as $value) {
    itg_sitemap_chunks_create_tabular_checkbox_fields($form, $value['types'], $value['entity_type'], $arguments);
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

/**
 * Function which gives data of itg_sitemap_chunks_content table which is saved
 * from setting form of content type.
 * 
 * @return array
 */
function itg_sitemap_chunks_get_content_data() {
  $query = db_select('itg_sitemap_chunks_content', 'scc');
  $query->fields('scc');
  $query->orderBy('scc.target_ms_id', 'DESC');
  $result['content'] = $query->execute()->fetchAll();
  return $result;
}

/**
 * Function which delete table data of given input table name.
 * 
 * @param string $table_name
 */
function itg_sitemap_chunks_get_content_data_delete($table_name) {
  if (!empty($table_name)) {
    db_delete($table_name)->execute();
  }
}

//function itg_sitemap_chunks_get_ms_id() {
//  $query = db_select('itg_sitemap_chunks', 'scc');
//  $query->fields('scc', array('ms_id'));
//  $query->orderBy('scc.ms_id', 'DESC');
//  $result = $query->execute()->fetchField();
//  return $result;
//}

function itg_sitemap_chunks_count_files() {
  $query = db_select('itg_sitemap_chunks', 'isc');
  $query->fields('isc', array('ms_id'));
  return $query->execute()->fetchField();
}

/**
 * Validate handler for form.
 */
//function itg_sitemap_chunks_add_sitemap_validate(&$form, &$form_state) {
//
//  // Validate file name.
//  $file_name = isset($form_state['values']['file_name']) ? $form_state['values']['file_name'] : NULL;
//
//  if (is_null($file_name)) {
//    form_set_error('file_name', t('Please provide sitemap name'));
//  }
//  else {
//    if (preg_match('/[^a-z_\-]/i', $file_name)) {
//      form_set_error('file_name', t('Please provide sitemap name in right format, allowed only a-z,_and -'));
//    }
//  }
//}

/**
 * Submit handler for form.
 */
function itg_sitemap_chunks_add_sitemap_submit(&$form, &$form_state) {

  itg_sitemap_chunks_get_content_data_delete('itg_sitemap_chunks_content');
  itg_sitemap_chunks_get_content_data_delete('itg_sitemap_chunks');

  $file_name = isset($form_state['values']['file_name']) ? $form_state['values']['file_name'] : NULL;
  $selected_ct = array();
  // Get selected content types.
  $content_types = $form_state['values']['content'];
  foreach ($content_types as $i => $content_type) {
    foreach ($content_type['content_type'] as $key => $value) {
      if ($key === $value) {

        $priority = isset($content_type['priority']) ? $content_type['priority'] : '0.5';
        $changefreq = isset($content_type['changefreq']) ? $content_type['changefreq'] : 'monthly';

        $selected_ct[$i]['name'] = $value;
        $selected_ct[$i]['priority'] = $priority;
        $selected_ct[$i]['changefreq'] = $changefreq;
      }
    }
  }
  $update_ms_id = $form_state['ms_id'];
  $input['file_name'] = $file_name;
  $ms_id = itg_sitemap_chunks_save_record($input, $update_ms_id);

  if (!empty($selected_ct)) {
    itg_sitemap_chunks_delete_sub_record('content', $ms_id);
    itg_sitemap_chunks_save_sub_record('content', $ms_id, $selected_ct);
  }
}

/**
 * Return all priority values.
 *
 * @return array
 *   Having priority values.
 */
function itg_sitemap_chunks_get_priority_options() {

  $priority = array(
    '0.1' => '0.1',
    '0.2' => '0.2',
    '0.3' => '0.3',
    '0.4' => '0.4',
    '0.5' => '0.5',
    '0.6' => '0.6',
    '0.7' => '0.7',
    '0.8' => '0.8',
    '0.9' => '0.9',
    '1.0' => '1.0',
  );

  return $priority;
}

/**
 * Return all changefreq values.
 *
 * @return array
 *   Having changefreq values.
 */
function itg_sitemap_chunks_get_changefreq_options() {

  $changefreq = array(
    'always' => 'always',
    'hourly' => 'hourly',
    'daily' => 'daily',
    'weekly' => 'weekly',
    'monthly' => 'monthly',
    'yearly' => 'yearly',
    'never' => 'never',
  );

  return $changefreq;
}

/**
 * Get the content type name in the desired format.
 *
 * @return array
 *   Content Type name in the desired format.
 */
function itg_sitemap_chunks_get_node_types() {
  $types = array();
  $content_types = node_type_get_types();
  foreach ($content_types as $type => $details) {
    $types[$type] = $details->name;
  }
  return $types;
}

/**
 * Get the vocab type name in the desired format.
 *
 * @return array
 *   Vocab name name in the desired format.
 */
function itg_sitemap_chunks_get_vocab_types() {
  $types = array();
  $vocabs_types = taxonomy_vocabulary_get_names();
  foreach ($vocabs_types as $type => $details) {
    $types[$type] = $details->name;
  }
  return $types;
}

/**
 * Dashboard for multiple sitemap.
 *
 * @return html
 *   Having details about created sitemaps.
 */
//function itg_sitemap_chunks_dashboard() {
//  $output = t('Your installation of multiple sitemap module  is not correct.');
//  if (db_table_exists('itg_sitemap_chunks')) {
//    $output = t('You have not created any sitemap yet.');
//    $results = db_select('itg_sitemap_chunks', 'ms')
//        ->fields('ms')
//        ->execute()
//        ->fetchAll();
//
//    $header = array(
//      'File Name',
//      'Custom links',
//      'Edit',
//      'Delete',
//    );
//
//    $rows = array();
//    if (!empty($results)) {
//      foreach ($results as $key => $result) {
//        $ms_id = $result->ms_id;
//        // $rows[$key]['msid'] = $result->ms_id.
//        $rows[$key]['fname'] = $result->file_name;
//        $rows[$key]['custom_links'] = $result->custom_links;
//
//        $delete_path = '/admin/config/search/itg-multiple-sitemap/delete/';
//        $edit_path = '/admin/config/search/itg-multiple-sitemap/edit/';
//
//        // Add webform query.
//        $delete_path .= $ms_id;
//        $edit_path .= $ms_id;
//        $rows[$key]['edit'] = l(t('Edit'), $edit_path);
//        $rows[$key]['delete'] = l(t('Delete'), $delete_path);
//      }
//
//      return theme('table', array('header' => $header, 'rows' => $rows));
//    }
//  }
//
//  return $output;
//}

/**
 * Callback function for edit the sitemap.
 *
 * @param int $ms_id
 *   Multiple site map id.
 *
 * @return html
 *   Having drupal edit form.
 */
function itg_sitemap_chunks_edit_sitemap($ms_id) {

  if (!(is_numeric($ms_id) && $ms_id > 0)) {

    return drupal_set_message(t('sitemap id is not exist'), 'error');
  } else {

    $records = itg_sitemap_chunks_get_record($ms_id);

    $form = drupal_get_form('itg_sitemap_chunks_add_sitemap', $records);

    return drupal_render($form);
  }
}

/**
 * Callbeck function for delete record.
 *
 * @param int $ms_id
 *   Map id.
 *
 * @return array
 *   Having form html.
 */
function itg_sitemap_chunks_delete_sitemap($ms_id) {
  $form = drupal_get_form('itg_sitemap_chunks_delete_sitemap_page', $ms_id);
  return $form;
}

/**
 * Callback function for delete confirm page.
 *
 * @param int $ms_id
 *   Having arguments which is require for deleting a record.
 */
function itg_sitemap_chunks_delete_sitemap_page($form, &$form_state, $ms_id) {

  $form['warning'] = array(
    '#markup' => '<div><strong>' . t('Are you sure? This action can not be undone.') . '</strong></div>',
  );

  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#submit' => array('itg_sitemap_chunks_callback_for_delete_button'),
    '#limit_validation_errors' => array(),
  );

  $form['actions']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => array('itg_sitemap_chunks_callback_for_cancel_button'),
    '#limit_validation_errors' => array(),
  );

  $form_state['storage']['ms_id'] = $ms_id;

  return $form;
}

/**
 * Delete callback.
 */
function itg_sitemap_chunks_callback_for_delete_button($form, &$form_state) {
  $ms_id = $form_state['storage']['ms_id'];

  $deleted = db_delete('itg_sitemap_chunks')
    ->condition('ms_id', $ms_id)
    ->execute();

  $record_types = array('content', 'menu', 'vocab');

  foreach ($record_types as $record_type) {
    itg_sitemap_chunks_delete_sub_record($record_type, $ms_id);
  }

  $url = 'admin/config/search/itg-multiple-sitemap/dashboard';
  if ($deleted) {
    drupal_set_message(t('Successfully deleted'), 'status');
  } else {
    drupal_set_message(t('Not  deleted'), 'error');
  }
  drupal_goto($url);
}

/**
 * Callback function for cancel button & redirects.
 */
function itg_sitemap_chunks_callback_for_cancel_button() {
  $url = 'admin/config/search/itg-multiple-sitemap/dashboard';
  drupal_goto($url);
}

/**
 * Get form checkbox element.
 *
 * @param object &$form
 *   Having form reference.
 * @param array $types
 *   Having specific entity type.
 * @param string $entity_type
 *   Entity type.
 * @param array $arguments
 *   Having edit form argument.
 */
function itg_sitemap_chunks_create_tabular_checkbox_fields(&$form, $types = array(), $entity_type, $arguments = array()) {

  $setvalues = array();
  if (!empty($arguments[$entity_type])) {
    $records = $arguments[$entity_type];
    foreach ($records as $key => $record) {
      $entitytype = $entity_type . '_type';
      $setvalues[$record->$entitytype]['priority'] = $record->priority;
      $setvalues[$record->$entitytype]['changefreq'] = $record->changefreq;
    }
  }

//  // Form container element.
//  $form['multiple_siteamp_' . $entity_type . '_container'] = array(
//    '#type' => 'fieldset',
//    '#title' => t('@entity_type type settings', array('@entity_type' => $entity_type)),
//  );

  $form['multiple_siteamp_' . $entity_type . '_container'][$entity_type] = array(
    '#prefix' => '<div id="multiple_siteamp_"' . $entity_type . '"_types">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
    '#theme' => 'table',
    '#attributes' => array('class' => array("views-table")),
    '#header' => array(t('@entity_type Type', array('@entity_type' => ucwords($entity_type))), t('Priority'), t('Frequency')),
    '#rows' => array(),
  );

  $priority_list = itg_sitemap_chunks_get_priority_options();

  $changefreq_list = itg_sitemap_chunks_get_changefreq_options();

  $setvalueskeys = array_keys($setvalues);
  foreach ($types as $key => $type) {

    // Set default values.
    $default_values = array();

    if (in_array($key, $setvalueskeys)) {
      $default_values['type'] = $key;
      $default_values['priority'] = $setvalues[$key]['priority'];
      $default_values['changefreq'] = $setvalues[$key]['changefreq'];
    }

    // Build the fields for this row in the table. We'll be adding
    // these to the form several times, so it's easier if they are
    // individual variables rather than in an array.
    $option = array($key => $key);
    $entity = array(
      '#id' => 'ms_' . $entity_type . '_' . $key,
      '#type' => 'checkboxes',
      '#options' => $option,
      '#default_value' => !empty($default_values) ? array($default_values['type']) : array(),
      '#title' => '',
    );

    $priority = array(
      '#id' => 'msp_' . $entity_type . '_' . $key,
      '#type' => 'select',
      '#default_value' => isset($default_values['priority']) ? $default_values['priority'] : "0.5",
      '#options' => $priority_list,
    );

    $changefreq = array(
      '#id' => 'msf_' . $entity_type . '_' . $key,
      '#type' => 'select',
      '#default_value' => isset($default_values['changefreq']) ? $default_values['changefreq'] : "monthly",
      '#options' => $changefreq_list,
    );

    // Include the fields so they'll be rendered and named
    // correctly, but they'll be ignored here when rendering as
    // we're using #theme => table.
    // Note that we're using references to the variables, not just
    // copying the values into the array.
    $form['multiple_siteamp_' . $entity_type . '_container'][$entity_type][] = array(
      $entity_type . '_type' => &$entity,
      'priority' => &$priority,
      'changefreq' => &$changefreq,
    );

    // Now add references to the fields to the rows that
    // `theme_table()` will use.
    // As we've used references, the table will use the very same
    // field arrays as the FAPI used above.
    $form['multiple_siteamp_' . $entity_type . '_container'][$entity_type]['#rows'][] = array(
      array('data' => &$entity),
      array('data' => &$priority),
      array('data' => &$changefreq),
    );

    // Because we've used references we need to `unset()` our
    // variables. If we don't then every iteration of the loop will
    // just overwrite the variables we created the first time
    // through leaving us with a form with 3 copies of the same fields.
    unset($entity);
    unset($priority);
    unset($changefreq);
    unset($option);
  }
}

/**
 *  Setting form for chunks i.e. .gd files.
 */
function itg_sitemap_chunks_setting_form() {
  drupal_set_message(t('If you will submit this form , all the sitemap chunk will be deleted.'));
  $form = array();
  $form['itg_sitemap_chunks_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of Chunk'),
    '#default_value' => variable_get('itg_sitemap_chunks_number', 50000),
    '#size' => 20,
    '#maxlength' => 20,
  );
  $form['itg_sitemap_exclude_nid'] = array(
    '#type' => 'textarea',
    '#title' => t('Nids To Exclude'),
    '#default_value' => variable_get('itg_sitemap_exclude_nid'),
    '#description' => 'Enter comma seperated nodeis you want to exclude in sitemap',
  );
  $form['#submit'][] = 'itg_sitemap_chunks_delete_chunks';
  return system_settings_form($form);
}

/**
 *  Setting from for sitemap.xml
 */
function itg_sitemap_mixedcontent_setting_form() {
  $form = array();
  $form['itg_sitemap_chunks_number_for_sitemap'] = array(
    '#type' => 'textfield',
    '#title' => t('Limit For Sitemap.xml'),
    '#default_value' => variable_get('itg_sitemap_chunks_number_for_sitemap', 2000),
    '#size' => 20,
    '#maxlength' => 20,
  );
  return system_settings_form($form);
}

/**
 *  Setting from for sitemap.xml
 */
function itg_sitemap_chunks_s3_bucket_setting_form() {
  $form = array();
  $form['itg_sitemap_chunks_s3_bucket_folder_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Xml generated Directory'),
    '#default_value' => !empty(SITEMAP_BUCKET) ? SITEMAP_BUCKET : "sitemapxml_others",
    '#size' => 20,
    '#maxlength' => 20,
  );
  return system_settings_form($form);
}

/**
 *  General setting form for rss
 */
function itg_sitemap_chunks_gereral_setting_form() {
  $form = array();

  $form['itg_rss_chunks_number'] = array(
    '#type' => 'textfield',
    '#title' => t('RSS: Items Chunks'),
    '#default_value' => variable_get('itg_rss_chunks_number'),
    '#description' => 'Number of items should appear in RSS',
    '#size' => 20,
    '#maxlength' => 20,
    '#required' => TRUE,
  );

  $form['video_category_tid'] = array(
    '#type' => 'textfield',
    '#title' => t('RSS: Video Section Tid'),
    '#default_value' => variable_get('video_category_tid'),
    '#description' => 'This Video Section Tid will be used to filter content for rss for <b> Videogallery </b> content type',
    '#size' => 20,
    '#maxlength' => 20,
    '#required' => TRUE,
  );

  $form['photo_category_tid'] = array(
    '#type' => 'textfield',
    '#title' => t('RSS: Photo Section Tid'),
    '#default_value' => variable_get('photo_category_tid'),
    '#description' => 'This Photo Section Tid will be used to filter content for rss for <b> Photogallery </b> content type',
    '#size' => 20,
    '#maxlength' => 20,
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

/**
 *  {@inheritdocs}
 */
function itg_sitemap_chunks_delete_chunks() {
  module_load_include('inc', 'itg_videogallery', 'includes/itg_videogallery_aws_s3');
  itg_video_get_s3_video_del('s3fs-public/'.SITEMAP_BUCKET);
  // remove directory if previously created sitemap.
  drupal_set_message(t("Sitemap directory has been deleted , Please create sitemap again"));
}

/**
 *  {@inheritdocs}
 */
function itg_sitemap_chunks_setting_form_validate($form, &$form_state) {
  $number_chunks = $form_state['values']['itg_sitemap_chunks_number'];
  $node_ids = trim($form_state['values']['itg_sitemap_exclude_nid']);
  $strings = array();
  if (!is_numeric($number_chunks)) {
    form_set_error('itg_sitemap_chunks_number', t("Field Must Be Numaric"));
  } else if (is_numeric($number_chunks) && $number_chunks < 1) {
    form_set_error('itg_sitemap_chunks_number', t("Field Must Be positive and greather then zero"));
  }

  if (!empty($node_ids)) {
    $nodes = explode(",", $node_ids);
    foreach ($nodes as $nid) {
      if ((integer) $nid == 0) {
        $strings[] = $nid;
      }
    }
  }

  if (!empty($strings)) {
    form_set_error('itg_sitemap_exclude_nid', t("Node Id Must be integer @strnodes", array('@strnodes' => implode(",", $strings))));
  }
}
