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
      '#type' =>'checkbox',
      '#title'=>t('Enable Top story ad'),
      '#required'=> FALSE,
      '#default_value' => get_itg_variable('enable_top_story_ad'),
  );
	$form['top_story_ad_position'] = array(
		'#type' => 'textfield',
		'#title' => t('Top story ad position'),
		'#default_value' => get_itg_variable('top_story_ad_position'),
		'#size' => 20,
		'#required'=> FALSE,
		'#maxlength' => 20,
	);
	$form['top_story_ad_html'] = array(
		'#type' => 'textarea',
		'#title' => t('Top story ad HTML'),
		'#default_value' => get_itg_variable('top_story_ad_html'),
		'#required'=> FALSE,
	);	
	$form['home_page_election_tid'] = array(
		'#type' => 'textfield',
		'#title' => t('Home Page election Tid'),
		'#default_value' => get_itg_variable('home_page_election_tid'),
		'#size' => 20,
		'#required'=> FALSE,
		'#maxlength' => 20,
	);
  $form['delete_pti_xmlfile_days'] = array(
    '#type' => 'textfield',
    '#title' => t('Delete PTI Xml FileName From DB (In Dyas)'),
    '#default_value' => get_itg_variable('delete_pti_xmlfile_days'),
    '#size' => 20,
    '#maxlength' => 20,
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
