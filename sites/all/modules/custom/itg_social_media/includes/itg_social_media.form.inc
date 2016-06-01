<?php
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
  foreach ($node->field_story_social_media_integ['und'] as $option) {
    $data[] = $option['value'];
  }

  // Add js file to form.
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'itg_social_media') . '/js/itg_social_media.js',
    drupal_get_path('module', 'itg_astro') . '/js/jquery.validate.min.js',
  ); 
  
  // Prepare form array.
    $form['itg_smi'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Social media integration '),
      '#options' => array(
        'facebook' => 'Facebook',
        'facebook_instant_article' => 'Facebook Instant Article',
        'twitter' => 'Twitter',
      ),
      '#default_value' => $data,
    );
    $form['fb_wrap'] = array(
      '#type' => 'fieldset',
      '#title' => t('Facebook Social Media Integration'),
      '#attributes' => array('class' => array('social-fb-block')),
      '#states' => array(
        'visible' => array(
          ':input[name="itg_smi[facebook]"]' => array('checked' => TRUE),
        )
      ),
    );
    $form['fb_wrap']['itg_facebook_narrative'] = array(
      '#type' => 'textfield',
      '#title' => t('Facebook Narrative'),
      '#maxlength' => 255,
      '#default_value' => isset($node->field_story_facebook_narrative['und'][0]['value']) ? $node->field_story_facebook_narrative['und'][0]['value'] : '',
      '#states' => array(
        'visible' => array(
          ':input[name="itg_smi[facebook]"]' => array('checked' => TRUE),
        ),
        'required' => array(
          ':input[name="itg_smi[facebook]"]' => array('checked' => TRUE),
        )
      ),
    );
    
    // Facebook additional fields
    $form['fb_wrap']['field_story_posted_by_facebook'] = array(
      '#type' => 'hidden',      
      '#maxlength' => 255,
      '#default_value' => $user->name,      
      '#states' => array(
        'visible' => array(
          ':input[name="itg_smi[facebook]"]' => array('checked' => TRUE),
        ),
        'required' => array(
          ':input[name="itg_smi[facebook]"]' => array('checked' => TRUE),
        )
      ),
    );    
    $form['fb_wrap']['field_story_time_facebook'] = array(    
      '#type' => 'hidden',
      '#default_value' => REQUEST_TIME,
      '#states' => array(
        'visible' => array(
          ':input[name="itg_smi[facebook]"]' => array('checked' => TRUE),
        ),
        'required' => array(
          ':input[name="itg_smi[facebook]"]' => array('checked' => TRUE),
        )
      ),
    );
    // Additional field ends here    
    $form['fb_wrap']['itg_fb_img'] = array(
      '#title' => t('Facebook Image'),
      '#type' => 'managed_file',
      '#description' => t('The uploaded image will be displayed on this page using the image style choosen below.'),      
      '#upload_location' => 'public://itg_fb_img/',
      '#default_value' => isset($node->field_story_facebook_image['und'][0]['fid']) ? $node->field_story_facebook_image['und'][0]['fid'] : 0,
      '#widget' => 'imce',      
      '#preview' => TRUE,
      '#states' => array(
        'visible' => array(
          ':input[name="itg_smi[facebook]"]' => array('checked' => TRUE),
        ),
        'required' => array(
          ':input[name="itg_smi[facebook]"]' => array('checked' => TRUE),
        )
      ),
    );
    $form['twit_wrap'] = array(
      '#type' => 'fieldset',
      '#title' => t('Twitter Social Media Integration'),
      '#attributes' => array('class' => array('social-twitter-block')),
      '#states' => array(
        'visible' => array(
          ':input[name="itg_smi[twitter]"]' => array('checked' => TRUE),
        )
      ),
    );
    $form['twit_wrap']['itg_twitter_narrative'] = array(
      '#type' => 'textfield',
      '#title' => t('Twitter Narrative'),
      '#maxlength' => 255,
      '#default_value' => isset($node->field_story_tweet['und'][0]['value']) ? $node->field_story_tweet['und'][0]['value'] : '',
      '#states' => array(
        'visible' => array(
          ':input[name="itg_smi[twitter]"]' => array('checked' => TRUE),
        ),
        'required' => array(
          ':input[name="itg_smi[twitter]"]' => array('checked' => TRUE),
        )
      ),
    );
    $form['twit_wrap']['itg_twitter_img'] = array(
      '#title' => t('Twitter Image'),
      '#type' => 'managed_file',
      '#description' => t('The uploaded image will be displayed on this page using the image style choosen below.'),
      '#default_value' => isset($node->field_story_tweet_image['und'][0]['fid']) ? $node->field_story_tweet_image['und'][0]['fid'] : 0,
      '#upload_location' => 'public://itg_twitter_img/',
      '#widget' => 'imce',      
      '#preview' => TRUE,
      '#states' => array(
        'visible' => array(
          ':input[name="itg_smi[twitter]"]' => array('checked' => TRUE),
        ),
        'required' => array(
          ':input[name="itg_smi[twitter]"]' => array('checked' => TRUE),
        )
      ),
    );
    
    // Twitter additional fields    
    $form['twit_wrap']['field_story_posted_by_twitter'] = array(
      '#type' => 'hidden',      
      '#maxlength' => 255,
      '#default_value' => $user->name,
      '#states' => array(
        'visible' => array(
          ':input[name="itg_smi[twitter]"]' => array('checked' => TRUE),
        ),
        'required' => array(
          ':input[name="itg_smi[twitter]"]' => array('checked' => TRUE),
        )
      ),
    );    
    $form['twit_wrap']['field_story_time_twitter'] = array(    
      '#type' => 'hidden',
      '#default_value' => REQUEST_TIME,
      '#states' => array(
        'visible' => array(
          ':input[name="itg_smi[twitter]"]' => array('checked' => TRUE),
        ),
        'required' => array(
          ':input[name="itg_smi[twitter]"]' => array('checked' => TRUE),
        )
      ),
    );
    // Additional field ends here
    
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
    
  // Check facebook USER IS LOGGED IN OR NOT
  $fb = new FBAutopost();
  $fb_user = $fb->getUser();  
  if ($fb_user == 0) {
    $form['not_login'] = array(
      '#type' => 'markup',
      '#markup' => l(t('Please login to facebook page'), $fb->getLoginUrl(), array('class' => array('button'))),
    );
  }
  
  return $form;
}