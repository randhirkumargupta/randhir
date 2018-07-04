<?php

/**
 * @file
 * All custom variables of widgets in this file.
 *
 */

/**
 * This function is used to create settings.
 *
 * {@inheritdoc}
 */
function itg_custom_variables() {
	$form = array();
  $form['enable_top_story_ad'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Top story ad'),
    '#required' => FALSE,
    '#default_value' => get_itg_variable('enable_top_story_ad'),
  );
  $form['top_story_ad_position'] = array(
    '#type' => 'textfield',
    '#title' => t('Top story ad position'),
    '#default_value' => get_itg_variable('top_story_ad_position'),
    '#size' => 20,
    '#required' => FALSE,
    '#maxlength' => 20,
  );
  $form['top_story_ad_html'] = array(
    '#type' => 'textarea',
    '#title' => t('Top story ad HTML'),
    '#default_value' => get_itg_variable('top_story_ad_html'),
    '#required' => FALSE,
  );
  $form['home_page_election_tid'] = array(
    '#type' => 'textfield',
    '#title' => t('Home Page election Tid'),
    '#default_value' => get_itg_variable('home_page_election_tid'),
    '#size' => 20,
    '#required' => FALSE,
    '#maxlength' => 20,
  );
  $form['delete_pti_xmlfile_days'] = array(
    '#type' => 'textfield',
    '#title' => t('Delete PTI Xml FileName From DB (In Days)'),
    '#default_value' => get_itg_variable('delete_pti_xmlfile_days'),
    '#size' => 20,
    '#maxlength' => 20,
  );
  $form['dns_preconnect_prefetch'] = array(
    '#type' => 'textarea',
    '#title' => t('DNS Preconnect Prefetch'),
    '#default_value' => get_itg_variable('dns_preconnect_prefetch'),
  );
  $form['ros_dns_preconnect_prefetch'] = array(
    '#type' => 'textarea',
    '#title' => t('ROS DNS Preconnect Prefetch'),
    '#default_value' => get_itg_variable('ros_dns_preconnect_prefetch'),
  );
  $form['enable_custom_lazyload'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Custom Lazy Load'),
    '#required' => FALSE,
    '#default_value' => get_itg_variable('enable_custom_lazyload'),
  );
  $form['indiatoday_tvschedule_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Indiatoday channel email'),
    '#default_value' => get_itg_variable('indiatoday_tvschedule_email'),
    '#required' => FALSE,
  );
  $form['aajtak_tvschedule_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Aajtak channel email'),
    '#default_value' => get_itg_variable('aajtak_tvschedule_email'),
    '#required' => FALSE,
  );
  $form['dilliaajtak_tvschedule_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Dilliaajtak channel email'),
    '#default_value' => get_itg_variable('dilliaajtak_tvschedule_email'),
    '#required' => FALSE,
  );
  $form['tez_tvschedule_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Tez channel email'),
    '#default_value' => get_itg_variable('tez_tvschedule_email'),
    '#required' => FALSE,
  );
  $form['occupation_people_termid'] = array(
    '#type' => 'textfield',
    '#title' => t('Occupation people ID'),
    '#default_value' => get_itg_variable('occupation_people_termid'),
    '#required' => FALSE,
  );
  $form['is_pti_cron_running'] = array(
    '#type' => 'textfield',
    '#title' => t('PTI Cron Running status'),
    '#default_value' => get_itg_variable('is_pti_cron_running', 1),
    '#required' => FALSE,
  );

  $form['status_third_level_menu'] = array(
    '#type' => 'textarea',
    '#title' => t('Third level menu show/hide at details page'),
    '#default_value' => get_itg_variable('status_third_level_menu'),
  );
  
  $form['sef_url_access'] = array(
    '#type' => 'textfield',
    '#title' => t('sefurl access by userid'),
    '#default_value' => get_itg_variable('sef_url_access'),
  );

  $form['sef_url_status'] = array(
    '#type' => 'checkbox',
    '#title' => t('sefurl status'),
    '#required' => FALSE,
    '#default_value' => get_itg_variable('sef_url_status'),
  );
  
  $form['anchor_page_js_version'] = array(
    '#type' => 'textfield',
    '#title' => t('Anchor Page Js Version'),
    '#default_value' => get_itg_variable('anchor_page_js_version'),
    '#required' => FALSE,
  );
  
  $form['alexa_email_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Email Adress for Alexa'),
    '#default_value' => get_itg_variable('alexa_email_id'),
  );
  
  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration'),
  );
  return $form;
}

function itg_custom_variables_submit($form, &$form_state){
	$values = $form_state['values'];
	unset($values['submit_button']);
	unset($values['form_build_id']);
	unset($values['form_token']);
	unset($values['form_id']);
	unset($values['op']);
	foreach ($values as $key => $value) {
		set_itg_variable($key, $value);
	}
  drupal_set_message(t('Configuration successfully saved.'), 'success');
}


function itg_election_configure() {
	$form = array();
  $form['itg_election_home_chunk'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Home election block'),
    '#required' => FALSE,
    '#default_value' => get_itg_variable('itg_election_home_chunk'),
  );
  $form['itg_election_home_webcast_livetv'] = array(
    '#type' => 'select',
    '#title' => t('Enable Webcast/LiveTV on Home election'),
    '#required' => FALSE,
    '#options' => array(0 => "Select", 'livetv' => "Live TV", 'webcast' => "Webcast Iframe"),
    '#default_value' => get_itg_variable('itg_election_home_webcast_livetv'),
  );
  $form['itg_election_home_webcast_html'] = array(
    '#type' => 'textarea',
    '#title' => t('Webcast home election HTML'),
    '#default_value' => get_itg_variable('itg_election_home_webcast_html'),
    '#required' => FALSE,
  );
  $form['itg_election_home_content_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Live Home election Live blog nid'),
    '#default_value' => get_itg_variable('itg_election_home_content_id'),
    '#size' => 20,
    '#required' => FALSE,
    '#maxlength' => 20,
  );
  $form['itg_election_home_bottom_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Live Home election Bottom label'),
    '#default_value' => get_itg_variable('itg_election_home_bottom_label'),
    '#size' => 60,
    '#required' => FALSE,
    '#maxlength' => 60,
  );
  $form['itg_election_home_bottom_label_url'] = array(
    '#type' => 'textarea',
    '#title' => t('Live Home election Bottom label Link'),
    '#default_value' => get_itg_variable('itg_election_home_bottom_label_url'),
    '#required' => FALSE
  );
  $form['election_graph_refreshtime'] = array(
    '#type' => 'textfield',
    '#title' => t('Election Graph refresh Time'),
    '#default_value' => get_itg_variable('election_graph_refreshtime'),
    '#size' => 20,
    '#required' => FALSE,
    '#maxlength' => 20,
  );
  $form['election_map_refreshtime'] = array(
    '#type' => 'textfield',
    '#title' => t('Election Map and Constituency page refresh Time'),
    '#default_value' => get_itg_variable('election_map_refreshtime'),
    '#size' => 20,
    '#required' => FALSE,
    '#maxlength' => 20,
  );
  $form['election_blocks_refreshtime'] = array(
    '#type' => 'textfield',
    '#title' => t('Election Blocks refresh Time'),
    '#default_value' => get_itg_variable('election_blocks_refreshtime'),
    '#size' => 20,
    '#required' => FALSE,
    '#maxlength' => 20,
  );
  $form['itg_election_top_stories_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Election Top Story label'),
    '#default_value' => get_itg_variable('itg_election_top_stories_label'),
    '#size' => 60,
    '#required' => FALSE,
    '#maxlength' => 60,
  );
  $form['itg_election_ttl_constituency'] = array(
    '#type' => 'textfield',
    '#title' => t('Election Constituency result AKAMAI cache TTL'),
    '#default_value' => get_itg_variable('itg_election_ttl_constituency'),
    '#size' => 60,
    '#required' => FALSE,
    '#maxlength' => 60,
  );
  $form['itg_election_mini_graph'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Mini Graph'),
    '#required' => FALSE,
    '#default_value' => get_itg_variable('itg_election_mini_graph'),
  );
  $form['livetv_share'] = array(
    '#type' => 'fieldset',
    '#title' => t('LiveTV share'),
    '#collapsible' => TRUE, // Added
    '#collapsed' => FALSE,  // Added
  );
  $form['livetv_share']['itg_livetvshare_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Live TV Share Title'),
    '#size' => 60,
    '#required' => FALSE,
    '#maxlength' => 60,
    '#default_value' => get_itg_variable('itg_livetvshare_title'),
  );
  $form['livetv_share']['itg_livetvshare_desc'] = array(
    '#type' => 'textarea',
    '#title' => t('Live TV Share Description'),
    '#required' => FALSE,
    '#default_value' => get_itg_variable('itg_livetvshare_desc'),
  );
  $form['graph_share'] = array(
    '#type' => 'fieldset',
    '#title' => t('Graph share'),
    '#collapsible' => TRUE, // Added
    '#collapsed' => FALSE,  // Added
  );
  $form['graph_share']['itg_graphshare_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Election graph Share Title'),
    '#size' => 60,
    '#required' => FALSE,
    '#maxlength' => 60,
    '#default_value' => get_itg_variable('itg_graphshare_title'),
  );
  $form['graph_share']['itg_graphshare_desc'] = array(
    '#type' => 'textarea',
    '#title' => t('Election graph Share Description'),
    '#required' => FALSE,
    '#default_value' => get_itg_variable('itg_graphshare_desc'),
  );
  $form['election_staticpages_nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Election Static pages nids'),
    '#required' => FALSE,
    '#default_value' => get_itg_variable('election_staticpages_nid'),
  );
  $form['submit_election'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration'),
  );
  return $form;
}

function itg_election_configure_submit($form, &$form_state){
	$values = $form_state['values'];
	unset($values['submit_button']);
	unset($values['form_build_id']);
	unset($values['form_token']);
	unset($values['form_id']);
	unset($values['op']);
	foreach ($values as $key => $value) {
		set_itg_variable($key, $value);
	}
  drupal_set_message(t('Configuration successfully saved.'), 'success');
}

/**
* Function For mobile app setting
* {@inheritdoc}
*/
function itg_mobile_app_configure(){
  global $user;
  $form = array();
  if (!in_array("Editor", $user->roles)) {

  $form['cube_js_mini_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Mini url'),
    '#default_value' => get_itg_variable('cube_js_mini_url'),
  );
  $form['cube_js_full_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Full url'),
    '#default_value' => get_itg_variable('cube_js_full_url'),
  );
  }
  $form['cube_js_status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable'),
    '#required' => FALSE,
    '#default_value' => get_itg_variable('cube_js_status'),
  );
  $form['submit_app_setting'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration'),
  );
  return $form;
}

/**
* {@inheritdoc}
*/
function itg_mobile_app_configure_submit($form, &$form_state){
  $values = $form_state['values'];
  unset($values['submit_button']);
  unset($values['form_build_id']);
  unset($values['form_token']);
  unset($values['form_id']);
  unset($values['op']);
  unset($values['submit_app_setting']);
  foreach ($values as $key => $value) {
    set_itg_variable($key, $value);
  }
  drupal_set_message(t('Configuration successfully saved.'), 'success');
}

/**
* Manage fifa category id for banner.
* {@inheritdoc}
*/
function itg_fifa_category_id(){
  $form = array();
  $form['fifa_category_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Fifa category id'),
    '#default_value' => get_itg_variable('fifa_category_id'),
  );
  $form['fifa_morenews_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Fifa More News Text'),
    '#default_value' => get_itg_variable('fifa_morenews_text'),
  );
  $form['fifa_morenews_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Fifa More News URL'),
    '#default_value' => get_itg_variable('fifa_morenews_url'),
  );
  $form['submit_fifa_setting'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration'),
  );
  return $form;
}

/**
* {@inheritdoc}
*/
function itg_fifa_category_id_submit($form, &$form_state){
  $values = $form_state['values'];
  unset($values['submit_button']);
  unset($values['form_build_id']);
  unset($values['form_token']);
  unset($values['form_id']);
  unset($values['op']);
  unset($values['submit_fifa_setting']);
  foreach ($values as $key => $value) {
    set_itg_variable($key, $value);
  }
  drupal_set_message(t('Configuration successfully saved.'), 'success');
}


/**
 * Manage fifa category id for banner.
 * {@inheritdoc}
 */
function itg_sponsor_content_configuration($form, &$form_state) {
  $form['field_container'] = [
    '#type' => 'container',
    '#weight' => 80,
    '#tree' => TRUE,
    '#prefix' => '<div id="js-ajax-elements-wrapper">',
    '#suffix' => '</div>',
  ];

  $form_state['field_deltas'] = isset($form_state['field_deltas']) ? $form_state['field_deltas'] : range(0, 0);
  $home_top_story_sponsor = json_decode(get_itg_variable('home_top_story_sponsor'));
  if (count($home_top_story_sponsor) > 0 && empty($form_state['clicked_button']['#value']) && $form_state['clicked_button']['#value'] != 'Remove') {
    $form_state['field_deltas'] = $home_top_story_sponsor;
  }
  $field_count = $form_state['field_deltas'];
  foreach ($field_count as $delta => $value) {
    $form['field_container'][$delta] = [
      '#type' => 'container',
      '#attributes' => [
        'class' => ['container-inline'],
      ],
      '#tree' => TRUE,
    ];

    $form['field_container'][$delta]['content_nid'] = [
      '#type' => 'textfield',
      '#default_value' => (!empty($value->nid) ? $value->nid : ''),
      '#size' => 25,
      '#weight' => 1,
      '#attributes' => [
        'placeholder' => ['Content Nid'],
      ],
    ];

    $form['field_container'][$delta]['content_position'] = [
      '#type' => 'textfield',
      '#default_value' => (!empty($value->position) ? $value->position : ''),
      '#size' => 25,
      '#weight' => 2,
      '#attributes' => [
        'placeholder' => ['Content Position'],
      ],
    ];

    $form['field_container'][$delta]['remove_name'] = [
      '#type' => 'submit',
      '#value' => t('Remove'),
      '#submit' => ['top_story_sponsor_add_more_remove'],
      '#ajax' => [
        'callback' => 'top_story_sponsor_add_more_remove_callback',
        'wrapper' => 'js-ajax-elements-wrapper',
      ],
      '#weight' => 3,
      '#attributes' => [
        'class' => ['button-small danger'],
      ],
      '#name' => 'remove_name_' . $delta,
    ];
  }

  $form['add_name'] = [
    '#type' => 'submit',
    '#value' => t('Add one more'),
    '#submit' => ['top_story_sponsor_add_more_add_one'],
    '#ajax' => [
      'callback' => 'top_story_sponsor_add_more_add_one_callback',
      'wrapper' => 'js-ajax-elements-wrapper',
    ],
    '#weight' => 100,
  ];
  $form['top_story_sponsor_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration'),
    '#weight' => 101,
  );
  return $form;
}

function top_story_sponsor_add_more_remove($form, &$form_state) {
  $delta_remove = $form_state['triggering_element']['#parents'][1];
  unset($form_state['field_deltas'][$delta_remove]);
  $form_state['rebuild'] = TRUE;
  drupal_get_messages();
}

function top_story_sponsor_add_more_remove_callback($form, &$form_state) {
  return $form['field_container'];
}

function top_story_sponsor_add_more_add_one($form, &$form_state) {
  $form_state['field_deltas'][] = count($form_state['field_deltas']) > 0 ? max($form_state['field_deltas']) + 1 : 0;
  $form_state['rebuild'] = TRUE;
  drupal_get_messages();
}

function top_story_sponsor_add_more_add_one_callback($form, $form_state) {
  return $form['field_container'];
}

/**
 * form_validate
 * @param type $form
 * @param type $form_state
 */
function itg_sponsor_content_configuration_validate($form, &$form_state){
  if ($form_state['input']['_triggering_element_value'] == 'Remove' || $form_state['input']['_triggering_element_value'] == 'Add one more' || $form_state['input']['_triggering_element_value'] == 'Add more') {
    return;
  }
  $is_empty = FALSE;
  $all_con_ids = array();
  $all_pos = array();
  $unpublished_ids = array();
  $invalid_ids = array();
  foreach ($form_state['values']['field_container'] as $key => $value) {
    if (empty($value['content_nid']) || empty($value['content_position'])) {
      $is_empty = TRUE;
    } else {
      $_nodes = itg_custom_var_get_node_title($value['content_nid']);
      if (empty($_nodes[0]->status)) {
        $unpublished_ids[] = $value['content_nid'];
      }
      if(count($_nodes) <= 0){
        $invalid_ids[] = $value['content_nid'];
      }
    }
    $all_con_ids[] = $value['content_nid'];
    $all_pos[] = $value['content_position'];

  }
  if (count($invalid_ids) > 0) {
    form_set_error('', t("Please use valid content id. Invalid: ". implode(",", $invalid_ids)));
  }
  if (count($unpublished_ids) > 0) {
    form_set_error('', t("Please use published content id. Unpublished: ". implode(",", $unpublished_ids)));
  }
  if ($is_empty) {
    form_set_error('', t("Content id and position can't empty"));
  }
  if (array_has_dupes($all_con_ids)) {
    form_set_error('', t("Content id already Exists"));
  }
  if (array_has_dupes($all_pos)) {
    form_set_error('', t("Content Position already Exists"));
  }
}

/**
 * form_submit
 * @param type $form
 * @param type $form_state
 */

function itg_sponsor_content_configuration_submit($form, &$form_state) {
  $sponsor_ids = array();
  foreach ($form_state['values']['field_container'] as $key => $value) {
    if (empty($value['content_nid']) || empty($value['content_position'])) {
      continue;
    }
    $sponsor_ids[] = array(
      'nid' => $value['content_nid'],
      'position' => $value['content_position']
    );
  }
  set_itg_variable('home_top_story_sponsor', json_encode($sponsor_ids));
  drupal_set_message(t('Configuration successfully saved.'), 'status');
}

/**
 * function is used to check duplicates in array
 * @param type $array
 * @return boolean
 */

function array_has_dupes($array) {
  return count($array) !== count(array_unique($array));
}


