<?php

/**
 * Function for ajax request callback
 */

function itg_live_blog_custom() {
  global $base_url, $user;
  $arg = arg();
  drupal_add_js(drupal_get_path('theme', 'itg') . '/js/bootstrap.min.js', array('preprocess' => false, 'weight' => 5, 'scope' => 'footer'));
  drupal_add_css('https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css', array('type' => 'external'));
 
  return theme('itg_live_blog_custom_form', array('data' => $data));

}

/**
 * custom form for content deatils.
 * @param type $form
 * @param type $form_state
 * @param type $bid
 * @param type $type
 * @return string
 */
function itg_manage_breking_news($form, &$form_state, $bid, $type) {
  $arg = arg();
   
  if (isset($arg) && ($arg[1] == 'edit' || $arg[2] == 'ajax')) {
    $query = db_select('itg_live_blog', 'm');
    if($arg[2] == 'ajax') {
      $query->condition('m.bid', $arg[3], '=');
    } else {
      $query->condition('m.bid', $arg[2], '=');
    }
    # get the desired fields from the database
    $query->fields('m', array('bid','blog_entity_id', 'blog_type', 'blog_title', 'blog_description', 'blog_breaking_band', 'blog_notification', 'blog_publish_time','blog_highlight_status'));
    # execute the query
    $results = $query->execute()->fetchObject();
  }
  elseif (isset($arg) && $arg[1] == 'add') {
    $blog_entity_id = $arg[2];
  }
 
  $form = array();
  // To make the fieldset collapsible
  $form['breaking'] = array(
    '#type' => 'fieldset',
    '#title' => t(''),
    '#collapsible' => TRUE, // Added
    '#collapsed' => FALSE,  // Added
  );
   
  $form['breaking']["wrapper"] = array(
      "#markup" => "<div class='inline-error-messages'></div>",
      );
   
  
   $form['breaking']['blog_title'] = array(
    '#type' => 'textfield',
    '#prefix' => '<div id="blog_title_replace_wrapper"><input class="blog_highlight_checkbox" type="checkbox" name="blog_highlight_checkbox" value="1" />',
    '#title' => t('Title'),
    '#default_value' => isset($results->blog_title) ? $results->blog_title : '',
     '#suffix' => '</div>',
  );
   
  $form['breaking']['blog_description'] = array(
    '#type' => 'text_format',
    '#title' => 'Description',
    '#rows' => 5,
    '#resizable' => FALSE,
    '#default_value'=> isset($results->blog_description) ? $results->blog_description : '',
    '#format' => 'full_html',
    '#prefix' => '<div id="blog_description_replace_wrapper">',
    '#suffix' => '</div>',
  );
    
  $form['breaking']['blog_breaking_band'] = array(
    '#type' => 'hidden',
    '#value' => ($results->blog_breaking_band) ? $results->blog_breaking_band : 1,
  );
  
  $form['breaking']['blog_entity_id'] = array(
    '#type' => 'hidden',
    '#value' => ($results->blog_entity_id) ? $results->blog_entity_id : $blog_entity_id,
    '#prefix' => '<div id="blog_entity_replace_wrapper">',
    '#suffix' => '</div>',
  );
  
   /*
   $publish_time = date('H:i');
   $form['breaking']['blog_publish_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Publish Time'),
    '#default_value' => ($results->blog_notification) ? $results->blog_notification : $publish_time,
    '#size' => 10,
    '#prefix' => '<div id="blog_publish_time_replace_wrapper">',
    '#suffix' => '</div>',
  );
  */   

  $form['breaking']['blog_highlight_status'] = array(
    '#type' => 'hidden',
    '#default_value' => ($results->blog_highlight_status) ? $results->blog_highlight_status : '2',
    '#attributes' => array('class' => 'blog_highlights_status'),
    '#prefix' => '<div id="blog_highlight_replace_wrapper">',
    '#suffix' => '</div>',
  );
  
  $form['breaking']['blog_entity_id'] = array(
    '#type' => 'hidden',
    '#value' => ($results->blog_entity_id) ? $results->blog_entity_id : $blog_entity_id,
    '#prefix' => '<div id="blog_entity_replace_wrapper">',
    '#suffix' => '</div>',
  );
  
  $form['breaking']['bid'] = array(
    '#type' => 'hidden',
    '#value' => ($results->bid) ? $results->bid : '',
    '#attributes' => array('class' => 'custom_blog_bid'),
    '#prefix' => '<div id="blog_bid_replace_wrapper">',
    '#suffix' => '</div>',
  );
  
  $form['breaking']['action'] = array(
    '#type' => 'hidden',
    '#value' => '',
    '#attributes' => array('class' => 'custom_blog_action'),
  );
   
  if ($type == 'insert') {
     $form['breaking']['submit'] = array(
      '#type' => 'submit',
      '#value' => 'Submit',
      '#ajax' => array(
        'callback' => 'itg_breaking_form_ajax_submit' ,
        'effect' => 'fade' ,
        'progress' => array('type' => 'throbber' , 'message' => '') ,
        'validate_first' => TRUE ,
      ) ,
    );
  } else {
    $form['breaking']['submit'] = array(
      '#type' => 'submit' ,
      '#value' => 'Submit',
      '#access' => TRUE,
      '#attributes' => array('class' => array('itg-custom-blog')),
      // '#attributes' => array("onclick" => "javascript:itg_blog_fetch_data($results->blog_entity_id);")
    );
    $form['#submit'][] = 'itg_live_blog_form_submit';
   
  }
 
  return $form;
}

/**
 * 
 * @param type $form
 * @param type $form_state
 */
function itg_manage_breking_news_submit($form, &$form_state) {
  
}

/**
 * 
 * @global type $user
 * @param type $form
 * @param type $form_state
 */
function itg_live_blog_form_submit($form, &$form_state) {
  global $user;
  $insert_id = '';
  $_SESSION['itg_blog_post'] = 1;
  $_SESSION['blogcron'] = 1;
  $blog_uid = $user->uid;
  $blog_type = 'Breaking News';
  $blog_title = $form_state['values']['blog_title'];
  $blog_description = $form_state['values']['blog_description']['value'];
  $blog_breaking_band = $form_state['values']['blog_breaking_band'];
  $blog_notification = $form_state['values']['blog_notification'];
  $blog_publish_time = $form_state['input']['blog_publish_time']['time'];
  $blog_highlight_status = $form_state['values']['blog_highlight_status'];
  $blog_entity_id = $form_state['values']['blog_entity_id'];
  $bid = $form_state['input']['bid'];
  if (isset($bid) && $bid > 0) {
    $insert_id = db_update('itg_live_blog')
        ->fields(array(
          'blog_entity_id' => $blog_entity_id,
          'blog_type' => $blog_type,
          'blog_title' => $blog_title,
          'blog_description' => $blog_description,
          'blog_breaking_band' => $blog_breaking_band,
          'blog_notification' => $blog_notification,
          'blog_publish_time' => $blog_publish_time,
          'blog_highlight_status' => $blog_highlight_status,
          'blog_uid' => $blog_uid,
          'blog_updated_date' => REQUEST_TIME,
        ))
        ->condition('bid', $bid, '=')
        ->execute();
    // $form_state['rebuild'] = TRUE;
    drupal_set_message(t('The form has been updated'));
  }
}


/**
 * 
 */
function live_bog_delete() {
  $bid = ($_POST['id']) ? $_POST['id'] : '';
  global $user;
  $blog_uid = $user->uid;
  $status = 0;
  $updated_date = date('Y-m-d H:i:s');
  if (!empty($bid)) {
     db_update('itg_live_blog')
              ->fields(array(
                'status' => $status,
                'update_uid' => $blog_uid,
                'blog_updated_date' => $updated_date,
              ))
              ->condition('bid', $bid, '=')
              ->execute();
  }
}

/**
 * 
 * @return string
 */
function live_bog_cron()
{
   return 'test';    
}
