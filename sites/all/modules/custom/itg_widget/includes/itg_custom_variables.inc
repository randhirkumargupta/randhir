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
  $form['enable_custom_lazyload'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Custom Lazy Load'),
    '#required' => FALSE,
    '#default_value' => get_itg_variable('enable_custom_lazyload'),
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
* Function For user access sef url
* {@inheritdoc}
*/
function itg_user_access_sef_url(){
  global $user;
  $form = array();
  $form['sef_url_access'] = array(
    '#type' => 'textfield',
    '#title' => t('Full url'),
    '#default_value' => get_itg_variable('sef_url_access'),
  );

  $form['sef_url_status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable'),
    '#required' => FALSE,
    '#default_value' => get_itg_variable('sef_url_status'),
  );
  $form['submit_sefurl_setting'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration'),
  );
  return $form;
}

/**
* {@inheritdoc}
*/
function itg_user_access_sef_url_submit($form, &$form_state){
  $values = $form_state['values'];
  unset($values['submit_button']);
  unset($values['form_build_id']);
  unset($values['form_token']);
  unset($values['form_id']);
  unset($values['op']);
  unset($values['submit_sefurl_setting']);
  foreach ($values as $key => $value) {
    set_itg_variable($key, $value);
  }
  drupal_set_message(t('Configuration successfully saved.'), 'success');
}
