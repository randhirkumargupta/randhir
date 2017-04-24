<?php

/**
 * Implements _personalization_all_content().
 */
function _personalization_all_content() {
  global $user, $base_url;
  $arg = arg();
  return drupal_get_form('itg_personalization_all_content_form');
}

/**
 * Implements hook_form().
 */
function itg_personalization_all_content_form($form, &$form_state) {
  global $base_url;
  $form = array();
  $form['heading'] = array(
    '#prefix' => '<h2>' . t('Here you can view all the content submitted by you'),
    '#markup' => '</h2>',
  );
  $form['status'] = array(
    '#type' => 'select',
    '#title' => 'Status',
    '#required' => TRUE,
    '#options' => array('_none' => 'Select', 'review' => 'Under Review', 'approve' => 'Approved', 'reject' => 'Rejected'),
    '#default_value' => ($_GET['status']) ? $_GET['status'] : '_none',
  );
  $form['items_per_page'] = array(
    '#type' => 'select',
    '#title' => 'Items per page',
    '#options' => array(5 => 5, 10 => 10, 20 => 20, 40 => 40, 60 => 60, 100 => 100, 500 => 500, 1000 => 1000),
    '#default_value' => ($_GET['items_per_page']) ? $_GET['items_per_page'] : 20,
  );
  $form['submit'] = array(
    '#value' => 'Apply',
    '#type' => 'submit',
    '#attributes' => array('class' => array('user-all-content')),
    '#prefix' => '<div class = "user-log-filter-btn">',
    '#suffix' => '<a class="user-log-reset form-submit" href="' . base_path() . 'personalization/my-content">'.t('Reset').'</a></div>',
  );
  
  return $form;
}

/**
 * Implements hook_form_validate().
 */
function itg_personalization_all_content_form_validate($form, &$form_state) {
  if(empty($form_state['values']['status']) || $form_state['values']['status'] == '_none') {
    form_set_error('status', t('Please select status!'));
  }
}

/**
 * Implements hook_submit()
 * {@inheritdoc}
 */
function itg_personalization_all_content_form_submit($form, &$form_state) {
  $form_state['redirect'] = array(
    'personalization-all-content',
    array(
      'query' => array(
        'status' => $form_state['values']['status'],
        'items_per_page' => $form_state['values']['items_per_page'],
      ),
    ),
  );
}

/**
 * Implements itg_personalization_all_content_display().
 */
function itg_personalization_all_content_display() {
  global $base_url, $user;
  $arg = arg();
  # configure the table header columns
  $header = array(
    array('data' => t('S. No')),
    array('data' => t('Title')),
    array('data' => t('Type')),
    array('data' => t('Description')),
    array('data' => t('Status')),
    array('data' => t('Submit Date')),
    array('data' => t('')),
  );
  if (function_exists('mongodb'))
  {
    $con = mongodb();
    if ($con)
    {
      $people = $con->ugc_details;
      $query = array();
      $limit = 0;
      
      if (!empty($_GET['items_per_page']))
      {
        $limit = $_GET['items_per_page'];
      }

      if (!empty($_GET['status']) && $_GET['status'] != '_none')
      {
        if($_GET['status'] == 'review') {
        $query['publish_status'] = array('$ne' => 1);
        $query['status'] = 1;
        $query['uid'] = $user->uid;
        }
        if($_GET['status'] == 'approve') {
          $query['publish_status'] = 1;
          $query['uid'] = $user->uid;
        }
        if($_GET['status'] == 'reject') {
          $query['status'] = 0;
          $query['uid'] = $user->uid;
        }
      }
      if (is_array($query) && empty($query))
      {

        $userData = $people->find(array("publish_status" => array('$ne' => 1), "status" => 1, "uid" => $user->uid))->limit($limit)->sort(array('_id' => -1));
      }
      else
      {
        $userData = $people->find($query)->limit($limit)->sort(array('_id' => -1));
      }

      $rows = array();
      $sl_no = 1;
      
      foreach ($userData as $row) {
        if(!empty($_GET['status']) && $_GET['status'] == 'review') {
          $link = '<span class="delete-link"><a class="user-con-delete" href="personalization-del-content/'.$row['_id'].'/ugc_details" title="Delete">'.t('Delete').'</a>';
        } else {
          $link = '';
        }
        
        $user_message_raw_value = strip_tags($row['description']);
        $user_message_lenth = strlen($user_message_raw_value);
        if ($user_message_lenth > 100)
        {
          $user_message_raw_value = substr($user_message_raw_value, 0, 99) . "...";
          $user_message_raw_value = itg_ugc_bad_words($user_message_raw_value);
        }
        else
        {
          $user_message_raw_value = itg_ugc_bad_words($user_message_raw_value);
          $user_message_raw_value = $user_message_raw_value;
        }
        //get the value in table
        $rows[] = array(
          array('data' => $sl_no),
          array('data' => $row['title']),
          array('data' => $row['content_type']),
          array('data' => $user_message_raw_value),
          array('data' => ucwords($_GET['status'])),
          array('data' => $row['publish_date']),
          array('data' => $link),
        );
        $sl_no = $sl_no + 1;
      } // end foreach
    }
  }
  //get the header in table
  $output = render(drupal_get_form('itg_personalization_all_content_form'));
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table cols-5')), 'empty' => t('No results found')));

  # add the pager
  $output .= theme('pager');
  return $output;
}