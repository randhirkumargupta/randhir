<?php
/**
 * Implements itg_workflow_logs_detailis().
 * {@inheritdoc}
 */
function itg_workflow_logs_detailis() {
  // configure the table header columns
  $header = array(
    array('data' => t('ID')),
    array('data' => t('Nid')),
    array('data' => t('Title')),
    array('data' => t('Created By')),
    array('data' => t('Published by')),
    array('data' => t('Type')),
    array('data' => t('Created Date')),
    array('data' => t('Modified Date')),
    array('data' => t('Action')),
  );

  if (isset($_GET['items_per_page'])) {
    $items_per_page = $_GET['items_per_page'];
  }
  else {
    $items_per_page = 20;
  }

  $itg_query = db_select('node', 'n')->extend('PagerDefault')->limit($items_per_page);
  $itg_query->leftJoin('itg_workflow_preview_log', 'iwf', 'iwf.nid=n.nid');
  $itg_query->leftJoin('workbench_moderation_node_history', 'wbh', 'wbh.nid=n.nid');
  $itg_query->leftJoin('users', 'user', 'user.uid=n.uid');
  $itg_query->leftJoin('users', 'wbh_user', 'wbh_user.uid=wbh.uid');
  $itg_query->condition("wbh.published", 1);
  $itg_query->condition("wbh.is_current", 1);
  $itg_query->condition("wbh.state", "published");

  if (!isset($_GET['type']) || (isset($_GET['type']) && $_GET['type'] == "All")) {
    $itg_query->condition("n.type", array("story", "videogallery", "blog", "photogallery"), "IN");
  }
  else {
    $itg_query->condition("n.type", $_GET['type']);
  }

  if (isset($_GET['nid']) && !empty($_GET['nid'])) {
    $itg_query->condition("n.nid", $_GET['nid']);
  }

  if (isset($_GET['username']) && !empty($_GET['username'])) {
    $or = db_or()->condition("wbh_user.name", $_GET['username'])->condition("user.name", $_GET['username']);
    $itg_query->condition($or);
  }

  if (isset($_GET['email']) && !empty($_GET['email'])) {
    $itg_query->condition("user.mail", $_GET['email']);
  }

  if (isset($_GET['title']) && !empty($_GET['title'])) {
    $title_chunk_array = explode(" ", $_GET['title']);
    foreach ($title_chunk_array as $title_chunk) {
      $itg_query->condition('title', '%' . db_like($title_chunk) . '%', 'LIKE');
    }
  }
  $itg_query->condition('n.status', 1);
  $itg_query->fields('n', array('nid', 'title', 'uid', 'type', 'created', 'changed'));
  $itg_query->fields('user', array('name'));
  $itg_query->fields('wbh_user', array('name'));
  $itg_query->fields('wbh', array('uid'));
  $itg_query->fields('iwf', array('nid'));
  $itg_query->isNull('iwf.nid');
  $itg_query->orderBy('n.nid', "DESC");
  $itg_result = $itg_query->execute()->fetchAll();

  $rows = array();
  $count = 0;
  foreach ($itg_result as $row) {
    $rows[] = array(
      array('data' => $count + 1),
      array('data' => $row->nid),
      array('data' => $row->title),
      array('data' => l($row->name, "user/$row->uid")),
      array('data' => l($row->wbh_user_name, "user/$row->wbh_uid")),
      array('data' => $row->type),
      array('data' => date('d/m/Y', $row->created)),
      array('data' => date('d/m/Y', $row->changed)),
      array('data' => l("<span class='view-link'>View</span>", "node/$row->nid", array("html" => TRUE, "attributes" => array("target" => "_blank")))),
    );
    $count++;
  }
  $filter_form = drupal_get_form('itg_workflow_preview_log_filter_form');
  $output = render($filter_form);
  $output .= '<div class="view"><div class="attachment"><span class="count">Count (' . count($itg_result) . ') </span>';
  $output .= '</div></div>';
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table', 'preview-log-table')), 'empty' => 'No result found.'));

  // add the pager
  $output .= theme('pager');

  return $output;
}

/**
 * Autocomplete for node id.
 * @param int $nid
 */
function itg_workflow_content_nid($nid) {
  $matches = array();
  $content_type = itg_workflow_valid_content_type();
  $itg_query = db_select("node", "n");
  $itg_query->leftJoin('itg_workflow_preview_log', 'iwf', 'iwf.nid=n.nid');
  $itg_query->fields('n', array('nid'));
  $itg_query->condition('n.nid', '%' . db_like($nid) . '%', 'LIKE');
  $itg_query->condition('n.type', array($content_type), 'IN');
  $itg_query->isNull('iwf.nid');
  $itg_query->range(0, 50);
  $return = $itg_query->execute();

  foreach ($return as $row) {
    $matches[$row->nid] = check_plain($row->nid);
  }

  drupal_json_output($matches);
}

/**
 * Autocompelte helper for title.
 * @param title $title
 */
function itg_workflow_content_title($title) {
  $matches = array();
  $content_type = itg_workflow_valid_content_type();
  $itg_query = db_select("node", "n");
  $itg_query->leftJoin('itg_workflow_preview_log', 'iwf', 'iwf.nid=n.nid');
  $itg_query->fields('n', array('title'));
  $itg_query->condition('n.title', '%' . db_like($title) . '%', 'LIKE');
  $itg_query->condition('n.type', array($content_type), 'IN');
  $itg_query->isNull('iwf.nid');
  $itg_query->range(0, 50);
  $return = $itg_query->execute();
  foreach ($return as $row) {
    $matches[$row->title] = check_plain($row->title);
  }

  drupal_json_output($matches);
}

/**
 * Autocompelte helper for title.
 * @param string $username
 */
function itg_workflow_content_username($username) {
  $matches = array();
  $content_type = itg_workflow_valid_content_type();
  $itg_query = db_select("node", "n");
  $itg_query->leftJoin('itg_workflow_preview_log', 'iwf', 'iwf.nid=n.nid');
  $itg_query->leftJoin('users', 'u', 'u.uid=n.uid');
  $itg_query->fields('u', array('name'));
  $itg_query->condition('u.name', '%' . db_like($username) . '%', 'LIKE');
  $itg_query->condition('n.type', array($content_type), 'IN');
  $itg_query->isNull('iwf.nid');
  $itg_query->range(0, 50);
  $return = $itg_query->execute();
  foreach ($return as $row) {
    $matches[$row->name] = check_plain($row->name);
  }

  drupal_json_output($matches);
}

/**
 * Autocompelte helper for email.
 * @param title $email.
 */
function itg_workflow_content_email($email) {
  $matches = array();
  $content_type = itg_workflow_valid_content_type();
  $itg_query = db_select("node", "n");
  $itg_query->leftJoin('itg_workflow_preview_log', 'iwf', 'iwf.nid=n.nid');
  $itg_query->leftJoin('users', 'u', 'u.uid=n.uid');
  $itg_query->fields('u', array('mail'));
  $itg_query->condition('u.mail', '%' . db_like($email) . '%', 'LIKE');
  $itg_query->condition('n.type', array($content_type), 'IN');
  $itg_query->isNull('iwf.nid');
  $itg_query->range(0, 50);
  $return = $itg_query->execute();
  foreach ($return as $row) {
    $matches[$row->mail] = check_plain($row->mail);
  }

  drupal_json_output($matches);
}

/**
 * Implements hook_form().
 * {@inheritdoc}
 */
function itg_workflow_preview_log_filter_form($form, &$form_state) {
  $form = array();

  $form['nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Content Id'),
    '#default_value' => isset($_GET['nid']) ? $_GET['nid'] : "",
    '#autocomplete_path' => 'preview-content-logs-report/nid/autocomplete',
    '#attributes' => array('placeholder' => array("Enter Content ID"))
  );

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Content Title'),
    '#default_value' => isset($_GET['title']) ? $_GET['title'] : "",
    '#autocomplete_path' => 'preview-content-logs-report/title/autocomplete',
    '#attributes' => array('placeholder' => array("Enter Content Title"))
  );

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

  $form['type'] = array(
    '#type' => 'select',
    '#title' => t('Content type'),
    '#options' => array("All" => "All", "blog" => "Blog", "story" => "Story", "videogallery" => "Videogallery", "photogallery" => "Photogallery", "podcast" => "Podcast"),
    '#default_value' => isset($_GET['type']) ? $_GET['type'] : "",
  );

  $form['items_per_page'] = array(
    '#type' => 'select',
    '#title' => t('Items per page'),
    '#options' => array(5 => 5, 10 => 10, 20 => 20, 40 => 40, 60 => 60),
    '#default_value' => isset($_GET['items_per_page']) ? $_GET['items_per_page'] : 20,
  );

  $form['submit'] = array(
    '#value' => 'Apply',
    '#type' => 'submit',
    '#attributes' => array('class' => array(' layout-apply', ' btn-small' . ' form-submit')),
    '#prefix' => '<div class = "layout-filter-btn">',
    '#suffix' => '<a class="layout-reset btn-small btn-reset" href="' . base_path() . 'preview-content-logs-report">Reset</a></div>',
  );

  return $form;
}

/**
 * Implements hook_submit()
 * {@inheritdoc}
 */
function itg_workflow_preview_log_filter_form_submit($form, &$form_state) {
  $item_per_page = $form_state['values']['items_per_page'];
  $nid = $form_state['values']['nid'];
  $title = $form_state['values']['title'];
  $type = $form_state['values']['type'];
  $username = $form_state['values']['username'];
  $email = $form_state['values']['email'];
  $form_state['redirect'] = array(
    'preview-content-logs-report',
    array(
      'query' => array(
        'nid' => $nid,
        'title' => $title,
        'type' => $type,
        'username' => $username,
        'email' => $email,
        'items_per_page' => $item_per_page,
      ),
    ),
  );
}
