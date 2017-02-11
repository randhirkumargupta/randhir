<?php

/**
 * @file: itg_loyalty_points_form.inc
 */

/**
 * Loyalty points configuration form
 * @return array
 */
function loyality_reward_points_configuration_form() {

    $form['lrp_layality_points_heading'] = array(
        '#type' => 'item',
        '#markup' => '<div class="itg-group-field"><h2>' . t('Point Configuration for Loyalty') . '</h2></div>',
    );
    $form['lrp_content_share'] = array(
        '#type' => 'textfield',
        '#title' => t('Content Share'),
        '#maxlength' => 6,
        '#default_value' => variable_get('lrp_content_share'),
    );
    $form['lrp_content_like'] = array(
        '#type' => 'textfield',
        '#title' => t('Content Like'),
        '#maxlength' => 6,
        '#default_value' => variable_get('lrp_content_like'),
    );
    $form['lrp_content_visit'] = array(
        '#type' => 'textfield',
        '#title' => t('Content Visit'),
        '#maxlength' => 6,
        '#default_value' => variable_get('lrp_content_visit'),
    );
    $form['lrp_follow_itg_on_social_sites'] = array(
        '#type' => 'textfield',
        '#title' => t('Follow ITG on Social Sites'),
        '#maxlength' => 6,
        '#default_value' => variable_get('lrp_follow_itg_on_social_sites'),
    );
    $form['lrp_newsletter_subscription'] = array(
        '#type' => 'textfield',
        '#title' => t('Newsletter Subscription'),
        '#maxlength' => 6,
        '#default_value' => variable_get('lrp_newsletter_subscription'),
    );
    $form['lrp_ugc_contribution'] = array(
        '#type' => 'textfield',
        '#title' => t('UGC Contribution'),
        '#maxlength' => 6,
        '#default_value' => variable_get('lrp_ugc_contribution'),
    );
    $form['lrp_online_registration_for_any_events'] = array(
        '#type' => 'textfield',
        '#title' => t('Online Registration for Any Events'),
        '#maxlength' => 6,
        '#default_value' => variable_get('lrp_online_registration_for_any_events'),
    );
    $form['lrp_participation_in_poll_campaign_survey'] = array(
        '#type' => 'textfield',
        '#title' => t('Participation in Poll/Campaign/Survey'),
        '#maxlength' => 6,
        '#default_value' => variable_get('lrp_participation_in_poll_campaign_survey'),
    );
    $form['lrp_refer_a_friend'] = array(
        '#type' => 'textfield',
        '#title' => t('Refer a Friend'),
        '#maxlength' => 6,
        '#default_value' => variable_get('lrp_refer_a_friend'),
    );

    $form['lrp_gold_start_heading'] = array(
        '#type' => 'item',
        '#markup' => '<div class="itg-group-field"><h2>' . t('Point configuration for Badges') . '</h2></div>',
    );
    $form['lrp_gold_star_one'] = array(
        '#type' => 'textfield',
        '#title' => t('Points required for one Gold Star'),
        '#maxlength' => 6,
        '#default_value' => variable_get('lrp_gold_star_one'),
    );

    $url_first = url('file/itg_image_repository/node/story/field_story_extra_large_image', array('query' => array('app' => 'lrp_gold_star_one_icon' . '|url@' . $filepath_id, 'field_name' => 'lrp_gold_star_one_icon', 'height' => 66, 'width' => 88, 'custom_form' => 1, 'btn_name' => 'lrp_gold_star_one_icon_upload_button')));
    $link_first_image = "showimagerepopopu('" . $url_first . "')";
    $form['lrp_gold_star_one_icon_fieldset'] = array(
        '#type' => 'fieldset',
        '#collapsible' => TRUE, // Added
        '#collapsed' => FALSE, // Added
    );

    $form['lrp_gold_star_one_icon_fieldset']['markup'] = array(
        '#type' => 'markup',
        '#markup' => '<div class="poll-form div_lrp_gold_star_one_icon"><a href="javascript:void(0)" onclick="' . $link_first_image . '">Browse Image</a></div>',
    );

    $form['lrp_gold_star_one_icon_fieldset']['lrp_gold_star_one_icon'] = array(
        '#type' => 'managed_file',
        '#title' => t('Badge Icon'),
        '#default_value' => variable_get('badge_1', ''),
        '#description' => t("Here you can upload an icon image for the first level."),
        '#required' => TRUE,
        '#upload_location' => 'public://badgeicons/',
        '#file_validate_extensions' => array('gif png jpg jpeg'),
    );

    $url_second = url('file/itg_image_repository/node/story/field_story_extra_large_image', array('query' => array('app' => 'lrp_gold_star_two_icon' . '|url@' . $filepath_id, 'field_name' => 'lrp_gold_star_two_icon', 'height' => 66, 'width' => 88, 'custom_form' => 1, 'btn_name' => 'lrp_gold_star_two_icon_upload_button')));
    $link_second_image = "showimagerepopopu('" . $url_second . "')";
    $form['lrp_gold_star_two'] = array(
        '#type' => 'textfield',
        '#title' => t('Points required for two Gold Star'),
        '#maxlength' => 6,
        '#default_value' => variable_get('lrp_gold_star_two'),
    );

    $form['lrp_gold_star_two_icon_fieldset'] = array(
        '#type' => 'fieldset',
        '#collapsible' => TRUE, // Added
        '#collapsed' => FALSE, // Added
    );

    $form['lrp_gold_star_two_icon_fieldset']['markup'] = array(
        '#type' => 'markup',
        '#markup' => '<div class="poll-form div_lrp_gold_star_two_icon"><a href="javascript:void(0)" onclick="' . $link_second_image . '">Browse Image</a></div>',
    );

    $form['lrp_gold_star_two_icon_fieldset']['lrp_gold_star_two_icon'] = array(
        '#type' => 'managed_file',
        '#title' => t('Badge Icon'),
        '#default_value' => variable_get('badge_2', ''),
        '#description' => t("Here you can upload an icon image for the second level."),
        '#required' => TRUE,
        '#upload_location' => 'public://badgeicons/',
        '#file_validate_extensions' => array('gif png jpg jpeg'),
    );

    $url_three = url('file/itg_image_repository/node/story/field_story_extra_large_image', array('query' => array('app' => 'lrp_gold_star_three_icon' . '|url@' . $filepath_id, 'field_name' => 'lrp_gold_star_three_icon', 'height' => 66, 'width' => 88, 'custom_form' => 1, 'btn_name' => 'lrp_gold_star_three_icon_upload_button')));
    $link_three_image = "showimagerepopopu('" . $url_three . "')";
    $form['lrp_gold_star_three'] = array(
        '#type' => 'textfield',
        '#title' => t('Points required for three Gold Star'),
        '#maxlength' => 6,
        '#default_value' => variable_get('lrp_gold_star_three'),
    );
    $form['lrp_gold_star_three_icon_fieldset'] = array(
        '#type' => 'fieldset',
        '#collapsible' => TRUE, // Added
        '#collapsed' => FALSE, // Added
    );

    $form['lrp_gold_star_three_icon_fieldset']['markup'] = array(
        '#type' => 'markup',
        '#markup' => '<div class="poll-form div_lrp_gold_star_three_icon"><a href="javascript:void(0)" onclick="' . $link_three_image . '">Browse Image</a></div>',
    );
    $form['lrp_gold_star_three_icon_fieldset']['lrp_gold_star_three_icon'] = array(
        '#type' => 'managed_file',
        '#title' => t('Badge Icon'),
        '#default_value' => variable_get('badge_3', ''),
        '#description' => t("Here you can upload an icon image for the third level."),
        '#required' => TRUE,
        '#upload_location' => 'public://badgeicons/',
        '#file_validate_extensions' => array('gif png jpg jpeg'),
    );
    $url_four = url('file/itg_image_repository/node/story/field_story_extra_large_image', array('query' => array('app' => 'lrp_gold_star_four_icon' . '|url@' . $filepath_id, 'field_name' => 'lrp_gold_star_four_icon', 'height' => 66, 'width' => 88, 'custom_form' => 1, 'btn_name' => 'lrp_gold_star_four_icon_upload_button')));
    $link_four_image = "showimagerepopopu('" . $url_four . "')";
    $form['lrp_gold_star_four'] = array(
        '#type' => 'textfield',
        '#title' => t('Points required for four Gold Star'),
        '#maxlength' => 6,
        '#default_value' => variable_get('lrp_gold_star_four'),
    );

    $form['lrp_gold_star_four_icon_fieldset'] = array(
        '#type' => 'fieldset',
        '#collapsible' => TRUE, // Added
        '#collapsed' => FALSE, // Added
    );

    $form['lrp_gold_star_four_icon_fieldset']['markup'] = array(
        '#type' => 'markup',
        '#markup' => '<div class="poll-form div_lrp_gold_star_four_icon"><a href="javascript:void(0)" onclick="' . $link_four_image . '">Browse Image</a></div>',
    );
    $form['lrp_gold_star_four_icon_fieldset']['lrp_gold_star_four_icon'] = array(
        '#type' => 'managed_file',
        '#title' => t('Badge Icon'),
        '#default_value' => variable_get('badge_4', ''),
        '#description' => t("Here you can upload an icon image for the fourth level."),
        '#required' => TRUE,
        '#upload_location' => 'public://badgeicons/',
        '#file_validate_extensions' => array('gif png jpg jpeg'),
    );
    $url_five = url('file/itg_image_repository/node/story/field_story_extra_large_image', array('query' => array('app' => 'lrp_gold_star_five_icon' . '|url@' . $filepath_id, 'field_name' => 'lrp_gold_star_five_icon', 'height' => 66, 'width' => 88, 'custom_form' => 1, 'btn_name' => 'lrp_gold_star_five_icon_upload_button')));
    $link_five_image = "showimagerepopopu('" . $url_five . "')";
    $form['lrp_gold_star_five'] = array(
        '#type' => 'textfield',
        '#title' => t('Points required for five Gold Star'),
        '#maxlength' => 6,
        '#default_value' => variable_get('lrp_gold_star_five'),
    );
    
     $form['lrp_gold_star_five_icon_fieldset'] = array(
        '#type' => 'fieldset',
        '#collapsible' => TRUE, // Added
        '#collapsed' => FALSE, // Added
    );

    $form['lrp_gold_star_five_icon_fieldset']['markup'] = array(
        '#type' => 'markup',
        '#markup' => '<div class="poll-form div_lrp_gold_star_five_icon"><a href="javascript:void(0)" onclick="' . $link_five_image . '">Browse Image</a></div>',
    );
    $form['lrp_gold_star_five_icon_fieldset']['lrp_gold_star_five_icon'] = array(
        '#type' => 'managed_file',
        '#title' => t('Badge Icon'),
        '#default_value' => variable_get('badge_5', ''),
        '#description' => t("Here you can upload an icon image for the fifth level."),
        '#required' => TRUE,
        '#upload_location' => 'public://badgeicons/',
        '#file_validate_extensions' => array('gif png jpg jpeg'),
    );
    $form['lrp_expiry_heading'] = array(
        '#type' => 'item',
        '#markup' => '<div class="itg-group-field"><h2>' . t('Expiry Settings') . '</h2></div>',
    );
    $form['lrp_loyality_points_expiry'] = array(
        '#type' => 'textfield',
        '#title' => t('Loyality Points Expiry (in days)'),
        '#required' => TRUE,
        '#maxlength' => 6,
        '#default_value' => variable_get('lrp_loyality_points_expiry'),
    );
    // Add cancel button to the form.
    $form['actions']['cancel'] = array(
        '#markup' => l(t('Cancel'), 'cms-user-dashboard', array('attributes' => array('class' => array('button')))),
        '#weight' => 20,
    );
    $form['#submit'][] = 'itg_loyalty_reward_badge_icon_submit';

    return system_settings_form($form);
}

/**
 * Implements custom submit callback function.
 *
 * {@inheritdoc}. 
 */
function itg_loyalty_reward_badge_icon_submit($form, &$form_state) {
    // Save first level icon
    _save_file_managed_image($form_state['values']['lrp_gold_star_one_icon']);
    variable_set('badge_1', $form_state['values']['lrp_gold_star_one_icon']);

    // Save first level icon
    _save_file_managed_image($form_state['values']['lrp_gold_star_two_icon']);
    variable_set('badge_2', $form_state['values']['lrp_gold_star_two_icon']);

    // Save first level icon
    _save_file_managed_image($form_state['values']['lrp_gold_star_three_icon']);
    variable_set('badge_3', $form_state['values']['lrp_gold_star_three_icon']);

    // Save first level icon
    _save_file_managed_image($form_state['values']['lrp_gold_star_four_icon']);
    variable_set('badge_4', $form_state['values']['lrp_gold_star_four_icon']);

    // Save first level icon
    _save_file_managed_image($form_state['values']['lrp_gold_star_five_icon']);
    variable_set('badge_5', $form_state['values']['lrp_gold_star_five_icon']);
}

/**
 * Save file to file_managed table and set status to permanent.
 *
 * @global stdObject $user
 * @param int $fid
 */
function _save_file_managed_image($fid) {
    global $user;
    // Load the file via file.fid.
    $file = file_load($fid);
    // Change status to permanent.
    $file->status = FILE_STATUS_PERMANENT;
    // Save.
    file_save($file);
    // Record that the module (in this example, user module) is using the file. 
    file_usage_add($file, 'user', 'user', $user->uid);
}

/**
 * Implements hook_validate function for loyalty points configuration form
 * @param array $form
 * @param array $form_state
 */
function loyality_reward_points_configuration_form_validate($form, &$form_state) {

    // Collect form variables
    $form_values = $form_state['values'];
    $content_share = $form_values['lrp_content_share'];
    $content_like = $form_values['lrp_content_like'];
    $content_visit = $form_values['lrp_content_visit'];
    $follow_social_sites = $form_values['lrp_follow_itg_on_social_sites'];
    $newsletter_sub = $form_values['lrp_newsletter_subscription'];
    $ugc_contribution = $form_values['lrp_ugc_contribution'];
    $online_reg = $form_values['lrp_online_registration_for_any_events'];
    $participate = $form_values['lrp_participation_in_poll_campaign_survey'];
    $refer_friend = $form_values['lrp_refer_a_friend'];
    $loyality_points_expiry = $form_values['lrp_loyality_points_expiry'];

    // Gold star variables
    $gold_start_one = $form_values['lrp_gold_star_one'];
    $gold_start_two = $form_values['lrp_gold_star_two'];
    $gold_start_three = $form_values['lrp_gold_star_three'];
    $gold_start_four = $form_values['lrp_gold_star_four'];
    $gold_start_five = $form_values['lrp_gold_star_five'];

    // Validation of loyalty points for form fileds
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

    if ($loyality_points_expiry !== '' && (!is_numeric($loyality_points_expiry) || $loyality_points_expiry < 1)) {
        form_set_error('lrp_loyality_points_expiry', t('Loyality points expiry field value must be numeric and greater than zero.'));
    }

    // Validation of gold star fields for zero and negative value
    if ($gold_start_one !== '' && (!is_numeric($gold_start_one) || $gold_start_one < 1)) {
        form_set_error('lrp_gold_star_one', t('Gold star one value must be numeric and greater than zero.'));
    }

    if ($gold_start_two !== '' && (!is_numeric($gold_start_two) || $gold_start_two < 1)) {
        form_set_error('lrp_gold_star_two', t('Gold star two value must be numeric and greater than zero.'));
    }

    if ($gold_start_three !== '' && (!is_numeric($gold_start_three) || $gold_start_three < 1)) {
        form_set_error('lrp_gold_star_three', t('Gold star three value must be numeric and greater than zero.'));
    }

    if ($gold_start_four !== '' && (!is_numeric($gold_start_four) || $gold_start_four < 1)) {
        form_set_error('lrp_gold_star_four', t('Gold star four value must be numeric and greater than zero.'));
    }

    if ($gold_start_five !== '' && (!is_numeric($gold_start_five) || $gold_start_five < 1)) {
        form_set_error('lrp_gold_star_five', t('Gold star five value must be numeric and greater than zero.'));
    }

    // Validation for gold star greater values
    if (!empty($gold_start_two) && ($gold_start_two <= $gold_start_one)) {
        form_set_error('lrp_gold_star_two', t('Gold star two value must be greater than gold star one.'));
    }

    if (!empty($gold_start_three) && (($gold_start_three <= $gold_start_one) || ($gold_start_three <= $gold_start_two))) {
        form_set_error('lrp_gold_star_two', t('Gold star three value must be greater than gold star one and two.'));
    }

    if (!empty($gold_start_four) && (($gold_start_four <= $gold_start_one) || ($gold_start_four <= $gold_start_two) || ($gold_start_four <= $gold_start_three))) {
        form_set_error('lrp_gold_star_two', t('Gold star four value must be greater than gold star one, two and three.'));
    }

    if (!empty($gold_start_five) && (($gold_start_five <= $gold_start_one) || ($gold_start_five <= $gold_start_two) || ($gold_start_five <= $gold_start_three) || ($gold_start_five <= $gold_start_four))) {
        form_set_error('lrp_gold_star_two', t('Gold star five value must be greater than gold star one, two, three and four.'));
    }
}
