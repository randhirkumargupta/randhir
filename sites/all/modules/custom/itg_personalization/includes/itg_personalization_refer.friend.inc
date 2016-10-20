<?php

/**
 * @file
 *   Refer a friend form. 
 */

/**
 * Implemetns hook_form().
 *
 * {@inheritdoc}.
 */
function itg_personalization_refer_a_friend_form($form, &$form_state) {      
  $form['friend_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Friend List'),
    // Set up the wrapper so that AJAX will be able to replace the fieldset.
    '#prefix' => '<div id="friend-fieldset-wrapper">',
    '#suffix' => '</div>',
  );

  // Build the fieldset with the proper number of names. We'll use
  // $form_state['num_firend'] to determine the number of collection to build.
  if (empty($form_state['num_friend'])) {
    $form_state['num_friend'] = 1;
  }

  for ($i = 0; $i < $form_state['num_friend']; $i++) {
    $form['friend_fieldset']['name_' . $i] = array(
      '#title' => t('Name'),
      '#type' => 'textfield',
      '#required' => TRUE,
      '#maxlength' => 255,
    );

    $form['friend_fieldset']['mail_' . $i] = array(
      '#title' => t('Email'),
      '#type' => 'textfield',
      '#required' => TRUE,
      '#maxlength' => 255,
    );
  }
  $form['friend_fieldset']['add_friend'] = array(
    '#type' => 'submit',
    '#value' => t('Add more'),
    '#submit' => array('itg_personalization_add_more_add_one'),
    '#ajax' => array(
      'callback' => 'itg_personalization_add_more_callback',
      'wrapper' => 'friend-fieldset-wrapper',
    ),
  );
  if ($form_state['num_friend'] > 1) {
    $form['friend_fieldset']['remove_friend'] = array(
      '#type' => 'submit',
      '#value' => t('Remove'),
      '#submit' => array('itg_personalization_add_more_remove_one'),
      '#ajax' => array(
        'callback' => 'itg_personalization_add_more_callback',
        'wrapper' => 'friend-fieldset-wrapper',
      ),
    );
  }
  $form['total_friend'] = array(
    '#type' => 'value',
    '#value' => $form_state['num_friend'],
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('save'),
  );

  return $form;
}

/**
 * Ajax callback function to add one more group.
 *
 * @param array $form
 * @param array $form_state
 */
function itg_personalization_add_more_add_one($form, &$form_state) {
  $form_state['num_friend'] ++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Ajax submit function for add more field.
 *
 * @param array $form
 * @param array $form_state
 * @return array
 */
function itg_personalization_add_more_callback($form, $form_state) {
  return $form['friend_fieldset'];
}

/**
 * Ajax callback fucntion to remove one group.
 *
 * @param array $form
 * @param array $form_state
 */
function itg_personalization_add_more_remove_one($form, &$form_state) {
  if ($form_state['num_friend'] > 1) {
    $form_state['num_friend'] --;
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Implements hook_submit().
 *
 * {@inheritdoc}. * 
 */
function itg_personalization_refer_a_friend_form_submit($form, &$form_state) {
  dpm($form_state['values']);
}
