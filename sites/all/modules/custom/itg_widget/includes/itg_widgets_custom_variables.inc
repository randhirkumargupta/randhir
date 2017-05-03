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
function itg_widgets_custom_variables() {
  $form = array();
  $form['program_category_id_for_programmes'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter Program Category Id'),
    '#default_value' => variable_get('program_category_id_for_programmes'),
    '#size' => 20,
    '#maxlength' => 20,
  );
  $form['so_sorry_category_id_for_widget'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter So Sorry Category Id'),
    '#default_value' => variable_get('so_sorry_category_id_for_widget'),
    '#size' => 20,
    '#maxlength' => 20,
  );
  $form['anchor_id_for_widget'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter Occupation for Anchors'),
    '#default_value' => variable_get('anchor_id_for_widget'),
    '#size' => 20,
    '#maxlength' => 20,
  );
  $form['year_end_for_widget'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter tid of year end'),
    '#default_value' => variable_get('year_end_for_widget'),
    '#size' => 20,
    '#maxlength' => 20,
  );
  $form['auto_for_widget'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter tid of Auto'),
    '#default_value' => variable_get('auto_for_widget'),
    '#size' => 20,
    '#maxlength' => 20,
  );


  $form['tech_for_widget'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter tid of tech'),
    '#default_value' => variable_get('tech_for_widget'),
    '#size' => 20,
    '#maxlength' => 20,
  );

  $form['entertainment_oscar_for_widget'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter tid of Entertainment Oscar Watch'),
    '#default_value' => variable_get('entertainment_oscar_for_widget'),
    '#size' => 20,
    '#maxlength' => 20,
  );

  $form['movie_for_widget'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter tid of movie'),
    '#default_value' => variable_get('movie_for_widget'),
    '#size' => 20,
    '#maxlength' => 20,
  );

  $form['ipl_points_tally_for_widget'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter nid of ipl points tally'),
    '#default_value' => variable_get('ipl_points_tally_for_widget'),
    '#size' => 20,
    '#maxlength' => 20,
  );
  $form['ipl_top_performer_for_widget'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter nid of ipl tip performer'),
    '#default_value' => variable_get('ipl_top_performer_for_widget'),
    '#size' => 20,
    '#maxlength' => 20,
  );
  $form['ipl_for_widget'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter tid of ipl'),
    '#default_value' => variable_get('ipl_for_widget'),
    '#size' => 20,
    '#maxlength' => 20,
  );

  $form['we_may_suggest_block_condition'] = array(
    '#type' => 'textarea',
    '#title' => t('We may suggest block condition for arg(1)'),
    '#default_value' => variable_get('we_may_suggest_block_condition'),
  );

  $form['watch_right_now_block_condition'] = array(
    '#type' => 'textarea',
    '#title' => t('watch right now block condition for arg(1)'),
    '#default_value' => variable_get('watch_right_now_block_condition'),
  );

  $form['top_takes_block_condition'] = array(
    '#type' => 'textarea',
    '#title' => t('top takes block condition for arg(1)'),
    '#default_value' => variable_get('top_takes_block_condition'),
  );
  $form['tid_politician'] = array(
    '#type' => 'textarea',
    '#title' => t('tid of politician'),
    '#default_value' => variable_get('tid_politician'),
  );

  $form['apache_solr_sites_prefix_values'] = array(
    '#type' => 'textfield',
    '#title' => t('Apache solr sites prefix and has values'),
    '#description' => t("Ex: eoshds|IndiaToday,asdasd|AAJtak"),
    '#default_value' => variable_get('apache_solr_sites_prefix_values'),
  );
  $form['newsletter_education_tid'] = array(
    '#type' => 'textfield',
    '#title' => t('Newsletter Eduction Tid'),
    '#default_value' => variable_get('newsletter_education_tid'),
  );
  $form['category_manager_vid'] = array(
    '#type' => 'textfield',
    '#title' => t('Category Manager Vid'),
    '#default_value' => variable_get('category_manager_vid'),
  );
  $form['itg_newsletter_education_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter education tid'),
    '#default_value' => variable_get('itg_newsletter_education_id'),
    '#size' => 20,
    '#maxlength' => 20,
  );
  $form['quiz_taxonomy_tid'] = array(
    '#type' => 'textfield',
    '#title' => t('Quiz taxonomy vid'),
    '#default_value' => variable_get('quiz_taxonomy_tid'),
    '#size' => 20,
    '#maxlength' => 20,
  );
  $form['city_manager_vid'] = array(
    '#type' => 'textfield',
    '#title' => t('City Management Vid'),
    '#default_value' => variable_get('city_manager_vid'),
    '#size' => 20,
  );
  $form['reporter_tid'] = array(
    '#type' => 'textfield',
    '#title' => t('Anchor occupation tid for anchors-listing page.'),
    '#default_value' => variable_get('reporter_tid'),
    '#size' => 20,
  );
  $form['live_score_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Live schore URL'),
    '#default_value' => variable_get('live_score_url'),
    '#size' => 255,
  );
  $form['ipl_rhs_nids'] = array(
    '#type' => 'textfield',
    '#title' => t('node id for ipl rhs'),
    '#default_value' => variable_get('ipl_rhs_nids'),
    '#size' => 255,
  );
  $form['anchor_tid'] = array(
    '#type' => 'textfield',
    '#title' => t('Anchor Tid'),
    '#default_value' => variable_get('anchor_tid'),
    '#size' => 20,
  );

  $form['solr_url_config'] = array(
    '#type' => 'textarea',
    '#title' => t('Solr urlconfig'),
    '#default_value' => variable_get('solr_url_config'),
  );

  $form['aaj_tak_json_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Aaj tak json url'),
    '#default_value' => variable_get('aaj_tak_json_url'),
  );

  $form['business_today_json_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Business today json url'),
    '#default_value' => variable_get('business_today_json_url'),
  );
  
  $form['read_later_days_config'] = array(
    '#type' => 'textfield',
    '#title' => t('Read Later days configuration'),
    '#attributes' => array('placeholder' => t('Enter no of days')),
    '#default_value' => variable_get('read_later_days_config'),
  );
  return system_settings_form($form);
}
