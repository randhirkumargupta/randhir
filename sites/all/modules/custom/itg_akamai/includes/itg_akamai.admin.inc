<?php

/**
 * General Settings for Akamai
 */
function itg_akamai_settings() {
  $form = array();

  $form['itg_akamai_host_map'] = array(
    '#type' => 'fieldset',
    '#title' => 'Akamai Cache Host Map URL',
  );
  $form['itg_akamai_host_map']['itg_akamai_mapping_host'] = array(
    '#type' => 'textfield',
    '#title' => t('ITG Akamai Map Host URL'),
    '#default_value' => variable_get('itg_akamai_mapping_host', ''),
    '#description' => t('Enter the host / uri that that have been whitelist for akamai cache'),
    '#required' => TRUE,
  );

  $form['itg_disable_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => 'Disable Akamai Cache Clearing',
    '#description' => 'Set this field to temporarity disable cache clearing during imports, migrations, or other batch processes.',
  );

  $form['itg_disable_fieldset']['itg_akamai_disabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable cache clearing'),
    '#default_value' => variable_get('itg_akamai_disabled', FALSE),
  );



  $form['itg_config_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => 'Akamai Credentials',
  );


  $form['itg_config_fieldset']['itg_akamai_basepath'] = array(
    '#type' => 'textfield',
    '#title' => t('Base URI'),
    '#default_value' => variable_get('itg_akamai_basepath', ''),
    '#description' => t('The URL of the base path (fully qualified domain name) of the site.  This will be used as a prefix for all cache clears (Akamai indexs on the full URI). e.g. "http://www.example.com"'),
    '#required' => TRUE,
  );

  $form['itg_config_fieldset']['itg_akamai_api_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Api End Point'),
    '#default_value' => variable_get('itg_akamai_api_endpoint', ''),
    '#description' => t('Akamai Api End Point'),
    '#required' => TRUE,
  );


  $form['itg_config_fieldset']['itg_akamai_client_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Akamai Client Token'),
    '#default_value' => variable_get('itg_akamai_client_token', ''),
    '#description' => t('Akamai Client Token'),
    '#required' => TRUE,
  );

  $form['itg_config_fieldset']['itg_akamai_client_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Akamai Client Secret'),
    '#default_value' => variable_get('itg_akamai_client_secret', ''),
    '#description' => t('Akamai Client Secret'),
    '#required' => TRUE,
  );

  $form['itg_config_fieldset']['itg_akamai_access_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Akamai Access Token'),
    '#default_value' => variable_get('itg_akamai_access_token', ''),
    '#description' => t('Akamai Access Token'),
    '#required' => TRUE,
  );


//  $form['itg_cctype_fieldset'] = array(
//    '#type' => 'fieldset',
//    '#title' => 'Timeout Length for all content type',
//  );
//  $form['itg_cctype_fieldset_holder'] = array(
//    '#type' => 'fieldset',
//    '#title' => 'Timeout Length for all content type',
//  );
//  $allnodes = node_type_get_types();
//  foreach ($allnodes as $key => $values) {
//
//    $form['itg_cctype_fieldset']['akamai_timeout_' . $key] = array(
//      '#type' => 'textfield',
//      '#title' => t("$values->name (in seconds)"),
//      '#default_value' => variable_get('akamai_timeout_' . $key, ''),
//      '#description' => t("Timeout Length for <strong>$values->name</strong>, the timeout used by when sending the cache clear request to Akamai's servers"),
//    );
//
//    $form['itg_cctype_fieldset']['akamai_config_cctype_flag_' . $key] = array(
//      '#type' => 'select',
//      '#options' => array('_none' => '-Select-', 'yes' => 'Yes', 'no' => 'No'),
//      '#title' => t("You want to use this configuration for $values->name"),
//      '#default_value' => variable_get('akamai_config_cctype_flag_' . $key, ''),
//      '#description' => t("Please select content type flag whether you want to use with akamai cache or not!"),
//    );
//  }

  return system_settings_form($form);
}

/**
 * General cache clearing page.
 */
function itg_akamai_cache_control() {
  $form = array();

  $form['paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Paths/URLs'),
    '#description' => t('Enter one URL per line. URL entries should be relative to the basepath. (e.g. node/1, content/pretty-title, /sites/default/files/some/image.png'),
  );


  $form['refresh'] = array(
    '#type' => 'radios',
    '#title' => t('Clearing Action Type'),
    '#default_value' => variable_get('itg_akamai_action', ''),
    '#options' => array(
      'remove' => t('Remove'),
      'invalidate' => t('Invalidate'),
    ),
    '#description' => t('<b>Remove:</b> Purge the content from Akamai edge server caches. The next time the edge server receives a request for the content, it will retrieve the current version from the origin server. If it cannot retrieve a current version, it will follow instructions in your edge server configuration.<br/><br/><b>Invalidate:</b> Mark the cached content as invalid. The next time the Akamai edge server receives a request for the content, it will send an HTTP conditional get (If-Modified-Since) request to the origin. If the content has changed, the origin server will return a full fresh copy; otherwise, the origin normally will respond that the content has not changed, and Akamai can serve the already-cached content.<br/><br/><b>Note that <em>Remove</em> can increase the load on the origin more than <em>Invalidate</em>.</b> With <em>Invalidate</em>, objects are not removed from cache and full objects are not retrieved from the origin unless they are newer than the cached versions.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Start Refreshing Content'),
  );

  return $form;
}

/**
 * Submit handler for itg_akamai_cache_control().
 *
 * Process the settings and submit to Akamai
 */
function itg_akamai_cache_control_submit($form, &$form_state) {
  $paths = explode("\n", filter_xss($form_state['values']['paths']));
  $action = $form_state['values']['refresh'];
  $overrides = array(
    'action' => $form_state['values']['refresh'],
    'domain' => $form_state['values']['domain_override']
  );

  if ($result = itg_akamai_clear_url($paths, $overrides)) {
    $message = t("Akamai Cache Request has been made successfully.") . theme("item_list", $paths);
//    $status = 'status';
//
//    if (is_object($result) && !empty($result->data)) {
//      if ($akamai_response_data = json_decode($result->data)) {
//        if (isset($akamai_response_data->httpStatus) && $akamai_response_data->httpStatus > 300) {
//          $message = t("There was a problem with your cache clearing request.  The error message returned was '@msg'", array('@msg' => $akamai_response_data->details));
//          $status = 'error';
//        }
//        else {
//          $message = t("Akamai Cache Request has been made successfully.  Akamai reports an estimated time to completion of @time", array('@time' => format_interval($akamai_response_data->estimatedSeconds))) . theme("item_list", $paths);
//        }
//      }
//      else {
//        $message = t('There was a problem with your cache clearing request. Please check the watchdog logs for details.');
//        $status = 'error';
//
//        watchdog('akamai', 'Unable to parse Akamai API response data: @json_data', array('@json_data' => '<pre>' . print_r($result->data, TRUE) . '</pre>'), WATCHDOG_ERROR);
//      }
//    }
  }
  else {
    $message = t('There was a problem with your cache clearing request. Please check the watchdog logs for details.');
    $status = 'error';
  }

  drupal_set_message($message, $status);
}

/**
 * Implements hook_form().
 */
function itg_akamai_cache_akamai_log($form, &$form_state) {
  $form['fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Search Akamai Log'),
  );

  $form['fieldset']['purge_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Purge Id'),
    '#description' => t('Please enter Purge id'),
    '#default_value' => isset($_GET['purge_id']) ? $_GET['purge_id'] : '',
  );

  $form['fieldset']['url'] = array(
    '#type' => 'textarea',
    '#title' => t('Url'),
    '#description' => t('Enter Url'),
    '#default_value' => isset($_GET['url']) ? $_GET['url'] : '',
  );

  $form['fieldset']['user'] = array(
    '#type' => 'textfield',
    '#title' => t('User Name'),
    '#description' => t('Enter User Name'),
    '#default_value' => isset($_GET['user']) ? $_GET['user'] : '',
    '#autocomplete_path' => 'user/autocomplete',
  );

  $form['fieldset']['display_button'] = array(
    '#prefix' => '<div class="submit">',
    '#suffix' => l(t('Reset'), 'admin/config/system/itg_akamai/akamai_log', array('attributes' => array('class' => array('reset')))) . '</div">',
    '#type' => 'submit',
    '#value' => t('Search'),
    '#submit' => array('itg_akamai_cache_akamai_log_submit'),
  );

  $itg_akamai_all_logs_rows = itg_akamai_all_logs_rows();
  $form['markup'] = array(
    '#markup' => drupal_render($itg_akamai_all_logs_rows),
  );

  return $form;
}

/**
 * Implements node_alias_history_form_submit().
 */
function itg_akamai_cache_akamai_log_submit($form, &$form_state) {

  $purge_id = isset($form_state['values']['purge_id']) ? trim($form_state['values']['purge_id']) : '';
  $user = isset($form_state['values']['user']) ? trim($form_state['values']['user']) : '';
  $url = isset($form_state['values']['url']) ? trim($form_state['values']['url']) : '';

  drupal_goto('admin/config/system/itg_akamai/akamai_log', array(
    'query' => array(
      'purge_id' => $purge_id,
      'user' => $user,
      'url' => $url,
    ),
      )
  );
}

/**
 * Function returns list of node alias.
 */
function itg_akamai_all_logs_rows() {

  $rows = array();
  $parameters = drupal_get_query_parameters();
  $purge_id = isset($parameters['purge_id']) ? $parameters['purge_id'] : '';
  $user = isset($parameters['user']) ? $parameters['user'] : '';
  $url = isset($parameters['url']) ? $parameters['url'] : '';

  $header = array(
    t('Sn no.'),
    t('Purge id'),
    t('Url'),
    t('Akamai Request'),
    t('Akamai Response'),
    t('User'),
    t('Status'),
    //t('Timestamp'),
    array('data' => t('Timestamp'), 'field' => 'timestamp', 'sort' => 'ASC'),
  );

  $query = db_select('itg_akamai_log', 'a');
  $query->leftjoin('users', 'u', 'u.uid=a.uid');
  $query->fields('a');
  $query->fields('u', array('name'));

  if (isset($purge_id) && !empty($purge_id)) {
    $query->condition('a.purge_id', $purge_id);
  }

  if (isset($user) && !empty($user)) {
    $query->condition('u.name', $user);
  }

  if (isset($url) && !empty($url)) {
    $query->condition('a.url', $url);
  }

  $query = $query->extend('PagerDefault')->limit(50);
  if (isset($parameters['sort']) && !empty($parameters['sort'])) {
    $query->orderBy('a.timestamp', $parameters['sort']);
  }
  else {
    $query->orderBy('a.timestamp', 'DESC');
  }

  $result = $query->execute();
  $sn = 0;
  while ($record = $result->fetchObject()) {

    $rows[] = array(
      ++$sn,
      $record->purge_id,
      $record->url,
      $record->akamai_request,
      $record->akamai_response,
      $record->name,
      $record->status == 201 ? "Success" : 'Fail',
      date('Y-m-d h:i', $record->timestamp),
    );
  }

  $render_array['akamai_cache_logs'] = array(
    array(
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows,
      '#empty' => t('No Record found!'),
    ),
    array(
      '#theme' => 'pager',
    ),
  );

  return $render_array;
}

/**
 * ITG Akamai purging 
 */
function itg_akamai_cache_akamai_ccpurge() {
  ctools_include('modal');
  ctools_modal_add_js();
  $form = array();

  $form['itg_akamai_cc_holder'] = array(
    '#type' => 'fieldset',
    '#title' => 'Akamai Cache on Content type',
    '#prefix' => '<div id="llllllllllllllll"></div>',
  );

  $header = array('Sn.', 'Content Type', 'Settings', 'Actions');


  $allnodes = node_type_get_types();
  $sn = 1;

  foreach ($allnodes as $key => $value) {
    $rows[] = array(
      $sn++,
      $value->name,
      l('Settings', 'admin/config/system/itg_akamai/akamai_ccs/nojs/' . $value->type, array('attributes' => array('class' => 'ctools-use-modal button'))),
      l("Purge $value->name", 'admin/config/system/itg_akamai/akamai_ccc/' . $value->type, array('attributes' => array('class' => 'button'))),
    );
  }

  $output = theme('table', array('header' => $header, 'rows' => $rows));

  $form['itg_akamai_cc_holder']['options'] = array(
    '#markup' => $output,
  );
  return $form;
}

/**
 * Ajax menu callback.
 */
function itg_akamai_cache_akamai_ccpurge_settings($ajax, $type) {

  if ($ajax) {

    ctools_include('ajax');
    ctools_include('modal');

    $form_state = array(
      'ajax' => TRUE,
      'title' => t('Akamai Cache Content Type Settings Form'),
    );

    // Use ctools to generate ajax instructions for the browser to create
    // a form in a modal popup.
    $output = ctools_modal_form_wrapper('akamai_cc_frm_form', $form_state);

    // If the form has been submitted, there may be additional instructions
    // such as dismissing the modal popup.
    if (!empty($form_state['ajax_commands'])) {
      $output = $form_state['ajax_commands'];
    }

    // Return the ajax instructions to the browser via ajax_render().
    print ajax_render($output);
    drupal_exit();
  }
  else {
    return drupal_get_form('akamai_cc_frm_form');
  }
}

/**
 * Drupal form to be put in a modal.
 */
function akamai_cc_frm_form($form, $form_state) {
  $form = array();
  $type = arg(6);

  $form['itg_akamai_setting'] = array(
    '#type' => 'fieldset',
    '#title' => t('Akamai Cache Setting'),
    '#weight' => 12,
    '#collapsible' => TRUE,
    '#collapsed' => false,
    '#group' => 'additional_settings',
    '#attached' => array(
    ),
  );
  $key = $type;
  $name = $type;

  $form['itg_akamai_setting']['akamai_timeout_' . $key] = array(
    '#type' => 'textfield',
    '#title' => t("$name (in seconds)"),
    '#default_value' => variable_get('akamai_timeout_' . $key, ''),
    '#description' => t("Timeout Length for <strong>$name</strong>, the timeout used by when sending the cache clear request to Akamai's servers"),
  );

  $form['itg_akamai_setting']['akamai_max_nodelimit_' . $key] = array(
    '#type' => 'textfield',
    '#title' => t("$name (Maximum number of node limit)"),
    '#default_value' => variable_get('akamai_max_nodelimit_' . $key, ''),
    '#description' => t("Maximum number of node limit for <strong>$name</strong>,  when sending the cache clear request to Akamai's servers"),
  );

  $form['itg_akamai_setting']['akamai_config_cctype_flag_' . $key] = array(
    '#type' => 'select',
    '#options' => array('_none' => '-Select-', 'yes' => 'Yes', 'no' => 'No'),
    '#title' => t("You want to use this configuration for $name"),
    '#default_value' => variable_get('akamai_config_cctype_flag_' . $key, ''),
    '#description' => t("Please select content type flag whether you want to use with akamai cache or not!"),
  );


  $form['itg_akamai_setting']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * Drupal form submit handler.
 */
function akamai_cc_frm_form_submit(&$form, &$form_state) {
  // Generate the new link using the submitted text value.
  $link = t('Settings have been saved successfully!');
  $type = arg(6);
  $akamai_timeout = $form_state['values']['akamai_timeout_' . $type];
  $akamai_config_cctype_flag = $form_state['values']['akamai_config_cctype_flag_' . $type];
  $akamai_max_nodelimit = $form_state['values']['akamai_max_nodelimit_' . $type];

  variable_set('akamai_timeout_' . $type, $akamai_timeout);
  variable_set('akamai_config_cctype_flag_' . $type, $akamai_config_cctype_flag);
  variable_set('akamai_max_nodelimit_' . $type, $akamai_max_nodelimit);

  // Tell the browser to close the modal.
  $form_state['ajax_commands'][] = ctools_modal_command_dismiss();

  // Tell the browser to replace the old link with the new one.
  $form_state['ajax_commands'][] = ajax_command_html('.messages.status', $link);
}

/**
 * Ajax menu callback.
 */
function itg_akamai_cache_akamai_ccpurge_clear() {
  return drupal_get_form('akamai_cc_clear_frm_form');
}

/**
 * Drupal form to be put in a modal.
 */
function akamai_cc_clear_frm_form($form, $form_state) {
  $form = array();
  $type = arg(5);

  $form['itg_akamai_setting'] = array(
    '#type' => 'fieldset',
    '#title' => t('Akamai Cache Purge content type'),
    '#weight' => 12,
    '#collapsible' => TRUE,
    '#collapsed' => false,
    '#group' => 'additional_settings',
    '#attached' => array(
    ),
  );

  $form['itg_akamai_setting']['limit'] = array(
    '#type' => 'hidden',
    '#title' => t("Enter the no of content"),
    '#default_value' => variable_get('akamai_max_nodelimit_' . $type),
//    '#description' => t("Enter the limit sending the cache clear request to Akamai's servers"),
  );

  $form['itg_akamai_setting']['contenttype'] = array(
    '#type' => 'hidden',
    '#default_value' => $type,
  );

  $form['itg_akamai_setting']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

function akamai_cc_clear_frm_form_validate(&$form, &$form_state) {
  $akamai_config_cctype_type = $form_state['values']['contenttype'];
  $config_flag = variable_get('akamai_config_cctype_flag_' . $akamai_config_cctype_type);
  $setting_link = l(t('Click here'), 'admin/config/system/itg_akamai/akamai_ccpurge');
  if ($config_flag != 'yes') {
    form_set_error('contenttype', t('You can not purge the content for this content type becuase for this content type you have choosen flag value as "Yes", please ' . $setting_link . ' to change the settings.'));
  }
}

/**
 * Drupal form submit handler.
 */
function akamai_cc_clear_frm_form_submit(&$form, &$form_state) {
  // Generate the new link using the submitted text value.
  $link = t('Purge process have been performed successfully');
  $akamai_config_cctype_flag = $form_state['values']['limit'];
  $akamai_config_cctype_type = $form_state['values']['contenttype'];

  $qry = db_select('node', 'n');
  $qry->condition('n.type', $akamai_config_cctype_type);
  $qry->condition('n.status', 1);
  $qry->fields('n', array('nid'));
  $qry->orderBy('n.nid', 'DESC');
  $qry->range(0, $akamai_config_cctype_flag);
  $res = $qry->execute();


  $a = array();
  foreach ($res as $chunk_data) {
    $a[] = $chunk_data;
    $operations[] = array('akamai_cc_clear_ct_op', array($chunk_data));
  }


  $batch = array(
    'title' => t('Content type nodes are purging process have been started...please wait....!'),
    'operations' => $operations,
    'finished' => 'akamai_cc_clear_ct_op_batch_finished',
    'init_message' => t('Content type nodes are started purging...please wait....!'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('NContent type nodes are started process has encountered an error.'),
    'file' => drupal_get_path('module', 'itg_akamai') . '/includes/itg_akamai.admin.inc',
  );

  batch_set($batch);
  batch_process('admin/config/system/itg_akamai/akamai_ccpurge');
}

function akamai_cc_clear_ct_op($nodedata, &$context) {
  $message = '';
  if (isset($nodedata->nid) && !empty($nodedata->nid)) {
    itg_akamai_clear_url('node/' . $nodedata->nid);
  }
}

/**
 * Batch 'finished' callback
 */
function akamai_cc_clear_ct_op_batch_finished($success, $results, $operations) {
  if ($success) {
    $message = t('Node purge process have been successfully done:');
    drupal_set_message($message);
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
    drupal_set_message($message, 'error');
  }
}

/**
 * General Settings for section or category
 */
function itg_akamai_cache_akamai_section() {
  $form = array();

  $form['itg_akamai_section'] = array(
    '#type' => 'fieldset',
    '#title' => 'Akamai Cache Setting For Section/Category',
  );

  $form['itg_akamai_section']['akamai_timeout_taxonomy'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter TTL for Section/Category'),
    '#default_value' => variable_get('akamai_timeout_taxonomy', ''),
    '#description' => t('Enter TTL for Section/Category for akamai cache'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

/**
 * General Settings for Akamai miscellaneous
 */
function itg_akamai_cache_akamai_other() {
  $form = array();

  $form['itg_akamai_homepage'] = array(
    '#type' => 'fieldset',
    '#title' => 'Akamai Cache TTL Setting for Some Other URL/Component',
  );

  $form['itg_akamai_homepage']['itg_akamai_other_hpage'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter TTL for Home Page'),
    '#default_value' => variable_get('itg_akamai_other_hpage', ''),
    '#description' => t('Enter TTL for Home Page for akamai cache'),
    '#required' => TRUE,
  );

  $form['itg_akamai_homepage']['itg_akamai_other_hpage'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter TTL for Home Page'),
    '#default_value' => variable_get('itg_akamai_other_hpage', ''),
    '#description' => t('Enter TTL for Home Page for akamai cache'),
    '#required' => TRUE,
  );
  

  return system_settings_form($form);
}
