<?php

/**
 * @file
 * Social media popup form
 */

/**
 * Create custom form for social media integration.
 *
 * {@inheritdoc}
 */
function itg_social_media_form($form, &$form_state, $c_type, $nid) {  
  global $user, $base_url;
  // Load node so that we can provide default value if values already present.
  $node = node_load($nid);
  $data = array();
  if (isset($node->field_story_social_media_integ['und']) && is_array($node->field_story_social_media_integ['und'])) {
    foreach ($node->field_story_social_media_integ['und'] as $option) {
      $data[] = $option['value'];
    }
  }   
  // Prepare form array.
  $form['itg_smi'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Promote On Social Media'),
    '#options' => array(
      'facebook' => t('<i title="Facebook" class="fa fa-facebook-square" aria-hidden="true"></i>'),      
      'twitter' => t('<i title="Twitter" class="fa fa-twitter-square" aria-hidden="true"></i>'),
      'instagram' => t('<i title="Instagram" class="fa fa-instagram" aria-hidden="true"></i>'),
      'facebook_instant_article' => t('<i title="Facebook Instant Article" class="fa fa-facebook-square" aria-hidden="true"></i>'),      
    ),
    '#default_value' => $data,
    '#required' => TRUE,
  );
  
  $form['fb_wrap'] = array(
    '#type' => 'fieldset',
    '#title' => t('Facebook'),
    '#attributes' => array('class' => array('social-fb-block')),
    '#states' => array(
      'visible' => array(
        ':input[name="itg_smi[facebook]"]' => array('checked' => TRUE),
      )
    ),
  );
  
  $form['fb_wrap']['itg_facebook_narrative'] = array(
    '#type' => 'textfield',
    '#title' => t('Image Narrative'),
    '#maxlength' => 255,
    '#default_value' => isset($node->field_story_facebook_narrative['und'][0]['value']) ? $node->field_story_facebook_narrative['und'][0]['value'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="itg_smi[facebook]"]' => array('checked' => TRUE),
      ),      
    ),
  );
  
  $form['fb_wrap']['itg_fb_img'] = array(
    '#title' => t('Image'),
    '#type' => 'managed_file',
    '#description' => t('The uploaded image will be displayed on this page using the image style choosen below.'),
    '#upload_location' => 'public://itg_fb_img/',
    '#default_value' => isset($node->field_story_facebook_image['und'][0]['fid']) ? $node->field_story_facebook_image['und'][0]['fid'] : 0,
    '#widget' => 'imce',
    '#description' => 'Files must be less than<strong>5 MB</strong>.<br>Allowed file types:<strong>gif jpeg </strong>',
    '#preview' => TRUE,
    "#upload_validators" => array(
      "file_validate_extensions" => array("gif jpeg"),
      "file_validate_size" => array(5*1024 * 1024),
    ),
    '#states' => array(
      'visible' => array(
        ':input[name="itg_smi[facebook]"]' => array('checked' => TRUE),
      ),      
    ),
  );
  $form['fb_wrap']['img_schedule_time'] = array(
    '#type' => 'date_popup',
    '#title' => t("Schedule Time"),    
    '#date_format' => 'd/m/Y H:i',
    '#attributes' => array('autocomplete' => 'off', 'readonly' => 'readonly'),
    '#default_value' => format_date(REQUEST_TIME, 'custom', 'd/m/Y H:i'),        
    '#date_timezone' => date_default_timezone(),
  );
  
  $form['fb_wrap']['itg_facebook_video_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Video Narrative'),
    '#maxlength' => 255,
    '#default_value' => isset($node->field_story_facebook_vdescripti['und'][0]['value']) ? $node->field_story_facebook_vdescripti['und'][0]['value'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="itg_smi[facebook]"]' => array('checked' => TRUE),
      ),      
    ),
  );
  
  $form['fb_wrap']['itg_fb_video'] = array(
    '#title' => t('Video'),
    '#type' => 'managed_file',
    '#upload_location' => 'public://facebook_video/',
    '#default_value' => isset($node->field_story_facebook_video['und'][0]['fid']) ? $node->field_story_facebook_video['und'][0]['fid'] : 0,
    '#widget' => 'imce',
    '#description' => 'Files must be less than<strong>512 MB</strong>.<br>Allowed file types:<strong>mp4 mov </strong>',
    '#preview' => TRUE,
    "#upload_validators" => array(
      "file_validate_extensions" => array("mp4 mov"),
      "file_validate_size" => array(500*1024 * 1024),
    ),
    '#states' => array(
      'visible' => array(
        ':input[name="itg_smi[facebook]"]' => array('checked' => TRUE),
      ),      
    ),
  );  
  $form['fb_wrap']['video_schedule_time'] = array(
    '#type' => 'date_popup',
    '#title' => t("Schedule Time"),    
    '#date_format' => 'd/m/Y H:i',
    '#attributes' => array('autocomplete' => 'off', 'readonly' => 'readonly'),
    '#default_value' => format_date(REQUEST_TIME, 'custom', 'd/m/Y H:i'),        
    '#date_timezone' => date_default_timezone(),
  );
  
  
  $form['twit_wrap'] = array(
    '#type' => 'fieldset',
    '#title' => t('Twitter'),
    '#attributes' => array('class' => array('social-twitter-block')),
    '#states' => array(
      'visible' => array(
        ':input[name="itg_smi[twitter]"]' => array('checked' => TRUE),
      )
    ),
  );
  
  $form['twit_wrap']['itg_twitter_narrative'] = array(
    '#type' => 'textfield',
    '#title' => t('Image Narrative'),
    '#maxlength' => 255,
    '#default_value' => isset($node->field_story_tweet['und'][0]['value']) ? $node->field_story_tweet['und'][0]['value'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="itg_smi[twitter]"]' => array('checked' => TRUE),
      ),
      'required' => array(
        ':input[name="itg_twitter_img[fid]"]' => array('!value' => 0),
      ),
    ),
    '#rules' => array(
        array(
          'rule' => 'length[10, 126]', 
          'error' => '%field field can not exceed 126 characters.'
        ),        
    ),    
  );
  
  $form['twit_wrap']['itg_twitter_img'] = array(
    '#title' => t('Image'),
    '#type' => 'managed_file',
    '#description' => t('The uploaded image will be displayed on this page using the image style choosen below.'),
    '#default_value' => isset($node->field_story_tweet_image['und'][0]['fid']) ? $node->field_story_tweet_image['und'][0]['fid'] : 0,
    '#upload_location' => 'public://itg_twitter_img/',
    '#widget' => 'imce',
    '#description' => 'Files must be less than<strong>5 MB</strong>.<br>Allowed file types:<strong>gif jpeg</strong>',
    '#preview' => TRUE,
    "#upload_validators" => array(
      "file_validate_extensions" => array("gif jepg"),
      "file_validate_size" => array(5*1024 * 1024),
    ),
    '#states' => array(
      'visible' => array(
        ':input[name="itg_smi[twitter]"]' => array('checked' => TRUE),
      ),      
    ),
  );
  
  $form['twit_wrap']['tw_img_schedule_time'] = array(
    '#type' => 'date_popup',
    '#title' => t("Schedule Time"),    
    '#date_format' => 'd/m/Y H:i',
    '#attributes' => array('autocomplete' => 'off', 'readonly' => 'readonly'),
    '#default_value' => format_date(REQUEST_TIME, 'custom', 'd/m/Y H:i'),    
    '#date_timezone' => date_default_timezone(),
  );

  $form['twit_wrap']['field_story_twitter_video_desc'] = array(
    '#type' => 'textfield',
    '#title' => t('Video Narrative'),
    '#maxlength' => 255,
    '#default_value' => isset($node->field_story_twitter_video_desc['und'][0]['value']) ? $node->field_story_twitter_video_desc['und'][0]['value'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="itg_smi[twitter]"]' => array('checked' => TRUE),
      ),      
    ),
    '#rules' => array(
        array(
          'rule' => 'length[10, 126]', 
          'error' => '%field field can not exceed 126 characters.'
        ),
    ),
  );
  $form['twit_wrap']['itg_twit_video'] = array(
    '#title' => t('Video'),
    '#type' => 'managed_file',
    '#upload_location' => 'public://twitter_video/',
    '#default_value' => isset($node->field_story_twitter_video['und'][0]['fid']) ? $node->field_story_twitter_video['und'][0]['fid'] : 0,
    '#widget' => 'imce',
    '#preview' => TRUE,
    '#description' => 'Files must be less than<strong>512 MB</strong>.<br>Allowed file types:<strong>mp4 mov </strong>' . l(t('Please visit'), 'https://support.twitter.com/articles/20172128#import-web'),
    "#upload_validators" => array(
      "file_validate_extensions" => array("mp4 mov"),
      "file_validate_size" => array(512*1024 * 1024),
    ),
    '#states' => array(
      'visible' => array(
        ':input[name="itg_smi[twitter]"]' => array('checked' => TRUE),
      ),      
    ),
  );
  
  $form['twit_wrap']['tw_vid_schedule_time'] = array(
    '#type' => 'date_popup',
    '#title' => t("Schedule Time"),    
    '#date_format' => 'd/m/Y H:i',
    '#attributes' => array('autocomplete' => 'off', 'readonly' => 'readonly'),
    '#default_value' => format_date(REQUEST_TIME, 'custom', 'd/m/Y H:i'),    
    '#date_timezone' => date_default_timezone(),
  );  
  $form['ctype'] = array(
    '#type' => 'hidden',
    '#default_value' => check_plain($c_type),
  );
  
  $form['nid'] = array(
    '#type' => 'hidden',
    '#default_value' => check_plain($nid),
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Share Content'),    
  );
  $form['#after_build'][] = 'itg_social_media_form_after_build';
  
  return $form;
}

/**
 * Implements after build function.
 *
 * @param array $form
 *   Array containing form elements.
 * @param array $form_state
 *   Array of submitted form data.
 *
 * @return array
 *   Altered form element array.
 */
function itg_social_media_form_after_build($form, &$form_state) {
  drupal_add_js(drupal_get_path('module', 'itg_social_media') . '/js/itg_social_media.js');
  drupal_add_js(drupal_get_path('module', 'itg_astro') . '/js/moment.js');
  
  return $form;
}
