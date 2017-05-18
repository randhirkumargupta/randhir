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
    '#prefix' => '<div id="akamai-custom-cache"></div>',
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

/**
 * Drupal form submit validate.
 */
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

/**
 * akamai_cc_clear_ct_op.
 */
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
function itg_akamai_cache_akamai_other($form, &$form_state) {
  drupal_add_css('input.form-submit.button-small {
  padding: 4px 8px;
  font-weight: bold;
}

.container-inline input.form-submit.button-small + .ajax-progress.ajax-progress-throbber .throbber {
  position: absolute;
  left: 19px;
  margin-top: 7px;
}

.container-inline input.form-submit.button-small + .ajax-progress.ajax-progress-throbber .message {
  display: none;
}
', 'inline');


  $form = array();

  $form['itg_akamai_homepage'] = array(
    '#type' => 'fieldset',
    '#title' => 'Akamai Cache TTL Setting for Some Other URL/Component',
  );

  $form['#limit_validation_errors'] = array();

  $form['itg_akamai_homepage']['itg_akamai_other_hpage'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter TTL for Home Page'),
    '#default_value' => variable_get('itg_akamai_other_hpage'),
    '#description' => t('Enter TTL for Home Page for akamai cache'),
    '#required' => TRUE,
  );

  $form['markup_data'] = [
    '#markup' => t('Enter Page Name, suffix URL and TTL, you can enter 0 for no-store, no-cache.'),
  ];

  $form['field_container'] = [
    '#title' => 'Custom and Other URL\'s TTL',
    '#type' => 'fieldset',
    '#weight' => 80,
    '#tree' => TRUE,
    // Set up the wrapper so that AJAX will be able to replace the fieldset.
    '#prefix' => '<div id="js-ajax-elements-wrapper">',
    '#suffix' => '</div>',
  ];


  $itg_akamai_get_result = itg_akamai_get_itg_custom_url_ttl_rows();
  $itg_akamai_get_result_count = 3;
  if (isset($itg_akamai_get_result) && !empty($itg_akamai_get_result)) {
    $itg_akamai_get_result_count = count($itg_akamai_get_result);
  }
  else {
    $itg_akamai_get_result_count = 3;
  }

  $form_state['field_deltas'] = isset($form_state['field_deltas']) ? $form_state['field_deltas'] : range(0, $itg_akamai_get_result_count);

  $field_count = $form_state['field_deltas'];

  foreach ($field_count as $delta) {
    $form['field_container'][$delta] = [
      '#type' => 'container',
      '#attributes' => [
        'class' => ['container-inline'],
      ],
      '#tree' => TRUE,
    ];

    $form['field_container'][$delta]['page_name'] = [
      '#type' => 'textfield',
      '#title' => t('Page Name'),
      '#size' => 10,
      '#default_value' => isset($itg_akamai_get_result[$delta]->page_name) ? $itg_akamai_get_result[$delta]->page_name : '',
    ];

    $form['field_container'][$delta]['page_url'] = [
      '#type' => 'textfield',
      '#title' => itg_akamai_host_path_get(),
      '#size' => 50,
      '#attributes' => array('placeholder' => t('Enter URL after base URL')),
      '#default_value' => isset($itg_akamai_get_result[$delta]->url) ? $itg_akamai_get_result[$delta]->url : '',
    ];

    $form['field_container'][$delta]['ttl'] = [
      '#type' => 'textfield',
      '#title' => t('TTL'),
      '#size' => 15,
      '#attributes' => array('placeholder' => t('Enter TTL(in Sec.)')),
      '#default_value' => isset($itg_akamai_get_result[$delta]->ttl) ? $itg_akamai_get_result[$delta]->ttl : '',
    ];

    $form['field_container'][$delta]['remove_name'] = [
      '#type' => 'submit',
      '#value' => t('-'),
      '#submit' => ['itg_akamai_ajax_other_add_more_remove'],
      // See the examples in ajax_example.module for more details on the
      // properties of #ajax.
      '#ajax' => [
        'callback' => 'itg_akamai_ajax_other_add_more_remove_callback',
        'wrapper' => 'js-ajax-elements-wrapper',
      ],
      '#weight' => -50,
      '#attributes' => [
        'class' => ['button-small'],
      ],
      '#name' => 'remove_name_' . $delta,
    ];
  }

  $form['field_container']['add_name'] = [
    '#type' => 'submit',
    '#value' => t('Add one more'),
    '#submit' => ['itg_akamai_ajax_other_add_more_add_one'],
    // See the examples in ajax_example.module for more details on the
    // properties of #ajax.
    '#ajax' => [
      'callback' => 'itg_akamai_ajax_other_add_more_add_one_callback',
      'wrapper' => 'js-ajax-elements-wrapper',
    ],
    '#weight' => 100,
  ];


  $form['field_container']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
    '#weight' => 400,
  );

  return $form;
  
}

/**
 * itg_akamai_ajax_other_add_more_remove
 */
function itg_akamai_ajax_other_add_more_remove($form, &$form_state) {
  $delta_remove = $form_state['triggering_element']['#parents'][1];
  $k = array_search($delta_remove, $form_state['field_deltas']);
  unset($form_state['field_deltas'][$k]);

  $form_state['rebuild'] = TRUE;
  drupal_get_messages();
}

/**
 * itg_akamai_ajax_other_add_more_remove_callback
 */
function itg_akamai_ajax_other_add_more_remove_callback($form, &$form_state) {
  return $form['field_container'];
}

/**
 * itg_akamai_ajax_other_add_more_add_one
 */
function itg_akamai_ajax_other_add_more_add_one($form, &$form_state) {
  $form_state['field_deltas'][] = count($form_state['field_deltas']) > 0 ? max($form_state['field_deltas']) + 1 : 0;

  $form_state['rebuild'] = TRUE;
  drupal_get_messages();
}

/**
 * itg_akamai_ajax_other_add_more_add_one_callback
 */
function itg_akamai_ajax_other_add_more_add_one_callback($form, $form_state) {
  return $form['field_container'];
}

/**
 * itg_akamai_cache_akamai_other form submit handler
 * @param type $form
 * @param type $form_state
 */
function itg_akamai_cache_akamai_other_submit($form, &$form_state) {

  if (isset($form_state['values']) && !empty($form_state['values'])) {
    // Setting TTL for home page
    if (isset($form_state['values']['itg_akamai_other_hpage']) && !empty($form_state['values']['itg_akamai_other_hpage'])) {
      variable_set('itg_akamai_other_hpage', $form_state['values']['itg_akamai_other_hpage']);
    }

    // Setting TTL for custom or other pages
    // First deleting all record from table

    try {
      db_delete('itg_akamai_custom_url_ttl')->execute();
    }
    catch (Exception $e) {
      watchdog('Unable to delete the table due to ' . $e->getMessage());
    }

    $finalcount = itg_akamai_custom_utl_from_data_count($form_state['values']['field_container']);
    $inserted_count = 0;
    foreach ($form_state['values']['field_container'] as $key => $form_chunk_data) {
      if (is_numeric($key)) {
        if (isset($form_chunk_data['page_name']) && !empty($form_chunk_data['page_name']) && isset($form_chunk_data['page_url']) && !empty($form_chunk_data['page_url'])) {
          try {
            $query = db_insert('itg_akamai_custom_url_ttl');
            $query->fields(
                    array(
                      'page_name' => $form_chunk_data['page_name'],
                      'url' => $form_chunk_data['page_url'],
                      'ttl' => isset($form_chunk_data['ttl']) && !empty($form_chunk_data['ttl']) ? $form_chunk_data['ttl'] : 0, // Setting the defult value if user not set the TTL
                    )
                )
                ->execute();
          }
          catch (Exception $e) {
            die($e->getMessage());
          }
          $inserted_count++;
        }
      }
    }
    if ($finalcount == $inserted_count) {
      drupal_set_message(t("Setting have been saved successfully! and imported :imported out of :total", array(':imported' => $inserted_count, ':total' => $finalcount)));
    }
    else {
      drupal_set_message(t("Problem to save the settings! and imported :imported out of :total", array(':imported' => $inserted_count, ':total' => $finalcount)), 'error');
    }
  }
}

/**
 * Getting host path for site for Akamai
 * @return string
 */
function itg_akamai_host_path_get() {
  $host = variable_get('itg_akamai_mapping_host');
  $lastchar = substr($host, -1);
  if ($lastchar != '/') {
    $host .= '/';
  }
  return $host;
}

/**
 * Returns row for itg custom url along with ttl data
 */
function itg_akamai_get_itg_custom_url_ttl_rows() {
  $data = array();

  $qry = db_select('itg_akamai_custom_url_ttl', 'i')
      ->fields('i')
      ->execute();

  foreach ($qry as $chunk_data) {
    $data[] = $chunk_data;
  }
  return $data;
}

/**
 * itg_akamai_custom_utl_from_data_count for calculating length of the data
 * @param array $field_container
 * @return int
 */
function itg_akamai_custom_utl_from_data_count($field_container) {
  $inserted_count = 0;
  foreach ($field_container as $key => $form_chunk_data) {
    if (is_numeric($key)) {
      if (isset($form_chunk_data['page_name']) && !empty($form_chunk_data['page_name']) && isset($form_chunk_data['page_url']) && !empty($form_chunk_data['page_url'])) {
        $inserted_count++;
      }
    }
  }
  return $inserted_count;
}
