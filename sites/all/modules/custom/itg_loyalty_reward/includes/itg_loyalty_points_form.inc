<?php

/**
 * @file: itg_loyalty_points_form.inc
 */

/**
 * Loyalty points configuration form
 * @return array
 */
function loyalty_points_configuration_form() {
 
  $form['lrp_content_share'] = array(
      '#type' => 'textfield',
      '#title' => 'Content Share',
      '#default_value' => variable_get('lrp_content_share'),
  );
  $form['lrp_content_like'] = array(
      '#type' => 'textfield',
      '#title' => 'Content Like',
      '#default_value' => variable_get('lrp_content_like'),
  );
  $form['lrp_content_visit'] = array(
      '#type' => 'textfield',
      '#title' => 'Content Visit',
      '#default_value' => variable_get('lrp_content_visit'),
  );
  $form['lrp_follow_itg_on_social_sites'] = array(
      '#type' => 'textfield',
      '#title' => 'Follow ITG on Social Sites ',
      '#default_value' => variable_get('lrp_follow_itg_on_social_sites'),
  );
  $form['lrp_newsletter_subscription'] = array(
      '#type' => 'textfield',
      '#title' => 'Newsletter Subscription ',
      '#default_value' => variable_get('lrp_newsletter_subscription'),
  );
  $form['lrp_ugc_contribution'] = array(
      '#type' => 'textfield',
      '#title' => 'UGC Contribution',
      '#default_value' => variable_get('lrp_ugc_contribution'),
  );
  $form['lrp_online_registration_for_any_events'] = array(
      '#type' => 'textfield',
      '#title' => 'Online Registration for Any Events',
      '#default_value' => variable_get('lrp_online_registration_for_any_events'),
  );
  $form['lrp_participation_in_poll_campaign_survey'] = array(
      '#type' => 'textfield',
      '#title' => 'Participation in Poll/Campaign/Survey',
      '#default_value' => variable_get('lrp_participation_in_poll_campaign_survey'),
  );
  $form['lrp_refer_a_friend'] = array(
      '#type' => 'textfield',
      '#title' => 'Refer a Friend',
      '#default_value' => variable_get('lrp_refer_a_friend'),
  );
  $form['lrp_points_required_for_one_gold_star'] = array(
      '#type' => 'textfield',
      '#title' => 'Points Required for One Gold Star',
      '#default_value' => variable_get('lrp_points_required_for_one_gold_star'),
  );
  $form['lrp_loyality_points_expiry'] = array(
      '#type' => 'textfield',
      '#title' => 'Loyality Points Expiry(in days)',
      '#required' => TRUE,
      '#default_value' => variable_get('lrp_loyality_points_expiry'),
  );

  return system_settings_form($form); 
}

/**
 * Implements hook_validate function for loyalty points configuration form
 * @param array $form
 * @param array $form_state
 */
function loyalty_points_configuration_form_validate($form, &$form_state) {
  $form_values = $form_state['values'];
  
  // Collect form variables
  $content_share = $form_values['lrp_content_share'];
  $content_like = $form_values['lrp_content_like'];
  $content_visit = $form_values['lrp_content_visit'];
  $follow_social_sites = $form_values['lrp_follow_itg_on_social_sites'];
  $newsletter_sub = $form_values['lrp_newsletter_subscription'];
  $ugc_contribution = $form_values['lrp_ugc_contribution'];
  $online_reg = $form_values['lrp_online_registration_for_any_events'];
  $participate = $form_values['lrp_participation_in_poll_campaign_survey'];
  $refer_friend = $form_values['lrp_refer_a_friend'];
  $points_gold_star = $form_values['lrp_points_required_for_one_gold_star'];
  $loyality_points_expiry = $form_values['lrp_loyality_points_expiry'];

  // Add validation for form fileds
  if ($content_share !== '' && (!is_numeric($content_share) || $content_share < 1)) {
    form_set_error('lrp_content_share', t('Content share field value must be numeric and greater than zero.'));
  }
  
  if ($content_like !== '' && (!is_numeric($content_like) || $content_like < 1)) {
    form_set_error('lrp_content_like', t('Content like field value must be numeric and greater than zero.'));
  }
  
  if ($content_visit !== '' && (!is_numeric($content_visit) || $content_visit < 1)) {
    form_set_error('lrp_content_visit', t('Content visit field value must be numeric and greater than zero.'));
  }
  
  if ($follow_social_sites !== '' && (!is_numeric($follow_social_sites) || $follow_social_sites < 1)) {
    form_set_error('lrp_follow_itg_on_social_sites', t('Follow itg on social sites field value must be numeric and greater than zero.'));
  }
  
  if ($newsletter_sub !== '' && (!is_numeric($newsletter_sub) || $newsletter_sub < 1)) {
    form_set_error('lrp_newsletter_subscription', t('Newsletter subscription field value must be numeric and greater than zero.'));
  }
  
  if ($ugc_contribution !== '' && (!is_numeric($ugc_contribution) || $ugc_contribution < 1)) {
    form_set_error('lrp_ugc_contribution', t('UGC contribution field value must be numeric and greater than zero.'));
  }
  
  if ($online_reg !== '' && (!is_numeric($online_reg) || $online_reg < 1)) {
    form_set_error('lrp_online_registration_for_any_events', t('Online registration for any events field value must be numeric and greater than zero.'));
  }
  
  if ($participate !== '' && (!is_numeric($participate) || $participate < 1)) {
    form_set_error('lrp_participation_in_poll_campaign_survey', t('Participation in poll/campaign/survey field value must be numeric and greater than zero.'));
  }
  
  if ($refer_friend !== '' && (!is_numeric($refer_friend) || $refer_friend < 1)) {
    form_set_error('lrp_refer_a_friend', t('Refer a friend field value must be numeric and greater than zero.'));
  }
  
  if ($points_gold_star !== '' && (!is_numeric($points_gold_star) || $points_gold_star < 1)) {
    form_set_error('lrp_points_required_for_one_gold_star', t('Points required for one gold star field value must be numeric and greater than zero.'));
  }
  
  if ($loyality_points_expiry !== '' && (!is_numeric($loyality_points_expiry) || $loyality_points_expiry < 1)) {
    form_set_error('lrp_loyality_points_expiry', t('Loyality points expiry field value must be numeric and greater than zero.'));
  }
}
