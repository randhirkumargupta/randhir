<?php

/**
 * Save logged user data in mongo database.
 * @param array $user_data
 */
function _itg_report_save_active_user_data($user_data) {
  if (function_exists('mongodb')) {
    $conn = mongodb();
    if ($conn) {
      $active_users = $conn->active_users;
      $qry = array(
        "uid" => $user_data['uid'],
        "name" => $user_data['name'],
        "mail" => $user_data['mail'],
        "mobile" => $user_data['mobile'],
        "created" => $user_data['created'],
        "login" => $user_data['login'],
        "role" => $user_data['role'],
        "access" => $user_data['access'],
      );
      $active_users->insert($qry);
    }
  }
}

/**
 * Implements hook_form()
 * {@inheritdoc}
 */
function itg_active_user_report_form($form, &$form_state) {
  $form['username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => isset($_GET['username']) ? $_GET['username'] : "",
    '#autocomplete_path' => 'preview-content-logs-report/username/autocomplete',
    '#attributes' => array('placeholder' => array("Enter Username"))
  );

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#default_value' => isset($_GET['email']) ? $_GET['email'] : "",
    '#autocomplete_path' => 'preview-content-logs-report/email/autocomplete',
    '#attributes' => array('placeholder' => array("Enter Email"))
  );

  $form['mobile'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile'),
    '#default_value' => isset($_GET['mobile']) ? $_GET['mobile'] : "",
    '#attributes' => array('placeholder' => array("Enter Mobile"))
  );

  $form['date_from'] = array(
    '#type' => 'textfield',
    '#title' => t('Date from'),
    '#attributes' => array("placeholder" => array("Enter Date From")),
    '#default_value' => isset($_GET['date_from']) ? date('d-m-Y', $_GET['date_from']) : "",
  );

  $form['date_to'] = array(
    '#type' => 'textfield',
    '#title' => t('Date to'),
    '#attributes' => array("placeholder" => array("Enter Date To")),
    '#default_value' => isset($_GET['date_to']) ? date('d-m-Y', $_GET['date_to']) : "",
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
    '#suffix' => '<a class="user-log-reset btn-reset" href="' . base_path() . 'itg-active-user-report">' . t('Reset') . '</a></div>',
  );

  $form['markup'] = array(
    '#type' => 'markup',
    '#markup' => itg_active_user_report(),
  );

  $form['#attached']['js'] = array(
    drupal_get_path('module', 'itg_reports') . '/js/itg_reports.js',
  );

  return $form;
}

/**
 * Implements hook_submit()
 * {@inheritdoc}
 */
function itg_active_user_report_form_submit($form, &$form_state) {
  $username = $form_state['values']['username'];
  $email = $form_state['values']['email'];
  $mobile = $form_state['values']['mobile'];
  $date_from = $form_state['values']['date_from'];
  $date_to = $form_state['values']['date_to'];
  $item_per_page = $form_state['values']['items_per_page'];
  $form_state['redirect'] = array(
    'itg-active-user-report',
    array(
      'query' => array(
        'username' => $username,
        'email' => $email,
        'mobile' => $mobile,
        'date_from' => strtotime($date_from),
        'date_to' => strtotime($date_to),
        'item_per_page' => $item_per_page,
      ),
    ),
  );
}

/**
 * Get active users from mong between two timestamp
 */
function itg_active_user_report() {
  //Add pagination class.
  module_load_include('php', 'itg_reports', 'includes/pagination');
  if (isset($_GET['email']) && !empty($_GET['email'])) {
    $email = trim($_GET['email']);
  }
  else {
    $email = '';
  }
  if (isset($_GET['username']) && !empty($_GET['username'])) {
    $username = trim($_GET['username']);
  }
  else {
    $username = '';
  }
  if (isset($_GET['mobile']) && !empty($_GET['mobile'])) {
    $mobile = trim($_GET['mobile']);
  }
  else {
    $mobile = '';
  }
  if (isset($_GET['date_to']) && !empty($_GET['date_to'])) {
    $date_to = trim($_GET['date_to']);
  }
  else {
    $date_to = '';
  }
  if (isset($_GET['date_from']) && !empty($_GET['date_from'])) {
    $date_from = trim($_GET['date_from']);
  }
  else {
    $date_from = '';
  }
  $table_data = _get_data_for_output_user_report($date_from, $date_to, $email, $username, $mobile);
  $products = $table_data;
  // Create the pagination object
  $pagination = new pagination;
  $count = 0;
  $header = array(
    array('data' => t('ID')),
    array('data' => t('Name')),
    array('data' => t('User Id')),
    array('data' => t('Email')),
    array('data' => t('Mobile')),
    array('data' => t('Created')),
    array('data' => t('Last Login')),
    array('data' => t('Action')),
  );
  // If we have an array with items
  if (count($products)) {
    // Parse through the pagination class
    $item_per_page = isset($_GET['item_per_page']) ? $_GET['item_per_page'] : 20;
    $user_details_pages = $pagination->generate($products, $item_per_page);
    // Load users report data.
    // If we have items 
    if (count($user_details_pages) != 0) {
      // Get pagination.
      $pageNumbers = '<div class="numbers">' . $pagination->links() . '</div>';
      foreach ($user_details_pages as $row) {
        // Prepare rows as per pagination.
        $rows[] = array(
          array('data' => $count + 1),
          array('data' => $row['name']),
          array('data' => $row['uid']),
          array('data' => $row['mail']),
          array('data' => $row['mobile']),
          array('data' => date('d/m/Y', $row['created'])),
          array('data' => date('d/m/Y', $row['login'])),
          array('data' => l("<span class='view-link'>View</span>", "user/" . $row['uid'], array("html" => TRUE, "attributes" => array("target" => "_blank")))),
        );
        $count++;
      }
      $output .= '<div class="view"><div class="attachment"><span class="count">Count (' . count($table_data) . ') </span>';
      $output .= '</div></div>';
      $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table', 'preview-log-table')), 'empty' => 'No result found.'));
      // add the pager
      $output .= '<ul class="pager">' . $pageNumbers . '</ul>';
      return $output;
    }
  }
}

/**
 * Function with gives user data array with fields.
 * @param string $start_date
 * @param string $end_date
 * @return array
 */
function _get_data_for_output_user_report($start_date, $end_date, $email = '', $name = '', $mobile = '') {
  $user_data = array();
  $user_array = _get_most_active_users_id_from_mongo($start_date, $end_date, $email, $name, $mobile);
  foreach ($user_array as $uid) {
    $user_load_details = get_required_data_for_user($uid, $email, $name, $mobile);
    if (!empty($user_load_details)) {
      $user_data[] = $user_load_details;
    }
  }
  return $user_data;
}

/**
 * Function which uses mongo database to get active users list.
 * @return array
 */
function _get_most_active_users_id_from_mongo($start_date, $end_date, $email, $name, $mobile) {
  $data = array();
  $final_data = array();
  if (function_exists('mongodb')) {
    $conn = mongodb();
    if ($conn) {
      $collection = $conn->active_users;
      if (empty($start_date)) {
        $start_date = 0;
      }
      else {
        $start_date = strtotime('-1 day' , $start_date);
      }
      if (empty($end_date)) {
        $end_date = time() + 100;
      }
      else {
        $end_date = strtotime('+1 day' , $end_date);
      }
      $condition = array(
        'condition' => array(
          'login' => array(
            '$gte' => (int) $start_date,
            '$lte' => (int) $end_date,
          ),
          'role' => 'Front User',
        )
      );
      $keys = array("uid" => true);
      $initial = array("items" => array());
      $reduce = "function(doc, prev) { prev.items++ }";
      $cursor = $collection->group($keys, $initial, $reduce, $condition);
      $data = json_encode($cursor['retval']);
      $mongo_db_array = json_decode($data);
      // Handle initial data
      foreach ($mongo_db_array as $item_data) {
        $final_data[$item_data->items] = $item_data->uid;
      }
    }
  }
  krsort($final_data);
  return array_values($final_data);
}

/**
 * Function to get user data as per the report.
 * @param int $uid
 * @return array
 */
function get_required_data_for_user($uid, $email, $name, $mobile) {
  if ($uid) {
    $user_return = TRUE;
    $user_load = user_load($uid);

    if (!empty($user_load)) {
      // Handle form filter from drupal user not from mongo.
      // START
      if ($email == $user_load->mail || $email == '') {
        $email_return = TRUE;
      }
      else {
        $email_return = FALSE;
      }

      if ($mobile == $user_load->field_mobile_number['und'][0]['value'] || $mobile == '') {
        $mobile_return = TRUE;
      }
      else {
        $mobile_return = FALSE;
      }

      if ($name == $user_load->name || $name == '') {
        $name_return = TRUE;
      }
      else {
        $name_return = FALSE;
      }

      // END      
      if ($email_return && $mobile_return && $name_return) {
        $user_required_data = array();
        $user_required_data['uid'] = $user_load->uid;
        $user_required_data['name'] = $user_load->name;
        $user_required_data['mail'] = $user_load->mail;
        $user_required_data['created'] = $user_load->created;
        $user_required_data['access'] = $user_load->access;
        $user_required_data['login'] = $user_load->login;
        $user_required_data['mobile'] = $user_load->field_mobile_number['und'][0]['value'];
        return $user_required_data;
      }
      return array();
    }
    return array();
  }
  return array();
}
