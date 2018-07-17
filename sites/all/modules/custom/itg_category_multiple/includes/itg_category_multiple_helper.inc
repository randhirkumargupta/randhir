<?php

/**
 * Implements itg_category_multiple_find()
 */

function itg_category_multiple_find() {
  $render_data = array();
  
  $render_data['b_cat_opt'] = '';
  $render_data['b_sub_cat_opt'] = '';
  $render_data['b_sub_sub_cat_opt'] = '';
  $render_data['b_sub_sub_sub_cat_opt'] = '';
  $render_data['b_cat'] = '';
  $render_data['b_sub_cat'] = '';
  $render_data['b_sub_sub_cat'] = '';
  $render_data['b_sub_sub_sub_cat'] = '';
  
  $category = $_POST['type'];
  switch ($category) {
    case 'itg_section[]':

      if (isset($_POST['section']) && count($_POST['section']) >= 1 && !empty($_POST['section'])) {
        $main_category = get_categoryies_by_tid(json_decode($_POST['section']));
        $render_data['pcat'] = isset($_POST['pcat']) ? $_POST['pcat'] : '';
        $itg_category_array_holder = array();

        $itg_category_array_holder[] = json_decode($_POST['section']);

        if (!empty($main_category['html']) && isset($_POST['b_cat']) && !empty($_POST['b_cat'])) {
          $category_data_c_after_intrs = array_values(itg_category_multiple_array_intersect($main_category['tids'], json_decode($_POST['b_cat'])));
          $render_data['b_cat'] = $_POST['b_cat'];
          $category_data_c = get_categoryies_by_tid($category_data_c_after_intrs);
          $render_data['b_cat_opt'] = $main_category['html'];
          $itg_category_array_holder[] = $category_data_c_after_intrs;
        }

        if (isset($category_data_c['tids']) && !empty($render_data['b_cat_opt']) && isset($_POST['b_sub_cat']) && !empty($_POST['b_sub_cat'])) {
          $sub_category_data_c_after_intrs = itg_category_multiple_array_intersect($category_data_c['tids'], json_decode($_POST['b_sub_cat']));
          $render_data['b_sub_cat'] = $_POST['b_sub_cat'];
          $sub_category_data_c = get_categoryies_by_tid($sub_category_data_c_after_intrs);
          $render_data['b_sub_cat_opt'] = $category_data_c['html'];
          $itg_category_array_holder[] = $sub_category_data_c_after_intrs;
        }
        if (!empty($sub_category_data_c['tids']) && !empty($render_data['b_cat_opt']) && !empty($render_data['b_sub_cat_opt']) && isset($_POST['b_sub_sub_cat']) && !empty($_POST['b_sub_sub_cat'])) {
          $sub_sub_category_data_c_after_intrs = itg_category_multiple_array_intersect($sub_category_data_c['tids'], json_decode($_POST['b_sub_sub_cat']));
          $render_data['b_sub_sub_cat'] = $_POST['b_sub_sub_cat'];
          $sub_sub_category_data_c = get_categoryies_by_tid($sub_sub_category_data_c_after_intrs);
          $render_data['b_sub_sub_cat_opt'] = $sub_category_data_c['html'];
          $itg_category_array_holder[] = $sub_sub_category_data_c_after_intrs;
        }

        if (!empty($sub_sub_category_data_c['tids']) && !empty($render_data['b_cat_opt']) && !empty($render_data['b_sub_sub_cat_opt']) && isset($_POST['b_sub_sub_sub_cat']) && !empty($_POST['b_sub_sub_sub_cat'])) {
          $sub_sub_sub_category_data_c_after_intrs = itg_category_multiple_array_intersect($sub_sub_category_data_c['tids'], json_decode($_POST['b_sub_sub_sub_cat']));
          $render_data['b_sub_sub_sub_cat'] = $_POST['b_sub_sub_sub_cat'];
          $sub_sub_sub_category_data_c = get_categoryies_by_tid($sub_sub_sub_category_data_c_after_intrs);
          $render_data['b_sub_sub_sub_cat_opt'] = $sub_sub_category_data_c['html'];
          $itg_category_array_holder[] = $sub_sub_sub_category_data_c_after_intrs;
        }

        $itg_category_list_for_primary = array();
        foreach ($itg_category_array_holder as $arr_chunk) {
          if (is_array($arr_chunk)) {
            $itg_category_list_for_primary = array_merge($itg_category_list_for_primary, $arr_chunk);
          }
        }

        $primary_category = get_parent_structure_by_tid($itg_category_list_for_primary);
        $render_data['main'] = $main_category['html'];
        $render_data['primary'] = $primary_category;
        print json_encode($render_data);
        drupal_exit();
      }
      break;
    case 'itg_category[]':
      if (isset($_POST['category']) && count($_POST['category']) >= 1 && !empty($_POST['category'])) {
        $category_data_c = get_categoryies_by_tid(json_decode($_POST['category']));
        $section = json_decode($_POST['section']);
        $category = json_decode($_POST['category']);
        $render_data['main'] = $category_data_c['html']; // Category default option 
        $render_data['pcat'] = isset($_POST['pcat']) ? $_POST['pcat'] : '';
        $itg_category_array_holder = array();

        // Default initilization for section and category
        $itg_category_array_holder[] = json_decode($_POST['section']);  // Holding section  in an array
        $itg_category_array_holder[] = json_decode($_POST['category']);  // Holding category  in an array

        if (isset($category_data_c['tids']) && isset($_POST['b_sub_cat']) && !empty($_POST['b_sub_cat'])) {
          $sub_category_data_c_after_intrs = itg_category_multiple_array_intersect($category_data_c['tids'], json_decode($_POST['b_sub_cat']));
          $render_data['b_sub_cat'] = $_POST['b_sub_cat'];
          $sub_category_data_c = get_categoryies_by_tid($sub_category_data_c_after_intrs);
          $render_data['b_sub_cat_opt'] = $category_data_c['html'];
          $itg_category_array_holder[] = $sub_category_data_c_after_intrs;
        }
        if (!empty($sub_category_data_c['tids']) && !empty($render_data['b_sub_cat_opt']) && isset($_POST['b_sub_sub_cat']) && !empty($_POST['b_sub_sub_cat'])) {
          $sub_sub_category_data_c_after_intrs = itg_category_multiple_array_intersect($sub_category_data_c['tids'], json_decode($_POST['b_sub_sub_cat']));
          $render_data['b_sub_sub_cat'] = $_POST['b_sub_sub_cat'];
          $sub_sub_category_data_c = get_categoryies_by_tid($sub_sub_category_data_c_after_intrs);
          $render_data['b_sub_sub_cat_opt'] = $sub_category_data_c['html'];
          $itg_category_array_holder[] = $sub_sub_category_data_c_after_intrs;
        }

        if (!empty($sub_sub_category_data_c['tids']) && !empty($render_data['b_sub_sub_cat_opt']) && isset($_POST['b_sub_sub_sub_cat']) && !empty($_POST['b_sub_sub_sub_cat'])) {
          $sub_sub_sub_category_data_c_after_intrs = itg_category_multiple_array_intersect($sub_sub_category_data_c['tids'], json_decode($_POST['b_sub_sub_sub_cat']));
          $render_data['b_sub_sub_sub_cat'] = $_POST['b_sub_sub_sub_cat'];
          $sub_sub_sub_category_data_c = get_categoryies_by_tid($sub_sub_sub_category_data_c_after_intrs);
          $render_data['b_sub_sub_sub_cat_opt'] = $sub_sub_category_data_c['html'];
          $itg_category_array_holder[] = $sub_sub_sub_category_data_c_after_intrs;
        }


        $itg_category_list_for_primary = array();
        foreach ($itg_category_array_holder as $arr_chunk) {
          if (is_array($arr_chunk)) {
            $itg_category_list_for_primary = array_merge($itg_category_list_for_primary, $arr_chunk);
          }
        }

        $primary_category = get_parent_structure_by_tid($itg_category_list_for_primary);
        $render_data['primary'] = $primary_category;


        print json_encode($render_data);
        drupal_exit();
      }
      break;

    case 'itg_sub_category[]':
      if (isset($_POST['sub_category']) && count($_POST['sub_category']) >= 1 && !empty($_POST['sub_category'])) {
        $sub_category_data_c = get_categoryies_by_tid(json_decode($_POST['sub_category']));
        $section = json_decode($_POST['section']);
        $category = json_decode($_POST['category']);
        $sub_category = json_decode($_POST['sub_category']);
        $render_data['main'] = $sub_category_data_c['html'];
        $render_data['pcat'] = isset($_POST['pcat']) ? $_POST['pcat'] : '';
        $itg_category_array_holder = array();

        // Default initilization for section and category
        $itg_category_array_holder[] = json_decode($_POST['section']);  // Holding section  in an array
        $itg_category_array_holder[] = json_decode($_POST['category']);  // Holding category  in an array
        $itg_category_array_holder[] = json_decode($_POST['sub_category']);  // Holding sub category  in an array

        if (!empty($sub_category_data_c['tids']) && isset($_POST['b_sub_sub_cat']) && !empty($_POST['b_sub_sub_cat'])) {
          $sub_sub_category_data_c_after_intrs = itg_category_multiple_array_intersect($sub_category_data_c['tids'], json_decode($_POST['b_sub_sub_cat']));
          $render_data['b_sub_sub_cat'] = $_POST['b_sub_sub_cat'];
          $sub_sub_category_data_c = get_categoryies_by_tid($sub_sub_category_data_c_after_intrs);
          $render_data['b_sub_sub_cat_opt'] = $sub_category_data_c['html'];
          $itg_category_array_holder[] = $sub_sub_category_data_c_after_intrs;
        }

        if (!empty($sub_sub_category_data_c['tids']) && !empty($render_data['b_sub_sub_cat_opt']) && isset($_POST['b_sub_sub_sub_cat']) && !empty($_POST['b_sub_sub_sub_cat'])) {
          $sub_sub_sub_category_data_c_after_intrs = itg_category_multiple_array_intersect($sub_sub_category_data_c['tids'], json_decode($_POST['b_sub_sub_sub_cat']));
          $render_data['b_sub_sub_sub_cat'] = $_POST['b_sub_sub_sub_cat'];
          $sub_sub_sub_category_data_c = get_categoryies_by_tid($sub_sub_sub_category_data_c_after_intrs);
          $render_data['b_sub_sub_sub_cat_opt'] = $sub_sub_category_data_c['html'];
          $itg_category_array_holder[] = $sub_sub_sub_category_data_c_after_intrs;
        }


        $itg_category_list_for_primary = array();
        foreach ($itg_category_array_holder as $arr_chunk) {
          if (is_array($arr_chunk)) {
            $itg_category_list_for_primary = array_merge($itg_category_list_for_primary, $arr_chunk);
          }
        }

        $primary_category = get_parent_structure_by_tid($itg_category_list_for_primary);
        $render_data['primary'] = $primary_category;

        print json_encode($render_data);
        drupal_exit();
      }
      break;

    case 'itg_sub_sub_category[]':
      if (isset($_POST['sub_sub_category']) && count($_POST['sub_sub_category']) >= 1 && !empty($_POST['sub_sub_category'])) {
        $sub_sub_category_data_c = get_categoryies_by_tid(json_decode($_POST['sub_sub_category']));
        $section = json_decode($_POST['section']);
        $category = json_decode($_POST['category']);
        $sub_category = json_decode($_POST['sub_category']);
        $sub_sub_category = json_decode($_POST['sub_sub_category']);
        $render_data['main'] = $sub_sub_category_data_c['html'];
        $render_data['pcat'] = isset($_POST['pcat']) ? $_POST['pcat'] : '';

        $itg_category_array_holder = array();

        // Default initilization for section and category
        $itg_category_array_holder[] = json_decode($_POST['section']);  // Holding section  in an array
        $itg_category_array_holder[] = json_decode($_POST['category']);  // Holding category  in an array
        $itg_category_array_holder[] = json_decode($_POST['sub_category']);  // Holding sub category  in an array
        $itg_category_array_holder[] = json_decode($_POST['sub_sub_category']);  // Holding sub sub category  in an array

        if (!empty($sub_sub_category_data_c['tids']) && isset($_POST['b_sub_sub_sub_cat']) && !empty($_POST['b_sub_sub_sub_cat'])) {
          $sub_sub_sub_category_data_c_after_intrs = itg_category_multiple_array_intersect($sub_sub_category_data_c['tids'], json_decode($_POST['b_sub_sub_sub_cat']));
          $render_data['b_sub_sub_sub_cat'] = $_POST['b_sub_sub_sub_cat'];
          $sub_sub_sub_category_data_c = get_categoryies_by_tid($sub_sub_sub_category_data_c_after_intrs);
          $render_data['b_sub_sub_sub_cat_opt'] = $sub_sub_category_data_c['html'];
          $itg_category_array_holder[] = $sub_sub_sub_category_data_c_after_intrs;
        }

        $itg_category_list_for_primary = array();
        foreach ($itg_category_array_holder as $arr_chunk) {
          if (is_array($arr_chunk)) {
            $itg_category_list_for_primary = array_merge($itg_category_list_for_primary, $arr_chunk);
          }
        }

        $primary_category = get_parent_structure_by_tid($itg_category_list_for_primary);
        $render_data['primary'] = $primary_category;


        print json_encode($render_data);
        drupal_exit();
      }
      break;

    case 'itg_sub_sub_sub_category[]': //p($_POST);
      if (isset($_POST['sub_sub_sub_category']) && count($_POST['sub_sub_sub_category']) >= 1 && !empty($_POST['sub_sub_sub_category'])) {
        $section = json_decode($_POST['section']);
        $category = json_decode($_POST['category']);
        $sub_category = json_decode($_POST['sub_category']);
        $sub_sub_category = json_decode($_POST['sub_sub_category']);
        $sub_sub_sub_category = json_decode($_POST['sub_sub_sub_category']);
        $final_array_for_final_category = array_merge($section, $category, $sub_category, $sub_sub_category, $sub_sub_sub_category);
        $primary_category = get_parent_structure_by_tid($final_array_for_final_category);
        $render_data['primary'] = $primary_category;
        $render_data['pcat'] = isset($_POST['pcat']) ? $_POST['pcat'] : '';
        print json_encode($render_data);
        drupal_exit();
      }
      break;
  }
}


/**
 * Implements itg_category_primary_category()
 * @param array $category_id
 */
function itg_category_primary_category($category_id) {
  $main_data = $_POST['data'];
  $actual_render = array();
  $html = '';
  foreach ($main_data as $values) {
    $option_label = itg_category_complete_hierarchy($values);
    $html.='<option value="' . $values . '">' . $option_label . '</option>';
  }
  print $html;
}



/**
 * Creating create_section_category_in_mongo_mig form
 */
function create_section_category_in_mongo_mig() {

  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Please submit for bulk insert section and its category'),
  );
  return $form;
}

/**
 * Implements create_section_category_in_mongo_mig_submit().
 */
function create_section_category_in_mongo_mig_submit($form, &$form_state) {
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
      $operations[] = array('create_section_cat_op_mig', array($chunk_data));
    }
  }
  $batch = array(
    'title' => t('Migrating data finally....please wait....!'),
    'operations' => $operations,
    'finished' => 'create_section_cat_op_batch_finished_mig',
    'init_message' => t('Migration started...please wait....!'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Migration checking process has encountered an error.'),
  );
  batch_set($batch);
  batch_process('create-section-category-in-mongo-mig');
}
